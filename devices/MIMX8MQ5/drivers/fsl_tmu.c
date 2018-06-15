/*
 * The Clear BSD License
 * Copyright (c) 2017, NXP
 * All rights reserved.
 *
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
 * o Neither the name of copyright holder nor the names of its
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
#include "fsl_tmu.h"

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Get instance number for TMU module.
 *
 * @param base TMU peripheral base address
 */
static uint32_t TMU_GetInstance(TMU_Type *base);

/*!
* @brief Programming the sensor translation table.
*
* @param base TMU peripheral base address.
*/
static void TMU_SetTranslationTable(TMU_Type *base);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to TMU bases for each instance. */
static TMU_Type *const s_tmuBases[] = TMU_BASE_PTRS;

/*! @brief Pointers to TMU clocks for each instance. */
static const clock_ip_name_t s_tmuClocks[] = TMU_CLOCKS;

/*******************************************************************************
 * Code
 ******************************************************************************/
static uint32_t TMU_GetInstance(TMU_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_tmuBases); instance++)
    {
        if (s_tmuBases[instance] == base)
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_tmuBases));

    return instance;
}

static void TMU_SetTranslationTable(TMU_Type *base)
{
    /*  programming the sensor translation table. */
    base->TTRCR[0] = TMU_TTRCR_TEMP(0U) | TMU_TTRCR_CAL_PTS(11U);  /* Range0. */
    base->TTRCR[1] = TMU_TTRCR_TEMP(44U) | TMU_TTRCR_CAL_PTS(9U);  /* Range1. */
    base->TTRCR[2] = TMU_TTRCR_TEMP(78U) | TMU_TTRCR_CAL_PTS(6U);  /* Range2. */
    base->TTRCR[3] = TMU_TTRCR_TEMP(102U) | TMU_TTRCR_CAL_PTS(3U); /* Range3. */
    /* For range0. */
    base->TTCFGR = 0x00000000U;
    base->TSCFGR = 0x00000020U;
    base->TTCFGR = 0x00000001U;
    base->TSCFGR = 0x00000024U;
    base->TTCFGR = 0x00000002U;
    base->TSCFGR = 0x0000002AU;
    base->TTCFGR = 0x00000003U;
    base->TSCFGR = 0x00000032U;
    base->TTCFGR = 0x00000004U;
    base->TSCFGR = 0x00000038U;
    base->TTCFGR = 0x00000005U;
    base->TSCFGR = 0x0000003EU;
    base->TTCFGR = 0x00000006U;
    base->TSCFGR = 0x00000043U;
    base->TTCFGR = 0x00000007U;
    base->TSCFGR = 0x0000004AU;
    base->TTCFGR = 0x00000008U;
    base->TSCFGR = 0x00000050U;
    base->TTCFGR = 0x00000009U;
    base->TSCFGR = 0x00000059U;
    base->TTCFGR = 0x0000000AU;
    base->TSCFGR = 0x0000005FU;
    base->TTCFGR = 0x0000000BU;
    base->TSCFGR = 0x00000066U;
    /* For range1. */
    base->TTCFGR = 0x00010000U;
    base->TSCFGR = 0x00000023U;
    base->TTCFGR = 0x00010001U;
    base->TSCFGR = 0x0000002BU;
    base->TTCFGR = 0x00010002U;
    base->TSCFGR = 0x00000033U;
    base->TTCFGR = 0x00010003U;
    base->TSCFGR = 0x0000003AU;
    base->TTCFGR = 0x00010004U;
    base->TSCFGR = 0x00000042U;
    base->TTCFGR = 0x00010005U;
    base->TSCFGR = 0x0000004AU;
    base->TTCFGR = 0x00010006U;
    base->TSCFGR = 0x00000054U;
    base->TTCFGR = 0x00010007U;
    base->TSCFGR = 0x0000005CU;
    base->TTCFGR = 0x00010008U;
    base->TSCFGR = 0x00000065U;
    base->TTCFGR = 0x00010009U;
    base->TSCFGR = 0x0000006FU;
    /* For range2. */
    base->TTCFGR = 0x00020000U;
    base->TSCFGR = 0x00000029U;
    base->TTCFGR = 0x00020001U;
    base->TSCFGR = 0x00000033U;
    base->TTCFGR = 0x00020002U;
    base->TSCFGR = 0x0000003DU;
    base->TTCFGR = 0x00020003U;
    base->TSCFGR = 0x00000048U;
    base->TTCFGR = 0x00020004U;
    base->TSCFGR = 0x00000054U;
    base->TTCFGR = 0x00020005U;
    base->TSCFGR = 0x00000060U;
    base->TTCFGR = 0x00020006U;
    base->TSCFGR = 0x0000006CU;
    /* For range3. */
    base->TTCFGR = 0x00030000U;
    base->TSCFGR = 0x00000025U;
    base->TTCFGR = 0x00030001U;
    base->TSCFGR = 0x00000033U;
    base->TTCFGR = 0x00030002U;
    base->TSCFGR = 0x00000043U;
    base->TTCFGR = 0x00030003U;
    base->TSCFGR = 0x00000055U;
}
void TMU_Init(TMU_Type *base, const tmu_config_t *config)
{
    assert(NULL != base);
    assert(NULL != config);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable TMU clock. */
    CLOCK_EnableClock(s_tmuClocks[TMU_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL. */

    /* Disable TMU monitor mode. */
    TMU_Enable(base, false);

    /* Set the sensor translation table. */
    TMU_SetTranslationTable(base);

    /* Clear interrupt relevant register. */
    TMU_ClearInterruptStatusFlags(base, kTMU_ImmediateTemperatureStatusFlags | kTMU_AverageTemperatureStatusFlags |
                                            kTMU_AverageTemperatureCriticalStatusFlags);

    /* Configure TMR register. */
    base->TMR = TMU_TMR_ALPF(config->averageLPF) | TMU_TMR_MSITE(config->monitorSiteSelection);

    /* Configure the time interval. */
    base->TMTMIR = TMU_TMTMIR_TMI(config->monitorInterval);
}

void TMU_Deinit(TMU_Type *base)
{
    /* Disable TMU monitor mode.. */
    TMU_Enable(base, false);
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable TMU clock. */
    CLOCK_DisableClock(s_tmuClocks[TMU_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL. */
}

void TMU_GetDefaultConfig(tmu_config_t *config)
{
    assert(NULL != config);

    config->monitorInterval = 0U;
    config->monitorSiteSelection = 0U; /* If no site is selected, site 0 is monitored by default. */
    config->averageLPF = kTMU_AverageLowPassFilter1_0;
}

void TMU_GetInterruptStatusFlags(TMU_Type *base, tmu_interrupt_status_t *status)
{
    assert(NULL != status);

    status->interruptDetectMask = base->TIDR;
    status->immediateInterruptsSiteMask = (TMU_TISCR_ISITE_MASK & base->TISCR) >> TMU_TISCR_ISITE_SHIFT;
    status->AverageInterruptsSiteMask = (TMU_TISCR_ASITE_MASK & base->TISCR) >> TMU_TISCR_ASITE_SHIFT;
    status->AverageCriticalInterruptsSiteMask = (TMU_TICSCR_CASITE_MASK & base->TICSCR) >> TMU_TICSCR_CASITE_SHIFT;
}

void TMU_ClearInterruptStatusFlags(TMU_Type *base, uint32_t mask)
{
    /* For immediate temperature threshold interrupt. */
    if (0U != (kTMU_ImmediateTemperatureStatusFlags & mask))
    {
        base->TIDR = TMU_TIDR_ITTE_MASK;      /* Clear interrupt detect register. */
        base->TISCR &= ~TMU_TISCR_ISITE_MASK; /* Clear interrupt site capture register. */
    }
    /* For average temperature threshold interrupt. */
    if (0U != (kTMU_AverageTemperatureStatusFlags & mask))
    {
        base->TIDR = TMU_TIDR_ATTE_MASK;      /* Clear interrupt detect register. */
        base->TISCR &= ~TMU_TISCR_ASITE_MASK; /* Clear interrupt site capture register. */
    }
    /* For Average temperature critical threshold interrupt. */
    if (0U != (kTMU_AverageTemperatureCriticalStatusFlags & mask))
    {
        base->TIDR = TMU_TIDR_ATCTE_MASK;        /* Clear interrupt detect register. */
        base->TICSCR &= ~TMU_TICSCR_CASITE_MASK; /* Clear interrupt critical site capture register. */
    }
}

status_t TMU_GetHighestTemperature(TMU_Type *base, uint32_t *temperature)
{
    assert(NULL != temperature);

    if (0U == (TMU_TMHTCRH_V_MASK & base->TMHTCRH))
    {
        return kStatus_Fail;
    }
    else
    {
        *temperature = (TMU_TMHTCRH_TEMP_MASK & base->TMHTCRH) >> TMU_TMHTCRH_TEMP_SHIFT;
        return kStatus_Success;
    }
}

status_t TMU_GetLowestTemperature(TMU_Type *base, uint32_t *temperature)
{
    assert(NULL != temperature);

    if (0U == (TMU_TMHTCRL_V_MASK & base->TMHTCRL))
    {
        return kStatus_Fail;
    }
    else
    {
        *temperature = (TMU_TMHTCRL_TEMP_MASK & base->TMHTCRL) >> TMU_TMHTCRL_TEMP_SHIFT;
        return kStatus_Success;
    }
}

status_t TMU_GetImmediateTemperature(TMU_Type *base, uint32_t siteIndex, uint32_t *temperature)
{
    assert(NULL != temperature);
    assert(siteIndex < TMU_TRITSR_COUNT);

    if (0U == (TMU_TRITSR_V_MASK & base->TRTSR[siteIndex].TRITSR))
    {
        return kStatus_Fail;
    }
    else
    {
        *temperature = (TMU_TRITSR_TEMP_MASK & base->TRTSR[siteIndex].TRITSR) >> TMU_TRITSR_TEMP_SHIFT;
        return kStatus_Success;
    }
}

status_t TMU_GetAverageTemperature(TMU_Type *base, uint32_t siteIndex, uint32_t *temperature)
{
    assert(NULL != temperature);
    assert(siteIndex < TMU_TRATSR_COUNT);

    if (0U == (TMU_TRATSR_V_MASK & base->TRTSR[siteIndex].TRATSR))
    {
        return kStatus_Fail;
    }
    else
    {
        *temperature = (TMU_TRATSR_TEMP_MASK & base->TRTSR[siteIndex].TRATSR) >> TMU_TRATSR_TEMP_SHIFT;
        return kStatus_Success;
    }
}

void TMU_SetHighTemperatureThresold(TMU_Type *base, const tmu_thresold_config_t *config)
{
    assert(NULL != config);

    /* Configure the high temperature immediate threshold. */
    if (config->immediateThresoldEnable)
    {
        base->TMHTITR = TMU_TMHTITR_EN_MASK | TMU_TMHTITR_TEMP(config->immediateThresoldValue);
    }
    else
    {
        base->TMHTITR = 0U;
    }
    /* Configure the high temperature average threshold. */
    if (config->AverageThresoldEnable)
    {
        base->TMHTATR = TMU_TMHTATR_EN_MASK | TMU_TMHTATR_TEMP(config->averageThresoldValue);
    }
    else
    {
        base->TMHTATR = 0U;
    }
    /* Configure the high temperature average critical thresold. */
    if (config->AverageCriticalThresoldEnable)
    {
        base->TMHTACTR = TMU_TMHTACTR_EN_MASK | TMU_TMHTACTR_TEMP(config->averageCriticalThresoldValue);
    }
    else
    {
        base->TMHTACTR = 0U;
    }
}
