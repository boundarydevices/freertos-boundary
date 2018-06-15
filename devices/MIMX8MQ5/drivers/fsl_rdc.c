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

#include "fsl_rdc.h"

/******************************************************************************
 * Definitions
 *****************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!
 * @brief Get instance number for RDC module.
 *
 * @param base RDC peripheral base address.
 */
uint32_t RDC_GetInstance(RDC_Type *base);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*! @brief Pointers to rdc bases for each instance. */
static RDC_Type *const s_rdcBases[] = RDC_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to rdc clocks for each instance. */
static const clock_ip_name_t s_rdcClocks[] = RDC_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/******************************************************************************
 * CODE
 *****************************************************************************/

uint32_t RDC_GetInstance(RDC_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_rdcBases); instance++)
    {
        if (s_rdcBases[instance] == base)
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_rdcBases));

    return instance;
}

void RDC_Init(RDC_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    CLOCK_EnableClock(s_rdcClocks[RDC_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

void RDC_Deinit(RDC_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    CLOCK_DisableClock(s_rdcClocks[RDC_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

void RDC_SetPeriphAccessConfig(RDC_Type *base, const rdc_periph_access_config_t *config)
{
    assert(config->periph < RDC_PDAP_COUNT);

    uint32_t periph = config->periph;
    uint32_t regPDAP = config->policy;

    if (config->lock)
    {
        regPDAP |= RDC_PDAP_LCK_MASK;
    }

    if (config->enableSema)
    {
        regPDAP |= RDC_PDAP_SREQ_MASK;
    }

    base->PDAP[periph] = regPDAP;
}

void RDC_GetDefaultPeriphAccessConfig(rdc_periph_access_config_t *config)
{
    assert(config);

    config->lock = false;
    config->enableSema = false;
    config->policy = RDC_ACCESS_POLICY(0, kRDC_ReadWrite) | RDC_ACCESS_POLICY(1, kRDC_ReadWrite) |
                     RDC_ACCESS_POLICY(2, kRDC_ReadWrite) | RDC_ACCESS_POLICY(3, kRDC_ReadWrite);
}

void RDC_SetMemAccessConfig(RDC_Type *base, const rdc_mem_access_config_t *config)
{
    assert(config->mem < RDC_MRC_COUNT);

    uint32_t mem = config->mem;
    /* The configuration is enabled by default. */
    uint32_t regMRC = config->policy | RDC_MRC_ENA_MASK;

    if (config->lock)
    {
        regMRC |= RDC_MRC_LCK_MASK;
    }

    base->MR[mem].MRSA = config->baseAddress;
    base->MR[mem].MREA = config->endAddress;
    base->MR[mem].MRC = regMRC;
}

void RDC_GetDefaultMemAccessConfig(rdc_mem_access_config_t *config)
{
    assert(config);

    config->lock = false;
    config->baseAddress = 0;
    config->endAddress = 0;
    config->policy = RDC_ACCESS_POLICY(0, kRDC_ReadWrite) | RDC_ACCESS_POLICY(1, kRDC_ReadWrite) |
                     RDC_ACCESS_POLICY(2, kRDC_ReadWrite) | RDC_ACCESS_POLICY(3, kRDC_ReadWrite);
}

void RDC_GetMemViolationStatus(RDC_Type *base, rdc_mem_t mem, rdc_mem_status_t *status)
{
    assert(mem < RDC_MRC_COUNT);

    uint32_t regMRVS = base->MR[mem].MRVS;

    status->hasViolation = (regMRVS & RDC_MRVS_AD_MASK);
    status->domainID = (regMRVS & RDC_MRVS_VDID_MASK) >> RDC_MRVS_VDID_SHIFT;
    status->address = (regMRVS & RDC_MRVS_VADR_MASK);
}
