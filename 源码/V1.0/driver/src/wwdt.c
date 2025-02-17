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
 ** @file wwdt.c
 **
 ** @brief Source file for WWDT functions
 **
 ** @author MADS Team 
 **
 ******************************************************************************/

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "wwdt.h"

/**
 ******************************************************************************
 ** \defgroup WWDTGroup
 **
 ******************************************************************************/

/******************************************************************************/
/* Local function prototypes ('static')                                       */
/******************************************************************************/

/**
 ******************************************************************************
 ** \brief  WDT初始化函数
 **
 ** \param [in] pstcWwdtInit @ref stc_wwdt_init_t
 **
 ** \retval Ok
 **
 ******************************************************************************/
en_result_t WWDT_Init(stc_wwdt_init_t *pstcWwdtInit)
{
    REG_WRITE(WWDT->CR1, pstcWwdtInit->u32Prescaler  |\
                             pstcWwdtInit->u32PreOverInt |\
                             pstcWwdtInit->u32Window);
    
    REG_WRITE(WWDT->CR0, pstcWwdtInit->u32Counter);
    
    return Ok;
}

/**
 ******************************************************************************
 ** \brief  WWDT启动运行函数
 **
 ** \param [in] 无
 **
 ** \retval 无
 **
 ******************************************************************************/
void WWDT_Start(void)
{ 
    REG_SETBITS(WWDT->CR0, WWDT_CR0_EN);
}

/**
 ******************************************************************************
 ** \brief  WWDT 喂狗
 **
 ** \param [in] 无
 **
 ** \retval Ok
 **
 ******************************************************************************/
void WWDT_Feed(uint32_t u32Cnt)
{ 
    REG_WRITE(WWDT->CR0, WWDT_CR0_EN|u32Cnt);
}

/**
 ******************************************************************************
 ** \brief  WWDT预溢出标志清除
 **
 ** \param [in] 无
 **
 ** \retval Ok
 **
 ******************************************************************************/
void WWDT_ClearPreOverFlag(void)
{
    REG_CLEARBITS(WWDT->SR, WWDT_SR_POV);
}

/**
 ******************************************************************************
 ** \brief  IWDT预溢出标志获取
 **
 ** \param [in] 无
 **
 ** \retval TRUE or FALSE
 **
 ******************************************************************************/
boolean_t WWDT_GetPreOverFlag(void)
{
    if(REG_READBITS(WWDT->SR, WWDT_SR_POV))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/**
 ******************************************************************************
 ** \brief  WWDT 获取当前运行状态
 **
 ** \param [in] 无
 **
 ** \retval TRUE or FALSE
 **
 ******************************************************************************/
boolean_t WWDT_GetRunFlag(void)
{
    if(REG_READBITS(WWDT->CR0, WWDT_CR0_EN))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/**
 ******************************************************************************
 ** \brief  WWDT 获取当前计数值
 **
 ** \param [in] 无
 **
 ** \retval TRUE or FALSE
 **
 ******************************************************************************/
uint32_t WWDT_GetCnt(void)
{
    return REG_READBITS(WWDT->CR0, WWDT_CR0_WCNT);
}

/**
 ******************************************************************************
** \brief  WWDT 直接复位
 **
 ** \param [in] 无
 **
 ** \retval NULL
 **
 ******************************************************************************/
void WWDT_Reset(void)
{
    REG_WRITE(WWDT->CR0, 0);
}

//@} // WWDTGroup
