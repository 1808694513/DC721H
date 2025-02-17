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
 ** @file i2c.h
 **
 ** @brief Header file for I2C functions
 **
 ** @author MADS Team 
 **
 ******************************************************************************/

#ifndef __I2C_H__
#define __I2C_H__

#include "ddl.h"


/**
 *******************************************************************************
 ** \defgroup I2cGroup Inter-Integrated Circuit (I2C)
 **
 **
 ******************************************************************************/
//@{

/******************************************************************************/
/* Global pre-processor symbols/macros ('#define')                            */
/******************************************************************************/

/** @defgroup I2C_FILTER_MODE  滤波方式选择，，作为主机I2C_BRR值大于9，或者作为
 ** 从机PCLK与SCL频率比值大于30时，建议使用I2C_FILTER_ADVANCE
  * @{
  */
#define   I2C_FILTER_ADVANCE   (0x00000000UL)    //更高的抗干扰性能
#define   I2C_FILTER_SIMPLE    (I2C_CR_FLT)      //更快的通信滤波
/**
  * @}
  */
  
/** @defgroup I2C_ACKNOWLEDGE_CFG  应答控制
  * @{
  */
#define   I2C_NACK   (0x00000000UL)    //在应答阶段发送ACK
#define   I2C_ACK    (I2C_CR_AA)       //在应答阶段发送NAK
/**
 * @}
 */
  
/** @defgroup I2C_START_CFG  向总线发送start控制
  * @{
  */
#define   I2C_START_DISABLE    (0x00000000UL)       //禁止向总线发送start
#define   I2C_START_ENABLE     (I2C_CR_STA)         //向总线发送start
/**
 * @}
 */
  
/** @defgroup I2C_STOP_CFG  向总线发送stop控制
  * @{
  */
#define   I2C_STOP_DISABLE    (0x00000000UL)      //禁止向总线发送stop
#define   I2C_STOP_ENABLE     (I2C_CR_STO)        //向总线发送stop
/**
 * @}
 */
  
/** @defgroup I2C_BROADCAST_CFG  向总线发送stop控制
  * @{
  */
#define   I2C_BROADCAST_DISABLE   (0x00000000UL)    //禁止广播地址应答
#define   I2C_BROADCAST_ENABLE    (I2C_ADDR0_GC)    //使能广播地址应答
/**
 * @}
 */
 
/** @defgroup I2C_BUS_ADDR_MATCH  总线设备地址匹配
  * @{
  */
#define   I2C_BUS_ADDR_MATCH_NONE    (0x00000000UL)        //无从地址与总线上的设备地址匹配
#define   I2C_BUS_ADDR_MATCH_ADDR0   (I2C_MATCH_AD0F)      //设备从地址ADDR0与总线上的设备地址匹配
#define   I2C_BUS_ADDR_MATCH_ADDR1   (I2C_MATCH_AD1F)      //设备从地址ADDR1与总线上的设备地址匹配
#define   I2C_BUS_ADDR_MATCH_ADDR2   (I2C_MATCH_AD2F)      //设备从地址ADDR2与总线上的设备地址匹配
/**
 * @}
 */
/******************************************************************************
 * Global type definitions
 ******************************************************************************/

/**
 ******************************************************************************
 ** \brief I2C从机初始化配置结构
 *****************************************************************************/
typedef struct stc_i2c_slave_init_cfg
{
    uint8_t         u8SlaveAddr0;           /*! 从机地址0  取值范围0 ~ 127 */
    uint8_t         u8SlaveAddr1;           /*! 从机地址1  取值范围0 ~ 127 */
    uint8_t         u8SlaveAddr2;           /*! 从机地址2  取值范围0 ~ 127 */
    uint32_t        u32Filter;              /*! 滤波配置  @ref I2C_FILTER_MODE */
    uint32_t        u32BroadcastEn;         /*! 广播地址使能  @ref I2C_BROADCAST_CFG */
}stc_i2c_slave_init_cfg_t;

/**
 ******************************************************************************
 ** \brief I2C主机初始化配置结构
 *****************************************************************************/
typedef struct stc_i2c_master_init_cfg
{
    uint32_t        u32Pclk;                /*! pclk时钟频率 通过调用SYSCTRL_GetPCLK()函数可以获取 */
    uint32_t        u32BaudRate;            /*! 波特率 */
}stc_i2c_master_init_cfg_t;

/******************************************************************************
 * Global variable declarations ('extern', definition in C source)
 *****************************************************************************/

/******************************************************************************
 * Global function prototypes (definition in C source)
 *****************************************************************************/ 
 
 //I2C初始化函数
en_result_t I2C_MasterInit(I2C_TypeDef* I2Cx, stc_i2c_master_init_cfg_t *pstcMasterInitCfg);
en_result_t I2C_SlaveInit(I2C_TypeDef* I2Cx, stc_i2c_slave_init_cfg_t *pstcSlaveInitCfg);
void I2C_EnableBaud(I2C_TypeDef *I2Cx);
void I2C_DisableBaud(I2C_TypeDef *I2Cx);
uint32_t I2C_IsEnableBaud(I2C_TypeDef *I2Cx);
void I2C_SetBaud(I2C_TypeDef *I2Cx, uint32_t u32Baud);
uint32_t I2C_GetBaud(I2C_TypeDef *I2Cx);
void I2C_SetFilter(I2C_TypeDef *I2Cx, uint32_t u32Filter);
uint32_t I2C_GetFilter(I2C_TypeDef *I2Cx);
uint32_t I2C_IsActiveFlag_SI(I2C_TypeDef *I2Cx);
void I2C_ClearFlag_SI(I2C_TypeDef *I2Cx);
void I2C_SetAck(I2C_TypeDef *I2Cx, uint32_t u32Ack);
uint32_t I2C_GetAck(I2C_TypeDef *I2Cx);
void I2C_SetStop(I2C_TypeDef *I2Cx, uint32_t u32Stop);
void I2C_SetStart(I2C_TypeDef *I2Cx, uint32_t u32Start);
uint32_t I2C_GetStart(I2C_TypeDef *I2Cx);
void I2C_Enable(I2C_TypeDef *I2Cx);
void I2C_Disable(I2C_TypeDef *I2Cx);
uint32_t I2C_IsEnable(I2C_TypeDef *I2Cx);
void I2C_WriteByte(I2C_TypeDef *I2Cx, uint8_t u8Data);
uint8_t I2C_ReadByte(I2C_TypeDef *I2Cx);
uint8_t I2C_GetBusState(I2C_TypeDef *I2Cx);
void I2C_EnableBroadcast(I2C_TypeDef *I2Cx);
void I2C_DisableBroadcast(I2C_TypeDef *I2Cx);
uint32_t I2C_IsEnableBroadcast(I2C_TypeDef *I2Cx);
void I2C_SetSlaveAddr0(I2C_TypeDef *I2Cx, uint32_t u32Addr);
uint32_t I2C_GetSlaveAddr0(I2C_TypeDef *I2Cx);
void I2C_SetSlaveAddr1(I2C_TypeDef *I2Cx, uint32_t u32Addr);
uint32_t I2C_GetSlaveAddr1(I2C_TypeDef *I2Cx);
void I2C_SetSlaveAddr2(I2C_TypeDef *I2Cx, uint32_t u32Addr);
uint32_t I2C_GetSlaveAddr2(I2C_TypeDef *I2Cx);
uint32_t I2C_GetBusMatchSlaveAddr(I2C_TypeDef *I2Cx);
 
//@} // I2cGroup

#ifdef __cplusplus
#endif

#endif /* __I2C_H__ */
/******************************************************************************
 * EOF (not truncated)
 *****************************************************************************/


