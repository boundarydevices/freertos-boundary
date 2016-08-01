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
#include "gpio_pins.h"
#include "i2c_imx.h"

/*! @brief i2c send data in polling mode as master. */
static bool I2C_MasterSendDataPolling(I2C_Type *base,
                                      const uint8_t *txBuff,
                                      uint32_t txSize);
static void ISL29023_Reset(void);

void hardware_init(void)
{
    /* Board specific RDC settings */
    BOARD_RdcInit();

    /* Board specific clock settings */
    BOARD_ClockInit();

    /* initialize debug uart */
    dbg_uart_init();

    /* In this demo, we need to access RDC SEMAPHORE1 on this board */
    RDC_SetPdapAccess(RDC, rdcPdapRdcSema421, 0xFF, false, false);

     /* In this example, we need to grasp board I2C exclusively */
    RDC_SetPdapAccess(RDC, BOARD_I2C_RDC_PDAP, 3 << (BOARD_DOMAIN_ID * 2), false, false);

    /* In this demo, we need to share board GPIO, we can set sreq argument to true
     * when the peer core could also access GPIO with RDC_SEMAPHORE, or the peer
     * core doesn't access the GPIO at all */
    RDC_SetPdapAccess(RDC, BOARD_GPIO_SENSOR_ACC_RDC_PDAP, 0xFF, false/*true*/, false);

    /* Select I2C clock derived from OSC clock(24M) */
    CCM_SetRootMux(CCM, BOARD_I2C_CCM_ROOT, ccmRootmuxPerclkClkOsc24m);
    /* Set relevant divider = 1. */
    CCM_SetRootDivider(CCM, BOARD_I2C_CCM_DIV, 0);
    /* Enable I2C3 clock */
    CCM_ControlGate(CCM, BOARD_I2C_CCM_CCGR, ccmClockNeededAll);

    /* I2C Pin setting */
    configure_i2c_pins(BOARD_I2C_BASEADDR);

    /* Configure gpio pin IOMUX */
    configure_gpio_pin(BOARD_GPIO_SENSOR_ACC_CONFIG);
    configure_gpio_pin(BOARD_GPIO_SENSOR_MAG_ALS_CONFIG);

    /* We reset ISL29023 here because its interrupt pin is bound to
     * MAG3110's interrupt pin on SABRE Board. To avoid unexpected 
     * ISL29023 and its impact on MAG3110 Int Demo, this should be
     * done before getting into the real demo logic.
     */
    ISL29023_Reset();
}

static void ISL29023_Reset(void)
{
    i2c_init_config_t i2cInitConfig = {
        .baudRate     = 400000u,
        .slaveAddress = 0x32,
        .clockRate    = get_i2c_clock_freq(BOARD_I2C_BASEADDR)
    };

    /*
     * txBuffer[0]: ISL29023 I2C Slave Address;
     * txBuffer[1]: ISL29023 CTRL1 Register;
     * txBuffer[2]~txBuffer[10]: The default value of all ISL29023 Registers.
     */
    uint8_t txBuffer[11] = {0x88, 0x00, 0x00, 0x00, 0x00, 0x00,0x00, 0x00, 0xFF, 0xFF, 0x00};

    /* Deinit i2c module */
    I2C_Init(BOARD_I2C_BASEADDR, &i2cInitConfig);
    /* Enable the I2C module */
    I2C_Enable(BOARD_I2C_BASEADDR);
    /* Reset ISL29023 */
    I2C_MasterSendDataPolling(BOARD_I2C_BASEADDR, txBuffer, 11);

    /* Deinit i2c module */
    I2C_Deinit(BOARD_I2C_BASEADDR);
}

static bool I2C_MasterSendDataPolling(I2C_Type *base,
                                      const uint8_t *txBuff,
                                      uint32_t txSize)
{
    bool result = true;

    if (I2C_GetStatusFlag(base, i2cStatusBusBusy) || (0 == txSize))
        return false;

    /* Set I2C work under Tx mode */
    I2C_SetDirMode(base, i2cDirectionTransmit);

    /* Switch to Master Mode and Send Start Signal. */
    I2C_SetWorkMode(base, i2cModeMaster);

    do
    {
        /* Send data byte. */
        I2C_WriteByte(base, *txBuff++);
        txSize--;

        /* Wait I2C transmission status flag assert. */
        while (!I2C_GetStatusFlag(base, i2cStatusInterrupt)) {}

        /* Clear I2C transmission status flag. */
        I2C_ClearStatusFlag(base, i2cStatusInterrupt);

        /* If we received a NACK Signal, break and send Stop Signal. */
        if (I2C_GetStatusFlag(base, i2cStatusReceivedAck))
        {
            result = false;
            break;
        }

    } while (txSize);

    /* Switch to Slave mode and Generate a Stop Signal. */
    I2C_SetWorkMode(base, i2cModeSlave);

    /* Switch back to Rx direction. */
    I2C_SetDirMode(base, i2cDirectionReceive);

    /* Wait for I2C bus idle. */
    while (I2C_GetStatusFlag(base, i2cStatusBusBusy)) {}

    return result;
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
