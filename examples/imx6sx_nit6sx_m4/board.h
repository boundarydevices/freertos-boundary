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

#if !defined(__BOARD_H__)
#define __BOARD_H__

#include "pin_mux.h"
#include "rdc.h"
#include "rdc_defs_imx6sx.h"
#include "ccm_imx6sx.h"
#include "clock_freq.h"

/* The board name */
#define BOARD_NAME                            "IMX6SX_NIT6SX_M4"
#define BOARD_DOMAIN_ID                       (1)

/* ADC information for this board */
#define BOARD_ADC_RDC_PDAP                    rdcPdapAdc1
#define BOARD_ADC_BASEADDR                    ADC1
#define BOARD_ADC_IRQ_NUM                     ADC1_IRQn
#define BOARD_ADC_HANDLER                     ADC1_Handler
#define BOARD_ADC_INPUT_CHANNEL               (3)

/* WDOG information for this board */
#define BOARD_WDOG_RDC_PDAP                   rdcPdapWdog3
#define BOARD_WDOG_BASEADDR                   WDOG3
#define BOARD_WDOG_IRQ_NUM                    WDOG3_IRQn
#define BOARD_WDOG_HANDLER                    WDOG3_Handler

/* SEMA4 information for this board */
#define BOARD_SEMA4_RDC_PDAP                  rdcPdapSema4
#define BOARD_SEMA4_BASEADDR                  SEMA4
#define BOARD_SEMA4_IRQ_NUM                   SEMA4_CP1_IRQn
#define BOARD_SEMA4_HANDLER                   SEMA4_CP1_Handler
#define BOARD_SEMA4_SHARE_MEM_NUM             (15)

/* Debug UART information for this board */
#define BOARD_DEBUG_UART_RDC_PDAP             rdcPdapUart2
#define BOARD_DEBUG_UART_CCM_ROOT             ccmRootUartClkSel
#define BOARD_DEBUG_UART_CCM_DIV              ccmRootUartClkPodf
#define BOARD_DEBUG_UART_CCM_CCGR             ccmCcgrGateUartClk
#define BOARD_DEBUG_UART_CCM_CCGR_SERIAL      ccmCcgrGateUartSerialClk
#define BOARD_DEBUG_UART_BASEADDR             UART2
#define BOARD_DEBUG_UART_IRQ_NUM              UART2_IRQn
#define BOARD_DEBUG_UART_HANDLER              UART2_Handler

/* MU information for this board*/
#define BOARD_MU_HANDLER                      MU_M4_Handler
#define BOARD_MU_IRQ_NUM                      MU_M4_IRQn
#define BOARD_MU_BASE_ADDR                    MUB
#define BOARD_MU_RDC_PDAP                     rdcPdapMuB

/* EPIT common information for this board */
#define BOARD_EPIT_CCM_ROOT                   ccmRootPerclkClkSel
#define BOARD_EPIT_CCM_DIV                    ccmRootPerclkPodf
/* EPIT instance A information for this board */
#define BOARD_EPITA_RDC_PDAP                  rdcPdapEpit1
#define BOARD_EPITA_CCM_CCGR                  ccmCcgrGateEpit1Clk
#define BOARD_EPITA_BASEADDR                  EPIT1
#define BOARD_EPITA_IRQ_NUM                   EPIT1_IRQn
#define BOARD_EPITA_HANDLER                   EPIT1_Handler
/* EPIT instance B information for this board */
#define BOARD_EPITB_RDC_PDAP                  rdcPdapEpit2
#define BOARD_EPITB_CCM_CCGR                  ccmCcgrGateEpit2Clk
#define BOARD_EPITB_BASEADDR                  EPIT2
#define BOARD_EPITB_IRQ_NUM                   EPIT2_IRQn
#define BOARD_EPITB_HANDLER                   EPIT2_Handler

/* FlexCAN information for this board */
#define BOARD_FLEXCAN_CCM_ROOT                ccmRootCanClkSel
#define BOARD_FLEXCAN_CCM_CCGR                ccmCcgrGateCan1Clk
#define BOARD_FLEXCAN_CCM_CCGR_SERIAL         ccmCcgrGateCan1SerialClk
#define BOARD_FLEXCAN_CCM_DIV                 ccmRootCanClkPodf
#define BOARD_FLEXCAN_RDC_PDAP                rdcPdapCan1
#define BOARD_FLEXCAN_BASEADDR                CAN1
#define BOARD_FLEXCAN_IRQ_NUM                 FLEXCAN1_IRQn
#define BOARD_FLEXCAN_HANDLER                 FLEXCAN1_Handler

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

void hardware_init(void);
void dbg_uart_init(void);
/* Function to initialize clock base on board configuration. */
void BOARD_ClockInit(void);
void BOARD_RdcInit(void);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* __BOARD_H__ */
