/*
** ###################################################################
**     Processors:          MIMX8MQ6CVAHZ
**                          MIMX8MQ6CZKHZ
**                          MIMX8MQ6DVAJZ
**                          MIMX8MQ6DZKJZ
**
**     Compilers:           Keil ARM C/C++ Compiler
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**
**     Reference manual:    IMX8MQRM, Rev. C, Jul. 2017
**     Version:             rev. 3.0, 2017-07-19
**     Build:               b170804
**
**     Abstract:
**         Provides a system configuration function and a global variable that
**         contains the system frequency. It configures the device and initializes
**         the oscillator (PLL) that is part of the microcontroller device.
**
**     The Clear BSD License
**     Copyright 2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2017 NXP
**     All rights reserved.
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted (subject to the limitations in the disclaimer below) provided that 
**     the following conditions are met:
**
**     1. Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**
**     2. Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**
**     3. Neither the name of the copyright holder nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**
**     NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED BY THIS LICENSE.
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2017-01-10)
**         Initial version.
**     - rev. 2.0 (2017-04-27)
**         Rev.B Header EAR1
**     - rev. 3.0 (2017-07-19)
**         Rev.C Header EAR2
**
** ###################################################################
*/

/*!
 * @file MIMX8MQ6_cm4
 * @version 3.0
 * @date 2017-07-19
 * @brief Device specific configuration file for MIMX8MQ6_cm4 (implementation
 *        file)
 *
 * Provides a system configuration function and a global variable that contains
 * the system frequency. It configures the device and initializes the oscillator
 * (PLL) that is part of the microcontroller device.
 */

#include <stdint.h>
#include "fsl_device_registers.h"

/* ----------------------------------------------------------------------------
   -- Core clock
   ---------------------------------------------------------------------------- */
uint32_t SystemCoreClock = DEFAULT_SYSTEM_CLOCK;

/* ----------------------------------------------------------------------------
   -- SystemInit()
   ---------------------------------------------------------------------------- */

void SystemInit (void) {
#if ((__FPU_PRESENT == 1) && (__FPU_USED == 1))
  SCB->CPACR |= ((3UL << 10*2) | (3UL << 11*2));    /* set CP10, CP11 Full Access */
#endif /* ((__FPU_PRESENT == 1) && (__FPU_USED == 1)) */
  /* Initialize Cache */
  /* Enable Code Bus Cache */
  /* set command to invalidate all ways, and write GO bit to initiate command */
  LMEM->PCCCR |= LMEM_PCCCR_INVW1_MASK | LMEM_PCCCR_INVW0_MASK;
  LMEM->PCCCR |= LMEM_PCCCR_GO_MASK;
  /* Wait until the command completes */
  while (LMEM->PCCCR & LMEM_PCCCR_GO_MASK) {
  }
  /* Enable cache, enable write buffer */
  LMEM->PCCCR |= (LMEM_PCCCR_ENWRBUF_MASK | LMEM_PCCCR_ENCACHE_MASK);
  
  /* Enable System Bus Cache */
  /* set command to invalidate all ways, and write GO bit to initiate command */
  LMEM->PSCCR |= LMEM_PSCCR_INVW1_MASK | LMEM_PSCCR_INVW0_MASK;
  LMEM->PSCCR |= LMEM_PSCCR_GO_MASK;
  /* Wait until the command completes */
  while (LMEM->PSCCR & LMEM_PSCCR_GO_MASK) {
  }
  /* Enable cache, enable write buffer */
  LMEM->PSCCR |= (LMEM_PSCCR_ENWRBUF_MASK | LMEM_PSCCR_ENCACHE_MASK);

  __ISB();
  __DSB();

}

/*!
 * @brief CCM reg macros to extract corresponding registers bit field.
 */
#define CCM_BIT_FIELD_VAL(val, mask, shift)  (((val) & mask) >> shift)

/*!
 * @brief CCM reg macros to get corresponding registers values.
 */ 
#define CCM_ANALOG_REG_VAL(base, off) (*((volatile uint32_t *)((uint32_t)base + off)))

uint32_t GetFracPllFreq(volatile uint32_t *base)
{

    uint32_t fracCfg0 = CCM_ANALOG_REG_VAL(base, 0U);
    uint32_t fracCfg1 = CCM_ANALOG_REG_VAL(base, 4U);
    uint32_t refClkFreq = 0U;
    uint64_t fracClk  = 0U;
                     
    uint8_t  refSel   = CCM_BIT_FIELD_VAL(fracCfg0, CCM_ANALOG_AUDIO_PLL1_CFG0_PLL_REFCLK_SEL_MASK, CCM_ANALOG_AUDIO_PLL1_CFG0_PLL_REFCLK_SEL_SHIFT);
    uint8_t  refDiv   = CCM_BIT_FIELD_VAL(fracCfg0, CCM_ANALOG_AUDIO_PLL1_CFG0_PLL_REFCLK_DIV_VAL_MASK, CCM_ANALOG_AUDIO_PLL1_CFG0_PLL_REFCLK_DIV_VAL_SHIFT);
    uint8_t  outDiv   = CCM_BIT_FIELD_VAL(fracCfg0, CCM_ANALOG_AUDIO_PLL1_CFG0_PLL_OUTPUT_DIV_VAL_MASK, CCM_ANALOG_AUDIO_PLL1_CFG0_PLL_OUTPUT_DIV_VAL_SHIFT);
    uint32_t fracDiv  = CCM_BIT_FIELD_VAL(fracCfg1, CCM_ANALOG_AUDIO_PLL1_CFG1_PLL_FRAC_DIV_CTL_MASK, CCM_ANALOG_AUDIO_PLL1_CFG1_PLL_FRAC_DIV_CTL_SHIFT);
    uint8_t  intDiv   = CCM_BIT_FIELD_VAL(fracCfg1, CCM_ANALOG_AUDIO_PLL1_CFG1_PLL_INT_DIV_CTL_MASK, CCM_ANALOG_AUDIO_PLL1_CFG1_PLL_INT_DIV_CTL_SHIFT);
    
    if(refSel == 0) /* OSC 25M Clock */
    {
       refClkFreq = CPU_XTAL_SOSC_CLK_25MHZ;
    }
    else if ((refSel == 1) || /* OSC 27M Clock */
             (refSel == 2)) /* HDMI_PYH 27M Clock */
    {
       refClkFreq = CPU_XTAL_SOSC_CLK_27MHZ;
    }
    else
    {
       refClkFreq = CLK_P_N_FREQ;  /* CLK_P_N Clock, please note that the value is 0hz by default, it could be set at system_MIMX8MQx_cm4.h :88 */
    }
    refClkFreq /= refDiv + 1U; 
    fracClk = (uint64_t)refClkFreq * 8U * (1U + intDiv) + (((uint64_t)refClkFreq * 8U * fracDiv) >> 24U);

    return fracClk / ((outDiv +1U) * 2U);
}

uint32_t GetSSCGPllFreq(volatile uint32_t * base)
{
    uint32_t sscgCfg0 = CCM_ANALOG_REG_VAL(base, 0U);
    uint32_t sscgCfg1 = CCM_ANALOG_REG_VAL(base, 4U);
    uint32_t sscgCfg2 = CCM_ANALOG_REG_VAL(base, 8U);
    uint32_t refClkFreq = 0U;
    uint64_t pll2InputClock = 0U;
    
    uint8_t pll1Bypass = CCM_BIT_FIELD_VAL(sscgCfg0, CCM_ANALOG_SYS_PLL_CFG0_PLL_BYPASS1_MASK, CCM_ANALOG_SYS_PLL_CFG0_PLL_BYPASS1_SHIFT);
    uint8_t refSel  = CCM_BIT_FIELD_VAL(sscgCfg0, CCM_ANALOG_SYS_PLL_CFG0_PLL_REFCLK_SEL_MASK, CCM_ANALOG_SYS_PLL_CFG0_PLL_REFCLK_SEL_SHIFT);
    uint8_t refDiv1 = CCM_BIT_FIELD_VAL(sscgCfg2, CCM_ANALOG_SYS_PLL_CFG2_PLL_REF_DIVR1_MASK, CCM_ANALOG_SYS_PLL_CFG2_PLL_REF_DIVR1_SHIFT) + 1U; 
    uint8_t refDiv2 = CCM_BIT_FIELD_VAL(sscgCfg2, CCM_ANALOG_SYS_PLL_CFG2_PLL_REF_DIVR2_MASK, CCM_ANALOG_SYS_PLL_CFG2_PLL_REF_DIVR2_SHIFT) + 1U;
    uint8_t divf1   = CCM_BIT_FIELD_VAL(sscgCfg2, CCM_ANALOG_SYS_PLL_CFG2_PLL_FEEDBACK_DIVF1_MASK, CCM_ANALOG_SYS_PLL_CFG2_PLL_FEEDBACK_DIVF1_SHIFT) + 1U;
    uint8_t divf2   = CCM_BIT_FIELD_VAL(sscgCfg2, CCM_ANALOG_SYS_PLL_CFG2_PLL_FEEDBACK_DIVF2_MASK, CCM_ANALOG_SYS_PLL_CFG2_PLL_FEEDBACK_DIVF2_SHIFT) + 1U;
    uint8_t outDiv  = CCM_BIT_FIELD_VAL(sscgCfg2, CCM_ANALOG_SYS_PLL_CFG2_PLL_OUTPUT_DIV_VAL_MASK, CCM_ANALOG_SYS_PLL_CFG2_PLL_OUTPUT_DIV_VAL_SHIFT) + 1U;
    
    if(refSel == 0) /* OSC 25M Clock */
    {
       refClkFreq = CPU_XTAL_SOSC_CLK_25MHZ;
    }
    else if ((refSel == 1) || /* OSC 27M Clock */
             (refSel == 2)) /* HDMI_PYH 27M Clock */
    {
       refClkFreq = CPU_XTAL_SOSC_CLK_27MHZ;
    }
    else
    {
       refClkFreq = CLK_P_N_FREQ;  /* CLK_P_N Clock, please note that the value is 0hz by default, it could be set at system_MIMX8MQx_cm4.h :88 */
    }
       
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
/* ----------------------------------------------------------------------------
   -- SystemCoreClockUpdate()
   ---------------------------------------------------------------------------- */

void SystemCoreClockUpdate (void) {
  
  volatile uint32_t * M4_ClockRoot = (uint32_t *)(&(CCM)->ROOT[1].TARGET_ROOT);                     
  uint32_t pre  = ((*M4_ClockRoot & CCM_TARGET_ROOT_PRE_PODF_MASK) >> CCM_TARGET_ROOT_PRE_PODF_SHIFT) + 1U;
  uint32_t post = ((*M4_ClockRoot & CCM_TARGET_ROOT_POST_PODF_MASK) >> CCM_TARGET_ROOT_POST_PODF_SHIFT) + 1U;
  
  uint32_t freq = 0U; 

  switch((*M4_ClockRoot & CCM_TARGET_ROOT_MUX_MASK) >> CCM_TARGET_ROOT_MUX_SHIFT)  
    {
        case 0U: /* OSC 25M Clock */
            freq = CPU_XTAL_SOSC_CLK_25MHZ;
            break;
        case 1U: /* System PLL2 DIV5 */         
            freq = GetSSCGPllFreq(&(CCM_ANALOG->SYS_PLL2_CFG0)) / 5; /* Get System PLL2 DIV5 freq */
            break;
        case 2U: /* System PLL2 DIV4 */
            freq = GetSSCGPllFreq(&(CCM_ANALOG->SYS_PLL2_CFG0)) / 4; /* Get System PLL2 DIV4 freq */
            break;
        case 3U: /* System PLL1 DIV3 */
            freq = GetSSCGPllFreq(&(CCM_ANALOG->SYS_PLL_CFG0)) / 3;  /* Get System PLL1 DIV3 freq */
            break;
        case 4U: /* System PLL1 */
            freq = GetSSCGPllFreq(&(CCM_ANALOG->SYS_PLL_CFG0));      /* Get System PLL1 freq */
            break;
        case 5U: /* AUDIO PLL1 */
             freq = GetFracPllFreq(&(CCM_ANALOG->AUDIO_PLL1_CFG0));  /* Get AUDIO PLL1 freq */
            break;
        case 6U: /* VIDEO PLL1 */
              freq = GetFracPllFreq(&(CCM_ANALOG->VIDEO_PLL_CFG0));  /* Get VIDEO PLL1 freq */
            break;
        case 7U: /* System PLL3 */
             freq = GetSSCGPllFreq(&(CCM_ANALOG->SYS_PLL3_CFG0));    /* Get System PLL3 freq */
            break;            
        default:
            break; 
    }
    
  SystemCoreClock = freq / pre / post;

}
