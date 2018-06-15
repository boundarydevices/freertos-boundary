/*
 * The Clear BSD License
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted (subject to the limitations in the disclaimer below) provided that 
 * the following conditions are met:
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
#define IOMUXC_PMIC_STBY_REQ_CCMSRCGPCMIX_PMIC_STBY_REQ               0x30330014, 0x0, 0x00000000, 0x0, 0x3033027c
#define IOMUXC_PMIC_ON_REQ_SNVSMIX_PMIC_ON_REQ                        0x30330018, 0x0, 0x00000000, 0x0, 0x30330280
#define IOMUXC_ONOFF_SNVSMIX_ONOFF                                    0x3033001c, 0x0, 0x00000000, 0x0, 0x30330284
#define IOMUXC_POR_B_SNVSMIX_POR_B                                    0x30330020, 0x0, 0x00000000, 0x0, 0x30330288
#define IOMUXC_RTC_RESET_B_SNVSMIX_RTC_RESET_B                        0x30330024, 0x0, 0x00000000, 0x0, 0x3033028c
#define IOMUXC_GPIO1_IO00_GPIO1_IO0                                 0x30330028, 0x0, 0x00000000, 0x0, 0x30330290
#define IOMUXC_GPIO1_IO00_CCMSRCGPCMIX_ENET_PHY_REF_CLK_ROOT          0x30330028, 0x1, 0x303304c0, 0x0, 0x30330290
#define IOMUXC_GPIO1_IO00_ANAMIX_REF_CLK_32K                          0x30330028, 0x5, 0x00000000, 0x0, 0x30330290
#define IOMUXC_GPIO1_IO00_CCMSRCGPCMIX_EXT_CLK1                       0x30330028, 0x6, 0x00000000, 0x0, 0x30330290
#define IOMUXC_GPIO1_IO00_SJC_FAIL                                    0x30330028, 0x7, 0x00000000, 0x0, 0x30330290
#define IOMUXC_GPIO1_IO01_GPIO1_IO1                                 0x3033002c, 0x0, 0x00000000, 0x0, 0x30330294
#define IOMUXC_GPIO1_IO01_PWM1_OUT                                    0x3033002c, 0x1, 0x00000000, 0x0, 0x30330294
#define IOMUXC_GPIO1_IO01_ANAMIX_REF_CLK_24M                          0x3033002c, 0x5, 0x303304bc, 0x0, 0x30330294
#define IOMUXC_GPIO1_IO01_CCMSRCGPCMIX_EXT_CLK2                       0x3033002c, 0x6, 0x00000000, 0x0, 0x30330294
#define IOMUXC_GPIO1_IO01_SJC_ACTIVE                                  0x3033002c, 0x7, 0x00000000, 0x0, 0x30330294
#define IOMUXC_GPIO1_IO02_GPIO1_IO2                                 0x30330030, 0x0, 0x00000000, 0x0, 0x30330298
#define IOMUXC_GPIO1_IO02_WDOG1_WDOG_B                                0x30330030, 0x1, 0x00000000, 0x0, 0x30330298
#define IOMUXC_GPIO1_IO02_WDOG1_WDOG_ANY                              0x30330030, 0x5, 0x00000000, 0x0, 0x30330298
#define IOMUXC_GPIO1_IO02_SJC_DE_B                                    0x30330030, 0x7, 0x00000000, 0x0, 0x30330298
#define IOMUXC_GPIO1_IO03_GPIO1_IO3                                 0x30330034, 0x0, 0x00000000, 0x0, 0x3033029c
#define IOMUXC_GPIO1_IO03_USDHC1_VSELECT                              0x30330034, 0x1, 0x00000000, 0x0, 0x3033029c
#define IOMUXC_GPIO1_IO03_SDMA1_EXT_EVENT0                          0x30330034, 0x5, 0x00000000, 0x0, 0x3033029c
#define IOMUXC_GPIO1_IO03_ANAMIX_XTAL_OK                              0x30330034, 0x6, 0x00000000, 0x0, 0x3033029c
#define IOMUXC_GPIO1_IO03_SJC_DONE                                    0x30330034, 0x7, 0x00000000, 0x0, 0x3033029c
#define IOMUXC_GPIO1_IO04_GPIO1_IO4                                 0x30330038, 0x0, 0x00000000, 0x0, 0x303302a0
#define IOMUXC_GPIO1_IO04_USDHC2_VSELECT                              0x30330038, 0x1, 0x00000000, 0x0, 0x303302a0
#define IOMUXC_GPIO1_IO04_SDMA1_EXT_EVENT1                          0x30330038, 0x5, 0x00000000, 0x0, 0x303302a0
#define IOMUXC_GPIO1_IO04_ANAMIX_XTAL_OK_LV                           0x30330038, 0x6, 0x00000000, 0x0, 0x303302a0
#define IOMUXC_GPIO1_IO04_USDHC1_TEST_TRIG                            0x30330038, 0x7, 0x00000000, 0x0, 0x303302a0
#define IOMUXC_GPIO1_IO05_GPIO1_IO5                                 0x3033003c, 0x0, 0x00000000, 0x0, 0x303302a4
#define IOMUXC_GPIO1_IO05_M4_NMI                                      0x3033003c, 0x1, 0x00000000, 0x0, 0x303302a4
#define IOMUXC_GPIO1_IO05_CCMSRCGPCMIX_PMIC_READY                     0x3033003c, 0x5, 0x00000000, 0x0, 0x303302a4
#define IOMUXC_GPIO1_IO05_CCMSRCGPCMIX_INT_BOOT                       0x3033003c, 0x6, 0x00000000, 0x0, 0x303302a4
#define IOMUXC_GPIO1_IO05_USDHC2_TEST_TRIG                            0x3033003c, 0x7, 0x00000000, 0x0, 0x303302a4
#define IOMUXC_GPIO1_IO06_GPIO1_IO6                                 0x30330040, 0x0, 0x00000000, 0x0, 0x303302a8
#define IOMUXC_GPIO1_IO06_ENET1_MDC                                   0x30330040, 0x1, 0x00000000, 0x0, 0x303302a8
#define IOMUXC_GPIO1_IO06_USDHC1_CD_B                                 0x30330040, 0x5, 0x00000000, 0x0, 0x303302a8
#define IOMUXC_GPIO1_IO06_CCMSRCGPCMIX_EXT_CLK3                       0x30330040, 0x6, 0x00000000, 0x0, 0x303302a8
#define IOMUXC_GPIO1_IO06_ECSPI1_TEST_TRIG                            0x30330040, 0x7, 0x00000000, 0x0, 0x303302a8
#define IOMUXC_GPIO1_IO07_GPIO1_IO7                                 0x30330044, 0x0, 0x00000000, 0x0, 0x303302ac
#define IOMUXC_GPIO1_IO07_ENET1_MDIO                                  0x30330044, 0x1, 0x00000000, 0x0, 0x303302ac
#define IOMUXC_GPIO1_IO07_USDHC1_WP                                   0x30330044, 0x5, 0x00000000, 0x0, 0x303302ac
#define IOMUXC_GPIO1_IO07_CCMSRCGPCMIX_EXT_CLK4                       0x30330044, 0x6, 0x00000000, 0x0, 0x303302ac
#define IOMUXC_GPIO1_IO07_ECSPI2_TEST_TRIG                            0x30330044, 0x7, 0x00000000, 0x0, 0x303302ac
#define IOMUXC_GPIO1_IO08_GPIO1_IO8                                 0x30330048, 0x0, 0x00000000, 0x0, 0x303302b0
#define IOMUXC_GPIO1_IO08_ENET1_1588_EVENT0_IN                        0x30330048, 0x1, 0x00000000, 0x0, 0x303302b0
#define IOMUXC_GPIO1_IO08_USDHC2_RESET_B                              0x30330048, 0x5, 0x00000000, 0x0, 0x303302b0
#define IOMUXC_GPIO1_IO08_CCMSRCGPCMIX_WAIT                           0x30330048, 0x6, 0x00000000, 0x0, 0x303302b0
#define IOMUXC_GPIO1_IO08_QSPI_TEST_TRIG                              0x30330048, 0x7, 0x00000000, 0x0, 0x303302b0
#define IOMUXC_GPIO1_IO09_GPIO1_IO9                                 0x3033004c, 0x0, 0x00000000, 0x0, 0x303302b4
#define IOMUXC_GPIO1_IO09_ENET1_1588_EVENT0_OUT                       0x3033004c, 0x1, 0x00000000, 0x0, 0x303302b4
#define IOMUXC_GPIO1_IO09_SDMA2_EXT_EVENT0                          0x3033004c, 0x5, 0x00000000, 0x0, 0x303302b4
#define IOMUXC_GPIO1_IO09_CCMSRCGPCMIX_STOP                           0x3033004c, 0x6, 0x00000000, 0x0, 0x303302b4
#define IOMUXC_GPIO1_IO09_RAWNAND_TEST_TRIG                           0x3033004c, 0x7, 0x00000000, 0x0, 0x303302b4
#define IOMUXC_GPIO1_IO10_GPIO1_IO10                                0x30330050, 0x0, 0x00000000, 0x0, 0x303302b8
#define IOMUXC_GPIO1_IO10_USB1_OTG_ID                                 0x30330050, 0x1, 0x00000000, 0x0, 0x303302b8
#define IOMUXC_GPIO1_IO10_OCOTP_CTRL_WRAPPER_FUSE_LATCHED             0x30330050, 0x7, 0x00000000, 0x0, 0x303302b8
#define IOMUXC_GPIO1_IO11_GPIO1_IO11                                0x30330054, 0x0, 0x00000000, 0x0, 0x303302bc
#define IOMUXC_GPIO1_IO11_USB2_OTG_ID                                 0x30330054, 0x1, 0x00000000, 0x0, 0x303302bc
#define IOMUXC_GPIO1_IO11_CCMSRCGPCMIX_PMIC_READY                     0x30330054, 0x5, 0x303304bc, 0x1, 0x303302bc
#define IOMUXC_GPIO1_IO11_CCMSRCGPCMIX_OUT0                           0x30330054, 0x6, 0x00000000, 0x0, 0x303302bc
#define IOMUXC_GPIO1_IO11_CAAM_WRAPPER_RNG_OSC_OBS                    0x30330054, 0x7, 0x00000000, 0x0, 0x303302bc
#define IOMUXC_GPIO1_IO12_GPIO1_IO12                                0x30330058, 0x0, 0x00000000, 0x0, 0x303302c0
#define IOMUXC_GPIO1_IO12_USB1_OTG_PWR                                0x30330058, 0x1, 0x00000000, 0x0, 0x303302c0
#define IOMUXC_GPIO1_IO12_SDMA2_EXT_EVENT1                          0x30330058, 0x5, 0x00000000, 0x0, 0x303302c0
#define IOMUXC_GPIO1_IO12_CCMSRCGPCMIX_OUT1                           0x30330058, 0x6, 0x00000000, 0x0, 0x303302c0
#define IOMUXC_GPIO1_IO12_CSU_CSU_ALARM_AUT0                        0x30330058, 0x7, 0x00000000, 0x0, 0x303302c0
#define IOMUXC_GPIO1_IO13_GPIO1_IO13                                0x3033005c, 0x0, 0x00000000, 0x0, 0x303302c4
#define IOMUXC_GPIO1_IO13_USB1_OTG_OC                                 0x3033005c, 0x1, 0x00000000, 0x0, 0x303302c4
#define IOMUXC_GPIO1_IO13_PWM2_OUT                                    0x3033005c, 0x5, 0x00000000, 0x0, 0x303302c4
#define IOMUXC_GPIO1_IO13_CCMSRCGPCMIX_OUT2                           0x3033005c, 0x6, 0x00000000, 0x0, 0x303302c4
#define IOMUXC_GPIO1_IO13_CSU_CSU_ALARM_AUT1                        0x3033005c, 0x7, 0x00000000, 0x0, 0x303302c4
#define IOMUXC_GPIO1_IO14_GPIO1_IO14                                0x30330060, 0x0, 0x00000000, 0x0, 0x303302c8
#define IOMUXC_GPIO1_IO14_USB2_OTG_PWR                                0x30330060, 0x1, 0x00000000, 0x0, 0x303302c8
#define IOMUXC_GPIO1_IO14_PWM3_OUT                                    0x30330060, 0x5, 0x00000000, 0x0, 0x303302c8
#define IOMUXC_GPIO1_IO14_CCMSRCGPCMIX_CLKO1                          0x30330060, 0x6, 0x00000000, 0x0, 0x303302c8
#define IOMUXC_GPIO1_IO14_CSU_CSU_ALARM_AUT2                        0x30330060, 0x7, 0x00000000, 0x0, 0x303302c8
#define IOMUXC_GPIO1_IO15_GPIO1_IO15                                0x30330064, 0x0, 0x00000000, 0x0, 0x303302cc
#define IOMUXC_GPIO1_IO15_USB2_OTG_OC                                 0x30330064, 0x1, 0x00000000, 0x0, 0x303302cc
#define IOMUXC_GPIO1_IO15_PWM4_OUT                                    0x30330064, 0x5, 0x00000000, 0x0, 0x303302cc
#define IOMUXC_GPIO1_IO15_CCMSRCGPCMIX_CLKO2                          0x30330064, 0x6, 0x00000000, 0x0, 0x303302cc
#define IOMUXC_GPIO1_IO15_CSU_CSU_INT_DEB                             0x30330064, 0x7, 0x00000000, 0x0, 0x303302cc
#define IOMUXC_ENET_MDC_ENET1_MDC                                     0x30330068, 0x0, 0x00000000, 0x0, 0x303302d0
#define IOMUXC_ENET_MDC_GPIO1_IO16                                  0x30330068, 0x5, 0x00000000, 0x0, 0x303302d0
#define IOMUXC_ENET_MDIO_ENET1_MDIO                                   0x3033006c, 0x0, 0x303304c0, 0x1, 0x303302d4
#define IOMUXC_ENET_MDIO_GPIO1_IO17                                 0x3033006c, 0x5, 0x00000000, 0x0, 0x303302d4
#define IOMUXC_ENET_TD3_ENET1_RGMII_TD3                               0x30330070, 0x0, 0x00000000, 0x0, 0x303302d8
#define IOMUXC_ENET_TD3_GPIO1_IO18                                  0x30330070, 0x5, 0x00000000, 0x0, 0x303302d8
#define IOMUXC_ENET_TD2_ENET1_RGMII_TD2                               0x30330074, 0x0, 0x00000000, 0x0, 0x303302dc
#define IOMUXC_ENET_TD2_ENET1_TX_CLK                                  0x30330074, 0x1, 0x00000000, 0x0, 0x303302dc
#define IOMUXC_ENET_TD2_GPIO1_IO19                                  0x30330074, 0x5, 0x00000000, 0x0, 0x303302dc
#define IOMUXC_ENET_TD1_ENET1_RGMII_TD1                               0x30330078, 0x0, 0x00000000, 0x0, 0x303302e0
#define IOMUXC_ENET_TD1_GPIO1_IO20                                  0x30330078, 0x5, 0x00000000, 0x0, 0x303302e0
#define IOMUXC_ENET_TD0_ENET1_RGMII_TD0                               0x3033007c, 0x0, 0x00000000, 0x0, 0x303302e4
#define IOMUXC_ENET_TD0_GPIO1_IO21                                  0x3033007c, 0x5, 0x00000000, 0x0, 0x303302e4
#define IOMUXC_ENET_TX_CTL_ENET1_RGMII_TX_CTL                         0x30330080, 0x0, 0x00000000, 0x0, 0x303302e8
#define IOMUXC_ENET_TX_CTL_GPIO1_IO22                               0x30330080, 0x5, 0x00000000, 0x0, 0x303302e8
#define IOMUXC_ENET_TXC_ENET1_RGMII_TXC                               0x30330084, 0x0, 0x00000000, 0x0, 0x303302ec
#define IOMUXC_ENET_TXC_ENET1_TX_ER                                   0x30330084, 0x1, 0x00000000, 0x0, 0x303302ec
#define IOMUXC_ENET_TXC_GPIO1_IO23                                  0x30330084, 0x5, 0x00000000, 0x0, 0x303302ec
#define IOMUXC_ENET_RX_CTL_ENET1_RGMII_RX_CTL                         0x30330088, 0x0, 0x00000000, 0x0, 0x303302f0
#define IOMUXC_ENET_RX_CTL_GPIO1_IO24                               0x30330088, 0x5, 0x00000000, 0x0, 0x303302f0
#define IOMUXC_ENET_RXC_ENET1_RGMII_RXC                               0x3033008c, 0x0, 0x00000000, 0x0, 0x303302f4
#define IOMUXC_ENET_RXC_ENET1_RX_ER                                   0x3033008c, 0x1, 0x00000000, 0x0, 0x303302f4
#define IOMUXC_ENET_RXC_GPIO1_IO25                                  0x3033008c, 0x5, 0x00000000, 0x0, 0x303302f4
#define IOMUXC_ENET_RD0_ENET1_RGMII_RD0                               0x30330090, 0x0, 0x00000000, 0x0, 0x303302f8
#define IOMUXC_ENET_RD0_GPIO1_IO26                                  0x30330090, 0x5, 0x00000000, 0x0, 0x303302f8
#define IOMUXC_ENET_RD1_ENET1_RGMII_RD1                               0x30330094, 0x0, 0x00000000, 0x0, 0x303302fc
#define IOMUXC_ENET_RD1_GPIO1_IO27                                  0x30330094, 0x5, 0x00000000, 0x0, 0x303302fc
#define IOMUXC_ENET_RD2_ENET1_RGMII_RD2                               0x30330098, 0x0, 0x00000000, 0x0, 0x30330300
#define IOMUXC_ENET_RD2_GPIO1_IO28                                  0x30330098, 0x5, 0x00000000, 0x0, 0x30330300
#define IOMUXC_ENET_RD3_ENET1_RGMII_RD3                               0x3033009c, 0x0, 0x00000000, 0x0, 0x30330304
#define IOMUXC_ENET_RD3_GPIO1_IO29                                  0x3033009c, 0x5, 0x00000000, 0x0, 0x30330304
#define IOMUXC_SD1_CLK_USDHC1_CLK                                     0x303300a0, 0x0, 0x00000000, 0x0, 0x30330308
#define IOMUXC_SD1_CLK_GPIO2_IO0                                    0x303300a0, 0x5, 0x00000000, 0x0, 0x30330308
#define IOMUXC_SD1_CMD_USDHC1_CMD                                     0x303300a4, 0x0, 0x00000000, 0x0, 0x3033030c
#define IOMUXC_SD1_CMD_GPIO2_IO1                                    0x303300a4, 0x5, 0x00000000, 0x0, 0x3033030c
#define IOMUXC_SD1_DATA0_USDHC1_DATA0                                 0x303300a8, 0x0, 0x00000000, 0x0, 0x30330310
#define IOMUXC_SD1_DATA0_GPIO2_IO2                                  0x303300a8, 0x5, 0x00000000, 0x0, 0x3033031
#define IOMUXC_SD1_DATA1_USDHC1_DATA1                                 0x303300ac, 0x0, 0x00000000, 0x0, 0x30330314
#define IOMUXC_SD1_DATA1_GPIO2_IO3                                  0x303300ac, 0x5, 0x00000000, 0x0, 0x30330314
#define IOMUXC_SD1_DATA2_USDHC1_DATA2                                 0x303300b0, 0x0, 0x00000000, 0x0, 0x30330318
#define IOMUXC_SD1_DATA2_GPIO2_IO4                                  0x303300b0, 0x5, 0x00000000, 0x0, 0x30330318
#define IOMUXC_SD1_DATA3_USDHC1_DATA3                                 0x303300b4, 0x0, 0x00000000, 0x0, 0x3033031c
#define IOMUXC_SD1_DATA3_GPIO2_IO5                                  0x303300b4, 0x5, 0x00000000, 0x0, 0x3033031c
#define IOMUXC_SD1_DATA4_USDHC1_DATA4                                 0x303300b8, 0x0, 0x00000000, 0x0, 0x30330320
#define IOMUXC_SD1_DATA4_GPIO2_IO6                                  0x303300b8, 0x5, 0x00000000, 0x0, 0x30330320
#define IOMUXC_SD1_DATA5_USDHC1_DATA5                                 0x303300bc, 0x0, 0x00000000, 0x0, 0x30330324
#define IOMUXC_SD1_DATA5_GPIO2_IO7                                  0x303300bc, 0x5, 0x00000000, 0x0, 0x30330324
#define IOMUXC_SD1_DATA6_USDHC1_DATA6                                 0x303300c0, 0x0, 0x00000000, 0x0, 0x30330328      
#define IOMUXC_SD1_DATA6_GPIO2_IO8                                  0x303300c0, 0x5, 0x00000000, 0x0, 0x30330328
#define IOMUXC_SD1_DATA7_USDHC1_DATA7                                 0x303300c4, 0x0, 0x00000000, 0x0, 0x3033032c
#define IOMUXC_SD1_DATA7_GPIO2_IO9                                  0x303300c4, 0x5, 0x00000000, 0x0, 0x3033032c
#define IOMUXC_SD1_RESET_B_USDHC1_RESET_B                             0x303300c8, 0x0, 0x00000000, 0x0, 0x30330330
#define IOMUXC_SD1_RESET_B_GPIO2_IO10                               0x303300c8, 0x5, 0x00000000, 0x0, 0x30330330
#define IOMUXC_SD1_STROBE_USDHC1_STROBE                               0x303300cc, 0x0, 0x00000000, 0x0, 0x30330334
#define IOMUXC_SD1_STROBE_GPIO2_IO11                                0x303300cc, 0x5, 0x00000000, 0x0, 0x30330334
#define IOMUXC_SD2_CD_B_USDHC2_CD_B                                   0x303300d0, 0x0, 0x00000000, 0x0, 0x30330338
#define IOMUXC_SD2_CD_B_GPIO2_IO12                                  0x303300d0, 0x5, 0x00000000, 0x0, 0x30330338
#define IOMUXC_SD2_CLK_USDHC2_CLK                                     0x303300d4, 0x0, 0x00000000, 0x0, 0x3033033c
#define IOMUXC_SD2_CLK_GPIO2_IO13                                   0x303300d4, 0x5, 0x00000000, 0x0, 0x3033033c
#define IOMUXC_SD2_CLK_CCMSRCGPCMIX_OBSERVE0                          0x303300d4, 0x6, 0x00000000, 0x0, 0x3033033c
#define IOMUXC_SD2_CLK_OBSERVE_MUX_OUT0                             0x303300d4, 0x7, 0x00000000, 0x0, 0x3033033c
#define IOMUXC_SD2_CMD_USDHC2_CMD                                     0x303300d8, 0x0, 0x00000000, 0x0, 0x30330340
#define IOMUXC_SD2_CMD_GPIO2_IO14                                   0x303300d8, 0x5, 0x00000000, 0x0, 0x30330340
#define IOMUXC_SD2_CMD_CCMSRCGPCMIX_OBSERVE1                          0x303300d8, 0x6, 0x00000000, 0x0, 0x30330340
#define IOMUXC_SD2_CMD_OBSERVE_MUX_OUT1                             0x303300d8, 0x7, 0x00000000, 0x0, 0x30330340
#define IOMUXC_SD2_DATA0_USDHC2_DATA0                                 0x303300dc, 0x0, 0x00000000, 0x0, 0x30330344
#define IOMUXC_SD2_DATA0_GPIO2_IO15                                 0x303300dc, 0x5, 0x00000000, 0x0, 0x30330344
#define IOMUXC_SD2_DATA0_CCMSRCGPCMIX_OBSERVE2                        0x303300dc, 0x6, 0x00000000, 0x0, 0x30330344
#define IOMUXC_SD2_DATA0_OBSERVE_MUX_OUT2                           0x303300dc, 0x7, 0x00000000, 0x0, 0x30330344
#define IOMUXC_SD2_DATA1_USDHC2_DATA1                                 0x303300e0, 0x0, 0x00000000, 0x0, 0x30330348
#define IOMUXC_SD2_DATA1_GPIO2_IO16                                 0x303300e0, 0x5, 0x00000000, 0x0, 0x30330348
#define IOMUXC_SD2_DATA1_CCMSRCGPCMIX_WAIT                            0x303300e0, 0x6, 0x00000000, 0x0, 0x30330348
#define IOMUXC_SD2_DATA1_OBSERVE_MUX_OUT3                           0x303300e0, 0x7, 0x00000000, 0x0, 0x30330348
#define IOMUXC_SD2_DATA2_USDHC2_DATA2                                 0x303300e4, 0x0, 0x00000000, 0x0, 0x3033034c
#define IOMUXC_SD2_DATA2_GPIO2_IO17                                 0x303300e4, 0x5, 0x00000000, 0x0, 0x3033034c
#define IOMUXC_SD2_DATA2_CCMSRCGPCMIX_STOP                            0x303300e4, 0x6, 0x00000000, 0x0, 0x3033034c
#define IOMUXC_SD2_DATA2_OBSERVE_MUX_OUT4                           0x303300e4, 0x7, 0x00000000, 0x0, 0x3033034c
#define IOMUXC_SD2_DATA3_USDHC2_DATA3                                 0x303300e8, 0x0, 0x00000000, 0x0, 0x30330350
#define IOMUXC_SD2_DATA3_GPIO2_IO18                                 0x303300e8, 0x5, 0x00000000, 0x0, 0x30330350
#define IOMUXC_SD2_DATA3_CCMSRCGPCMIX_EARLY_RESET                     0x303300e8, 0x6, 0x00000000, 0x0, 0x30330350
#define IOMUXC_SD2_RESET_B_USDHC2_RESET_B                             0x303300ec, 0x0, 0x00000000, 0x0, 0x30330354
#define IOMUXC_SD2_RESET_B_GPIO2_IO19                               0x303300ec, 0x5, 0x00000000, 0x0, 0x30330354
#define IOMUXC_SD2_RESET_B_CCMSRCGPCMIX_SYSTEM_RESET                  0x303300ec, 0x6, 0x00000000, 0x0, 0x30330354
#define IOMUXC_SD2_WP_USDHC2_WP                                       0x303300f0, 0x0, 0x00000000, 0x0, 0x30330358
#define IOMUXC_SD2_WP_GPIO2_IO20                                    0x303300f0, 0x5, 0x00000000, 0x0, 0x30330358
#define IOMUXC_SD2_WP_SIM_M_HMASTLOCK                                 0x303300f0, 0x7, 0x00000000, 0x0, 0x30330358
#define IOMUXC_NAND_ALE_RAWNAND_ALE                                   0x303300f4, 0x0, 0x00000000, 0x0, 0x3033035c
#define IOMUXC_NAND_ALE_QSPI_A_SCLK                                   0x303300f4, 0x1, 0x00000000, 0x0, 0x3033035c
#define IOMUXC_NAND_ALE_GPIO3_IO0                                   0x303300f4, 0x5, 0x00000000, 0x0, 0x3033035c
#define IOMUXC_NAND_ALE_SIM_M_HPROT0                                0x303300f4, 0x7, 0x00000000, 0x0, 0x3033035c
#define IOMUXC_NAND_CE0_B_RAWNAND_CE0_B                               0x303300f8, 0x0, 0x00000000, 0x0, 0x30330360
#define IOMUXC_NAND_CE0_B_QSPI_A_SS0_B                                0x303300f8, 0x1, 0x00000000, 0x0, 0x30330360
#define IOMUXC_NAND_CE0_B_GPIO3_IO1                                 0x303300f8, 0x5, 0x00000000, 0x0, 0x30330360
#define IOMUXC_NAND_CE0_B_SIM_M_HPROT1                              0x303300f8, 0x7, 0x00000000, 0x0, 0x30330360
#define IOMUXC_NAND_CE1_B_RAWNAND_CE1_B                               0x303300fc, 0x0, 0x00000000, 0x0, 0x30330364
#define IOMUXC_NAND_CE1_B_QSPI_A_SS1_B                                0x303300fc, 0x1, 0x00000000, 0x0, 0x30330364
#define IOMUXC_NAND_CE1_B_GPIO3_IO2                                 0x303300fc, 0x5, 0x00000000, 0x0, 0x30330364
#define IOMUXC_NAND_CE1_B_SIM_M_HPROT2                              0x303300fc, 0x7, 0x00000000, 0x0, 0x30330364
#define IOMUXC_NAND_CE2_B_RAWNAND_CE2_B                               0x30330100, 0x0, 0x00000000, 0x0, 0x30330368
#define IOMUXC_NAND_CE2_B_QSPI_B_SS0_B                                0x30330100, 0x1, 0x00000000, 0x0, 0x30330368
#define IOMUXC_NAND_CE2_B_GPIO3_IO3                                 0x30330100, 0x5, 0x00000000, 0x0, 0x30330368
#define IOMUXC_NAND_CE2_B_SIM_M_HPROT3                              0x30330100, 0x7, 0x00000000, 0x0, 0x30330368
#define IOMUXC_NAND_CE3_B_RAWNAND_CE3_B                               0x30330104, 0x0, 0x00000000, 0x0, 0x3033036c
#define IOMUXC_NAND_CE3_B_QSPI_B_SS1_B                                0x30330104, 0x1, 0x00000000, 0x0, 0x3033036c
#define IOMUXC_NAND_CE3_B_GPIO3_IO4                                 0x30330104, 0x5, 0x00000000, 0x0, 0x3033036c
#define IOMUXC_NAND_CE3_B_SIM_M_HADDR0                              0x30330104, 0x7, 0x00000000, 0x0, 0x3033036c
#define IOMUXC_NAND_CLE_RAWNAND_CLE                                   0x30330108, 0x0, 0x00000000, 0x0, 0x30330370
#define IOMUXC_NAND_CLE_QSPI_B_SCLK                                   0x30330108, 0x1, 0x00000000, 0x0, 0x30330370
#define IOMUXC_NAND_CLE_GPIO3_IO5                                   0x30330108, 0x5, 0x00000000, 0x0, 0x30330370
#define IOMUXC_NAND_CLE_SIM_M_HADDR1                                0x30330108, 0x7, 0x00000000, 0x0, 0x30330370
#define IOMUXC_NAND_DATA00_RAWNAND_DATA00                             0x3033010c, 0x0, 0x00000000, 0x0, 0x30330374
#define IOMUXC_NAND_DATA00_QSPI_A_DATA0                             0x3033010c, 0x1, 0x00000000, 0x0, 0x30330374
#define IOMUXC_NAND_DATA00_GPIO3_IO6                                0x3033010c, 0x5, 0x00000000, 0x0, 0x30330374
#define IOMUXC_NAND_DATA00_SIM_M_HADDR2                             0x3033010c, 0x7, 0x00000000, 0x0, 0x30330374
#define IOMUXC_NAND_DATA01_RAWNAND_DATA01                             0x30330110, 0x0, 0x00000000, 0x0, 0x30330378
#define IOMUXC_NAND_DATA01_QSPI_A_DATA1                             0x30330110, 0x1, 0x00000000, 0x0, 0x30330378
#define IOMUXC_NAND_DATA01_GPIO3_IO7                                0x30330110, 0x5, 0x00000000, 0x0, 0x30330378
#define IOMUXC_NAND_DATA01_SIM_M_HADDR3                             0x30330110, 0x7, 0x00000000, 0x0, 0x30330378
#define IOMUXC_NAND_DATA02_RAWNAND_DATA02                             0x30330114, 0x0, 0x00000000, 0x0, 0x3033037c
#define IOMUXC_NAND_DATA02_QSPI_A_DATA2                             0x30330114, 0x1, 0x00000000, 0x0, 0x3033037c
#define IOMUXC_NAND_DATA02_GPIO3_IO8                                0x30330114, 0x5, 0x00000000, 0x0, 0x3033037c
#define IOMUXC_NAND_DATA02_SIM_M_HADDR4                             0x30330114, 0x7, 0x00000000, 0x0, 0x3033037c
#define IOMUXC_NAND_DATA03_RAWNAND_DATA03                             0x30330118, 0x0, 0x00000000, 0x0, 0x30330380
#define IOMUXC_NAND_DATA03_QSPI_A_DATA3                             0x30330118, 0x1, 0x00000000, 0x0, 0x30330380
#define IOMUXC_NAND_DATA03_GPIO3_IO9                                0x30330118, 0x5, 0x00000000, 0x0, 0x30330380
#define IOMUXC_NAND_DATA03_SIM_M_HADDR5                             0x30330118, 0x7, 0x00000000, 0x0, 0x30330380
#define IOMUXC_NAND_DATA04_RAWNAND_DATA04                             0x3033011c, 0x0, 0x00000000, 0x0, 0x30330384
#define IOMUXC_NAND_DATA04_QSPI_B_DATA0                             0x3033011c, 0x1, 0x00000000, 0x0, 0x30330384
#define IOMUXC_NAND_DATA04_GPIO3_IO10                               0x3033011c, 0x5, 0x00000000, 0x0, 0x30330384
#define IOMUXC_NAND_DATA04_SIM_M_HADDR6                             0x3033011c, 0x7, 0x00000000, 0x0, 0x30330384
#define IOMUXC_NAND_DATA05_RAWNAND_DATA05                             0x30330120, 0x0, 0x00000000, 0x0, 0x30330388
#define IOMUXC_NAND_DATA05_QSPI_B_DATA1                             0x30330120, 0x1, 0x00000000, 0x0, 0x30330388
#define IOMUXC_NAND_DATA05_GPIO3_IO11                               0x30330120, 0x5, 0x00000000, 0x0, 0x30330388
#define IOMUXC_NAND_DATA05_SIM_M_HADDR7                             0x30330120, 0x7, 0x00000000, 0x0, 0x30330388
#define IOMUXC_NAND_DATA06_RAWNAND_DATA06                             0x30330124, 0x0, 0x00000000, 0x0, 0x3033038c
#define IOMUXC_NAND_DATA06_QSPI_B_DATA2                             0x30330124, 0x1, 0x00000000, 0x0, 0x3033038c
#define IOMUXC_NAND_DATA06_GPIO3_IO12                               0x30330124, 0x5, 0x00000000, 0x0, 0x3033038c
#define IOMUXC_NAND_DATA06_SIM_M_HADDR8                             0x30330124, 0x7, 0x00000000, 0x0, 0x3033038c
#define IOMUXC_NAND_DATA07_RAWNAND_DATA07                             0x30330128, 0x0, 0x00000000, 0x0, 0x30330390
#define IOMUXC_NAND_DATA07_QSPI_B_DATA3                             0x30330128, 0x1, 0x00000000, 0x0, 0x30330390
#define IOMUXC_NAND_DATA07_GPIO3_IO13                               0x30330128, 0x5, 0x00000000, 0x0, 0x30330390
#define IOMUXC_NAND_DATA07_SIM_M_HADDR9                             0x30330128, 0x7, 0x00000000, 0x0, 0x30330390
#define IOMUXC_NAND_DQS_RAWNAND_DQS                                   0x3033012c, 0x0, 0x00000000, 0x0, 0x30330394
#define IOMUXC_NAND_DQS_QSPI_A_DQS                                    0x3033012c, 0x1, 0x00000000, 0x0, 0x30330394
#define IOMUXC_NAND_DQS_GPIO3_IO14                                  0x3033012c, 0x5, 0x00000000, 0x0, 0x30330394
#define IOMUXC_NAND_DQS_SIM_M_HADDR10                               0x3033012c, 0x7, 0x00000000, 0x0, 0x30330394
#define IOMUXC_NAND_RE_B_RAWNAND_RE_B                                 0x30330130, 0x0, 0x00000000, 0x0, 0x30330398
#define IOMUXC_NAND_RE_B_QSPI_B_DQS                                   0x30330130, 0x1, 0x00000000, 0x0, 0x30330398
#define IOMUXC_NAND_RE_B_GPIO3_IO15                                 0x30330130, 0x5, 0x00000000, 0x0, 0x30330398
#define IOMUXC_NAND_RE_B_SIM_M_HADDR11                              0x30330130, 0x7, 0x00000000, 0x0, 0x30330398
#define IOMUXC_NAND_READY_B_RAWNAND_READY_B                           0x30330134, 0x0, 0x00000000, 0x0, 0x3033039c
#define IOMUXC_NAND_READY_B_GPIO3_IO16                              0x30330134, 0x5, 0x00000000, 0x0, 0x3033039c
#define IOMUXC_NAND_READY_B_SIM_M_HADDR12                           0x30330134, 0x7, 0x00000000, 0x0, 0x3033039c
#define IOMUXC_NAND_WE_B_RAWNAND_WE_B                                 0x30330138, 0x0, 0x00000000, 0x0, 0x303303a0
#define IOMUXC_NAND_WE_B_GPIO3_IO17                                 0x30330138, 0x5, 0x00000000, 0x0, 0x303303a0
#define IOMUXC_NAND_WE_B_SIM_M_HADDR13                              0x30330138, 0x7, 0x00000000, 0x0, 0x303303a0
#define IOMUXC_NAND_WP_B_RAWNAND_WP_B                                 0x3033013c, 0x0, 0x00000000, 0x0, 0x303303a4
#define IOMUXC_NAND_WP_B_GPIO3_IO18                                 0x3033013c, 0x5, 0x00000000, 0x0, 0x303303a4
#define IOMUXC_NAND_WP_B_SIM_M_HADDR14                              0x3033013c, 0x7, 0x00000000, 0x0, 0x303303a4
#define IOMUXC_SAI5_RXFS_SAI5_RX_SYNC                                 0x30330140, 0x0, 0x303304e4, 0x0, 0x303303a8
#define IOMUXC_SAI5_RXFS_SAI1_TX_DATA0                              0x30330140, 0x1, 0x00000000, 0x0, 0x303303a8
#define IOMUXC_SAI5_RXFS_GPIO3_IO19                                 0x30330140, 0x5, 0x00000000, 0x0, 0x303303a8
#define IOMUXC_SAI5_RXC_SAI5_RX_BCLK                                  0x30330144, 0x0, 0x303304d0, 0x0, 0x303303ac
#define IOMUXC_SAI5_RXC_SAI1_TX_DATA1                               0x30330144, 0x1, 0x00000000, 0x0, 0x303303ac
#define IOMUXC_SAI5_RXC_GPIO3_IO20                                  0x30330144, 0x5, 0x00000000, 0x0, 0x303303ac
#define IOMUXC_SAI5_RXD0_SAI5_RX_DATA0                              0x30330148, 0x0, 0x303304d4, 0x0, 0x303303b0
#define IOMUXC_SAI5_RXD0_SAI1_TX_DATA2                              0x30330148, 0x1, 0x00000000, 0x0, 0x303303b0
#define IOMUXC_SAI5_RXD0_GPIO3_IO21                                 0x30330148, 0x5, 0x00000000, 0x0, 0x303303b0
#define IOMUXC_SAI5_RXD1_SAI5_RX_DATA1                              0x3033014c, 0x0, 0x303304d8, 0x0, 0x303303b4
#define IOMUXC_SAI5_RXD1_SAI1_TX_DATA3                              0x3033014c, 0x1, 0x00000000, 0x0, 0x303303b4
#define IOMUXC_SAI5_RXD1_SAI1_TX_SYNC                                 0x3033014c, 0x2, 0x303304cc, 0x0, 0x303303b4
#define IOMUXC_SAI5_RXD1_SAI5_TX_SYNC                                 0x3033014c, 0x3, 0x303304ec, 0x0, 0x303303b4
#define IOMUXC_SAI5_RXD1_GPIO3_IO22                                 0x3033014c, 0x5, 0x00000000, 0x0, 0x303303b4
#define IOMUXC_SAI5_RXD2_SAI5_RX_DATA2                              0x30330150, 0x0, 0x303304dc, 0x0, 0x303303b8
#define IOMUXC_SAI5_RXD2_SAI1_TX_DATA4                              0x30330150, 0x1, 0x00000000, 0x0, 0x303303b8
#define IOMUXC_SAI5_RXD2_SAI1_TX_SYNC                                 0x30330150, 0x2, 0x303304cc, 0x1, 0x303303b8
#define IOMUXC_SAI5_RXD2_SAI5_TX_BCLK                                 0x30330150, 0x3, 0x303304e8, 0x0, 0x303303b8
#define IOMUXC_SAI5_RXD2_GPIO3_IO23                                 0x30330150, 0x5, 0x00000000, 0x0, 0x303303b8
#define IOMUXC_SAI5_RXD3_SAI5_RX_DATA3                              0x30330154, 0x0, 0x303304e0, 0x0, 0x303303bc
#define IOMUXC_SAI5_RXD3_SAI1_TX_DATA5                              0x30330154, 0x1, 0x00000000, 0x0, 0x303303bc
#define IOMUXC_SAI5_RXD3_SAI1_TX_SYNC                                 0x30330154, 0x2, 0x303304cc, 0x2, 0x303303bc
#define IOMUXC_SAI5_RXD3_SAI5_TX_DATA0                              0x30330154, 0x3, 0x00000000, 0x0, 0x303303bc
#define IOMUXC_SAI5_RXD3_GPIO3_IO24                                 0x30330154, 0x5, 0x00000000, 0x0, 0x303303bc
#define IOMUXC_SAI5_MCLK_SAI5_MCLK                                    0x30330158, 0x0, 0x3033052c, 0x0, 0x303303c0
#define IOMUXC_SAI5_MCLK_SAI1_TX_BCLK                                 0x30330158, 0x1, 0x303304c8, 0x0, 0x303303c0
#define IOMUXC_SAI5_MCLK_SAI4_MCLK                                    0x30330158, 0x2, 0x00000000, 0x0, 0x303303c0
#define IOMUXC_SAI5_MCLK_GPIO3_IO25                                 0x30330158, 0x5, 0x00000000, 0x0, 0x303303c0
#define IOMUXC_SAI5_MCLK_CCMSRCGPCMIX_TESTER_ACK                      0x30330158, 0x6, 0x00000000, 0x0, 0x303303c0
#define IOMUXC_SAI1_RXFS_SAI1_RX_SYNC                                 0x3033015c, 0x0, 0x303304c4, 0x0, 0x303303c4
#define IOMUXC_SAI1_RXFS_SAI5_RX_SYNC                                 0x3033015c, 0x1, 0x303304e4, 0x1, 0x303303c4
#define IOMUXC_SAI1_RXFS_CORESIGHT_TRACE_CLK                          0x3033015c, 0x4, 0x00000000, 0x0, 0x303303c4
#define IOMUXC_SAI1_RXFS_GPIO4_IO0                                  0x3033015c, 0x5, 0x00000000, 0x0, 0x303303c4
#define IOMUXC_SAI1_RXFS_SIM_M_HADDR15                              0x3033015c, 0x7, 0x00000000, 0x0, 0x303303c4
#define IOMUXC_SAI1_RXC_SAI1_RX_BCLK                                  0x30330160, 0x0, 0x00000000, 0x0, 0x303303c8
#define IOMUXC_SAI1_RXC_SAI5_RX_BCLK                                  0x30330160, 0x1, 0x303304d0, 0x1, 0x303303c8
#define IOMUXC_SAI1_RXC_CORESIGHT_TRACE_CTL                           0x30330160, 0x4, 0x00000000, 0x0, 0x303303c8
#define IOMUXC_SAI1_RXC_GPIO4_IO1                                   0x30330160, 0x5, 0x00000000, 0x0, 0x303303c8
#define IOMUXC_SAI1_RXC_SIM_M_HADDR16                               0x30330160, 0x7, 0x00000000, 0x0, 0x303303c8
#define IOMUXC_SAI1_RXD0_SAI1_RX_DATA0                              0x30330164, 0x0, 0x00000000, 0x0, 0x303303cc
#define IOMUXC_SAI1_RXD0_SAI5_RX_DATA0                              0x30330164, 0x1, 0x303304d4, 0x1, 0x303303cc
#define IOMUXC_SAI1_RXD0_CORESIGHT_TRACE0                           0x30330164, 0x4, 0x00000000, 0x0, 0x303303cc
#define IOMUXC_SAI1_RXD0_GPIO4_IO2                                  0x30330164, 0x5, 0x00000000, 0x0, 0x303303cc
#define IOMUXC_SAI1_RXD0_CCMSRCGPCMIX_BOOT_CFG0                     0x30330164, 0x6, 0x00000000, 0x0, 0x303303cc
#define IOMUXC_SAI1_RXD0_SIM_M_HADDR17                              0x30330164, 0x7, 0x00000000, 0x0, 0x303303cc
#define IOMUXC_SAI1_RXD1_SAI1_RX_DATA1                              0x30330168, 0x0, 0x00000000, 0x0, 0x303303d0
#define IOMUXC_SAI1_RXD1_SAI5_RX_DATA1                              0x30330168, 0x1, 0x303304d8, 0x1, 0x303303d0
#define IOMUXC_SAI1_RXD1_CORESIGHT_TRACE1                           0x30330168, 0x4, 0x00000000, 0x0, 0x303303d0
#define IOMUXC_SAI1_RXD1_GPIO4_IO3                                  0x30330168, 0x5, 0x00000000, 0x0, 0x303303d0
#define IOMUXC_SAI1_RXD1_CCMSRCGPCMIX_BOOT_CFG1                     0x30330168, 0x6, 0x00000000, 0x0, 0x303303d0
#define IOMUXC_SAI1_RXD1_SIM_M_HADDR18                              0x30330168, 0x7, 0x00000000, 0x0, 0x303303d0
#define IOMUXC_SAI1_RXD2_SAI1_RX_DATA2                              0x3033016c, 0x0, 0x00000000, 0x0, 0x303303d4
#define IOMUXC_SAI1_RXD2_SAI5_RX_DATA2                              0x3033016c, 0x1, 0x303304dc, 0x1, 0x303303d4
#define IOMUXC_SAI1_RXD2_CORESIGHT_TRACE2                           0x3033016c, 0x4, 0x00000000, 0x0, 0x303303d4
#define IOMUXC_SAI1_RXD2_GPIO4_IO4                                  0x3033016c, 0x5, 0x00000000, 0x0, 0x303303d4
#define IOMUXC_SAI1_RXD2_CCMSRCGPCMIX_BOOT_CFG2                     0x3033016c, 0x6, 0x00000000, 0x0, 0x303303d4
#define IOMUXC_SAI1_RXD2_SIM_M_HADDR19                              0x3033016c, 0x7, 0x00000000, 0x0, 0x303303d4
#define IOMUXC_SAI1_RXD3_SAI1_RX_DATA3                              0x30330170, 0x0, 0x303304e0, 0x1, 0x303303d8
#define IOMUXC_SAI1_RXD3_SAI5_RX_DATA3                              0x30330170, 0x1, 0x00000000, 0x0, 0x303303d8
#define IOMUXC_SAI1_RXD3_CORESIGHT_TRACE3                           0x30330170, 0x4, 0x00000000, 0x0, 0x303303d8
#define IOMUXC_SAI1_RXD3_GPIO4_IO5                                  0x30330170, 0x5, 0x00000000, 0x0, 0x303303d8
#define IOMUXC_SAI1_RXD3_CCMSRCGPCMIX_BOOT_CFG3                     0x30330170, 0x6, 0x00000000, 0x0, 0x303303d8
#define IOMUXC_SAI1_RXD3_SIM_M_HADDR20                              0x30330170, 0x7, 0x00000000, 0x0, 0x303303d8
#define IOMUXC_SAI1_RXD4_SAI1_RX_DATA4                              0x30330174, 0x0, 0x00000000, 0x0, 0x303303dc
#define IOMUXC_SAI1_RXD4_SAI6_TX_BCLK                                 0x30330174, 0x1, 0x3033051c, 0x0, 0x303303dc
#define IOMUXC_SAI1_RXD4_SAI6_RX_BCLK                                 0x30330174, 0x2, 0x30330510, 0x0, 0x303303dc
#define IOMUXC_SAI1_RXD4_CORESIGHT_TRACE4                           0x30330174, 0x4, 0x00000000, 0x0, 0x303303dc
#define IOMUXC_SAI1_RXD4_GPIO4_IO6                                  0x30330174, 0x5, 0x00000000, 0x0, 0x303303dc
#define IOMUXC_SAI1_RXD4_CCMSRCGPCMIX_BOOT_CFG4                     0x30330174, 0x6, 0x00000000, 0x0, 0x303303dc
#define IOMUXC_SAI1_RXD4_SIM_M_HADDR21                              0x30330174, 0x7, 0x00000000, 0x0, 0x303303dc
#define IOMUXC_SAI1_RXD5_SAI1_RX_DATA5                              0x30330178, 0x0, 0x00000000, 0x0, 0x303303e0
#define IOMUXC_SAI1_RXD5_SAI6_TX_DATA0                              0x30330178, 0x1, 0x00000000, 0x0, 0x303303e0
#define IOMUXC_SAI1_RXD5_SAI6_RX_DATA0                              0x30330178, 0x2, 0x30330514, 0x0, 0x303303e0
#define IOMUXC_SAI1_RXD5_SAI1_RX_SYNC                                 0x30330178, 0x3, 0x303304c4, 0x1, 0x303303e0
#define IOMUXC_SAI1_RXD5_CORESIGHT_TRACE5                           0x30330178, 0x4, 0x00000000, 0x0, 0x303303e0
#define IOMUXC_SAI1_RXD5_GPIO4_IO7                                  0x30330178, 0x5, 0x00000000, 0x0, 0x303303e0
#define IOMUXC_SAI1_RXD5_CCMSRCGPCMIX_BOOT_CFG5                     0x30330178, 0x6, 0x00000000, 0x0, 0x303303e0
#define IOMUXC_SAI1_RXD5_SIM_M_HADDR22                              0x30330178, 0x7, 0x00000000, 0x0, 0x303303e0
#define IOMUXC_SAI1_RXD6_SAI1_RX_DATA6                              0x3033017c, 0x0, 0x30330520, 0x0, 0x303303e4
#define IOMUXC_SAI1_RXD6_SAI6_TX_SYNC                                 0x3033017c, 0x1, 0x00000000, 0x0, 0x303303e4
#define IOMUXC_SAI1_RXD6_SAI6_RX_SYNC                                 0x3033017c, 0x2, 0x30330518, 0x0, 0x303303e4
#define IOMUXC_SAI1_RXD6_CORESIGHT_TRACE6                           0x3033017c, 0x4, 0x00000000, 0x0, 0x303303e4
#define IOMUXC_SAI1_RXD6_GPIO4_IO8                                  0x3033017c, 0x5, 0x00000000, 0x0, 0x303303e4
#define IOMUXC_SAI1_RXD6_CCMSRCGPCMIX_BOOT_CFG6                     0x3033017c, 0x6, 0x00000000, 0x0, 0x303303e4
#define IOMUXC_SAI1_RXD6_SIM_M_HADDR23                              0x3033017c, 0x7, 0x00000000, 0x0, 0x303303e4
#define IOMUXC_SAI1_RXD7_SAI1_RX_DATA7                              0x30330180, 0x0, 0x00000000, 0x0, 0x303303e8
#define IOMUXC_SAI1_RXD7_SAI6_MCLK                                    0x30330180, 0x1, 0x30330530, 0x0, 0x303303e8
#define IOMUXC_SAI1_RXD7_SAI1_TX_SYNC                                 0x30330180, 0x2, 0x303304cc, 0x4, 0x303303e8
#define IOMUXC_SAI1_RXD7_SAI1_TX_DATA4                              0x30330180, 0x3, 0x00000000, 0x0, 0x303303e8
#define IOMUXC_SAI1_RXD7_CORESIGHT_TRACE7                           0x30330180, 0x4, 0x00000000, 0x0, 0x303303e8
#define IOMUXC_SAI1_RXD7_GPIO4_IO9                                  0x30330180, 0x5, 0x00000000, 0x0, 0x303303e8
#define IOMUXC_SAI1_RXD7_CCMSRCGPCMIX_BOOT_CFG7                     0x30330180, 0x6, 0x00000000, 0x0, 0x303303e8
#define IOMUXC_SAI1_RXD7_SIM_M_HADDR24                              0x30330180, 0x7, 0x00000000, 0x0, 0x303303e8
#define IOMUXC_SAI1_TXFS_SAI1_TX_SYNC                                 0x30330184, 0x0, 0x303304cc, 0x3, 0x303303ec
#define IOMUXC_SAI1_TXFS_SAI5_TX_SYNC                                 0x30330184, 0x1, 0x303304ec, 0x1, 0x303303ec
#define IOMUXC_SAI1_TXFS_CORESIGHT_EVENTO                             0x30330184, 0x4, 0x00000000, 0x0, 0x303303ec
#define IOMUXC_SAI1_TXFS_GPIO4_IO10                                 0x30330184, 0x5, 0x00000000, 0x0, 0x303303ec
#define IOMUXC_SAI1_TXFS_SIM_M_HADDR25                              0x30330184, 0x7, 0x00000000, 0x0, 0x303303ec
#define IOMUXC_SAI1_TXC_SAI1_TX_BCLK                                  0x30330188, 0x0, 0x303304c8, 0x1, 0x303303f0
#define IOMUXC_SAI1_TXC_SAI5_TX_BCLK                                  0x30330188, 0x1, 0x303304e8, 0x1, 0x303303f0
#define IOMUXC_SAI1_TXC_CORESIGHT_EVENTI                              0x30330188, 0x4, 0x00000000, 0x0, 0x303303f0
#define IOMUXC_SAI1_TXC_GPIO4_IO11                                  0x30330188, 0x5, 0x00000000, 0x0, 0x303303f0
#define IOMUXC_SAI1_TXC_SIM_M_HADDR26                               0x30330188, 0x7, 0x00000000, 0x0, 0x303303f0
#define IOMUXC_SAI1_TXD0_SAI1_TX_DATA0                              0x3033018c, 0x0, 0x00000000, 0x0, 0x303303f4
#define IOMUXC_SAI1_TXD0_SAI5_TX_DATA0                              0x3033018c, 0x1, 0x00000000, 0x0, 0x303303f4
#define IOMUXC_SAI1_TXD0_CORESIGHT_TRACE8                           0x3033018c, 0x4, 0x00000000, 0x0, 0x303303f4
#define IOMUXC_SAI1_TXD0_GPIO4_IO12                                 0x3033018c, 0x5, 0x00000000, 0x0, 0x303303f4
#define IOMUXC_SAI1_TXD0_CCMSRCGPCMIX_BOOT_CFG8                     0x3033018c, 0x6, 0x00000000, 0x0, 0x303303f4
#define IOMUXC_SAI1_TXD0_SIM_M_HADDR27                              0x3033018c, 0x7, 0x00000000, 0x0, 0x303303f4
#define IOMUXC_SAI1_TXD1_SAI1_TX_DATA1                              0x30330190, 0x0, 0x00000000, 0x0, 0x303303f8
#define IOMUXC_SAI1_TXD1_SAI5_TX_DATA1                              0x30330190, 0x1, 0x00000000, 0x0, 0x303303f8
#define IOMUXC_SAI1_TXD1_CORESIGHT_TRACE9                           0x30330190, 0x4, 0x00000000, 0x0, 0x303303f8
#define IOMUXC_SAI1_TXD1_GPIO4_IO13                                 0x30330190, 0x5, 0x00000000, 0x0, 0x303303f8
#define IOMUXC_SAI1_TXD1_CCMSRCGPCMIX_BOOT_CFG9                     0x30330190, 0x6, 0x00000000, 0x0, 0x303303f8
#define IOMUXC_SAI1_TXD1_SIM_M_HADDR28                              0x30330190, 0x7, 0x00000000, 0x0, 0x303303f8
#define IOMUXC_SAI1_TXD2_SAI1_TX_DATA2                              0x30330194, 0x0, 0x00000000, 0x0, 0x303303fc
#define IOMUXC_SAI1_TXD2_SAI5_TX_DATA2                              0x30330194, 0x1, 0x00000000, 0x0, 0x303303fc
#define IOMUXC_SAI1_TXD2_CORESIGHT_TRACE10                          0x30330194, 0x4, 0x00000000, 0x0, 0x303303fc
#define IOMUXC_SAI1_TXD2_GPIO4_IO14                                 0x30330194, 0x5, 0x00000000, 0x0, 0x303303fc
#define IOMUXC_SAI1_TXD2_CCMSRCGPCMIX_BOOT_CFG10                    0x30330194, 0x6, 0x00000000, 0x0, 0x303303fc
#define IOMUXC_SAI1_TXD2_SIM_M_HADDR29                              0x30330194, 0x7, 0x00000000, 0x0, 0x303303fc
#define IOMUXC_SAI1_TXD3_SAI1_TX_DATA3                              0x30330198, 0x0, 0x00000000, 0x0, 0x30330400
#define IOMUXC_SAI1_TXD3_SAI5_TX_DATA3                              0x30330198, 0x1, 0x00000000, 0x0, 0x30330400
#define IOMUXC_SAI1_TXD3_CORESIGHT_TRACE11                          0x30330198, 0x4, 0x00000000, 0x0, 0x30330400
#define IOMUXC_SAI1_TXD3_GPIO4_IO15                                 0x30330198, 0x5, 0x00000000, 0x0, 0x30330400
#define IOMUXC_SAI1_TXD3_CCMSRCGPCMIX_BOOT_CFG11                    0x30330198, 0x6, 0x00000000, 0x0, 0x30330400
#define IOMUXC_SAI1_TXD3_SIM_M_HADDR30                              0x30330198, 0x7, 0x00000000, 0x0, 0x30330400
#define IOMUXC_SAI1_TXD4_SAI1_TX_DATA4                              0x3033019c, 0x0, 0x00000000, 0x0, 0x30330404
#define IOMUXC_SAI1_TXD4_SAI6_RX_BCLK                                 0x3033019c, 0x1, 0x30330510, 0x1, 0x30330404
#define IOMUXC_SAI1_TXD4_SAI6_TX_BCLK                                 0x3033019c, 0x2, 0x3033051c, 0x1, 0x30330404
#define IOMUXC_SAI1_TXD4_CORESIGHT_TRACE12                          0x3033019c, 0x4, 0x00000000, 0x0, 0x30330404
#define IOMUXC_SAI1_TXD4_GPIO4_IO16                                 0x3033019c, 0x5, 0x00000000, 0x0, 0x30330404
#define IOMUXC_SAI1_TXD4_CCMSRCGPCMIX_BOOT_CFG12                    0x3033019c, 0x6, 0x00000000, 0x0, 0x30330404
#define IOMUXC_SAI1_TXD4_SIM_M_HADDR31                              0x3033019c, 0x7, 0x00000000, 0x0, 0x30330404
#define IOMUXC_SAI1_TXD5_SAI1_TX_DATA5                              0x303301a0, 0x0, 0x00000000, 0x0, 0x30330408
#define IOMUXC_SAI1_TXD5_SAI6_RX_DATA0                              0x303301a0, 0x1, 0x30330514, 0x1, 0x30330408
#define IOMUXC_SAI1_TXD5_SAI6_TX_DATA0                              0x303301a0, 0x2, 0x00000000, 0x0, 0x30330408
#define IOMUXC_SAI1_TXD5_CORESIGHT_TRACE13                          0x303301a0, 0x4, 0x00000000, 0x0, 0x30330408
#define IOMUXC_SAI1_TXD5_GPIO4_IO17                                 0x303301a0, 0x5, 0x00000000, 0x0, 0x30330408
#define IOMUXC_SAI1_TXD5_CCMSRCGPCMIX_BOOT_CFG13                    0x303301a0, 0x6, 0x00000000, 0x0, 0x30330408
#define IOMUXC_SAI1_TXD5_SIM_M_HBURST0                              0x303301a0, 0x7, 0x00000000, 0x0, 0x30330408
#define IOMUXC_SAI1_TXD6_SAI1_TX_DATA6                              0x303301a4, 0x0, 0x00000000, 0x0, 0x3033040c
#define IOMUXC_SAI1_TXD6_SAI6_RX_SYNC                                 0x303301a4, 0x1, 0x30330518, 0x1, 0x3033040c
#define IOMUXC_SAI1_TXD6_SAI6_TX_SYNC                                 0x303301a4, 0x2, 0x30330520, 0x1, 0x3033040c
#define IOMUXC_SAI1_TXD6_CORESIGHT_TRACE14                          0x303301a4, 0x4, 0x00000000, 0x0, 0x3033040c
#define IOMUXC_SAI1_TXD6_GPIO4_IO18                                 0x303301a4, 0x5, 0x00000000, 0x0, 0x3033040c
#define IOMUXC_SAI1_TXD6_CCMSRCGPCMIX_BOOT_CFG14                    0x303301a4, 0x6, 0x00000000, 0x0, 0x3033040c
#define IOMUXC_SAI1_TXD6_SIM_M_HBURST1                              0x303301a4, 0x7, 0x00000000, 0x0, 0x3033040c
#define IOMUXC_SAI1_TXD7_SAI1_TX_DATA7                              0x303301a8, 0x0, 0x00000000, 0x0, 0x30330410
#define IOMUXC_SAI1_TXD7_SAI6_MCLK                                    0x303301a8, 0x1, 0x30330530, 0x1, 0x30330410
#define IOMUXC_SAI1_TXD7_CORESIGHT_TRACE15                          0x303301a8, 0x4, 0x00000000, 0x0, 0x30330410
#define IOMUXC_SAI1_TXD7_GPIO4_IO19                                 0x303301a8, 0x5, 0x00000000, 0x0, 0x30330410
#define IOMUXC_SAI1_TXD7_CCMSRCGPCMIX_BOOT_CFG15                    0x303301a8, 0x6, 0x00000000, 0x0, 0x30330410
#define IOMUXC_SAI1_TXD7_SIM_M_HBURST2                              0x303301a8, 0x7, 0x00000000, 0x0, 0x30330410
#define IOMUXC_SAI1_MCLK_SAI1_MCLK                                    0x303301ac, 0x0, 0x00000000, 0x0, 0x30330414
#define IOMUXC_SAI1_MCLK_SAI5_MCLK                                    0x303301ac, 0x1, 0x3033052c, 0x1, 0x30330414
#define IOMUXC_SAI1_MCLK_SAI1_TX_BCLK                                 0x303301ac, 0x2, 0x303304c8, 0x2, 0x30330414
#define IOMUXC_SAI1_MCLK_GPIO4_IO20                                 0x303301ac, 0x5, 0x00000000, 0x0, 0x30330414
#define IOMUXC_SAI1_MCLK_SIM_M_HRESP                                  0x303301ac, 0x7, 0x00000000, 0x0, 0x30330414
#define IOMUXC_SAI2_RXFS_SAI2_RX_SYNC                                 0x303301b0, 0x0, 0x00000000, 0x0, 0x30330418
#define IOMUXC_SAI2_RXFS_SAI5_TX_SYNC                                 0x303301b0, 0x1, 0x303304ec, 0x2, 0x30330418
#define IOMUXC_SAI2_RXFS_GPIO4_IO21                                 0x303301b0, 0x5, 0x00000000, 0x0, 0x30330418
#define IOMUXC_SAI2_RXFS_SIM_M_HSIZE0                               0x303301b0, 0x7, 0x00000000, 0x0, 0x30330418
#define IOMUXC_SAI2_RXC_SAI2_RX_BCLK                                  0x303301b4, 0x0, 0x00000000, 0x0, 0x3033041c
#define IOMUXC_SAI2_RXC_SAI5_TX_BCLK                                  0x303301b4, 0x1, 0x303304e8, 0x2, 0x3033041c
#define IOMUXC_SAI2_RXC_GPIO4_IO22                                  0x303301b4, 0x5, 0x00000000, 0x0, 0x3033041c
#define IOMUXC_SAI2_RXC_SIM_M_HSIZE1                                0x303301b4, 0x7, 0x00000000, 0x0, 0x3033041c
#define IOMUXC_SAI2_RXD0_SAI2_RX_DATA0                              0x303301b8, 0x0, 0x00000000, 0x0, 0x30330420
#define IOMUXC_SAI2_RXD0_SAI5_TX_DATA0                              0x303301b8, 0x1, 0x00000000, 0x0, 0x30330420
#define IOMUXC_SAI2_RXD0_GPIO4_IO23                                 0x303301b8, 0x5, 0x00000000, 0x0, 0x30330420
#define IOMUXC_SAI2_RXD0_SIM_M_HSIZE2                               0x303301b8, 0x7, 0x00000000, 0x0, 0x30330420
#define IOMUXC_SAI2_TXFS_SAI2_TX_SYNC                                 0x303301bc, 0x0, 0x00000000, 0x0, 0x30330424
#define IOMUXC_SAI2_TXFS_SAI5_TX_DATA1                              0x303301bc, 0x1, 0x00000000, 0x0, 0x30330424
#define IOMUXC_SAI2_TXFS_GPIO4_IO24                                 0x303301bc, 0x5, 0x00000000, 0x0, 0x30330424
#define IOMUXC_SAI2_TXFS_SIM_M_HWRITE                                 0x303301bc, 0x7, 0x00000000, 0x0, 0x30330424
#define IOMUXC_SAI2_TXC_SAI2_TX_BCLK                                  0x303301c0, 0x0, 0x00000000, 0x0, 0x30330428
#define IOMUXC_SAI2_TXC_SAI5_TX_DATA2                               0x303301c0, 0x1, 0x00000000, 0x0, 0x30330428
#define IOMUXC_SAI2_TXC_GPIO4_IO25                                  0x303301c0, 0x5, 0x00000000, 0x0, 0x30330428
#define IOMUXC_SAI2_TXC_SIM_M_HREADYOUT                               0x303301c0, 0x7, 0x00000000, 0x0, 0x30330428
#define IOMUXC_SAI2_TXD0_SAI2_TX_DATA0                              0x303301c4, 0x0, 0x00000000, 0x0, 0x3033042c
#define IOMUXC_SAI2_TXD0_SAI5_TX_DATA3                              0x303301c4, 0x1, 0x00000000, 0x0, 0x3033042c
#define IOMUXC_SAI2_TXD0_GPIO4_IO26                                 0x303301c4, 0x5, 0x00000000, 0x0, 0x3033042c
#define IOMUXC_SAI2_TXD0_TPSMP_CLK                                    0x303301c4, 0x7, 0x00000000, 0x0, 0x3033042c
#define IOMUXC_SAI2_MCLK_SAI2_MCLK                                    0x303301c8, 0x0, 0x00000000, 0x0, 0x30330430
#define IOMUXC_SAI2_MCLK_SAI5_MCLK                                    0x303301c8, 0x1, 0x3033052c, 0x2, 0x30330430
#define IOMUXC_SAI2_MCLK_GPIO4_IO27                                 0x303301c8, 0x5, 0x00000000, 0x0, 0x30330430
#define IOMUXC_SAI2_MCLK_TPSMP_HDATA_DIR                              0x303301c8, 0x7, 0x00000000, 0x0, 0x30330430
#define IOMUXC_SAI3_RXFS_SAI3_RX_SYNC                                 0x303301cc, 0x0, 0x00000000, 0x0, 0x30330434
#define IOMUXC_SAI3_RXFS_GPT1_CAPTURE1                                0x303301cc, 0x1, 0x00000000, 0x0, 0x30330434
#define IOMUXC_SAI3_RXFS_SAI5_RX_SYNC                                 0x303301cc, 0x2, 0x303304e4, 0x2, 0x30330434
#define IOMUXC_SAI3_RXFS_GPIO4_IO28                                0x303301cc, 0x5, 0x00000000, 0x0, 0x30330434
#define IOMUXC_SAI3_RXFS_TPSMP_HTRANS0                             0x303301cc, 0x7, 0x00000000, 0x0, 0x30330434
#define IOMUXC_SAI3_RXC_SAI3_RX_BCLK                                  0x303301d0, 0x0, 0x00000000, 0x0, 0x30330438
#define IOMUXC_SAI3_RXC_GPT1_CAPTURE2                                 0x303301d0, 0x1, 0x00000000, 0x0, 0x30330438
#define IOMUXC_SAI3_RXC_SAI5_RX_BCLK                                  0x303301d0, 0x2, 0x303304d0, 0x2, 0x30330438
#define IOMUXC_SAI3_RXC_GPIO4_IO29                                  0x303301d0, 0x5, 0x00000000, 0x0, 0x30330438
#define IOMUXC_SAI3_RXC_TPSMP_HTRANS1                               0x303301d0, 0x7, 0x00000000, 0x0, 0x30330438
#define IOMUXC_SAI3_RXD_SAI3_RX_DATA0                               0x303301d4, 0x0, 0x00000000, 0x0, 0x3033043c
#define IOMUXC_SAI3_RXD_GPT1_COMPARE1                                 0x303301d4, 0x1, 0x00000000, 0x0, 0x3033043c
#define IOMUXC_SAI3_RXD_SAI5_RX_DATA0                               0x303301d4, 0x2, 0x303304d4, 0x2, 0x3033043c
#define IOMUXC_SAI3_RXD_GPIO4_IO30                                  0x303301d4, 0x5, 0x00000000, 0x0, 0x3033043c
#define IOMUXC_SAI3_RXD_TPSMP_HDATA0                                0x303301d4, 0x7, 0x00000000, 0x0, 0x3033043c
#define IOMUXC_SAI3_TXFS_SAI3_TX_SYNC                                 0x303301d8, 0x0, 0x00000000, 0x0, 0x30330440
#define IOMUXC_SAI3_TXFS_GPT1_CLK                                     0x303301d8, 0x1, 0x00000000, 0x0, 0x30330440
#define IOMUXC_SAI3_TXFS_SAI5_RX_DATA1                              0x303301d8, 0x2, 0x303304d8, 0x2, 0x30330440
#define IOMUXC_SAI3_TXFS_GPIO4_IO31                                 0x303301d8, 0x5, 0x00000000, 0x0, 0x30330440
#define IOMUXC_SAI3_TXFS_TPSMP_HDATA1                               0x303301d8, 0x7, 0x00000000, 0x0, 0x30330440
#define IOMUXC_SAI3_TXC_SAI3_TX_BCLK                                  0x303301dc, 0x0, 0x00000000, 0x0, 0x30330444
#define IOMUXC_SAI3_TXC_GPT1_COMPARE2                                 0x303301dc, 0x1, 0x00000000, 0x0, 0x30330444
#define IOMUXC_SAI3_TXC_SAI5_RX_DATA2                               0x303301dc, 0x2, 0x303304dc, 0x2, 0x30330444
#define IOMUXC_SAI3_TXC_GPIO5_IO0                                   0x303301dc, 0x5, 0x00000000, 0x0, 0x30330444
#define IOMUXC_SAI3_TXC_TPSMP_HDATA2                                0x303301dc, 0x7, 0x00000000, 0x0, 0x30330444
#define IOMUXC_SAI3_TXD_SAI3_TX_DATA0                               0x303301e0, 0x0, 0x00000000, 0x0, 0x30330448
#define IOMUXC_SAI3_TXD_GPT1_COMPARE3                                 0x303301e0, 0x1, 0x00000000, 0x0, 0x30330448
#define IOMUXC_SAI3_TXD_SAI5_RX_DATA3                               0x303301e0, 0x2, 0x303304e0, 0x2, 0x30330448
#define IOMUXC_SAI3_TXD_GPIO5_IO1                                   0x303301e0, 0x5, 0x00000000, 0x0, 0x30330448
#define IOMUXC_SAI3_TXD_TPSMP_HDATA3                                0x303301e0, 0x7, 0x00000000, 0x0, 0x30330448
#define IOMUXC_SAI3_MCLK_SAI3_MCLK                                    0x303301e4, 0x0, 0x00000000, 0x0, 0x3033044c
#define IOMUXC_SAI3_MCLK_PWM4_OUT                                     0x303301e4, 0x1, 0x00000000, 0x0, 0x3033044c
#define IOMUXC_SAI3_MCLK_SAI5_MCLK                                    0x303301e4, 0x2, 0x3033052c, 0x3, 0x3033044c
#define IOMUXC_SAI3_MCLK_GPIO5_IO2                                  0x303301e4, 0x5, 0x00000000, 0x0, 0x3033044c
#define IOMUXC_SAI3_MCLK_TPSMP_HDATA4                               0x303301e4, 0x7, 0x00000000, 0x0, 0x3033044c
#define IOMUXC_SPDIF_TX_SPDIF1_OUT                                    0x303301e8, 0x0, 0x00000000, 0x0, 0x30330450
#define IOMUXC_SPDIF_TX_PWM3_OUT                                      0x303301e8, 0x1, 0x00000000, 0x0, 0x30330450
#define IOMUXC_SPDIF_TX_GPIO5_IO3                                   0x303301e8, 0x5, 0x00000000, 0x0, 0x30330450
#define IOMUXC_SPDIF_TX_TPSMP_HDATA5                                0x303301e8, 0x7, 0x00000000, 0x0, 0x30330450
#define IOMUXC_SPDIF_RX_SPDIF1_IN                                     0x303301ec, 0x0, 0x00000000, 0x0, 0x30330454
#define IOMUXC_SPDIF_RX_PWM2_OUT                                      0x303301ec, 0x1, 0x00000000, 0x0, 0x30330454
#define IOMUXC_SPDIF_RX_GPIO5_IO4                                   0x303301ec, 0x5, 0x00000000, 0x0, 0x30330454
#define IOMUXC_SPDIF_RX_TPSMP_HDATA6                                0x303301ec, 0x7, 0x00000000, 0x0, 0x30330454
#define IOMUXC_SPDIF_EXT_CLK_SPDIF1_EXT_CLK                           0x303301f0, 0x0, 0x00000000, 0x0, 0x30330458
#define IOMUXC_SPDIF_EXT_CLK_PWM1_OUT                                 0x303301f0, 0x1, 0x00000000, 0x0, 0x30330458
#define IOMUXC_SPDIF_EXT_CLK_GPIO5_IO5                              0x303301f0, 0x5, 0x00000000, 0x0, 0x30330458
#define IOMUXC_SPDIF_EXT_CLK_TPSMP_HDATA7                           0x303301f0, 0x7, 0x00000000, 0x0, 0x30330458
#define IOMUXC_ECSPI1_SCLK_ECSPI1_SCLK                                0x303301f4, 0x0, 0x00000000, 0x0, 0x3033045c
#define IOMUXC_ECSPI1_SCLK_UART3_RX                                   0x303301f4, 0x1, 0x30330504, 0x0, 0x3033045c
#define IOMUXC_ECSPI1_SCLK_GPIO5_IO6                                0x303301f4, 0x5, 0x00000000, 0x0, 0x3033045c
#define IOMUXC_ECSPI1_SCLK_TPSMP_HDATA8                             0x303301f4, 0x7, 0x00000000, 0x0, 0x3033045c
#define IOMUXC_ECSPI1_MOSI_ECSPI1_MOSI                                0x303301f8, 0x0, 0x00000000, 0x0, 0x30330460
#define IOMUXC_ECSPI1_MOSI_UART3_TX                                   0x303301f8, 0x1, 0x30330504, 0x1, 0x30330460
#define IOMUXC_ECSPI1_MOSI_GPIO5_IO7                                0x303301f8, 0x5, 0x00000000, 0x0, 0x30330460
#define IOMUXC_ECSPI1_MOSI_TPSMP_HDATA9                             0x303301f8, 0x7, 0x00000000, 0x0, 0x30330460
#define IOMUXC_ECSPI1_MISO_ECSPI1_MISO                                0x303301fc, 0x0, 0x00000000, 0x0, 0x30330464
#define IOMUXC_ECSPI1_MISO_UART3_CTS_B                                0x303301fc, 0x1, 0x30330500, 0x0, 0x30330464
#define IOMUXC_ECSPI1_MISO_GPIO5_IO8                                0x303301fc, 0x5, 0x00000000, 0x0, 0x30330464
#define IOMUXC_ECSPI1_MISO_TPSMP_HDATA10                            0x303301fc, 0x7, 0x00000000, 0x0, 0x30330464
#define IOMUXC_ECSPI1_SS0_ECSPI1_SS0                                  0x30330200, 0x0, 0x00000000, 0x0, 0x30330468
#define IOMUXC_ECSPI1_SS0_UART3_RTS_B                                 0x30330200, 0x1, 0x30330500, 0x1, 0x30330468
#define IOMUXC_ECSPI1_SS0_GPIO5_IO9                                 0x30330200, 0x5, 0x00000000, 0x0, 0x30330468
#define IOMUXC_ECSPI1_SS0_TPSMP_HDATA11                             0x30330200, 0x7, 0x00000000, 0x0, 0x30330468
#define IOMUXC_ECSPI2_SCLK_ECSPI2_SCLK                                0x30330204, 0x0, 0x00000000, 0x0, 0x3033046c
#define IOMUXC_ECSPI2_SCLK_UART4_RX                                   0x30330204, 0x1, 0x3033050c, 0x0, 0x3033046c
#define IOMUXC_ECSPI2_SCLK_GPIO5_IO10                               0x30330204, 0x5, 0x00000000, 0x0, 0x3033046c
#define IOMUXC_ECSPI2_SCLK_TPSMP_HDATA12                            0x30330204, 0x7, 0x00000000, 0x0, 0x3033046c
#define IOMUXC_ECSPI2_MOSI_ECSPI2_MOSI                                0x30330208, 0x0, 0x00000000, 0x0, 0x30330470
#define IOMUXC_ECSPI2_MOSI_UART4_TX                                   0x30330208, 0x1, 0x3033050c, 0x1, 0x30330470
#define IOMUXC_ECSPI2_MOSI_GPIO5_IO11                               0x30330208, 0x5, 0x00000000, 0x0, 0x30330470
#define IOMUXC_ECSPI2_MOSI_TPSMP_HDATA13                            0x30330208, 0x7, 0x00000000, 0x0, 0x30330470
#define IOMUXC_ECSPI2_MISO_ECSPI2_MISO                                0x3033020c, 0x0, 0x00000000, 0x0, 0x30330474
#define IOMUXC_ECSPI2_MISO_UART4_CTS_B                                0x3033020c, 0x1, 0x30330508, 0x0, 0x30330474
#define IOMUXC_ECSPI2_MISO_GPIO5_IO12                               0x3033020c, 0x5, 0x00000000, 0x0, 0x30330474
#define IOMUXC_ECSPI2_MISO_TPSMP_HDATA14                            0x3033020c, 0x7, 0x00000000, 0x0, 0x30330474
#define IOMUXC_ECSPI2_SS0_ECSPI2_SS0                                  0x30330210, 0x0, 0x00000000, 0x0, 0x30330478
#define IOMUXC_ECSPI2_SS0_UART4_RTS_B                                 0x30330210, 0x1, 0x30330508, 0x1, 0x30330478
#define IOMUXC_ECSPI2_SS0_GPIO5_IO13                                0x30330210, 0x5, 0x00000000, 0x0, 0x30330478
#define IOMUXC_ECSPI2_SS0_TPSMP_HDATA15                             0x30330210, 0x7, 0x00000000, 0x0, 0x30330478
#define IOMUXC_I2C1_SCL_I2C1_SCL                                      0x30330214, 0x0, 0x00000000, 0x0, 0x3033047c
#define IOMUXC_I2C1_SCL_ENET1_MDC                                     0x30330214, 0x1, 0x00000000, 0x0, 0x3033047c
#define IOMUXC_I2C1_SCL_GPIO5_IO14                                  0x30330214, 0x5, 0x00000000, 0x0, 0x3033047c
#define IOMUXC_I2C1_SCL_TPSMP_HDATA16                               0x30330214, 0x7, 0x00000000, 0x0, 0x3033047c
#define IOMUXC_I2C1_SDA_I2C1_SDA                                      0x30330218, 0x0, 0x00000000, 0x0, 0x30330480
#define IOMUXC_I2C1_SDA_ENET1_MDIO                                    0x30330218, 0x1, 0x303304c0, 0x2, 0x30330480
#define IOMUXC_I2C1_SDA_GPIO5_IO15                                  0x30330218, 0x5, 0x00000000, 0x0, 0x30330480
#define IOMUXC_I2C1_SDA_TPSMP_HDATA17                               0x30330218, 0x7, 0x00000000, 0x0, 0x30330480
#define IOMUXC_I2C2_SCL_I2C2_SCL                                      0x3033021c, 0x0, 0x00000000, 0x0, 0x30330484
#define IOMUXC_I2C2_SCL_ENET1_1588_EVENT1_IN                          0x3033021c, 0x1, 0x00000000, 0x0, 0x30330484
#define IOMUXC_I2C2_SCL_GPIO5_IO16                                  0x3033021c, 0x5, 0x00000000, 0x0, 0x30330484
#define IOMUXC_I2C2_SCL_TPSMP_HDATA18                               0x3033021c, 0x7, 0x00000000, 0x0, 0x30330484
#define IOMUXC_I2C2_SDA_I2C2_SDA                                      0x30330220, 0x0, 0x00000000, 0x0, 0x30330488
#define IOMUXC_I2C2_SDA_ENET1_1588_EVENT1_OUT                         0x30330220, 0x1, 0x00000000, 0x0, 0x30330488
#define IOMUXC_I2C2_SDA_GPIO5_IO17                                  0x30330220, 0x5, 0x00000000, 0x0, 0x30330488
#define IOMUXC_I2C2_SDA_TPSMP_HDATA19                               0x30330220, 0x7, 0x00000000, 0x0, 0x30330488
#define IOMUXC_I2C3_SCL_I2C3_SCL                                      0x30330224, 0x0, 0x00000000, 0x0, 0x3033048c
#define IOMUXC_I2C3_SCL_PWM4_OUT                                      0x30330224, 0x1, 0x00000000, 0x0, 0x3033048c
#define IOMUXC_I2C3_SCL_GPT2_CLK                                      0x30330224, 0x2, 0x00000000, 0x0, 0x3033048c
#define IOMUXC_I2C3_SCL_GPIO5_IO18                                  0x30330224, 0x5, 0x00000000, 0x0, 0x3033048c
#define IOMUXC_I2C3_SCL_TPSMP_HDATA20                               0x30330224, 0x7, 0x00000000, 0x0, 0x3033048c
#define IOMUXC_I2C3_SDA_I2C3_SDA                                      0x30330228, 0x0, 0x00000000, 0x0, 0x30330490
#define IOMUXC_I2C3_SDA_PWM3_OUT                                      0x30330228, 0x1, 0x00000000, 0x0, 0x30330490
#define IOMUXC_I2C3_SDA_GPT3_CLK                                      0x30330228, 0x2, 0x00000000, 0x0, 0x30330490
#define IOMUXC_I2C3_SDA_GPIO5_IO19                                  0x30330228, 0x5, 0x00000000, 0x0, 0x30330490
#define IOMUXC_I2C3_SDA_TPSMP_HDATA21                               0x30330228, 0x7, 0x00000000, 0x0, 0x30330490
#define IOMUXC_I2C4_SCL_I2C4_SCL                                      0x3033022c, 0x0, 0x00000000, 0x0, 0x30330494
#define IOMUXC_I2C4_SCL_PWM2_OUT                                      0x3033022c, 0x1, 0x00000000, 0x0, 0x30330494
#define IOMUXC_I2C4_SCL_PCIE1_CLKREQ_B                                0x3033022c, 0x2, 0x30330524, 0x0, 0x30330494
#define IOMUXC_I2C4_SCL_GPIO5_IO20                                  0x3033022c, 0x5, 0x00000000, 0x0, 0x30330494
#define IOMUXC_I2C4_SCL_TPSMP_HDATA22                               0x3033022c, 0x7, 0x00000000, 0x0, 0x30330494
#define IOMUXC_I2C4_SDA_I2C4_SDA                                      0x30330230, 0x0, 0x00000000, 0x0, 0x30330498
#define IOMUXC_I2C4_SDA_PWM1_OUT                                      0x30330230, 0x1, 0x00000000, 0x0, 0x30330498
#define IOMUXC_I2C4_SDA_PCIE2_CLKREQ_B                                0x30330230, 0x2, 0x30330528, 0x0, 0x30330498
#define IOMUXC_I2C4_SDA_GPIO5_IO21                                  0x30330230, 0x5, 0x00000000, 0x0, 0x30330498
#define IOMUXC_I2C4_SDA_TPSMP_HDATA23                               0x30330230, 0x7, 0x00000000, 0x0, 0x30330498
#define IOMUXC_UART1_RXD_UART1_RX                                     0x30330234, 0x0, 0x303304f4, 0x0, 0x3033049c
#define IOMUXC_UART1_RXD_ECSPI3_SCLK                                  0x30330234, 0x1, 0x00000000, 0x0, 0x3033049c
#define IOMUXC_UART1_RXD_GPIO5_IO22                                 0x30330234, 0x5, 0x00000000, 0x0, 0x3033049c
#define IOMUXC_UART1_RXD_TPSMP_HDATA24                              0x30330234, 0x7, 0x00000000, 0x0, 0x3033049c
#define IOMUXC_UART1_TXD_UART1_TX                                     0x30330238, 0x0, 0x303304f4, 0x1, 0x303304a0
#define IOMUXC_UART1_TXD_ECSPI3_MOSI                                  0x30330238, 0x1, 0x00000000, 0x0, 0x303304a0
#define IOMUXC_UART1_TXD_GPIO5_IO23                                 0x30330238, 0x5, 0x00000000, 0x0, 0x303304a0
#define IOMUXC_UART1_TXD_TPSMP_HDATA25                              0x30330238, 0x7, 0x00000000, 0x0, 0x303304a0
#define IOMUXC_UART2_RXD_UART2_RX                                     0x3033023c, 0x0, 0x303304fc, 0x0, 0x303304a4
#define IOMUXC_UART2_RXD_ECSPI3_MISO                                  0x3033023c, 0x1, 0x00000000, 0x0, 0x303304a4
#define IOMUXC_UART2_RXD_GPIO5_IO24                                 0x3033023c, 0x5, 0x00000000, 0x0, 0x303304a4
#define IOMUXC_UART2_RXD_TPSMP_HDATA26                              0x3033023c, 0x7, 0x00000000, 0x0, 0x303304a4
#define IOMUXC_UART2_TXD_UART2_TX                                     0x30330240, 0x0, 0x00000000, 0x0, 0x303304a8
#define IOMUXC_UART2_TXD_ECSPI3_SS0                                   0x30330240, 0x1, 0x00000000, 0x0, 0x303304a8
#define IOMUXC_UART2_TXD_GPIO5_IO25                                 0x30330240, 0x5, 0x00000000, 0x0, 0x303304a8
#define IOMUXC_UART2_TXD_TPSMP_HDATA27                              0x30330240, 0x7, 0x00000000, 0x0, 0x303304a8 
#define IOMUXC_UART3_RXD_UART3_RX                                     0x30330244, 0x0, 0x30330504, 0x2, 0x303304ac
#define IOMUXC_UART3_RXD_UART1_CTS_B                                  0x30330244, 0x1, 0x303304f0, 0x0, 0x303304ac
#define IOMUXC_UART3_RXD_GPIO5_IO26                                 0x30330244, 0x5, 0x00000000, 0x0, 0x303304ac
#define IOMUXC_UART3_RXD_TPSMP_HDATA28                              0x30330244, 0x7, 0x00000000, 0x0, 0x303304ac
#define IOMUXC_UART3_TXD_UART3_TX                                     0x30330248, 0x0, 0x30330504, 0x3, 0x303304b0
#define IOMUXC_UART3_TXD_UART1_RTS_B                                  0x30330248, 0x1, 0x303304f0, 0x1, 0x303304b0
#define IOMUXC_UART3_TXD_GPIO5_IO27                                 0x30330248, 0x5, 0x00000000, 0x0, 0x303304b0
#define IOMUXC_UART3_TXD_TPSMP_HDATA29                              0x30330248, 0x7, 0x00000000, 0x0, 0x303304b0
#define IOMUXC_UART4_RXD_UART4_RX                                     0x3033024c, 0x0, 0x3033050c, 0x2, 0x303304b4
#define IOMUXC_UART4_RXD_UART2_CTS_B                                  0x3033024c, 0x1, 0x303304f8, 0x0, 0x303304b4
#define IOMUXC_UART4_RXD_PCIE1_CLKREQ_B                               0x3033024c, 0x2, 0x30330524, 0x1, 0x303304b4
#define IOMUXC_UART4_RXD_GPIO5_IO28                                 0x3033024c, 0x5, 0x00000000, 0x0, 0x303304b4
#define IOMUXC_UART4_RXD_TPSMP_HDATA30                              0x3033024c, 0x7, 0x00000000, 0x0, 0x303304b4
#define IOMUXC_UART4_TXD_UART4_TX                                     0x30330250, 0x0, 0x3033050c, 0x3, 0x303304b8
#define IOMUXC_UART4_TXD_UART2_RTS_B                                  0x30330250, 0x1, 0x303304f8, 0x1, 0x303304b8
#define IOMUXC_UART4_TXD_PCIE2_CLKREQ_B                               0x30330250, 0x2, 0x30330528, 0x1, 0x303304b8
#define IOMUXC_UART4_TXD_GPIO5_IO29                                 0x30330250, 0x5, 0x00000000, 0x0, 0x303304b8
#define IOMUXC_UART4_TXD_TPSMP_HDATA31                              0x30330250, 0x7, 0x00000000, 0x0, 0x303304b8
#define IOMUXC_TEST_MODE                                              0x00000000, 0x0, 0x00000000, 0x0, 0x30330254
#define IOMUXC_BOOT_MODE0                                             0x00000000, 0x0, 0x00000000, 0x0, 0x30330258
#define IOMUXC_BOOT_MODE1                                             0x00000000, 0x0, 0x00000000, 0x0, 0x3033025c
#define IOMUXC_JTAG_MOD                                               0x00000000, 0x0, 0x00000000, 0x0, 0x30330260
#define IOMUXC_JTAG_TRST_B                                            0x00000000, 0x0, 0x00000000, 0x0, 0x30330264
#define IOMUXC_JTAG_TDI                                               0x00000000, 0x0, 0x00000000, 0x0, 0x30330268
#define IOMUXC_JTAG_TMS                                               0x00000000, 0x0, 0x00000000, 0x0, 0x3033026c
#define IOMUXC_JTAG_TCK                                               0x00000000, 0x0, 0x00000000, 0x0, 0x30330270
#define IOMUXC_JTAG_TDO                                               0x00000000, 0x0, 0x00000000, 0x0, 0x30330274
#define IOMUXC_RTC                                                    0x00000000, 0x0, 0x00000000, 0x0, 0x30330278

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
 * IOMUXC_SetPinMux(IOMUXC_I2C4_SDA_pwm1_OUT, 0);
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
 * This is an example to set pin configuration for IOMUXC_I2C4_SDA_pwm1_OUT:
 * @code
 * IOMUXC_SetPinConfig(IOMUXC_I2C4_SDA_pwm1_OUT, IOMUXC_SW_PAD_CTL_PAD_ODE_MASK | IOMUXC0_SW_PAD_CTL_PAD_DSE(2U))
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
