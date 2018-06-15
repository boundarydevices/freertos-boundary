/*
 * The Clear BSD License
 * Copyright 2017 NXP
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted (subject to the limitations in the disclaimer below) provided
 *  that the following conditions are met:
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

#include "fsl_common.h"
#include "fsl_sema4.h"
#include "fsl_debug_console.h"
#include "board.h"

#include "pin_mux.h"
#include "clock_config.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define APP_SEMA4 SEMA4
#define APP_PROC_NUM 1
#define APP_OTHER_PROC_NUM 0
#define APP_SEMA4_GATE 0
#define APP_SEMA4_GATE_ADDR ((uint32_t)(&(APP_SEMA4->Gate00)))
#define SEMA4_IRQHandler HS0_IRQHandler
#define SOC_EnableSEMA4Intterrupt() NVIC_EnableIRQ(HS0_IRQn)
#define SOC_DisableSEMA4Intterrupt() NVIC_DisableIRQ(HS0_IRQn)
#define APP_ASSERT(x)                \
    if (!(x))                        \
    {                                \
        PRINTF("Example error\r\n"); \
        for (;;)                     \
            ;                        \
    }

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

void SEMA4_IRQHandler(void)
{
    /* If gate notification IRQ received, then lock the gate. */
    if (((1U << APP_SEMA4_GATE) & SEMA4_GetGateNotifyStatus(APP_SEMA4, APP_PROC_NUM)))
    {
        SEMA4_TryLock(APP_SEMA4, APP_SEMA4_GATE, APP_PROC_NUM);
    }
}

/*!
 * @brief Main function
 */
int main(void)
{
    /* Board specific RDC settings */
    BOARD_RdcInit();
    
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();
    BOARD_InitMemory();   

    PRINTF("SEMA4 uboot example start\r\n");

    SEMA4_Init(APP_SEMA4);

    SEMA4_EnableGateNotifyInterrupt(APP_SEMA4, APP_PROC_NUM, (1 << APP_SEMA4_GATE));

    SOC_EnableSEMA4Intterrupt();

    /* Step 1: The other core lock the sema4 gate. */
    PRINTF("Lock sema4 gate in uboot using:\r\n");
    PRINTF(" > mw.b 0x%08x %d 1 \r\n", APP_SEMA4_GATE_ADDR, APP_OTHER_PROC_NUM + 1);

    /* Wait SEMA4 gate is locked by the other core. */
    while (SEMA4_GetLockProc(APP_SEMA4, APP_SEMA4_GATE) != APP_OTHER_PROC_NUM)
    {
    }

    /* Step 2: Current core try to lock the sema4 gate and lock failed. */
    APP_ASSERT(kStatus_Fail == SEMA4_TryLock(APP_SEMA4, APP_SEMA4_GATE, APP_PROC_NUM));

    /* Step 3: The other core unlock the sema4 gate. */
    PRINTF("Unlock sema4 gate in uboot using:\r\n");
    PRINTF(" > mw.b 0x%08x 0 1 \r\n", APP_SEMA4_GATE_ADDR);

    /* Wait SEMA4 gate is locked by the other core. */
    while (SEMA4_GetLockProc(APP_SEMA4, APP_SEMA4_GATE) == APP_OTHER_PROC_NUM)
    {
    }

    /*
     * When the other core unlocked the gate, current core receives the notification
     * interrupt and lock the gate in ISR.
     */
    APP_ASSERT(SEMA4_GetLockProc(APP_SEMA4, APP_SEMA4_GATE) == APP_PROC_NUM);

    SEMA4_Unlock(APP_SEMA4, APP_SEMA4_GATE);

    SOC_DisableSEMA4Intterrupt();

    SEMA4_DisableGateNotifyInterrupt(APP_SEMA4, APP_PROC_NUM, (1 << APP_SEMA4_GATE));

    SEMA4_Deinit(APP_SEMA4);

    PRINTF("SEMA4 uboot example success\r\n");

    while (1)
    {
    }
}
