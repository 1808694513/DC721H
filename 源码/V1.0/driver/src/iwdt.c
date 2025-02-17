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
 ** @file iwdt.c
 **
 ** @brief Source file for IWDT functions
 **
 ** @author MADS Team 
 **
 ******************************************************************************/

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "iwdt.h"

/**
 ******************************************************************************
 ** \defgroup IWDTGroup
 **
 ******************************************************************************/
#define IWDT_KEY_VALUE              (0x5555U)
#define IWDT_KEY_START_VALUE        (0xCCCCU)
#define IWDT_KEY_RELOAD_VALUE       (0xAAAAU)
#define IWDT_KEY_STOP_BYPASS_1234   (0x1234U)
#define IWDT_KEY_STOP_BYPASS_5678   (0x5678U)
/******************************************************************************/
/* Local function prototypes ('static')                                       */
/******************************************************************************/

/**
 ******************************************************************************
 ** \brief  IWDT初始化函数
 **
 ** \param [in] pstcIwdtInit @ref stc_iwdt_init_t
 **
 ** \retval Ok
 **
 ******************************************************************************/
en_result_t IWDT_Init(stc_iwdt_init_t *pstcIwdtInit)
{
    REG_WRITE(IWDT->KR, IWDT_KEY_START_VALUE);
    REG_WRITE(IWDT->KR, IWDT_KEY_VALUE);
    while(REG_READBITS(IWDT->SR, IWDT_SR_PRSF|IWDT_SR_ARRF|IWDT_SR_WINRF)){;}
        
    REG_WRITE(IWDT->CR, pstcIwdtInit->u32Action |\
                            pstcIwdtInit->u32Prescaler);
    while(REG_READBITS(IWDT->SR, IWDT_SR_PRSF)){;}
    
    REG_WRITE(IWDT->ARR, pstcIwdtInit->u32ArrCounter);
    while(REG_READBITS(IWDT->SR, IWDT_SR_ARRF)){;}
    
    REG_WRITE(IWDT->WINR, pstcIwdtInit->u32Window);
    while(REG_READBITS(IWDT->SR, IWDT_SR_WINRF)){;}
    
    REG_WRITE(IWDT->KR, IWDT_KEY_RELOAD_VALUE);
    
    while(!REG_READBITS(IWDT->SR, IWDT_SR_RUN)){;}
    
    return Ok;
}

/**
 ******************************************************************************
 ** \brief  IWDT启动运行函数
 **
 ** \param [in] 无
 **
 ** \retval 无
 **
 ******************************************************************************/
void IWDT_Start(void)
{ 
    REG_WRITE(IWDT->KR, IWDT_KEY_START_VALUE);
}

/**
 ******************************************************************************
 ** \brief  IWDT停止运行函数
 **
 ** \param [in] 无
 **
 ** \retval 无
 **
 ******************************************************************************/
void IWDT_Stop(void)
{ 
    REG_WRITE(IWDT->KR, IWDT_KEY_STOP_BYPASS_1234);
    REG_WRITE(IWDT->KR, IWDT_KEY_STOP_BYPASS_5678);
}

/**
 ******************************************************************************
 ** \brief  IWDT 喂狗
 **
 ** \param [in] 无
 **
 ** \retval Ok
 **
 ******************************************************************************/
void IWDT_Feed(void)
{ 
    REG_WRITE(IWDT->KR, IWDT_KEY_RELOAD_VALUE);
}

/**
 ******************************************************************************
 ** \brief  IWDT溢出标志清除
 **
 ** \param [in] 无
 **
 ** \retval Ok
 **
 ******************************************************************************/
void IWDT_ClearOverFlag(void)
{
    REG_CLEARBITS(IWDT->SR, IWDT_SR_OV);
}

/**
 ******************************************************************************
 ** \brief  IWDT溢出标志获取
 **
 ** \param [in] 无
 **
 ** \retval TRUE or FALSE
 **
 ******************************************************************************/
boolean_t IWDT_GetOverFlag(void)
{
    if(REG_READBITS(IWDT->SR, IWDT_SR_OV))
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
 ** \brief  IWDT 获取当前运行状态
 **
 ** \param [in] 无
 **
 ** \retval TRUE or FALSE
 **
 ******************************************************************************/
boolean_t IWDT_GetRunFlag(void)
{
    if(REG_READBITS(IWDT->SR, IWDT_SR_RUN))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


//@} // IWDT Group
