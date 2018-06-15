/*
 * The Clear BSD License
 * Copyright 2017 NXP Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted (subject to the limitations in the disclaimer below) provided
 * that the following conditions are met:
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

#include "fsl_wm8524.h"
#include "fsl_gpio.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

void WM8524_Init(wm8524_handle_t *handle, wm8524_config_t *config)
{
    gpio_pin_config_t gpioConfig = {kGPIO_DigitalOutput, 1};

    /* Configure contents to handle */
    handle->busPin = config->busPin;
    handle->busPinNum = config->busPinNum;
    handle->mutePin = config->mutePin;
    handle->mutePinNum = config->mutePinNum;

    /* Initialize GPIO pins */
    if (handle->busPin)
    {
        GPIO_PinInit(config->busPin, config->busPinNum, &gpioConfig);
        /* Initialize codec protocol */
        WM8524_ConfigFormat(handle, config->protocol);
    }

    /* Unmute codec */
    GPIO_PinInit(config->mutePin, config->mutePinNum, &gpioConfig);
    WM8524_SetMute(handle, false);
}

void WM8524_ConfigFormat(wm8524_handle_t *handle, wm8524_protocol_t protocol)
{
    if (protocol != kWM8524_ProtocolRightJustified)
    {
        GPIO_PinWrite(handle->busPin, handle->busPinNum, protocol);
    }
}

void WM8524_SetMute(wm8524_handle_t *handle, bool isMute)
{
    GPIO_PinWrite(handle->mutePin, handle->mutePinNum, (!isMute));
}
