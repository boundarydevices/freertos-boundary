/*
 * The Clear BSD License
 * Copyright 2017 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted (subject to the limitations in the disclaimer below) provided
 * that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED BY THIS LICENSE.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "fsl_tmu.h"
#include "fsl_debug_console.h"
#include "board.h"

#include "pin_mux.h"
#include "clock_config.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define DEMO_TMU_BASE TMU
#define DEMO_TMU_IMMEDIATE_THRESOLD 0U
#define DEMO_TMU_INTERVAL_VALUE 8U
#define DEMO_TMU_IRQ TEMPMON_LOW_IRQn
#define DEMO_TMU_IRQ_HANDLER_FUNC TEMPMON_LOW_IRQHandler

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
volatile tmu_interrupt_status_t g_tmuInterruptStausStruct;

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
* @brief TMU ISR.
*/
void DEMO_TMU_IRQ_HANDLER_FUNC(void)
{
    uint32_t temp;

    TMU_GetInterruptStatusFlags(DEMO_TMU_BASE, (tmu_interrupt_status_t *)&g_tmuInterruptStausStruct);
    TMU_ClearInterruptStatusFlags(DEMO_TMU_BASE, g_tmuInterruptStausStruct.interruptDetectMask);
    if (0U != (g_tmuInterruptStausStruct.interruptDetectMask & kTMU_ImmediateTemperatureStatusFlags))
    {
        /* For site0. */
        if (0U != (g_tmuInterruptStausStruct.immediateInterruptsSiteMask & kTMU_MonitorSite0))
        {
            TMU_GetImmediateTemperature(TMU, 0U, &temp);
            PRINTF("site 0 immediate temperature is too high. %d°„C\r\n", temp);
        }
        /* For site1. */
        if (0U != (g_tmuInterruptStausStruct.immediateInterruptsSiteMask & kTMU_MonitorSite1))
        {
            TMU_GetImmediateTemperature(TMU, 1U, &temp);
            PRINTF("site 1 immediate temperature is too high. %d°„C\r\n", temp);
        }
    }
}

/*!
 * @brief Main function
 */
int main(void)
{
    tmu_config_t k_tmuConfig;
    tmu_thresold_config_t k_tmuThresoldConfig;

    /* Board specific RDC settings */
    BOARD_RdcInit();
    
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();
    BOARD_InitMemory();

    PRINTF("TMU monitor report example.\r\n");

    /* Initialize the TMU mode. */
    k_tmuConfig.monitorInterval = DEMO_TMU_INTERVAL_VALUE;
    k_tmuConfig.monitorSiteSelection =
        kTMU_MonitorSite0 | kTMU_MonitorSite1; /* Monitor temperature of site 0 and site 1. */
    k_tmuConfig.averageLPF = kTMU_AverageLowPassFilter1_0;
    TMU_Init(DEMO_TMU_BASE, &k_tmuConfig);

    /* Set the temperature threshold. */
    k_tmuThresoldConfig.immediateThresoldEnable = true;
    k_tmuThresoldConfig.AverageThresoldEnable = false;
    k_tmuThresoldConfig.AverageCriticalThresoldEnable = false;
    k_tmuThresoldConfig.immediateThresoldValue = DEMO_TMU_IMMEDIATE_THRESOLD;
    k_tmuThresoldConfig.averageThresoldValue = 0U;
    k_tmuThresoldConfig.averageCriticalThresoldValue = 0U;
    TMU_SetHighTemperatureThresold(DEMO_TMU_BASE, &k_tmuThresoldConfig);

    /* Enable the Immediate temperature threshold exceeded interrupt. */
    TMU_EnableInterrupts(DEMO_TMU_BASE, kTMU_ImmediateTemperatureInterruptEnable);
    EnableIRQ(DEMO_TMU_IRQ);

    /* Enable the monitor mode. */
    TMU_Enable(DEMO_TMU_BASE, true);

    while (true)
    {
    }
}
