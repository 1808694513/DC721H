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
 ** @file ddl.h
 **
 ** @brief Header file for DDL common functions
 **
 ** @author MADS Team 
 **
 ******************************************************************************/

#ifndef __DDL_H__
#define __DDL_H__

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "base_types.h"
#include "board_stkhc32f002.h"
#include "hc32f002.h"
#include "system_hc32f002.h"
#include "sysctrl.h"
#include "interrupts_hc32f002.h"
/* C binding of definitions if building with C++ compiler                     */
#ifdef __cplusplus
extern "C"
{
#endif

/******************************************************************************/
/* Global pre-processor symbols/macros ('#define')                            */
/* Macro for initializing local structures to zero                            */
/******************************************************************************/
#define DDL_ZERO_STRUCT(x)          ddl_memclr((uint8_t*)&(x), (uint32_t)(sizeof(x)))

#define DEC2BCD(x)                  ((((x)/10)<<4) + ((x)%10))
#define BCD2DEC(x)                  ((((x)>>4)*10) + ((x)&0x0F))

///<============================ 通用寄存器操作宏定义 ===============================*/
///< 寄存器位置位
#define REG_SETBITS(REG, BITS)                  ((REG) |= (BITS))

///< 寄存器位清零
#define REG_CLEARBITS(REG, BITS)                ((REG) &= ~(BITS))

///< 寄存器位读取
#define REG_READBITS(REG, BITS)                 ((REG) & (BITS))

///< 寄存器清零
#define REG_CLEAR(REG)                          ((REG) = (0x0))

///< 寄存器写入
#define REG_WRITE(REG, VAL)                     ((REG) = (VAL))

///< 寄存器读取
#define REG_READ(REG)                           ((REG))

///< 寄存器修改
#define REG_MODIFY(REG, CLEARMASK, SETMASK)     REG_WRITE((REG), (((REG_READ(REG)) & (~(CLEARMASK))) | (SETMASK)))

///< BV = Bit Value 寄存器位掩码
#define BV(n)                       ((uint32_t)1u << (n))
       
#define BV0                         ((uint32_t)1u << 0)  
#define BV1                         ((uint32_t)1u << 1)  
#define BV2                         ((uint32_t)1u << 2)  
#define BV3                         ((uint32_t)1u << 3)  
#define BV4                         ((uint32_t)1u << 4)  
#define BV5                         ((uint32_t)1u << 5)  
#define BV6                         ((uint32_t)1u << 6)  
#define BV7                         ((uint32_t)1u << 7)  
#define BV8                         ((uint32_t)1u << 8)  
#define BV9                         ((uint32_t)1u << 9)  
#define BV10                        ((uint32_t)1u << 10) 
#define BV11                        ((uint32_t)1u << 11) 
#define BV12                        ((uint32_t)1u << 12) 
#define BV13                        ((uint32_t)1u << 13) 
#define BV14                        ((uint32_t)1u << 14) 
#define BV15                        ((uint32_t)1u << 15) 
#define BV16                        ((uint32_t)1u << 16) 
#define BV17                        ((uint32_t)1u << 17) 
#define BV18                        ((uint32_t)1u << 18) 
#define BV19                        ((uint32_t)1u << 19) 
#define BV20                        ((uint32_t)1u << 20) 
#define BV21                        ((uint32_t)1u << 21) 
#define BV22                        ((uint32_t)1u << 22) 
#define BV23                        ((uint32_t)1u << 23) 
#define BV24                        ((uint32_t)1u << 24) 
#define BV25                        ((uint32_t)1u << 25) 
#define BV26                        ((uint32_t)1u << 26) 
#define BV27                        ((uint32_t)1u << 27) 
#define BV28                        ((uint32_t)1u << 28) 
#define BV29                        ((uint32_t)1u << 29) 
#define BV30                        ((uint32_t)1u << 30) 
#define BV31                        ((uint32_t)1u << 31) 

/**
 ******************************************************************************
 ** Global Device Series List
 ******************************************************************************/
#define DDL_DEVICE_SERIES_HC32F002       (0u)

/**
 ******************************************************************************
 ** Global Device Package List
 ******************************************************************************/
// package definitions of HC device.
#define DDL_DEVICE_PACKAGE_HC_C         (0x00u)
#define DDL_DEVICE_PACKAGE_HC_F         (0x10u)
#define DDL_DEVICE_PACKAGE_HC_J         (0x20u)
#define DDL_DEVICE_PACKAGE_HC_K         (0x30u)

/******************************************************************************/
/* User Device Setting Include file                                           */
/******************************************************************************/
#include "ddl_device.h"  // MUST be included here!

/******************************************************************************/
/* Global type definitions ('typedef')                                        */
/******************************************************************************/
/**
 ******************************************************************************
 ** \brief Level
 **
 ** Specifies levels.
 **
 ******************************************************************************/
typedef enum en_level
{
    DdlLow      = 0u,  ///< Low level  '0'
    DdlHigh     = 1u   ///< High level '1'
} en_level_t;

/**
 ******************************************************************************
 ** \brief Generic Flag Code
 **
 ** Specifies flags.
 **
 ******************************************************************************/
typedef enum en_flag
{
    DdlClr = 0u,       ///< Flag clr '0'
    DdlSet = 1u        ///< Flag set '1'
} en_stat_flag_t, en_irq_flag_t;
/******************************************************************************/
/* Global variable declarations ('extern', definition in C source)            */
/******************************************************************************/

/******************************************************************************/
/* Global function prototypes ('extern', definition in C source)              */
/******************************************************************************/
/* Private function prototypes -----------------------------------------------*/
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)

/*******************************************************************************
 * Global function prototypes
 ******************************************************************************/
extern void ddl_memclr(void* pu8Address, uint32_t u32Count);
uint32_t Log2(uint32_t u32Val);
/**
 *******************************************************************************
 ** This hook is part of wait loops.
 ******************************************************************************/
void delay1ms(uint32_t u32Cnt);
void delay100us(uint32_t u32Cnt);
void delay10us(uint32_t u32Cnt);
void SetBit(uint32_t addr, uint32_t offset, boolean_t bFlag);
void ClrBit(uint32_t addr, uint32_t offset);
boolean_t GetBit(uint32_t addr, uint32_t offset);
#ifdef __cplusplus
}
#endif

#endif /* __DDL_H__ */

/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/

