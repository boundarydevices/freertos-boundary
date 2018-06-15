/*
 * The Clear BSD License
 * Copyright 2017 NXP
  * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted (subject to the limitations in the disclaimer below) provided that 
 * the following conditions are met:
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
#include "fsl_common.h"
#include "fsl_clock.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @brief SSCG PLL FLITER range value */
#define SSCG_PLL1_FILTER_RANGE  (35000000U)
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
 
 /*******************************************************************************
 * Code
 ******************************************************************************/
uint32_t CLOCK_GetFreq(clock_name_t clockName)
{
    uint32_t freq;

    switch (clockName)
    {
        case kCLOCK_CoreM4Clk:
            freq = CLOCK_GetCoreM4Freq();
            break;
        case kCLOCK_AxiClk:
            freq = CLOCK_GetAxiFreq();
            break;
        case kCLOCK_AhbClk:
            freq = CLOCK_GetAhbFreq();
            break;
        case kCLOCK_IpgClk:
            freq = CLOCK_GetAhbFreq();
            break;          
        default:
            freq = 0U;
            break;
    }
    return freq;
}

uint32_t CLOCK_GetCoreM4Freq(void)
{
    uint32_t freq;
    uint32_t pre  = CLOCK_GetRootPreDivider(kCLOCK_RootM4);
    uint32_t post = CLOCK_GetRootPostDivider(kCLOCK_RootM4);
    
    switch(CLOCK_GetRootMux(kCLOCK_RootM4))
    {
        case kCLOCK_M4RootmuxOsc25m:
            freq = OSC25M_CLK_FREQ;
            break;
        case kCLOCK_M4RootmuxSysPll2Div5:
            freq = CLOCK_GetPllFreq(kCLOCK_SystemPll2Ctrl) / 5U;
            break;
        case kCLOCK_M4RootmuxSysPll2Div4:
            freq = CLOCK_GetPllFreq(kCLOCK_SystemPll2Ctrl) / 4U;
            break;
        case kCLOCK_M4RootmuxSysPll1Div3:
            freq = CLOCK_GetPllFreq(kCLOCK_SystemPll1Ctrl) / 3U;
            break;
        case kCLOCK_M4RootmuxSysPll1:
            freq = CLOCK_GetPllFreq(kCLOCK_SystemPll1Ctrl);
            break;
        case kCLOCK_M4RootmuxAudioPll1:
            freq = CLOCK_GetPllFreq(kCLOCK_AudioPll1Ctrl);
            break;
        case kCLOCK_M4RootmuxVideoPll1:
            freq = CLOCK_GetPllFreq(kCLOCK_VideoPll1Ctrl);
            break;
        case kCLOCK_M4RootmuxSysPll3:
            freq = CLOCK_GetPllFreq(kCLOCK_SystemPll3Ctrl);
            break;          
        default:
            return 0;
    }
    
    return freq / pre / post ;
}

uint32_t CLOCK_GetAxiFreq(void)
{
    uint32_t freq;
    uint32_t pre  = CLOCK_GetRootPreDivider(kCLOCK_RootAxi);
    uint32_t post = CLOCK_GetRootPostDivider(kCLOCK_RootAxi);

    switch(CLOCK_GetRootMux(kCLOCK_RootAxi))
    {
        case kCLOCK_AxiRootmuxOsc25m:
            freq = OSC25M_CLK_FREQ;
            break;
        case kCLOCK_AxiRootmuxSysPll2Div3:
            freq = CLOCK_GetPllFreq(kCLOCK_SystemPll2Ctrl) / 3U;
            break;
        case kCLOCK_AxiRootmuxSysPll2Div4:
            freq = CLOCK_GetPllFreq(kCLOCK_SystemPll2Ctrl) / 4U;
            break;
        case kCLOCK_AxiRootmuxSysPll2:
            freq = CLOCK_GetPllFreq(kCLOCK_SystemPll2Ctrl);
            break;
        case kCLOCK_AxiRootmuxAudioPll1:
            freq = CLOCK_GetPllFreq(kCLOCK_AudioPll1Ctrl);
            break;
        case kCLOCK_AxiRootmuxVideoPll1:
            freq = CLOCK_GetPllFreq(kCLOCK_VideoPll1Ctrl);
            break;
        case kCLOCK_AxiRootmuxSysPll1Div8:
            freq = CLOCK_GetPllFreq(kCLOCK_SystemPll1Ctrl) / 8;
            break;
        case kCLOCK_AxiRootmuxSysPll1:
            freq = CLOCK_GetPllFreq(kCLOCK_SystemPll1Ctrl);
            break;          
        default:
            return 0;
    }
    
    return freq / pre / post;
}

uint32_t CLOCK_GetAhbFreq(void)
{
    uint32_t freq;
    uint32_t pre  = CLOCK_GetRootPreDivider(kCLOCK_RootAhb);
    uint32_t post = CLOCK_GetRootPostDivider(kCLOCK_RootAhb);

    switch(CLOCK_GetRootMux(kCLOCK_RootAhb))
    {
        case kCLOCK_AhbRootmuxOsc25m:
            freq = OSC25M_CLK_FREQ;
            break;
        case kCLOCK_AhbRootmuxSysPll1Div6:
            freq = CLOCK_GetPllFreq(kCLOCK_SystemPll1Ctrl) / 6U;
            break;
        case kCLOCK_AhbRootmuxSysPll1Div2:
            freq = CLOCK_GetPllFreq(kCLOCK_SystemPll1Ctrl) / 2U;
            break;
        case kCLOCK_AhbRootmuxSysPll1:
            freq = CLOCK_GetPllFreq(kCLOCK_SystemPll1Ctrl);
            break;
        case kCLOCK_AhbRootmuxSysPll2Div8:
            freq = CLOCK_GetPllFreq(kCLOCK_SystemPll2Ctrl) / 8U;
            break;
        case kCLOCK_AhbRootmuxSysPll3:
            freq = CLOCK_GetPllFreq(kCLOCK_SystemPll3Ctrl);
            break;
        case kCLOCK_AhbRootmuxAudioPll1:
            freq = CLOCK_GetPllFreq(kCLOCK_AudioPll1Ctrl);
            break;
        case kCLOCK_AhbRootmuxVideoPll1:
            freq = CLOCK_GetPllFreq(kCLOCK_VideoPll1Ctrl);
            break;            
        default:
            return 0;
    }
    
    return freq / pre / post;
}

uint32_t CLOCK_GetPllRefClkFreq(clock_pll_ctrl_t ctrl)
{
    uint32_t refClkFreq = 0U;
    uint8_t clkSel = 0U;

    if(ctrl <= kCLOCK_ArmPllCtrl)
    {
        clkSel = CCM_BIT_FIELD_EXTRACTION(CCM_ANALOG_TUPLE_REG(CCM_ANALOG, ctrl), CCM_ANALOG_AUDIO_PLL1_CFG0_PLL_REFCLK_SEL_MASK, CCM_ANALOG_AUDIO_PLL1_CFG0_PLL_REFCLK_SEL_SHIFT);
    }
    else
    {
        clkSel = (CCM_ANALOG_TUPLE_REG(CCM_ANALOG, ctrl) & CCM_ANALOG_SYS_PLL_CFG0_PLL_REFCLK_SEL_MASK);
    }

    switch(clkSel)
    {
        case kANALOG_PllRefOsc25M:
            refClkFreq = OSC25M_CLK_FREQ / (CCM_BIT_FIELD_EXTRACTION(XTALOSC->OSC_CTL_CFG_25M, XTALOSC_OSC_CTL_CFG_25M_OSC_DIV_MASK, XTALOSC_OSC_CTL_CFG_25M_OSC_DIV_SHIFT) + 1U);
            break;

        case kANALOG_PllRefOsc27M:  
            refClkFreq = OSC27M_CLK_FREQ / (CCM_BIT_FIELD_EXTRACTION(XTALOSC->OSC_CTL_CFG_27M, XTALOSC_OSC_CTL_CFG_27M_OSC_DIV_MASK, XTALOSC_OSC_CTL_CFG_27M_OSC_DIV_SHIFT) + 1U);
            break;

        case kANALOG_PllRefOscHdmiPhy27M:            
            refClkFreq = HDMI_PHY_27M_FREQ;
            break;

        case kANALOG_PllRefClkPN:
            refClkFreq = CLKPN_FREQ;
            break;
        default:
            break;
    }

    return refClkFreq;
}

uint32_t CLOCK_GetPllFreq(clock_pll_ctrl_t pll)
{
    uint32_t pllFreq = 0U;
    uint32_t pllRefFreq = 0U;
    bool sscgPll1Bypass = false;
    bool sscgPll2Bypass = false;
    bool fracPllBypass = false;

    pllRefFreq = CLOCK_GetPllRefClkFreq(pll);

    switch(pll)
    {
        /* SSCG PLL frequency */
        case kCLOCK_SystemPll1Ctrl:
            sscgPll1Bypass = CLOCK_IsPllBypassed(CCM_ANALOG, kCLOCK_SysPll1InternalPll1BypassCtrl);
            sscgPll2Bypass = CLOCK_IsPllBypassed(CCM_ANALOG, kCLOCK_SysPll1InternalPll2BypassCtrl);
            break;
        case kCLOCK_SystemPll2Ctrl:
            sscgPll1Bypass = CLOCK_IsPllBypassed(CCM_ANALOG, kCLOCK_SysPll2InternalPll1BypassCtrl);
            sscgPll2Bypass = CLOCK_IsPllBypassed(CCM_ANALOG, kCLOCK_SysPll2InternalPll2BypassCtrl);
            break;
        case kCLOCK_SystemPll3Ctrl:
            sscgPll1Bypass = CLOCK_IsPllBypassed(CCM_ANALOG, kCLOCK_SysPll3InternalPll1BypassCtrl);
            sscgPll2Bypass = CLOCK_IsPllBypassed(CCM_ANALOG, kCLOCK_SysPll3InternalPll2BypassCtrl);
            break;
        case kCLOCK_VideoPll2Ctrl:
            sscgPll1Bypass = CLOCK_IsPllBypassed(CCM_ANALOG, kCLOCK_VideoPll2InternalPll1BypassCtrl);
            sscgPll2Bypass = CLOCK_IsPllBypassed(CCM_ANALOG, kCLOCK_VideoPll2InternalPll2BypassCtrl);
            break;
        case kCLOCK_DramPllCtrl:
            sscgPll1Bypass = CLOCK_IsPllBypassed(CCM_ANALOG, kCLOCK_DramPllInternalPll1BypassCtrl);
            sscgPll2Bypass = CLOCK_IsPllBypassed(CCM_ANALOG, kCLOCK_DramPllInternalPll2BypassCtrl);
            break;
        case kCLOCK_AudioPll1Ctrl:
            fracPllBypass = CLOCK_IsPllBypassed(CCM_ANALOG, kCLOCK_AudioPll1BypassCtrl);
            break;
        case kCLOCK_AudioPll2Ctrl:
            fracPllBypass = CLOCK_IsPllBypassed(CCM_ANALOG, kCLOCK_AudioPll2BypassCtrl);
            break;
        case kCLOCK_VideoPll1Ctrl:
            fracPllBypass = CLOCK_IsPllBypassed(CCM_ANALOG, kCLOCK_VideoPll1BypassCtrl);
            break;
        case kCLOCK_GpuPllCtrl:
            fracPllBypass = CLOCK_IsPllBypassed(CCM_ANALOG, kCLOCK_GpuPLLPwrBypassCtrl);
            break;
        case kCLOCK_VpuPllCtrl:
            fracPllBypass = CLOCK_IsPllBypassed(CCM_ANALOG, kCLOCK_VpuPllPwrBypassCtrl);
            break;
        case kCLOCK_ArmPllCtrl:
            fracPllBypass = CLOCK_IsPllBypassed(CCM_ANALOG, kCLOCK_ArmPllPwrBypassCtrl);
            break;
        default:
            break;
    }
    if(pll <=  kCLOCK_ArmPllCtrl)
    {
        if(fracPllBypass)
        {
            pllFreq = pllRefFreq;
        }
        else
        {
            pllFreq = CLOCK_GetFracPllFreq(CCM_ANALOG, pll, pllRefFreq);
        }
    }
    else
    {
        if(sscgPll2Bypass)
        {
            /* if PLL2 is bypass, return reference clock directly */
            pllFreq = pllRefFreq;
        }
        else
        {
            pllFreq = CLOCK_GetSSCGPllFreq(CCM_ANALOG, pll, pllRefFreq, sscgPll1Bypass);
        }
    }
    
    return pllFreq;
}

void CLOCK_InitArmPll(const ccm_analog_frac_pll_config_t *config)
{
    assert(config);

    /* Disable PLL bypass */
    CLOCK_SetPllBypass(CCM_ANALOG, kCLOCK_ArmPllPwrBypassCtrl, false);
    /* Fractional pll configuration */
    CLOCK_InitFracPll(CCM_ANALOG, config, kCLOCK_ArmPllCtrl);
    /* Enable and power up PLL clock. */
    CLOCK_EnableAnalogClock(CCM_ANALOG, kCLOCK_ArmPllClke);
    
    /* Wait for PLL to be locked. */
    while(!CLOCK_IsPllLocked(CCM_ANALOG, kCLOCK_ArmPllCtrl))
    {
    }
}

void CLOCK_DeinitArmPll(void)
{
    CLOCK_PowerDownPll(CCM_ANALOG, kCLOCK_ArmPllCtrl);
}

void CLOCK_InitAudioPll1(const ccm_analog_frac_pll_config_t *config)
{
    assert(config);

    /* Disable PLL bypass */
    CLOCK_SetPllBypass(CCM_ANALOG, kCLOCK_AudioPll1BypassCtrl, false);
    /* Fractional pll configuration */
    CLOCK_InitFracPll(CCM_ANALOG, config, kCLOCK_AudioPll1Ctrl);
    /* Enable and power up PLL clock. */
    CLOCK_EnableAnalogClock(CCM_ANALOG, kCLOCK_AudioPll1Clke);
    
    /* Wait for PLL to be locked. */
    while(!CLOCK_IsPllLocked(CCM_ANALOG, kCLOCK_AudioPll1Ctrl))
    {
    }
}

void CLOCK_DeinitAudioPll1(void)
{
    CLOCK_PowerDownPll(CCM_ANALOG, kCLOCK_AudioPll1Ctrl);
}

void CLOCK_InitAudioPll2(const ccm_analog_frac_pll_config_t *config)
{
    assert(config);

    /* Disable PLL bypass */
    CLOCK_SetPllBypass(CCM_ANALOG, kCLOCK_AudioPll2BypassCtrl, false);
    /* Fractional pll configuration */
    CLOCK_InitFracPll(CCM_ANALOG, config, kCLOCK_AudioPll2Ctrl);
    /* Enable and power up PLL clock. */
    CLOCK_EnableAnalogClock(CCM_ANALOG, kCLOCK_AudioPll2Clke);
    
    /* Wait for PLL to be locked. */
    while(!CLOCK_IsPllLocked(CCM_ANALOG, kCLOCK_AudioPll2Ctrl))
    {
    }
}

void CLOCK_DeinitAudioPll2(void)
{
    CLOCK_PowerDownPll(CCM_ANALOG, kCLOCK_AudioPll2Ctrl);
}

void CLOCK_InitVideoPll1(const ccm_analog_frac_pll_config_t *config)
{
    assert(config);

    /* Disable PLL bypass */
    CLOCK_SetPllBypass(CCM_ANALOG, kCLOCK_VideoPll1BypassCtrl, false);
    /* Fractional pll configuration */
    CLOCK_InitFracPll(CCM_ANALOG, config, kCLOCK_VideoPll1Ctrl);
    /* Enable and power up PLL clock. */
    CLOCK_EnableAnalogClock(CCM_ANALOG, kCLOCK_VideoPll1Clke);
    
    /* Wait for PLL to be locked. */
    while(!CLOCK_IsPllLocked(CCM_ANALOG, kCLOCK_VideoPll1Ctrl))
    {
    }
}

void CLOCK_DeinitVedioPll1(void)
{
    CLOCK_PowerDownPll(CCM_ANALOG, kCLOCK_VideoPll1Ctrl);
}

void CLOCK_InitSysPll1(const ccm_analog_sscg_pll_config_t *config)
{
    assert(config);

    /* SSCG PLL configuration */
    CLOCK_InitSSCGPll(CCM_ANALOG, config, kCLOCK_SystemPll1Ctrl);
    /* Disable PLL bypass */
    CLOCK_SetPllBypass(CCM_ANALOG, kCLOCK_SysPll1InternalPll1BypassCtrl, false);
    CLOCK_SetPllBypass(CCM_ANALOG, kCLOCK_SysPll1InternalPll2BypassCtrl, false);
    /* Enable and power up PLL clock. */
    CLOCK_EnableAnalogClock(CCM_ANALOG, kCLOCK_SystemPll1Clke);
    
    /* Wait for PLL to be locked. */
    while(!CLOCK_IsPllLocked(CCM_ANALOG, kCLOCK_SystemPll1Ctrl))
    {
    }
}

void CLOCK_DeinitSysPll1(void)
{
    CLOCK_PowerDownPll(CCM_ANALOG, kCLOCK_SystemPll1Ctrl);
}

void CLOCK_InitSysPll2(const ccm_analog_sscg_pll_config_t *config)
{
    assert(config);

    /* SSCG PLL configuration */
    CLOCK_InitSSCGPll(CCM_ANALOG, config, kCLOCK_SystemPll2Ctrl);
    /* Disable PLL bypass */
    CLOCK_SetPllBypass(CCM_ANALOG, kCLOCK_SysPll2InternalPll1BypassCtrl, false);
    CLOCK_SetPllBypass(CCM_ANALOG, kCLOCK_SysPll2InternalPll2BypassCtrl, false);
    /* Enable and power up PLL clock. */
    CLOCK_EnableAnalogClock(CCM_ANALOG, kCLOCK_SystemPll2Clke);
    
    /* Wait for PLL to be locked. */
    while(!CLOCK_IsPllLocked(CCM_ANALOG, kCLOCK_SystemPll2Ctrl))
    {
    }
}

void CLOCK_DeinitSysPll2(void)
{
    CLOCK_PowerDownPll(CCM_ANALOG, kCLOCK_SystemPll2Ctrl);
}

void CLOCK_InitSysPll3(const ccm_analog_sscg_pll_config_t *config)
{
    assert(config);

    /* SSCG PLL configuration */
    CLOCK_InitSSCGPll(CCM_ANALOG, config, kCLOCK_SystemPll3Ctrl);
    /* Disable PLL bypass */
    CLOCK_SetPllBypass(CCM_ANALOG, kCLOCK_SysPll3InternalPll1BypassCtrl, false);
    CLOCK_SetPllBypass(CCM_ANALOG, kCLOCK_SysPll3InternalPll2BypassCtrl, false);
    /* Enable and power up PLL clock. */
    CLOCK_EnableAnalogClock(CCM_ANALOG, kCLOCK_SystemPll3Clke);
    
    /* Wait for PLL to be locked. */
    while(!CLOCK_IsPllLocked(CCM_ANALOG, kCLOCK_SystemPll3Ctrl))
    {
    }
}

void CLOCK_DeinitSysPll3(void)
{
    CLOCK_PowerDownPll(CCM_ANALOG, kCLOCK_SystemPll3Ctrl);
}

void CLOCK_InitDramPll(const ccm_analog_sscg_pll_config_t *config)
{
    assert(config);

    /* init SSCG pll */
    CLOCK_InitSSCGPll(CCM_ANALOG, config, kCLOCK_DramPllCtrl);
    /* Disable PLL bypass */
    CLOCK_SetPllBypass(CCM_ANALOG, kCLOCK_DramPllInternalPll1BypassCtrl, false);
    CLOCK_SetPllBypass(CCM_ANALOG, kCLOCK_DramPllInternalPll2BypassCtrl, false);
    /* Enable and power up PLL clock. */
    CLOCK_EnableAnalogClock(CCM_ANALOG, kCLOCK_DramPllClke);
    
    /* make sure DDR is release from reset, DDR1 should be assigned to special domain first */
    /* trigger the DDR1 power up */
    GPC->PU_PGC_SW_PUP_REQ |= GPC_PU_PGC_SW_PUP_REQ_DDR1_SW_PUP_REQ_MASK;
    /* release DDR1 from reset status */
    SRC->DDRC2_RCR = (SRC->DDRC2_RCR & (~(SRC_DDRC2_RCR_DDRC1_PHY_PWROKIN_MASK | SRC_DDRC2_RCR_DDRC1_PHY_RESET_MASK | 
                    SRC_DDRC2_RCR_DDRC2_CORE_RST_MASK | SRC_DDRC2_RCR_DDRC2_PRST_MASK))) | SRC_DDRC2_RCR_DOM_EN_MASK |
                    SRC_DDRC2_RCR_DOMAIN3_MASK | SRC_DDRC2_RCR_DOMAIN2_MASK | SRC_DDRC2_RCR_DOMAIN1_MASK | SRC_DDRC2_RCR_DOMAIN0_MASK;

    while(!CLOCK_IsPllLocked(CCM_ANALOG, kCLOCK_DramPllCtrl))
    {
    }
}

void CLOCK_DeinitDramPll(void)
{
    CLOCK_PowerDownPll(CCM_ANALOG, kCLOCK_DramPllCtrl);
}

void CLOCK_InitVideoPll2(const ccm_analog_sscg_pll_config_t *config)
{
    assert(config);
    
    /* init SSCG pll */
    CLOCK_InitSSCGPll(CCM_ANALOG, config, kCLOCK_VideoPll2Ctrl);

    /* Disable PLL bypass */
    CLOCK_SetPllBypass(CCM_ANALOG, kCLOCK_VideoPll2InternalPll1BypassCtrl, false);
    CLOCK_SetPllBypass(CCM_ANALOG, kCLOCK_VideoPll2InternalPll2BypassCtrl, false);
    /* Enable and power up PLL clock. */
    CLOCK_EnableAnalogClock(CCM_ANALOG, kCLOCK_VideoPll2Clke);
    
    /* Wait for PLL to be locked. */
    while(!CLOCK_IsPllLocked(CCM_ANALOG, kCLOCK_VideoPll2Ctrl))
    {
    }
}

void CLOCK_DeinitVedioPll2(void)
{
    CLOCK_PowerDownPll(CCM_ANALOG, kCLOCK_VideoPll2Ctrl);
}

void CLOCK_InitFracPll(CCM_ANALOG_Type *base, const ccm_analog_frac_pll_config_t *config, clock_pll_ctrl_t type)
{
    assert(config);
    assert((config->refDiv != 0U) && (config->outDiv != 0U));
    assert((config->outDiv % 2) == 0U);
    assert(type <= kCLOCK_ArmPllCtrl);

    uint32_t fracCfg0 = CCM_ANALOG_TUPLE_REG_OFF(base, type, 0U) | CCM_ANALOG_AUDIO_PLL1_CFG0_PLL_PD_MASK;
    uint32_t fracCfg1 = CCM_ANALOG_TUPLE_REG_OFF(base, type, 4U);

    /* power down the fractional PLL first */
    CCM_ANALOG_TUPLE_REG_OFF(base, type, 0U) = fracCfg0;

    CCM_ANALOG_TUPLE_REG_OFF(base, type, 0U) = (fracCfg0 & (~(CCM_ANALOG_AUDIO_PLL1_CFG0_PLL_OUTPUT_DIV_VAL_MASK | CCM_ANALOG_AUDIO_PLL1_CFG0_PLL_REFCLK_DIV_VAL_MASK | 
                    CCM_ANALOG_AUDIO_PLL1_CFG0_PLL_REFCLK_SEL_MASK | CCM_ANALOG_AUDIO_PLL1_CFG0_PLL_NEWDIV_VAL_MASK))) | CCM_ANALOG_AUDIO_PLL1_CFG0_PLL_OUTPUT_DIV_VAL(config->outDiv / 2U - 1U) | 
                    CCM_ANALOG_AUDIO_PLL1_CFG0_PLL_REFCLK_DIV_VAL(config->refDiv - 1U) | CCM_ANALOG_AUDIO_PLL1_CFG0_PLL_REFCLK_SEL(config->refSel);

    CCM_ANALOG_TUPLE_REG_OFF(base, type, 4U) = (fracCfg1 & (~(CCM_ANALOG_AUDIO_PLL1_CFG1_PLL_INT_DIV_CTL_MASK | CCM_ANALOG_AUDIO_PLL1_CFG1_PLL_FRAC_DIV_CTL_MASK))) |
                  CCM_ANALOG_AUDIO_PLL1_CFG1_PLL_INT_DIV_CTL(config->intDiv) | CCM_ANALOG_AUDIO_PLL1_CFG1_PLL_FRAC_DIV_CTL(config->fractionDiv);

    /* NEW_DIV_VAL */
    CCM_ANALOG_TUPLE_REG_OFF(base, type, 0U) |= CCM_ANALOG_AUDIO_PLL1_CFG0_PLL_NEWDIV_VAL_MASK;

    /* power up the fractional pll */
    CCM_ANALOG_TUPLE_REG_OFF(base, type, 0U) &= ~CCM_ANALOG_AUDIO_PLL1_CFG0_PLL_PD_MASK;

    /* need to check NEW_DIV_ACK */
    while(!(CCM_ANALOG_TUPLE_REG_OFF(base, type, 0U) & CCM_ANALOG_AUDIO_PLL1_CFG0_PLL_NEWDIV_ACK_MASK))
    {
    }
}

uint32_t CLOCK_GetFracPllFreq(CCM_ANALOG_Type *base, clock_pll_ctrl_t type, uint32_t refClkFreq)
{
    assert(type <= kCLOCK_ArmPllCtrl);

    uint32_t fracCfg0 = CCM_ANALOG_TUPLE_REG_OFF(base, type, 0U);
    uint32_t fracCfg1 = CCM_ANALOG_TUPLE_REG_OFF(base, type, 4U);
    uint64_t fracClk  = 0U;

    uint8_t  refDiv   = CCM_BIT_FIELD_EXTRACTION(fracCfg0, CCM_ANALOG_AUDIO_PLL1_CFG0_PLL_REFCLK_DIV_VAL_MASK, CCM_ANALOG_AUDIO_PLL1_CFG0_PLL_REFCLK_DIV_VAL_SHIFT);
    uint8_t  outDiv   = CCM_BIT_FIELD_EXTRACTION(fracCfg0, CCM_ANALOG_AUDIO_PLL1_CFG0_PLL_OUTPUT_DIV_VAL_MASK, CCM_ANALOG_AUDIO_PLL1_CFG0_PLL_OUTPUT_DIV_VAL_SHIFT);
    uint32_t fracDiv  = CCM_BIT_FIELD_EXTRACTION(fracCfg1, CCM_ANALOG_AUDIO_PLL1_CFG1_PLL_FRAC_DIV_CTL_MASK, CCM_ANALOG_AUDIO_PLL1_CFG1_PLL_FRAC_DIV_CTL_SHIFT);
    uint8_t  intDiv   = CCM_BIT_FIELD_EXTRACTION(fracCfg1, CCM_ANALOG_AUDIO_PLL1_CFG1_PLL_INT_DIV_CTL_MASK, CCM_ANALOG_AUDIO_PLL1_CFG1_PLL_INT_DIV_CTL_SHIFT);

    refClkFreq /= refDiv + 1U; 
    fracClk = (uint64_t)refClkFreq * 8U * (1U + intDiv) + (((uint64_t)refClkFreq * 8U * fracDiv) >> 24U);

    return fracClk / ((outDiv +1U) * 2U);
}

void CLOCK_InitSSCGPll(CCM_ANALOG_Type *base, const ccm_analog_sscg_pll_config_t *config, clock_pll_ctrl_t type)
{
    assert(config);
    assert(config->refDiv1 != 0U);
    assert(config->refDiv2 != 0U);
    assert(config->outDiv != 0U);
    assert(config->loopDivider1 != 0U);
    assert(config->loopDivider2 != 0U);
    assert(type >= kCLOCK_SystemPll1Ctrl);

    uint32_t sscgCfg0 = CCM_ANALOG_TUPLE_REG_OFF(base, type, 0U) | CCM_ANALOG_SYS_PLL_CFG0_PLL_PD_MASK;
    uint32_t sscgCfg2 = CCM_ANALOG_TUPLE_REG_OFF(base, type, 8U);
    uint32_t pll1Filter = 0U;

    /* power down the SSCG PLL first */
    CCM_ANALOG_TUPLE_REG_OFF(base, type, 0U) = sscgCfg0;

    /* pll mux configuration */
    CCM_ANALOG_TUPLE_REG_OFF(base, type, 0U) = (sscgCfg0 & (~CCM_ANALOG_SYS_PLL_CFG0_PLL_REFCLK_SEL_MASK)) | config->refSel;

    /* reserve CFG1, spread spectrum */

    /* match the PLL1 input clock range with PLL filter range */
    if ((CLOCK_GetPllRefClkFreq(type) / (config->refDiv1)) > SSCG_PLL1_FILTER_RANGE)
    {
        pll1Filter = 1U;
    }
    /* divider configuration */
    CCM_ANALOG_TUPLE_REG_OFF(base, type, 8U) = (sscgCfg2 & (~(CCM_ANALOG_SYS_PLL_CFG2_PLL_OUTPUT_DIV_VAL_MASK | CCM_ANALOG_SYS_PLL_CFG2_PLL_FEEDBACK_DIVF2_MASK | 
                    CCM_ANALOG_SYS_PLL_CFG2_PLL_FEEDBACK_DIVF1_MASK | CCM_ANALOG_SYS_PLL_CFG2_PLL_REF_DIVR2_MASK | CCM_ANALOG_SYS_PLL_CFG2_PLL_REF_DIVR1_MASK))) | 
                CCM_ANALOG_SYS_PLL_CFG2_PLL_OUTPUT_DIV_VAL(config->outDiv - 1U) | CCM_ANALOG_SYS_PLL_CFG2_PLL_FEEDBACK_DIVF2(config->loopDivider2 - 1U) | 
                CCM_ANALOG_SYS_PLL_CFG2_PLL_FEEDBACK_DIVF1(config->loopDivider1 - 1U) | CCM_ANALOG_SYS_PLL_CFG2_PLL_REF_DIVR2(config->refDiv2 - 1U) | CCM_ANALOG_SYS_PLL_CFG2_PLL_REF_DIVR1(config->refDiv1 - 1U) | pll1Filter;
 
    /* power up the SSCG PLL */
    CCM_ANALOG_TUPLE_REG_OFF(base, type, 0U) &= ~CCM_ANALOG_SYS_PLL_CFG0_PLL_PD_MASK;
}

uint32_t CLOCK_GetSSCGPllFreq(CCM_ANALOG_Type *base, clock_pll_ctrl_t type, uint32_t refClkFreq, bool pll1Bypass)
{
    assert(type >= kCLOCK_SystemPll1Ctrl);

    uint32_t sscgCfg1 = CCM_ANALOG_TUPLE_REG_OFF(base, type, 4U);
    uint32_t sscgCfg2 = CCM_ANALOG_TUPLE_REG_OFF(base, type, 8U);
    uint64_t pll2InputClock = 0U;

    uint8_t refDiv1 = CCM_BIT_FIELD_EXTRACTION(sscgCfg2, CCM_ANALOG_SYS_PLL_CFG2_PLL_REF_DIVR1_MASK, CCM_ANALOG_SYS_PLL_CFG2_PLL_REF_DIVR1_SHIFT) + 1U; 
    uint8_t refDiv2 = CCM_BIT_FIELD_EXTRACTION(sscgCfg2, CCM_ANALOG_SYS_PLL_CFG2_PLL_REF_DIVR2_MASK, CCM_ANALOG_SYS_PLL_CFG2_PLL_REF_DIVR2_SHIFT) + 1U;
    uint8_t divf1   = CCM_BIT_FIELD_EXTRACTION(sscgCfg2, CCM_ANALOG_SYS_PLL_CFG2_PLL_FEEDBACK_DIVF1_MASK, CCM_ANALOG_SYS_PLL_CFG2_PLL_FEEDBACK_DIVF1_SHIFT) + 1U;
    uint8_t divf2   = CCM_BIT_FIELD_EXTRACTION(sscgCfg2, CCM_ANALOG_SYS_PLL_CFG2_PLL_FEEDBACK_DIVF2_MASK, CCM_ANALOG_SYS_PLL_CFG2_PLL_FEEDBACK_DIVF2_SHIFT) + 1U;
    uint8_t outDiv  = CCM_BIT_FIELD_EXTRACTION(sscgCfg2, CCM_ANALOG_SYS_PLL_CFG2_PLL_OUTPUT_DIV_VAL_MASK, CCM_ANALOG_SYS_PLL_CFG2_PLL_OUTPUT_DIV_VAL_SHIFT) + 1U;

    refClkFreq /= refDiv1;

    if(pll1Bypass)
    {
        pll2InputClock = refClkFreq;
    }
    else if(sscgCfg1 & CCM_ANALOG_SYS_PLL_CFG1_PLL_SSE_MASK)
    {
        pll2InputClock = (uint64_t)refClkFreq  * 8U * divf1 / refDiv2;
    }
    else
    {
        pll2InputClock = refClkFreq * 2U * divf1 / refDiv2;
    }

    return pll2InputClock * divf2 / outDiv;
}

void CLOCK_SetRootDivider(clock_root_control_t ccmRootClk, uint32_t pre, uint32_t post)
{
    assert ((pre <= 8U) && (pre != 0U));
    assert ((post <= 64U) && (post != 0U));

    CCM_REG(ccmRootClk) = (CCM_REG(ccmRootClk) &
                        (~(CCM_TARGET_ROOT_PRE_PODF_MASK | CCM_TARGET_ROOT_POST_PODF_MASK))) |
                       CCM_TARGET_ROOT_PRE_PODF(pre - 1U) | CCM_TARGET_ROOT_POST_PODF(post - 1U);
}

void CLOCK_UpdateRoot(clock_root_control_t ccmRootClk, uint32_t mux, uint32_t pre, uint32_t post)
{
    assert ((pre <= 8U) && (pre != 0U));
    assert ((post <= 64U) && (post != 0U));

    CCM_REG(ccmRootClk) = (CCM_REG(ccmRootClk) &
                        (~(CCM_TARGET_ROOT_MUX_MASK | CCM_TARGET_ROOT_PRE_PODF_MASK | CCM_TARGET_ROOT_POST_PODF_MASK))) |
                       CCM_TARGET_ROOT_MUX(mux) | CCM_TARGET_ROOT_PRE_PODF(pre - 1U) | CCM_TARGET_ROOT_POST_PODF(post - 1U);
}

void CLOCK_InitOSC25M(const osc_config_t *config)
{
    assert(config);
    assert(config->oscDiv != 0U);

    XTALOSC->OSC_CTL_CFG_25M = (XTALOSC->OSC_CTL_CFG_25M & (~(XTALOSC_OSC_CTL_CFG_25M_OSC_DIV_MASK | XTALOSC_OSC_CTL_CFG_25M_OSC_BYPSS_MASK))) |
                        XTALOSC_OSC_CTL_CFG_25M_OSC_DIV(config->oscDiv - 1U) | XTALOSC_OSC_CTL_CFG_25M_OSC_BYPSS(config->oscMode);

    CLOCK_EnableAnalogClock(CCM_ANALOG, kCLOCK_OSC25MClke);
}

void CLOCK_DeinitOSC25M(void)
{
    CLOCK_DisableAnalogClock(CCM_ANALOG, kCLOCK_OSC25MClke);
}

void CLOCK_InitOSC27M(const osc_config_t *config)
{
    assert(config);
    assert(config->oscDiv != 0U);

    XTALOSC->OSC_CTL_CFG_27M = (XTALOSC->OSC_CTL_CFG_27M & (~(XTALOSC_OSC_CTL_CFG_27M_OSC_DIV_MASK | XTALOSC_OSC_CTL_CFG_27M_OSC_BYPSS_MASK))) |
                        XTALOSC_OSC_CTL_CFG_27M_OSC_DIV(config->oscDiv - 1U) | XTALOSC_OSC_CTL_CFG_27M_OSC_BYPSS(config->oscMode);

    CLOCK_EnableAnalogClock(CCM_ANALOG, kCLOCK_OSC27MClke);
}

void CLOCK_DeinitOSC27M(void)
{
    CLOCK_DisableAnalogClock(CCM_ANALOG, kCLOCK_OSC27MClke);
}

void CLOCK_EnableClock(clock_ip_name_t ccmGate)
{
    uint32_t ccgr = CCM_TUPLE_CCGR(ccmGate);
    uint32_t rootClk = CCM_TUPLE_ROOT(ccmGate);

    CCM_REG_SET(ccgr) = kCLOCK_ClockNeededAll;
    /* if root clock is 0xFFFFU, then skip enable root clock */
    if(rootClk != 0xFFFFU)
    {
        CCM_REG_SET(rootClk) = CCM_TARGET_ROOT_SET_ENABLE_MASK;
    }
}

void CLOCK_DisableClock(clock_ip_name_t ccmGate)
{
    uint32_t ccgr = CCM_TUPLE_CCGR(ccmGate);
    uint32_t rootClk = CCM_TUPLE_ROOT(ccmGate);

    CCM_REG(ccgr) = kCLOCK_ClockNotNeeded;

    /* if root clock is 0xFFFFU, then skip disable root clock */
    if(rootClk != 0xFFFFU)
    {
        CCM_REG_CLR(rootClk) = CCM_TARGET_ROOT_CLR_ENABLE_MASK;
    }
}
