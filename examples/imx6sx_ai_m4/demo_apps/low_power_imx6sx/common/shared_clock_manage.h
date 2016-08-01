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

#ifndef __CLOCK_SHARE_MANAGE_H__
#define __CLOCK_SHARE_MANAGE_H__

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "device_imx.h"
#include "shared_clock_node.h"

/*******************************************************************************
 * Type definitions
 ******************************************************************************/
typedef struct _shared_clk_init_config {
    uint32_t    shareMemStartAddress;
    SEMA4_Type *sema4BaseAddress;
    uint8_t     sema4Num;
} shared_clk_init_config_t;

/*******************************************************************************
 * Constants
 ******************************************************************************/
#define SHAREMEM_READY_MAGIC    0x12345678

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

void SharedClk_Init(shared_clk_init_config_t *initConfig);
void SharedClk_AcquireLock(void);
void SharedClk_ReleaseLock(void);
void SharedClk_EnabeNode(uint32_t shareNodeIndex);
void SharedClk_DisableNode(uint32_t shareNodeIndex);
bool SharedClk_GetPeerNodeStatus(uint32_t shareNodeIndex);
uint32_t SharedClock_GetPeerMagic(void);
static inline bool SharedClk_GetPeerReady(void)
{
    return (SHAREMEM_READY_MAGIC == SharedClock_GetPeerMagic()) ? true : false;
}

#if defined(__cplusplus)
}
#endif

#endif /* __CLOCK_SHARE_MANAGE_H__ */
/*******************************************************************************
 * EOF
 ******************************************************************************/
