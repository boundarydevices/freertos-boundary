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

#include <stdint.h>
#include <stdbool.h>
#include "adc_imx6sx.h"
#include "debug_console_imx.h"
#include "board.h"

#define ADC_RESOLUTION  0xFFF;

static volatile bool printFlag;
static float voltage;

int main(void)
{
    uint32_t count;

    adc_init_config_t adcConfig = {
        .clockSource = adcIpgClockDivide2,
        .divideRatio = adcInputClockDiv4,
        .averageNumber = adcAvgNum32,
        .resolutionMode = adcResolutionBit12
    };

    // Initialize board specified hardware.
    hardware_init();

    PRINTF("\n-------------- ADC imx6sx driver example --------------\n\n\r");
    PRINTF("This example demonstrates usage of ADC driver on i.MX 6SoloX processor.\n\r");
    PRINTF("It Continuous convert Analog Input, and print the result to terminal \n\r");

    /* Initialize ADC module. */
    ADC_Init(BOARD_ADC_BASEADDR, &adcConfig);

    /* Enable overwrite conversion result for continuous conversion. */
    ADC_SetConvertResultOverwrite(BOARD_ADC_BASEADDR, true);

    /* Enable Conversion complete interrupt. */
    ADC_SetIntCmd(BOARD_ADC_BASEADDR, true);

    /* Set ADC Interrupt priority */
    NVIC_SetPriority(BOARD_ADC_IRQ_NUM, 3);

    /* Call core API to enable the IRQ. */
    NVIC_EnableIRQ(BOARD_ADC_IRQ_NUM);

    /* Trigger single conversion. */
    ADC_TriggerSingleConvert(BOARD_ADC_BASEADDR, BOARD_ADC_INPUT_CHANNEL);

    printFlag = false;
    while(1)
    {
        if(printFlag)
        {
            PRINTF("Current analog value: %3.2fv\n\r", voltage);
            printFlag = false;
            for(count = 0; count < 227000000; count++)
                __asm("NOP");
            ADC_TriggerSingleConvert(BOARD_ADC_BASEADDR, BOARD_ADC_INPUT_CHANNEL);
        }
    }
}

void BOARD_ADC_HANDLER(void)
{
    /* Read conversion result will clear conversion complete status flag automatically. */
    voltage = (3.3 * ADC_GetConvertResult(BOARD_ADC_BASEADDR)) / ADC_RESOLUTION;
    printFlag = true;
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
