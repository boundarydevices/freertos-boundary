/*
 * Copyright 2019 NXP
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
product: Pins v6.0
processor: MIMX8MN6xxxJZ
package_id: MIMX8MN6DVTJZ
mcu_data: ksdk2_0
processor_version: 0.0.0
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
}

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'false', coreID: m7}
- pin_list:
  - {pin_num: F19, peripheral: UART4, signal: uart_rx, pin_signal: UART4_RXD, PE: Disabled, FSEL: FAST0, DSE: X6_0}
  - {pin_num: F18, peripheral: UART4, signal: uart_tx, pin_signal: UART4_TXD, PE: Disabled, FSEL: FAST0, DSE: X6_0}
  - {pin_num: AC15, peripheral: PDM, signal: pdm_clk, pin_signal: SAI5_RXC, PE: Disabled, DSE: X6_1}
  - {pin_num: AD18, peripheral: PDM, signal: 'pdm_bit_stream, 0', pin_signal: SAI5_RXD0, PE: Enabled, PUE: Enabled, FSEL: FAST0, DSE: X6_1}
  - {pin_num: AC14, peripheral: PDM, signal: 'pdm_bit_stream, 1', pin_signal: SAI5_RXD1, PE: Enabled, PUE: Enabled, FSEL: FAST0, DSE: X6_1}
  - {pin_num: AD13, peripheral: PDM, signal: 'pdm_bit_stream, 2', pin_signal: SAI5_RXD2, PE: Enabled, PUE: Enabled, FSEL: FAST0, DSE: X6_1}
  - {pin_num: AC13, peripheral: PDM, signal: 'pdm_bit_stream, 3', pin_signal: SAI5_RXD3, PE: Enabled, PUE: Enabled, FSEL: FAST0, DSE: X6_1}
  - {pin_num: E13, peripheral: GPIO5, signal: 'gpio_io, 21', pin_signal: I2C4_SDA, SION: DISABLED}
  - {pin_num: AD6, peripheral: SAI3, signal: sai_mclk, pin_signal: SAI3_MCLK, PE: Disabled, HYS: Enabled, FSEL: FAST0, DSE: X4_0}
  - {pin_num: AG6, peripheral: SAI3, signal: sai_tx_bclk, pin_signal: SAI3_TXC, PE: Disabled, HYS: Enabled, FSEL: FAST0, DSE: X4_0}
  - {pin_num: AF6, peripheral: SAI3, signal: 'sai_tx_data, 0', pin_signal: SAI3_TXD, PE: Disabled, HYS: Enabled, FSEL: FAST0, DSE: X4_0}
  - {pin_num: AC6, peripheral: SAI3, signal: sai_tx_sync, pin_signal: SAI3_TXFS, PE: Disabled, HYS: Enabled, FSEL: FAST0, DSE: X4_0}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void) {                                /*!< Function assigned for the core: Cortex-M7F[m7] */
    IOMUXC_SetPinMux(IOMUXC_I2C4_SDA_GPIO5_IO21, 0U);
    IOMUXC_SetPinMux(IOMUXC_SAI3_MCLK_SAI3_MCLK, 0U);
    IOMUXC_SetPinConfig(IOMUXC_SAI3_MCLK_SAI3_MCLK, 
                        IOMUXC_SW_PAD_CTL_PAD_DSE(2U) |
                        IOMUXC_SW_PAD_CTL_PAD_FSEL(2U) |
                        IOMUXC_SW_PAD_CTL_PAD_HYS_MASK);
    IOMUXC_SetPinMux(IOMUXC_SAI3_TXC_SAI3_TX_BCLK, 0U);
    IOMUXC_SetPinConfig(IOMUXC_SAI3_TXC_SAI3_TX_BCLK, 
                        IOMUXC_SW_PAD_CTL_PAD_DSE(2U) |
                        IOMUXC_SW_PAD_CTL_PAD_FSEL(2U) |
                        IOMUXC_SW_PAD_CTL_PAD_HYS_MASK);
    IOMUXC_SetPinMux(IOMUXC_SAI3_TXD_SAI3_TX_DATA0, 0U);
    IOMUXC_SetPinConfig(IOMUXC_SAI3_TXD_SAI3_TX_DATA0, 
                        IOMUXC_SW_PAD_CTL_PAD_DSE(2U) |
                        IOMUXC_SW_PAD_CTL_PAD_FSEL(2U) |
                        IOMUXC_SW_PAD_CTL_PAD_HYS_MASK);
    IOMUXC_SetPinMux(IOMUXC_SAI3_TXFS_SAI3_TX_SYNC, 0U);
    IOMUXC_SetPinConfig(IOMUXC_SAI3_TXFS_SAI3_TX_SYNC, 
                        IOMUXC_SW_PAD_CTL_PAD_DSE(2U) |
                        IOMUXC_SW_PAD_CTL_PAD_FSEL(2U) |
                        IOMUXC_SW_PAD_CTL_PAD_HYS_MASK);
    IOMUXC_SetPinMux(IOMUXC_SAI5_RXC_PDM_CLK, 0U);
    IOMUXC_SetPinConfig(IOMUXC_SAI5_RXC_PDM_CLK, 
                        IOMUXC_SW_PAD_CTL_PAD_DSE(7U) |
                        IOMUXC_SW_PAD_CTL_PAD_FSEL(2U));
    IOMUXC_SetPinMux(IOMUXC_SAI5_RXD0_PDM_BIT_STREAM0, 0U);
    IOMUXC_SetPinConfig(IOMUXC_SAI5_RXD0_PDM_BIT_STREAM0, 
                        IOMUXC_SW_PAD_CTL_PAD_DSE(7U) |
                        IOMUXC_SW_PAD_CTL_PAD_FSEL(2U) |
                        IOMUXC_SW_PAD_CTL_PAD_PUE_MASK |
                        IOMUXC_SW_PAD_CTL_PAD_PE_MASK);
    IOMUXC_SetPinMux(IOMUXC_SAI5_RXD1_PDM_BIT_STREAM1, 0U);
    IOMUXC_SetPinConfig(IOMUXC_SAI5_RXD1_PDM_BIT_STREAM1, 
                        IOMUXC_SW_PAD_CTL_PAD_DSE(7U) |
                        IOMUXC_SW_PAD_CTL_PAD_FSEL(2U) |
                        IOMUXC_SW_PAD_CTL_PAD_PUE_MASK |
                        IOMUXC_SW_PAD_CTL_PAD_PE_MASK);
    IOMUXC_SetPinMux(IOMUXC_SAI5_RXD2_PDM_BIT_STREAM2, 0U);
    IOMUXC_SetPinConfig(IOMUXC_SAI5_RXD2_PDM_BIT_STREAM2, 
                        IOMUXC_SW_PAD_CTL_PAD_DSE(7U) |
                        IOMUXC_SW_PAD_CTL_PAD_FSEL(2U) |
                        IOMUXC_SW_PAD_CTL_PAD_PUE_MASK |
                        IOMUXC_SW_PAD_CTL_PAD_PE_MASK);
    IOMUXC_SetPinMux(IOMUXC_SAI5_RXD3_PDM_BIT_STREAM3, 0U);
    IOMUXC_SetPinConfig(IOMUXC_SAI5_RXD3_PDM_BIT_STREAM3, 
                        IOMUXC_SW_PAD_CTL_PAD_DSE(7U) |
                        IOMUXC_SW_PAD_CTL_PAD_FSEL(2U) |
                        IOMUXC_SW_PAD_CTL_PAD_PUE_MASK |
                        IOMUXC_SW_PAD_CTL_PAD_PE_MASK);
    IOMUXC_SetPinMux(IOMUXC_UART4_RXD_UART4_RX, 0U);
    IOMUXC_SetPinConfig(IOMUXC_UART4_RXD_UART4_RX, 
                        IOMUXC_SW_PAD_CTL_PAD_DSE(6U) |
                        IOMUXC_SW_PAD_CTL_PAD_FSEL(2U));
    IOMUXC_SetPinMux(IOMUXC_UART4_TXD_UART4_TX, 0U);
    IOMUXC_SetPinConfig(IOMUXC_UART4_TXD_UART4_TX, 
                        IOMUXC_SW_PAD_CTL_PAD_DSE(6U) |
                        IOMUXC_SW_PAD_CTL_PAD_FSEL(2U));
}

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
