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
 ** @file btim.h
 **
 ** @brief Header file for BTIM functions
 **
 ** @author MADS Team 
 **
 ******************************************************************************/

#ifndef __BTIM_H__
#define __BTIM_H__

/*****************************************************************************
 * Include files
 *****************************************************************************/
#include "ddl.h"


#ifdef __cplusplus
extern "C"
{
#endif

/**
 ******************************************************************************
 ** \defgroup BtGroup Base Timer (BT)
  **
 ******************************************************************************/
//@{
    
/******************************************************************************/
/* Global pre-processor symbols/macros ('#define')                            */
/******************************************************************************/

/******************************************************************************
 * Global type definitions
 ******************************************************************************/



/**
 *******************************************************************************
 ** \brief BTIMx 初始化配置的结构体
 ** \note       
 ******************************************************************************/
typedef struct stc_btim_init
{
    uint32_t       u32TaskMode;       //定时器计数模式选择：连续计数模式或单次计数模式
    uint32_t       u32WorkMode;       //工作模式：内部时钟计数、外部输入计数、触发模式、门控模式
    uint32_t       u32Prescaler;      //计数器输入信号分频
    uint32_t       u32ToggleEn;       //Toggle_N和Toggle_P输出使能
    uint32_t       u32TriggerSource;  //触发源选择，外部管脚ETR或者上一级BTIM溢出
    uint32_t       u32ExInputPolarity;//外部输入极性选择
    uint32_t       u32AutoReloadVal;  //配置重载寄存器的值
}stc_btim_init_t;


/** @defgroup stc_btim_init_t Single or Continuous  Count Mode: u32TaskMode (OST)
  * @{
  */
#define  BTIM_TASK_MODE_CONTINUOUS_COUNTER     (0x00000000UL)
#define  BTIM_TASK_MODE_ONESHOT_COUNTER        (BTIM_CR_OST)
/**
  * @}
  */

/** @defgroup stc_btim_init_t Work Mode: u32WorkMode (MD)
  * @{
  */
#define  BTIM_WORK_MODE_PCLK           (0x00000000UL)
#define  BTIM_WORK_MODE_EXTERNAL       (0x1 << BTIM_CR_MD_Pos)
#define  BTIM_WORK_MODE_TRIGGER        (0x2 << BTIM_CR_MD_Pos)
#define  BTIM_WORK_MODE_GATE           (BTIM_CR_MD)
/**
  * @}
  */

/** @defgroup stc_btim_init_t Clock devide: u32Prescaler (PRS)
  * @{
  */
#define  BTIM_COUNTER_CLK_DIV1        (0x00000000UL)
#define  BTIM_COUNTER_CLK_DIV2        (0x1 << BTIM_CR_PRS_Pos)
#define  BTIM_COUNTER_CLK_DIV4        (0x2 << BTIM_CR_PRS_Pos)
#define  BTIM_COUNTER_CLK_DIV8        (0x3 << BTIM_CR_PRS_Pos)
#define  BTIM_COUNTER_CLK_DIV16       (0x4 << BTIM_CR_PRS_Pos)
#define  BTIM_COUNTER_CLK_DIV32       (0x5 << BTIM_CR_PRS_Pos)
#define  BTIM_COUNTER_CLK_DIV64       (0x6 << BTIM_CR_PRS_Pos)
#define  BTIM_COUNTER_CLK_DIV128      (0x7 << BTIM_CR_PRS_Pos)
#define  BTIM_COUNTER_CLK_DIV256      (0x8 << BTIM_CR_PRS_Pos)
#define  BTIM_COUNTER_CLK_DIV512      (0x9 << BTIM_CR_PRS_Pos)
#define  BTIM_COUNTER_CLK_DIV1024     (0xA << BTIM_CR_PRS_Pos)
#define  BTIM_COUNTER_CLK_DIV2048     (0xB << BTIM_CR_PRS_Pos)
#define  BTIM_COUNTER_CLK_DIV4096     (0xC << BTIM_CR_PRS_Pos)
#define  BTIM_COUNTER_CLK_DIV8192     (0xD << BTIM_CR_PRS_Pos)
#define  BTIM_COUNTER_CLK_DIV16384    (0xE << BTIM_CR_PRS_Pos)
#define  BTIM_COUNTER_CLK_DIV32768    (BTIM_CR_PRS)
/**
  * @}
  */

/** @defgroup stc_btim_init_t Toggle ourput control: u32ToggleEn (TOGEN)
  * @{
  */
#define  BTIM_TOGGLE_DISABLE        (0x00000000UL)
#define  BTIM_TOGGLE_ENABLE         (BTIM_CR_TOGEN)
/**
  * @}
  */


/** @defgroup stc_btim_init_t Trigger Source Selection: u32TriggerSource (TRS)
  * @{
  */
#define  BTIM_TRIGGER_SOURCE_ETR           (0x00000000UL)
#define  BTIM_TRIGGER_SOURCE_TRGO          (0x1 << BTIM_CR_TRS_Pos)
/**
  * @}
  */

/** @defgroup stc_btim_init_t ETR Input Polarity: u32ExInputPolarity (ETP)
  * @{
  */
#define  BTIM_ETR_POLARITY_NORMAL            (0x00000000UL)
#define  BTIM_ETR_POLARITY_INVERTED          (BTIM_CR_ETP)
/**
  * @}
  */
    
/** @defgroup Interrupt Enable/Disable (IER)
  * @{
  */ 
#define BTIM_IT_UI        (BTIM_IER_UI)     //溢出中断使能控制
#define BTIM_IT_TI        (BTIM_IER_TI)     //触发中断使能控制
/**
  * @}
  */


/** @defgroup Interrupt Flag (IFR)
  * @{
  */
#define BTIM_IT_FLAG_UI        (BTIM_IFR_UI)     //溢出中断标志
#define BTIM_IT_FLAG_TI        (BTIM_IFR_TI)     //触发中断标志
/**
  * @}
  */

    
/** @defgroup Interrupt Clear Types (ICR)
  * @{
  */ 
#define BTIM_IT_CLR_UI        (BTIM_ICR_UI)     //清除溢出中断标志
#define BTIM_IT_CLR_TI        (BTIM_ICR_TI)     //清除触发中断标志
/**
  * @}
  */

/** @defgroup BTIM3/BTIM4/BTIM5 All Interrupt Flags (AIFR)
  * @{
  */ 
#define BTIM3_AIT_FLAG_UI        (BTIM_AIFR_UI3)     //BTIM3 溢出中断标志
#define BTIM3_AIT_FLAG_TI        (BTIM_AIFR_TI3)     //BTIM3 触发中断标志
#define BTIM4_AIT_FLAG_UI        (BTIM_AIFR_UI4)     //BTIM4 溢出中断标志
#define BTIM4_AIT_FLAG_TI        (BTIM_AIFR_TI4)     //BTIM4 触发中断标志
#define BTIM5_AIT_FLAG_UI        (BTIM_AIFR_UI5)     //BTIM5 溢出中断标志
#define BTIM5_AIT_FLAG_TI        (BTIM_AIFR_TI5)     //BTIM5 触发中断标志
/**
  * @}
  */

/** @defgroup BTIM3/BTIM4/BTIM5 All Interrupt Clear Reg (AICR)
  * @{
  */ 
#define BTIM3_AIT_CLR_UI        (BTIM_AICR_UI3)     //BTIM3 溢出中断标志
#define BTIM3_AIT_CLR_TI        (BTIM_AICR_TI3)     //BTIM3 触发中断标志
#define BTIM4_AIT_CLR_UI        (BTIM_AICR_UI4)     //BTIM4 溢出中断标志
#define BTIM4_AIT_CLR_TI        (BTIM_AICR_TI4)     //BTIM4 触发中断标志
#define BTIM5_AIT_CLR_UI        (BTIM_AICR_UI5)     //BTIM5 溢出中断标志
#define BTIM5_AIT_CLR_TI        (BTIM_AICR_TI5)     //BTIM5 触发中断标志
/**
  * @}
  */

/******************************************************************************
 * Global variable declarations ('extern', definition in C source)
 *****************************************************************************/

/******************************************************************************
 * Global function prototypes (definition in C source)
 *****************************************************************************/
//Btimer配置及初始化
en_result_t Btim_Init(BTIM_TypeDef* BTIMx, stc_btim_init_t* pstcInitCfg);
//Btimer设置/获取 计数值
void Btim_SetCounter(BTIM_TypeDef* BTIMx, uint16_t u16CntValue);
uint32_t Btim_GetCounter(BTIM_TypeDef* BTIMx);
//Btimer设置/获取 重载值
void Btim_SetAutoReload(BTIM_TypeDef* BTIMx, uint16_t u16AutoReload);
uint32_t Btim_GetAutoReload(BTIM_TypeDef* BTIMx);
//Btimer使能/禁止/查询 Gtimer启动
void Btim_Enable(BTIM_TypeDef *BTIMx);
void Btim_Disable(BTIM_TypeDef *BTIMx);
uint32_t Btim_IsEnable(BTIM_TypeDef *BTIMx);
//Btimer设置/查询 工作模式
void Btim_SetWorkMode(BTIM_TypeDef* BTIMx, uint32_t u32WorkMode);
uint32_t Btim_GetWorkMode(BTIM_TypeDef* BTIMx);
//Btimer设置/禁止/查询 TOG输出
void Btim_EnableToggle(BTIM_TypeDef *BTIMx);
void Btim_DisableToggle(BTIM_TypeDef *BTIMx);
uint32_t Btim_IsEnableToggle(BTIM_TypeDef *BTIMx);
//Bimer设置/获取 Btimer定时器时钟分频
void Btim_SetCounterClkDiv(BTIM_TypeDef* BTIMx, uint32_t u32CounterClkDiv);
uint32_t Btim_GetCounterClkDiv(BTIM_TypeDef* BTIMx);
//Btimer设置/查询 单次计数或者连续计数
void Btim_SetOneShotMode(BTIM_TypeDef* BTIMx, uint32_t u32Mode);
uint32_t Btim_GetOneShotMode(BTIM_TypeDef* BTIMx);
//Btimer设置/查询 触发源
void Btim_SetTriggerSource(BTIM_TypeDef* BTIMx, uint32_t u32TriggerSource);
uint32_t Btim_GetTriggerSource(BTIM_TypeDef* BTIMx);
//Btimer设置/查询 ETP外部引脚输入极性
void Btim_SetExInputPolarity(BTIM_TypeDef* BTIMx, uint32_t u32ExInputPolarity);
uint32_t Btim_GetExInputPolarity(BTIM_TypeDef* BTIMx);
//Btimer 使能/禁止/查询 溢出中断
void Btim_EnableIT(BTIM_TypeDef* BTIMx, uint32_t u32IntClrFlag);
void Btim_DisableIT(BTIM_TypeDef* BTIMx, uint32_t u32IntClrFlag);
uint32_t Btim_IsEnableIT(BTIM_TypeDef* BTIMx, uint32_t u32IntClrFlag);
//Btimer 查询中断标志
uint32_t Btim_IsActiveFlag(BTIM_TypeDef* BTIMx, uint32_t u32IntFlag);
uint32_t Btim_AIFR345_IsActiveFlag(BTIM_TypeDef* BTIMx, uint32_t u32IntFlag);
//Btimer 清除中断标志
void Btim_ClearFlag(BTIM_TypeDef* BTIMx, uint32_t u32IntClrFlag);
void Btim_AICR345_ClearFlag(BTIM_TypeDef* BTIMx, uint32_t u32IntClrFlag);



//@} // BtGroup

#ifdef __cplusplus
#endif


#endif /* __BT_H__ */
/******************************************************************************
 * EOF (not truncated)
 *****************************************************************************/


