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
 ** @file wwdt.h
 **
 ** @brief Header file for WWDT functions
 **
 ** @author MADS Team 
 **
 ******************************************************************************/

#ifndef __WWDT_H__
#define __WWDT_H__

#include "ddl.h"


/**
 ******************************************************************************
 ** \defgroup WdtGroup Watchdog Timer (WDT)
 **
 ******************************************************************************/
//@{

/******************************************************************************/
/* Global pre-processor symbols/macros ('#define')                            */
/******************************************************************************/

/******************************************************************************
 * Global type definitions
 ******************************************************************************/
typedef struct stc_wwdt_init
{
    uint32_t u32Prescaler;              ///< 看门狗计数时钟(PCLK)的分频 @ref WWDT_PCLK_Prescaler
    uint32_t u32Window;                 ///< 看门狗窗口值配置,取值范围必须为：[0x40u ~ 0x7Fu]
    uint32_t u32Counter;                ///< 看门狗计数值配置,取值范围必须为：[0x40u ~ 0x7Fu]
                                        ///< u32Window < u32ArrCounter时, IWDT工作于窗口看门狗模式
                                        ///< u32Window ≥ u32ArrCounter时, IWDT工作于独立看门狗模式
    uint32_t u32PreOverInt;             ///< 预溢出中断控制 @ref WWDT_Pre_Over_Int
} stc_wwdt_init_t;

/** @defgroup stc_wwdt_init_t WWDT_PCLK_Prescaler
  * @{
  */
#define WWDT_PCLK_DIV_4096                        (0U << WWDT_CR1_PRS_Pos)
#define WWDT_PCLK_DIV_8192                        (1U << WWDT_CR1_PRS_Pos)
#define WWDT_PCLK_DIV_16384                       (2U << WWDT_CR1_PRS_Pos)
#define WWDT_PCLK_DIV_32768                       (3U << WWDT_CR1_PRS_Pos)
#define WWDT_PCLK_DIV_65536                       (4U << WWDT_CR1_PRS_Pos)
#define WWDT_PCLK_DIV_131072                      (5U << WWDT_CR1_PRS_Pos)
#define WWDT_PCLK_DIV_262144                      (6U << WWDT_CR1_PRS_Pos)
#define WWDT_PCLK_DIV_524288                      (7U << WWDT_CR1_PRS_Pos)

/**
  * @}
  */

/** @defgroup stc_wwdt_init_t WWDT_Pre_Over_Int
  * @{
  */
#define WWDT_PRE_INT_ENABLE                     WWDT_CR1_IE
#define WWDT_PRE_INT_DISABLE                    (0U)


/**
  * @}
  */

///< WWDT 初始化配置
en_result_t WWDT_Init(stc_wwdt_init_t *pstcWwdtInit);

///< WWDT 启动
void WWDT_Start(void);

///< 喂狗处理
void WWDT_Feed(uint32_t u32Cnt);

///< 获取当前计数值
uint32_t WWDT_GetCnt(void);

///< WWDT 溢出标志获取
boolean_t WWDT_GetPreOverFlag(void);
///< WWDT 溢出标志清除
void WWDT_ClearPreOverFlag(void);
///< 运行状态获取
boolean_t WWDT_GetRunFlag(void);

///< 执行WWDT 复位
void WWDT_Reset(void);

//@} // WWDTGroup

#ifdef __cplusplus
#endif

#endif /* __WWDT_H__ */



