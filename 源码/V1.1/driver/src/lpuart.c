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
 ** @file lpuart.c
 **
 ** @brief Source file for LPUART functions
 **
 ** @author MADS Team 
 **
 ******************************************************************************/

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "lpuart.h"
/**
 ******************************************************************************
 ** \addtogroup LPUART Group
 ******************************************************************************/
//@{
/******************************************************************************/
/* Local pre-processor symbols/macros ('#define')                             */
/******************************************************************************/

/******************************************************************************/
/* Local function prototypes ('static')                                       */
/******************************************************************************/

/******************************************************************************/
/* Local variable definitions ('static')                                       */
/******************************************************************************/

/**
 ******************************************************************************
 ** \brief  LPUART 初始化函数
 **
 ** \param [in] LPUARTx 通道指针 @ref LPUART_TypeDef
 ** \param [in] pstcLPUARTInit   @ref stc_lpuart_init_t
 **
 ** \retval OK配置成功
 ** \retval ErrorInvalidParameter配置失败
 ** \retval ErrorInvalidMode 波特率配置失败,或当前时钟无法计算出满足精度的波特率
 ******************************************************************************/
en_result_t LPUART_Init(LPUART_TypeDef* LPUARTx, stc_lpuart_init_t* pstcLPUARTInit)
{
    en_result_t enRet = Error;
    float32_t f32Scnt = 0;
	uint8_t u8Shift = 0;

    if(NULL == pstcLPUARTInit)
    {
        return ErrorInvalidParameter;
    }

    REG_CLEAR(LPUARTx->CR);
    REG_WRITE(LPUARTx->CR, pstcLPUARTInit->u32StopBits            |
                           pstcLPUARTInit->u32Parity              |
                           pstcLPUARTInit->u32FrameLength         |
                           pstcLPUARTInit->u32TransMode           |
                           pstcLPUARTInit->stcBaudRate.u32SclkSrc |
                           pstcLPUARTInit->u32HwControl);
	
    if(LPUART_CLKSRC_PCLK == pstcLPUARTInit->stcBaudRate.u32SclkSrc)
	{
		u8Shift = 3;	
	}
	else if(LPUART_CLKSRC_RCL == pstcLPUARTInit->stcBaudRate.u32SclkSrc)
	{
		u8Shift = 2;		
	}
	
	f32Scnt = (float32_t)(pstcLPUARTInit->stcBaudRate.u32Sclk) / (float32_t)(pstcLPUARTInit->stcBaudRate.u32BaudRate << u8Shift);	


    REG_WRITE(LPUARTx->BRR, (uint16_t)(float32_t)(f32Scnt + 0.5f));

    if((((pstcLPUARTInit->stcBaudRate.u32Sclk) / (LPUARTx->BRR << u8Shift)) < pstcLPUARTInit->stcBaudRate.u32BaudRate*0.98) ||
       (((pstcLPUARTInit->stcBaudRate.u32Sclk) / (LPUARTx->BRR << u8Shift)) > pstcLPUARTInit->stcBaudRate.u32BaudRate*1.02))
    {
        enRet = ErrorInvalidMode;
    }
    else
    {
        enRet = Ok;
    }

    return enRet;
}

/**
 ******************************************************************************
 ** \brief  LPUART 查询发送
 **
 ** \param [in] LPUARTx 通道指针 @ref LPUART_TypeDef
 ** \param [in] pu8Data     发送数据buffer指针
 ** \param [in] u32Size     发送数据长度(字节数)
 ** \param [in] u32Timeout  发送超时时间
 **
 ** \retval OK发送完成
 ** \retval
 ******************************************************************************/
en_result_t LPUART_Transmit(LPUART_TypeDef* LPUARTx, uint8_t *pu8Data, uint32_t u32Size, uint32_t u32Timeout)
{

    while(u32Size)
    {
        while(!REG_READBITS(LPUARTx->ISR, LPUART_ISR_TXE)){;}
        REG_WRITE(LPUARTx->DR, *pu8Data);
        pu8Data++;
        u32Size--;
    }

    while(!REG_READBITS(LPUARTx->ISR, LPUART_ISR_TC)){;}
    REG_CLEARBITS(LPUARTx->ICR, LPUART_ICR_TC);

    return Ok;
}

/**
 ******************************************************************************
 ** \brief  UART中断发送
 **
 ** \param [in] pu8Data     发送数据指针
 **
 ** \retval OK发送完成
 ** \retval
 ******************************************************************************/
en_result_t LPUART_TransmitIT(LPUART_TypeDef* LPUARTx, uint8_t *pu8Data)
{
    REG_WRITE(LPUARTx->DR, *pu8Data);

    return Ok;
}

/**
 ******************************************************************************
 ** \brief  UART查询接收
 **
 ** \param [in] LPUARTx 通道指针 @ref LPUART_TypeDef
 ** \param [in] pu8Data     接收数据buffer指针
 ** \param [in] u32Size     接收数据长度(字节数)
 ** \param [in] u32Timeout  接收超时时间
 **
 ** \retval OK 接收完成
 ** \retval
 ******************************************************************************/
en_result_t LPUART_Receive(LPUART_TypeDef* LPUARTx, uint8_t *pu8Data, uint32_t u32Size, uint32_t u32Timeout)
{

    while(u32Size)
    {
        while(!REG_READBITS(LPUARTx->ISR, LPUART_ISR_RC)){;}
        *pu8Data = REG_READ(LPUARTx->DR);
        REG_CLEARBITS(LPUARTx->ICR, LPUART_ICR_RC);
        pu8Data++;
        u32Size--;
    }

    return Ok;
}

/**
 ******************************************************************************
 ** \brief  UART中断接收
 **
 ** \param [in] pu8Data     接收数据buffer指针
 **
 ** \retval OK 接收完成
 ** \retval
 ******************************************************************************/
en_result_t LPUART_ReceiveIT(LPUART_TypeDef* LPUARTx, uint8_t *pu8Data)
{
    *pu8Data = REG_READ(LPUARTx->DR);

    return Ok;
}

/**
 ******************************************************************************
 ** \brief  LPUART 中断使能
 **
 ** \param [in] LPUARTx 通道号
 ** \param [in] u32State 中断类型 @ref LPUART_Int_Type
 **
 ** \retval None
 ******************************************************************************/
void LPUART_EnableIrq(LPUART_TypeDef* LPUARTx, uint32_t u32State)
{
    REG_SETBITS(LPUARTx->CR, u32State);
}

/**
 ******************************************************************************
 ** \brief  LPUART 中断禁止
 **
 ** \param [in] LPUARTx 通道号
 ** \param [in] u32State 中断类型 @ref LPUART_Int_Type
 **
 ** \retval None
 ******************************************************************************/
void LPUART_DisableIrq(LPUART_TypeDef* LPUARTx, uint32_t u32State)
{
    REG_CLEARBITS(LPUARTx->CR, u32State);
}

/**
 ******************************************************************************
 ** \brief  LPUART 中断标志获取
 **
 ** \param [in] LPUARTx 通道号
 ** \param [in] u32State 中断标志 @ref LPUART_Flag_Type
 **
 ** \retval None
 ******************************************************************************/
uint32_t LPUART_GetFlag(LPUART_TypeDef* LPUARTx, uint32_t u32State)
{
    return REG_READBITS(LPUARTx->ISR, u32State);
}

/**
 ******************************************************************************
 ** \brief  LPUART 中断标志清除
 **
 ** \param [in] LPUARTx 通道号
 ** \param [in] u32State 中断标志 @ref LPUART_Flag_Type
 **
 ** \retval None
 ******************************************************************************/
void LPUART_ClearIrq(LPUART_TypeDef* LPUARTx, uint32_t u32State)
{
    REG_CLEARBITS(LPUARTx->ICR, u32State);
}

/**
 ******************************************************************************
 ** \brief  LPUART单线半双工模式使能
 **
 ** \param [in] LPUARTx 通道号
 **
 ** \retval None
 ******************************************************************************/
void LPUART_HdModeEnable(LPUART_TypeDef* LPUARTx)
{
    REG_SETBITS(LPUARTx->CR, LPUART_CR_HDSEL);
}


/**
 ******************************************************************************
 ** \brief  LPUART单线半双工模式关闭
 **
 ** \param [in] LPUARTx 通道号
 **
 ** \retval None
 ******************************************************************************/
void LPUART_HdModeDisable(LPUART_TypeDef* LPUARTx)
{
    REG_CLEARBITS(LPUARTx->CR, LPUART_CR_HDSEL);
}

/**
 ******************************************************************************
 ** \brief  LPUART通道多主机模式配置
 **
 ** \param [in] LPUARTx通道号
 ** \param [in] u8Addr    从机设备地址
 ** \param [in] u8AddrMsk 从机设备地址掩码
 **
 ** \retval None
 ******************************************************************************/
void LPUart_MultiModeConfig(LPUART_TypeDef* LPUARTx, uint8_t u8Addr, uint8_t u8AddrMsk)
{
    REG_SETBITS(LPUARTx->CR, LPUART_CR_ADRDET);
    REG_SETBITS(LPUARTx->ADDR, u8Addr);
    REG_SETBITS(LPUARTx->ADDRMASK, u8AddrMsk);
}

/**
 ******************************************************************************
 ** \brief  LPUART DR8置位
 **
 ** \param [in] LPUARTx 通道号
 **
 ** \retval None
 ******************************************************************************/
void LPUart_SetDR8(LPUART_TypeDef* LPUARTx)
{
    REG_SETBITS(LPUARTx->DR, LPUART_DR_DR8);
}

/**
 ******************************************************************************
 ** \brief  LPUART DR8清零
 **
 ** \param [in] LPUARTx 通道号
 **
 ** \retval None
 ******************************************************************************/
void LPUart_ClearDR8(LPUART_TypeDef* LPUARTx)
{
    REG_CLEARBITS(LPUARTx->DR, LPUART_DR_DR8);
}

/**
 ******************************************************************************
 ** \brief 获取DR8数值
 **
 ** \param [in] LPUARTx 通道号
 **
 ** \retval DR8
 **\retval  ErrorInvalidParameter配置失败
 ******************************************************************************/
boolean_t LPUart_GetDR8(LPUART_TypeDef* LPUARTx)
{
    return (REG_READBITS(LPUARTx->DR, LPUART_DR_DR8) ? TRUE : FALSE);
}


//@} // LPUARTGroup
