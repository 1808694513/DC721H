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
 ** @file btim.c
 **
 ** @brief Source file for BTIM functions
 **
 ** @author MADS Team 
 **
 ******************************************************************************/

/******************************************************************************
 * Include files
 ******************************************************************************/

#include "btim.h"

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
 ** \brief  定时器BTIMx的初始化配置
 **
 ** @param  BTIMx    : BTIM结构体
 **
 ** @param  pstcInitCfg : 初始化BTIMx的结构体
 **         pstcInitCfg->u32TaskMode           //单次/连续计数模式控制
 **                      BTIM_TASK_MODE_CONTINUOUS_COUNTER//连续计数模式
 **                      BTIM_TASK_MODE_ONESHOT_COUNTER   //单次模式
 **
 **         pstcInitCfg->u32WorkMode        //工作模式控制
 **                      BTIM_WORK_MODE_PCLK              //定时器模式
 **                      BTIM_WORK_MODE_EXTERNAL          //计数器模式
 **                      BTIM_WORK_MODE_TRIGGER           //触发启动模式
 **                      BTIM_WORK_MODE_GATE              //门控模式
 **
 **         pstcInitCfg->u32Prescaler         
 **                      BTIM_COUNTER_CLK_DIV1
 **                      BTIM_COUNTER_CLK_DIV2
 **                      BTIM_COUNTER_CLK_DIV4
 **                      BTIM_COUNTER_CLK_DIV8
 **                      BTIM_COUNTER_CLK_DIV16
 **                      BTIM_COUNTER_CLK_DIV32
 **                      BTIM_COUNTER_CLK_DIV64
 **                      BTIM_COUNTER_CLK_DIV128
 **                      BTIM_COUNTER_CLK_DIV256
 **                      BTIM_COUNTER_CLK_DIV512
 **                      BTIM_COUNTER_CLK_DIV1024
 **                      BTIM_COUNTER_CLK_DIV2048
 **                      BTIM_COUNTER_CLK_DIV4096
 **                      BTIM_COUNTER_CLK_DIV8192
 **                      BTIM_COUNTER_CLK_DIV16384
 **                      BTIM_COUNTER_CLK_DIV32768
 **
 **
 **         pstcInitCfg->u32ToggleEn           //TOG管脚输出使能控制
 **                      BTIM_TOGGLE_DISABLE              //TOG禁止，输出电平为0
 **                      BTIM_TOGGLE_ENABLE               //TOG输出使能，电平反相
 **
 **         pstcInitCfg->u32TriggerSource      //触发源选择
 **                      BTIM_TRIGGER_SOURCE_ETR          //ETR引脚输入信号
 **                      BTIM_TRIGGER_SOURCE_TRGO         //ITR 内部级联信号
 **
 **         pstcInitCfg->u32ExInputPolarity    //外部管脚输入的ETR信号极性选择
   **                    BTIM_ETR_POLARITY_NORMAL         //ETR输入触发模式上升沿有效，门控模式高电平有效
 **                      BTIM_ETR_POLARITY_INVERTED       //ETR输入触发模式下降沿有效，门控模式低电平有效
 **
 ** \retval en_result_t类型数据
 **
******************************************************************************/
en_result_t Btim_Init(BTIM_TypeDef* BTIMx, stc_btim_init_t* pstcInitCfg)
{
    if (NULL == pstcInitCfg)
    {
        return ErrorInvalidParameter;
    }
    
    REG_MODIFY(BTIMx->CR, 
                           BTIM_CR_OST\
                            | BTIM_CR_MD\
                            | BTIM_CR_PRS\
                            | BTIM_CR_TOGEN\
                            | BTIM_CR_TRS\
                            | BTIM_CR_ETP\
                            , \
                            pstcInitCfg->u32TaskMode\
                            | pstcInitCfg->u32WorkMode\
                            | pstcInitCfg->u32Prescaler\
                            | pstcInitCfg->u32ToggleEn\
                            | pstcInitCfg->u32TriggerSource\
                            | pstcInitCfg->u32ExInputPolarity\
                            );
    
    REG_MODIFY(BTIMx->ARR, BTIM_ARR_ARR, (uint16_t)pstcInitCfg->u32AutoReloadVal);
            
    return Ok;
}
                   
 /**
 ***********************************************************************************************
 ** \brief  设定BTIMx计数器计数值
 **
 ** \param  [in] BTIMx：BTIM结构体变量
 **
 ** \param  [in] u16CntValue  //16bit 计数值
 **
 ** \retval [out] 返回值:BTIMx计数器计数值
 **         
 ***********************************************************************************************/
void Btim_SetCounter(BTIM_TypeDef* BTIMx, uint16_t u16CntValue)
{
    REG_WRITE(BTIMx->CNT, (uint32_t)u16CntValue);
}

 /**
 ***********************************************************************************************
 ** \brief  获取BTIMx计数器计数值
 **
 ** \param  [in] BTIMx：BTIM结构体变量

 ** \retval [out] 返回值:BTIMx计数器计数值
 **         
 ***********************************************************************************************/
uint32_t Btim_GetCounter(BTIM_TypeDef* BTIMx)
{
    return (uint32_t)(REG_READBITS(BTIMx->CNT, BTIM_CNT_CNT));    
}
 
 /**
 ***********************************************************************************************
 ** \brief  设定BTIMx 重载寄存器的值
 **
 ** \param  [in] BTIMx：BTIM结构体变量
 **
 ** \param  [in] u16AutoReload: 重载值
 **
 ** \retval NULL
 **         
 ***********************************************************************************************/
void Btim_SetAutoReload(BTIM_TypeDef* BTIMx, uint16_t u16AutoReload)
{
    REG_WRITE(BTIMx->ARR, (uint32_t)u16AutoReload);
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取BTIMx 重载寄存器的值
 **
 ** \param  [in] BTIMx：BTIM结构体变量
 **
 ** \retval [out] 返回值:BTIMx重载寄存器的值
 **         
 ***********************************************************************************************/
uint32_t Btim_GetAutoReload(BTIM_TypeDef* BTIMx)
{
    return (uint32_t)(REG_READBITS(BTIMx->ARR, BTIM_ARR_ARR));    
}

/**
 ***********************************************************************************************
 ** \brief  开启定时器BTIMx模块
 **
 ** \param  [in] BTIMx：BTIM结构体变量
 **
 ** \retval NULL
 ***********************************************************************************************/
void Btim_Enable(BTIM_TypeDef *BTIMx)
{
    REG_SETBITS(BTIMx->CR, BTIM_CR_CEN);
}

/**
 ***********************************************************************************************
 ** \brief  禁止定时器BTIMx模块
 **
 ** \param  [in] BTIMx：BTIM结构体变量
 **
 ** \retval NULL
 ***********************************************************************************************/
void Btim_Disable(BTIM_TypeDef *BTIMx)
{
    REG_CLEARBITS(BTIMx->CR, BTIM_CR_CEN);    
}

/**
 ***********************************************************************************************
 ** \brief  检查定时器BTIMx模块是否已开启
 **
 ** \param  [in] BTIMx：BTIM结构体变量
 **
 ** \retval [out] 0：未开启； 非0：已开启
 ***********************************************************************************************/
uint32_t Btim_IsEnable(BTIM_TypeDef *BTIMx)
{
    return (uint32_t)(REG_READBITS(BTIMx->CR, BTIM_CR_CEN) == BTIM_CR_CEN);    
}


 
 /**
 ***********************************************************************************************
 ** \brief  设定定时器BTIMx 工作模式
 **
 ** \param  [in] BTIMx：BTIM结构体变量
 **
 ** \param  [in] u32WorkMode: 选择BTIM工作模式
 **              BTIM_WORK_MODE_PCLK              //定时器模式
 **              BTIM_WORK_MODE_EXTERNAL          //计数器模式
 **              BTIM_WORK_MODE_TRIGGER           //触发启动模式
 **              BTIM_WORK_MODE_GATE              //门控模式
 **
 ** \retval NULL
 **         
 ***********************************************************************************************/
void Btim_SetWorkMode(BTIM_TypeDef* BTIMx, uint32_t u32WorkMode)
{
    REG_MODIFY(BTIMx->CR, BTIM_CR_MD, u32WorkMode);    
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取定时器BTIMx 工作模式
 ** \param  [in] BTIMx：BTIM结构体变量

 ** \retval [out] 返回值:选择BTIM工作模式
 **               BTIM_WORK_MODE_PCLK              //定时器模式
 **               BTIM_WORK_MODE_EXTERNAL          //计数器模式
 **               BTIM_WORK_MODE_TRIGGER           //触发启动模式
 **               BTIM_WORK_MODE_GATE              //门控模式
 **         
 ***********************************************************************************************/
uint32_t Btim_GetWorkMode(BTIM_TypeDef* BTIMx)
{
    return (uint32_t)(REG_READBITS(BTIMx->CR, BTIM_CR_MD));    
}



/**
 ***********************************************************************************************
 ** \brief  定时器BTIMx TOG输出使能，TOGP和TOGN输出相位相反的信号
 **
 ** \param  [in] BTIMx：BTIM结构体变量
 **
 ** \retval NULL
 ***********************************************************************************************/
void Btim_EnableToggle(BTIM_TypeDef *BTIMx)
{
    REG_SETBITS(BTIMx->CR, BTIM_CR_TOGEN);
}

/**
 ***********************************************************************************************
 ** \brief  定时器BTIMx TOG输出禁止，TOGP和TOGN同时输出0
 **
 ** \param  [in] BTIMx：BTIM结构体变量
 **
 ** \retval NULL
 ***********************************************************************************************/
void Btim_DisableToggle(BTIM_TypeDef *BTIMx)
{
    REG_CLEARBITS(BTIMx->CR, BTIM_CR_TOGEN);    
}

/**
 ***********************************************************************************************
 ** \brief  检查定时器BTIMx模块 TOG输出 是否已开启
 **
 ** \param  [in] BTIMx：BTIM结构体变量
 **
 ** \retval [out] 0：未开启； 非0：已开启
 ***********************************************************************************************/
uint32_t Btim_IsEnableToggle(BTIM_TypeDef *BTIMx)
{
    return (uint32_t)(REG_READBITS(BTIMx->CR, BTIM_CR_TOGEN) == BTIM_CR_TOGEN);    
}


 /**
 ***********************************************************************************************
 ** \brief  定时器BTIMx模块 计数时钟预除频
 **
 ** \param  [in] BTIMx：BTIM结构体变量
 **
 ** \param  [in] u32CounterClkDiv: 计数时钟预分频选择
 **              BTIM_COUNTER_CLK_DIV1  
 **              BTIM_COUNTER_CLK_DIV2
 **              BTIM_COUNTER_CLK_DIV4  
 **              BTIM_COUNTER_CLK_DIV8  
 **              BTIM_COUNTER_CLK_DIV16
 **              BTIM_COUNTER_CLK_DIV32  
 **              BTIM_COUNTER_CLK_DIV64  
 **              BTIM_COUNTER_CLK_DIV128
 **              BTIM_COUNTER_CLK_DIV256  
 **              BTIM_COUNTER_CLK_DIV512  
 **              BTIM_COUNTER_CLK_DIV1024
 **              BTIM_COUNTER_CLK_DIV2048  
 **              BTIM_COUNTER_CLK_DIV4096  
 **              BTIM_COUNTER_CLK_DIV8192
 **              BTIM_COUNTER_CLK_DIV16384 
 **              BTIM_COUNTER_CLK_DIV32768   
 **
 ** \retval NULL
 **         
 ***********************************************************************************************/
void Btim_SetCounterClkDiv(BTIM_TypeDef* BTIMx, uint32_t u32CounterClkDiv)
{
    REG_MODIFY(BTIMx->CR, BTIM_CR_PRS, u32CounterClkDiv);    
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取定时器BTIMx 时钟，此时钟是定时器模块工作时钟，非计数时钟源
 **
 ** \param  [in] BTIMx：BTIM结构体变量
 **
 ** \retval [out] 返回值:计数时钟预分频
 **              BTIM_COUNTER_CLK_DIV1  
 **              BTIM_COUNTER_CLK_DIV2
 **              BTIM_COUNTER_CLK_DIV4  
 **              BTIM_COUNTER_CLK_DIV8  
 **              BTIM_COUNTER_CLK_DIV16
 **              BTIM_COUNTER_CLK_DIV32  
 **              BTIM_COUNTER_CLK_DIV64  
 **              BTIM_COUNTER_CLK_DIV128
 **              BTIM_COUNTER_CLK_DIV256  
 **              BTIM_COUNTER_CLK_DIV512  
 **              BTIM_COUNTER_CLK_DIV1024
 **              BTIM_COUNTER_CLK_DIV2048  
 **              BTIM_COUNTER_CLK_DIV4096  
 **              BTIM_COUNTER_CLK_DIV8192
 **              BTIM_COUNTER_CLK_DIV16384 
 **              BTIM_COUNTER_CLK_DIV32768  
 **         
 ***********************************************************************************************/
uint32_t Btim_GetCounterClkDiv(BTIM_TypeDef* BTIMx)
{
    return (uint32_t)(REG_READBITS(BTIMx->CR, BTIM_CR_PRS));    
}


 /**
 ***********************************************************************************************
 ** \brief  设定BTIMx 计数模式：连续计数模式或单次计数模式
 **
 ** \param  [in] BTIMx：BTIM结构体变量
 **
 ** \param  [in] u32Mode: 计数模式
 **              BTIM_TASK_MODE_CONTINUOUS_COUNTER//连续计数模式
 **              BTIM_TASK_MODE_ONESHOT_COUNTER   //单次模式
 **
 ** \retval NULL
 **         
 ***********************************************************************************************/
void Btim_SetOneShotMode(BTIM_TypeDef* BTIMx, uint32_t u32Mode)
{
    REG_MODIFY(BTIMx->CR, BTIM_CR_OST, u32Mode);    
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取BTIMx 计数模式：连续计数模式或单次计数模式
 **
 ** \param  [in] BTIMx：BTIM结构体变量
 **
 ** \retval [out] 返回值:BTIMx 计数模式
 **              BTIM_TASK_MODE_CONTINUOUS_COUNTER//连续计数模式
 **              BTIM_TASK_MODE_ONESHOT_COUNTER   //单次模式
 **         
 ***********************************************************************************************/
uint32_t Btim_GetOneShotMode(BTIM_TypeDef* BTIMx)
{
    return (uint32_t)(REG_READBITS(BTIMx->CR, BTIM_CR_OST));    
}


 
 /**
 ***********************************************************************************************
 ** \brief  设定定时器BTIMx 触发源
 **
 ** \rmtoll CR      TRS          Btim_SetTriggerSource
 **
 ** \param  [in] BTIMx：BTIM结构体变量
 **
 ** \param  [in] u32TriggerSource: 选择BTIM触发源
 **              BTIM_TRIGGER_SOURCE_ETR      //外部管脚TER作为计数器触发源，或门控
 **              BTIM_TRIGGER_SOURCE_TRGO     //上一级BTIM溢出信号,门控模式下不建议选此源作为门控信号
 **
 ** \retval NULL
 **         
 ***********************************************************************************************/
void Btim_SetTriggerSource(BTIM_TypeDef* BTIMx, uint32_t u32TriggerSource)
{
    REG_MODIFY(BTIMx->CR, BTIM_CR_TRS, u32TriggerSource);    
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取定时器BTIMx 触发源
 **
 ** \rmtoll CR      TRS          Btim_GetTriggerSource
 **
 ** \param  [in] BTIMx：BTIM结构体变量
 **
 ** \retval [out] 返回值:BTIM 触发源
 **              BTIM_TRIGGER_SOURCE_ETR      //外部管脚TER作为计数器触发源，或门控
 **              BTIM_TRIGGER_SOURCE_TRGO     //上一级BTIM溢出信号,门控模式下不建议选此源作为门控信号
 **         
 ***********************************************************************************************/
uint32_t Btim_GetTriggerSource(BTIM_TypeDef* BTIMx)
{
    return (uint32_t)(REG_READBITS(BTIMx->CR, BTIM_CR_TRS));    
}

 
 /**
 ***********************************************************************************************
 ** \brief  设定定时器BTIMx 外部输入ETR极性设定
 **
 ** \rmtoll CR      ETP          Btim_SetExInputPolarity
 **
 ** \param  [in] BTIMx：BTIM结构体变量
 **
 ** \param  [in] u32ExInputPolarity: 外部输入ETR极性
 **              BTIM_ETR_POLARITY_NORMAL         //外部输入ETR不反向(触发模式上沿触发，门控模式低电平停止计数)
 **              BTIM_ETR_POLARITY_INVERTED       //外部输入ETR反向(触发模式下沿触发，门控模式高电平停止计数)

 ** \retval NULL
 **         
 ***********************************************************************************************/
void Btim_SetExInputPolarity(BTIM_TypeDef* BTIMx, uint32_t u32ExInputPolarity)
{
    REG_MODIFY(BTIMx->CR, BTIM_CR_ETP, u32ExInputPolarity);    
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取定时器BTIMx 触发源
 **
 ** \rmtoll CR      TRS          Btim_GetExInputPolarity
 **
 ** \param  [in] BTIMx：BTIM结构体变量
 **
 ** \retval [out] 返回值:外部输入ETR极性
 **              BTIM_ETR_POLARITY_NORMAL         //外部输入ETR不反向(触发模式上沿触发，门控模式低电平停止计数)
 **              BTIM_ETR_POLARITY_INVERTED       //外部输入ETR反向(触发模式下沿触发，门控模式高电平停止计数)
 **         
 ***********************************************************************************************/
uint32_t Btim_GetExInputPolarity(BTIM_TypeDef* BTIMx)
{
    return (uint32_t)(REG_READBITS(BTIMx->CR, BTIM_CR_ETP));    
}

/**
 ***********************************************************************************************
 ** \brief  BTIMx 中断使能
 **
 ** \param  [in] BTIMx：BTIM结构体变量
 **
 ** \param  [in] u32IntClrFlag
 **              BTIM_IT_UI     //溢出中断使能控制
 **              BTIM_IT_TI     //触发中断使能控制
 **
 ** \retval NULL
 ***********************************************************************************************/
void Btim_EnableIT(BTIM_TypeDef* BTIMx, uint32_t u32IntClrFlag)
{
    REG_SETBITS(BTIMx->IER, u32IntClrFlag);
}

/**
 ***********************************************************************************************
 ** \brief  BTIMx 中断禁止
 **
 ** \param  [in] BTIMx：BTIM结构体变量
 **
 ** \param  [in] u32IntClrFlag
 **              BTIM_IT_UI     //溢出中断使能控制
 **              BTIM_IT_TI     //触发中断使能控制
 **
 ** \retval NULL
 ***********************************************************************************************/
void Btim_DisableIT(BTIM_TypeDef* BTIMx, uint32_t u32IntClrFlag)
{
    REG_CLEARBITS(BTIMx->IER, u32IntClrFlag);    
}

/**
 ***********************************************************************************************
 ** \brief  检查 BTIMx 查询中断 是否已使能
 **
 ** \param  [in] BTIMx：BTIM结构体变量
 **
 ** \param  [in] u32IntClrFlag
 **              BTIM_IT_UI     //溢出中断使能控制
 **              BTIM_IT_TI     //触发中断使能控制
 **
 ** \retval [out] 返回值 对应bit 0:未置起 1:已置起
 ***********************************************************************************************/
uint32_t Btim_IsEnableIT(BTIM_TypeDef* BTIMx, uint32_t u32IntClrFlag)
{
    return (uint32_t)(REG_READBITS(BTIMx->IER, u32IntClrFlag) == u32IntClrFlag);    
}

/**
 ***********************************************************************************************
 ** \brief  获取 BTIMx 中断标志
 **
 ** \param  [in] BTIMx：BTIM结构体变量
 **
 ** \param  [in] u32IntFlag
 **              BTIM_IT_FLAG_UI     //溢出中断标志
 **              BTIM_IT_FLAG_TI     //触发中断标志
 **
 ** \retval [out]  返回值 对应bit 0:未置起 1:已置起
 **
 ***********************************************************************************************/
uint32_t Btim_IsActiveFlag(BTIM_TypeDef* BTIMx, uint32_t u32IntFlag)
{
    return (REG_READBITS(BTIMx->IFR, u32IntFlag) == u32IntFlag);    
}


/**
 ***********************************************************************************************
 ** \brief  清除 BTIMx 中断 标志位
 **
 ** \param  [in] BTIMx：BTIM结构体变量
 **
 ** \param  [in] u32IntClrFlag
 **              BTIM_IT_CLR_UI     //清除溢出中断标志
 **              BTIM_IT_CLR_TI     //清除触发中断标志
 **
 ** \retval NULL
 ***********************************************************************************************/
void Btim_ClearFlag(BTIM_TypeDef* BTIMx, uint32_t u32IntClrFlag)
{
    REG_CLEARBITS(BTIMx->ICR, u32IntClrFlag);    
}


/**
 ***********************************************************************************************
 ** \brief  获取 复合 BTIM3/4/5 中断标志
 **
 ** \param  [in] BTIMx：BTIM结构体变量
 **
 ** \param  [in] u32IntFlag
 **              BTIM3_AIT_FLAG_UI     //BTIM3溢出中断标志
 **              BTIM3_AIT_FLAG_TI     //BTIM3触发中断标志
 **              BTIM4_AIT_FLAG_UI     //BTIM4溢出中断标志
 **              BTIM4_AIT_FLAG_TI     //BTIM4触发中断标志
 **              BTIM5_AIT_FLAG_UI     //BTIM5溢出中断标志
 **              BTIM5_AIT_FLAG_TI     //BTIM5触发中断标志
 **
 ** \retval [out]  返回值 对应bit 0:未置起 1:已置起
 **
 ***********************************************************************************************/
uint32_t Btim_AIFR345_IsActiveFlag(BTIM_TypeDef* BTIMx, uint32_t u32IntFlag)
{
    return (REG_READBITS(BTIMx->AIFR, u32IntFlag) == u32IntFlag);    
}


/**
 ***********************************************************************************************
 ** \brief  清除 复合 BTIM3/4/5 标志位
 **
 ** \param  [in] BTIMx：BTIM结构体变量
 **
 ** \param  [in] u32IntClrFlag
 **              BTIM3_AIT_CLR_UI     //清除BTIM3溢出中断标志
 **              BTIM3_AIT_CLR_TI     //清除BTIM3触发中断标志
 **              BTIM4_AIT_CLR_UI     //清除BTIM4溢出中断标志
 **              BTIM4_AIT_CLR_TI     //清除BTIM4触发中断标志
 **              BTIM5_AIT_CLR_UI     //清除BTIM5溢出中断标志
 **              BTIM5_AIT_CLR_TI     //清除BTIM5触发中断标志
 **
 ** \retval NULL
 ***********************************************************************************************/
void Btim_AICR345_ClearFlag(BTIM_TypeDef* BTIMx, uint32_t u32IntClrFlag)
{
    REG_CLEARBITS(BTIMx->AICR, u32IntClrFlag);    
}

/******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
