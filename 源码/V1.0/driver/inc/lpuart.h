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
 ** @file lpuart.h
 **
 ** @brief Header file for LPUART functions
 **
 ** @author MADS Team 
 **
 ******************************************************************************/

#ifndef __LPUART_H__
#define __LPUART_H__
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
 ** \defgroup LPUARTGroup Universal Asynchronous Receiver/Transmitter (LPUART)
 **
 ******************************************************************************/
//@{

/******************************************************************************/
/* Global pre-processor symbols/macros ('#define')                            */
/******************************************************************************/

/******************************************************************************
 * Global type definitions
 ******************************************************************************/
 /**
 ******************************************************************************
 **\brief LPuart通道选择
 ******************************************************************************/

/**
 ******************************************************************************
 ** \brief lpuart 通道Mode1和Mode3波特率计算参数
 ******************************************************************************/
typedef struct stc_lpuart_baud
{
    uint32_t            u32SclkSrc;         ///< 传输时钟源选择
    uint32_t            u32Sclk;            ///< SCLK
    uint32_t            u32BaudRate;        ///< 波特率
} stc_lpuart_baudrate_t;

/**
 ******************************************************************************
 ** \lpuart 总体配置
 ******************************************************************************/
typedef struct stc_lpuart_init
{
    ///< UART Base Type
    uint32_t u32FrameLength;                            ///< 数据帧长度8/9bits
    uint32_t u32Parity;                                 ///< 奇偶校验选择
    uint32_t u32StopBits;                               ///< 停止位长度 @ref LUART_Stop_Bits
    uint32_t u32TransMode;                              ///< 数据传输方式

    stc_lpuart_baudrate_t     stcBaudRate;              ///< Mode1/3波特率配置

    uint32_t u32HwControl;                              ///< 硬件流控模式
} stc_lpuart_init_t;


/******************************************************************************
 ** \usart LPUART 基本功能初始化配置
 ******************************************************************************/
/** @defgroup stc_lpuart_init_t                 LUART_Stop_Bits
  * @{
  */
#define LPUART_STOPBITS_1                     0x00000000U                   /*!< USART frame with 1 stop bit    */
#define LPUART_STOPBITS_1p5                   (0x1U << LPUART_CR_STOP_Pos)  /*!< USART frame with 1 stop bit    */
#define LPUART_STOPBITS_2                     (0x2U << LPUART_CR_STOP_Pos)  /*!< USART frame with 2 stop bits   */
/**
  * @}
  */

/** @defgroup stc_lpuart_init_t                 LPUART_Parity
  * @{
  */
#define LPUART_PARITY_NONE                    (0x00U << LPUART_CR_MODE_Pos)       /*!< No parity   */
#define LPUART_PARITY_EVEN                    (0x01U << LPUART_CR_DR8CFG_Pos)     /*!< Even parity */
#define LPUART_PARITY_ODD                     (0x02U << LPUART_CR_DR8CFG_Pos)     /*!< Odd parity  */
/**
  * @}
  */

/** @defgroup stc_lpuart_init_t                 LPUART_Hardware_Flow_Control
  * @{
  */
#define LPUART_HWCONTROL_NONE                  0x00000000U                          /*!< No hardware control       */
#define LPUART_HWCONTROL_RTS                   LPUART_CR_RTSEN                      /*!< Request To Send           */
#define LPUART_HWCONTROL_CTS                   LPUART_CR_CTSEN                      /*!< Clear To Send             */
#define LPUART_HWCONTROL_RTS_CTS               (LPUART_CR_RTSEN | LPUART_CR_CTSEN)  /*!< Request and Clear To Send */
/**
  * @}
  */

/** @defgroup stc_lpuart_init_t                 LPUART_Mode(UART Transfer Mode)
  * @{
  */
#define LPUART_MODE_RX                        LPUART_CR_RXEN     /*!< RX mode        */
#define LPUART_MODE_TX                        0U                 /*!< TX mode        */
#define LPUART_MODE_TX_RX                     LPUART_CR_RXEN     /*!< RX and TX mode */
/**
  * @}
  */

/** @defgroup stc_lpuart_init_t                 LPUART_Frame_Length
  * @{
  */
#define LPUART_FRAME_LEN_8BITS                  (0x1U << LPUART_CR_MODE_Pos)  /*!< UART 帧长度 8Bits  */
#define LPUART_FRAME_LEN_9BITS                  (0x3U << LPUART_CR_MODE_Pos)  /*!< UART 帧长度 9Bits, 含校验位 */
/**
  * @}
  */


/** @defgroup stc_lpuart_init_t                 LPUART_Frame_Length
  * @{
  */
#define LPUART_CLKSRC_RCL                  ((0x3U << LPUART_CR_CLKSRC_Pos) | (0x02 << LPUART_CR_OVER_Pos))  /*!< UART SCLK时钟源RCL   */
#define LPUART_CLKSRC_PCLK                 ((0x1U << LPUART_CR_CLKSRC_Pos) | (0x01 << LPUART_CR_OVER_Pos))  /*!< UART SCLK时钟源PCLK  */
/**
  * @}
  */


/** @defgroup LPUART_Int_Type                   LPUART Interrupt Type
  * @{
  */
#define LPUART_INT_TXE                      LPUART_CR_TXEIE        ///< 发送缓存空
#define LPUART_INT_TC                       LPUART_CR_TCIE         ///< 发送完成
#define LPUART_INT_RC                       LPUART_CR_RCIE         ///< 接收完成
#define LPUART_INT_PE                       LPUART_CR_PEIE         ///< 接收数据校验错误
#define LPUART_INT_FE                       LPUART_CR_FEIE         ///< 接收帧错误
#define LPUART_INT_CTS                      LPUART_CR_CTSIE        ///< CTS中断使能

/**
  * @}
  */

/** @defgroup LPUART_Flag_Type                  LPUART Flag Type
  * @{
  */
#define LPUART_FLAG_TXE                      LPUART_ISR_TXE        ///< 发送缓存空
#define LPUART_FLAG_TC                       LPUART_ISR_TC         ///< 发送完成
#define LPUART_FLAG_RC                       LPUART_ISR_RC         ///< 接收完成
#define LPUART_FLAG_PE                       LPUART_ISR_PE         ///< 接收数据校验错误
#define LPUART_FLAG_FE                       LPUART_ISR_FE         ///< 接收帧错误
#define LPUART_FLAG_CTS                      LPUART_ISR_CTS        ///< CTS管脚电平
#define LPUART_FLAG_CTSIF                    LPUART_ISR_CTSIF      ///< CTS管脚电平变化标志
#define LPUART_FLAG_ALL                      (0x37u)
/**
  * @}
  */

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
en_result_t LPUART_Init(LPUART_TypeDef* LPUARTx, stc_lpuart_init_t* pstcLPUARTInit);

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
en_result_t LPUART_Transmit(LPUART_TypeDef* LPUARTx, uint8_t *pu8Data, uint32_t u32Size, uint32_t u32Timeout);

/**
 ******************************************************************************
 ** \brief  UART中断发送
 **
 ** \param [in] pu8Data     发送数据指针
 **
 ** \retval OK发送完成
 ** \retval
 ******************************************************************************/
en_result_t LPUART_TransmitIT(LPUART_TypeDef* LPUARTx, uint8_t *pu8Data);

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
en_result_t LPUART_Receive(LPUART_TypeDef* LPUARTx, uint8_t *pu8Data, uint32_t u32Size, uint32_t u32Timeout);

/**
 ******************************************************************************
 ** \brief  UART中断接收
 **
 ** \param [in] pu8Data     接收数据buffer指针
 **
 ** \retval OK 接收完成
 ** \retval
 ******************************************************************************/
en_result_t LPUART_ReceiveIT(LPUART_TypeDef* LPUARTx, uint8_t *pu8Data);

/**
 ******************************************************************************
 ** \brief  LPUART 中断使能
 **
 ** \param [in] LPUARTx 通道号
 ** \param [in] u32State 中断类型 @ref LPUART_Int_Type
 **
 ** \retval None
 ******************************************************************************/
void LPUART_EnableIrq(LPUART_TypeDef* LPUARTx, uint32_t u32State);

/**
 ******************************************************************************
 ** \brief  LPUART 中断禁止
 **
 ** \param [in] LPUARTx 通道号
 ** \param [in] u32State 中断类型 @ref LPUART_Int_Type
 **
 ** \retval None
 ******************************************************************************/
void LPUART_DisableIrq(LPUART_TypeDef* LPUARTx, uint32_t u32State);

/**
 ******************************************************************************
 ** \brief  LPUART 中断标志获取
 **
 ** \param [in] LPUARTx 通道号
 ** \param [in] u32State 中断标志 @ref LPUART_Flag_Type
 **
 ** \retval None
 ******************************************************************************/
uint32_t LPUART_GetFlag(LPUART_TypeDef* LPUARTx, uint32_t u32State);

/**
 ******************************************************************************
 ** \brief  LPUART 中断标志清除
 **
 ** \param [in] LPUARTx 通道号
 ** \param [in] u32State 中断标志 @ref LPUART_Flag_Type
 **
 ** \retval None
 ******************************************************************************/
void LPUART_ClearIrq(LPUART_TypeDef* LPUARTx, uint32_t u32State);


/**
 ******************************************************************************
 ** \brief  LPUART单线半双工模式使能
 **
 ** \param [in] LPUARTx 通道号
 **
 ** \retval None
 ******************************************************************************/
void LPUART_HdModeEnable(LPUART_TypeDef* LPUARTx);

/**
 ******************************************************************************
 ** \brief  LPUART单线半双工模式关闭
 **
 ** \param [in] LPUARTx 通道号
 **
 ** \retval None
 ******************************************************************************/
void LPUART_HdModeDisable(LPUART_TypeDef* LPUARTx);

/**
 ******************************************************************************
 ** \brief  LPUART DR8置位
 **
 ** \param [in] LPUARTx 通道号
 **
 ** \retval None
 ******************************************************************************/
void LPUart_SetDR8(LPUART_TypeDef* LPUARTx);

/**
 ******************************************************************************
 ** \brief  LPUART DR8清零
 **
 ** \param [in] LPUARTx 通道号
 **
 ** \retval None
 ******************************************************************************/
void LPUart_ClearDR8(LPUART_TypeDef* LPUARTx);

/**
 ******************************************************************************
 ** \brief 获取DR8数值
 **
 ** \param [in] LPUARTx 通道号
 **
 ** \retval DR8
 **\retval  ErrorInvalidParameter配置失败
 ******************************************************************************/
boolean_t LPUART_GetDR8(LPUART_TypeDef* LPUARTx);

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
void LPUart_MultiModeConfig(LPUART_TypeDef* LPUARTx, uint8_t u8Addr, uint8_t u8AddrMsk);

//@} // LPUARTGroup

#ifdef __cplusplus
#endif

#endif /* __LPUART_H__ */
/******************************************************************************
 * EOF (not truncated)
 *****************************************************************************/



