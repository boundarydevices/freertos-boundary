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

#ifndef __LPM_MCORE_H__
#define __LPM_MCORE_H__

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdint.h>

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define STATUS_NORMAL_RUN          (0)
#define STATUS_LOWPOWER_RUN        (1)

#define WAKEUP_ENABLE              (1)
#define WAKEUP_DISABLE             (0)
#define WAKEUP_REGISTER_SUCCESS    (1)
#define WAKEUP_REGISTER_FAILURE    (0)

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*
 * mcore lpm init API
 */
void LPM_MCORE_Init(void);

/*
 * mcore lpm API to get current power status
 */
uint32_t LPM_MCORE_GetPowerStatus(void);

/*
 * mcore lpm API to set power status
 */
void LPM_MCORE_SetPowerStatus(uint32_t powerStatus);

/*
 * mcore lpm API to register peer wakeup interrupt
 */
uint32_t LPM_MCORE_RegisterPeerWakeup(uint32_t int_no, uint32_t enable);

/*
 * mcore lpm API to enter TCM WFI
 */
void LPM_MCORE_WaitForInt(void);

#if defined(__cplusplus)
}
#endif

#endif /* __LPM_MCORE_H__ */
/*******************************************************************************
 * EOF
 ******************************************************************************/
