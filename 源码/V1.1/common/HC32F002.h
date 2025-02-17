/******************************************************************************
* Copyright (C) 2021, Xiaohua Semiconductor Co., Ltd. All rights reserved.
*
* This software component is licensed by XHSC under BSD 3-Clause license
* (the "License"); You may not use this file except in compliance with the
* License. You may obtain a copy of the License at:
*                    opensource.org/licenses/BSD-3-Clause
*
******************************************************************************/

/******************************************************************************
** @file HC32F002.h
**
** @brief Headerfile for HC32F002 series MCU
**
** @author MADS Team
**
** - 2022-01-26.
**
******************************************************************************/

#ifndef __HC32F002_H__
#define __HC32F002_H__

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
* Configuration of the Cortex-M0P Processor and Core Peripherals
******************************************************************************/
#define __MPU_PRESENT           0 /* No MPU                                       */
#define __NVIC_PRIO_BITS        2 /* M0P uses 2 Bits for the Priority Levels      */
#define __Vendor_SysTickConfig  0 /* Set to 1 if different SysTick Config is used */

/******************************************************************************
* Interrupt Number Definition
******************************************************************************/
typedef enum IRQn
{
    NMI_IRQn            = -14, /*  2 Non Maskable                            */
    HardFault_IRQn      = -13, /*  3 Hard Fault                              */
    SVC_IRQn            = -5,  /* 11 SV Call                                 */
    PendSV_IRQn         = -2,  /* 14 Pend SV                                 */
    SysTick_IRQn        = -1,  /* 15 System Tick                             */
    
    PORTA_IRQn          = 0 ,
    PORTB_IRQn          = 1 ,
    PORTC_IRQn          = 2 ,
    PORTD_IRQn          = 3 ,
    ATIM3_IRQn          = 5 ,
    LPUART0_IRQn        = 8 ,
    LPUART1_IRQn        = 9 ,
    SPI0_IRQn           = 10,
    I2C_IRQn            = 12,
    BTIM3_4_5_IRQn      = 15,
    GTIM_IRQn           = 15,
    IWDT_WWDT_IRQn      = 22,
    ADC_IRQn            = 24,
    LVD_IRQn            = 28,
    FLASH_IRQn          = 30,
    CTRIM_IRQn          = 31,
    
    
} IRQn_Type;


#include <core_cm0plus.h>
#include <stdint.h>

#define SUCCESS         (0)
#define ERROR           (-1)

#ifndef NULL
#define NULL            (0)
#endif


/******************************************************************************/
/*                Device Specific Peripheral Registers structures             */
/******************************************************************************/

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

typedef struct
{
    __IO uint32_t EN                        : 1;
    uint32_t RESERVED1                      : 1;
    __IO uint32_t CKDIV                     : 3;
    uint32_t RESERVED5                      : 4;
    __IO uint32_t REF                       : 2;
    uint32_t RESERVED11                     : 1;
    __IO uint32_t SAM                       : 2;
    uint32_t RESERVED14                     :17;
    __IO uint32_t RSV                       : 1;
} stc_adc_cr0_field_t;

typedef struct
{
    __IO uint32_t CHSEL                     : 4;
    uint32_t RESERVED4                      :27;
    __IO uint32_t RSV                       : 1;
} stc_adc_cr1_field_t;

typedef struct
{
    __IO uint32_t RESULT                    :16;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_adc_result_field_t;

typedef struct
{
    __IO uint32_t EOC                       : 1;
    uint32_t RESERVED1                      :30;
    __IO uint32_t RSV                       : 1;
} stc_adc_ifr_field_t;

typedef struct
{
    __IO uint32_t EOC                       : 1;
    uint32_t RESERVED1                      :30;
    __IO uint32_t RSV                       : 1;
} stc_adc_ier_field_t;

typedef struct
{
    __IO uint32_t EOC                       : 1;
    uint32_t RESERVED1                      :30;
    __IO uint32_t RSV                       : 1;
} stc_adc_icr_field_t;

typedef struct
{
    __IO uint32_t TRIGSEL                   : 4;
    uint32_t RESERVED4                      :27;
    __IO uint32_t RSV                       : 1;
} stc_adc_exttrigger_field_t;

typedef struct
{
    __IO uint32_t START                     : 1;
    uint32_t RESERVED1                      :30;
    __IO uint32_t RSV                       : 1;
} stc_adc_start_field_t;

typedef struct
{
    __IO uint32_t START                     : 1;
    uint32_t RESERVED1                      :30;
    __IO uint32_t RSV                       : 1;
} stc_adc_allstart_field_t;

typedef struct
{
    __IO uint32_t ARR                       :16;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_atim3mode0_arr_field_t;

typedef struct
{
    __IO uint32_t CNT                       :16;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_atim3mode0_cnt_field_t;

typedef struct
{
    __IO uint32_t CNT32                     :32;
} stc_atim3mode0_cnt32_field_t;

typedef struct
{
    __IO uint32_t CEN                       : 1;
    __IO uint32_t MD                        : 1;
    __IO uint32_t CT                        : 1;
    __IO uint32_t TOG                       : 1;
    __IO uint32_t PRS                       : 3;
    uint32_t RESERVED7                      : 1;
    __IO uint32_t GATE                      : 1;
    __IO uint32_t GATEP                     : 1;
    __IO uint32_t UI                        : 1;
    uint32_t RESERVED11                     : 1;
    __IO uint32_t MODE                      : 2;
    uint32_t RESERVED14                     :17;
    __IO uint32_t RSV                       : 1;
} stc_atim3mode0_m0cr_field_t;

typedef struct
{
    __IO uint32_t UI                        : 1;
    uint32_t RESERVED1                      :30;
    __IO uint32_t RSV                       : 1;
} stc_atim3mode0_ifr_field_t;

typedef struct
{
    __IO uint32_t UI                        : 1;
    uint32_t RESERVED1                      :30;
    __IO uint32_t RSV                       : 1;
} stc_atim3mode0_iclr_field_t;

typedef struct
{
    uint32_t RESERVED0                      :12;
    __IO uint32_t MO                        : 1;
    uint32_t RESERVED13                     :18;
    __IO uint32_t RSV                       : 1;
} stc_atim3mode0_dtr_field_t;

typedef struct
{
    __IO uint32_t CNT                       :16;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_atim3mode1_cnt_field_t;

typedef struct
{
    __IO uint32_t CEN                       : 1;
    uint32_t RESERVED1                      : 1;
    __IO uint32_t CT                        : 1;
    uint32_t RESERVED3                      : 1;
    __IO uint32_t PRS                       : 3;
    uint32_t RESERVED7                      : 1;
    __IO uint32_t EDG1ST                    : 1;
    __IO uint32_t EDG2ND                    : 1;
    __IO uint32_t UI                        : 1;
    uint32_t RESERVED11                     : 1;
    __IO uint32_t MODE                      : 2;
    __IO uint32_t ONESHOT                   : 1;
    uint32_t RESERVED15                     :16;
    __IO uint32_t RSV                       : 1;
} stc_atim3mode1_m1cr_field_t;

typedef struct
{
    __IO uint32_t UI                        : 1;
    uint32_t RESERVED1                      : 1;
    __IO uint32_t PWC                       : 1;
    uint32_t RESERVED3                      :28;
    __IO uint32_t RSV                       : 1;
} stc_atim3mode1_ifr_field_t;

typedef struct
{
    __IO uint32_t UI                        : 1;
    uint32_t RESERVED1                      : 1;
    __IO uint32_t CA0                       : 1;
    uint32_t RESERVED3                      :28;
    __IO uint32_t RSV                       : 1;
} stc_atim3mode1_iclr_field_t;

typedef struct
{
    uint32_t RESERVED0                      : 5;
    __IO uint32_t TS                        : 3;
    uint32_t RESERVED8                      : 3;
    __IO uint32_t IA0S                      : 1;
    __IO uint32_t IB0S                      : 1;
    uint32_t RESERVED13                     :18;
    __IO uint32_t RSV                       : 1;
} stc_atim3mode1_mscr_field_t;

typedef struct
{
    __IO uint32_t FLTA0                     : 3;
    uint32_t RESERVED3                      : 1;
    __IO uint32_t FLTB0                     : 3;
    uint32_t RESERVED7                      :21;
    __IO uint32_t FLTET                     : 3;
    __IO uint32_t ETP                       : 1;
} stc_atim3mode1_fltr_field_t;

typedef struct
{
    uint32_t RESERVED0                      : 8;
    __IO uint32_t CIEA                      : 1;
    uint32_t RESERVED9                      :22;
    __IO uint32_t RSV                       : 1;
} stc_atim3mode1_cr0_field_t;

typedef struct
{
    __IO uint32_t CCR0A                     :16;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_atim3mode1_ccr0a_field_t;

typedef struct
{
    __IO uint32_t ARR                       :16;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_atim3mode23_arr_field_t;

typedef struct
{
    __IO uint32_t CNT                       :16;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_atim3mode23_cnt_field_t;

typedef struct
{
    __IO uint32_t CTEN                      : 1;
    __IO uint32_t COMP                      : 1;
    __IO uint32_t CT                        : 1;
    __IO uint32_t PWM2S                     : 1;
    __IO uint32_t PRS                       : 3;
    __IO uint32_t BUFP                      : 1;
    __IO uint32_t CRG                       : 1;
    __IO uint32_t CFG                       : 1;
    __IO uint32_t UI                        : 1;
    __IO uint32_t UD                        : 1;
    __IO uint32_t MODE                      : 2;
    __IO uint32_t ONESHOT                   : 1;
    __IO uint32_t CSG                       : 1;
    __IO uint32_t OCCS                      : 1;
    __IO uint32_t URS                       : 1;
    __IO uint32_t TD                        : 1;
    __IO uint32_t TI                        : 1;
    __IO uint32_t BI                        : 1;
    __IO uint32_t CIS                       : 2;
    __IO uint32_t OCC                       : 1;
    __IO uint32_t TG                        : 1;
    __IO uint32_t UG                        : 1;
    __IO uint32_t BG                        : 1;
    __IO uint32_t DIR                       : 1;
    __IO uint32_t OV                        : 1;
    __IO uint32_t UND                       : 1;
    uint32_t RESERVED30                     : 1;
    __IO uint32_t RSV                       : 1;
} stc_atim3mode23_m23cr_field_t;

typedef struct
{
    __IO uint32_t UI                        : 1;
    uint32_t RESERVED1                      : 1;
    __IO uint32_t CA0                       : 1;
    __IO uint32_t CA1                       : 1;
    __IO uint32_t CA2                       : 1;
    __IO uint32_t CB0                       : 1;
    __IO uint32_t CB1                       : 1;
    __IO uint32_t CB2                       : 1;
    __IO uint32_t CA0E                      : 1;
    __IO uint32_t CA1E                      : 1;
    __IO uint32_t CA2E                      : 1;
    __IO uint32_t CB0E                      : 1;
    __IO uint32_t CB1E                      : 1;
    __IO uint32_t CB2E                      : 1;
    __IO uint32_t BI                        : 1;
    __IO uint32_t TI                        : 1;
    __IO uint32_t OV                        : 1;
    __IO uint32_t UND                       : 1;
    __IO uint32_t CA3                       : 1;
    uint32_t RESERVED19                     :12;
    __IO uint32_t RSV                       : 1;
} stc_atim3mode23_ifr_field_t;

typedef struct
{
    __IO uint32_t UI                        : 1;
    uint32_t RESERVED1                      : 1;
    __IO uint32_t CA0                       : 1;
    __IO uint32_t CA1                       : 1;
    __IO uint32_t CA2                       : 1;
    __IO uint32_t CB0                       : 1;
    __IO uint32_t CB1                       : 1;
    __IO uint32_t CB2                       : 1;
    __IO uint32_t CA0E                      : 1;
    __IO uint32_t CA1E                      : 1;
    __IO uint32_t CA2E                      : 1;
    __IO uint32_t CB0E                      : 1;
    __IO uint32_t CB1E                      : 1;
    __IO uint32_t CB2E                      : 1;
    __IO uint32_t BI                        : 1;
    __IO uint32_t TI                        : 1;
    __IO uint32_t OV                        : 1;
    __IO uint32_t UND                       : 1;
    __IO uint32_t CA3                       : 1;
    uint32_t RESERVED19                     :12;
    __IO uint32_t RSV                       : 1;
} stc_atim3mode23_iclr_field_t;

typedef struct
{
    __IO uint32_t MMS                       : 3;
    __IO uint32_t CCDS                      : 1;
    __IO uint32_t MSM                       : 1;
    __IO uint32_t TS                        : 3;
    __IO uint32_t SMS                       : 3;
    __IO uint32_t IA0S                      : 1;
    __IO uint32_t IB0S                      : 1;
    uint32_t RESERVED13                     :18;
    __IO uint32_t RSV                       : 1;
} stc_atim3mode23_mscr_field_t;

typedef struct
{
    __IO uint32_t OCMA0FLTA0                : 3;
    __IO uint32_t CCPA0                     : 1;
    __IO uint32_t OCMB0FLTB0                : 3;
    __IO uint32_t CCPB0                     : 1;
    __IO uint32_t OCMA1FLTA1                : 3;
    __IO uint32_t CCPA1                     : 1;
    __IO uint32_t OCMB1FLTB1                : 3;
    __IO uint32_t CCPB1                     : 1;
    __IO uint32_t OCMA2FLTA2                : 3;
    __IO uint32_t CCPA2                     : 1;
    __IO uint32_t OCMB2FLTB2                : 3;
    __IO uint32_t CCPB2                     : 1;
    __IO uint32_t FLTBK                     : 3;
    __IO uint32_t BKP                       : 1;
    __IO uint32_t FLTET                     : 3;
    __IO uint32_t ETP                       : 1;
} stc_atim3mode23_fltr_field_t;

typedef struct
{
    __IO uint32_t UEV                       : 1;
    __IO uint32_t CMA0                      : 1;
    __IO uint32_t CMA1                      : 1;
    __IO uint32_t CMA2                      : 1;
    __IO uint32_t CMB0                      : 1;
    __IO uint32_t CMB1                      : 1;
    __IO uint32_t CMB2                      : 1;
    __IO uint32_t ADT                       : 1;
    uint32_t RESERVED8                      :23;
    __IO uint32_t RSV                       : 1;
} stc_atim3mode23_adtr_field_t;

typedef struct
{
    __IO uint32_t BKSACFACRA                : 2;
    __IO uint32_t BKSBCFBCRB                : 2;
    __IO uint32_t CSA                       : 1;
    __IO uint32_t CSB                       : 1;
    __IO uint32_t BUFEA                     : 1;
    __IO uint32_t BUFEB                     : 1;
    __IO uint32_t CIEA                      : 1;
    __IO uint32_t CIEB                      : 1;
    __IO uint32_t CDEA                      : 1;
    __IO uint32_t CDEB                      : 1;
    __IO uint32_t CISB                      : 2;
    __IO uint32_t CCGA                      : 1;
    __IO uint32_t CCGB                      : 1;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_atim3mode23_crch0_field_t;

typedef struct
{
    __IO uint32_t BKSACFACRA                : 2;
    __IO uint32_t BKSBCFBCRB                : 2;
    __IO uint32_t CSA                       : 1;
    __IO uint32_t CSB                       : 1;
    __IO uint32_t BUFEA                     : 1;
    __IO uint32_t BUFEB                     : 1;
    __IO uint32_t CIEA                      : 1;
    __IO uint32_t CIEB                      : 1;
    __IO uint32_t CDEA                      : 1;
    __IO uint32_t CDEB                      : 1;
    __IO uint32_t CISB                      : 2;
    __IO uint32_t CCGA                      : 1;
    __IO uint32_t CCGB                      : 1;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_atim3mode23_crch1_field_t;

typedef struct
{
    __IO uint32_t BKSACFACRA                : 2;
    __IO uint32_t BKSBCFBCRB                : 2;
    __IO uint32_t CSA                       : 1;
    __IO uint32_t CSB                       : 1;
    __IO uint32_t BUFEA                     : 1;
    __IO uint32_t BUFEB                     : 1;
    __IO uint32_t CIEA                      : 1;
    __IO uint32_t CIEB                      : 1;
    __IO uint32_t CDEA                      : 1;
    __IO uint32_t CDEB                      : 1;
    __IO uint32_t CISB                      : 2;
    __IO uint32_t CCGA                      : 1;
    __IO uint32_t CCGB                      : 1;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_atim3mode23_crch2_field_t;

typedef struct
{
    __IO uint32_t DTR                       : 8;
    __IO uint32_t BKSEL                     : 1;
    __IO uint32_t DT                        : 1;
    __IO uint32_t BK                        : 1;
    __IO uint32_t AO                        : 1;
    __IO uint32_t MO                        : 1;
    __IO uint32_t SAFE                      : 1;
    __IO uint32_t VC                        : 1;
    uint32_t RESERVED15                     :16;
    __IO uint32_t RSV                       : 1;
} stc_atim3mode23_dtr_field_t;

typedef struct
{
    __IO uint32_t RCR                       : 8;
    __IO uint32_t OV                        : 1;
    __IO uint32_t UD                        : 1;
    uint32_t RESERVED10                     :21;
    __IO uint32_t RSV                       : 1;
} stc_atim3mode23_rcr_field_t;

typedef struct
{
    __IO uint32_t CCR0A                     :16;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_atim3mode23_ccr0a_field_t;

typedef struct
{
    __IO uint32_t CCR0B                     :16;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_atim3mode23_ccr0b_field_t;

typedef struct
{
    __IO uint32_t CCR1A                     :16;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_atim3mode23_ccr1a_field_t;

typedef struct
{
    __IO uint32_t CCR1B                     :16;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_atim3mode23_ccr1b_field_t;

typedef struct
{
    __IO uint32_t CCR2A                     :16;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_atim3mode23_ccr2a_field_t;

typedef struct
{
    __IO uint32_t CCR2B                     :16;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_atim3mode23_ccr2b_field_t;

typedef struct
{
    __IO uint32_t CCR3                      :16;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_atim3mode23_ccr3_field_t;

typedef struct
{
    __IO uint32_t BUF                       : 1;
    __IO uint32_t CI                        : 1;
    __IO uint32_t CD                        : 1;
    __IO uint32_t CIS                       : 2;
    __IO uint32_t C3                        : 1;
    uint32_t RESERVED6                      :25;
    __IO uint32_t RSV                       : 1;
} stc_atim3mode23_crch3_field_t;

typedef struct
{
    __IO uint32_t ARR                       :16;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_btim_arr_field_t;

typedef struct
{
    __IO uint32_t CNT                       :16;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_btim_cnt_field_t;

typedef struct
{
    __IO uint32_t CEN                       : 1;
    __IO uint32_t MD                        : 2;
    __IO uint32_t TOGEN                     : 1;
    __IO uint32_t PRS                       : 4;
    __IO uint32_t OST                       : 1;
    __IO uint32_t TRS                       : 2;
    __IO uint32_t ETP                       : 1;
    uint32_t RESERVED12                     :19;
    __IO uint32_t RSV                       : 1;
} stc_btim_cr_field_t;

typedef struct
{
    __IO uint32_t UI                        : 1;
    __IO uint32_t TI                        : 1;
    uint32_t RESERVED2                      :29;
    __IO uint32_t RSV                       : 1;
} stc_btim_ier_field_t;

typedef struct
{
    __IO uint32_t UI                        : 1;
    __IO uint32_t TI                        : 1;
    uint32_t RESERVED2                      :29;
    __IO uint32_t RSV                       : 1;
} stc_btim_ifr_field_t;

typedef struct
{
    __IO uint32_t UI                        : 1;
    __IO uint32_t TI                        : 1;
    uint32_t RESERVED2                      :29;
    __IO uint32_t RSV                       : 1;
} stc_btim_icr_field_t;

typedef struct
{
    __IO uint32_t UI3                       : 1;
    __IO uint32_t TI3                       : 1;
    __IO uint32_t UI4                       : 1;
    __IO uint32_t TI4                       : 1;
    __IO uint32_t UI5                       : 1;
    __IO uint32_t TI5                       : 1;
    uint32_t RESERVED6                      :25;
    __IO uint32_t RSV                       : 1;
} stc_btim_aifr_field_t;

typedef struct
{
    __IO uint32_t UI3                       : 1;
    __IO uint32_t TI3                       : 1;
    __IO uint32_t UI4                       : 1;
    __IO uint32_t TI4                       : 1;
    __IO uint32_t UI5                       : 1;
    __IO uint32_t TI5                       : 1;
    uint32_t RESERVED6                      :25;
    __IO uint32_t RSV                       : 1;
} stc_btim_aicr_field_t;

typedef struct
{
    __IO uint32_t ARR                       :16;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_ctrim_arr_field_t;

typedef struct
{
    __IO uint32_t CNT                       :16;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_ctrim_cnt_field_t;

typedef struct
{
    __IO uint32_t STEP                      : 3;
    uint32_t RESERVED3                      : 1;
    __IO uint32_t ETRFLT                    : 3;
    uint32_t RESERVED7                      : 1;
    __IO uint32_t SRC                       : 3;
    uint32_t RESERVED11                     :20;
    __IO uint32_t RSV                       : 1;
} stc_ctrim_cr0_field_t;

typedef struct
{
    __IO uint32_t EN                        : 1;
    __IO uint32_t MD                        : 2;
    __IO uint32_t AUTO                      : 1;
    __IO uint32_t PRS                       : 4;
    __IO uint32_t OST                       : 1;
    uint32_t RESERVED9                      :22;
    __IO uint32_t RSV                       : 1;
} stc_ctrim_cr1_field_t;

typedef struct
{
    __IO uint32_t UD                        : 1;
    __IO uint32_t END                       : 1;
    __IO uint32_t PS                        : 1;
    __IO uint32_t MISS                      : 1;
    __IO uint32_t OV                        : 1;
    uint32_t RESERVED5                      :26;
    __IO uint32_t RSV                       : 1;
} stc_ctrim_ier_field_t;

typedef struct
{
    __IO uint32_t UD                        : 1;
    __IO uint32_t END                       : 1;
    __IO uint32_t PS                        : 1;
    __IO uint32_t MISS                      : 1;
    __IO uint32_t OV                        : 1;
    __IO uint32_t DIR                       : 1;
    __IO uint32_t OK                        : 1;
    uint32_t RESERVED7                      :24;
    __IO uint32_t RSV                       : 1;
} stc_ctrim_isr_field_t;

typedef struct
{
    __IO uint32_t UD                        : 1;
    __IO uint32_t END                       : 1;
    __IO uint32_t PS                        : 1;
    __IO uint32_t MISS                      : 1;
    __IO uint32_t OV                        : 1;
    __IO uint32_t OK                        : 1;
    uint32_t RESERVED6                      :25;
    __IO uint32_t RSV                       : 1;
} stc_ctrim_icr_field_t;

typedef struct
{
    __IO uint32_t FCAP                      :16;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_ctrim_fcap_field_t;

typedef struct
{
    __IO uint32_t TVAL                      :16;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_ctrim_tval_field_t;

typedef struct
{
    __IO uint32_t FLIM                      : 8;
    uint32_t RESERVED8                      :23;
    __IO uint32_t RSV                       : 1;
} stc_ctrim_flim_field_t;

typedef struct
{
    __IO uint32_t OP                        : 2;
    uint32_t RESERVED2                      : 2;
    __IO uint32_t BUSY                      : 1;
    __IO uint32_t PCIE                      : 1;
    __IO uint32_t FLASHIE                   : 1;
    uint32_t RESERVED7                      : 2;
    __IO uint32_t LPMODE                    : 1;
    uint32_t RESERVED10                     :21;
    __IO uint32_t RSV                       : 1;
} stc_flash_cr_field_t;

typedef struct
{
    __IO uint32_t PC                        : 1;
    __IO uint32_t FLASH                     : 1;
    uint32_t RESERVED2                      :29;
    __IO uint32_t RSV                       : 1;
} stc_flash_ifr_field_t;

typedef struct
{
    __IO uint32_t PC                        : 1;
    __IO uint32_t FLASH                     : 1;
    uint32_t RESERVED2                      :29;
    __IO uint32_t RSV                       : 1;
} stc_flash_iclr_field_t;

typedef struct
{
    __IO uint32_t BYPASS                    :16;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_flash_bypass_field_t;

typedef struct
{
    __IO uint32_t SLOCK                     : 9;
    uint32_t RESERVED9                      :22;
    __IO uint32_t RSV                       : 1;
} stc_flash_slock_field_t;

typedef struct
{
    __IO uint32_t WAIT                      : 2;
    uint32_t RESERVED2                      :29;
    __IO uint32_t RSV                       : 1;
} stc_flash_wait_field_t;

typedef struct
{
    __IO uint32_t STATE                     : 2;
    uint32_t RESERVED2                      :29;
    __IO uint32_t RSV                       : 1;
} stc_flash_lockstate_field_t;

typedef struct
{
    __IO uint32_t PIN0                      : 1;
    __IO uint32_t PIN1                      : 1;
    __IO uint32_t PIN2                      : 1;
    __IO uint32_t PIN3                      : 1;
    __IO uint32_t PIN4                      : 1;
    __IO uint32_t PIN5                      : 1;
    __IO uint32_t PIN6                      : 1;
    __IO uint32_t PIN7                      : 1;
    uint32_t RESERVED8                      :23;
    __IO uint32_t RSV                       : 1;
} stc_gpio_ads_field_t;

typedef struct
{
    __IO uint32_t PIN0                      : 1;
    __IO uint32_t PIN1                      : 1;
    __IO uint32_t PIN2                      : 1;
    __IO uint32_t PIN3                      : 1;
    __IO uint32_t PIN4                      : 1;
    __IO uint32_t PIN5                      : 1;
    __IO uint32_t PIN6                      : 1;
    __IO uint32_t PIN7                      : 1;
    uint32_t RESERVED8                      :23;
    __IO uint32_t RSV                       : 1;
} stc_gpio_dir_field_t;

typedef struct
{
    __IO uint32_t PIN0                      : 1;
    __IO uint32_t PIN1                      : 1;
    __IO uint32_t PIN2                      : 1;
    __IO uint32_t PIN3                      : 1;
    __IO uint32_t PIN4                      : 1;
    __IO uint32_t PIN5                      : 1;
    __IO uint32_t PIN6                      : 1;
    __IO uint32_t PIN7                      : 1;
    uint32_t RESERVED8                      :23;
    __IO uint32_t RSV                       : 1;
} stc_gpio_opendrain_field_t;

typedef struct
{
    __IO uint32_t PIN0                      : 1;
    __IO uint32_t PIN1                      : 1;
    __IO uint32_t PIN2                      : 1;
    __IO uint32_t PIN3                      : 1;
    __IO uint32_t PIN4                      : 1;
    __IO uint32_t PIN5                      : 1;
    __IO uint32_t PIN6                      : 1;
    __IO uint32_t PIN7                      : 1;
    uint32_t RESERVED8                      :23;
    __IO uint32_t RSV                       : 1;
} stc_gpio_pu_field_t;

typedef struct
{
    __IO uint32_t PIN0                      : 1;
    __IO uint32_t PIN1                      : 1;
    __IO uint32_t PIN2                      : 1;
    __IO uint32_t PIN3                      : 1;
    __IO uint32_t PIN4                      : 1;
    __IO uint32_t PIN5                      : 1;
    __IO uint32_t PIN6                      : 1;
    __IO uint32_t PIN7                      : 1;
    uint32_t RESERVED8                      :23;
    __IO uint32_t RSV                       : 1;
} stc_gpio_in_field_t;

typedef struct
{
    __IO uint32_t PIN0                      : 1;
    __IO uint32_t PIN1                      : 1;
    __IO uint32_t PIN2                      : 1;
    __IO uint32_t PIN3                      : 1;
    __IO uint32_t PIN4                      : 1;
    __IO uint32_t PIN5                      : 1;
    __IO uint32_t PIN6                      : 1;
    __IO uint32_t PIN7                      : 1;
    uint32_t RESERVED8                      :23;
    __IO uint32_t RSV                       : 1;
} stc_gpio_out_field_t;

typedef struct
{
    __IO uint32_t PIN0                      : 1;
    __IO uint32_t PIN1                      : 1;
    __IO uint32_t PIN2                      : 1;
    __IO uint32_t PIN3                      : 1;
    __IO uint32_t PIN4                      : 1;
    __IO uint32_t PIN5                      : 1;
    __IO uint32_t PIN6                      : 1;
    __IO uint32_t PIN7                      : 1;
    uint32_t RESERVED8                      :23;
    __IO uint32_t RSV                       : 1;
} stc_gpio_brr_field_t;

typedef struct
{
    __IO uint32_t BSPIN0                    : 1;
    __IO uint32_t BSPIN1                    : 1;
    __IO uint32_t BSPIN2                    : 1;
    __IO uint32_t BSPIN3                    : 1;
    __IO uint32_t BSPIN4                    : 1;
    __IO uint32_t BSPIN5                    : 1;
    __IO uint32_t BSPIN6                    : 1;
    __IO uint32_t BSPIN7                    : 1;
    uint32_t RESERVED8                      : 8;
    __IO uint32_t BRPIN0                    : 1;
    __IO uint32_t BRPIN1                    : 1;
    __IO uint32_t BRPIN2                    : 1;
    __IO uint32_t BRPIN3                    : 1;
    __IO uint32_t BRPIN4                    : 1;
    __IO uint32_t BRPIN5                    : 1;
    __IO uint32_t BRPIN6                    : 1;
    __IO uint32_t BRPIN7                    : 1;
    uint32_t RESERVED24                     : 7;
    __IO uint32_t RSV                       : 1;
} stc_gpio_bsrr_field_t;

typedef struct
{
    __IO uint32_t AFSEL0                    : 4;
    __IO uint32_t AFSEL1                    : 4;
    __IO uint32_t AFSEL2                    : 4;
    __IO uint32_t AFSEL3                    : 4;
    __IO uint32_t AFSEL4                    : 4;
    __IO uint32_t AFSEL5                    : 4;
    __IO uint32_t AFSEL6                    : 4;
    __IO uint32_t AFSEL7                    : 4;
} stc_gpio_afrl_field_t;

typedef struct
{
    __IO uint32_t PIN0                      : 1;
    __IO uint32_t PIN1                      : 1;
    __IO uint32_t PIN2                      : 1;
    __IO uint32_t PIN3                      : 1;
    __IO uint32_t PIN4                      : 1;
    __IO uint32_t PIN5                      : 1;
    __IO uint32_t PIN6                      : 1;
    __IO uint32_t PIN7                      : 1;
    uint32_t RESERVED8                      :23;
    __IO uint32_t RSV                       : 1;
} stc_gpio_highie_field_t;

typedef struct
{
    __IO uint32_t PIN0                      : 1;
    __IO uint32_t PIN1                      : 1;
    __IO uint32_t PIN2                      : 1;
    __IO uint32_t PIN3                      : 1;
    __IO uint32_t PIN4                      : 1;
    __IO uint32_t PIN5                      : 1;
    __IO uint32_t PIN6                      : 1;
    __IO uint32_t PIN7                      : 1;
    uint32_t RESERVED8                      :23;
    __IO uint32_t RSV                       : 1;
} stc_gpio_lowie_field_t;

typedef struct
{
    __IO uint32_t PIN0                      : 1;
    __IO uint32_t PIN1                      : 1;
    __IO uint32_t PIN2                      : 1;
    __IO uint32_t PIN3                      : 1;
    __IO uint32_t PIN4                      : 1;
    __IO uint32_t PIN5                      : 1;
    __IO uint32_t PIN6                      : 1;
    __IO uint32_t PIN7                      : 1;
    uint32_t RESERVED8                      :23;
    __IO uint32_t RSV                       : 1;
} stc_gpio_riseie_field_t;

typedef struct
{
    __IO uint32_t PIN0                      : 1;
    __IO uint32_t PIN1                      : 1;
    __IO uint32_t PIN2                      : 1;
    __IO uint32_t PIN3                      : 1;
    __IO uint32_t PIN4                      : 1;
    __IO uint32_t PIN5                      : 1;
    __IO uint32_t PIN6                      : 1;
    __IO uint32_t PIN7                      : 1;
    uint32_t RESERVED8                      :23;
    __IO uint32_t RSV                       : 1;
} stc_gpio_fallie_field_t;

typedef struct
{
    __IO uint32_t PIN0                      : 1;
    __IO uint32_t PIN1                      : 1;
    __IO uint32_t PIN2                      : 1;
    __IO uint32_t PIN3                      : 1;
    __IO uint32_t PIN4                      : 1;
    __IO uint32_t PIN5                      : 1;
    __IO uint32_t PIN6                      : 1;
    __IO uint32_t PIN7                      : 1;
    uint32_t RESERVED8                      :23;
    __IO uint32_t RSV                       : 1;
} stc_gpio_ifr_field_t;

typedef struct
{
    __IO uint32_t PIN0                      : 1;
    __IO uint32_t PIN1                      : 1;
    __IO uint32_t PIN2                      : 1;
    __IO uint32_t PIN3                      : 1;
    __IO uint32_t PIN4                      : 1;
    __IO uint32_t PIN5                      : 1;
    __IO uint32_t PIN6                      : 1;
    __IO uint32_t PIN7                      : 1;
    uint32_t RESERVED8                      :23;
    __IO uint32_t RSV                       : 1;
} stc_gpio_icr_field_t;

typedef struct
{
    __IO uint32_t TCLKSRC                   : 2;
    uint32_t RESERVED2                      : 1;
    __IO uint32_t TCLKDIV                   : 2;
    uint32_t RESERVED5                      :26;
    __IO uint32_t RSV                       : 1;
} stc_gpioaux_cr1_field_t;

typedef struct
{
    uint32_t RESERVED0                      : 4;
    __IO uint32_t ATIM3CH0A                 : 2;
    uint32_t RESERVED6                      : 2;
    __IO uint32_t GTIMCH1                   : 2;
    uint32_t RESERVED10                     :21;
    __IO uint32_t RSV                       : 1;
} stc_gpioaux_cr4_field_t;

typedef struct
{
    __IO uint32_t ARR                       :16;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_gtim_arr_field_t;

typedef struct
{
    __IO uint32_t CNT                       :16;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_gtim_cnt_field_t;

typedef struct
{
    __IO uint32_t CC0M                      : 3;
    uint32_t RESERVED3                      : 1;
    __IO uint32_t CC1M                      : 3;
    uint32_t RESERVED7                      : 1;
    __IO uint32_t CC2M                      : 3;
    uint32_t RESERVED11                     : 1;
    __IO uint32_t CC3M                      : 3;
    uint32_t RESERVED15                     :16;
    __IO uint32_t RSV                       : 1;
} stc_gtim_cmmr_field_t;

typedef struct
{
    uint32_t RESERVED0                      : 4;
    __IO uint32_t ETRFLT                    : 3;
    uint32_t RESERVED7                      :24;
    __IO uint32_t RSV                       : 1;
} stc_gtim_cr1_field_t;

typedef struct
{
    __IO uint32_t CEN                       : 1;
    __IO uint32_t MD                        : 2;
    __IO uint32_t TOGEN                     : 1;
    __IO uint32_t PRS                       : 4;
    __IO uint32_t OST                       : 1;
    __IO uint32_t TRS                       : 2;
    __IO uint32_t ETP                       : 1;
    uint32_t RESERVED12                     :19;
    __IO uint32_t RSV                       : 1;
} stc_gtim_cr0_field_t;

typedef struct
{
    __IO uint32_t UI                        : 1;
    __IO uint32_t TI                        : 1;
    __IO uint32_t CC0                       : 1;
    __IO uint32_t CC1                       : 1;
    __IO uint32_t CC2                       : 1;
    __IO uint32_t CC3                       : 1;
    uint32_t RESERVED6                      :25;
    __IO uint32_t RSV                       : 1;
} stc_gtim_ier_field_t;

typedef struct
{
    __IO uint32_t UI                        : 1;
    __IO uint32_t TI                        : 1;
    __IO uint32_t CC0                       : 1;
    __IO uint32_t CC1                       : 1;
    __IO uint32_t CC2                       : 1;
    __IO uint32_t CC3                       : 1;
    uint32_t RESERVED6                      :25;
    __IO uint32_t RSV                       : 1;
} stc_gtim_ifr_field_t;

typedef struct
{
    __IO uint32_t UI                        : 1;
    __IO uint32_t TI                        : 1;
    __IO uint32_t CC0                       : 1;
    __IO uint32_t CC1                       : 1;
    __IO uint32_t CC2                       : 1;
    __IO uint32_t CC3                       : 1;
    uint32_t RESERVED6                      :25;
    __IO uint32_t RSV                       : 1;
} stc_gtim_icr_field_t;

typedef struct
{
    __IO uint32_t CCR                       :16;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_gtim_ccr0_field_t;

typedef struct
{
    __IO uint32_t CCR                       :16;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_gtim_ccr1_field_t;

typedef struct
{
    __IO uint32_t CCR                       :16;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_gtim_ccr2_field_t;

typedef struct
{
    __IO uint32_t CCR                       :16;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_gtim_ccr3_field_t;

typedef struct
{
    __IO uint32_t EN                        : 1;
    uint32_t RESERVED1                      :30;
    __IO uint32_t RSV                       : 1;
} stc_i2c_brren_field_t;

typedef struct
{
    __IO uint32_t BRR                       : 8;
    uint32_t RESERVED8                      :23;
    __IO uint32_t RSV                       : 1;
} stc_i2c_brr_field_t;

typedef struct
{
    __IO uint32_t FLT                       : 1;
    uint32_t RESERVED1                      : 1;
    __IO uint32_t AA                        : 1;
    __IO uint32_t SI                        : 1;
    __IO uint32_t STO                       : 1;
    __IO uint32_t STA                       : 1;
    __IO uint32_t EN                        : 1;
    uint32_t RESERVED7                      :24;
    __IO uint32_t RSV                       : 1;
} stc_i2c_cr_field_t;

typedef struct
{
    __IO uint32_t DR                        : 8;
    uint32_t RESERVED8                      :23;
    __IO uint32_t RSV                       : 1;
} stc_i2c_dr_field_t;

typedef struct
{
    __IO uint32_t GC                        : 1;
    __IO uint32_t ADDR0                     : 7;
    uint32_t RESERVED8                      :23;
    __IO uint32_t RSV                       : 1;
} stc_i2c_addr0_field_t;

typedef struct
{
    __IO uint32_t STAT                      : 8;
    uint32_t RESERVED8                      :23;
    __IO uint32_t RSV                       : 1;
} stc_i2c_stat_field_t;

typedef struct
{
    uint32_t RESERVED0                      : 1;
    __IO uint32_t ADDR                      : 7;
    uint32_t RESERVED8                      :23;
    __IO uint32_t RSV                       : 1;
} stc_i2c_addr1_field_t;

typedef struct
{
    uint32_t RESERVED0                      : 1;
    __IO uint32_t ADDR                      : 7;
    uint32_t RESERVED8                      :23;
    __IO uint32_t RSV                       : 1;
} stc_i2c_addr2_field_t;

typedef struct
{
    __IO uint32_t AD0F                      : 1;
    __IO uint32_t AD1F                      : 1;
    __IO uint32_t AD2F                      : 1;
    uint32_t RESERVED3                      :28;
    __IO uint32_t RSV                       : 1;
} stc_i2c_match_field_t;

typedef struct
{
    __IO uint32_t KR                        :16;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_iwdt_kr_field_t;

typedef struct
{
    __IO uint32_t PRS                       : 4;
    __IO uint32_t IE                        : 1;
    __IO uint32_t ACTION                    : 1;
    __IO uint32_t PAUSE                     : 1;
    uint32_t RESERVED7                      :24;
    __IO uint32_t RSV                       : 1;
} stc_iwdt_cr_field_t;

typedef struct
{
    __IO uint32_t ARR                       :12;
    uint32_t RESERVED12                     :19;
    __IO uint32_t RSV                       : 1;
} stc_iwdt_arr_field_t;

typedef struct
{
    __IO uint32_t PRSF                      : 1;
    __IO uint32_t ARRF                      : 1;
    __IO uint32_t WINRF                     : 1;
    __IO uint32_t OV                        : 1;
    __IO uint32_t RUN                       : 1;
    uint32_t RESERVED5                      :26;
    __IO uint32_t RSV                       : 1;
} stc_iwdt_sr_field_t;

typedef struct
{
    __IO uint32_t WINR                      :12;
    uint32_t RESERVED12                     :19;
    __IO uint32_t RSV                       : 1;
} stc_iwdt_winr_field_t;

typedef struct
{
    __IO uint32_t DR                        : 8;
    __IO uint32_t DR8                       : 1;
    uint32_t RESERVED9                      :22;
    __IO uint32_t RSV                       : 1;
} stc_lpuart_dr_field_t;

typedef struct
{
    __IO uint32_t RCIE                      : 1;
    __IO uint32_t TCIE                      : 1;
    __IO uint32_t DR8CFG                    : 2;
    __IO uint32_t RXEN                      : 1;
    __IO uint32_t ADRDET                    : 1;
    __IO uint32_t MODE                      : 2;
    __IO uint32_t TXEIE                     : 1;
    __IO uint32_t OVER                      : 2;
    __IO uint32_t CLKSRC                    : 2;
    __IO uint32_t PEIE                      : 1;
    __IO uint32_t STOP                      : 2;
    uint32_t RESERVED16                     : 2;
    __IO uint32_t RTSEN                     : 1;
    __IO uint32_t CTSEN                     : 1;
    __IO uint32_t CTSIE                     : 1;
    __IO uint32_t FEIE                      : 1;
    __IO uint32_t HDSEL                     : 1;
    uint32_t RESERVED23                     : 8;
    __IO uint32_t RSV                       : 1;
} stc_lpuart_cr_field_t;

typedef struct
{
    __IO uint32_t ADDR                      : 8;
    uint32_t RESERVED8                      :23;
    __IO uint32_t RSV                       : 1;
} stc_lpuart_addr_field_t;

typedef struct
{
    __IO uint32_t MASK                      : 8;
    uint32_t RESERVED8                      :23;
    __IO uint32_t RSV                       : 1;
} stc_lpuart_addrmask_field_t;

typedef struct
{
    __IO uint32_t RC                        : 1;
    __IO uint32_t TC                        : 1;
    __IO uint32_t FE                        : 1;
    __IO uint32_t TXE                       : 1;
    __IO uint32_t PE                        : 1;
    __IO uint32_t CTSIF                     : 1;
    __IO uint32_t CTS                       : 1;
    uint32_t RESERVED7                      :24;
    __IO uint32_t RSV                       : 1;
} stc_lpuart_isr_field_t;

typedef struct
{
    __IO uint32_t RC                        : 1;
    __IO uint32_t TC                        : 1;
    __IO uint32_t FE                        : 1;
    uint32_t RESERVED3                      : 1;
    __IO uint32_t PE                        : 1;
    __IO uint32_t CTSIF                     : 1;
    uint32_t RESERVED6                      :25;
    __IO uint32_t RSV                       : 1;
} stc_lpuart_icr_field_t;

typedef struct
{
    __IO uint32_t SCNT                      :16;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_lpuart_brr_field_t;

typedef struct
{
    __IO uint32_t EN                        : 1;
    __IO uint32_t ACT                       : 1;
    __IO uint32_t SOURCE                    : 2;
    __IO uint32_t VTDS                      : 4;
    __IO uint32_t FLTEN                     : 1;
    __IO uint32_t FLTTIME                   : 3;
    __IO uint32_t FTEN                      : 1;
    __IO uint32_t RTEN                      : 1;
    __IO uint32_t HTEN                      : 1;
    __IO uint32_t IE                        : 1;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_lvd_cr_field_t;

typedef struct
{
    __IO uint32_t INTF                      : 1;
    __IO uint32_t FLTV                      : 1;
    uint32_t RESERVED2                      :29;
    __IO uint32_t RSV                       : 1;
} stc_lvd_sr_field_t;

typedef struct
{
    __IO uint32_t EN                        : 1;
    __IO uint32_t BRR                       : 3;
    __IO uint32_t CPHA                      : 1;
    __IO uint32_t CPOL                      : 1;
    __IO uint32_t MSTR                      : 1;
    __IO uint32_t LSBF                      : 1;
    __IO uint32_t WIDTH                     : 4;
    __IO uint32_t SSM                       : 1;
    __IO uint32_t CM                        : 2;
    uint32_t RESERVED15                     :16;
    __IO uint32_t RSV                       : 1;
} stc_spi_cr0_field_t;

typedef struct
{
    __IO uint32_t TXEIE                     : 1;
    __IO uint32_t RXNEIE                    : 1;
    __IO uint32_t SSFIE                     : 1;
    __IO uint32_t SSRIE                     : 1;
    __IO uint32_t UDFIE                     : 1;
    __IO uint32_t OVFIE                     : 1;
    __IO uint32_t SSERRIE                   : 1;
    __IO uint32_t MODFIE                    : 1;
    uint32_t RESERVED8                      :23;
    __IO uint32_t RSV                       : 1;
} stc_spi_cr1_field_t;

typedef struct
{
    __IO uint32_t HDOE                      : 1;
    uint32_t RESERVED1                      :30;
    __IO uint32_t RSV                       : 1;
} stc_spi_hdoe_field_t;

typedef struct
{
    __IO uint32_t SSI                       : 1;
    uint32_t RESERVED1                      :30;
    __IO uint32_t RSV                       : 1;
} stc_spi_ssi_field_t;

typedef struct
{
    __IO uint32_t TXE                       : 1;
    __IO uint32_t RXNE                      : 1;
    __IO uint32_t SSF                       : 1;
    __IO uint32_t SSR                       : 1;
    __IO uint32_t UDF                       : 1;
    __IO uint32_t OVF                       : 1;
    __IO uint32_t SSERR                     : 1;
    __IO uint32_t MODF                      : 1;
    __IO uint32_t BUSY                      : 1;
    __IO uint32_t SSLVL                     : 1;
    uint32_t RESERVED10                     :21;
    __IO uint32_t RSV                       : 1;
} stc_spi_sr_field_t;

typedef struct
{
    __IO uint32_t TXE                       : 1;
    __IO uint32_t RXNE                      : 1;
    __IO uint32_t SSF                       : 1;
    __IO uint32_t SSR                       : 1;
    __IO uint32_t UDF                       : 1;
    __IO uint32_t OVF                       : 1;
    __IO uint32_t SSERR                     : 1;
    __IO uint32_t MODF                      : 1;
    uint32_t RESERVED8                      :23;
    __IO uint32_t RSV                       : 1;
} stc_spi_icr_field_t;

typedef struct
{
    __IO uint32_t DR                        :16;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_spi_dr_field_t;

typedef struct
{
    __IO uint32_t CLKSRC                    : 3;
    __IO uint32_t HCLKPRS                   : 3;
    __IO uint32_t PCLKPRS                   : 2;
    uint32_t RESERVED8                      :23;
    __IO uint32_t RSV                       : 1;
} stc_sysctrl_cr0_field_t;

typedef struct
{
    __IO uint32_t SWDIO                     : 1;
    __IO uint32_t LOCKUP                    : 1;
    __IO uint32_t WAKEUPCLK                 : 1;
    __IO uint32_t RESIO                     : 1;
    uint32_t RESERVED4                      : 4;
    __IO uint32_t GTIMCFG                   : 1;
    uint32_t RESERVED9                      :22;
    __IO uint32_t RSV                       : 1;
} stc_sysctrl_cr1_field_t;

typedef struct
{
    __IO uint32_t RCHEN                     : 1;
    uint32_t RESERVED1                      : 1;
    __IO uint32_t RCLEN                     : 1;
    uint32_t RESERVED3                      : 2;
    __IO uint32_t EXTCLKEN                  : 1;
    uint32_t RESERVED6                      :25;
    __IO uint32_t RSV                       : 1;
} stc_sysctrl_cr2_field_t;

typedef struct
{
    __IO uint32_t CR3                       :16;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_sysctrl_cr3_field_t;

typedef struct
{
    __IO uint32_t TRIM                      : 9;
    __IO uint32_t DIV                       : 4;
    uint32_t RESERVED13                     : 2;
    __IO uint32_t STABLE                    : 1;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_sysctrl_rch_field_t;

typedef struct
{
    __IO uint32_t TRIM                      :10;
    __IO uint32_t WAITCYCLE                 : 2;
    uint32_t RESERVED12                     : 3;
    __IO uint32_t STABLE                    : 1;
    uint32_t RESERVED16                     :15;
    __IO uint32_t RSV                       : 1;
} stc_sysctrl_rcl_field_t;

typedef struct
{
    uint32_t RESERVED0                      : 2;
    __IO uint32_t LPUART0                   : 1;
    __IO uint32_t LPUART1                   : 1;
    __IO uint32_t I2C                       : 1;
    uint32_t RESERVED5                      : 1;
    __IO uint32_t SPI                       : 1;
    uint32_t RESERVED7                      : 4;
    __IO uint32_t ATIM3                     : 1;
    uint32_t RESERVED12                     : 3;
    __IO uint32_t IWDT                      : 1;
    __IO uint32_t ADC                       : 1;
    uint32_t RESERVED17                     : 4;
    __IO uint32_t CTRIM                     : 1;
    uint32_t RESERVED22                     : 9;
    __IO uint32_t FLASH                     : 1;
} stc_sysctrl_periclken0_field_t;

typedef struct
{
    __IO uint32_t PA                        : 1;
    __IO uint32_t PB                        : 1;
    __IO uint32_t PC                        : 1;
    __IO uint32_t PD                        : 1;
    uint32_t RESERVED4                      : 6;
    __IO uint32_t WWDT                      : 1;
    uint32_t RESERVED11                     : 3;
    __IO uint32_t GTIM                      : 1;
    uint32_t RESERVED15                     :16;
    __IO uint32_t RSV                       : 1;
} stc_sysctrl_periclken1_field_t;

typedef struct
{
    uint32_t RESERVED0                      : 2;
    __IO uint32_t LPUART0                   : 1;
    __IO uint32_t LPUART1                   : 1;
    __IO uint32_t I2C                       : 1;
    uint32_t RESERVED5                      : 1;
    __IO uint32_t SPI                       : 1;
    uint32_t RESERVED7                      : 4;
    __IO uint32_t ATIM3                     : 1;
    uint32_t RESERVED12                     : 4;
    __IO uint32_t ADC                       : 1;
    uint32_t RESERVED17                     : 4;
    __IO uint32_t CTRIM                     : 1;
    uint32_t RESERVED22                     : 9;
    __IO uint32_t RSV                       : 1;
} stc_sysctrl_perireset0_field_t;

typedef struct
{
    __IO uint32_t PA                        : 1;
    __IO uint32_t PB                        : 1;
    __IO uint32_t PC                        : 1;
    __IO uint32_t PD                        : 1;
    uint32_t RESERVED4                      : 6;
    __IO uint32_t WWDT                      : 1;
    uint32_t RESERVED11                     : 3;
    __IO uint32_t GTIM                      : 1;
    uint32_t RESERVED15                     :16;
    __IO uint32_t RSV                       : 1;
} stc_sysctrl_perireset1_field_t;

typedef struct
{
    __IO uint32_t VCC                       : 1;
    __IO uint32_t VCORE                     : 1;
    __IO uint32_t LVD                       : 1;
    __IO uint32_t IWDT                      : 1;
    __IO uint32_t WWDT                      : 1;
    __IO uint32_t LOCKUP                    : 1;
    __IO uint32_t SYSREQ                    : 1;
    __IO uint32_t RSTB                      : 1;
    uint32_t RESERVED8                      :23;
    __IO uint32_t RSV                       : 1;
} stc_sysctrl_resetflag_field_t;

typedef struct
{
    uint32_t RESERVED0                      : 7;
    __IO uint32_t CTRIM                     : 1;
    __IO uint32_t IWDT                      : 1;
    uint32_t RESERVED9                      : 2;
    __IO uint32_t ATIM3                     : 1;
    uint32_t RESERVED12                     : 2;
    __IO uint32_t GTIM                      : 1;
    uint32_t RESERVED15                     : 1;
    __IO uint32_t WWDT                      : 1;
    uint32_t RESERVED17                     :14;
    __IO uint32_t RSV                       : 1;
} stc_sysctrl_debugactive_field_t;

typedef struct
{
    __IO uint32_t WCNT                      : 7;
    __IO uint32_t EN                        : 1;
    uint32_t RESERVED8                      :23;
    __IO uint32_t RSV                       : 1;
} stc_wwdt_cr0_field_t;

typedef struct
{
    __IO uint32_t WINR                      : 7;
    uint32_t RESERVED7                      : 2;
    __IO uint32_t IE                        : 1;
    uint32_t RESERVED10                     : 1;
    __IO uint32_t PRS                       : 3;
    uint32_t RESERVED14                     :17;
    __IO uint32_t RSV                       : 1;
} stc_wwdt_cr1_field_t;

typedef struct
{
    __IO uint32_t POV                       : 1;
    uint32_t RESERVED1                      :30;
    __IO uint32_t RSV                       : 1;
} stc_wwdt_sr_field_t;


typedef struct
{
    uint8_t RESERVED0[4];
    union
    {
        __IO uint32_t CR0;
        stc_adc_cr0_field_t CR0_f;
    };
    union
    {
        __IO uint32_t CR1;
        stc_adc_cr1_field_t CR1_f;
    };
    uint8_t RESERVED2[148];
    union
    {
        __IO uint32_t RESULT;
        stc_adc_result_field_t RESULT_f;
    };
    uint8_t RESERVED3[12];
    union
    {
        __IO uint32_t IFR;
        stc_adc_ifr_field_t IFR_f;
    };
    union
    {
        __IO uint32_t IER;
        stc_adc_ier_field_t IER_f;
    };
    union
    {
        __IO uint32_t ICR;
        stc_adc_icr_field_t ICR_f;
    };
    union
    {
        __IO uint32_t EXTTRIGGER;
        stc_adc_exttrigger_field_t EXTTRIGGER_f;
    };
    union
    {
        __IO uint32_t START;
        stc_adc_start_field_t START_f;
    };
    uint8_t RESERVED8[8];
    union
    {
        __IO uint32_t ALLSTART;
        stc_adc_allstart_field_t ALLSTART_f;
    };
}ADC_TypeDef;

typedef struct
{
    union
    {
        __IO uint32_t ARR;
        stc_atim3mode0_arr_field_t ARR_f;
    };
    union
    {
        __IO uint32_t CNT;
        stc_atim3mode0_cnt_field_t CNT_f;
    };
    union
    {
        __IO uint32_t CNT32;
        stc_atim3mode0_cnt32_field_t CNT32_f;
    };
    union
    {
        __IO uint32_t M0CR;
        stc_atim3mode0_m0cr_field_t M0CR_f;
    };
    union
    {
        __IO uint32_t IFR;
        stc_atim3mode0_ifr_field_t IFR_f;
    };
    union
    {
        __IO uint32_t ICLR;
        stc_atim3mode0_iclr_field_t ICLR_f;
    };
    uint8_t RESERVED6[24];
    union
    {
        __IO uint32_t DTR;
        stc_atim3mode0_dtr_field_t DTR_f;
    };
}ATIM3MODE0_TypeDef;

typedef struct
{
    uint8_t RESERVED0[4];
    union
    {
        __IO uint32_t CNT;
        stc_atim3mode1_cnt_field_t CNT_f;
    };
    uint8_t RESERVED1[4];
    union
    {
        __IO uint32_t M1CR;
        stc_atim3mode1_m1cr_field_t M1CR_f;
    };
    union
    {
        __IO uint32_t IFR;
        stc_atim3mode1_ifr_field_t IFR_f;
    };
    union
    {
        __IO uint32_t ICLR;
        stc_atim3mode1_iclr_field_t ICLR_f;
    };
    union
    {
        __IO uint32_t MSCR;
        stc_atim3mode1_mscr_field_t MSCR_f;
    };
    union
    {
        __IO uint32_t FLTR;
        stc_atim3mode1_fltr_field_t FLTR_f;
    };
    uint8_t RESERVED6[4];
    union
    {
        __IO uint32_t CR0;
        stc_atim3mode1_cr0_field_t CR0_f;
    };
    uint8_t RESERVED7[20];
    union
    {
        __IO uint32_t CCR0A;
        stc_atim3mode1_ccr0a_field_t CCR0A_f;
    };
}ATIM3MODE1_TypeDef;

typedef struct
{
    union
    {
        __IO uint32_t ARR;
        stc_atim3mode23_arr_field_t ARR_f;
    };
    union
    {
        __IO uint32_t CNT;
        stc_atim3mode23_cnt_field_t CNT_f;
    };
    uint8_t RESERVED2[4];
    union
    {
        __IO uint32_t M23CR;
        stc_atim3mode23_m23cr_field_t M23CR_f;
    };
    union
    {
        __IO uint32_t IFR;
        stc_atim3mode23_ifr_field_t IFR_f;
    };
    union
    {
        __IO uint32_t ICLR;
        stc_atim3mode23_iclr_field_t ICLR_f;
    };
    union
    {
        __IO uint32_t MSCR;
        stc_atim3mode23_mscr_field_t MSCR_f;
    };
    union
    {
        __IO uint32_t FLTR;
        stc_atim3mode23_fltr_field_t FLTR_f;
    };
    union
    {
        __IO uint32_t ADTR;
        stc_atim3mode23_adtr_field_t ADTR_f;
    };
    union
    {
        __IO uint32_t CRCH0;
        stc_atim3mode23_crch0_field_t CRCH0_f;
    };
    union
    {
        __IO uint32_t CRCH1;
        stc_atim3mode23_crch1_field_t CRCH1_f;
    };
    union
    {
        __IO uint32_t CRCH2;
        stc_atim3mode23_crch2_field_t CRCH2_f;
    };
    union
    {
        __IO uint32_t DTR;
        stc_atim3mode23_dtr_field_t DTR_f;
    };
    union
    {
        __IO uint32_t RCR;
        stc_atim3mode23_rcr_field_t RCR_f;
    };
    uint8_t RESERVED13[4];
    union
    {
        __IO uint32_t CCR0A;
        stc_atim3mode23_ccr0a_field_t CCR0A_f;
    };
    union
    {
        __IO uint32_t CCR0B;
        stc_atim3mode23_ccr0b_field_t CCR0B_f;
    };
    union
    {
        __IO uint32_t CCR1A;
        stc_atim3mode23_ccr1a_field_t CCR1A_f;
    };
    union
    {
        __IO uint32_t CCR1B;
        stc_atim3mode23_ccr1b_field_t CCR1B_f;
    };
    union
    {
        __IO uint32_t CCR2A;
        stc_atim3mode23_ccr2a_field_t CCR2A_f;
    };
    union
    {
        __IO uint32_t CCR2B;
        stc_atim3mode23_ccr2b_field_t CCR2B_f;
    };
    union
    {
        __IO uint32_t CCR3;
        stc_atim3mode23_ccr3_field_t CCR3_f;
    };
    union
    {
        __IO uint32_t CRCH3;
        stc_atim3mode23_crch3_field_t CRCH3_f;
    };
}ATIM3MODE23_TypeDef;

typedef struct
{
    union
    {
        __IO uint32_t ARR;
        stc_btim_arr_field_t ARR_f;
    };
    union
    {
        __IO uint32_t CNT;
        stc_btim_cnt_field_t CNT_f;
    };
    uint8_t RESERVED2[8];
    union
    {
        __IO uint32_t CR;
        stc_btim_cr_field_t CR_f;
    };
    union
    {
        __IO uint32_t IER;
        stc_btim_ier_field_t IER_f;
    };
    union
    {
        __IO uint32_t IFR;
        stc_btim_ifr_field_t IFR_f;
    };
    union
    {
        __IO uint32_t ICR;
        stc_btim_icr_field_t ICR_f;
    };
    uint8_t RESERVED6[40];
    union
    {
        __IO uint32_t AIFR;
        stc_btim_aifr_field_t AIFR_f;
    };
    union
    {
        __IO uint32_t AICR;
        stc_btim_aicr_field_t AICR_f;
    };
}BTIM_TypeDef;

typedef struct
{
    union
    {
        __IO uint32_t ARR;
        stc_ctrim_arr_field_t ARR_f;
    };
    union
    {
        __IO uint32_t CNT;
        stc_ctrim_cnt_field_t CNT_f;
    };
    uint8_t RESERVED2[4];
    union
    {
        __IO uint32_t CR0;
        stc_ctrim_cr0_field_t CR0_f;
    };
    union
    {
        __IO uint32_t CR1;
        stc_ctrim_cr1_field_t CR1_f;
    };
    union
    {
        __IO uint32_t IER;
        stc_ctrim_ier_field_t IER_f;
    };
    union
    {
        __IO uint32_t ISR;
        stc_ctrim_isr_field_t ISR_f;
    };
    union
    {
        __IO uint32_t ICR;
        stc_ctrim_icr_field_t ICR_f;
    };
    union
    {
        __IO uint32_t FCAP;
        stc_ctrim_fcap_field_t FCAP_f;
    };
    union
    {
        __IO uint32_t TVAL;
        stc_ctrim_tval_field_t TVAL_f;
    };
    union
    {
        __IO uint32_t FLIM;
        stc_ctrim_flim_field_t FLIM_f;
    };
}CTRIM_TypeDef;

typedef struct
{
    uint8_t RESERVED0[32];
    union
    {
        __IO uint32_t CR;
        stc_flash_cr_field_t CR_f;
    };
    union
    {
        __IO uint32_t IFR;
        stc_flash_ifr_field_t IFR_f;
    };
    union
    {
        __IO uint32_t ICLR;
        stc_flash_iclr_field_t ICLR_f;
    };
    union
    {
        __IO uint32_t BYPASS;
        stc_flash_bypass_field_t BYPASS_f;
    };
    union
    {
        __IO uint32_t SLOCK;
        stc_flash_slock_field_t SLOCK_f;
    };
    uint8_t RESERVED5[28];
    union
    {
        __IO uint32_t WAIT;
        stc_flash_wait_field_t WAIT_f;
    };
    union
    {
        __IO uint32_t LOCKSTATE;
        stc_flash_lockstate_field_t LOCKSTATE_f;
    };
}FLASH_TypeDef;

typedef struct
{
    union
    {
        __IO uint32_t ADS;
        stc_gpio_ads_field_t ADS_f;
    };
    union
    {
        __IO uint32_t DIR;
        stc_gpio_dir_field_t DIR_f;
    };
    union
    {
        __IO uint32_t OPENDRAIN;
        stc_gpio_opendrain_field_t OPENDRAIN_f;
    };
    uint8_t RESERVED3[12];
    union
    {
        __IO uint32_t PU;
        stc_gpio_pu_field_t PU_f;
    };
    union
    {
        __IO uint32_t IN;
        stc_gpio_in_field_t IN_f;
    };
    union
    {
        __IO uint32_t OUT;
        stc_gpio_out_field_t OUT_f;
    };
    union
    {
        __IO uint32_t BRR;
        stc_gpio_brr_field_t BRR_f;
    };
    union
    {
        __IO uint32_t BSRR;
        stc_gpio_bsrr_field_t BSRR_f;
    };
    uint8_t RESERVED8[4];
    union
    {
        __IO uint32_t AFRL;
        stc_gpio_afrl_field_t AFRL_f;
    };
    uint8_t RESERVED9[4];
    union
    {
        __IO uint32_t HIGHIE;
        stc_gpio_highie_field_t HIGHIE_f;
    };
    union
    {
        __IO uint32_t LOWIE;
        stc_gpio_lowie_field_t LOWIE_f;
    };
    union
    {
        __IO uint32_t RISEIE;
        stc_gpio_riseie_field_t RISEIE_f;
    };
    union
    {
        __IO uint32_t FALLIE;
        stc_gpio_fallie_field_t FALLIE_f;
    };
    union
    {
        __IO uint32_t IFR;
        stc_gpio_ifr_field_t IFR_f;
    };
    union
    {
        __IO uint32_t ICR;
        stc_gpio_icr_field_t ICR_f;
    };
}GPIO_TypeDef;

typedef struct
{
    uint8_t RESERVED0[4];
    union
    {
        __IO uint32_t CR1;
        stc_gpioaux_cr1_field_t CR1_f;
    };
    uint8_t RESERVED1[8];
    union
    {
        __IO uint32_t CR4;
        stc_gpioaux_cr4_field_t CR4_f;
    };
}GPIOAUX_TypeDef;

typedef struct
{
    uint8_t RESERVED0[768];
    union
    {
        __IO uint32_t ARR;
        stc_gtim_arr_field_t ARR_f;
    };
    union
    {
        __IO uint32_t CNT;
        stc_gtim_cnt_field_t CNT_f;
    };
    union
    {
        __IO uint32_t CMMR;
        stc_gtim_cmmr_field_t CMMR_f;
    };
    union
    {
        __IO uint32_t CR1;
        stc_gtim_cr1_field_t CR1_f;
    };
    union
    {
        __IO uint32_t CR0;
        stc_gtim_cr0_field_t CR0_f;
    };
    union
    {
        __IO uint32_t IER;
        stc_gtim_ier_field_t IER_f;
    };
    union
    {
        __IO uint32_t IFR;
        stc_gtim_ifr_field_t IFR_f;
    };
    union
    {
        __IO uint32_t ICR;
        stc_gtim_icr_field_t ICR_f;
    };
    union
    {
        __IO uint32_t CCR0;
        stc_gtim_ccr0_field_t CCR0_f;
    };
    union
    {
        __IO uint32_t CCR1;
        stc_gtim_ccr1_field_t CCR1_f;
    };
    union
    {
        __IO uint32_t CCR2;
        stc_gtim_ccr2_field_t CCR2_f;
    };
    union
    {
        __IO uint32_t CCR3;
        stc_gtim_ccr3_field_t CCR3_f;
    };
}GTIM_TypeDef;

typedef struct
{
    union
    {
        __IO uint32_t BRREN;
        stc_i2c_brren_field_t BRREN_f;
    };
    union
    {
        __IO uint32_t BRR;
        stc_i2c_brr_field_t BRR_f;
    };
    union
    {
        __IO uint32_t CR;
        stc_i2c_cr_field_t CR_f;
    };
    union
    {
        __IO uint32_t DR;
        stc_i2c_dr_field_t DR_f;
    };
    union
    {
        __IO uint32_t ADDR0;
        stc_i2c_addr0_field_t ADDR0_f;
    };
    union
    {
        __IO uint32_t STAT;
        stc_i2c_stat_field_t STAT_f;
    };
    uint8_t RESERVED6[8];
    union
    {
        __IO uint32_t ADDR1;
        stc_i2c_addr1_field_t ADDR1_f;
    };
    union
    {
        __IO uint32_t ADDR2;
        stc_i2c_addr2_field_t ADDR2_f;
    };
    union
    {
        __IO uint32_t MATCH;
        stc_i2c_match_field_t MATCH_f;
    };
}I2C_TypeDef;

typedef struct
{
    union
    {
        __IO uint32_t KR;
        stc_iwdt_kr_field_t KR_f;
    };
    union
    {
        __IO uint32_t CR;
        stc_iwdt_cr_field_t CR_f;
    };
    union
    {
        __IO uint32_t ARR;
        stc_iwdt_arr_field_t ARR_f;
    };
    union
    {
        __IO uint32_t SR;
        stc_iwdt_sr_field_t SR_f;
    };
    union
    {
        __IO uint32_t WINR;
        stc_iwdt_winr_field_t WINR_f;
    };
}IWDT_TypeDef;

typedef struct
{
    union
    {
        __IO uint32_t DR;
        stc_lpuart_dr_field_t DR_f;
    };
    union
    {
        __IO uint32_t CR;
        stc_lpuart_cr_field_t CR_f;
    };
    union
    {
        __IO uint32_t ADDR;
        stc_lpuart_addr_field_t ADDR_f;
    };
    union
    {
        __IO uint32_t ADDRMASK;
        stc_lpuart_addrmask_field_t ADDRMASK_f;
    };
    union
    {
        __IO uint32_t ISR;
        stc_lpuart_isr_field_t ISR_f;
    };
    union
    {
        __IO uint32_t ICR;
        stc_lpuart_icr_field_t ICR_f;
    };
    union
    {
        __IO uint32_t BRR;
        stc_lpuart_brr_field_t BRR_f;
    };
}LPUART_TypeDef;

typedef struct
{
    union
    {
        __IO uint32_t CR;
        stc_lvd_cr_field_t CR_f;
    };
    union
    {
        __IO uint32_t SR;
        stc_lvd_sr_field_t SR_f;
    };
}LVD_TypeDef;

typedef struct
{
    union
    {
        __IO uint32_t CR0;
        stc_spi_cr0_field_t CR0_f;
    };
    union
    {
        __IO uint32_t CR1;
        stc_spi_cr1_field_t CR1_f;
    };
    union
    {
        __IO uint32_t HDOE;
        stc_spi_hdoe_field_t HDOE_f;
    };
    union
    {
        __IO uint32_t SSI;
        stc_spi_ssi_field_t SSI_f;
    };
    union
    {
        __IO uint32_t SR;
        stc_spi_sr_field_t SR_f;
    };
    union
    {
        __IO uint32_t ICR;
        stc_spi_icr_field_t ICR_f;
    };
    union
    {
        __IO uint32_t DR;
        stc_spi_dr_field_t DR_f;
    };
}SPI_TypeDef;

typedef struct
{
    union
    {
        __IO uint32_t CR0;
        stc_sysctrl_cr0_field_t CR0_f;
    };
    union
    {
        __IO uint32_t CR1;
        stc_sysctrl_cr1_field_t CR1_f;
    };
    union
    {
        __IO uint32_t CR2;
        stc_sysctrl_cr2_field_t CR2_f;
    };
    union
    {
        __IO uint32_t CR3;
        stc_sysctrl_cr3_field_t CR3_f;
    };
    union
    {
        __IO uint32_t RCH;
        stc_sysctrl_rch_field_t RCH_f;
    };
    uint8_t RESERVED5[4];
    union
    {
        __IO uint32_t RCL;
        stc_sysctrl_rcl_field_t RCL_f;
    };
    uint8_t RESERVED6[20];
    union
    {
        __IO uint32_t PERICLKEN0;
        stc_sysctrl_periclken0_field_t PERICLKEN0_f;
    };
    union
    {
        __IO uint32_t PERICLKEN1;
        stc_sysctrl_periclken1_field_t PERICLKEN1_f;
    };
    union
    {
        __IO uint32_t PERIRESET0;
        stc_sysctrl_perireset0_field_t PERIRESET0_f;
    };
    union
    {
        __IO uint32_t PERIRESET1;
        stc_sysctrl_perireset1_field_t PERIRESET1_f;
    };
    union
    {
        __IO uint32_t RESETFLAG;
        stc_sysctrl_resetflag_field_t RESETFLAG_f;
    };
    union
    {
        __IO uint32_t DEBUGACTIVE;
        stc_sysctrl_debugactive_field_t DEBUGACTIVE_f;
    };
}SYSCTRL_TypeDef;

typedef struct
{
    union
    {
        __IO uint32_t CR0;
        stc_wwdt_cr0_field_t CR0_f;
    };
    union
    {
        __IO uint32_t CR1;
        stc_wwdt_cr1_field_t CR1_f;
    };
    union
    {
        __IO uint32_t SR;
        stc_wwdt_sr_field_t SR_f;
    };
}WWDT_TypeDef;



#define PERIPH_BASE                        (0x40000000UL)
#define ADC_BASE                               (PERIPH_BASE + 0x00002400UL)
#define ATIM3MODE0_BASE                        (PERIPH_BASE + 0x00005800UL)
#define ATIM3MODE1_BASE                        (PERIPH_BASE + 0x00005800UL)
#define ATIM3MODE23_BASE                       (PERIPH_BASE + 0x00005800UL)
#define BTIM3_BASE                             (PERIPH_BASE + 0x00007400UL)
#define BTIM4_BASE                             (PERIPH_BASE + 0x00007500UL)
#define BTIM5_BASE                             (PERIPH_BASE + 0x00007600UL)
#define CTRIM_BASE                             (PERIPH_BASE + 0x00005000UL)
#define FLASH_BASE                             (PERIPH_BASE + 0x00020000UL)
#define GPIOA_BASE                             (PERIPH_BASE + 0x00020C00UL)
#define GPIOAUX_BASE                           (PERIPH_BASE + 0x00020CA0UL)
#define GPIOB_BASE                             (PERIPH_BASE + 0x00020D00UL)
#define GPIOC_BASE                             (PERIPH_BASE + 0x00020E00UL)
#define GPIOD_BASE                             (PERIPH_BASE + 0x00020F00UL)
#define GTIM_BASE                              (PERIPH_BASE + 0x00007400UL)
#define I2C_BASE                               (PERIPH_BASE + 0x00000400UL)
#define IWDT_BASE                              (PERIPH_BASE + 0x00000F80UL)
#define LPUART0_BASE                           (PERIPH_BASE + 0x00000000UL)
#define LPUART1_BASE                           (PERIPH_BASE + 0x00004000UL)
#define LVD_BASE                               (PERIPH_BASE + 0x00002680UL)
#define SPI_BASE                               (PERIPH_BASE + 0x00000800UL)
#define SYSCTRL_BASE                           (PERIPH_BASE + 0x00002000UL)
#define WWDT_BASE                              (PERIPH_BASE + 0x00006800UL)


#define ADC                                    ((ADC_TypeDef *)0x40002400UL)
#define ATIM3MODE0                             ((ATIM3MODE0_TypeDef *)0x40005800UL)
#define ATIM3MODE1                             ((ATIM3MODE1_TypeDef *)0x40005800UL)
#define ATIM3MODE23                            ((ATIM3MODE23_TypeDef *)0x40005800UL)
#define BTIM3                                  ((BTIM_TypeDef *)0x40007400UL)
#define BTIM4                                  ((BTIM_TypeDef *)0x40007500UL)
#define BTIM5                                  ((BTIM_TypeDef *)0x40007600UL)
#define CTRIM                                  ((CTRIM_TypeDef *)0x40005000UL)
#define FLASH                                  ((FLASH_TypeDef *)0x40020000UL)
#define GPIOA                                  ((GPIO_TypeDef *)0x40020C00UL)
#define GPIOAUX                                ((GPIOAUX_TypeDef *)0x40020CA0UL)
#define GPIOB                                  ((GPIO_TypeDef *)0x40020D00UL)
#define GPIOC                                  ((GPIO_TypeDef *)0x40020E00UL)
#define GPIOD                                  ((GPIO_TypeDef *)0x40020F00UL)
#define GTIM                                   ((GTIM_TypeDef *)0x40007400UL)
#define I2C                                    ((I2C_TypeDef *)0x40000400UL)
#define IWDT                                   ((IWDT_TypeDef *)0x40000F80UL)
#define LPUART0                                ((LPUART_TypeDef *)0x40000000UL)
#define LPUART1                                ((LPUART_TypeDef *)0x40004000UL)
#define LVD                                    ((LVD_TypeDef *)0x40002680UL)
#define SPI                                    ((SPI_TypeDef *)0x40000800UL)
#define SYSCTRL                                ((SYSCTRL_TypeDef *)0x40002000UL)
#define WWDT                                   ((WWDT_TypeDef *)0x40006800UL)


//********************    Bits Define For Peripheral ADC    ********************//
// ADC_CR0
#define ADC_CR0_EN_Pos                                      (0U)
#define ADC_CR0_EN_Msk                                      (0x1UL << ADC_CR0_EN_Pos)
#define ADC_CR0_EN                                          ADC_CR0_EN_Msk
#define ADC_CR0_CKDIV_Pos                                   (2U)
#define ADC_CR0_CKDIV_Msk                                   (0x7UL << ADC_CR0_CKDIV_Pos)
#define ADC_CR0_CKDIV                                       ADC_CR0_CKDIV_Msk
#define ADC_CR0_REF_Pos                                     (9U)
#define ADC_CR0_REF_Msk                                     (0x3UL << ADC_CR0_REF_Pos)
#define ADC_CR0_REF                                         ADC_CR0_REF_Msk
#define ADC_CR0_SAM_Pos                                     (12U)
#define ADC_CR0_SAM_Msk                                     (0x3UL << ADC_CR0_SAM_Pos)
#define ADC_CR0_SAM                                         ADC_CR0_SAM_Msk

// ADC_CR1
#define ADC_CR1_CHSEL_Pos                                   (0U)
#define ADC_CR1_CHSEL_Msk                                   (0xFUL << ADC_CR1_CHSEL_Pos)
#define ADC_CR1_CHSEL                                       ADC_CR1_CHSEL_Msk

// ADC_RESULT
#define ADC_RESULT_RESULT_Pos                               (0U)
#define ADC_RESULT_RESULT_Msk                               (0xFFFFUL << ADC_RESULT_RESULT_Pos)
#define ADC_RESULT_RESULT                                   ADC_RESULT_RESULT_Msk

// ADC_IFR
#define ADC_IFR_EOC_Pos                                     (0U)
#define ADC_IFR_EOC_Msk                                     (0x1UL << ADC_IFR_EOC_Pos)
#define ADC_IFR_EOC                                         ADC_IFR_EOC_Msk

// ADC_IER
#define ADC_IER_EOC_Pos                                     (0U)
#define ADC_IER_EOC_Msk                                     (0x1UL << ADC_IER_EOC_Pos)
#define ADC_IER_EOC                                         ADC_IER_EOC_Msk

// ADC_ICR
#define ADC_ICR_EOC_Pos                                     (0U)
#define ADC_ICR_EOC_Msk                                     (0x1UL << ADC_ICR_EOC_Pos)
#define ADC_ICR_EOC                                         ADC_ICR_EOC_Msk

// ADC_EXTTRIGGER
#define ADC_EXTTRIGGER_TRIGSEL_Pos                          (0U)
#define ADC_EXTTRIGGER_TRIGSEL_Msk                          (0xFUL << ADC_EXTTRIGGER_TRIGSEL_Pos)
#define ADC_EXTTRIGGER_TRIGSEL                              ADC_EXTTRIGGER_TRIGSEL_Msk

// ADC_START
#define ADC_START_START_Pos                                 (0U)
#define ADC_START_START_Msk                                 (0x1UL << ADC_START_START_Pos)
#define ADC_START_START                                     ADC_START_START_Msk

// ADC_ALLSTART
#define ADC_ALLSTART_START_Pos                              (0U)
#define ADC_ALLSTART_START_Msk                              (0x1UL << ADC_ALLSTART_START_Pos)
#define ADC_ALLSTART_START                                  ADC_ALLSTART_START_Msk



//********************    Bits Define For Peripheral ATIM3MODE0    ********************//
// ATIM3MODE0_ARR
#define ATIM3MODE0_ARR_ARR_Pos                              (0U)
#define ATIM3MODE0_ARR_ARR_Msk                              (0xFFFFUL << ATIM3MODE0_ARR_ARR_Pos)
#define ATIM3MODE0_ARR_ARR                                  ATIM3MODE0_ARR_ARR_Msk

// ATIM3MODE0_CNT
#define ATIM3MODE0_CNT_CNT_Pos                              (0U)
#define ATIM3MODE0_CNT_CNT_Msk                              (0xFFFFUL << ATIM3MODE0_CNT_CNT_Pos)
#define ATIM3MODE0_CNT_CNT                                  ATIM3MODE0_CNT_CNT_Msk

// ATIM3MODE0_CNT32
#define ATIM3MODE0_CNT32_CNT32_Pos                          (0U)
#define ATIM3MODE0_CNT32_CNT32_Msk                          (0xFFFFFFFFUL << ATIM3MODE0_CNT32_CNT32_Pos)
#define ATIM3MODE0_CNT32_CNT32                              ATIM3MODE0_CNT32_CNT32_Msk

// ATIM3MODE0_M0CR
#define ATIM3MODE0_M0CR_CEN_Pos                             (0U)
#define ATIM3MODE0_M0CR_CEN_Msk                             (0x1UL << ATIM3MODE0_M0CR_CEN_Pos)
#define ATIM3MODE0_M0CR_CEN                                 ATIM3MODE0_M0CR_CEN_Msk
#define ATIM3MODE0_M0CR_MD_Pos                              (1U)
#define ATIM3MODE0_M0CR_MD_Msk                              (0x1UL << ATIM3MODE0_M0CR_MD_Pos)
#define ATIM3MODE0_M0CR_MD                                  ATIM3MODE0_M0CR_MD_Msk
#define ATIM3MODE0_M0CR_CT_Pos                              (2U)
#define ATIM3MODE0_M0CR_CT_Msk                              (0x1UL << ATIM3MODE0_M0CR_CT_Pos)
#define ATIM3MODE0_M0CR_CT                                  ATIM3MODE0_M0CR_CT_Msk
#define ATIM3MODE0_M0CR_TOG_Pos                             (3U)
#define ATIM3MODE0_M0CR_TOG_Msk                             (0x1UL << ATIM3MODE0_M0CR_TOG_Pos)
#define ATIM3MODE0_M0CR_TOG                                 ATIM3MODE0_M0CR_TOG_Msk
#define ATIM3MODE0_M0CR_PRS_Pos                             (4U)
#define ATIM3MODE0_M0CR_PRS_Msk                             (0x7UL << ATIM3MODE0_M0CR_PRS_Pos)
#define ATIM3MODE0_M0CR_PRS                                 ATIM3MODE0_M0CR_PRS_Msk
#define ATIM3MODE0_M0CR_GATE_Pos                            (8U)
#define ATIM3MODE0_M0CR_GATE_Msk                            (0x1UL << ATIM3MODE0_M0CR_GATE_Pos)
#define ATIM3MODE0_M0CR_GATE                                ATIM3MODE0_M0CR_GATE_Msk
#define ATIM3MODE0_M0CR_GATEP_Pos                           (9U)
#define ATIM3MODE0_M0CR_GATEP_Msk                           (0x1UL << ATIM3MODE0_M0CR_GATEP_Pos)
#define ATIM3MODE0_M0CR_GATEP                               ATIM3MODE0_M0CR_GATEP_Msk
#define ATIM3MODE0_M0CR_UI_Pos                              (10U)
#define ATIM3MODE0_M0CR_UI_Msk                              (0x1UL << ATIM3MODE0_M0CR_UI_Pos)
#define ATIM3MODE0_M0CR_UI                                  ATIM3MODE0_M0CR_UI_Msk
#define ATIM3MODE0_M0CR_MODE_Pos                            (12U)
#define ATIM3MODE0_M0CR_MODE_Msk                            (0x3UL << ATIM3MODE0_M0CR_MODE_Pos)
#define ATIM3MODE0_M0CR_MODE                                ATIM3MODE0_M0CR_MODE_Msk

// ATIM3MODE0_IFR
#define ATIM3MODE0_IFR_UI_Pos                               (0U)
#define ATIM3MODE0_IFR_UI_Msk                               (0x1UL << ATIM3MODE0_IFR_UI_Pos)
#define ATIM3MODE0_IFR_UI                                   ATIM3MODE0_IFR_UI_Msk

// ATIM3MODE0_ICLR
#define ATIM3MODE0_ICLR_UI_Pos                              (0U)
#define ATIM3MODE0_ICLR_UI_Msk                              (0x1UL << ATIM3MODE0_ICLR_UI_Pos)
#define ATIM3MODE0_ICLR_UI                                  ATIM3MODE0_ICLR_UI_Msk

// ATIM3MODE0_DTR
#define ATIM3MODE0_DTR_MO_Pos                               (12U)
#define ATIM3MODE0_DTR_MO_Msk                               (0x1UL << ATIM3MODE0_DTR_MO_Pos)
#define ATIM3MODE0_DTR_MO                                   ATIM3MODE0_DTR_MO_Msk



//********************    Bits Define For Peripheral ATIM3MODE1    ********************//
// ATIM3MODE1_CNT
#define ATIM3MODE1_CNT_CNT_Pos                              (0U)
#define ATIM3MODE1_CNT_CNT_Msk                              (0xFFFFUL << ATIM3MODE1_CNT_CNT_Pos)
#define ATIM3MODE1_CNT_CNT                                  ATIM3MODE1_CNT_CNT_Msk

// ATIM3MODE1_M1CR
#define ATIM3MODE1_M1CR_CEN_Pos                             (0U)
#define ATIM3MODE1_M1CR_CEN_Msk                             (0x1UL << ATIM3MODE1_M1CR_CEN_Pos)
#define ATIM3MODE1_M1CR_CEN                                 ATIM3MODE1_M1CR_CEN_Msk
#define ATIM3MODE1_M1CR_CT_Pos                              (2U)
#define ATIM3MODE1_M1CR_CT_Msk                              (0x1UL << ATIM3MODE1_M1CR_CT_Pos)
#define ATIM3MODE1_M1CR_CT                                  ATIM3MODE1_M1CR_CT_Msk
#define ATIM3MODE1_M1CR_PRS_Pos                             (4U)
#define ATIM3MODE1_M1CR_PRS_Msk                             (0x7UL << ATIM3MODE1_M1CR_PRS_Pos)
#define ATIM3MODE1_M1CR_PRS                                 ATIM3MODE1_M1CR_PRS_Msk
#define ATIM3MODE1_M1CR_EDG1ST_Pos                          (8U)
#define ATIM3MODE1_M1CR_EDG1ST_Msk                          (0x1UL << ATIM3MODE1_M1CR_EDG1ST_Pos)
#define ATIM3MODE1_M1CR_EDG1ST                              ATIM3MODE1_M1CR_EDG1ST_Msk
#define ATIM3MODE1_M1CR_EDG2ND_Pos                          (9U)
#define ATIM3MODE1_M1CR_EDG2ND_Msk                          (0x1UL << ATIM3MODE1_M1CR_EDG2ND_Pos)
#define ATIM3MODE1_M1CR_EDG2ND                              ATIM3MODE1_M1CR_EDG2ND_Msk
#define ATIM3MODE1_M1CR_UI_Pos                              (10U)
#define ATIM3MODE1_M1CR_UI_Msk                              (0x1UL << ATIM3MODE1_M1CR_UI_Pos)
#define ATIM3MODE1_M1CR_UI                                  ATIM3MODE1_M1CR_UI_Msk
#define ATIM3MODE1_M1CR_MODE_Pos                            (12U)
#define ATIM3MODE1_M1CR_MODE_Msk                            (0x3UL << ATIM3MODE1_M1CR_MODE_Pos)
#define ATIM3MODE1_M1CR_MODE                                ATIM3MODE1_M1CR_MODE_Msk
#define ATIM3MODE1_M1CR_ONESHOT_Pos                         (14U)
#define ATIM3MODE1_M1CR_ONESHOT_Msk                         (0x1UL << ATIM3MODE1_M1CR_ONESHOT_Pos)
#define ATIM3MODE1_M1CR_ONESHOT                             ATIM3MODE1_M1CR_ONESHOT_Msk

// ATIM3MODE1_IFR
#define ATIM3MODE1_IFR_UI_Pos                               (0U)
#define ATIM3MODE1_IFR_UI_Msk                               (0x1UL << ATIM3MODE1_IFR_UI_Pos)
#define ATIM3MODE1_IFR_UI                                   ATIM3MODE1_IFR_UI_Msk
#define ATIM3MODE1_IFR_PWC_Pos                              (2U)
#define ATIM3MODE1_IFR_PWC_Msk                              (0x1UL << ATIM3MODE1_IFR_PWC_Pos)
#define ATIM3MODE1_IFR_PWC                                  ATIM3MODE1_IFR_PWC_Msk

// ATIM3MODE1_ICLR
#define ATIM3MODE1_ICLR_UI_Pos                              (0U)
#define ATIM3MODE1_ICLR_UI_Msk                              (0x1UL << ATIM3MODE1_ICLR_UI_Pos)
#define ATIM3MODE1_ICLR_UI                                  ATIM3MODE1_ICLR_UI_Msk
#define ATIM3MODE1_ICLR_CA0_Pos                             (2U)
#define ATIM3MODE1_ICLR_CA0_Msk                             (0x1UL << ATIM3MODE1_ICLR_CA0_Pos)
#define ATIM3MODE1_ICLR_CA0                                 ATIM3MODE1_ICLR_CA0_Msk

// ATIM3MODE1_MSCR
#define ATIM3MODE1_MSCR_TS_Pos                              (5U)
#define ATIM3MODE1_MSCR_TS_Msk                              (0x7UL << ATIM3MODE1_MSCR_TS_Pos)
#define ATIM3MODE1_MSCR_TS                                  ATIM3MODE1_MSCR_TS_Msk
#define ATIM3MODE1_MSCR_IA0S_Pos                            (11U)
#define ATIM3MODE1_MSCR_IA0S_Msk                            (0x1UL << ATIM3MODE1_MSCR_IA0S_Pos)
#define ATIM3MODE1_MSCR_IA0S                                ATIM3MODE1_MSCR_IA0S_Msk
#define ATIM3MODE1_MSCR_IB0S_Pos                            (12U)
#define ATIM3MODE1_MSCR_IB0S_Msk                            (0x1UL << ATIM3MODE1_MSCR_IB0S_Pos)
#define ATIM3MODE1_MSCR_IB0S                                ATIM3MODE1_MSCR_IB0S_Msk

// ATIM3MODE1_FLTR
#define ATIM3MODE1_FLTR_FLTA0_Pos                           (0U)
#define ATIM3MODE1_FLTR_FLTA0_Msk                           (0x7UL << ATIM3MODE1_FLTR_FLTA0_Pos)
#define ATIM3MODE1_FLTR_FLTA0                               ATIM3MODE1_FLTR_FLTA0_Msk
#define ATIM3MODE1_FLTR_FLTB0_Pos                           (4U)
#define ATIM3MODE1_FLTR_FLTB0_Msk                           (0x7UL << ATIM3MODE1_FLTR_FLTB0_Pos)
#define ATIM3MODE1_FLTR_FLTB0                               ATIM3MODE1_FLTR_FLTB0_Msk
#define ATIM3MODE1_FLTR_FLTET_Pos                           (28U)
#define ATIM3MODE1_FLTR_FLTET_Msk                           (0x7UL << ATIM3MODE1_FLTR_FLTET_Pos)
#define ATIM3MODE1_FLTR_FLTET                               ATIM3MODE1_FLTR_FLTET_Msk
#define ATIM3MODE1_FLTR_ETP_Pos                             (31U)
#define ATIM3MODE1_FLTR_ETP_Msk                             (0x1UL << ATIM3MODE1_FLTR_ETP_Pos)
#define ATIM3MODE1_FLTR_ETP                                 ATIM3MODE1_FLTR_ETP_Msk

// ATIM3MODE1_CR0
#define ATIM3MODE1_CR0_CIEA_Pos                             (8U)
#define ATIM3MODE1_CR0_CIEA_Msk                             (0x1UL << ATIM3MODE1_CR0_CIEA_Pos)
#define ATIM3MODE1_CR0_CIEA                                 ATIM3MODE1_CR0_CIEA_Msk

// ATIM3MODE1_CCR0A
#define ATIM3MODE1_CCR0A_CCR0A_Pos                          (0U)
#define ATIM3MODE1_CCR0A_CCR0A_Msk                          (0xFFFFUL << ATIM3MODE1_CCR0A_CCR0A_Pos)
#define ATIM3MODE1_CCR0A_CCR0A                              ATIM3MODE1_CCR0A_CCR0A_Msk



//********************    Bits Define For Peripheral ATIM3MODE23    ********************//
// ATIM3MODE23_ARR
#define ATIM3MODE23_ARR_ARR_Pos                             (0U)
#define ATIM3MODE23_ARR_ARR_Msk                             (0xFFFFUL << ATIM3MODE23_ARR_ARR_Pos)
#define ATIM3MODE23_ARR_ARR                                 ATIM3MODE23_ARR_ARR_Msk

// ATIM3MODE23_CNT
#define ATIM3MODE23_CNT_CNT_Pos                             (0U)
#define ATIM3MODE23_CNT_CNT_Msk                             (0xFFFFUL << ATIM3MODE23_CNT_CNT_Pos)
#define ATIM3MODE23_CNT_CNT                                 ATIM3MODE23_CNT_CNT_Msk

// ATIM3MODE23_M23CR
#define ATIM3MODE23_M23CR_CTEN_Pos                          (0U)
#define ATIM3MODE23_M23CR_CTEN_Msk                          (0x1UL << ATIM3MODE23_M23CR_CTEN_Pos)
#define ATIM3MODE23_M23CR_CTEN                              ATIM3MODE23_M23CR_CTEN_Msk
#define ATIM3MODE23_M23CR_COMP_Pos                          (1U)
#define ATIM3MODE23_M23CR_COMP_Msk                          (0x1UL << ATIM3MODE23_M23CR_COMP_Pos)
#define ATIM3MODE23_M23CR_COMP                              ATIM3MODE23_M23CR_COMP_Msk
#define ATIM3MODE23_M23CR_CT_Pos                            (2U)
#define ATIM3MODE23_M23CR_CT_Msk                            (0x1UL << ATIM3MODE23_M23CR_CT_Pos)
#define ATIM3MODE23_M23CR_CT                                ATIM3MODE23_M23CR_CT_Msk
#define ATIM3MODE23_M23CR_PWM2S_Pos                         (3U)
#define ATIM3MODE23_M23CR_PWM2S_Msk                         (0x1UL << ATIM3MODE23_M23CR_PWM2S_Pos)
#define ATIM3MODE23_M23CR_PWM2S                             ATIM3MODE23_M23CR_PWM2S_Msk
#define ATIM3MODE23_M23CR_PRS_Pos                           (4U)
#define ATIM3MODE23_M23CR_PRS_Msk                           (0x7UL << ATIM3MODE23_M23CR_PRS_Pos)
#define ATIM3MODE23_M23CR_PRS                               ATIM3MODE23_M23CR_PRS_Msk
#define ATIM3MODE23_M23CR_BUFP_Pos                          (7U)
#define ATIM3MODE23_M23CR_BUFP_Msk                          (0x1UL << ATIM3MODE23_M23CR_BUFP_Pos)
#define ATIM3MODE23_M23CR_BUFP                              ATIM3MODE23_M23CR_BUFP_Msk
#define ATIM3MODE23_M23CR_CRG_Pos                           (8U)
#define ATIM3MODE23_M23CR_CRG_Msk                           (0x1UL << ATIM3MODE23_M23CR_CRG_Pos)
#define ATIM3MODE23_M23CR_CRG                               ATIM3MODE23_M23CR_CRG_Msk
#define ATIM3MODE23_M23CR_CFG_Pos                           (9U)
#define ATIM3MODE23_M23CR_CFG_Msk                           (0x1UL << ATIM3MODE23_M23CR_CFG_Pos)
#define ATIM3MODE23_M23CR_CFG                               ATIM3MODE23_M23CR_CFG_Msk
#define ATIM3MODE23_M23CR_UI_Pos                            (10U)
#define ATIM3MODE23_M23CR_UI_Msk                            (0x1UL << ATIM3MODE23_M23CR_UI_Pos)
#define ATIM3MODE23_M23CR_UI                                ATIM3MODE23_M23CR_UI_Msk
#define ATIM3MODE23_M23CR_UD_Pos                            (11U)
#define ATIM3MODE23_M23CR_UD_Msk                            (0x1UL << ATIM3MODE23_M23CR_UD_Pos)
#define ATIM3MODE23_M23CR_UD                                ATIM3MODE23_M23CR_UD_Msk
#define ATIM3MODE23_M23CR_MODE_Pos                          (12U)
#define ATIM3MODE23_M23CR_MODE_Msk                          (0x3UL << ATIM3MODE23_M23CR_MODE_Pos)
#define ATIM3MODE23_M23CR_MODE                              ATIM3MODE23_M23CR_MODE_Msk
#define ATIM3MODE23_M23CR_ONESHOT_Pos                       (14U)
#define ATIM3MODE23_M23CR_ONESHOT_Msk                       (0x1UL << ATIM3MODE23_M23CR_ONESHOT_Pos)
#define ATIM3MODE23_M23CR_ONESHOT                           ATIM3MODE23_M23CR_ONESHOT_Msk
#define ATIM3MODE23_M23CR_CSG_Pos                           (15U)
#define ATIM3MODE23_M23CR_CSG_Msk                           (0x1UL << ATIM3MODE23_M23CR_CSG_Pos)
#define ATIM3MODE23_M23CR_CSG                               ATIM3MODE23_M23CR_CSG_Msk
#define ATIM3MODE23_M23CR_OCCS_Pos                          (16U)
#define ATIM3MODE23_M23CR_OCCS_Msk                          (0x1UL << ATIM3MODE23_M23CR_OCCS_Pos)
#define ATIM3MODE23_M23CR_OCCS                              ATIM3MODE23_M23CR_OCCS_Msk
#define ATIM3MODE23_M23CR_URS_Pos                           (17U)
#define ATIM3MODE23_M23CR_URS_Msk                           (0x1UL << ATIM3MODE23_M23CR_URS_Pos)
#define ATIM3MODE23_M23CR_URS                               ATIM3MODE23_M23CR_URS_Msk
#define ATIM3MODE23_M23CR_TD_Pos                            (18U)
#define ATIM3MODE23_M23CR_TD_Msk                            (0x1UL << ATIM3MODE23_M23CR_TD_Pos)
#define ATIM3MODE23_M23CR_TD                                ATIM3MODE23_M23CR_TD_Msk
#define ATIM3MODE23_M23CR_TI_Pos                            (19U)
#define ATIM3MODE23_M23CR_TI_Msk                            (0x1UL << ATIM3MODE23_M23CR_TI_Pos)
#define ATIM3MODE23_M23CR_TI                                ATIM3MODE23_M23CR_TI_Msk
#define ATIM3MODE23_M23CR_BI_Pos                            (20U)
#define ATIM3MODE23_M23CR_BI_Msk                            (0x1UL << ATIM3MODE23_M23CR_BI_Pos)
#define ATIM3MODE23_M23CR_BI                                ATIM3MODE23_M23CR_BI_Msk
#define ATIM3MODE23_M23CR_CIS_Pos                           (21U)
#define ATIM3MODE23_M23CR_CIS_Msk                           (0x3UL << ATIM3MODE23_M23CR_CIS_Pos)
#define ATIM3MODE23_M23CR_CIS                               ATIM3MODE23_M23CR_CIS_Msk
#define ATIM3MODE23_M23CR_OCC_Pos                           (23U)
#define ATIM3MODE23_M23CR_OCC_Msk                           (0x1UL << ATIM3MODE23_M23CR_OCC_Pos)
#define ATIM3MODE23_M23CR_OCC                               ATIM3MODE23_M23CR_OCC_Msk
#define ATIM3MODE23_M23CR_TG_Pos                            (24U)
#define ATIM3MODE23_M23CR_TG_Msk                            (0x1UL << ATIM3MODE23_M23CR_TG_Pos)
#define ATIM3MODE23_M23CR_TG                                ATIM3MODE23_M23CR_TG_Msk
#define ATIM3MODE23_M23CR_UG_Pos                            (25U)
#define ATIM3MODE23_M23CR_UG_Msk                            (0x1UL << ATIM3MODE23_M23CR_UG_Pos)
#define ATIM3MODE23_M23CR_UG                                ATIM3MODE23_M23CR_UG_Msk
#define ATIM3MODE23_M23CR_BG_Pos                            (26U)
#define ATIM3MODE23_M23CR_BG_Msk                            (0x1UL << ATIM3MODE23_M23CR_BG_Pos)
#define ATIM3MODE23_M23CR_BG                                ATIM3MODE23_M23CR_BG_Msk
#define ATIM3MODE23_M23CR_DIR_Pos                           (27U)
#define ATIM3MODE23_M23CR_DIR_Msk                           (0x1UL << ATIM3MODE23_M23CR_DIR_Pos)
#define ATIM3MODE23_M23CR_DIR                               ATIM3MODE23_M23CR_DIR_Msk
#define ATIM3MODE23_M23CR_OV_Pos                            (28U)
#define ATIM3MODE23_M23CR_OV_Msk                            (0x1UL << ATIM3MODE23_M23CR_OV_Pos)
#define ATIM3MODE23_M23CR_OV                                ATIM3MODE23_M23CR_OV_Msk
#define ATIM3MODE23_M23CR_UND_Pos                           (29U)
#define ATIM3MODE23_M23CR_UND_Msk                           (0x1UL << ATIM3MODE23_M23CR_UND_Pos)
#define ATIM3MODE23_M23CR_UND                               ATIM3MODE23_M23CR_UND_Msk

// ATIM3MODE23_IFR
#define ATIM3MODE23_IFR_UI_Pos                              (0U)
#define ATIM3MODE23_IFR_UI_Msk                              (0x1UL << ATIM3MODE23_IFR_UI_Pos)
#define ATIM3MODE23_IFR_UI                                  ATIM3MODE23_IFR_UI_Msk
#define ATIM3MODE23_IFR_CA0_Pos                             (2U)
#define ATIM3MODE23_IFR_CA0_Msk                             (0x1UL << ATIM3MODE23_IFR_CA0_Pos)
#define ATIM3MODE23_IFR_CA0                                 ATIM3MODE23_IFR_CA0_Msk
#define ATIM3MODE23_IFR_CA1_Pos                             (3U)
#define ATIM3MODE23_IFR_CA1_Msk                             (0x1UL << ATIM3MODE23_IFR_CA1_Pos)
#define ATIM3MODE23_IFR_CA1                                 ATIM3MODE23_IFR_CA1_Msk
#define ATIM3MODE23_IFR_CA2_Pos                             (4U)
#define ATIM3MODE23_IFR_CA2_Msk                             (0x1UL << ATIM3MODE23_IFR_CA2_Pos)
#define ATIM3MODE23_IFR_CA2                                 ATIM3MODE23_IFR_CA2_Msk
#define ATIM3MODE23_IFR_CB0_Pos                             (5U)
#define ATIM3MODE23_IFR_CB0_Msk                             (0x1UL << ATIM3MODE23_IFR_CB0_Pos)
#define ATIM3MODE23_IFR_CB0                                 ATIM3MODE23_IFR_CB0_Msk
#define ATIM3MODE23_IFR_CB1_Pos                             (6U)
#define ATIM3MODE23_IFR_CB1_Msk                             (0x1UL << ATIM3MODE23_IFR_CB1_Pos)
#define ATIM3MODE23_IFR_CB1                                 ATIM3MODE23_IFR_CB1_Msk
#define ATIM3MODE23_IFR_CB2_Pos                             (7U)
#define ATIM3MODE23_IFR_CB2_Msk                             (0x1UL << ATIM3MODE23_IFR_CB2_Pos)
#define ATIM3MODE23_IFR_CB2                                 ATIM3MODE23_IFR_CB2_Msk
#define ATIM3MODE23_IFR_CA0E_Pos                            (8U)
#define ATIM3MODE23_IFR_CA0E_Msk                            (0x1UL << ATIM3MODE23_IFR_CA0E_Pos)
#define ATIM3MODE23_IFR_CA0E                                ATIM3MODE23_IFR_CA0E_Msk
#define ATIM3MODE23_IFR_CA1E_Pos                            (9U)
#define ATIM3MODE23_IFR_CA1E_Msk                            (0x1UL << ATIM3MODE23_IFR_CA1E_Pos)
#define ATIM3MODE23_IFR_CA1E                                ATIM3MODE23_IFR_CA1E_Msk
#define ATIM3MODE23_IFR_CA2E_Pos                            (10U)
#define ATIM3MODE23_IFR_CA2E_Msk                            (0x1UL << ATIM3MODE23_IFR_CA2E_Pos)
#define ATIM3MODE23_IFR_CA2E                                ATIM3MODE23_IFR_CA2E_Msk
#define ATIM3MODE23_IFR_CB0E_Pos                            (11U)
#define ATIM3MODE23_IFR_CB0E_Msk                            (0x1UL << ATIM3MODE23_IFR_CB0E_Pos)
#define ATIM3MODE23_IFR_CB0E                                ATIM3MODE23_IFR_CB0E_Msk
#define ATIM3MODE23_IFR_CB1E_Pos                            (12U)
#define ATIM3MODE23_IFR_CB1E_Msk                            (0x1UL << ATIM3MODE23_IFR_CB1E_Pos)
#define ATIM3MODE23_IFR_CB1E                                ATIM3MODE23_IFR_CB1E_Msk
#define ATIM3MODE23_IFR_CB2E_Pos                            (13U)
#define ATIM3MODE23_IFR_CB2E_Msk                            (0x1UL << ATIM3MODE23_IFR_CB2E_Pos)
#define ATIM3MODE23_IFR_CB2E                                ATIM3MODE23_IFR_CB2E_Msk
#define ATIM3MODE23_IFR_BI_Pos                              (14U)
#define ATIM3MODE23_IFR_BI_Msk                              (0x1UL << ATIM3MODE23_IFR_BI_Pos)
#define ATIM3MODE23_IFR_BI                                  ATIM3MODE23_IFR_BI_Msk
#define ATIM3MODE23_IFR_TI_Pos                              (15U)
#define ATIM3MODE23_IFR_TI_Msk                              (0x1UL << ATIM3MODE23_IFR_TI_Pos)
#define ATIM3MODE23_IFR_TI                                  ATIM3MODE23_IFR_TI_Msk
#define ATIM3MODE23_IFR_OV_Pos                              (16U)
#define ATIM3MODE23_IFR_OV_Msk                              (0x1UL << ATIM3MODE23_IFR_OV_Pos)
#define ATIM3MODE23_IFR_OV                                  ATIM3MODE23_IFR_OV_Msk
#define ATIM3MODE23_IFR_UND_Pos                             (17U)
#define ATIM3MODE23_IFR_UND_Msk                             (0x1UL << ATIM3MODE23_IFR_UND_Pos)
#define ATIM3MODE23_IFR_UND                                 ATIM3MODE23_IFR_UND_Msk
#define ATIM3MODE23_IFR_CA3_Pos                             (18U)
#define ATIM3MODE23_IFR_CA3_Msk                             (0x1UL << ATIM3MODE23_IFR_CA3_Pos)
#define ATIM3MODE23_IFR_CA3                                 ATIM3MODE23_IFR_CA3_Msk

// ATIM3MODE23_ICLR
#define ATIM3MODE23_ICLR_UI_Pos                             (0U)
#define ATIM3MODE23_ICLR_UI_Msk                             (0x1UL << ATIM3MODE23_ICLR_UI_Pos)
#define ATIM3MODE23_ICLR_UI                                 ATIM3MODE23_ICLR_UI_Msk
#define ATIM3MODE23_ICLR_CA0_Pos                            (2U)
#define ATIM3MODE23_ICLR_CA0_Msk                            (0x1UL << ATIM3MODE23_ICLR_CA0_Pos)
#define ATIM3MODE23_ICLR_CA0                                ATIM3MODE23_ICLR_CA0_Msk
#define ATIM3MODE23_ICLR_CA1_Pos                            (3U)
#define ATIM3MODE23_ICLR_CA1_Msk                            (0x1UL << ATIM3MODE23_ICLR_CA1_Pos)
#define ATIM3MODE23_ICLR_CA1                                ATIM3MODE23_ICLR_CA1_Msk
#define ATIM3MODE23_ICLR_CA2_Pos                            (4U)
#define ATIM3MODE23_ICLR_CA2_Msk                            (0x1UL << ATIM3MODE23_ICLR_CA2_Pos)
#define ATIM3MODE23_ICLR_CA2                                ATIM3MODE23_ICLR_CA2_Msk
#define ATIM3MODE23_ICLR_CB0_Pos                            (5U)
#define ATIM3MODE23_ICLR_CB0_Msk                            (0x1UL << ATIM3MODE23_ICLR_CB0_Pos)
#define ATIM3MODE23_ICLR_CB0                                ATIM3MODE23_ICLR_CB0_Msk
#define ATIM3MODE23_ICLR_CB1_Pos                            (6U)
#define ATIM3MODE23_ICLR_CB1_Msk                            (0x1UL << ATIM3MODE23_ICLR_CB1_Pos)
#define ATIM3MODE23_ICLR_CB1                                ATIM3MODE23_ICLR_CB1_Msk
#define ATIM3MODE23_ICLR_CB2_Pos                            (7U)
#define ATIM3MODE23_ICLR_CB2_Msk                            (0x1UL << ATIM3MODE23_ICLR_CB2_Pos)
#define ATIM3MODE23_ICLR_CB2                                ATIM3MODE23_ICLR_CB2_Msk
#define ATIM3MODE23_ICLR_CA0E_Pos                           (8U)
#define ATIM3MODE23_ICLR_CA0E_Msk                           (0x1UL << ATIM3MODE23_ICLR_CA0E_Pos)
#define ATIM3MODE23_ICLR_CA0E                               ATIM3MODE23_ICLR_CA0E_Msk
#define ATIM3MODE23_ICLR_CA1E_Pos                           (9U)
#define ATIM3MODE23_ICLR_CA1E_Msk                           (0x1UL << ATIM3MODE23_ICLR_CA1E_Pos)
#define ATIM3MODE23_ICLR_CA1E                               ATIM3MODE23_ICLR_CA1E_Msk
#define ATIM3MODE23_ICLR_CA2E_Pos                           (10U)
#define ATIM3MODE23_ICLR_CA2E_Msk                           (0x1UL << ATIM3MODE23_ICLR_CA2E_Pos)
#define ATIM3MODE23_ICLR_CA2E                               ATIM3MODE23_ICLR_CA2E_Msk
#define ATIM3MODE23_ICLR_CB0E_Pos                           (11U)
#define ATIM3MODE23_ICLR_CB0E_Msk                           (0x1UL << ATIM3MODE23_ICLR_CB0E_Pos)
#define ATIM3MODE23_ICLR_CB0E                               ATIM3MODE23_ICLR_CB0E_Msk
#define ATIM3MODE23_ICLR_CB1E_Pos                           (12U)
#define ATIM3MODE23_ICLR_CB1E_Msk                           (0x1UL << ATIM3MODE23_ICLR_CB1E_Pos)
#define ATIM3MODE23_ICLR_CB1E                               ATIM3MODE23_ICLR_CB1E_Msk
#define ATIM3MODE23_ICLR_CB2E_Pos                           (13U)
#define ATIM3MODE23_ICLR_CB2E_Msk                           (0x1UL << ATIM3MODE23_ICLR_CB2E_Pos)
#define ATIM3MODE23_ICLR_CB2E                               ATIM3MODE23_ICLR_CB2E_Msk
#define ATIM3MODE23_ICLR_BI_Pos                             (14U)
#define ATIM3MODE23_ICLR_BI_Msk                             (0x1UL << ATIM3MODE23_ICLR_BI_Pos)
#define ATIM3MODE23_ICLR_BI                                 ATIM3MODE23_ICLR_BI_Msk
#define ATIM3MODE23_ICLR_TI_Pos                             (15U)
#define ATIM3MODE23_ICLR_TI_Msk                             (0x1UL << ATIM3MODE23_ICLR_TI_Pos)
#define ATIM3MODE23_ICLR_TI                                 ATIM3MODE23_ICLR_TI_Msk
#define ATIM3MODE23_ICLR_OV_Pos                             (16U)
#define ATIM3MODE23_ICLR_OV_Msk                             (0x1UL << ATIM3MODE23_ICLR_OV_Pos)
#define ATIM3MODE23_ICLR_OV                                 ATIM3MODE23_ICLR_OV_Msk
#define ATIM3MODE23_ICLR_UND_Pos                            (17U)
#define ATIM3MODE23_ICLR_UND_Msk                            (0x1UL << ATIM3MODE23_ICLR_UND_Pos)
#define ATIM3MODE23_ICLR_UND                                ATIM3MODE23_ICLR_UND_Msk
#define ATIM3MODE23_ICLR_CA3_Pos                            (18U)
#define ATIM3MODE23_ICLR_CA3_Msk                            (0x1UL << ATIM3MODE23_ICLR_CA3_Pos)
#define ATIM3MODE23_ICLR_CA3                                ATIM3MODE23_ICLR_CA3_Msk

// ATIM3MODE23_MSCR
#define ATIM3MODE23_MSCR_MMS_Pos                            (0U)
#define ATIM3MODE23_MSCR_MMS_Msk                            (0x7UL << ATIM3MODE23_MSCR_MMS_Pos)
#define ATIM3MODE23_MSCR_MMS                                ATIM3MODE23_MSCR_MMS_Msk
#define ATIM3MODE23_MSCR_CCDS_Pos                           (3U)
#define ATIM3MODE23_MSCR_CCDS_Msk                           (0x1UL << ATIM3MODE23_MSCR_CCDS_Pos)
#define ATIM3MODE23_MSCR_CCDS                               ATIM3MODE23_MSCR_CCDS_Msk
#define ATIM3MODE23_MSCR_MSM_Pos                            (4U)
#define ATIM3MODE23_MSCR_MSM_Msk                            (0x1UL << ATIM3MODE23_MSCR_MSM_Pos)
#define ATIM3MODE23_MSCR_MSM                                ATIM3MODE23_MSCR_MSM_Msk
#define ATIM3MODE23_MSCR_TS_Pos                             (5U)
#define ATIM3MODE23_MSCR_TS_Msk                             (0x7UL << ATIM3MODE23_MSCR_TS_Pos)
#define ATIM3MODE23_MSCR_TS                                 ATIM3MODE23_MSCR_TS_Msk
#define ATIM3MODE23_MSCR_SMS_Pos                            (8U)
#define ATIM3MODE23_MSCR_SMS_Msk                            (0x7UL << ATIM3MODE23_MSCR_SMS_Pos)
#define ATIM3MODE23_MSCR_SMS                                ATIM3MODE23_MSCR_SMS_Msk
#define ATIM3MODE23_MSCR_IA0S_Pos                           (11U)
#define ATIM3MODE23_MSCR_IA0S_Msk                           (0x1UL << ATIM3MODE23_MSCR_IA0S_Pos)
#define ATIM3MODE23_MSCR_IA0S                               ATIM3MODE23_MSCR_IA0S_Msk
#define ATIM3MODE23_MSCR_IB0S_Pos                           (12U)
#define ATIM3MODE23_MSCR_IB0S_Msk                           (0x1UL << ATIM3MODE23_MSCR_IB0S_Pos)
#define ATIM3MODE23_MSCR_IB0S                               ATIM3MODE23_MSCR_IB0S_Msk

// ATIM3MODE23_FLTR
#define ATIM3MODE23_FLTR_OCMA0FLTA0_Pos                     (0U)
#define ATIM3MODE23_FLTR_OCMA0FLTA0_Msk                     (0x7UL << ATIM3MODE23_FLTR_OCMA0FLTA0_Pos)
#define ATIM3MODE23_FLTR_OCMA0FLTA0                         ATIM3MODE23_FLTR_OCMA0FLTA0_Msk
#define ATIM3MODE23_FLTR_CCPA0_Pos                          (3U)
#define ATIM3MODE23_FLTR_CCPA0_Msk                          (0x1UL << ATIM3MODE23_FLTR_CCPA0_Pos)
#define ATIM3MODE23_FLTR_CCPA0                              ATIM3MODE23_FLTR_CCPA0_Msk
#define ATIM3MODE23_FLTR_OCMB0FLTB0_Pos                     (4U)
#define ATIM3MODE23_FLTR_OCMB0FLTB0_Msk                     (0x7UL << ATIM3MODE23_FLTR_OCMB0FLTB0_Pos)
#define ATIM3MODE23_FLTR_OCMB0FLTB0                         ATIM3MODE23_FLTR_OCMB0FLTB0_Msk
#define ATIM3MODE23_FLTR_CCPB0_Pos                          (7U)
#define ATIM3MODE23_FLTR_CCPB0_Msk                          (0x1UL << ATIM3MODE23_FLTR_CCPB0_Pos)
#define ATIM3MODE23_FLTR_CCPB0                              ATIM3MODE23_FLTR_CCPB0_Msk
#define ATIM3MODE23_FLTR_OCMA1FLTA1_Pos                     (8U)
#define ATIM3MODE23_FLTR_OCMA1FLTA1_Msk                     (0x7UL << ATIM3MODE23_FLTR_OCMA1FLTA1_Pos)
#define ATIM3MODE23_FLTR_OCMA1FLTA1                         ATIM3MODE23_FLTR_OCMA1FLTA1_Msk
#define ATIM3MODE23_FLTR_CCPA1_Pos                          (11U)
#define ATIM3MODE23_FLTR_CCPA1_Msk                          (0x1UL << ATIM3MODE23_FLTR_CCPA1_Pos)
#define ATIM3MODE23_FLTR_CCPA1                              ATIM3MODE23_FLTR_CCPA1_Msk
#define ATIM3MODE23_FLTR_OCMB1FLTB1_Pos                     (12U)
#define ATIM3MODE23_FLTR_OCMB1FLTB1_Msk                     (0x7UL << ATIM3MODE23_FLTR_OCMB1FLTB1_Pos)
#define ATIM3MODE23_FLTR_OCMB1FLTB1                         ATIM3MODE23_FLTR_OCMB1FLTB1_Msk
#define ATIM3MODE23_FLTR_CCPB1_Pos                          (15U)
#define ATIM3MODE23_FLTR_CCPB1_Msk                          (0x1UL << ATIM3MODE23_FLTR_CCPB1_Pos)
#define ATIM3MODE23_FLTR_CCPB1                              ATIM3MODE23_FLTR_CCPB1_Msk
#define ATIM3MODE23_FLTR_OCMA2FLTA2_Pos                     (16U)
#define ATIM3MODE23_FLTR_OCMA2FLTA2_Msk                     (0x7UL << ATIM3MODE23_FLTR_OCMA2FLTA2_Pos)
#define ATIM3MODE23_FLTR_OCMA2FLTA2                         ATIM3MODE23_FLTR_OCMA2FLTA2_Msk
#define ATIM3MODE23_FLTR_CCPA2_Pos                          (19U)
#define ATIM3MODE23_FLTR_CCPA2_Msk                          (0x1UL << ATIM3MODE23_FLTR_CCPA2_Pos)
#define ATIM3MODE23_FLTR_CCPA2                              ATIM3MODE23_FLTR_CCPA2_Msk
#define ATIM3MODE23_FLTR_OCMB2FLTB2_Pos                     (20U)
#define ATIM3MODE23_FLTR_OCMB2FLTB2_Msk                     (0x7UL << ATIM3MODE23_FLTR_OCMB2FLTB2_Pos)
#define ATIM3MODE23_FLTR_OCMB2FLTB2                         ATIM3MODE23_FLTR_OCMB2FLTB2_Msk
#define ATIM3MODE23_FLTR_CCPB2_Pos                          (23U)
#define ATIM3MODE23_FLTR_CCPB2_Msk                          (0x1UL << ATIM3MODE23_FLTR_CCPB2_Pos)
#define ATIM3MODE23_FLTR_CCPB2                              ATIM3MODE23_FLTR_CCPB2_Msk
#define ATIM3MODE23_FLTR_FLTBK_Pos                          (24U)
#define ATIM3MODE23_FLTR_FLTBK_Msk                          (0x7UL << ATIM3MODE23_FLTR_FLTBK_Pos)
#define ATIM3MODE23_FLTR_FLTBK                              ATIM3MODE23_FLTR_FLTBK_Msk
#define ATIM3MODE23_FLTR_BKP_Pos                            (27U)
#define ATIM3MODE23_FLTR_BKP_Msk                            (0x1UL << ATIM3MODE23_FLTR_BKP_Pos)
#define ATIM3MODE23_FLTR_BKP                                ATIM3MODE23_FLTR_BKP_Msk
#define ATIM3MODE23_FLTR_FLTET_Pos                          (28U)
#define ATIM3MODE23_FLTR_FLTET_Msk                          (0x7UL << ATIM3MODE23_FLTR_FLTET_Pos)
#define ATIM3MODE23_FLTR_FLTET                              ATIM3MODE23_FLTR_FLTET_Msk
#define ATIM3MODE23_FLTR_ETP_Pos                            (31U)
#define ATIM3MODE23_FLTR_ETP_Msk                            (0x1UL << ATIM3MODE23_FLTR_ETP_Pos)
#define ATIM3MODE23_FLTR_ETP                                ATIM3MODE23_FLTR_ETP_Msk

// ATIM3MODE23_ADTR
#define ATIM3MODE23_ADTR_UEV_Pos                            (0U)
#define ATIM3MODE23_ADTR_UEV_Msk                            (0x1UL << ATIM3MODE23_ADTR_UEV_Pos)
#define ATIM3MODE23_ADTR_UEV                                ATIM3MODE23_ADTR_UEV_Msk
#define ATIM3MODE23_ADTR_CMA0_Pos                           (1U)
#define ATIM3MODE23_ADTR_CMA0_Msk                           (0x1UL << ATIM3MODE23_ADTR_CMA0_Pos)
#define ATIM3MODE23_ADTR_CMA0                               ATIM3MODE23_ADTR_CMA0_Msk
#define ATIM3MODE23_ADTR_CMA1_Pos                           (2U)
#define ATIM3MODE23_ADTR_CMA1_Msk                           (0x1UL << ATIM3MODE23_ADTR_CMA1_Pos)
#define ATIM3MODE23_ADTR_CMA1                               ATIM3MODE23_ADTR_CMA1_Msk
#define ATIM3MODE23_ADTR_CMA2_Pos                           (3U)
#define ATIM3MODE23_ADTR_CMA2_Msk                           (0x1UL << ATIM3MODE23_ADTR_CMA2_Pos)
#define ATIM3MODE23_ADTR_CMA2                               ATIM3MODE23_ADTR_CMA2_Msk
#define ATIM3MODE23_ADTR_CMB0_Pos                           (4U)
#define ATIM3MODE23_ADTR_CMB0_Msk                           (0x1UL << ATIM3MODE23_ADTR_CMB0_Pos)
#define ATIM3MODE23_ADTR_CMB0                               ATIM3MODE23_ADTR_CMB0_Msk
#define ATIM3MODE23_ADTR_CMB1_Pos                           (5U)
#define ATIM3MODE23_ADTR_CMB1_Msk                           (0x1UL << ATIM3MODE23_ADTR_CMB1_Pos)
#define ATIM3MODE23_ADTR_CMB1                               ATIM3MODE23_ADTR_CMB1_Msk
#define ATIM3MODE23_ADTR_CMB2_Pos                           (6U)
#define ATIM3MODE23_ADTR_CMB2_Msk                           (0x1UL << ATIM3MODE23_ADTR_CMB2_Pos)
#define ATIM3MODE23_ADTR_CMB2                               ATIM3MODE23_ADTR_CMB2_Msk
#define ATIM3MODE23_ADTR_ADT_Pos                            (7U)
#define ATIM3MODE23_ADTR_ADT_Msk                            (0x1UL << ATIM3MODE23_ADTR_ADT_Pos)
#define ATIM3MODE23_ADTR_ADT                                ATIM3MODE23_ADTR_ADT_Msk

// ATIM3MODE23_CRCH0
#define ATIM3MODE23_CRCH0_BKSACFACRA_Pos                    (0U)
#define ATIM3MODE23_CRCH0_BKSACFACRA_Msk                    (0x3UL << ATIM3MODE23_CRCH0_BKSACFACRA_Pos)
#define ATIM3MODE23_CRCH0_BKSACFACRA                        ATIM3MODE23_CRCH0_BKSACFACRA_Msk
#define ATIM3MODE23_CRCH0_BKSBCFBCRB_Pos                    (2U)
#define ATIM3MODE23_CRCH0_BKSBCFBCRB_Msk                    (0x3UL << ATIM3MODE23_CRCH0_BKSBCFBCRB_Pos)
#define ATIM3MODE23_CRCH0_BKSBCFBCRB                        ATIM3MODE23_CRCH0_BKSBCFBCRB_Msk
#define ATIM3MODE23_CRCH0_CSA_Pos                           (4U)
#define ATIM3MODE23_CRCH0_CSA_Msk                           (0x1UL << ATIM3MODE23_CRCH0_CSA_Pos)
#define ATIM3MODE23_CRCH0_CSA                               ATIM3MODE23_CRCH0_CSA_Msk
#define ATIM3MODE23_CRCH0_CSB_Pos                           (5U)
#define ATIM3MODE23_CRCH0_CSB_Msk                           (0x1UL << ATIM3MODE23_CRCH0_CSB_Pos)
#define ATIM3MODE23_CRCH0_CSB                               ATIM3MODE23_CRCH0_CSB_Msk
#define ATIM3MODE23_CRCH0_BUFEA_Pos                         (6U)
#define ATIM3MODE23_CRCH0_BUFEA_Msk                         (0x1UL << ATIM3MODE23_CRCH0_BUFEA_Pos)
#define ATIM3MODE23_CRCH0_BUFEA                             ATIM3MODE23_CRCH0_BUFEA_Msk
#define ATIM3MODE23_CRCH0_BUFEB_Pos                         (7U)
#define ATIM3MODE23_CRCH0_BUFEB_Msk                         (0x1UL << ATIM3MODE23_CRCH0_BUFEB_Pos)
#define ATIM3MODE23_CRCH0_BUFEB                             ATIM3MODE23_CRCH0_BUFEB_Msk
#define ATIM3MODE23_CRCH0_CIEA_Pos                          (8U)
#define ATIM3MODE23_CRCH0_CIEA_Msk                          (0x1UL << ATIM3MODE23_CRCH0_CIEA_Pos)
#define ATIM3MODE23_CRCH0_CIEA                              ATIM3MODE23_CRCH0_CIEA_Msk
#define ATIM3MODE23_CRCH0_CIEB_Pos                          (9U)
#define ATIM3MODE23_CRCH0_CIEB_Msk                          (0x1UL << ATIM3MODE23_CRCH0_CIEB_Pos)
#define ATIM3MODE23_CRCH0_CIEB                              ATIM3MODE23_CRCH0_CIEB_Msk
#define ATIM3MODE23_CRCH0_CDEA_Pos                          (10U)
#define ATIM3MODE23_CRCH0_CDEA_Msk                          (0x1UL << ATIM3MODE23_CRCH0_CDEA_Pos)
#define ATIM3MODE23_CRCH0_CDEA                              ATIM3MODE23_CRCH0_CDEA_Msk
#define ATIM3MODE23_CRCH0_CDEB_Pos                          (11U)
#define ATIM3MODE23_CRCH0_CDEB_Msk                          (0x1UL << ATIM3MODE23_CRCH0_CDEB_Pos)
#define ATIM3MODE23_CRCH0_CDEB                              ATIM3MODE23_CRCH0_CDEB_Msk
#define ATIM3MODE23_CRCH0_CISB_Pos                          (12U)
#define ATIM3MODE23_CRCH0_CISB_Msk                          (0x3UL << ATIM3MODE23_CRCH0_CISB_Pos)
#define ATIM3MODE23_CRCH0_CISB                              ATIM3MODE23_CRCH0_CISB_Msk
#define ATIM3MODE23_CRCH0_CCGA_Pos                          (14U)
#define ATIM3MODE23_CRCH0_CCGA_Msk                          (0x1UL << ATIM3MODE23_CRCH0_CCGA_Pos)
#define ATIM3MODE23_CRCH0_CCGA                              ATIM3MODE23_CRCH0_CCGA_Msk
#define ATIM3MODE23_CRCH0_CCGB_Pos                          (15U)
#define ATIM3MODE23_CRCH0_CCGB_Msk                          (0x1UL << ATIM3MODE23_CRCH0_CCGB_Pos)
#define ATIM3MODE23_CRCH0_CCGB                              ATIM3MODE23_CRCH0_CCGB_Msk

// ATIM3MODE23_CRCH1
#define ATIM3MODE23_CRCH1_BKSACFACRA_Pos                    (0U)
#define ATIM3MODE23_CRCH1_BKSACFACRA_Msk                    (0x3UL << ATIM3MODE23_CRCH1_BKSACFACRA_Pos)
#define ATIM3MODE23_CRCH1_BKSACFACRA                        ATIM3MODE23_CRCH1_BKSACFACRA_Msk
#define ATIM3MODE23_CRCH1_BKSBCFBCRB_Pos                    (2U)
#define ATIM3MODE23_CRCH1_BKSBCFBCRB_Msk                    (0x3UL << ATIM3MODE23_CRCH1_BKSBCFBCRB_Pos)
#define ATIM3MODE23_CRCH1_BKSBCFBCRB                        ATIM3MODE23_CRCH1_BKSBCFBCRB_Msk
#define ATIM3MODE23_CRCH1_CSA_Pos                           (4U)
#define ATIM3MODE23_CRCH1_CSA_Msk                           (0x1UL << ATIM3MODE23_CRCH1_CSA_Pos)
#define ATIM3MODE23_CRCH1_CSA                               ATIM3MODE23_CRCH1_CSA_Msk
#define ATIM3MODE23_CRCH1_CSB_Pos                           (5U)
#define ATIM3MODE23_CRCH1_CSB_Msk                           (0x1UL << ATIM3MODE23_CRCH1_CSB_Pos)
#define ATIM3MODE23_CRCH1_CSB                               ATIM3MODE23_CRCH1_CSB_Msk
#define ATIM3MODE23_CRCH1_BUFEA_Pos                         (6U)
#define ATIM3MODE23_CRCH1_BUFEA_Msk                         (0x1UL << ATIM3MODE23_CRCH1_BUFEA_Pos)
#define ATIM3MODE23_CRCH1_BUFEA                             ATIM3MODE23_CRCH1_BUFEA_Msk
#define ATIM3MODE23_CRCH1_BUFEB_Pos                         (7U)
#define ATIM3MODE23_CRCH1_BUFEB_Msk                         (0x1UL << ATIM3MODE23_CRCH1_BUFEB_Pos)
#define ATIM3MODE23_CRCH1_BUFEB                             ATIM3MODE23_CRCH1_BUFEB_Msk
#define ATIM3MODE23_CRCH1_CIEA_Pos                          (8U)
#define ATIM3MODE23_CRCH1_CIEA_Msk                          (0x1UL << ATIM3MODE23_CRCH1_CIEA_Pos)
#define ATIM3MODE23_CRCH1_CIEA                              ATIM3MODE23_CRCH1_CIEA_Msk
#define ATIM3MODE23_CRCH1_CIEB_Pos                          (9U)
#define ATIM3MODE23_CRCH1_CIEB_Msk                          (0x1UL << ATIM3MODE23_CRCH1_CIEB_Pos)
#define ATIM3MODE23_CRCH1_CIEB                              ATIM3MODE23_CRCH1_CIEB_Msk
#define ATIM3MODE23_CRCH1_CDEA_Pos                          (10U)
#define ATIM3MODE23_CRCH1_CDEA_Msk                          (0x1UL << ATIM3MODE23_CRCH1_CDEA_Pos)
#define ATIM3MODE23_CRCH1_CDEA                              ATIM3MODE23_CRCH1_CDEA_Msk
#define ATIM3MODE23_CRCH1_CDEB_Pos                          (11U)
#define ATIM3MODE23_CRCH1_CDEB_Msk                          (0x1UL << ATIM3MODE23_CRCH1_CDEB_Pos)
#define ATIM3MODE23_CRCH1_CDEB                              ATIM3MODE23_CRCH1_CDEB_Msk
#define ATIM3MODE23_CRCH1_CISB_Pos                          (12U)
#define ATIM3MODE23_CRCH1_CISB_Msk                          (0x3UL << ATIM3MODE23_CRCH1_CISB_Pos)
#define ATIM3MODE23_CRCH1_CISB                              ATIM3MODE23_CRCH1_CISB_Msk
#define ATIM3MODE23_CRCH1_CCGA_Pos                          (14U)
#define ATIM3MODE23_CRCH1_CCGA_Msk                          (0x1UL << ATIM3MODE23_CRCH1_CCGA_Pos)
#define ATIM3MODE23_CRCH1_CCGA                              ATIM3MODE23_CRCH1_CCGA_Msk
#define ATIM3MODE23_CRCH1_CCGB_Pos                          (15U)
#define ATIM3MODE23_CRCH1_CCGB_Msk                          (0x1UL << ATIM3MODE23_CRCH1_CCGB_Pos)
#define ATIM3MODE23_CRCH1_CCGB                              ATIM3MODE23_CRCH1_CCGB_Msk

// ATIM3MODE23_CRCH2
#define ATIM3MODE23_CRCH2_BKSACFACRA_Pos                    (0U)
#define ATIM3MODE23_CRCH2_BKSACFACRA_Msk                    (0x3UL << ATIM3MODE23_CRCH2_BKSACFACRA_Pos)
#define ATIM3MODE23_CRCH2_BKSACFACRA                        ATIM3MODE23_CRCH2_BKSACFACRA_Msk
#define ATIM3MODE23_CRCH2_BKSBCFBCRB_Pos                    (2U)
#define ATIM3MODE23_CRCH2_BKSBCFBCRB_Msk                    (0x3UL << ATIM3MODE23_CRCH2_BKSBCFBCRB_Pos)
#define ATIM3MODE23_CRCH2_BKSBCFBCRB                        ATIM3MODE23_CRCH2_BKSBCFBCRB_Msk
#define ATIM3MODE23_CRCH2_CSA_Pos                           (4U)
#define ATIM3MODE23_CRCH2_CSA_Msk                           (0x1UL << ATIM3MODE23_CRCH2_CSA_Pos)
#define ATIM3MODE23_CRCH2_CSA                               ATIM3MODE23_CRCH2_CSA_Msk
#define ATIM3MODE23_CRCH2_CSB_Pos                           (5U)
#define ATIM3MODE23_CRCH2_CSB_Msk                           (0x1UL << ATIM3MODE23_CRCH2_CSB_Pos)
#define ATIM3MODE23_CRCH2_CSB                               ATIM3MODE23_CRCH2_CSB_Msk
#define ATIM3MODE23_CRCH2_BUFEA_Pos                         (6U)
#define ATIM3MODE23_CRCH2_BUFEA_Msk                         (0x1UL << ATIM3MODE23_CRCH2_BUFEA_Pos)
#define ATIM3MODE23_CRCH2_BUFEA                             ATIM3MODE23_CRCH2_BUFEA_Msk
#define ATIM3MODE23_CRCH2_BUFEB_Pos                         (7U)
#define ATIM3MODE23_CRCH2_BUFEB_Msk                         (0x1UL << ATIM3MODE23_CRCH2_BUFEB_Pos)
#define ATIM3MODE23_CRCH2_BUFEB                             ATIM3MODE23_CRCH2_BUFEB_Msk
#define ATIM3MODE23_CRCH2_CIEA_Pos                          (8U)
#define ATIM3MODE23_CRCH2_CIEA_Msk                          (0x1UL << ATIM3MODE23_CRCH2_CIEA_Pos)
#define ATIM3MODE23_CRCH2_CIEA                              ATIM3MODE23_CRCH2_CIEA_Msk
#define ATIM3MODE23_CRCH2_CIEB_Pos                          (9U)
#define ATIM3MODE23_CRCH2_CIEB_Msk                          (0x1UL << ATIM3MODE23_CRCH2_CIEB_Pos)
#define ATIM3MODE23_CRCH2_CIEB                              ATIM3MODE23_CRCH2_CIEB_Msk
#define ATIM3MODE23_CRCH2_CDEA_Pos                          (10U)
#define ATIM3MODE23_CRCH2_CDEA_Msk                          (0x1UL << ATIM3MODE23_CRCH2_CDEA_Pos)
#define ATIM3MODE23_CRCH2_CDEA                              ATIM3MODE23_CRCH2_CDEA_Msk
#define ATIM3MODE23_CRCH2_CDEB_Pos                          (11U)
#define ATIM3MODE23_CRCH2_CDEB_Msk                          (0x1UL << ATIM3MODE23_CRCH2_CDEB_Pos)
#define ATIM3MODE23_CRCH2_CDEB                              ATIM3MODE23_CRCH2_CDEB_Msk
#define ATIM3MODE23_CRCH2_CISB_Pos                          (12U)
#define ATIM3MODE23_CRCH2_CISB_Msk                          (0x3UL << ATIM3MODE23_CRCH2_CISB_Pos)
#define ATIM3MODE23_CRCH2_CISB                              ATIM3MODE23_CRCH2_CISB_Msk
#define ATIM3MODE23_CRCH2_CCGA_Pos                          (14U)
#define ATIM3MODE23_CRCH2_CCGA_Msk                          (0x1UL << ATIM3MODE23_CRCH2_CCGA_Pos)
#define ATIM3MODE23_CRCH2_CCGA                              ATIM3MODE23_CRCH2_CCGA_Msk
#define ATIM3MODE23_CRCH2_CCGB_Pos                          (15U)
#define ATIM3MODE23_CRCH2_CCGB_Msk                          (0x1UL << ATIM3MODE23_CRCH2_CCGB_Pos)
#define ATIM3MODE23_CRCH2_CCGB                              ATIM3MODE23_CRCH2_CCGB_Msk

// ATIM3MODE23_DTR
#define ATIM3MODE23_DTR_DTR_Pos                             (0U)
#define ATIM3MODE23_DTR_DTR_Msk                             (0xFFUL << ATIM3MODE23_DTR_DTR_Pos)
#define ATIM3MODE23_DTR_DTR                                 ATIM3MODE23_DTR_DTR_Msk
#define ATIM3MODE23_DTR_BKSEL_Pos                           (8U)
#define ATIM3MODE23_DTR_BKSEL_Msk                           (0x1UL << ATIM3MODE23_DTR_BKSEL_Pos)
#define ATIM3MODE23_DTR_BKSEL                               ATIM3MODE23_DTR_BKSEL_Msk
#define ATIM3MODE23_DTR_DT_Pos                              (9U)
#define ATIM3MODE23_DTR_DT_Msk                              (0x1UL << ATIM3MODE23_DTR_DT_Pos)
#define ATIM3MODE23_DTR_DT                                  ATIM3MODE23_DTR_DT_Msk
#define ATIM3MODE23_DTR_BK_Pos                              (10U)
#define ATIM3MODE23_DTR_BK_Msk                              (0x1UL << ATIM3MODE23_DTR_BK_Pos)
#define ATIM3MODE23_DTR_BK                                  ATIM3MODE23_DTR_BK_Msk
#define ATIM3MODE23_DTR_AO_Pos                              (11U)
#define ATIM3MODE23_DTR_AO_Msk                              (0x1UL << ATIM3MODE23_DTR_AO_Pos)
#define ATIM3MODE23_DTR_AO                                  ATIM3MODE23_DTR_AO_Msk
#define ATIM3MODE23_DTR_MO_Pos                              (12U)
#define ATIM3MODE23_DTR_MO_Msk                              (0x1UL << ATIM3MODE23_DTR_MO_Pos)
#define ATIM3MODE23_DTR_MO                                  ATIM3MODE23_DTR_MO_Msk
#define ATIM3MODE23_DTR_SAFE_Pos                            (13U)
#define ATIM3MODE23_DTR_SAFE_Msk                            (0x1UL << ATIM3MODE23_DTR_SAFE_Pos)
#define ATIM3MODE23_DTR_SAFE                                ATIM3MODE23_DTR_SAFE_Msk
#define ATIM3MODE23_DTR_VC_Pos                              (14U)
#define ATIM3MODE23_DTR_VC_Msk                              (0x1UL << ATIM3MODE23_DTR_VC_Pos)
#define ATIM3MODE23_DTR_VC                                  ATIM3MODE23_DTR_VC_Msk

// ATIM3MODE23_RCR
#define ATIM3MODE23_RCR_RCR_Pos                             (0U)
#define ATIM3MODE23_RCR_RCR_Msk                             (0xFFUL << ATIM3MODE23_RCR_RCR_Pos)
#define ATIM3MODE23_RCR_RCR                                 ATIM3MODE23_RCR_RCR_Msk
#define ATIM3MODE23_RCR_OV_Pos                              (8U)
#define ATIM3MODE23_RCR_OV_Msk                              (0x1UL << ATIM3MODE23_RCR_OV_Pos)
#define ATIM3MODE23_RCR_OV                                  ATIM3MODE23_RCR_OV_Msk
#define ATIM3MODE23_RCR_UD_Pos                              (9U)
#define ATIM3MODE23_RCR_UD_Msk                              (0x1UL << ATIM3MODE23_RCR_UD_Pos)
#define ATIM3MODE23_RCR_UD                                  ATIM3MODE23_RCR_UD_Msk

// ATIM3MODE23_CCR0A
#define ATIM3MODE23_CCR0A_CCR0A_Pos                         (0U)
#define ATIM3MODE23_CCR0A_CCR0A_Msk                         (0xFFFFUL << ATIM3MODE23_CCR0A_CCR0A_Pos)
#define ATIM3MODE23_CCR0A_CCR0A                             ATIM3MODE23_CCR0A_CCR0A_Msk

// ATIM3MODE23_CCR0B
#define ATIM3MODE23_CCR0B_CCR0B_Pos                         (0U)
#define ATIM3MODE23_CCR0B_CCR0B_Msk                         (0xFFFFUL << ATIM3MODE23_CCR0B_CCR0B_Pos)
#define ATIM3MODE23_CCR0B_CCR0B                             ATIM3MODE23_CCR0B_CCR0B_Msk

// ATIM3MODE23_CCR1A
#define ATIM3MODE23_CCR1A_CCR1A_Pos                         (0U)
#define ATIM3MODE23_CCR1A_CCR1A_Msk                         (0xFFFFUL << ATIM3MODE23_CCR1A_CCR1A_Pos)
#define ATIM3MODE23_CCR1A_CCR1A                             ATIM3MODE23_CCR1A_CCR1A_Msk

// ATIM3MODE23_CCR1B
#define ATIM3MODE23_CCR1B_CCR1B_Pos                         (0U)
#define ATIM3MODE23_CCR1B_CCR1B_Msk                         (0xFFFFUL << ATIM3MODE23_CCR1B_CCR1B_Pos)
#define ATIM3MODE23_CCR1B_CCR1B                             ATIM3MODE23_CCR1B_CCR1B_Msk

// ATIM3MODE23_CCR2A
#define ATIM3MODE23_CCR2A_CCR2A_Pos                         (0U)
#define ATIM3MODE23_CCR2A_CCR2A_Msk                         (0xFFFFUL << ATIM3MODE23_CCR2A_CCR2A_Pos)
#define ATIM3MODE23_CCR2A_CCR2A                             ATIM3MODE23_CCR2A_CCR2A_Msk

// ATIM3MODE23_CCR2B
#define ATIM3MODE23_CCR2B_CCR2B_Pos                         (0U)
#define ATIM3MODE23_CCR2B_CCR2B_Msk                         (0xFFFFUL << ATIM3MODE23_CCR2B_CCR2B_Pos)
#define ATIM3MODE23_CCR2B_CCR2B                             ATIM3MODE23_CCR2B_CCR2B_Msk

// ATIM3MODE23_CCR3
#define ATIM3MODE23_CCR3_CCR3_Pos                           (0U)
#define ATIM3MODE23_CCR3_CCR3_Msk                           (0xFFFFUL << ATIM3MODE23_CCR3_CCR3_Pos)
#define ATIM3MODE23_CCR3_CCR3                               ATIM3MODE23_CCR3_CCR3_Msk

// ATIM3MODE23_CRCH3
#define ATIM3MODE23_CRCH3_BUF_Pos                           (0U)
#define ATIM3MODE23_CRCH3_BUF_Msk                           (0x1UL << ATIM3MODE23_CRCH3_BUF_Pos)
#define ATIM3MODE23_CRCH3_BUF                               ATIM3MODE23_CRCH3_BUF_Msk
#define ATIM3MODE23_CRCH3_CI_Pos                            (1U)
#define ATIM3MODE23_CRCH3_CI_Msk                            (0x1UL << ATIM3MODE23_CRCH3_CI_Pos)
#define ATIM3MODE23_CRCH3_CI                                ATIM3MODE23_CRCH3_CI_Msk
#define ATIM3MODE23_CRCH3_CD_Pos                            (2U)
#define ATIM3MODE23_CRCH3_CD_Msk                            (0x1UL << ATIM3MODE23_CRCH3_CD_Pos)
#define ATIM3MODE23_CRCH3_CD                                ATIM3MODE23_CRCH3_CD_Msk
#define ATIM3MODE23_CRCH3_CIS_Pos                           (3U)
#define ATIM3MODE23_CRCH3_CIS_Msk                           (0x3UL << ATIM3MODE23_CRCH3_CIS_Pos)
#define ATIM3MODE23_CRCH3_CIS                               ATIM3MODE23_CRCH3_CIS_Msk
#define ATIM3MODE23_CRCH3_C3_Pos                            (5U)
#define ATIM3MODE23_CRCH3_C3_Msk                            (0x1UL << ATIM3MODE23_CRCH3_C3_Pos)
#define ATIM3MODE23_CRCH3_C3                                ATIM3MODE23_CRCH3_C3_Msk



//********************    Bits Define For Peripheral BTIM    ********************//
// BTIM_ARR
#define BTIM_ARR_ARR_Pos                                    (0U)
#define BTIM_ARR_ARR_Msk                                    (0xFFFFUL << BTIM_ARR_ARR_Pos)
#define BTIM_ARR_ARR                                        BTIM_ARR_ARR_Msk

// BTIM_CNT
#define BTIM_CNT_CNT_Pos                                    (0U)
#define BTIM_CNT_CNT_Msk                                    (0xFFFFUL << BTIM_CNT_CNT_Pos)
#define BTIM_CNT_CNT                                        BTIM_CNT_CNT_Msk

// BTIM_CR
#define BTIM_CR_CEN_Pos                                     (0U)
#define BTIM_CR_CEN_Msk                                     (0x1UL << BTIM_CR_CEN_Pos)
#define BTIM_CR_CEN                                         BTIM_CR_CEN_Msk
#define BTIM_CR_MD_Pos                                      (1U)
#define BTIM_CR_MD_Msk                                      (0x3UL << BTIM_CR_MD_Pos)
#define BTIM_CR_MD                                          BTIM_CR_MD_Msk
#define BTIM_CR_TOGEN_Pos                                   (3U)
#define BTIM_CR_TOGEN_Msk                                   (0x1UL << BTIM_CR_TOGEN_Pos)
#define BTIM_CR_TOGEN                                       BTIM_CR_TOGEN_Msk
#define BTIM_CR_PRS_Pos                                     (4U)
#define BTIM_CR_PRS_Msk                                     (0xFUL << BTIM_CR_PRS_Pos)
#define BTIM_CR_PRS                                         BTIM_CR_PRS_Msk
#define BTIM_CR_OST_Pos                                     (8U)
#define BTIM_CR_OST_Msk                                     (0x1UL << BTIM_CR_OST_Pos)
#define BTIM_CR_OST                                         BTIM_CR_OST_Msk
#define BTIM_CR_TRS_Pos                                     (9U)
#define BTIM_CR_TRS_Msk                                     (0x3UL << BTIM_CR_TRS_Pos)
#define BTIM_CR_TRS                                         BTIM_CR_TRS_Msk
#define BTIM_CR_ETP_Pos                                     (11U)
#define BTIM_CR_ETP_Msk                                     (0x1UL << BTIM_CR_ETP_Pos)
#define BTIM_CR_ETP                                         BTIM_CR_ETP_Msk

// BTIM_IER
#define BTIM_IER_UI_Pos                                     (0U)
#define BTIM_IER_UI_Msk                                     (0x1UL << BTIM_IER_UI_Pos)
#define BTIM_IER_UI                                         BTIM_IER_UI_Msk
#define BTIM_IER_TI_Pos                                     (1U)
#define BTIM_IER_TI_Msk                                     (0x1UL << BTIM_IER_TI_Pos)
#define BTIM_IER_TI                                         BTIM_IER_TI_Msk

// BTIM_IFR
#define BTIM_IFR_UI_Pos                                     (0U)
#define BTIM_IFR_UI_Msk                                     (0x1UL << BTIM_IFR_UI_Pos)
#define BTIM_IFR_UI                                         BTIM_IFR_UI_Msk
#define BTIM_IFR_TI_Pos                                     (1U)
#define BTIM_IFR_TI_Msk                                     (0x1UL << BTIM_IFR_TI_Pos)
#define BTIM_IFR_TI                                         BTIM_IFR_TI_Msk

// BTIM_ICR
#define BTIM_ICR_UI_Pos                                     (0U)
#define BTIM_ICR_UI_Msk                                     (0x1UL << BTIM_ICR_UI_Pos)
#define BTIM_ICR_UI                                         BTIM_ICR_UI_Msk
#define BTIM_ICR_TI_Pos                                     (1U)
#define BTIM_ICR_TI_Msk                                     (0x1UL << BTIM_ICR_TI_Pos)
#define BTIM_ICR_TI                                         BTIM_ICR_TI_Msk

// BTIM_AIFR
#define BTIM_AIFR_UI3_Pos                                   (0U)
#define BTIM_AIFR_UI3_Msk                                   (0x1UL << BTIM_AIFR_UI3_Pos)
#define BTIM_AIFR_UI3                                       BTIM_AIFR_UI3_Msk
#define BTIM_AIFR_TI3_Pos                                   (1U)
#define BTIM_AIFR_TI3_Msk                                   (0x1UL << BTIM_AIFR_TI3_Pos)
#define BTIM_AIFR_TI3                                       BTIM_AIFR_TI3_Msk
#define BTIM_AIFR_UI4_Pos                                   (2U)
#define BTIM_AIFR_UI4_Msk                                   (0x1UL << BTIM_AIFR_UI4_Pos)
#define BTIM_AIFR_UI4                                       BTIM_AIFR_UI4_Msk
#define BTIM_AIFR_TI4_Pos                                   (3U)
#define BTIM_AIFR_TI4_Msk                                   (0x1UL << BTIM_AIFR_TI4_Pos)
#define BTIM_AIFR_TI4                                       BTIM_AIFR_TI4_Msk
#define BTIM_AIFR_UI5_Pos                                   (4U)
#define BTIM_AIFR_UI5_Msk                                   (0x1UL << BTIM_AIFR_UI5_Pos)
#define BTIM_AIFR_UI5                                       BTIM_AIFR_UI5_Msk
#define BTIM_AIFR_TI5_Pos                                   (5U)
#define BTIM_AIFR_TI5_Msk                                   (0x1UL << BTIM_AIFR_TI5_Pos)
#define BTIM_AIFR_TI5                                       BTIM_AIFR_TI5_Msk

// BTIM_AICR
#define BTIM_AICR_UI3_Pos                                   (0U)
#define BTIM_AICR_UI3_Msk                                   (0x1UL << BTIM_AICR_UI3_Pos)
#define BTIM_AICR_UI3                                       BTIM_AICR_UI3_Msk
#define BTIM_AICR_TI3_Pos                                   (1U)
#define BTIM_AICR_TI3_Msk                                   (0x1UL << BTIM_AICR_TI3_Pos)
#define BTIM_AICR_TI3                                       BTIM_AICR_TI3_Msk
#define BTIM_AICR_UI4_Pos                                   (2U)
#define BTIM_AICR_UI4_Msk                                   (0x1UL << BTIM_AICR_UI4_Pos)
#define BTIM_AICR_UI4                                       BTIM_AICR_UI4_Msk
#define BTIM_AICR_TI4_Pos                                   (3U)
#define BTIM_AICR_TI4_Msk                                   (0x1UL << BTIM_AICR_TI4_Pos)
#define BTIM_AICR_TI4                                       BTIM_AICR_TI4_Msk
#define BTIM_AICR_UI5_Pos                                   (4U)
#define BTIM_AICR_UI5_Msk                                   (0x1UL << BTIM_AICR_UI5_Pos)
#define BTIM_AICR_UI5                                       BTIM_AICR_UI5_Msk
#define BTIM_AICR_TI5_Pos                                   (5U)
#define BTIM_AICR_TI5_Msk                                   (0x1UL << BTIM_AICR_TI5_Pos)
#define BTIM_AICR_TI5                                       BTIM_AICR_TI5_Msk



//********************    Bits Define For Peripheral CTRIM    ********************//
// CTRIM_ARR
#define CTRIM_ARR_ARR_Pos                                   (0U)
#define CTRIM_ARR_ARR_Msk                                   (0xFFFFUL << CTRIM_ARR_ARR_Pos)
#define CTRIM_ARR_ARR                                       CTRIM_ARR_ARR_Msk

// CTRIM_CNT
#define CTRIM_CNT_CNT_Pos                                   (0U)
#define CTRIM_CNT_CNT_Msk                                   (0xFFFFUL << CTRIM_CNT_CNT_Pos)
#define CTRIM_CNT_CNT                                       CTRIM_CNT_CNT_Msk

// CTRIM_CR0
#define CTRIM_CR0_STEP_Pos                                  (0U)
#define CTRIM_CR0_STEP_Msk                                  (0x7UL << CTRIM_CR0_STEP_Pos)
#define CTRIM_CR0_STEP                                      CTRIM_CR0_STEP_Msk
#define CTRIM_CR0_ETRFLT_Pos                                (4U)
#define CTRIM_CR0_ETRFLT_Msk                                (0x7UL << CTRIM_CR0_ETRFLT_Pos)
#define CTRIM_CR0_ETRFLT                                    CTRIM_CR0_ETRFLT_Msk
#define CTRIM_CR0_SRC_Pos                                   (8U)
#define CTRIM_CR0_SRC_Msk                                   (0x7UL << CTRIM_CR0_SRC_Pos)
#define CTRIM_CR0_SRC                                       CTRIM_CR0_SRC_Msk

// CTRIM_CR1
#define CTRIM_CR1_EN_Pos                                    (0U)
#define CTRIM_CR1_EN_Msk                                    (0x1UL << CTRIM_CR1_EN_Pos)
#define CTRIM_CR1_EN                                        CTRIM_CR1_EN_Msk
#define CTRIM_CR1_MD_Pos                                    (1U)
#define CTRIM_CR1_MD_Msk                                    (0x3UL << CTRIM_CR1_MD_Pos)
#define CTRIM_CR1_MD                                        CTRIM_CR1_MD_Msk
#define CTRIM_CR1_AUTO_Pos                                  (3U)
#define CTRIM_CR1_AUTO_Msk                                  (0x1UL << CTRIM_CR1_AUTO_Pos)
#define CTRIM_CR1_AUTO                                      CTRIM_CR1_AUTO_Msk
#define CTRIM_CR1_PRS_Pos                                   (4U)
#define CTRIM_CR1_PRS_Msk                                   (0xFUL << CTRIM_CR1_PRS_Pos)
#define CTRIM_CR1_PRS                                       CTRIM_CR1_PRS_Msk
#define CTRIM_CR1_OST_Pos                                   (8U)
#define CTRIM_CR1_OST_Msk                                   (0x1UL << CTRIM_CR1_OST_Pos)
#define CTRIM_CR1_OST                                       CTRIM_CR1_OST_Msk

// CTRIM_IER
#define CTRIM_IER_UD_Pos                                    (0U)
#define CTRIM_IER_UD_Msk                                    (0x1UL << CTRIM_IER_UD_Pos)
#define CTRIM_IER_UD                                        CTRIM_IER_UD_Msk
#define CTRIM_IER_END_Pos                                   (1U)
#define CTRIM_IER_END_Msk                                   (0x1UL << CTRIM_IER_END_Pos)
#define CTRIM_IER_END                                       CTRIM_IER_END_Msk
#define CTRIM_IER_PS_Pos                                    (2U)
#define CTRIM_IER_PS_Msk                                    (0x1UL << CTRIM_IER_PS_Pos)
#define CTRIM_IER_PS                                        CTRIM_IER_PS_Msk
#define CTRIM_IER_MISS_Pos                                  (3U)
#define CTRIM_IER_MISS_Msk                                  (0x1UL << CTRIM_IER_MISS_Pos)
#define CTRIM_IER_MISS                                      CTRIM_IER_MISS_Msk
#define CTRIM_IER_OV_Pos                                    (4U)
#define CTRIM_IER_OV_Msk                                    (0x1UL << CTRIM_IER_OV_Pos)
#define CTRIM_IER_OV                                        CTRIM_IER_OV_Msk

// CTRIM_ISR
#define CTRIM_ISR_UD_Pos                                    (0U)
#define CTRIM_ISR_UD_Msk                                    (0x1UL << CTRIM_ISR_UD_Pos)
#define CTRIM_ISR_UD                                        CTRIM_ISR_UD_Msk
#define CTRIM_ISR_END_Pos                                   (1U)
#define CTRIM_ISR_END_Msk                                   (0x1UL << CTRIM_ISR_END_Pos)
#define CTRIM_ISR_END                                       CTRIM_ISR_END_Msk
#define CTRIM_ISR_PS_Pos                                    (2U)
#define CTRIM_ISR_PS_Msk                                    (0x1UL << CTRIM_ISR_PS_Pos)
#define CTRIM_ISR_PS                                        CTRIM_ISR_PS_Msk
#define CTRIM_ISR_MISS_Pos                                  (3U)
#define CTRIM_ISR_MISS_Msk                                  (0x1UL << CTRIM_ISR_MISS_Pos)
#define CTRIM_ISR_MISS                                      CTRIM_ISR_MISS_Msk
#define CTRIM_ISR_OV_Pos                                    (4U)
#define CTRIM_ISR_OV_Msk                                    (0x1UL << CTRIM_ISR_OV_Pos)
#define CTRIM_ISR_OV                                        CTRIM_ISR_OV_Msk
#define CTRIM_ISR_DIR_Pos                                   (5U)
#define CTRIM_ISR_DIR_Msk                                   (0x1UL << CTRIM_ISR_DIR_Pos)
#define CTRIM_ISR_DIR                                       CTRIM_ISR_DIR_Msk
#define CTRIM_ISR_OK_Pos                                    (6U)
#define CTRIM_ISR_OK_Msk                                    (0x1UL << CTRIM_ISR_OK_Pos)
#define CTRIM_ISR_OK                                        CTRIM_ISR_OK_Msk

// CTRIM_ICR
#define CTRIM_ICR_UD_Pos                                    (0U)
#define CTRIM_ICR_UD_Msk                                    (0x1UL << CTRIM_ICR_UD_Pos)
#define CTRIM_ICR_UD                                        CTRIM_ICR_UD_Msk
#define CTRIM_ICR_END_Pos                                   (1U)
#define CTRIM_ICR_END_Msk                                   (0x1UL << CTRIM_ICR_END_Pos)
#define CTRIM_ICR_END                                       CTRIM_ICR_END_Msk
#define CTRIM_ICR_PS_Pos                                    (2U)
#define CTRIM_ICR_PS_Msk                                    (0x1UL << CTRIM_ICR_PS_Pos)
#define CTRIM_ICR_PS                                        CTRIM_ICR_PS_Msk
#define CTRIM_ICR_MISS_Pos                                  (3U)
#define CTRIM_ICR_MISS_Msk                                  (0x1UL << CTRIM_ICR_MISS_Pos)
#define CTRIM_ICR_MISS                                      CTRIM_ICR_MISS_Msk
#define CTRIM_ICR_OV_Pos                                    (4U)
#define CTRIM_ICR_OV_Msk                                    (0x1UL << CTRIM_ICR_OV_Pos)
#define CTRIM_ICR_OV                                        CTRIM_ICR_OV_Msk
#define CTRIM_ICR_OK_Pos                                    (5U)
#define CTRIM_ICR_OK_Msk                                    (0x1UL << CTRIM_ICR_OK_Pos)
#define CTRIM_ICR_OK                                        CTRIM_ICR_OK_Msk

// CTRIM_FCAP
#define CTRIM_FCAP_FCAP_Pos                                 (0U)
#define CTRIM_FCAP_FCAP_Msk                                 (0xFFFFUL << CTRIM_FCAP_FCAP_Pos)
#define CTRIM_FCAP_FCAP                                     CTRIM_FCAP_FCAP_Msk

// CTRIM_TVAL
#define CTRIM_TVAL_TVAL_Pos                                 (0U)
#define CTRIM_TVAL_TVAL_Msk                                 (0xFFFFUL << CTRIM_TVAL_TVAL_Pos)
#define CTRIM_TVAL_TVAL                                     CTRIM_TVAL_TVAL_Msk

// CTRIM_FLIM
#define CTRIM_FLIM_FLIM_Pos                                 (0U)
#define CTRIM_FLIM_FLIM_Msk                                 (0xFFUL << CTRIM_FLIM_FLIM_Pos)
#define CTRIM_FLIM_FLIM                                     CTRIM_FLIM_FLIM_Msk



//********************    Bits Define For Peripheral FLASH    ********************//
// FLASH_CR
#define FLASH_CR_OP_Pos                                     (0U)
#define FLASH_CR_OP_Msk                                     (0x3UL << FLASH_CR_OP_Pos)
#define FLASH_CR_OP                                         FLASH_CR_OP_Msk
#define FLASH_CR_BUSY_Pos                                   (4U)
#define FLASH_CR_BUSY_Msk                                   (0x1UL << FLASH_CR_BUSY_Pos)
#define FLASH_CR_BUSY                                       FLASH_CR_BUSY_Msk
#define FLASH_CR_PCIE_Pos                                   (5U)
#define FLASH_CR_PCIE_Msk                                   (0x1UL << FLASH_CR_PCIE_Pos)
#define FLASH_CR_PCIE                                       FLASH_CR_PCIE_Msk
#define FLASH_CR_FLASHIE_Pos                                (6U)
#define FLASH_CR_FLASHIE_Msk                                (0x1UL << FLASH_CR_FLASHIE_Pos)
#define FLASH_CR_FLASHIE                                    FLASH_CR_FLASHIE_Msk
#define FLASH_CR_LPMODE_Pos                                 (9U)
#define FLASH_CR_LPMODE_Msk                                 (0x1UL << FLASH_CR_LPMODE_Pos)
#define FLASH_CR_LPMODE                                     FLASH_CR_LPMODE_Msk

// FLASH_IFR
#define FLASH_IFR_PC_Pos                                    (0U)
#define FLASH_IFR_PC_Msk                                    (0x1UL << FLASH_IFR_PC_Pos)
#define FLASH_IFR_PC                                        FLASH_IFR_PC_Msk
#define FLASH_IFR_FLASH_Pos                                 (1U)
#define FLASH_IFR_FLASH_Msk                                 (0x1UL << FLASH_IFR_FLASH_Pos)
#define FLASH_IFR_FLASH                                     FLASH_IFR_FLASH_Msk

// FLASH_ICLR
#define FLASH_ICLR_PC_Pos                                   (0U)
#define FLASH_ICLR_PC_Msk                                   (0x1UL << FLASH_ICLR_PC_Pos)
#define FLASH_ICLR_PC                                       FLASH_ICLR_PC_Msk
#define FLASH_ICLR_FLASH_Pos                                (1U)
#define FLASH_ICLR_FLASH_Msk                                (0x1UL << FLASH_ICLR_FLASH_Pos)
#define FLASH_ICLR_FLASH                                    FLASH_ICLR_FLASH_Msk

// FLASH_BYPASS
#define FLASH_BYPASS_BYPASS_Pos                             (0U)
#define FLASH_BYPASS_BYPASS_Msk                             (0xFFFFUL << FLASH_BYPASS_BYPASS_Pos)
#define FLASH_BYPASS_BYPASS                                 FLASH_BYPASS_BYPASS_Msk

// FLASH_SLOCK
#define FLASH_SLOCK_SLOCK_Pos                               (0U)
#define FLASH_SLOCK_SLOCK_Msk                               (0x1FFUL << FLASH_SLOCK_SLOCK_Pos)
#define FLASH_SLOCK_SLOCK                                   FLASH_SLOCK_SLOCK_Msk

// FLASH_WAIT
#define FLASH_WAIT_WAIT_Pos                                 (0U)
#define FLASH_WAIT_WAIT_Msk                                 (0x3UL << FLASH_WAIT_WAIT_Pos)
#define FLASH_WAIT_WAIT                                     FLASH_WAIT_WAIT_Msk

// FLASH_LOCKSTATE
#define FLASH_LOCKSTATE_STATE_Pos                           (0U)
#define FLASH_LOCKSTATE_STATE_Msk                           (0x3UL << FLASH_LOCKSTATE_STATE_Pos)
#define FLASH_LOCKSTATE_STATE                               FLASH_LOCKSTATE_STATE_Msk



//********************    Bits Define For Peripheral GPIO    ********************//
// GPIO_ADS
#define GPIO_ADS_PIN0_Pos                                   (0U)
#define GPIO_ADS_PIN0_Msk                                   (0x1UL << GPIO_ADS_PIN0_Pos)
#define GPIO_ADS_PIN0                                       GPIO_ADS_PIN0_Msk
#define GPIO_ADS_PIN1_Pos                                   (1U)
#define GPIO_ADS_PIN1_Msk                                   (0x1UL << GPIO_ADS_PIN1_Pos)
#define GPIO_ADS_PIN1                                       GPIO_ADS_PIN1_Msk
#define GPIO_ADS_PIN2_Pos                                   (2U)
#define GPIO_ADS_PIN2_Msk                                   (0x1UL << GPIO_ADS_PIN2_Pos)
#define GPIO_ADS_PIN2                                       GPIO_ADS_PIN2_Msk
#define GPIO_ADS_PIN3_Pos                                   (3U)
#define GPIO_ADS_PIN3_Msk                                   (0x1UL << GPIO_ADS_PIN3_Pos)
#define GPIO_ADS_PIN3                                       GPIO_ADS_PIN3_Msk
#define GPIO_ADS_PIN4_Pos                                   (4U)
#define GPIO_ADS_PIN4_Msk                                   (0x1UL << GPIO_ADS_PIN4_Pos)
#define GPIO_ADS_PIN4                                       GPIO_ADS_PIN4_Msk
#define GPIO_ADS_PIN5_Pos                                   (5U)
#define GPIO_ADS_PIN5_Msk                                   (0x1UL << GPIO_ADS_PIN5_Pos)
#define GPIO_ADS_PIN5                                       GPIO_ADS_PIN5_Msk
#define GPIO_ADS_PIN6_Pos                                   (6U)
#define GPIO_ADS_PIN6_Msk                                   (0x1UL << GPIO_ADS_PIN6_Pos)
#define GPIO_ADS_PIN6                                       GPIO_ADS_PIN6_Msk
#define GPIO_ADS_PIN7_Pos                                   (7U)
#define GPIO_ADS_PIN7_Msk                                   (0x1UL << GPIO_ADS_PIN7_Pos)
#define GPIO_ADS_PIN7                                       GPIO_ADS_PIN7_Msk

// GPIO_DIR
#define GPIO_DIR_PIN0_Pos                                   (0U)
#define GPIO_DIR_PIN0_Msk                                   (0x1UL << GPIO_DIR_PIN0_Pos)
#define GPIO_DIR_PIN0                                       GPIO_DIR_PIN0_Msk
#define GPIO_DIR_PIN1_Pos                                   (1U)
#define GPIO_DIR_PIN1_Msk                                   (0x1UL << GPIO_DIR_PIN1_Pos)
#define GPIO_DIR_PIN1                                       GPIO_DIR_PIN1_Msk
#define GPIO_DIR_PIN2_Pos                                   (2U)
#define GPIO_DIR_PIN2_Msk                                   (0x1UL << GPIO_DIR_PIN2_Pos)
#define GPIO_DIR_PIN2                                       GPIO_DIR_PIN2_Msk
#define GPIO_DIR_PIN3_Pos                                   (3U)
#define GPIO_DIR_PIN3_Msk                                   (0x1UL << GPIO_DIR_PIN3_Pos)
#define GPIO_DIR_PIN3                                       GPIO_DIR_PIN3_Msk
#define GPIO_DIR_PIN4_Pos                                   (4U)
#define GPIO_DIR_PIN4_Msk                                   (0x1UL << GPIO_DIR_PIN4_Pos)
#define GPIO_DIR_PIN4                                       GPIO_DIR_PIN4_Msk
#define GPIO_DIR_PIN5_Pos                                   (5U)
#define GPIO_DIR_PIN5_Msk                                   (0x1UL << GPIO_DIR_PIN5_Pos)
#define GPIO_DIR_PIN5                                       GPIO_DIR_PIN5_Msk
#define GPIO_DIR_PIN6_Pos                                   (6U)
#define GPIO_DIR_PIN6_Msk                                   (0x1UL << GPIO_DIR_PIN6_Pos)
#define GPIO_DIR_PIN6                                       GPIO_DIR_PIN6_Msk
#define GPIO_DIR_PIN7_Pos                                   (7U)
#define GPIO_DIR_PIN7_Msk                                   (0x1UL << GPIO_DIR_PIN7_Pos)
#define GPIO_DIR_PIN7                                       GPIO_DIR_PIN7_Msk

// GPIO_OPENDRAIN
#define GPIO_OPENDRAIN_PIN0_Pos                             (0U)
#define GPIO_OPENDRAIN_PIN0_Msk                             (0x1UL << GPIO_OPENDRAIN_PIN0_Pos)
#define GPIO_OPENDRAIN_PIN0                                 GPIO_OPENDRAIN_PIN0_Msk
#define GPIO_OPENDRAIN_PIN1_Pos                             (1U)
#define GPIO_OPENDRAIN_PIN1_Msk                             (0x1UL << GPIO_OPENDRAIN_PIN1_Pos)
#define GPIO_OPENDRAIN_PIN1                                 GPIO_OPENDRAIN_PIN1_Msk
#define GPIO_OPENDRAIN_PIN2_Pos                             (2U)
#define GPIO_OPENDRAIN_PIN2_Msk                             (0x1UL << GPIO_OPENDRAIN_PIN2_Pos)
#define GPIO_OPENDRAIN_PIN2                                 GPIO_OPENDRAIN_PIN2_Msk
#define GPIO_OPENDRAIN_PIN3_Pos                             (3U)
#define GPIO_OPENDRAIN_PIN3_Msk                             (0x1UL << GPIO_OPENDRAIN_PIN3_Pos)
#define GPIO_OPENDRAIN_PIN3                                 GPIO_OPENDRAIN_PIN3_Msk
#define GPIO_OPENDRAIN_PIN4_Pos                             (4U)
#define GPIO_OPENDRAIN_PIN4_Msk                             (0x1UL << GPIO_OPENDRAIN_PIN4_Pos)
#define GPIO_OPENDRAIN_PIN4                                 GPIO_OPENDRAIN_PIN4_Msk
#define GPIO_OPENDRAIN_PIN5_Pos                             (5U)
#define GPIO_OPENDRAIN_PIN5_Msk                             (0x1UL << GPIO_OPENDRAIN_PIN5_Pos)
#define GPIO_OPENDRAIN_PIN5                                 GPIO_OPENDRAIN_PIN5_Msk
#define GPIO_OPENDRAIN_PIN6_Pos                             (6U)
#define GPIO_OPENDRAIN_PIN6_Msk                             (0x1UL << GPIO_OPENDRAIN_PIN6_Pos)
#define GPIO_OPENDRAIN_PIN6                                 GPIO_OPENDRAIN_PIN6_Msk
#define GPIO_OPENDRAIN_PIN7_Pos                             (7U)
#define GPIO_OPENDRAIN_PIN7_Msk                             (0x1UL << GPIO_OPENDRAIN_PIN7_Pos)
#define GPIO_OPENDRAIN_PIN7                                 GPIO_OPENDRAIN_PIN7_Msk

// GPIO_PU
#define GPIO_PU_PIN0_Pos                                    (0U)
#define GPIO_PU_PIN0_Msk                                    (0x1UL << GPIO_PU_PIN0_Pos)
#define GPIO_PU_PIN0                                        GPIO_PU_PIN0_Msk
#define GPIO_PU_PIN1_Pos                                    (1U)
#define GPIO_PU_PIN1_Msk                                    (0x1UL << GPIO_PU_PIN1_Pos)
#define GPIO_PU_PIN1                                        GPIO_PU_PIN1_Msk
#define GPIO_PU_PIN2_Pos                                    (2U)
#define GPIO_PU_PIN2_Msk                                    (0x1UL << GPIO_PU_PIN2_Pos)
#define GPIO_PU_PIN2                                        GPIO_PU_PIN2_Msk
#define GPIO_PU_PIN3_Pos                                    (3U)
#define GPIO_PU_PIN3_Msk                                    (0x1UL << GPIO_PU_PIN3_Pos)
#define GPIO_PU_PIN3                                        GPIO_PU_PIN3_Msk
#define GPIO_PU_PIN4_Pos                                    (4U)
#define GPIO_PU_PIN4_Msk                                    (0x1UL << GPIO_PU_PIN4_Pos)
#define GPIO_PU_PIN4                                        GPIO_PU_PIN4_Msk
#define GPIO_PU_PIN5_Pos                                    (5U)
#define GPIO_PU_PIN5_Msk                                    (0x1UL << GPIO_PU_PIN5_Pos)
#define GPIO_PU_PIN5                                        GPIO_PU_PIN5_Msk
#define GPIO_PU_PIN6_Pos                                    (6U)
#define GPIO_PU_PIN6_Msk                                    (0x1UL << GPIO_PU_PIN6_Pos)
#define GPIO_PU_PIN6                                        GPIO_PU_PIN6_Msk
#define GPIO_PU_PIN7_Pos                                    (7U)
#define GPIO_PU_PIN7_Msk                                    (0x1UL << GPIO_PU_PIN7_Pos)
#define GPIO_PU_PIN7                                        GPIO_PU_PIN7_Msk

// GPIO_IN
#define GPIO_IN_PIN0_Pos                                    (0U)
#define GPIO_IN_PIN0_Msk                                    (0x1UL << GPIO_IN_PIN0_Pos)
#define GPIO_IN_PIN0                                        GPIO_IN_PIN0_Msk
#define GPIO_IN_PIN1_Pos                                    (1U)
#define GPIO_IN_PIN1_Msk                                    (0x1UL << GPIO_IN_PIN1_Pos)
#define GPIO_IN_PIN1                                        GPIO_IN_PIN1_Msk
#define GPIO_IN_PIN2_Pos                                    (2U)
#define GPIO_IN_PIN2_Msk                                    (0x1UL << GPIO_IN_PIN2_Pos)
#define GPIO_IN_PIN2                                        GPIO_IN_PIN2_Msk
#define GPIO_IN_PIN3_Pos                                    (3U)
#define GPIO_IN_PIN3_Msk                                    (0x1UL << GPIO_IN_PIN3_Pos)
#define GPIO_IN_PIN3                                        GPIO_IN_PIN3_Msk
#define GPIO_IN_PIN4_Pos                                    (4U)
#define GPIO_IN_PIN4_Msk                                    (0x1UL << GPIO_IN_PIN4_Pos)
#define GPIO_IN_PIN4                                        GPIO_IN_PIN4_Msk
#define GPIO_IN_PIN5_Pos                                    (5U)
#define GPIO_IN_PIN5_Msk                                    (0x1UL << GPIO_IN_PIN5_Pos)
#define GPIO_IN_PIN5                                        GPIO_IN_PIN5_Msk
#define GPIO_IN_PIN6_Pos                                    (6U)
#define GPIO_IN_PIN6_Msk                                    (0x1UL << GPIO_IN_PIN6_Pos)
#define GPIO_IN_PIN6                                        GPIO_IN_PIN6_Msk
#define GPIO_IN_PIN7_Pos                                    (7U)
#define GPIO_IN_PIN7_Msk                                    (0x1UL << GPIO_IN_PIN7_Pos)
#define GPIO_IN_PIN7                                        GPIO_IN_PIN7_Msk

// GPIO_OUT
#define GPIO_OUT_PIN0_Pos                                   (0U)
#define GPIO_OUT_PIN0_Msk                                   (0x1UL << GPIO_OUT_PIN0_Pos)
#define GPIO_OUT_PIN0                                       GPIO_OUT_PIN0_Msk
#define GPIO_OUT_PIN1_Pos                                   (1U)
#define GPIO_OUT_PIN1_Msk                                   (0x1UL << GPIO_OUT_PIN1_Pos)
#define GPIO_OUT_PIN1                                       GPIO_OUT_PIN1_Msk
#define GPIO_OUT_PIN2_Pos                                   (2U)
#define GPIO_OUT_PIN2_Msk                                   (0x1UL << GPIO_OUT_PIN2_Pos)
#define GPIO_OUT_PIN2                                       GPIO_OUT_PIN2_Msk
#define GPIO_OUT_PIN3_Pos                                   (3U)
#define GPIO_OUT_PIN3_Msk                                   (0x1UL << GPIO_OUT_PIN3_Pos)
#define GPIO_OUT_PIN3                                       GPIO_OUT_PIN3_Msk
#define GPIO_OUT_PIN4_Pos                                   (4U)
#define GPIO_OUT_PIN4_Msk                                   (0x1UL << GPIO_OUT_PIN4_Pos)
#define GPIO_OUT_PIN4                                       GPIO_OUT_PIN4_Msk
#define GPIO_OUT_PIN5_Pos                                   (5U)
#define GPIO_OUT_PIN5_Msk                                   (0x1UL << GPIO_OUT_PIN5_Pos)
#define GPIO_OUT_PIN5                                       GPIO_OUT_PIN5_Msk
#define GPIO_OUT_PIN6_Pos                                   (6U)
#define GPIO_OUT_PIN6_Msk                                   (0x1UL << GPIO_OUT_PIN6_Pos)
#define GPIO_OUT_PIN6                                       GPIO_OUT_PIN6_Msk
#define GPIO_OUT_PIN7_Pos                                   (7U)
#define GPIO_OUT_PIN7_Msk                                   (0x1UL << GPIO_OUT_PIN7_Pos)
#define GPIO_OUT_PIN7                                       GPIO_OUT_PIN7_Msk

// GPIO_BRR
#define GPIO_BRR_PIN0_Pos                                   (0U)
#define GPIO_BRR_PIN0_Msk                                   (0x1UL << GPIO_BRR_PIN0_Pos)
#define GPIO_BRR_PIN0                                       GPIO_BRR_PIN0_Msk
#define GPIO_BRR_PIN1_Pos                                   (1U)
#define GPIO_BRR_PIN1_Msk                                   (0x1UL << GPIO_BRR_PIN1_Pos)
#define GPIO_BRR_PIN1                                       GPIO_BRR_PIN1_Msk
#define GPIO_BRR_PIN2_Pos                                   (2U)
#define GPIO_BRR_PIN2_Msk                                   (0x1UL << GPIO_BRR_PIN2_Pos)
#define GPIO_BRR_PIN2                                       GPIO_BRR_PIN2_Msk
#define GPIO_BRR_PIN3_Pos                                   (3U)
#define GPIO_BRR_PIN3_Msk                                   (0x1UL << GPIO_BRR_PIN3_Pos)
#define GPIO_BRR_PIN3                                       GPIO_BRR_PIN3_Msk
#define GPIO_BRR_PIN4_Pos                                   (4U)
#define GPIO_BRR_PIN4_Msk                                   (0x1UL << GPIO_BRR_PIN4_Pos)
#define GPIO_BRR_PIN4                                       GPIO_BRR_PIN4_Msk
#define GPIO_BRR_PIN5_Pos                                   (5U)
#define GPIO_BRR_PIN5_Msk                                   (0x1UL << GPIO_BRR_PIN5_Pos)
#define GPIO_BRR_PIN5                                       GPIO_BRR_PIN5_Msk
#define GPIO_BRR_PIN6_Pos                                   (6U)
#define GPIO_BRR_PIN6_Msk                                   (0x1UL << GPIO_BRR_PIN6_Pos)
#define GPIO_BRR_PIN6                                       GPIO_BRR_PIN6_Msk
#define GPIO_BRR_PIN7_Pos                                   (7U)
#define GPIO_BRR_PIN7_Msk                                   (0x1UL << GPIO_BRR_PIN7_Pos)
#define GPIO_BRR_PIN7                                       GPIO_BRR_PIN7_Msk

// GPIO_BSRR
#define GPIO_BSRR_BSPIN0_Pos                                (0U)
#define GPIO_BSRR_BSPIN0_Msk                                (0x1UL << GPIO_BSRR_BSPIN0_Pos)
#define GPIO_BSRR_BSPIN0                                    GPIO_BSRR_BSPIN0_Msk
#define GPIO_BSRR_BSPIN1_Pos                                (1U)
#define GPIO_BSRR_BSPIN1_Msk                                (0x1UL << GPIO_BSRR_BSPIN1_Pos)
#define GPIO_BSRR_BSPIN1                                    GPIO_BSRR_BSPIN1_Msk
#define GPIO_BSRR_BSPIN2_Pos                                (2U)
#define GPIO_BSRR_BSPIN2_Msk                                (0x1UL << GPIO_BSRR_BSPIN2_Pos)
#define GPIO_BSRR_BSPIN2                                    GPIO_BSRR_BSPIN2_Msk
#define GPIO_BSRR_BSPIN3_Pos                                (3U)
#define GPIO_BSRR_BSPIN3_Msk                                (0x1UL << GPIO_BSRR_BSPIN3_Pos)
#define GPIO_BSRR_BSPIN3                                    GPIO_BSRR_BSPIN3_Msk
#define GPIO_BSRR_BSPIN4_Pos                                (4U)
#define GPIO_BSRR_BSPIN4_Msk                                (0x1UL << GPIO_BSRR_BSPIN4_Pos)
#define GPIO_BSRR_BSPIN4                                    GPIO_BSRR_BSPIN4_Msk
#define GPIO_BSRR_BSPIN5_Pos                                (5U)
#define GPIO_BSRR_BSPIN5_Msk                                (0x1UL << GPIO_BSRR_BSPIN5_Pos)
#define GPIO_BSRR_BSPIN5                                    GPIO_BSRR_BSPIN5_Msk
#define GPIO_BSRR_BSPIN6_Pos                                (6U)
#define GPIO_BSRR_BSPIN6_Msk                                (0x1UL << GPIO_BSRR_BSPIN6_Pos)
#define GPIO_BSRR_BSPIN6                                    GPIO_BSRR_BSPIN6_Msk
#define GPIO_BSRR_BSPIN7_Pos                                (7U)
#define GPIO_BSRR_BSPIN7_Msk                                (0x1UL << GPIO_BSRR_BSPIN7_Pos)
#define GPIO_BSRR_BSPIN7                                    GPIO_BSRR_BSPIN7_Msk
#define GPIO_BSRR_BRPIN0_Pos                                (16U)
#define GPIO_BSRR_BRPIN0_Msk                                (0x1UL << GPIO_BSRR_BRPIN0_Pos)
#define GPIO_BSRR_BRPIN0                                    GPIO_BSRR_BRPIN0_Msk
#define GPIO_BSRR_BRPIN1_Pos                                (17U)
#define GPIO_BSRR_BRPIN1_Msk                                (0x1UL << GPIO_BSRR_BRPIN1_Pos)
#define GPIO_BSRR_BRPIN1                                    GPIO_BSRR_BRPIN1_Msk
#define GPIO_BSRR_BRPIN2_Pos                                (18U)
#define GPIO_BSRR_BRPIN2_Msk                                (0x1UL << GPIO_BSRR_BRPIN2_Pos)
#define GPIO_BSRR_BRPIN2                                    GPIO_BSRR_BRPIN2_Msk
#define GPIO_BSRR_BRPIN3_Pos                                (19U)
#define GPIO_BSRR_BRPIN3_Msk                                (0x1UL << GPIO_BSRR_BRPIN3_Pos)
#define GPIO_BSRR_BRPIN3                                    GPIO_BSRR_BRPIN3_Msk
#define GPIO_BSRR_BRPIN4_Pos                                (20U)
#define GPIO_BSRR_BRPIN4_Msk                                (0x1UL << GPIO_BSRR_BRPIN4_Pos)
#define GPIO_BSRR_BRPIN4                                    GPIO_BSRR_BRPIN4_Msk
#define GPIO_BSRR_BRPIN5_Pos                                (21U)
#define GPIO_BSRR_BRPIN5_Msk                                (0x1UL << GPIO_BSRR_BRPIN5_Pos)
#define GPIO_BSRR_BRPIN5                                    GPIO_BSRR_BRPIN5_Msk
#define GPIO_BSRR_BRPIN6_Pos                                (22U)
#define GPIO_BSRR_BRPIN6_Msk                                (0x1UL << GPIO_BSRR_BRPIN6_Pos)
#define GPIO_BSRR_BRPIN6                                    GPIO_BSRR_BRPIN6_Msk
#define GPIO_BSRR_BRPIN7_Pos                                (23U)
#define GPIO_BSRR_BRPIN7_Msk                                (0x1UL << GPIO_BSRR_BRPIN7_Pos)
#define GPIO_BSRR_BRPIN7                                    GPIO_BSRR_BRPIN7_Msk

// GPIO_AFRL
#define GPIO_AFRL_AFSEL0_Pos                                (0U)
#define GPIO_AFRL_AFSEL0_Msk                                (0xFUL << GPIO_AFRL_AFSEL0_Pos)
#define GPIO_AFRL_AFSEL0                                    GPIO_AFRL_AFSEL0_Msk
#define GPIO_AFRL_AFSEL1_Pos                                (4U)
#define GPIO_AFRL_AFSEL1_Msk                                (0xFUL << GPIO_AFRL_AFSEL1_Pos)
#define GPIO_AFRL_AFSEL1                                    GPIO_AFRL_AFSEL1_Msk
#define GPIO_AFRL_AFSEL2_Pos                                (8U)
#define GPIO_AFRL_AFSEL2_Msk                                (0xFUL << GPIO_AFRL_AFSEL2_Pos)
#define GPIO_AFRL_AFSEL2                                    GPIO_AFRL_AFSEL2_Msk
#define GPIO_AFRL_AFSEL3_Pos                                (12U)
#define GPIO_AFRL_AFSEL3_Msk                                (0xFUL << GPIO_AFRL_AFSEL3_Pos)
#define GPIO_AFRL_AFSEL3                                    GPIO_AFRL_AFSEL3_Msk
#define GPIO_AFRL_AFSEL4_Pos                                (16U)
#define GPIO_AFRL_AFSEL4_Msk                                (0xFUL << GPIO_AFRL_AFSEL4_Pos)
#define GPIO_AFRL_AFSEL4                                    GPIO_AFRL_AFSEL4_Msk
#define GPIO_AFRL_AFSEL5_Pos                                (20U)
#define GPIO_AFRL_AFSEL5_Msk                                (0xFUL << GPIO_AFRL_AFSEL5_Pos)
#define GPIO_AFRL_AFSEL5                                    GPIO_AFRL_AFSEL5_Msk
#define GPIO_AFRL_AFSEL6_Pos                                (24U)
#define GPIO_AFRL_AFSEL6_Msk                                (0xFUL << GPIO_AFRL_AFSEL6_Pos)
#define GPIO_AFRL_AFSEL6                                    GPIO_AFRL_AFSEL6_Msk
#define GPIO_AFRL_AFSEL7_Pos                                (28U)
#define GPIO_AFRL_AFSEL7_Msk                                (0xFUL << GPIO_AFRL_AFSEL7_Pos)
#define GPIO_AFRL_AFSEL7                                    GPIO_AFRL_AFSEL7_Msk

// GPIO_HIGHIE
#define GPIO_HIGHIE_PIN0_Pos                                (0U)
#define GPIO_HIGHIE_PIN0_Msk                                (0x1UL << GPIO_HIGHIE_PIN0_Pos)
#define GPIO_HIGHIE_PIN0                                    GPIO_HIGHIE_PIN0_Msk
#define GPIO_HIGHIE_PIN1_Pos                                (1U)
#define GPIO_HIGHIE_PIN1_Msk                                (0x1UL << GPIO_HIGHIE_PIN1_Pos)
#define GPIO_HIGHIE_PIN1                                    GPIO_HIGHIE_PIN1_Msk
#define GPIO_HIGHIE_PIN2_Pos                                (2U)
#define GPIO_HIGHIE_PIN2_Msk                                (0x1UL << GPIO_HIGHIE_PIN2_Pos)
#define GPIO_HIGHIE_PIN2                                    GPIO_HIGHIE_PIN2_Msk
#define GPIO_HIGHIE_PIN3_Pos                                (3U)
#define GPIO_HIGHIE_PIN3_Msk                                (0x1UL << GPIO_HIGHIE_PIN3_Pos)
#define GPIO_HIGHIE_PIN3                                    GPIO_HIGHIE_PIN3_Msk
#define GPIO_HIGHIE_PIN4_Pos                                (4U)
#define GPIO_HIGHIE_PIN4_Msk                                (0x1UL << GPIO_HIGHIE_PIN4_Pos)
#define GPIO_HIGHIE_PIN4                                    GPIO_HIGHIE_PIN4_Msk
#define GPIO_HIGHIE_PIN5_Pos                                (5U)
#define GPIO_HIGHIE_PIN5_Msk                                (0x1UL << GPIO_HIGHIE_PIN5_Pos)
#define GPIO_HIGHIE_PIN5                                    GPIO_HIGHIE_PIN5_Msk
#define GPIO_HIGHIE_PIN6_Pos                                (6U)
#define GPIO_HIGHIE_PIN6_Msk                                (0x1UL << GPIO_HIGHIE_PIN6_Pos)
#define GPIO_HIGHIE_PIN6                                    GPIO_HIGHIE_PIN6_Msk
#define GPIO_HIGHIE_PIN7_Pos                                (7U)
#define GPIO_HIGHIE_PIN7_Msk                                (0x1UL << GPIO_HIGHIE_PIN7_Pos)
#define GPIO_HIGHIE_PIN7                                    GPIO_HIGHIE_PIN7_Msk

// GPIO_LOWIE
#define GPIO_LOWIE_PIN0_Pos                                 (0U)
#define GPIO_LOWIE_PIN0_Msk                                 (0x1UL << GPIO_LOWIE_PIN0_Pos)
#define GPIO_LOWIE_PIN0                                     GPIO_LOWIE_PIN0_Msk
#define GPIO_LOWIE_PIN1_Pos                                 (1U)
#define GPIO_LOWIE_PIN1_Msk                                 (0x1UL << GPIO_LOWIE_PIN1_Pos)
#define GPIO_LOWIE_PIN1                                     GPIO_LOWIE_PIN1_Msk
#define GPIO_LOWIE_PIN2_Pos                                 (2U)
#define GPIO_LOWIE_PIN2_Msk                                 (0x1UL << GPIO_LOWIE_PIN2_Pos)
#define GPIO_LOWIE_PIN2                                     GPIO_LOWIE_PIN2_Msk
#define GPIO_LOWIE_PIN3_Pos                                 (3U)
#define GPIO_LOWIE_PIN3_Msk                                 (0x1UL << GPIO_LOWIE_PIN3_Pos)
#define GPIO_LOWIE_PIN3                                     GPIO_LOWIE_PIN3_Msk
#define GPIO_LOWIE_PIN4_Pos                                 (4U)
#define GPIO_LOWIE_PIN4_Msk                                 (0x1UL << GPIO_LOWIE_PIN4_Pos)
#define GPIO_LOWIE_PIN4                                     GPIO_LOWIE_PIN4_Msk
#define GPIO_LOWIE_PIN5_Pos                                 (5U)
#define GPIO_LOWIE_PIN5_Msk                                 (0x1UL << GPIO_LOWIE_PIN5_Pos)
#define GPIO_LOWIE_PIN5                                     GPIO_LOWIE_PIN5_Msk
#define GPIO_LOWIE_PIN6_Pos                                 (6U)
#define GPIO_LOWIE_PIN6_Msk                                 (0x1UL << GPIO_LOWIE_PIN6_Pos)
#define GPIO_LOWIE_PIN6                                     GPIO_LOWIE_PIN6_Msk
#define GPIO_LOWIE_PIN7_Pos                                 (7U)
#define GPIO_LOWIE_PIN7_Msk                                 (0x1UL << GPIO_LOWIE_PIN7_Pos)
#define GPIO_LOWIE_PIN7                                     GPIO_LOWIE_PIN7_Msk

// GPIO_RISEIE
#define GPIO_RISEIE_PIN0_Pos                                (0U)
#define GPIO_RISEIE_PIN0_Msk                                (0x1UL << GPIO_RISEIE_PIN0_Pos)
#define GPIO_RISEIE_PIN0                                    GPIO_RISEIE_PIN0_Msk
#define GPIO_RISEIE_PIN1_Pos                                (1U)
#define GPIO_RISEIE_PIN1_Msk                                (0x1UL << GPIO_RISEIE_PIN1_Pos)
#define GPIO_RISEIE_PIN1                                    GPIO_RISEIE_PIN1_Msk
#define GPIO_RISEIE_PIN2_Pos                                (2U)
#define GPIO_RISEIE_PIN2_Msk                                (0x1UL << GPIO_RISEIE_PIN2_Pos)
#define GPIO_RISEIE_PIN2                                    GPIO_RISEIE_PIN2_Msk
#define GPIO_RISEIE_PIN3_Pos                                (3U)
#define GPIO_RISEIE_PIN3_Msk                                (0x1UL << GPIO_RISEIE_PIN3_Pos)
#define GPIO_RISEIE_PIN3                                    GPIO_RISEIE_PIN3_Msk
#define GPIO_RISEIE_PIN4_Pos                                (4U)
#define GPIO_RISEIE_PIN4_Msk                                (0x1UL << GPIO_RISEIE_PIN4_Pos)
#define GPIO_RISEIE_PIN4                                    GPIO_RISEIE_PIN4_Msk
#define GPIO_RISEIE_PIN5_Pos                                (5U)
#define GPIO_RISEIE_PIN5_Msk                                (0x1UL << GPIO_RISEIE_PIN5_Pos)
#define GPIO_RISEIE_PIN5                                    GPIO_RISEIE_PIN5_Msk
#define GPIO_RISEIE_PIN6_Pos                                (6U)
#define GPIO_RISEIE_PIN6_Msk                                (0x1UL << GPIO_RISEIE_PIN6_Pos)
#define GPIO_RISEIE_PIN6                                    GPIO_RISEIE_PIN6_Msk
#define GPIO_RISEIE_PIN7_Pos                                (7U)
#define GPIO_RISEIE_PIN7_Msk                                (0x1UL << GPIO_RISEIE_PIN7_Pos)
#define GPIO_RISEIE_PIN7                                    GPIO_RISEIE_PIN7_Msk

// GPIO_FALLIE
#define GPIO_FALLIE_PIN0_Pos                                (0U)
#define GPIO_FALLIE_PIN0_Msk                                (0x1UL << GPIO_FALLIE_PIN0_Pos)
#define GPIO_FALLIE_PIN0                                    GPIO_FALLIE_PIN0_Msk
#define GPIO_FALLIE_PIN1_Pos                                (1U)
#define GPIO_FALLIE_PIN1_Msk                                (0x1UL << GPIO_FALLIE_PIN1_Pos)
#define GPIO_FALLIE_PIN1                                    GPIO_FALLIE_PIN1_Msk
#define GPIO_FALLIE_PIN2_Pos                                (2U)
#define GPIO_FALLIE_PIN2_Msk                                (0x1UL << GPIO_FALLIE_PIN2_Pos)
#define GPIO_FALLIE_PIN2                                    GPIO_FALLIE_PIN2_Msk
#define GPIO_FALLIE_PIN3_Pos                                (3U)
#define GPIO_FALLIE_PIN3_Msk                                (0x1UL << GPIO_FALLIE_PIN3_Pos)
#define GPIO_FALLIE_PIN3                                    GPIO_FALLIE_PIN3_Msk
#define GPIO_FALLIE_PIN4_Pos                                (4U)
#define GPIO_FALLIE_PIN4_Msk                                (0x1UL << GPIO_FALLIE_PIN4_Pos)
#define GPIO_FALLIE_PIN4                                    GPIO_FALLIE_PIN4_Msk
#define GPIO_FALLIE_PIN5_Pos                                (5U)
#define GPIO_FALLIE_PIN5_Msk                                (0x1UL << GPIO_FALLIE_PIN5_Pos)
#define GPIO_FALLIE_PIN5                                    GPIO_FALLIE_PIN5_Msk
#define GPIO_FALLIE_PIN6_Pos                                (6U)
#define GPIO_FALLIE_PIN6_Msk                                (0x1UL << GPIO_FALLIE_PIN6_Pos)
#define GPIO_FALLIE_PIN6                                    GPIO_FALLIE_PIN6_Msk
#define GPIO_FALLIE_PIN7_Pos                                (7U)
#define GPIO_FALLIE_PIN7_Msk                                (0x1UL << GPIO_FALLIE_PIN7_Pos)
#define GPIO_FALLIE_PIN7                                    GPIO_FALLIE_PIN7_Msk

// GPIO_IFR
#define GPIO_IFR_PIN0_Pos                                   (0U)
#define GPIO_IFR_PIN0_Msk                                   (0x1UL << GPIO_IFR_PIN0_Pos)
#define GPIO_IFR_PIN0                                       GPIO_IFR_PIN0_Msk
#define GPIO_IFR_PIN1_Pos                                   (1U)
#define GPIO_IFR_PIN1_Msk                                   (0x1UL << GPIO_IFR_PIN1_Pos)
#define GPIO_IFR_PIN1                                       GPIO_IFR_PIN1_Msk
#define GPIO_IFR_PIN2_Pos                                   (2U)
#define GPIO_IFR_PIN2_Msk                                   (0x1UL << GPIO_IFR_PIN2_Pos)
#define GPIO_IFR_PIN2                                       GPIO_IFR_PIN2_Msk
#define GPIO_IFR_PIN3_Pos                                   (3U)
#define GPIO_IFR_PIN3_Msk                                   (0x1UL << GPIO_IFR_PIN3_Pos)
#define GPIO_IFR_PIN3                                       GPIO_IFR_PIN3_Msk
#define GPIO_IFR_PIN4_Pos                                   (4U)
#define GPIO_IFR_PIN4_Msk                                   (0x1UL << GPIO_IFR_PIN4_Pos)
#define GPIO_IFR_PIN4                                       GPIO_IFR_PIN4_Msk
#define GPIO_IFR_PIN5_Pos                                   (5U)
#define GPIO_IFR_PIN5_Msk                                   (0x1UL << GPIO_IFR_PIN5_Pos)
#define GPIO_IFR_PIN5                                       GPIO_IFR_PIN5_Msk
#define GPIO_IFR_PIN6_Pos                                   (6U)
#define GPIO_IFR_PIN6_Msk                                   (0x1UL << GPIO_IFR_PIN6_Pos)
#define GPIO_IFR_PIN6                                       GPIO_IFR_PIN6_Msk
#define GPIO_IFR_PIN7_Pos                                   (7U)
#define GPIO_IFR_PIN7_Msk                                   (0x1UL << GPIO_IFR_PIN7_Pos)
#define GPIO_IFR_PIN7                                       GPIO_IFR_PIN7_Msk

// GPIO_ICR
#define GPIO_ICR_PIN0_Pos                                   (0U)
#define GPIO_ICR_PIN0_Msk                                   (0x1UL << GPIO_ICR_PIN0_Pos)
#define GPIO_ICR_PIN0                                       GPIO_ICR_PIN0_Msk
#define GPIO_ICR_PIN1_Pos                                   (1U)
#define GPIO_ICR_PIN1_Msk                                   (0x1UL << GPIO_ICR_PIN1_Pos)
#define GPIO_ICR_PIN1                                       GPIO_ICR_PIN1_Msk
#define GPIO_ICR_PIN2_Pos                                   (2U)
#define GPIO_ICR_PIN2_Msk                                   (0x1UL << GPIO_ICR_PIN2_Pos)
#define GPIO_ICR_PIN2                                       GPIO_ICR_PIN2_Msk
#define GPIO_ICR_PIN3_Pos                                   (3U)
#define GPIO_ICR_PIN3_Msk                                   (0x1UL << GPIO_ICR_PIN3_Pos)
#define GPIO_ICR_PIN3                                       GPIO_ICR_PIN3_Msk
#define GPIO_ICR_PIN4_Pos                                   (4U)
#define GPIO_ICR_PIN4_Msk                                   (0x1UL << GPIO_ICR_PIN4_Pos)
#define GPIO_ICR_PIN4                                       GPIO_ICR_PIN4_Msk
#define GPIO_ICR_PIN5_Pos                                   (5U)
#define GPIO_ICR_PIN5_Msk                                   (0x1UL << GPIO_ICR_PIN5_Pos)
#define GPIO_ICR_PIN5                                       GPIO_ICR_PIN5_Msk
#define GPIO_ICR_PIN6_Pos                                   (6U)
#define GPIO_ICR_PIN6_Msk                                   (0x1UL << GPIO_ICR_PIN6_Pos)
#define GPIO_ICR_PIN6                                       GPIO_ICR_PIN6_Msk
#define GPIO_ICR_PIN7_Pos                                   (7U)
#define GPIO_ICR_PIN7_Msk                                   (0x1UL << GPIO_ICR_PIN7_Pos)
#define GPIO_ICR_PIN7                                       GPIO_ICR_PIN7_Msk



//********************    Bits Define For Peripheral GPIOAUX    ********************//
// GPIOAUX_CR1
#define GPIOAUX_CR1_TCLKSRC_Pos                             (0U)
#define GPIOAUX_CR1_TCLKSRC_Msk                             (0x3UL << GPIOAUX_CR1_TCLKSRC_Pos)
#define GPIOAUX_CR1_TCLKSRC                                 GPIOAUX_CR1_TCLKSRC_Msk
#define GPIOAUX_CR1_TCLKDIV_Pos                             (3U)
#define GPIOAUX_CR1_TCLKDIV_Msk                             (0x3UL << GPIOAUX_CR1_TCLKDIV_Pos)
#define GPIOAUX_CR1_TCLKDIV                                 GPIOAUX_CR1_TCLKDIV_Msk

// GPIOAUX_CR4
#define GPIOAUX_CR4_ATIM3CH0A_Pos                           (4U)
#define GPIOAUX_CR4_ATIM3CH0A_Msk                           (0x3UL << GPIOAUX_CR4_ATIM3CH0A_Pos)
#define GPIOAUX_CR4_ATIM3CH0A                               GPIOAUX_CR4_ATIM3CH0A_Msk
#define GPIOAUX_CR4_GTIMCH1_Pos                             (8U)
#define GPIOAUX_CR4_GTIMCH1_Msk                             (0x3UL << GPIOAUX_CR4_GTIMCH1_Pos)
#define GPIOAUX_CR4_GTIMCH1                                 GPIOAUX_CR4_GTIMCH1_Msk



//********************    Bits Define For Peripheral GTIM    ********************//
// GTIM_ARR
#define GTIM_ARR_ARR_Pos                                    (0U)
#define GTIM_ARR_ARR_Msk                                    (0xFFFFUL << GTIM_ARR_ARR_Pos)
#define GTIM_ARR_ARR                                        GTIM_ARR_ARR_Msk

// GTIM_CNT
#define GTIM_CNT_CNT_Pos                                    (0U)
#define GTIM_CNT_CNT_Msk                                    (0xFFFFUL << GTIM_CNT_CNT_Pos)
#define GTIM_CNT_CNT                                        GTIM_CNT_CNT_Msk

// GTIM_CMMR
#define GTIM_CMMR_CC0M_Pos                                  (0U)
#define GTIM_CMMR_CC0M_Msk                                  (0x7UL << GTIM_CMMR_CC0M_Pos)
#define GTIM_CMMR_CC0M                                      GTIM_CMMR_CC0M_Msk
#define GTIM_CMMR_CC1M_Pos                                  (4U)
#define GTIM_CMMR_CC1M_Msk                                  (0x7UL << GTIM_CMMR_CC1M_Pos)
#define GTIM_CMMR_CC1M                                      GTIM_CMMR_CC1M_Msk
#define GTIM_CMMR_CC2M_Pos                                  (8U)
#define GTIM_CMMR_CC2M_Msk                                  (0x7UL << GTIM_CMMR_CC2M_Pos)
#define GTIM_CMMR_CC2M                                      GTIM_CMMR_CC2M_Msk
#define GTIM_CMMR_CC3M_Pos                                  (12U)
#define GTIM_CMMR_CC3M_Msk                                  (0x7UL << GTIM_CMMR_CC3M_Pos)
#define GTIM_CMMR_CC3M                                      GTIM_CMMR_CC3M_Msk

// GTIM_CR1
#define GTIM_CR1_ETRFLT_Pos                                 (4U)
#define GTIM_CR1_ETRFLT_Msk                                 (0x7UL << GTIM_CR1_ETRFLT_Pos)
#define GTIM_CR1_ETRFLT                                     GTIM_CR1_ETRFLT_Msk

// GTIM_CR0
#define GTIM_CR0_CEN_Pos                                    (0U)
#define GTIM_CR0_CEN_Msk                                    (0x1UL << GTIM_CR0_CEN_Pos)
#define GTIM_CR0_CEN                                        GTIM_CR0_CEN_Msk
#define GTIM_CR0_MD_Pos                                     (1U)
#define GTIM_CR0_MD_Msk                                     (0x3UL << GTIM_CR0_MD_Pos)
#define GTIM_CR0_MD                                         GTIM_CR0_MD_Msk
#define GTIM_CR0_TOGEN_Pos                                  (3U)
#define GTIM_CR0_TOGEN_Msk                                  (0x1UL << GTIM_CR0_TOGEN_Pos)
#define GTIM_CR0_TOGEN                                      GTIM_CR0_TOGEN_Msk
#define GTIM_CR0_PRS_Pos                                    (4U)
#define GTIM_CR0_PRS_Msk                                    (0xFUL << GTIM_CR0_PRS_Pos)
#define GTIM_CR0_PRS                                        GTIM_CR0_PRS_Msk
#define GTIM_CR0_OST_Pos                                    (8U)
#define GTIM_CR0_OST_Msk                                    (0x1UL << GTIM_CR0_OST_Pos)
#define GTIM_CR0_OST                                        GTIM_CR0_OST_Msk
#define GTIM_CR0_TRS_Pos                                    (9U)
#define GTIM_CR0_TRS_Msk                                    (0x3UL << GTIM_CR0_TRS_Pos)
#define GTIM_CR0_TRS                                        GTIM_CR0_TRS_Msk
#define GTIM_CR0_ETP_Pos                                    (11U)
#define GTIM_CR0_ETP_Msk                                    (0x1UL << GTIM_CR0_ETP_Pos)
#define GTIM_CR0_ETP                                        GTIM_CR0_ETP_Msk

// GTIM_IER
#define GTIM_IER_UI_Pos                                     (0U)
#define GTIM_IER_UI_Msk                                     (0x1UL << GTIM_IER_UI_Pos)
#define GTIM_IER_UI                                         GTIM_IER_UI_Msk
#define GTIM_IER_TI_Pos                                     (1U)
#define GTIM_IER_TI_Msk                                     (0x1UL << GTIM_IER_TI_Pos)
#define GTIM_IER_TI                                         GTIM_IER_TI_Msk
#define GTIM_IER_CC0_Pos                                    (2U)
#define GTIM_IER_CC0_Msk                                    (0x1UL << GTIM_IER_CC0_Pos)
#define GTIM_IER_CC0                                        GTIM_IER_CC0_Msk
#define GTIM_IER_CC1_Pos                                    (3U)
#define GTIM_IER_CC1_Msk                                    (0x1UL << GTIM_IER_CC1_Pos)
#define GTIM_IER_CC1                                        GTIM_IER_CC1_Msk
#define GTIM_IER_CC2_Pos                                    (4U)
#define GTIM_IER_CC2_Msk                                    (0x1UL << GTIM_IER_CC2_Pos)
#define GTIM_IER_CC2                                        GTIM_IER_CC2_Msk
#define GTIM_IER_CC3_Pos                                    (5U)
#define GTIM_IER_CC3_Msk                                    (0x1UL << GTIM_IER_CC3_Pos)
#define GTIM_IER_CC3                                        GTIM_IER_CC3_Msk

// GTIM_IFR
#define GTIM_IFR_UI_Pos                                     (0U)
#define GTIM_IFR_UI_Msk                                     (0x1UL << GTIM_IFR_UI_Pos)
#define GTIM_IFR_UI                                         GTIM_IFR_UI_Msk
#define GTIM_IFR_TI_Pos                                     (1U)
#define GTIM_IFR_TI_Msk                                     (0x1UL << GTIM_IFR_TI_Pos)
#define GTIM_IFR_TI                                         GTIM_IFR_TI_Msk
#define GTIM_IFR_CC0_Pos                                    (2U)
#define GTIM_IFR_CC0_Msk                                    (0x1UL << GTIM_IFR_CC0_Pos)
#define GTIM_IFR_CC0                                        GTIM_IFR_CC0_Msk
#define GTIM_IFR_CC1_Pos                                    (3U)
#define GTIM_IFR_CC1_Msk                                    (0x1UL << GTIM_IFR_CC1_Pos)
#define GTIM_IFR_CC1                                        GTIM_IFR_CC1_Msk
#define GTIM_IFR_CC2_Pos                                    (4U)
#define GTIM_IFR_CC2_Msk                                    (0x1UL << GTIM_IFR_CC2_Pos)
#define GTIM_IFR_CC2                                        GTIM_IFR_CC2_Msk
#define GTIM_IFR_CC3_Pos                                    (5U)
#define GTIM_IFR_CC3_Msk                                    (0x1UL << GTIM_IFR_CC3_Pos)
#define GTIM_IFR_CC3                                        GTIM_IFR_CC3_Msk

// GTIM_ICR
#define GTIM_ICR_UI_Pos                                     (0U)
#define GTIM_ICR_UI_Msk                                     (0x1UL << GTIM_ICR_UI_Pos)
#define GTIM_ICR_UI                                         GTIM_ICR_UI_Msk
#define GTIM_ICR_TI_Pos                                     (1U)
#define GTIM_ICR_TI_Msk                                     (0x1UL << GTIM_ICR_TI_Pos)
#define GTIM_ICR_TI                                         GTIM_ICR_TI_Msk
#define GTIM_ICR_CC0_Pos                                    (2U)
#define GTIM_ICR_CC0_Msk                                    (0x1UL << GTIM_ICR_CC0_Pos)
#define GTIM_ICR_CC0                                        GTIM_ICR_CC0_Msk
#define GTIM_ICR_CC1_Pos                                    (3U)
#define GTIM_ICR_CC1_Msk                                    (0x1UL << GTIM_ICR_CC1_Pos)
#define GTIM_ICR_CC1                                        GTIM_ICR_CC1_Msk
#define GTIM_ICR_CC2_Pos                                    (4U)
#define GTIM_ICR_CC2_Msk                                    (0x1UL << GTIM_ICR_CC2_Pos)
#define GTIM_ICR_CC2                                        GTIM_ICR_CC2_Msk
#define GTIM_ICR_CC3_Pos                                    (5U)
#define GTIM_ICR_CC3_Msk                                    (0x1UL << GTIM_ICR_CC3_Pos)
#define GTIM_ICR_CC3                                        GTIM_ICR_CC3_Msk

// GTIM_CCR0
#define GTIM_CCR0_CCR_Pos                                   (0U)
#define GTIM_CCR0_CCR_Msk                                   (0xFFFFUL << GTIM_CCR0_CCR_Pos)
#define GTIM_CCR0_CCR                                       GTIM_CCR0_CCR_Msk

// GTIM_CCR1
#define GTIM_CCR1_CCR_Pos                                   (0U)
#define GTIM_CCR1_CCR_Msk                                   (0xFFFFUL << GTIM_CCR1_CCR_Pos)
#define GTIM_CCR1_CCR                                       GTIM_CCR1_CCR_Msk

// GTIM_CCR2
#define GTIM_CCR2_CCR_Pos                                   (0U)
#define GTIM_CCR2_CCR_Msk                                   (0xFFFFUL << GTIM_CCR2_CCR_Pos)
#define GTIM_CCR2_CCR                                       GTIM_CCR2_CCR_Msk

// GTIM_CCR3
#define GTIM_CCR3_CCR_Pos                                   (0U)
#define GTIM_CCR3_CCR_Msk                                   (0xFFFFUL << GTIM_CCR3_CCR_Pos)
#define GTIM_CCR3_CCR                                       GTIM_CCR3_CCR_Msk



//********************    Bits Define For Peripheral I2C    ********************//
// I2C_BRREN
#define I2C_BRREN_EN_Pos                                    (0U)
#define I2C_BRREN_EN_Msk                                    (0x1UL << I2C_BRREN_EN_Pos)
#define I2C_BRREN_EN                                        I2C_BRREN_EN_Msk

// I2C_BRR
#define I2C_BRR_BRR_Pos                                     (0U)
#define I2C_BRR_BRR_Msk                                     (0xFFUL << I2C_BRR_BRR_Pos)
#define I2C_BRR_BRR                                         I2C_BRR_BRR_Msk

// I2C_CR
#define I2C_CR_FLT_Pos                                      (0U)
#define I2C_CR_FLT_Msk                                      (0x1UL << I2C_CR_FLT_Pos)
#define I2C_CR_FLT                                          I2C_CR_FLT_Msk
#define I2C_CR_AA_Pos                                       (2U)
#define I2C_CR_AA_Msk                                       (0x1UL << I2C_CR_AA_Pos)
#define I2C_CR_AA                                           I2C_CR_AA_Msk
#define I2C_CR_SI_Pos                                       (3U)
#define I2C_CR_SI_Msk                                       (0x1UL << I2C_CR_SI_Pos)
#define I2C_CR_SI                                           I2C_CR_SI_Msk
#define I2C_CR_STO_Pos                                      (4U)
#define I2C_CR_STO_Msk                                      (0x1UL << I2C_CR_STO_Pos)
#define I2C_CR_STO                                          I2C_CR_STO_Msk
#define I2C_CR_STA_Pos                                      (5U)
#define I2C_CR_STA_Msk                                      (0x1UL << I2C_CR_STA_Pos)
#define I2C_CR_STA                                          I2C_CR_STA_Msk
#define I2C_CR_EN_Pos                                       (6U)
#define I2C_CR_EN_Msk                                       (0x1UL << I2C_CR_EN_Pos)
#define I2C_CR_EN                                           I2C_CR_EN_Msk

// I2C_DR
#define I2C_DR_DR_Pos                                       (0U)
#define I2C_DR_DR_Msk                                       (0xFFUL << I2C_DR_DR_Pos)
#define I2C_DR_DR                                           I2C_DR_DR_Msk

// I2C_ADDR0
#define I2C_ADDR0_GC_Pos                                    (0U)
#define I2C_ADDR0_GC_Msk                                    (0x1UL << I2C_ADDR0_GC_Pos)
#define I2C_ADDR0_GC                                        I2C_ADDR0_GC_Msk
#define I2C_ADDR0_ADDR0_Pos                                 (1U)
#define I2C_ADDR0_ADDR0_Msk                                 (0x7FUL << I2C_ADDR0_ADDR0_Pos)
#define I2C_ADDR0_ADDR0                                     I2C_ADDR0_ADDR0_Msk

// I2C_STAT
#define I2C_STAT_STAT_Pos                                   (0U)
#define I2C_STAT_STAT_Msk                                   (0xFFUL << I2C_STAT_STAT_Pos)
#define I2C_STAT_STAT                                       I2C_STAT_STAT_Msk

// I2C_ADDR1
#define I2C_ADDR1_ADDR_Pos                                  (1U)
#define I2C_ADDR1_ADDR_Msk                                  (0x7FUL << I2C_ADDR1_ADDR_Pos)
#define I2C_ADDR1_ADDR                                      I2C_ADDR1_ADDR_Msk

// I2C_ADDR2
#define I2C_ADDR2_ADDR_Pos                                  (1U)
#define I2C_ADDR2_ADDR_Msk                                  (0x7FUL << I2C_ADDR2_ADDR_Pos)
#define I2C_ADDR2_ADDR                                      I2C_ADDR2_ADDR_Msk

// I2C_MATCH
#define I2C_MATCH_AD0F_Pos                                  (0U)
#define I2C_MATCH_AD0F_Msk                                  (0x1UL << I2C_MATCH_AD0F_Pos)
#define I2C_MATCH_AD0F                                      I2C_MATCH_AD0F_Msk
#define I2C_MATCH_AD1F_Pos                                  (1U)
#define I2C_MATCH_AD1F_Msk                                  (0x1UL << I2C_MATCH_AD1F_Pos)
#define I2C_MATCH_AD1F                                      I2C_MATCH_AD1F_Msk
#define I2C_MATCH_AD2F_Pos                                  (2U)
#define I2C_MATCH_AD2F_Msk                                  (0x1UL << I2C_MATCH_AD2F_Pos)
#define I2C_MATCH_AD2F                                      I2C_MATCH_AD2F_Msk



//********************    Bits Define For Peripheral IWDT    ********************//
// IWDT_KR
#define IWDT_KR_KR_Pos                                      (0U)
#define IWDT_KR_KR_Msk                                      (0xFFFFUL << IWDT_KR_KR_Pos)
#define IWDT_KR_KR                                          IWDT_KR_KR_Msk

// IWDT_CR
#define IWDT_CR_PRS_Pos                                     (0U)
#define IWDT_CR_PRS_Msk                                     (0xFUL << IWDT_CR_PRS_Pos)
#define IWDT_CR_PRS                                         IWDT_CR_PRS_Msk
#define IWDT_CR_IE_Pos                                      (4U)
#define IWDT_CR_IE_Msk                                      (0x1UL << IWDT_CR_IE_Pos)
#define IWDT_CR_IE                                          IWDT_CR_IE_Msk
#define IWDT_CR_ACTION_Pos                                  (5U)
#define IWDT_CR_ACTION_Msk                                  (0x1UL << IWDT_CR_ACTION_Pos)
#define IWDT_CR_ACTION                                      IWDT_CR_ACTION_Msk
#define IWDT_CR_PAUSE_Pos                                   (6U)
#define IWDT_CR_PAUSE_Msk                                   (0x1UL << IWDT_CR_PAUSE_Pos)
#define IWDT_CR_PAUSE                                       IWDT_CR_PAUSE_Msk

// IWDT_ARR
#define IWDT_ARR_ARR_Pos                                    (0U)
#define IWDT_ARR_ARR_Msk                                    (0xFFFUL << IWDT_ARR_ARR_Pos)
#define IWDT_ARR_ARR                                        IWDT_ARR_ARR_Msk

// IWDT_SR
#define IWDT_SR_PRSF_Pos                                    (0U)
#define IWDT_SR_PRSF_Msk                                    (0x1UL << IWDT_SR_PRSF_Pos)
#define IWDT_SR_PRSF                                        IWDT_SR_PRSF_Msk
#define IWDT_SR_ARRF_Pos                                    (1U)
#define IWDT_SR_ARRF_Msk                                    (0x1UL << IWDT_SR_ARRF_Pos)
#define IWDT_SR_ARRF                                        IWDT_SR_ARRF_Msk
#define IWDT_SR_WINRF_Pos                                   (2U)
#define IWDT_SR_WINRF_Msk                                   (0x1UL << IWDT_SR_WINRF_Pos)
#define IWDT_SR_WINRF                                       IWDT_SR_WINRF_Msk
#define IWDT_SR_OV_Pos                                      (3U)
#define IWDT_SR_OV_Msk                                      (0x1UL << IWDT_SR_OV_Pos)
#define IWDT_SR_OV                                          IWDT_SR_OV_Msk
#define IWDT_SR_RUN_Pos                                     (4U)
#define IWDT_SR_RUN_Msk                                     (0x1UL << IWDT_SR_RUN_Pos)
#define IWDT_SR_RUN                                         IWDT_SR_RUN_Msk

// IWDT_WINR
#define IWDT_WINR_WINR_Pos                                  (0U)
#define IWDT_WINR_WINR_Msk                                  (0xFFFUL << IWDT_WINR_WINR_Pos)
#define IWDT_WINR_WINR                                      IWDT_WINR_WINR_Msk



//********************    Bits Define For Peripheral LPUART    ********************//
// LPUART_DR
#define LPUART_DR_DR_Pos                                    (0U)
#define LPUART_DR_DR_Msk                                    (0xFFUL << LPUART_DR_DR_Pos)
#define LPUART_DR_DR                                        LPUART_DR_DR_Msk
#define LPUART_DR_DR8_Pos                                   (8U)
#define LPUART_DR_DR8_Msk                                   (0x1UL << LPUART_DR_DR8_Pos)
#define LPUART_DR_DR8                                       LPUART_DR_DR8_Msk

// LPUART_CR
#define LPUART_CR_RCIE_Pos                                  (0U)
#define LPUART_CR_RCIE_Msk                                  (0x1UL << LPUART_CR_RCIE_Pos)
#define LPUART_CR_RCIE                                      LPUART_CR_RCIE_Msk
#define LPUART_CR_TCIE_Pos                                  (1U)
#define LPUART_CR_TCIE_Msk                                  (0x1UL << LPUART_CR_TCIE_Pos)
#define LPUART_CR_TCIE                                      LPUART_CR_TCIE_Msk
#define LPUART_CR_DR8CFG_Pos                                (2U)
#define LPUART_CR_DR8CFG_Msk                                (0x3UL << LPUART_CR_DR8CFG_Pos)
#define LPUART_CR_DR8CFG                                    LPUART_CR_DR8CFG_Msk
#define LPUART_CR_RXEN_Pos                                  (4U)
#define LPUART_CR_RXEN_Msk                                  (0x1UL << LPUART_CR_RXEN_Pos)
#define LPUART_CR_RXEN                                      LPUART_CR_RXEN_Msk
#define LPUART_CR_ADRDET_Pos                                (5U)
#define LPUART_CR_ADRDET_Msk                                (0x1UL << LPUART_CR_ADRDET_Pos)
#define LPUART_CR_ADRDET                                    LPUART_CR_ADRDET_Msk
#define LPUART_CR_MODE_Pos                                  (6U)
#define LPUART_CR_MODE_Msk                                  (0x3UL << LPUART_CR_MODE_Pos)
#define LPUART_CR_MODE                                      LPUART_CR_MODE_Msk
#define LPUART_CR_TXEIE_Pos                                 (8U)
#define LPUART_CR_TXEIE_Msk                                 (0x1UL << LPUART_CR_TXEIE_Pos)
#define LPUART_CR_TXEIE                                     LPUART_CR_TXEIE_Msk
#define LPUART_CR_OVER_Pos                                  (9U)
#define LPUART_CR_OVER_Msk                                  (0x3UL << LPUART_CR_OVER_Pos)
#define LPUART_CR_OVER                                      LPUART_CR_OVER_Msk
#define LPUART_CR_CLKSRC_Pos                                (11U)
#define LPUART_CR_CLKSRC_Msk                                (0x3UL << LPUART_CR_CLKSRC_Pos)
#define LPUART_CR_CLKSRC                                    LPUART_CR_CLKSRC_Msk
#define LPUART_CR_PEIE_Pos                                  (13U)
#define LPUART_CR_PEIE_Msk                                  (0x1UL << LPUART_CR_PEIE_Pos)
#define LPUART_CR_PEIE                                      LPUART_CR_PEIE_Msk
#define LPUART_CR_STOP_Pos                                  (14U)
#define LPUART_CR_STOP_Msk                                  (0x3UL << LPUART_CR_STOP_Pos)
#define LPUART_CR_STOP                                      LPUART_CR_STOP_Msk
#define LPUART_CR_RTSEN_Pos                                 (18U)
#define LPUART_CR_RTSEN_Msk                                 (0x1UL << LPUART_CR_RTSEN_Pos)
#define LPUART_CR_RTSEN                                     LPUART_CR_RTSEN_Msk
#define LPUART_CR_CTSEN_Pos                                 (19U)
#define LPUART_CR_CTSEN_Msk                                 (0x1UL << LPUART_CR_CTSEN_Pos)
#define LPUART_CR_CTSEN                                     LPUART_CR_CTSEN_Msk
#define LPUART_CR_CTSIE_Pos                                 (20U)
#define LPUART_CR_CTSIE_Msk                                 (0x1UL << LPUART_CR_CTSIE_Pos)
#define LPUART_CR_CTSIE                                     LPUART_CR_CTSIE_Msk
#define LPUART_CR_FEIE_Pos                                  (21U)
#define LPUART_CR_FEIE_Msk                                  (0x1UL << LPUART_CR_FEIE_Pos)
#define LPUART_CR_FEIE                                      LPUART_CR_FEIE_Msk
#define LPUART_CR_HDSEL_Pos                                 (22U)
#define LPUART_CR_HDSEL_Msk                                 (0x1UL << LPUART_CR_HDSEL_Pos)
#define LPUART_CR_HDSEL                                     LPUART_CR_HDSEL_Msk

// LPUART_ADDR
#define LPUART_ADDR_ADDR_Pos                                (0U)
#define LPUART_ADDR_ADDR_Msk                                (0xFFUL << LPUART_ADDR_ADDR_Pos)
#define LPUART_ADDR_ADDR                                    LPUART_ADDR_ADDR_Msk

// LPUART_ADDRMASK
#define LPUART_ADDRMASK_MASK_Pos                            (0U)
#define LPUART_ADDRMASK_MASK_Msk                            (0xFFUL << LPUART_ADDRMASK_MASK_Pos)
#define LPUART_ADDRMASK_MASK                                LPUART_ADDRMASK_MASK_Msk

// LPUART_ISR
#define LPUART_ISR_RC_Pos                                   (0U)
#define LPUART_ISR_RC_Msk                                   (0x1UL << LPUART_ISR_RC_Pos)
#define LPUART_ISR_RC                                       LPUART_ISR_RC_Msk
#define LPUART_ISR_TC_Pos                                   (1U)
#define LPUART_ISR_TC_Msk                                   (0x1UL << LPUART_ISR_TC_Pos)
#define LPUART_ISR_TC                                       LPUART_ISR_TC_Msk
#define LPUART_ISR_FE_Pos                                   (2U)
#define LPUART_ISR_FE_Msk                                   (0x1UL << LPUART_ISR_FE_Pos)
#define LPUART_ISR_FE                                       LPUART_ISR_FE_Msk
#define LPUART_ISR_TXE_Pos                                  (3U)
#define LPUART_ISR_TXE_Msk                                  (0x1UL << LPUART_ISR_TXE_Pos)
#define LPUART_ISR_TXE                                      LPUART_ISR_TXE_Msk
#define LPUART_ISR_PE_Pos                                   (4U)
#define LPUART_ISR_PE_Msk                                   (0x1UL << LPUART_ISR_PE_Pos)
#define LPUART_ISR_PE                                       LPUART_ISR_PE_Msk
#define LPUART_ISR_CTSIF_Pos                                (5U)
#define LPUART_ISR_CTSIF_Msk                                (0x1UL << LPUART_ISR_CTSIF_Pos)
#define LPUART_ISR_CTSIF                                    LPUART_ISR_CTSIF_Msk
#define LPUART_ISR_CTS_Pos                                  (6U)
#define LPUART_ISR_CTS_Msk                                  (0x1UL << LPUART_ISR_CTS_Pos)
#define LPUART_ISR_CTS                                      LPUART_ISR_CTS_Msk

// LPUART_ICR
#define LPUART_ICR_RC_Pos                                   (0U)
#define LPUART_ICR_RC_Msk                                   (0x1UL << LPUART_ICR_RC_Pos)
#define LPUART_ICR_RC                                       LPUART_ICR_RC_Msk
#define LPUART_ICR_TC_Pos                                   (1U)
#define LPUART_ICR_TC_Msk                                   (0x1UL << LPUART_ICR_TC_Pos)
#define LPUART_ICR_TC                                       LPUART_ICR_TC_Msk
#define LPUART_ICR_FE_Pos                                   (2U)
#define LPUART_ICR_FE_Msk                                   (0x1UL << LPUART_ICR_FE_Pos)
#define LPUART_ICR_FE                                       LPUART_ICR_FE_Msk
#define LPUART_ICR_PE_Pos                                   (4U)
#define LPUART_ICR_PE_Msk                                   (0x1UL << LPUART_ICR_PE_Pos)
#define LPUART_ICR_PE                                       LPUART_ICR_PE_Msk
#define LPUART_ICR_CTSIF_Pos                                (5U)
#define LPUART_ICR_CTSIF_Msk                                (0x1UL << LPUART_ICR_CTSIF_Pos)
#define LPUART_ICR_CTSIF                                    LPUART_ICR_CTSIF_Msk

// LPUART_BRR
#define LPUART_BRR_SCNT_Pos                                 (0U)
#define LPUART_BRR_SCNT_Msk                                 (0xFFFFUL << LPUART_BRR_SCNT_Pos)
#define LPUART_BRR_SCNT                                     LPUART_BRR_SCNT_Msk



//********************    Bits Define For Peripheral LVD    ********************//
// LVD_CR
#define LVD_CR_EN_Pos                                       (0U)
#define LVD_CR_EN_Msk                                       (0x1UL << LVD_CR_EN_Pos)
#define LVD_CR_EN                                           LVD_CR_EN_Msk
#define LVD_CR_ACT_Pos                                      (1U)
#define LVD_CR_ACT_Msk                                      (0x1UL << LVD_CR_ACT_Pos)
#define LVD_CR_ACT                                          LVD_CR_ACT_Msk
#define LVD_CR_SOURCE_Pos                                   (2U)
#define LVD_CR_SOURCE_Msk                                   (0x3UL << LVD_CR_SOURCE_Pos)
#define LVD_CR_SOURCE                                       LVD_CR_SOURCE_Msk
#define LVD_CR_VTDS_Pos                                     (4U)
#define LVD_CR_VTDS_Msk                                     (0xFUL << LVD_CR_VTDS_Pos)
#define LVD_CR_VTDS                                         LVD_CR_VTDS_Msk
#define LVD_CR_FLTEN_Pos                                    (8U)
#define LVD_CR_FLTEN_Msk                                    (0x1UL << LVD_CR_FLTEN_Pos)
#define LVD_CR_FLTEN                                        LVD_CR_FLTEN_Msk
#define LVD_CR_FLTTIME_Pos                                  (9U)
#define LVD_CR_FLTTIME_Msk                                  (0x7UL << LVD_CR_FLTTIME_Pos)
#define LVD_CR_FLTTIME                                      LVD_CR_FLTTIME_Msk
#define LVD_CR_FTEN_Pos                                     (12U)
#define LVD_CR_FTEN_Msk                                     (0x1UL << LVD_CR_FTEN_Pos)
#define LVD_CR_FTEN                                         LVD_CR_FTEN_Msk
#define LVD_CR_RTEN_Pos                                     (13U)
#define LVD_CR_RTEN_Msk                                     (0x1UL << LVD_CR_RTEN_Pos)
#define LVD_CR_RTEN                                         LVD_CR_RTEN_Msk
#define LVD_CR_HTEN_Pos                                     (14U)
#define LVD_CR_HTEN_Msk                                     (0x1UL << LVD_CR_HTEN_Pos)
#define LVD_CR_HTEN                                         LVD_CR_HTEN_Msk
#define LVD_CR_IE_Pos                                       (15U)
#define LVD_CR_IE_Msk                                       (0x1UL << LVD_CR_IE_Pos)
#define LVD_CR_IE                                           LVD_CR_IE_Msk

// LVD_SR
#define LVD_SR_INTF_Pos                                     (0U)
#define LVD_SR_INTF_Msk                                     (0x1UL << LVD_SR_INTF_Pos)
#define LVD_SR_INTF                                         LVD_SR_INTF_Msk
#define LVD_SR_FLTV_Pos                                     (1U)
#define LVD_SR_FLTV_Msk                                     (0x1UL << LVD_SR_FLTV_Pos)
#define LVD_SR_FLTV                                         LVD_SR_FLTV_Msk



//********************    Bits Define For Peripheral SPI    ********************//
// SPI_CR0
#define SPI_CR0_EN_Pos                                      (0U)
#define SPI_CR0_EN_Msk                                      (0x1UL << SPI_CR0_EN_Pos)
#define SPI_CR0_EN                                          SPI_CR0_EN_Msk
#define SPI_CR0_BRR_Pos                                     (1U)
#define SPI_CR0_BRR_Msk                                     (0x7UL << SPI_CR0_BRR_Pos)
#define SPI_CR0_BRR                                         SPI_CR0_BRR_Msk
#define SPI_CR0_CPHA_Pos                                    (4U)
#define SPI_CR0_CPHA_Msk                                    (0x1UL << SPI_CR0_CPHA_Pos)
#define SPI_CR0_CPHA                                        SPI_CR0_CPHA_Msk
#define SPI_CR0_CPOL_Pos                                    (5U)
#define SPI_CR0_CPOL_Msk                                    (0x1UL << SPI_CR0_CPOL_Pos)
#define SPI_CR0_CPOL                                        SPI_CR0_CPOL_Msk
#define SPI_CR0_MSTR_Pos                                    (6U)
#define SPI_CR0_MSTR_Msk                                    (0x1UL << SPI_CR0_MSTR_Pos)
#define SPI_CR0_MSTR                                        SPI_CR0_MSTR_Msk
#define SPI_CR0_LSBF_Pos                                    (7U)
#define SPI_CR0_LSBF_Msk                                    (0x1UL << SPI_CR0_LSBF_Pos)
#define SPI_CR0_LSBF                                        SPI_CR0_LSBF_Msk
#define SPI_CR0_WIDTH_Pos                                   (8U)
#define SPI_CR0_WIDTH_Msk                                   (0xFUL << SPI_CR0_WIDTH_Pos)
#define SPI_CR0_WIDTH                                       SPI_CR0_WIDTH_Msk
#define SPI_CR0_SSM_Pos                                     (12U)
#define SPI_CR0_SSM_Msk                                     (0x1UL << SPI_CR0_SSM_Pos)
#define SPI_CR0_SSM                                         SPI_CR0_SSM_Msk
#define SPI_CR0_CM_Pos                                      (13U)
#define SPI_CR0_CM_Msk                                      (0x3UL << SPI_CR0_CM_Pos)
#define SPI_CR0_CM                                          SPI_CR0_CM_Msk

// SPI_CR1
#define SPI_CR1_TXEIE_Pos                                   (0U)
#define SPI_CR1_TXEIE_Msk                                   (0x1UL << SPI_CR1_TXEIE_Pos)
#define SPI_CR1_TXEIE                                       SPI_CR1_TXEIE_Msk
#define SPI_CR1_RXNEIE_Pos                                  (1U)
#define SPI_CR1_RXNEIE_Msk                                  (0x1UL << SPI_CR1_RXNEIE_Pos)
#define SPI_CR1_RXNEIE                                      SPI_CR1_RXNEIE_Msk
#define SPI_CR1_SSFIE_Pos                                   (2U)
#define SPI_CR1_SSFIE_Msk                                   (0x1UL << SPI_CR1_SSFIE_Pos)
#define SPI_CR1_SSFIE                                       SPI_CR1_SSFIE_Msk
#define SPI_CR1_SSRIE_Pos                                   (3U)
#define SPI_CR1_SSRIE_Msk                                   (0x1UL << SPI_CR1_SSRIE_Pos)
#define SPI_CR1_SSRIE                                       SPI_CR1_SSRIE_Msk
#define SPI_CR1_UDFIE_Pos                                   (4U)
#define SPI_CR1_UDFIE_Msk                                   (0x1UL << SPI_CR1_UDFIE_Pos)
#define SPI_CR1_UDFIE                                       SPI_CR1_UDFIE_Msk
#define SPI_CR1_OVFIE_Pos                                   (5U)
#define SPI_CR1_OVFIE_Msk                                   (0x1UL << SPI_CR1_OVFIE_Pos)
#define SPI_CR1_OVFIE                                       SPI_CR1_OVFIE_Msk
#define SPI_CR1_SSERRIE_Pos                                 (6U)
#define SPI_CR1_SSERRIE_Msk                                 (0x1UL << SPI_CR1_SSERRIE_Pos)
#define SPI_CR1_SSERRIE                                     SPI_CR1_SSERRIE_Msk
#define SPI_CR1_MODFIE_Pos                                  (7U)
#define SPI_CR1_MODFIE_Msk                                  (0x1UL << SPI_CR1_MODFIE_Pos)
#define SPI_CR1_MODFIE                                      SPI_CR1_MODFIE_Msk

// SPI_HDOE
#define SPI_HDOE_HDOE_Pos                                   (0U)
#define SPI_HDOE_HDOE_Msk                                   (0x1UL << SPI_HDOE_HDOE_Pos)
#define SPI_HDOE_HDOE                                       SPI_HDOE_HDOE_Msk

// SPI_SSI
#define SPI_SSI_SSI_Pos                                     (0U)
#define SPI_SSI_SSI_Msk                                     (0x1UL << SPI_SSI_SSI_Pos)
#define SPI_SSI_SSI                                         SPI_SSI_SSI_Msk

// SPI_SR
#define SPI_SR_TXE_Pos                                      (0U)
#define SPI_SR_TXE_Msk                                      (0x1UL << SPI_SR_TXE_Pos)
#define SPI_SR_TXE                                          SPI_SR_TXE_Msk
#define SPI_SR_RXNE_Pos                                     (1U)
#define SPI_SR_RXNE_Msk                                     (0x1UL << SPI_SR_RXNE_Pos)
#define SPI_SR_RXNE                                         SPI_SR_RXNE_Msk
#define SPI_SR_SSF_Pos                                      (2U)
#define SPI_SR_SSF_Msk                                      (0x1UL << SPI_SR_SSF_Pos)
#define SPI_SR_SSF                                          SPI_SR_SSF_Msk
#define SPI_SR_SSR_Pos                                      (3U)
#define SPI_SR_SSR_Msk                                      (0x1UL << SPI_SR_SSR_Pos)
#define SPI_SR_SSR                                          SPI_SR_SSR_Msk
#define SPI_SR_UDF_Pos                                      (4U)
#define SPI_SR_UDF_Msk                                      (0x1UL << SPI_SR_UDF_Pos)
#define SPI_SR_UDF                                          SPI_SR_UDF_Msk
#define SPI_SR_OVF_Pos                                      (5U)
#define SPI_SR_OVF_Msk                                      (0x1UL << SPI_SR_OVF_Pos)
#define SPI_SR_OVF                                          SPI_SR_OVF_Msk
#define SPI_SR_SSERR_Pos                                    (6U)
#define SPI_SR_SSERR_Msk                                    (0x1UL << SPI_SR_SSERR_Pos)
#define SPI_SR_SSERR                                        SPI_SR_SSERR_Msk
#define SPI_SR_MODF_Pos                                     (7U)
#define SPI_SR_MODF_Msk                                     (0x1UL << SPI_SR_MODF_Pos)
#define SPI_SR_MODF                                         SPI_SR_MODF_Msk
#define SPI_SR_BUSY_Pos                                     (8U)
#define SPI_SR_BUSY_Msk                                     (0x1UL << SPI_SR_BUSY_Pos)
#define SPI_SR_BUSY                                         SPI_SR_BUSY_Msk
#define SPI_SR_SSLVL_Pos                                    (9U)
#define SPI_SR_SSLVL_Msk                                    (0x1UL << SPI_SR_SSLVL_Pos)
#define SPI_SR_SSLVL                                        SPI_SR_SSLVL_Msk

// SPI_ICR
#define SPI_ICR_TXE_Pos                                     (0U)
#define SPI_ICR_TXE_Msk                                     (0x1UL << SPI_ICR_TXE_Pos)
#define SPI_ICR_TXE                                         SPI_ICR_TXE_Msk
#define SPI_ICR_RXNE_Pos                                    (1U)
#define SPI_ICR_RXNE_Msk                                    (0x1UL << SPI_ICR_RXNE_Pos)
#define SPI_ICR_RXNE                                        SPI_ICR_RXNE_Msk
#define SPI_ICR_SSF_Pos                                     (2U)
#define SPI_ICR_SSF_Msk                                     (0x1UL << SPI_ICR_SSF_Pos)
#define SPI_ICR_SSF                                         SPI_ICR_SSF_Msk
#define SPI_ICR_SSR_Pos                                     (3U)
#define SPI_ICR_SSR_Msk                                     (0x1UL << SPI_ICR_SSR_Pos)
#define SPI_ICR_SSR                                         SPI_ICR_SSR_Msk
#define SPI_ICR_UDF_Pos                                     (4U)
#define SPI_ICR_UDF_Msk                                     (0x1UL << SPI_ICR_UDF_Pos)
#define SPI_ICR_UDF                                         SPI_ICR_UDF_Msk
#define SPI_ICR_OVF_Pos                                     (5U)
#define SPI_ICR_OVF_Msk                                     (0x1UL << SPI_ICR_OVF_Pos)
#define SPI_ICR_OVF                                         SPI_ICR_OVF_Msk
#define SPI_ICR_SSERR_Pos                                   (6U)
#define SPI_ICR_SSERR_Msk                                   (0x1UL << SPI_ICR_SSERR_Pos)
#define SPI_ICR_SSERR                                       SPI_ICR_SSERR_Msk
#define SPI_ICR_MODF_Pos                                    (7U)
#define SPI_ICR_MODF_Msk                                    (0x1UL << SPI_ICR_MODF_Pos)
#define SPI_ICR_MODF                                        SPI_ICR_MODF_Msk

// SPI_DR
#define SPI_DR_DR_Pos                                       (0U)
#define SPI_DR_DR_Msk                                       (0xFFFFUL << SPI_DR_DR_Pos)
#define SPI_DR_DR                                           SPI_DR_DR_Msk



//********************    Bits Define For Peripheral SYSCTRL    ********************//
// SYSCTRL_CR0
#define SYSCTRL_CR0_CLKSRC_Pos                              (0U)
#define SYSCTRL_CR0_CLKSRC_Msk                              (0x7UL << SYSCTRL_CR0_CLKSRC_Pos)
#define SYSCTRL_CR0_CLKSRC                                  SYSCTRL_CR0_CLKSRC_Msk
#define SYSCTRL_CR0_HCLKPRS_Pos                             (3U)
#define SYSCTRL_CR0_HCLKPRS_Msk                             (0x7UL << SYSCTRL_CR0_HCLKPRS_Pos)
#define SYSCTRL_CR0_HCLKPRS                                 SYSCTRL_CR0_HCLKPRS_Msk
#define SYSCTRL_CR0_PCLKPRS_Pos                             (6U)
#define SYSCTRL_CR0_PCLKPRS_Msk                             (0x3UL << SYSCTRL_CR0_PCLKPRS_Pos)
#define SYSCTRL_CR0_PCLKPRS                                 SYSCTRL_CR0_PCLKPRS_Msk

// SYSCTRL_CR1
#define SYSCTRL_CR1_SWDIO_Pos                               (0U)
#define SYSCTRL_CR1_SWDIO_Msk                               (0x1UL << SYSCTRL_CR1_SWDIO_Pos)
#define SYSCTRL_CR1_SWDIO                                   SYSCTRL_CR1_SWDIO_Msk
#define SYSCTRL_CR1_LOCKUP_Pos                              (1U)
#define SYSCTRL_CR1_LOCKUP_Msk                              (0x1UL << SYSCTRL_CR1_LOCKUP_Pos)
#define SYSCTRL_CR1_LOCKUP                                  SYSCTRL_CR1_LOCKUP_Msk
#define SYSCTRL_CR1_WAKEUPCLK_Pos                           (2U)
#define SYSCTRL_CR1_WAKEUPCLK_Msk                           (0x1UL << SYSCTRL_CR1_WAKEUPCLK_Pos)
#define SYSCTRL_CR1_WAKEUPCLK                               SYSCTRL_CR1_WAKEUPCLK_Msk
#define SYSCTRL_CR1_RESIO_Pos                               (3U)
#define SYSCTRL_CR1_RESIO_Msk                               (0x1UL << SYSCTRL_CR1_RESIO_Pos)
#define SYSCTRL_CR1_RESIO                                   SYSCTRL_CR1_RESIO_Msk
#define SYSCTRL_CR1_GTIMCFG_Pos                             (8U)
#define SYSCTRL_CR1_GTIMCFG_Msk                             (0x1UL << SYSCTRL_CR1_GTIMCFG_Pos)
#define SYSCTRL_CR1_GTIMCFG                                 SYSCTRL_CR1_GTIMCFG_Msk

// SYSCTRL_CR2
#define SYSCTRL_CR2_RCHEN_Pos                               (0U)
#define SYSCTRL_CR2_RCHEN_Msk                               (0x1UL << SYSCTRL_CR2_RCHEN_Pos)
#define SYSCTRL_CR2_RCHEN                                   SYSCTRL_CR2_RCHEN_Msk
#define SYSCTRL_CR2_RCLEN_Pos                               (2U)
#define SYSCTRL_CR2_RCLEN_Msk                               (0x1UL << SYSCTRL_CR2_RCLEN_Pos)
#define SYSCTRL_CR2_RCLEN                                   SYSCTRL_CR2_RCLEN_Msk
#define SYSCTRL_CR2_EXTCLKEN_Pos                            (5U)
#define SYSCTRL_CR2_EXTCLKEN_Msk                            (0x1UL << SYSCTRL_CR2_EXTCLKEN_Pos)
#define SYSCTRL_CR2_EXTCLKEN                                SYSCTRL_CR2_EXTCLKEN_Msk

// SYSCTRL_CR3
#define SYSCTRL_CR3_CR3_Pos                                 (0U)
#define SYSCTRL_CR3_CR3_Msk                                 (0xFFFFUL << SYSCTRL_CR3_CR3_Pos)
#define SYSCTRL_CR3_CR3                                     SYSCTRL_CR3_CR3_Msk

// SYSCTRL_RCH
#define SYSCTRL_RCH_TRIM_Pos                                (0U)
#define SYSCTRL_RCH_TRIM_Msk                                (0x1FFUL << SYSCTRL_RCH_TRIM_Pos)
#define SYSCTRL_RCH_TRIM                                    SYSCTRL_RCH_TRIM_Msk
#define SYSCTRL_RCH_DIV_Pos                                 (9U)
#define SYSCTRL_RCH_DIV_Msk                                 (0xFUL << SYSCTRL_RCH_DIV_Pos)
#define SYSCTRL_RCH_DIV                                     SYSCTRL_RCH_DIV_Msk
#define SYSCTRL_RCH_STABLE_Pos                              (15U)
#define SYSCTRL_RCH_STABLE_Msk                              (0x1UL << SYSCTRL_RCH_STABLE_Pos)
#define SYSCTRL_RCH_STABLE                                  SYSCTRL_RCH_STABLE_Msk

// SYSCTRL_RCL
#define SYSCTRL_RCL_TRIM_Pos                                (0U)
#define SYSCTRL_RCL_TRIM_Msk                                (0x3FFUL << SYSCTRL_RCL_TRIM_Pos)
#define SYSCTRL_RCL_TRIM                                    SYSCTRL_RCL_TRIM_Msk
#define SYSCTRL_RCL_WAITCYCLE_Pos                           (10U)
#define SYSCTRL_RCL_WAITCYCLE_Msk                           (0x3UL << SYSCTRL_RCL_WAITCYCLE_Pos)
#define SYSCTRL_RCL_WAITCYCLE                               SYSCTRL_RCL_WAITCYCLE_Msk
#define SYSCTRL_RCL_STABLE_Pos                              (15U)
#define SYSCTRL_RCL_STABLE_Msk                              (0x1UL << SYSCTRL_RCL_STABLE_Pos)
#define SYSCTRL_RCL_STABLE                                  SYSCTRL_RCL_STABLE_Msk

// SYSCTRL_PERICLKEN0
#define SYSCTRL_PERICLKEN0_LPUART0_Pos                      (2U)
#define SYSCTRL_PERICLKEN0_LPUART0_Msk                      (0x1UL << SYSCTRL_PERICLKEN0_LPUART0_Pos)
#define SYSCTRL_PERICLKEN0_LPUART0                          SYSCTRL_PERICLKEN0_LPUART0_Msk
#define SYSCTRL_PERICLKEN0_LPUART1_Pos                      (3U)
#define SYSCTRL_PERICLKEN0_LPUART1_Msk                      (0x1UL << SYSCTRL_PERICLKEN0_LPUART1_Pos)
#define SYSCTRL_PERICLKEN0_LPUART1                          SYSCTRL_PERICLKEN0_LPUART1_Msk
#define SYSCTRL_PERICLKEN0_I2C_Pos                          (4U)
#define SYSCTRL_PERICLKEN0_I2C_Msk                          (0x1UL << SYSCTRL_PERICLKEN0_I2C_Pos)
#define SYSCTRL_PERICLKEN0_I2C                              SYSCTRL_PERICLKEN0_I2C_Msk
#define SYSCTRL_PERICLKEN0_SPI_Pos                          (6U)
#define SYSCTRL_PERICLKEN0_SPI_Msk                          (0x1UL << SYSCTRL_PERICLKEN0_SPI_Pos)
#define SYSCTRL_PERICLKEN0_SPI                              SYSCTRL_PERICLKEN0_SPI_Msk
#define SYSCTRL_PERICLKEN0_ATIM3_Pos                        (11U)
#define SYSCTRL_PERICLKEN0_ATIM3_Msk                        (0x1UL << SYSCTRL_PERICLKEN0_ATIM3_Pos)
#define SYSCTRL_PERICLKEN0_ATIM3                            SYSCTRL_PERICLKEN0_ATIM3_Msk
#define SYSCTRL_PERICLKEN0_IWDT_Pos                         (15U)
#define SYSCTRL_PERICLKEN0_IWDT_Msk                         (0x1UL << SYSCTRL_PERICLKEN0_IWDT_Pos)
#define SYSCTRL_PERICLKEN0_IWDT                             SYSCTRL_PERICLKEN0_IWDT_Msk
#define SYSCTRL_PERICLKEN0_ADC_Pos                          (16U)
#define SYSCTRL_PERICLKEN0_ADC_Msk                          (0x1UL << SYSCTRL_PERICLKEN0_ADC_Pos)
#define SYSCTRL_PERICLKEN0_ADC                              SYSCTRL_PERICLKEN0_ADC_Msk
#define SYSCTRL_PERICLKEN0_CTRIM_Pos                        (21U)
#define SYSCTRL_PERICLKEN0_CTRIM_Msk                        (0x1UL << SYSCTRL_PERICLKEN0_CTRIM_Pos)
#define SYSCTRL_PERICLKEN0_CTRIM                            SYSCTRL_PERICLKEN0_CTRIM_Msk
#define SYSCTRL_PERICLKEN0_FLASH_Pos                        (31U)
#define SYSCTRL_PERICLKEN0_FLASH_Msk                        (0x1UL << SYSCTRL_PERICLKEN0_FLASH_Pos)
#define SYSCTRL_PERICLKEN0_FLASH                            SYSCTRL_PERICLKEN0_FLASH_Msk

// SYSCTRL_PERICLKEN1
#define SYSCTRL_PERICLKEN1_PA_Pos                           (0U)
#define SYSCTRL_PERICLKEN1_PA_Msk                           (0x1UL << SYSCTRL_PERICLKEN1_PA_Pos)
#define SYSCTRL_PERICLKEN1_PA                               SYSCTRL_PERICLKEN1_PA_Msk
#define SYSCTRL_PERICLKEN1_PB_Pos                           (1U)
#define SYSCTRL_PERICLKEN1_PB_Msk                           (0x1UL << SYSCTRL_PERICLKEN1_PB_Pos)
#define SYSCTRL_PERICLKEN1_PB                               SYSCTRL_PERICLKEN1_PB_Msk
#define SYSCTRL_PERICLKEN1_PC_Pos                           (2U)
#define SYSCTRL_PERICLKEN1_PC_Msk                           (0x1UL << SYSCTRL_PERICLKEN1_PC_Pos)
#define SYSCTRL_PERICLKEN1_PC                               SYSCTRL_PERICLKEN1_PC_Msk
#define SYSCTRL_PERICLKEN1_PD_Pos                           (3U)
#define SYSCTRL_PERICLKEN1_PD_Msk                           (0x1UL << SYSCTRL_PERICLKEN1_PD_Pos)
#define SYSCTRL_PERICLKEN1_PD                               SYSCTRL_PERICLKEN1_PD_Msk
#define SYSCTRL_PERICLKEN1_WWDT_Pos                         (10U)
#define SYSCTRL_PERICLKEN1_WWDT_Msk                         (0x1UL << SYSCTRL_PERICLKEN1_WWDT_Pos)
#define SYSCTRL_PERICLKEN1_WWDT                             SYSCTRL_PERICLKEN1_WWDT_Msk
#define SYSCTRL_PERICLKEN1_GTIM_Pos                         (14U)
#define SYSCTRL_PERICLKEN1_GTIM_Msk                         (0x1UL << SYSCTRL_PERICLKEN1_GTIM_Pos)
#define SYSCTRL_PERICLKEN1_GTIM                             SYSCTRL_PERICLKEN1_GTIM_Msk

// SYSCTRL_PERIRESET0
#define SYSCTRL_PERIRESET0_LPUART0_Pos                      (2U)
#define SYSCTRL_PERIRESET0_LPUART0_Msk                      (0x1UL << SYSCTRL_PERIRESET0_LPUART0_Pos)
#define SYSCTRL_PERIRESET0_LPUART0                          SYSCTRL_PERIRESET0_LPUART0_Msk
#define SYSCTRL_PERIRESET0_LPUART1_Pos                      (3U)
#define SYSCTRL_PERIRESET0_LPUART1_Msk                      (0x1UL << SYSCTRL_PERIRESET0_LPUART1_Pos)
#define SYSCTRL_PERIRESET0_LPUART1                          SYSCTRL_PERIRESET0_LPUART1_Msk
#define SYSCTRL_PERIRESET0_I2C_Pos                          (4U)
#define SYSCTRL_PERIRESET0_I2C_Msk                          (0x1UL << SYSCTRL_PERIRESET0_I2C_Pos)
#define SYSCTRL_PERIRESET0_I2C                              SYSCTRL_PERIRESET0_I2C_Msk
#define SYSCTRL_PERIRESET0_SPI_Pos                          (6U)
#define SYSCTRL_PERIRESET0_SPI_Msk                          (0x1UL << SYSCTRL_PERIRESET0_SPI_Pos)
#define SYSCTRL_PERIRESET0_SPI                              SYSCTRL_PERIRESET0_SPI_Msk
#define SYSCTRL_PERIRESET0_ATIM3_Pos                        (11U)
#define SYSCTRL_PERIRESET0_ATIM3_Msk                        (0x1UL << SYSCTRL_PERIRESET0_ATIM3_Pos)
#define SYSCTRL_PERIRESET0_ATIM3                            SYSCTRL_PERIRESET0_ATIM3_Msk
#define SYSCTRL_PERIRESET0_ADC_Pos                          (16U)
#define SYSCTRL_PERIRESET0_ADC_Msk                          (0x1UL << SYSCTRL_PERIRESET0_ADC_Pos)
#define SYSCTRL_PERIRESET0_ADC                              SYSCTRL_PERIRESET0_ADC_Msk
#define SYSCTRL_PERIRESET0_CTRIM_Pos                        (21U)
#define SYSCTRL_PERIRESET0_CTRIM_Msk                        (0x1UL << SYSCTRL_PERIRESET0_CTRIM_Pos)
#define SYSCTRL_PERIRESET0_CTRIM                            SYSCTRL_PERIRESET0_CTRIM_Msk

// SYSCTRL_PERIRESET1
#define SYSCTRL_PERIRESET1_PA_Pos                           (0U)
#define SYSCTRL_PERIRESET1_PA_Msk                           (0x1UL << SYSCTRL_PERIRESET1_PA_Pos)
#define SYSCTRL_PERIRESET1_PA                               SYSCTRL_PERIRESET1_PA_Msk
#define SYSCTRL_PERIRESET1_PB_Pos                           (1U)
#define SYSCTRL_PERIRESET1_PB_Msk                           (0x1UL << SYSCTRL_PERIRESET1_PB_Pos)
#define SYSCTRL_PERIRESET1_PB                               SYSCTRL_PERIRESET1_PB_Msk
#define SYSCTRL_PERIRESET1_PC_Pos                           (2U)
#define SYSCTRL_PERIRESET1_PC_Msk                           (0x1UL << SYSCTRL_PERIRESET1_PC_Pos)
#define SYSCTRL_PERIRESET1_PC                               SYSCTRL_PERIRESET1_PC_Msk
#define SYSCTRL_PERIRESET1_PD_Pos                           (3U)
#define SYSCTRL_PERIRESET1_PD_Msk                           (0x1UL << SYSCTRL_PERIRESET1_PD_Pos)
#define SYSCTRL_PERIRESET1_PD                               SYSCTRL_PERIRESET1_PD_Msk
#define SYSCTRL_PERIRESET1_WWDT_Pos                         (10U)
#define SYSCTRL_PERIRESET1_WWDT_Msk                         (0x1UL << SYSCTRL_PERIRESET1_WWDT_Pos)
#define SYSCTRL_PERIRESET1_WWDT                             SYSCTRL_PERIRESET1_WWDT_Msk
#define SYSCTRL_PERIRESET1_GTIM_Pos                         (14U)
#define SYSCTRL_PERIRESET1_GTIM_Msk                         (0x1UL << SYSCTRL_PERIRESET1_GTIM_Pos)
#define SYSCTRL_PERIRESET1_GTIM                             SYSCTRL_PERIRESET1_GTIM_Msk

// SYSCTRL_RESETFLAG
#define SYSCTRL_RESETFLAG_VCC_Pos                           (0U)
#define SYSCTRL_RESETFLAG_VCC_Msk                           (0x1UL << SYSCTRL_RESETFLAG_VCC_Pos)
#define SYSCTRL_RESETFLAG_VCC                               SYSCTRL_RESETFLAG_VCC_Msk
#define SYSCTRL_RESETFLAG_VCORE_Pos                         (1U)
#define SYSCTRL_RESETFLAG_VCORE_Msk                         (0x1UL << SYSCTRL_RESETFLAG_VCORE_Pos)
#define SYSCTRL_RESETFLAG_VCORE                             SYSCTRL_RESETFLAG_VCORE_Msk
#define SYSCTRL_RESETFLAG_LVD_Pos                           (2U)
#define SYSCTRL_RESETFLAG_LVD_Msk                           (0x1UL << SYSCTRL_RESETFLAG_LVD_Pos)
#define SYSCTRL_RESETFLAG_LVD                               SYSCTRL_RESETFLAG_LVD_Msk
#define SYSCTRL_RESETFLAG_IWDT_Pos                          (3U)
#define SYSCTRL_RESETFLAG_IWDT_Msk                          (0x1UL << SYSCTRL_RESETFLAG_IWDT_Pos)
#define SYSCTRL_RESETFLAG_IWDT                              SYSCTRL_RESETFLAG_IWDT_Msk
#define SYSCTRL_RESETFLAG_WWDT_Pos                          (4U)
#define SYSCTRL_RESETFLAG_WWDT_Msk                          (0x1UL << SYSCTRL_RESETFLAG_WWDT_Pos)
#define SYSCTRL_RESETFLAG_WWDT                              SYSCTRL_RESETFLAG_WWDT_Msk
#define SYSCTRL_RESETFLAG_LOCKUP_Pos                        (5U)
#define SYSCTRL_RESETFLAG_LOCKUP_Msk                        (0x1UL << SYSCTRL_RESETFLAG_LOCKUP_Pos)
#define SYSCTRL_RESETFLAG_LOCKUP                            SYSCTRL_RESETFLAG_LOCKUP_Msk
#define SYSCTRL_RESETFLAG_SYSREQ_Pos                        (6U)
#define SYSCTRL_RESETFLAG_SYSREQ_Msk                        (0x1UL << SYSCTRL_RESETFLAG_SYSREQ_Pos)
#define SYSCTRL_RESETFLAG_SYSREQ                            SYSCTRL_RESETFLAG_SYSREQ_Msk
#define SYSCTRL_RESETFLAG_RSTB_Pos                          (7U)
#define SYSCTRL_RESETFLAG_RSTB_Msk                          (0x1UL << SYSCTRL_RESETFLAG_RSTB_Pos)
#define SYSCTRL_RESETFLAG_RSTB                              SYSCTRL_RESETFLAG_RSTB_Msk

// SYSCTRL_DEBUGACTIVE
#define SYSCTRL_DEBUGACTIVE_CTRIM_Pos                       (7U)
#define SYSCTRL_DEBUGACTIVE_CTRIM_Msk                       (0x1UL << SYSCTRL_DEBUGACTIVE_CTRIM_Pos)
#define SYSCTRL_DEBUGACTIVE_CTRIM                           SYSCTRL_DEBUGACTIVE_CTRIM_Msk
#define SYSCTRL_DEBUGACTIVE_IWDT_Pos                        (8U)
#define SYSCTRL_DEBUGACTIVE_IWDT_Msk                        (0x1UL << SYSCTRL_DEBUGACTIVE_IWDT_Pos)
#define SYSCTRL_DEBUGACTIVE_IWDT                            SYSCTRL_DEBUGACTIVE_IWDT_Msk
#define SYSCTRL_DEBUGACTIVE_ATIM3_Pos                       (11U)
#define SYSCTRL_DEBUGACTIVE_ATIM3_Msk                       (0x1UL << SYSCTRL_DEBUGACTIVE_ATIM3_Pos)
#define SYSCTRL_DEBUGACTIVE_ATIM3                           SYSCTRL_DEBUGACTIVE_ATIM3_Msk
#define SYSCTRL_DEBUGACTIVE_GTIM_Pos                        (14U)
#define SYSCTRL_DEBUGACTIVE_GTIM_Msk                        (0x1UL << SYSCTRL_DEBUGACTIVE_GTIM_Pos)
#define SYSCTRL_DEBUGACTIVE_GTIM                            SYSCTRL_DEBUGACTIVE_GTIM_Msk
#define SYSCTRL_DEBUGACTIVE_WWDT_Pos                        (16U)
#define SYSCTRL_DEBUGACTIVE_WWDT_Msk                        (0x1UL << SYSCTRL_DEBUGACTIVE_WWDT_Pos)
#define SYSCTRL_DEBUGACTIVE_WWDT                            SYSCTRL_DEBUGACTIVE_WWDT_Msk



//********************    Bits Define For Peripheral WWDT    ********************//
// WWDT_CR0
#define WWDT_CR0_WCNT_Pos                                   (0U)
#define WWDT_CR0_WCNT_Msk                                   (0x7FUL << WWDT_CR0_WCNT_Pos)
#define WWDT_CR0_WCNT                                       WWDT_CR0_WCNT_Msk
#define WWDT_CR0_EN_Pos                                     (7U)
#define WWDT_CR0_EN_Msk                                     (0x1UL << WWDT_CR0_EN_Pos)
#define WWDT_CR0_EN                                         WWDT_CR0_EN_Msk

// WWDT_CR1
#define WWDT_CR1_WINR_Pos                                   (0U)
#define WWDT_CR1_WINR_Msk                                   (0x7FUL << WWDT_CR1_WINR_Pos)
#define WWDT_CR1_WINR                                       WWDT_CR1_WINR_Msk
#define WWDT_CR1_IE_Pos                                     (9U)
#define WWDT_CR1_IE_Msk                                     (0x1UL << WWDT_CR1_IE_Pos)
#define WWDT_CR1_IE                                         WWDT_CR1_IE_Msk
#define WWDT_CR1_PRS_Pos                                    (11U)
#define WWDT_CR1_PRS_Msk                                    (0x7UL << WWDT_CR1_PRS_Pos)
#define WWDT_CR1_PRS                                        WWDT_CR1_PRS_Msk

// WWDT_SR
#define WWDT_SR_POV_Pos                                     (0U)
#define WWDT_SR_POV_Msk                                     (0x1UL << WWDT_SR_POV_Pos)
#define WWDT_SR_POV                                         WWDT_SR_POV_Msk





#ifdef __cplusplus
}
#endif

#endif /* __HC32F002_H__ */

