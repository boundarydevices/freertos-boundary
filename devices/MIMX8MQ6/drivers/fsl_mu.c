/*
 * The Clear BSD License
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
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

#include "fsl_mu.h"

/*******************************************************************************
 * Variables
 ******************************************************************************/
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to mu clocks for each instance. */
static const clock_ip_name_t s_muClocks[] = MU_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
/*! @brief Pointers to mu bases for each instance. */
static MU_Type *const s_muBases[] = MU_BASE_PTRS;

/******************************************************************************
 * Code
 *****************************************************************************/
static uint32_t MU_GetInstance(MU_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < (sizeof(s_muBases) / sizeof(s_muBases[0])); instance++)
    {
        if (s_muBases[instance] == base)
        {
            break;
        }
    }

    assert(instance < (sizeof(s_muBases) / sizeof(s_muBases[0])));

    return instance;
}

void MU_Init(MU_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    CLOCK_EnableClock(s_muClocks[MU_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

void MU_Deinit(MU_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    CLOCK_DisableClock(s_muClocks[MU_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

void MU_SendMsg(MU_Type *base, uint32_t regIndex, uint32_t msg)
{
    assert(regIndex < MU_TR_COUNT);

    /* Wait TX register to be empty. */
    while (!(base->SR & (kMU_Tx0EmptyFlag >> regIndex)))
    {
    }

    base->TR[regIndex] = msg;
}

uint32_t MU_ReceiveMsg(MU_Type *base, uint32_t regIndex)
{
    assert(regIndex < MU_TR_COUNT);

    /* Wait RX register to be full. */
    while (!(base->SR & (kMU_Rx0FullFlag >> regIndex)))
    {
    }

    return base->RR[regIndex];
}

void MU_SetFlags(MU_Type *base, uint32_t flags)
{
    /* Wait for update finished. */
    while (base->SR & MU_SR_FUP_MASK)
    {
    }

    MU_SetFlagsNonBlocking(base, flags);
}

status_t MU_TriggerInterrupts(MU_Type *base, uint32_t mask)
{
    uint32_t reg = base->CR;

    /* Previous interrupt has been accepted. */
    if (!(reg & mask))
    {
        /* All interrupts have been accepted, trigger now. */
        reg = (reg & ~(MU_CR_GIRn_MASK | MU_CR_NMI_MASK)) | mask;
        base->CR = reg;
        return kStatus_Success;
    }
    else
    {
        return kStatus_Fail;
    }
}

#if !(defined(FSL_FEATURE_MU_NO_RSTH) && FSL_FEATURE_MU_NO_RSTH)
void MU_BootCoreB(MU_Type *base, mu_core_boot_mode_t mode)
{
#if (defined(FSL_FEATURE_MU_HAS_RESET_INT) && FSL_FEATURE_MU_HAS_RESET_INT)
    /* Clean the reset de-assert pending flag. */
    base->SR = MU_SR_RDIP_MASK;
#endif

#if (defined(FSL_FEATURE_MU_HAS_CCR) && FSL_FEATURE_MU_HAS_CCR)
    uint32_t reg = base->CCR;

    reg = (reg & ~(MU_CCR_HR_MASK | MU_CCR_RSTH_MASK | MU_CCR_BOOT_MASK)) | MU_CCR_BOOT(mode);

    base->CCR = reg;
#else
    uint32_t reg = base->CR;

    reg = (reg & ~((MU_CR_GIRn_MASK | MU_CR_NMI_MASK) | MU_CR_HR_MASK | MU_CR_RSTH_MASK | MU_CR_BBOOT_MASK)) |
          MU_CR_BBOOT(mode);

    base->CR = reg;
#endif
}

void MU_BootOtherCore(MU_Type *base, mu_core_boot_mode_t mode)
{
    /*
     * MU_BootOtherCore and MU_BootCoreB are the same, MU_BootCoreB is kept
     * for compatible with older platforms.
     */
    MU_BootCoreB(base, mode);
}
#endif /* FSL_FEATURE_MU_NO_RSTH */

#if !(defined(FSL_FEATURE_MU_NO_HR) && FSL_FEATURE_MU_NO_HR)
#if (defined(FSL_FEATURE_MU_HAS_CCR) && FSL_FEATURE_MU_HAS_CCR)
void MU_HardwareResetOtherCore(MU_Type *base, bool waitReset, bool holdReset, mu_core_boot_mode_t bootMode)
{
#if (defined(FSL_FEATURE_MU_NO_RSTH) && FSL_FEATURE_MU_NO_RSTH)
    /* If MU does not support hold reset, then the parameter must be false. */
    assert(false == holdReset);
#endif
    uint32_t ccr = base->CCR & ~(MU_CCR_HR_MASK | MU_CCR_RSTH_MASK | MU_CCR_BOOT_MASK);

    ccr |= MU_CCR_BOOT(bootMode);

    if (holdReset)
    {
        ccr |= MU_CCR_RSTH_MASK;
    }

    /* Clean the reset assert pending flag. */
    base->SR = (MU_SR_RAIP_MASK | MU_SR_RDIP_MASK);

    /* Set CCR[HR] to trigger hardware reset. */
    base->CCR = ccr | MU_CCR_HR_MASK;

    /* If don't wait the other core enters reset, return directly. */
    if (!waitReset)
    {
        return;
    }

    /* Wait for the other core go to reset. */
    while (!(base->SR & MU_SR_RAIP_MASK))
    {
    }

    if (!holdReset)
    {
        /* Clear CCR[HR]. */
        base->CCR = ccr;

        /* Wait for the other core out of reset. */
        while (!(base->SR & MU_SR_RDIP_MASK))
        {
        }
    }
}
#else /* FSL_FEATURE_MU_HAS_CCR */
void MU_HardwareResetOtherCore(MU_Type *base, bool waitReset, bool holdReset, mu_core_boot_mode_t bootMode)
{
#if (defined(FSL_FEATURE_MU_NO_RSTH) && FSL_FEATURE_MU_NO_RSTH)
    /* If MU does not support hold reset, then the parameter must be false. */
    assert(false == holdReset);
#endif

    uint32_t cr = base->CR & ~(MU_CR_HR_MASK | MU_CR_RSTH_MASK | MU_CR_BOOT_MASK | MU_CR_GIRn_MASK | MU_CR_NMI_MASK);

    cr |= MU_CR_BOOT(bootMode);

    if (holdReset)
    {
        cr |= MU_CR_RSTH_MASK;
    }

#if (defined(FSL_FEATURE_MU_HAS_RESET_INT) && FSL_FEATURE_MU_HAS_RESET_INT)
    /* Clean the reset assert pending flag. */
    base->SR = (MU_SR_RAIP_MASK | MU_SR_RDIP_MASK);
#endif

    /* Set CR[HR] to trigger hardware reset. */
    base->CR = cr | MU_CR_HR_MASK;

    /* If don't wait the other core enters reset, return directly. */
    if (!waitReset)
    {
        return;
    }

#if (defined(FSL_FEATURE_MU_HAS_RESET_INT) && FSL_FEATURE_MU_HAS_RESET_INT)
    /* Wait for the other core go to reset. */
    while (!(base->SR & MU_SR_RAIP_MASK))
    {
    }
#endif

    if (!holdReset)
    {
        /* Clear CR[HR]. */
        base->CR = cr;

#if (defined(FSL_FEATURE_MU_HAS_RESET_INT) && FSL_FEATURE_MU_HAS_RESET_INT)
        /* Wait for the other core out of reset. */
        while (!(base->SR & MU_SR_RDIP_MASK))
        {
        }
#endif
    }
}
#endif /* FSL_FEATURE_MU_HAS_CCR  */
#endif /* FSL_FEATURE_MU_NO_HR */
