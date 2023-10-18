/*
 * Copyright 2018-2021, 2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_flexspi.h"
#include "app.h"
#include "fsl_debug_console.h"
#include "fsl_spi_nor.h"
#include "flexspi_octal_flash_ops.h"

#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "fsl_common.h"
#include "fsl_reset.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*******************************************************************************
 * Variables
 ******************************************************************************/

static uint8_t s_nor_program_buffer[256];
static uint8_t s_nor_read_buffer[256];
/*
 * FLASH_USE_DEFAULT_LUT_TABLE
 * Note: Pls define it in app.h when try to use default look up table.
 * #define FLASH_USE_DEFAULT_LUT_TABLE (1)
 *
 * 1: use default look up table. When use default look up table, every body don't need care about the look up table.
 * When the nor flash is supported already, it's easy to support it on new platform.
 * When the nor flash is not supported, add a default look up table for the new nor flash and add specific logic in function flexspi_nor_enable_octal_mode.
 *
 * 0: use custom look up table. It's used for old platforms.
 */

#if defined(FLASH_USE_DEFAULT_LUT_TABLE) && FLASH_USE_DEFAULT_LUT_TABLE

#if defined(EXAMPLE_FLASH_RESET_CONFIG)
const uint32_t FastReadSDRLUTCommandSeq[4] = {0};
const uint32_t OctalReadDDRLUTCommandSeq[4] = {0};
#endif

const uint32_t customLUTOctalMode[CUSTOM_LUT_LENGTH] = {0};
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/
extern spi_nor_flash_state flash_state;
flexspi_device_config_t deviceconfig = {
    .flexspiRootClk       = 98000000,
    .flashSize            = FLASH_SIZE,
    .CSIntervalUnit       = kFLEXSPI_CsIntervalUnit1SckCycle,
    .CSInterval           = 2,
    .CSHoldTime           = 3,
    .CSSetupTime          = 3,
    .dataValidTime        = 2,
    .columnspace          = 0,
    .enableWordAddress    = 0,
    .AWRSeqIndex          = NOR_CMD_LUT_SEQ_IDX_WRITE,
    .AWRSeqNumber         = 1,
    .ARDSeqIndex          = NOR_CMD_LUT_SEQ_IDX_READ,
    .ARDSeqNumber         = 1,
    .AHBWriteWaitUnit     = kFLEXSPI_AhbWriteWaitUnit2AhbCycle,
    .AHBWriteWaitInterval = 0,
};

status_t flexspi_nor_get_id(FLEXSPI_Type *base, uint8_t *Id)
{
    /* Read manufacturer ID based on JEP106V spec, max continuation code table is 9, max manufacturer ID starts from
     * 9 + 1. */
    uint8_t id[SPI_NOR_MAX_ID_LEN] = {0x00U};
    status_t status                = kStatus_Fail;
    uint32_t tempLUT[4]            = {0};
    uint32_t readValue;
    bool enableOctal = false;

    if (flash_state.spiMode == SPINOR_OPI_MODE)
    {
        enableOctal = true;
        /* need exit from octal mode to spi mode when flash is in octal mode */
        /* Exit octal mode command. */
        tempLUT[0] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_8PAD, SPINOR_OP_RETURN_TO_SPI_FROM_OCTAL_ADESTO,
                                     kFLEXSPI_Command_STOP, kFLEXSPI_8PAD, 0x0); /* exit octal mode in Octal SDR mode */

        /* Update for exit octal mode. */
        FLEXSPI_UpdateLUT(base, 4 * NOR_CMD_LUT_SEQ_IDX_CONFIG, tempLUT, 4);
        /* Write enable */
        status = flexspi_nor_write_enable(base, 0, enableOctal);
        if (status != kStatus_Success)
        {
            return status;
        }

        /* check whether write enable */
        status = flexspi_nor_exec_op(
            base, 0, FLASH_PORT, kFLEXSPI_Read,
            (enableOctal) ? (NOR_CMD_LUT_SEQ_IDX_READSTATUS_OPI) : (NOR_CMD_LUT_SEQ_IDX_READSTATUS), 1, &readValue, 1);
        if (status != kStatus_Success)
        {
            return status;
        }

        /* Back from octal mode to standard SPI mode. */
        status = flexspi_nor_exec_op(base, 0, FLASH_PORT, kFLEXSPI_Command, NOR_CMD_LUT_SEQ_IDX_CONFIG, 1, NULL, 0);
        if (status == kStatus_Success)
        {
            status = flexspi_nor_wait_bus_busy(base, false);
        }
        if (status != kStatus_Success)
        {
            return status;
        }
        flash_state.spiMode = SPINOR_SPI_MODE;
    }

    status = flexspi_nor_exec_op(base, 0, FLASH_PORT, kFLEXSPI_Read, NOR_CMD_LUT_SEQ_IDX_READID_SPI, 1, (uint32_t *)id,
                                 sizeof(id));

    if (status == kStatus_Success)
    {
        for (uint8_t i = 0x00U; i < sizeof(id); i++)
        {
            if (CFI_CONTINUATION != id[i])
            {
                *Id++ = id[i];
            }
        }
    }

    return status;
}



int main(void)
{
    uint32_t i = 0;
    status_t status;
    uint8_t id[SPI_NOR_MAX_ID_LEN] = {0};

    BOARD_ConfigMPU();
    BOARD_InitBootPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();

#if !(defined(XIP_EXTERNAL_FLASH) && XIP_EXTERNAL_FLASH == 1)
    /* Only ram target needed. */
    RESET_PeripheralReset(kRESET_Flexspi0);
#endif

    /* 392MHz * 1U / 4U = 98MHz */
    BOARD_SetFlexspiClock(EXAMPLE_FLEXSPI, kCLOCK_Pcc0PlatIpSrcPll0Pfd3, 3U, 0U);

    if (BOARD_IsLowPowerBootType() != true) /* not low power boot type */
    {
        BOARD_HandshakeWithUboot(); /* Must handshake with uboot, unless will get issues(such as: SoC reset all the
                                       time) */
    }
    else /* low power boot type */
    {
        BOARD_SetTrdcGlobalConfig();
    }


    PRINTF("\r\nFLEXSPI example started!\r\n");

    status = flexspi_nor_flash_init(EXAMPLE_FLEXSPI, id);
    if (status != kStatus_Success)
    {
        PRINTF("Init Flash failure !\r\n");
        assert(false);
    }

    /* Enter octal mode unless the FLASH boots in octal mode after reset */
    status = flexspi_nor_enable_octal_mode(EXAMPLE_FLEXSPI);
    if (status != kStatus_Success)
    {
        assert(false);
    }

    if (id[0] == 0)
    {
        status = flexspi_nor_get_id(EXAMPLE_FLEXSPI, id); /* read id in octal mode */
        if (status != kStatus_Success)
        {
            assert(false);
        }
    }

    /* Show JEDEC ID. */
    PRINTF("JEDEC id bytes: %02x, %02x, %02x\r\n", id[0], id[1], id[2]);

    /* Erase sectors. */
    PRINTF("Erasing Serial NOR over FlexSPI...\r\n");
    status = flexspi_nor_flash_erase_sector(EXAMPLE_FLEXSPI, EXAMPLE_SECTOR * SECTOR_SIZE);
    if (status != kStatus_Success)
    {
        PRINTF("Erase sector failure !\r\n");
        assert(false);
    }

#if defined(CACHE_MAINTAIN) && CACHE_MAINTAIN
    DCACHE_InvalidateByRange(EXAMPLE_FLEXSPI_AMBA_BASE + EXAMPLE_SECTOR * SECTOR_SIZE, FLASH_PAGE_SIZE);
#endif

    memset(s_nor_program_buffer, 0xFFU, sizeof(s_nor_program_buffer));
    memcpy(s_nor_read_buffer, (void *)(EXAMPLE_FLEXSPI_AMBA_BASE + EXAMPLE_SECTOR * SECTOR_SIZE),
           sizeof(s_nor_read_buffer));

    if (memcmp(s_nor_program_buffer, s_nor_read_buffer, sizeof(s_nor_program_buffer)))
    {
        PRINTF("Erase data -  read out data value incorrect !\r\n ");
        assert(false);
    }
    else
    {
        PRINTF("Erase data - successfully. \r\n");
    }

    for (i = 0; i < 0xFFU; i++)
    {
        s_nor_program_buffer[i] = i;
    }

    status =
        flexspi_nor_flash_page_program(EXAMPLE_FLEXSPI, EXAMPLE_SECTOR * SECTOR_SIZE, (void *)s_nor_program_buffer);
    if (status != kStatus_Success)
    {
        PRINTF("Page program failure !\r\n");
        assert(false);
    }

#if defined(CACHE_MAINTAIN) && CACHE_MAINTAIN
    DCACHE_InvalidateByRange(EXAMPLE_FLEXSPI_AMBA_BASE + EXAMPLE_SECTOR * SECTOR_SIZE, FLASH_PAGE_SIZE);
#endif

    memcpy(s_nor_read_buffer, (void *)(EXAMPLE_FLEXSPI_AMBA_BASE + EXAMPLE_SECTOR * SECTOR_SIZE),
           sizeof(s_nor_read_buffer));

    if (memcmp(s_nor_read_buffer, s_nor_program_buffer, sizeof(s_nor_program_buffer)) != 0)
    {
        PRINTF("Program data -  read out data value incorrect !\r\n ");
        assert(false);
    }
    else
    {
        PRINTF("Program data - successfully. \r\n");
    }

    while (1)
    {
    }
}
