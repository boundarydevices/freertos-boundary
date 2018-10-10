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

#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "fsl_ecspi.h"
#include "board.h"

#include "pin_mux.h"
#include "clock_config.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define ECSPI_TRANSFER_SIZE 64
#define ECSPI_TRANSFER_BAUDRATE 500000U
#define ECSPI_MASTER_BASEADDR ECSPI1
#define ECSPI_MASTER_CLK_FREQ  \
         CLOCK_GetPllFreq(kCLOCK_SystemPll1Ctrl) / (CLOCK_GetRootPreDivider(kCLOCK_RootEcspi1)) / \
        (CLOCK_GetRootPostDivider(kCLOCK_RootEcspi1))
#define ECSPI_MASTER_TRANSFER_CHANNEL kECSPI_Channel0

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief Main function
 */
int main(void)
{
    uint8_t i;
    ecspi_transfer_t masterXfer;
    ecspi_master_config_t masterConfig;
    uint32_t masterRxData[ECSPI_TRANSFER_SIZE] = {0};
    uint32_t masterTxData[ECSPI_TRANSFER_SIZE] = {0};

    /* Init board hardware. */
    /* Board specific RDC settings */
    BOARD_RdcInit();
    
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();
    BOARD_InitMemory();
    
    
    CLOCK_SetRootMux(kCLOCK_RootEcspi1, kCLOCK_EcspiRootmuxSysPll1); /* Set ECSPI1 source to SYSTEM PLL1 800MHZ */
    CLOCK_SetRootDivider(kCLOCK_RootEcspi1, 2U, 5U);                 /* Set root clock to 800MHZ / 10 = 80MHZ */

    PRINTF("\r\n***ECSPI Loopback Demo***\r\n");
    PRINTF("\r\nThis demo is a loopback transfer test for ECSPI.\r\n");
    PRINTF("The ECSPI will connect the transmitter and receiver sections internally.\r\n");
    PRINTF("So, there is no need to connect the MOSI and MISO pins.\r\n");

    /* Master config:
     * masterConfig.channel = kECSPI_Channel0;
     * masterConfig.burstLength = 8;
     * masterConfig.samplePeriodClock = kECSPI_spiClock;
     * masterConfig.baudRate_Bps = TRANSFER_BAUDRATE;
     * masterConfig.chipSelectDelay = 0;
     * masterConfig.samplePeriod = 0;
     * masterConfig.txFifoThreshold = 1;
     * masterConfig.rxFifoThreshold = 0;
     * masterConfig.enableLoopback = true;
     */
    ECSPI_MasterGetDefaultConfig(&masterConfig);
    masterConfig.baudRate_Bps = ECSPI_TRANSFER_BAUDRATE;
    masterConfig.enableLoopback = true;
    ECSPI_MasterInit(ECSPI_MASTER_BASEADDR, &masterConfig, ECSPI_MASTER_CLK_FREQ);

    for (i = 0; i < ECSPI_TRANSFER_SIZE; i++)
    {
        masterTxData[i] = i;
    }
    /*Start master transfer*/
    masterXfer.txData = masterTxData;
    masterXfer.rxData = masterRxData;
    masterXfer.dataSize = ECSPI_TRANSFER_SIZE;
    masterXfer.channel = ECSPI_MASTER_TRANSFER_CHANNEL;
    ECSPI_MasterTransferBlocking(ECSPI_MASTER_BASEADDR, &masterXfer);

    /* Compare Tx and Rx data. */
    for (i = 0; i < ECSPI_TRANSFER_SIZE; i++)
    {
        if (masterTxData[i] != masterRxData[i])
        {
            break;
        }
    }

    if (ECSPI_TRANSFER_SIZE == i)
    {
        PRINTF("\r\nECSPI loopback test pass!");
    }
    else
    {
        PRINTF("\r\nECSPI loopback test fail!");
    }

    /* Deinit the ECSPI. */
    ECSPI_Deinit(ECSPI_MASTER_BASEADDR);

    while (1)
    {
        __NOP();
    }
}
