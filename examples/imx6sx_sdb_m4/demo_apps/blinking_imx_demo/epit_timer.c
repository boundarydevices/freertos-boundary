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
/****************************************************************************
*
* Comments:
*   This file contains the functions which write and read the SPI memories
*   using the ECSPI driver in interrupt mode.
*
****************************************************************************/

#include "FreeRTOS.h"
#include "semphr.h"
#include "board.h"
#include "epit.h"
#include "hw_timer.h"

static SemaphoreHandle_t xSemaphore;

void Hw_Timer_Init(void)
{
    epit_init_config_t config = {
        .freeRun    = true,
        .waitEnable = true,
        .stopEnable = true,
        .dbgEnable  = true,
        .enableMode = true
    };

    /* Initialize EPIT module */
    EPIT_Init(BOARD_EPITA_BASEADDR, &config);

    /* Set EPIT clock source to 32k low frequency reference clock */
    EPIT_SetClockSource(BOARD_EPITA_BASEADDR, epitClockSourceLowFreq);

    /* Divide EPITA clock source frequency by 32 inside EPIT module */
    EPIT_SetPrescaler(BOARD_EPITA_BASEADDR, 31);

    /* Set EPIT interrupt priority 3 */
    NVIC_SetPriority(BOARD_EPITA_IRQ_NUM, 3);

    /* Enable NVIC interrupt */
    NVIC_EnableIRQ(BOARD_EPITA_IRQ_NUM);

    xSemaphore = xSemaphoreCreateBinary();
}

void Hw_Timer_Delay(uint32_t ms)
{
    /* Epit is a count-down timer. */
    /* Set both EPIT modules to ms duration */
    EPIT_SetCounterLoadValue(BOARD_EPITA_BASEADDR, ms);
    /* Set EPIT compare value */
    EPIT_SetOutputCompareValue(BOARD_EPITA_BASEADDR, 0x0);

    /* Enable EPIT Output Compare interrupt */
    EPIT_SetIntCmd(BOARD_EPITA_BASEADDR, true);

    /* EPIT start */
    EPIT_Enable(BOARD_EPITA_BASEADDR);

    /* Wait until GPT event happens. */
    xSemaphoreTake(xSemaphore, portMAX_DELAY);
}

void BOARD_EPITA_HANDLER(void)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    /* When EPIT time-out, we disable EPIT to make sure this is a one-shot event. */
    EPIT_Disable(BOARD_EPITA_BASEADDR);
    EPIT_SetIntCmd(BOARD_EPITA_BASEADDR, false);
    EPIT_ClearStatusFlag(BOARD_EPITA_BASEADDR);

    /* Unlock the task to process the event. */
    xSemaphoreGiveFromISR(xSemaphore, &xHigherPriorityTaskWoken);

    /* Perform a context switch to wake the higher priority task. */
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
