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
 ** @file adc.h
 **
 ** @brief Header file for ADC functions
 **
 ** @author MADS Team 
 **
 ******************************************************************************/

#ifndef __ADC_H__
#define __ADC_H__


/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "ddl.h"


/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif

/**
 ******************************************************************************
 ** \defgroup AdcGroup AD Converter (ADC)
  **
 ******************************************************************************/
 
//@{

/******************************************************************************
 * Global definitions
 ******************************************************************************/
/** @defgroup Bit definition
  * @{
  */
#define ADC_CR0_SAM_0             (0x1UL<<ADC_CR0_SAM_Pos)
#define ADC_CR0_SAM_1             (0x2UL<<ADC_CR0_SAM_Pos)
                                 
#define ADC_CR0_REF_0             (0x1UL<<ADC_CR0_REF_Pos)
#define ADC_CR0_REF_1             (0x2UL<<ADC_CR0_REF_Pos)
                                 
#define ADC_CR0_CKDIV_0           (0x1UL<<ADC_CR0_CKDIV_Pos)
#define ADC_CR0_CKDIV_1           (0x2UL<<ADC_CR0_CKDIV_Pos)
#define ADC_CR0_CKDIV_2           (0x4UL<<ADC_CR0_CKDIV_Pos)
                                 
#define ADC_CR1_CHSEL_0           (0x1UL<<ADC_CR1_CHSEL_Pos)
#define ADC_CR1_CHSEL_1           (0x2UL<<ADC_CR1_CHSEL_Pos)
#define ADC_CR1_CHSEL_2           (0x4UL<<ADC_CR1_CHSEL_Pos)
#define ADC_CR1_CHSEL_3           (0x8UL<<ADC_CR1_CHSEL_Pos)

#define ADC_EXTTRIGGER_TRIGSEL_0  (0x1UL<<ADC_EXTTRIGGER_TRIGSEL_Pos)
#define ADC_EXTTRIGGER_TRIGSEL_1  (0x2UL<<ADC_EXTTRIGGER_TRIGSEL_Pos)
#define ADC_EXTTRIGGER_TRIGSEL_2  (0x4UL<<ADC_EXTTRIGGER_TRIGSEL_Pos)
#define ADC_EXTTRIGGER_TRIGSEL_3  (0x8UL<<ADC_EXTTRIGGER_TRIGSEL_Pos)
/**
  * @}
  */  

/** @defgroup ADC_SAMPLINGTIME_CYCLE_SELECTION  ADC采样周期选择
  * @{
  */
#define ADC_SAMPLINGTIME_6CYCLE   ((uint32_t)0x00000000U)
#define ADC_SAMPLINGTIME_8CYCLE   (ADC_CR0_SAM_0)
#define ADC_SAMPLINGTIME_11CYCLE  (ADC_CR0_SAM_1)
#define ADC_SAMPLINGTIME_12CYCLE  (ADC_CR0_SAM_0 | ADC_CR0_SAM_1)
/**
  * @}
  */  

/** @defgroup ADC_REF_VOLTAGE_SELECTION  ADC 参考电压选择
  * @{
  */
#define ADC_REF_VOLTAGE_EXREF     ((uint32_t)0x00000000U)         /*!< 外部参考电压ExRef(PB01) */
#define ADC_REF_VOLTAGE_AVCC      (ADC_CR0_REF_0)                /*!< AVCC电压                */
/**
  * @}
  */
  
/** @defgroup ADC_CLOCK_SELECTION  ADC 时钟选择
  * @{
  */
#define ADC_CLOCK_PCLK_DIV1       ((uint32_t)0x00000000U)
#define ADC_CLOCK_PCLK_DIV2       (ADC_CR0_CKDIV_0)
#define ADC_CLOCK_PCLK_DIV4       (ADC_CR0_CKDIV_1)
#define ADC_CLOCK_PCLK_DIV8       (ADC_CR0_CKDIV_0 | ADC_CR0_CKDIV_1)
#define ADC_CLOCK_PCLK_DIV16      (ADC_CR0_CKDIV_2)
#define ADC_CLOCK_PCLK_DIV32      (ADC_CR0_CKDIV_0 | ADC_CR0_CKDIV_2)
#define ADC_CLOCK_PCLK_DIV64      (ADC_CR0_CKDIV_1 | ADC_CR0_CKDIV_2)
#define ADC_CLOCK_PCLK_DIV128     (ADC_CR0_CKDIV_0 | ADC_CR0_CKDIV_1 | ADC_CR0_CKDIV_2)
/**
  * @}
  */

/** @defgroup ADC_EXINPUT_SELECTION  通道输入信号选择
  * @{
  */
#define ADC_EXINPUT_PC04          ((uint32_t)0x00000000U)
#define ADC_EXINPUT_PC06          (ADC_CR1_CHSEL_0)
#define ADC_EXINPUT_PD02          (ADC_CR1_CHSEL_1)
#define ADC_EXINPUT_PD03          (ADC_CR1_CHSEL_0 | ADC_CR1_CHSEL_1)
#define ADC_EXINPUT_PD04          (ADC_CR1_CHSEL_2)
#define ADC_EXINPUT_PD05          (ADC_CR1_CHSEL_0 | ADC_CR1_CHSEL_2)
#define ADC_EXINPUT_PD06          (ADC_CR1_CHSEL_1 | ADC_CR1_CHSEL_2)
#define ADC_EXINPUT_PA01          (ADC_CR1_CHSEL_0 | ADC_CR1_CHSEL_1 | ADC_CR1_CHSEL_2)
#define ADC_EXINPUT_PA02          (ADC_CR1_CHSEL_3)
#define ADC_EXINPUT_PB05          (ADC_CR1_CHSEL_0 | ADC_CR1_CHSEL_3)
#define ADC_EXINPUT_PB04          (ADC_CR1_CHSEL_1 | ADC_CR1_CHSEL_3)
#define ADC_EXINPUT_PB02          (ADC_CR1_CHSEL_0 | ADC_CR1_CHSEL_1 | ADC_CR1_CHSEL_3)
#define ADC_EXINPUT_PB01          (ADC_CR1_CHSEL_2 | ADC_CR1_CHSEL_3)
#define ADC_EXINPUT_PB00          (ADC_CR1_CHSEL_0 | ADC_CR1_CHSEL_2 | ADC_CR1_CHSEL_3)
#define ADC_EXINPUT_VREF_0p9      (ADC_CR1_CHSEL_1 | ADC_CR1_CHSEL_2 | ADC_CR1_CHSEL_3)
/**
  * @}
  */

/** @defgroup ADC_EXTTRIGGER_SELECTION  外部触发ADC转换源选择
  * @{
  */
#define ADC_EXTTRIGGER_ATIM3      ((uint32_t)0x00000000U)          /*!< ATimer3触发ADC转换 */
#define ADC_EXTTRIGGER_GTIM       (ADC_EXTTRIGGER_TRIGSEL_0)       /*!< GTimer溢出触发ADC转换 */
#define ADC_EXTTRIGGER_PB03       (ADC_EXTTRIGGER_TRIGSEL_1)       /*!< PB03中断触发ADC转换 */
#define ADC_EXTTRIGGER_PB04       (ADC_EXTTRIGGER_TRIGSEL_0 | ADC_EXTTRIGGER_TRIGSEL_1)        /*!< PB04中断触发ADC转换 */
#define ADC_EXTTRIGGER_PC03       (ADC_EXTTRIGGER_TRIGSEL_2)                                   /*!< PC03中断触发ADC转换 */
#define ADC_EXTTRIGGER_PC04       (ADC_EXTTRIGGER_TRIGSEL_0 | ADC_EXTTRIGGER_TRIGSEL_2)        /*!< PC04中断触发ADC转换 */
#define ADC_EXTTRIGGER_PD03       (ADC_EXTTRIGGER_TRIGSEL_1 | ADC_EXTTRIGGER_TRIGSEL_2)        /*!< PD03中断触发ADC转换 */
#define ADC_EXTTRIGGER_PD04       (ADC_EXTTRIGGER_TRIGSEL_0 | ADC_EXTTRIGGER_TRIGSEL_1 | ADC_EXTTRIGGER_TRIGSEL_2) /*!< PD04中断触发ADC转换 */
/**
  * @}
  */
  
/******************************************************************************
 ** Global type definitions
 *****************************************************************************/

/******************************************************************************
 ** Extern type definitions ('typedef')
 ******************************************************************************/

/**
 ******************************************************************************
 ** \brief  ADC初始化配置结构体
 *****************************************************************************/
typedef struct stc_adc_cfg
{    
    uint32_t        u32ClkDiv;                /*! ADC时钟选择  @ref ADC_CLOCK_SELECTION */
    uint32_t        u32SampCycleSel;          /*! ADC采样周期选择  @ref ADC_SAMPLINGTIME_CYCLE_SELECTION */
    uint32_t        u32RefVolSel;             /*! ADC参考电压选择  @ref ADC_REF_VOLTAGE_SELECTION */
    uint32_t        u32InputSource;           /*! ADC输入信号选择  @ref ADC_EXINPUT_SELECTION */
    uint32_t        u32ExtTriggerSource;      /*! ADC外部触发源选择  @ref ADC_EXTTRIGGER_SELECTION */
}stc_adc_cfg_t;



/******************************************************************************
 * Global variable definitions ('extern')
 ******************************************************************************/

/******************************************************************************
 * Global function prototypes (definition in C source)
 ******************************************************************************/
//ADC 初始化
en_result_t ADC_Init(ADC_TypeDef *ADCx, stc_adc_cfg_t* pstcAdcCfg);
void ADC_SetSampCycle(ADC_TypeDef *ADCx, uint32_t u32SampCycle);
uint32_t ADC_GetSampCycle(ADC_TypeDef *ADCx);
void ADC_SetRefVol(ADC_TypeDef *ADCx, uint32_t u32RefVol);
uint32_t ADC_GetRefVol(ADC_TypeDef *ADCx);
void ADC_SetClockDiv(ADC_TypeDef *ADCx, uint32_t u32ClockDiv);
uint32_t ADC_GetClockDiv(ADC_TypeDef *ADCx);
void ADC_StartSingleConversion(ADC_TypeDef *ADCx);
void ADC_StartContinuousConversion(ADC_TypeDef *ADCx);
void ADC_StopContinuousConversion(ADC_TypeDef *ADCx);
void ADC_SetInputSource(ADC_TypeDef *ADCx, uint32_t u32AdcSampInput);
uint32_t ADC_GetInputSource(ADC_TypeDef *ADCx);
uint32_t ADC_GetResult(ADC_TypeDef *ADCx);
void ADC_SetExtTriggerSource(ADC_TypeDef *ADCx, uint32_t u32ExtTriggerSource);
uint32_t ADC_GetExtTriggerSource(ADC_TypeDef *ADCx);
void ADC_Enable(ADC_TypeDef *ADCx);
void ADC_Disable(ADC_TypeDef *ADCx);
uint32_t ADC_IsEnable(ADC_TypeDef *ADCx);
uint32_t ADC_IsActiveFlag_EOC(ADC_TypeDef *ADCx);
void ADC_ClearFlag_EOC(ADC_TypeDef *ADCx);
void ADC_EnableIT_EOC(ADC_TypeDef *ADCx);
void ADC_DisableIT_EOC(ADC_TypeDef *ADCx);
uint32_t ADC_IsEnableIT_EOC(ADC_TypeDef *ADCx);


//@}
#ifdef __cplusplus
}
#endif

#endif /* __ADC_H__ */
/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
