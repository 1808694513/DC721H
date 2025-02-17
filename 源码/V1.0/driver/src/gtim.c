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
 ** @file gtim.c
 **
 ** @brief Source file for GTIM functions
 **
 ** @author MADS Team 
 **
 ******************************************************************************/

/******************************************************************************
 * Include files
 ******************************************************************************/

#include "gtim.h"

/**
 ******************************************************************************
 ** \addtogroup PCNTGroup
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

/**
******************************************************************************
 ** \brief  定时器GTIM的初始化配置
 **
 ** @param  pstcInitCfg : 初始化GTIMx的结构体
 **
 **         pstcInitCfg->u32TaskMode             //计数模式选择
 **                      GTIM_TASK_MODE_CONTINUOUS_COUNTER //连续计数模式
 **                      GTIM_TASK_MODE_ONESHOT_COUNTER    //单次计数模式
 **   
 **         pstcInitCfg->u32WorkMode            //工作模式
 **                      GTIM_WORK_MODE_PCLK            //定时器模式:计数时钟为PCLK
 **                      GTIM_WORK_MODE_EXTERNAL        //计数器模式:计数时钟来自TRS选择信号
 **                      GTIM_WORK_MODE_TRIGGER         //触发启动模式:计数时钟为PCLK，TRS信号触发计数器启动
 **                      GTIM_WORK_MODE_GATE            //门控模式:计数时钟为PCLK，TRS信号作为门控
 **
 **         pstcInitCfg->u32Prescaler           //计数时钟信号分频
 **                      GTIM_COUNTER_CLK_DIV1
 **                      GTIM_COUNTER_CLK_DIV2
 **                      GTIM_COUNTER_CLK_DIV4
 **                      GTIM_COUNTER_CLK_DIV8
 **                      GTIM_COUNTER_CLK_DIV16
 **                      GTIM_COUNTER_CLK_DIV32
 **                      GTIM_COUNTER_CLK_DIV64
 **                      GTIM_COUNTER_CLK_DIV128
 **                      GTIM_COUNTER_CLK_DIV256
 **                      GTIM_COUNTER_CLK_DIV512
 **                      GTIM_COUNTER_CLK_DIV1024
 **                      GTIM_COUNTER_CLK_DIV2048
 **                      GTIM_COUNTER_CLK_DIV4096
 **                      GTIM_COUNTER_CLK_DIV8192
 **                      GTIM_COUNTER_CLK_DIV16384
 **                      GTIM_COUNTER_CLK_DIV32768
 **
 **         pstcInitCfg->u32ToggleEn        //Toggle_N和Toggle_P输出使能
 **                      GTIM_TOGGLE_DISABLE  //TOGP、TOGN输出电平都为0
 **                      GTIM_TOGGLE_ENABLE   //TOGP、TOGN输出电平相反的信号
 **
 **         pstcInitCfg->u32TriggerSource  //触发源选择
 **                      GTIM_TRIGGER_SOURCE_ETR        //ETR管脚输入的信号
 **                      GTIM_TRIGGER_SOURCE_ATIM3_TRGO //ITR管脚输入的信号(ATIM3_TRGO)
 **
 **         pstcInitCfg->u32ExInputPolarity //外部输入极性选择
 **                      GTIM_ETR_POLARITY_NORMAL       //正相输入
 **                      GTIM_ETR_POLARITY_INVERTED     //反相输入
 **
 ** \retval en_result_t类型数据
 **
******************************************************************************/
en_result_t Gtim_Init(stc_gtim_init_t* pstcInitCfg)
{
    if (NULL == pstcInitCfg)
    {
        return ErrorInvalidParameter;
    }
    
    REG_MODIFY( GTIM->CR0,\
                     GTIM_CR0_MD\
                            | GTIM_CR0_TOGEN\
                            | GTIM_CR0_PRS\
                            | GTIM_CR0_OST\
                            | GTIM_CR0_TRS\
                            | GTIM_CR0_ETP\
                            , \
                             pstcInitCfg->u32TaskMode
                            | pstcInitCfg->u32WorkMode\
                            | pstcInitCfg->u32Prescaler\
                            | pstcInitCfg->u32ToggleEn\
                            | pstcInitCfg->u32TriggerSource\
                            | pstcInitCfg->u32ExInputPolarity);
    
    REG_MODIFY( GTIM->ARR, GTIM_ARR_ARR, (uint16_t)pstcInitCfg->u32AutoReloadVal);
            
    return Ok;
}

 /**
 ***********************************************************************************************
 ** \brief  获取GTIM计数器计数值
 **
 **
 **
 ** \retval [out] 返回值:GTIMx计数器计数值
 **         
 ***********************************************************************************************/
uint32_t Gtim_GetCounter(void)
{
    return (uint32_t)(REG_READBITS( GTIM->CNT, GTIM_CNT_CNT));    
}
   
 /**
 ***********************************************************************************************
 ** \brief  设置GTIM计数器计数值
 **
 **
 ** \param  [in] u16CntValue: 计数值
 **
 **
 ** \retval None
 **         
 ***********************************************************************************************/
void Gtim_SetCounter(uint16_t u16CntValue)
{
    REG_WRITE( GTIM->CNT, (uint32_t)u16CntValue);
}
 
 /**
 ***********************************************************************************************
 ** \brief  设定GTIM 重载寄存器的值
 **
 ** \param  [in] u16AutoReload: 重载值
 **
 **
 ** \retval NULL
 **         
 ***********************************************************************************************/
void Gtim_SetAutoReload(uint16_t u16AutoReload)
{
    REG_WRITE(GTIM->ARR, (uint32_t)u16AutoReload);
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取GTIM 重载寄存器的值
 **
 ** \retval [out] 返回值:GTIMx重载寄存器的值
 **         
 ***********************************************************************************************/
uint32_t Gtim_GetAutoReload(void)
{
    return (uint32_t)(REG_READBITS( GTIM->ARR, GTIM_ARR_ARR));    
}

/**
 ***********************************************************************************************
 ** \brief  开启定时器GTIM模块
 **
 **
 **
 ** \retval NULL
 ***********************************************************************************************/
void Gtim_Enable(void)
{
    REG_SETBITS( GTIM->CR0, GTIM_CR0_CEN);
}

/**
 ***********************************************************************************************
 ** \brief  禁止定时器GTIM模块
 **
 **
 **
 ** \retval NULL
 ***********************************************************************************************/
void Gtim_Disable(void)
{
    REG_CLEARBITS( GTIM->CR0, GTIM_CR0_CEN);    
}

/**
 ***********************************************************************************************
 ** \brief  检查定时器GTIM模块是否已开启
 **
 **
 **
 ** \retval [out] 0：未开启； 非0：已开启
 ***********************************************************************************************/
uint32_t Gtim_IsEnable(void)
{
    return (uint32_t)(REG_READBITS( GTIM->CR0, GTIM_CR0_CEN) == GTIM_CR0_CEN);    
}


/**
 ***********************************************************************************************
 ** \brief  设定定时器GTIM 工作模式
 **
 ** \param  [in] u32CounterMode: 选择GTIM工作模式
 **              GTIM_WORK_MODE_PCLK            //定时器模式:计数时钟为PCLK
 **              GTIM_WORK_MODE_EXTERNAL        //计数器模式:计数时钟来自TRS选择信号
 **              GTIM_WORK_MODE_TRIGGER         //触发启动模式:计数时钟为PCLK，TRS信号触发计数器启动
 **              GTIM_WORK_MODE_GATE            //门控模式:计数时钟为PCLK，TRS信号作为门控
 **
 **
 ** \retval NULL
 **         
 ***********************************************************************************************/
void Gtim_SetWorkMode(uint32_t u32WorkMode)
{
    REG_MODIFY( GTIM->CR0, GTIM_CR0_MD, u32WorkMode);    
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取定时器GTIM 工作模式
 **
 **
 ** \retval [out] 返回值:GTIM工作模式
 **               GTIM_WORK_MODE_PCLK            //定时器模式:计数时钟为PCLK
 **               GTIM_WORK_MODE_EXTERNAL        //计数器模式:计数时钟来自TRS选择信号
 **               GTIM_WORK_MODE_TRIGGER         //触发启动模式:计数时钟为PCLK，TRS信号触发计数器启动
 **               GTIM_WORK_MODE_GATE            //门控模式:计数时钟为PCLK，TRS信号作为门控
 **         
 ***********************************************************************************************/
uint32_t Gtim_GetWorkMode(void)
{
    return (uint32_t)(REG_READBITS( GTIM->CR0, GTIM_CR0_MD));    
}

/**
 ***********************************************************************************************
 ** \brief  定时器GTIM TOG输出使能，TOGP和TOGN输出相位相反的信号
 **
 **
 **
 **
 ** \retval NULL
 ***********************************************************************************************/
void Gtim_EnableToggle(void)
{
    REG_SETBITS( GTIM->CR0, GTIM_CR0_TOGEN);
}

/**
 ***********************************************************************************************
 ** \brief  定时器GTIM TOG输出禁止，TOGP和TOGN同时输出0
 **
 **
 **
 **
 ** \retval NULL
 ***********************************************************************************************/
void Gtim_DisableToggle(void)
{
    REG_CLEARBITS( GTIM->CR0, GTIM_CR0_TOGEN);    
}

/**
 ***********************************************************************************************
 ** \brief  检查定时器GTIM模块 TOG输出 是否已开启
 **
 **
 **
 ** \retval [out] 0：未开启； 非0：已开启
 ***********************************************************************************************/
uint32_t Gtim_IsEnableToggle(void)
{
    return (uint32_t)(REG_READBITS( GTIM->CR0, GTIM_CR0_TOGEN) == GTIM_CR0_TOGEN);    
}

 /**
 ***********************************************************************************************
 ** \brief  定时器GTIM模块 计数时钟预除频
 **
 ** \param  [in] u32CounterClkDiv: 计数时钟预分频选择
 **              GTIM_COUNTER_CLK_DIV1  
 **              GTIM_COUNTER_CLK_DIV2
 **              GTIM_COUNTER_CLK_DIV4  
 **              GTIM_COUNTER_CLK_DIV8  
 **              GTIM_COUNTER_CLK_DIV16
 **              GTIM_COUNTER_CLK_DIV32  
 **              GTIM_COUNTER_CLK_DIV64  
 **              GTIM_COUNTER_CLK_DIV128
 **              GTIM_COUNTER_CLK_DIV256  
 **              GTIM_COUNTER_CLK_DIV512  
 **              GTIM_COUNTER_CLK_DIV1024
 **              GTIM_COUNTER_CLK_DIV2048  
 **              GTIM_COUNTER_CLK_DIV4096  
 **              GTIM_COUNTER_CLK_DIV8192
 **              GTIM_COUNTER_CLK_DIV16384 
 **              GTIM_COUNTER_CLK_DIV32768   
 **
 **
 ** \retval NULL
 **         
 ***********************************************************************************************/
void Gtim_SetCounterClkDiv(uint32_t u32CounterClkDiv)
{
    REG_MODIFY( GTIM->CR0, GTIM_CR0_PRS, u32CounterClkDiv);    
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取定时器GTIM 时钟，此时钟是定时器模块工作时钟，非计数时钟源
 **
 ** \retval [out] 返回值:计数时钟预分频
 **              GTIM_COUNTER_CLK_DIV1  
 **              GTIM_COUNTER_CLK_DIV2
 **              GTIM_COUNTER_CLK_DIV4  
 **              GTIM_COUNTER_CLK_DIV8  
 **              GTIM_COUNTER_CLK_DIV16
 **              GTIM_COUNTER_CLK_DIV32  
 **              GTIM_COUNTER_CLK_DIV64  
 **              GTIM_COUNTER_CLK_DIV128
 **              GTIM_COUNTER_CLK_DIV256  
 **              GTIM_COUNTER_CLK_DIV512  
 **              GTIM_COUNTER_CLK_DIV1024
 **              GTIM_COUNTER_CLK_DIV2048  
 **              GTIM_COUNTER_CLK_DIV4096  
 **              GTIM_COUNTER_CLK_DIV8192
 **              GTIM_COUNTER_CLK_DIV16384 
 **              GTIM_COUNTER_CLK_DIV32768  
 **         
 ***********************************************************************************************/
uint32_t Gtim_GetCounterClkDiv(void)
{
    return (uint32_t)(REG_READBITS( GTIM->CR0, GTIM_CR0_PRS));    
}


 /**
 ***********************************************************************************************
 ** \brief  设定GTIM 计数模式：连续计数模式或单次计数模式
 **
 ** \param  [in] u32Mode: GTIM工计数模式
 **              GTIM_TASK_MODE_CONTINUOUS_COUNTER //连续计数模式
 **              GTIM_TASK_MODE_ONESHOT_COUNTER    //单次计数模式
 **
 ** \retval NULL
 **         
 ***********************************************************************************************/
void Gtim_SetTaskMode(uint32_t u32Mode)
{
    REG_MODIFY( GTIM->CR0, GTIM_CR0_OST, u32Mode);    
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取GTIM 计数模式：连续计数模式或单次计数模式
 **
 ** \retval [out] 返回值: GTIM工计数模式
 **              GTIM_TASK_MODE_CONTINUOUS_COUNTER //连续计数模式
 **              GTIM_TASK_MODE_ONESHOT_COUNTER    //单次计数模式
 **         
 ***********************************************************************************************/
uint32_t Gtim_GetTaskMode(void)
{
    return (uint32_t)(REG_READBITS(GTIM->CR0, GTIM_CR0_OST));    
}

 /**
 ***********************************************************************************************
 ** \brief  设定定时器GTIM 触发源
 ** \rmtoll CR      TS          Gtim_SetTriggerSource
 **
 ** \param  [in] u32TriggerSource: 选择GTIM触发源
 **              GTIM_TRIGGER_SOURCE_ETR         //外部管脚TER作为计数器触发源，或门控
 **              GTIM_TRIGGER_SOURCE_ATIM3_TRGO  //ATIM3_TRGO信号,门控模式下不建议选此源作为门控信号

 ** \retval NULL
 **         
 ***********************************************************************************************/
void Gtim_SetTriggerSource(uint32_t u32TriggerSource)
{
    REG_MODIFY( GTIM->CR0, GTIM_CR0_TRS, u32TriggerSource);    
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取定时器GTIM 触发源
 **
 ** \rmtoll CR      TS          Gtim_GetTriggerSource
 **
 ** \retval [out] 返回值:GTIM 触发源
 **              GTIM_TRIGGER_SOURCE_ETR         //外部管脚TER作为计数器触发源，或门控
 **              GTIM_TRIGGER_SOURCE_ATIM3_TRGO  //ATIM3_TRGO信号,门控模式下不建议选此源作为门控信号
 **         
 ***********************************************************************************************/
uint32_t Gtim_GetTriggerSource(void)
{
    return (uint32_t)(REG_READBITS( GTIM->CR0, GTIM_CR0_TRS));    
}


 
 /**
 ***********************************************************************************************
 ** \brief  设定定时器GTIM 外部输入ETR极性设定
 **
 ** \rmtoll CR      ETP          Gtim_SetExInputPolarity
 **
 ** \param  [in] u32ExInputPolarity: 外部输入ETR极性
 **              GTIM_ETR_POLARITY_NORMAL         //外部输入ETR不反向(触发模式上沿触发，门控模式低电平停止计数)
 **              GTIM_ETR_POLARITY_INVERTED       //外部输入ETR反向(触发模式下沿触发，门控模式高电平停止计数)
 **
 ** \retval NULL
 **         
 ***********************************************************************************************/
void Gtim_SetExInputPolarity(uint32_t u32ExInputPolarity)
{
    REG_MODIFY( GTIM->CR0, GTIM_CR0_ETP, u32ExInputPolarity);    
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取定时器GTIM 外部输入ETR极性配置
 **
 ** \rmtoll CR      TRS          Gtim_GetExInputPolarity
 **
 ** \retval [out] 返回值:外部输入ETR极性
 **              GTIM_ETR_POLARITY_NORMAL         //外部输入ETR不反向(触发模式上沿触发，门控模式低电平停止计数)
 **              GTIM_ETR_POLARITY_INVERTED       //外部输入ETR反向(触发模式下沿触发，门控模式高电平停止计数)
 **         
 ***********************************************************************************************/
uint32_t Gtim_GetExInputPolarity(void)
{
    return (uint32_t)(REG_READBITS( GTIM->CR0, GTIM_CR0_ETP));    
}

 /**
 ***********************************************************************************************
 ** \brief  设定定时器GTIM 外部输入ETR滤波时间
 **
 ** \rmtoll CR1      ETRFLT          Gtim_SetExInputFilter
 **
 ** \param  [in] u32ExInputFilter: 外部输入ETR滤波时间
 **              GTIM_ETR_FILTER_NONE                外部输入信号无滤波
 **              GTIM_ETR_FILTER_PCLK_DIV1_CYCLE2    采样时钟频率为PCLK，滤波宽度小于2个采样周期
 **              GTIM_ETR_FILTER_PCLK_DIV1_CYCLE4    采样时钟频率为PCLK，滤波宽度小于4个采样周期
 **              GTIM_ETR_FILTER_PCLK_DIV1_CYCLE6    采样时钟频率为PCLK，滤波宽度小于6个采样周期
 **              GTIM_ETR_FILTER_PCLK_DIV4_CYCLE4    采样时钟频率为PCLK/4，滤波宽度小于4个采样周期
 **              GTIM_ETR_FILTER_PCLK_DIV4_CYCLE6    采样时钟频率为PCLK/4，滤波宽度小于6个采样周期
 **              GTIM_ETR_FILTER_PCLK_DIV16_CYCLE4   采样时钟频率为PCLK/4，滤波宽度小于4个采样周期
 **              GTIM_ETR_FILTER_PCLK_DIV16_CYCLE6   采样时钟频率为PCLK/4，滤波宽度小于6个采样周期

 ** \retval NULL
 **         
 ***********************************************************************************************/
void Gtim_SetExInputFilter(uint32_t u32ExInputFilter)
{
    REG_MODIFY( GTIM->CR1, GTIM_CR1_ETRFLT, u32ExInputFilter);    
}

 /**
 ***********************************************************************************************
 ** \brief  获取定时器GTIM 外部输入ETR滤波时间
 **
 ** \rmtoll CR1      ETRFLT          Gtim_GetExInputFilter
 **
 ** \retval [out] 返回值:外部输入ETR滤波时间
 **              GTIM_ETR_FILTER_NONE                外部输入信号无滤波
 **              GTIM_ETR_FILTER_PCLK_DIV1_CYCLE2    采样时钟频率为PCLK，滤波宽度小于2个采样周期
 **              GTIM_ETR_FILTER_PCLK_DIV1_CYCLE4    采样时钟频率为PCLK，滤波宽度小于4个采样周期
 **              GTIM_ETR_FILTER_PCLK_DIV1_CYCLE6    采样时钟频率为PCLK，滤波宽度小于6个采样周期
 **              GTIM_ETR_FILTER_PCLK_DIV4_CYCLE4    采样时钟频率为PCLK/4，滤波宽度小于4个采样周期
 **              GTIM_ETR_FILTER_PCLK_DIV4_CYCLE6    采样时钟频率为PCLK/4，滤波宽度小于6个采样周期
 **              GTIM_ETR_FILTER_PCLK_DIV16_CYCLE4   采样时钟频率为PCLK/4，滤波宽度小于4个采样周期
 **              GTIM_ETR_FILTER_PCLK_DIV16_CYCLE6   采样时钟频率为PCLK/4，滤波宽度小于6个采样周期
 **         
 ***********************************************************************************************/
uint32_t Gtim_GetExInputFilter(void)
{
    return (uint32_t)(REG_READBITS( GTIM->CR1, GTIM_CR1_ETRFLT));    
}


 /**
 ***********************************************************************************************
 ** \brief  定时器GTIM 捕获比较模式选择
 **
 ** \rmtoll CMMR      CCxM          Gtim_SetCompareCaptureMode
 **
 ** \param  [in] u32Channel：比较捕获通道选择
 **              GTIM_COMPARE_CAPTURE_CH0 
 **              GTIM_COMPARE_CAPTURE_CH1
 **              GTIM_COMPARE_CAPTURE_CH2
 **              GTIM_COMPARE_CAPTURE_CH3
 **
 ** \param  [in] u32CaptureMode: 捕获比较模式选择
 **              GTIM_COMPARE_CAPTURE_NONE               关闭capture功能，GTIM只做普通定时器功能
 **              GTIM_COMPARE_CAPTURE_RISING             CHx输入上升沿捕获
 **              GTIM_COMPARE_CAPTURE_FALLING            CHx输入下降沿捕获
 **              GTIM_COMPARE_CAPTURE_RISING_FALLING     CHx上升沿下降沿捕获
 **              GTIM_COMPARE_CAPTURE_FORCE_LOW_LEVEL    CHx强制输出低电平
 **              GTIM_COMPARE_CAPTURE_FORCE_HIGH_LEVEL   CHx强制输出高电平
 **              GTIM_COMPARE_CAPTURE_PWM_NORMAL         CHx PWM输出，CNT＞＝CCR输出高电平
 **              GTIM_COMPARE_CAPTURE_PWM_INVERTED       CHx PWM输出，CNT＜CCR输出高电平
 **
 ** \retval NULL
 **         
 ***********************************************************************************************/

void Gtim_SetCompareCaptureMode(uint32_t u32Channel, uint32_t u32CaptureMode)
{
    REG_MODIFY( GTIM->CMMR, (GTIM_CMMR_CC0M << (u32Channel*GTIM_CMMR_CC1M_Pos)), (u32CaptureMode << (u32Channel*GTIM_CMMR_CC1M_Pos)));    
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取定时器GTIM 捕获比较模式
 **
 ** \rmtoll CCR      CCxM          Gtim_GetCompareCaptureMode
 **
 ** \param  [in] u32Channel：比较捕获通道选择
 **              GTIM_COMPARE_CAPTURE_CH0 
 **              GTIM_COMPARE_CAPTURE_CH1
 **              GTIM_COMPARE_CAPTURE_CH2
 **              GTIM_COMPARE_CAPTURE_CH3
 **
 ** \retval [out] 返回值:捕获比较模式
 **              GTIM_COMPARE_CAPTURE_NONE               关闭捕获比较功能，GTIM只做普通定时器功能
 **              GTIM_COMPARE_CAPTURE_RISING             CHx 输入上升沿捕获
 **              GTIM_COMPARE_CAPTURE_FALLING            CHx 输入下降沿捕获
 **              GTIM_COMPARE_CAPTURE_RISING_FALLING     CHx 上升沿下降沿捕获
 **              GTIM_COMPARE_CAPTURE_FORCE_LOW_LEVEL    CHx 强制输出低电平
 **              GTIM_COMPARE_CAPTURE_FORCE_HIGH_LEVEL   CHx 强制输出高电平
 **              GTIM_COMPARE_CAPTURE_PWM_NORMAL         CHx PWM输出，CNT＞＝CCR输出高电平
 **              GTIM_COMPARE_CAPTURE_PWM_INVERTED       CHx PWM输出，CNT＜CCR输出高电平
 **         
 ***********************************************************************************************/
uint32_t Gtim_GetCompareCaptureMode(uint32_t u32Channel)
{
    return (uint32_t)((REG_READBITS( GTIM->CMMR, (GTIM_CMMR_CC0M << (u32Channel*GTIM_CMMR_CC1M_Pos)))) >> (u32Channel*GTIM_CMMR_CC1M_Pos));    
}


 /**
 ***********************************************************************************************
 ** \brief  设定GTIM 比较捕获（寄存器）值
 **
 ** \param  [in] u32Channel：比较捕获通道选择
 **              GTIM_COMPARE_CAPTURE_CH0
 **              GTIM_COMPARE_CAPTURE_CH1
 **              GTIM_COMPARE_CAPTURE_CH2
 **              GTIM_COMPARE_CAPTURE_CH3
 **
 ** \param  [in] u32Capture: 16位比较捕获寄存器值
 **
 ** \retval NULL
 **         
 ***********************************************************************************************/
void Gtim_SetCompareCaptureReg(uint32_t u32Channel, uint32_t u32Capture)
{
    REG_MODIFY(*(& GTIM->CCR0 + u32Channel), GTIM_CCR0_CCR, u32Capture);    
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取GTIM 比较捕获（寄存器）值
 **
 ** \param  [in] u32Channel：比较捕获通道选择
 **              GTIM_COMPARE_CAPTURE_CH0
 **              GTIM_COMPARE_CAPTURE_CH1
 **              GTIM_COMPARE_CAPTURE_CH2
 **              GTIM_COMPARE_CAPTURE_CH3
 **
 ** \retval [out] 返回值:比较捕获寄存器的值
 **         
 ***********************************************************************************************/
uint32_t Gtim_GetCompareCaptureReg(uint32_t u32Channel)
{
    return (uint32_t)(REG_READBITS(*(& GTIM->CCR0 + u32Channel), GTIM_CCR0_CCR));    
}
        
 /**
 ***********************************************************************************************
 ** \brief  禁止所有通道比较捕获功能
 **
 **
 **
 ** \retval NULL
 **         
 ***********************************************************************************************/
void Gtim_DisableCompareCaptureAll(void)
{
    REG_CLEAR( GTIM->CMMR);    
}

               

/**
 ***********************************************************************************************
 ** \brief  GTIM 中断使能
 **
 ** \param  [in] u32IT：中断使能控制位：下列值或多个值相或
 **              GTIM_IT_UI     //溢出中断使能控制
 **              GTIM_IT_TI     //触发中断使能控制
 **              GTIM_IT_CC0    //TIM捕获比较0中断使能控制
 **              GTIM_IT_CC1    //TIM捕获比较1中断使能控制
 **              GTIM_IT_CC2    //TIM捕获比较2中断使能控制
 **              GTIM_IT_CC3    //TIM捕获比较3中断使能控制

 ** \retval NULL
 ***********************************************************************************************/
void Gtim_EnableIT(uint32_t u32IT)
{
    REG_SETBITS( GTIM->IER, u32IT);
}

/**
 ***********************************************************************************************
 ** \brief  GTIM 中断禁止
 **
 ** \param  [in] u32IT：中断使能控制位：下列值或多个值相或
 **              GTIM_IT_UI     //溢出中断使能控制
 **              GTIM_IT_TI     //触发中断使能控制
 **              GTIM_IT_CC0    //TIM捕获比较0中断使能控制
 **              GTIM_IT_CC1    //TIM捕获比较1中断使能控制
 **              GTIM_IT_CC2    //TIM捕获比较2中断使能控制
 **              GTIM_IT_CC3    //TIM捕获比较3中断使能控制

 ** \retval NULL
 ***********************************************************************************************/
void Gtim_DisableIT(uint32_t u32IT)
{
    REG_CLEARBITS( GTIM->IER, u32IT);    
}

/**
 ***********************************************************************************************
 ** \brief  检查 GTIM 哪些中断已使能
 **
 ** \param  [in] u32IntEnableTypes  //中断使能类型
 **              GTIM_IT_UI     //溢出中断使能控制
 **              GTIM_IT_TI     //触发中断使能控制
 **              GTIM_IT_CC0    //TIM捕获比较0中断使能控制
 **              GTIM_IT_CC1    //TIM捕获比较1中断使能控制
 **              GTIM_IT_CC2    //TIM捕获比较2中断使能控制
 **              GTIM_IT_CC3    //TIM捕获比较3中断使能控制
 **
 ** \retval [out] 返回值 0:未使能； 1:已使能
 **
 ***********************************************************************************************/
uint32_t Gtim_IsEnableIT(uint32_t u32IntEnableTypes)
{
    return(REG_READBITS( GTIM->IER, u32IntEnableTypes) == u32IntEnableTypes);
}


/**
 ***********************************************************************************************
 ** \brief  获取 GTIM 中断标志
 **
 ** \param  [in] u32IntFlagTypes    //中断标志类型
 **              GTIM_IT_FLAG_UI     //溢出中断标志
 **              GTIM_IT_FLAG_TI     //触发中断标志
 **              GTIM_IT_FLAG_CC0    //TIM捕获比较0中断标志
 **              GTIM_IT_FLAG_CC1    //TIM捕获比较1中断标志
 **              GTIM_IT_FLAG_CC2    //TIM捕获比较2中断标志
 **              GTIM_IT_FLAG_CC3    //TIM捕获比较3中断标志
 **
 ** \retval [out] 返回值 0:未置起 1:已置起
 **
 ***********************************************************************************************/
uint32_t Gtim_IsActiveFlag(uint32_t u32IntFlagTypes)
{
    return(REG_READBITS( GTIM->IFR, u32IntFlagTypes) == u32IntFlagTypes);
}
               
               
/**
 ***********************************************************************************************
 ** \brief  清除 GTIM 中断 标志位
 **
 ** \param  [in] u32IntClrFlag
 **              GTIM_IT_CLR_UI     //清除溢出中断标志
 **              GTIM_IT_CLR_TI     //清除触发中断标志
 **              GTIM_IT_CLR_CC0    //清除GTIM捕获比较0中断标志
 **              GTIM_IT_CLR_CC1    //清除GTIM捕获比较1中断标志
 **              GTIM_IT_CLR_CC2    //清除GTIM捕获比较2中断标志
 **              GTIM_IT_CLR_CC3    //清除GTIM捕获比较3中断标志
 **
 ** \retval NULL
 ***********************************************************************************************/
void Gtim_ClearFlag(uint32_t u32IntClrFlag)
{
    REG_CLEARBITS( GTIM->ICR, u32IntClrFlag);    
}


/******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
