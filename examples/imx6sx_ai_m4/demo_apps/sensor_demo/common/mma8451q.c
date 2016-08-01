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

#include <stdint.h>
#include <stdbool.h>
#include "board.h"
#include "debug_console_imx.h"
#include "i2c_xfer.h"
#include "mma8451q.h"

static uint8_t mma8451qRangMode;

/*FUNCTION****************************************************************
*
* Function Name    : MMA8451Q_Init
* Returned Value   : true or false
* Comments         : Initialize MMA8451Q 3-axis accelerometer sensor.
*
*END*********************************************************************/
bool MMA8451Q_Init(mma8451q_handle_t *handle, const mma8451q_init_t *mma8451qConfig)
{
    uint8_t regVal;

    /* Place the MMA8451Q in Standby */
    if (!MMA8451Q_WriteReg(handle, MMA8451Q_CTRL_REG1, 0x00))
    {
        PRINTF("Place the MMA8451Q in standby mode ERROR\n\r");
        return false;
    }

    // write 0000 0000= 0x00 to MMA8451Q_XYZ_DATA_CFG register
    // [7]: reserved
    // [6]: reserved
    // [5]: reserved
    // [4]: hpf_out=0
    // [3]: reserved
    // [2]: reserved
    // [1-0]: fs=00 for 2g mode.
    if (!MMA8451Q_WriteReg(handle, MMA8451Q_XYZ_DATA_CFG, (uint8_t)mma8451qConfig->range))
    {
        PRINTF("Set the mode: 2G ...ERROR\n\r");
        return false;
    }
    mma8451qRangMode = (uint8_t)mma8451qConfig->range;

    /* Set data rate selection. */
    if (!MMA8451Q_WriteReg(handle, MMA8451Q_CTRL_REG1, (uint8_t)mma8451qConfig->dataRate))
    {
        PRINTF("Set data rate: 400HZ ...ERROR\n\r");
        return false;
    }

    /* Read WHO_AM_I device register, 0x1A. */
    if (!MMA8451Q_ReadReg(handle, MMA8451Q_WHO_AM_I, &regVal))
    {
        PRINTF("ERROR\n\r");
        return false;
    }
    if(regVal != MMA8451Q_DEVICE_ID)
    {
        PRINTF("Test WHO_AM_I check...ERROR\n\r");
        return false;
    }
    return true;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : MMA8451Q_Deinit
 * Description   : Disable the MMA8451Q and reset register content.
 *
 *END**************************************************************************/
bool MMA8451Q_Deinit(mma8451q_handle_t *handle)
{
    // Write 0000 0000 = 0x00 to CTRL_REG1 to place MMA8451Q into standby.
    if (!MMA8451Q_WriteReg(handle, MMA8451Q_CTRL_REG1, 0x00))
        return false;

    // Reset Register content.
    return MMA8451Q_WriteReg(handle, MMA8451Q_CTRL_REG2, 0x40);
}

/*FUNCTION****************************************************************
*
* Function Name    : MMA8451Q_Enable
* Returned Value   : result
* Comments         : Enable the MMA8451Q sensor.
*
*END*********************************************************************/
bool MMA8451Q_Enable(mma8451q_handle_t *handle)
{
    uint8_t regVal;

    if (!MMA8451Q_ReadReg(handle, MMA8451Q_CTRL_REG1, &regVal))
        return false;

    /* Active MMA8451Q and Enable Reduced noise mode */
    regVal |= 0x05;

    if (!MMA8451Q_WriteReg(handle, MMA8451Q_CTRL_REG1, regVal))
        return false;

    return true;
}

/*FUNCTION****************************************************************
*
* Function Name    : MMA8451Q_Disable
* Returned Value   : result
* Comments         : Disable the MMA8451Q sensor.
*
*END*********************************************************************/
bool MMA8451Q_Disable(mma8451q_handle_t *handle)
{
    uint8_t regVal;

    if (!MMA8451Q_ReadReg(handle, MMA8451Q_CTRL_REG1, &regVal))
        return false;

    /* De-active MMA8451Q & Disable Reduced noise mode*/
    regVal &= ~0x05;

    if (!MMA8451Q_WriteReg(handle, MMA8451Q_CTRL_REG1, regVal))
        return false;

    return true;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : MMA8451Q_WriteReg
 * Description   : Write the specified register of MMA8451Q.
 * The writing process is through I2C.
 *END**************************************************************************/
bool MMA8451Q_WriteReg(mma8451q_handle_t *handle, uint8_t regAddr, uint8_t regVal)
{
    uint8_t cmdBuffer[2];

    cmdBuffer[0] = handle->address << 1;
    cmdBuffer[1] = regAddr;

    return I2C_XFER_SendDataBlocking(handle->device, cmdBuffer, 2, &regVal, 1); 
}

/*FUNCTION**********************************************************************
 *
 * Function Name : MMA8451Q_ReadReg
 * Description   : Read the specified register value of MMA8451Q.
 * The reading process is through I2C.
 *END**************************************************************************/
bool MMA8451Q_ReadReg(mma8451q_handle_t *handle, uint8_t regAddr, uint8_t *regValPtr)
{
    uint8_t cmdBuffer[3];

    cmdBuffer[0] = handle->address << 1;
    cmdBuffer[1] = regAddr;
    cmdBuffer[2] = (handle->address << 1) + 1;

    return I2C_XFER_ReceiveDataBlocking(handle->device, cmdBuffer, 3, regValPtr, 1);
}

/*FUNCTION****************************************************************
*
* Function Name    : MMA8451Q_ReadData
* Returned Value   : true or false
* Comments         : Get current acceleration from MMA8451Q.
*
*END*********************************************************************/
bool MMA8451Q_ReadData(mma8451q_handle_t *handle, mma8451q_data_t *val)
{
    uint8_t rxBuffer[7];
    uint8_t cmdBuffer[3];

    cmdBuffer[0] = handle->address << 1;
    cmdBuffer[1] = MMA8451Q_OUT_X_MSB;
    cmdBuffer[2] = (handle->address << 1) + 1;
    if (!I2C_XFER_ReceiveDataBlocking(handle->device, cmdBuffer, 3, rxBuffer, 7))
        return false;

    val->accX = ((rxBuffer[0] << 8) & 0xff00) | rxBuffer[1];
    val->accY = ((rxBuffer[2] << 8) & 0xff00) | rxBuffer[3];
    val->accZ = ((rxBuffer[4] << 8) & 0xff00) | rxBuffer[5];
    val->accX = (int16_t)(val->accX) >> 2;
    val->accY = (int16_t)(val->accY) >> 2;
    val->accZ = (int16_t)(val->accZ) >> 2;

    if(mma8451qRangMode == mma8451qRang4gMode)
    {
        val->accX = (val->accX) << 1;
        val->accY = (val->accY) << 1;
        val->accZ = (val->accZ) << 1;
    }
    else if(mma8451qRangMode == mma8451qRang8gMode)
    {
        val->accX = (val->accX) << 2;
        val->accY = (val->accY) << 2;
        val->accZ = (val->accZ) << 2;
    }

    return true;
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
