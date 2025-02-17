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
 ** @file interrupts_hc32f002.h
 **
 ** @brief Header file for INTERRUPTS functions
 **
 ** @author MADS Team 
 **
 ******************************************************************************/
#ifndef __INTERRUPTS_HC32F002_H__
#define __INTERRUPTS_HC32F002_H__

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "ddl.h"

/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif

/******************************************************************************/
/* Global pre-processor symbols/macros ('#define')                            */
/******************************************************************************/
#define DDL_IRQ_LEVEL_DEFAULT                   3u

//<<此选项会打开interrupt_hc32xxx.c中的中断回调函数，用户如果需要实现中断服务函数，
//<<可在源码文件中定义该文件中用"__WEAK"声明的同名中断服务函数即可。
#define INT_CALLBACK_ON                                  1u  //<<(默认值)
//<<此选项会关闭interrupt_hc32xxx.c中的中断回调函数，此时用户可在该文件中自行定义中断服务函数的实现。
#define INT_CALLBACK_OFF                                 0u
/******************************************************************************
 * Global type definitions
 ******************************************************************************/
#define INT_CALLBACK_PORTA                      INT_CALLBACK_ON
#define INT_CALLBACK_PORTB                      INT_CALLBACK_ON
#define INT_CALLBACK_PORTC                      INT_CALLBACK_ON
#define INT_CALLBACK_PORTD                      INT_CALLBACK_ON
#define INT_CALLBACK_ATIM3                      INT_CALLBACK_ON
#define INT_CALLBACK_LPUART0                    INT_CALLBACK_ON
#define INT_CALLBACK_LPUART1                    INT_CALLBACK_ON
#define INT_CALLBACK_SPI                        INT_CALLBACK_ON
#define INT_CALLBACK_I2C                        INT_CALLBACK_ON
#define INT_CALLBACK_GTIM                       INT_CALLBACK_ON
#define INT_CALLBACK_BTIM3                      INT_CALLBACK_ON
#define INT_CALLBACK_BTIM4                      INT_CALLBACK_ON
#define INT_CALLBACK_BTIM5                      INT_CALLBACK_ON
#define INT_CALLBACK_IWDT                       INT_CALLBACK_ON
#define INT_CALLBACK_WWDT                       INT_CALLBACK_ON
#define INT_CALLBACK_ADC                        INT_CALLBACK_ON
#define INT_CALLBACK_LVD                        INT_CALLBACK_ON
#define INT_CALLBACK_FLASH                      INT_CALLBACK_ON
#define INT_CALLBACK_CTRIM                      INT_CALLBACK_ON


/**
 *******************************************************************************
 ** \brief 中断优先级数据类型定义
 ** \note
 ******************************************************************************/
typedef enum en_irq_level
{                                  ///<             优先级顺序
    IrqLevel0  = 0u,               ///< 优先级0(高)     ||
    IrqLevel1  = 1u,               ///< 优先级1         ||
    IrqLevel2  = 2u,               ///< 优先级2         ||
    IrqLevel3  = 3u,               ///< 优先级3(低)     \/
} en_irq_level_t; 


/******************************************************************************
 * Global function prototypes (definition in C source)
 ******************************************************************************/
///< 系统中断使能开关
extern void EnableNvic(IRQn_Type enIrq, en_irq_level_t enLevel, boolean_t bEn);


#ifdef __cplusplus
}
#endif


#endif /* __INTERRUPTS_HC32F002_H__ */

/******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
