/*
 * The Clear BSD License
 * Copyright 2017 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted (subject to the limitations in the disclaimer below) provided
 *  that the following conditions are met:
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

#include "board.h"
#include "fsl_debug_console.h"
#include "fsl_rdc.h"
#include "fsl_rdc_sema42.h"

#include "pin_mux.h"
#include "clock_config.h"
#include "fsl_gpio.h"
/*******************************************************************************
* Definitions
******************************************************************************/
#define APP_RDC RDC
#define APP_CUR_MASTER kRDC_Master_M4
#define APP_CUR_MASTER_DID 3 /* Current master domain ID. */
#define APP_RDC_PERIPH kRDC_Periph_GPIO1
#define APP_RDC_SEMA42 RDC_SEMAPHORE1 /* Current master domain ID. */
#define APP_RDC_SEMA42_GATE (((uint8_t)APP_RDC_PERIPH) & 0x3F)

/* OCRAM is used for demonstration here. */
#define APP_RDC_MEM kRDC_Mem_MRC4_0
#define APP_RDC_MEM_BASE_ADDR 0x900000
#define APP_RDC_MEM_END_ADDR 0x920000

/*
 * Master index:
 * All masters excluding ARM core: 0
 * A53 core: 1
 * M4 core: 6
 * SDMA 3
 */
#define APP_MASTER_INDEX 6

typedef enum
{
    kRDC_DEMO_None = 0,
    kRDC_DEMO_Periph = 1,
    kRDC_DEMO_PeriphSema42 = 2,
    kRDC_DEMO_Mem = 3,
} rdc_demo_state_t;

#define DEMO_CHECK(x) \
    if (!(x)) \
    { \
        PRINTF("Example error\r\n"); \
        for(;;); \
      \
    }

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void APP_TouchPeriph(void);
void APP_TouchMem(void);
/*
 * In this function, sema42 is not required. The peripheral is set inaccessible
 * by current domain. When touch the peripheral, hardfault is triggered. In
 * hardfault handler, the peripheral is set accessible by current domain.
 */
static void APP_RDC_Periph(void);

/*
 * In this function, sema42 is required. The peripheral is set accessible by
 * current domain, before touch the peripheral, the sema42 gate should be locked.
 * So in this function, core touch the peripheral before locking the sema42 gate,
 * then hardfault happens. In hardfault handler, core locks the sema42, then
 * the peripheral is accessible.
 */
static void APP_RDC_PeriphWithSema42(void);

/*
 * In this function, the memory region is set inaccessible by current domain.
 * When touch the memory, hardfault is triggered. In hardfault handler, the
 * memory region is set accessible by current domain.
 */
static void APP_RDC_Mem(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/* Current demo state. */
static volatile rdc_demo_state_t s_demoState = kRDC_DEMO_None;
/* HardFault happened or not. */
static volatile bool s_hardfaultFlag = false;
/* How many error happens during memory region demo. */
static volatile uint32_t memDemoError = 0;

rdc_domain_assignment_t assignment;
rdc_periph_access_config_t periphConfig;
rdc_mem_access_config_t memConfig;

/*******************************************************************************
 * Code
 ******************************************************************************/

void APP_TouchPeriph(void)
{
    GPIO_PinRead(GPIO1, 0);
}

void APP_TouchMem(void)
{
    /* Touch the memory. */
    (*(volatile uint32_t *)APP_RDC_MEM_BASE_ADDR)++;
}
void HardFault_Handler(void)
{
    rdc_mem_status_t memStatus;

    s_hardfaultFlag = true;

    if (kRDC_DEMO_Periph == s_demoState)
    {
        /* Make peripheral accessible. */
        periphConfig.policy |= RDC_ACCESS_POLICY(APP_CUR_MASTER_DID, kRDC_ReadWrite);
        RDC_SetPeriphAccessConfig(APP_RDC, &periphConfig);
    }
    else if (kRDC_DEMO_PeriphSema42 == s_demoState)
    {
        /* Lock the SEMA42 gate, then the peripheral should be accessible. */
        RDC_SEMA42_Lock(APP_RDC_SEMA42, APP_RDC_SEMA42_GATE, APP_MASTER_INDEX, APP_CUR_MASTER_DID);
    }
    else if (kRDC_DEMO_Mem == s_demoState)
    {
        /* Check error status. */
        RDC_GetMemViolationStatus(APP_RDC, APP_RDC_MEM, &memStatus);

        if (false == memStatus.hasViolation)
        {
            memDemoError++;
        }

        if (APP_CUR_MASTER_DID != memStatus.domainID)
        {
            memDemoError++;
        }

        if (APP_RDC_MEM_BASE_ADDR != memStatus.address)
        {
            memDemoError++;
        }

        /* Make memory region accessible. */
        memConfig.policy |= RDC_ACCESS_POLICY(APP_CUR_MASTER_DID, kRDC_ReadWrite);
        RDC_SetMemAccessConfig(APP_RDC, &memConfig);

        RDC_ClearMemViolationFlag(APP_RDC, APP_RDC_MEM);
    }
}

/*!
 * @brief Main function
 */
int main(void)
{
    /* Board specific RDC settings */
    BOARD_RdcInit();

    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();
    BOARD_InitMemory();

    /* Init GPIO used for peripheral access demonstration. */
    gpio_pin_config_t pinConfig = {
        kGPIO_DigitalOutput, 0, kGPIO_IntRisingEdge,
    };

    GPIO_PinInit(GPIO1, 0, &pinConfig);

    /* Set the IOMUXC_GPR10[2:3], thus the memory violation triggers the hardfault. */
    *(volatile uint32_t *)0x30340028 |= (0x0C);

    PRINTF("\r\nRDC Example:\r\n");

    RDC_Init(APP_RDC);
    RDC_SEMA42_Init(APP_RDC_SEMA42);

    /* Assign current master domain. */
    RDC_GetDefaultMasterDomainAssignment(&assignment);
    assignment.domainId = APP_CUR_MASTER_DID;
    RDC_SetMasterDomainAssignment(APP_RDC, APP_CUR_MASTER, &assignment);

    APP_RDC_Periph();

    APP_RDC_PeriphWithSema42();

    APP_RDC_Mem();

    PRINTF("\r\nRDC Example Success\r\n");

    while (1)
    {
    }
}

static void APP_RDC_Periph(void)
{
    PRINTF("RDC Peripheral access control\r\n");

    s_demoState = kRDC_DEMO_Periph;

    /*
     * Item 1: Peripheral accessible.
     */
    RDC_GetDefaultPeriphAccessConfig(&periphConfig);
    periphConfig.periph = APP_RDC_PERIPH;

    /* Set peripheral to accessible by all domains. */
    RDC_SetPeriphAccessConfig(APP_RDC, &periphConfig);

    s_hardfaultFlag = false;

    APP_TouchPeriph();

    /* Peripheral is accessible, there should not be hardfault. */
    DEMO_CHECK(false == s_hardfaultFlag);

    /*
     * Item 2: Peripheral inaccessible.
     */
    /* Make peripheral not accessible. */
    periphConfig.policy &= ~(RDC_ACCESS_POLICY(APP_CUR_MASTER_DID, kRDC_ReadWrite));
    RDC_SetPeriphAccessConfig(APP_RDC, &periphConfig);

    s_hardfaultFlag = false;
    APP_TouchPeriph();

    /* Peripheral is not accessible, there should be hardfault. */
    DEMO_CHECK(true == s_hardfaultFlag);
}

static void APP_RDC_PeriphWithSema42(void)
{
    PRINTF("RDC Peripheral access control with SEMA42\r\n");

    /* Demo the SEMA42 used together with RDC. */
    s_demoState = kRDC_DEMO_PeriphSema42;

    RDC_GetDefaultPeriphAccessConfig(&periphConfig);
    periphConfig.periph = APP_RDC_PERIPH;
    periphConfig.enableSema = true;

    RDC_SetPeriphAccessConfig(APP_RDC, &periphConfig);

    /* Make sure current core does not hold the SEMA42 gate. */
    RDC_SEMA42_Unlock(APP_RDC_SEMA42, APP_RDC_SEMA42_GATE);
    DEMO_CHECK(APP_CUR_MASTER_DID != RDC_SEMA42_GetLockDomainID(APP_RDC_SEMA42, APP_RDC_SEMA42_GATE));

    s_hardfaultFlag = false;

    APP_TouchPeriph();

    /* Peripheral is not accessible because SEMA42 gate not locked, there should be hardfault. */
    DEMO_CHECK(true == s_hardfaultFlag);

    /* Demo finished, make the peripheral to default policy. */
    RDC_GetDefaultPeriphAccessConfig(&periphConfig);

    /* Set peripheral to accessible by all domains. */
    RDC_SetPeriphAccessConfig(APP_RDC, &periphConfig);

    RDC_SEMA42_Unlock(APP_RDC_SEMA42, APP_RDC_SEMA42_GATE);
}

static void APP_RDC_Mem(void)
{
    /*
     * In memory protection, please notice the cache's effect.
     * For example, if a memory region has been loaded to cache
     * before it is set not accessible, then CPU only access the
     * cache but not the memory, application could not detect
     * access violation.
     */
    PRINTF("RDC memory region access control\r\n");

    s_demoState = kRDC_DEMO_Mem;

    RDC_GetDefaultMemAccessConfig(&memConfig);

    memConfig.mem = APP_RDC_MEM;
    memConfig.baseAddress = APP_RDC_MEM_BASE_ADDR;
    memConfig.endAddress = APP_RDC_MEM_END_ADDR;

    /* Make memory not accessible. */
    memConfig.policy &= ~(RDC_ACCESS_POLICY(APP_CUR_MASTER_DID, kRDC_ReadWrite));
    RDC_SetMemAccessConfig(APP_RDC, &memConfig);

    s_hardfaultFlag = false;
    APP_TouchMem();

    /* Memory is not accessible, there should be hardfault. */
    DEMO_CHECK(true == s_hardfaultFlag);
    DEMO_CHECK(0 == memDemoError);
}
