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
 ** @file lvd.c
 **
 ** @brief Source file for LVD functions
 **
 ** @author MADS Team 
 **
 ******************************************************************************/

/******************************************************************************
 * Include files
 ******************************************************************************/
#include "lvd.h"

/**
 ******************************************************************************
 ** \addtogroup LvdGroup
 ******************************************************************************/
//@{

/******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/

#define IS_VALID_INPUT(x)       ( (x) <= LvdInputPB07 )

#define IS_VALID_THRESHOLD(x)   ( (x) <= LvdTH3p3V )

#define IS_VALID_FILTER(x)      ( (x) <= LvdFilter29ms )

#define IS_VALID_IRQTYPE(x)     ( (x) <= LvdIrqFall )


/******************************************************************************
 * Global variable definitions (declared in header file with 'extern')        *
 ******************************************************************************/

/******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/******************************************************************************
 * Local function prototypes ('static')
 ******************************************************************************/
// static void LvdEnableNvic(void);
// static void LvdDisableNvic(void);
// static en_result_t LvdEnable(en_lvd_type_t enType, boolean_t bFlag);

/******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/

/*****************************************************************************
 * Function implementation - global ('extern') and local ('static')
 *****************************************************************************/

/**
 * \brief   
 *          LVD初始化
 *
 * \param   [in]  pstcInitCfg  LVD配置指针
 *
 * \retval  无
 */
en_result_t LVD_Init(LVD_TypeDef *LVDx, stc_lvd_init_t *pstcInitCfg)
{
    if (NULL == pstcInitCfg)
    {
        return ErrorInvalidParameter;
    }
    
    REG_MODIFY(LVDx->CR, 
                 LVD_CR_ACT
               | LVD_CR_HTEN
               | LVD_CR_RTEN
               | LVD_CR_FTEN
               | LVD_CR_SOURCE
               | LVD_CR_VTDS
               | LVD_CR_FLTEN
               | LVD_CR_FLTTIME
               , 
                 pstcInitCfg->u32TriggerAction
               | pstcInitCfg->u32TriggerMode
               | pstcInitCfg->u32InputSource
               | pstcInitCfg->u32ThresholdVolt
               | pstcInitCfg->u32Filter);

    return Ok;
}

/**
 ***********************************************************************************************
 ** \brief  开启LVD模块
 ** \param  [in] LVDx：LVD结构体变量

 ** \retval NULL
 ***********************************************************************************************/
void LVD_Enable(LVD_TypeDef *LVDx)
{
    REG_SETBITS(LVDx->CR, LVD_CR_EN);
}

/**
 ***********************************************************************************************
 ** \brief  关闭LVD模块
 ** \param  [in] LVDx：LVD结构体变量

 ** \retval NULL
 ***********************************************************************************************/
void LVD_Disable(LVD_TypeDef *LVDx)
{
    REG_CLEARBITS(LVDx->CR, LVD_CR_EN);    
}

/**
 ***********************************************************************************************
 ** \brief  检查LVD模块 是否已开启
 ** \param  [in] LVDx：LVD结构体变量

 ** \retval [out] 0：未开启； 非0：已开启
 ***********************************************************************************************/
uint32_t LVD_IsEnable(LVD_TypeDef *LVDx)
{
    return (uint32_t)(REG_READBITS(LVDx->CR, LVD_CR_EN) == LVD_CR_EN);
}

/**
 ***********************************************************************************************
 ** \brief  LVD触发动作选择
 ** \param  [in] LVDx：LVD结构体变量
 ** \param  [in] u32TriggerAction: 触发动作选择
 **              LVD_TRIGGER_ACTION_INT     NVIC中断
 **              LVD_TRIGGER_ACTION_RESET   系统复位

 ** \retval NULL
 ***********************************************************************************************/
void LVD_SetTriggerAction(LVD_TypeDef *LVDx, uint32_t u32TriggerAction)
{
    REG_MODIFY(LVDx->CR, LVD_CR_ACT, u32TriggerAction);
}

/**
 ***********************************************************************************************
 ** \brief  获取LVD触发动作
 ** \param  [in] LVDx：LVD结构体变量

 ** \retval [out] 返回值:触发动作
 **              LVD_TRIGGER_ACTION_INT     NVIC中断
 **              LVD_TRIGGER_ACTION_RESET   系统复位
 ** 
 ***********************************************************************************************/
uint32_t LVD_GetTriggerAction(LVD_TypeDef *LVDx)
{
    return (uint32_t)(REG_READBITS(LVDx->CR, LVD_CR_ACT));    
}

/**
 ***********************************************************************************************
 ** \brief  LVD 中断触发模式配置
 ** \param  [in] LVDx：LVD结构体变量
 ** \param  [in] u32TriggerMode: 中断触发模式选择: 下述单个值或者多个值相或
 **              LVD_TRIGGER_MODE_HIGHLEVEL     输入端被监测电压低于阈值电压(LVD输出端高电平)触发
 **              LVD_TRIGGER_MODE_RISING        输入端被监测电压从高于阈值电压变为低于阈值电压(LVD输出端上升沿)触发
 **              LVD_TRIGGER_MODE_FALLING       输入端被监测电压从低于阈值电压变为高于阈值电压(LVD输出端下降沿)触发

 ** \retval NULL
 ***********************************************************************************************/
void LVD_SetTriggerMode(LVD_TypeDef *LVDx, uint32_t u32TriggerMode)
{
    REG_MODIFY(LVDx->CR, (LVD_CR_HTEN | LVD_CR_RTEN | LVD_CR_FTEN), u32TriggerMode);
}

/**
 ***********************************************************************************************
 ** \brief  获取 LVD中断触发模式
 ** \param  [in] LVDx：LVD结构体变量

 ** \retval [out] 返回值: 中断触发模式,下述单个值或者多个值相或
 **              LVD_TRIGGER_MODE_HIGHLEVEL     LVD滤波信号高电平触发中断
 **              LVD_TRIGGER_MODE_RISING        LVD滤波信号上升沿触发中断
 **              LVD_TRIGGER_MODE_FALLING       LVD滤波信号下降沿触发中断
 ***********************************************************************************************/
uint32_t LVD_GetTriggerMode(LVD_TypeDef *LVDx)
{
    return (uint32_t)(REG_READBITS(LVDx->CR, (LVD_CR_HTEN | LVD_CR_RTEN | LVD_CR_FTEN)));    
}

/**
 ***********************************************************************************************
 ** \brief  LVD输入监测源配置
 ** \param  [in] LVDx：LVD结构体变量
 ** \param  [in] 输入监测源选择
 **              LVD_INPUT_AVCC    
 **              LVD_INPUT_PA03
 **              LVD_INPUT_PC03
 **              LVD_INPUT_PD04

 ** \retval NULL
 ***********************************************************************************************/
void LVD_SetInputSource(LVD_TypeDef *LVDx, uint32_t u32InputSource)
{
    REG_MODIFY(LVDx->CR, LVD_CR_SOURCE, u32InputSource);
}

/**
 ***********************************************************************************************
 ** \brief  获取LVD输入监测源
 ** \param  [in] LVDx：LVD结构体变量

 ** \retval [out] 返回值:输入检测源
 **              LVD_INPUT_AVCC    
 **              LVD_INPUT_PA03
 **              LVD_INPUT_PC03
 **              LVD_INPUT_PD04
 ** 
 ***********************************************************************************************/
uint32_t LVD_GetInputSource(LVD_TypeDef *LVDx)
{
    return (uint32_t)(REG_READBITS(LVDx->CR, LVD_CR_SOURCE));    
}

/**
 ***********************************************************************************************
 ** \brief  LVD 阈值电压选择
 ** \param  [in] LVDx：LVD结构体变量
 ** \param  [in] 阈值电压选择
 **         @arg @ref LVD_THRESHOLD_VOLT1p8V    
 **         @arg @ref LVD_THRESHOLD_VOLT1p9V
 **         @arg @ref LVD_THRESHOLD_VOLT2p0V
 **         @arg @ref LVD_THRESHOLD_VOLT2p1V
 **         @arg @ref LVD_THRESHOLD_VOLT2p2V    
 **         @arg @ref LVD_THRESHOLD_VOLT2p3V
 **         @arg @ref LVD_THRESHOLD_VOLT2p4V
 **         @arg @ref LVD_THRESHOLD_VOLT2p5V
 **         @arg @ref LVD_THRESHOLD_VOLT2p6V    
 **         @arg @ref LVD_THRESHOLD_VOLT2p7V
 **         @arg @ref LVD_THRESHOLD_VOLT2p8V
 **         @arg @ref LVD_THRESHOLD_VOLT2p9V
 **         @arg @ref LVD_THRESHOLD_VOLT3p0V    
 **         @arg @ref LVD_THRESHOLD_VOLT3p1V
 **         @arg @ref LVD_THRESHOLD_VOLT3p2V
 **         @arg @ref LVD_THRESHOLD_VOLT3p3V

 ** \retval NULL
 ***********************************************************************************************/
void LVD_SetThresholdVolt(LVD_TypeDef *LVDx, uint32_t u32ThresholdVolt)
{
    REG_MODIFY(LVDx->CR, LVD_CR_VTDS, u32ThresholdVolt);
}

/**
 ***********************************************************************************************
 ** \brief  获取LVD阈值电压
 ** \param  [in] LVDx：LVD结构体变量

 ** \retval [out] 返回值:阈值电压
 **         @arg @ref LVD_THRESHOLD_VOLT1p8V    
 **         @arg @ref LVD_THRESHOLD_VOLT1p9V
 **         @arg @ref LVD_THRESHOLD_VOLT2p0V
 **         @arg @ref LVD_THRESHOLD_VOLT2p1V
 **         @arg @ref LVD_THRESHOLD_VOLT2p2V    
 **         @arg @ref LVD_THRESHOLD_VOLT2p3V
 **         @arg @ref LVD_THRESHOLD_VOLT2p4V
 **         @arg @ref LVD_THRESHOLD_VOLT2p5V
 **         @arg @ref LVD_THRESHOLD_VOLT2p6V    
 **         @arg @ref LVD_THRESHOLD_VOLT2p7V
 **         @arg @ref LVD_THRESHOLD_VOLT2p8V
 **         @arg @ref LVD_THRESHOLD_VOLT2p9V
 **         @arg @ref LVD_THRESHOLD_VOLT3p0V    
 **         @arg @ref LVD_THRESHOLD_VOLT3p1V
 **         @arg @ref LVD_THRESHOLD_VOLT3p2V
 **         @arg @ref LVD_THRESHOLD_VOLT3p3V
 ** 
 ***********************************************************************************************/
uint32_t LVD_GetThresholdVolt(LVD_TypeDef *LVDx)
{
    return (uint32_t)(REG_READBITS(LVDx->CR, LVD_CR_VTDS));    
}

/**
 ***********************************************************************************************
 ** \brief  LVD数字滤波使能
 ** \param  [in] LVDx：LVD结构体变量

 ** \retval NULL
 ***********************************************************************************************/
void LVD_EnableFilter(LVD_TypeDef *LVDx)
{
    REG_SETBITS(LVDx->CR, LVD_CR_FLTEN);
}

/**
 ***********************************************************************************************
 ** \brief  LVD数字滤波禁止
 ** \param  [in] LVDx：LVD结构体变量

 ** \retval NULL
 ***********************************************************************************************/
void LVD_DisableFilter(LVD_TypeDef *LVDx)
{
    REG_CLEARBITS(LVDx->CR, LVD_CR_FLTEN);    
}

/**
 ***********************************************************************************************
 ** \brief  检查LVD数字滤波 是否已开启
 ** \param  [in] LVDx：LVD结构体变量

 ** \retval [out] 0：未开启； 非0：已开启
 ***********************************************************************************************/
uint32_t LVD_IsEnableFilter(LVD_TypeDef *LVDx)
{
    return (uint32_t)(REG_READBITS(LVDx->CR, LVD_CR_FLTEN) == LVD_CR_FLTEN);
}

/**
 ***********************************************************************************************
 ** \brief  电压比较器 滤波配置
 ** \param  [in] LVDx：LVD结构体变量
 ** \param  [in] u32Filter: 滤波时间选择:
 **         @arg @ref LVD_FILTER_NONE
 **         @arg @ref LVD_FILTER_1CYCLE
 **         @arg @ref LVD_FILTER_3CYCLE
 **         @arg @ref LVD_FILTER_7CYCLE
 **         @arg @ref LVD_FILTER_15CYCLE
 **         @arg @ref LVD_FILTER_63CYCLE
 **         @arg @ref LVD_FILTER_255CYCLE
 **         @arg @ref LVD_FILTER_1023CYCLE
 **         @arg @ref LVD_FILTER_4095CYCLE

 ** \retval NULL
 ***********************************************************************************************/
void LVD_SetFilter(LVD_TypeDef *LVDx, uint32_t u32Filter)
{
    REG_MODIFY(LVDx->CR, (LVD_CR_FLTTIME | LVD_CR_FLTEN), u32Filter);
}

/**
 ***********************************************************************************************
 ** \brief  获取 电压比较器滤波时间
 ** \param  [in] LVDx：LVD结构体变量

 ** \retval [out] 返回值:滤波时间:
 **         @arg @ref LVD_FILTER_NONE
 **         @arg @ref LVD_FILTER_1CYCLE
 **         @arg @ref LVD_FILTER_3CYCLE
 **         @arg @ref LVD_FILTER_7CYCLE
 **         @arg @ref LVD_FILTER_15CYCLE
 **         @arg @ref LVD_FILTER_63CYCLE
 **         @arg @ref LVD_FILTER_255CYCLE
 **         @arg @ref LVD_FILTER_1023CYCLE
 **         @arg @ref LVD_FILTER_4095CYCLE
 ***********************************************************************************************/
uint32_t LVD_GetFilter(LVD_TypeDef *LVDx)
{
    return (uint32_t)(REG_READBITS(LVDx->CR, (LVD_CR_FLTTIME | LVD_CR_FLTEN)));    
}

/**
 ***********************************************************************************************
 ** \brief  获取 滤波后的信号电平
 ** \param  [in] LVDx：LVD结构体变量

 ** \retval [out] 返回值:滤波后的信号电平
 **              0       滤波后的信号电平为低
 **              1       滤波后的信号电平为高
 ** 
 ***********************************************************************************************/
uint32_t LVD_GetFilterOutput(LVD_TypeDef *LVDx)
{
    return (uint32_t)(REG_READBITS(LVDx->SR, LVD_SR_FLTV));    
}

/**
 ***********************************************************************************************
 ** \brief  LVD中断使能
 ** \param  [in] LVDx：LVD结构体变量

 ** \retval NULL
 ***********************************************************************************************/
void LVD_EnableIT(LVD_TypeDef *LVDx)
{
    REG_SETBITS(LVDx->CR, LVD_CR_IE);
}

/**
 ***********************************************************************************************
 ** \brief  LVD中断禁止
 ** \param  [in] LVDx：LVD结构体变量

 ** \retval NULL
 ***********************************************************************************************/
void LVD_DisableIT(LVD_TypeDef *LVDx)
{
    REG_CLEARBITS(LVDx->CR, LVD_CR_IE);    
}

/**
 ***********************************************************************************************
 ** \brief  检查LVD中断 是否已使能
 ** \param  [in] LVDx：LVD结构体变量

 ** \retval [out] 0：未开启； 非0：已开启
 ***********************************************************************************************/
uint32_t LVD_IsEnableIT(LVD_TypeDef *LVDx)
{
    return (uint32_t)(REG_READBITS(LVDx->CR, LVD_CR_IE) == LVD_CR_IE);
}

/**
 ***********************************************************************************************
 ** \brief  获取 中断标志
 ** \param  [in] LVDx：LVD结构体变量

 ** \retval [out] 返回值: 0或者1
 ** 
 ***********************************************************************************************/
uint32_t LVD_IsActiveFlag_IT(LVD_TypeDef *LVDx)
{
    return (uint32_t)(REG_READBITS(LVDx->SR, LVD_SR_INTF) == LVD_SR_INTF);    
}

/**
 ***********************************************************************************************
 ** \brief  清除 中断标志
 ** \param  [in] LVDx：LVD结构体变量

 ** \retval NULL
 ** 
 ***********************************************************************************************/
void LVD_ClearFlag_IT(LVD_TypeDef *LVDx)
{
    REG_CLEARBITS(LVDx->SR, LVD_SR_INTF);
}

//@} // LvdGroup

/******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/

