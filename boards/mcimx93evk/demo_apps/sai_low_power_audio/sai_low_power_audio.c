/*
 * Copyright 2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "FreeRTOS.h"
#include "task.h"

#include "pin_mux.h"
#include "board.h"
#include "app_srtm.h"
#include "fsl_debug_console.h"
#include "fsl_iomuxc.h"
#include "fsl_lpuart.h"
#include "fsl_mu.h"
#include "rsc_table.h"
#include "fsl_edma.h"
#include "fsl_sai.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
extern volatile app_srtm_state_t srtmState;

/*******************************************************************************
 * Code
 ******************************************************************************/
#define IMX_SRC_BASE            0x44460000
#define M33_ACTIVE_FLAG         (IMX_SRC_BASE + 0x54)
#define M33_ACTIVE              (0x5555)
#define M33_DisACTIVE           (0x0)

void MainTask(void *pvParameters)
{
    /*
     * Wait For A core Side Become Ready
     */
    PRINTF("********************************\r\n");
    PRINTF(" Wait the Linux kernel boot up to create the link between M core and A core.\r\n");
    PRINTF("\r\n");
    PRINTF("********************************\r\n");
    while (srtmState != APP_SRTM_StateLinkedUp)
        ;
    PRINTF("The rpmsg channel between M core and A core created!\r\n");
    PRINTF("********************************\r\n");
    PRINTF("\r\n");

    while (true)
    {
        /* Use App task logic to replace vTaskDelay */
        PRINTF("\r\nTask %s is working now.\r\n", (char *)pvParameters);
        vTaskDelay(portMAX_DELAY);
    }
}

/*!
 * @brief Main function
 */
int main(void)
{
    char *taskID = "A";
    /* clang-format off */
    /* 250MHz DMA clock */
    const clock_root_config_t dmaClkCfg = {
        .clockOff = false,
	.mux = kCLOCK_WAKEUPAXI_ClockRoot_MuxSysPll1Pfd0, // 1000MHz
	.div = 4
    };
    const clock_root_config_t lpi2cClkCfg = {
        .clockOff = false,
	.mux = 0, // 24MHz oscillator source
	.div = 1
    };
    const clock_root_config_t saiClkCfg = {
        .clockOff = false,
        .mux = 1, // select audiopll1out source(393216000 Hz)
        .div = 32 // output 12288000 Hz
    };
    const clock_root_config_t pdmClkCfg = {
        .clockOff = false,
        .mux = 1,
        .div = 32
    };

    sai_master_clock_t saiMasterCfg = {
        .mclkOutputEnable = true,
     };

    BOARD_InitBootPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();

    CLOCK_SetRootClock(kCLOCK_Root_WakeupAxi, &dmaClkCfg);
    CLOCK_SetRootClock(kCLOCK_Root_Pdm, &pdmClkCfg);
    CLOCK_SetRootClock(kCLOCK_Root_Lpi2c1, &lpi2cClkCfg);
    CLOCK_SetRootClock(kCLOCK_Root_Sai3, &saiClkCfg);
    CLOCK_SetRootClock(BOARD_ADP5585_I2C_CLOCK_ROOT, &lpi2cClkCfg);

    /* Select PDM signals */
    adp5585_handle_t handle;
    BOARD_InitADP5585(&handle);
    ADP5585_SetDirection(&handle, (1 << BOARD_ADP5585_PDM_MQS_SEL) | (1 << BOARD_ADP5585_EXP_SEL), kADP5585_Output);
    ADP5585_ClearPins(&handle, (1 << BOARD_ADP5585_PDM_MQS_SEL) | (1 << BOARD_ADP5585_EXP_SEL));

    /* Select SAI3 signals */
    ADP5585_SetDirection(&handle, (1 << BOARD_ADP5585_EXP_SEL), kADP5585_Output);
    ADP5585_ClearPins(&handle, (1 << BOARD_ADP5585_EXP_SEL));

    /* select MCLK direction(Enable MCLK clock) */
    saiMasterCfg.mclkSourceClkHz = CLOCK_GetIpFreq(kCLOCK_Root_Sai3);  /* setup source clock for MCLK */
    saiMasterCfg.mclkHz          = saiMasterCfg.mclkSourceClkHz;       /* setup target clock of MCLK */
    SAI_SetMasterClockConfig(SAI3, &saiMasterCfg);

    /* Request ATF to let DDR active when Cortex-A is suspended */
    *((uint32_t *)M33_ACTIVE_FLAG) = M33_ACTIVE;

    /* copy resource table to destination address(TCM) */
    copyResourceTable();

    APP_SRTM_Init();
    APP_SRTM_StartCommunication();

    PRINTF("\r\n####################  LOW POWER AUDIO TASK ####################\n\r\n");
    PRINTF("    Build Time: %s--%s \r\n", __DATE__, __TIME__);

    if (xTaskCreate(MainTask, "Main Task", 256U, (void *)taskID, tskIDLE_PRIORITY + 1U, NULL) != pdPASS)
    {
        PRINTF("\r\nFailed to create MainTask task\r\n");
        while (1)
        {
        }
    }

    /* Start FreeRTOS scheduler. */
    vTaskStartScheduler();

    /* Application should never reach this point. */
    for (;;)
    {
    }
}
void vApplicationMallocFailedHook(void)
{
    PRINTF("Malloc Failed!!!\r\n");
}
