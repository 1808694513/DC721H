;/******************************************************************************
; * Copyright (C) 2021, Xiaohua Semiconductor Co., Ltd. All rights reserved.
; *
; * This software component is licensed by XHSC under BSD 3-Clause license
; * (the "License"); You may not use this file except in compliance with the
; * License. You may obtain a copy of the License at:
; *                    opensource.org/licenses/BSD-3-Clause
; *
; ******************************************************************************/

;/*****************************************************************************/
;/*  Startup for IAR                                                          */
;/*  Version     V1.0                                                         */
;/*  Date        2021-12-02                                                   */
;/*  Target-mcu  HC32F002                                                     */
;/*****************************************************************************/


                MODULE  ?cstartup

                ;; Forward declaration of sections.
                SECTION CSTACK:DATA:NOROOT(3)

                EXTERN  __iar_program_start
                EXTERN  SystemInit
                PUBLIC  __vector_table
                
                SECTION .intvec:CODE:ROOT(8)
                DATA
__vector_table  
                DCD     sfe(CSTACK)               ; Top of Stack
                DCD     Reset_Handler             ; Reset
                DCD     NMI_Handler               ; NMI
                DCD     HardFault_Handler         ; Hard Fault
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     SVC_Handler               ; SVCall
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     PendSV_Handler            ; PendSV
                DCD     SysTick_Handler           ; SysTick

; Numbered IRQ handler vectors

; Note: renaming to device dependent ISR function names are done in

                DCD     PORTA_IRQHandler            ; IRQ #0 
                DCD     PORTB_IRQHandler            ; IRQ #1 
                DCD     PORTC_IRQHandler            ; IRQ #2 
                DCD     Dummy_IRQHandler            ; IRQ #3 
                DCD     DMAC_IRQHandler             ; IRQ #4 
                DCD     ATIM3_IRQHandler            ; IRQ #5 
                DCD     Dummy_IRQHandler            ; IRQ #6 
                DCD     USART_IRQHandler            ; IRQ #7 
                DCD     LPUART0_IRQHandler          ; IRQ #8 
                DCD     LPUART1_IRQHandler          ; IRQ #9 
                DCD     SPI0_IRQHandler             ; IRQ #10
                DCD     SPI1_IRQHandler             ; IRQ #11
                DCD     I2C_IRQHandler              ; IRQ #12
                DCD     I2CSLV_IRQHandler           ; IRQ #13
                DCD     ATIM_IRQHandler             ; IRQ #14
                DCD     GTIM_IRQHandler             ; IRQ #15
                DCD     Dummy_IRQHandler            ; IRQ #16
                DCD     LPTIM_IRQHandler            ; IRQ #17
                DCD     Dummy_IRQHandler            ; IRQ #18
                DCD     Dummy_IRQHandler            ; IRQ #19
                DCD     PLA_IRQHandler              ; IRQ #20
                DCD     BTIM_IRQHandler             ; IRQ #21
                DCD     WDT_WWDT_IRQHandler         ; IRQ #22
                DCD     RTC_IRQHandler              ; IRQ #23
                DCD     ADC_IRQHandler              ; IRQ #24
                DCD     Dummy_IRQHandler            ; IRQ #25
                DCD     Dummy_IRQHandler            ; IRQ #26
                DCD     VC_IRQHandler               ; IRQ #27
                DCD     LVD_IRQHandler              ; IRQ #28
                DCD     Dummy_IRQHandler            ; IRQ #29
                DCD     FLASH_RAM_IRQHandler        ; IRQ #30
                DCD     CTRIM_IRQHandler            ; IRQ #31


                THUMB

                PUBWEAK Reset_Handler
                SECTION .text:CODE:NOROOT:REORDER(2)
Reset_Handler
                ;reset NVIC if in rom debug
                LDR     R0, =0x20000000
                LDR     R2, =0x0              ; vector offset
                cmp     PC, R0
                bls     ROMCODE
              
              ; ram code base address. 
                ADD     R2, R0,R2
ROMCODE
              ; reset Vector table address.
                LDR     R0, =0xE000ED08
                STR     R2, [R0]
                
                LDR     R0, =SystemInit
                BLX     R0
                LDR     R0, =__iar_program_start
                BX      R0

                PUBWEAK NMI_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
NMI_Handler
                B       NMI_Handler

                PUBWEAK HardFault_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
HardFault_Handler
                B       HardFault_Handler


                PUBWEAK SVC_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
SVC_Handler
                B       SVC_Handler

                PUBWEAK PendSV_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
PendSV_Handler
                B       PendSV_Handler

                PUBWEAK SysTick_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
SysTick_Handler
                B       SysTick_Handler

                PUBWEAK PORTA_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
PORTA_IRQHandler
                B       PORTA_IRQHandler


                PUBWEAK PORTB_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
PORTB_IRQHandler
                B       PORTB_IRQHandler


                PUBWEAK PORTC_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
PORTC_IRQHandler
                B       PORTC_IRQHandler


                PUBWEAK Dummy_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
Dummy_IRQHandler
                B       Dummy_IRQHandler


                PUBWEAK DMAC_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
DMAC_IRQHandler
                B       DMAC_IRQHandler


                PUBWEAK ATIM3_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
ATIM3_IRQHandler
                B       ATIM3_IRQHandler


                PUBWEAK USART_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
USART_IRQHandler
                B       USART_IRQHandler


                PUBWEAK LPUART0_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
LPUART0_IRQHandler
                B       LPUART0_IRQHandler


                PUBWEAK LPUART1_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
LPUART1_IRQHandler
                B       LPUART1_IRQHandler


                PUBWEAK SPI0_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
SPI0_IRQHandler
                B       SPI0_IRQHandler


                PUBWEAK SPI1_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
SPI1_IRQHandler
                B       SPI1_IRQHandler


                PUBWEAK I2C_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
I2C_IRQHandler
                B       I2C_IRQHandler


                PUBWEAK I2CSLV_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
I2CSLV_IRQHandler
                B       I2CSLV_IRQHandler


                PUBWEAK ATIM_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
ATIM_IRQHandler
                B       ATIM_IRQHandler


                PUBWEAK GTIM_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
GTIM_IRQHandler
                B       GTIM_IRQHandler


                PUBWEAK LPTIM_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
LPTIM_IRQHandler
                B       LPTIM_IRQHandler


                PUBWEAK PLA_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
PLA_IRQHandler
                B       PLA_IRQHandler


                PUBWEAK BTIM_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
BTIM_IRQHandler
                B       BTIM_IRQHandler


                PUBWEAK WDT_WWDT_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
WDT_WWDT_IRQHandler
                B       WDT_WWDT_IRQHandler


                PUBWEAK RTC_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
RTC_IRQHandler
                B       RTC_IRQHandler


                PUBWEAK ADC_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
ADC_IRQHandler
                B       ADC_IRQHandler


                PUBWEAK VC_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
VC_IRQHandler
                B       VC_IRQHandler


                PUBWEAK LVD_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
LVD_IRQHandler
                B       LVD_IRQHandler


                PUBWEAK FLASH_RAM_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
FLASH_RAM_IRQHandler
                B       FLASH_RAM_IRQHandler


                PUBWEAK CTRIM_IRQHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
CTRIM_IRQHandler
                B       CTRIM_IRQHandler
                
                
                END
