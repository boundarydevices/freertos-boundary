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

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string.h>
#include <assert.h>
#include "device_imx.h"
#include "lmem.h"
#include "sema4.h"
#include "shared_clock_manage.h"
#include "shared_clock_node.h"
#include "board.h"

/*******************************************************************************
 * Type definitions
 ******************************************************************************/
typedef struct _shared_clk_node {
    uint32_t reserve[4];
    uint8_t a9_enable;
    uint8_t m4_enable;
} shared_clk_node_t;

typedef struct _shared_clk_memeory {
    uint32_t a9_ready_magic;
    uint32_t m4_ready_magic;
    shared_clk_node_t shared_node[SHARED_CLK_COUNT];
} shared_clk_memeory_t;

typedef struct _shared_clk_status {
    shared_clk_memeory_t *shareMemPtr;
    SEMA4_Type           *sema4Base;
    uint8_t               sema4Num;
    uint32_t              priMaskBackup;
} shared_clk_status_t;

/*******************************************************************************
 *  Private variable
 ******************************************************************************/
static shared_clk_status_t sharedClkStatus;

/*******************************************************************************
 * Code
 ******************************************************************************/
void SharedClk_Init(shared_clk_init_config_t *initConfig)
{
    uint8_t i;

    sharedClkStatus.shareMemPtr =
            (shared_clk_memeory_t *)initConfig->shareMemStartAddress;
    sharedClkStatus.sema4Base = initConfig->sema4BaseAddress;
    sharedClkStatus.sema4Num = initConfig->sema4Num;

    /* Lock share memory */
    SharedClk_AcquireLock();

    /* Initialize Clock Share Memory */
    for (i = 0; i < SHARED_CLK_COUNT; i++)
    {
        /* Mark all shared clock as unused. */
        sharedClkStatus.shareMemPtr->shared_node[i].m4_enable = 0x0;
    }

    /* Fill M4 Magic to indicate M4 side Shared Clock mechanism start. */
    sharedClkStatus.shareMemPtr->m4_ready_magic = SHAREMEM_READY_MAGIC;

    LMEM_FlushSystemCacheLines(LMEM, (void *)(sharedClkStatus.shareMemPtr),
                               sizeof(shared_clk_memeory_t));

    /* Unlock share memory */
    SharedClk_ReleaseLock();
}

void SharedClk_AcquireLock(void)
{
    sharedClkStatus.priMaskBackup = __get_PRIMASK();

    /* Set PRIMASK to avoid execution of any enabled ISR. */
    __set_PRIMASK(1);

    /* polling until A9 Core release Core Semaphore. */
    while (statusSema4Success != SEMA4_TryLock(sharedClkStatus.sema4Base,
                                               sharedClkStatus.sema4Num));
}

void SharedClk_ReleaseLock(void)
{
    /* Unlock Core Semaphore. */
    SEMA4_Unlock(sharedClkStatus.sema4Base, sharedClkStatus.sema4Num);

    /* Recover PRIMASK register value. */
    __set_PRIMASK(sharedClkStatus.priMaskBackup);
}

/* Need lock */
void SharedClk_EnabeNode(uint32_t shareNodeIndex)
{
    assert(shareNodeIndex < SHARED_CLK_COUNT);

    /* Enable shared clock node. */
    sharedClkStatus.shareMemPtr->shared_node[shareNodeIndex].m4_enable = 0x1;

    LMEM_FlushSystemCacheLines(LMEM, (void *)sharedClkStatus.shareMemPtr,
                               sizeof(shared_clk_memeory_t));
}

/* Need lock */
void SharedClk_DisableNode(uint32_t shareNodeIndex)
{
    assert(shareNodeIndex < SHARED_CLK_COUNT);

    /* Disable shared clock node. */
    sharedClkStatus.shareMemPtr->shared_node[shareNodeIndex].m4_enable = 0x0;

    LMEM_FlushSystemCacheLines(LMEM, (void *)sharedClkStatus.shareMemPtr,
                               sizeof(shared_clk_memeory_t));
}

bool SharedClk_GetPeerNodeStatus(uint32_t shareNodeIndex)
{
    uint8_t result;
    assert(shareNodeIndex < SHARED_CLK_COUNT);

    LMEM_InvalidateSystemCacheLines(LMEM, (void *)sharedClkStatus.shareMemPtr,
                                    sizeof(shared_clk_memeory_t));

    SharedClk_AcquireLock();

    result = sharedClkStatus.shareMemPtr->shared_node[shareNodeIndex].a9_enable;

    SharedClk_ReleaseLock();

    if (0x0 != result)
        return true;
    else
        return false;
}

uint32_t SharedClock_GetPeerMagic(void)
{
    uint32_t result;

    LMEM_InvalidateSystemCacheLines(LMEM, (void *)sharedClkStatus.shareMemPtr,
                                    sizeof(shared_clk_memeory_t));

    SharedClk_AcquireLock();

    /* Get A9 side magic word. */
    result = sharedClkStatus.shareMemPtr->a9_ready_magic;

    SharedClk_ReleaseLock();

    return result;
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
