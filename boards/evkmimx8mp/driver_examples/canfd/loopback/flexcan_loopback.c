/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_debug_console.h"
#include "fsl_flexcan.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"

#include "fsl_gpio.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define EXAMPLE_CAN                FLEXCAN1
#define EXAMPLE_FLEXCAN_IRQn       CAN_FD1_IRQn
#define EXAMPLE_FLEXCAN_IRQHandler CAN_FD1_IRQHandler
#define EXAMPLE_CAN_CLK_SOURCE     (kFLEXCAN_ClkSrcPeri)
#define EXAMPLE_CAN_CLK_FREQ                                                                    \
    (CLOCK_GetPllFreq(kCLOCK_SystemPll1Ctrl) / (CLOCK_GetRootPreDivider(kCLOCK_RootFlexCan1)) / \
     (CLOCK_GetRootPostDivider(kCLOCK_RootFlexCan1)))
/* Set USE_IMPROVED_TIMING_CONFIG macro to use api to calculates the improved CAN / CAN FD timing values. */
#define USE_IMPROVED_TIMING_CONFIG (1U)

#define USE_CANFD \
    (1) /* Define USE_CANFD to no-zero value to evaluate CANFD mode, define to 0 to use classical CAN mode*/

#define RX_MESSAGE_BUFFER_NUM (9)
#define TX_MESSAGE_BUFFER_NUM (8)

/* Fix MISRA_C-2012 Rule 17.7. */
#define LOG_INFO (void)PRINTF

#if (defined(USE_CANFD) && USE_CANFD)
/*
 *    DWORD_IN_MB    DLC    BYTES_IN_MB             Maximum MBs
 *    2              8      kFLEXCAN_8BperMB        64
 *    4              10     kFLEXCAN_16BperMB       42
 *    8              13     kFLEXCAN_32BperMB       25
 *    16             15     kFLEXCAN_64BperMB       14
 *
 * Dword in each message buffer, Length of data in bytes, Payload size must align,
 * and the Message Buffers are limited corresponding to each payload configuration:
 */
#define DWORD_IN_MB (16)
#define DLC         (15)
#define BYTES_IN_MB kFLEXCAN_64BperMB
#else
#define DLC (8)
#endif
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
volatile bool rxComplete = false;
#if (defined(USE_CANFD) && USE_CANFD)
flexcan_fd_frame_t txFrame, rxFrame;
#else
flexcan_frame_t txFrame, rxFrame;
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/

void EXAMPLE_FLEXCAN_IRQHandler(void)
{
#if (defined(FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER)) && (FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER > 0)
    uint64_t flag = 1U;
#else
    uint32_t flag = 1U;
#endif
    /* If new data arrived. */
    if (0U != FLEXCAN_GetMbStatusFlags(EXAMPLE_CAN, flag << RX_MESSAGE_BUFFER_NUM))
    {
        FLEXCAN_ClearMbStatusFlags(EXAMPLE_CAN, flag << RX_MESSAGE_BUFFER_NUM);
#if (defined(USE_CANFD) && USE_CANFD)
        (void)FLEXCAN_ReadFDRxMb(EXAMPLE_CAN, RX_MESSAGE_BUFFER_NUM, &rxFrame);
#else
        (void)FLEXCAN_ReadRxMb(EXAMPLE_CAN, RX_MESSAGE_BUFFER_NUM, &rxFrame);
#endif
        rxComplete = true;
    }
    SDK_ISR_EXIT_BARRIER;
}

/*!
 * @brief Main function
 */
int main(void)
{
    flexcan_config_t flexcanConfig;
    flexcan_rx_mb_config_t mbConfig;
#if (defined(FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER)) && (FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER > 0)
    uint64_t flag = 1U;
#else
    uint32_t flag = 1U;
#endif

    /* Initialize board hardware. */
    /* M7 has its local cache and enabled by default,
     * need to set smart subsystems (0x28000000 ~ 0x3FFFFFFF)
     * non-cacheable before accessing this address region */
    BOARD_InitMemory();

    /* Board specific RDC settings */
    BOARD_RdcInit();

    BOARD_InitBootPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();

    CLOCK_SetRootMux(kCLOCK_RootFlexCan1, kCLOCK_FlexCanRootmuxSysPll1); /* Set FLEXCAN1 source to SYSTEM PLL1 800MHZ */
    CLOCK_SetRootDivider(kCLOCK_RootFlexCan1, 2U, 5U);                   /* Set root clock to 800MHZ / 10 = 80MHZ */

    LOG_INFO("\r\n==FlexCAN loopback functional example -- Start.==\r\n\r\n");

    /* Init FlexCAN module. */
    /*
     * flexcanConfig.clkSrc                 = kFLEXCAN_ClkSrc0;
     * flexcanConfig.bitRate                = 1000000U;
     * flexcanConfig.bitRateFD              = 2000000U;
     * flexcanConfig.maxMbNum               = 16;
     * flexcanConfig.enableLoopBack         = false;
     * flexcanConfig.enableSelfWakeup       = false;
     * flexcanConfig.enableIndividMask      = false;
     * flexcanConfig.disableSelfReception   = false;
     * flexcanConfig.enableListenOnlyMode   = false;
     * flexcanConfig.enableDoze             = false;
     */
    FLEXCAN_GetDefaultConfig(&flexcanConfig);

#if defined(EXAMPLE_CAN_CLK_SOURCE)
    flexcanConfig.clkSrc = EXAMPLE_CAN_CLK_SOURCE;
#endif

    flexcanConfig.enableLoopBack = true;

#if (defined(USE_IMPROVED_TIMING_CONFIG) && USE_IMPROVED_TIMING_CONFIG)
    flexcan_timing_config_t timing_config;
    memset(&timing_config, 0, sizeof(flexcan_timing_config_t));
#if (defined(USE_CANFD) && USE_CANFD)
    if (FLEXCAN_FDCalculateImprovedTimingValues(EXAMPLE_CAN, flexcanConfig.bitRate, flexcanConfig.bitRateFD,
                                                EXAMPLE_CAN_CLK_FREQ, &timing_config))
    {
        /* Update the improved timing configuration*/
        memcpy(&(flexcanConfig.timingConfig), &timing_config, sizeof(flexcan_timing_config_t));
    }
    else
    {
        LOG_INFO("No found Improved Timing Configuration. Just used default configuration\r\n\r\n");
    }
#else
    if (FLEXCAN_CalculateImprovedTimingValues(EXAMPLE_CAN, flexcanConfig.bitRate, EXAMPLE_CAN_CLK_FREQ, &timing_config))
    {
        /* Update the improved timing configuration*/
        memcpy(&(flexcanConfig.timingConfig), &timing_config, sizeof(flexcan_timing_config_t));
    }
    else
    {
        LOG_INFO("No found Improved Timing Configuration. Just used default configuration\r\n\r\n");
    }
#endif
#endif

#if (defined(USE_CANFD) && USE_CANFD)
    FLEXCAN_FDInit(EXAMPLE_CAN, &flexcanConfig, EXAMPLE_CAN_CLK_FREQ, BYTES_IN_MB, true);
#else
    FLEXCAN_Init(EXAMPLE_CAN, &flexcanConfig, EXAMPLE_CAN_CLK_FREQ);
#endif

    /* Setup Rx Message Buffer. */
    mbConfig.format = kFLEXCAN_FrameFormatStandard;
    mbConfig.type   = kFLEXCAN_FrameTypeData;
    mbConfig.id     = FLEXCAN_ID_STD(0x123);
#if (defined(USE_CANFD) && USE_CANFD)
    FLEXCAN_SetFDRxMbConfig(EXAMPLE_CAN, RX_MESSAGE_BUFFER_NUM, &mbConfig, true);
#else
    FLEXCAN_SetRxMbConfig(EXAMPLE_CAN, RX_MESSAGE_BUFFER_NUM, &mbConfig, true);
#endif

/* Setup Tx Message Buffer. */
#if (defined(USE_CANFD) && USE_CANFD)
    FLEXCAN_SetFDTxMbConfig(EXAMPLE_CAN, TX_MESSAGE_BUFFER_NUM, true);
#else
    FLEXCAN_SetTxMbConfig(EXAMPLE_CAN, TX_MESSAGE_BUFFER_NUM, true);
#endif

    /* Enable Rx Message Buffer interrupt. */
    FLEXCAN_EnableMbInterrupts(EXAMPLE_CAN, flag << RX_MESSAGE_BUFFER_NUM);
    (void)EnableIRQ(EXAMPLE_FLEXCAN_IRQn);

    /* Prepare Tx Frame for sending. */
    txFrame.format = (uint8_t)kFLEXCAN_FrameFormatStandard;
    txFrame.type   = (uint8_t)kFLEXCAN_FrameTypeData;
    txFrame.id     = FLEXCAN_ID_STD(0x123);
    txFrame.length = (uint8_t)DLC;
#if (defined(USE_CANFD) && USE_CANFD)
    txFrame.brs = 1U;
#endif
#if (defined(USE_CANFD) && USE_CANFD)
    uint8_t i = 0;
    for (i = 0; i < DWORD_IN_MB; i++)
    {
        txFrame.dataWord[i] = i;
    }
#else
    txFrame.dataWord0 = CAN_WORD0_DATA_BYTE_0(0x11) | CAN_WORD0_DATA_BYTE_1(0x22) | CAN_WORD0_DATA_BYTE_2(0x33) |
                        CAN_WORD0_DATA_BYTE_3(0x44);
    txFrame.dataWord1 = CAN_WORD1_DATA_BYTE_4(0x55) | CAN_WORD1_DATA_BYTE_5(0x66) | CAN_WORD1_DATA_BYTE_6(0x77) |
                        CAN_WORD1_DATA_BYTE_7(0x88);
#endif

    LOG_INFO("Send message from MB%d to MB%d\r\n", TX_MESSAGE_BUFFER_NUM, RX_MESSAGE_BUFFER_NUM);
#if (defined(USE_CANFD) && USE_CANFD)
    for (i = 0; i < DWORD_IN_MB; i++)
    {
        LOG_INFO("tx word%d = 0x%x\r\n", i, txFrame.dataWord[i]);
    }
#else
    LOG_INFO("tx word0 = 0x%x\r\n", txFrame.dataWord0);
    LOG_INFO("tx word1 = 0x%x\r\n", txFrame.dataWord1);
#endif

/* Send data through Tx Message Buffer using polling function. */
#if (defined(USE_CANFD) && USE_CANFD)
    (void)FLEXCAN_TransferFDSendBlocking(EXAMPLE_CAN, TX_MESSAGE_BUFFER_NUM, &txFrame);
#else
    (void)FLEXCAN_TransferSendBlocking(EXAMPLE_CAN, TX_MESSAGE_BUFFER_NUM, &txFrame);
#endif

    /* Waiting for Message receive finish. */
    while (!rxComplete)
    {
    }

    LOG_INFO("\r\nReceived message from MB%d\r\n", RX_MESSAGE_BUFFER_NUM);
#if (defined(USE_CANFD) && USE_CANFD)
    for (i = 0; i < DWORD_IN_MB; i++)
    {
        LOG_INFO("rx word%d = 0x%x\r\n", i, rxFrame.dataWord[i]);
    }
#else
    LOG_INFO("rx word0 = 0x%x\r\n", rxFrame.dataWord0);
    LOG_INFO("rx word1 = 0x%x\r\n", rxFrame.dataWord1);
#endif

    /* Stop FlexCAN Send & Receive. */
    FLEXCAN_DisableMbInterrupts(EXAMPLE_CAN, flag << RX_MESSAGE_BUFFER_NUM);

    LOG_INFO("\r\n==FlexCAN loopback functional example -- Finish.==\r\n");

    while (true)
    {
    }
}
