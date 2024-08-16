/*
 * Copyright 2019-2022 NXP
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
  - {pin_num: AJ5, peripheral: UART4, signal: uart_rx, pin_signal: UART4_RXD, PE: Enabled, PUE: Weak_Pull_Up, DSE: X1}
  - {pin_num: AH5, peripheral: UART4, signal: uart_tx, pin_signal: UART4_TXD, PE: Enabled, PUE: Weak_Pull_Up, DSE: X1}
  - {pin_num: AH9, peripheral: ENET1, signal: enet_mdc, pin_signal: SAI1_RXD2, PE: Disabled, DSE: X2}
  - {pin_num: AJ8, peripheral: ENET1, signal: enet_mdio, pin_signal: SAI1_RXD3, PE: Disabled, DSE: X2}
  - {pin_num: AD10, peripheral: ENET1, signal: 'enet_rgmii_rd, 0', pin_signal: SAI1_RXD4, PE: Disabled, HYS: Schmitt, FSEL: Fast}
  - {pin_num: AE10, peripheral: ENET1, signal: 'enet_rgmii_rd, 1', pin_signal: SAI1_RXD5, PE: Disabled, HYS: Schmitt, FSEL: Fast}
  - {pin_num: AH10, peripheral: ENET1, signal: 'enet_rgmii_rd, 2', pin_signal: SAI1_RXD6, PE: Disabled, HYS: Schmitt, FSEL: Fast}
  - {pin_num: AH12, peripheral: ENET1, signal: 'enet_rgmii_rd, 3', pin_signal: SAI1_RXD7, PE: Disabled, HYS: Schmitt, FSEL: Fast}
  - {pin_num: AF12, peripheral: ENET1, signal: enet_rgmii_rx_ctl, pin_signal: SAI1_TXFS, PE: Disabled, HYS: Schmitt, FSEL: Fast}
  - {pin_num: AJ12, peripheral: ENET1, signal: enet_rgmii_rxc, pin_signal: SAI1_TXC, PE: Disabled, HYS: Schmitt, FSEL: Fast}
  - {pin_num: AJ11, peripheral: ENET1, signal: 'enet_rgmii_td, 0', pin_signal: SAI1_TXD0, PE: Disabled, HYS: CMOS, FSEL: Fast}
  - {pin_num: AJ10, peripheral: ENET1, signal: 'enet_rgmii_td, 1', pin_signal: SAI1_TXD1, PE: Disabled, HYS: CMOS, FSEL: Fast}
  - {pin_num: AH11, peripheral: ENET1, signal: 'enet_rgmii_td, 2', pin_signal: SAI1_TXD2, PE: Disabled, HYS: CMOS, FSEL: Fast}
  - {pin_num: AD12, peripheral: ENET1, signal: 'enet_rgmii_td, 3', pin_signal: SAI1_TXD3, PE: Disabled, HYS: CMOS, FSEL: Fast}
  - {pin_num: AH13, peripheral: ENET1, signal: enet_rgmii_tx_ctl, pin_signal: SAI1_TXD4, PE: Disabled, HYS: CMOS, FSEL: Fast}
  - {pin_num: AH14, peripheral: ENET1, signal: enet_rgmii_txc, pin_signal: SAI1_TXD5, PE: Disabled, HYS: CMOS, FSEL: Fast}
  - {pin_num: AC10, peripheral: GPIO4, signal: 'gpio_io, 02', pin_signal: SAI1_RXD0, PE: Disabled, FSEL: Slow, DSE: X1}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void) {                                /*!< Function assigned for the core: Cortex-M7F[m7] */
    IOMUXC_SetPinMux(IOMUXC_SAI1_RXD0_GPIO4_IO02, 0U);
    IOMUXC_SetPinConfig(IOMUXC_SAI1_RXD0_GPIO4_IO02, 0U);
    IOMUXC_SetPinMux(IOMUXC_SAI1_RXD2_ENET1_MDC, 0U);
    IOMUXC_SetPinConfig(IOMUXC_SAI1_RXD2_ENET1_MDC, 
                        IOMUXC_SW_PAD_CTL_PAD_DSE(2U));
    IOMUXC_SetPinMux(IOMUXC_SAI1_RXD3_ENET1_MDIO, 0U);
    IOMUXC_SetPinConfig(IOMUXC_SAI1_RXD3_ENET1_MDIO, 
                        IOMUXC_SW_PAD_CTL_PAD_DSE(2U));
    IOMUXC_SetPinMux(IOMUXC_SAI1_RXD4_ENET1_RGMII_RD0, 0U);
    IOMUXC_SetPinConfig(IOMUXC_SAI1_RXD4_ENET1_RGMII_RD0, 
                        IOMUXC_SW_PAD_CTL_PAD_DSE(3U) |
                        IOMUXC_SW_PAD_CTL_PAD_FSEL_MASK |
                        IOMUXC_SW_PAD_CTL_PAD_HYS_MASK);
    IOMUXC_SetPinMux(IOMUXC_SAI1_RXD5_ENET1_RGMII_RD1, 0U);
    IOMUXC_SetPinConfig(IOMUXC_SAI1_RXD5_ENET1_RGMII_RD1, 
                        IOMUXC_SW_PAD_CTL_PAD_DSE(3U) |
                        IOMUXC_SW_PAD_CTL_PAD_FSEL_MASK |
                        IOMUXC_SW_PAD_CTL_PAD_HYS_MASK);
    IOMUXC_SetPinMux(IOMUXC_SAI1_RXD6_ENET1_RGMII_RD2, 0U);
    IOMUXC_SetPinConfig(IOMUXC_SAI1_RXD6_ENET1_RGMII_RD2, 
                        IOMUXC_SW_PAD_CTL_PAD_DSE(3U) |
                        IOMUXC_SW_PAD_CTL_PAD_FSEL_MASK |
                        IOMUXC_SW_PAD_CTL_PAD_HYS_MASK);
    IOMUXC_SetPinMux(IOMUXC_SAI1_RXD7_ENET1_RGMII_RD3, 0U);
    IOMUXC_SetPinConfig(IOMUXC_SAI1_RXD7_ENET1_RGMII_RD3, 
                        IOMUXC_SW_PAD_CTL_PAD_DSE(3U) |
                        IOMUXC_SW_PAD_CTL_PAD_FSEL_MASK |
                        IOMUXC_SW_PAD_CTL_PAD_HYS_MASK);
    IOMUXC_SetPinMux(IOMUXC_SAI1_TXC_ENET1_RGMII_RXC, 0U);
    IOMUXC_SetPinConfig(IOMUXC_SAI1_TXC_ENET1_RGMII_RXC, 
                        IOMUXC_SW_PAD_CTL_PAD_DSE(3U) |
                        IOMUXC_SW_PAD_CTL_PAD_FSEL_MASK |
                        IOMUXC_SW_PAD_CTL_PAD_HYS_MASK);
    IOMUXC_SetPinMux(IOMUXC_SAI1_TXD0_ENET1_RGMII_TD0, 0U);
    IOMUXC_SetPinConfig(IOMUXC_SAI1_TXD0_ENET1_RGMII_TD0, 
                        IOMUXC_SW_PAD_CTL_PAD_DSE(3U) |
                        IOMUXC_SW_PAD_CTL_PAD_FSEL_MASK);
    IOMUXC_SetPinMux(IOMUXC_SAI1_TXD1_ENET1_RGMII_TD1, 0U);
    IOMUXC_SetPinConfig(IOMUXC_SAI1_TXD1_ENET1_RGMII_TD1, 
                        IOMUXC_SW_PAD_CTL_PAD_DSE(3U) |
                        IOMUXC_SW_PAD_CTL_PAD_FSEL_MASK);
    IOMUXC_SetPinMux(IOMUXC_SAI1_TXD2_ENET1_RGMII_TD2, 0U);
    IOMUXC_SetPinConfig(IOMUXC_SAI1_TXD2_ENET1_RGMII_TD2, 
                        IOMUXC_SW_PAD_CTL_PAD_DSE(3U) |
                        IOMUXC_SW_PAD_CTL_PAD_FSEL_MASK);
    IOMUXC_SetPinMux(IOMUXC_SAI1_TXD3_ENET1_RGMII_TD3, 0U);
    IOMUXC_SetPinConfig(IOMUXC_SAI1_TXD3_ENET1_RGMII_TD3, 
                        IOMUXC_SW_PAD_CTL_PAD_DSE(3U) |
                        IOMUXC_SW_PAD_CTL_PAD_FSEL_MASK);
    IOMUXC_SetPinMux(IOMUXC_SAI1_TXD4_ENET1_RGMII_TX_CTL, 0U);
    IOMUXC_SetPinConfig(IOMUXC_SAI1_TXD4_ENET1_RGMII_TX_CTL, 
                        IOMUXC_SW_PAD_CTL_PAD_DSE(3U) |
                        IOMUXC_SW_PAD_CTL_PAD_FSEL_MASK);
    IOMUXC_SetPinMux(IOMUXC_SAI1_TXD5_ENET1_RGMII_TXC, 0U);
    IOMUXC_SetPinConfig(IOMUXC_SAI1_TXD5_ENET1_RGMII_TXC, 
                        IOMUXC_SW_PAD_CTL_PAD_DSE(3U) |
                        IOMUXC_SW_PAD_CTL_PAD_FSEL_MASK);
    IOMUXC_SetPinMux(IOMUXC_SAI1_TXFS_ENET1_RGMII_RX_CTL, 0U);
    IOMUXC_SetPinConfig(IOMUXC_SAI1_TXFS_ENET1_RGMII_RX_CTL, 
                        IOMUXC_SW_PAD_CTL_PAD_DSE(3U) |
                        IOMUXC_SW_PAD_CTL_PAD_FSEL_MASK |
                        IOMUXC_SW_PAD_CTL_PAD_HYS_MASK);
    IOMUXC_SetPinMux(IOMUXC_NAND_ALE_UART3_RX, 0U);
    IOMUXC_SetPinConfig(IOMUXC_NAND_ALE_UART3_RX, 
                        IOMUXC_SW_PAD_CTL_PAD_PUE_MASK |
                        IOMUXC_SW_PAD_CTL_PAD_PE_MASK);
    IOMUXC_SetPinMux(IOMUXC_NAND_CE0_B_UART3_TX, 0U);
    IOMUXC_SetPinConfig(IOMUXC_NAND_CE0_B_UART3_TX, 
                        IOMUXC_SW_PAD_CTL_PAD_PUE_MASK |
                        IOMUXC_SW_PAD_CTL_PAD_PE_MASK);
}

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
