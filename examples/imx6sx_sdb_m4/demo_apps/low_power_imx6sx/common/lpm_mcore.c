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

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string.h>
#include "device_imx.h"
#include "FreeRTOS.h"
#include "mu_imx.h"
#include "shared_clock_manage.h"
#include "lpm_mcore.h"
#include "board.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define NVIC_GIC_OFFSET              32
#define REGISTER_PEER_WAKEUP_MASK    0x55555000
#define MSG_FMT_INT_NO_OFFSET        4
#define LPM_MCORE_MU_CHANNEL         0

#define STATUS_LPRUN                 0x2222BBBB
#define STATUS_HIRUN                 0x2222CCCC
#define PEER_RESPONSE_HI_OK          0xFFFF6666
#define PEER_FREQ_CHANGE_READY       0xFFFF7777

static uint32_t lpm_mcore_state = STATUS_NORMAL_RUN;
static void (*runInRAM)(void) = NULL;

/*******************************************************************************
 * Function prototype
 ******************************************************************************/
static uint8_t* RAM_Function_Copy(uint8_t* func_start, uint8_t* func_end);
#if defined(__GNUC__) || defined(__CC_ARM)
static void RAM_Wfi(void) __attribute__((section(".ram_function")));
static void RAM_Wfi_End(void) __attribute__((section(".ram_function_end")));
#elif defined(__ICCARM__)
#pragma section = ".ram_function"
static void RAM_Wfi(void);
#pragma section = ".ram_function_end"
static void RAM_Wfi_End(void);
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/
/*FUNCTION**********************************************************************
 *
 * Function Name : LPM_MCORE_Init
 * Description   :
 *
 *END**************************************************************************/
void LPM_MCORE_Init(void)
{
    // register MU
    // Here we do not need to enable the interrupt, because the MU message waiting
    // is implemented in the assembly code

    /* Is RAM_Wfi linked to TCM? */
    if (((uint32_t)RAM_Wfi < 0x1FFF8000) || ((uint32_t)RAM_Wfi > 0x20007FFF))
        // If no, copy the RAM_Wfi function to TCM.
        runInRAM = (void(*)(void))RAM_Function_Copy((uint8_t *)RAM_Wfi,
                                                    (uint8_t *)RAM_Wfi_End);
    else
        // If yes, just assign RAM_Wfi to runInRAM pointer.
        runInRAM = RAM_Wfi;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LPM_MCORE_GetPowerStatus
 * Description   :
 *
 *END**************************************************************************/
uint32_t LPM_MCORE_GetPowerStatus(void)
{
    return lpm_mcore_state;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LPM_MCORE_SetPowerStatus
 * Description   :
 *
 *END**************************************************************************/
void LPM_MCORE_SetPowerStatus(uint32_t status)
{
    lpm_mcore_state = status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LPM_MCORE_RegisterPeerWakeup
 * Description   :
 *
 *END**************************************************************************/
uint32_t LPM_MCORE_RegisterPeerWakeup(uint32_t int_num, uint32_t enable)
{
    uint32_t peer_int_num;
    uint32_t msg;

    /* Power of A9 side not ready. */
    if (SHAREMEM_READY_MAGIC != SharedClock_GetPeerMagic())
    {
        return WAKEUP_REGISTER_FAILURE;
    }
    else
    {
        peer_int_num = int_num + NVIC_GIC_OFFSET;
        msg = REGISTER_PEER_WAKEUP_MASK | (peer_int_num << MSG_FMT_INT_NO_OFFSET) | enable;

        /* Wait until the channel is available */
        while (!MU_IsTxEmpty(MUB, LPM_MCORE_MU_CHANNEL));

        /* Transmit the message */
        MU_SendMsg(MUB, LPM_MCORE_MU_CHANNEL, msg);

        return WAKEUP_REGISTER_SUCCESS;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LPM_MCORE_WaitForInt
 * Description   :
 *
 *END**************************************************************************/
void LPM_MCORE_WaitForInt(void)
{
    uint32_t priMaskBackup;

    /* Before run WFI in TCM, ARM Core interrupts are disabled
     * After resume from WFI, ARM Core interrupts are enabled
     * the interrupt should be disabled to make core status query and
     * set atomic.
     */

    /* Check Peer magic to see if peer is boot up. */
    if (SHAREMEM_READY_MAGIC == SharedClock_GetPeerMagic())
    {
        /* Save current PRIMASK value. */
        priMaskBackup = __get_PRIMASK();

        /* Set PRIMASK to avoid execution of any enabled ISR. */
        __set_PRIMASK(1);
        /* Barriers are normally not required but do ensure the code is completely
         * within the specified behaviour for the architecture.
         */
        __DSB();
        __ISB();

        /*
         * If Current M4 power status is low-power run and LPM is
         * initialized, dual core WFI will be executed, otherwise 
         * normal WFI is enough for M4 side power saving.
         */
        if ((STATUS_LOWPOWER_RUN == LPM_MCORE_GetPowerStatus()) && (runInRAM != NULL))
        {
            runInRAM();
        }
        else
        {
            __WFI();
        }

        /* Recover PRIMASK register value. */
        __set_PRIMASK(priMaskBackup);
        /* Barriers are normally not required but do ensure the code is completely
         * within the specified behaviour for the architecture. */
        __DSB();
        __ISB();
    }
    else
    {
        __WFI();
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : RAM_Function_Copy
 * Description   :
 *
 *END**************************************************************************/
static uint8_t* RAM_Function_Copy(uint8_t* func_start, uint8_t* func_end)
{
    uint8_t* ram_code_ptr;
    uint32_t ram_function_start;

    ram_function_start = (uint32_t)func_start & ~0x3;
    ram_code_ptr = pvPortMalloc((uint8_t*)func_end - (uint8_t*)ram_function_start);
    memcpy(ram_code_ptr, (uint8_t*)ram_function_start, (uint32_t)func_end -
           (uint32_t)ram_function_start);
    ram_code_ptr = (uint8_t *)((uint32_t)ram_code_ptr | ((uint32_t)func_start & 0x3));

    return ram_code_ptr;
}

/*
 * The following functions should be copied to TCM in runtime, no subroutines
 * can be called inside ram_wfi. So instead of calling mu_tx, mu_tx_available, direct
 * register operation is performed
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : RAM_Wfi
 * Description   :
 *
 *END**************************************************************************/
static void RAM_Wfi(void)
{
    uint32_t nvicMubEnableBackup, nvicMubPriorityBackup, mubCrBackup, basePriBackup;
#if defined(__CC_ARM)
    register uint32_t __regBasePri __ASM("basepri");
#endif

    /*
     * 1. Save NVIC MU related register content
     */
    nvicMubEnableBackup   = NVIC->ISER[MU_M4_IRQn >> 5];
    nvicMubPriorityBackup = (uint32_t)NVIC->IP[(uint32_t)(MU_M4_IRQn)];
    mubCrBackup           = MUB_CR;

    /******************** Pre WFI handshake start ********************/

    /*
     * 2. Disable all NVIC interrupts except for MU
     */

    /*
     * Change BASEPRI to disable all task level interrupts
     */
#if defined(__CC_ARM)
    basePriBackup = __regBasePri;
    __regBasePri  = (configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << 4) & 0xFF;
#else
    basePriBackup = __get_BASEPRI();
    __set_BASEPRI(configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << 4);
#endif
    __DSB();
    __ISB();

    /* Set MUB to higher interrupt priority than MAX_SYSCALL_INTERRUPT_PRIORITY. */
    NVIC->IP[(uint32_t)(MU_M4_IRQn)] = (((configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY - 1)
                                         << (8 - __NVIC_PRIO_BITS)) & 0xff);
    NVIC->ISER[(uint32_t)((int32_t)MU_M4_IRQn) >> 5] =
                        (uint32_t)(1 << ((uint32_t)((int32_t)MU_M4_IRQn) & (uint32_t)0x1F));
    MUB_CR = MU_CR_RIEn(0x8 >> LPM_MCORE_MU_CHANNEL);

    /*
     * Manually clear pending
     */
    NVIC->ICPR[((uint32_t)(MU_M4_IRQn) >> 5)] = (1 << ((uint32_t)(MU_M4_IRQn) & 0x1F));

    /*
     * 3. Send LPRUN Request
     */

    /*
     * Wait for the previous MU message being read
     */
    while (0 == (MUB_SR & MU_SR_TEn(0x8 >> LPM_MCORE_MU_CHANNEL)));

    /* Inform peer about the low power status */
    MUB->TR[LPM_MCORE_MU_CHANNEL] = STATUS_LPRUN;

    /* Waiting for B-side event pending clear*/
    while ((MUB_SR & MU_SR_EP_MASK) != 0);

    /*
     * 4. WFI which will be only wake up by A9 MU, after wakeup clock
     * has been changed and QSPI, DDR are not available A9 will send
     * a MU to indicate this done
     */
    __WFI();

    /*
     * 5. Confirms that A9 send FREQ_READY msg
     */
    while (1)
    {
        if ((MUB_SR & (MU_SR_RFn(0x8 >> LPM_MCORE_MU_CHANNEL))) != 0)
            if (PEER_FREQ_CHANGE_READY == MUB->RR[LPM_MCORE_MU_CHANNEL])
                break;
    }

    /*
     * Manually clear pending
     */
    NVIC->ICPR[((uint32_t)(MU_M4_IRQn) >> 5)] = (1 << ((uint32_t)(MU_M4_IRQn) & 0x1F));

    /******************** Pre WFI handshake end ********************/

    /*
     * 6. Restore MU interrupt settings
     */
    MUB_CR = mubCrBackup;
    NVIC->ISER[MU_M4_IRQn >> 5] = nvicMubEnableBackup;
    NVIC->IP[(uint32_t)(MU_M4_IRQn)] = (uint8_t)nvicMubPriorityBackup;

    /*
     * Restore all thread-context interrupt except Kernel interrupt,
     * Real WFI start from here.
     */
#if defined(__CC_ARM)
    __regBasePri = configKERNEL_INTERRUPT_PRIORITY & 0xFF;
#else
    __set_BASEPRI(configKERNEL_INTERRUPT_PRIORITY);
#endif
    __DSB();
    __ISB();

    /*
     * 7. WFI, which will be waken up by Enabled Interrupts
     */
    __WFI();

#if defined(__CC_ARM)
    __regBasePri = (configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << 4) & 0xFF;
#else
    __set_BASEPRI(configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << 4);
#endif
    __DSB();
    __ISB();

    /******************** Post WFI handshake start ********************/

    /*
     * 8. Change MU interrupt settings
     */
    /* Set MUB to highest interrupt priority. */
    NVIC->IP[(uint32_t)(MU_M4_IRQn)] = (((configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY - 1)
                                        << (8 - __NVIC_PRIO_BITS)) & 0xff);
    NVIC->ISER[(uint32_t)((int32_t)MU_M4_IRQn) >> 5] =
                        (uint32_t)(1 << ((uint32_t)((int32_t)MU_M4_IRQn) & (uint32_t)0x1F));
    MUB_CR = MU_CR_RIEn(0x8 >> LPM_MCORE_MU_CHANNEL);

    /*
     * Manually clear pending
     */
    NVIC->ICPR[((uint32_t)(MU_M4_IRQn) >> 5)] = (1 << ((uint32_t)(MU_M4_IRQn) & 0x1F));

    /*
     * 9. Wake up, send HI_RUN message to A9
     */

    /*
     * Wait for the previous MU message being read
     */
    while (0 == (MUB_SR & (MU_SR_TEn(0x8 >> LPM_MCORE_MU_CHANNEL))));

    /* Inform peer about the high power status */
    MUB->TR[LPM_MCORE_MU_CHANNEL] = STATUS_HIRUN;

    /* Waiting for B-side event pending clear*/
    while ((MUB_SR & MU_SR_EP_MASK) != 0);

    /*
    * 10. WFI which can only be waken up by MU
    */
    __WFI();

    /* 
     * 11. confirms A9 send RESPONSE_HI message
     */
    while (1)
    {
        if ((MUB_SR & (MU_SR_RFn(0x8 >> LPM_MCORE_MU_CHANNEL))) != 0)
        {
            if (MUB->RR[LPM_MCORE_MU_CHANNEL] == PEER_RESPONSE_HI_OK)
                break;
        }
    }

    /*
     * Manually clear pending
     */
    NVIC->ICPR[((uint32_t)(MU_M4_IRQn) >> 5)] = (1 << ((uint32_t)(MU_M4_IRQn) & 0x1F));

    /******************** Post WFI handshake end ********************/

    /*
     * 12. Restore MU related registers
     */
    MUB_CR = mubCrBackup;
    NVIC->ISER[MU_M4_IRQn >> 5] = nvicMubEnableBackup;
    NVIC->IP[(uint32_t)(MU_M4_IRQn)] = (uint8_t)nvicMubPriorityBackup;

#if defined(__CC_ARM)
    __regBasePri = basePriBackup & 0xFF;
#else
    __set_BASEPRI(basePriBackup);
#endif
    __DSB();
    __ISB();
}

/*FUNCTION**********************************************************************
 *
 * Function Name : RAM_Wfi_End
 * Description   : A trick to get the end of ram_wfi
 *
 *END**************************************************************************/
static void RAM_Wfi_End(void)
{
    return;
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
