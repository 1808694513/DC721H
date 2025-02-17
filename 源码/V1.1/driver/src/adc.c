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
 ** @file adc.c
 **
 ** @brief Source file for ADC functions
 **
 ** @author MADS Team 
 **
 ******************************************************************************/

/******************************************************************************
 * Include files
 ******************************************************************************/
#include "adc.h"

/**
 ******************************************************************************
 ** \addtogroup AdcGroup
 ******************************************************************************/
//@{

/******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/
  
/******************************************************************************
 * Global variable definitions (declared in header file with 'extern')
 ******************************************************************************/

/******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/******************************************************************************
 * Local function prototypes ('static')
 ******************************************************************************/

/******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/

/*****************************************************************************
 * Function implementation - global ('extern') and local ('static')
 *****************************************************************************/

/**
 * \brief
 *          ADC初始化
 *
 * \param   [in]  pstcAdcCfg  ADC配置指针
 *
 * \retval  en_result_t  Ok:  配置成功
 * \retval  en_result_t  ErrorInvalidParameter: 无效参数
 */
en_result_t ADC_Init(ADC_TypeDef *ADCx, stc_adc_cfg_t* pstcAdcCfg)
{
    if (NULL == pstcAdcCfg)
    {
        return ErrorInvalidParameter;
    }
    
    REG_MODIFY(ADCx->CR0, 
                 ADC_CR0_CKDIV
               | ADC_CR0_REF
               | ADC_CR0_SAM
               | ADC_CR0_EN
               , 
                 pstcAdcCfg->u32ClkDiv
               | pstcAdcCfg->u32RefVolSel
               | pstcAdcCfg->u32SampCycleSel
               | ADC_CR0_EN);
    
    REG_MODIFY(ADCx->CR1, ADC_CR1_CHSEL,  pstcAdcCfg->u32InputSource);
    
    REG_MODIFY(ADCx->EXTTRIGGER, ADC_EXTTRIGGER_TRIGSEL,  pstcAdcCfg->u32ExtTriggerSource);

    delay10us(1);
    return Ok;
}

/**
 ***********************************************************************************************
 ** \brief  设定ADC采样周期
 ** \param  [in] ADCx：ADC结构体变量
 ** \param  [in] 设定值如下：
 **         @arg @ref ADC_SAMPLINGTIME_6CYCLE
 **         @arg @ref ADC_SAMPLINGTIME_8CYCLE
 **         @arg @ref ADC_SAMPLINGTIME_11CYCLE
 **         @arg @ref ADC_SAMPLINGTIME_12CYCLE

 ** \retval NULL
 ***********************************************************************************************/
void ADC_SetSampCycle(ADC_TypeDef *ADCx, uint32_t u32SampCycle)
{
    REG_MODIFY(ADCx->CR0, ADC_CR0_SAM, u32SampCycle);
}

/**
 ***********************************************************************************************
 ** \brief  获取ADC采样周期
 ** \param  [in] ADCx：ADC结构体变量

 ** \retval [out] 返回值如下:
 **         @arg @ref ADC_SAMPLINGTIME_6CYCLE
 **         @arg @ref ADC_SAMPLINGTIME_8CYCLE
 **         @arg @ref ADC_SAMPLINGTIME_11CYCLE
 **         @arg @ref ADC_SAMPLINGTIME_12CYCLE
 ***********************************************************************************************/
uint32_t ADC_GetSampCycle(ADC_TypeDef *ADCx)
{
    return (uint32_t)(REG_READBITS(ADCx->CR0, ADC_CR0_SAM));    
}

/**
 ***********************************************************************************************
 ** \brief  设定ADC采样周期
 ** \param  [in] ADCx：ADC结构体变量
 ** \param  [in] 设定值如下：
 **         @arg @ref ADC_REF_VOLTAGE_EXREF
 **         @arg @ref ADC_REF_VOLTAGE_AVCC

 ** \retval NULL
 ***********************************************************************************************/
void ADC_SetRefVol(ADC_TypeDef *ADCx, uint32_t u32RefVol)
{
    REG_MODIFY(ADCx->CR0, ADC_CR0_REF, u32RefVol);
}

/**
 ***********************************************************************************************
 ** \brief  获取ADC采样周期
 ** \param  [in] ADCx：ADC结构体变量

 ** \retval [out] 返回值如下:
 **         @arg @ref ADC_REF_VOLTAGE_EXREF
 **         @arg @ref ADC_REF_VOLTAGE_AVCC
 ***********************************************************************************************/
uint32_t ADC_GetRefVol(ADC_TypeDef *ADCx)
{
    return (uint32_t)(REG_READBITS(ADCx->CR0, ADC_CR0_REF));    
}


/**
 ***********************************************************************************************
 ** \brief  设定ADC采样周期
 ** \param  [in] ADCx：ADC结构体变量
 ** \param  [in] 设定值如下：
 **         @arg @ref ADC_CLOCK_PCLK_DIV1
 **         @arg @ref ADC_CLOCK_PCLK_DIV2
 **         @arg @ref ADC_CLOCK_PCLK_DIV4
 **         @arg @ref ADC_CLOCK_PCLK_DIV8
 **         @arg @ref ADC_CLOCK_PCLK_DIV16
 **         @arg @ref ADC_CLOCK_PCLK_DIV32
 **         @arg @ref ADC_CLOCK_PCLK_DIV64
 **         @arg @ref ADC_CLOCK_PCLK_DIV128

 ** \retval NULL
 ***********************************************************************************************/
void ADC_SetClockDiv(ADC_TypeDef *ADCx, uint32_t u32ClockDiv)
{
    REG_MODIFY(ADCx->CR0, ADC_CR0_CKDIV, u32ClockDiv);
}

/**
 ***********************************************************************************************
 ** \brief  获取ADC采样周期
 ** \param  [in] ADCx：ADC结构体变量

 ** \retval [out] 返回值如下:
 **         @arg @ref ADC_CLOCK_PCLK_DIV1
 **         @arg @ref ADC_CLOCK_PCLK_DIV2
 **         @arg @ref ADC_CLOCK_PCLK_DIV4
 **         @arg @ref ADC_CLOCK_PCLK_DIV8
 **         @arg @ref ADC_CLOCK_PCLK_DIV16
 **         @arg @ref ADC_CLOCK_PCLK_DIV32
 **         @arg @ref ADC_CLOCK_PCLK_DIV64
 **         @arg @ref ADC_CLOCK_PCLK_DIV128
 ***********************************************************************************************/
uint32_t ADC_GetClockDiv(ADC_TypeDef *ADCx)
{
    return (uint32_t)(REG_READBITS(ADCx->CR0, ADC_CR0_CKDIV));    
}

/**
 ***********************************************************************************************
 ** \brief  启动 ADC单次转换
 ** \param  [in] ADCx：ADC结构体变量

 ** \retval NULL
 ***********************************************************************************************/
void ADC_StartSingleConversion(ADC_TypeDef *ADCx)
{
    REG_SETBITS(ADCx->START, ADC_START_START);
}

/**
 ***********************************************************************************************
 ** \brief  启动 ADC持续转换
 ** \param  [in] ADCx：ADC结构体变量

 ** \retval NULL
 ***********************************************************************************************/
void ADC_StartContinuousConversion(ADC_TypeDef *ADCx)
{
    REG_SETBITS(ADCx->ALLSTART, ADC_ALLSTART_START);
}

/**
 ***********************************************************************************************
 ** \brief  停止 ADC 持续转换
 ** \param  [in] ADCx：ADC结构体变量

 ** \retval NULL
 ***********************************************************************************************/
void ADC_StopContinuousConversion(ADC_TypeDef *ADCx)
{
    REG_CLEARBITS(ADCx->ALLSTART, ADC_ALLSTART_START);
}

/**
 ***********************************************************************************************
 ** \brief  配置ADC转换通道
 ** \param  [in] ADCx：ADC结构体变量
 ** \param  u32AdcSampInput   设定值如下：
 **         @arg @ref ADC_EXINPUT_PC04
 **         @arg @ref ADC_EXINPUT_PC06
 **         @arg @ref ADC_EXINPUT_PD02
 **         @arg @ref ADC_EXINPUT_PD03
 **         @arg @ref ADC_EXINPUT_PD04
 **         @arg @ref ADC_EXINPUT_PD05
 **         @arg @ref ADC_EXINPUT_PD06
 **         @arg @ref ADC_EXINPUT_PA01
 **         @arg @ref ADC_EXINPUT_PA02
 **         @arg @ref ADC_EXINPUT_PB05
 **         @arg @ref ADC_EXINPUT_PB04
 **         @arg @ref ADC_EXINPUT_PB02
 **         @arg @ref ADC_EXINPUT_PB01
 **         @arg @ref ADC_EXINPUT_PB00
 **         @arg @ref ADC_EXINPUT_VREF_0p9

 ** \retval NULL
 ***********************************************************************************************/
void ADC_SetInputSource(ADC_TypeDef *ADCx, uint32_t u32AdcSampInput)
{
    REG_MODIFY(ADCx->CR1, ADC_CR1_CHSEL, u32AdcSampInput);
}

/**
 ***********************************************************************************************
 ** \brief  获取 指定通道的输入选择
 ** \param  [in] ADCx：ADC结构体变量

 ** \retval [out] 返回值: 输入选择
 **         @arg @ref ADC_EXINPUT_PC04
 **         @arg @ref ADC_EXINPUT_PC06
 **         @arg @ref ADC_EXINPUT_PD02
 **         @arg @ref ADC_EXINPUT_PD03
 **         @arg @ref ADC_EXINPUT_PD04
 **         @arg @ref ADC_EXINPUT_PD05
 **         @arg @ref ADC_EXINPUT_PD06
 **         @arg @ref ADC_EXINPUT_PA01
 **         @arg @ref ADC_EXINPUT_PA02
 **         @arg @ref ADC_EXINPUT_PB05
 **         @arg @ref ADC_EXINPUT_PB04
 **         @arg @ref ADC_EXINPUT_PB02
 **         @arg @ref ADC_EXINPUT_PB01
 **         @arg @ref ADC_EXINPUT_PB00
 **         @arg @ref ADC_EXINPUT_VREF_0p9

 ***********************************************************************************************/
uint32_t ADC_GetInputSource(ADC_TypeDef *ADCx)
{
    return (uint32_t)(REG_READBITS(ADCx->CR1, ADC_CR1_CHSEL));    
}

/**
 ***********************************************************************************************
 ** \brief  获取 ADC转换结果
 ** \param  [in] ADCx：ADC结构体变量

 ** \retval [out] 返回值: 转换结果

 ***********************************************************************************************/
uint32_t ADC_GetResult(ADC_TypeDef *ADCx)
{
    return (uint32_t)(REG_READ(ADCx->RESULT));    
}

/**
 ***********************************************************************************************
 ** \brief  设定 ADC转换外部中断触发源
 ** \param  [in] ADCx：ADC结构体变量
 ** \param  [in] u32ExtTriggerSource：触发源，下面单个值或多个相或的值
 **         @arg @ref ADC_EXTTRIGGER_ATIM3    ATimer3触发ADC转换
 **         @arg @ref ADC_EXTTRIGGER_GTIM     GTimer溢出触发ADC转换
 **         @arg @ref ADC_EXTTRIGGER_PB03     PB03中断触发ADC转换
 **         @arg @ref ADC_EXTTRIGGER_PB04     PB04中断触发ADC转换
 **         @arg @ref ADC_EXTTRIGGER_PC03     PC03中断触发ADC转换
 **         @arg @ref ADC_EXTTRIGGER_PC04     PC04中断触发ADC转换
 **         @arg @ref ADC_EXTTRIGGER_PD03     PD03中断触发ADC转换
 **         @arg @ref ADC_EXTTRIGGER_PD04     PD04中断触发ADC转换

 ** \retval NULL
 ***********************************************************************************************/
void ADC_SetExtTriggerSource(ADC_TypeDef *ADCx, uint32_t u32ExtTriggerSource)
{
    REG_WRITE(ADCx->EXTTRIGGER, u32ExtTriggerSource);
}

/**
 ***********************************************************************************************
 ** \brief  获取  ADC转换外部中断触发源
 ** \param  [in] ADCx：ADC结构体变量

 ** \retval [out] 返回值: 触发源，下面单个值或多个相或的值
 **         @arg @ref ADC_EXTTRIGGER_ATIM3    ATimer3触发ADC转换
 **         @arg @ref ADC_EXTTRIGGER_GTIM     GTimer溢出触发ADC转换
 **         @arg @ref ADC_EXTTRIGGER_PB03     PB03中断触发ADC转换
 **         @arg @ref ADC_EXTTRIGGER_PB04     PB04中断触发ADC转换
 **         @arg @ref ADC_EXTTRIGGER_PC03     PC03中断触发ADC转换
 **         @arg @ref ADC_EXTTRIGGER_PC04     PC04中断触发ADC转换
 **         @arg @ref ADC_EXTTRIGGER_PD03     PD03中断触发ADC转换
 **         @arg @ref ADC_EXTTRIGGER_PD04     PD04中断触发ADC转换
 ***********************************************************************************************/
uint32_t ADC_GetExtTriggerSource(ADC_TypeDef *ADCx)
{
    return (uint32_t)(REG_READ(ADCx->EXTTRIGGER));    
}

/**
 ***********************************************************************************************
 ** \brief  开启ADC模块
 ** \param  [in] ADCx：ADC结构体变量

 ** \retval NULL
 ***********************************************************************************************/
void ADC_Enable(ADC_TypeDef *ADCx)
{
    REG_SETBITS(ADCx->CR0, ADC_CR0_EN);
}

/**
 ***********************************************************************************************
 ** \brief  禁止ADC模块
 ** \param  [in] ADCx：ADC结构体变量

 ** \retval NULL
 ***********************************************************************************************/
void ADC_Disable(ADC_TypeDef *ADCx)
{
    REG_CLEARBITS(ADCx->CR0, ADC_CR0_EN);    
}

/**
 ***********************************************************************************************
 ** \brief  检查ADC模块是否已开启
 ** \param  [in] ADCx：ADC结构体变量

 ** \retval [out] 0：未开启； 非0：已开启
 ***********************************************************************************************/
uint32_t ADC_IsEnable(ADC_TypeDef *ADCx)
{
    return (uint32_t)(REG_READBITS(ADCx->CR0, ADC_CR0_EN) == ADC_CR0_EN);    
}

/**
 ***********************************************************************************************
 ** \brief  获取 ADC一次转换完成标志
 ** \param  [in] ADCx：ADC结构体变量

 ** \retval [out] 返回值: 0或者1

 ***********************************************************************************************/
uint32_t ADC_IsActiveFlag_EOC(ADC_TypeDef *ADCx)
{
    return (REG_READBITS(ADCx->IFR, ADC_IFR_EOC) == ADC_IFR_EOC);    
}

/**
 ***********************************************************************************************
 ** \brief  清除ADC一次转换完成标志
 ** \param  [in] ADCx：ADC结构体变量

 ** \retval NULL
 ***********************************************************************************************/
void ADC_ClearFlag_EOC(ADC_TypeDef *ADCx)
{
    REG_CLEARBITS(ADCx->ICR, ADC_ICR_EOC);    
}

/**
 ***********************************************************************************************
 ** \brief  ADC一次转换完成 中断使能 
 ** \param  [in] ADCx：ADC结构体变量

 ** \retval NULL
 ***********************************************************************************************/
void ADC_EnableIT_EOC(ADC_TypeDef *ADCx)
{
    REG_SETBITS(ADCx->IER, ADC_IER_EOC);
}

/**
 ***********************************************************************************************
 ** \brief  ADC一次转换完成 中断禁止
 ** \param  [in] ADCx：ADC结构体变量

 ** \retval NULL
 ***********************************************************************************************/
void ADC_DisableIT_EOC(ADC_TypeDef *ADCx)
{
    REG_CLEARBITS(ADCx->IER, ADC_IER_EOC);    
}

/**
 ***********************************************************************************************
 ** \brief  检查 ADC一次转换完成 是否已使能
 ** \param  [in] ADCx：ADC结构体变量

 ** \retval [out] 0：未开启； 非0：已开启
 ***********************************************************************************************/
uint32_t ADC_IsEnableIT_EOC(ADC_TypeDef *ADCx)
{
    return (uint32_t)(REG_READBITS(ADCx->IER, ADC_IER_EOC) == ADC_IER_EOC);    
}


//@} // AdcGroup


/******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/

