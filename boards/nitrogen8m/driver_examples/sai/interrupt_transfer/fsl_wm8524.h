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

#ifndef _FSL_WM8524_H_
#define _FSL_WM8524_H_

#include "fsl_common.h"
#include "fsl_gpio.h"

/*!
 * @addtogroup wm8524
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @brief The audio data transfer protocol. */
typedef enum _wm8524_protocol
{
    kWM8524_ProtocolLeftJustified = 0x0,  /*!< Left justified mode */
    kWM8524_ProtocolI2S = 0x1,            /*!< I2S mode */
    kWM8524_ProtocolRightJustified = 0x2, /*!< Right justified mode */
} wm8524_protocol_t;

typedef struct _wm8524_config
{
    GPIO_Type *busPin;          /*!< GPIO type for protocol control */
    uint32_t busPinNum;         /*!< Pin number for protocol control */
    GPIO_Type *mutePin;         /*!< GPIO type for mute control */
    uint32_t mutePinNum;        /*!< Pin number for mute control */
    wm8524_protocol_t protocol; /*!< Protocol of the codec */
} wm8524_config_t;

/*! @brief WM8542 codec handler. */
typedef struct _wm8524_handle
{
    GPIO_Type *busPin;   /*!< GPIO type for protocol control */
    uint32_t busPinNum;  /*!< Pin number for protocol control */
    GPIO_Type *mutePin;  /*!< GPIO type for mute control */
    uint32_t mutePinNum; /*!< Pin number for mute control */
} wm8524_handle_t;

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Initializes WM8524.
 *
 * @param handle WM8524 handle structure.
 * @param config WM8524 configure structure.
 */
void WM8524_Init(wm8524_handle_t *handle, wm8524_config_t *config);

/*!
 * @brief Configure WM8524 audio protocol.
 *
 * @param handle WM8524 handle structure.
 * @param protocol WM8524 configuration structure.
 */
void WM8524_ConfigFormat(wm8524_handle_t *handle, wm8524_protocol_t protocol);

/*!
 * @brief Sets the codec mute state.
 *
 * @param handle WM8524 handle structure.
 * @param isMute true means mute, false means normal.
 */
void WM8524_SetMute(wm8524_handle_t *handle, bool isMute);
#if defined(__cplusplus)
}
#endif

/*! @} */
#endif /* _FSL_WM8524_H_ */
