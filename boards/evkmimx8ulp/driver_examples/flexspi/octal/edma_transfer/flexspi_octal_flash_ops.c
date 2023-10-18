/*
 * Copyright 2019-2021,2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_flexspi.h"
#include "fsl_flexspi_edma.h"
#include "fsl_spi_nor.h"
#include "app.h"
#include "flexspi_octal_flash_ops.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*******************************************************************************
 * Variables
 ******************************************************************************/
spi_nor_flash_state flash_state;
extern flexspi_device_config_t deviceconfig;
#if FLASH_ADESTO_DEVICE_ATXP032
extern const uint32_t defaultLUTOctalMode_ADESTO[CUSTOM_LUT_LENGTH];
#endif

#if FLASH_GIGADEVICE_DEVICE_GD25LX256
extern const uint32_t defaultLUTOctalMode_GIGADEVICE[CUSTOM_LUT_LENGTH];
#endif

extern const uint32_t defaultLUTOctalMode[CUSTOM_LUT_LENGTH];
extern const uint32_t customLUTOctalMode[CUSTOM_LUT_LENGTH];


#if defined(EXAMPLE_FLASH_RESET_CONFIG)
extern const uint32_t defaultFastReadSDRLUTCommandSeq[4];
extern const uint32_t defaultOctalReadDDRLUTCommandSeq[4];
extern const uint32_t FastReadSDRLUTCommandSeq[4];
extern const uint32_t OctalReadDDRLUTCommandSeq[4];
#endif

static volatile bool g_completionFlag = false;
extern edma_handle_t dmaTxHandle;
extern edma_handle_t dmaRxHandle;
static flexspi_edma_handle_t flexspiHandle;

/*******************************************************************************
 * Code
 ******************************************************************************/
void flexspi_nor_disable_cache(flexspi_cache_status_t *cacheStatus)
{
#if (defined __CORTEX_M) && (__CORTEX_M == 7U)
#if defined(__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
    /* Disable D cache. */
    if (SCB_CCR_DC_Msk == (SCB_CCR_DC_Msk & SCB->CCR))
    {
        SCB_DisableDCache();
        cacheStatus->DCacheEnableFlag = true;
    }
#endif /* __DCACHE_PRESENT */

#if defined(__ICACHE_PRESENT) && (__ICACHE_PRESENT == 1U)
    /* Disable I cache. */
    if (SCB_CCR_IC_Msk == (SCB_CCR_IC_Msk & SCB->CCR))
    {
        SCB_DisableICache();
        cacheStatus->ICacheEnableFlag = true;
    }
#endif /* __ICACHE_PRESENT */

#elif (defined FSL_FEATURE_SOC_LMEM_COUNT) && (FSL_FEATURE_SOC_LMEM_COUNT != 0U)
    /* Disable code bus cache and system bus cache */
    if (LMEM_PCCCR_ENCACHE_MASK == (LMEM_PCCCR_ENCACHE_MASK & LMEM->PCCCR))
    {
        L1CACHE_DisableCodeCache();
        cacheStatus->codeCacheEnableFlag = true;
    }
    if (LMEM_PSCCR_ENCACHE_MASK == (LMEM_PSCCR_ENCACHE_MASK & LMEM->PSCCR))
    {
        L1CACHE_DisableSystemCache();
        cacheStatus->systemCacheEnableFlag = true;
    }

#elif (defined FSL_FEATURE_SOC_CACHE64_CTRL_COUNT) && (FSL_FEATURE_SOC_CACHE64_CTRL_COUNT != 0U)
    /* Disable cache */
    CACHE64_DisableCache(EXAMPLE_CACHE);
    cacheStatus->CacheEnableFlag = true;
#endif
}

void flexspi_nor_enable_cache(flexspi_cache_status_t cacheStatus)
{
#if (defined __CORTEX_M) && (__CORTEX_M == 7U)
#if defined(__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
    if (cacheStatus.DCacheEnableFlag)
    {
        /* Enable D cache. */
        SCB_EnableDCache();
    }
#endif /* __DCACHE_PRESENT */

#if defined(__ICACHE_PRESENT) && (__ICACHE_PRESENT == 1U)
    if (cacheStatus.ICacheEnableFlag)
    {
        /* Enable I cache. */
        SCB_EnableICache();
    }
#endif /* __ICACHE_PRESENT */

#elif (defined FSL_FEATURE_SOC_LMEM_COUNT) && (FSL_FEATURE_SOC_LMEM_COUNT != 0U)
    if (cacheStatus.codeCacheEnableFlag)
    {
        /* Enable code cache. */
        L1CACHE_EnableCodeCache();
    }

    if (cacheStatus.systemCacheEnableFlag)
    {
        /* Enable system cache. */
        L1CACHE_EnableSystemCache();
    }
#elif (defined FSL_FEATURE_SOC_CACHE64_CTRL_COUNT) && (FSL_FEATURE_SOC_CACHE64_CTRL_COUNT != 0U)
    if (cacheStatus.CacheEnableFlag)
    {
        /* Enable cache. */
        CACHE64_EnableCache(EXAMPLE_CACHE);
    }
#endif
}

static void flexspi_callback(FLEXSPI_Type *base, flexspi_edma_handle_t *handle, status_t status, void *userData)
{
    /* Signal transfer success when received success status. */
    if (status == kStatus_Success)
    {
        g_completionFlag = true;
    }
}

status_t flexspi_nor_exec_op(FLEXSPI_Type *base,
                             uint32_t deviceAddr,
                             flexspi_port_t port,
                             flexspi_command_type_t cmdType,
                             uint8_t seqIndex,
                             uint8_t seqNumber,
                             uint32_t *data,
                             size_t dataSize)
{
    flexspi_transfer_t flashXfer;

    flashXfer.deviceAddress = deviceAddr;
    flashXfer.port          = port;
    flashXfer.cmdType       = cmdType;
    flashXfer.SeqNumber     = seqNumber;
    flashXfer.seqIndex      = seqIndex;
    flashXfer.data          = data;
    flashXfer.dataSize      = dataSize;

    return FLEXSPI_TransferBlocking(base, &flashXfer);
}

status_t flexspi_nor_exec_op_with_edma(FLEXSPI_Type *base,
                             uint32_t deviceAddr,
                             flexspi_port_t port,
                             flexspi_command_type_t cmdType,
                             uint8_t seqIndex,
                             uint8_t seqNumber,
                             uint32_t *data,
                             size_t dataSize)
{
    flexspi_transfer_t flashXfer;

    flashXfer.deviceAddress = deviceAddr;
    flashXfer.port          = port;
    flashXfer.cmdType       = cmdType;
    flashXfer.SeqNumber     = seqNumber;
    flashXfer.seqIndex      = seqIndex;
    flashXfer.data          = data;
    flashXfer.dataSize      = dataSize;

    return FLEXSPI_TransferEDMA(base, &flexspiHandle, &flashXfer);
}

status_t flexspi_nor_write_enable(FLEXSPI_Type *base, uint32_t baseAddr, bool enableOctal)
{
    status_t status;

    /* Write enable */
    status = flexspi_nor_exec_op(
        base, baseAddr, FLASH_PORT, kFLEXSPI_Command,
        (enableOctal) ? (NOR_CMD_LUT_SEQ_IDX_WRITEENABLE_OPI) : (NOR_CMD_LUT_SEQ_IDX_WRITEENABLE), 1, NULL, 0);

    return status;
}

status_t flexspi_nor_wait_bus_busy(FLEXSPI_Type *base, bool enableOctal)
{
    /* Wait status ready. */
    bool isBusy;
    uint32_t readValue = 0U;
    status_t status;

    do
    {
        status = flexspi_nor_exec_op(
            base, 0, FLASH_PORT, kFLEXSPI_Read,
            (enableOctal) ? (NOR_CMD_LUT_SEQ_IDX_READSTATUS_OPI) : (NOR_CMD_LUT_SEQ_IDX_READSTATUS), 1, &readValue, 1);
        if (status != kStatus_Success)
        {
            return status;
        }
        if (FLASH_BUSY_STATUS_POL)
        {
            if (readValue & (1U << FLASH_BUSY_STATUS_OFFSET))
            {
                isBusy = true;
            }
            else
            {
                isBusy = false;
            }
        }
        else
        {
            if (readValue & (1U << FLASH_BUSY_STATUS_OFFSET))
            {
                isBusy = false;
            }
            else
            {
                isBusy = true;
            }
        }

    } while (isBusy);

    return status;
}

#if 0
status_t flexspi_nor_wait_bus_busy(FLEXSPI_Type *base, bool enableOctal)
{
    /* Wait status ready. */
    bool isBusy;
    uint32_t readValue;
    status_t status;
    flexspi_transfer_t flashXfer;

    flashXfer.deviceAddress = 0;
    flashXfer.port          = FLASH_PORT;
    flashXfer.cmdType       = kFLEXSPI_Read;
    flashXfer.SeqNumber     = 1;
    if (enableOctal)
    {
        flashXfer.seqIndex = NOR_CMD_LUT_SEQ_IDX_READSTATUS_OPI;
    }
    else
    {
        flashXfer.seqIndex = NOR_CMD_LUT_SEQ_IDX_READSTATUS;
    }

    flashXfer.data     = &readValue;
    flashXfer.dataSize = 1;

    do
    {
        /* For flash targets, after doing erase/program, need to call flexspi_nor_wait_bus_busy to wait for the
        operation finish, Use blocking way to read back the status instead of using DMA. The reason is that the called
        DMA API calls memset which is placed in flash region, because the external flash is being erase/propgram, so
        load instruction from external flash at this time may read back some invalid instructions. */
        status = flexspi_nor_exec_op(
            base, 0, FLASH_PORT, kFLEXSPI_Read,
            (enableOctal) ? (NOR_CMD_LUT_SEQ_IDX_READSTATUS_OPI) : (NOR_CMD_LUT_SEQ_IDX_READSTATUS), 1, &readValue, 1);
        if (status != kStatus_Success)
        {
            return status;
        }
        if (FLASH_BUSY_STATUS_POL)
        {
            if (readValue & (1U << FLASH_BUSY_STATUS_OFFSET))
            {
                isBusy = true;
            }
            else
            {
                isBusy = false;
            }
        }
        else
        {
            if (readValue & (1U << FLASH_BUSY_STATUS_OFFSET))
            {
                isBusy = false;
            }
            else
            {
                isBusy = true;
            }
        }

    } while (isBusy);

    return status;
}
#endif

#if 0
status_t flexspi_nor_enable_octal_mode(FLEXSPI_Type *base)
{
    flexspi_transfer_t flashXfer;
    status_t status;

    /* Copy LUT information from flash region into RAM region, because flash boot mode maybe not same with application's
       required mode.
       If yes, doesn't need to memory copy operation; if no, need to memory opeation before flash access failure due to
       mismatch LUT read command sequence. */
#if defined(EXAMPLE_FLASH_RESET_CONFIG)
    uint32_t TempOctalReadDDRLUTCommandSeq[4];

    memcpy(TempOctalReadDDRLUTCommandSeq, OctalReadDDRLUTCommandSeq, sizeof(OctalReadDDRLUTCommandSeq));
#endif
#if defined(CACHE_MAINTAIN) && CACHE_MAINTAIN
    flexspi_cache_status_t cacheStatus;
    flexspi_nor_disable_cache(&cacheStatus);
#endif

#if defined(FLASH_ADESTO) && FLASH_ADESTO
    uint32_t tempLUT[4] = {0};
    uint32_t readValue;

    /* Update LUT table for octal mode. */
    FLEXSPI_UpdateLUT(base, 4 * NOR_CMD_LUT_SEQ_IDX_READ, OctalReadDDRLUTCommandSeq, 4);

    /* Set the command instruction of read status register for LUT in octal sdr mode. */
    tempLUT[0] =
        FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_8PAD, 0x05, kFLEXSPI_Command_DUMMY_SDR, kFLEXSPI_8PAD, 0x04);
    tempLUT[1] =
        FLEXSPI_LUT_SEQ(kFLEXSPI_Command_READ_SDR, kFLEXSPI_8PAD, 0x04, kFLEXSPI_Command_STOP, kFLEXSPI_8PAD, 0x0);
    /* Update LUT table. */
    FLEXSPI_UpdateLUT(base, 4 * NOR_CMD_LUT_SEQ_IDX_READSTATUS_OPI, tempLUT, 4);

    /* Write enable */
    status = flexspi_nor_write_enable(base, 0, false);

    /* Enable quad mode. */
    flashXfer.deviceAddress = 0;
    flashXfer.port          = FLASH_PORT;
    flashXfer.cmdType       = kFLEXSPI_Command;
    flashXfer.SeqNumber     = 1;
    flashXfer.seqIndex      = NOR_CMD_LUT_SEQ_IDX_ENTEROPI;

    status = FLEXSPI_TransferBlocking(base, &flashXfer);
    if (status != kStatus_Success)
    {
        return status;
    }

    status = flexspi_nor_wait_bus_busy(base, true);
    if (status != kStatus_Success)
    {
        return status;
    }

    /* Check global protect or ont. */
    flashXfer.deviceAddress = 0;
    flashXfer.port          = FLASH_PORT;
    flashXfer.cmdType       = kFLEXSPI_Read;
    flashXfer.SeqNumber     = 1;
    flashXfer.seqIndex      = NOR_CMD_LUT_SEQ_IDX_READSTATUS_OPI;

    flashXfer.data     = &readValue;
    flashXfer.dataSize = 1;

    status = FLEXSPI_TransferBlocking(base, &flashXfer);
    if (status != kStatus_Success)
    {
        return status;
    }

    /* Global protected. */
    if ((readValue & 0x0CU) == 0x0CU)
    {
        /* Global unprotect entire memory region if it was protected by default, such as Adesto's octal flash. */
        tempLUT[0] =
            FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_8PAD, 0x01, kFLEXSPI_Command_WRITE_SDR, kFLEXSPI_8PAD, 0x04);
        tempLUT[1] = 0x00U;

        /* Update LUT table. */
        FLEXSPI_UpdateLUT(base, 4 * NOR_CMD_LUT_SEQ_IDX_CONFIG, tempLUT, 4);

        uint32_t globalUnprotect = FLASH_UNPROTECTVALUE;

        /* Write enable */
        status = flexspi_nor_write_enable(base, 0, true);

        if (status != kStatus_Success)
        {
            return status;
        }

        flashXfer.deviceAddress = 0;
        flashXfer.port          = FLASH_PORT;
        flashXfer.cmdType       = kFLEXSPI_Write;
        flashXfer.SeqNumber     = 1;
        flashXfer.seqIndex      = NOR_CMD_LUT_SEQ_IDX_CONFIG;
        flashXfer.data          = &globalUnprotect;
        flashXfer.dataSize      = 1;

        status = FLEXSPI_TransferBlocking(base, &flashXfer);
        if (status != kStatus_Success)
        {
            return status;
        }

        status = flexspi_nor_wait_bus_busy(base, true);

        if (status != kStatus_Success)
        {
            return status;
        }

        /* Check unprotect successfully or not. */
        flashXfer.deviceAddress = 0;
        flashXfer.port          = FLASH_PORT;
        flashXfer.cmdType       = kFLEXSPI_Read;
        flashXfer.SeqNumber     = 1;
        flashXfer.seqIndex      = NOR_CMD_LUT_SEQ_IDX_READSTATUS_OPI;

        flashXfer.data     = &readValue;
        flashXfer.dataSize = 1;

        status = FLEXSPI_TransferBlocking(base, &flashXfer);
        if (status != kStatus_Success)
        {
            return status;
        }

        status = flexspi_nor_wait_bus_busy(base, true);
        if (status != kStatus_Success)
        {
            return status;
        }

        if ((readValue & 0x0CU) != 0x00U)
        {
            return -1;
        }
    }

    /* Enable DDR mode. */
    /* Update LUT table for configure status register2.*/
    tempLUT[0] =
        FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_8PAD, 0x31, kFLEXSPI_Command_WRITE_SDR, kFLEXSPI_8PAD, 0x01);
    /* Update LUT table. */
    FLEXSPI_UpdateLUT(base, 4 * NOR_CMD_LUT_SEQ_IDX_CONFIG, tempLUT, 4);

    /* Set the command instruction of read status register for LUT in octal ddr mode. */
    tempLUT[0] =
        FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_8PAD, 0x05, kFLEXSPI_Command_DUMMY_DDR, kFLEXSPI_8PAD, 0x04);
    tempLUT[1] =
        FLEXSPI_LUT_SEQ(kFLEXSPI_Command_READ_DDR, kFLEXSPI_8PAD, 0x04, kFLEXSPI_Command_STOP, kFLEXSPI_8PAD, 0x0);
    /* Update LUT table. */
    FLEXSPI_UpdateLUT(base, 4 * NOR_CMD_LUT_SEQ_IDX_READSTATUS_OPI, tempLUT, 4);

    /* Adesto enable octal mode needs to configures status register2. */
    uint32_t enableDdrMode = FLASH_ENABLE_OCTAL_DDRMODE;

    /* Write enable */
    status = flexspi_nor_write_enable(base, 0, true);
    if (status != kStatus_Success)
    {
        return status;
    }

    flashXfer.deviceAddress = 0;
    flashXfer.port          = FLASH_PORT;
    flashXfer.cmdType       = kFLEXSPI_Write;
    flashXfer.SeqNumber     = 1;
    flashXfer.seqIndex      = NOR_CMD_LUT_SEQ_IDX_CONFIG;
    flashXfer.data          = &enableDdrMode;
    flashXfer.dataSize      = 1;

    status = FLEXSPI_TransferBlocking(base, &flashXfer);
    if (status != kStatus_Success)
    {
        return status;
    }

    status = flexspi_nor_wait_bus_busy(base, true);

#else /* MXIC's octal flash. */

    uint32_t writeValue = FLASH_ENABLE_OCTAL_CMD;

    /* Write enable */
    status = flexspi_nor_write_enable(base, 0, false);

    if (status != kStatus_Success)
    {
        return status;
    }

    /* Enable quad mode. */
    flashXfer.deviceAddress = 0;
    flashXfer.port          = FLASH_PORT;
    flashXfer.cmdType       = kFLEXSPI_Write;
    flashXfer.SeqNumber     = 1;
    flashXfer.seqIndex      = NOR_CMD_LUT_SEQ_IDX_ENTEROPI;
    flashXfer.data          = &writeValue;
    flashXfer.dataSize      = 1;

    status = FLEXSPI_TransferBlocking(base, &flashXfer);
    if (status != kStatus_Success)
    {
        return status;
    }

    status             = flexspi_nor_wait_bus_busy(base, true);
#endif

#if defined(EXAMPLE_FLASH_RESET_CONFIG)
    /* 8DTRD: enter octal DDR and update read LUT entry into 8DTRD. */
    FLEXSPI_UpdateLUT(base, 4 * NOR_CMD_LUT_SEQ_IDX_READ, TempOctalReadDDRLUTCommandSeq, 4);
#endif

    /* Do software reset. */
    FLEXSPI_SoftwareReset(base);

#if defined(CACHE_MAINTAIN) && CACHE_MAINTAIN
    flexspi_nor_enable_cache(cacheStatus);
#endif

    return status;
}
#endif

status_t flexspi_nor_enable_octal_for_adesto(FLEXSPI_Type *base)
{
    status_t status = kStatus_Fail;
    uint32_t tempLUT[4] = {0U};
    uint32_t readValue  = 0U;
    /* Adesto enable Octal DDR(DTR) mode needs to configures status register byte 2. */
    uint32_t enableDdrMode   = SR2_SDR_DDR_ADESTO | SR2_OME_ADESTO;
    uint32_t globalUnprotect = 0U;
#if defined(EXAMPLE_FLASH_RESET_CONFIG)
    uint32_t TempOctalReadDDRLUTCommandSeq[4];

    if (OctalReadDDRLUTCommandSeq[0] != 0U)
    {
        memcpy(TempOctalReadDDRLUTCommandSeq, OctalReadDDRLUTCommandSeq, sizeof(OctalReadDDRLUTCommandSeq));
    }
    else
    {
        /* use default look up table */
        memcpy(TempOctalReadDDRLUTCommandSeq, defaultOctalReadDDRLUTCommandSeq, sizeof(defaultOctalReadDDRLUTCommandSeq));
    }

    /*
     * Update LUT table for octal mode fast read.Make sure that cpu AHB read instruction from nor flash
     * correctly
     */
    FLEXSPI_UpdateLUT(base, 4 * NOR_CMD_LUT_SEQ_IDX_READ, TempOctalReadDDRLUTCommandSeq,
                      ARRAY_SIZE(TempOctalReadDDRLUTCommandSeq));
#endif

    /* Set the command instruction of read status register for LUT in octal sdr mode. */
    tempLUT[0] =
        FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_8PAD, SPINOR_OP_RDSR, kFLEXSPI_Command_DUMMY_SDR,
                        kFLEXSPI_8PAD, SPINOR_DUMMY_CYCLE_NUMBER_4); /* it's relative with nor flash */
    tempLUT[1] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_READ_SDR, kFLEXSPI_8PAD, SPINOR_DATA_SIZE_4_BYTES,
                                 kFLEXSPI_Command_STOP, kFLEXSPI_8PAD, 0x0);
    /* Update LUT table. */
    FLEXSPI_UpdateLUT(base, 4 * NOR_CMD_LUT_SEQ_IDX_READSTATUS_OPI, tempLUT, ARRAY_SIZE(tempLUT));

    /* Write enable */
    status = flexspi_nor_write_enable(base, 0, false);

    /* Enable octal mode(OPI). */
    status = flexspi_nor_exec_op(base, 0, FLASH_PORT, kFLEXSPI_Command, NOR_CMD_LUT_SEQ_IDX_ENTEROPI, 1,
                                 NULL, 0);
    if (status != kStatus_Success)
    {
        return status;
    }

    status = flexspi_nor_wait_bus_busy(base, true);
    if (status != kStatus_Success)
    {
        return status;
    }

    /* Check global protect or ont. */
    status = flexspi_nor_exec_op(base, 0, FLASH_PORT, kFLEXSPI_Read, NOR_CMD_LUT_SEQ_IDX_READSTATUS_OPI, 1,
                                 &readValue, 1);
    if (status != kStatus_Success)
    {
        return status;
    }

    /* Global protected. */
    if ((readValue & SR_SWP_ALL_SECTORS_PROTECTED) == SR_SWP_ALL_SECTORS_PROTECTED)
    {
        /*
         * Global unprotect entire memory region if it was protected by default, such as Adesto's octal
         * flash.
         */
        tempLUT[0] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_8PAD, SPINOR_OP_WRSR,
                                     kFLEXSPI_Command_WRITE_SDR, kFLEXSPI_8PAD, SPINOR_DATA_SIZE_4_BYTES);
        tempLUT[1] = 0x00U;

        /* Update LUT table. */
        FLEXSPI_UpdateLUT(base, 4 * NOR_CMD_LUT_SEQ_IDX_CONFIG, tempLUT,
                          ARRAY_SIZE(tempLUT));

        /* Write enable */
        status = flexspi_nor_write_enable(base, 0, true);

        if (status != kStatus_Success)
        {
            return status;
        }

        globalUnprotect = readValue & (~SR_SWP_ALL_SECTORS_PROTECTED);
        status = flexspi_nor_exec_op(base, 0, FLASH_PORT, kFLEXSPI_Write, NOR_CMD_LUT_SEQ_IDX_CONFIG, 1,
                                     &globalUnprotect, 1);
        if (status != kStatus_Success)
        {
            return status;
        }

        status = flexspi_nor_wait_bus_busy(base, true);

        if (status != kStatus_Success)
        {
            return status;
        }

        /* Check unprotect successfully or not. */
        status = flexspi_nor_exec_op(base, 0, FLASH_PORT, kFLEXSPI_Read, NOR_CMD_LUT_SEQ_IDX_READSTATUS_OPI,
                                     1, &readValue, 1);
        if (status != kStatus_Success)
        {
            return status;
        }

        status = flexspi_nor_wait_bus_busy(base, true);
        if (status != kStatus_Success)
        {
            return status;
        }

        if ((readValue & SR_SWP_ALL_SECTORS_PROTECTED) != SR_SWP_ALL_SECTORS_UNPROTECTED)
        {
            return -1;
        }
    }

    /* Enable DDR mode. */
    /* Update LUT table for configure status register2.*/
    tempLUT[0] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_8PAD, SPINOR_OP_WRSR2_ADESTO,
                                 kFLEXSPI_Command_WRITE_SDR, kFLEXSPI_8PAD,
                                 SPINOR_DATA_SIZE_1_BYTES); /* write status register byte 2 in octal sdr
                                                               mode to enable Octal DDR mode */
    tempLUT[1] = 0x00U;
    /* Update LUT table. */
    FLEXSPI_UpdateLUT(base, 4 * NOR_CMD_LUT_SEQ_IDX_CONFIG, tempLUT, ARRAY_SIZE(tempLUT));

    /* Set the command instruction of read status register for LUT in octal ddr mode. */
    tempLUT[0] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_8PAD, SPINOR_OP_RDSR1,
                                 kFLEXSPI_Command_DUMMY_DDR, kFLEXSPI_8PAD, SPINOR_DUMMY_CYCLE_NUMBER_4);
    tempLUT[1] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_READ_DDR, kFLEXSPI_8PAD, SPINOR_DATA_SIZE_4_BYTES,
                                 kFLEXSPI_Command_STOP, kFLEXSPI_8PAD, 0x0);
    /* Update LUT table. */
    FLEXSPI_UpdateLUT(base, 4 * NOR_CMD_LUT_SEQ_IDX_READSTATUS_OPI, tempLUT, ARRAY_SIZE(tempLUT));

    /* Write enable */
    status = flexspi_nor_write_enable(base, 0, true);
    if (status != kStatus_Success)
    {
        return status;
    }

    status = flexspi_nor_exec_op(base, 0, FLASH_PORT, kFLEXSPI_Write, NOR_CMD_LUT_SEQ_IDX_CONFIG, 1,
                                 &enableDdrMode, 1);
    if (status != kStatus_Success)
    {
        return status;
    }

    status = flexspi_nor_wait_bus_busy(base, true);
    if (status == kStatus_Success)
    {
        flash_state.spiMode = SPINOR_OPI_MODE;
    }
    
    return status;
}

status_t flexspi_nor_enable_octal_for_gigadevice(FLEXSPI_Type *base)
{
    status_t status = kStatus_Fail;
    uint32_t tempLUT[4] = {0};
    uint32_t val        = SPINOR_IO_MODE_OCTAL_DTR_WITH_DQS_GIGADEVICE;

#if defined(EXAMPLE_FLASH_RESET_CONFIG)
    uint32_t TempOctalReadDDRLUTCommandSeq[4];

    if (OctalReadDDRLUTCommandSeq[0] != 0U)
    {
        memcpy(TempOctalReadDDRLUTCommandSeq, OctalReadDDRLUTCommandSeq, sizeof(OctalReadDDRLUTCommandSeq));
    }
    else
    {
        /* use default look up table */
        memcpy(TempOctalReadDDRLUTCommandSeq, defaultOctalReadDDRLUTCommandSeq, sizeof(defaultOctalReadDDRLUTCommandSeq));
    }
#endif

    /* Write enable */
    status = flexspi_nor_write_enable(base, 0, false);

    memset((void *)tempLUT, 0, sizeof(tempLUT));
    tempLUT[0] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_1PAD, SPINOR_OP_WR_VOLATILE_CFG_GIGADEVICE,
                                 kFLEXSPI_Command_RADDR_SDR, kFLEXSPI_1PAD, SPINOR_ADDRESS_32_BITS);
    tempLUT[1] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_WRITE_SDR, kFLEXSPI_1PAD, SPINOR_DATA_SIZE_4_BYTES,
                                 kFLEXSPI_Command_STOP, kFLEXSPI_1PAD, 0x0);
    /* Update LUT table. */
    FLEXSPI_UpdateLUT(base, 4 * NOR_CMD_LUT_SEQ_IDX_CONFIG, tempLUT, ARRAY_SIZE(tempLUT));

    /* write address 0(I/O Mode) of volatile configuration registers with SPI Mode to enter Octal DTR with
     * DQS mode */
    status = flexspi_nor_exec_op(base, SPINOR_VOLATILE_CFG_REG_ADDR_IO_MODE_GIGADEVICE, FLASH_PORT,
                                 kFLEXSPI_Write, NOR_CMD_LUT_SEQ_IDX_CONFIG, 1, &val, 1);
    if (status != kStatus_Success)
    {
        return status;
    }
#if defined(EXAMPLE_FLASH_RESET_CONFIG)
    /*
     * Update LUT table for octal mode fast read.Make sure that cpu AHB read instruction from nor flash
     * correctly
     */
    FLEXSPI_UpdateLUT(base, 4 * NOR_CMD_LUT_SEQ_IDX_READ, TempOctalReadDDRLUTCommandSeq,
                      ARRAY_SIZE(TempOctalReadDDRLUTCommandSeq));
#endif

    /* check whether switched to OPI Mode */
    memset((void *)tempLUT, 0, sizeof(tempLUT));
    tempLUT[0] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_8PAD, SPINOR_OP_RD_VOLATILE_CFG_GIGADEVICE,
                                 kFLEXSPI_Command_RADDR_DDR, kFLEXSPI_8PAD, SPINOR_ADDRESS_32_BITS);
    tempLUT[1] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_DUMMY_DDR, kFLEXSPI_8PAD, SPINOR_DUMMY_CYCLE_NUMBER_8,
                                 kFLEXSPI_Command_READ_DDR, kFLEXSPI_8PAD, SPINOR_DATA_SIZE_4_BYTES);
    FLEXSPI_UpdateLUT(EXAMPLE_FLEXSPI, 4 * NOR_CMD_LUT_SEQ_IDX_CONFIG, tempLUT, ARRAY_SIZE(tempLUT));
    /* read address 0(I/O Mode) of volatile configuration registers in OPI Mode */
    status = flexspi_nor_exec_op(EXAMPLE_FLEXSPI, SPINOR_VOLATILE_CFG_REG_ADDR_IO_MODE_GIGADEVICE,
                                 FLASH_PORT, kFLEXSPI_Read, NOR_CMD_LUT_SEQ_IDX_CONFIG, 1, &val, 1);
    if (status != kStatus_Success)
    {
        return status;
    }
    else
    {
        if (val == SPINOR_IO_MODE_OCTAL_DTR_WITH_DQS_GIGADEVICE)
        {
            flash_state.spiMode = SPINOR_OPI_MODE;
        }
    }

    return status;
}

status_t flexspi_nor_enable_octal_for_macronix(FLEXSPI_Type *base)
{
    status_t status = kStatus_Fail;
    /* MXIC's octal flash. */
    uint32_t value = CR2_DTR_OPI_ENABLE_MACRONIX;

#if defined(EXAMPLE_FLASH_RESET_CONFIG)
    uint32_t TempOctalReadDDRLUTCommandSeq[4];

    if (OctalReadDDRLUTCommandSeq[0] != 0U)
    {
        memcpy(TempOctalReadDDRLUTCommandSeq, OctalReadDDRLUTCommandSeq, sizeof(OctalReadDDRLUTCommandSeq));
    }
    else
    {
        /* use default look up table */
        memcpy(TempOctalReadDDRLUTCommandSeq, defaultOctalReadDDRLUTCommandSeq, sizeof(defaultOctalReadDDRLUTCommandSeq));
    }
#endif

    /* Write enable */
    status = flexspi_nor_write_enable(base, 0, false);

    if (status != kStatus_Success)
    {
        return status;
    }

    /* Enable octal mode. */
    status = flexspi_nor_exec_op(base, 0, FLASH_PORT, kFLEXSPI_Write, NOR_CMD_LUT_SEQ_IDX_ENTEROPI, 1,
                                 &value, 1);
    if (status != kStatus_Success)
    {
        return status;
    }

    status = flexspi_nor_wait_bus_busy(base, true);
    if (status == kStatus_Success)
    {
        flash_state.spiMode = SPINOR_OPI_MODE;

#if defined(EXAMPLE_FLASH_RESET_CONFIG)
        /*
	 * 8DTRD: enter octal DDR and update read LUT entry into 8DTRD. OCTAL DTR(Double Transfer Rate) Read Mode(from MACRONIX's datasheet).
	 */
        FLEXSPI_UpdateLUT(base, 4 * NOR_CMD_LUT_SEQ_IDX_READ, TempOctalReadDDRLUTCommandSeq, 4);
#endif
    }

    return status;
}

status_t flexspi_nor_enable_octal_mode(FLEXSPI_Type *base)
{
    status_t status = kStatus_Success;
    /*
     * Copy LUT information from flash region into RAM region, because flash boot mode maybe not same with application's
     * required mode.
     * If yes, doesn't need to memory copy operation; if no, need to memory opeation before flash access failure due to
     * mismatch LUT read command sequence.
     */
#if defined(CACHE_MAINTAIN) && CACHE_MAINTAIN
    flexspi_cache_status_t cacheStatus;
    flexspi_nor_disable_cache(&cacheStatus);
#endif

    if (flash_state.spiMode != SPINOR_OPI_MODE) /* When flash is not in OPI Mode */
    {
        switch (flash_state.manufacturerId) /* Manufacturer ID */
        {
#if FLASH_ADESTO_DEVICE_ATXP032
            case (SNOR_MFR_ADESTO):
            {
                status = flexspi_nor_enable_octal_for_adesto(base);
                if (status != kStatus_Success)
                {
                    return status;	
                }
            }
            break;
#endif
#if FLASH_GIGADEVICE_DEVICE_GD25LX256
            case (SNOR_MFR_GIGADEVICE):
            {
                status = flexspi_nor_enable_octal_for_gigadevice(base);
                if (status != kStatus_Success)
                {
                    return status;	
                }
            }
            break;
#endif
            case (SNOR_MFR_MACRONIX):
            {
                status = flexspi_nor_enable_octal_for_macronix(base);
                if (status != kStatus_Success)
                {
                    return status;	
                }
            }
            break;
            default:
                break;
        }

    }

    /* Do software reset. */
    FLEXSPI_SoftwareReset(base);

#if defined(CACHE_MAINTAIN) && CACHE_MAINTAIN
    flexspi_nor_enable_cache(cacheStatus);
#endif

    return status;
}

status_t flexspi_nor_flash_erase_sector(FLEXSPI_Type *base, uint32_t address)
{
    status_t status;

#if defined(CACHE_MAINTAIN) && CACHE_MAINTAIN
    flexspi_cache_status_t cacheStatus;
    flexspi_nor_disable_cache(&cacheStatus);
#endif

    /* Write enable */
    status = flexspi_nor_write_enable(base, 0, true);

    if (status != kStatus_Success)
    {
        return status;
    }

    status =
        flexspi_nor_exec_op(base, address, FLASH_PORT, kFLEXSPI_Command, NOR_CMD_LUT_SEQ_IDX_ERASESECTOR, 1, NULL, 0);
    if (status != kStatus_Success)
    {
        return status;
    }

    status = flexspi_nor_wait_bus_busy(base, true);

    /* Do software reset. */
    FLEXSPI_SoftwareReset(base);

#if defined(CACHE_MAINTAIN) && CACHE_MAINTAIN
    flexspi_nor_enable_cache(cacheStatus);
#endif

    return status;
}

status_t flexspi_nor_flash_page_program(FLEXSPI_Type *base, uint32_t dstAddr, const uint32_t *src)
{
    status_t status;

#if defined(CACHE_MAINTAIN) && CACHE_MAINTAIN
    flexspi_cache_status_t cacheStatus;
    flexspi_nor_disable_cache(&cacheStatus);
#endif

    /* Write neable */
    status = flexspi_nor_write_enable(base, dstAddr, true);

    if (status != kStatus_Success)
    {
        return status;
    }

    /* Prepare page program command */
    status = flexspi_nor_exec_op_with_edma(base, dstAddr, FLASH_PORT, kFLEXSPI_Write, NOR_CMD_LUT_SEQ_IDX_PAGEPROGRAM, 1,
                                 (uint32_t *)src, FLASH_PAGE_SIZE);

    if (status != kStatus_Success)
    {
        return status;
    }

    /*  Wait for transfer completed. */
    while (!g_completionFlag)
    {
    }
    g_completionFlag = false;

    status = flexspi_nor_wait_bus_busy(base, true);

    /* Do software reset. */
    FLEXSPI_SoftwareReset(base);

#if defined(CACHE_MAINTAIN) && CACHE_MAINTAIN
    flexspi_nor_enable_cache(cacheStatus);
#endif

    return status;
}

#if 0
status_t flexspi_nor_flash_page_program(FLEXSPI_Type *base, uint32_t dstAddr, const uint32_t *src)
{
    status_t status;
    flexspi_transfer_t flashXfer;

#if defined(CACHE_MAINTAIN) && CACHE_MAINTAIN
    flexspi_cache_status_t cacheStatus;
    flexspi_nor_disable_cache(&cacheStatus);
#endif

    /* Write neable */
    status = flexspi_nor_write_enable(base, dstAddr, true);

    if (status != kStatus_Success)
    {
        return status;
    }

    /* Prepare page program command */
    flashXfer.deviceAddress = dstAddr;
    flashXfer.port          = FLASH_PORT;
    flashXfer.cmdType       = kFLEXSPI_Write;
    flashXfer.SeqNumber     = 1;
    flashXfer.seqIndex      = NOR_CMD_LUT_SEQ_IDX_PAGEPROGRAM;
    flashXfer.data          = (uint32_t *)src;
    flashXfer.dataSize      = FLASH_PAGE_SIZE;
    status                  = FLEXSPI_TransferEDMA(base, &flexspiHandle, &flashXfer);

    if (status != kStatus_Success)
    {
        return status;
    }

    /*  Wait for transfer completed. */
    while (!g_completionFlag)
    {
    }
    g_completionFlag = false;

    status = flexspi_nor_wait_bus_busy(base, true);

    /* Do software reset. */
    FLEXSPI_SoftwareReset(base);

#if defined(CACHE_MAINTAIN) && CACHE_MAINTAIN
    flexspi_nor_enable_cache(cacheStatus);
#endif

    return status;
}
#endif

status_t flexspi_nor_read_data(FLEXSPI_Type *base, uint32_t startAddress, uint32_t *buffer, uint32_t length)
{
    status_t status;

    /* Read page. */
    status =
        flexspi_nor_exec_op_with_edma(base, startAddress, FLASH_PORT, kFLEXSPI_Read, NOR_CMD_LUT_SEQ_IDX_READ, 1, buffer, length);

    if (status != kStatus_Success)
    {
        return status;
    }

    /*  Wait for transfer completed. */
    while (!g_completionFlag)
    {
    }
    g_completionFlag = false;

    /* Do software reset. */
    FLEXSPI_SoftwareReset(base);


    return status;
}

#if 0
status_t flexspi_nor_read_data(FLEXSPI_Type *base, uint32_t startAddress, uint32_t *buffer, uint32_t length)
{
    status_t status;
    flexspi_transfer_t flashXfer;
    uint32_t readAddress = startAddress;

    /* Read page. */
    flashXfer.deviceAddress = readAddress;
    flashXfer.port          = FLASH_PORT;
    flashXfer.cmdType       = kFLEXSPI_Read;
    flashXfer.SeqNumber     = 1;
    flashXfer.seqIndex      = NOR_CMD_LUT_SEQ_IDX_READ;
    flashXfer.data          = buffer;
    flashXfer.dataSize      = length;

    status = FLEXSPI_TransferEDMA(base, &flexspiHandle, &flashXfer);

    if (status != kStatus_Success)
    {
        return status;
    }

    /*  Wait for transfer completed. */
    while (!g_completionFlag)
    {
    }
    g_completionFlag = false;

    /* Do software reset. */
    FLEXSPI_SoftwareReset(base);

    return status;
}
#endif

#if defined(__ICCARM__)
#pragma optimize = none
#endif
__attribute__((weak)) status_t flexspi_nor_get_id(FLEXSPI_Type *base, uint8_t *Id)
{
    /* Read manufacturer ID based on JEP106V spec, max continuation code table is 9, max manufacturer ID starts from
     * 9 + 1. */
    uint8_t id[SPI_NOR_MAX_ID_LEN] = {0x00U};
    status_t status                = kStatus_Fail;
    uint8_t seqIdx                 = NOR_CMD_LUT_SEQ_IDX_READID_SPI;

#ifdef NOR_CMD_LUT_SEQ_IDX_READID_OPI
    if (flash_state.spiMode == SPINOR_OPI_MODE)
    {
        seqIdx = NOR_CMD_LUT_SEQ_IDX_READID_OPI;
    }
#endif

    status = flexspi_nor_exec_op(base, 0, FLASH_PORT, kFLEXSPI_Read, seqIdx, 1, (uint32_t *)id, sizeof(id));

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

status_t flexspi_nor_flash_init(FLEXSPI_Type *base, uint8_t *id)
{
    flexspi_config_t config;
    /* To store custom's LUT table in local. */
    uint32_t tempCustomLUT[CUSTOM_LUT_LENGTH] = {0U};
    status_t status;
    uint32_t val = 0;

    /* memcpy/memset api is running in nor flash, so make sure that copy the data as soon as possible */
#if defined(EXAMPLE_FLASH_RESET_CONFIG)
    uint32_t TempFastReadSDRLUTCommandSeq[4];

    if (FastReadSDRLUTCommandSeq[0] != 0U)
    {
        memcpy(TempFastReadSDRLUTCommandSeq, FastReadSDRLUTCommandSeq, sizeof(FastReadSDRLUTCommandSeq));
    }
    else
    {
        memcpy(TempFastReadSDRLUTCommandSeq, defaultFastReadSDRLUTCommandSeq, sizeof(defaultFastReadSDRLUTCommandSeq));
    }
#endif
    /*
     * Copy LUT information from flash region into RAM region, because flash will be reset and back to single mode;
     * In lately time, LUT table assignment maybe failed after flash reset due to LUT read entry is application's
     * required mode(such as octal DDR mode) and flash is being in single SDR mode, they don't matched.
     */
    if (customLUTOctalMode[0] != 0U)
    {
        memcpy(tempCustomLUT, customLUTOctalMode, sizeof(tempCustomLUT));
    }
    else
    {
        memcpy(tempCustomLUT, defaultLUTOctalMode, sizeof(tempCustomLUT));
    }

#if defined(CACHE_MAINTAIN) && CACHE_MAINTAIN
    flexspi_cache_status_t cacheStatus;
    flexspi_nor_disable_cache(&cacheStatus);
#endif

    /*Get FLEXSPI default settings and configure the flexspi. */
    FLEXSPI_GetDefaultConfig(&config);

    /*Set AHB buffer size for reading data through AHB bus. */
    config.ahbConfig.enableAHBPrefetch = true;
    config.rxSampleClock               = EXAMPLE_FLEXSPI_RX_SAMPLE_CLOCK;
#if !(defined(FSL_FEATURE_FLEXSPI_HAS_NO_MCR0_COMBINATIONEN) && FSL_FEATURE_FLEXSPI_HAS_NO_MCR0_COMBINATIONEN)
    config.enableCombination = true;
#endif
    config.ahbConfig.enableAHBBufferable = true;
    config.ahbConfig.enableAHBCachable   = true;
    FLEXSPI_Init(base, &config); /* The FLEXSPI_Init api does flexspi software reset */

    /* Configure flash settings according to serial flash feature. */
    FLEXSPI_SetFlashConfig(base, &deviceconfig, FLASH_PORT);

    /* Update LUT table into a specific mode, such as octal SDR mode or octal DDR mode based on application's
     * requirement. */
    FLEXSPI_UpdateLUT(base, 0, tempCustomLUT, ARRAY_SIZE(tempCustomLUT));

#if defined(EXAMPLE_FLASH_RESET_CONFIG) && (FLASH_ADESTO_DEVICE_ATXP032 || FLASH_GIGADEVICE_DEVICE_GD25LX256)
    FLEXSPI_UpdateLUT(base, 4 * NOR_CMD_LUT_SEQ_IDX_READ, TempFastReadSDRLUTCommandSeq,
                      4); /* Make sure that cpu could load instruction from flash correctly */
#endif

    /* Do software reset. */
    FLEXSPI_SoftwareReset(base);

    /* detect which mode flash is in(SPI, OPI) */
    status = flexspi_nor_exec_op(base, 0, FLASH_PORT, kFLEXSPI_Read, NOR_CMD_LUT_SEQ_IDX_READSTATUS_OPI, 1, &val,
                                 1); /* flash is in OPI mode when status is kStatus_Success */
    if (status == kStatus_Success)
    {
        flash_state.spiMode = SPINOR_OPI_MODE; /* flash is in OPI Mode */
    }
    else
    {
        status = flexspi_nor_exec_op(base, 0, FLASH_PORT, kFLEXSPI_Read, NOR_CMD_LUT_SEQ_IDX_READSTATUS, 1, &val,
                                     1); /* flash is in SPI mode when status is kStatus_Success */
        if (status != kStatus_Success)
        {
            return status;
        }
        flash_state.spiMode = SPINOR_SPI_MODE; /* flash is in SPI Mode */
    }

    status = flexspi_nor_get_id(base, id);
    if (status != kStatus_Success)
    {
        return status;
    }
    flash_state.manufacturerId = id[0];

    switch (flash_state.manufacturerId) /* Manufacturer ID */
    {
#if FLASH_ADESTO_DEVICE_ATXP032
        case (SNOR_MFR_ADESTO):
        {
            /*
             * Copy LUT information from flash region into RAM region, because LUT update maybe corrupt read
             * sequence(LUT[0]) and load wrong LUT table from FLASH region.
             */

            memcpy(tempCustomLUT, defaultLUTOctalMode_ADESTO, sizeof(tempCustomLUT));
            /*
             * Update LUT table into a specific mode, such as octal SDR mode or octal DDR mode based on application's
             * requirement.
             */

            FLEXSPI_UpdateLUT(base, 0, tempCustomLUT, ARRAY_SIZE(tempCustomLUT));
#if defined(EXAMPLE_FLASH_RESET_CONFIG)
            if (flash_state.spiMode == SPINOR_SPI_MODE)
            {
                /*
                 * Make sure that cpu could load instruction from flash correctly(cpu will load
                 * instruction when execute the function EXAMPLE_FLASH_RESET_CONFIG).
                 */
                FLEXSPI_UpdateLUT(base, 4 * NOR_CMD_LUT_SEQ_IDX_READ, TempFastReadSDRLUTCommandSeq, 4);
            }
#endif
        }
        break;
#endif
#if FLASH_GIGADEVICE_DEVICE_GD25LX256
        case (SNOR_MFR_GIGADEVICE):
        {
            if (flash_state.spiMode == SPINOR_SPI_MODE)
            {
                uint32_t tempLUT[4] = {0};

                /*
                 * Copy LUT information from flash region into RAM region, because LUT update maybe corrupt read
                 * sequence(LUT[0]) and load wrong LUT table from FLASH region.
                 */
                memcpy(tempCustomLUT, defaultLUTOctalMode_GIGADEVICE, sizeof(tempCustomLUT));
                /*
                 * Update LUT table into a specific mode, such as octal SDR mode or octal DDR mode based on
                 * application's requirement.
                 */

                FLEXSPI_UpdateLUT(
                    base, 0, tempCustomLUT,
                    ARRAY_SIZE(tempCustomLUT)); /* NOR_CMD_LUT_SEQ_IDX_READ lookup table will be replaced */

#if defined(EXAMPLE_FLASH_RESET_CONFIG)
                FLEXSPI_UpdateLUT(base, 4 * NOR_CMD_LUT_SEQ_IDX_READ, TempFastReadSDRLUTCommandSeq,
                                  4); /* Make sure that cpu could load instruction from flash correctly */
#endif

                memset((void *)tempLUT, 0, sizeof(tempLUT));

                tempLUT[0] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_1PAD, SPINOR_OP_RDFSR,
                                             kFLEXSPI_Command_READ_SDR, kFLEXSPI_1PAD, SPINOR_DATA_SIZE_4_BYTES);
                /* Update LUT table. */
                FLEXSPI_UpdateLUT(base, 4 * NOR_CMD_LUT_SEQ_IDX_CONFIG, tempLUT, ARRAY_SIZE(tempLUT));

                /* Read flag status register in SDR SPI Mode */
                status =
                    flexspi_nor_exec_op(base, 0, FLASH_PORT, kFLEXSPI_Read, NOR_CMD_LUT_SEQ_IDX_CONFIG, 1, &val, 1);
                if (status == kStatus_Success)
                {
                    memset((void *)tempLUT, 0, sizeof(tempLUT));
                    /* check address mode(Flag Status Register FS0, ADS), in 4-Byte address mode when ADS = 1 */
                    flash_state.addrMode = val & FSR_ADS_GIGADEVICE;

                    if (flash_state.addrMode != true)
                    {
                        /* change from 3-byte address mode to 4-byte address mode in SDR SPI Mode */
                        tempLUT[0] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_1PAD,
                                                     SPINOR_OP_ENABLE_4_BYTE_ADDR_MODE_GIGADEVICE,
                                                     kFLEXSPI_Command_STOP, kFLEXSPI_1PAD, 0x0);
                        /* Update LUT table. */
                        FLEXSPI_UpdateLUT(base, 4 * NOR_CMD_LUT_SEQ_IDX_CONFIG, tempLUT, ARRAY_SIZE(tempLUT));
                        /* Enable 4-Byte Mode in SPI SDR Mode */
                        status = flexspi_nor_exec_op(base, 0, FLASH_PORT, kFLEXSPI_Command, NOR_CMD_LUT_SEQ_IDX_CONFIG, 1,
                                                     NULL, 0);

                        if (status == kStatus_Success)
                        {
                            tempLUT[0] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_1PAD, SPINOR_OP_RDFSR,
                                                         kFLEXSPI_Command_READ_SDR, kFLEXSPI_1PAD, SPINOR_DATA_SIZE_4_BYTES);
                            /* Update LUT table. */
                            FLEXSPI_UpdateLUT(base, 4 * NOR_CMD_LUT_SEQ_IDX_CONFIG, tempLUT, ARRAY_SIZE(tempLUT));

                            /* Read flag status register in SDR SPI Mode */
                            status = flexspi_nor_exec_op(base, 0, FLASH_PORT, kFLEXSPI_Read, NOR_CMD_LUT_SEQ_IDX_CONFIG,
                                                         1, &val, 1);
                            if (status != kStatus_Success)
                            {
                                return status;
                            }
                            else
                            {
                                if (val & FSR_ADS_GIGADEVICE)
                                {
                                    flash_state.addrMode = true;
                                }
                            }
                        }
                    }
                }
                else
                {
                    return status;
                }
            }
        }
        break;
#endif
        case (SNOR_MFR_MACRONIX):
            break;
        default:
            break;
    }

    /* Create handle for flexspi. */
    FLEXSPI_TransferCreateHandleEDMA(base, &flexspiHandle, flexspi_callback, NULL, &dmaTxHandle, &dmaRxHandle);

#if defined(EXAMPLE_FLASH_RESET_CONFIG)
    EXAMPLE_FLASH_RESET_CONFIG();
    /* FAST_READ4B: back to single mode and update read LUT entry into FAST_READ4B after flash reset,
           to make sure fetch code/data from flash is right. */
    FLEXSPI_UpdateLUT(base, 4 * NOR_CMD_LUT_SEQ_IDX_READ, TempFastReadSDRLUTCommandSeq, 4);
#endif

#if defined(EXAMPLE_INVALIDATE_FLEXSPI_CACHE)
    EXAMPLE_INVALIDATE_FLEXSPI_CACHE();
#endif

#if defined(CACHE_MAINTAIN) && CACHE_MAINTAIN
    flexspi_nor_enable_cache(cacheStatus);
#endif

    return status;
}

#if 0
void flexspi_nor_flash_init(FLEXSPI_Type *base)
{
    flexspi_config_t config;
    /* To store custom's LUT table in local. */
    uint32_t tempCustomLUT[CUSTOM_LUT_LENGTH] = {0U};
    status_t status;
    uint32_t val = 0;

#if defined(CACHE_MAINTAIN) && CACHE_MAINTAIN
    flexspi_cache_status_t cacheStatus;
    flexspi_nor_disable_cache(&cacheStatus);
#endif

    /*Get FLEXSPI default settings and configure the flexspi. */
    FLEXSPI_GetDefaultConfig(&config);

    /*Set AHB buffer size for reading data through AHB bus. */
    config.ahbConfig.enableAHBPrefetch = true;
    config.rxSampleClock               = EXAMPLE_FLEXSPI_RX_SAMPLE_CLOCK;
#if !(defined(FSL_FEATURE_FLEXSPI_HAS_NO_MCR0_COMBINATIONEN) && FSL_FEATURE_FLEXSPI_HAS_NO_MCR0_COMBINATIONEN)
    config.enableCombination = true;
#endif
    config.ahbConfig.enableAHBBufferable = true;
    config.ahbConfig.enableAHBCachable   = true;
    FLEXSPI_Init(base, &config);

    /* Configure flash settings according to serial flash feature. */
    FLEXSPI_SetFlashConfig(base, &deviceconfig, FLASH_PORT);

    /* Copy LUT information from flash region into RAM region, because flash will be reset and back to single mode;
       In lately time, LUT table assignment maybe failed after flash reset due to LUT read entry is application's
       required mode(such as octal DDR mode) and flash is being in single SDR mode, they don't matched. */
#if defined(EXAMPLE_FLASH_RESET_CONFIG)
    uint32_t TempFastReadSDRLUTCommandSeq[4];

    memcpy(TempFastReadSDRLUTCommandSeq, FastReadSDRLUTCommandSeq, sizeof(FastReadSDRLUTCommandSeq));
#endif

#if (defined(XIP_EXTERNAL_FLASH) && XIP_EXTERNAL_FLASH == 1) && (FLASH_ADESTO == 1)
    uint32_t tempLUT[4] = {0};
    uint32_t tmpFastReadSDRLUTCommandSeq[4];
    /* Exit octal mode command. */
    tempLUT[0] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_8PAD, 0xFF, kFLEXSPI_Command_STOP, kFLEXSPI_8PAD, 0x0);
    memcpy(tmpFastReadSDRLUTCommandSeq, FastReadSDRLUTCommandSeq, sizeof(FastReadSDRLUTCommandSeq));
#endif

    /* Copy LUT information from flash region into RAM region, because LUT update maybe corrupt read sequence(LUT[0])
     * and load wrong LUT table from FLASH region. */
    memcpy(tempCustomLUT, customLUTOctalMode, sizeof(tempCustomLUT));
    FLEXSPI_UpdateLUT(base, 0, tempCustomLUT, CUSTOM_LUT_LENGTH);

    /* Do software reset. */
    FLEXSPI_SoftwareReset(base);

#if (defined(XIP_EXTERNAL_FLASH) && XIP_EXTERNAL_FLASH == 1) && (FLASH_ADESTO == 1)
    status_t status;
    flexspi_transfer_t flashXfer;

    /* Update for standard mode. */
    FLEXSPI_UpdateLUT(base, 4 * NOR_CMD_LUT_SEQ_IDX_READ, tmpFastReadSDRLUTCommandSeq, 4);
    /* Update for exit octal mode. */
    FLEXSPI_UpdateLUT(base, 4 * NOR_CMD_LUT_SEQ_IDX_CONFIG, tempLUT, 4);

    /* Write enable */
    status = flexspi_nor_write_enable(base, 0, true);

    /* Back to standard SPI mode. */
    flashXfer.deviceAddress = 0;
    flashXfer.port          = FLASH_PORT;
    flashXfer.cmdType       = kFLEXSPI_Command;
    flashXfer.SeqNumber     = 1;
    flashXfer.seqIndex      = NOR_CMD_LUT_SEQ_IDX_CONFIG;

    status = FLEXSPI_TransferBlocking(base, &flashXfer);

    if (status == kStatus_Success)
    {
        status = flexspi_nor_wait_bus_busy(base, false);
    }
#endif

    /* Create handle for flexspi. */
    FLEXSPI_TransferCreateHandleEDMA(base, &flexspiHandle, flexspi_callback, NULL, &dmaTxHandle, &dmaRxHandle);

#if defined(EXAMPLE_FLASH_RESET_CONFIG)
    EXAMPLE_FLASH_RESET_CONFIG();
    /* FAST_READ4B: back to single mode and update read LUT entry into FAST_READ4B after flash reset,
           to make sure fetch code/data from flash is right. */
    FLEXSPI_UpdateLUT(base, 4 * NOR_CMD_LUT_SEQ_IDX_READ, TempFastReadSDRLUTCommandSeq, 4);
#endif

#if defined(EXAMPLE_INVALIDATE_FLEXSPI_CACHE)
    EXAMPLE_INVALIDATE_FLEXSPI_CACHE();
#endif

#if defined(CACHE_MAINTAIN) && CACHE_MAINTAIN
    flexspi_nor_enable_cache(cacheStatus);
#endif
}
#endif
