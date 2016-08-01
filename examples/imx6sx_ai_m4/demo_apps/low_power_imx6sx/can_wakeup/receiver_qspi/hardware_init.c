/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
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

#include "board.h"
#include "pin_mux.h"
#include "i2c_imx.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @brief MAG3110 Registers address definition. */
#define MAX7310_INTPUT_PORT                 (0x00)
#define MAX7310_OUTPUT_PORT                 (0x01)
#define MAX7310_POLARITY_INVERSION          (0x02)
#define MAX7310_CONFIGURATION               (0x03)
#define MAX7310_TIMEOUT                     (0x04)

/*! @brief i2c send data in polling mode as master. */
static bool I2C_MasterSendDataPolling(I2C_Type *base,
                                      const uint8_t *cmdBuff,
                                      uint32_t cmdSize,
                                      const uint8_t *txBuff,
                                      uint32_t txSize);
/*! @brief wake up the can transceiver. */
static void FLEXCAN_WakeupTransceiver(void);

void hardware_init(void)
{
    /* Board specific RDC settings */
    BOARD_RdcInit();

    /* Board specific clock settings */
    BOARD_ClockInit();

    /* initialize debug uart */
    dbg_uart_init();

    /* In this demo, we need to share SEMA4 access between domains */
    RDC_SetPdapAccess(RDC, BOARD_SEMA4_RDC_PDAP, 0xFF, false, false);

    /* In this example, we need to grasp board MUB exclusively */
    RDC_SetPdapAccess(RDC, BOARD_MU_RDC_PDAP, 3 << (BOARD_DOMAIN_ID * 2), false, false);

    /* In this example, we need to grasp board flexcan exclusively */
    RDC_SetPdapAccess(RDC, BOARD_FLEXCAN_RDC_PDAP, 3 << (BOARD_DOMAIN_ID * 2), false, false);

    /* Select board flexcan derived from OSC clock(24M) */
    CCM_SetRootMux(CCM, BOARD_FLEXCAN_CCM_ROOT, ccmRootmuxPerclkClkOsc24m);

    /* Set relevant divider = 1. */
    CCM_SetRootDivider(CCM, BOARD_FLEXCAN_CCM_DIV, 0);

    /* Enable flexcan clock */
    CCM_ControlGate(CCM, BOARD_FLEXCAN_CCM_CCGR, ccmClockNeededAll);
    CCM_ControlGate(CCM, BOARD_FLEXCAN_CCM_CCGR_SERIAL, ccmClockNeededAll);

    /* FLEXCAN Pin setting */
    configure_flexcan_pins(BOARD_FLEXCAN_BASEADDR);

    /* Select I2C clock derived from OSC clock(24M) */
    CCM_SetRootMux(CCM, BOARD_I2C_CCM_ROOT, ccmRootmuxPerclkClkOsc24m);
    /* Set relevant divider = 1. */
    CCM_SetRootDivider(CCM, BOARD_I2C_CCM_DIV, 0);

    /* Enable I2C3 clock */
    CCM_ControlGate(CCM, BOARD_I2C_CCM_CCGR, ccmClockNeededAll);

    /* I2C Pin setting */
    configure_i2c_pins(BOARD_I2C_BASEADDR);

    /* In this example, we need to grasp I2C exclusively to wake up can transceiver first*/
    RDC_SetPdapAccess(RDC, BOARD_I2C_RDC_PDAP, 3 <<(BOARD_DOMAIN_ID * 2), false, false);

    /* wake up the can transceiver */
    FLEXCAN_WakeupTransceiver();

    /* Then we should restore the i2c default PDAP setting */
    RDC_SetPdapAccess(RDC, BOARD_I2C_RDC_PDAP, 0xFF, false, false);
}

static bool I2C_MasterSendDataPolling(I2C_Type *base,
                                      const uint8_t *cmdBuff,
                                      uint32_t cmdSize,
                                      const uint8_t *txBuff,
                                      uint32_t txSize)
{
    if (I2C_GetStatusFlag(base, i2cStatusBusBusy))
        return false;

    /* Set I2C work under Tx mode */
    I2C_SetDirMode(base, i2cDirectionTransmit);

    /* Switch to Master Mode and Send Start Signal. */
    I2C_SetWorkMode(base, i2cModeMaster);

    /* Send first byte */
    if (0 != cmdSize)
    {
        I2C_WriteByte(base, *cmdBuff++);
        cmdSize--;
    }
    else
    {
        I2C_WriteByte(base, *txBuff++);
        txSize--;
    }
    while (1)
    {
        /* Wait I2C transmission status flag assert.  */
        while (!I2C_GetStatusFlag(base, i2cStatusInterrupt));

        /* Clear I2C transmission status flag. */
        I2C_ClearStatusFlag(base, i2cStatusInterrupt);

        /* Transmit complete. */
        if ((I2C_GetStatusFlag(base, i2cStatusReceivedAck)) ||
            ((0 == txSize) && (0 == cmdSize)))
        {
            /* Switch to Slave mode and Generate a Stop Signal. */
            I2C_SetWorkMode(base, i2cModeSlave);

            /* Switch back to Rx direction. */
            I2C_SetDirMode(base, i2cDirectionReceive);

            /* Wait until bus idle. */
            while (I2C_GetStatusFlag(base, i2cStatusBusBusy));

            return true;
        }
        else
        {
            if (0 != cmdSize)
            {
                I2C_WriteByte(base, *cmdBuff++);
                cmdSize--;
            }
            else
            {
                I2C_WriteByte(base, *txBuff++);
                txSize--;
            }
        }
    }
}

static void FLEXCAN_WakeupTransceiver(void)
{
    i2c_init_config_t i2cInitConfig = {
        .baudRate     = 400000u,
        .slaveAddress = 0x00
    };
    uint8_t cmdBuffer[5];
    uint8_t txBuffer[5];
    i2cInitConfig.clockRate = get_i2c_clock_freq(BOARD_I2C_BASEADDR);
    /* Enable ii2c driver */
    I2C_Init(BOARD_I2C_BASEADDR, &i2cInitConfig);
    /* Enable the I2C module */
    I2C_Enable(BOARD_I2C_BASEADDR);

    /* Set can wake-up pin as output */
    cmdBuffer[0] = BOARD_I2C_MAX7310_ADDR << 1;
    cmdBuffer[1] = MAX7310_CONFIGURATION;
    txBuffer[0]  = 0x7F;
    I2C_MasterSendDataPolling(BOARD_I2C_BASEADDR, cmdBuffer, 2, txBuffer, 1);

    /* Output '1' to trigger transceiver wake-up */
    cmdBuffer[0] = BOARD_I2C_MAX7310_ADDR << 1;
    cmdBuffer[1] = MAX7310_OUTPUT_PORT;
    txBuffer[0]  = 0x80;
    I2C_MasterSendDataPolling(BOARD_I2C_BASEADDR, cmdBuffer, 2, txBuffer, 1);

    /* Output '0' to clear transceiver wake-up */
    cmdBuffer[0] = BOARD_I2C_MAX7310_ADDR << 1;
    cmdBuffer[1] = MAX7310_OUTPUT_PORT;
    txBuffer[0]  = 0x00;
    I2C_MasterSendDataPolling(BOARD_I2C_BASEADDR, cmdBuffer, 2, txBuffer, 1);

    /* deinit i2c3 */
    I2C_Deinit(BOARD_I2C_BASEADDR);
}
/*******************************************************************************
 * EOF
 ******************************************************************************/
