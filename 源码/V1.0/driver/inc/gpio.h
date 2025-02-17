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
 ** @file gpio.h
 **
 ** @brief Header file for GPIO functions
 **
 ** @author MADS Team 
 **
 ******************************************************************************/

#ifndef __GPIO_H__
#define __GPIO_H__

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "ddl.h"


/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif

/**
 *******************************************************************************
 ** \defgroup GpioGroup General Purpose I/O (GPIO)
 **
 **
 ******************************************************************************/
//@{
#define GPIO_GPSZ       (0x40u)

/*******************************************************************************
 * Global type definitions
 ******************************************************************************/
/**
  * @brief   GPIO Init structure definition
  */
typedef struct
{
    uint32_t u32Pin;            ///< GPIO PIN脚选择      @ref GPIO_PINs_define

    uint32_t u32Mode;           ///< GPIO 模式选择       @ref GPIO_mode_define

    uint32_t u32Pull;           ///< GPIO 上下拉配置     @ref GPIO_pull_define

    uint32_t u32ExtI;           ///< GPIO PIN脚复用功能  @ref GPIO_external_interrupter_define

}stc_gpio_init_t;
/**
  * @}
  */

/** @defgroup en_gpio_pin_t GPIO_PINs_define
  * @{
  */
#define GPIO_PIN_00                ((uint16_t)0x0001U)  /* Pin 0 selected    */
#define GPIO_PIN_01                ((uint16_t)0x0002U)  /* Pin 1 selected    */
#define GPIO_PIN_02                ((uint16_t)0x0004U)  /* Pin 2 selected    */
#define GPIO_PIN_03                ((uint16_t)0x0008U)  /* Pin 3 selected    */
#define GPIO_PIN_04                ((uint16_t)0x0010U)  /* Pin 4 selected    */
#define GPIO_PIN_05                ((uint16_t)0x0020U)  /* Pin 5 selected    */
#define GPIO_PIN_06                ((uint16_t)0x0040U)  /* Pin 6 selected    */
#define GPIO_PIN_07                ((uint16_t)0x0080U)  /* Pin 7 selected    */
#define GPIO_PIN_All               ((uint16_t)0x00FFU)  /* All pins selected */
/**
  * @}
  */

/** @defgroup en_gpio_pin_t GPIO_mode_define
  *        Elements values convention: 0x00UVWXYZ
  *           - V  : IO中断方式
  *           - W  ：IO驱动模式
  *           - X  : IO输入电平方式
  *           - Y  : IO输出方式 (Push Pull or Open Drain)
  *           - Z  : IO模式 (Input, Output, Alternate or Analog)
  * @{
  */
#define  GPIO_MODE_INPUT                        ((uint32_t)0x00000001U)     ///< 高阻输入模式
#define  GPIO_MODE_INPUT_TTL                    ((uint32_t)0x00000101U)     ///< TTL输入模式

#define  GPIO_MODE_OUTPUT_PP                    ((uint32_t)0x00000002U)     ///< 推挽输出模式(Push Pull)
#define  GPIO_MODE_OUTPUT_OD                    ((uint32_t)0x00000012U)     ///< 开漏输出模式(Open Drain)
#define  GPIO_MODE_OUTPUT_DRV_H                 ((uint32_t)0x00000002U)     ///< 高驱动模式
#define  GPIO_MODE_OUTPUT_DRV_L                 ((uint32_t)0x00001002U)     ///< 高驱动模式

#define  GPIO_MODE_AF_PP                        ((uint32_t)0x00000003U)     ///< 推挽复用模式
#define  GPIO_MODE_AF_OD                        ((uint32_t)0x00000013U)     ///< 开漏复用模式

#define  GPIO_MODE_ANALOG                       ((uint32_t)0x00000004U)     ///< 模拟功能模式

#define  GPIO_MODE_EXTI                         ((uint32_t)0x000F0000U)     ///< 外部中断模式

/**
  * @}
  */

/** @defgroup en_gpio_pin_t GPIO_pull_define
  * @{
  */
#define  GPIO_PULL_UP                           ((uint32_t)0x00100000U)     ///< 端口上拉
#define  GPIO_PULL_DOWN                         ((uint32_t)0x00200000U)     ///< 端口下拉
#define  GPIO_PULL_NONE                         ((uint32_t)0x00000000U)     ///< 端口无上下拉

/**
  * @}
  */

/** @defgroup en_gpio_pin_t GPIO_external_interrupter_define
  * @{
  */
#define  GPIO_EXTI_RISING                  ((uint32_t)0x00010000U)     ///< 上升沿触发
#define  GPIO_EXTI_FALLING                 ((uint32_t)0x00020000U)     ///< 下降沿触发
#define  GPIO_EXTI_RISING_FALLING          ((uint32_t)0x00030000U)     ///< 双沿触发
#define  GPIO_EXTI_HIGH                    ((uint32_t)0x00040000U)     ///< 高电平触发
#define  GPIO_EXTI_LOW                     ((uint32_t)0x00080000U)     ///< 低电平触发

/**
  * @}
  */

/*******************************************************************************
 * Global definitions——(GPIO 模拟功能设置宏定义)
 ******************************************************************************/
/*
 * Alternate function AF0
 */
#define GPIO_PORTA_ANALOG_SET()              REG_SETBITS(GPIOA->ADS, GPIO_PIN_All)
#define GPIO_PORTB_ANALOG_SET()              REG_SETBITS(GPIOB->ADS, GPIO_PIN_All)
#define GPIO_PORTC_ANALOG_SET()              REG_SETBITS(GPIOC->ADS, GPIO_PIN_All)
#define GPIO_PORTD_ANALOG_SET()              REG_SETBITS(GPIOD->ADS, GPIO_PIN_All)

#define GPIO_PA01_ANALOG_SET()               REG_SETBITS(GPIOA->ADS, GPIO_PIN_01)
#define GPIO_PA02_ANALOG_SET()               REG_SETBITS(GPIOA->ADS, GPIO_PIN_02)
#define GPIO_PA03_ANALOG_SET()               REG_SETBITS(GPIOA->ADS, GPIO_PIN_03)
#define GPIO_PA04_ANALOG_SET()               REG_SETBITS(GPIOA->ADS, GPIO_PIN_04)
#define GPIO_PB00_ANALOG_SET()               REG_SETBITS(GPIOB->ADS, GPIO_PIN_00)
#define GPIO_PB01_ANALOG_SET()               REG_SETBITS(GPIOB->ADS, GPIO_PIN_01)
#define GPIO_PB02_ANALOG_SET()               REG_SETBITS(GPIOB->ADS, GPIO_PIN_02)
#define GPIO_PB03_ANALOG_SET()               REG_SETBITS(GPIOB->ADS, GPIO_PIN_03)
#define GPIO_PB04_ANALOG_SET()               REG_SETBITS(GPIOB->ADS, GPIO_PIN_04)
#define GPIO_PB05_ANALOG_SET()               REG_SETBITS(GPIOB->ADS, GPIO_PIN_05)
#define GPIO_PC03_ANALOG_SET()               REG_SETBITS(GPIOC->ADS, GPIO_PIN_03)
#define GPIO_PC04_ANALOG_SET()               REG_SETBITS(GPIOC->ADS, GPIO_PIN_04)
#define GPIO_PC05_ANALOG_SET()               REG_SETBITS(GPIOC->ADS, GPIO_PIN_05)
#define GPIO_PC06_ANALOG_SET()               REG_SETBITS(GPIOC->ADS, GPIO_PIN_06)
#define GPIO_PC07_ANALOG_SET()               REG_SETBITS(GPIOC->ADS, GPIO_PIN_07)
#define GPIO_PD01_ANALOG_SET()               REG_SETBITS(GPIOD->ADS, GPIO_PIN_01)
#define GPIO_PD02_ANALOG_SET()               REG_SETBITS(GPIOD->ADS, GPIO_PIN_02)
#define GPIO_PD03_ANALOG_SET()               REG_SETBITS(GPIOD->ADS, GPIO_PIN_03)
#define GPIO_PD04_ANALOG_SET()               REG_SETBITS(GPIOD->ADS, GPIO_PIN_04)
#define GPIO_PD05_ANALOG_SET()               REG_SETBITS(GPIOD->ADS, GPIO_PIN_05)
#define GPIO_PD06_ANALOG_SET()               REG_SETBITS(GPIOD->ADS, GPIO_PIN_06)
/**
  *
  */

/*******************************************************************************
 * Global definitions——(GPIO 复用功能配置宏定义)
 ******************************************************************************/
/** @defgroup  GPIO_Alternate_function_selection
 * @{
 */

/*
 * Alternate function AF0
 */
#define GPIO_PA01_AF_GPIO_SET()               REG_CLEARBITS(GPIOA->AFRL, GPIO_AFRL_AFSEL1_Msk)
#define GPIO_PA02_AF_GPIO_SET()               REG_CLEARBITS(GPIOA->AFRL, GPIO_AFRL_AFSEL2_Msk)
#define GPIO_PA03_AF_GPIO_SET()               REG_CLEARBITS(GPIOA->AFRL, GPIO_AFRL_AFSEL3_Msk)
#define GPIO_PA04_AF_GPIO_SET()               REG_CLEARBITS(GPIOA->AFRL, GPIO_AFRL_AFSEL4_Msk)
#define GPIO_PB00_AF_GPIO_SET()               REG_CLEARBITS(GPIOB->AFRL, GPIO_AFRL_AFSEL0_Msk)
#define GPIO_PB01_AF_GPIO_SET()               REG_CLEARBITS(GPIOB->AFRL, GPIO_AFRL_AFSEL1_Msk)
#define GPIO_PB02_AF_GPIO_SET()               REG_CLEARBITS(GPIOB->AFRL, GPIO_AFRL_AFSEL2_Msk)
#define GPIO_PB03_AF_GPIO_SET()               REG_CLEARBITS(GPIOB->AFRL, GPIO_AFRL_AFSEL3_Msk)
#define GPIO_PB04_AF_GPIO_SET()               REG_CLEARBITS(GPIOB->AFRL, GPIO_AFRL_AFSEL4_Msk)
#define GPIO_PB05_AF_GPIO_SET()               REG_CLEARBITS(GPIOB->AFRL, GPIO_AFRL_AFSEL5_Msk)
#define GPIO_PC03_AF_GPIO_SET()               REG_CLEARBITS(GPIOC->AFRL, GPIO_AFRL_AFSEL3_Msk)
#define GPIO_PC04_AF_GPIO_SET()               REG_CLEARBITS(GPIOC->AFRL, GPIO_AFRL_AFSEL4_Msk)
#define GPIO_PC05_AF_GPIO_SET()               REG_CLEARBITS(GPIOC->AFRL, GPIO_AFRL_AFSEL5_Msk)
#define GPIO_PC06_AF_GPIO_SET()               REG_CLEARBITS(GPIOC->AFRL, GPIO_AFRL_AFSEL6_Msk)
#define GPIO_PC07_AF_GPIO_SET()               REG_CLEARBITS(GPIOC->AFRL, GPIO_AFRL_AFSEL7_Msk)
#define GPIO_PD01_AF_GPIO_SET()               REG_CLEARBITS(GPIOD->AFRL, GPIO_AFRL_AFSEL1_Msk)
#define GPIO_PD02_AF_GPIO_SET()               REG_CLEARBITS(GPIOD->AFRL, GPIO_AFRL_AFSEL2_Msk)
#define GPIO_PD03_AF_GPIO_SET()               REG_CLEARBITS(GPIOD->AFRL, GPIO_AFRL_AFSEL3_Msk)
#define GPIO_PD04_AF_GPIO_SET()               REG_CLEARBITS(GPIOD->AFRL, GPIO_AFRL_AFSEL4_Msk)
#define GPIO_PD05_AF_GPIO_SET()               REG_CLEARBITS(GPIOD->AFRL, GPIO_AFRL_AFSEL5_Msk)
#define GPIO_PD06_AF_GPIO_SET()               REG_CLEARBITS(GPIOD->AFRL, GPIO_AFRL_AFSEL6_Msk)
/**
  *
  */

/*
 * Alternate function AF1
 */
#define GPIO_PA01_AF_LPUART0_RXD_SET()          REG_MODIFY(GPIOA->AFRL, GPIO_AFRL_AFSEL1_Msk, (0x01u << GPIO_AFRL_AFSEL1_Pos))
#define GPIO_PA02_AF_LPUART0_TXD_SET()          REG_MODIFY(GPIOA->AFRL, GPIO_AFRL_AFSEL2_Msk, (0x01u << GPIO_AFRL_AFSEL2_Pos))
#define GPIO_PA03_AF_GTIM_CH2_SET()             REG_MODIFY(GPIOA->AFRL, GPIO_AFRL_AFSEL3_Msk, (0x01u << GPIO_AFRL_AFSEL3_Pos))
#define GPIO_PA04_AF_GTIM_TOGP_SET()            REG_MODIFY(GPIOA->AFRL, GPIO_AFRL_AFSEL4_Msk, (0x01u << GPIO_AFRL_AFSEL4_Pos))
#define GPIO_PB00_AF_ATIM3_CH0B_SET()           REG_MODIFY(GPIOB->AFRL, GPIO_AFRL_AFSEL0_Msk, (0x01u << GPIO_AFRL_AFSEL0_Pos))
#define GPIO_PB01_AF_ATIM3_CH1B_SET()           REG_MODIFY(GPIOB->AFRL, GPIO_AFRL_AFSEL1_Msk, (0x01u << GPIO_AFRL_AFSEL1_Pos))
#define GPIO_PB02_AF_ATIM3_CH2B_SET()           REG_MODIFY(GPIOB->AFRL, GPIO_AFRL_AFSEL2_Msk, (0x01u << GPIO_AFRL_AFSEL2_Pos))
#define GPIO_PB03_AF_ATIM3_ETR_SET()            REG_MODIFY(GPIOB->AFRL, GPIO_AFRL_AFSEL3_Msk, (0x01u << GPIO_AFRL_AFSEL3_Pos))
#define GPIO_PB04_AF_I2C_SCL_SET()              REG_MODIFY(GPIOB->AFRL, GPIO_AFRL_AFSEL4_Msk, (0x01u << GPIO_AFRL_AFSEL4_Pos))
#define GPIO_PB05_AF_I2C_SDA_SET()              REG_MODIFY(GPIOB->AFRL, GPIO_AFRL_AFSEL5_Msk, (0x01u << GPIO_AFRL_AFSEL5_Pos))
#define GPIO_PC03_AF_ATIM3_CH2A_SET()           REG_MODIFY(GPIOC->AFRL, GPIO_AFRL_AFSEL3_Msk, (0x01u << GPIO_AFRL_AFSEL3_Pos))
#define GPIO_PC04_AF_ATIM3_CH0B_SET()           REG_MODIFY(GPIOC->AFRL, GPIO_AFRL_AFSEL4_Msk, (0x01u << GPIO_AFRL_AFSEL4_Pos))
#define GPIO_PC05_AF_SPI_SCK_SET()              REG_MODIFY(GPIOC->AFRL, GPIO_AFRL_AFSEL5_Msk, (0x01u << GPIO_AFRL_AFSEL5_Pos))
#define GPIO_PC06_AF_SPI_MOSI_SET()             REG_MODIFY(GPIOC->AFRL, GPIO_AFRL_AFSEL6_Msk, (0x01u << GPIO_AFRL_AFSEL6_Pos))
#define GPIO_PC07_AF_SPI_MISO_SET()             REG_MODIFY(GPIOC->AFRL, GPIO_AFRL_AFSEL7_Msk, (0x01u << GPIO_AFRL_AFSEL7_Pos))
#define GPIO_PD01_AF_GTIM_ETR_SET()             REG_MODIFY(GPIOD->AFRL, GPIO_AFRL_AFSEL1_Msk, (0x01u << GPIO_AFRL_AFSEL1_Pos))
#define GPIO_PD02_AF_GTIM_CH2_SET()             REG_MODIFY(GPIOD->AFRL, GPIO_AFRL_AFSEL2_Msk, (0x01u << GPIO_AFRL_AFSEL2_Pos))
#define GPIO_PD03_AF_GTIM_CH1_SET()             REG_MODIFY(GPIOD->AFRL, GPIO_AFRL_AFSEL3_Msk, (0x01u << GPIO_AFRL_AFSEL3_Pos))
#define GPIO_PD04_AF_GTIM_CH0_SET()             REG_MODIFY(GPIOD->AFRL, GPIO_AFRL_AFSEL4_Msk, (0x01u << GPIO_AFRL_AFSEL4_Pos))
#define GPIO_PD05_AF_LPUART1_TXD_SET()          REG_MODIFY(GPIOD->AFRL, GPIO_AFRL_AFSEL5_Msk, (0x01u << GPIO_AFRL_AFSEL5_Pos))
#define GPIO_PD06_AF_LPUART1_RXD_SET()          REG_MODIFY(GPIOD->AFRL, GPIO_AFRL_AFSEL6_Msk, (0x01u << GPIO_AFRL_AFSEL6_Pos))

#define GPIO_PA03_AF_BTIM5_TOGP_SET()           GPIO_PA03_AF_GTIM_CH2_SET()
#define GPIO_PA04_AF_BTIM3_TOGP_SET()           GPIO_PA04_AF_GTIM_TOGP_SET()
#define GPIO_PD02_AF_BTIM5_TOGP_SET()           GPIO_PD02_AF_GTIM_CH2_SET()
#define GPIO_PD03_AF_BTIM4_TOGN_SET()           GPIO_PD03_AF_GTIM_CH1_SET()
#define GPIO_PD04_AF_BTIM4_TOGP_SET()           GPIO_PD04_AF_GTIM_CH0_SET()
#define GPIO_PD01_AF_BTIM3_ETR_SET()            GPIO_PD01_AF_GTIM_ETR_SET()
#define GPIO_PD01_AF_BTIM4_ETR_SET()            GPIO_PD01_AF_GTIM_ETR_SET()
#define GPIO_PD01_AF_BTIM5_ETR_SET()            GPIO_PD01_AF_GTIM_ETR_SET()
/**
  *
  */

/*
 *  Alternate function AF2
 */
#define GPIO_PA01_AF_I2C_SDA_SET()              REG_MODIFY(GPIOA->AFRL, GPIO_AFRL_AFSEL1_Msk, (0x02u << GPIO_AFRL_AFSEL1_Pos))
#define GPIO_PA02_AF_I2C_SCL_SET()              REG_MODIFY(GPIOA->AFRL, GPIO_AFRL_AFSEL2_Msk, (0x02u << GPIO_AFRL_AFSEL2_Pos))
#define GPIO_PA03_AF_SPI_CS_SET()               REG_MODIFY(GPIOA->AFRL, GPIO_AFRL_AFSEL3_Msk, (0x02u << GPIO_AFRL_AFSEL3_Pos))
#define GPIO_PA04_AF_LVD_OUT_SET()              REG_MODIFY(GPIOA->AFRL, GPIO_AFRL_AFSEL4_Msk, (0x02u << GPIO_AFRL_AFSEL4_Pos))
#define GPIO_PB00_AF_GTIM_CH3_SET()             REG_MODIFY(GPIOB->AFRL, GPIO_AFRL_AFSEL0_Msk, (0x02u << GPIO_AFRL_AFSEL0_Pos))
#define GPIO_PB01_AF_GTIM_CH2_SET()             REG_MODIFY(GPIOB->AFRL, GPIO_AFRL_AFSEL1_Msk, (0x02u << GPIO_AFRL_AFSEL1_Pos))
#define GPIO_PB02_AF_GTIM_CH1_SET()             REG_MODIFY(GPIOB->AFRL, GPIO_AFRL_AFSEL2_Msk, (0x02u << GPIO_AFRL_AFSEL2_Pos))
#define GPIO_PB03_AF_GTIM_CH0_SET()             REG_MODIFY(GPIOB->AFRL, GPIO_AFRL_AFSEL3_Msk, (0x02u << GPIO_AFRL_AFSEL3_Pos))
#define GPIO_PB04_AF_ATIM3_CH2B_SET()           REG_MODIFY(GPIOB->AFRL, GPIO_AFRL_AFSEL4_Msk, (0x02u << GPIO_AFRL_AFSEL4_Pos))
#define GPIO_PB05_AF_ATIM3_BK_SET()             REG_MODIFY(GPIOB->AFRL, GPIO_AFRL_AFSEL5_Msk, (0x02u << GPIO_AFRL_AFSEL5_Pos))
#define GPIO_PC03_AF_ATIM3_CH0B_SET()           REG_MODIFY(GPIOC->AFRL, GPIO_AFRL_AFSEL3_Msk, (0x02u << GPIO_AFRL_AFSEL3_Pos))
#define GPIO_PC04_AF_ATIM3_CH1B_SET()           REG_MODIFY(GPIOC->AFRL, GPIO_AFRL_AFSEL4_Msk, (0x02u << GPIO_AFRL_AFSEL4_Pos))
#define GPIO_PC05_AF_GTIM_CH3_SET()             REG_MODIFY(GPIOC->AFRL, GPIO_AFRL_AFSEL5_Msk, (0x02u << GPIO_AFRL_AFSEL5_Pos))
#define GPIO_PC06_AF_ATIM3_CH0A_SET()           REG_MODIFY(GPIOC->AFRL, GPIO_AFRL_AFSEL6_Msk, (0x02u << GPIO_AFRL_AFSEL6_Pos))
#define GPIO_PC07_AF_ATIM3_CH1A_SET()           REG_MODIFY(GPIOC->AFRL, GPIO_AFRL_AFSEL7_Msk, (0x02u << GPIO_AFRL_AFSEL7_Pos))
#define GPIO_PD01_AF_ATIM3_BK_SET()             REG_MODIFY(GPIOD->AFRL, GPIO_AFRL_AFSEL1_Msk, (0x02u << GPIO_AFRL_AFSEL1_Pos))
#define GPIO_PD02_AF_ATIM3_CH2A_SET()           REG_MODIFY(GPIOD->AFRL, GPIO_AFRL_AFSEL2_Msk, (0x02u << GPIO_AFRL_AFSEL2_Pos))
#define GPIO_PD03_AF_ATIM3_CH1A_SET()           REG_MODIFY(GPIOD->AFRL, GPIO_AFRL_AFSEL3_Msk, (0x02u << GPIO_AFRL_AFSEL3_Pos))
#define GPIO_PD04_AF_LPUART1_TXD_SET()          REG_MODIFY(GPIOD->AFRL, GPIO_AFRL_AFSEL4_Msk, (0x02u << GPIO_AFRL_AFSEL4_Pos))
#define GPIO_PD05_AF_ATIM3_CH0A_SET()           REG_MODIFY(GPIOD->AFRL, GPIO_AFRL_AFSEL5_Msk, (0x02u << GPIO_AFRL_AFSEL5_Pos))
#define GPIO_PD06_AF_GTIM_ETR_SET()             REG_MODIFY(GPIOD->AFRL, GPIO_AFRL_AFSEL6_Msk, (0x02u << GPIO_AFRL_AFSEL6_Pos))

#define GPIO_PB00_AF_BTIM5_TOGN_SET()             GPIO_PB00_AF_GTIM_CH3_SET()
#define GPIO_PB01_AF_BTIM5_TOGP_SET()             GPIO_PB01_AF_GTIM_CH2_SET()
#define GPIO_PB02_AF_BTIM4_TOGN_SET()             GPIO_PB02_AF_GTIM_CH1_SET()
#define GPIO_PB03_AF_BTIM4_TOGP_SET()             GPIO_PB03_AF_GTIM_CH0_SET()
#define GPIO_PC05_AF_BTIM5_TOGN_SET()             GPIO_PC05_AF_GTIM_CH3_SET()
#define GPIO_PD06_AF_BTIM3_ETR_SET()              GPIO_PD06_AF_GTIM_ETR_SET()
#define GPIO_PD06_AF_BTIM4_ETR_SET()              GPIO_PD06_AF_GTIM_ETR_SET()
#define GPIO_PD06_AF_BTIM5_ETR_SET()              GPIO_PD06_AF_GTIM_ETR_SET()
/**
  *
  */

/*
 *  Alternate function AF3
 */
#define GPIO_PA01_AF_GTIM_TOGP_SET()            REG_MODIFY(GPIOA->AFRL, GPIO_AFRL_AFSEL1_Msk, (0x03u << GPIO_AFRL_AFSEL1_Pos))
#define GPIO_PA02_AF_GTIM_TOGN_SET()            REG_MODIFY(GPIOA->AFRL, GPIO_AFRL_AFSEL2_Msk, (0x03u << GPIO_AFRL_AFSEL2_Pos))
#define GPIO_PA03_AF_CTRIM_ETR_TOG_SET()        REG_MODIFY(GPIOA->AFRL, GPIO_AFRL_AFSEL3_Msk, (0x03u << GPIO_AFRL_AFSEL3_Pos))
#define GPIO_PA04_AF_SPI_NSS_SET()              REG_MODIFY(GPIOA->AFRL, GPIO_AFRL_AFSEL4_Msk, (0x03u << GPIO_AFRL_AFSEL4_Pos))
#define GPIO_PB00_AF_LPUART0_RTS_SET()          REG_MODIFY(GPIOB->AFRL, GPIO_AFRL_AFSEL0_Msk, (0x03u << GPIO_AFRL_AFSEL0_Pos))
#define GPIO_PB01_AF_LPUART0_CTS_SET()          REG_MODIFY(GPIOB->AFRL, GPIO_AFRL_AFSEL1_Msk, (0x03u << GPIO_AFRL_AFSEL1_Pos))
#define GPIO_PB02_AF_LPUART1_RTS_SET()          REG_MODIFY(GPIOB->AFRL, GPIO_AFRL_AFSEL2_Msk, (0x03u << GPIO_AFRL_AFSEL2_Pos))
#define GPIO_PB03_AF_LPUART1_CTS_SET()          REG_MODIFY(GPIOB->AFRL, GPIO_AFRL_AFSEL3_Msk, (0x03u << GPIO_AFRL_AFSEL3_Pos))
#define GPIO_PB04_AF_LPUART0_CTS_SET()          REG_MODIFY(GPIOB->AFRL, GPIO_AFRL_AFSEL4_Msk, (0x03u << GPIO_AFRL_AFSEL4_Pos))
#define GPIO_PB05_AF_CTRIM_ETR_TOG_SET()        REG_MODIFY(GPIOB->AFRL, GPIO_AFRL_AFSEL5_Msk, (0x03u << GPIO_AFRL_AFSEL5_Pos))
#define GPIO_PC03_AF_LPUART0_RTS_SET()          REG_MODIFY(GPIOC->AFRL, GPIO_AFRL_AFSEL3_Msk, (0x03u << GPIO_AFRL_AFSEL3_Pos))
#define GPIO_PC04_AF_TCLK_OUT_SET()             REG_MODIFY(GPIOC->AFRL, GPIO_AFRL_AFSEL4_Msk, (0x03u << GPIO_AFRL_AFSEL4_Pos))
#define GPIO_PC05_AF_ATIM3_ETR_SET()            REG_MODIFY(GPIOC->AFRL, GPIO_AFRL_AFSEL5_Msk, (0x03u << GPIO_AFRL_AFSEL5_Pos))
#define GPIO_PC06_AF_LPUART1_RTS_SET()          REG_MODIFY(GPIOC->AFRL, GPIO_AFRL_AFSEL6_Msk, (0x03u << GPIO_AFRL_AFSEL6_Pos))
#define GPIO_PC07_AF_LPUART0_RXD_SET()          REG_MODIFY(GPIOC->AFRL, GPIO_AFRL_AFSEL7_Msk, (0x03u << GPIO_AFRL_AFSEL7_Pos))
#define GPIO_PD01_AF_LPUART0_TXD_SET()          REG_MODIFY(GPIOD->AFRL, GPIO_AFRL_AFSEL1_Msk, (0x03u << GPIO_AFRL_AFSEL1_Pos))
#define GPIO_PD02_AF_LPUART1_CTS_SET()          REG_MODIFY(GPIOD->AFRL, GPIO_AFRL_AFSEL2_Msk, (0x03u << GPIO_AFRL_AFSEL2_Pos))
#define GPIO_PD03_AF_LPUART1_RXD_SET()          REG_MODIFY(GPIOD->AFRL, GPIO_AFRL_AFSEL3_Msk, (0x03u << GPIO_AFRL_AFSEL3_Pos))
#define GPIO_PD04_AF_SPI_SCK_SET()              REG_MODIFY(GPIOD->AFRL, GPIO_AFRL_AFSEL4_Msk, (0x03u << GPIO_AFRL_AFSEL4_Pos))
#define GPIO_PD05_AF_SPI_MISO_SET()             REG_MODIFY(GPIOD->AFRL, GPIO_AFRL_AFSEL5_Msk, (0x03u << GPIO_AFRL_AFSEL5_Pos))
#define GPIO_PD06_AF_SPI_MOSI_SET()             REG_MODIFY(GPIOD->AFRL, GPIO_AFRL_AFSEL6_Msk, (0x03u << GPIO_AFRL_AFSEL6_Pos))

#define GPIO_PA01_AF_BTIM3_TOGP_SET()           GPIO_PA01_AF_GTIM_TOGP_SET()
#define GPIO_PA02_AF_BTIM3_TOGN_SET()           GPIO_PA02_AF_GTIM_TOGN_SET()
/**
  *
  */

/*
 *  Alternate function AF4
 */
#define GPIO_PA01_AF_HCLK_OUT_SET()             REG_MODIFY(GPIOA->AFRL, GPIO_AFRL_AFSEL1_Msk, (0x04u << GPIO_AFRL_AFSEL1_Pos))
#define GPIO_PA02_AF_LVD_OUT_SET()              REG_MODIFY(GPIOA->AFRL, GPIO_AFRL_AFSEL2_Msk, (0x04u << GPIO_AFRL_AFSEL2_Pos))
/**
  *
  */
  
/**
  * @}
  */


/*******************************************************************************
 * Global definitions——(GPIO IO操作宏定义)
 ******************************************************************************/
/** @defgroup en_gpio_pin_t GPIO_Alternate_function_selection
 * @{
 */

/*
 *  GPIO READ
 */
#define GPIO_PORTA_READ()              REG_READBITS(GPIOA->IN, GPIO_PIN_All)
#define GPIO_PORTB_READ()              REG_READBITS(GPIOB->IN, GPIO_PIN_All)
#define GPIO_PORTC_READ()              REG_READBITS(GPIOC->IN, GPIO_PIN_All)
#define GPIO_PORTD_READ()              REG_READBITS(GPIOD->IN, GPIO_PIN_All)

#define GPIO_PA01_READ()               REG_READBITS(GPIOA->IN, GPIO_PIN_01)
#define GPIO_PA02_READ()               REG_READBITS(GPIOA->IN, GPIO_PIN_02)
#define GPIO_PA03_READ()               REG_READBITS(GPIOA->IN, GPIO_PIN_03)
#define GPIO_PA04_READ()               REG_READBITS(GPIOA->IN, GPIO_PIN_04)
#define GPIO_PB00_READ()               REG_READBITS(GPIOB->IN, GPIO_PIN_00)
#define GPIO_PB01_READ()               REG_READBITS(GPIOB->IN, GPIO_PIN_01)
#define GPIO_PB02_READ()               REG_READBITS(GPIOB->IN, GPIO_PIN_02)
#define GPIO_PB03_READ()               REG_READBITS(GPIOB->IN, GPIO_PIN_03)
#define GPIO_PB04_READ()               REG_READBITS(GPIOB->IN, GPIO_PIN_04)
#define GPIO_PB05_READ()               REG_READBITS(GPIOB->IN, GPIO_PIN_05)
#define GPIO_PC03_READ()               REG_READBITS(GPIOC->IN, GPIO_PIN_03)
#define GPIO_PC04_READ()               REG_READBITS(GPIOC->IN, GPIO_PIN_04)
#define GPIO_PC05_READ()               REG_READBITS(GPIOC->IN, GPIO_PIN_05)
#define GPIO_PC06_READ()               REG_READBITS(GPIOC->IN, GPIO_PIN_06)
#define GPIO_PC07_READ()               REG_READBITS(GPIOC->IN, GPIO_PIN_07)
#define GPIO_PD01_READ()               REG_READBITS(GPIOD->IN, GPIO_PIN_01)
#define GPIO_PD02_READ()               REG_READBITS(GPIOD->IN, GPIO_PIN_02)
#define GPIO_PD03_READ()               REG_READBITS(GPIOD->IN, GPIO_PIN_03)
#define GPIO_PD04_READ()               REG_READBITS(GPIOD->IN, GPIO_PIN_04)
#define GPIO_PD05_READ()               REG_READBITS(GPIOD->IN, GPIO_PIN_05)
#define GPIO_PD06_READ()               REG_READBITS(GPIOD->IN, GPIO_PIN_06)
/**
  *
  */

/*
 *  GPIO PORT(Pins) WRITE
 */

#define GPIO_PORTA_WRITE_BYTE(u8Val)        REG_WRITE((volitile uint8_t*)GPIOA->OUT, (u8Val));
#define GPIO_PORTB_WRITE_BYTE(u8Val)        REG_WRITE((volitile uint8_t*)GPIOB->OUT, (u8Val));
#define GPIO_PORTC_WRITE_BYTE(u8Val)        REG_WRITE((volitile uint8_t*)GPIOC->OUT, (u8Val));
#define GPIO_PORTD_WRITE_BYTE(u8Val)        REG_WRITE((volitile uint8_t*)GPIOD->OUT, (u8Val));

#define GPIO_PORTA_WRITE_ATOMIC(u8Val)         REG_WRITE(GPIOA->BSRR, ((uint32_t)(u8Val)|((~(u8Val))<<0x10u)));
#define GPIO_PORTB_WRITE_ATOMIC(u8Val)         REG_WRITE(GPIOB->BSRR, ((uint32_t)(u8Val)|((~(u8Val))<<0x10u)));
#define GPIO_PORTC_WRITE_ATOMIC(u8Val)         REG_WRITE(GPIOC->BSRR, ((uint32_t)(u8Val)|((~(u8Val))<<0x10u)));
#define GPIO_PORTD_WRITE_ATOMIC(u8Val)         REG_WRITE(GPIOD->BSRR, ((uint32_t)(u8Val)|((~(u8Val))<<0x10u)));

/**
  *
  */

/*
 *  GPIO SET
 */
#define GPIO_PORTA_SET(Pins)          REG_WRITE(GPIOA->BSRR, (Pins));
#define GPIO_PORTB_SET(Pins)          REG_WRITE(GPIOB->BSRR, (Pins));
#define GPIO_PORTC_SET(Pins)          REG_WRITE(GPIOC->BSRR, (Pins));
#define GPIO_PORTD_SET(Pins)          REG_WRITE(GPIOD->BSRR, (Pins));

#define GPIO_PA01_SET()               REG_WRITE(GPIOA->BSRR, GPIO_PIN_01);
#define GPIO_PA02_SET()               REG_WRITE(GPIOA->BSRR, GPIO_PIN_02);
#define GPIO_PA03_SET()               REG_WRITE(GPIOA->BSRR, GPIO_PIN_03);
#define GPIO_PA04_SET()               REG_WRITE(GPIOA->BSRR, GPIO_PIN_04);
#define GPIO_PB00_SET()               REG_WRITE(GPIOB->BSRR, GPIO_PIN_00);
#define GPIO_PB01_SET()               REG_WRITE(GPIOB->BSRR, GPIO_PIN_01);
#define GPIO_PB02_SET()               REG_WRITE(GPIOB->BSRR, GPIO_PIN_02);
#define GPIO_PB03_SET()               REG_WRITE(GPIOB->BSRR, GPIO_PIN_03);
#define GPIO_PB04_SET()               REG_WRITE(GPIOB->BSRR, GPIO_PIN_04);
#define GPIO_PB05_SET()               REG_WRITE(GPIOB->BSRR, GPIO_PIN_05);
#define GPIO_PC03_SET()               REG_WRITE(GPIOC->BSRR, GPIO_PIN_03);
#define GPIO_PC04_SET()               REG_WRITE(GPIOC->BSRR, GPIO_PIN_04);
#define GPIO_PC05_SET()               REG_WRITE(GPIOC->BSRR, GPIO_PIN_05);
#define GPIO_PC06_SET()               REG_WRITE(GPIOC->BSRR, GPIO_PIN_06);
#define GPIO_PC07_SET()               REG_WRITE(GPIOC->BSRR, GPIO_PIN_07);
#define GPIO_PD01_SET()               REG_WRITE(GPIOD->BSRR, GPIO_PIN_01);
#define GPIO_PD02_SET()               REG_WRITE(GPIOD->BSRR, GPIO_PIN_02);
#define GPIO_PD03_SET()               REG_WRITE(GPIOD->BSRR, GPIO_PIN_03);
#define GPIO_PD04_SET()               REG_WRITE(GPIOD->BSRR, GPIO_PIN_04);
#define GPIO_PD05_SET()               REG_WRITE(GPIOD->BSRR, GPIO_PIN_05);
#define GPIO_PD06_SET()               REG_WRITE(GPIOD->BSRR, GPIO_PIN_06);

/**
  *
  */

/*
 *  GPIO RESET
 */
#define GPIO_PORTA_RESET(Pins)          REG_WRITE(GPIOA->BRR, (Pins));
#define GPIO_PORTB_RESET(Pins)          REG_WRITE(GPIOB->BRR, (Pins));
#define GPIO_PORTC_RESET(Pins)          REG_WRITE(GPIOC->BRR, (Pins));
#define GPIO_PORTD_RESET(Pins)          REG_WRITE(GPIOD->BRR, (Pins));

#define GPIO_PA01_RESET()               REG_WRITE(GPIOA->BRR, GPIO_PIN_01);
#define GPIO_PA02_RESET()               REG_WRITE(GPIOA->BRR, GPIO_PIN_02);
#define GPIO_PA03_RESET()               REG_WRITE(GPIOA->BRR, GPIO_PIN_03);
#define GPIO_PA04_RESET()               REG_WRITE(GPIOA->BRR, GPIO_PIN_04);
#define GPIO_PB00_RESET()               REG_WRITE(GPIOB->BRR, GPIO_PIN_00);
#define GPIO_PB01_RESET()               REG_WRITE(GPIOB->BRR, GPIO_PIN_01);
#define GPIO_PB02_RESET()               REG_WRITE(GPIOB->BRR, GPIO_PIN_02);
#define GPIO_PB03_RESET()               REG_WRITE(GPIOB->BRR, GPIO_PIN_03);
#define GPIO_PB04_RESET()               REG_WRITE(GPIOB->BRR, GPIO_PIN_04);
#define GPIO_PB05_RESET()               REG_WRITE(GPIOB->BRR, GPIO_PIN_05);
#define GPIO_PC03_RESET()               REG_WRITE(GPIOC->BRR, GPIO_PIN_03);
#define GPIO_PC04_RESET()               REG_WRITE(GPIOC->BRR, GPIO_PIN_04);
#define GPIO_PC05_RESET()               REG_WRITE(GPIOC->BRR, GPIO_PIN_05);
#define GPIO_PC06_RESET()               REG_WRITE(GPIOC->BRR, GPIO_PIN_06);
#define GPIO_PC07_RESET()               REG_WRITE(GPIOC->BRR, GPIO_PIN_07);
#define GPIO_PD01_RESET()               REG_WRITE(GPIOD->BRR, GPIO_PIN_01);
#define GPIO_PD02_RESET()               REG_WRITE(GPIOD->BRR, GPIO_PIN_02);
#define GPIO_PD03_RESET()               REG_WRITE(GPIOD->BRR, GPIO_PIN_03);
#define GPIO_PD04_RESET()               REG_WRITE(GPIOD->BRR, GPIO_PIN_04);
#define GPIO_PD05_RESET()               REG_WRITE(GPIOD->BRR, GPIO_PIN_05);
#define GPIO_PD06_RESET()               REG_WRITE(GPIOD->BRR, GPIO_PIN_06);

/**
  *
  */


/**
  * @}
  */


/**     GPIO_Clock_Output_Function
 * @{   GPIO时钟输出功能配置
 */


#define GPIO_PA01_HCLK_OUT()                        REG_MODIFY(GPIOA->AFRL, GPIO_AFRL_AFSEL1_Msk, (0x04u << GPIO_AFRL_AFSEL1_Pos));

#define _PC04_AF_TCLKO_SET(src, div)                REG_MODIFY(GPIOC->AFRL, GPIO_AFRL_AFSEL4_Msk , (0x03u << GPIO_AFRL_AFSEL4_Pos ));\
                                                    REG_MODIFY(GPIOAUX->CR1, GPIOAUX_CR1_TCLKDIV_Msk, ((div) << GPIOAUX_CR1_TCLKDIV_Pos));\
                                                    REG_MODIFY(GPIOAUX->CR1, GPIOAUX_CR1_TCLKSRC_Msk, ((src) << GPIOAUX_CR1_TCLKSRC_Pos));
#define GPIO_PC04_TCLK_OUT_RCH_DIV1()               _PC04_AF_TCLKO_SET(0, 0);
#define GPIO_PC04_TCLK_OUT_RCH_DIV8()               _PC04_AF_TCLKO_SET(0, 1);
#define GPIO_PC04_TCLK_OUT_RCH_DIV64()              _PC04_AF_TCLKO_SET(0, 2);
#define GPIO_PC04_TCLK_OUT_RCH_DIV256()             _PC04_AF_TCLKO_SET(0, 3);
#define GPIO_PC04_TCLK_OUT_RCL_DIV1()               _PC04_AF_TCLKO_SET(1, 0);
#define GPIO_PC04_TCLK_OUT_RCL_DIV8()               _PC04_AF_TCLKO_SET(1, 1);
#define GPIO_PC04_TCLK_OUT_RCL_DIV64()              _PC04_AF_TCLKO_SET(1, 2);
#define GPIO_PC04_TCLK_OUT_RCL_DIV256()             _PC04_AF_TCLKO_SET(1, 3);
#define GPIO_PC04_TCLK_OUT_PCLK_DIV1()              _PC04_AF_TCLKO_SET(2, 0);
#define GPIO_PC04_TCLK_OUT_PCLK_DIV8()              _PC04_AF_TCLKO_SET(2, 1);
#define GPIO_PC04_TCLK_OUT_PCLK_DIV64()             _PC04_AF_TCLKO_SET(2, 2);
#define GPIO_PC04_TCLK_OUT_PCLK_DIV256()            _PC04_AF_TCLKO_SET(2, 3);
#define GPIO_PC04_TCLK_OUT_HCLK_DIV1()              _PC04_AF_TCLKO_SET(3, 0);
#define GPIO_PC04_TCLK_OUT_HCLK_DIV8()              _PC04_AF_TCLKO_SET(3, 1);
#define GPIO_PC04_TCLK_OUT_HCLK_DIV64()             _PC04_AF_TCLKO_SET(3, 2);
#define GPIO_PC04_TCLK_OUT_HCLK_DIV256()            _PC04_AF_TCLKO_SET(3, 3);

/*
 *
 */


/**     GPIO_Timer_Interconnection_Function (TIMIF)
 * @{   GPIO定时器内部互联功能配置
 */

#define GPIO_TIMIF_ATIM3CH0A_LPUART0_RXD()      REG_MODIFY(GPIOAUX->CR4, GPIOAUX_CR4_ATIM3CH0A_Msk, ((1U)<<GPIOAUX_CR4_ATIM3CH0A_Pos));
#define GPIO_TIMIF_ATIM3CH0A_LPUART1_RXD()      REG_MODIFY(GPIOAUX->CR4, GPIOAUX_CR4_ATIM3CH0A_Msk, ((2U)<<GPIOAUX_CR4_ATIM3CH0A_Pos));
#define GPIO_TIMIF_ATIM3CH0A_LVD_OUT()          REG_MODIFY(GPIOAUX->CR4, GPIOAUX_CR4_ATIM3CH0A_Msk, ((3U)<<GPIOAUX_CR4_ATIM3CH0A_Pos));

#define GPIO_TIMIF_GTIMCH1_LPUART0_RXD()        REG_MODIFY(GPIOAUX->CR4, GPIOAUX_CR4_GTIMCH1_Msk, ((1U)<<GPIOAUX_CR4_GTIMCH1_Pos));
#define GPIO_TIMIF_GTIMCH1_LPUART1_RXD()        REG_MODIFY(GPIOAUX->CR4, GPIOAUX_CR4_GTIMCH1_Msk, ((2U)<<GPIOAUX_CR4_GTIMCH1_Pos));
#define GPIO_TIMIF_GTIMCH1_LVD_OUT()            REG_MODIFY(GPIOAUX->CR4, GPIOAUX_CR4_GTIMCH1_Msk, ((3U)<<GPIOAUX_CR4_GTIMCH1_Pos));

/*
 *
 */

/******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/


/******************************************************************************
 * Global variable definitions ('extern')
 ******************************************************************************/

/******************************************************************************
  Global function prototypes (definition in C source)
*******************************************************************************/
/**
 *******************************************************************************
 ** \brief GPIO 初始化
 **
 ** \param [in]  GPIOx          @ref GPIO_TypeDef
 ** \param [in]  pstcGpioInit   @ref stc_gpio_init_t
 **
 ** \retval  None
 ******************************************************************************/
void GPIO_Init(GPIO_TypeDef *GPIOx, stc_gpio_init_t *pstcGpioInit);
#define GPIOA_Init(pstcGpioInit)    GPIO_Init(GPIOA, (pstcGpioInit));
#define GPIOB_Init(pstcGpioInit)    GPIO_Init(GPIOB, (pstcGpioInit));
#define GPIOC_Init(pstcGpioInit)    GPIO_Init(GPIOC, (pstcGpioInit));
#define GPIOD_Init(pstcGpioInit)    GPIO_Init(GPIOD, (pstcGpioInit));

/**
 *******************************************************************************
 ** \brief GPIO PIN脚中断状态获取
 **
 ** \param [in]  GPIOx          @ref GPIO_TypeDef
 ** \param [in]  u32Pin         @ref GPIO_PINs_definition
 **
 ** \retval  0表示未发生中断，非0表示产生中断
 ******************************************************************************/
uint32_t GPIO_ExtIrqStateGet(GPIO_TypeDef *GPIOx, uint32_t u32Pin);

/**
 *******************************************************************************
 ** \brief GPIO PIN脚中断状态清除
 **
 ** \param [in]  GPIOx          @ref GPIO_TypeDef
 ** \param [in]  u32Pin         @ref GPIO_PINs_definition
 **
 ** \retval  None
 ******************************************************************************/
void GPIO_ExtIrqStateClear(GPIO_TypeDef *GPIOx, uint32_t u32Pin);


//@} // GpioGroup

#ifdef __cplusplus
}
#endif

#endif /* __GPIO_H__ */
/******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
