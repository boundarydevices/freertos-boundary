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
#include <stdint.h>
#include <stdbool.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "flexcan.h"
#include "debug_console_imx.h"
#include "lpm_mcore.h"
#include "shared_clock_manage.h"
#include "board.h"

#if (1 != configUSE_IDLE_HOOK)
#error "To run this demo, please enable configUSE_IDLE_HOOK configuration in FreeRTOSConfig.h!"
#endif

////////////////////////////////////////////////////////////////////////////////
// Macros
////////////////////////////////////////////////////////////////////////////////
#define SHARED_CM_OCRAM_START       0x2091F000
#define SHARED_CM_SMEA4_GATE_NUM    (6)

#define FLEXCAN_RX_MSG_BUF_NUM      (9)
#define FLEXCAN_RX_IDENTIFIER       (0x123)
#define FLEXCAN_GLOBAL_MASK         (0x123)

////////////////////////////////////////////////////////////////////////////////
// Constants
////////////////////////////////////////////////////////////////////////////////
const flexcan_timing_t timing_table[] = {
    {7, 3, 7, 7, 6},  /* 125 kHz from 24 MHz OSC */
    {3, 3, 7, 7, 6},  /* 250 kHz from 24 MHz OSC */
    {1, 3, 7, 7, 6},  /* 500 kHz from 24 MHz OSC */
    {0, 3, 7, 7, 6},  /* 1   MHz from 24 MHz OSC */
};

////////////////////////////////////////////////////////////////////////////////
// Static variables
////////////////////////////////////////////////////////////////////////////////
static QueueHandle_t     xQueue;
static SemaphoreHandle_t xSemaphore;

////////////////////////////////////////////////////////////////////////////////
// Function Declarations
////////////////////////////////////////////////////////////////////////////////
static void init_Flexcan(void);
static void FLEXCAN_EnterStopMode(CAN_Type* base);
static void FLEXCAN_ExitStopMode(CAN_Type* base);

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

/*FUNCTION*----------------------------------------------------------------*
* Function Name  : BOARD_FLEXCAN_HANDLER
* Returned Value : void
* Comments :
*       The FlexCAN Interrupt Service Routine.
*END*----------------------------------------------------------------------*/
void BOARD_FLEXCAN_HANDLER(void)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    flexcan_msgbuf_t *rxMsgBufPtr =
            FLEXCAN_GetMsgBufPtr(BOARD_FLEXCAN_BASEADDR, FLEXCAN_RX_MSG_BUF_NUM);

    /* Solve Rx interrupt */
    if (FLEXCAN_GetMsgBufStatusFlag(BOARD_FLEXCAN_BASEADDR, FLEXCAN_RX_MSG_BUF_NUM))
    {
        /* Lock message buffer for receive data. */
        FLEXCAN_LockRxMsgBuf(BOARD_FLEXCAN_BASEADDR, FLEXCAN_RX_MSG_BUF_NUM);
        xQueueSendFromISR(xQueue, (void *)&rxMsgBufPtr->data0, &xHigherPriorityTaskWoken);
        FLEXCAN_UnlockAllRxMsgBuf(BOARD_FLEXCAN_BASEADDR);

        FLEXCAN_ClearMsgBufStatusFlag(BOARD_FLEXCAN_BASEADDR, FLEXCAN_RX_MSG_BUF_NUM);

        /* Perform a context switch to wake the higher priority task. */
        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    }

    /* Solve Self Wakeup interrupt */
    if (FLEXCAN_GetErrStatusFlag(BOARD_FLEXCAN_BASEADDR, flexcanStatusWake))
    {
        /* 
         * Note: User should exit FlexCAN Stop Mode before clean Wakeup status flag.
         */
        FLEXCAN_ExitStopMode(BOARD_FLEXCAN_BASEADDR);

        /* Clean FlexCAN Wakeup interrupt pending bit. */
        FLEXCAN_ClearErrStatusFlag(BOARD_FLEXCAN_BASEADDR, flexcanStatusWake);

        /* Release CanWakeupRxTask */
        xSemaphoreGiveFromISR(xSemaphore, &xHigherPriorityTaskWoken);

        /* Perform a context switch to wake the higher priority task. */
        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    }
}

/*FUNCTION*----------------------------------------------------------------*
* Function Name  : CanWakeupRxTask
* Returned Value : void
* Comments :
*       The FlexCAN Receive and WFI Task.
*END*----------------------------------------------------------------------*/
void CanWakeupRxTask(void *pvParameters)
{
    uint8_t rxData;
    uint32_t result;

    /* Create FlexCan Wakeup Semaphore. */
    xSemaphore = xSemaphoreCreateBinary();

    /* Create FlexCan RX message receive message queue. */
    xQueue = xQueueCreate(10, sizeof(uint8_t));

    PRINTF("Waiting for A9 Side Ready...\r\n");
    while (!SharedClk_GetPeerReady())
    {
        vTaskDelay(5);
    }

    /* Initialize FlexCAN module for Normal receive. */
    init_Flexcan();
    PRINTF("FlexCAN Module Initialization finish.\r\n");

    while (1)
    {
        /* Register A9 side Wakeup source and switch low-power run. */
        result = LPM_MCORE_RegisterPeerWakeup(BOARD_FLEXCAN_IRQ_NUM, WAKEUP_ENABLE);
        if (WAKEUP_REGISTER_SUCCESS == result)
        {
            PRINTF("Enter flexcan stop mode\r\n\r\n");

            /* Let flexcan enter stop mode */
            FLEXCAN_EnterStopMode(BOARD_FLEXCAN_BASEADDR);

            /* Allow idle task to enter Ram WFI */
            LPM_MCORE_SetPowerStatus(STATUS_LOWPOWER_RUN);

            /* Waiting for FlexCAN Wakeup event. */
            xSemaphoreTake(xSemaphore, portMAX_DELAY);

            /* Don't allow idle task to enter Ram WFI */
            LPM_MCORE_SetPowerStatus(STATUS_NORMAL_RUN);

            /* In this case FlexCAN ISR will exit stop mode automatically when 
             * triggered message is received. Calling it here explictly is
             * just to let user know he's able to exit CAN stop mode if the
             * system is woken up
             * by some other wakeup source.
             */
            FLEXCAN_ExitStopMode(BOARD_FLEXCAN_BASEADDR);            

            /* Un-register A9 side Wakeup source and switch back to normal run. */
            LPM_MCORE_RegisterPeerWakeup(BOARD_FLEXCAN_IRQ_NUM, WAKEUP_DISABLE);

            PRINTF("Leave flexcan stop mode\r\n");
        }

        while (pdPASS == xQueueReceive(xQueue, &rxData, 0))
        {
            PRINTF("Receiving data: 0x%x success!\r\n", rxData);
        }
    }
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
* Function Name  : init_Flexcan
* Returned Value : void
* Comments : Setting FlexCAN and its RX Message Box.
*
*END*----------------------------------------------------------------------*/
static void init_Flexcan(void)
{
    flexcan_msgbuf_t *rxMsgBufPtr;

    flexcan_init_config_t initConfig = {
        .timing = timing_table[0],
        .operatingMode = flexcanNormalMode,
        .maxMsgBufNum  = 16
    };

    /* Initialize FlexCAN module. */
    FLEXCAN_Init(BOARD_FLEXCAN_BASEADDR, &initConfig);
    /* Enable FlexCAN Clock. */
    FLEXCAN_Enable(BOARD_FLEXCAN_BASEADDR);
    /* Set FlexCAN to use Global mask mode. */
    FLEXCAN_SetRxMaskMode(BOARD_FLEXCAN_BASEADDR, flexcanRxMaskGlobal);
    /* Set FlexCAN global mask. */
    FLEXCAN_SetRxGlobalMask(BOARD_FLEXCAN_BASEADDR, ~CAN_ID_STD(FLEXCAN_GLOBAL_MASK));

    /* Clear Rx message buffer interrupt pending bit. */
    FLEXCAN_ClearMsgBufStatusFlag(BOARD_FLEXCAN_BASEADDR, FLEXCAN_RX_MSG_BUF_NUM);
    /* Enable Rx message buffer interrupt. */
    FLEXCAN_SetMsgBufIntCmd(BOARD_FLEXCAN_BASEADDR, FLEXCAN_RX_MSG_BUF_NUM, true);

    /* Initialize Global variable. */
    rxMsgBufPtr = FLEXCAN_GetMsgBufPtr(BOARD_FLEXCAN_BASEADDR, FLEXCAN_RX_MSG_BUF_NUM);

    /* Setup Rx MsgBuf to receive Frame. */
    rxMsgBufPtr->idStd = FLEXCAN_RX_IDENTIFIER;
    rxMsgBufPtr->code  = flexcanRxEmpty;

    /* Clear Self-Wakeup interrupt pending bit. */
    FLEXCAN_ClearErrStatusFlag(BOARD_FLEXCAN_BASEADDR, flexcanIntWakeUp);

    /* Enable Self-Wakeup interrupt. */
    FLEXCAN_SetErrIntCmd(BOARD_FLEXCAN_BASEADDR, flexcanIntWakeUp, true);

    /* Request FlexCAN to Enter stop Mode */
    FLEXCAN_SetSelfWakeUpCmd(BOARD_FLEXCAN_BASEADDR, false, true);

    /* Set FlexCAN interrupt priority. */
    NVIC_SetPriority(BOARD_FLEXCAN_IRQ_NUM, 3);
    /* Enable FlexCAN interrupt. */
    NVIC_EnableIRQ(BOARD_FLEXCAN_IRQ_NUM);
}

/*FUNCTION*----------------------------------------------------------------*
* Function Name  : FLEXCAN_EnterStopMode
* Returned Value : void
* Comments : Setting FlexCAN module to Stop Mode.
*     
*END*----------------------------------------------------------------------*/
static void FLEXCAN_EnterStopMode(CAN_Type* base)
{
    switch ((uint32_t)base)
    {
        case (CAN1_BASE):
            IOMUXC_GPR_GPR4 |= IOMUXC_GPR_GPR4_CAN1_STOP_REQ_MASK;
            while (!(IOMUXC_GPR_GPR4 & IOMUXC_GPR_GPR4_CAN1_STOP_ACK_MASK));
            break;

        case (CAN2_BASE):
            IOMUXC_GPR_GPR4 |= IOMUXC_GPR_GPR4_CAN2_STOP_REQ_MASK;
            while (!(IOMUXC_GPR_GPR4 & IOMUXC_GPR_GPR4_CAN2_STOP_ACK_MASK));
            break;

        default:
            break;
    }
}

/*FUNCTION*----------------------------------------------------------------*
* Function Name  : FLEXCAN_ExitStopMode
* Returned Value : void
* Comments : Setting FlexCAN module to normal working mode.
*     
*END*----------------------------------------------------------------------*/
static void FLEXCAN_ExitStopMode(CAN_Type* base)
{
    switch ((uint32_t)base)
    {
        case (CAN1_BASE):
            IOMUXC_GPR_GPR4 &= ~IOMUXC_GPR_GPR4_CAN1_STOP_REQ_MASK;
            break;

        case (CAN2_BASE):
            IOMUXC_GPR_GPR4 &= ~IOMUXC_GPR_GPR4_CAN2_STOP_REQ_MASK;
            break;

        default:
            break;
    }
}

/*FUNCTION*----------------------------------------------------------------*
* Function Name  : init_PowerManger
* Returned Value : void
* Comments : Initialize power saving mechanism.
*     
*END*----------------------------------------------------------------------*/
static void init_PowerManger(void)
{
    shared_clk_init_config_t sharedClkConfig = {
        /* Start Address for Appointed Memory for Shared clock management. */
        .shareMemStartAddress = SHARED_CM_OCRAM_START,
        /* The Sema4 base address used in shared clock management. */
        .sema4BaseAddress     = BOARD_SEMA4_BASEADDR,
        /* The Sema4 gate number used in shared clock management. */
        .sema4Num             = SHARED_CM_SMEA4_GATE_NUM
    };

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
    SharedClk_EnabeNode(SHARED_CLK_FLEXCAN1);
    SharedClk_EnabeNode(SHARED_CLK_FLEXCAN1_IPG);
    SharedClk_EnabeNode(SHARED_CLK_UART);
    SharedClk_EnabeNode(SHARED_CLK_UART_IPG);
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
}

/*FUNCTION*----------------------------------------------------------------*
* Function Name  : main
* Returned Value : int
* Comments :
*       Initialize hardware resource used in this demo, create
*       CanWakeupRxTask Task and start FreeRTOS Kernel.
*END*----------------------------------------------------------------------*/
int main(void)
{
    // Initialize demo application pins setting and clock setting.
    hardware_init();

    PRINTF("********* FLEXCAN NETWORK TEST ***********\r\n\r\n");
    PRINTF("********* FLEXCAN WAKEUP PROGRAM *********\r\n");
    PRINTF("   Message format: Standard (11 bit id)   \r\n");
    PRINTF("   Message buffer %d used for RX          \r\n", FLEXCAN_RX_MSG_BUF_NUM);
    PRINTF("   Interrupt Mode: Enabled                \r\n");
    PRINTF("   Operation Mode: RX --> Normal          \r\n");
    PRINTF("******************************************\r\n");

    /* Initialize power manager */
    init_PowerManger();

    /* Create the demo task. */
    xTaskCreate(CanWakeupRxTask, "RX Task", configMINIMAL_STACK_SIZE,
                NULL, tskIDLE_PRIORITY+1, NULL);

    /* Start FreeRTOS scheduler. */
    vTaskStartScheduler();

    /* Should never reach this point. */
    while (true);
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
