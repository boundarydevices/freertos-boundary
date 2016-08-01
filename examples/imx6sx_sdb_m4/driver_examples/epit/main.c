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

#include "epit.h"
#include "board.h"
#include "clock_freq.h"
#include "debug_console_imx.h"

/* This case will run for 4.5 seconds */
static volatile uint32_t num = 10;
static uint32_t counterA, counterB;

int main(void)
{
    uint32_t freqA, freqB;
    epit_init_config_t config = {
        .freeRun     = true,
        .waitEnable  = true,
        .stopEnable  = true,
        .dbgEnable   = true,
        .enableMode  = true
    };

    hardware_init();

    /* Initialize EPIT module */
    EPIT_Init(BOARD_EPITA_BASEADDR, &config);
    EPIT_Init(BOARD_EPITB_BASEADDR, &config);

    /* Set EPIT clock source */
    EPIT_SetClockSource(BOARD_EPITA_BASEADDR, epitClockSourcePeriph);
    EPIT_SetClockSource(BOARD_EPITB_BASEADDR, epitClockSourceLowFreq);

    /* Divide EPITA clock source frequency by 2 inside EPIT module */
    EPIT_SetPrescaler(BOARD_EPITA_BASEADDR, 1);
    /* Divide EPITB clock source frequency by 2 inside EPIT module */
    EPIT_SetPrescaler(BOARD_EPITB_BASEADDR, 1);

    /* Get EPITA clock frequency */
    freqA = get_epit_clock_freq(BOARD_EPITA_BASEADDR)/2;
    /* Get EPITB clock frequency, 32768Hz */
    freqB = 32768/2;

    /* Set both EPIT modules to 1 second duration */
    EPIT_SetCounterLoadValue(BOARD_EPITA_BASEADDR, freqA);
    EPIT_SetCounterLoadValue(BOARD_EPITB_BASEADDR, freqB);
    /* The first interrupt occured at 0.5 second */
    EPIT_SetOutputCompareValue(BOARD_EPITA_BASEADDR, freqA/2);
    EPIT_SetOutputCompareValue(BOARD_EPITB_BASEADDR, freqB/2);

    /* Set EPIT interrupt priority to same value to avoid handler preemption */
    NVIC_SetPriority(BOARD_EPITA_IRQ_NUM, 3);
    NVIC_SetPriority(BOARD_EPITB_IRQ_NUM, 3);
    /* Enable NVIC interrupt */
    NVIC_EnableIRQ(BOARD_EPITA_IRQ_NUM);
    NVIC_EnableIRQ(BOARD_EPITB_IRQ_NUM);

    /* Enable EPIT Output Compare interrupt */
    EPIT_SetIntCmd(BOARD_EPITA_BASEADDR, true);
    EPIT_SetIntCmd(BOARD_EPITB_BASEADDR, true);

    PRINTF("EPIT timer will now start\n\r");
    PRINTF("counter/freq ratio should be close to 0.5 ...\n\r");
    /* EPIT start */
    EPIT_Enable(BOARD_EPITA_BASEADDR);
    EPIT_Enable(BOARD_EPITB_BASEADDR);

    while (true)
    {
        __WFI();

        while ((num & 1) != 0); /* wait both timer handled */

        PRINTF("\tEPIT A freq %u, counter %u.\n\r", freqA, counterA);
        PRINTF("\tEPIT B freq %u, counter %u.\n\r", freqB, counterB);

        if (num == 0)
        {
            /* Stop EPIT */
            EPIT_Disable(BOARD_EPITA_BASEADDR);
            EPIT_Disable(BOARD_EPITB_BASEADDR);
            PRINTF("EPIT example finished...\n\r");
        }
    }
}

void BOARD_EPITA_HANDLER()
{
    EPIT_ClearStatusFlag(BOARD_EPITA_BASEADDR);

    if (num && --num)
        counterA = EPIT_ReadCounter(BOARD_EPITA_BASEADDR);
}

void BOARD_EPITB_HANDLER()
{
    EPIT_ClearStatusFlag(BOARD_EPITB_BASEADDR);

    if (num && --num)
        counterB = EPIT_ReadCounter(BOARD_EPITB_BASEADDR);
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
