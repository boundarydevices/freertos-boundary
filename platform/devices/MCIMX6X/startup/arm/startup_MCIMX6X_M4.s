; * ---------------------------------------------------------------------------------------
; *  @file:    startup_MCIMX6X_M4.s
; *  @purpose: CMSIS Cortex-M4 Core Device Startup File
; *            MCIMX6X_M4
; *  @version: 0.1
; *  @date:    2015-5-27
; *  @build:   b150527
; * ---------------------------------------------------------------------------------------
; *
; * Copyright (c) 2015 , Freescale Semiconductor, Inc.
; * All rights reserved.
; *
; * Redistribution and use in source and binary forms, with or without modification,
; * are permitted provided that the following conditions are met:
; *
; * o Redistributions of source code must retain the above copyright notice, this list
; *   of conditions and the following disclaimer.
; *
; * o Redistributions in binary form must reproduce the above copyright notice, this
; *   list of conditions and the following disclaimer in the documentation and/or
; *   other materials provided with the distribution.
; *
; * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
; *   contributors may be used to endorse or promote products derived from this
; *   software without specific prior written permission.
; *
; * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
; * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
; * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
; * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
; * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
; * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
; * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
; * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
; * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
; * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
; *
; *------- <<< Use Configuration Wizard in Context Menu >>> ------------------
; *
; *****************************************************************************/


                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size
                IMPORT |Image$$ARM_LIB_STACK$$ZI$$Limit|

__Vectors       DCD    |Image$$ARM_LIB_STACK$$ZI$$Limit|           ;Top of Stack
                DCD     Reset_Handler                              ;Reset Handler
                DCD     NMI_Handler                                ;NMI Handler
                DCD     HardFault_Handler                          ;Hard Fault Handler
                DCD     MemManage_Handler                          ;MPU Fault Handler
                DCD     BusFault_Handler                           ;Bus Fault Handler
                DCD     UsageFault_Handler                         ;Usage Fault Handler
                DCD     0                                          ;Reserved
                DCD     0                                          ;Reserved
                DCD     0                                          ;Reserved
                DCD     0                                          ;Reserved
                DCD     SVC_Handler                                ;SVCall Handler
                DCD     DebugMon_Handler                           ;Debug Monitor Handler
                DCD     0                                          ;Reserved
                DCD     PendSV_Handler                             ;PendSV Handler
                DCD     SysTick_Handler                            ;SysTick Handler

                                                                   ;External Interrupts
                DCD     CORTEX_M4_Handler                          ;Cache Controller interrupt
                DCD     DAP_Handler                                ;Debug Access Port interrupt request
                DCD     SDMA_Handler                               ;SDMA interrupt request from all channels
                DCD     Reserved19_Handler                         ;Reserved interrupt 19
                DCD     SNVS_PMIC_Handler                          ;PMIC power off request
                DCD     LCDIF1_Handler                             ;LCDIF1 Sync Interrupt
                DCD     LCDIF2_Handler                             ;LCDIF1 Sync Interrupt
                DCD     CSI1_Handler                               ;CMOS Sensor Interface interrupt request
                DCD     PXP_Handler                                ;PXP interrupt
                DCD     Reserved25_Handler                         ;Reserved interrupt 25
                DCD     GPU_Handler                                ;GPU general interrupt request
                DCD     WDOG3_Handler                              ;WDOG3 interrupt request
                DCD     SEMA4_CP1_Handler                          ;SEMA4 CP1 interrupt request
                DCD     APBH_DMA_Handler                           ;Logical OR of APBH DMA channels 0-3 completion and error interrupts
                DCD     EIM_Handler                                ;EIM interrupt request
                DCD     BCH_Handler                                ;BCH operation complete interrupt
                DCD     GPMI_Handler                               ;GPMI operation timeout error interrupt
                DCD     UART6_Handler                              ;UART6 interrupt request
                DCD     eCSPI5_Handler                             ;eCSPI5 interrupt request
                DCD     SNVS_Consolidated_Handler                  ;SNVS consolidated interrupt
                DCD     SNVS_Security_Handler                      ;SNVS security interrupt
                DCD     CSU_Handler                                ;CSU interrupt request 1
                DCD     uSDHC1_Handler                             ;uSDHC1 (Enhanced SDHC) interrupt request
                DCD     uSDHC2_Handler                             ;uSDHC2 (Enhanced SDHC) interrupt request
                DCD     uSDHC3_Handler                             ;uSDHC3 (Enhanced SDHC) interrupt request
                DCD     uSDHC4_Handler                             ;uSDHC4 (Enhanced SDHC) interrupt request
                DCD     UART1_Handler                              ;UART1 interrupt request
                DCD     UART2_Handler                              ;UART2 interrupt request
                DCD     UART3_Handler                              ;UART3 interrupt request
                DCD     UART4_Handler                              ;UART4 interrupt request
                DCD     UART5_Handler                              ;UART5 interrupt request
                DCD     eCSPI1_Handler                             ;eCSPI1 interrupt request
                DCD     eCSPI2_Handler                             ;eCSPI2 interrupt request
                DCD     eCSPI3_Handler                             ;eCSPI3 interrupt request
                DCD     eCSPI4_Handler                             ;eCSPI4 interrupt request
                DCD     I2C4_Handler                               ;I2C4 interrupt request
                DCD     I2C1_Handler                               ;I2C1 interrupt request
                DCD     I2C2_Handler                               ;I2C2 interrupt request
                DCD     I2C3_Handler                               ;I2C3 interrupt request
                DCD     RDC_Handler                                ;RDC interrupt request
                DCD     USB_HISC_Handler                           ;USB HISC Host interrupt request
                DCD     CSI2_Handler                               ;CSI interrupt
                DCD     USB_OTG2_Handler                           ;USB OTG 2 interrupt request
                DCD     USB_OTG1_Handler                           ;USB OTG 1 interrupt request
                DCD     USB_PHY_UTMI0_Handler                      ;UTMI0 interrupt request
                DCD     USB_PHY_UTMI1_Handler                      ;UTMI1 interrupt request
                DCD     SSI1_Handler                               ;SSI1 interrupt request
                DCD     SSI2_Handler                               ;SSI2 interrupt request
                DCD     SSI3_Handler                               ;SSI3 interrupt request
                DCD     TEMPMON_Handler                            ;Temperature Sensor (temp. greater than threshold) interrupt request
                DCD     ASRC_Handler                               ;ASRC interrupt request
                DCD     ESAI_Handler                               ;ESAI interrupt request
                DCD     SPDIF_Handler                              ;SPDIF Rx/Tx interrupt
                DCD     MLB_Error_Handler                          ;MLB error interrupt request
                DCD     PMU_BrownOut_Handler                       ;Brown-out event
                DCD     GPT_Handler                                ;Logical OR of GPT rollover interrupt line, input capture 1 & 2 lines, output compare 1, 2 & 3 interrupt lines
                DCD     EPIT1_Handler                              ;EPIT1 output compare interrupt
                DCD     EPIT2_Handler                              ;EPIT2 output compare interrupt
                DCD     GPIO1_INT7_Handler                         ;INT7 interrupt request
                DCD     GPIO1_INT6_Handler                         ;INT6 interrupt request
                DCD     GPIO1_INT5_Handler                         ;INT5 interrupt request
                DCD     GPIO1_INT4_Handler                         ;INT4 interrupt request
                DCD     GPIO1_INT3_Handler                         ;INT3 interrupt request
                DCD     GPIO1_INT2_Handler                         ;INT2 interrupt request
                DCD     GPIO1_INT1_Handler                         ;INT1 interrupt request
                DCD     GPIO1_INT0_Handler                         ;INT0 interrupt request
                DCD     GPIO1_Combined_0_15_Handler                ;Combined interrupt indication for GPIO1 signals 0 - 15
                DCD     GPIO1_Combined_16_31_Handler               ;Combined interrupt indication for GPIO1 signals 16 - 31
                DCD     GPIO2_Combined_0_15_Handler                ;Combined interrupt indication for GPIO2 signals 0 - 15
                DCD     GPIO2_Combined_16_31_Handler               ;Combined interrupt indication for GPIO2 signals 16 - 31
                DCD     GPIO3_Combined_0_15_Handler                ;Combined interrupt indication for GPIO3 signals 0 - 15
                DCD     GPIO3_Combined_16_31_Handler               ;Combined interrupt indication for GPIO3 signals 16 - 31
                DCD     GPIO4_Combined_0_15_Handler                ;Combined interrupt indication for GPIO4 signals 0 - 15
                DCD     GPIO4_Combined_16_31_Handler               ;Combined interrupt indication for GPIO4 signals 16 - 31
                DCD     GPIO5_Combined_0_15_Handler                ;Combined interrupt indication for GPIO5 signals 0 - 15
                DCD     GPIO5_Combined_16_31_Handler               ;Combined interrupt indication for GPIO5 signals 16 - 31
                DCD     GPIO6_Combined_0_15_Handler                ;Combined interrupt indication for GPIO6 signals 0 - 15
                DCD     GPIO6_Combined_16_31_Handler               ;Combined interrupt indication for GPIO6 signals 16 - 31
                DCD     GPIO7_Combined_0_15_Handler                ;Combined interrupt indication for GPIO7 signals 0 - 15
                DCD     GPIO7_Combined_16_31_Handler               ;Combined interrupt indication for GPIO7 signals 16 - 31
                DCD     WDOG1_Handler                              ;WDOG1 timer reset interrupt request
                DCD     WDOG2_Handler                              ;WDOG2 timer reset interrupt request
                DCD     KPP_Handler                                ;Key Pad interrupt request
                DCD     PWM1_PWM5_Handler                          ;Cumulative interrupt line for PWM1/PWM5. Logical OR of rollover, compare, and FIFO waterlevel crossing interrupts
                DCD     PWM2_PWM6_Handler                          ;Cumulative interrupt line for PWM2/PWM6. Logical OR of rollover, compare, and FIFO waterlevel crossing interrupts
                DCD     PWM3_PWM7_Handler                          ;Cumulative interrupt line for PWM3/PWM7. Logical OR of rollover, compare, and FIFO waterlevel crossing interrupts
                DCD     PWM4_PWM8_Handler                          ;Cumulative interrupt line for PWM4/PWM8. Logical OR of rollover, compare, and FIFO waterlevel crossing interrupts
                DCD     CCM1_Handler                               ;CCM interrupt request 1
                DCD     CCM2_Handler                               ;CCM interrupt request 2
                DCD     GPC_Handler                                ;GPC interrupt request 1
                DCD     MU_A9_Handler                              ;Message unit interrupt to A9 core
                DCD     SRC_Handler                                ;SRC interrupt request
                DCD     CPU_L2_Handler                             ;L2 interrupt request
                DCD     CPU_Parity_Handler                         ;Parity Check error interrupt request
                DCD     CPU_Perfomance_Handler                     ;Performance Unit interrupt
                DCD     CPU_CTI_Trigger_Handler                    ;CTI trigger outputs interrupt
                DCD     SRC_WDOG_Handler                           ;Combined CPU wdog interrupts (4x) out of SRC
                DCD     SAI1_Handler                               ;SAI1 interrupt request
                DCD     SAI2_Handler                               ;SAI2 interrupt request
                DCD     MU_M4_Handler                              ;Message unit Interrupt to M4 core
                DCD     ADC1_Handler                               ;ADC1 interrupt request
                DCD     ADC2_Handler                               ;ADC2 interrupt request
                DCD     ENET2_Handler                              ;ENET2 Interrupt Request
                DCD     ENET2_Timer_Handler                        ;ENET2 1588 Timer interrupt [synchronous] request
                DCD     SJC_Handler                                ;SJC interrupt from General Purpose register
                DCD     CAAM0_Handler                              ;CAAM job ring 0 interrupt
                DCD     CAAM1_Handler                              ;CAAM job ring 1 interrupt
                DCD     QSPI1_Handler                              ;QSPI1 interrupt request
                DCD     TZASC_Handler                              ;TZASC (PL380) interrupt request
                DCD     QSPI2_Handler                              ;QSPI2 interrupt request
                DCD     FLEXCAN1_Handler                           ;FLEXCAN1 combined interrupt
                DCD     FLEXCAN2_Handler                           ;FLEXCAN1 combined interrupt
                DCD     Reserved128_Handler                        ;Reserved interrupt 128
                DCD     Reserved129_Handler                        ;Reserved interrupt 129
                DCD     CANFD1_Handler                             ;CANFD1 interrupt request
                DCD     CANFD2_Handler                             ;CANFD2 interrupt request
                DCD     SEMA4_CP0_Handler                          ;SEMA4 CP0 interrupt request
                DCD     MLB_Channels_31_0_Handler                  ;MLB Interrupt request for channels [31:0]
                DCD     ENET1_Handler                              ;ENET1 Interrupt Request
                DCD     ENET1_Timer_Handler                        ;ENET1 1588 Timer interrupt [synchronous] request
                DCD     PCIe1_Handler                              ;PCIe interrupt request 1
                DCD     PCIe2_Handler                              ;PCIe interrupt request 2
                DCD     PCIe3_Handler                              ;PCIe interrupt request 3
                DCD     PCIe4_Handler                              ;PCIe interrupt request 4
                DCD     DCIC1_Handler                              ;DCIC1 interrupt request
                DCD     DCIC2_Handler                              ;DCIC2 interrupt request
                DCD     MLB_Channels_63_32_Handler                 ;MLB Interrupt request for channels [63:32]
                DCD     PMU_BrownOutCore_Handler                   ;Brown out of core, gpu, and chip digital regulators occurred
__Vectors_End

__Vectors_Size  EQU     __Vectors_End - __Vectors


                AREA    |.text|, CODE, READONLY

; Reset Handler

Reset_Handler   PROC
                EXPORT  Reset_Handler                   [WEAK]
                IMPORT  SystemInit
                IMPORT  __main

                CPSID   I               ; Mask interrupts
                LDR     R0, =SystemInit
                BLX     R0
                CPSIE   i               ; Unmask interrupts
                LDR     R0, =__main
                BX      R0
                ENDP


; Dummy Exception Handlers (infinite loops which can be modified)
NMI_Handler\
                PROC
                EXPORT  NMI_Handler                     [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler               [WEAK]
                B       .
                ENDP
MemManage_Handler\
                PROC
                EXPORT  MemManage_Handler               [WEAK]
                B       .
                ENDP
BusFault_Handler\
                PROC
                EXPORT  BusFault_Handler                [WEAK]
                B       .
                ENDP
UsageFault_Handler\
                PROC
                EXPORT  UsageFault_Handler              [WEAK]
                B       .
                ENDP
SVC_Handler\
                PROC
                EXPORT  SVC_Handler                     [WEAK]
                B       .
                ENDP
DebugMon_Handler\
                PROC
                EXPORT  DebugMon_Handler                [WEAK]
                B       .
                ENDP
PendSV_Handler\
                PROC
                EXPORT  PendSV_Handler                  [WEAK]
                B       .
                ENDP
SysTick_Handler\
                PROC
                EXPORT  SysTick_Handler                 [WEAK]
                B       .
                ENDP
Default_Handler\
                PROC
                EXPORT  CORTEX_M4_Handler               [WEAK]
                EXPORT  DAP_Handler                     [WEAK]
                EXPORT  SDMA_Handler                    [WEAK]
                EXPORT  Reserved19_Handler              [WEAK]
                EXPORT  SNVS_PMIC_Handler               [WEAK]
                EXPORT  LCDIF1_Handler                  [WEAK]
                EXPORT  LCDIF2_Handler                  [WEAK]
                EXPORT  CSI1_Handler                    [WEAK]
                EXPORT  PXP_Handler                     [WEAK]
                EXPORT  Reserved25_Handler              [WEAK]
                EXPORT  GPU_Handler                     [WEAK]
                EXPORT  WDOG3_Handler                   [WEAK]
                EXPORT  SEMA4_CP1_Handler               [WEAK]
                EXPORT  APBH_DMA_Handler                [WEAK]
                EXPORT  EIM_Handler                     [WEAK]
                EXPORT  BCH_Handler                     [WEAK]
                EXPORT  GPMI_Handler                    [WEAK]
                EXPORT  UART6_Handler                   [WEAK]
                EXPORT  eCSPI5_Handler                  [WEAK]
                EXPORT  SNVS_Consolidated_Handler       [WEAK]
                EXPORT  SNVS_Security_Handler           [WEAK]
                EXPORT  CSU_Handler                     [WEAK]
                EXPORT  uSDHC1_Handler                  [WEAK]
                EXPORT  uSDHC2_Handler                  [WEAK]
                EXPORT  uSDHC3_Handler                  [WEAK]
                EXPORT  uSDHC4_Handler                  [WEAK]
                EXPORT  UART1_Handler                   [WEAK]
                EXPORT  UART2_Handler                   [WEAK]
                EXPORT  UART3_Handler                   [WEAK]
                EXPORT  UART4_Handler                   [WEAK]
                EXPORT  UART5_Handler                   [WEAK]
                EXPORT  eCSPI1_Handler                  [WEAK]
                EXPORT  eCSPI2_Handler                  [WEAK]
                EXPORT  eCSPI3_Handler                  [WEAK]
                EXPORT  eCSPI4_Handler                  [WEAK]
                EXPORT  I2C4_Handler                    [WEAK]
                EXPORT  I2C1_Handler                    [WEAK]
                EXPORT  I2C2_Handler                    [WEAK]
                EXPORT  I2C3_Handler                    [WEAK]
                EXPORT  RDC_Handler                     [WEAK]
                EXPORT  USB_HISC_Handler                [WEAK]
                EXPORT  CSI2_Handler                    [WEAK]
                EXPORT  USB_OTG2_Handler                [WEAK]
                EXPORT  USB_OTG1_Handler                [WEAK]
                EXPORT  USB_PHY_UTMI0_Handler           [WEAK]
                EXPORT  USB_PHY_UTMI1_Handler           [WEAK]
                EXPORT  SSI1_Handler                    [WEAK]
                EXPORT  SSI2_Handler                    [WEAK]
                EXPORT  SSI3_Handler                    [WEAK]
                EXPORT  TEMPMON_Handler                 [WEAK]
                EXPORT  ASRC_Handler                    [WEAK]
                EXPORT  ESAI_Handler                    [WEAK]
                EXPORT  SPDIF_Handler                   [WEAK]
                EXPORT  MLB_Error_Handler               [WEAK]
                EXPORT  PMU_BrownOut_Handler            [WEAK]
                EXPORT  GPT_Handler                     [WEAK]
                EXPORT  EPIT1_Handler                   [WEAK]
                EXPORT  EPIT2_Handler                   [WEAK]
                EXPORT  GPIO1_INT7_Handler              [WEAK]
                EXPORT  GPIO1_INT6_Handler              [WEAK]
                EXPORT  GPIO1_INT5_Handler              [WEAK]
                EXPORT  GPIO1_INT4_Handler              [WEAK]
                EXPORT  GPIO1_INT3_Handler              [WEAK]
                EXPORT  GPIO1_INT2_Handler              [WEAK]
                EXPORT  GPIO1_INT1_Handler              [WEAK]
                EXPORT  GPIO1_INT0_Handler              [WEAK]
                EXPORT  GPIO1_Combined_0_15_Handler     [WEAK]
                EXPORT  GPIO1_Combined_16_31_Handler    [WEAK]
                EXPORT  GPIO2_Combined_0_15_Handler     [WEAK]
                EXPORT  GPIO2_Combined_16_31_Handler    [WEAK]
                EXPORT  GPIO3_Combined_0_15_Handler     [WEAK]
                EXPORT  GPIO3_Combined_16_31_Handler    [WEAK]
                EXPORT  GPIO4_Combined_0_15_Handler     [WEAK]
                EXPORT  GPIO4_Combined_16_31_Handler    [WEAK]
                EXPORT  GPIO5_Combined_0_15_Handler     [WEAK]
                EXPORT  GPIO5_Combined_16_31_Handler    [WEAK]
                EXPORT  GPIO6_Combined_0_15_Handler     [WEAK]
                EXPORT  GPIO6_Combined_16_31_Handler    [WEAK]
                EXPORT  GPIO7_Combined_0_15_Handler     [WEAK]
                EXPORT  GPIO7_Combined_16_31_Handler    [WEAK]
                EXPORT  WDOG1_Handler                   [WEAK]
                EXPORT  WDOG2_Handler                   [WEAK]
                EXPORT  KPP_Handler                     [WEAK]
                EXPORT  PWM1_PWM5_Handler               [WEAK]
                EXPORT  PWM2_PWM6_Handler               [WEAK]
                EXPORT  PWM3_PWM7_Handler               [WEAK]
                EXPORT  PWM4_PWM8_Handler               [WEAK]
                EXPORT  CCM1_Handler                    [WEAK]
                EXPORT  CCM2_Handler                    [WEAK]
                EXPORT  GPC_Handler                     [WEAK]
                EXPORT  MU_A9_Handler                   [WEAK]
                EXPORT  SRC_Handler                     [WEAK]
                EXPORT  CPU_L2_Handler                  [WEAK]
                EXPORT  CPU_Parity_Handler              [WEAK]
                EXPORT  CPU_Perfomance_Handler          [WEAK]
                EXPORT  CPU_CTI_Trigger_Handler         [WEAK]
                EXPORT  SRC_WDOG_Handler                [WEAK]
                EXPORT  SAI1_Handler                    [WEAK]
                EXPORT  SAI2_Handler                    [WEAK]
                EXPORT  MU_M4_Handler                   [WEAK]
                EXPORT  ADC1_Handler                    [WEAK]
                EXPORT  ADC2_Handler                    [WEAK]
                EXPORT  ENET2_Handler                   [WEAK]
                EXPORT  ENET2_Timer_Handler             [WEAK]
                EXPORT  SJC_Handler                     [WEAK]
                EXPORT  CAAM0_Handler                   [WEAK]
                EXPORT  CAAM1_Handler                   [WEAK]
                EXPORT  QSPI1_Handler                   [WEAK]
                EXPORT  TZASC_Handler                   [WEAK]
                EXPORT  QSPI2_Handler                   [WEAK]
                EXPORT  FLEXCAN1_Handler                [WEAK]
                EXPORT  FLEXCAN2_Handler                [WEAK]
                EXPORT  Reserved128_Handler             [WEAK]
                EXPORT  Reserved129_Handler             [WEAK]
                EXPORT  CANFD1_Handler                  [WEAK]
                EXPORT  CANFD2_Handler                  [WEAK]
                EXPORT  SEMA4_CP0_Handler               [WEAK]
                EXPORT  MLB_Channels_31_0_Handler       [WEAK]
                EXPORT  ENET1_Handler                   [WEAK]
                EXPORT  ENET1_Timer_Handler             [WEAK]
                EXPORT  PCIe1_Handler                   [WEAK]
                EXPORT  PCIe2_Handler                   [WEAK]
                EXPORT  PCIe3_Handler                   [WEAK]
                EXPORT  PCIe4_Handler                   [WEAK]
                EXPORT  DCIC1_Handler                   [WEAK]
                EXPORT  DCIC2_Handler                   [WEAK]
                EXPORT  MLB_Channels_63_32_Handler      [WEAK]
                EXPORT  PMU_BrownOutCore_Handler        [WEAK]
CORTEX_M4_Handler
DAP_Handler
SDMA_Handler
Reserved19_Handler
SNVS_PMIC_Handler
LCDIF1_Handler
LCDIF2_Handler
CSI1_Handler
PXP_Handler
Reserved25_Handler
GPU_Handler
WDOG3_Handler
SEMA4_CP1_Handler
APBH_DMA_Handler
EIM_Handler
BCH_Handler
GPMI_Handler
UART6_Handler
eCSPI5_Handler
SNVS_Consolidated_Handler
SNVS_Security_Handler
CSU_Handler
uSDHC1_Handler
uSDHC2_Handler
uSDHC3_Handler
uSDHC4_Handler
UART1_Handler
UART2_Handler
UART3_Handler
UART4_Handler
UART5_Handler
eCSPI1_Handler
eCSPI2_Handler
eCSPI3_Handler
eCSPI4_Handler
I2C4_Handler
I2C1_Handler
I2C2_Handler
I2C3_Handler
RDC_Handler
USB_HISC_Handler
CSI2_Handler
USB_OTG2_Handler
USB_OTG1_Handler
USB_PHY_UTMI0_Handler
USB_PHY_UTMI1_Handler
SSI1_Handler
SSI2_Handler
SSI3_Handler
TEMPMON_Handler
ASRC_Handler
ESAI_Handler
SPDIF_Handler
MLB_Error_Handler
PMU_BrownOut_Handler
GPT_Handler
EPIT1_Handler
EPIT2_Handler
GPIO1_INT7_Handler
GPIO1_INT6_Handler
GPIO1_INT5_Handler
GPIO1_INT4_Handler
GPIO1_INT3_Handler
GPIO1_INT2_Handler
GPIO1_INT1_Handler
GPIO1_INT0_Handler
GPIO1_Combined_0_15_Handler
GPIO1_Combined_16_31_Handler
GPIO2_Combined_0_15_Handler
GPIO2_Combined_16_31_Handler
GPIO3_Combined_0_15_Handler
GPIO3_Combined_16_31_Handler
GPIO4_Combined_0_15_Handler
GPIO4_Combined_16_31_Handler
GPIO5_Combined_0_15_Handler
GPIO5_Combined_16_31_Handler
GPIO6_Combined_0_15_Handler
GPIO6_Combined_16_31_Handler
GPIO7_Combined_0_15_Handler
GPIO7_Combined_16_31_Handler
WDOG1_Handler
WDOG2_Handler
KPP_Handler
PWM1_PWM5_Handler
PWM2_PWM6_Handler
PWM3_PWM7_Handler
PWM4_PWM8_Handler
CCM1_Handler
CCM2_Handler
GPC_Handler
MU_A9_Handler
SRC_Handler
CPU_L2_Handler
CPU_Parity_Handler
CPU_Perfomance_Handler
CPU_CTI_Trigger_Handler
SRC_WDOG_Handler
SAI1_Handler
SAI2_Handler
MU_M4_Handler
ADC1_Handler
ADC2_Handler
ENET2_Handler
ENET2_Timer_Handler
SJC_Handler
CAAM0_Handler
CAAM1_Handler
QSPI1_Handler
TZASC_Handler
QSPI2_Handler
FLEXCAN1_Handler
FLEXCAN2_Handler
Reserved128_Handler
Reserved129_Handler
CANFD1_Handler
CANFD2_Handler
SEMA4_CP0_Handler
MLB_Channels_31_0_Handler
ENET1_Handler
ENET1_Timer_Handler
PCIe1_Handler
PCIe2_Handler
PCIe3_Handler
PCIe4_Handler
DCIC1_Handler
DCIC2_Handler
MLB_Channels_63_32_Handler
PMU_BrownOutCore_Handler
DefaultISR
                B      DefaultISR
                ENDP
                  ALIGN


                END
