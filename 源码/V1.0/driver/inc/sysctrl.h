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
 ** @file sysctrl.h
 **
 ** @brief Header file for SYSCTRL functions
 **
 ** @author MADS Team 
 **
 ******************************************************************************/

#ifndef __SYSCTRL_H__
#define __SYSCTRL_H__

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "ddl.h"


#ifdef __cplusplus
extern "C"
{
#endif

/**
 ******************************************************************************
 ** \defgroup SysCtrlGroup (SYSCTRL)
  **
 ******************************************************************************/
//@{

/**
 *******************************************************************************
 ** function prototypes.
 ******************************************************************************/

/******************************************************************************
 * Global type definitions
 ******************************************************************************/
typedef struct
{
    uint8_t  *pu8UID;                               ///< 10字节UID(唯一识别号)
    char_t   *pcProductNumber;                      ///< 32字节产品型号"HC32xxx ……" 
    uint32_t u32FlashSize;                          ///< FLASH容量(Byte)
    uint32_t u32RamSize;                            ///< RAM容量(Byte)
    uint16_t u16PinsCounter;                        ///< 管脚数量
}stc_sysctrl_chip_info_t;

typedef struct
{
    uint32_t u32SysClkSourceType;       ///< 系统时钟源   @ref Sysclk_Source_Type

    uint32_t u32RCHState;               ///< RCH 配置     @ref RCH_Config
    uint32_t u32RCLState;               ///< RCL 配置     @ref RCL_Config
    uint32_t u32EXTCLKState;            ///< EXTCLK 配置  @ref EXTCLK_Config

}stc_sysctrl_sysclk_source_init_t;


/** @defgroup stc_sysctrl_sysclk_source_init_t Sysclk_Source_Type
  * @{
  */
#define SYSCTRL_SYSCLK_SOURCE_TYPE_RCH              (0x00000001u)
#define SYSCTRL_SYSCLK_SOURCE_TYPE_RCL              (0x00000004u)
/**
  * @}
  */

/** @defgroup stc_sysctrl_sysclk_source_init_t RCH_Config
  * @{
  */
///< 校准值定义
#define SYSCTRL_RCH_TRIM_48MHz          (*((volatile uint16_t*) (0x00100DF2u)))
#define SYSCTRL_RCH_TRIM_44p24MHz       (*((volatile uint16_t*) (0x00100DF0u)))
#if 0   ///< 自定义值
#define SYSCTRL_RCH_TRIM_VALUE          (0x0000016Cu)
#endif

///< RCH 分频值定义
#define SYSCTRL_RCH_DIV1                (0x8u<<SYSCTRL_RCH_DIV_Pos)
#define SYSCTRL_RCH_DIV2                (0x0u<<SYSCTRL_RCH_DIV_Pos)
#define SYSCTRL_RCH_DIV4                (0x1u<<SYSCTRL_RCH_DIV_Pos)
#define SYSCTRL_RCH_DIV6                (0x2u<<SYSCTRL_RCH_DIV_Pos)
#define SYSCTRL_RCH_DIV8                (0x3u<<SYSCTRL_RCH_DIV_Pos)
#define SYSCTRL_RCH_DIV10               (0x4u<<SYSCTRL_RCH_DIV_Pos)
#define SYSCTRL_RCH_DIV12               (0x5u<<SYSCTRL_RCH_DIV_Pos)
#define SYSCTRL_RCH_DIV14               (0x6u<<SYSCTRL_RCH_DIV_Pos)
#define SYSCTRL_RCH_DIV16               (0x7u<<SYSCTRL_RCH_DIV_Pos)
/**
  * @}
  */

/** @defgroup stc_sysctrl_sysclk_source_init_t RCL_Config
  * @{
  */
///< RCL 校准值定义
#define SYSCTRL_RCL_TRIM_32p8KHz            (*((volatile uint16_t*) (0x00100DF4u)))
#define SYSCTRL_RCL_TRIM_38p4KHz            (*((volatile uint16_t*) (0x00100DF6u)))
#if 0   ///< 自定义值
#define SYSCTRL_RCL_TRIM_VALUE              (0x000001B3u)
#endif

///< RCL 稳定等待周期定义
#define SYSCTRL_RCL_WAITCYCLE4              (0x0u<<SYSCTRL_RCL_WAITCYCLE_Pos)
#define SYSCTRL_RCL_WAITCYCLE16             (0x1u<<SYSCTRL_RCL_WAITCYCLE_Pos)
#define SYSCTRL_RCL_WAITCYCLE64             (0x2u<<SYSCTRL_RCL_WAITCYCLE_Pos)
#define SYSCTRL_RCL_WAITCYCLE256            (0x3u<<SYSCTRL_RCL_WAITCYCLE_Pos)
/**
  * @}
  */

/** @defgroup stc_sysctrl_sysclk_source_init_t EXTCLK_Config
  * @{
  */
///< 外部时钟频率定义
#define SYSCTRL_EXTCLK                      (16000000U)      ///<根据实际输入频率修改:1 ~ 16MHz

/**
  * @}
  */

/**
 *******************************************************************************
 ** \brief 系统时钟初始化配置结构体定义
 ******************************************************************************/
typedef struct
{
    uint32_t    u32ClockType;           ///< 初始化时钟类型  @ref System_Clock_Type
    uint32_t    u32SysClkSource;        ///< 系统时钟源      @ref System_Clock_Source
    uint32_t    u32HClkDiv;             ///< HCLK时钟分频    @ref System_HCLK_Prs
    uint32_t    u32PClkDiv;             ///< PCLK时钟分频    @ref System_PCLK_Prs
    uint32_t    u32WaitCycle;           ///< FLASH读等待周期 @ref Flash_Wait_Cycle
}stc_sysctrl_clk_init_t;

/** @defgroup stc_sysctrl_clk_init_t System_Clock_Type
  * @{
  */
///< 系统时钟类型定义
#define SYSCTRL_CLOCKTYPE_SYSCLK             (0x00000001u) /*!< SYSCLK to configure */
#define SYSCTRL_CLOCKTYPE_HCLK               (0x00000002u) /*!< HCLK to configure */
#define SYSCTRL_CLOCKTYPE_PCLK               (0x00000004u) /*!< PCLK to configure */
/**
  * @}
  */

/** @defgroup stc_sysctrl_clk_init_t System_Clock_Source
  * @{
  */
///< 系统时钟源定义
#define SYSCTRL_SYSCLK_SOURCE_RCH            (0x0u)
#define SYSCTRL_SYSCLK_SOURCE_EXTCLK         (0xFu)
#define SYSCTRL_SYSCLK_SOURCE_RCL            (0x2u)
/**
  * @}
  */

/** @defgroup stc_sysctrl_clk_init_t System_HCLK_Prs
  * @{
  */
///< 系统时钟 HCLK 分频系数定义
#define SYSCTRL_SYSCLK_HCLK_PRS1            (0x0u<<SYSCTRL_CR0_HCLKPRS_Pos)
#define SYSCTRL_SYSCLK_HCLK_PRS2            (0x1u<<SYSCTRL_CR0_HCLKPRS_Pos)
#define SYSCTRL_SYSCLK_HCLK_PRS4            (0x2u<<SYSCTRL_CR0_HCLKPRS_Pos)
#define SYSCTRL_SYSCLK_HCLK_PRS8            (0x3u<<SYSCTRL_CR0_HCLKPRS_Pos)
#define SYSCTRL_SYSCLK_HCLK_PRS16           (0x4u<<SYSCTRL_CR0_HCLKPRS_Pos)
#define SYSCTRL_SYSCLK_HCLK_PRS32           (0x5u<<SYSCTRL_CR0_HCLKPRS_Pos)
#define SYSCTRL_SYSCLK_HCLK_PRS64           (0x6u<<SYSCTRL_CR0_HCLKPRS_Pos)
#define SYSCTRL_SYSCLK_HCLK_PRS128          (0x7u<<SYSCTRL_CR0_HCLKPRS_Pos)
/**
  * @}
  */

/** @defgroup stc_sysctrl_clk_init_t System_PCLK_Prs
  * @{
  */
///< 系统时钟 PCLK 分频系数定义
#define SYSCTRL_SYSCLK_PCLK_PRS1            (0x0u<<SYSCTRL_CR0_PCLKPRS_Pos)
#define SYSCTRL_SYSCLK_PCLK_PRS2            (0x1u<<SYSCTRL_CR0_PCLKPRS_Pos)
#define SYSCTRL_SYSCLK_PCLK_PRS4            (0x2u<<SYSCTRL_CR0_PCLKPRS_Pos)
#define SYSCTRL_SYSCLK_PCLK_PRS8            (0x3u<<SYSCTRL_CR0_PCLKPRS_Pos)
/**
  * @}
  */

/** @defgroup stc_sysctrl_clk_init_t Flash_Wait_Cycle
  * @{
  */
///< FLASH指令读取等待周期定义
#define SYSCTRL_FLASH_WAIT_CYCLE1            (0x0u<<FLASH_WAIT_WAIT_Pos)
#define SYSCTRL_FLASH_WAIT_CYCLE2            (0x1u<<FLASH_WAIT_WAIT_Pos)
#define SYSCTRL_FLASH_WAIT_CYCLE3            (0x2u<<FLASH_WAIT_WAIT_Pos)
/**
  * @}
  */



/** @defgroup Sysctrl_Function_Ctrl
  * @{
  */
#define _CR2_MSK                            (0x80000000u)
///< 系统控制功能定义
#define SYSCTRL_FUNC_GTIMCONFIG             SYSCTRL_CR1_GTIMCFG
#define SYSCTRL_FUNC_RESIO                  SYSCTRL_CR1_RESIO
#define SYSCTRL_FUNC_WAKEUPCLKSOURCE        SYSCTRL_CR1_WKPCLKSRC
#define SYSCTRL_FUNC_LOCKUPEN               SYSCTRL_CR1_LOCKUPEN
#define SYSCTRL_FUNC_SWDIO                  SYSCTRL_CR1_SWDIO

/**
  * @}
  */


/** @defgroup Sysctrl_Periph_Clock
  * @{
  */
#define _PERICLK_REG1_MSK                       (0x80000000U)

///< 系统外设时钟类型定义
#define SYSCTRL_PERICLK_LPUART0                 SYSCTRL_PERICLKEN0_LPUART0
#define SYSCTRL_PERICLK_LPUART1                 SYSCTRL_PERICLKEN0_LPUART1
#define SYSCTRL_PERICLK_I2C                     SYSCTRL_PERICLKEN0_I2C
#define SYSCTRL_PERICLK_SPI                     SYSCTRL_PERICLKEN0_SPI
#define SYSCTRL_PERICLK_ATIM3                   SYSCTRL_PERICLKEN0_ATIM3
#define SYSCTRL_PERICLK_IWDT                    SYSCTRL_PERICLKEN0_IWDT
#define SYSCTRL_PERICLK_ADC                     SYSCTRL_PERICLKEN0_ADC
#define SYSCTRL_PERICLK_CTRIM                   SYSCTRL_PERICLKEN0_CTRIM
#define SYSCTRL_PERICLK_FLASH                   SYSCTRL_PERICLKEN0_FLASH

#define SYSCTRL_PERICLK_PA                      (_PERICLK_REG1_MSK | SYSCTRL_PERICLKEN1_PA)
#define SYSCTRL_PERICLK_PB                      (_PERICLK_REG1_MSK | SYSCTRL_PERICLKEN1_PB)
#define SYSCTRL_PERICLK_PC                      (_PERICLK_REG1_MSK | SYSCTRL_PERICLKEN1_PC)
#define SYSCTRL_PERICLK_PD                      (_PERICLK_REG1_MSK | SYSCTRL_PERICLKEN1_PD)
#define SYSCTRL_PERICLK_WWDT                    (_PERICLK_REG1_MSK | SYSCTRL_PERICLKEN1_WWDT)
#define SYSCTRL_PERICLK_GTIM                    (_PERICLK_REG1_MSK | SYSCTRL_PERICLKEN1_GTIM)

/**
  * @}
  */


/** @defgroup Sysctrl_Debug_Module
  * @{
  */

///< SYSCTRL_DEBUGACTIVE
#define SYSCTRL_DEBUG_Module_CTRIM                SYSCTRL_DEBUGACTIVE_CTRIM
#define SYSCTRL_DEBUG_Module_IWDT                 SYSCTRL_DEBUGACTIVE_IWDT
#define SYSCTRL_DEBUG_Module_ATIM3                SYSCTRL_DEBUGACTIVE_ATIM3
#define SYSCTRL_DEBUG_Module_GTIM                 SYSCTRL_DEBUGACTIVE_GTIM
#define SYSCTRL_DEBUG_Module_WWDT                 SYSCTRL_DEBUGACTIVE_WWDT

/**
  * @}
  */


/** @defgroup Sysctrl_Periph_Reset
  * @{
  */
#define _PERIRESET_REG1_MSK                       (0x80000000U)

///< 系统外设复位定义
#define SYSCTRL_PERIRESET_LPUART0               SYSCTRL_PERIRESET0_LPUART0
#define SYSCTRL_PERIRESET_LPUART1               SYSCTRL_PERIRESET0_LPUART1
#define SYSCTRL_PERIRESET_I2C                   SYSCTRL_PERIRESET0_I2C
#define SYSCTRL_PERIRESET_SPI                   SYSCTRL_PERIRESET0_SPI
#define SYSCTRL_PERIRESET_ATIM3                 SYSCTRL_PERIRESET0_ATIM3
#define SYSCTRL_PERIRESET_ADC                   SYSCTRL_PERIRESET0_ADC
#define SYSCTRL_PERIRESET_CTRIM                 SYSCTRL_PERIRESET0_CTRIM

#define SYSCTRL_PERIRESET_PA                    (_PERIRESET_REG1_MSK | SYSCTRL_PERIRESET1_PA)
#define SYSCTRL_PERIRESET_PB                    (_PERIRESET_REG1_MSK | SYSCTRL_PERIRESET1_PB)
#define SYSCTRL_PERIRESET_PC                    (_PERIRESET_REG1_MSK | SYSCTRL_PERIRESET1_PC)
#define SYSCTRL_PERIRESET_PD                    (_PERIRESET_REG1_MSK | SYSCTRL_PERIRESET1_PD)
#define SYSCTRL_PERIRESET_WWDT                  (_PERIRESET_REG1_MSK | SYSCTRL_PERIRESET1_WWDT)
#define SYSCTRL_PERIRESET_GTIM                  (_PERIRESET_REG1_MSK | SYSCTRL_PERIRESET1_GTIM)

/**
  * @}
  */


/** @defgroup Sysctrl_Reset_Flag
  * @{
  */
///< 系统复位标志定义
#define SYSCTRL_RESET_FLAG_VCC                      SYSCTRL_RESETFLAG_VCC
#define SYSCTRL_RESET_FLAG_VCORE                    SYSCTRL_RESETFLAG_VCORE
#define SYSCTRL_RESET_FLAG_LVD                      SYSCTRL_RESETFLAG_LVD
#define SYSCTRL_RESET_FLAG_IWDT                     SYSCTRL_RESETFLAG_IWDT
#define SYSCTRL_RESET_FLAG_WWDT                     SYSCTRL_RESETFLAG_WWDT
#define SYSCTRL_RESET_FLAG_LOCKUP                   SYSCTRL_RESETFLAG_LOCKUP
#define SYSCTRL_RESET_FLAG_SYSREQ                   SYSCTRL_RESETFLAG_SYSREQ
#define SYSCTRL_RESET_FLAG_RSTB                     SYSCTRL_RESETFLAG_RSTB
#define SYSCTRL_RESET_FLAG_ALL                      (0xFFU)
/**
  * @}
  */


/******************************************************************************
 * Global variable declarations ('extern', definition in C source)
 ******************************************************************************/

/******************************************************************************
 * Global function prototypes (definition in C source)
 ******************************************************************************/

/**
 ***********************************************************************************************
 ** \brief 系统时钟源初始化
 ** \param [in]  pstcSysClkSrc 系统时钟源配置结构体指针 @ref stc_sysctrl_sysclk_source_init_t
 **
 ** \retval @ref en_result_t
 ***********************************************************************************************/
en_result_t SYSCTRL_SysClkSrcInit(stc_sysctrl_sysclk_source_init_t *pstcSysClkSrc);

/**
 ***********************************************************************************************
 ** \brief 系统时钟初始化
 ** \param [in]  pstcSysClk 系统时钟配置结构体指针 @ref stc_sysctrl_clk_init_t
 **
 ** \retval @ref en_result_t
 ***********************************************************************************************/
en_result_t SYSCTRL_SysClkInit(stc_sysctrl_clk_init_t *pstcSysClk);

/**
 ***********************************************************************************************
 ** \brief 系统时钟 HCLK 频率获取
 ** \param None

 ** \retval HCLK频率值(Hz)
 ***********************************************************************************************/
uint32_t SYSCTRL_GetHCLK(void);

/**
 ***********************************************************************************************
 ** \brief 系统时钟PCLK频率获取
 ** \param None

 ** \retval PCLK频率值(Hz)
 ***********************************************************************************************/
uint32_t SYSCTRL_GetPCLK(void);

/**
 ***********************************************************************************************
 ** \brief 系统功能使能————系统控制其他功能使能
 ** \param [in]  u32SysctrlFunction   系统功能宏定义 @ref Sysctrl_Function_Ctrl

 ** \retval NULL
 ***********************************************************************************************/
void SYSCTRL_FuncEnable(uint32_t u32SysctrlFunction);

/**
 ***********************************************************************************************
 ** \brief 系统功能禁止————系统控制其他功能禁止
 ** \param [in]  u32SysctrlFunction   系统功能宏定义 @ref Sysctrl_Function_Ctrl

 ** \retval NULL
 ***********************************************************************************************/
void SYSCTRL_FuncDisable(uint32_t u32SysctrlFunction);

/**
 ***********************************************************************************************
 ** \brief 系统外设时钟控制使能
 ** \param [in]  u32PeriphClk 系统外设时钟 @ref Sysctrl_Periph_Clock

 ** \retval None
 ***********************************************************************************************/
void SYSCTRL_PeriphClkEnable(uint32_t u32PeriphClk);

/**
 ***********************************************************************************************
 ** \brief 系统外设时钟控制禁止
 ** \param [in]  u32PeriphClk 系统外设时钟 @ref Sysctrl_Periph_Clock

 ** \retval None
 ***********************************************************************************************/
void SYSCTRL_PeriphClkDisable(uint32_t u32PeriphClk);

/**
 ***********************************************************************************************
 ** \brief 系统外设复位
 ** \param [in]  u32PeriphReset 系统外设复位 @ref Sysctrl_Periph_Reset

 ** \retval None
 ***********************************************************************************************/
void SYSCTRL_PeriphReset(uint32_t u32PeriphReset);

/**
 ***********************************************************************************************
 ** \brief 系统复位标志清除
 ** \param [in]  u32ResetFlag 系统复位标志 @ref Sysctrl_Reset_Flag

 ** \retval None
 ***********************************************************************************************/
void SYSCTRL_ResetFlagClear(uint32_t u32ResetFlag);

/**
 ***********************************************************************************************
 ** \brief 系统复位标志获取
 ** \param [in]  u32ResetFlag 系统复位标志 @ref Sysctrl_Reset_Flag

 ** \retval 复位标志
 ***********************************************************************************************/
uint32_t SYSCTRL_ResetFlagGet(uint32_t u32ResetFlag);

/**
 ***********************************************************************************************
 ** \brief 系统调试功能控制使能
 ** \param [in]  u32DebugModule 系统复位标志 @ref Sysctrl_Debug_Module

 ** \retval None
 ***********************************************************************************************/
void SYSCTRL_DebugEnable(uint32_t u32DebugModule);

/**
 ***********************************************************************************************
 ** \brief 系统调试功能控制禁止
 ** \param [in]  u32DebugModule 系统复位标志 @ref Sysctrl_Debug_Module

 ** \retval None
 ***********************************************************************************************/
void SYSCTRL_DebugDisable(uint32_t u32DebugModule);

/**
 ***********************************************************************************************
 ** \brief 系统调试功能控制禁止
 ** \param [in]  pstcChipInfo 芯片信息结构体指针 @ref stc_sysctrl_chip_info_t

 ** \retval None
 ***********************************************************************************************/
void SYSCTRL_GetChipInfo(stc_sysctrl_chip_info_t *pstcChipInfo);

//@} // Sysctrl Group

#ifdef __cplusplus
#endif

#endif /* __SYSCTRL_H__ */
/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/


