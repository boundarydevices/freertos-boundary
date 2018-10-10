/*
 * The Clear BSD License
 * Copyright 2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2018 NXP
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted (subject to the limitations in the
 * disclaimer below) provided that the following conditions are met:
 * 
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * 
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * 
 * * Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 * 
 * NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE
 * GRANTED BY THIS LICENSE. THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT
 * HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef _FSL_IOMUXC_H_
#define _FSL_IOMUXC_H_

#include "fsl_common.h"

/*!
 * @addtogroup iomuxc_driver
 * @{
*/

/*! @file */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief IOMUXC driver version 2.0.0. */
#define FSL_IOMUXC_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

/*! @name Pin function ID */
/*@{*/
/*! @brief The pin function ID is a tuple of <muxRegister muxMode inputRegister inputDaisy configRegister> */
#define IOMUXC_PMIC_STBY_REQ                                    0x30330014, 0x0, 0x00000000, 0x0, 0x3033027C
#define IOMUXC_PMIC_ON_REQ                                      0x30330018, 0x0, 0x00000000, 0x0, 0x30330280
#define IOMUXC_ONOFF                                            0x3033001C, 0x0, 0x00000000, 0x0, 0x30330284
#define IOMUXC_POR_B                                            0x30330020, 0x0, 0x00000000, 0x0, 0x30330288
#define IOMUXC_RTC_RESET_B                                      0x30330024, 0x0, 0x00000000, 0x0, 0x3033028C
#define IOMUXC_GPIO1_IO00_GPIO1_IO00                            0x30330028, 0x0, 0x00000000, 0x0, 0x30330290
#define IOMUXC_GPIO1_IO00_CCM_ENET_PHY_REF_CLK_ROOT             0x30330028, 0x1, 0x00000000, 0x0, 0x30330290
#define IOMUXC_GPIO1_IO00_XTALOSC_REF_CLK_32K                   0x30330028, 0x5, 0x00000000, 0x0, 0x30330290
#define IOMUXC_GPIO1_IO00_CCM_EXT_CLK1                          0x30330028, 0x6, 0x00000000, 0x0, 0x30330290
#define IOMUXC_GPIO1_IO01_GPIO1_IO01                            0x3033002C, 0x0, 0x00000000, 0x0, 0x30330294
#define IOMUXC_GPIO1_IO01_PWM1_OUT                              0x3033002C, 0x1, 0x00000000, 0x0, 0x30330294
#define IOMUXC_GPIO1_IO01_XTALOSC_REF_CLK_24M                   0x3033002C, 0x5, 0x00000000, 0x0, 0x30330294
#define IOMUXC_GPIO1_IO01_CCM_EXT_CLK2                          0x3033002C, 0x6, 0x00000000, 0x0, 0x30330294
#define IOMUXC_GPIO1_IO02_GPIO1_IO02                            0x30330030, 0x0, 0x00000000, 0x0, 0x30330298
#define IOMUXC_GPIO1_IO02_WDOG1_WDOG_B                          0x30330030, 0x1, 0x00000000, 0x0, 0x30330298
#define IOMUXC_GPIO1_IO02_WDOG1_WDOG_ANY                        0x30330030, 0x5, 0x00000000, 0x0, 0x30330298
#define IOMUXC_GPIO1_IO03_GPIO1_IO03                            0x30330034, 0x0, 0x00000000, 0x0, 0x3033029C
#define IOMUXC_GPIO1_IO03_USDHC1_VSELECT                        0x30330034, 0x1, 0x00000000, 0x0, 0x3033029C
#define IOMUXC_GPIO1_IO03_SDMA1_EXT_EVENT0                      0x30330034, 0x5, 0x00000000, 0x0, 0x3033029C
#define IOMUXC_GPIO1_IO04_GPIO1_IO04                            0x30330038, 0x0, 0x00000000, 0x0, 0x303302A0
#define IOMUXC_GPIO1_IO04_USDHC2_VSELECT                        0x30330038, 0x1, 0x00000000, 0x0, 0x303302A0
#define IOMUXC_GPIO1_IO04_SDMA1_EXT_EVENT1                      0x30330038, 0x5, 0x00000000, 0x0, 0x303302A0
#define IOMUXC_GPIO1_IO05_GPIO1_IO05                            0x3033003C, 0x0, 0x00000000, 0x0, 0x303302A4
#define IOMUXC_GPIO1_IO05_M4_NMI                                0x3033003C, 0x1, 0x00000000, 0x0, 0x303302A4
#define IOMUXC_GPIO1_IO05_CCM_PMIC_READY                        0x3033003C, 0x5, 0x303304BC, 0x0, 0x303302A4
#define IOMUXC_GPIO1_IO06_GPIO1_IO06                            0x30330040, 0x0, 0x00000000, 0x0, 0x303302A8
#define IOMUXC_GPIO1_IO06_ENET1_MDC                             0x30330040, 0x1, 0x00000000, 0x0, 0x303302A8
#define IOMUXC_GPIO1_IO06_USDHC1_CD_B                           0x30330040, 0x5, 0x00000000, 0x0, 0x303302A8
#define IOMUXC_GPIO1_IO06_CCM_EXT_CLK3                          0x30330040, 0x6, 0x00000000, 0x0, 0x303302A8
#define IOMUXC_GPIO1_IO07_GPIO1_IO07                            0x30330044, 0x0, 0x00000000, 0x0, 0x303302AC
#define IOMUXC_GPIO1_IO07_ENET1_MDIO                            0x30330044, 0x1, 0x303304C0, 0x0, 0x303302AC
#define IOMUXC_GPIO1_IO07_USDHC1_WP                             0x30330044, 0x5, 0x00000000, 0x0, 0x303302AC
#define IOMUXC_GPIO1_IO07_CCM_EXT_CLK4                          0x30330044, 0x6, 0x00000000, 0x0, 0x303302AC
#define IOMUXC_GPIO1_IO08_GPIO1_IO08                            0x30330048, 0x0, 0x00000000, 0x0, 0x303302B0
#define IOMUXC_GPIO1_IO08_ENET1_1588_EVENT0_IN                  0x30330048, 0x1, 0x00000000, 0x0, 0x303302B0
#define IOMUXC_GPIO1_IO08_USDHC2_RESET_B                        0x30330048, 0x5, 0x00000000, 0x0, 0x303302B0
#define IOMUXC_GPIO1_IO09_GPIO1_IO09                            0x3033004C, 0x0, 0x00000000, 0x0, 0x303302B4
#define IOMUXC_GPIO1_IO09_ENET1_1588_EVENT0_OUT                 0x3033004C, 0x1, 0x00000000, 0x0, 0x303302B4
#define IOMUXC_GPIO1_IO09_SDMA2_EXT_EVENT0                      0x3033004C, 0x5, 0x00000000, 0x0, 0x303302B4
#define IOMUXC_GPIO1_IO10_GPIO1_IO10                            0x30330050, 0x0, 0x00000000, 0x0, 0x303302B8
#define IOMUXC_GPIO1_IO10_USB1_OTG_ID                           0x30330050, 0x1, 0x00000000, 0x0, 0x303302B8
#define IOMUXC_GPIO1_IO11_GPIO1_IO11                            0x30330054, 0x0, 0x00000000, 0x0, 0x303302BC
#define IOMUXC_GPIO1_IO11_USB2_OTG_ID                           0x30330054, 0x1, 0x00000000, 0x0, 0x303302BC
#define IOMUXC_GPIO1_IO11_CCM_PMIC_READY                        0x30330054, 0x5, 0x303304BC, 0x1, 0x303302BC
#define IOMUXC_GPIO1_IO12_GPIO1_IO12                            0x30330058, 0x0, 0x00000000, 0x0, 0x303302C0
#define IOMUXC_GPIO1_IO12_USB1_OTG_PWR                          0x30330058, 0x1, 0x00000000, 0x0, 0x303302C0
#define IOMUXC_GPIO1_IO12_SDMA2_EXT_EVENT1                      0x30330058, 0x5, 0x00000000, 0x0, 0x303302C0
#define IOMUXC_GPIO1_IO13_GPIO1_IO13                            0x3033005C, 0x0, 0x00000000, 0x0, 0x303302C4
#define IOMUXC_GPIO1_IO13_USB1_OTG_OC                           0x3033005C, 0x1, 0x00000000, 0x0, 0x303302C4
#define IOMUXC_GPIO1_IO13_PWM2_OUT                              0x3033005C, 0x5, 0x00000000, 0x0, 0x303302C4
#define IOMUXC_GPIO1_IO14_GPIO1_IO14                            0x30330060, 0x0, 0x00000000, 0x0, 0x303302C8
#define IOMUXC_GPIO1_IO14_USB2_OTG_PWR                          0x30330060, 0x1, 0x00000000, 0x0, 0x303302C8
#define IOMUXC_GPIO1_IO14_PWM3_OUT                              0x30330060, 0x5, 0x00000000, 0x0, 0x303302C8
#define IOMUXC_GPIO1_IO14_CCM_CLKO1                             0x30330060, 0x6, 0x00000000, 0x0, 0x303302C8
#define IOMUXC_GPIO1_IO15_GPIO1_IO15                            0x30330064, 0x0, 0x00000000, 0x0, 0x303302CC
#define IOMUXC_GPIO1_IO15_USB2_OTG_OC                           0x30330064, 0x1, 0x00000000, 0x0, 0x303302CC
#define IOMUXC_GPIO1_IO15_PWM4_OUT                              0x30330064, 0x5, 0x00000000, 0x0, 0x303302CC
#define IOMUXC_GPIO1_IO15_CCM_CLKO2                             0x30330064, 0x6, 0x00000000, 0x0, 0x303302CC
#define IOMUXC_ENET_MDC_ENET1_MDC                               0x30330068, 0x0, 0x00000000, 0x0, 0x303302D0
#define IOMUXC_ENET_MDC_GPIO1_IO16                              0x30330068, 0x5, 0x00000000, 0x0, 0x303302D0
#define IOMUXC_ENET_MDIO_ENET1_MDIO                             0x3033006C, 0x0, 0x303304C0, 0x1, 0x303302D4
#define IOMUXC_ENET_MDIO_GPIO1_IO17                             0x3033006C, 0x5, 0x00000000, 0x0, 0x303302D4
#define IOMUXC_ENET_TD3_ENET1_RGMII_TD3                         0x30330070, 0x0, 0x00000000, 0x0, 0x303302D8
#define IOMUXC_ENET_TD3_GPIO1_IO18                              0x30330070, 0x5, 0x00000000, 0x0, 0x303302D8
#define IOMUXC_ENET_TD2_ENET1_RGMII_TD2                         0x30330074, 0x0, 0x00000000, 0x0, 0x303302DC
#define IOMUXC_ENET_TD2_ENET1_TX_CLK                            0x30330074, 0x1, 0x00000000, 0x0, 0x303302DC
#define IOMUXC_ENET_TD2_GPIO1_IO19                              0x30330074, 0x5, 0x00000000, 0x0, 0x303302DC
#define IOMUXC_ENET_TD1_ENET1_RGMII_TD1                         0x30330078, 0x0, 0x00000000, 0x0, 0x303302E0
#define IOMUXC_ENET_TD1_GPIO1_IO20                              0x30330078, 0x5, 0x00000000, 0x0, 0x303302E0
#define IOMUXC_ENET_TD0_ENET1_RGMII_TD0                         0x3033007C, 0x0, 0x00000000, 0x0, 0x303302E4
#define IOMUXC_ENET_TD0_GPIO1_IO21                              0x3033007C, 0x5, 0x00000000, 0x0, 0x303302E4
#define IOMUXC_ENET_TX_CTL_ENET1_RGMII_TX_CTL                   0x30330080, 0x0, 0x00000000, 0x0, 0x303302E8
#define IOMUXC_ENET_TX_CTL_GPIO1_IO22                           0x30330080, 0x5, 0x00000000, 0x0, 0x303302E8
#define IOMUXC_ENET_TXC_ENET1_RGMII_TXC                         0x30330084, 0x0, 0x00000000, 0x0, 0x303302EC
#define IOMUXC_ENET_TXC_ENET1_TX_ER                             0x30330084, 0x1, 0x00000000, 0x0, 0x303302EC
#define IOMUXC_ENET_TXC_GPIO1_IO23                              0x30330084, 0x5, 0x00000000, 0x0, 0x303302EC
#define IOMUXC_ENET_RX_CTL_ENET1_RGMII_RX_CTL                   0x30330088, 0x0, 0x00000000, 0x0, 0x303302F0
#define IOMUXC_ENET_RX_CTL_GPIO1_IO24                           0x30330088, 0x5, 0x00000000, 0x0, 0x303302F0
#define IOMUXC_ENET_RXC_ENET1_RGMII_RXC                         0x3033008C, 0x0, 0x00000000, 0x0, 0x303302F4
#define IOMUXC_ENET_RXC_ENET1_RX_ER                             0x3033008C, 0x1, 0x00000000, 0x0, 0x303302F4
#define IOMUXC_ENET_RXC_GPIO1_IO25                              0x3033008C, 0x5, 0x00000000, 0x0, 0x303302F4
#define IOMUXC_ENET_RD0_ENET1_RGMII_RD0                         0x30330090, 0x0, 0x00000000, 0x0, 0x303302F8
#define IOMUXC_ENET_RD0_GPIO1_IO26                              0x30330090, 0x5, 0x00000000, 0x0, 0x303302F8
#define IOMUXC_ENET_RD1_ENET1_RGMII_RD1                         0x30330094, 0x0, 0x00000000, 0x0, 0x303302FC
#define IOMUXC_ENET_RD1_GPIO1_IO27                              0x30330094, 0x5, 0x00000000, 0x0, 0x303302FC
#define IOMUXC_ENET_RD2_ENET1_RGMII_RD2                         0x30330098, 0x0, 0x00000000, 0x0, 0x30330300
#define IOMUXC_ENET_RD2_GPIO1_IO28                              0x30330098, 0x5, 0x00000000, 0x0, 0x30330300
#define IOMUXC_ENET_RD3_ENET1_RGMII_RD3                         0x3033009C, 0x0, 0x00000000, 0x0, 0x30330304
#define IOMUXC_ENET_RD3_GPIO1_IO29                              0x3033009C, 0x5, 0x00000000, 0x0, 0x30330304
#define IOMUXC_SD1_CLK_USDHC1_CLK                               0x303300A0, 0x0, 0x00000000, 0x0, 0x30330308
#define IOMUXC_SD1_CLK_GPIO2_IO00                               0x303300A0, 0x5, 0x00000000, 0x0, 0x30330308
#define IOMUXC_SD1_CMD_USDHC1_CMD                               0x303300A4, 0x0, 0x00000000, 0x0, 0x3033030C
#define IOMUXC_SD1_CMD_GPIO2_IO01                               0x303300A4, 0x5, 0x00000000, 0x0, 0x3033030C
#define IOMUXC_SD1_DATA0_USDHC1_DATA0                           0x303300A8, 0x0, 0x00000000, 0x0, 0x30330310
#define IOMUXC_SD1_DATA0_GPIO2_IO02                             0x303300A8, 0x5, 0x00000000, 0x0, 0x30330310
#define IOMUXC_SD1_DATA1_USDHC1_DATA1                           0x303300AC, 0x0, 0x00000000, 0x0, 0x30330314
#define IOMUXC_SD1_DATA1_GPIO2_IO03                             0x303300AC, 0x5, 0x00000000, 0x0, 0x30330314
#define IOMUXC_SD1_DATA2_USDHC1_DATA2                           0x303300B0, 0x0, 0x00000000, 0x0, 0x30330318
#define IOMUXC_SD1_DATA2_GPIO2_IO04                             0x303300B0, 0x5, 0x00000000, 0x0, 0x30330318
#define IOMUXC_SD1_DATA3_USDHC1_DATA3                           0x303300B4, 0x0, 0x00000000, 0x0, 0x3033031C
#define IOMUXC_SD1_DATA3_GPIO2_IO05                             0x303300B4, 0x5, 0x00000000, 0x0, 0x3033031C
#define IOMUXC_SD1_DATA4_USDHC1_DATA4                           0x303300B8, 0x0, 0x00000000, 0x0, 0x30330320
#define IOMUXC_SD1_DATA4_GPIO2_IO06                             0x303300B8, 0x5, 0x00000000, 0x0, 0x30330320
#define IOMUXC_SD1_DATA5_USDHC1_DATA5                           0x303300BC, 0x0, 0x00000000, 0x0, 0x30330324
#define IOMUXC_SD1_DATA5_GPIO2_IO07                             0x303300BC, 0x5, 0x00000000, 0x0, 0x30330324
#define IOMUXC_SD1_DATA6_USDHC1_DATA6                           0x303300C0, 0x0, 0x00000000, 0x0, 0x30330328
#define IOMUXC_SD1_DATA6_GPIO2_IO08                             0x303300C0, 0x5, 0x00000000, 0x0, 0x30330328
#define IOMUXC_SD1_DATA7_USDHC1_DATA7                           0x303300C4, 0x0, 0x00000000, 0x0, 0x3033032C
#define IOMUXC_SD1_DATA7_GPIO2_IO09                             0x303300C4, 0x5, 0x00000000, 0x0, 0x3033032C
#define IOMUXC_SD1_RESET_B_USDHC1_RESET_B                       0x303300C8, 0x0, 0x00000000, 0x0, 0x30330330
#define IOMUXC_SD1_RESET_B_GPIO2_IO10                           0x303300C8, 0x5, 0x00000000, 0x0, 0x30330330
#define IOMUXC_SD1_STROBE_USDHC1_STROBE                         0x303300CC, 0x0, 0x00000000, 0x0, 0x30330334
#define IOMUXC_SD1_STROBE_GPIO2_IO11                            0x303300CC, 0x5, 0x00000000, 0x0, 0x30330334
#define IOMUXC_SD2_CD_B_USDHC2_CD_B                             0x303300D0, 0x0, 0x00000000, 0x0, 0x30330338
#define IOMUXC_SD2_CD_B_GPIO2_IO12                              0x303300D0, 0x5, 0x00000000, 0x0, 0x30330338
#define IOMUXC_SD2_CLK_USDHC2_CLK                               0x303300D4, 0x0, 0x00000000, 0x0, 0x3033033C
#define IOMUXC_SD2_CLK_GPIO2_IO13                               0x303300D4, 0x5, 0x00000000, 0x0, 0x3033033C
#define IOMUXC_SD2_CMD_USDHC2_CMD                               0x303300D8, 0x0, 0x00000000, 0x0, 0x30330340
#define IOMUXC_SD2_CMD_GPIO2_IO14                               0x303300D8, 0x5, 0x00000000, 0x0, 0x30330340
#define IOMUXC_SD2_DATA0_USDHC2_DATA0                           0x303300DC, 0x0, 0x00000000, 0x0, 0x30330344
#define IOMUXC_SD2_DATA0_GPIO2_IO15                             0x303300DC, 0x5, 0x00000000, 0x0, 0x30330344
#define IOMUXC_SD2_DATA1_USDHC2_DATA1                           0x303300E0, 0x0, 0x00000000, 0x0, 0x30330348
#define IOMUXC_SD2_DATA1_GPIO2_IO16                             0x303300E0, 0x5, 0x00000000, 0x0, 0x30330348
#define IOMUXC_SD2_DATA2_USDHC2_DATA2                           0x303300E4, 0x0, 0x00000000, 0x0, 0x3033034C
#define IOMUXC_SD2_DATA2_GPIO2_IO17                             0x303300E4, 0x5, 0x00000000, 0x0, 0x3033034C
#define IOMUXC_SD2_DATA3_USDHC2_DATA3                           0x303300E8, 0x0, 0x00000000, 0x0, 0x30330350
#define IOMUXC_SD2_DATA3_GPIO2_IO18                             0x303300E8, 0x5, 0x00000000, 0x0, 0x30330350
#define IOMUXC_SD2_RESET_B_USDHC2_RESET_B                       0x303300EC, 0x0, 0x00000000, 0x0, 0x30330354
#define IOMUXC_SD2_RESET_B_GPIO2_IO19                           0x303300EC, 0x5, 0x00000000, 0x0, 0x30330354
#define IOMUXC_SD2_WP_USDHC2_WP                                 0x303300F0, 0x0, 0x00000000, 0x0, 0x30330358
#define IOMUXC_SD2_WP_GPIO2_IO20                                0x303300F0, 0x5, 0x00000000, 0x0, 0x30330358
#define IOMUXC_NAND_ALE_RAWNAND_ALE                             0x303300F4, 0x0, 0x00000000, 0x0, 0x3033035C
#define IOMUXC_NAND_ALE_QSPI_A_SCLK                             0x303300F4, 0x1, 0x00000000, 0x0, 0x3033035C
#define IOMUXC_NAND_ALE_GPIO3_IO00                              0x303300F4, 0x5, 0x00000000, 0x0, 0x3033035C
#define IOMUXC_NAND_CE0_B_RAWNAND_CE0_B                         0x303300F8, 0x0, 0x00000000, 0x0, 0x30330360
#define IOMUXC_NAND_CE0_B_QSPI_A_SS0_B                          0x303300F8, 0x1, 0x00000000, 0x0, 0x30330360
#define IOMUXC_NAND_CE0_B_GPIO3_IO01                            0x303300F8, 0x5, 0x00000000, 0x0, 0x30330360
#define IOMUXC_NAND_CE1_B_RAWNAND_CE1_B                         0x303300FC, 0x0, 0x00000000, 0x0, 0x30330364
#define IOMUXC_NAND_CE1_B_QSPI_A_SS1_B                          0x303300FC, 0x1, 0x00000000, 0x0, 0x30330364
#define IOMUXC_NAND_CE1_B_GPIO3_IO02                            0x303300FC, 0x5, 0x00000000, 0x0, 0x30330364
#define IOMUXC_NAND_CE2_B_RAWNAND_CE2_B                         0x30330100, 0x0, 0x00000000, 0x0, 0x30330368
#define IOMUXC_NAND_CE2_B_QSPI_B_SS0_B                          0x30330100, 0x1, 0x00000000, 0x0, 0x30330368
#define IOMUXC_NAND_CE2_B_GPIO3_IO03                            0x30330100, 0x5, 0x00000000, 0x0, 0x30330368
#define IOMUXC_NAND_CE3_B_RAWNAND_CE3_B                         0x30330104, 0x0, 0x00000000, 0x0, 0x3033036C
#define IOMUXC_NAND_CE3_B_QSPI_B_SS1_B                          0x30330104, 0x1, 0x00000000, 0x0, 0x3033036C
#define IOMUXC_NAND_CE3_B_GPIO3_IO04                            0x30330104, 0x5, 0x00000000, 0x0, 0x3033036C
#define IOMUXC_NAND_CLE_RAWNAND_CLE                             0x30330108, 0x0, 0x00000000, 0x0, 0x30330370
#define IOMUXC_NAND_CLE_QSPI_B_SCLK                             0x30330108, 0x1, 0x00000000, 0x0, 0x30330370
#define IOMUXC_NAND_CLE_GPIO3_IO05                              0x30330108, 0x5, 0x00000000, 0x0, 0x30330370
#define IOMUXC_NAND_DATA00_RAWNAND_DATA00                       0x3033010C, 0x0, 0x00000000, 0x0, 0x30330374
#define IOMUXC_NAND_DATA00_QSPI_A_DATA0                         0x3033010C, 0x1, 0x00000000, 0x0, 0x30330374
#define IOMUXC_NAND_DATA00_GPIO3_IO06                           0x3033010C, 0x5, 0x00000000, 0x0, 0x30330374
#define IOMUXC_NAND_DATA01_RAWNAND_DATA01                       0x30330110, 0x0, 0x00000000, 0x0, 0x30330378
#define IOMUXC_NAND_DATA01_QSPI_A_DATA1                         0x30330110, 0x1, 0x00000000, 0x0, 0x30330378
#define IOMUXC_NAND_DATA01_GPIO3_IO07                           0x30330110, 0x5, 0x00000000, 0x0, 0x30330378
#define IOMUXC_NAND_DATA02_RAWNAND_DATA02                       0x30330114, 0x0, 0x00000000, 0x0, 0x3033037C
#define IOMUXC_NAND_DATA02_QSPI_A_DATA2                         0x30330114, 0x1, 0x00000000, 0x0, 0x3033037C
#define IOMUXC_NAND_DATA02_GPIO3_IO08                           0x30330114, 0x5, 0x00000000, 0x0, 0x3033037C
#define IOMUXC_NAND_DATA03_RAWNAND_DATA03                       0x30330118, 0x0, 0x00000000, 0x0, 0x30330380
#define IOMUXC_NAND_DATA03_QSPI_A_DATA3                         0x30330118, 0x1, 0x00000000, 0x0, 0x30330380
#define IOMUXC_NAND_DATA03_GPIO3_IO09                           0x30330118, 0x5, 0x00000000, 0x0, 0x30330380
#define IOMUXC_NAND_DATA04_RAWNAND_DATA04                       0x3033011C, 0x0, 0x00000000, 0x0, 0x30330384
#define IOMUXC_NAND_DATA04_QSPI_B_DATA0                         0x3033011C, 0x1, 0x00000000, 0x0, 0x30330384
#define IOMUXC_NAND_DATA04_GPIO3_IO10                           0x3033011C, 0x5, 0x00000000, 0x0, 0x30330384
#define IOMUXC_NAND_DATA05_RAWNAND_DATA05                       0x30330120, 0x0, 0x00000000, 0x0, 0x30330388
#define IOMUXC_NAND_DATA05_QSPI_B_DATA1                         0x30330120, 0x1, 0x00000000, 0x0, 0x30330388
#define IOMUXC_NAND_DATA05_GPIO3_IO11                           0x30330120, 0x5, 0x00000000, 0x0, 0x30330388
#define IOMUXC_NAND_DATA06_RAWNAND_DATA06                       0x30330124, 0x0, 0x00000000, 0x0, 0x3033038C
#define IOMUXC_NAND_DATA06_QSPI_B_DATA2                         0x30330124, 0x1, 0x00000000, 0x0, 0x3033038C
#define IOMUXC_NAND_DATA06_GPIO3_IO12                           0x30330124, 0x5, 0x00000000, 0x0, 0x3033038C
#define IOMUXC_NAND_DATA07_RAWNAND_DATA07                       0x30330128, 0x0, 0x00000000, 0x0, 0x30330390
#define IOMUXC_NAND_DATA07_QSPI_B_DATA3                         0x30330128, 0x1, 0x00000000, 0x0, 0x30330390
#define IOMUXC_NAND_DATA07_GPIO3_IO13                           0x30330128, 0x5, 0x00000000, 0x0, 0x30330390
#define IOMUXC_NAND_DQS_RAWNAND_DQS                             0x3033012C, 0x0, 0x00000000, 0x0, 0x30330394
#define IOMUXC_NAND_DQS_QSPI_A_DQS                              0x3033012C, 0x1, 0x00000000, 0x0, 0x30330394
#define IOMUXC_NAND_DQS_GPIO3_IO14                              0x3033012C, 0x5, 0x00000000, 0x0, 0x30330394
#define IOMUXC_NAND_RE_B_RAWNAND_RE_B                           0x30330130, 0x0, 0x00000000, 0x0, 0x30330398
#define IOMUXC_NAND_RE_B_QSPI_B_DQS                             0x30330130, 0x1, 0x00000000, 0x0, 0x30330398
#define IOMUXC_NAND_RE_B_GPIO3_IO15                             0x30330130, 0x5, 0x00000000, 0x0, 0x30330398
#define IOMUXC_NAND_READY_B_RAWNAND_READY_B                     0x30330134, 0x0, 0x00000000, 0x0, 0x3033039C
#define IOMUXC_NAND_READY_B_GPIO3_IO16                          0x30330134, 0x5, 0x00000000, 0x0, 0x3033039C
#define IOMUXC_NAND_WE_B_RAWNAND_WE_B                           0x30330138, 0x0, 0x00000000, 0x0, 0x303303A0
#define IOMUXC_NAND_WE_B_GPIO3_IO17                             0x30330138, 0x5, 0x00000000, 0x0, 0x303303A0
#define IOMUXC_NAND_WP_B_RAWNAND_WP_B                           0x3033013C, 0x0, 0x00000000, 0x0, 0x303303A4
#define IOMUXC_NAND_WP_B_GPIO3_IO18                             0x3033013C, 0x5, 0x00000000, 0x0, 0x303303A4
#define IOMUXC_SAI5_RXFS_SAI5_RX_SYNC                           0x30330140, 0x0, 0x303304E4, 0x0, 0x303303A8
#define IOMUXC_SAI5_RXFS_SAI1_TX_DATA0                          0x30330140, 0x1, 0x00000000, 0x0, 0x303303A8
#define IOMUXC_SAI5_RXFS_GPIO3_IO19                             0x30330140, 0x5, 0x00000000, 0x0, 0x303303A8
#define IOMUXC_SAI5_RXC_SAI5_RX_BCLK                            0x30330144, 0x0, 0x303304D0, 0x0, 0x303303AC
#define IOMUXC_SAI5_RXC_SAI1_TX_DATA1                           0x30330144, 0x1, 0x00000000, 0x0, 0x303303AC
#define IOMUXC_SAI5_RXC_GPIO3_IO20                              0x30330144, 0x5, 0x00000000, 0x0, 0x303303AC
#define IOMUXC_SAI5_RXD0_SAI5_RX_DATA0                          0x30330148, 0x0, 0x303304D4, 0x0, 0x303303B0
#define IOMUXC_SAI5_RXD0_SAI1_TX_DATA2                          0x30330148, 0x1, 0x00000000, 0x0, 0x303303B0
#define IOMUXC_SAI5_RXD0_GPIO3_IO21                             0x30330148, 0x5, 0x00000000, 0x0, 0x303303B0
#define IOMUXC_SAI5_RXD1_SAI5_RX_DATA1                          0x3033014C, 0x0, 0x303304D8, 0x0, 0x303303B4
#define IOMUXC_SAI5_RXD1_SAI1_TX_DATA3                          0x3033014C, 0x1, 0x00000000, 0x0, 0x303303B4
#define IOMUXC_SAI5_RXD1_SAI1_TX_SYNC                           0x3033014C, 0x2, 0x303304CC, 0x0, 0x303303B4
#define IOMUXC_SAI5_RXD1_SAI5_TX_SYNC                           0x3033014C, 0x3, 0x303304EC, 0x0, 0x303303B4
#define IOMUXC_SAI5_RXD1_GPIO3_IO22                             0x3033014C, 0x5, 0x00000000, 0x0, 0x303303B4
#define IOMUXC_SAI5_RXD2_SAI5_RX_DATA2                          0x30330150, 0x0, 0x303304DC, 0x0, 0x303303B8
#define IOMUXC_SAI5_RXD2_SAI1_TX_DATA4                          0x30330150, 0x1, 0x00000000, 0x0, 0x303303B8
#define IOMUXC_SAI5_RXD2_SAI1_TX_SYNC                           0x30330150, 0x2, 0x303304CC, 0x1, 0x303303B8
#define IOMUXC_SAI5_RXD2_SAI5_TX_BCLK                           0x30330150, 0x3, 0x303304E8, 0x0, 0x303303B8
#define IOMUXC_SAI5_RXD2_GPIO3_IO23                             0x30330150, 0x5, 0x00000000, 0x0, 0x303303B8
#define IOMUXC_SAI5_RXD3_SAI5_RX_DATA3                          0x30330154, 0x0, 0x303304E0, 0x0, 0x303303BC
#define IOMUXC_SAI5_RXD3_SAI1_TX_DATA5                          0x30330154, 0x1, 0x00000000, 0x0, 0x303303BC
#define IOMUXC_SAI5_RXD3_SAI1_TX_SYNC                           0x30330154, 0x2, 0x303304CC, 0x2, 0x303303BC
#define IOMUXC_SAI5_RXD3_SAI5_TX_DATA0                          0x30330154, 0x3, 0x00000000, 0x0, 0x303303BC
#define IOMUXC_SAI5_RXD3_GPIO3_IO24                             0x30330154, 0x5, 0x00000000, 0x0, 0x303303BC
#define IOMUXC_SAI5_MCLK_SAI5_MCLK                              0x30330158, 0x0, 0x3033052C, 0x0, 0x303303C0
#define IOMUXC_SAI5_MCLK_SAI1_TX_BCLK                           0x30330158, 0x1, 0x303304C8, 0x0, 0x303303C0
#define IOMUXC_SAI5_MCLK_SAI4_MCLK                              0x30330158, 0x2, 0x00000000, 0x0, 0x303303C0
#define IOMUXC_SAI5_MCLK_GPIO3_IO25                             0x30330158, 0x5, 0x00000000, 0x0, 0x303303C0
#define IOMUXC_SAI1_RXFS_SAI1_RX_SYNC                           0x3033015C, 0x0, 0x303304C4, 0x0, 0x303303C4
#define IOMUXC_SAI1_RXFS_SAI5_RX_SYNC                           0x3033015C, 0x1, 0x303304E4, 0x1, 0x303303C4
#define IOMUXC_SAI1_RXFS_CORESIGHT_TRACE_CLK                    0x3033015C, 0x4, 0x00000000, 0x0, 0x303303C4
#define IOMUXC_SAI1_RXFS_GPIO4_IO00                             0x3033015C, 0x5, 0x00000000, 0x0, 0x303303C4
#define IOMUXC_SAI1_RXC_SAI1_RX_BCLK                            0x30330160, 0x0, 0x00000000, 0x0, 0x303303C8
#define IOMUXC_SAI1_RXC_SAI5_RX_BCLK                            0x30330160, 0x1, 0x303304D0, 0x1, 0x303303C8
#define IOMUXC_SAI1_RXC_CORESIGHT_TRACE_CTL                     0x30330160, 0x4, 0x00000000, 0x0, 0x303303C8
#define IOMUXC_SAI1_RXC_GPIO4_IO01                              0x30330160, 0x5, 0x00000000, 0x0, 0x303303C8
#define IOMUXC_SAI1_RXD0_SAI1_RX_DATA0                          0x30330164, 0x0, 0x00000000, 0x0, 0x303303CC
#define IOMUXC_SAI1_RXD0_SAI5_RX_DATA0                          0x30330164, 0x1, 0x303304D4, 0x1, 0x303303CC
#define IOMUXC_SAI1_RXD0_CORESIGHT_TRACE0                       0x30330164, 0x4, 0x00000000, 0x0, 0x303303CC
#define IOMUXC_SAI1_RXD0_GPIO4_IO02                             0x30330164, 0x5, 0x00000000, 0x0, 0x303303CC
#define IOMUXC_SAI1_RXD0_SRC_BOOT_CFG0                          0x30330164, 0x6, 0x00000000, 0x0, 0x303303CC
#define IOMUXC_SAI1_RXD1_SAI1_RX_DATA1                          0x30330168, 0x0, 0x00000000, 0x0, 0x303303D0
#define IOMUXC_SAI1_RXD1_SAI5_RX_DATA1                          0x30330168, 0x1, 0x303304D8, 0x1, 0x303303D0
#define IOMUXC_SAI1_RXD1_CORESIGHT_TRACE1                       0x30330168, 0x4, 0x00000000, 0x0, 0x303303D0
#define IOMUXC_SAI1_RXD1_GPIO4_IO03                             0x30330168, 0x5, 0x00000000, 0x0, 0x303303D0
#define IOMUXC_SAI1_RXD1_SRC_BOOT_CFG1                          0x30330168, 0x6, 0x00000000, 0x0, 0x303303D0
#define IOMUXC_SAI1_RXD2_SAI1_RX_DATA2                          0x3033016C, 0x0, 0x00000000, 0x0, 0x303303D4
#define IOMUXC_SAI1_RXD2_SAI5_RX_DATA2                          0x3033016C, 0x1, 0x303304DC, 0x1, 0x303303D4
#define IOMUXC_SAI1_RXD2_CORESIGHT_TRACE2                       0x3033016C, 0x4, 0x00000000, 0x0, 0x303303D4
#define IOMUXC_SAI1_RXD2_GPIO4_IO04                             0x3033016C, 0x5, 0x00000000, 0x0, 0x303303D4
#define IOMUXC_SAI1_RXD2_SRC_BOOT_CFG2                          0x3033016C, 0x6, 0x00000000, 0x0, 0x303303D4
#define IOMUXC_SAI1_RXD3_SAI1_RX_DATA3                          0x30330170, 0x0, 0x00000000, 0x0, 0x303303D8
#define IOMUXC_SAI1_RXD3_SAI5_RX_DATA3                          0x30330170, 0x1, 0x303304E0, 0x1, 0x303303D8
#define IOMUXC_SAI1_RXD3_CORESIGHT_TRACE3                       0x30330170, 0x4, 0x00000000, 0x0, 0x303303D8
#define IOMUXC_SAI1_RXD3_GPIO4_IO05                             0x30330170, 0x5, 0x00000000, 0x0, 0x303303D8
#define IOMUXC_SAI1_RXD3_SRC_BOOT_CFG3                          0x30330170, 0x6, 0x00000000, 0x0, 0x303303D8
#define IOMUXC_SAI1_RXD4_SAI1_RX_DATA4                          0x30330174, 0x0, 0x00000000, 0x0, 0x303303DC
#define IOMUXC_SAI1_RXD4_SAI6_TX_BCLK                           0x30330174, 0x1, 0x3033051C, 0x0, 0x303303DC
#define IOMUXC_SAI1_RXD4_SAI6_RX_BCLK                           0x30330174, 0x2, 0x30330510, 0x0, 0x303303DC
#define IOMUXC_SAI1_RXD4_CORESIGHT_TRACE4                       0x30330174, 0x4, 0x00000000, 0x0, 0x303303DC
#define IOMUXC_SAI1_RXD4_GPIO4_IO06                             0x30330174, 0x5, 0x00000000, 0x0, 0x303303DC
#define IOMUXC_SAI1_RXD4_SRC_BOOT_CFG4                          0x30330174, 0x6, 0x00000000, 0x0, 0x303303DC
#define IOMUXC_SAI1_RXD5_SAI1_RX_DATA5                          0x30330178, 0x0, 0x00000000, 0x0, 0x303303E0
#define IOMUXC_SAI1_RXD5_SAI6_TX_DATA0                          0x30330178, 0x1, 0x00000000, 0x0, 0x303303E0
#define IOMUXC_SAI1_RXD5_SAI6_RX_DATA0                          0x30330178, 0x2, 0x30330514, 0x0, 0x303303E0
#define IOMUXC_SAI1_RXD5_SAI1_RX_SYNC                           0x30330178, 0x3, 0x303304C4, 0x1, 0x303303E0
#define IOMUXC_SAI1_RXD5_CORESIGHT_TRACE5                       0x30330178, 0x4, 0x00000000, 0x0, 0x303303E0
#define IOMUXC_SAI1_RXD5_GPIO4_IO07                             0x30330178, 0x5, 0x00000000, 0x0, 0x303303E0
#define IOMUXC_SAI1_RXD5_SRC_BOOT_CFG5                          0x30330178, 0x6, 0x00000000, 0x0, 0x303303E0
#define IOMUXC_SAI1_RXD6_SAI1_RX_DATA6                          0x3033017C, 0x0, 0x00000000, 0x0, 0x303303E4
#define IOMUXC_SAI1_RXD6_SAI6_TX_SYNC                           0x3033017C, 0x1, 0x30330520, 0x0, 0x303303E4
#define IOMUXC_SAI1_RXD6_SAI6_RX_SYNC                           0x3033017C, 0x2, 0x30330518, 0x0, 0x303303E4
#define IOMUXC_SAI1_RXD6_CORESIGHT_TRACE6                       0x3033017C, 0x4, 0x00000000, 0x0, 0x303303E4
#define IOMUXC_SAI1_RXD6_GPIO4_IO08                             0x3033017C, 0x5, 0x00000000, 0x0, 0x303303E4
#define IOMUXC_SAI1_RXD6_SRC_BOOT_CFG6                          0x3033017C, 0x6, 0x00000000, 0x0, 0x303303E4
#define IOMUXC_SAI1_RXD7_SAI1_RX_DATA7                          0x30330180, 0x0, 0x00000000, 0x0, 0x303303E8
#define IOMUXC_SAI1_RXD7_SAI6_MCLK                              0x30330180, 0x1, 0x30330530, 0x0, 0x303303E8
#define IOMUXC_SAI1_RXD7_SAI1_TX_SYNC                           0x30330180, 0x2, 0x303304CC, 0x4, 0x303303E8
#define IOMUXC_SAI1_RXD7_SAI1_TX_DATA4                          0x30330180, 0x3, 0x00000000, 0x0, 0x303303E8
#define IOMUXC_SAI1_RXD7_CORESIGHT_TRACE7                       0x30330180, 0x4, 0x00000000, 0x0, 0x303303E8
#define IOMUXC_SAI1_RXD7_GPIO4_IO09                             0x30330180, 0x5, 0x00000000, 0x0, 0x303303E8
#define IOMUXC_SAI1_RXD7_SRC_BOOT_CFG7                          0x30330180, 0x6, 0x00000000, 0x0, 0x303303E8
#define IOMUXC_SAI1_TXFS_SAI1_TX_SYNC                           0x30330184, 0x0, 0x303304CC, 0x3, 0x303303EC
#define IOMUXC_SAI1_TXFS_SAI5_TX_SYNC                           0x30330184, 0x1, 0x303304EC, 0x1, 0x303303EC
#define IOMUXC_SAI1_TXFS_CORESIGHT_EVENTO                       0x30330184, 0x4, 0x00000000, 0x0, 0x303303EC
#define IOMUXC_SAI1_TXFS_GPIO4_IO10                             0x30330184, 0x5, 0x00000000, 0x0, 0x303303EC
#define IOMUXC_SAI1_TXC_SAI1_TX_BCLK                            0x30330188, 0x0, 0x303304C8, 0x1, 0x303303F0
#define IOMUXC_SAI1_TXC_SAI5_TX_BCLK                            0x30330188, 0x1, 0x303304E8, 0x1, 0x303303F0
#define IOMUXC_SAI1_TXC_CORESIGHT_EVENTI                        0x30330188, 0x4, 0x00000000, 0x0, 0x303303F0
#define IOMUXC_SAI1_TXC_GPIO4_IO11                              0x30330188, 0x5, 0x00000000, 0x0, 0x303303F0
#define IOMUXC_SAI1_TXD0_SAI1_TX_DATA0                          0x3033018C, 0x0, 0x00000000, 0x0, 0x303303F4
#define IOMUXC_SAI1_TXD0_SAI5_TX_DATA0                          0x3033018C, 0x1, 0x00000000, 0x0, 0x303303F4
#define IOMUXC_SAI1_TXD0_CORESIGHT_TRACE8                       0x3033018C, 0x4, 0x00000000, 0x0, 0x303303F4
#define IOMUXC_SAI1_TXD0_GPIO4_IO12                             0x3033018C, 0x5, 0x00000000, 0x0, 0x303303F4
#define IOMUXC_SAI1_TXD0_SRC_BOOT_CFG8                          0x3033018C, 0x6, 0x00000000, 0x0, 0x303303F4
#define IOMUXC_SAI1_TXD1_SAI1_TX_DATA1                          0x30330190, 0x0, 0x00000000, 0x0, 0x303303F8
#define IOMUXC_SAI1_TXD1_SAI5_TX_DATA1                          0x30330190, 0x1, 0x00000000, 0x0, 0x303303F8
#define IOMUXC_SAI1_TXD1_CORESIGHT_TRACE9                       0x30330190, 0x4, 0x00000000, 0x0, 0x303303F8
#define IOMUXC_SAI1_TXD1_GPIO4_IO13                             0x30330190, 0x5, 0x00000000, 0x0, 0x303303F8
#define IOMUXC_SAI1_TXD1_SRC_BOOT_CFG9                          0x30330190, 0x6, 0x00000000, 0x0, 0x303303F8
#define IOMUXC_SAI1_TXD2_SAI1_TX_DATA2                          0x30330194, 0x0, 0x00000000, 0x0, 0x303303FC
#define IOMUXC_SAI1_TXD2_SAI5_TX_DATA2                          0x30330194, 0x1, 0x00000000, 0x0, 0x303303FC
#define IOMUXC_SAI1_TXD2_CORESIGHT_TRACE10                      0x30330194, 0x4, 0x00000000, 0x0, 0x303303FC
#define IOMUXC_SAI1_TXD2_GPIO4_IO14                             0x30330194, 0x5, 0x00000000, 0x0, 0x303303FC
#define IOMUXC_SAI1_TXD2_SRC_BOOT_CFG10                         0x30330194, 0x6, 0x00000000, 0x0, 0x303303FC
#define IOMUXC_SAI1_TXD3_SAI1_TX_DATA3                          0x30330198, 0x0, 0x00000000, 0x0, 0x30330400
#define IOMUXC_SAI1_TXD3_SAI5_TX_DATA3                          0x30330198, 0x1, 0x00000000, 0x0, 0x30330400
#define IOMUXC_SAI1_TXD3_CORESIGHT_TRACE11                      0x30330198, 0x4, 0x00000000, 0x0, 0x30330400
#define IOMUXC_SAI1_TXD3_GPIO4_IO15                             0x30330198, 0x5, 0x00000000, 0x0, 0x30330400
#define IOMUXC_SAI1_TXD3_SRC_BOOT_CFG11                         0x30330198, 0x6, 0x00000000, 0x0, 0x30330400
#define IOMUXC_SAI1_TXD4_SAI1_TX_DATA4                          0x3033019C, 0x0, 0x00000000, 0x0, 0x30330404
#define IOMUXC_SAI1_TXD4_SAI6_RX_BCLK                           0x3033019C, 0x1, 0x30330510, 0x1, 0x30330404
#define IOMUXC_SAI1_TXD4_SAI6_TX_BCLK                           0x3033019C, 0x2, 0x3033051C, 0x1, 0x30330404
#define IOMUXC_SAI1_TXD4_CORESIGHT_TRACE12                      0x3033019C, 0x4, 0x00000000, 0x0, 0x30330404
#define IOMUXC_SAI1_TXD4_GPIO4_IO16                             0x3033019C, 0x5, 0x00000000, 0x0, 0x30330404
#define IOMUXC_SAI1_TXD4_SRC_BOOT_CFG12                         0x3033019C, 0x6, 0x00000000, 0x0, 0x30330404
#define IOMUXC_SAI1_TXD5_SAI1_TX_DATA5                          0x303301A0, 0x0, 0x00000000, 0x0, 0x30330408
#define IOMUXC_SAI1_TXD5_SAI6_RX_DATA0                          0x303301A0, 0x1, 0x30330514, 0x1, 0x30330408
#define IOMUXC_SAI1_TXD5_SAI6_TX_DATA0                          0x303301A0, 0x2, 0x00000000, 0x0, 0x30330408
#define IOMUXC_SAI1_TXD5_CORESIGHT_TRACE13                      0x303301A0, 0x4, 0x00000000, 0x0, 0x30330408
#define IOMUXC_SAI1_TXD5_GPIO4_IO17                             0x303301A0, 0x5, 0x00000000, 0x0, 0x30330408
#define IOMUXC_SAI1_TXD5_SRC_BOOT_CFG13                         0x303301A0, 0x6, 0x00000000, 0x0, 0x30330408
#define IOMUXC_SAI1_TXD6_SAI1_TX_DATA6                          0x303301A4, 0x0, 0x00000000, 0x0, 0x3033040C
#define IOMUXC_SAI1_TXD6_SAI6_RX_SYNC                           0x303301A4, 0x1, 0x30330518, 0x1, 0x3033040C
#define IOMUXC_SAI1_TXD6_SAI6_TX_SYNC                           0x303301A4, 0x2, 0x30330520, 0x1, 0x3033040C
#define IOMUXC_SAI1_TXD6_CORESIGHT_TRACE14                      0x303301A4, 0x4, 0x00000000, 0x0, 0x3033040C
#define IOMUXC_SAI1_TXD6_GPIO4_IO18                             0x303301A4, 0x5, 0x00000000, 0x0, 0x3033040C
#define IOMUXC_SAI1_TXD6_SRC_BOOT_CFG14                         0x303301A4, 0x6, 0x00000000, 0x0, 0x3033040C
#define IOMUXC_SAI1_TXD7_SAI1_TX_DATA7                          0x303301A8, 0x0, 0x00000000, 0x0, 0x30330410
#define IOMUXC_SAI1_TXD7_SAI6_MCLK                              0x303301A8, 0x1, 0x30330530, 0x1, 0x30330410
#define IOMUXC_SAI1_TXD7_CORESIGHT_TRACE15                      0x303301A8, 0x4, 0x00000000, 0x0, 0x30330410
#define IOMUXC_SAI1_TXD7_GPIO4_IO19                             0x303301A8, 0x5, 0x00000000, 0x0, 0x30330410
#define IOMUXC_SAI1_TXD7_SRC_BOOT_CFG15                         0x303301A8, 0x6, 0x00000000, 0x0, 0x30330410
#define IOMUXC_SAI1_MCLK_SAI1_MCLK                              0x303301AC, 0x0, 0x00000000, 0x0, 0x30330414
#define IOMUXC_SAI1_MCLK_SAI5_MCLK                              0x303301AC, 0x1, 0x3033052C, 0x1, 0x30330414
#define IOMUXC_SAI1_MCLK_SAI1_TX_BCLK                           0x303301AC, 0x2, 0x303304C8, 0x2, 0x30330414
#define IOMUXC_SAI1_MCLK_GPIO4_IO20                             0x303301AC, 0x5, 0x00000000, 0x0, 0x30330414
#define IOMUXC_SAI2_RXFS_SAI2_RX_SYNC                           0x303301B0, 0x0, 0x00000000, 0x0, 0x30330418
#define IOMUXC_SAI2_RXFS_SAI5_TX_SYNC                           0x303301B0, 0x1, 0x303304EC, 0x2, 0x30330418
#define IOMUXC_SAI2_RXFS_GPIO4_IO21                             0x303301B0, 0x5, 0x00000000, 0x0, 0x30330418
#define IOMUXC_SAI2_RXC_SAI2_RX_BCLK                            0x303301B4, 0x0, 0x00000000, 0x0, 0x3033041C
#define IOMUXC_SAI2_RXC_SAI5_TX_BCLK                            0x303301B4, 0x1, 0x303304E8, 0x2, 0x3033041C
#define IOMUXC_SAI2_RXC_GPIO4_IO22                              0x303301B4, 0x5, 0x00000000, 0x0, 0x3033041C
#define IOMUXC_SAI2_RXD0_SAI2_RX_DATA0                          0x303301B8, 0x0, 0x00000000, 0x0, 0x30330420
#define IOMUXC_SAI2_RXD0_SAI5_TX_DATA0                          0x303301B8, 0x1, 0x00000000, 0x0, 0x30330420
#define IOMUXC_SAI2_RXD0_GPIO4_IO23                             0x303301B8, 0x5, 0x00000000, 0x0, 0x30330420
#define IOMUXC_SAI2_TXFS_SAI2_TX_SYNC                           0x303301BC, 0x0, 0x00000000, 0x0, 0x30330424
#define IOMUXC_SAI2_TXFS_SAI5_TX_DATA1                          0x303301BC, 0x1, 0x00000000, 0x0, 0x30330424
#define IOMUXC_SAI2_TXFS_GPIO4_IO24                             0x303301BC, 0x5, 0x00000000, 0x0, 0x30330424
#define IOMUXC_SAI2_TXC_SAI2_TX_BCLK                            0x303301C0, 0x0, 0x00000000, 0x0, 0x30330428
#define IOMUXC_SAI2_TXC_SAI5_TX_DATA2                           0x303301C0, 0x1, 0x00000000, 0x0, 0x30330428
#define IOMUXC_SAI2_TXC_GPIO4_IO25                              0x303301C0, 0x5, 0x00000000, 0x0, 0x30330428
#define IOMUXC_SAI2_TXD0_SAI2_TX_DATA0                          0x303301C4, 0x0, 0x00000000, 0x0, 0x3033042C
#define IOMUXC_SAI2_TXD0_SAI5_TX_DATA3                          0x303301C4, 0x1, 0x00000000, 0x0, 0x3033042C
#define IOMUXC_SAI2_TXD0_GPIO4_IO26                             0x303301C4, 0x5, 0x00000000, 0x0, 0x3033042C
#define IOMUXC_SAI2_MCLK_SAI2_MCLK                              0x303301C8, 0x0, 0x00000000, 0x0, 0x30330430
#define IOMUXC_SAI2_MCLK_SAI5_MCLK                              0x303301C8, 0x1, 0x3033052C, 0x2, 0x30330430
#define IOMUXC_SAI2_MCLK_GPIO4_IO27                             0x303301C8, 0x5, 0x00000000, 0x0, 0x30330430
#define IOMUXC_SAI3_RXFS_SAI3_RX_SYNC                           0x303301CC, 0x0, 0x00000000, 0x0, 0x30330434
#define IOMUXC_SAI3_RXFS_GPT1_CAPTURE1                          0x303301CC, 0x1, 0x00000000, 0x0, 0x30330434
#define IOMUXC_SAI3_RXFS_SAI5_RX_SYNC                           0x303301CC, 0x2, 0x303304E4, 0x2, 0x30330434
#define IOMUXC_SAI3_RXFS_GPIO4_IO28                             0x303301CC, 0x5, 0x00000000, 0x0, 0x30330434
#define IOMUXC_SAI3_RXC_SAI3_RX_BCLK                            0x303301D0, 0x0, 0x00000000, 0x0, 0x30330438
#define IOMUXC_SAI3_RXC_GPT1_CAPTURE2                           0x303301D0, 0x1, 0x00000000, 0x0, 0x30330438
#define IOMUXC_SAI3_RXC_SAI5_RX_BCLK                            0x303301D0, 0x2, 0x303304D0, 0x2, 0x30330438
#define IOMUXC_SAI3_RXC_GPIO4_IO29                              0x303301D0, 0x5, 0x00000000, 0x0, 0x30330438
#define IOMUXC_SAI3_RXD_SAI3_RX_DATA0                           0x303301D4, 0x0, 0x00000000, 0x0, 0x3033043C
#define IOMUXC_SAI3_RXD_GPT1_COMPARE1                           0x303301D4, 0x1, 0x00000000, 0x0, 0x3033043C
#define IOMUXC_SAI3_RXD_SAI5_RX_DATA0                           0x303301D4, 0x2, 0x303304D4, 0x2, 0x3033043C
#define IOMUXC_SAI3_RXD_GPIO4_IO30                              0x303301D4, 0x5, 0x00000000, 0x0, 0x3033043C
#define IOMUXC_SAI3_TXFS_SAI3_TX_SYNC                           0x303301D8, 0x0, 0x00000000, 0x0, 0x30330440
#define IOMUXC_SAI3_TXFS_GPT1_CLK                               0x303301D8, 0x1, 0x00000000, 0x0, 0x30330440
#define IOMUXC_SAI3_TXFS_SAI5_RX_DATA1                          0x303301D8, 0x2, 0x303304D8, 0x2, 0x30330440
#define IOMUXC_SAI3_TXFS_GPIO4_IO31                             0x303301D8, 0x5, 0x00000000, 0x0, 0x30330440
#define IOMUXC_SAI3_TXC_SAI3_TX_BCLK                            0x303301DC, 0x0, 0x00000000, 0x0, 0x30330444
#define IOMUXC_SAI3_TXC_GPT1_COMPARE2                           0x303301DC, 0x1, 0x00000000, 0x0, 0x30330444
#define IOMUXC_SAI3_TXC_SAI5_RX_DATA2                           0x303301DC, 0x2, 0x303304DC, 0x2, 0x30330444
#define IOMUXC_SAI3_TXC_GPIO5_IO00                              0x303301DC, 0x5, 0x00000000, 0x0, 0x30330444
#define IOMUXC_SAI3_TXD_SAI3_TX_DATA0                           0x303301E0, 0x0, 0x00000000, 0x0, 0x30330448
#define IOMUXC_SAI3_TXD_GPT1_COMPARE3                           0x303301E0, 0x1, 0x00000000, 0x0, 0x30330448
#define IOMUXC_SAI3_TXD_SAI5_RX_DATA3                           0x303301E0, 0x2, 0x303304E0, 0x2, 0x30330448
#define IOMUXC_SAI3_TXD_GPIO5_IO01                              0x303301E0, 0x5, 0x00000000, 0x0, 0x30330448
#define IOMUXC_SAI3_MCLK_SAI3_MCLK                              0x303301E4, 0x0, 0x00000000, 0x0, 0x3033044C
#define IOMUXC_SAI3_MCLK_PWM4_OUT                               0x303301E4, 0x1, 0x00000000, 0x0, 0x3033044C
#define IOMUXC_SAI3_MCLK_SAI5_MCLK                              0x303301E4, 0x2, 0x3033052C, 0x3, 0x3033044C
#define IOMUXC_SAI3_MCLK_GPIO5_IO02                             0x303301E4, 0x5, 0x00000000, 0x0, 0x3033044C
#define IOMUXC_SPDIF_TX_SPDIF1_OUT                              0x303301E8, 0x0, 0x00000000, 0x0, 0x30330450
#define IOMUXC_SPDIF_TX_PWM3_OUT                                0x303301E8, 0x1, 0x00000000, 0x0, 0x30330450
#define IOMUXC_SPDIF_TX_GPIO5_IO03                              0x303301E8, 0x5, 0x00000000, 0x0, 0x30330450
#define IOMUXC_SPDIF_RX_SPDIF1_IN                               0x303301EC, 0x0, 0x00000000, 0x0, 0x30330454
#define IOMUXC_SPDIF_RX_PWM2_OUT                                0x303301EC, 0x1, 0x00000000, 0x0, 0x30330454
#define IOMUXC_SPDIF_RX_GPIO5_IO04                              0x303301EC, 0x5, 0x00000000, 0x0, 0x30330454
#define IOMUXC_SPDIF_EXT_CLK_SPDIF1_EXT_CLK                     0x303301F0, 0x0, 0x00000000, 0x0, 0x30330458
#define IOMUXC_SPDIF_EXT_CLK_PWM1_OUT                           0x303301F0, 0x1, 0x00000000, 0x0, 0x30330458
#define IOMUXC_SPDIF_EXT_CLK_GPIO5_IO05                         0x303301F0, 0x5, 0x00000000, 0x0, 0x30330458
#define IOMUXC_ECSPI1_SCLK_ECSPI1_SCLK                          0x303301F4, 0x0, 0x00000000, 0x0, 0x3033045C
#define IOMUXC_ECSPI1_SCLK_UART3_RX                             0x303301F4, 0x1, 0x30330504, 0x0, 0x3033045C
#define IOMUXC_ECSPI1_SCLK_UART3_TX                             0x303301F4, 0x1, 0x00000000, 0X0, 0x3033045C
#define IOMUXC_ECSPI1_SCLK_GPIO5_IO06                           0x303301F4, 0x5, 0x00000000, 0x0, 0x3033045C
#define IOMUXC_ECSPI1_MOSI_ECSPI1_MOSI                          0x303301F8, 0x0, 0x00000000, 0x0, 0x30330460
#define IOMUXC_ECSPI1_MOSI_UART3_TX                             0x303301F8, 0x1, 0x00000000, 0X0, 0x30330460
#define IOMUXC_ECSPI1_MOSI_UART3_RX                             0x303301F8, 0x1, 0x30330504, 0x1, 0x30330460
#define IOMUXC_ECSPI1_MOSI_GPIO5_IO07                           0x303301F8, 0x5, 0x00000000, 0x0, 0x30330460
#define IOMUXC_ECSPI1_MISO_ECSPI1_MISO                          0x303301FC, 0x0, 0x00000000, 0x0, 0x30330464
#define IOMUXC_ECSPI1_MISO_UART3_CTS_B                          0x303301FC, 0x1, 0x00000000, 0X0, 0x30330464
#define IOMUXC_ECSPI1_MISO_UART3_RTS_B                          0x303301FC, 0x1, 0x30330500, 0x0, 0x30330464
#define IOMUXC_ECSPI1_MISO_GPIO5_IO08                           0x303301FC, 0x5, 0x00000000, 0x0, 0x30330464
#define IOMUXC_ECSPI1_SS0_ECSPI1_SS0                            0x30330200, 0x0, 0x00000000, 0x0, 0x30330468
#define IOMUXC_ECSPI1_SS0_UART3_RTS_B                           0x30330200, 0x1, 0x30330500, 0x1, 0x30330468
#define IOMUXC_ECSPI1_SS0_UART3_CTS_B                           0x30330200, 0x1, 0x00000000, 0X0, 0x30330468
#define IOMUXC_ECSPI1_SS0_GPIO5_IO09                            0x30330200, 0x5, 0x00000000, 0x0, 0x30330468
#define IOMUXC_ECSPI2_SCLK_ECSPI2_SCLK                          0x30330204, 0x0, 0x00000000, 0x0, 0x3033046C
#define IOMUXC_ECSPI2_SCLK_UART4_RX                             0x30330204, 0x1, 0x3033050C, 0x0, 0x3033046C
#define IOMUXC_ECSPI2_SCLK_UART4_TX                             0x30330204, 0x1, 0x00000000, 0X0, 0x3033046C
#define IOMUXC_ECSPI2_SCLK_GPIO5_IO10                           0x30330204, 0x5, 0x00000000, 0x0, 0x3033046C
#define IOMUXC_ECSPI2_MOSI_ECSPI2_MOSI                          0x30330208, 0x0, 0x00000000, 0x0, 0x30330470
#define IOMUXC_ECSPI2_MOSI_UART4_TX                             0x30330208, 0x1, 0x00000000, 0X0, 0x30330470
#define IOMUXC_ECSPI2_MOSI_UART4_RX                             0x30330208, 0x1, 0x3033050C, 0x1, 0x30330470
#define IOMUXC_ECSPI2_MOSI_GPIO5_IO11                           0x30330208, 0x5, 0x00000000, 0x0, 0x30330470
#define IOMUXC_ECSPI2_MISO_ECSPI2_MISO                          0x3033020C, 0x0, 0x00000000, 0x0, 0x30330474
#define IOMUXC_ECSPI2_MISO_UART4_CTS_B                          0x3033020C, 0x1, 0x00000000, 0X0, 0x30330474
#define IOMUXC_ECSPI2_MISO_UART4_RTS_B                          0x3033020C, 0x1, 0x30330508, 0x0, 0x30330474
#define IOMUXC_ECSPI2_MISO_GPIO5_IO12                           0x3033020C, 0x5, 0x00000000, 0x0, 0x30330474
#define IOMUXC_ECSPI2_SS0_ECSPI2_SS0                            0x30330210, 0x0, 0x00000000, 0x0, 0x30330478
#define IOMUXC_ECSPI2_SS0_UART4_RTS_B                           0x30330210, 0x1, 0x30330508, 0x1, 0x30330478
#define IOMUXC_ECSPI2_SS0_UART4_CTS_B                           0x30330210, 0x1, 0x00000000, 0X0, 0x30330478
#define IOMUXC_ECSPI2_SS0_GPIO5_IO13                            0x30330210, 0x5, 0x00000000, 0x0, 0x30330478
#define IOMUXC_I2C1_SCL_I2C1_SCL                                0x30330214, 0x0, 0x00000000, 0x0, 0x3033047C
#define IOMUXC_I2C1_SCL_ENET1_MDC                               0x30330214, 0x1, 0x00000000, 0x0, 0x3033047C
#define IOMUXC_I2C1_SCL_GPIO5_IO14                              0x30330214, 0x5, 0x00000000, 0x0, 0x3033047C
#define IOMUXC_I2C1_SDA_I2C1_SDA                                0x30330218, 0x0, 0x00000000, 0x0, 0x30330480
#define IOMUXC_I2C1_SDA_ENET1_MDIO                              0x30330218, 0x1, 0x303304C0, 0x2, 0x30330480
#define IOMUXC_I2C1_SDA_GPIO5_IO15                              0x30330218, 0x5, 0x00000000, 0x0, 0x30330480
#define IOMUXC_I2C2_SCL_I2C2_SCL                                0x3033021C, 0x0, 0x00000000, 0x0, 0x30330484
#define IOMUXC_I2C2_SCL_ENET1_1588_EVENT1_IN                    0x3033021C, 0x1, 0x00000000, 0x0, 0x30330484
#define IOMUXC_I2C2_SCL_GPIO5_IO16                              0x3033021C, 0x5, 0x00000000, 0x0, 0x30330484
#define IOMUXC_I2C2_SDA_I2C2_SDA                                0x30330220, 0x0, 0x00000000, 0x0, 0x30330488
#define IOMUXC_I2C2_SDA_ENET1_1588_EVENT1_OUT                   0x30330220, 0x1, 0x00000000, 0x0, 0x30330488
#define IOMUXC_I2C2_SDA_GPIO5_IO17                              0x30330220, 0x5, 0x00000000, 0x0, 0x30330488
#define IOMUXC_I2C3_SCL_I2C3_SCL                                0x30330224, 0x0, 0x00000000, 0x0, 0x3033048C
#define IOMUXC_I2C3_SCL_PWM4_OUT                                0x30330224, 0x1, 0x00000000, 0x0, 0x3033048C
#define IOMUXC_I2C3_SCL_GPT2_CLK                                0x30330224, 0x2, 0x00000000, 0x0, 0x3033048C
#define IOMUXC_I2C3_SCL_GPIO5_IO18                              0x30330224, 0x5, 0x00000000, 0x0, 0x3033048C
#define IOMUXC_I2C3_SDA_I2C3_SDA                                0x30330228, 0x0, 0x00000000, 0x0, 0x30330490
#define IOMUXC_I2C3_SDA_PWM3_OUT                                0x30330228, 0x1, 0x00000000, 0x0, 0x30330490
#define IOMUXC_I2C3_SDA_GPT3_CLK                                0x30330228, 0x2, 0x00000000, 0x0, 0x30330490
#define IOMUXC_I2C3_SDA_GPIO5_IO19                              0x30330228, 0x5, 0x00000000, 0x0, 0x30330490
#define IOMUXC_I2C4_SCL_I2C4_SCL                                0x3033022C, 0x0, 0x00000000, 0x0, 0x30330494
#define IOMUXC_I2C4_SCL_PWM2_OUT                                0x3033022C, 0x1, 0x00000000, 0x0, 0x30330494
#define IOMUXC_I2C4_SCL_PCIE1_CLKREQ_B                          0x3033022C, 0x2, 0x30330524, 0x0, 0x30330494
#define IOMUXC_I2C4_SCL_GPIO5_IO20                              0x3033022C, 0x5, 0x00000000, 0x0, 0x30330494
#define IOMUXC_I2C4_SDA_I2C4_SDA                                0x30330230, 0x0, 0x00000000, 0x0, 0x30330498
#define IOMUXC_I2C4_SDA_PWM1_OUT                                0x30330230, 0x1, 0x00000000, 0x0, 0x30330498
#define IOMUXC_I2C4_SDA_PCIE2_CLKREQ_B                          0x30330230, 0x2, 0x30330528, 0x0, 0x30330498
#define IOMUXC_I2C4_SDA_GPIO5_IO21                              0x30330230, 0x5, 0x00000000, 0x0, 0x30330498
#define IOMUXC_UART1_RXD_UART1_RX                               0x30330234, 0x0, 0x303304F4, 0x0, 0x3033049C
#define IOMUXC_UART1_RXD_UART1_TX                               0x30330234, 0x0, 0x00000000, 0X0, 0x3033049C
#define IOMUXC_UART1_RXD_ECSPI3_SCLK                            0x30330234, 0x1, 0x00000000, 0x0, 0x3033049C
#define IOMUXC_UART1_RXD_GPIO5_IO22                             0x30330234, 0x5, 0x00000000, 0x0, 0x3033049C
#define IOMUXC_UART1_TXD_UART1_TX                               0x30330238, 0x0, 0x00000000, 0X0, 0x303304A0
#define IOMUXC_UART1_TXD_UART1_RX                               0x30330238, 0x0, 0x303304F4, 0x1, 0x303304A0
#define IOMUXC_UART1_TXD_ECSPI3_MOSI                            0x30330238, 0x1, 0x00000000, 0x0, 0x303304A0
#define IOMUXC_UART1_TXD_GPIO5_IO23                             0x30330238, 0x5, 0x00000000, 0x0, 0x303304A0
#define IOMUXC_UART2_RXD_UART2_RX                               0x3033023C, 0x0, 0x303304FC, 0x0, 0x303304A4
#define IOMUXC_UART2_RXD_UART2_TX                               0x3033023C, 0x0, 0x00000000, 0X0, 0x303304A4
#define IOMUXC_UART2_RXD_ECSPI3_MISO                            0x3033023C, 0x1, 0x00000000, 0x0, 0x303304A4
#define IOMUXC_UART2_RXD_GPIO5_IO24                             0x3033023C, 0x5, 0x00000000, 0x0, 0x303304A4
#define IOMUXC_UART2_TXD_UART2_TX                               0x30330240, 0x0, 0x00000000, 0X0, 0x303304A8
#define IOMUXC_UART2_TXD_UART2_RX                               0x30330240, 0x0, 0x303304FC, 0x1, 0x303304A8
#define IOMUXC_UART2_TXD_ECSPI3_SS0                             0x30330240, 0x1, 0x00000000, 0x0, 0x303304A8
#define IOMUXC_UART2_TXD_GPIO5_IO25                             0x30330240, 0x5, 0x00000000, 0x0, 0x303304A8
#define IOMUXC_UART3_RXD_UART3_RX                               0x30330244, 0x0, 0x30330504, 0x2, 0x303304AC
#define IOMUXC_UART3_RXD_UART3_TX                               0x30330244, 0x0, 0x00000000, 0X0, 0x303304AC
#define IOMUXC_UART3_RXD_UART1_CTS_B                            0x30330244, 0x1, 0x00000000, 0X0, 0x303304AC
#define IOMUXC_UART3_RXD_UART1_RTS_B                            0x30330244, 0x1, 0x303304F0, 0x0, 0x303304AC
#define IOMUXC_UART3_RXD_GPIO5_IO26                             0x30330244, 0x5, 0x00000000, 0x0, 0x303304AC
#define IOMUXC_UART3_TXD_UART3_TX                               0x30330248, 0x0, 0x00000000, 0X0, 0x303304B0
#define IOMUXC_UART3_TXD_UART3_RX                               0x30330248, 0x0, 0x30330504, 0x3, 0x303304B0
#define IOMUXC_UART3_TXD_UART1_RTS_B                            0x30330248, 0x1, 0x303304F0, 0x1, 0x303304B0
#define IOMUXC_UART3_TXD_UART1_CTS_B                            0x30330248, 0x1, 0x00000000, 0X0, 0x303304B0
#define IOMUXC_UART3_TXD_GPIO5_IO27                             0x30330248, 0x5, 0x00000000, 0x0, 0x303304B0
#define IOMUXC_UART4_RXD_UART4_RX                               0x3033024C, 0x0, 0x3033050C, 0x2, 0x303304B4
#define IOMUXC_UART4_RXD_UART4_TX                               0x3033024C, 0x0, 0x00000000, 0X0, 0x303304B4
#define IOMUXC_UART4_RXD_UART2_CTS_B                            0x3033024C, 0x1, 0x00000000, 0X0, 0x303304B4
#define IOMUXC_UART4_RXD_UART2_RTS_B                            0x3033024C, 0x1, 0x303304F8, 0x0, 0x303304B4
#define IOMUXC_UART4_RXD_PCIE1_CLKREQ_B                         0x3033024C, 0x2, 0x30330524, 0x1, 0x303304B4
#define IOMUXC_UART4_RXD_GPIO5_IO28                             0x3033024C, 0x5, 0x00000000, 0x0, 0x303304B4
#define IOMUXC_UART4_TXD_UART4_TX                               0x30330250, 0x0, 0x00000000, 0X0, 0x303304B8
#define IOMUXC_UART4_TXD_UART4_RX                               0x30330250, 0x0, 0x3033050C, 0x3, 0x303304B8
#define IOMUXC_UART4_TXD_UART2_RTS_B                            0x30330250, 0x1, 0x303304F8, 0x1, 0x303304B8
#define IOMUXC_UART4_TXD_UART2_CTS_B                            0x30330250, 0x1, 0x00000000, 0X0, 0x303304B8
#define IOMUXC_UART4_TXD_PCIE2_CLKREQ_B                         0x30330250, 0x2, 0x30330528, 0x1, 0x303304B8
#define IOMUXC_UART4_TXD_GPIO5_IO29                             0x30330250, 0x5, 0x00000000, 0x0, 0x303304B8
#define IOMUXC_TEST_MODE                                        0x00000000, 0x0, 0x00000000, 0x0, 0x30330254
#define IOMUXC_BOOT_MODE0                                       0x00000000, 0x0, 0x00000000, 0x0, 0x30330258
#define IOMUXC_BOOT_MODE1                                       0x00000000, 0x0, 0x00000000, 0x0, 0x3033025C
#define IOMUXC_JTAG_MOD                                         0x00000000, 0x0, 0x00000000, 0x0, 0x30330260
#define IOMUXC_JTAG_TRST_B                                      0x00000000, 0x0, 0x00000000, 0x0, 0x30330264
#define IOMUXC_JTAG_TDI                                         0x00000000, 0x0, 0x00000000, 0x0, 0x30330268
#define IOMUXC_JTAG_TMS                                         0x00000000, 0x0, 0x00000000, 0x0, 0x3033026C
#define IOMUXC_JTAG_TCK                                         0x00000000, 0x0, 0x00000000, 0x0, 0x30330270
#define IOMUXC_JTAG_TDO                                         0x00000000, 0x0, 0x00000000, 0x0, 0x30330274
#define IOMUXC_RTC                                              0x00000000, 0x0, 0x00000000, 0x0, 0x30330278

/*@}*/

#if defined(__cplusplus)
extern "C" {
#endif /*__cplusplus */

/*! @name Configuration */
/*@{*/

/*!
 * @brief Sets the IOMUXC pin mux mode.
 * @note The first five parameters can be filled with the pin function ID macros.
 *
 * This is an example to set the I2C4_SDA as the pwm1_OUT:
 * @code
 * IOMUXC_SetPinMux(IOMUXC_I2C4_SDA_PWM1_OUT, 0);
 * @endcode
 *
 *
 * @param muxRegister    The pin mux register_
 * @param muxMode        The pin mux mode_
 * @param inputRegister  The select input register_
 * @param inputDaisy     The input daisy_
 * @param configRegister The config register_
 * @param inputInv       The pad->module input inversion_
 */
static inline void IOMUXC_SetPinMux(uint32_t muxRegister,
                                    uint32_t muxMode,
                                    uint32_t inputRegister,
                                    uint32_t inputDaisy,
                                    uint32_t configRegister,
                                    uint32_t inputOnfield)
{
    *((volatile uint32_t *)muxRegister) =
        IOMUXC_SW_MUX_CTL_PAD_MUX_MODE(muxMode) | IOMUXC_SW_MUX_CTL_PAD_SION(inputOnfield);

    if (inputRegister)
    {
        *((volatile uint32_t *)inputRegister) = IOMUXC_SELECT_INPUT_DAISY(inputDaisy);
    }
}
/*!
 * @brief Sets the IOMUXC pin configuration.
 * @note The previous five parameters can be filled with the pin function ID macros.
 *
 * This is an example to set pin configuration for IOMUXC_I2C4_SDA_PWM1_OUT:
 * @code
 * IOMUXC_SetPinConfig(IOMUXC_I2C4_SDA_PWM1_OUT, IOMUXC_SW_PAD_CTL_PAD_ODE_MASK | IOMUXC0_SW_PAD_CTL_PAD_DSE(2U))
 * @endcode
 *
 * @param muxRegister    The pin mux register_
 * @param muxMode        The pin mux mode_
 * @param inputRegister  The select input register_
 * @param inputDaisy     The input daisy_
 * @param configRegister The config register_
 * @param configValue    The pin config value_
 */
static inline void IOMUXC_SetPinConfig(uint32_t muxRegister,
                                       uint32_t muxMode,
                                       uint32_t inputRegister,
                                       uint32_t inputDaisy,
                                       uint32_t configRegister,
                                       uint32_t configValue)
{
    if (configRegister)
    {
        *((volatile uint32_t *)configRegister) = configValue;
    }
}
/*@}*/

#if defined(__cplusplus)
}
#endif /*__cplusplus */

/*! @}*/

#endif /* _FSL_IOMUXC_H_ */
