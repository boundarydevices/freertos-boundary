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

#ifndef __MAG_3110_H__
#define __MAG_3110_H__

#include <stdint.h>
#include <stdbool.h>

/*!
 * @addtogroup mag3110
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @brief MAG3110 I2C address. */
#define MAG3110_ADDRESS             (0x0E)
#define MAG3110_ADDRESS_DEFAULT     (MAG3110_ADDRESS)

/*! @brief MAG3110 device ID number. */
#define MAG3110_DEVICE_ID           (0xC4)

/*! @brief MAG3110 Registers address definition. */
#define MAG3110_DR_STATUS           (0x00)
#define MAG3110_OUT_X_MSB           (0x01)
#define MAG3110_OUT_X_LSB           (0x02)
#define MAG3110_OUT_Y_MSB           (0x03)
#define MAG3110_OUT_Y_LSB           (0x04)
#define MAG3110_OUT_Z_MSB           (0x05)
#define MAG3110_OUT_Z_LSB           (0x06)
#define MAG3110_WHO_AM_I            (0x07)
#define MAG3110_SYSMOD              (0x08)
#define MAG3110_OFF_X_MSB           (0x09)
#define MAG3110_OFF_X_LSB           (0x0A)
#define MAG3110_OFF_Y_MSB           (0x0B)
#define MAG3110_OFF_Y_LSB           (0x0C)
#define MAG3110_OFF_Z_MSB           (0x0D)
#define MAG3110_OFF_Z_LSB           (0x0E)
#define MAG3110_DIE_TEMP            (0x0F)
#define MAG3110_CTRL_REG1           (0x10)
#define MAG3110_CTRL_REG2           (0x11)

/*
 * Field Definitions.
 */

/*! @brief mag3110 output data rate configuration. */
typedef enum _mag3110_data_rate_cfg
{
    mag3110DataRate_0 = 0x0 << 5,
    mag3110DataRate_1 = 0x1 << 5,
    mag3110DataRate_2 = 0x2 << 5,
    mag3110DataRate_3 = 0x3 << 5,
    mag3110DataRate_4 = 0x4 << 5,
    mag3110DataRate_5 = 0x5 << 5,
    mag3110DataRate_6 = 0x6 << 5,
    mag3110DataRate_7 = 0x7 << 5
} mag3110_data_rate_cfg_t;

/*! @brief mag3110 oversample ratio configuration. */
typedef enum _mag3110_oversample_cfg
{
    mag3110OSR_1 = 0x0 << 3,
    mag3110OSR_2 = 0x1 << 3,
    mag3110OSR_4 = 0x2 << 3,
    mag3110OSR_8 = 0x3 << 3
} mag3110_oversample_cfg_t;

/*! @brief mag3110 fast read selection. */
typedef enum _mag3110_fast_read_mode
{
    mag3110FastReadFull16Bit = 0x0 << 2,      /*!< Read full 16-bit. */
    mag3110FastReadMsb8Bit   = 0x1 << 2       /*!< Read MSB 8-bit. */
} mag3110_fast_read_mode_t;

/*! @brief mag3110 automatic magnetic sensor reset. */
typedef enum _mag3110_auto_mag_reset
{
    mag3110AutoMagResetDisable = 0x0 << 7,    /*!< Automatic magnetic sensor resets off. */
    mag3110AutoMagResetEnable  = 0x1 << 7     /*!< Automatic magnetic sensor resets on. */
} mag3110_auto_mag_reset_t;

/*! @brief mag3110 data output correction mode. */
typedef enum _mag3110_correction_mode
{
    mag3110CorrectionEnable   = 0x0 << 5,     /*!< Normal mode: data values are corrected by the user offset register values. */
    mag3110CorrectionDisable  = 0x1 << 5      /*!< Raw mode: data values are not corrected by the user offset register values. */
} mag3110_correction_mode_t;

/*! @brief mag3110 configure definition. */
typedef struct _mag3110_handle
{
    i2c_handle_t *device;  /*!< I2C handle. */
    uint8_t       address; /*!< mag3110 I2C bus address. */
} mag3110_handle_t;

/*! @brief Initialize structure of mag3110 */
typedef struct _mag3110_init
{
    mag3110_data_rate_cfg_t   dataRate;       /*!< Output data rate selection. */
    mag3110_oversample_cfg_t  overSample;     /*!< Over sample ratio selection. */
    mag3110_fast_read_mode_t  fastReadMode;   /*!< Fast Read mode selection. */
    mag3110_auto_mag_reset_t  autoReset;      /*!< Automatic Magnetic Sensor Reset. */
    mag3110_correction_mode_t correctionMode; /*!< Data output correction configuration. */
} mag3110_init_t;

/*! @brief mag3110 accelerometer and magnetometer data structure */
typedef struct _mag3110_data
{
    int16_t magX;
    int16_t magY;
    int16_t magZ;
} mag3110_data_t;

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief mag3110 initialize function.
 *
 * This function should be called after i2c module initialize, and in this function,
 * some configurations are fixed. The second parameter is the initialize structure to mag3110.
 * If users want to change the settings after initialization, they have to use MAG3110_writeReg()
 * to set the register value of mag3110.
 * @param handle mag3110 handle structure.
 * @param mag3110_config mag3110 configuration structure.
 */
bool MAG3110_Init(mag3110_handle_t *handle, const mag3110_init_t *mag3110_config);

/*!
 * @brief Deinit the mag3110 sensor.
 *
 * Mainly used to set mag3110 to standby mode and reset its registers content.
 * @param handle mag3110 handle structure pointer.
 */
bool MAG3110_Deinit(mag3110_handle_t *handle);

/*!
 * @brief Enable the mag3110 sensor.
 * @param handle mag3110 handler structure.
 */
bool MAG3110_Enable(mag3110_handle_t *handle);

/*!
 * @brief Disable the mag3110 sensor.
 * @param handle mag3110 handler structure.
 */
bool MAG3110_Disable(mag3110_handle_t *handle);

/*!
 * @brief Write register to mag3110 using I2C.
 * @param handle mag3110 handle structure.
 * @param regAddr The register address in mag3110.
 * @param regVal Value needs to write into the register.
 */
bool MAG3110_WriteReg(mag3110_handle_t *handle, uint8_t regAddr, uint8_t regVal);

/*!
 * @brief Read register from mag3110 using I2C.
 * @param handle mag3110 handle structure.
 * @param regAddr The register address in mag3110.
 * @param regValPtr The read value buffer pointer.
 */
bool MAG3110_ReadReg(mag3110_handle_t *handle, uint8_t regAddr, uint8_t *regValPtr);

/*!
 * @brief Read sensor data from mag3110 using I2C
 * @param handle mag3110 handle structure.
 * @param val Sensor data read from mag3110.
 * @param fastRead fast read mode selection (see mag3110_fast_read_mode_t).
 */
bool MAG3110_ReadData(mag3110_handle_t *handle, mag3110_data_t *val, mag3110_fast_read_mode_t fastRead);

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif/* __MAG_3110_H__ */
/*******************************************************************************
 * EOF
 ******************************************************************************/
