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
 ** @file gtim.h
 **
 ** @brief Header file for GTIM functions
 **
 ** @author MADS Team 
 **
 ******************************************************************************/

#ifndef __GTIM_H__
#define __GTIM_H__

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
 ** \brief GTIMx 初始化配置的结构体
 ** \note       
 ******************************************************************************/
typedef struct stc_gtim_init
{
    uint32_t       u32TaskMode;        //定时器计数模式选择：连续计数模式或单次计数模式
    uint32_t       u32WorkMode;        //工作模式：内部时钟计数、外部输入计数、触发模式、门控模式
    uint32_t       u32Prescaler;       //计数器输入信号分频
    uint32_t       u32ToggleEn;        //Toggle_N和Toggle_P输出使能
    uint32_t       u32TriggerSource;   //触发源选择，外部管脚ETR或者上一级BTIM溢出
    uint32_t       u32ExInputPolarity; //外部输入极性选择
    uint32_t       u32AutoReloadVal;   //配置重载寄存器的值
}stc_gtim_init_t;

    
/** @defgroup stc_gtim_init_t u32TaskMode (OST)
  * @{
  */
#define  GTIM_TASK_MODE_CONTINUOUS_COUNTER     (0x00000000UL)
#define  GTIM_TASK_MODE_ONESHOT_COUNTER        (GTIM_CR0_OST)
/**
  * @}
  */
    
    
/** @defgroup stc_gtim_init_t u32CounterMode (MD) 
  * @{
  */
#define  GTIM_WORK_MODE_PCLK           (0x00000000UL)
#define  GTIM_WORK_MODE_EXTERNAL       (0x1 << GTIM_CR0_MD_Pos)
#define  GTIM_WORK_MODE_TRIGGER        (0x2 << GTIM_CR0_MD_Pos)
#define  GTIM_WORK_MODE_GATE           (GTIM_CR0_MD)
/**
  * @}
  */

    
/** @defgroup stc_gtim_init_t u32Prescaler (PRS)
  * @{
  */
#define  GTIM_COUNTER_CLK_DIV1        (0x00000000UL)
#define  GTIM_COUNTER_CLK_DIV2        (0x1 << GTIM_CR0_PRS_Pos)
#define  GTIM_COUNTER_CLK_DIV4        (0x2 << GTIM_CR0_PRS_Pos)
#define  GTIM_COUNTER_CLK_DIV8        (0x3 << GTIM_CR0_PRS_Pos)
#define  GTIM_COUNTER_CLK_DIV16       (0x4 << GTIM_CR0_PRS_Pos)
#define  GTIM_COUNTER_CLK_DIV32       (0x5 << GTIM_CR0_PRS_Pos)
#define  GTIM_COUNTER_CLK_DIV64       (0x6 << GTIM_CR0_PRS_Pos)
#define  GTIM_COUNTER_CLK_DIV128      (0x7 << GTIM_CR0_PRS_Pos)
#define  GTIM_COUNTER_CLK_DIV256      (0x8 << GTIM_CR0_PRS_Pos)
#define  GTIM_COUNTER_CLK_DIV512      (0x9 << GTIM_CR0_PRS_Pos)
#define  GTIM_COUNTER_CLK_DIV1024     (0xA << GTIM_CR0_PRS_Pos)
#define  GTIM_COUNTER_CLK_DIV2048     (0xB << GTIM_CR0_PRS_Pos)
#define  GTIM_COUNTER_CLK_DIV4096     (0xC << GTIM_CR0_PRS_Pos)
#define  GTIM_COUNTER_CLK_DIV8192     (0xD << GTIM_CR0_PRS_Pos)
#define  GTIM_COUNTER_CLK_DIV16384    (0xE << GTIM_CR0_PRS_Pos)
#define  GTIM_COUNTER_CLK_DIV32768    (GTIM_CR0_PRS)
/**
  * @}
  */
    

/** @defgroup stc_gtim_init_t u32ToggleEn (TOGEN)
  * @{
  */
#define  GTIM_TOGGLE_DISABLE        (0x00000000UL)
#define  GTIM_TOGGLE_ENABLE         (GTIM_CR0_TOGEN)
/**
  * @}
  */


/** @defgroup stc_gtim_init_t u32TriggerSource (TRS)
  * @{
  */
#define  GTIM_TRIGGER_SOURCE_ETR           (0x00000000UL)
#define  GTIM_TRIGGER_SOURCE_ATIM3_TRGO    (0x1 << GTIM_CR0_TRS_Pos)
/**
  * @}
  */

/** @defgroup stc_gtim_init_t u32ExInputPolarity (ETP)
  * @{
  */
#define  GTIM_ETR_POLARITY_NORMAL            (0x00000000UL)
#define  GTIM_ETR_POLARITY_INVERTED          (GTIM_CR0_ETP)
/**
  * @}
  */


/** @defgroup ETP External Input Filter u32ExInputFilter (ETRFLT)
  * @{
  */
#define  GTIM_ETR_FILTER_NONE                (0x00000000UL)
#define  GTIM_ETR_FILTER_PCLK_DIV1_CYCLE2    (0x1 << GTIM_CR1_ETRFLT_Pos)
#define  GTIM_ETR_FILTER_PCLK_DIV1_CYCLE4    (0x2 << GTIM_CR1_ETRFLT_Pos)
#define  GTIM_ETR_FILTER_PCLK_DIV1_CYCLE6    (0x3 << GTIM_CR1_ETRFLT_Pos)
#define  GTIM_ETR_FILTER_PCLK_DIV4_CYCLE4    (0x4 << GTIM_CR1_ETRFLT_Pos)
#define  GTIM_ETR_FILTER_PCLK_DIV4_CYCLE6    (0x5 << GTIM_CR1_ETRFLT_Pos)
#define  GTIM_ETR_FILTER_PCLK_DIV16_CYCLE4   (0x6 << GTIM_CR1_ETRFLT_Pos)
#define  GTIM_ETR_FILTER_PCLK_DIV16_CYCLE6   (GTIM_CR1_ETRFLT)
/**
  * @}
  */


/** @defgroup stc_gtim_compare_capture_cfg_t Capture or Compare Mode Config u32Channel u32Mode (CCMR)
  * @{
  */
#define  GTIM_COMPARE_CAPTURE_CH0                  0    //GTIM_CCR相对于CC0M的bit偏移位置
#define  GTIM_COMPARE_CAPTURE_CH1                  1    //GTIM_CCR相对于CC0M的bit偏移位置
#define  GTIM_COMPARE_CAPTURE_CH2                  2    //GTIM_CCR相对于CC0M的bit偏移位置
#define  GTIM_COMPARE_CAPTURE_CH3                  3   //GTIM_CCR相对于CC0M的bit偏移位置

#define  GTIM_COMPARE_CAPTURE_NONE                 (0x00000000UL)
#define  GTIM_COMPARE_CAPTURE_RISING               (0x1 << GTIM_CMMR_CC0M_Pos)
#define  GTIM_COMPARE_CAPTURE_FALLING              (0x2 << GTIM_CMMR_CC0M_Pos)
#define  GTIM_COMPARE_CAPTURE_RISING_FALLING       (0x3 << GTIM_CMMR_CC0M_Pos)
#define  GTIM_COMPARE_CAPTURE_FORCE_LOW_LEVEL      (0x4 << GTIM_CMMR_CC0M_Pos)
#define  GTIM_COMPARE_CAPTURE_FORCE_HIGH_LEVEL     (0x5 << GTIM_CMMR_CC0M_Pos)
#define  GTIM_COMPARE_CAPTURE_PWM_NORMAL           (0x6 << GTIM_CMMR_CC0M_Pos)
#define  GTIM_COMPARE_CAPTURE_PWM_INVERTED         (GTIM_CMMR_CC0M)
/**
  * @}
  */


/** @defgroup Interrupt Enable/Disable (IER)
  * @{
  */ 
#define GTIM_IT_UI        (GTIM_IER_UI)     //溢出中断使能控制
#define GTIM_IT_TI        (GTIM_IER_TI)     //触发中断使能控制
#define GTIM_IT_CC0      (GTIM_IER_CC0)     //GTIM捕获比较0中断使能控制
#define GTIM_IT_CC1      (GTIM_IER_CC1)     //GTIM捕获比较1中断使能控制
#define GTIM_IT_CC2      (GTIM_IER_CC2)     //GTIM捕获比较2中断使能控制
#define GTIM_IT_CC3      (GTIM_IER_CC3)     //GTIM捕获比较3中断使能控制
/**
  * @}
  */


/** @defgroup Interrupt Flag (IFR)
  * @{
  */
#define GTIM_IT_FLAG_UI        (GTIM_IFR_UI)     //溢出中断标志
#define GTIM_IT_FLAG_TI        (GTIM_IFR_TI)     //触发中断标志
#define GTIM_IT_FLAG_CC0      (GTIM_IFR_CC0)     //GTIM捕获比较0中断标志
#define GTIM_IT_FLAG_CC1      (GTIM_IFR_CC1)     //GTIM捕获比较1中断标志
#define GTIM_IT_FLAG_CC2      (GTIM_IFR_CC2)     //GTIM捕获比较2中断标志
#define GTIM_IT_FLAG_CC3      (GTIM_IFR_CC3)     //GTIM捕获比较3中断标志
/**
  * @}
  */

    
/** @defgroup Interrupt Clear Types (ICR)
  * @{
  */ 
#define GTIM_IT_CLR_UI        (GTIM_ICR_UI)     //清除溢出中断标志
#define GTIM_IT_CLR_TI        (GTIM_ICR_TI)     //清除触发中断标志
#define GTIM_IT_CLR_CC0      (GTIM_ICR_CC0)     //清除GTIM捕获比较0中断标志
#define GTIM_IT_CLR_CC1      (GTIM_ICR_CC1)     //清除GTIM捕获比较1中断标志
#define GTIM_IT_CLR_CC2      (GTIM_ICR_CC2)     //清除GTIM捕获比较2中断标志
#define GTIM_IT_CLR_CC3      (GTIM_ICR_CC3)     //清除GTIM捕获比较3中断标志
/**
  * @}
  */
/******************************************************************************
 * Global variable declarations ('extern', definition in C source)
 *****************************************************************************/

/******************************************************************************
 * Global function prototypes (definition in C source)
 *****************************************************************************/

//Gtimer配置及初始化
en_result_t Gtim_Init(stc_gtim_init_t* pstcInitCfg);
//Gtimer设置/获取 计数值
void Gtim_SetCounter(uint16_t u16CntValue);
uint32_t Gtim_GetCounter(void);
//Gtimer设置/获取 重载值
void Gtim_SetAutoReload(uint16_t u16AutoReload);
uint32_t Gtim_GetAutoReload(void);
//Gtimer使能/禁止/查询 Gtimer启动
void Gtim_Enable(void);
void Gtim_Disable(void);
uint32_t Gtim_IsEnable(void);
//Gtimer设置/查询 工作模式
void Gtim_SetWorkMode(uint32_t u32WorkMode);
uint32_t Gtim_GetWorkMode(void);
//Gtimer设置/禁止/查询 TOG输出
void Gtim_EnableToggle(void);
void Gtim_DisableToggle(void);
uint32_t Gtim_IsEnableToggle(void);
//Gtimer设置/获取 Gtimer定时器时钟分频
void Gtim_SetCounterClkDiv(uint32_t u32CounterClkDiv);
uint32_t Gtim_GetCounterClkDiv(void);
//Gtimer设置/查询 单次计数或者连续计数
void Gtim_SetTaskMode(uint32_t u32Mode);
uint32_t Gtim_GetTaskMode(void);
//Gtimer设置/查询 触发源
void Gtim_SetTriggerSource(uint32_t u32TriggerSource);
uint32_t Gtim_GetTriggerSource(void);
//Gtimer设置/查询 ETP外部引脚输入极性
void Gtim_SetExInputPolarity(uint32_t u32ExInputPolarity);
uint32_t Gtim_GetExInputPolarity(void);
//Gtimer设置/查询 ETP外部引脚输入滤波
void Gtim_SetExInputFilter(uint32_t u32ExInputFilter);
uint32_t Gtim_GetExInputFilter(void);
//Gtimer设置/查询 捕获比较模式
void Gtim_SetCompareCaptureMode(uint32_t u32Channel, uint32_t u32CaptureMode);
uint32_t Gtim_GetCompareCaptureMode(uint32_t u32Channel);
//Gtimer设置比较值/查询捕获值
void Gtim_SetCompareCaptureReg(uint32_t u32Channel, uint32_t u32Capture);
uint32_t Gtim_GetCompareCaptureReg(uint32_t u32Channel);
//Gtimer禁止 所有通道的捕获比较功能
void Gtim_DisableCompareCaptureAll(void);
//Gtimer 使能/禁止中断
void Gtim_EnableIT(uint32_t u32IT);
void Gtim_DisableIT(uint32_t u32IT);
//Gtimer 查询哪些中断是否使能
uint32_t Gtim_IsEnableIT(uint32_t u32IntEnableTypes);
//Gtimer 查询中断标志
uint32_t Gtim_IsActiveFlag(uint32_t u32IntFlagTypes);
//Gtimer 清除中断标志
void Gtim_ClearFlag(uint32_t u32IntClrFlag);

//@} // BtGroup

#ifdef __cplusplus
#endif


#endif /* __BT_H__ */
/******************************************************************************
 * EOF (not truncated)
 *****************************************************************************/


