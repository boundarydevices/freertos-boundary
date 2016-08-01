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

///////////////////////////////////////////////////////////////////////////////
//  Includes
///////////////////////////////////////////////////////////////////////////////
#include <stdint.h>
#include <stdbool.h>
#include "FreeRTOS.h"
#include "task.h"
#include "board.h"
#include "gpio_imx.h"
#include "gpio_pins.h"
#include "rdc_semaphore.h"
#include "debug_console_imx.h"
#include "i2c_xfer.h"
#include "mma8451q.h"
#include "mag3110.h"

////////////////////////////////////////////////////////////////////////////////
// Static Variable
////////////////////////////////////////////////////////////////////////////////
static i2c_handle_t        I2C_handle;
static SemaphoreHandle_t   xSemaphore;
static mma8451q_handle_t   mma8451qHandle = {.device = &I2C_handle,
                                             .address = BOARD_I2C_MMA8451Q_ADDR};
static mag3110_handle_t    mag3110Handle =  {.device = &I2C_handle,
                                             .address = BOARD_I2C_MAG3110_ADDR};
static uint8_t demoSel;
////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////
void mma8451qDemo_Pol(void)
{
    float Ax, Ay, Az;
    mma8451q_data_t mma8451qData;

    const mma8451q_init_t initConfig = {
        .dataRate = mma8451qDataRate400HZ,
        .range    = mma8451qRang2gMode
    };

    if (!MMA8451Q_Init(&mma8451qHandle, &initConfig))
        PRINTF("Initialization ERROR\n\r");

    /* Active MMA8451Q Sensor. */
    MMA8451Q_Enable(&mma8451qHandle);

    while(1)
    {
        vTaskDelay(1000);
        MMA8451Q_ReadData(&mma8451qHandle, &mma8451qData);
        Ax = mma8451qData.accX / (4.0 * 1024);     //For full scale range 2g mode.
        Ay = mma8451qData.accY / (4.0 * 1024);
        Az = mma8451qData.accZ / (4.0 * 1024);
        PRINTF("[MMA8451Q]Current Acc:X=%6.5fg Y=%6.5fg Z=%6.5fg\n\r",Ax, Ay, Az);
    }
}

void mma8451qDemo_Int(void)
{
    float Ax, Ay, Az;
    mma8451q_data_t mma8451qData;

    const mma8451q_init_t initConfig = {
        .dataRate = mma8451qDataRate1_56HZ,
        .range    = mma8451qRang2gMode
    };

    if (!MMA8451Q_Init(&mma8451qHandle, &initConfig))
        PRINTF("Initialization ERROR\n\r");

    /* Enable Data Ready Interrupt. */
    /* Set Interrupt pin to Active Low & Push-Pull. */
    MMA8451Q_WriteReg(&mma8451qHandle, MMA8451Q_CTRL_REG3, 0x00);

    // Route Data Ready Interrupt to Int2 Pin.
    MMA8451Q_WriteReg(&mma8451qHandle, MMA8451Q_CTRL_REG5, BOARD_SENSOR_MMA8451Q_INT);

    // Enable Data Ready Interrupt.
    MMA8451Q_WriteReg(&mma8451qHandle, MMA8451Q_CTRL_REG4, 0x01);

    /* Active MMA8451Q. */
    MMA8451Q_Enable(&mma8451qHandle);

    while(1)
    {
        /* Wait until pulse detected. The timeout value should be
         * Changed according to actual data rate.
         */
        if (pdTRUE == xSemaphoreTake(xSemaphore, 1000))
        {
            /* Read data from sensor */
            MMA8451Q_ReadData(&mma8451qHandle, &mma8451qData);
            Ax = mma8451qData.accX / (4.0 * 1024);     //For full scale range 2g mode.
            Ay = mma8451qData.accY / (4.0 * 1024);
            Az = mma8451qData.accZ / (4.0 * 1024);
            PRINTF("[MMA8451Q]Current Acc:X=%6.5fg Y=%6.5fg Z=%6.5fg\n\r",Ax, Ay, Az);
        }
        else
        {
            /* Because the GPIO interrutp of Sensor Int pin will be masked when Linux
             * boot on Cortex-A9 Core, so we provide this walkaround to enable the GPIO
             * interrupt of Sensor Int pin here, if we did not get the sensor data ready
             * interrupt for a long time.
             */
            NVIC_DisableIRQ(BOARD_GPIO_SENSOR_ACC_IRQ_NUM);
            RDC_SEMAPHORE_Lock(BOARD_GPIO_SENSOR_ACC_RDC_PDAP);
            GPIO_SetPinIntMode(BOARD_GPIO_SENSOR_ACC_CONFIG->base, BOARD_GPIO_SENSOR_ACC_CONFIG->pin, true);
            RDC_SEMAPHORE_Unlock(BOARD_GPIO_SENSOR_ACC_RDC_PDAP);
            NVIC_EnableIRQ(BOARD_GPIO_SENSOR_ACC_IRQ_NUM);
        }
    }
}

void mag3110Demo_Pol(void)
{
    float Mx, My, Mz;
    mag3110_data_t mag3110Data;

    /* There are many combination of data output rate and over sample ratio. */
    /* Each combination corresponds to different consumption Level. */
    /* Refer to MAG3110 datasheet page 20 for detail. */
    const mag3110_init_t initConfig = {
        .dataRate       = mag3110DataRate_0,
        .overSample     = mag3110OSR_1,
        .fastReadMode   = mag3110FastReadFull16Bit,
        .autoReset      = mag3110AutoMagResetDisable,
        .correctionMode = mag3110CorrectionEnable
    };

    if (!MAG3110_Init(&mag3110Handle, &initConfig))
        PRINTF("Initialization ERROR\n\r");

    /* Active MAG3110 Magnetic Field Strength Sensor. */
    MAG3110_Enable(&mag3110Handle);

    while(1)
    {
        vTaskDelay(1000);
        MAG3110_ReadData(&mag3110Handle, &mag3110Data, initConfig.fastReadMode);
        Mx = mag3110Data.magX / 30.0;
        My = mag3110Data.magY / 30.0;
        Mz = mag3110Data.magZ / 30.0;
        PRINTF("[MAG3110]Current Mag:X=%6.1fuT Y=%6.1fuT Z=%6.1fuT\n\r",Mx, My, Mz);
    }
}

void mag3110Demo_Int(void)
{
    float Mx, My, Mz;
    mag3110_data_t mag3110Data;

    /* There are many combination of data output rate and over sample ratio. */
    /* Each combination corresponds to different consumption Level. */
    /* Refer to MAG3110 datasheet page 20 for detail. */
    /* In this interrupt demo, configure output rate to 0.63Hz. */
    const mag3110_init_t initConfig = {
        .dataRate       = mag3110DataRate_4,
        .overSample     = mag3110OSR_8,
        .fastReadMode   = mag3110FastReadFull16Bit,
        .autoReset      = mag3110AutoMagResetDisable,
        .correctionMode = mag3110CorrectionEnable
    };

    if (!MAG3110_Init(&mag3110Handle, &initConfig))
        PRINTF("Initialization ERROR\n\r");

    /* Active MAG3110 Magnetic Field Strength Sensor. */
    MAG3110_Enable(&mag3110Handle);
    while(1)
    {
        /* Wait until pulse detected. The timeout value should be
         * Changed according to actual data rate.
         */
        if (pdTRUE == xSemaphoreTake(xSemaphore, 2000))
        {
            MAG3110_ReadData(&mag3110Handle, &mag3110Data, initConfig.fastReadMode);
            Mx = mag3110Data.magX / 30.0;
            My = mag3110Data.magY / 30.0;
            Mz = mag3110Data.magZ / 30.0;
            PRINTF("[MAG3110]Current Mag:X=%6.1fuT Y=%6.1fuT Z=%6.1fuT\n\r",Mx, My, Mz);
        }
        else
        {
            /* Because the GPIO interrutp of Sensor Int pin will be masked when Linux
             * boot on Cortex-A9 Core, so we provide this walkaround to enable the GPIO
             * interrupt of Sensor Int pin here, if we did not get the sensor data ready
             * interrupt for a long time.
             */
            NVIC_DisableIRQ(BOARD_GPIO_SENSOR_MAG_ALS_IRQ_NUM);
            RDC_SEMAPHORE_Lock(BOARD_GPIO_SENSOR_MAG_ALS_RDC_PDAP);
            GPIO_SetPinIntMode(BOARD_GPIO_SENSOR_MAG_ALS_CONFIG->base, BOARD_GPIO_SENSOR_MAG_ALS_CONFIG->pin, true);
            RDC_SEMAPHORE_Unlock(BOARD_GPIO_SENSOR_MAG_ALS_RDC_PDAP);
            NVIC_EnableIRQ(BOARD_GPIO_SENSOR_MAG_ALS_IRQ_NUM);
        }
    }
}

void MainTask(void *pvParameters)
{
    /* GPIO module initialize, configure button(GPIO6_IO02) as interrupt mode. */
    /* This gpio interrupt is for MMA8451Q sensor. */
    gpio_init_config_t sensorAccIntInitConfig = {
        .pin = BOARD_GPIO_SENSOR_ACC_CONFIG->pin,
        .direction = gpioDigitalInput,
        .interruptMode = gpioIntFallingEdge
    };

    /* GPIO module initialize, configure button(GPIO6_IO05) as interrupt mode. */
    /* This gpio interrupt is for MAG3110 and ISL29023 sensor. */
    gpio_init_config_t sensorMagAlsIntInitConfig = {
        .pin = BOARD_GPIO_SENSOR_MAG_ALS_CONFIG->pin,
        .direction = gpioDigitalInput,
        .interruptMode = gpioIntRisingEdge
    };

    /* Setup I2C init structure. */
    i2c_xfer_init_config_t i2cInitConfig = {
        .base   = BOARD_I2C_BASEADDR,
        .config = {
            .clockRate    = get_i2c_clock_freq(BOARD_I2C_BASEADDR),
            .baudRate     = 100000u,
            .slaveAddress = 0x70
        },
        .irqNum  = BOARD_I2C_IRQ_NUM,
        .irqPrio = 3
    };

    PRINTF("\n\r-------------- i.MX 6SoloX SABRE on board sensor example --------------\n\r\n\r");

    /* Data acquire sync sema4 init. */
    xSemaphore = xSemaphoreCreateBinary();

    /* Initialize I2C module with I2C init structure. */
    I2C_XFER_Init(&I2C_handle, &i2cInitConfig);

    /* Deinit on-board sensors to avoid unexpected interrupt. */
    MMA8451Q_Deinit(&mma8451qHandle);
    MAG3110_Deinit(&mag3110Handle);
    vTaskDelay(50);

    /* Print the initial banner. */
    PRINTF("\n\rPlease select the sensor demo you want to run:\n\r");
    PRINTF("[1].MMA8451Q 3-Axis Digital Accelerometer Polling Demo\n\r");
    PRINTF("[2].MMA8451Q 3-Axis Digital Accelerometer Interrupt Demo\n\r");
    PRINTF("[3].MAG3110  3-Axis Digital Magnetometer Polling Demo\n\r");
    PRINTF("[4].MAG3110  3-Axis Digital Magnetometer Interrupt Demo\n\r");
    while(1)
    {
        demoSel = GETCHAR();
        if ((demoSel >= '1') && (demoSel <= '4'))
            break;
    }

    /* Select MMA8451Q interrupt or polling demo. */
    if ((demoSel == '1') || (demoSel == '2'))
    {
        /* Acquire RDC semaphore before access GPIO to avoid conflict, it's
         * necessary when GPIO RDC is configured as Semaphore Required */
        RDC_SEMAPHORE_Lock(BOARD_GPIO_SENSOR_ACC_RDC_PDAP);
        GPIO_Init(BOARD_GPIO_SENSOR_ACC_CONFIG->base, &sensorAccIntInitConfig);
        /* Clear the interrupt state, this operation is necessary, because the GPIO module maybe confuse
           the first rising edge as interrupt*/
        GPIO_ClearStatusFlag(BOARD_GPIO_SENSOR_ACC_CONFIG->base, BOARD_GPIO_SENSOR_ACC_CONFIG->pin);
        /* Enable GPIO pin interrupt */
        GPIO_SetPinIntMode(BOARD_GPIO_SENSOR_ACC_CONFIG->base, BOARD_GPIO_SENSOR_ACC_CONFIG->pin, true);
        RDC_SEMAPHORE_Unlock(BOARD_GPIO_SENSOR_ACC_RDC_PDAP);

        /* Set GPIO Interrupt priority */
        NVIC_SetPriority(BOARD_GPIO_SENSOR_ACC_IRQ_NUM, 3);
        NVIC_EnableIRQ(BOARD_GPIO_SENSOR_ACC_IRQ_NUM);
    }
    else/* Select MAG3110/ISL29023 interrupt or polling demo. */
    {
        /* Acquire RDC semaphore before access GPIO to avoid conflict, it's
         * necessary when GPIO RDC is configured as Semaphore Required */
        RDC_SEMAPHORE_Lock(BOARD_GPIO_SENSOR_MAG_ALS_RDC_PDAP);
        GPIO_Init(BOARD_GPIO_SENSOR_MAG_ALS_CONFIG->base, &sensorMagAlsIntInitConfig);
        /* Clear the interrupt state, this operation is necessary, because the GPIO module maybe confuse
           the first rising edge as interrupt*/
        GPIO_ClearStatusFlag(BOARD_GPIO_SENSOR_MAG_ALS_CONFIG->base, BOARD_GPIO_SENSOR_MAG_ALS_CONFIG->pin);
        /* Enable GPIO pin interrupt */
        GPIO_SetPinIntMode(BOARD_GPIO_SENSOR_MAG_ALS_CONFIG->base, BOARD_GPIO_SENSOR_MAG_ALS_CONFIG->pin, true);
        RDC_SEMAPHORE_Unlock(BOARD_GPIO_SENSOR_MAG_ALS_RDC_PDAP);

        NVIC_SetPriority(BOARD_GPIO_SENSOR_MAG_ALS_IRQ_NUM, 3);
        NVIC_EnableIRQ(BOARD_GPIO_SENSOR_MAG_ALS_IRQ_NUM);
    }

    switch(demoSel)
    {
        case '1':
            mma8451qDemo_Pol();
            break;
        case '2':
            mma8451qDemo_Int();
            break;
        case '3':
            mag3110Demo_Pol();
            break;
        case '4':
            mag3110Demo_Int();
            break;
    }
}

int main(void)
{
    /* Initialize board specified hardware. */
    hardware_init();

    /* Create a the APP main task. */
    xTaskCreate(MainTask, "Main Task", configMINIMAL_STACK_SIZE + 50,
                NULL, tskIDLE_PRIORITY+1, NULL);

    /* Start FreeRTOS scheduler. */
    vTaskStartScheduler();

    /* should never reach this point. */
    while (true);
}

void BOARD_I2C_HANDLER(void)
{
    I2C_XFER_Handler(&I2C_handle);
}

void BOARD_GPIO_SENSOR_ACC_HANDLER(void)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    if(GPIO_IsIntPending(BOARD_GPIO_SENSOR_ACC_CONFIG->base, BOARD_GPIO_SENSOR_ACC_CONFIG->pin))
    {
        RDC_SEMAPHORE_Lock(BOARD_GPIO_SENSOR_ACC_RDC_PDAP);
        /* clear the interrupt status. */
        GPIO_ClearStatusFlag(BOARD_GPIO_SENSOR_ACC_CONFIG->base, BOARD_GPIO_SENSOR_ACC_CONFIG->pin);
        RDC_SEMAPHORE_Unlock(BOARD_GPIO_SENSOR_ACC_RDC_PDAP);
    }
    else
    {
        RDC_SEMAPHORE_Lock(BOARD_GPIO_SENSOR_MAG_ALS_RDC_PDAP);
        /* clear the interrupt status. */
        GPIO_ClearStatusFlag(BOARD_GPIO_SENSOR_MAG_ALS_CONFIG->base, BOARD_GPIO_SENSOR_MAG_ALS_CONFIG->pin);
        RDC_SEMAPHORE_Unlock(BOARD_GPIO_SENSOR_MAG_ALS_RDC_PDAP);
    }

    /* Inform main task. */
    xSemaphoreGiveFromISR(xSemaphore, &xHigherPriorityTaskWoken);

    if(xHigherPriorityTaskWoken == pdTRUE)
    {
        portEND_SWITCHING_ISR(xHigherPriorityTaskWoken);
    }
}

#ifdef BOARD_AI_SENSOR_MAG3110
void BOARD_GPIO_SENSOR_MAG_ALS_HANDLER(void)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    if(GPIO_IsIntPending(BOARD_GPIO_SENSOR_ACC_CONFIG->base, BOARD_GPIO_SENSOR_ACC_CONFIG->pin))
    {
        RDC_SEMAPHORE_Lock(BOARD_GPIO_SENSOR_ACC_RDC_PDAP);
        /* clear the interrupt status. */
        GPIO_ClearStatusFlag(BOARD_GPIO_SENSOR_ACC_CONFIG->base, BOARD_GPIO_SENSOR_ACC_CONFIG->pin);
        RDC_SEMAPHORE_Unlock(BOARD_GPIO_SENSOR_ACC_RDC_PDAP);
    }
    else
    {
        RDC_SEMAPHORE_Lock(BOARD_GPIO_SENSOR_MAG_ALS_RDC_PDAP);
        /* clear the interrupt status. */
        GPIO_ClearStatusFlag(BOARD_GPIO_SENSOR_MAG_ALS_CONFIG->base, BOARD_GPIO_SENSOR_MAG_ALS_CONFIG->pin);
        RDC_SEMAPHORE_Unlock(BOARD_GPIO_SENSOR_MAG_ALS_RDC_PDAP);
    }

    /* Inform main task. */
    xSemaphoreGiveFromISR(xSemaphore, &xHigherPriorityTaskWoken);

    if(xHigherPriorityTaskWoken == pdTRUE)
    {
        portEND_SWITCHING_ISR(xHigherPriorityTaskWoken);
    }
}
#endif
/*******************************************************************************
 * EOF
 ******************************************************************************/
