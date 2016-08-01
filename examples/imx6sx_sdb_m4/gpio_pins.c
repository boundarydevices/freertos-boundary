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

#include <assert.h>
#include "gpio_pins.h"

gpio_config_t gpioKeyFunc1 = {
    "FUNC1",                                        /* name */
    &IOMUXC_SW_MUX_CTL_PAD_CSI_DATA04,              /* muxReg */
    5,                                              /* muxConfig */
    &IOMUXC_SW_PAD_CTL_PAD_CSI_DATA04,              /* padReg */
    IOMUXC_SW_PAD_CTL_PAD_CSI_DATA04_PUS(2) |       /* padConfig */
    IOMUXC_SW_PAD_CTL_PAD_CSI_DATA04_PUE_MASK |
    IOMUXC_SW_PAD_CTL_PAD_CSI_DATA04_PKE_MASK |
    IOMUXC_SW_PAD_CTL_PAD_CSI_DATA04_SPEED(2) |
    IOMUXC_SW_PAD_CTL_PAD_CSI_DATA04_DSE(6),
    GPIO1,                                          /* base */
    18                                              /* pin */
};

gpio_config_t gpioKeyFunc2 = {
    "FUNC2",                                        /* name */
    &IOMUXC_SW_MUX_CTL_PAD_CSI_DATA05,              /* muxReg */
    5,                                              /* muxConfig */
    &IOMUXC_SW_PAD_CTL_PAD_CSI_DATA05,              /* padReg */
    IOMUXC_SW_PAD_CTL_PAD_CSI_DATA05_PUS(1) |       /* padConfig */
    IOMUXC_SW_PAD_CTL_PAD_CSI_DATA05_PUE_MASK |
    IOMUXC_SW_PAD_CTL_PAD_CSI_DATA05_PKE_MASK |
    IOMUXC_SW_PAD_CTL_PAD_CSI_DATA05_SPEED(2) |
    IOMUXC_SW_PAD_CTL_PAD_CSI_DATA05_DSE(6),
    GPIO1,                                          /* base */
    19                                              /* pin */
};

gpio_config_t gpioSensorAccInt = {
    "SensorAccInt",                                 /* name */
    &IOMUXC_SW_MUX_CTL_PAD_SD1_DATA0,               /* muxReg */
    5,                                              /* muxConfig */
    &IOMUXC_SW_PAD_CTL_PAD_SD1_DATA0,               /* padReg */
    IOMUXC_SW_PAD_CTL_PAD_SD1_DATA0_PUS(2) |        /* padConfig */
    IOMUXC_SW_PAD_CTL_PAD_SD1_DATA0_PUE_MASK |
    IOMUXC_SW_PAD_CTL_PAD_SD1_DATA0_PKE_MASK |
    IOMUXC_SW_PAD_CTL_PAD_SD1_DATA0_SPEED(2) |
    IOMUXC_SW_PAD_CTL_PAD_SD1_DATA0_DSE(6),
    GPIO6,                                          /* base */
    2                                               /* pin */
};

gpio_config_t gpioSensorMagAlsInt = {
    "SensorMagAlsInt",                              /* name */
    &IOMUXC_SW_MUX_CTL_PAD_SD1_DATA3,               /* muxReg */
    5,                                              /* muxConfig */
    &IOMUXC_SW_PAD_CTL_PAD_SD1_DATA3,               /* padReg */
    IOMUXC_SW_PAD_CTL_PAD_SD1_DATA3_PUS(2) |        /* padConfig */
    IOMUXC_SW_PAD_CTL_PAD_SD1_DATA3_PUE_MASK |
    IOMUXC_SW_PAD_CTL_PAD_SD1_DATA3_PKE_MASK |
    IOMUXC_SW_PAD_CTL_PAD_SD1_DATA3_SPEED(2) |
    IOMUXC_SW_PAD_CTL_PAD_SD1_DATA3_DSE(6),
    GPIO6,                                          /* base */
    5                                               /* pin */
};

void configure_gpio_pin(gpio_config_t *config)
{
    assert(config);

    *(config->muxReg) = config->muxConfig;
    *(config->padReg) = config->padConfig;
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
