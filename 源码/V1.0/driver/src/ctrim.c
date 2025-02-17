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
 ** @file ctrim.c
 **
 ** @brief Source file for CTRIM functions
 **
 ** @author MADS Team 
 **
 ******************************************************************************/

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "ctrim.h"
/**
 *******************************************************************************
 ** \addtogroup CtrimGroup
 ******************************************************************************/
//@{

/*******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/

/*******************************************************************************
 * Global variable definitions (declared in header file with 'extern')
 ******************************************************************************/

/*******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/*******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/

/*******************************************************************************
 * Local function prototypes ('static')
 ******************************************************************************/

/*******************************************************************************
 * Function implementation - global ('extern') and local ('static')
 ******************************************************************************/

/**
 *****************************************************************************
 ** \brief CTRIM时钟校准初始化配置
 **
 **
 ** \param [in]  pstcInitCfg           Trim时钟校准结构体指针
 ** 
 ** \retval Ok or ErrorInvalidParameter                                      
 *****************************************************************************/
en_result_t CTRIM_CaliInit(CTRIM_TypeDef* CTRIMx, stc_ctrim_cali_init_t* pstcInitCfg)
{
    ASSERT(NULL != pstcInitCfg);
    
    if (((pstcInitCfg->u32Mode&CTRIM_CR1_MD_1) != 0) || (pstcInitCfg->u32RefClockDiv == 0))
    {
        return ErrorInvalidParameter;
    }
    
    REG_MODIFY(CTRIMx->CR0, 
                 CTRIM_CR0_STEP
               | CTRIM_CR0_ETRFLT
               | CTRIM_CR0_SRC
               , 
                 pstcInitCfg->u32InitialStep
               | pstcInitCfg->u32EtrFilter
               | pstcInitCfg->u32AccurateClock);
    
    REG_MODIFY(CTRIMx->CR1, 
                 CTRIM_CR1_MD
               | CTRIM_CR1_AUTO
               | CTRIM_CR1_PRS
               | CTRIM_CR1_OST
               , 
                 pstcInitCfg->u32Mode
               | pstcInitCfg->u32RefClockDiv
               | pstcInitCfg->u32OneShot);

    CTRIMx->ARR = pstcInitCfg->u16ReloadVal;
    
    CTRIMx->FLIM = pstcInitCfg->u8CountErrorLimit;
    
    return Ok;
}

/**
 *****************************************************************************
 ** \brief CTRIM 时钟功能初始化配置
 **
 **
 ** \param [in]  pstcInitCfg           时钟初始化结构体指针
 ** 
 ** \retval Ok or ErrorInvalidParameter                                      
 *****************************************************************************/
en_result_t CTRIM_TimerInit(CTRIM_TypeDef* CTRIMx, stc_ctrim_timer_init_t* pstcInitCfg)
{
    ASSERT(NULL != pstcInitCfg);
    
    REG_MODIFY(CTRIMx->CR0, 
                 CTRIM_CR0_ETRFLT
               | CTRIM_CR0_SRC
               , 
                 pstcInitCfg->u32EtrFilter
               | pstcInitCfg->u32Clock);
    
    REG_MODIFY(CTRIMx->CR1, 
                 CTRIM_CR1_MD
               | CTRIM_CR1_AUTO
               | CTRIM_CR1_PRS
               , 
                 CTRIM_CR1_MD_1
               | pstcInitCfg->u32ClockDiv);

    CTRIMx->ARR = pstcInitCfg->u32ReloadVal;
    
    return Ok;
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取CTRIMx 误差计数器计数值
 ** \param  [in] CTRIMx：CTRIM结构体变量

 ** \retval [out] 返回值:CTRIMx计数器计数值
 **         
 ***********************************************************************************************/
uint32_t CTRIM_GetCounter(CTRIM_TypeDef* CTRIMx)
{
    return (uint32_t)(REG_READBITS(CTRIMx->CNT, CTRIM_CNT_CNT));    
}
 
 /**
 ***********************************************************************************************
 ** \brief  设定CTRIMx 自动装载寄存器的值
 ** \param  [in] CTRIMx：CTRIM结构体变量
 ** \param  [in] u32AutoReload: 重载值

 ** \retval NULL
 **         
 ***********************************************************************************************/
void CTRIM_SetAutoReload(CTRIM_TypeDef* CTRIMx, uint32_t u32AutoReload)
{
    REG_MODIFY(CTRIMx->ARR, CTRIM_ARR_ARR, u32AutoReload);    
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取CTRIMx 自动装载寄存器的值
 ** \param  [in] CTRIMx：CTRIM结构体变量

 ** \retval [out] 返回值:CTRIMx自动装载寄存器的值
 **         
 ***********************************************************************************************/
uint32_t CTRIM_GetAutoReload(CTRIM_TypeDef* CTRIMx)
{
    return (uint32_t)(REG_READBITS(CTRIMx->ARR, CTRIM_ARR_ARR));    
}
 
 /**
 ***********************************************************************************************
 ** \brief  CTRIMx RCH/RCL TRIM初始步进量配置，必须在CTRIM模块未使能时才可以配置
 ** \param  [in] CTRIMx：CTRIM结构体变量
 ** \param  [in] u32TrimStep: TRIM初始步进量,可配置如下值
 **              CTRIM_INITIAL_STEP_1
 **              CTRIM_INITIAL_STEP_2
 **              CTRIM_INITIAL_STEP_4
 **              CTRIM_INITIAL_STEP_8
 **              CTRIM_INITIAL_STEP_16
 **              CTRIM_INITIAL_STEP_32
 **              CTRIM_INITIAL_STEP_64
 **              CTRIM_INITIAL_STEP_128

 ** \retval NULL
 **         
 ***********************************************************************************************/
void CTRIM_SetInitialStep(CTRIM_TypeDef* CTRIMx, uint32_t u32TrimStep)
{
    REG_MODIFY(CTRIMx->CR0, CTRIM_CR0_STEP, u32TrimStep);    
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取CTRIMx TRIM初始步进量
 ** \param  [in] CTRIMx：CTRIM结构体变量

 ** \retval [out] 返回值:TRIM初始步进量
 **              CTRIM_INITIAL_STEP_1
 **              CTRIM_INITIAL_STEP_2
 **              CTRIM_INITIAL_STEP_4
 **              CTRIM_INITIAL_STEP_8
 **              CTRIM_INITIAL_STEP_16
 **              CTRIM_INITIAL_STEP_32
 **              CTRIM_INITIAL_STEP_64
 **              CTRIM_INITIAL_STEP_128
 **         
 ***********************************************************************************************/
uint32_t CTRIM_GetInitialStep(CTRIM_TypeDef* CTRIMx)
{
    return (uint32_t)(REG_READBITS(CTRIMx->CR0, CTRIM_CR0_STEP));    
}
 
 /**
 ***********************************************************************************************
 ** \brief  CTRIMx 外部管脚输入时钟滤波配置，必须在CTRIM模块未使能时才可以配置
 ** \param  [in] CTRIMx：CTRIM结构体变量
 ** \param  [in] u32ExClockFilter: 外部输入时钟滤波配置,可配置如下值
 **              CTRIM_ETR_CLOCK_FILTER_NONE               外部输入时钟无滤波
 **              CTRIM_ETR_CLOCK_FILTER_PCLK_DIV1_CYCLE2   采样时钟频率为PCLK，滤波宽度小于2个采样周期
 **              CTRIM_ETR_CLOCK_FILTER_PCLK_DIV1_CYCLE4   采样时钟频率为PCLK，滤波宽度小于4个采样周期
 **              CTRIM_ETR_CLOCK_FILTER_PCLK_DIV1_CYCLE6   采样时钟频率为PCLK，滤波宽度小于6个采样周期
 **              CTRIM_ETR_CLOCK_FILTER_PCLK_DIV4_CYCLE4   采样时钟频率为PCLK/4，滤波宽度小于4个采样周期
 **              CTRIM_ETR_CLOCK_FILTER_PCLK_DIV4_CYCLE6   采样时钟频率为PCLK/4，滤波宽度小于6个采样周期
 **              CTRIM_ETR_CLOCK_FILTER_PCLK_DIV8_CYCLE4   采样时钟频率为PCLK/8，滤波宽度小于4个采样周期
 **              CTRIM_ETR_CLOCK_FILTER_PCLK_DIV8_CYCLE6   采样时钟频率为PCLK/8，滤波宽度小于6个采样周期

 ** \retval NULL
 **         
 ***********************************************************************************************/
void CTRIM_SetEtrClockFilter(CTRIM_TypeDef* CTRIMx, uint32_t u32ExClockFilter)
{
    REG_MODIFY(CTRIMx->CR0, CTRIM_CR0_ETRFLT, u32ExClockFilter);    
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取CTRIMx 外部管脚输入时钟滤波配置
 ** \param  [in] CTRIMx：CTRIM结构体变量

 ** \retval [out] 返回值:外部输入时钟滤波配置
 **              CTRIM_ETR_CLOCK_FILTER_NONE               外部输入时钟无滤波
 **              CTRIM_ETR_CLOCK_FILTER_PCLK_DIV1_CYCLE2   采样时钟频率为PCLK，滤波宽度小于2个采样周期
 **              CTRIM_ETR_CLOCK_FILTER_PCLK_DIV1_CYCLE4   采样时钟频率为PCLK，滤波宽度小于4个采样周期
 **              CTRIM_ETR_CLOCK_FILTER_PCLK_DIV1_CYCLE6   采样时钟频率为PCLK，滤波宽度小于6个采样周期
 **              CTRIM_ETR_CLOCK_FILTER_PCLK_DIV4_CYCLE4   采样时钟频率为PCLK/4，滤波宽度小于4个采样周期
 **              CTRIM_ETR_CLOCK_FILTER_PCLK_DIV4_CYCLE6   采样时钟频率为PCLK/4，滤波宽度小于6个采样周期
 **              CTRIM_ETR_CLOCK_FILTER_PCLK_DIV8_CYCLE4   采样时钟频率为PCLK/8，滤波宽度小于4个采样周期
 **              CTRIM_ETR_CLOCK_FILTER_PCLK_DIV8_CYCLE6   采样时钟频率为PCLK/8，滤波宽度小于6个采样周期
 **         
 ***********************************************************************************************/
uint32_t CTRIM_GetEtrClockFilter(CTRIM_TypeDef* CTRIMx)
{
    return (uint32_t)(REG_READBITS(CTRIMx->CR0, CTRIM_CR0_ETRFLT));    
}
 
 /**
 ***********************************************************************************************
 ** \brief  CTRIMx 精确时钟源选择，必须在CTRIM模块未使能时才可以配置
 ** \param  [in] CTRIMx：CTRIM结构体变量
 ** \param  [in] u32ClockSource: 时钟源选择
 **              CTRIM_ACCURATE_CLOCK_ETR         精准时钟源选择外部输入时钟
 **              CTRIM_ACCURATE_CLOCK_PCLK        精准时钟源选择PCLK
 **              CTRIM_ACCURATE_CLOCK_RCL         精准时钟源选择RCL
 **              CTRIM_ACCURATE_CLOCK_RCH         精准时钟源选择RCH

 ** \retval NULL
 **         
 ***********************************************************************************************/
void CTRIM_SetAccurateClock(CTRIM_TypeDef* CTRIMx, uint32_t u32ClockSource)
{
    REG_MODIFY(CTRIMx->CR0, CTRIM_CR0_SRC, u32ClockSource);    
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取CTRIMx 精准时钟源选择
 ** \param  [in] CTRIMx：CTRIM结构体变量

 ** \retval [out] 返回值:时钟源选择
 **              CTRIM_ACCURATE_CLOCK_ETR         精准时钟源选择外部输入时钟
 **              CTRIM_ACCURATE_CLOCK_PCLK        精准时钟源选择PCLK
 **              CTRIM_ACCURATE_CLOCK_RCL         精准时钟源选择RCL
 **              CTRIM_ACCURATE_CLOCK_RCH         精准时钟源选择RCH
 **         
 ***********************************************************************************************/
uint32_t CTRIM_GetAccurateClock(CTRIM_TypeDef* CTRIMx)
{
    return (uint32_t)(REG_READBITS(CTRIMx->CR0, CTRIM_CR0_SRC));    
}
 
 /**
 ***********************************************************************************************
 ** \brief  CTRIMx 工作模式配置
 ** \param  [in] CTRIMx：CTRIM结构体变量
 ** \param  [in] u32Mode: 工作模式选择
 **              CTRIM_MODE_RCH_AUTO_TRIM    RCH自动校准模式
 **              CTRIM_MODE_RCL_AUTO_TRIM    RCL自动校准模式
 **              CTRIM_MODE_TIMER            定时器模式

 ** \retval NULL
 **         
 ***********************************************************************************************/
void CTRIM_SetMode(CTRIM_TypeDef* CTRIMx, uint32_t u32Mode)
{
    REG_MODIFY(CTRIMx->CR1, (CTRIM_CR1_AUTO | CTRIM_CR1_MD), u32Mode);    
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取CTRIMx 工作模式配置
 ** \param  [in] CTRIMx：CTRIM结构体变量

 ** \retval [out] 返回值:工作模式选择
 **              CTRIM_MODE_RCH_AUTO_TRIM    RCH自动校准模式
 **              CTRIM_MODE_RCL_AUTO_TRIM    RCL自动校准模式
 **              CTRIM_MODE_TIMER            定时器模式
 **         
 ***********************************************************************************************/
uint32_t CTRIM_GetMode(CTRIM_TypeDef* CTRIMx)
{
    return (uint32_t)(REG_READBITS(CTRIMx->CR1,  (CTRIM_CR1_AUTO | CTRIM_CR1_MD)));    
}

 /**
 ***********************************************************************************************
 ** \brief  CTRIMx 参考时钟预分频配置,CTRIMx->CR1.PRS不能配置为0值，否则CTRIM不能正常工作
 **         RCH自动校准模式和定时器模式，分频精确时钟；RCL自动校准模式，分频RCL时钟
 ** \param  [in] CTRIMx：CTRIM结构体变量
 ** \param  [in] u32RefClockDiv: 参考时钟预分频配置,可配置如下值
 **              CTRIM_REF_CLOCK_DIV2
 **              CTRIM_REF_CLOCK_DIV4
 **              CTRIM_REF_CLOCK_DIV8
 **              CTRIM_REF_CLOCK_DIV16
 **              CTRIM_REF_CLOCK_DIV32
 **              CTRIM_REF_CLOCK_DIV64
 **              CTRIM_REF_CLOCK_DIV128
 **              CTRIM_REF_CLOCK_DIV512
 **              CTRIM_REF_CLOCK_DIV1024
 **              CTRIM_REF_CLOCK_DIV2048
 **              CTRIM_REF_CLOCK_DIV4096
 **              CTRIM_REF_CLOCK_DIV8192
 **              CTRIM_REF_CLOCK_DIV16384
 **              CTRIM_REF_CLOCK_DIV32768

 ** \retval NULL
 **         
 ***********************************************************************************************/
void CTRIM_SetRefClockDiv(CTRIM_TypeDef* CTRIMx, uint32_t u32RefClockDiv)
{
    REG_MODIFY(CTRIMx->CR1, CTRIM_CR1_PRS, u32RefClockDiv);    
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取CTRIMx 参考时钟预分频配置
 **         RCH自动校准模式和定时器模式，分频精确时钟；RCL自动校准模式，分频RCL时钟
 ** \param  [in] CTRIMx：CTRIM结构体变量

 ** \retval [out] 返回值:参考时钟预分频配置
 **              CTRIM_REF_CLOCK_DIV2
 **              CTRIM_REF_CLOCK_DIV4
 **              CTRIM_REF_CLOCK_DIV8
 **              CTRIM_REF_CLOCK_DIV16
 **              CTRIM_REF_CLOCK_DIV32
 **              CTRIM_REF_CLOCK_DIV64
 **              CTRIM_REF_CLOCK_DIV128
 **              CTRIM_REF_CLOCK_DIV512
 **              CTRIM_REF_CLOCK_DIV1024
 **              CTRIM_REF_CLOCK_DIV2048
 **              CTRIM_REF_CLOCK_DIV4096
 **              CTRIM_REF_CLOCK_DIV8192
 **              CTRIM_REF_CLOCK_DIV16384
 **              CTRIM_REF_CLOCK_DIV32768
 **         
 ***********************************************************************************************/
uint32_t CTRIM_GetRefClockDiv(CTRIM_TypeDef* CTRIMx)
{
    return (uint32_t)(REG_READBITS(CTRIMx->CR1, CTRIM_CR1_PRS));    
}
 
 /**
 ***********************************************************************************************
 ** \brief  CTRIMx 校准模式配置
 ** \param  [in] CTRIMx：CTRIM结构体变量
 ** \param  [in] u32OneShotMode: 校准模式配置
 **              CTRIM_ONE_SHOT_REPETITIVE    实时校准模式
 **              CTRIM_ONE_SHOT_SINGLE        单次校准模式

 ** \retval NULL
 **         
 ***********************************************************************************************/
void CTRIM_SetOneShot(CTRIM_TypeDef* CTRIMx, uint32_t u32OneShotMode)
{
    REG_MODIFY(CTRIMx->CR1, CTRIM_CR1_OST, u32OneShotMode);    
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取CTRIMx 校准模式配置
 ** \param  [in] CTRIMx：CTRIM结构体变量

 ** \retval [out] 返回值:校准模式配置
 **              CTRIM_ONE_SHOT_REPETITIVE    实时校准模式
 **              CTRIM_ONE_SHOT_SINGLE        单次校准模式
 **         
 ***********************************************************************************************/
uint32_t CTRIM_GetOneShot(CTRIM_TypeDef* CTRIMx)
{
    return (uint32_t)(REG_READBITS(CTRIMx->CR1, CTRIM_CR1_OST));    
}

/**
 ***********************************************************************************************
 ** \brief  获取 CTRIMx 误差计数器计数方向
 ** \param  [in] CTRIMx：CTRIM结构体变量

 ** \retval [out] 返回值: 误差计数器计数方向
 **               CTRIM_ARR_COUNT_DIR_INCREASE  递增计数，RCH输出频率高于目标频率，或RCL输出频率低于目标频率
 **               CTRIM_ARR_COUNT_DIR_DECREASE  递减计数，RCH输出频率低于目标频率，或RCL输出频率高于目标频率

 ***********************************************************************************************/
uint32_t CTRIM_GetARRCoutDir(CTRIM_TypeDef* CTRIMx)
{
    return (uint32_t)(REG_READBITS(CTRIMx->ISR, CTRIM_ISR_DIR));    
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取CTRIMx TrimCode值，及trim结束后的trim校准值
 ** \param  [in] CTRIMx：CTRIM结构体变量

 ** \retval [out] 返回值:TrimCode值
 **         
 ***********************************************************************************************/
uint32_t CTRIM_GetTrimCode(CTRIM_TypeDef* CTRIMx)
{
    return (uint32_t)(REG_READBITS(CTRIMx->TVAL, CTRIM_TVAL_TVAL));    
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取CTRIMx 计数误差捕获值，校准结束时，ARR寄存器里面的值
 ** \param  [in] CTRIMx：CTRIM结构体变量

 ** \retval [out] 返回值:计数误差捕获值
 **         
 ***********************************************************************************************/
uint32_t CTRIM_GetCountErrorCapture(CTRIM_TypeDef* CTRIMx)
{
    return (uint32_t)(REG_READBITS(CTRIMx->FCAP, CTRIM_FCAP_FCAP));    
}
 
 /**
 ***********************************************************************************************
 ** \brief  设定 CTRIMx 误差允许值， 一个周期计数结束，ARR寄存器里的值小于当前设定值，则认为校验成功。
 ** \param  [in] CTRIMx：CTRIM结构体变量
 ** \param  [in] u8ErrLimit: 误差上限值

 ** \retval NULL
 **         
 ***********************************************************************************************/
void CTRIM_SetCountErrorLimit(CTRIM_TypeDef* CTRIMx, uint8_t u8ErrLimit)
{
    REG_MODIFY(CTRIMx->FLIM, CTRIM_FLIM_FLIM, u8ErrLimit);    
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取CTRIMx 误差允许值, 一个周期计数结束，ARR寄存器里的值小于当前设定值，则认为校验成功。
 ** \param  [in] CTRIMx：CTRIM结构体变量

 ** \retval [out] 返回值:误差上限值
 **         
 ***********************************************************************************************/
uint8_t CTRIM_GetCountErrorLimit(CTRIM_TypeDef* CTRIMx)
{
    return (uint8_t)(REG_READBITS(CTRIMx->FLIM, CTRIM_FLIM_FLIM));    
}

/**
 ***********************************************************************************************
 ** \brief  开启CTRIMx模块
 ** \param  [in] CTRIMx：CTRIM结构体变量

 ** \retval NULL
 ***********************************************************************************************/
void CTRIM_Enable(CTRIM_TypeDef *CTRIMx)
{
    REG_SETBITS(CTRIMx->CR1, CTRIM_CR1_EN);
}

/**
 ***********************************************************************************************
 ** \brief  禁止CTRIMx模块
 ** \param  [in] CTRIMx：CTRIM结构体变量

 ** \retval NULL
 ***********************************************************************************************/
void CTRIM_Disable(CTRIM_TypeDef *CTRIMx)
{
    REG_CLEARBITS(CTRIMx->CR1, CTRIM_CR1_EN);    
}

/**
 ***********************************************************************************************
 ** \brief  检查CTRIMx模块是否已开启
 ** \param  [in] CTRIMx：CTRIM结构体变量

 ** \retval [out] 0：未开启； 非0：已开启
 ***********************************************************************************************/
uint32_t CTRIM_IsEnable(CTRIM_TypeDef *CTRIMx)
{
    return (uint32_t)(REG_READBITS(CTRIMx->CR1, CTRIM_CR1_EN) == CTRIM_CR1_EN);    
}

/**
 ***********************************************************************************************
 ** \brief  CTRIMx 中断使能
 ** \param  [in] CTRIMx：CTRIM结构体变量
 ** \param  [in] u32IT：中断控制位,下列值或下列值相或的组合
 **         @arg @ref CTRIM_IT_UD    误差计数器下溢 中断 
 **         @arg @ref CTRIM_IT_END   自动Trim结束 中断
 **         @arg @ref CTRIM_IT_PS    误差计数器完成(一次计数) 中断
 **         @arg @ref CTRIM_IT_MISS  计数失败(在GCLK的一个周期内，误差计数器已计数到ARR) 中断
 **         @arg @ref CTRIM_IT_OV    TrimCode溢出(TrimCode已调整到0或者0x1FF) 中断

 ** \retval NULL
 ***********************************************************************************************/
void CTRIM_EnableIT(CTRIM_TypeDef* CTRIMx, uint32_t u32IT)
{
    REG_SETBITS(CTRIMx->IER, u32IT);
}

/**
 ***********************************************************************************************
 ** \brief  CTRIMx 中断禁止
 ** \param  [in] CTRIMx：CTRIM结构体变量
 ** \param  [in] u32IT：中断控制位,下列值或下列值相或的组合
 **         @arg @ref CTRIM_IT_UD    误差计数器下溢 中断 
 **         @arg @ref CTRIM_IT_END   自动Trim结束 中断
 **         @arg @ref CTRIM_IT_PS    误差计数器完成(一次计数) 中断
 **         @arg @ref CTRIM_IT_MISS  计数失败(在GCLK的一个周期内，误差计数器已计数到ARR) 中断
 **         @arg @ref CTRIM_IT_OV    TrimCode溢出(TrimCode已调整到0或者0x1FF) 中断

 ** \retval NULL
 ***********************************************************************************************/
void CTRIM_DisableIT(CTRIM_TypeDef* CTRIMx, uint32_t u32IT)
{
    REG_CLEARBITS(CTRIMx->IER, u32IT);
}

/**
 ***********************************************************************************************
 ** \brief  检查CTRIM 中断是否开启
 ** \param  [in] CTRIMx：CTRIM结构体变量
 ** \param  [in] u32IT：中断控制位,下列值或下列值相或的组合
 **         @arg @ref CTRIM_IT_UD    误差计数器下溢 中断 
 **         @arg @ref CTRIM_IT_END   自动Trim结束 中断
 **         @arg @ref CTRIM_IT_PS    误差计数器完成(一次计数) 中断
 **         @arg @ref CTRIM_IT_MISS  计数失败(在GCLK的一个周期内，误差计数器已计数到ARR) 中断
 **         @arg @ref CTRIM_IT_OV    TrimCode溢出(TrimCode已调整到0或者0x1FF) 中断

 ** \retval [out] 0：未开启； 非0：已开启
 ***********************************************************************************************/
uint32_t CTRIM_IsEnableIT(ADC_TypeDef *CTRIMx, uint32_t u32IT)
{
    return (uint32_t)(REG_READBITS(CTRIMx->IER, u32IT) == u32IT);    
}

/**
 ***********************************************************************************************
 ** \brief  获取 CTRIMx 中断标志
 ** \param  [in] CTRIMx：CTRIM结构体变量
 ** \param  [in] u32ITFlag：中断标记,下列值或下列值相或的组合
 **         @arg @ref CTRIM_FLAG_UD    误差计数器下溢 标志 
 **         @arg @ref CTRIM_FLAG_END   自动Trim结束 标志
 **         @arg @ref CTRIM_FLAG_PS    误差计数器完成(一次计数) 标志
 **         @arg @ref CTRIM_FLAG_MISS  计数失败(在GCLK的一个周期内，误差计数器已计数到ARR) 标志
 **         @arg @ref CTRIM_FLAG_OV    TrimCode溢出(TrimCode已调整到0或者0x1FF) 标志
 **         @arg @ref CTRIM_FLAG_OK    Trim完成时精度满足FLIM要求 标志

 ** \retval [out] 返回值: 0或者1

 ***********************************************************************************************/
uint32_t CTRIM_IsActiveFlag(CTRIM_TypeDef* CTRIMx, uint32_t u32ITFlag)
{
    return (REG_READBITS(CTRIMx->ISR, u32ITFlag) == u32ITFlag);    
}

/**
 ***********************************************************************************************
 ** \brief  清除 CTRIMx 中断 标志位
 ** \param  [in] CTRIMx：CTRIM结构体变量
 ** \param  [in] u32ITFlag：中断标记,下列值或下列值相或的组合
 **         @arg @ref CTRIM_CLEAR_FLAG_UD    误差计数器下溢 标志 
 **         @arg @ref CTRIM_CLEAR_FLAG_END   自动Trim结束 标志
 **         @arg @ref CTRIM_CLEAR_FLAG_PS    误差计数器完成(一次计数) 标志
 **         @arg @ref CTRIM_CLEAR_FLAG_MISS  计数失败(在GCLK的一个周期内，误差计数器已计数到ARR) 标志
 **         @arg @ref CTRIM_CLEAR_FLAG_OV    TrimCode溢出(TrimCode已调整到0或者0x1FF) 标志
 **         @arg @ref CTRIM_CLEAR_FLAG_OK    Trim完成时精度满足FLIM要求 标志

 ** \retval NULL
 ***********************************************************************************************/
void CTRIM_ClearFlag(CTRIM_TypeDef* CTRIMx, uint32_t u32ITFlag)
{
    REG_CLEARBITS(CTRIMx->ICR, u32ITFlag);    
}

/**
 ***********************************************************************************************
 ** \brief  清除 CTRIMx 所有 标志位
 ** \param  [in] CTRIMx：CTRIM结构体变量

 ** \retval NULL
 ***********************************************************************************************/
void CTRIM_ClearFlag_ALL(CTRIM_TypeDef* CTRIMx)
{
    CTRIMx->ICR = 0;
}


//@} // CtrimGroup

/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
