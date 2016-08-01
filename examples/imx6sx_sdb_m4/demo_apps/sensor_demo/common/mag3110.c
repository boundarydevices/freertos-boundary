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
#include "i2c_xfer.h"
#include "mag3110.h"

/*FUNCTION****************************************************************
*
* Function Name    : MAG3110_Init
* Returned Value   : result
* Comments         : Initialize MAG3110 3-Axis digital magnetometer.
*
*END*********************************************************************/
bool MAG3110_Init(mag3110_handle_t *handle, const mag3110_init_t *mag3110_config)
{
    uint8_t setVal;
    mag3110_data_t mag3110Data;

    /* Place MAG3110 into standby mode. */
    if (!MAG3110_WriteReg(handle, MAG3110_CTRL_REG1, 0x00))
        return false;

    /* Dummy read to de-assert INT pin. */
    MAG3110_ReadData(handle, &mag3110Data, mag3110FastReadFull16Bit);

    /* Set data output rate, oversample ratio and fast read mode. */
    // There are many combination of data output rate and over sample ratio.
    // Each combination corresponds to different consumption Level.
    // Refer to MAG3110 datasheet page 20 for detail.
    setVal = (uint8_t)mag3110_config->dataRate | (uint8_t)mag3110_config->overSample | (uint8_t)mag3110_config->fastReadMode;
    if (!MAG3110_WriteReg(handle, MAG3110_CTRL_REG1, setVal))
        return false;

    /* Set automatic magnetic sensor reset and correction mode. */
	setVal = (uint8_t)mag3110_config->autoReset | (uint8_t)mag3110_config->correctionMode;
    if (!MAG3110_WriteReg(handle, MAG3110_CTRL_REG2, setVal))
        return false;

    return true;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : MAG3110_Deinit
 * Description   : Disable the MAG3110 and reset register content.
 *
 *END**************************************************************************/
bool MAG3110_Deinit(mag3110_handle_t *handle)
{
    /* Clean all MAG3110 registers. */
    if (!MAG3110_WriteReg(handle, MAG3110_CTRL_REG1, 0x00) ||
        !MAG3110_WriteReg(handle, MAG3110_CTRL_REG2, 0x00) ||
        !MAG3110_WriteReg(handle, MAG3110_OFF_X_MSB, 0x00) ||
        !MAG3110_WriteReg(handle, MAG3110_OFF_X_LSB, 0x00) ||
        !MAG3110_WriteReg(handle, MAG3110_OFF_Y_MSB, 0x00) ||
        !MAG3110_WriteReg(handle, MAG3110_OFF_Y_LSB, 0x00) ||
        !MAG3110_WriteReg(handle, MAG3110_OFF_Z_MSB, 0x00) ||
        !MAG3110_WriteReg(handle, MAG3110_OFF_Z_LSB, 0x00))
        return true;
    else
        return false;
}

/*FUNCTION****************************************************************
*
* Function Name    : MAG3110_Enable
* Returned Value   : result
* Comments         : Enable the MAG3110 sensor.
*
*END*********************************************************************/
bool MAG3110_Enable(mag3110_handle_t *handle)
{
    uint8_t regVal;

    if (!MAG3110_ReadReg(handle, MAG3110_CTRL_REG1, &regVal))
        return false;

    /* Active MAG3110. */
    regVal |= 0x01;

    if (!MAG3110_WriteReg(handle, MAG3110_CTRL_REG1, regVal))
        return false;

    return true;
}

/*FUNCTION****************************************************************
*
* Function Name    : MAG3110_Disable
* Returned Value   : result
* Comments         : Disable the MAG3110 sensor.
*
*END*********************************************************************/
bool MAG3110_Disable(mag3110_handle_t *handle)
{
    uint8_t regVal;

    if (!MAG3110_ReadReg(handle, MAG3110_CTRL_REG1, &regVal))
        return false;

    /* De-active MAG3110.*/
    regVal &= ~0x01;

    if (!MAG3110_WriteReg(handle, MAG3110_CTRL_REG1, regVal))
        return false;

    return true;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : MAG3110_WriteReg
 * Description   : Write the specified register of MAG3110.
 * The writing process is through I2C.
 *END**************************************************************************/
bool MAG3110_WriteReg(mag3110_handle_t *handle, uint8_t regAddr, uint8_t regVal)
{
    uint8_t cmdBuffer[2];

    cmdBuffer[0] = handle->address << 1;
    cmdBuffer[1] = regAddr;

    return I2C_XFER_SendDataBlocking(handle->device, cmdBuffer, 2, &regVal, 1); 
}

/*FUNCTION**********************************************************************
 *
 * Function Name : MAG3110_ReadReg
 * Description   : Read the specified register value of MAG3110.
 * The reading process is through I2C.
 *END**************************************************************************/
bool MAG3110_ReadReg(mag3110_handle_t *handle, uint8_t regAddr, uint8_t *regValPtr)
{
    uint8_t cmdBuffer[3];

    cmdBuffer[0] = handle->address << 1;
    cmdBuffer[1] = regAddr;
    cmdBuffer[2] = (handle->address << 1) + 1;

    return I2C_XFER_ReceiveDataBlocking(handle->device, cmdBuffer, 3, regValPtr, 1);
}

/*FUNCTION****************************************************************
*
* Function Name    : MAG3110_ReadData
* Returned Value   : result
* Comments         : Get current 3-axis magnetic field strength.
*
*END*********************************************************************/
bool MAG3110_ReadData(mag3110_handle_t *handle, mag3110_data_t *val, mag3110_fast_read_mode_t fastRead)
{
    uint8_t rxBuffer[6];
    uint8_t cmdBuffer[3];

    /* Fetch Current magnetic field strength in 3 Axis. */
    cmdBuffer[0] = handle->address << 1;
    cmdBuffer[1] = MAG3110_OUT_X_MSB;
    cmdBuffer[2] = (handle->address << 1) + 1;

    /* For fast read mode is full 16-bit value. */
    if(fastRead == mag3110FastReadFull16Bit)
    {
        if (!I2C_XFER_ReceiveDataBlocking(handle->device, cmdBuffer, 3, rxBuffer, 6))
            return false;
        val->magX = (int16_t)((rxBuffer[0] << 8) + rxBuffer[1]);
        val->magY = (int16_t)((rxBuffer[2] << 8) + rxBuffer[3]);
        val->magZ = (int16_t)((rxBuffer[4] << 8) + rxBuffer[5]);
	}
    else /* For fast read mode is MSB 8-bit value. */
    {
        if (!I2C_XFER_ReceiveDataBlocking(handle->device, cmdBuffer, 3, rxBuffer, 3))
            return false;
        val->magX = (int8_t)rxBuffer[0];
        val->magY = (int8_t)rxBuffer[1];
        val->magZ = (int8_t)rxBuffer[2];
    }

    return true;
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
