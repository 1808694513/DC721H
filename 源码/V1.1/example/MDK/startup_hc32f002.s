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
;/*  Startup for ARM                                                          */
;/*  Version     V1.0                                                         */
;/*  Date        2021-12-02                                                   */
;/*  Target-mcu  HC32F002                                                     */
;/*****************************************************************************/

; Stack Configuration
; Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>

Stack_Size      EQU     0x00000200			; 栈大小分配

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; Heap Configuration
;  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>

Heap_Size       EQU     0x00000200			; 堆大小分配

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size

__Vectors                       
                DCD     __initial_sp                ; Top of Stack
                DCD     Reset_Handler               ; Reset        
                DCD     NMI_Handler                 ; NMI
                DCD     HardFault_Handler           ; Hard Fault
                DCD     0                           ; Reserved
                DCD     0                           ; Reserved
                DCD     0                           ; Reserved
                DCD     0                           ; Reserved
                DCD     0                           ; Reserved
                DCD     0                           ; Reserved
                DCD     0                           ; Reserved
                DCD     SVC_Handler                 ; SVCall
                DCD     0                           ; Reserved
                DCD     0                           ; Reserved
                DCD     PendSV_Handler              ; PendSV
                DCD     SysTick_Handler             ; SysTick

                DCD     PORTA_IRQHandler            ; IRQ #0 
                DCD     PORTB_IRQHandler            ; IRQ #1 
                DCD     PORTC_IRQHandler            ; IRQ #2 
                DCD     PORTD_IRQHandler            ; IRQ #3 
                DCD     Dummy_IRQHandler            ; IRQ #4 
                DCD     ATIM3_IRQHandler            ; IRQ #5 
                DCD     Dummy_IRQHandler            ; IRQ #6 
                DCD     Dummy_IRQHandler            ; IRQ #7 
                DCD     LPUART0_IRQHandler          ; IRQ #8 
                DCD     LPUART1_IRQHandler          ; IRQ #9 
                DCD     SPI_IRQHandler              ; IRQ #10
                DCD     Dummy_IRQHandler            ; IRQ #11
                DCD     I2C_IRQHandler              ; IRQ #12
                DCD     Dummy_IRQHandler            ; IRQ #13
                DCD     Dummy_IRQHandler            ; IRQ #14
                DCD     GTIM_BTIM3_4_5_IRQHandler   ; IRQ #15
                DCD     Dummy_IRQHandler            ; IRQ #16
                DCD     Dummy_IRQHandler            ; IRQ #17
                DCD     Dummy_IRQHandler            ; IRQ #18
                DCD     Dummy_IRQHandler            ; IRQ #19
                DCD     Dummy_IRQHandler            ; IRQ #20
                DCD     Dummy_IRQHandler            ; IRQ #21
                DCD     IWDT_WWDT_IRQHandler        ; IRQ #22
                DCD     Dummy_IRQHandler            ; IRQ #23
                DCD     ADC_IRQHandler              ; IRQ #24
                DCD     Dummy_IRQHandler            ; IRQ #25
                DCD     Dummy_IRQHandler            ; IRQ #26
                DCD     Dummy_IRQHandler            ; IRQ #27
                DCD     LVD_IRQHandler              ; IRQ #28
                DCD     Dummy_IRQHandler            ; IRQ #29
                DCD     FLASH_IRQHandler            ; IRQ #30
                DCD     CTRIM_IRQHandler            ; IRQ #31
__Vectors_End

__Vectors_Size 	EQU     __Vectors_End - __Vectors

                AREA    |.text|, CODE, READONLY


; Reset Handler
Reset_Handler   PROC
                EXPORT  Reset_Handler               [WEAK]
                IMPORT  SystemInit
                IMPORT  __main

               ;reset NVIC if in rom debug
                LDR     R0, =0x20000000
                LDR     R2, =0x0
                MOVS    R1, #0 
                ADD     R1, PC,#0 
                CMP     R1, R0
                BLS     RAMCODE

              ; ram code base address. 
                ADD     R2, R0,R2
RAMCODE
              ; reset Vector table address.
                LDR     R0, =0xE000ED08 
                STR     R2, [R0]

                LDR     R0, =SystemInit
                BLX     R0
                LDR     R0, =__main
                BX      R0
                ENDP


; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler                 [WEAK]
                B       .
                ENDP
                
                
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler           [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler                 [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler              [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler             [WEAK]
                B       .
                ENDP

Default_Handler PROC
                EXPORT  PORTA_IRQHandler              [WEAK]
                EXPORT  PORTB_IRQHandler              [WEAK]
                EXPORT  PORTC_IRQHandler              [WEAK]
                EXPORT  PORTD_IRQHandler              [WEAK]
                EXPORT  ATIM3_IRQHandler              [WEAK]
                EXPORT  LPUART0_IRQHandler            [WEAK]
                EXPORT  LPUART1_IRQHandler            [WEAK]
                EXPORT  SPI_IRQHandler                [WEAK]
                EXPORT  Dummy_IRQHandler              [WEAK]
                EXPORT  I2C_IRQHandler                [WEAK]
                EXPORT  GTIM_BTIM3_4_5_IRQHandler     [WEAK]
                EXPORT  IWDT_WWDT_IRQHandler          [WEAK]
                EXPORT  ADC_IRQHandler                [WEAK]
                EXPORT  LVD_IRQHandler                [WEAK]
                EXPORT  FLASH_IRQHandler              [WEAK]
                EXPORT  CTRIM_IRQHandler              [WEAK]

PORTA_IRQHandler      
PORTB_IRQHandler      
PORTC_IRQHandler      
PORTD_IRQHandler             
ATIM3_IRQHandler              
LPUART0_IRQHandler    
LPUART1_IRQHandler    
SPI_IRQHandler       
Dummy_IRQHandler       
I2C_IRQHandler                  
GTIM_BTIM3_4_5_IRQHandler               
IWDT_WWDT_IRQHandler                      
ADC_IRQHandler              
LVD_IRQHandler        
FLASH_IRQHandler  
CTRIM_IRQHandler     
                        
                              
                        
                        








                
               B .

                ENDP


                ALIGN


; User Initial Stack & Heap

                IF      :DEF:__MICROLIB

                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit

                ELSE

                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap
__user_initial_stackheap

                LDR     R0, =  Heap_Mem
                LDR     R1, =(Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR

                ALIGN

                ENDIF


                END
