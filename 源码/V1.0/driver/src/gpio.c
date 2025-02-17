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
 ** @file gpio.c
 **
 ** @brief Source file for GPIO functions
 **
 ** @author MADS Team 
 **
 ******************************************************************************/

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "gpio.h"

/**
 *******************************************************************************
 ** \addtogroup GpioGroup
 ******************************************************************************/
//@{

/*******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/
#define GPIO_MODE           (0xF)
#define GPIO_MODE_OD        (0xF0)
#define GPIO_MODE_OUTPUT    (0x2)
#define GPIO_MODE_AF        (0x3)

/*******************************************************************************
 * Global variable definitions (declared in header file with 'extern')         *
 ******************************************************************************/

/*******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/*******************************************************************************
 * Local function prototypes ('static')
 ******************************************************************************/

/*******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/

/*******************************************************************************
 * Function implementation - global ('extern') and local ('static')
 ******************************************************************************/
/**
 *******************************************************************************
 ** \brief GPIO 初始化
 **
 ** \param [in]  GPIOx          @ref GPIO_TypeDef
 ** \param [in]  pstcGpioInit   @ref stc_gpio_init_t
 **
 ** \retval  None
 ******************************************************************************/
void GPIO_Init(GPIO_TypeDef *GPIOx, stc_gpio_init_t *pstcGpioInit)
{
    ///< ANALOG
    if(GPIO_MODE_ANALOG == (pstcGpioInit->u32Mode&GPIO_MODE))
    {
        REG_SETBITS(GPIOx->ADS, pstcGpioInit->u32Pin);
    }
    else
    {
        REG_CLEARBITS(GPIOx->ADS, pstcGpioInit->u32Pin);
    }
    
    ///< INPUT
    if(GPIO_MODE_INPUT == (pstcGpioInit->u32Mode&GPIO_MODE))
    {
        REG_SETBITS(GPIOx->DIR, pstcGpioInit->u32Pin);
    }
    
    ///< OUTPUT
    if(GPIO_MODE_OUTPUT == (pstcGpioInit->u32Mode&GPIO_MODE))
    {
        REG_CLEARBITS(GPIOx->DIR, pstcGpioInit->u32Pin);
    }
    
    ///< OPENDRAIN or PUSH-PULL
    if(pstcGpioInit->u32Mode&GPIO_MODE_OD)
    {
        REG_SETBITS(GPIOx->OPENDRAIN, pstcGpioInit->u32Pin);
    }
    else
    {
        REG_CLEARBITS(GPIOx->OPENDRAIN, pstcGpioInit->u32Pin);
        
        ///< PUSH-PULL TYPE
        if(GPIO_PULL_UP == pstcGpioInit->u32Pull)
        {
            REG_SETBITS(GPIOx->PU, pstcGpioInit->u32Pin);
        }
        else
        {
            REG_CLEARBITS(GPIOx->PU, pstcGpioInit->u32Pin);
        }
    }
        
    ///< EXTI
    if(pstcGpioInit->u32Mode&GPIO_MODE_EXTI)
    {
        if(pstcGpioInit->u32ExtI&GPIO_EXTI_RISING)
        {
            REG_SETBITS(GPIOx->RISEIE, pstcGpioInit->u32Pin);
        }
        else
        {
            REG_CLEARBITS(GPIOx->RISEIE, pstcGpioInit->u32Pin);
        }
        
        if(pstcGpioInit->u32ExtI&GPIO_EXTI_FALLING)
        {
            REG_SETBITS(GPIOx->FALLIE, pstcGpioInit->u32Pin);
        }
        else
        {
            REG_CLEARBITS(GPIOx->FALLIE, pstcGpioInit->u32Pin);
        }
        
        if(pstcGpioInit->u32ExtI&GPIO_EXTI_HIGH)
        {
            REG_SETBITS(GPIOx->HIGHIE, pstcGpioInit->u32Pin);
        }
        else
        {
            REG_CLEARBITS(GPIOx->HIGHIE, pstcGpioInit->u32Pin);
        }
        
        if(pstcGpioInit->u32ExtI&GPIO_EXTI_LOW)
        {
            REG_SETBITS(GPIOx->LOWIE, pstcGpioInit->u32Pin);
        }
        else
        {
            REG_CLEARBITS(GPIOx->LOWIE, pstcGpioInit->u32Pin);
        }
    }
     
}


/**
 *******************************************************************************
 ** \brief GPIO PIN脚中断状态获取
 **
 ** \param [in]  GPIOx          @ref GPIO_TypeDef
 ** \param [in]  u32Pin         @ref GPIO_PINs_definition
 **
 ** \retval  0表示未发生中断，非0表示产生中断
 ******************************************************************************/
uint32_t GPIO_ExtIrqStateGet(GPIO_TypeDef *GPIOx, uint32_t u32Pin)
{    
    return (uint32_t)REG_READBITS(GPIOx->IFR, u32Pin);
}

/**
 *******************************************************************************
 ** \brief GPIO PIN脚中断状态清除
 **
 ** \param [in]  GPIOx          @ref GPIO_TypeDef
 ** \param [in]  u32Pin         @ref GPIO_PINs_definition
 **
 ** \retval  None
 ******************************************************************************/
void GPIO_ExtIrqStateClear(GPIO_TypeDef *GPIOx, uint32_t u32Pin)
{
    REG_CLEARBITS(GPIOx->ICR, u32Pin);
}




//@} // GpioGroup


/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/

