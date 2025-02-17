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
 ** @file spi.c
 **
 ** @brief Source file for SPI functions
 **
 ** @author MADS Team 
 **
 ******************************************************************************/

/******************************************************************************
 * Include files
 *****************************************************************************/
#include "spi.h"

/**
 ******************************************************************************
 ** \addtogroup SpiGroup
 *****************************************************************************/
//@{

/******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 *****************************************************************************/


/******************************************************************************/
/* Local function prototypes ('static')                                       */
/******************************************************************************/

/******************************************************************************/
/* Local variable prototypes ('static')                                       */
/******************************************************************************/

/**
 ******************************************************************************
 ** \brief  SPI 总体初始化函数
 **
 ** \param [in] SPIx 通道
 ** \param [in] pstcSpiCfg 初始化结构体
 **
 ** \retval Ok初始化成功
 ** \retval ErrorInvalidParameter 初始化错误
 ******************************************************************************/
en_result_t Spi_Init(SPI_TypeDef* SPIx, stc_spi_init_t *pstcInitCfg)
{
    ASSERT(NULL != pstcInitCfg);
    
    REG_MODIFY(SPIx->CR0, 
                 SPI_CR0_BRR
               | SPI_CR0_CPHA
               | SPI_CR0_CPOL
               | SPI_CR0_MSTR
               | SPI_CR0_LSBF
               | SPI_CR0_WIDTH
               | SPI_CR0_SSM
               | SPI_CR0_CM
               , 
                 pstcInitCfg->u32BaudRate
               | pstcInitCfg->u32CPHA
               | pstcInitCfg->u32CPOL
               | pstcInitCfg->u32Mode
               | pstcInitCfg->u32BitOrder
               | pstcInitCfg->u32DataWidth
               | pstcInitCfg->u32NSS
               | pstcInitCfg->u32TransferDirection);
               
    return Ok;
}

/**
 ***********************************************************************************************
 ** \brief  开启SPI模块
 ** \param  [in] SPIx：SPI结构体变量

 ** \retval NULL
 ***********************************************************************************************/
void SPI_Enable(SPI_TypeDef *SPIx)
{
    REG_SETBITS(SPIx->CR0, SPI_CR0_EN);
}

/**
 ***********************************************************************************************
 ** \brief  禁止SPI模块
 ** \param  [in] SPIx：SPI结构体变量

 ** \retval NULL
 ***********************************************************************************************/
void SPI_Disable(SPI_TypeDef *SPIx)
{
    REG_CLEARBITS(SPIx->CR0, SPI_CR0_EN);    
}

/**
 ***********************************************************************************************
 ** \brief  检查SPI模块是否已开启
 ** \param  [in] SPIx：SPI结构体变量

 ** \retval [out] 0：未开启； 非0：已开启
 ***********************************************************************************************/
uint32_t SPI_IsEnable(SPI_TypeDef *SPIx)
{
    return (uint32_t)(REG_READBITS(SPIx->CR0, SPI_CR0_EN) == SPI_CR0_EN);    
}
 
 /**
 ***********************************************************************************************
 ** \brief  设定SPI主机模式波特率
 ** \param  [in] SPIx：SPI结构体变量
 ** \param  [in] u32BaudRate: 选择波特率
 **              SPI_BAUDRATE_PCLK_DIV2      pclk/2
 **              SPI_BAUDRATE_PCLK_DIV4      pclk/4
 **              SPI_BAUDRATE_PCLK_DIV8      pclk/8
 **              SPI_BAUDRATE_PCLK_DIV16     pclk/16
 **              SPI_BAUDRATE_PCLK_DIV32     pclk/32
 **              SPI_BAUDRATE_PCLK_DIV64     pclk/64
 **              SPI_BAUDRATE_PCLK_DIV128    pclk/128

 ** \retval NULL
 **         
 ***********************************************************************************************/
void SPI_SetBaudRate(SPI_TypeDef *SPIx, uint32_t u32BaudRate)
{
    REG_MODIFY(SPIx->CR0, SPI_CR0_BRR, u32BaudRate);    
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取SPI主机模式波特率
 ** \param  [in] SPIx：SPI结构体变量

 ** \retval [out] 返回值:主机模式波特率
 **              SPI_BAUDRATE_PCLK_DIV2      pclk/2
 **              SPI_BAUDRATE_PCLK_DIV4      pclk/4
 **              SPI_BAUDRATE_PCLK_DIV8      pclk/8
 **              SPI_BAUDRATE_PCLK_DIV16     pclk/16
 **              SPI_BAUDRATE_PCLK_DIV32     pclk/32
 **              SPI_BAUDRATE_PCLK_DIV64     pclk/64
 **              SPI_BAUDRATE_PCLK_DIV128    pclk/128
 **         
 ***********************************************************************************************/
uint32_t SPI_GetBaudRate(SPI_TypeDef *SPIx)
{
    return (uint32_t)(REG_READBITS(SPIx->CR0, SPI_CR0_BRR));    
}
 
 /**
 ***********************************************************************************************
 ** \brief  设定SPI串行时钟相位
 ** \param  [in] SPIx：SPI结构体变量
 ** \param  [in] u32ClockPhase: 时钟相位选择
 **              SPI_CLOCK_PHASE_1EDGE      第一个边沿采样(第二个边沿移位)
 **              SPI_CLOCK_PHASE_2EDGE      第二个边沿采样(第一个边沿移位)

 ** \retval NULL
 **         
 ***********************************************************************************************/
void SPI_SetClockPhase(SPI_TypeDef *SPIx, uint32_t u32ClockPhase)
{
    REG_MODIFY(SPIx->CR0, SPI_CR0_CPHA, u32ClockPhase);    
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取SPI串行时钟相位
 ** \param  [in] SPIx：SPI结构体变量

 ** \retval [out] 返回值:时钟相位选择
 **              SPI_CLOCK_PHASE_1EDGE      第一个边沿采样(第二个边沿移位)
 **              SPI_CLOCK_PHASE_2EDGE      第二个边沿采样(第一个边沿移位)
 **         
 ***********************************************************************************************/
uint32_t SPI_GetClockPhase(SPI_TypeDef *SPIx)
{
    return (uint32_t)(REG_READBITS(SPIx->CR0, SPI_CR0_CPHA));    
}
 
 /**
 ***********************************************************************************************
 ** \brief  设定SPI串行时钟极性选择
 ** \param  [in] SPIx：SPI结构体变量
 ** \param  [in] u32ClockPolarity: 时钟极性选择
 **              SPI_CLOCK_POLARITY_LOW       待机时低电平
 **              SPI_CLOCK_POLARITY_HIGH      待机时高电平

 ** \retval NULL
 **         
 ***********************************************************************************************/
void SPI_SetClockPolarity(SPI_TypeDef *SPIx, uint32_t u32ClockPolarity)
{
    REG_MODIFY(SPIx->CR0, SPI_CR0_CPOL, u32ClockPolarity);    
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取SPI串行时钟极性选择
 ** \param  [in] SPIx：SPI结构体变量

 ** \retval [out] 返回值:时钟极性选择
 **              SPI_CLOCK_POLARITY_LOW       待机时低电平
 **              SPI_CLOCK_POLARITY_HIGH      待机时高电平
 **         
 ***********************************************************************************************/
uint32_t SPI_GetClockPolarity(SPI_TypeDef *SPIx)
{
    return (uint32_t)(REG_READBITS(SPIx->CR0, SPI_CR0_CPOL));    
}
 
 /**
 ***********************************************************************************************
 ** \brief  设定SPI模式，主机模式或者从机模式
 ** \param  [in] SPIx：SPI结构体变量
 ** \param  [in] u32Mode: 模式选择
 **              SPI_MODE_SLAVE       从机模式
 **              SPI_MODE_MASTER      主机模式

 ** \retval NULL
 **         
 ***********************************************************************************************/
void SPI_SetMode(SPI_TypeDef *SPIx, uint32_t u32Mode)
{
    REG_MODIFY(SPIx->CR0, SPI_CR0_MSTR, u32Mode);    
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取SPI模式，主机模式或者从机模式
 ** \param  [in] SPIx：SPI结构体变量

 ** \retval [out] 返回值:模式选择
 **              SPI_MODE_SLAVE       主机模式
 **              SPI_MODE_MASTER      从机模式
 **         
 ***********************************************************************************************/
uint32_t SPI_GetMode(SPI_TypeDef *SPIx)
{
    return (uint32_t)(REG_READBITS(SPIx->CR0, SPI_CR0_MSTR));    
}
 
 /**
 ***********************************************************************************************
 ** \brief  设定SPI数据传输，高低位顺序选择
 ** \param  [in] SPIx：SPI结构体变量
 ** \param  [in] u32TransferBitOrder: 数据传输，高低位顺序选择
 **              SPI_MSB_FIRST       最高有效位MSB收发在前
 **              SPI_LSB_FIRST       最低有效位LSB收发在前

 ** \retval NULL
 **         
 ***********************************************************************************************/
void SPI_SetTransferBitOrder(SPI_TypeDef *SPIx, uint32_t u32TransferBitOrder)
{
    REG_MODIFY(SPIx->CR0, SPI_CR0_LSBF, u32TransferBitOrder);    
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取SPI数据传输，高低位顺序选择
 ** \param  [in] SPIx：SPI结构体变量

 ** \retval [out] 返回值:数据传输，高低位顺序选择
 **              SPI_MSB_FIRST       最高有效位MSB收发在前
 **              SPI_LSB_FIRST       最低有效位LSB收发在前
 **         
 ***********************************************************************************************/
uint32_t SPI_GetTransferBitOrder(SPI_TypeDef *SPIx)
{
    return (uint32_t)(REG_READBITS(SPIx->CR0, SPI_CR0_LSBF));    
}
 
 /**
 ***********************************************************************************************
 ** \brief  设定SPI每帧的数据宽度
 ** \param  [in] SPIx：SPI结构体变量
 ** \param  [in] u32DataWidth: 数据宽度
 **              SPI_DATAWIDTH_4BIT     
 **              SPI_DATAWIDTH_5BIT     
 **              SPI_DATAWIDTH_6BIT    
 **              SPI_DATAWIDTH_7BIT     
 **              SPI_DATAWIDTH_8BIT     
 **              SPI_DATAWIDTH_9BIT    
 **              SPI_DATAWIDTH_10BIT     
 **              SPI_DATAWIDTH_11BIT    
 **              SPI_DATAWIDTH_12BIT     
 **              SPI_DATAWIDTH_13BIT     
 **              SPI_DATAWIDTH_14BIT    
 **              SPI_DATAWIDTH_15BIT     
 **              SPI_DATAWIDTH_16BIT    

 ** \retval NULL
 **         
 ***********************************************************************************************/
void SPI_SetDataWidth(SPI_TypeDef *SPIx, uint32_t u32DataWidth)
{
    REG_MODIFY(SPIx->CR0, SPI_CR0_WIDTH, u32DataWidth);    
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取SPI每帧的数据宽度
 ** \param  [in] SPIx：SPI结构体变量

 ** \retval [out] 返回值:数据宽度
 **              SPI_DATAWIDTH_4BIT     
 **              SPI_DATAWIDTH_5BIT     
 **              SPI_DATAWIDTH_6BIT    
 **              SPI_DATAWIDTH_7BIT     
 **              SPI_DATAWIDTH_8BIT     
 **              SPI_DATAWIDTH_9BIT    
 **              SPI_DATAWIDTH_10BIT     
 **              SPI_DATAWIDTH_11BIT    
 **              SPI_DATAWIDTH_12BIT     
 **              SPI_DATAWIDTH_13BIT     
 **              SPI_DATAWIDTH_14BIT    
 **              SPI_DATAWIDTH_15BIT     
 **              SPI_DATAWIDTH_16BIT   
 **         
 ***********************************************************************************************/
uint32_t SPI_GetDataWidth(SPI_TypeDef *SPIx)
{
    return (uint32_t)(REG_READBITS(SPIx->CR0, SPI_CR0_WIDTH));    
}
 
 /**
 ***********************************************************************************************
 ** \brief  设定SPI NSS从机选择配置
 ** \param  [in] SPIx：SPI结构体变量
 ** \param  [in] u32NSSMode: NSS从机选择
 **              SPI_NSS_HARD_INPUT    外部IO管脚决定NSS信号
 **              SPI_NSS_HARD_OUTPUT   NSS信号由IO管脚输出
 **              SPI_NSS_SOFT          SSI寄存器值决定NSS从机选择信号

 ** \retval NULL
 **         
 ***********************************************************************************************/
void SPI_SetNSSMode(SPI_TypeDef *SPIx, uint32_t u32NSSMode)
{
    REG_MODIFY(SPIx->CR0, SPI_CR0_SSM, u32NSSMode);    
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取SPI NSS从机选择配置
 ** \param  [in] SPIx：SPI结构体变量

 ** \retval [out] 返回值:NSS从机选择
 **              SPI_NSS_HARD_INPUT    外部IO管脚决定NSS信号
 **              SPI_NSS_HARD_OUTPUT   NSS信号由IO管脚输出
 **              SPI_NSS_SOFT          SSI寄存器值决定NSS从机选择信号
 **         
 ***********************************************************************************************/
uint32_t SPI_GetNSSMode(SPI_TypeDef *SPIx)
{
    return (uint32_t)(REG_READBITS(SPIx->CR0, SPI_CR0_SSM));    
}
 
 /**
 ***********************************************************************************************
 ** \brief  SPI模块作为从机时，配置NSS片选使能或禁止，只有当SSM=1，即软件控制(非外部IO管脚输入)时有效
 ** \param  [in] SPIx：SPI结构体变量
 ** \param  [in] u32NSSCfg: NSS选择
 **              SPI_NSS_CONFIG_ENABLE    从机自己软件使能片选
 **              SPI_NSS_CONFIG_DISABLE   从机自己软件禁止片选

 ** \retval NULL
 **         
 ***********************************************************************************************/
void SPI_SlaveNSSConfig(SPI_TypeDef *SPIx, uint32_t u32NSSCfg)
{
    REG_MODIFY(SPIx->SSI, SPI_SSI_SSI, u32NSSCfg);
}
 
 /**
 ***********************************************************************************************
 ** \brief  SPI模块作为主机 配置NSS片选输出(到从机)，只有当SSM=1，即硬件控制输出(外部IO管脚NSS输出)时有效
 ** \param  [in] SPIx：SPI结构体变量
 ** \param  [in] u32NSSCfg: NSS选择
 **              SPI_NSS_CONFIG_ENABLE    主机片选NSS输出, 选中从机信号(低电平)
 **              SPI_NSS_CONFIG_DISABLE   主机片选NSS输出, 取消选中从机信号(高电平)

 ** \retval NULL
 **         
 ***********************************************************************************************/
void SPI_MasterNSSOutput(SPI_TypeDef *SPIx, uint32_t u32NSSCfg)
{
    REG_MODIFY(SPIx->SSI, SPI_SSI_SSI, u32NSSCfg);
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取SPI SSI的值， 只有SSM=1时有效
 ** \param  [in] SPIx：SPI结构体变量

 ** \retval [out] 返回值:
 **              SPI_NSS_CONFIG_ENABLE    片选使能
 **              SPI_NSS_CONFIG_DISABLE   片选禁止
 **         
 ***********************************************************************************************/
uint32_t SPI_GetNSSSoftValue(SPI_TypeDef *SPIx)
{
    return (uint32_t)(REG_READBITS(SPIx->SSI, SPI_SSI_SSI));
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取SPI NSS管脚上的电平,如果没有使能NSS外部硬件输入，读取此值无意义
 ** \param  [in] SPIx：SPI结构体变量

 ** \retval [out] 返回值:
 **              SPI_NSS_EXT_INPUT_LOW_LEVEL    外部NSS管脚返回低电平
 **              SPI_NSS_EXT_INPUT_HIGH_LEVEL   外部NSS管脚返回高电平
 **         
 ***********************************************************************************************/
uint32_t SPI_GetNSSExtInput(SPI_TypeDef *SPIx)
{
    return (uint32_t)(REG_READBITS(SPIx->SR, SPI_SR_SSLVL));
}
 
 /**
 ***********************************************************************************************
 ** \brief  设定SPI 通信方式选择
 ** \param  [in] SPIx：SPI结构体变量
 ** \param  [in] u32TransferDirection: 通信方式选择
 **              SPI_FULL_DUPLEX     全双工双向
 **              SPI_SIMPLEX_TX      单工只发
 **              SPI_SIMPLEX_RX      单工只收
 **              SPI_HALF_DUPLEX     单线半双工

 ** \retval NULL
 **         
 ***********************************************************************************************/
void SPI_SetTransferDirection(SPI_TypeDef *SPIx, uint32_t u32TransferDirection)
{
    REG_MODIFY(SPIx->CR0, SPI_CR0_CM, u32TransferDirection);
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取SPI 通信方式选择
 ** \param  [in] SPIx：SPI结构体变量

 ** \retval [out] 返回值:通信方式选择
 **              SPI_FULL_DUPLEX     全双工双向
 **              SPI_SIMPLEX_TX      单工只发
 **              SPI_SIMPLEX_RX      单工只收
 **              SPI_HALF_DUPLEX     单线半双工
 **         
 ***********************************************************************************************/
uint32_t SPI_GetTransferDirection(SPI_TypeDef *SPIx)
{
    return (uint32_t)(REG_READBITS(SPIx->CR0, SPI_CR0_CM));    
}
 
 /**
 ***********************************************************************************************
 ** \brief  设定SPI 半双工通信方式选择
 ** \param  [in] SPIx：SPI结构体变量
 ** \param  [in] u32TransferDirection: 半双工通信方式
 **              SPI_HALF_DUPLEX_RX  单线半双工只收
 **              SPI_HALF_DUPLEX_TX  单线半双工只发

 ** \retval NULL
 **         
 ***********************************************************************************************/
void SPI_SetHalfDuplexDirection(SPI_TypeDef *SPIx, uint32_t u32TransferDirection)
{
    REG_MODIFY(SPIx->HDOE, SPI_HDOE_HDOE, u32TransferDirection);
}
 
 /**
 ***********************************************************************************************
 ** \brief  获取SPI 半双工通信方式
 ** \param  [in] SPIx：SPI结构体变量

 ** \retval [out] 返回值:半双工通信方式
 **              SPI_HALF_DUPLEX_RX  单线半双工只收
 **              SPI_HALF_DUPLEX_TX  单线半双工只发
 **         
 ***********************************************************************************************/
uint32_t SPI_GetHalfDuplexDirection(SPI_TypeDef *SPIx)
{
    return (uint32_t)(REG_READBITS(SPIx->HDOE, SPI_HDOE_HDOE));    
}

/**
 ***********************************************************************************************
 ** \brief  SPI 中断使能
 ** \param  [in] SPIx：SPI结构体变量
 ** \param  [in] u32ITEn：下列值或下列多个值相或
 **         @arg @ref SPI_IT_TXE     发送缓冲空中断
 **         @arg @ref SPI_IT_RXNE    接收缓冲非空中断
 **         @arg @ref SPI_IT_SSF     从机选择输入下降沿中断
 **         @arg @ref SPI_IT_SSR     从机选择输入上升沿中断
 **         @arg @ref SPI_IT_UDF     从机模式下发送缓冲下溢错误中断
 **         @arg @ref SPI_IT_OVF     接收缓冲上溢错误
 **         @arg @ref SPI_IT_SSERR   从机模式下的从机选择错误中断
 **         @arg @ref SPI_IT_MODF    模式错误中断

 ** \retval NULL
 ***********************************************************************************************/
void SPI_EnableIT(SPI_TypeDef* SPIx, uint32_t u32ITEn)
{
    REG_SETBITS(SPIx->CR1, u32ITEn);
}

/**
 ***********************************************************************************************
 ** \brief  SPI中断 禁止
 ** \param  [in] SPIx：SPI结构体变量
 ** \param  [in] u32IT：下列值或下列多个值相或
 **         @arg @ref SPI_IT_TXE     发送缓冲空中断
 **         @arg @ref SPI_IT_RXNE    接收缓冲非空中断
 **         @arg @ref SPI_IT_SSF     从机选择输入下降沿中断
 **         @arg @ref SPI_IT_SSR     从机选择输入上升沿中断
 **         @arg @ref SPI_IT_UDF     从机模式下发送缓冲下溢错误中断
 **         @arg @ref SPI_IT_OVF     接收缓冲上溢错误
 **         @arg @ref SPI_IT_SSERR   从机模式下的从机选择错误中断
 **         @arg @ref SPI_IT_MODF    模式错误中断

 ** \retval NULL
 ***********************************************************************************************/
void SPI_DisableIT(SPI_TypeDef* SPIx, uint32_t u32IT)
{
    REG_CLEARBITS(SPIx->CR1, u32IT);
}

/**
 ***********************************************************************************************
 ** \brief  检查 中断 是否已使能
 ** \param  [in] SPIx：SPI结构体变量
 ** \param  [in] u32IT：下列中断值
 **         @arg @ref SPI_IT_TXE     发送缓冲空中断
 **         @arg @ref SPI_IT_RXNE    接收缓冲非空中断
 **         @arg @ref SPI_IT_SSF     从机选择输入下降沿中断
 **         @arg @ref SPI_IT_SSR     从机选择输入上升沿中断
 **         @arg @ref SPI_IT_UDF     从机模式下发送缓冲下溢错误中断
 **         @arg @ref SPI_IT_OVF     接收缓冲上溢错误
 **         @arg @ref SPI_IT_SSERR   从机模式下的从机选择错误中断
 **         @arg @ref SPI_IT_MODF    模式错误中断

 ** \retval [out] 0：未开启； 非0：已开启
 ***********************************************************************************************/
uint32_t SPI_IsEnableIT(SPI_TypeDef* SPIx, uint32_t u32IT)
{
    return (uint32_t)(REG_READBITS(SPIx->CR1, u32IT) == u32IT);    
}

/**
 ***********************************************************************************************
 ** \brief  获取 SPI 发送缓冲空标志
 ** \param  [in] SPIx：SPI结构体变量
 ** \param  [in] u32IT：下列值或下列多个值相或
 **         @arg @ref SPI_FLAG_TXE    发送缓冲空 标志
 **         @arg @ref SPI_FLAG_RXNE   接收缓冲非空 标志
 **         @arg @ref SPI_FLAG_SSF    从机选择输入下降沿 标志
 **         @arg @ref SPI_FLAG_SSR    从机选择输入上升沿 标志
 **         @arg @ref SPI_FLAG_UDF    从机模式下发送缓冲下溢错误 标志
 **         @arg @ref SPI_FLAG_OVF    接收缓冲上溢错误 标志
 **         @arg @ref SPI_FLAG_SSERR  从机模式下的从机选择错误 标志
 **         @arg @ref SPI_FLAG_MODF   模式错误 标志
 **         @arg @ref SPI_FLAG_BUSY   总线忙 标志

 ** \retval [out] 返回值: 0或者1

 ***********************************************************************************************/
uint32_t SPI_IsActiveFlag(SPI_TypeDef* SPIx, uint32_t u32IT)
{
    return (REG_READBITS(SPIx->SR, u32IT) == u32IT);    
}

/**
 ***********************************************************************************************
 ** \brief  清除 SPI 接收缓冲非空标志
 ** \param  [in] SPIx：SPI结构体变量
 ** \param  [in] u32IT：下列值或下列多个值相或
 **         @arg @ref SPI_CLEAR_RXNE   清除 接收缓冲非空 标志
 **         @arg @ref SPI_CLEAR_SSF    清除 从机选择输入下降沿 标志
 **         @arg @ref SPI_CLEAR_SSR    清除 从机选择输入上升沿 标志
 **         @arg @ref SPI_CLEAR_UDF    清除 从机模式下发送缓冲下溢错误 标志
 **         @arg @ref SPI_CLEAR_OVF    清除 接收缓冲上溢错误 标志
 **         @arg @ref SPI_CLEAR_SSERR  清除 从机模式下的从机选择错误 标志
 **         @arg @ref SPI_CLEAR_MODF   清除 模式错误 标志
 **         @arg @ref SPI_CLEAR_BUSY   清除 总线忙 标志

 ** \retval NULL
 ***********************************************************************************************/
void SPI_ClearFlag(SPI_TypeDef* SPIx, uint32_t u32IT)
{
    REG_CLEARBITS(SPIx->ICR, u32IT);    
}

/**
 ***********************************************************************************************
 ** \brief  清除 SPI 所有中断 标志
 ** \param  [in] SPIx：SPI结构体变量

 ** \retval NULL
 ***********************************************************************************************/
void SPI_ClearFlag_ALL(SPI_TypeDef* SPIx)
{
    SPIx->ICR = 0x01;    
}

/**
 ***********************************************************************************************
 ** \brief  SPI 发送缓冲空标志 置位
 ** \param  [in] SPIx：SPI结构体变量

 ** \retval NULL
 ***********************************************************************************************/
void SPI_SetFlag_TXE(SPI_TypeDef* SPIx)
{
    REG_CLEARBITS(SPIx->ICR, SPI_ICR_TXE);    
}
 
 /**
 ***********************************************************************************************
 ** \brief  写数据到SPI数据寄存器
 ** \param  [in] SPIx：SPI结构体变量
 ** \param  [in] u16Data: 写数据

 ** \retval NULL
 **         
 ***********************************************************************************************/
void SPI_TransmitData(SPI_TypeDef *SPIx, uint16_t u16Data)
{
    REG_MODIFY(SPIx->DR, SPI_DR_DR, u16Data);    
}
 
 /**
 ***********************************************************************************************
 ** \brief  读取SPI数据寄存器
 ** \param  [in] SPIx：SPI结构体变量

 ** \retval [out] 返回值: 读数据寄存器的值
 **         
 ***********************************************************************************************/
uint32_t SPI_ReceiveData(SPI_TypeDef *SPIx)
{
    return (uint32_t)(REG_READBITS(SPIx->DR, SPI_DR_DR));    
}


//@} // SpiGroup
/******************************************************************************
 * EOF (not truncated)
 *****************************************************************************/

