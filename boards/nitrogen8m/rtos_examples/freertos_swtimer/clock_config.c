/*
 * The Clear BSD License
 * Copyright 2017 NXP
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

#include "fsl_common.h"
#include "clock_config.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* OSC 27M configuration */
const osc_config_t g_osc27MConfig = {
    .oscMode = kOSC_OscMode, .oscDiv = 1U,
};

/* OSC 25M configuration */
const osc_config_t g_osc25MConfig = {
    .oscMode = kOSC_OscMode, .oscDiv = 1U,
};

/* AUDIO PLL1 configuration */
const ccm_analog_frac_pll_config_t g_audioPll1Config = {
    .refSel = kANALOG_PllRefOsc25M, /*!< PLL reference OSC25M */
    .refDiv = 5U,                   /*!< PLL input = 25 / 5 = 5M */
    .fractionDiv = 0U,
    .intDiv = 64U, /*!< Integer and fractional Divider output  = 5 * (1 + 64) * 8 = 2600MHZ */
    .outDiv = 4U,  /*!< Pll out frequency  = 2600 / 4 = 650MHZ */
};

/* AUDIO PLL2 configuration */
const ccm_analog_frac_pll_config_t g_audioPll2Config = {
    .refSel = kANALOG_PllRefOsc25M, /*!< PLL reference OSC25M */
    .refDiv = 5U,                   /*!< PLL input = 25 / 5 = 5M */
    .fractionDiv = 0U,
    .intDiv = 64U, /*!< Integer and fractional Divider output  = 5 * (1 + 64) * 8 = 2600MHZ */
    .outDiv = 4U,  /*!< Pll out frequency  = 2600 / 4 = 650MHZ */
};

/* VIDEO PLL1 configuration */
const ccm_analog_frac_pll_config_t g_videoPll1Config = {
    .refSel = kANALOG_PllRefOsc25M, /*!< PLL reference OSC25M */
    .refDiv = 5U,                   /*!< PLL input = 25 / 5 = 5M */
    .fractionDiv = 0U,
    .intDiv = 64U, /*!< Integer and fractional Divider output  = 5 * (1 + 64) * 8 = 2600MHZ */
    .outDiv = 4U,  /*!< Pll out frequency  = 2600 / 4 = 650MHZ */
};

/* SYSTEM PLL1 configuration */
const ccm_analog_sscg_pll_config_t g_sysPll1Config = {
    .refSel = kANALOG_PllRefOsc25M, /*!< PLL reference OSC25M */
    .refDiv1 = 1U,                  /*!< PLL1 input = 25 / 1 = 25MHZ */
    .loopDivider1 = 32U,            /*!< PLL1 output  = 25 * 32 * 2 = 1600MHZ */
    .refDiv2 = 24U,                 /*!< PLL2 input  = 1600 / 24 = 66.66MHZ */
    .loopDivider2 = 12U,            /*!< PLL2 output  = 12 * 66.66 * 2 = 1600MHZ */
    .outDiv = 1U,                   /*!< PLL output = 1600 / 2 / 1 = 800MHZ */
};

/* SYSTEM PLL2 configuration */
const ccm_analog_sscg_pll_config_t g_sysPll2Config = {
    .refSel = kANALOG_PllRefOsc25M, /*!< PLL reference OSC25M */
    .refDiv1 = 1U,                  /*!< PLL1 input = 25 / 1 = 25MHZ */
    .loopDivider1 = 32U,            /*!< PLL1 output  = 25 * 32 * 2 = 1600MHZ */
    .refDiv2 = 16U,                 /*!< PLL2 input  = 1600 / 16 = 100MHZ */
    .loopDivider2 = 10U,            /*!< PLL2 output  = 10 * 100 * 2 = 2000MHZ */
    .outDiv = 1U,                   /*!< PLL output = 2000 / 2 / 1 = 1000MHZ */
};

/* SYSTEM PLL3 configuration */
const ccm_analog_sscg_pll_config_t g_sysPll3Config = {
    .refSel = kANALOG_PllRefOsc25M, /*!< PLL reference OSC25M */
    .refDiv1 = 1U,                  /*!< PLL1 input = 25 / 1 = 25MHZ */
    .loopDivider1 = 32U,            /*!< PLL1 output  = 25 * 32 * 2 = 1600MHZ */
    .refDiv2 = 16U,                 /*!< PLL2 input  = 1600 / 16 = 100MHZ */
    .loopDivider2 = 10U,            /*!< PLL2 output  = 10 * 100 * 2 = 2000MHZ */
    .outDiv = 1U,                   /*!< PLL output = 2000 / 2 / 1 = 1000MHZ */
};
/*******************************************************************************
 * Variables
 ******************************************************************************/
/* System clock frequency. */
extern uint32_t SystemCoreClock;

/*******************************************************************************
 * Code
 ******************************************************************************/
void BOARD_BootClockRUN(void)
{
    /* OSC configuration */
    CLOCK_InitOSC25M(&g_osc25MConfig);
    CLOCK_InitOSC27M(&g_osc27MConfig);

    /* switch AXI AHB IPG root to 25M first */
    CLOCK_SetRootMux(kCLOCK_RootAxi, kCLOCK_AxiRootmuxOsc25m);
    CLOCK_SetRootMux(kCLOCK_RootAhb, kCLOCK_AhbRootmuxOsc25m);
    CLOCK_SetRootMux(kCLOCK_RootM4, kCLOCK_M4RootmuxOsc25m);
    /* switch NOC root to 25M first */
    CLOCK_SetRootMux(kCLOCK_RootNoc, 0U);
    
    CLOCK_InitSysPll1(&g_sysPll1Config);     /* init SYSTEM PLL1 run at 800MHZ */
    CLOCK_InitSysPll2(&g_sysPll2Config);     /* init SYSTEM PLL2 run at 1000MHZ */
    CLOCK_InitSysPll3(&g_sysPll3Config);     /* init SYSTEM PLL3 run at 1000MHZ */
    
    CLOCK_InitAudioPll1(&g_audioPll1Config); /* init AUDIO PLL1 run at 650MHZ */
    CLOCK_InitAudioPll2(&g_audioPll2Config); /* init AUDIO PLL2 run at 650MHZ */
    CLOCK_InitVideoPll1(&g_videoPll1Config); /* init VIDEO PLL1 run at 650MHZ */
    
    CLOCK_SetRootMux(kCLOCK_RootM4, kCLOCK_M4RootmuxSysPll1Div3); /* switch cortex-m4 to SYSTEM pll1 */
    
    CLOCK_SetRootMux(kCLOCK_RootNoc, 3U); /* switch NOC to SYSTEM pll1 DIV3*/ 
    
    CLOCK_SetRootDivider(kCLOCK_RootAhb, 1U, 1U);
    CLOCK_SetRootMux(kCLOCK_RootAhb, kCLOCK_AhbRootmuxSysPll1Div6); /* switch AHB to SYSTEM PLL1 DIV6 = 133MHZ */
    
    CLOCK_SetRootDivider(kCLOCK_RootAxi, 3U, 1U);
    CLOCK_SetRootMux(kCLOCK_RootAxi, kCLOCK_AxiRootmuxSysPll1); /* switch AXI to SYSTEM PLL1 = 266MHZ */

    
    CLOCK_SetRootMux(kCLOCK_RootUart2, kCLOCK_UartRootmuxSysPll1Div10); /* Set UART source to SysPLL1 Div10 80MHZ */
    CLOCK_SetRootDivider(kCLOCK_RootUart2, 1U, 1U);                  /* Set root clock to 80MHZ/ 1= 80MHZ */   
    
    CLOCK_EnableClock(kCLOCK_Rdc);   /* Enable RDC clock */
    
    /* Disable unused PLL */
    CLOCK_DeinitSysPll3();
    CLOCK_DeinitVedioPll1();
    CLOCK_DeinitAudioPll1();
    CLOCK_DeinitAudioPll2();
    /* Update core clock */
    SystemCoreClockUpdate();
}
