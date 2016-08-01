/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
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

///////////////////////////////////////////////////////////////////////////////
//  Includes
///////////////////////////////////////////////////////////////////////////////
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "epit.h"
#include "shared_clock_manage.h"
#include "lpm_mcore.h"
#include "debug_console_imx.h"
#include "board.h"

#if (1 != configUSE_IDLE_HOOK)
#error "To run this demo, please enable configUSE_IDLE_HOOK configuration in FreeRTOSConfig.h!"
#endif

////////////////////////////////////////////////////////////////////////////////
// Constants
////////////////////////////////////////////////////////////////////////////////
#define SHARED_CM_OCRAM_START       0x2091F000
#define SHARED_CM_SMEA4_GATE_NUM    (6)

/*
 * Demo configuration :
 *      If DEMO_LPM_MCORE_CONFIGURATION is set to 0, the demo is running with an EPIT
 *    timer. M4 platform will switch between high power running mode and low power
 *    running mode every 10 seconds. This is the default demo mode
 *      If DEMO_LPM_MCORE_CONFIGURATION is set to 1, the demo is running without an
 *    EPIT timer. M4 platform will go directly to low power running mode. This mode
 *    will make it easier to test the system low power data. The user should manually
 *    change the macro to 1 for this purpose.
 */
#define DEMO_LPM_MCORE_CONFIGURATION    (0)

////////////////////////////////////////////////////////////////////////////////
// Static variables
////////////////////////////////////////////////////////////////////////////////
static SemaphoreHandle_t xSemaphore;

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

/*FUNCTION*----------------------------------------------------------------*
* Function Name  : BOARD_EPITA_HANDLER
* Returned Value : void
* Comments :
*       The EPIT Interrupt Service Routine.
*END*----------------------------------------------------------------------*/
void BOARD_EPITA_HANDLER(void)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    /* Just Wake M4 Core from WFI and clear IRQ after that. */
    EPIT_ClearStatusFlag(BOARD_EPITA_BASEADDR);

    /* Release EPIT overflow Sem4. */
    xSemaphoreGiveFromISR(xSemaphore, &xHigherPriorityTaskWoken);

    /* Perform a context switch to wake the higher priority task. */
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

/*TASK*------------------------------------------------------------------------------
* Task Name    : WfiTask
* Comments     : the main cycle of this task is switching m4 clock source between PLL_PFD
*                and OSC on EPIT timer event. When switching to OSC, it will also disable
*                non-wakeup interrupts and call LPM_MCORE_SetPowerStatus API to let
*                next idle task scheduling put the core into deep sleep (sticking to WFI
*                in TCM code).
*                EPIT timer also acts as wakeup source. Once timer reaches, it will drag M4 out
*                of TCM WFI. The TCM will handshake with A9 to ensure all necessary
*                resources for M4 to run in full speed in QSPI are ready. After that the
*                timer ISR will be invoked so that all the interrupt can be re-enabled,
*                m4 core clock source will change back to PLL and LPM_MCORE_SetPowerStatus
*                API will be called again to disable idle task to enter deep sleep.
*END*------------------------------------------------------------------------------*/
void WfiTask(void *pvParameters)
{
    PRINTF("Waiting for A9 Side Ready...\r\n");
    while (!SharedClk_GetPeerReady())
    {
        vTaskDelay(5);
    }

    /* For normal demo exhibition. */
#if (0 == DEMO_LPM_MCORE_CONFIGURATION)
    xSemaphore = xSemaphoreCreateBinary();

    /* EPIT start */
    EPIT_Enable(BOARD_EPITA_BASEADDR);

    while (1)
    {
        if (STATUS_NORMAL_RUN == LPM_MCORE_GetPowerStatus())
        {
            /* Register EPIT1 as A9 wakeup source */
            LPM_MCORE_RegisterPeerWakeup(EPIT1_IRQn, WAKEUP_ENABLE);

            PRINTF("\r\nAllow deep sleep\r\n");
            /* Allow idle task to enter Ram WFI */
            LPM_MCORE_SetPowerStatus(STATUS_LOWPOWER_RUN);
        }
        else
        {
            /* Don't allow idle task to enter Ram WFI */
            LPM_MCORE_SetPowerStatus(STATUS_NORMAL_RUN);
            PRINTF("\r\nDeny deep sleep\r\n");

            /* Unregister EPIT A9 wakeup source */
            LPM_MCORE_RegisterPeerWakeup(EPIT1_IRQn, WAKEUP_DISABLE);
        }

        /* Wait until EPIT overflow */
        xSemaphoreTake(xSemaphore, portMAX_DELAY);
    }

    /* For system low-power data test. */
#elif (1 == DEMO_LPM_MCORE_CONFIGURATION)
    PRINTF("A9 low power operation allowed forever...\r\n");
    LPM_MCORE_SetPowerStatus(STATUS_LOWPOWER_RUN);

    while (1)
    {
        vTaskDelay(portMAX_DELAY);
    }
#endif
}

/*FUNCTION*----------------------------------------------------------------*
* Function Name  : vApplicationIdleHook
* Returned Value : void
* Comments :
*       FreeRTOS will schedule to Idle Task when no user defined task is
*       ready. The vApplicationIdleHook will called inside of Idle Task
*       and we use it to set M4 Core to low-power state when no other 
*       task is running.
*
*END*----------------------------------------------------------------------*/
void vApplicationIdleHook(void)
{
    /* Waiting for Wake up event. */
    LPM_MCORE_WaitForInt();
}

/*FUNCTION*----------------------------------------------------------------*
* Function Name  : main
* Returned Value : int
* Comments :
*       Initialize hardware resource used in this demo, create
*       WFI Task and start FreeRTOS Kernel.
*END*----------------------------------------------------------------------*/
int main(void)
{
    shared_clk_init_config_t sharedClkConfig = {
        /* Start Address for Appointed Memory for Shared clock management. */
        .shareMemStartAddress = SHARED_CM_OCRAM_START,
        /* The Sema4 base address used in shared clock management. */
        .sema4BaseAddress     = BOARD_SEMA4_BASEADDR,
        /* The Sema4 gate number used in shared clock management. */
        .sema4Num             = SHARED_CM_SMEA4_GATE_NUM
    };

    epit_init_config_t initConfig = {
        .freeRun     = true,
        .waitEnable  = true,
        .stopEnable  = true,
        .dbgEnable   = true,
        .enableMode  = true
    };

    // Initialize demo application pins setting and clock setting.
    hardware_init();

    PRINTF(" ************************************************************************\r\n");
    PRINTF(" *         i.MX 6SoloX Dual Core Low Power Demo - M4 side               *\r\n");
    PRINTF(" *                                                                      *\r\n");
    PRINTF(" *       A EPIT will change the M4 running speed every 5s               *\r\n");
    PRINTF(" *                                                                      *\r\n");
    PRINTF(" ************************************************************************\r\n");

    /*
     * Initialize Shared Clock manager:
     * You need to enable the clock nodes used in your application here
     * to remind A9 Core these clock nodes are used by M4 Core. A9 Core
     * will keep the clock nodes available in low-power state. 
     * By default all Clock Nodes are disabled. Closing the unused Clock
     * Node can achieve the lowest power consumption level.
     */
    SharedClk_Init(&sharedClkConfig);
    SharedClk_AcquireLock();
    SharedClk_EnabeNode(SHARED_CLK_QSPI1);
    SharedClk_EnabeNode(SHARED_CLK_QSPI2);
    SharedClk_EnabeNode(SHARED_CLK_UART);
    SharedClk_EnabeNode(SHARED_CLK_UART_IPG);
    SharedClk_EnabeNode(SHARED_CLK_EPIT1);
    SharedClk_ReleaseLock();

    /*
     * Initialize Dual-Core low-power mechanism:
     *
     * This function is used to initialize the Dual-Core low-power 
     * handshake mechanism. When M4 enter into low power run state,
     * A9 Core will switch M4 Core clock to 24M to achieve lowest
     * power consumption level.
     */
    LPM_MCORE_Init();

    /* Initialize EPIT module */
    EPIT_Init(BOARD_EPITA_BASEADDR, &initConfig);

    /* Set EPIT clock source */
    EPIT_SetClockSource(BOARD_EPITA_BASEADDR, epitClockSourceLowFreq);

    /* Divide EPITA clock source frequency by 2 inside EPIT module */
    EPIT_SetPrescaler(BOARD_EPITA_BASEADDR, 1);

    /* Set EPIT to overflow every 5s */
    EPIT_SetCounterLoadValue(BOARD_EPITA_BASEADDR, 5 * (32768/2));
    EPIT_SetOutputCompareValue(BOARD_EPITA_BASEADDR, 0);

    /* Enable EPIT Interrupt */
    NVIC_SetPriority(BOARD_EPITA_IRQ_NUM, 3);
    NVIC_EnableIRQ(BOARD_EPITA_IRQ_NUM);
    EPIT_SetIntCmd(BOARD_EPITA_BASEADDR, true);

    /* Create the demo task. */
    xTaskCreate(WfiTask, "WFI Task", configMINIMAL_STACK_SIZE,
                NULL, tskIDLE_PRIORITY+1, NULL);

    /* Start FreeRTOS scheduler. */
    vTaskStartScheduler();

    /* Should never reach this point. */
    while (true);
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
