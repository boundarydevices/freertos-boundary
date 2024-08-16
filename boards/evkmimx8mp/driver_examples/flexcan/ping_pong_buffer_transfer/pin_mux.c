/*
 * Copyright 2020-2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v9.0
processor: MIMX8ML8xxxLZ
package_id: MIMX8ML8DVNLZ
mcu_data: ksdk2_0
processor_version: 0.9.1
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
    BOARD_InitPins();
}

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: cm7}
- pin_list:
  - {pin_num: AD18, peripheral: FLEXCAN1, signal: can_rx, pin_signal: SPDIF_RX, PUE: Weak_Pull_Up, FSEL: Fast, DSE: X4}
  - {pin_num: AE18, peripheral: FLEXCAN1, signal: can_tx, pin_signal: SPDIF_TX, PUE: Weak_Pull_Up, FSEL: Fast, DSE: X4}
  - {pin_num: AJ5, peripheral: UART4, signal: uart_rx, pin_signal: UART4_RXD, PUE: Weak_Pull_Up, DSE: X6}
  - {pin_num: AH5, peripheral: UART4, signal: uart_tx, pin_signal: UART4_TXD, PUE: Weak_Pull_Up, DSE: X6}
  - {pin_num: AC18, peripheral: GPIO5, signal: 'gpio_io, 05', pin_signal: SPDIF_EXT_CLK, PUE: Weak_Pull_Up}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void) {                                /*!< Function assigned for the core: Cortex-M7F[m7] */
    IOMUXC_SetPinMux(IOMUXC_SAI5_RXC_GPIO3_IO20, 0U);
    IOMUXC_SetPinConfig(IOMUXC_SAI5_RXC_GPIO3_IO20, 
                        IOMUXC_SW_PAD_CTL_PAD_DSE(3U) |
                        IOMUXC_SW_PAD_CTL_PAD_PUE_MASK |
                        IOMUXC_SW_PAD_CTL_PAD_PE_MASK);
    IOMUXC_SetPinMux(IOMUXC_SAI5_RXD2_CAN1_RX, 0U);
    IOMUXC_SetPinConfig(IOMUXC_SAI5_RXD2_CAN1_RX, 
                        IOMUXC_SW_PAD_CTL_PAD_DSE(1U) |
                        IOMUXC_SW_PAD_CTL_PAD_FSEL_MASK |
                        IOMUXC_SW_PAD_CTL_PAD_PUE_MASK |
                        IOMUXC_SW_PAD_CTL_PAD_PE_MASK);
    IOMUXC_SetPinMux(IOMUXC_SAI5_RXD1_CAN1_TX, 0U);
    IOMUXC_SetPinConfig(IOMUXC_SAI5_RXD1_CAN1_TX, 
                        IOMUXC_SW_PAD_CTL_PAD_DSE(1U) |
                        IOMUXC_SW_PAD_CTL_PAD_FSEL_MASK |
                        IOMUXC_SW_PAD_CTL_PAD_PUE_MASK |
                        IOMUXC_SW_PAD_CTL_PAD_PE_MASK);
    IOMUXC_SetPinMux(IOMUXC_UART4_RXD_UART4_RX, 0U);
    IOMUXC_SetPinConfig(IOMUXC_UART4_RXD_UART4_RX, 
                        IOMUXC_SW_PAD_CTL_PAD_DSE(3U) |
                        IOMUXC_SW_PAD_CTL_PAD_PUE_MASK |
                        IOMUXC_SW_PAD_CTL_PAD_PE_MASK);
    IOMUXC_SetPinMux(IOMUXC_UART4_TXD_UART4_TX, 0U);
    IOMUXC_SetPinConfig(IOMUXC_UART4_TXD_UART4_TX, 
                        IOMUXC_SW_PAD_CTL_PAD_DSE(3U) |
                        IOMUXC_SW_PAD_CTL_PAD_PUE_MASK |
                        IOMUXC_SW_PAD_CTL_PAD_PE_MASK);
}

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
