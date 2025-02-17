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
 ** @file flash.h
 **
 ** @brief Header file for FLASH functions
 **
 ** @author MADS Team 
 **
 ******************************************************************************/

#ifndef __FLASH_H__
#define __FLASH_H__

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "ddl.h"

/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif

/**
 ******************************************************************************
 ** \defgroup FlashGroup Flash Controller (Flash)
 **
 **
 ******************************************************************************/
//@{

/******************************************************************************
 * Global type definitions
 ******************************************************************************/

/** @defgroup FLASH INT TYPE FLASH_IntType
  * @{
  */
#define FLASH_INT_PC                FLASH_CR_PCIE
#define FLASH_INT                   FLASH_CR_FLASHIE
/**
  * @}
  */

/** @defgroup FLASH INT TYPE FLASH_IntTypeFlag
  * @{
  */
#define FLASH_INT_PC_FLAG           FLASH_IFR_IF0
#define FLASH_INT_FLAG              FLASH_IFR_IF1
/**
  * @}
  */

/**
 ******************************************************************************
  ** \brief Flash读等待周期类型重定义
 *****************************************************************************/
typedef enum en_flash_waitcycle
{
    FlashWaitCycle0 = 0u,       ///< 读等待周期设置为0-即读周期为1（当HCLK小于等于24MHz时）
    FlashWaitCycle1 = 1u,       ///< 读等待周期设置为1-即读周期为2（当HCLK大于24MHz时必须至少为1）
    FlashWaitCycle2 = 2u,       ///< 读等待周期设置为2-即读周期为3（当HCK大于48MHz时必须至少为2）
} en_flash_waitcycle_t;

/**
 ******************************************************************************
 ** \brief Redefinition of FLASH register structure 
 ******************************************************************************/

/******************************************************************************
 * Global definitions
 ******************************************************************************/
#define FLASH_PROGRAM_BYTE          (0x1u)
#define FLASH_PROGRAM_HALFWORD      (0x2u)
#define FLASH_PROGRAM_WORD          (0x4u)



/******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/******************************************************************************
 * Global variable definitions ('extern')                                     
 ******************************************************************************/

/******************************************************************************
 * Global function prototypes (definition in C source)                        
 ******************************************************************************/

///<Flash 页/全片擦除
en_result_t FLASH_SectorErase(uint32_t u32SectorAddr);

/**
 *****************************************************************************
 ** \brief FLASH 字节写
 **
 ** 字节方式向FLASH写入数据.
 **
 ** \param [in]  u32Addr          Flash地址
 ** \param [in]  pu8Data          字节数据指针
 ** \param [in]  u32Len           字节数
 ** \retval Ok                    写入成功.
 ** \retval ErrorInvalidParameter FLASH地址无效
 ** \retval ErrorTimeout          操作超时
 *****************************************************************************/
en_result_t FLASH_WriteByte(uint32_t u32Addr, uint8_t *pu8Data, uint32_t u32Len);

/**
 *****************************************************************************
 ** \brief FLASH 半字写
 **
 ** 半字(2字节)方式向FLASH写入数据.
 **
 ** \param [in]  u32Addr          Flash地址
 ** \param [in]  pu16Data         数据指针
 ** \param [in]  u32Len           半字数
 **
 ** \retval Ok                    写入成功.
 ** \retval ErrorInvalidParameter FLASH地址无效
 ** \retval ErrorTimeout          操作超时
 *****************************************************************************/
en_result_t FLASH_WriteHalfWord(uint32_t u32Addr, uint16_t *pu16Data, uint32_t u32Len);

/**
 *****************************************************************************
 ** \brief FLASH 字写
 **
 ** 字(4字节)方式向FLASH写入数据.
 **
 ** \param [in]  u32Addr          Flash地址
 ** \param [in]  pu16Data         数据指针
 ** \param [in]  u32Len           字数
 ** \retval Ok                    写入成功.
 ** \retval ErrorInvalidParameter FLASH地址无效
 ** \retval ErrorTimeout          操作超时
 *****************************************************************************/
en_result_t FLASH_WriteWord(uint32_t u32Addr, uint32_t *pu32Data, uint32_t u32Len);

/**
 *****************************************************************************
 ** \brief Flash数据校验
 **
 ** \param [in]  u32SrcAddr          源地址数据指针
 ** \param [in]  u32DstAddr          目标地址数据指针
 ** \param [in]  u32Size             校验数据长度
 **
 ** \retval Ok or Error                                      
 *****************************************************************************/
en_result_t FLASH_DataVerify(uint8_t *pu8SrcAddr, uint8_t *pu8DstAddr, uint32_t u32Size);

/**
 *****************************************************************************
 ** \brief FLASH 编程保护加锁
 ** \param [in] u32LockSector 扇区锁
 **
 ** \note u32LockSector 第n个bit为'0'时的加锁Sector范围为[4*n, 4*n + 3]
 ** 
 ** \retval None                               
 *****************************************************************************/
void FLASH_FlashLockSet(uint32_t u32LockSector);


/**
 *****************************************************************************
 ** \brief FLASH 读等待周期设置
 **
 ** \param [in]  enWaitCycle  插入FLASH读等待周期数枚举类型 @ref en_flash_waitcycle_t
 **
 ** \note FlashWaitCycle0 = 0u,       ///< 读等待周期设置为0-即读周期为1（当HCLK小于等于24MHz时）
 ** \note FlashWaitCycle1 = 1u,       ///< 读等待周期设置为1-即读周期为2（当HCLK大于24MHz时必须至少为1）
 ** \note FlashWaitCycle2 = 2u,       ///< 读等待周期设置为2-即读周期为3（当HCK大于48MHz时必须至少为2）
 **
 ** \retval  None                              
 *****************************************************************************/
void FLASH_WaitCycle(en_flash_waitcycle_t enWaitCycle);

/**
 *****************************************************************************
 ** \brief Flash中断使能
 **
 **
 ** \param [in]  u32IrqTypeEnable          @ref FLASH_IntType
 ** 
 ** \retval None                                      
 *****************************************************************************/
void FLASH_EnableIrq(uint32_t u32IrqTypeEnable);

/**
 *****************************************************************************
 ** \brief Flash中断禁止
 **
 **
 ** \param [in]  u32IrqTypeEnable          @ref FLASH_IntType
 ** 
 ** \retval None                                      
 *****************************************************************************/
void FLASH_DisableIrq(uint32_t u32IrqTypeEnable);

/**
 *****************************************************************************
 ** \brief FLASH 中断标志获取
 **
 **
 ** \param [in]  u32IrqTypeFlag          @ref FLASH_IntTypeFlag
 ** 
 ** \retval 中断标志                                     
 *****************************************************************************/
uint32_t FLASH_GetIntFlag(uint32_t u32IrqTypeFlag);

/**
 *****************************************************************************
 ** \brief Flash中断标志清除
 **
 **
 ** \param [in]  u32IrqTypeFlag          @ref FLASH_IntTypeFlag
 ** 
 ** \retval None                                      
 *****************************************************************************/
void FLASH_ClearIntFlag(uint32_t u32IrqTypeFlag);

//@} // FlashGroup

#ifdef __cplusplus
}
#endif

#endif /* __FLASH_H__ */
/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
