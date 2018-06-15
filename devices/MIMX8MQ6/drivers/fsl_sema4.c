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

#include "fsl_sema4.h"

/******************************************************************************
 * Definitions
 *****************************************************************************/
/* The first number write to RSTGDP when reset SEMA4 gate. */
#define SEMA4_GATE_RESET_PATTERN_1 (0xE2U)
/* The second number write to RSTGDP when reset SEMA4 gate. */
#define SEMA4_GATE_RESET_PATTERN_2 (0x1DU)

/* The first number write to RSTGDP when reset SEMA4 gate IRQ notification. */
#define SEMA4_GATE_IRQ_RESET_PATTERN_1 (0x47U)
/* The second number write to RSTGDP when reset SEMA4 gate IRQ notification. */
#define SEMA4_GATE_IRQ_RESET_PATTERN_2 (0xB8U)

#define SEMA4_RSTGT_RSTNSM_MASK (0x30U)

#define SEMA4_RSTNTF_RSTNSM_MASK (0x30U)

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

#if defined(SEMA4_CLOCKS)
/*!
 * @brief Get instance number for SEMA4 module.
 *
 * @param base SEMA4 peripheral base address.
 */
uint32_t SEMA4_GetInstance(SEMA4_Type *base);
#endif

/*******************************************************************************
 * Variables
 ******************************************************************************/

#if defined(SEMA4_CLOCKS)
/*! @brief Pointers to sema4 bases for each instance. */
static SEMA4_Type *const s_sema4Bases[] = SEMA4_BASE_PTRS;
#endif

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
#if defined(SEMA4_CLOCKS)
/*! @brief Pointers to sema4 clocks for each instance. */
static const clock_ip_name_t s_sema4Clocks[] = SEMA4_CLOCKS;
#endif
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/******************************************************************************
 * CODE
 *****************************************************************************/

#if defined(SEMA4_CLOCKS)
uint32_t SEMA4_GetInstance(SEMA4_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_sema4Bases); instance++)
    {
        if (s_sema4Bases[instance] == base)
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_sema4Bases));

    return instance;
}
#endif

void SEMA4_Init(SEMA4_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
#if defined(SEMA4_CLOCKS)
    CLOCK_EnableClock(s_sema4Clocks[SEMA4_GetInstance(base)]);
#endif
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

void SEMA4_Deinit(SEMA4_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
#if defined(SEMA4_CLOCKS)
    CLOCK_DisableClock(s_sema4Clocks[SEMA4_GetInstance(base)]);
#endif
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

status_t SEMA4_TryLock(SEMA4_Type *base, uint8_t gateNum, uint8_t procNum)
{
    assert(gateNum < FSL_FEATURE_SEMA4_GATE_COUNT);

    ++procNum;

    /* Try to lock. */
    SEMA4_GATEn(base, gateNum) = procNum;

    /* Check locked or not. */
    if (procNum != SEMA4_GATEn(base, gateNum))
    {
        return kStatus_Fail;
    }

    return kStatus_Success;
}

void SEMA4_Lock(SEMA4_Type *base, uint8_t gateNum, uint8_t procNum)
{
    assert(gateNum < FSL_FEATURE_SEMA4_GATE_COUNT);

    ++procNum;

    while (procNum != SEMA4_GATEn(base, gateNum))
    {
        /* Wait for unlocked status. */
        while (SEMA4_GATEn(base, gateNum))
        {
        }

        /* Lock the gate. */
        SEMA4_GATEn(base, gateNum) = procNum;
    }
}

status_t SEMA4_ResetGate(SEMA4_Type *base, uint8_t gateNum)
{
    /*
     * Reset all gates if gateNum >= SEMA4_GATE_NUM_RESET_ALL
     * Reset specific gate if gateNum < FSL_FEATURE_SEMA4_GATE_COUNT
     */
    assert(!((gateNum < SEMA4_GATE_NUM_RESET_ALL) && (gateNum >= FSL_FEATURE_SEMA4_GATE_COUNT)));

    /* Check whether some reset is ongoing. */
    if (base->RSTGT & SEMA4_RSTGT_RSTNSM_MASK)
    {
        return kStatus_Fail;
    }

    /* First step. */
    base->RSTGT = SEMA4_RSTGT_RSTGSM_RSTGMS_RSTGDP(SEMA4_GATE_RESET_PATTERN_1);
    /* Second step. */
    base->RSTGT = SEMA4_RSTGT_RSTGSM_RSTGMS_RSTGDP(SEMA4_GATE_RESET_PATTERN_2) | SEMA4_RSTGT_RSTGTN(gateNum);

    return kStatus_Success;
}

status_t SEMA4_ResetGateNotify(SEMA4_Type *base, uint8_t gateNum)
{
    /*
     * Reset all gates if gateNum >= SEMA4_GATE_NUM_RESET_ALL
     * Reset specific gate if gateNum < FSL_FEATURE_SEMA4_GATE_COUNT
     */
    assert(!((gateNum < SEMA4_GATE_NUM_RESET_ALL) && (gateNum >= FSL_FEATURE_SEMA4_GATE_COUNT)));

    /* Check whether some reset is ongoing. */
    if (base->RSTNTF & SEMA4_RSTNTF_RSTNSM_MASK)
    {
        return kStatus_Fail;
    }

    /* First step. */
    base->RSTNTF = SEMA4_RSTNTF_RSTNSM_RSTNMS_RSTNDP(SEMA4_GATE_IRQ_RESET_PATTERN_1);
    /* Second step. */
    base->RSTNTF = SEMA4_RSTNTF_RSTNSM_RSTNMS_RSTNDP(SEMA4_GATE_IRQ_RESET_PATTERN_2) | SEMA4_RSTNTF_RSTNTN(gateNum);

    return kStatus_Success;
}
