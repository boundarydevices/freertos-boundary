/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "fsl_debug_console.h"
#include "fsl_sai.h"
#include "music.h"
#include "fsl_codec_common.h"
#include "fsl_wm8962.h"
#include "fsl_iomuxc.h"
#include "fsl_codec_adapter.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* SAI and I2C instance and clock */
#define DEMO_CODEC_WM8960
#define DEMO_SAI              SAI3
#define DEMO_SAI_CHANNEL      (0)
#define DEMO_SAI_IRQ          SAI3_IRQn
#define DEMO_SAITxIRQHandler  SAI3_IRQHandler
#define DEMO_SAI_TX_SYNC_MODE kSAI_ModeAsync
#define DEMO_SAI_RX_SYNC_MODE kSAI_ModeSync

#define DEMO_SAI_MASTER_SLAVE kSAI_Master

#define DEMO_AUDIO_DATA_CHANNEL (2U)
#define DEMO_AUDIO_BIT_WIDTH    kSAI_WordWidth16bits
#define DEMO_AUDIO_SAMPLE_RATE  (kSAI_SampleRate16KHz)
#define DEMO_AUDIO_MASTER_CLOCK DEMO_SAI_CLK_FREQ

/* Get frequency of sai1 clock */
#define SAI_CLOCK_ROOT    kCLOCK_Root_Sai3
#define SAI_CLOCK_GATE kCLOCK_Sai3
#define DEMO_SAI_CLK_FREQ CLOCK_GetIpFreq(SAI_CLOCK_ROOT)

/* I2C instance and clock */
#define DEMO_I2C LPI2C1

/* Get frequency of lpi2c clock */
#define LPI2C_MASTER_CLOCK_ROOT kCLOCK_Root_Lpi2c1
#define LPI2C_MASTER_CLOCK_GATE kCLOCK_Lpi2c1
#define DEMO_I2C_CLK_FREQ       CLOCK_GetIpFreq(LPI2C_MASTER_CLOCK_ROOT)
#define BOARD_MASTER_CLOCK_CONFIG()
#define BOARD_SAI_RXCONFIG(config, mode)
#ifndef DEMO_CODEC_INIT_DELAY_MS
#define DEMO_CODEC_INIT_DELAY_MS (1000U)
#endif
#ifndef DEMO_CODEC_VOLUME
#define DEMO_CODEC_VOLUME 100U
#endif
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
extern void BOARD_SAI_RXConfig(sai_transceiver_t *config, sai_sync_mode_t sync);
/*******************************************************************************
 * Variables
 ******************************************************************************/
wm8962_config_t wm8962Config = {
    .i2cConfig = {.codecI2CInstance = BOARD_CODEC_I2C_INSTANCE},
    .route =
        {
            .enableLoopBack            = false,
            .leftInputPGASource        = kWM8962_InputPGASourceInput1,
            .leftInputMixerSource      = kWM8962_InputMixerSourceInputPGA,
            .rightInputPGASource       = kWM8962_InputPGASourceInput3,
            .rightInputMixerSource     = kWM8962_InputMixerSourceInputPGA,
            .leftHeadphoneMixerSource  = kWM8962_OutputMixerDisabled,
            .leftHeadphonePGASource    = kWM8962_OutputPGASourceDAC,
            .rightHeadphoneMixerSource = kWM8962_OutputMixerDisabled,
            .rightHeadphonePGASource   = kWM8962_OutputPGASourceDAC,
        },
    .slaveAddress = WM8962_I2C_ADDR,
    .bus          = kWM8962_BusI2S,
    .format       = {.sampleRate = kWM8962_AudioSampleRate16KHz, .bitWidth = kWM8962_AudioBitWidth16bit},
    .fllClock =
        {
            .fllClockSource        = kWM8962_FLLClkSourceMCLK,
            .fllReferenceClockFreq = 12288000U,
            .fllOutputFreq         = 12288000U,
        },
    .sysclkSource = kWM8962_SysClkSourceMclk, /* use MCLK pin as sysclk's source */
    .masterSlave  = false,                    /* sai running as master mode, so codec running as slave mode */
};

codec_config_t boardCodecConfig = {.codecDevType = kCODEC_WM8962, .codecDevConfig = &wm8962Config};
static size_t g_index           = 0;
static volatile bool isFinished = false;
extern codec_config_t boardCodecConfig;
codec_handle_t codecHandle;
/*******************************************************************************
 * Code
 ******************************************************************************/

void DEMO_SAITxIRQHandler(void)
{
    uint8_t i     = 0;
    uint8_t j     = 0;
    uint32_t data = 0;
    uint32_t temp = 0;

    /* Clear the FIFO error flag */
    if (SAI_TxGetStatusFlag(DEMO_SAI) & kSAI_FIFOErrorFlag)
    {
        SAI_TxClearStatusFlags(DEMO_SAI, kSAI_FIFOErrorFlag);
    }

    if (SAI_TxGetStatusFlag(DEMO_SAI) & kSAI_FIFOWarningFlag)
    {
        for (i = 0; i < FSL_FEATURE_SAI_FIFO_COUNTn(DEMO_SAI); i++)
        {
            data = 0;
            for (j = 0; j < DEMO_AUDIO_BIT_WIDTH / 8U; j++)
            {
                temp = (uint32_t)(music[g_index]);
                data |= (temp << (8U * j));
                g_index++;
            }
            SAI_WriteData(DEMO_SAI, DEMO_SAI_CHANNEL, data);
        }
    }

    if (g_index >= MUSIC_LEN)
    {
        isFinished = true;
        SAI_TxDisableInterrupts(DEMO_SAI, kSAI_FIFOWarningInterruptEnable | kSAI_FIFOErrorInterruptEnable);
        SAI_TxEnable(DEMO_SAI, false);
    }
    SDK_ISR_EXIT_BARRIER;
}

void DelayMS(uint32_t ms)
{
    for (uint32_t i = 0; i < ms; i++)
    {
        SDK_DelayAtLeastUs(1000, SystemCoreClock);
    }
}

/*!
 * @brief Main function
 */
int main(void)
{
    sai_transceiver_t saiConfig;

    /* clang-format off */
    const clock_root_config_t lpi2cClkCfg = {
        .clockOff = false,
	.mux = 0, // 24MHz oscillator source
	.div = 1
    };
    const clock_root_config_t saiClkCfg = {
        .clockOff = false,
        .mux = 1, // select audiopll1out source(393216000 Hz)
        .div = 32, // output 12288000 Hz
    };
    sai_master_clock_t saiMasterCfg = {
        .mclkOutputEnable = true,
     };
    /* clang-format on */

    BOARD_InitBootPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();

    CLOCK_SetRootClock(LPI2C_MASTER_CLOCK_ROOT, &lpi2cClkCfg);
    CLOCK_EnableClock(LPI2C_MASTER_CLOCK_GATE);
    CLOCK_SetRootClock(SAI_CLOCK_ROOT, &saiClkCfg);
    CLOCK_EnableClock(SAI_CLOCK_GATE);
    CLOCK_SetRootClock(BOARD_ADP5585_I2C_CLOCK_ROOT, &lpi2cClkCfg);
    CLOCK_EnableClock(BOARD_ADP5585_I2C_CLOCK_GATE);

    /* Select SAI3 signals */
    adp5585_handle_t handle;
    BOARD_InitADP5585(&handle);
    ADP5585_SetDirection(&handle, (1 << BOARD_ADP5585_EXP_SEL), kADP5585_Output);
    ADP5585_ClearPins(&handle, (1 << BOARD_ADP5585_EXP_SEL));

    /* select MCLK direction(Enable MCLK clock) */
    saiMasterCfg.mclkSourceClkHz = DEMO_SAI_CLK_FREQ;            /* setup source clock for MCLK */
    saiMasterCfg.mclkHz          = saiMasterCfg.mclkSourceClkHz; /* setup target clock of MCLK */
    SAI_SetMasterClockConfig(DEMO_SAI, &saiMasterCfg);

    wm8962Config.i2cConfig.codecI2CSourceClock = DEMO_I2C_CLK_FREQ;
    wm8962Config.format.mclk_HZ                = DEMO_SAI_CLK_FREQ;

    PRINTF("SAI functional interrupt example started!\n\r");

    /* SAI init */
    SAI_Init(DEMO_SAI);
    /* I2S mode configurations */
    SAI_GetClassicI2SConfig(&saiConfig, DEMO_AUDIO_BIT_WIDTH, kSAI_Stereo, 1U << DEMO_SAI_CHANNEL);
    saiConfig.masterSlave = DEMO_SAI_MASTER_SLAVE;
    saiConfig.syncMode    = DEMO_SAI_TX_SYNC_MODE;
    SAI_TxSetConfig(DEMO_SAI, &saiConfig);
    /* set bit clock divider */
    SAI_TxSetBitClockRate(DEMO_SAI, DEMO_AUDIO_MASTER_CLOCK, DEMO_AUDIO_SAMPLE_RATE, DEMO_AUDIO_BIT_WIDTH,
                          DEMO_AUDIO_DATA_CHANNEL);

    /* sai rx configurations */
    BOARD_SAI_RXCONFIG(&saiConfig, DEMO_SAI_RX_SYNC_MODE);
    /* master clock configurations */
    BOARD_MASTER_CLOCK_CONFIG();

    /* Use default setting to init codec */
    if (CODEC_Init(&codecHandle, &boardCodecConfig) != kStatus_Success)
    {
        assert(false);
    }
    if (CODEC_SetVolume(&codecHandle, kCODEC_PlayChannelHeadphoneLeft | kCODEC_PlayChannelHeadphoneRight,
                        DEMO_CODEC_VOLUME) != kStatus_Success)
    {
        assert(false);
    }
    /* delay for codec output stable */
    DelayMS(DEMO_CODEC_INIT_DELAY_MS);

    /*  Enable interrupt */
    EnableIRQ(DEMO_SAI_IRQ);
    SAI_TxEnableInterrupts(DEMO_SAI, kSAI_FIFOWarningInterruptEnable | kSAI_FIFOErrorInterruptEnable);
    SAI_TxEnable(DEMO_SAI, true);

    /* Wait until finished */
    while (isFinished != true)
    {
    }

    PRINTF("\n\r SAI functional interrupt example finished!\n\r ");
    while (1)
    {
    }
}
