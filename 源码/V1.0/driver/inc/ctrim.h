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
 ** @file ctrim.h
 **
 ** @brief Header file for CTRIM functions
 **
 ** @author MADS Team 
 **
 ******************************************************************************/

#ifndef __CTRIM_H__
#define __CTRIM_H__

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
 ** \defgroup TrimGroup Clock Trimming (CTRIM)
 **
 ******************************************************************************/
//@{

/******************************************************************************
 ** Global pre-processor symbols/macros ('#define')                            
 ******************************************************************************/

/** @defgroup Bit definition
  * @{
  */
#define  CTRIM_CR0_STEP_0          (0x1<<CTRIM_CR0_STEP_Pos)
#define  CTRIM_CR0_STEP_1          (0x2<<CTRIM_CR0_STEP_Pos)
#define  CTRIM_CR0_STEP_2          (0x4<<CTRIM_CR0_STEP_Pos)

#define  CTRIM_CR0_ETRFLT_0        (0x1<<CTRIM_CR0_ETRFLT_Pos)
#define  CTRIM_CR0_ETRFLT_1        (0x2<<CTRIM_CR0_ETRFLT_Pos)
#define  CTRIM_CR0_ETRFLT_2        (0x4<<CTRIM_CR0_ETRFLT_Pos)

#define  CTRIM_CR0_SRC_0           (0x1<<CTRIM_CR0_SRC_Pos)
#define  CTRIM_CR0_SRC_1           (0x2<<CTRIM_CR0_SRC_Pos)
#define  CTRIM_CR0_SRC_2           (0x4<<CTRIM_CR0_SRC_Pos)

#define  CTRIM_CR1_MD_0            (0x1<<CTRIM_CR1_MD_Pos)
#define  CTRIM_CR1_MD_1            (0x2<<CTRIM_CR1_MD_Pos)

#define  CTRIM_CR1_PRS_0           (0x1<<CTRIM_CR1_PRS_Pos)
#define  CTRIM_CR1_PRS_1           (0x2<<CTRIM_CR1_PRS_Pos)
#define  CTRIM_CR1_PRS_2           (0x4<<CTRIM_CR1_PRS_Pos)
#define  CTRIM_CR1_PRS_3           (0x8<<CTRIM_CR1_PRS_Pos)
/**
  * @}
  */  

/** @defgroup CTRIM_INITIAL_STEP_SELECTION  TRIM初始步进量选择
  * @{
  */
#define  CTRIM_INITIAL_STEP_2      (CTRIM_CR0_STEP_0)
#define  CTRIM_INITIAL_STEP_4      (CTRIM_CR0_STEP_1)
#define  CTRIM_INITIAL_STEP_8      (CTRIM_CR0_STEP_0 | CTRIM_CR0_STEP_1)
#define  CTRIM_INITIAL_STEP_16     (0x00000000UL)
#define  CTRIM_INITIAL_STEP_32     (CTRIM_CR0_STEP_0 | CTRIM_CR0_STEP_2)
#define  CTRIM_INITIAL_STEP_64     (CTRIM_CR0_STEP_1 | CTRIM_CR0_STEP_2)
#define  CTRIM_INITIAL_STEP_128    (CTRIM_CR0_STEP_0 | CTRIM_CR0_STEP_1 | CTRIM_CR0_STEP_2)
/**
  * @}
  */  

/** @defgroup CTRIM_ETR_CLOCK_FILTER_SELECTION  外部管脚输入时钟滤波配置
  * @{
  */
#define  CTRIM_ETR_CLOCK_FILTER_NONE                (0x00000000UL)
#define  CTRIM_ETR_CLOCK_FILTER_PCLK_DIV1_CYCLE2    (CTRIM_CR0_ETRFLT_0)
#define  CTRIM_ETR_CLOCK_FILTER_PCLK_DIV1_CYCLE4    (CTRIM_CR0_ETRFLT_1)
#define  CTRIM_ETR_CLOCK_FILTER_PCLK_DIV1_CYCLE6    (CTRIM_CR0_ETRFLT_0 | CTRIM_CR0_ETRFLT_1)
#define  CTRIM_ETR_CLOCK_FILTER_PCLK_DIV4_CYCLE4    (CTRIM_CR0_ETRFLT_2)
#define  CTRIM_ETR_CLOCK_FILTER_PCLK_DIV4_CYCLE6    (CTRIM_CR0_ETRFLT_0 | CTRIM_CR0_ETRFLT_2)
#define  CTRIM_ETR_CLOCK_FILTER_PCLK_DIV8_CYCLE4    (CTRIM_CR0_ETRFLT_1 | CTRIM_CR0_ETRFLT_2)
#define  CTRIM_ETR_CLOCK_FILTER_PCLK_DIV8_CYCLE6    (CTRIM_CR0_ETRFLT_0 | CTRIM_CR0_ETRFLT_1 | CTRIM_CR0_ETRFLT_2)
/**
  * @}
  */  

/** @defgroup CTRIM_ACCURATE_CLOCK_SELECTION  精确时钟源选择
  * @{
  */
#define  CTRIM_ACCURATE_CLOCK_ETR                  (0x00000000UL)
#define  CTRIM_ACCURATE_CLOCK_PCLK                 (CTRIM_CR0_SRC_0 | CTRIM_CR0_SRC_1)
#define  CTRIM_ACCURATE_CLOCK_RCL                  (CTRIM_CR0_SRC_2)
#define  CTRIM_ACCURATE_CLOCK_RCH                  (CTRIM_CR0_SRC_0 | CTRIM_CR0_SRC_2)
/**
  * @}
  */  

/** @defgroup CTRIM_MODE_SELECTION  工作模式选择
  * @{
  */
#define  CTRIM_MODE_RCH_AUTO_TRIM      (CTRIM_CR1_AUTO)
#define  CTRIM_MODE_RCL_AUTO_TRIM      ((CTRIM_CR1_AUTO) | (CTRIM_CR1_MD_0))
#define  CTRIM_MODE_TIMER              (CTRIM_CR1_MD_1)
/**
  * @}
  */  

/** @defgroup CTRIM_TRIM_MODE  校准模式选择
  * @{
  */
#define  CTRIM_RCH_AUTO_TRIM           (CTRIM_CR1_AUTO)
#define  CTRIM_RCL_AUTO_TRIM           ((CTRIM_CR1_AUTO) | (CTRIM_CR1_MD_0))
/**
  * @}
  */  

/** @defgroup CTRIM_REF_CLOCK_DIV_SELECTION  参考时钟预分频配置
  * @{
  */
#define  CTRIM_REF_CLOCK_DIV2          (CTRIM_CR1_PRS_0)
#define  CTRIM_REF_CLOCK_DIV4          (CTRIM_CR1_PRS_1)
#define  CTRIM_REF_CLOCK_DIV8          (CTRIM_CR1_PRS_0 | CTRIM_CR1_PRS_1)
#define  CTRIM_REF_CLOCK_DIV16         (CTRIM_CR1_PRS_2)
#define  CTRIM_REF_CLOCK_DIV32         (CTRIM_CR1_PRS_0 | CTRIM_CR1_PRS_2)
#define  CTRIM_REF_CLOCK_DIV64         (CTRIM_CR1_PRS_1 | CTRIM_CR1_PRS_2)
#define  CTRIM_REF_CLOCK_DIV128        (CTRIM_CR1_PRS_0 | CTRIM_CR1_PRS_1 | CTRIM_CR1_PRS_2)
#define  CTRIM_REF_CLOCK_DIV512        (CTRIM_CR1_PRS_0 | CTRIM_CR1_PRS_3)
#define  CTRIM_REF_CLOCK_DIV1024       (CTRIM_CR1_PRS_1 | CTRIM_CR1_PRS_3)
#define  CTRIM_REF_CLOCK_DIV2048       (CTRIM_CR1_PRS_0 | CTRIM_CR1_PRS_1 | CTRIM_CR1_PRS_3)
#define  CTRIM_REF_CLOCK_DIV4096       (CTRIM_CR1_PRS_2 | CTRIM_CR1_PRS_3)
#define  CTRIM_REF_CLOCK_DIV8192       (CTRIM_CR1_PRS_0 | CTRIM_CR1_PRS_2 | CTRIM_CR1_PRS_3)
#define  CTRIM_REF_CLOCK_DIV16384      (CTRIM_CR1_PRS_1 | CTRIM_CR1_PRS_2 | CTRIM_CR1_PRS_3)
#define  CTRIM_REF_CLOCK_DIV32768      (CTRIM_CR1_PRS_0 | CTRIM_CR1_PRS_1 | CTRIM_CR1_PRS_2 | CTRIM_CR1_PRS_3)
/**
  * @}
  */  

/** @defgroup CTRIM_ONE_SHOT_SELECTION  校准模式配置
  * @{
  */
#define  CTRIM_ONE_SHOT_REPETITIVE     (0x00000000UL)   /*! 实时校准模式 */
#define  CTRIM_ONE_SHOT_SINGLE         (CTRIM_CR1_OST)  /*! 单次校准模式 */
/**
  * @}
  */  

/** @defgroup CTRIM_IT_SELECTION  中断控制位选择
  * @{
  */
#define  CTRIM_IT_UD                   (CTRIM_IER_UD)   /*! 误差计数器下溢 中断 */
#define  CTRIM_IT_END                  (CTRIM_IER_END)  /*! 自动Trim结束 中断 */
#define  CTRIM_IT_PS                   (CTRIM_IER_PS)   /*! 误差计数器完成(一次计数) 中断 */
#define  CTRIM_IT_MISS                 (CTRIM_IER_MISS) /*! 计数失败(在GCLK的一个周期内，误差计数器已计数到ARR) 中断 */
#define  CTRIM_IT_OV                   (CTRIM_IER_OV)   /*! TrimCode溢出(TrimCode已调整到0或者0x1FF) 中断 */
/**
  * @}
  */  

/** @defgroup CTRIM_FLAG_SELECTION  中断标志位选择
  * @{
  */
#define  CTRIM_FLAG_UD                 (CTRIM_ISR_UD)    /*! 误差计数器下溢 标志 */
#define  CTRIM_FLAG_END                (CTRIM_ISR_END)   /*! 自动Trim结束 标志 */
#define  CTRIM_FLAG_PS                 (CTRIM_ISR_PS)    /*! 误差计数器完成(一次计数) 标志 */
#define  CTRIM_FLAG_MISS               (CTRIM_ISR_MISS)  /*! 计数失败(在GCLK的一个周期内，误差计数器已计数到ARR) 标志 */
#define  CTRIM_FLAG_OV                 (CTRIM_ISR_OV)    /*! TrimCode溢出(TrimCode已调整到0或者0x1FF) 标志 */
#define  CTRIM_FLAG_OK                 (CTRIM_ISR_OK)    /*! Trim完成时精度满足FLIM要求 标志 */
/**
  * @}
  */  

/** @defgroup CTRIM_CLEAR_FLAG_SELECTION  清除中断标志位选择
  * @{
  */
#define  CTRIM_CLEAR_FLAG_UD           (CTRIM_ICR_UD)   /*! 误差计数器下溢 标志 */
#define  CTRIM_CLEAR_FLAG_END          (CTRIM_ICR_END)  /*! 自动Trim结束 标志 */
#define  CTRIM_CLEAR_FLAG_PS           (CTRIM_ICR_PS)   /*! 误差计数器完成(一次计数) 标志 */
#define  CTRIM_CLEAR_FLAG_MISS         (CTRIM_ICR_MISS) /*! 计数失败(在GCLK的一个周期内，误差计数器已计数到ARR) 标志 */
#define  CTRIM_CLEAR_FLAG_OV           (CTRIM_ICR_OV)   /*! TrimCode溢出(TrimCode已调整到0或者0x1FF) 标志 */
#define  CTRIM_CLEAR_FLAG_OK           (CTRIM_ICR_OK)   /*! Trim完成时精度满足FLIM要求 标志 */
/**
  * @}
  */  

/** @defgroup CTRIM_ARR_COUNT_DIR  误差计数器计数方向
  * @{
  */
#define  CTRIM_ARR_COUNT_DIR_INCREASE  (0x00000000UL)  /*! 递增计数，RCH输出频率高于目标频率，或RCL输出频率低于目标频率 */
#define  CTRIM_ARR_COUNT_DIR_DECREASE  (CTRIM_ISR_DIR) /*! 递减计数，RCH输出频率低于目标频率，或RCL输出频率高于目标频率 */

/******************************************************************************
 * Global type definitions
 ******************************************************************************/

/**
 ******************************************************************************
 ** \brief clock自动校准 配置结构体定义 
 *****************************************************************************/
typedef struct stc_ctrim_cali_init
{
    uint32_t    u32Mode;             /*! 校准模式  @ref CTRIM_TRIM_MODE */
    uint32_t    u32AccurateClock;    /*! 精确时钟源选择  @ref CTRIM_ACCURATE_CLOCK_SELECTION */
    uint32_t    u32RefClockDiv;      /*! 参考时钟分频  @ref CTRIM_REF_CLOCK_DIV_SELECTION */
    uint32_t    u32OneShot;          /*! 校准模式，实时校准或单次校准  @ref CTRIM_ONE_SHOT_SELECTION */
    uint32_t    u32InitialStep;      /*! TRIM初始步进量  @ref CTRIM_INITIAL_STEP_SELECTION */
    uint32_t    u32EtrFilter;        /*! 外部输入管脚滤波配置  @ref CTRIM_ETR_CLOCK_FILTER_SELECTION */
    uint16_t    u16ReloadVal;        /*! 自动装载寄存器ARR配置值 取值范围 0x0 ~ 0xFFFF */
    uint8_t     u8CountErrorLimit;   /*! 误差允许值  取值范围 0x0 ~ 0xFF */
}stc_ctrim_cali_init_t;

/**
 ******************************************************************************
 ** \brief clock自动校准 配置结构体定义 
 *****************************************************************************/
typedef struct stc_ctrim_timer_init
{
    uint32_t    u32Clock;            /*! 时钟源选择  @ref CTRIM_ACCURATE_CLOCK_SELECTION */
    uint32_t    u32ClockDiv;         /*! 时钟分频  @ref CTRIM_REF_CLOCK_DIV_SELECTION */
    uint32_t    u32EtrFilter;        /*! 外部输入管脚滤波配置  @ref CTRIM_ETR_CLOCK_FILTER_SELECTION */
    uint32_t    u32ReloadVal;        /*! 自动装载寄存器ARR配置值 取值范围 0x0 ~ 0xFFFF */
}stc_ctrim_timer_init_t;

/******************************************************************************
 * Global variable declarations ('extern', definition in C source)
 *****************************************************************************/

/******************************************************************************
 * Global function prototypes (definition in C source)
 *****************************************************************************/
 
 
///<<功能配置及操作函数
en_result_t CTRIM_CaliInit(CTRIM_TypeDef* CTRIMx, stc_ctrim_cali_init_t* pstcInitCfg);
en_result_t CTRIM_TimerInit(CTRIM_TypeDef* CTRIMx, stc_ctrim_timer_init_t* pstcInitCfg);
uint32_t CTRIM_GetCounter(CTRIM_TypeDef* CTRIMx);
void CTRIM_SetAutoReload(CTRIM_TypeDef* CTRIMx, uint32_t u32AutoReload);
uint32_t CTRIM_GetAutoReload(CTRIM_TypeDef* CTRIMx);
void CTRIM_SetInitialStep(CTRIM_TypeDef* CTRIMx, uint32_t u32TrimStep);
uint32_t CTRIM_GetInitialStep(CTRIM_TypeDef* CTRIMx);
void CTRIM_SetEtrClockFilter(CTRIM_TypeDef* CTRIMx, uint32_t u32ExClockFilter);
uint32_t CTRIM_GetEtrClockFilter(CTRIM_TypeDef* CTRIMx);
void CTRIM_SetAccurateClock(CTRIM_TypeDef* CTRIMx, uint32_t u32ClockSource);
uint32_t CTRIM_GetAccurateClock(CTRIM_TypeDef* CTRIMx);
void CTRIM_SetMode(CTRIM_TypeDef* CTRIMx, uint32_t u32Mode);
uint32_t CTRIM_GetMode(CTRIM_TypeDef* CTRIMx);
void CTRIM_SetRefClockDiv(CTRIM_TypeDef* CTRIMx, uint32_t u32RefClockDiv);
uint32_t CTRIM_GetRefClockDiv(CTRIM_TypeDef* CTRIMx);
void CTRIM_SetOneShot(CTRIM_TypeDef* CTRIMx, uint32_t u32OneShotMode);
uint32_t CTRIM_GetOneShot(CTRIM_TypeDef* CTRIMx);
uint32_t CTRIM_GetARRCoutDir(CTRIM_TypeDef* CTRIMx);
uint32_t CTRIM_GetTrimCode(CTRIM_TypeDef* CTRIMx);
uint32_t CTRIM_GetCountErrorCapture(CTRIM_TypeDef* CTRIMx);
void CTRIM_SetCountErrorLimit(CTRIM_TypeDef* CTRIMx, uint8_t u8ErrLimit);
uint8_t CTRIM_GetCountErrorLimit(CTRIM_TypeDef* CTRIMx);
void CTRIM_Enable(CTRIM_TypeDef *CTRIMx);
void CTRIM_Disable(CTRIM_TypeDef *CTRIMx);
uint32_t CTRIM_IsEnable(CTRIM_TypeDef *CTRIMx);
void CTRIM_EnableIT(CTRIM_TypeDef* CTRIMx, uint32_t u32IT);
void CTRIM_DisableIT(CTRIM_TypeDef* CTRIMx, uint32_t u32IT);
uint32_t CTRIM_IsEnableIT(ADC_TypeDef *CTRIMx, uint32_t u32IT);
uint32_t CTRIM_IsActiveFlag(CTRIM_TypeDef* CTRIMx, uint32_t u32ITFlag);
void CTRIM_ClearFlag(CTRIM_TypeDef* CTRIMx, uint32_t u32ITFlag);
void CTRIM_ClearFlag_ALL(CTRIM_TypeDef* CTRIMx);

//@} // CtrimGroup

#ifdef __cplusplus
#endif


#endif /* __CTRIM_H__ */
/******************************************************************************
 * EOF (not truncated)
 *****************************************************************************/


