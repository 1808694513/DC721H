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
 ** @file iwdt.h
 **
 ** @brief Header file for IWDT functions
 **
 ** @author MADS Team 
 **
 ******************************************************************************/

#ifndef __IWDT_H__
#define __IWDT_H__

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
typedef struct stc_iwdt_init
{
    uint32_t u32Action;                 ///< 看门狗休眠模式及溢出后动作配置 @ref IWDT_Action
    uint32_t u32Prescaler;              ///< 看门狗计数时钟(RC10K)的分频 @ref IWDT_RC10K_Prescaler
    uint32_t u32Window;                 ///< 看门狗窗口值配置,取值范围必须为：[0u ~ 0xFFFu]
    uint32_t u32ArrCounter;             ///< 看门狗重载计数值配置,取值范围必须为：[0u ~ 0xFFFu]
                                        ///< u32Window < u32ArrCounter时, IWDT工作于窗口看门狗模式
                                        ///< u32Window ≥ u32ArrCounter时, IWDT工作于独立看门狗模式
} stc_iwdt_init_t;


/** @defgroup stc_iwdt_init_t IWDT_Action
  * @{
  */
#define IWDT_OVER_INT__SLEEPMODE_STOP           (IWDT_CR_ACTION | IWDT_CR_IE | IWDT_CR_PAUSE)
#define IWDT_OVER_RESET__SLEEPMODE_STOP         (IWDT_CR_PAUSE)
#define IWDT_OVER_INT__SLEEPMODE_RUN            (IWDT_CR_ACTION | IWDT_CR_IE)
#define IWDT_OVER_RESET__SLEEPMODE_RUN          (0U)

/**
  * @}
  */

/** @defgroup stc_iwdt_init_t IWDT_RC10K_Prescaler
  * @{
  */
#define IWDT_RC10K_DIV_4                        (0U)
#define IWDT_RC10K_DIV_8                        (1U)
#define IWDT_RC10K_DIV_16                       (2U)
#define IWDT_RC10K_DIV_32                       (3U)
#define IWDT_RC10K_DIV_64                       (4U)
#define IWDT_RC10K_DIV_128                      (5U)
#define IWDT_RC10K_DIV_256                      (6U)
#define IWDT_RC10K_DIV_512                      (7U)

/**
  * @}
  */

/** @defgroup IWDT_Flag
  * @{
  */
#define IWDT_FLAG_PRS                      IWDT_SR_PRSF
#define IWDT_FLAG_ARR                      IWDT_SR_ARRF
#define IWDT_FLAG_WINR                     IWDT_SR_WINRF
#define IWDT_FLAG_OVER                     IWDT_SR_OV
#define IWDT_FLAG_RUN                      IWDT_SR_RUN

/**
  * @}
  */

/**
  * @}
  */

///< IWDT 初始化配置
en_result_t IWDT_Init(stc_iwdt_init_t *pstcIwdtInit);

///< IWDT 开始和停止
void IWDT_Start(void);
void IWDT_Stop(void);
///< 喂狗处理
void IWDT_Feed(void);
///< IWDT 溢出标志获取
boolean_t IWDT_GetOverFlag(void);
///< IWDT 溢出标志清除
void IWDT_ClearOverFlag(void);
///< 运行状态获取
boolean_t IWDT_GetRunFlag(void);

//@} // IWDTGroup

#ifdef __cplusplus
#endif

#endif /* __IWDT_H__ */



