/*
**     Filename    : pin_mux.c
**     Project     : imx6sx_nit6sx_m4-pin
**     Processor   : MCIMX6SX
**     Component   : PinSettings
**     Version     : Component 01.007, Driver 1.2, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2014-06-08, 20:07, # CodeGen: 9
**     Abstract    :
**
**     Settings    :
**
**
**     Copyright : 2015 Freescale Semiconductor, Inc.
**     All Rights Reserved.
**
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file pin_mux.c
** @version 1.2
** @brief
**
*/
/*!
**  @addtogroup pin_mux_module pin_mux module documentation
**  @{
*/

/* MODULE pin_mux. */

#include "pin_mux.h"

void configure_uart_pins(UART_Type* base)
{
    switch((uint32_t)base)
    {
        case UART2_BASE:
            // UART2 iomux configuration
            IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO06 = IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO06_MUX_MODE(0);
            IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO07 = IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO07_MUX_MODE(0);
            IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO06 = IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO06_PKE_MASK |
                                               IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO06_PUE_MASK |
                                               IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO06_PUS(2)   |
                                               IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO06_SPEED(2) |
                                               IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO06_DSE(6)   |
                                               IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO06_SRE_MASK |
                                               IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO06_HYS_MASK;
            IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO07 = IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO07_PKE_MASK |
                                               IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO07_PUE_MASK |
                                               IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO07_PUS(2)   |
                                               IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO07_SPEED(2) |
                                               IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO07_DSE(6)   |
                                               IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO07_SRE_MASK |
                                               IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO07_HYS_MASK;
            IOMUXC_UART2_IPP_UART_RXD_MUX_SELECT_INPUT = IOMUXC_UART2_IPP_UART_RXD_MUX_SELECT_INPUT_DAISY(1);
            break;
        default:
            break;
    }
}

void configure_flexcan_pins(CAN_Type* base)
{
    volatile GPIO_MemMapPtr gpio4_pdir;
    void   *addr;

    switch((uint32_t)base)
    {
        case CAN1_BASE:
            // CAN1_2_STBY_B DRIVE LOW
            IOMUXC_SW_MUX_CTL_PAD_QSPI1B_DATA3 = IOMUXC_SW_MUX_CTL_PAD_QSPI1B_DATA3_MUX_MODE(5);
            IOMUXC_SW_PAD_CTL_PAD_QSPI1B_DATA3 = IOMUXC_SW_PAD_CTL_PAD_QSPI1B_DATA3_HYS_MASK|
                                                 IOMUXC_SW_PAD_CTL_PAD_QSPI1B_DATA3_DSE(6)  |
                                                 IOMUXC_SW_PAD_CTL_PAD_QSPI1B_DATA3_SPEED(2)|
                                                 IOMUXC_SW_PAD_CTL_PAD_QSPI1B_DATA3_PKE_MASK|
                                                 IOMUXC_SW_PAD_CTL_PAD_QSPI1B_DATA3_PUE_MASK|
                                                 IOMUXC_SW_PAD_CTL_PAD_QSPI1B_DATA3_PUS(2);
            addr = (void *) GPIO4_BASE_PTR;
            gpio4_pdir = addr;
            gpio4_pdir->GDIR |= 0x08000000;
            gpio4_pdir->DR &= ~0x08000000;

            // CAN1_TX
            IOMUXC_SW_MUX_CTL_PAD_QSPI1B_DQS = IOMUXC_SW_MUX_CTL_PAD_QSPI1B_DQS_MUX_MODE(1);
            IOMUXC_SW_PAD_CTL_PAD_QSPI1B_DQS = IOMUXC_SW_PAD_CTL_PAD_QSPI1B_DQS_HYS_MASK |
                                               IOMUXC_SW_PAD_CTL_PAD_QSPI1B_DQS_DSE(6)   |
                                               IOMUXC_SW_PAD_CTL_PAD_QSPI1B_DQS_SPEED(2) |
                                               IOMUXC_SW_PAD_CTL_PAD_QSPI1B_DQS_PKE_MASK |
                                               IOMUXC_SW_PAD_CTL_PAD_QSPI1B_DQS_PUE_MASK |
                                               IOMUXC_SW_PAD_CTL_PAD_QSPI1B_DQS_PUS(2);
            // CAN1_RX
            IOMUXC_SW_MUX_CTL_PAD_QSPI1A_SS1_B = IOMUXC_SW_MUX_CTL_PAD_QSPI1A_SS1_B_MUX_MODE(1);
            IOMUXC_CAN1_IPP_IND_CANRX_SELECT_INPUT = IOMUXC_CAN1_IPP_IND_CANRX_SELECT_INPUT_DAISY(2);
            IOMUXC_SW_PAD_CTL_PAD_QSPI1A_SS1_B = IOMUXC_SW_PAD_CTL_PAD_QSPI1A_SS1_B_HYS_MASK|
                                                 IOMUXC_SW_PAD_CTL_PAD_QSPI1A_SS1_B_DSE(6)  |
                                                 IOMUXC_SW_PAD_CTL_PAD_QSPI1A_SS1_B_SPEED(2)|
                                                 IOMUXC_SW_PAD_CTL_PAD_QSPI1A_SS1_B_PKE_MASK|
                                                 IOMUXC_SW_PAD_CTL_PAD_QSPI1A_SS1_B_PUE_MASK|
                                                 IOMUXC_SW_PAD_CTL_PAD_QSPI1A_SS1_B_PUS(2);

            break;
        case CAN2_BASE:
            // CAN1_2_STBY_B DRIVE LOW
            IOMUXC_SW_MUX_CTL_PAD_QSPI1B_DATA3 = IOMUXC_SW_MUX_CTL_PAD_QSPI1B_DATA3_MUX_MODE(5);
            IOMUXC_SW_PAD_CTL_PAD_QSPI1B_DATA3 = IOMUXC_SW_PAD_CTL_PAD_QSPI1B_DATA3_HYS_MASK|
                                                 IOMUXC_SW_PAD_CTL_PAD_QSPI1B_DATA3_DSE(6)  |
                                                 IOMUXC_SW_PAD_CTL_PAD_QSPI1B_DATA3_SPEED(2)|
                                                 IOMUXC_SW_PAD_CTL_PAD_QSPI1B_DATA3_PKE_MASK|
                                                 IOMUXC_SW_PAD_CTL_PAD_QSPI1B_DATA3_PUE_MASK|
                                                 IOMUXC_SW_PAD_CTL_PAD_QSPI1B_DATA3_PUS(2);
            addr = (void *) GPIO4_BASE_PTR;
            gpio4_pdir = addr;
            gpio4_pdir->GDIR |= 0x08000000;
            gpio4_pdir->DR &= ~0x08000000;

            // CAN2_TX
            IOMUXC_SW_MUX_CTL_PAD_QSPI1A_DQS = IOMUXC_SW_MUX_CTL_PAD_QSPI1A_DQS_MUX_MODE(1);
            IOMUXC_SW_PAD_CTL_PAD_QSPI1A_DQS = IOMUXC_SW_PAD_CTL_PAD_QSPI1A_DQS_HYS_MASK|
                                               IOMUXC_SW_PAD_CTL_PAD_QSPI1A_DQS_DSE(6)  |
                                               IOMUXC_SW_PAD_CTL_PAD_QSPI1A_DQS_SPEED(2)|
                                               IOMUXC_SW_PAD_CTL_PAD_QSPI1A_DQS_PKE_MASK|
                                               IOMUXC_SW_PAD_CTL_PAD_QSPI1A_DQS_PUE_MASK|
                                               IOMUXC_SW_PAD_CTL_PAD_QSPI1A_DQS_PUS(2);

            // CAN2_RX
            IOMUXC_SW_MUX_CTL_PAD_QSPI1B_SS1_B = IOMUXC_SW_MUX_CTL_PAD_QSPI1B_SS1_B_MUX_MODE(1);
            IOMUXC_CAN2_IPP_IND_CANRX_SELECT_INPUT = IOMUXC_CAN2_IPP_IND_CANRX_SELECT_INPUT_DAISY(2);
            IOMUXC_SW_PAD_CTL_PAD_QSPI1B_SS1_B = IOMUXC_SW_PAD_CTL_PAD_QSPI1B_SS1_B_HYS_MASK|
                                                 IOMUXC_SW_PAD_CTL_PAD_QSPI1B_SS1_B_DSE(6)  |
                                                 IOMUXC_SW_PAD_CTL_PAD_QSPI1B_SS1_B_SPEED(2)|
                                                 IOMUXC_SW_PAD_CTL_PAD_QSPI1B_SS1_B_PKE_MASK|
                                                 IOMUXC_SW_PAD_CTL_PAD_QSPI1B_SS1_B_PUE_MASK|
                                                 IOMUXC_SW_PAD_CTL_PAD_QSPI1B_SS1_B_PUS(2);
            break;
    }
}

/* END pin_mux. */
/*!
** @}
*/
