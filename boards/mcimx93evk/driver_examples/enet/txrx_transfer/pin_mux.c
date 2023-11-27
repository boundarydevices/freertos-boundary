/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v12.0
processor: MIMX9352xxxxM
package_id: MIMX9352DVUXM
mcu_data: ksdk2_0
processor_version: 0.12.3
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

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
- options: {callFromInitBoot: 'true', coreID: cm33}
- pin_list:
  - {pin_num: F20, peripheral: LPUART2, signal: lpuart_rx, pin_signal: UART2_RXD, HYS: DISABLED, FSEL1: SlOW_SLEW_RATE, DSE: NO_DRIVE}
  - {pin_num: F21, peripheral: LPUART2, signal: lpuart_tx, pin_signal: UART2_TXD, HYS: DISABLED, PD: DISABLED, FSEL1: SlOW_SLEW_RATE}
  - {pin_num: Y7, peripheral: ENET1, signal: enet_mdc, pin_signal: ENET2_MDC, HYS: DISABLED, DSE: X6}
  - {pin_num: AA6, peripheral: ENET1, signal: enet_mdio, pin_signal: ENET2_MDIO, HYS: DISABLED, DSE: X6}
  - {pin_num: AA4, peripheral: ENET1, signal: 'enet_rgmii_rd, 0', pin_signal: ENET2_RD0, HYS: DISABLED, DSE: X6}
  - {pin_num: Y5, peripheral: ENET1, signal: 'enet_rgmii_rd, 1', pin_signal: ENET2_RD1, HYS: DISABLED, DSE: X6}
  - {pin_num: AA5, peripheral: ENET1, signal: 'enet_rgmii_rd, 2', pin_signal: ENET2_RD2, HYS: DISABLED, DSE: X6}
  - {pin_num: Y6, peripheral: ENET1, signal: 'enet_rgmii_rd, 3', pin_signal: ENET2_RD3, HYS: DISABLED, DSE: X6}
  - {pin_num: Y4, peripheral: ENET1, signal: enet_rgmii_rx_ctl, pin_signal: ENET2_RX_CTL, HYS: DISABLED, DSE: X6}
  - {pin_num: AA3, peripheral: ENET1, signal: enet_rgmii_rxc, pin_signal: ENET2_RXC, HYS: DISABLED, FSEL1: FAST_SLEW_RATE, DSE: X6}
  - {pin_num: T8, peripheral: ENET1, signal: 'enet_rgmii_td, 0', pin_signal: ENET2_TD0, HYS: DISABLED, PD: DISABLED, DSE: X6}
  - {pin_num: U8, peripheral: ENET1, signal: 'enet_rgmii_td, 1', pin_signal: ENET2_TD1, HYS: DISABLED, PD: DISABLED, DSE: X6}
  - {pin_num: V8, peripheral: ENET1, signal: 'enet_rgmii_td, 2', pin_signal: ENET2_TD2, HYS: DISABLED, PD: DISABLED, DSE: X6}
  - {pin_num: T10, peripheral: ENET1, signal: 'enet_rgmii_td, 3', pin_signal: ENET2_TD3, HYS: DISABLED, PD: DISABLED, DSE: X6}
  - {pin_num: V6, peripheral: ENET1, signal: enet_rgmii_tx_ctl, pin_signal: ENET2_TX_CTL, HYS: DISABLED, PD: DISABLED, DSE: X6}
  - {pin_num: U6, peripheral: ENET1, signal: enet_rgmii_txc, pin_signal: ENET2_TXC, HYS: DISABLED, PD: DISABLED, FSEL1: FAST_SLEW_RATE, DSE: X6}
  - {pin_num: D20, peripheral: LPI2C2, signal: lpi2c_scl, pin_signal: I2C2_SCL, SION: ENABLED, HYS: DISABLED, OD: ENABLED, PD: DISABLED}
  - {pin_num: D21, peripheral: LPI2C2, signal: lpi2c_sda, pin_signal: I2C2_SDA, SION: ENABLED, HYS: DISABLED, OD: ENABLED, PD: DISABLED}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void) {                                /*!< Function assigned for the core: undefined[cm33] */
    IOMUXC_SetPinMux(IOMUXC_PAD_ENET2_MDC__ENET1_MDC, 0U);
    IOMUXC_SetPinMux(IOMUXC_PAD_ENET2_MDIO__ENET1_MDIO, 0U);
    IOMUXC_SetPinMux(IOMUXC_PAD_ENET2_RD0__ENET1_RGMII_RD0, 0U);
    IOMUXC_SetPinMux(IOMUXC_PAD_ENET2_RD1__ENET1_RGMII_RD1, 0U);
    IOMUXC_SetPinMux(IOMUXC_PAD_ENET2_RD2__ENET1_RGMII_RD2, 0U);
    IOMUXC_SetPinMux(IOMUXC_PAD_ENET2_RD3__ENET1_RGMII_RD3, 0U);
    IOMUXC_SetPinMux(IOMUXC_PAD_ENET2_RXC__ENET1_RGMII_RXC, 0U);
    IOMUXC_SetPinMux(IOMUXC_PAD_ENET2_RX_CTL__ENET1_RGMII_RX_CTL, 0U);
    IOMUXC_SetPinMux(IOMUXC_PAD_ENET2_TD0__ENET1_RGMII_TD0, 0U);
    IOMUXC_SetPinMux(IOMUXC_PAD_ENET2_TD1__ENET1_RGMII_TD1, 0U);
    IOMUXC_SetPinMux(IOMUXC_PAD_ENET2_TD2__ENET1_RGMII_TD2, 0U);
    IOMUXC_SetPinMux(IOMUXC_PAD_ENET2_TD3__ENET1_RGMII_TD3, 0U);
    IOMUXC_SetPinMux(IOMUXC_PAD_ENET2_TXC__ENET1_RGMII_TXC, 0U);
    IOMUXC_SetPinMux(IOMUXC_PAD_ENET2_TX_CTL__ENET1_RGMII_TX_CTL, 0U);
    IOMUXC_SetPinMux(IOMUXC_PAD_I2C2_SCL__LPI2C2_SCL, 1U);
    IOMUXC_SetPinMux(IOMUXC_PAD_I2C2_SDA__LPI2C2_SDA, 1U);
    IOMUXC_SetPinMux(IOMUXC_PAD_UART2_RXD__LPUART2_RX, 0U);
    IOMUXC_SetPinMux(IOMUXC_PAD_UART2_TXD__LPUART2_TX, 0U);

    IOMUXC_SetPinConfig(IOMUXC_PAD_ENET2_MDC__ENET1_MDC, 
                        IOMUXC_PAD_DSE(63U) |
                        IOMUXC_PAD_FSEL1(2U) |
                        IOMUXC_PAD_PD_MASK);
    IOMUXC_SetPinConfig(IOMUXC_PAD_ENET2_MDIO__ENET1_MDIO, 
                        IOMUXC_PAD_DSE(63U) |
                        IOMUXC_PAD_FSEL1(2U) |
                        IOMUXC_PAD_PD_MASK);
    IOMUXC_SetPinConfig(IOMUXC_PAD_ENET2_RD0__ENET1_RGMII_RD0, 
                        IOMUXC_PAD_DSE(63U) |
                        IOMUXC_PAD_FSEL1(2U) |
                        IOMUXC_PAD_PD_MASK);
    IOMUXC_SetPinConfig(IOMUXC_PAD_ENET2_RD1__ENET1_RGMII_RD1, 
                        IOMUXC_PAD_DSE(63U) |
                        IOMUXC_PAD_FSEL1(2U) |
                        IOMUXC_PAD_PD_MASK);
    IOMUXC_SetPinConfig(IOMUXC_PAD_ENET2_RD2__ENET1_RGMII_RD2, 
                        IOMUXC_PAD_DSE(63U) |
                        IOMUXC_PAD_FSEL1(2U) |
                        IOMUXC_PAD_PD_MASK);
    IOMUXC_SetPinConfig(IOMUXC_PAD_ENET2_RD3__ENET1_RGMII_RD3, 
                        IOMUXC_PAD_DSE(63U) |
                        IOMUXC_PAD_FSEL1(2U) |
                        IOMUXC_PAD_PD_MASK);
    IOMUXC_SetPinConfig(IOMUXC_PAD_ENET2_RXC__ENET1_RGMII_RXC, 
                        IOMUXC_PAD_DSE(63U) |
                        IOMUXC_PAD_FSEL1(3U) |
                        IOMUXC_PAD_PD_MASK);
    IOMUXC_SetPinConfig(IOMUXC_PAD_ENET2_RX_CTL__ENET1_RGMII_RX_CTL, 
                        IOMUXC_PAD_DSE(63U) |
                        IOMUXC_PAD_FSEL1(2U) |
                        IOMUXC_PAD_PD_MASK);
    IOMUXC_SetPinConfig(IOMUXC_PAD_ENET2_TD0__ENET1_RGMII_TD0, 
                        IOMUXC_PAD_DSE(63U) |
                        IOMUXC_PAD_FSEL1(2U));
    IOMUXC_SetPinConfig(IOMUXC_PAD_ENET2_TD1__ENET1_RGMII_TD1, 
                        IOMUXC_PAD_DSE(63U) |
                        IOMUXC_PAD_FSEL1(2U));
    IOMUXC_SetPinConfig(IOMUXC_PAD_ENET2_TD2__ENET1_RGMII_TD2, 
                        IOMUXC_PAD_DSE(63U) |
                        IOMUXC_PAD_FSEL1(2U));
    IOMUXC_SetPinConfig(IOMUXC_PAD_ENET2_TD3__ENET1_RGMII_TD3, 
                        IOMUXC_PAD_DSE(63U) |
                        IOMUXC_PAD_FSEL1(2U));
    IOMUXC_SetPinConfig(IOMUXC_PAD_ENET2_TXC__ENET1_RGMII_TXC, 
                        IOMUXC_PAD_DSE(63U) |
                        IOMUXC_PAD_FSEL1(3U));
    IOMUXC_SetPinConfig(IOMUXC_PAD_ENET2_TX_CTL__ENET1_RGMII_TX_CTL, 
                        IOMUXC_PAD_DSE(63U) |
                        IOMUXC_PAD_FSEL1(2U));
    IOMUXC_SetPinConfig(IOMUXC_PAD_I2C2_SCL__LPI2C2_SCL, 
                        IOMUXC_PAD_DSE(15U) |
                        IOMUXC_PAD_FSEL1(2U) |
                        IOMUXC_PAD_OD_MASK);
    IOMUXC_SetPinConfig(IOMUXC_PAD_I2C2_SDA__LPI2C2_SDA, 
                        IOMUXC_PAD_DSE(15U) |
                        IOMUXC_PAD_FSEL1(2U) |
                        IOMUXC_PAD_OD_MASK);
    IOMUXC_SetPinConfig(IOMUXC_PAD_UART2_RXD__LPUART2_RX, 
                        IOMUXC_PAD_PD_MASK);
    IOMUXC_SetPinConfig(IOMUXC_PAD_UART2_TXD__LPUART2_TX, 
                        IOMUXC_PAD_DSE(15U));
}

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
