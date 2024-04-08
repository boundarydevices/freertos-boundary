/*
 * Copyright 2023 NXP
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
product: Pins v13.0
processor: MIMX9352xxxxM
package_id: MIMX9352DVVXM
mcu_data: ksdk2_0
processor_version: 0.13.4
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
  - {pin_num: D20, peripheral: LPI2C2, signal: lpi2c_scl, pin_signal: I2C2_SCL, SION: ENABLED, HYS: DISABLED, OD: ENABLED, PD: DISABLED}
  - {pin_num: D21, peripheral: LPI2C2, signal: lpi2c_sda, pin_signal: I2C2_SDA, SION: ENABLED, OD: ENABLED, PD: DISABLED}
  - {pin_num: F21, peripheral: LPUART2, signal: lpuart_tx, pin_signal: UART2_TXD, OD: no_init, PD: DISABLED, PU: DISABLED, FSEL1: SlOW_SLEW_RATE}
  - {pin_num: F20, peripheral: LPUART2, signal: lpuart_rx, pin_signal: UART2_RXD, OD: DISABLED, PD: ENABLED, PU: DISABLED, FSEL1: SlOW_SLEW_RATE, DSE: NO_DRIVE}
  - {pin_num: V16, peripheral: FLEXSPI1, signal: flexspi_a_sclk, pin_signal: SD3_CLK, PD: DISABLED, FSEL1: SlOW_SLEW_RATE, DSE: X6}
  - {pin_num: T16, peripheral: FLEXSPI1, signal: 'flexspi_a_data, 00', pin_signal: SD3_DATA0, PD: DISABLED, FSEL1: SlOW_SLEW_RATE, DSE: X6}
  - {pin_num: V14, peripheral: FLEXSPI1, signal: 'flexspi_a_data, 01', pin_signal: SD3_DATA1, PD: DISABLED, FSEL1: SlOW_SLEW_RATE, DSE: X6}
  - {pin_num: U14, peripheral: FLEXSPI1, signal: 'flexspi_a_data, 02', pin_signal: SD3_DATA2, PD: DISABLED, FSEL1: SlOW_SLEW_RATE, DSE: X6}
  - {pin_num: T14, peripheral: FLEXSPI1, signal: 'flexspi_a_data, 03', pin_signal: SD3_DATA3, PD: DISABLED, FSEL1: SlOW_SLEW_RATE, DSE: X6}
  - {pin_num: U16, peripheral: USDHC3, signal: 'flexspi_a_ss_b, 0', pin_signal: SD3_CMD, PD: DISABLED, FSEL1: SlOW_SLEW_RATE, DSE: X6}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void) {                                /*!< Function assigned for the core: Cortex-M33[cm33] */
    IOMUXC_SetPinMux(IOMUXC_PAD_I2C2_SCL__LPI2C2_SCL, 1U);
    IOMUXC_SetPinConfig(IOMUXC_PAD_I2C2_SCL__LPI2C2_SCL,
                        IOMUXC_PAD_DSE(15U) |
                        IOMUXC_PAD_FSEL1(2U) |
                        IOMUXC_PAD_OD_MASK);
    IOMUXC_SetPinMux(IOMUXC_PAD_I2C2_SDA__LPI2C2_SDA, 1U);
    IOMUXC_SetPinConfig(IOMUXC_PAD_I2C2_SDA__LPI2C2_SDA,
                        IOMUXC_PAD_DSE(15U) |
                        IOMUXC_PAD_FSEL1(2U) |
                        IOMUXC_PAD_OD_MASK);
    IOMUXC_SetPinMux(IOMUXC_PAD_SD3_CLK__FLEXSPI1_A_SCLK, 0U);
    IOMUXC_SetPinConfig(IOMUXC_PAD_SD3_CLK__FLEXSPI1_A_SCLK,
                        IOMUXC_PAD_DSE(63U));
    IOMUXC_SetPinMux(IOMUXC_PAD_SD3_CMD__FLEXSPI1_A_SS0_B, 0U);
    IOMUXC_SetPinConfig(IOMUXC_PAD_SD3_CMD__FLEXSPI1_A_SS0_B,
                        IOMUXC_PAD_DSE(63U));
    IOMUXC_SetPinMux(IOMUXC_PAD_SD3_DATA0__FLEXSPI1_A_DATA00, 0U);
    IOMUXC_SetPinConfig(IOMUXC_PAD_SD3_DATA0__FLEXSPI1_A_DATA00,
                        IOMUXC_PAD_DSE(63U));
    IOMUXC_SetPinMux(IOMUXC_PAD_SD3_DATA1__FLEXSPI1_A_DATA01, 0U);
    IOMUXC_SetPinConfig(IOMUXC_PAD_SD3_DATA1__FLEXSPI1_A_DATA01,
                        IOMUXC_PAD_DSE(63U));
    IOMUXC_SetPinMux(IOMUXC_PAD_SD3_DATA2__FLEXSPI1_A_DATA02, 0U);
    IOMUXC_SetPinConfig(IOMUXC_PAD_SD3_DATA2__FLEXSPI1_A_DATA02,
                        IOMUXC_PAD_DSE(63U));
    IOMUXC_SetPinMux(IOMUXC_PAD_SD3_DATA3__FLEXSPI1_A_DATA03, 0U);
    IOMUXC_SetPinConfig(IOMUXC_PAD_SD3_DATA3__FLEXSPI1_A_DATA03,
                        IOMUXC_PAD_DSE(63U));
    IOMUXC_SetPinMux(IOMUXC_PAD_UART2_RXD__LPUART2_RX, 0U);
    IOMUXC_SetPinConfig(IOMUXC_PAD_UART2_RXD__LPUART2_RX,
                        IOMUXC_PAD_PD_MASK);
    IOMUXC_SetPinMux(IOMUXC_PAD_UART2_TXD__LPUART2_TX, 0U);
    IOMUXC_SetPinConfig(IOMUXC_PAD_UART2_TXD__LPUART2_TX,
                        IOMUXC_PAD_DSE(15U));
}

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
