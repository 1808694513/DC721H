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
 ** @file lvd.h
 **
 ** @brief Header file for LVD functions
 **
 ** @author MADS Team 
 **
 ******************************************************************************/

#ifndef __LVD_H__
#define __LVD_H__

/******************************************************************************
 * Include files
 ******************************************************************************/
#include "ddl.h"


/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif

/**
 ******************************************************************************
 ** \defgroup LvdGroup Low Voltage Detector (LVD)
 **
 ******************************************************************************/
//@{

/******************************************************************************
 * Global type definitions
 ******************************************************************************/
/** @defgroup Bit definition
  * @{
  */
#define LVD_CR_SOURCE_0      (0x1UL << LVD_CR_SOURCE_Pos)
#define LVD_CR_SOURCE_1      (0x2UL << LVD_CR_SOURCE_Pos)

#define LVD_CR_VTDS_0        (0x1UL << LVD_CR_VTDS_Pos)
#define LVD_CR_VTDS_1        (0x2UL << LVD_CR_VTDS_Pos)
#define LVD_CR_VTDS_2        (0x4UL << LVD_CR_VTDS_Pos)
#define LVD_CR_VTDS_3        (0x8UL << LVD_CR_VTDS_Pos)

#define  LVD_CR_FLTTIME_0    (0x1UL<<LVD_CR_FLTTIME_Pos)
#define  LVD_CR_FLTTIME_1    (0x2UL<<LVD_CR_FLTTIME_Pos)
#define  LVD_CR_FLTTIME_2    (0x4UL<<LVD_CR_FLTTIME_Pos)
/**
  * @}
  */ 
  
/** @defgroup LVD_TRIGGER_ACTION_SELECTION  触发动作选择
  * @{
  */
#define LVD_TRIGGER_ACTION_INT         (0x00000000UL)      /*!< 触发动作 NVIC中断 */
#define LVD_TRIGGER_ACTION_RESET       (LVD_CR_ACT)        /*!< 触发动作 系统复位 */
/**
  * @}
  */

/** @defgroup LVD_TRIGGER_MODE_SELECTION  触发模式选择
  * @{
  */
#define  LVD_TRIGGER_MODE_HIGHLEVEL    (LVD_CR_HTEN)  /*!< 输入端被监测电压低于阈值电压(LVD输出端高电平)触发 */
#define  LVD_TRIGGER_MODE_RISING       (LVD_CR_RTEN)  /*!< 输入端被监测电压从高于阈值电压变为低于阈值电压(LVD输出端上升沿)触发 */
#define  LVD_TRIGGER_MODE_FALLING      (LVD_CR_FTEN)  /*!< 输入端被监测电压从低于阈值电压变为高于阈值电压(LVD输出端下降沿)触发 */
/**
  * @}
  */

/** @defgroup LVD_INPUT_SELECTION  LVD输入监测源配置
  * @{
  */
#define LVD_INPUT_AVCC                 (0x00000000UL)
#define LVD_INPUT_PA03                 (LVD_CR_SOURCE_0)
#define LVD_INPUT_PC03                 (LVD_CR_SOURCE_1)
#define LVD_INPUT_PD04                 (LVD_CR_SOURCE_0 | LVD_CR_SOURCE_1)
/**
  * @}
  */

/** @defgroup LVD_THRESHOLD_VOLT_SELECTION  阈值电压选择
  * @{
  */
#define LVD_THRESHOLD_VOLT1p8V         (0x00000000UL)
#define LVD_THRESHOLD_VOLT1p9V         (LVD_CR_VTDS_0)
#define LVD_THRESHOLD_VOLT2p0V         (LVD_CR_VTDS_1)
#define LVD_THRESHOLD_VOLT2p1V         (LVD_CR_VTDS_0 | LVD_CR_VTDS_1)
#define LVD_THRESHOLD_VOLT2p2V         (LVD_CR_VTDS_2)
#define LVD_THRESHOLD_VOLT2p3V         (LVD_CR_VTDS_0 | LVD_CR_VTDS_2)
#define LVD_THRESHOLD_VOLT2p4V         (LVD_CR_VTDS_1 | LVD_CR_VTDS_2)
#define LVD_THRESHOLD_VOLT2p5V         (LVD_CR_VTDS_0 | LVD_CR_VTDS_1 | LVD_CR_VTDS_2)
#define LVD_THRESHOLD_VOLT2p6V         (LVD_CR_VTDS_3)
#define LVD_THRESHOLD_VOLT2p7V         (LVD_CR_VTDS_0 | LVD_CR_VTDS_3)
#define LVD_THRESHOLD_VOLT2p8V         (LVD_CR_VTDS_1 | LVD_CR_VTDS_3)
#define LVD_THRESHOLD_VOLT2p9V         (LVD_CR_VTDS_0 | LVD_CR_VTDS_1 | LVD_CR_VTDS_3)
#define LVD_THRESHOLD_VOLT3p0V         (LVD_CR_VTDS_2 | LVD_CR_VTDS_3)
#define LVD_THRESHOLD_VOLT3p1V         (LVD_CR_VTDS_0 | LVD_CR_VTDS_2 | LVD_CR_VTDS_3)
#define LVD_THRESHOLD_VOLT3p2V         (LVD_CR_VTDS_1 | LVD_CR_VTDS_2 | LVD_CR_VTDS_3)
#define LVD_THRESHOLD_VOLT3p3V         (LVD_CR_VTDS_0 | LVD_CR_VTDS_1 | LVD_CR_VTDS_2 | LVD_CR_VTDS_3)
/**
  * @}
  */

/** @defgroup LVD_FILTER_SELECTION  数字滤波时间配置
  * @{
  */
#define  LVD_FILTER_NONE               (0x00000000UL)
#define  LVD_FILTER_1CYCLE             (LVD_CR_FLTEN) | (0x00000000UL)
#define  LVD_FILTER_3CYCLE             (LVD_CR_FLTEN) | (LVD_CR_FLTTIME_0)
#define  LVD_FILTER_7CYCLE             (LVD_CR_FLTEN) | (LVD_CR_FLTTIME_1)
#define  LVD_FILTER_15CYCLE            (LVD_CR_FLTEN) | (LVD_CR_FLTTIME_0 | LVD_CR_FLTTIME_1)
#define  LVD_FILTER_63CYCLE            (LVD_CR_FLTEN) | (LVD_CR_FLTTIME_2)
#define  LVD_FILTER_255CYCLE           (LVD_CR_FLTEN) | (LVD_CR_FLTTIME_0 | LVD_CR_FLTTIME_2)
#define  LVD_FILTER_1023CYCLE          (LVD_CR_FLTEN) | (LVD_CR_FLTTIME_1 | LVD_CR_FLTTIME_2)
#define  LVD_FILTER_4095CYCLE          (LVD_CR_FLTEN) | (LVD_CR_FLTTIME_0 | LVD_CR_FLTTIME_1 | LVD_CR_FLTTIME_2)
/**
  * @}
  */
  
/**
 ******************************************************************************
 ** \brief LVD配置
 ** \note
 ******************************************************************************/
typedef struct stc_lvd_init
{
    uint32_t      u32TriggerAction;    /*! LVD触发动作,中断或复位  @ref LVD_TRIGGER_ACTION_SELECTION */
    uint32_t      u32TriggerMode;      /*! LVD触发动作,中断或复位  @ref LVD_TRIGGER_MODE_SELECTION */
    uint32_t      u32InputSource;      /*! LVD输入电压源  @ref LVD_INPUT_SELECTION */
    uint32_t      u32ThresholdVolt;    /*! LVD阈值电压  @ref LVD_THRESHOLD_VOLT_SELECTION */
    uint32_t      u32Filter;           /*! 输出滤波配置  @ref LVD_FILTER_SELECTION */
}stc_lvd_init_t;

/******************************************************************************
 * Global definitions
 ******************************************************************************/

/******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/******************************************************************************
 * Global variable definitions ('extern')
 ******************************************************************************/

/******************************************************************************
 * Global function prototypes (definition in C source)
 ******************************************************************************/
//init/deinit function
en_result_t LVD_Init(LVD_TypeDef *LVDx, stc_lvd_init_t *pstcInitCfg);
void LVD_Enable(LVD_TypeDef *LVDx);
void LVD_Disable(LVD_TypeDef *LVDx);
uint32_t LVD_IsEnable(LVD_TypeDef *LVDx);
void LVD_SetTriggerAction(LVD_TypeDef *LVDx, uint32_t u32TriggerAction);
uint32_t LVD_GetTriggerAction(LVD_TypeDef *LVDx);
void LVD_SetTriggerMode(LVD_TypeDef *LVDx, uint32_t u32TriggerMode);
uint32_t LVD_GetTriggerMode(LVD_TypeDef *LVDx);
void LVD_SetInputSource(LVD_TypeDef *LVDx, uint32_t u32InputSource);
uint32_t LVD_GetInputSource(LVD_TypeDef *LVDx);
void LVD_SetThresholdVolt(LVD_TypeDef *LVDx, uint32_t u32ThresholdVolt);
uint32_t LVD_GetThresholdVolt(LVD_TypeDef *LVDx);
void LVD_EnableFilter(LVD_TypeDef *LVDx);
void LVD_DisableFilter(LVD_TypeDef *LVDx);
uint32_t LVD_IsEnableFilter(LVD_TypeDef *LVDx);
void LVD_SetFilter(LVD_TypeDef *LVDx, uint32_t u32Filter);
uint32_t LVD_GetFilter(LVD_TypeDef *LVDx);
uint32_t LVD_GetFilterOutput(LVD_TypeDef *LVDx);
void LVD_EnableIT(LVD_TypeDef *LVDx);
void LVD_DisableIT(LVD_TypeDef *LVDx);
uint32_t LVD_IsEnableIT(LVD_TypeDef *LVDx);
uint32_t LVD_IsActiveFlag_IT(LVD_TypeDef *LVDx);
void LVD_ClearFlag_IT(LVD_TypeDef *LVDx);


//@} // LvdGroup

#ifdef __cplusplus
}
#endif

#endif /* __LVD_H__ */
/******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
