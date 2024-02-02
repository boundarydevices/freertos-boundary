/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: TEE v4.0
processor: MIMX8UD7xxx08
package_id: MIMX8UD7DVP08
mcu_data: ksdk2_0
processor_version: 0.12.3
toolOptions:
  _legacy_source_names_: 'no'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/
#include "fsl_common.h"
#include "tzm_config.h"
#include "fsl_debug_console.h"
#include "fsl_trdc.h"
#include "board.h"
#include "fsl_sentinel.h"

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * BOARD_InitTrustZone function
 **********************************************************************************************************************/
void App_SetTrdcMBCNSE(uint8_t mbcIdx, uint8_t slvIdx, uint8_t mbIdx, uint32_t nse)
{
    trdc_mbc_memory_block_config_t mbcBlockConfig;

    (void)memset(&mbcBlockConfig, 0, sizeof(mbcBlockConfig));
    mbcBlockConfig.memoryAccessControlSelect = EXAMPLE_TRDC_MBC_ACCESS_CONTROL_POLICY_ALL_INDEX;
    mbcBlockConfig.mbcIdx                    = mbcIdx;
    mbcBlockConfig.domainIdx                 = TRDC_GetCurrentMasterDomainId(TRDC);
    mbcBlockConfig.slaveMemoryIdx            = slvIdx;
    mbcBlockConfig.nseEnable                 = nse;
    mbcBlockConfig.memoryBlockIdx            = mbIdx;
    TRDC_MbcSetMemoryBlockConfig(TRDC, &mbcBlockConfig);
}

void APP_SetTrdcMRCNSE(uint32_t saddr, uint32_t eaddr, uint8_t mrcIdx)
{
    uint32_t n, m;
    uint32_t mrc_start_addr = 0x4000000;
    uint32_t mrc_end_addr   = 0x4800000;
    trdc_mrc_region_descriptor_config_t mrcRegionConfig;

    (void)memset(&mrcRegionConfig, 0, sizeof(mrcRegionConfig));
    mrcRegionConfig.memoryAccessControlSelect = EXAMPLE_TRDC_MRC_ACCESS_CONTROL_POLICY_ALL_INDEX;
    mrcRegionConfig.valid                     = true;
    mrcRegionConfig.domainIdx                 = TRDC_GetCurrentMasterDomainId(TRDC);
    mrcRegionConfig.mrcIdx                    = mrcIdx;
    /* Get region number for current MRC instance */
    n = TRDC_GetMrcRegionNumber(TRDC, mrcIdx);

    /*__IO uint32_t MRC_DOM0_RGD_W[8][2]; n do not more than 8 (coverity check)*/
    if (n > 8)
    {
        return;
    }

    for (m = 0U; m < n; m++)
    {
        mrcRegionConfig.nseEnable = 0;
        mrcRegionConfig.regionIdx = m;
        mrcRegionConfig.startAddr = mrc_start_addr + (mrc_end_addr - mrc_start_addr) / n * m;
        mrcRegionConfig.endAddr =
            (mrc_start_addr + (mrc_end_addr - mrc_start_addr) / n * (m + 1U) - 4 * 1024) & (~(4 * 1024 - 1));

        if ((mrcRegionConfig.startAddr <= saddr && mrcRegionConfig.endAddr > saddr) ||
            (mrcRegionConfig.startAddr < eaddr && mrcRegionConfig.endAddr >= eaddr) ||
            (mrcRegionConfig.startAddr > saddr && mrcRegionConfig.endAddr < eaddr))
        {
            mrcRegionConfig.nseEnable = 1;
        }

        TRDC_MrcSetRegionDescriptorConfig(TRDC, &mrcRegionConfig);
    }
}
void APP_PrintTrdcErr(void)
{
    trdc_domain_error_t error;

    if (kStatus_Success == TRDC_GetAndClearFirstDomainError(TRDC, &error))
    {
        if (error.controller == kTRDC_MemRegionChecker0)
        {
            PRINTF("TRDC MRC Violent access \r\n");
        }
        if (error.controller == kTRDC_MemBlockController0)
        {
            PRINTF("TRDC MBC slavemem:%d Violent access \r\n", error.slaveMemoryIdx);
        }
        PRINTF("    domainId        : %d\r\n", error.domainId);
        PRINTF("    Address         : 0x%08X\r\n", error.address);
        PRINTF("    Error state     : %d\r\n", error.errorState);
        PRINTF("    Error attribute : %d\r\n", error.errorAttr);
        PRINTF("    Error type      : %d\r\n", error.errorType);
        PRINTF("    Error port      : %d\r\n", error.errorPort);
    }
}
void TRDC_InitGlobalConfig(void)
{
    uint32_t mrc_start_addr[2] = {0x4000000, 0x40000000};
    uint32_t mrc_end_addr[2]   = {0x4800000, 0x50000000};
    uint32_t i, j, m, n;

    /* Ungate TRDC MRC, MBC and DAC PCC */
    TRDC_Init(TRDC);

    /* 1. Get the hardware configuration of the TRDC module */
    trdc_hardware_config_t hwConfig;
    TRDC_GetHardwareConfig(TRDC, &hwConfig);

    /* 2. Set control policies for MRC and MBC access control configuration registers */
    trdc_memory_access_control_config_t memAccessConfig;
    (void)memset(&memAccessConfig, 0, sizeof(memAccessConfig));

    /* Disable all access modes for MBC and MRC access control configuration register 1-7. */
    for (i = 0U; i < hwConfig.mbcNumber; i++)
    {
        for (j = 1U; j < 8U; j++)
        {
            TRDC_MbcSetMemoryAccessConfig(TRDC, &memAccessConfig, i, j);
        }
    }

    for (i = 0U; i < hwConfig.mrcNumber; i++)
    {
        for (j = 1U; j < 8U; j++)
        {
            TRDC_MrcSetMemoryAccessConfig(TRDC, &memAccessConfig, i, j);
        }
    }

    /* Enable all access modes for MRC access control configuration register 0. */
    memAccessConfig.nonsecureUsrX  = 1U;
    memAccessConfig.nonsecureUsrW  = 1U;
    memAccessConfig.nonsecureUsrR  = 1U;
    memAccessConfig.nonsecurePrivX = 1U;
    memAccessConfig.nonsecurePrivW = 1U;
    memAccessConfig.nonsecurePrivR = 1U;
    memAccessConfig.secureUsrX     = 1U;
    memAccessConfig.secureUsrW     = 1U;
    memAccessConfig.secureUsrR     = 1U;
    memAccessConfig.securePrivX    = 1U;
    memAccessConfig.securePrivW    = 1U;
    memAccessConfig.securePrivR    = 1U;

    for (i = 0U; i < hwConfig.mrcNumber; i++)
    {
        TRDC_MrcSetMemoryAccessConfig(TRDC, &memAccessConfig, i, EXAMPLE_TRDC_MRC_ACCESS_CONTROL_POLICY_ALL_INDEX);
    }

    for (i = 0U; i < hwConfig.mbcNumber; i++)
    {
        TRDC_MbcSetMemoryAccessConfig(TRDC, &memAccessConfig, i, EXAMPLE_TRDC_MBC_ACCESS_CONTROL_POLICY_ALL_INDEX);
    }

    /* 3. Set the configuration for all MRC regions */
    trdc_mrc_region_descriptor_config_t mrcRegionConfig;
    (void)memset(&mrcRegionConfig, 0, sizeof(mrcRegionConfig));
    mrcRegionConfig.memoryAccessControlSelect = EXAMPLE_TRDC_MRC_ACCESS_CONTROL_POLICY_ALL_INDEX;
    mrcRegionConfig.valid                     = true;
    mrcRegionConfig.nseEnable                 = false;

    for (i = 0; i < hwConfig.mrcNumber; i++)
    {
        mrcRegionConfig.mrcIdx = i;
        for (j = 0; j < hwConfig.domainNumber; j++)
        {
            mrcRegionConfig.domainIdx = j;
            /* Get region number for current MRC instance */
            n = TRDC_GetMrcRegionNumber(TRDC, i);

            /*__IO uint32_t MRC_DOM0_RGD_W[8][2]; n do not more than 8 (coverity check)*/
            if (n > 8)
            {
                return;
            }

            for (m = 0U; m < n; m++)
            {
                mrcRegionConfig.regionIdx = m;
                mrcRegionConfig.startAddr = mrc_start_addr[i] + (mrc_end_addr[i] - mrc_start_addr[i]) / n * m;
                mrcRegionConfig.endAddr =
                    (mrc_start_addr[i] + (mrc_end_addr[i] - mrc_start_addr[i]) / n * (m + 1U) - 4 * 1024) &
                    (~(4 * 1024 - 1));

                if (mrcRegionConfig.startAddr < SAU_REGION_0_BASE || mrcRegionConfig.endAddr > SAU_REGION_0_END)
                {
                    mrcRegionConfig.nseEnable = false;
                }
                else
                {
                    mrcRegionConfig.nseEnable = true;
                }

                TRDC_MrcSetRegionDescriptorConfig(TRDC, &mrcRegionConfig);
            }
        }
    }

    TRDC_SetMrcGlobalValid(TRDC);

    /* 4. Set the configuration for all MBC slave memory blocks */
    trdc_slave_memory_hardware_config_t mbcHwConfig;
    trdc_mbc_memory_block_config_t mbcBlockConfig;
    (void)memset(&mbcBlockConfig, 0, sizeof(mbcBlockConfig));
    mbcBlockConfig.memoryAccessControlSelect = EXAMPLE_TRDC_MBC_ACCESS_CONTROL_POLICY_ALL_INDEX;
    mbcBlockConfig.nseEnable                 = false;

    for (i = 0U; i < hwConfig.mbcNumber; i++)
    {
        mbcBlockConfig.mbcIdx = i;
        for (j = 0U; j < hwConfig.domainNumber; j++)
        {
            mbcBlockConfig.domainIdx = j;
            for (m = 0U; m < 4; m++)
            {
                TRDC_GetMbcHardwareConfig(TRDC, &mbcHwConfig, i, m);
                if (mbcHwConfig.blockNum == 0U)
                {
                    break;
                }
                mbcBlockConfig.slaveMemoryIdx = m;
                for (n = 0U; n < mbcHwConfig.blockNum; n++)
                {
                    /*tcramu [0x20030000-0x2003FFFF] for non-secure*/
                    if (i == 0 && j == 0 && m == 1)
                    { /*mbc0 tcmu blocknum[4-5] for non-secure data2*/
                        if (n > 3 && n < 8)
                        {
                            mbcBlockConfig.nseEnable = true;
                        }
                        else
                        {
                            mbcBlockConfig.nseEnable = false;
                        }
                    }
                    else if (i == 0 && j == 0 && m == 0)
                    { /*mbc0 tcml blocknum[0-3] for non-secure data*/
                        if (n >= 4 && n < 8)
                        {
                            mbcBlockConfig.nseEnable = true;
                        }
                        else
                        {
                            mbcBlockConfig.nseEnable = false;
                        }
                    }
                    else
                    {
                        mbcBlockConfig.nseEnable = false;
                    }
                    mbcBlockConfig.memoryBlockIdx = n;

                    TRDC_MbcSetMemoryBlockConfig(TRDC, &mbcBlockConfig);
                }
            }
        }
    }

    TRDC_SetMbcGlobalValid(TRDC);

    /* 5. Set master domain ID for processor master */
    trdc_processor_domain_assignment_t pDomainAssignment;
    TRDC_GetDefaultProcessorDomainAssignment(&pDomainAssignment);
    pDomainAssignment.domainId = EXAMPLE_TRDC_PROCESSOR_MASTER_DOMAIN_ID;

    TRDC_SetProcessorDomainAssignment(TRDC, &pDomainAssignment);

    TRDC_SetDacGlobalValid(TRDC);
}
extern int32_t BOARD_FuseRead(uint32_t bank, uint32_t word, uint32_t *val);
bool BOARD_IsRdcEnabled_TMP(void)
{
    bool rdc_en  = true; /* Default assume DBD_EN is set */
    int32_t ret  = -1;
    uint32_t val = 0;

    /* Read DBD_EN fuse */
    ret = BOARD_FuseRead(8, 1, &val);
    if (!ret)
    {
        rdc_en = !!(val & 0x200); /* Only A1 sillicon uses DBD_EN */
    }
    return rdc_en;
}
void BOARD_ReleaseTRDC_TMP(void)
{
    uint32_t status;
    if (BOARD_IsRdcEnabled_TMP() == true)
    {
        /* Release TRDC(transfer owner of TRDC from s400 to m33) */
        status = SENTINEL_ReleaseRDC(TRDC_TYPE);
        if (status != BASELINE_SUCCESS_IND)
        {
            assert(status == BASELINE_SUCCESS_IND);
        }
    }
}
void APP_SetTrdcGlobalConfig(void)
{
    uint16_t Soc_id  = 0;
    uint16_t Soc_rev = 0;
    uint32_t ret;

    ret = SENTINEL_GetSocInfo(&Soc_id, &Soc_rev);

    /* imx8ulp A0(soc_id:0x84d rev:0xA000) need to init trdc.
     * Others SOC need to change owner of trdc from Sentinel to M33
     * ret = BASELINE_FAILURE_IND The request failed */
    if ((IMX8ULP_SOC_ID == Soc_id && IMX8ULP_SOC_REV_A0 == Soc_rev) || (ret == BASELINE_FAILURE_IND))
    {
        TRDC_InitGlobalConfig();
    }
    else
    {
        int i = 0;
        BOARD_ReleaseTRDC_TMP();
        for (i = 4; i < 8; i++)
        {
            /*mbc0 tcml blocknum[4-7] for non-secure data*/
            App_SetTrdcMBCNSE(0, 0, i, 1);
            /*mbc0 tcmu blocknum[4-7] for non-secure data2*/
            App_SetTrdcMBCNSE(0, 1, i, 1);
        }
        APP_SetTrdcMRCNSE(SAU_REGION_0_BASE, SAU_REGION_0_END, EXAMPLE_TRDC_MRC_INDEX);
    }
}
void BOARD_InitTrustZone()
{
    /* SAU configuration */

    /* Set SAU Control register: Disable SAU and All Secure */
    SAU->CTRL = 0;

    /* Set SAU region number */
    SAU->RNR = 0;
    /* Region base address */
    SAU->RBAR = SAU_REGION_0_BASE & SAU_RBAR_BADDR_Msk;
    /* Region end address */
    SAU->RLAR = (SAU_REGION_0_END & SAU_RLAR_LADDR_Msk) | ((0U << SAU_RLAR_NSC_Pos) & SAU_RLAR_NSC_Msk) |
                ((1U << SAU_RLAR_ENABLE_Pos) & SAU_RLAR_ENABLE_Msk);

    /* Set SAU region number */
    SAU->RNR = 1;
    /* Region base address */
    SAU->RBAR = SAU_REGION_1_BASE & SAU_RBAR_BADDR_Msk;
    /* Region end address */
    SAU->RLAR = (SAU_REGION_1_END & SAU_RLAR_LADDR_Msk) | ((0U << SAU_RLAR_NSC_Pos) & SAU_RLAR_NSC_Msk) |
                ((1U << SAU_RLAR_ENABLE_Pos) & SAU_RLAR_ENABLE_Msk);

    /* Set SAU region number */
    SAU->RNR = 2;
    /* Region base address */
    SAU->RBAR = SAU_REGION_2_BASE & SAU_RBAR_BADDR_Msk;
    /* Region end address */
    SAU->RLAR = (SAU_REGION_2_END & SAU_RLAR_LADDR_Msk) | ((0U << SAU_RLAR_NSC_Pos) & SAU_RLAR_NSC_Msk) |
                ((1U << SAU_RLAR_ENABLE_Pos) & SAU_RLAR_ENABLE_Msk);

    /* Set SAU region number */
    SAU->RNR = 3;
    /* Region base address */
    SAU->RBAR = SAU_REGION_3_BASE & SAU_RBAR_BADDR_Msk;
    /* Region end address */
    SAU->RLAR = (SAU_REGION_3_END & SAU_RLAR_LADDR_Msk) | ((1U << SAU_RLAR_NSC_Pos) & SAU_RLAR_NSC_Msk) |
                ((1U << SAU_RLAR_ENABLE_Pos) & SAU_RLAR_ENABLE_Msk);

    /* Set SAU region number */
    SAU->RNR = 4;
    /* Region base address */
    SAU->RBAR = SAU_REGION_4_BASE & SAU_RBAR_BADDR_Msk;
    /* Region end address */
    SAU->RLAR = (SAU_REGION_4_END & SAU_RLAR_LADDR_Msk) | ((1U << SAU_RLAR_NSC_Pos) & SAU_RLAR_NSC_Msk) |
                ((1U << SAU_RLAR_ENABLE_Pos) & SAU_RLAR_ENABLE_Msk);

    /* Set SAU region number */
    SAU->RNR = 5;
    /* Region base address */
    SAU->RBAR = SAU_REGION_5_BASE & SAU_RBAR_BADDR_Msk;
    /* Region end address */
    SAU->RLAR = (SAU_REGION_5_END & SAU_RLAR_LADDR_Msk) | ((0U << SAU_RLAR_NSC_Pos) & SAU_RLAR_NSC_Msk) |
                ((1U << SAU_RLAR_ENABLE_Pos) & SAU_RLAR_ENABLE_Msk);

    /* Set SAU region number */
    SAU->RNR = 6;
    /* Region base address */
    SAU->RBAR = SAU_REGION_6_BASE & SAU_RBAR_BADDR_Msk;
    /* Region end address */
    SAU->RLAR = (SAU_REGION_6_END & SAU_RLAR_LADDR_Msk) | ((0U << SAU_RLAR_NSC_Pos) & SAU_RLAR_NSC_Msk) |
                ((1U << SAU_RLAR_ENABLE_Pos) & SAU_RLAR_ENABLE_Msk);

    /* Force memory writes before continuing */
    __DSB();
    /* Flush and refill pipeline with updated permissions */
    __ISB();

    /* Set SAU Control register: Enable SAU and All Secure (applied only if disabled) */
    SAU->CTRL = ((0U << SAU_CTRL_ALLNS_Pos) & SAU_CTRL_ALLNS_Msk) | ((1U << SAU_CTRL_ENABLE_Pos) & SAU_CTRL_ENABLE_Msk);

    APP_SetTrdcGlobalConfig();

    /*--------------------------------------------------------------------
     - Interrupts: Interrupt security configuration
     -------------------------------------------------------------------*/
    /* Possible values for every interrupt:
     *  0b0    Secure
     *  0b1    Non-secure */
    NVIC->ITNS[0] = 0;
    NVIC->ITNS[1] = 0;

    /* Global Options */
    SCB->AIRCR = (SCB->AIRCR & 0x000009FF7U) | 0x005FA0000U;
    SCB->SCR &= 0x0FFFFFFF7U;
    SCB->SHCSR &= 0x0FFF7FFFFU;
    SCB->NSACR    = 0x00000C03U;
    SCnSCB->CPPWR = 0;

    /*set ns=1 to be accessed by non-secure for cm33cc*/
    App_SetTrdcMBCNSE(2, 0, 70, true);
}
