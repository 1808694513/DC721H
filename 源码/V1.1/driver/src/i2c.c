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
 ** @file i2c.c
 **
 ** @brief Source file for I2C functions
 **
 ** @author MADS Team 
 **
 ******************************************************************************/

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "i2c.h"

/**
 *******************************************************************************
 ** \addtogroup I2cGroup
 ******************************************************************************/
//@{

/******************************************************************************/
/* Local function prototypes ('static')                                       */
/******************************************************************************/


/**
 ******************************************************************************
 ** \brief  I2C模块主机初始化
 **
 ** \param  pstcMasterInitCfg
 **
 ** \retval 初始化是否成功
 **
 ******************************************************************************/
en_result_t I2C_MasterInit(I2C_TypeDef* I2Cx, stc_i2c_master_init_cfg_t *pstcMasterInitCfg)
{   
    uint8_t u8Tm;
    
    I2Cx->CR = 0;
    
    if((pstcMasterInitCfg->u32BaudRate<<4) > pstcMasterInitCfg->u32Pclk)
    {
        return Error;
    }       
    
    I2Cx->BRREN |= I2C_BRREN_EN;  //使能波特率发生器
    ///< Fsck = Fpclk/8*(Tm+1)
    u8Tm = ((pstcMasterInitCfg->u32Pclk / pstcMasterInitCfg->u32BaudRate) >> 3) - 1;
    I2Cx->BRR = u8Tm;
    if(9 > u8Tm)
    {
        I2Cx->CR |= I2C_CR_FLT;  //使用简单滤波，以适应更快的通信速率
    }
 
    return Ok;
}

/**
 ******************************************************************************
 ** \brief  I2C模块从机初始化
 **
 ** \param  pstcSlaveInitCfg
 **
 ** \retval 初始化是否成功
 **
 ******************************************************************************/
en_result_t I2C_SlaveInit(I2C_TypeDef* I2Cx, stc_i2c_slave_init_cfg_t *pstcSlaveInitCfg)
{   
    I2Cx->CR = 0;   
    
    I2Cx->BRREN = 0;  //禁止波特率发生器
    
    I2Cx->ADDR0 = ((uint32_t)pstcSlaveInitCfg->u8SlaveAddr0 << 1) | (pstcSlaveInitCfg->u32BroadcastEn);
    I2Cx->ADDR1 = ((uint32_t)pstcSlaveInitCfg->u8SlaveAddr1 << 1);
    I2Cx->ADDR2 = ((uint32_t)pstcSlaveInitCfg->u8SlaveAddr2 << 1);
    
    //pclk与scl频率比值小于等于30时置1，否则置0
    REG_MODIFY(I2Cx->CR, I2C_CR_FLT, pstcSlaveInitCfg->u32Filter);
 
    return Ok;
}

/**
 ***********************************************************************************************
 ** \brief  使能 I2C 波特率发生器
 ** \param  [in] I2Cx：I2C结构体变量

 ** \retval NULL
 ***********************************************************************************************/
void I2C_EnableBaud(I2C_TypeDef *I2Cx)
{
    REG_SETBITS(I2Cx->BRREN, I2C_BRREN_EN);
}

/**
 ***********************************************************************************************
 ** \brief  禁止 I2C 波特率发生器
 ** \param  [in] I2Cx：I2C结构体变量

 ** \retval NULL
 ***********************************************************************************************/
void I2C_DisableBaud(I2C_TypeDef *I2Cx)
{
    REG_CLEARBITS(I2Cx->BRREN, I2C_BRREN_EN);    
}

/**
 ***********************************************************************************************
 ** \brief  检查I2C 波特率发生器 是否已开启
 ** \param  [in] I2Cx：I2C结构体变量

 ** \retval [out] 0：未开启； 非0：已开启
 ***********************************************************************************************/
uint32_t I2C_IsEnableBaud(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(REG_READBITS(I2Cx->BRREN, I2C_BRREN_EN) == I2C_BRREN_EN);    
}
 
 /**
 ***********************************************************************************************
 ** \brief  设置 I2C 波特率配置寄存器
 ** \param  [in] I2Cx：I2C结构体变量
 ** \param  [in] u32Baud: 波特率配置值

 ** \retval NULL
 **         
 ***********************************************************************************************/
void I2C_SetBaud(I2C_TypeDef *I2Cx, uint32_t u32Baud)
{
    REG_MODIFY(I2Cx->BRR, I2C_BRR_BRR, u32Baud);
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取 I2C 波特率配置寄存器的值
 ** \param  [in] I2Cx：I2C结构体变量

 ** \retval [out] 返回值:I2C 波特率配置寄存器的值
 **         
 ***********************************************************************************************/
uint32_t I2C_GetBaud(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(REG_READBITS(I2Cx->BRR, I2C_BRR_BRR));    
}
 
 /**
 ***********************************************************************************************
 ** \brief  设置 I2C 滤波参数，作为主机I2C_BRR值大于9，或者作为从机PCLK与SCL频率比值大于30时，建议使用I2C_FILTER_ADVANCE
 ** \param  [in] I2Cx：I2C结构体变量
 ** \param  [in] u32Filter: 滤波参数
 **         @arg @ref I2C_FILTER_ADVANCE     更高的抗干扰性能
 **         @arg @ref I2C_FILTER_SIMPLE      更快的通信滤波

 ** \retval NULL
 **         
 ***********************************************************************************************/
void I2C_SetFilter(I2C_TypeDef *I2Cx, uint32_t u32Filter)
{
    REG_MODIFY(I2Cx->CR, I2C_CR_FLT, u32Filter);
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取 I2C 滤波参数
 ** \param  [in] I2Cx：I2C结构体变量

 ** \retval [out] 返回值:I2C 滤波参数
 **         @arg @ref I2C_FILTER_ADVANCE     更高的抗干扰性能
 **         @arg @ref I2C_FILTER_SIMPLE      更快的通信滤波
 **         
 ***********************************************************************************************/
uint32_t I2C_GetFilter(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(REG_READBITS(I2Cx->CR, I2C_CR_FLT));    
}

/**
 ***********************************************************************************************
 ** \brief  获取 I2Cx 状态中断标志
 ** \param  [in] I2Cx：I2C结构体变量

 ** \retval [out] 返回值: 0或者1

 ***********************************************************************************************/
uint32_t I2C_IsActiveFlag_SI(I2C_TypeDef *I2Cx)
{
    return (REG_READBITS(I2Cx->CR, I2C_CR_SI) == I2C_CR_SI);    
}

/**
 ***********************************************************************************************
 ** \brief  清除 I2Cx 状态中断 标志位
 ** \param  [in] I2Cx：I2C结构体变量

 ** \retval NULL
 ***********************************************************************************************/
void I2C_ClearFlag_SI(I2C_TypeDef *I2Cx)
{
    REG_CLEARBITS(I2Cx->CR, I2C_CR_SI);    
}

 /**
 ***********************************************************************************************
 ** \brief  设置 I2C 应答控制
 ** \param  [in] I2Cx：I2C结构体变量
 ** \param  [in] u32Ack: 应答控制
 **         @arg @ref I2C_NACK     在应答阶段发送ACK
 **         @arg @ref I2C_ACK      在应答阶段发送NAK

 ** \retval NULL
 **         
 ***********************************************************************************************/
void I2C_SetAck(I2C_TypeDef *I2Cx, uint32_t u32Ack)
{
    REG_MODIFY(I2Cx->CR, I2C_CR_AA, u32Ack);
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取 I2C 应答配置
 ** \param  [in] I2Cx：I2C结构体变量

 ** \retval [out] 返回值:I2C 应答配置
 **         @arg @ref I2C_NACK     在应答阶段发送ACK
 **         @arg @ref I2C_ACK      在应答阶段发送NAK
 **         
 ***********************************************************************************************/
uint32_t I2C_GetAck(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(REG_READBITS(I2Cx->CR, I2C_CR_AA));    
}

 /**
 ***********************************************************************************************
 ** \brief  I2C 总线状态控制 发送STOP
 ** \param  [in] I2Cx：I2C结构体变量
 **         @arg @ref I2C_STOP_DISABLE
 **         @arg @ref I2C_STOP_ENABLE

 ** \retval NULL
 **         
 ***********************************************************************************************/
void I2C_SetStop(I2C_TypeDef *I2Cx, uint32_t u32Stop)
{
    REG_MODIFY(I2Cx->CR, I2C_CR_STO, u32Stop);
}

 /**
 ***********************************************************************************************
 ** \brief  I2C 总线状态控制 发送START
 ** \param  [in] I2Cx：I2C结构体变量
 ** \param  [in] u32Start：是否使能发送START
 **         @arg @ref I2C_START_DISABLE
 **         @arg @ref I2C_START_ENABLE

 ** \retval NULL
 **         
 ***********************************************************************************************/
void I2C_SetStart(I2C_TypeDef *I2Cx, uint32_t u32Start)
{
    REG_MODIFY(I2Cx->CR, I2C_CR_STA, u32Start);
}

 /**
 ***********************************************************************************************
 ** \brief  I2C 总线状态控制 清除START
 ** \param  [in] I2Cx：I2C结构体变量

 ** \retval [out] 返回值:I2C start状态位
 **         @arg @ref I2C_START_DISABLE
 **         @arg @ref I2C_START_ENABLE
 **         
 ***********************************************************************************************/
uint32_t I2C_GetStart(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(REG_READBITS(I2Cx->CR, I2C_CR_STA));    
}

/**
 ***********************************************************************************************
 ** \brief  使能 I2C 模块
 ** \param  [in] I2Cx：I2C结构体变量

 ** \retval NULL
 ***********************************************************************************************/
void I2C_Enable(I2C_TypeDef *I2Cx)
{
    REG_SETBITS(I2Cx->CR, I2C_CR_EN);
}

/**
 ***********************************************************************************************
 ** \brief  禁止 I2C 模块
 ** \param  [in] I2Cx：I2C结构体变量

 ** \retval NULL
 ***********************************************************************************************/
void I2C_Disable(I2C_TypeDef *I2Cx)
{
    REG_CLEARBITS(I2Cx->CR, I2C_CR_EN);    
}

/**
 ***********************************************************************************************
 ** \brief  检查I2C 模块 是否已开启
 ** \param  [in] I2Cx：I2C结构体变量

 ** \retval [out] 0：未开启； 非0：已开启
 ***********************************************************************************************/
uint32_t I2C_IsEnable(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(REG_READBITS(I2Cx->CR, I2C_CR_EN) == I2C_CR_EN);    
}
 
 /**
 ***********************************************************************************************
 ** \brief  设置 I2C 数据寄存器，写入待发送的数据
 ** \param  [in] I2Cx：I2C结构体变量
 ** \param  [in] u8Data: 8bit数据值

 ** \retval NULL
 **         
 ***********************************************************************************************/
void I2C_WriteByte(I2C_TypeDef *I2Cx, uint8_t u8Data)
{
    REG_MODIFY(I2Cx->DR, I2C_DR_DR, u8Data);
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取 I2C 数据寄存器，读出接收到的数据
 ** \param  [in] I2Cx：I2C结构体变量

 ** \retval [out] 返回值:I2C 8bit数据值
 **         
 ***********************************************************************************************/
uint8_t I2C_ReadByte(I2C_TypeDef *I2Cx)
{
    return (uint8_t)(REG_READBITS(I2Cx->DR, I2C_DR_DR));    
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取 I2C 总线状态
 ** \param  [in] I2Cx：I2C结构体变量

 ** \retval [out] 返回值:I2C 总线状态码，状态码的具体定义详见[状态码表述]章节
 **         
 ***********************************************************************************************/
uint8_t I2C_GetBusState(I2C_TypeDef *I2Cx)
{
    return (uint8_t)(REG_READBITS(I2Cx->STAT, I2C_STAT_STAT));    
}

/**
 ***********************************************************************************************
 ** \brief  使能 I2C 广播地址应答
 ** \param  [in] I2Cx：I2C结构体变量
 **         @arg @ref I2C_BROADCAST_DISABLE  禁止广播地址应答
 **         @arg @ref I2C_BROADCAST_ENABLE   使能广播地址应答

 ** \retval NULL
 ***********************************************************************************************/
void I2C_EnableBroadcast(I2C_TypeDef *I2Cx)
{
    REG_SETBITS(I2Cx->ADDR0, I2C_ADDR0_GC);
}

/**
 ***********************************************************************************************
 ** \brief  禁止 I2C 广播地址应答
 ** \param  [in] I2Cx：I2C结构体变量

 ** \retval NULL
 ***********************************************************************************************/
void I2C_DisableBroadcast(I2C_TypeDef *I2Cx)
{
    REG_CLEARBITS(I2Cx->ADDR0, I2C_ADDR0_GC);    
}

/**
 ***********************************************************************************************
 ** \brief  检查I2C 广播地址应答 是否已开启
 ** \param  [in] I2Cx：I2C结构体变量

 ** \retval [out] 0：未开启； 非0：已开启
 ***********************************************************************************************/
uint32_t I2C_IsEnableBroadcast(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(REG_READBITS(I2Cx->ADDR0, I2C_ADDR0_GC) == I2C_ADDR0_GC);    
}
 
 /**
 ***********************************************************************************************
 ** \brief  设置 I2C 从机模式地址0
 ** \param  [in] I2Cx：I2C结构体变量
 ** \param  [in] u32Addr: 地址值

 ** \retval NULL
 **         
 ***********************************************************************************************/
void I2C_SetSlaveAddr0(I2C_TypeDef *I2Cx, uint32_t u32Addr)
{
    REG_MODIFY(I2Cx->ADDR0, I2C_ADDR0_ADDR0, u32Addr);
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取 I2C 从机模式地址0
 ** \param  [in] I2Cx：I2C结构体变量

 ** \retval [out] 返回值:地址值
 **         
 ***********************************************************************************************/
uint32_t I2C_GetSlaveAddr0(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(REG_READBITS(I2Cx->ADDR0, I2C_ADDR0_ADDR0));    
}
 
 /**
 ***********************************************************************************************
 ** \brief  设置 I2C 从机模式地址1
 ** \param  [in] I2Cx：I2C结构体变量
 ** \param  [in] u32Addr: 地址值

 ** \retval NULL
 **         
 ***********************************************************************************************/
void I2C_SetSlaveAddr1(I2C_TypeDef *I2Cx, uint32_t u32Addr)
{
    REG_MODIFY(I2Cx->ADDR1, I2C_ADDR1_ADDR, u32Addr);
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取 I2C 从机模式地址1
 ** \param  [in] I2Cx：I2C结构体变量

 ** \retval [out] 返回值:地址值
 **         
 ***********************************************************************************************/
uint32_t I2C_GetSlaveAddr1(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(REG_READBITS(I2Cx->ADDR1, I2C_ADDR1_ADDR));    
}
 
 /**
 ***********************************************************************************************
 ** \brief  设置 I2C 从机模式地址2
 ** \param  [in] I2Cx：I2C结构体变量
 ** \param  [in] u32Addr: 地址值

 ** \retval NULL
 **         
 ***********************************************************************************************/
void I2C_SetSlaveAddr2(I2C_TypeDef *I2Cx, uint32_t u32Addr)
{
    REG_MODIFY(I2Cx->ADDR2, I2C_ADDR2_ADDR, u32Addr);
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取 I2C 从机模式地址2
 ** \param  [in] I2Cx：I2C结构体变量

 ** \retval [out] 返回值:地址值
 **         
 ***********************************************************************************************/
uint32_t I2C_GetSlaveAddr2(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(REG_READBITS(I2Cx->ADDR2, I2C_ADDR2_ADDR));    
}

/**
 ***********************************************************************************************
 ** \brief  获取 I2Cx 是哪个从机地址与总线收到的设备地址匹配。
 ** \param  [in] I2Cx：I2C结构体变量

 ** \retval [out] 返回值: 
 **         @arg @ref I2C_BUS_ADDR_MATCH_NONE    无从地址与总线上的设备地址匹配
 **         @arg @ref I2C_BUS_ADDR_MATCH_ADDR0   设备从地址ADDR0与总线上的设备地址匹配
 **         @arg @ref I2C_BUS_ADDR_MATCH_ADDR1   设备从地址ADDR1与总线上的设备地址匹配
 **         @arg @ref I2C_BUS_ADDR_MATCH_ADDR2   设备从地址ADDR2与总线上的设备地址匹配

 ***********************************************************************************************/
uint32_t I2C_GetBusMatchSlaveAddr(I2C_TypeDef *I2Cx)
{
    return (uint32_t)(REG_READBITS(I2Cx->MATCH, (I2C_MATCH_AD0F | I2C_MATCH_AD1F |I2C_MATCH_AD2F)));    
}

//@} // I2cGroup
