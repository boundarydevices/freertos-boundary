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

////////////////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////////////////
#include <stdint.h>
#include <stdbool.h>
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "flexcan.h"
#include "debug_console_imx.h"
#include "board.h"

////////////////////////////////////////////////////////////////////////////////
// Macros
////////////////////////////////////////////////////////////////////////////////
#define FLEXCAN_TX_MSG_BUF_NUM      (8)
#define FLEXCAN_TX_IDENTIFIER       (0x123)
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
static SemaphoreHandle_t xSemaphore;

////////////////////////////////////////////////////////////////////////////////
// Function Declarations
////////////////////////////////////////////////////////////////////////////////
static void init_Flexcan(void);

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

    /* Solve Tx interrupt */
    if (FLEXCAN_GetMsgBufStatusFlag(BOARD_FLEXCAN_BASEADDR, FLEXCAN_TX_MSG_BUF_NUM))
    {
        FLEXCAN_ClearMsgBufStatusFlag(BOARD_FLEXCAN_BASEADDR, FLEXCAN_TX_MSG_BUF_NUM);

        /* Release FlexCAN Tx Sem4 */
        xSemaphoreGiveFromISR(xSemaphore, &xHigherPriorityTaskWoken);
    }

    /* Perform a context switch to wake the higher priority task. */
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

/*FUNCTION*----------------------------------------------------------------*
* Function Name  : CanWakeupTxTask
* Returned Value : void
* Comments :
*       The FlexCAN Transmit Task.
*END*----------------------------------------------------------------------*/
void CanWakeupTxTask(void *pvParameters)
{
    flexcan_msgbuf_t *txMsgBufPtr;
    uint8_t txData = 0;

    /* Create FlexCan TX Semaphore. */
    xSemaphore = xSemaphoreCreateBinary();

    /* Initialize FlexCAN module for Normal receive. */
    init_Flexcan();

    txMsgBufPtr = FLEXCAN_GetMsgBufPtr(BOARD_FLEXCAN_BASEADDR, FLEXCAN_TX_MSG_BUF_NUM);

    while (1)
    {
        /* Load data to message buffer. */
        txMsgBufPtr->data0 = txData;

        /* Start FlexCAN transmit. */
        txMsgBufPtr->code = flexcanTxDataOrRemte;

        /* Wait until send data finish. */
        if (pdPASS == xSemaphoreTake(xSemaphore, portMAX_DELAY))
        {
            PRINTF("Sending data: 0x%x success!\r\n", txData);
            txData++;
        }

        /* Wait 5s before send next data frame. */
        vTaskDelay(5 * configTICK_RATE_HZ);
    }
}

/*FUNCTION*----------------------------------------------------------------*
* Function Name  : init_Flexcan
* Returned Value : void
* Comments : Setting FlexCAN and its TX Message Box.
*
*END*----------------------------------------------------------------------*/
static void init_Flexcan(void)
{
    flexcan_msgbuf_t *txMsgBufPtr;

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

    /* Clear Tx message buffer interrupt pending bit. */
    FLEXCAN_ClearMsgBufStatusFlag(BOARD_FLEXCAN_BASEADDR, FLEXCAN_TX_MSG_BUF_NUM);
    /* Enable Tx message buffer interrupt. */
    FLEXCAN_SetMsgBufIntCmd(BOARD_FLEXCAN_BASEADDR, FLEXCAN_TX_MSG_BUF_NUM, true);

    /* Initialize Global variable. */
    txMsgBufPtr = FLEXCAN_GetMsgBufPtr(BOARD_FLEXCAN_BASEADDR, FLEXCAN_TX_MSG_BUF_NUM);

    /* Setup Tx MsgBuf to send Frame. */
    txMsgBufPtr->prio  = 0x0; /* We don't use local priority */
    txMsgBufPtr->idStd = FLEXCAN_TX_IDENTIFIER; /* Set Tx Identifier */
    txMsgBufPtr->idExt = 0x0; /* We don't use Extend Id. */
    txMsgBufPtr->dlc   = 0x1; /* Send only 1 byte data. */
    txMsgBufPtr->rtr   = 0x0; /* Send data frame. */
    txMsgBufPtr->ide   = 0x0; /* Frame format is standard. */
    txMsgBufPtr->srr   = 0x1; /* Don't care in standard id mode. */

    /* Set FlexCAN interrupt priority. */
    NVIC_SetPriority(BOARD_FLEXCAN_IRQ_NUM, 3);
    /* Enable FlexCAN interrupt. */
    NVIC_EnableIRQ(BOARD_FLEXCAN_IRQ_NUM);
}

/*FUNCTION*----------------------------------------------------------------*
* Function Name  : main
* Returned Value : int
* Comments :
*       Initialize hardware resource used in this demo, create
*       CanWakeupTxTask Task and start FreeRTOS Kernel.
*END*----------------------------------------------------------------------*/
int main(void)
{
    /* Initialize demo application pins setting and clock setting. */
    hardware_init();

    PRINTF("********* FLEXCAN NETWORK TEST ***********\r\n\r\n");
    PRINTF("***** FLEXCAN WAKEUP TRIGGER PROGRAM *****\r\n");
    PRINTF("   Message format: Standard (11 bit id)   \r\n");
    PRINTF("   Message buffer %d used for TX          \r\n", FLEXCAN_TX_MSG_BUF_NUM);
    PRINTF("   Interrupt Mode: Enabled                \r\n");
    PRINTF("   Operation Mode: TX --> Normal          \r\n");
    PRINTF("******************************************\r\n");

    /* Create the demo task. */
    xTaskCreate(CanWakeupTxTask, "TX Task", configMINIMAL_STACK_SIZE,
                NULL, tskIDLE_PRIORITY+1, NULL);

    /* Start FreeRTOS scheduler. */
    vTaskStartScheduler();

    /* Should never reach this point. */
    while (true);
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
