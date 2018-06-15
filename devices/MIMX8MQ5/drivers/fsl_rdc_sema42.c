/*
 * The Clear BSD License
 * Copyright 2017 NXP
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted (subject to the limitations in the disclaimer below) provided
 *  that the following conditions are met:
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

#include "fsl_rdc_sema42.h"

/******************************************************************************
 * Definitions
 *****************************************************************************/
/* The first number write to RSTGDP when reset RDC_SEMA42 gate. */
#define RDC_SEMA42_GATE_RESET_PATTERN_1 (0xE2U)
/* The second number write to RSTGDP when reset RDC_SEMA42 gate. */
#define RDC_SEMA42_GATE_RESET_PATTERN_2 (0x1DU)

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!
 * @brief Get instance number for RDC_SEMA42 module.
 *
 * @param base RDC_SEMA42 peripheral base address.
 */
uint32_t RDC_SEMA42_GetInstance(RDC_SEMAPHORE_Type *base);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*! @brief Pointers to sema42 bases for each instance. */
static RDC_SEMAPHORE_Type *const s_sema42Bases[] = RDC_SEMAPHORE_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to sema42 clocks for each instance. */
static const clock_ip_name_t s_sema42Clocks[] = RDC_SEMA42_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/******************************************************************************
 * CODE
 *****************************************************************************/

uint32_t RDC_SEMA42_GetInstance(RDC_SEMAPHORE_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_sema42Bases); instance++)
    {
        if (s_sema42Bases[instance] == base)
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_sema42Bases));

    return instance;
}

void RDC_SEMA42_Init(RDC_SEMAPHORE_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    CLOCK_EnableClock(s_sema42Clocks[RDC_SEMA42_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

void RDC_SEMA42_Deinit(RDC_SEMAPHORE_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    CLOCK_DisableClock(s_sema42Clocks[RDC_SEMA42_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

status_t RDC_SEMA42_TryLock(RDC_SEMAPHORE_Type *base, uint8_t gateNum, uint8_t masterIndex, uint8_t domainId)
{
    assert(gateNum < RDC_SEMA42_GATE_COUNT);

    status_t status = kStatus_Success;
    uint8_t regGate;

    ++masterIndex;

    regGate = RDC_SEMAPHORE_GATE0_LDOM(domainId) | RDC_SEMAPHORE_GATE0_GTFSM(masterIndex);

    /* Try to lock. */
    RDC_SEMA42_GATEn(base, gateNum) = masterIndex;

    /* Check locked or not. */
    if (regGate != RDC_SEMA42_GATEn(base, gateNum))
    {
        status = kStatus_Fail;
    }

    return status;
}

void RDC_SEMA42_Lock(RDC_SEMAPHORE_Type *base, uint8_t gateNum, uint8_t masterIndex, uint8_t domainId)
{
    assert(gateNum < RDC_SEMA42_GATE_COUNT);

    uint8_t regGate;

    ++masterIndex;

    regGate = RDC_SEMAPHORE_GATE0_LDOM(domainId) | RDC_SEMAPHORE_GATE0_GTFSM(masterIndex);

    while (regGate != RDC_SEMA42_GATEn(base, gateNum))
    {
        /* Wait for unlocked status. */
        while (0 != (RDC_SEMA42_GATEn(base, gateNum) & RDC_SEMAPHORE_GATE0_GTFSM_MASK))
        {
        }

        /* Lock the gate. */
        RDC_SEMA42_GATEn(base, gateNum) = masterIndex;
    }
}

int32_t RDC_SEMA42_GetLockDomainID(RDC_SEMAPHORE_Type *base, uint8_t gateNum)
{
    assert(gateNum < RDC_SEMA42_GATE_COUNT);

    uint8_t regGate = RDC_SEMA42_GATEn(base, gateNum);

    /* Current gate is not locked. */
    if (0U == (regGate & RDC_SEMAPHORE_GATE0_GTFSM_MASK))
    {
        return -1;
    }
    else
    {
        return (int32_t)(((uint32_t)regGate & RDC_SEMAPHORE_GATE0_LDOM_MASK) >> RDC_SEMAPHORE_GATE0_LDOM_SHIFT);
    }
}

status_t RDC_SEMA42_ResetGate(RDC_SEMAPHORE_Type *base, uint8_t gateNum)
{
    status_t status;

    /*
     * Reset all gates if gateNum >= RDC_SEMA42_GATE_NUM_RESET_ALL
     * Reset specific gate if gateNum < RDC_SEMA42_GATE_COUNT
     */
    assert(!((gateNum < RDC_SEMA42_GATE_NUM_RESET_ALL) && (gateNum >= RDC_SEMA42_GATE_COUNT)));

    /* Check whether some reset is ongoing. */
    if (base->RSTGT_R & RDC_SEMAPHORE_RSTGT_R_RSTGSM_MASK)
    {
        status = kStatus_Fail;
    }
    else
    {
        /* First step. */
        base->RSTGT_W = RDC_SEMAPHORE_RSTGT_W_RSTGDP(RDC_SEMA42_GATE_RESET_PATTERN_1);
        /* Second step. */
        base->RSTGT_W =
            RDC_SEMAPHORE_RSTGT_W_RSTGDP(RDC_SEMA42_GATE_RESET_PATTERN_2) | RDC_SEMAPHORE_RSTGT_W_RSTGTN(gateNum);

        status = kStatus_Success;
    }

    return status;
}
