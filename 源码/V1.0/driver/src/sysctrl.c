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
 ** @file sysctrl.c
 **
 ** @brief Source file for SYSCTRL functions
 **
 ** @author MADS Team 
 **
 ******************************************************************************/

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "sysctrl.h"

/**
 *******************************************************************************
 ** \addtogroup SysctrlGroup
 ******************************************************************************/
//@{

/*******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/
#define CLK_TIMEOUT             (1000000u)

#define IS_VALID_SRC(x)         (   ClkRCH == (x)||\
                                    ClkXTH == (x)||\
                                    ClkRCL == (x)||\
                                    ClkXTL == (x) )


#define IS_VALID_FUNC(x)        (   ClkFuncWkupRCH == (x)||\
                                    ClkFuncXTHEn == (x)||\
                                    ClkFuncXTLEn == (x)||\
                                    ClkFuncXTLAWSON == (x)||\
                                    ClkFuncFaultEn == (x)||\
                                    ClkFuncRtcLPWEn == (x)||\
                                    ClkFuncLockUpEn == (x)||\
                                    ClkFuncRstPinIOEn == (x)||\
                                    ClkFuncSwdPinIOEn == (x) )

/*******************************************************************************
 * Global variable definitions (declared in header file with 'extern')
 ******************************************************************************/
extern uint32_t SystemCoreClock;
extern uint32_t SystemHCLK;
extern uint32_t SystemPCLK;
/*******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/*******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/
static const uint32_t au32RCHFreqTable[9] = {
                                              2u,
                                              4u,
                                              6u,
                                              8u,
                                              10u,
                                              12u,
                                              14u,
                                              16u,
                                              1u
                                            };

/*******************************************************************************
 * Local function prototypes ('static')
 ******************************************************************************/


/*******************************************************************************
 * Function implementation - global ('extern') and local ('static')
 ******************************************************************************/

/**
 *******************************************************************************
 ** \brief SYSCTRL->CR0/CR1/CR2寄存器操作解锁
 **
 ** \retval None
 ******************************************************************************/
void _SysctrlUnlock(void)
{
    SYSCTRL->CR3 = 0x5A5Au;
    SYSCTRL->CR3 = 0xA5A5u;
}

void _FlashUnlock(void)
{
    FLASH->BYPASS = 0x5A5Au;
    FLASH->BYPASS = 0xA5A5u;
}

void _SystemCoreClockUpdate(void)
{
    uint16_t u16RCL32p8, u16RCH44p24;
    u16RCL32p8  = SYSCTRL_RCL_TRIM_32p8KHz;
    u16RCH44p24 = SYSCTRL_RCH_TRIM_44p24MHz;

    ///< Update [SystemCoreClock]
    if(REG_READBITS(SYSCTRL->CR2, SYSCTRL_CR2_EXTCLKEN))
    {
        SystemHCLK = SYSTEM_EXTCLK;
    }
    
    if(SYSCTRL_SYSCLK_SOURCE_RCL == REG_READBITS(SYSCTRL->CR0, SYSCTRL_CR0_CLKSRC))
    {
        if(u16RCL32p8 == (REG_READBITS(SYSCTRL->RCL, SYSCTRL_RCL_TRIM)))
        {
            SystemHCLK = 32768;
        }
        else
        {
            SystemHCLK = 38400;
        }
    }

    if(SYSCTRL_SYSCLK_SOURCE_RCH == REG_READBITS(SYSCTRL->CR0, SYSCTRL_CR0_CLKSRC))
    {
        if(u16RCH44p24 == REG_READBITS(SYSCTRL->RCH, SYSCTRL_RCH_TRIM))
        {
            SystemHCLK = 44240000u;
        }
        else
        {
            SystemHCLK = 48000000u;
        }
        SystemHCLK = SystemHCLK / au32RCHFreqTable[REG_READBITS(SYSCTRL->RCH, SYSCTRL_RCH_DIV) >> SYSCTRL_RCH_DIV_Pos];

    }

    SystemHCLK = SystemHCLK >> (REG_READBITS(SYSCTRL->CR0, SYSCTRL_CR0_HCLKPRS) >> SYSCTRL_CR0_HCLKPRS_Pos);
}

/**
 ***********************************************************************************************
 ** \brief 系统时钟源初始化
 ** \param [in]  pstcSysClkSrc 系统时钟源配置结构体指针 @ref stc_sysctrl_sysclk_source_init_t
 **
 ** \retval @ref en_result_t
 ***********************************************************************************************/
en_result_t SYSCTRL_SysClkSrcInit(stc_sysctrl_sysclk_source_init_t *pstcSysClkSrc)
{
    ///< RCH Configuration
    if(pstcSysClkSrc->u32SysClkSourceType & SYSCTRL_SYSCLK_SOURCE_TYPE_RCH)
    {
        if(SYSCTRL_RCH_DIV1 & pstcSysClkSrc->u32RCHState)
        {
            _FlashUnlock();
            REG_MODIFY(FLASH->WAIT, FLASH_WAIT_WAIT, SYSCTRL_FLASH_WAIT_CYCLE2);
        }

        REG_WRITE(SYSCTRL->RCH, pstcSysClkSrc->u32RCHState);
        _SysctrlUnlock();
        REG_SETBITS(SYSCTRL->CR2, SYSCTRL_CR2_RCHEN);
        while(FALSE == !!REG_READBITS(SYSCTRL->RCH, SYSCTRL_RCH_STABLE)){;}
    }

    ///< RCL Configuration
    if(pstcSysClkSrc->u32SysClkSourceType & SYSCTRL_SYSCLK_SOURCE_TYPE_RCL)
    {
        REG_WRITE(SYSCTRL->RCL, pstcSysClkSrc->u32RCLState);
        _SysctrlUnlock();
        REG_SETBITS(SYSCTRL->CR2, SYSCTRL_CR2_RCLEN);
        while(FALSE == !!REG_READBITS(SYSCTRL->RCL, SYSCTRL_RCL_STABLE)){;}
    }

    return Ok;
}

/**
 ***********************************************************************************************
 ** \brief 系统时钟初始化
 ** \param [in]  pstcSysClk 系统时钟配置结构体指针 @ref stc_sysctrl_clk_init_t
 **
 ** \retval @ref en_result_t
 ***********************************************************************************************/
en_result_t SYSCTRL_SysClkInit(stc_sysctrl_clk_init_t *pstcSysClk)
{
    ///< PCLK = HCLK / DIV
    if(pstcSysClk->u32ClockType & SYSCTRL_CLOCKTYPE_PCLK)
    {
        _SysctrlUnlock();
        REG_MODIFY(SYSCTRL->CR0, SYSCTRL_CR0_PCLKPRS, pstcSysClk->u32PClkDiv);
    }

    ///< HCLK = SYSCLK / DIV
    if(pstcSysClk->u32ClockType & SYSCTRL_CLOCKTYPE_HCLK)
    {
        _SysctrlUnlock();
        REG_MODIFY(SYSCTRL->CR0, SYSCTRL_CR0_HCLKPRS, pstcSysClk->u32HClkDiv);
    }

    if(pstcSysClk->u32WaitCycle >= (REG_READBITS(FLASH->WAIT, FLASH_WAIT_WAIT) >> FLASH_WAIT_WAIT_Pos))
    {
        _FlashUnlock();
        REG_MODIFY(FLASH->WAIT, FLASH_WAIT_WAIT, pstcSysClk->u32WaitCycle);
    }

    ///< System Clock Source
    if(pstcSysClk->u32ClockType & SYSCTRL_CLOCKTYPE_SYSCLK)
    {
        if(SYSCTRL_SYSCLK_SOURCE_EXTCLK == pstcSysClk->u32SysClkSource)
        {
            _SysctrlUnlock();
            REG_SETBITS(SYSCTRL->CR2, SYSCTRL_CR2_EXTCLKEN);
        }
        else
        {
            _SysctrlUnlock();
            REG_MODIFY(SYSCTRL->CR0, SYSCTRL_CR0_CLKSRC, pstcSysClk->u32SysClkSource);
            _SysctrlUnlock();
            REG_CLEARBITS(SYSCTRL->CR2, SYSCTRL_CR2_EXTCLKEN);
        }

    }
    

    if(pstcSysClk->u32WaitCycle < (REG_READBITS(FLASH->WAIT, FLASH_WAIT_WAIT) >> FLASH_WAIT_WAIT_Pos))
    {
        _FlashUnlock();
        REG_MODIFY(FLASH->WAIT, FLASH_WAIT_WAIT, pstcSysClk->u32WaitCycle);
    }

    _SystemCoreClockUpdate();

    SystemCoreClock = SystemHCLK;
    return Ok;

}


/**
 ***********************************************************************************************
 ** \brief 系统时钟 HCLK 频率获取
 ** \param None

 ** \retval HCLK频率值(Hz)
 ***********************************************************************************************/
uint32_t SYSCTRL_GetHCLK(void)
{
    _SystemCoreClockUpdate();

    return SystemHCLK;
}

/**
 ***********************************************************************************************
 ** \brief 系统时钟 PCLK 频率获取
 ** \param None

 ** \retval PCLK频率值(Hz)
 ***********************************************************************************************/
uint32_t SYSCTRL_GetPCLK(void)
{
    _SystemCoreClockUpdate();

    return (SystemHCLK >> (REG_READBITS(SYSCTRL->CR0, SYSCTRL_CR0_PCLKPRS) >> SYSCTRL_CR0_PCLKPRS_Pos));
}


/**
 ***********************************************************************************************
 ** \brief 系统功能使能————系统控制其他功能使能
 ** \param [in]  u32SysctrlFunction   系统功能宏定义 @ref Sysctrl_Function_Ctrl

 ** \retval NULL
 ***********************************************************************************************/
void SYSCTRL_FuncEnable(uint32_t u32SysctrlFunction)
{
    if(_CR2_MSK&u32SysctrlFunction)
    {
        u32SysctrlFunction = u32SysctrlFunction & (~_CR2_MSK);
        _SysctrlUnlock();
        REG_SETBITS(SYSCTRL->CR2, u32SysctrlFunction);
    }
    else
    {
        _SysctrlUnlock();
        REG_SETBITS(SYSCTRL->CR1, u32SysctrlFunction);
    }

}

/**
 ***********************************************************************************************
 ** \brief 系统功能禁止————系统控制其他功能禁止
 ** \param [in]  u32SysctrlFunction   系统功能宏定义 @ref Sysctrl_Function_Ctrl

 ** \retval NULL
 ***********************************************************************************************/
void SYSCTRL_FuncDisable(uint32_t u32SysctrlFunction)
{
    if(_CR2_MSK&u32SysctrlFunction)
    {
        u32SysctrlFunction = u32SysctrlFunction & (~_CR2_MSK);
        _SysctrlUnlock();
        REG_CLEARBITS(SYSCTRL->CR2, u32SysctrlFunction);
    }
    else
    {
        _SysctrlUnlock();
        REG_CLEARBITS(SYSCTRL->CR1, u32SysctrlFunction);
    }

}

/**
 ***********************************************************************************************
 ** \brief 系统外设时钟控制使能
 ** \param [in]  u32PeriphClk 系统外设时钟 @ref Sysctrl_Periph_Clock

 ** \retval None
 ***********************************************************************************************/
void SYSCTRL_PeriphClkEnable(uint32_t u32PeriphClk)
{
    if(_PERICLK_REG1_MSK&u32PeriphClk)
    {
        u32PeriphClk = u32PeriphClk & (~_PERICLK_REG1_MSK);
        REG_SETBITS(SYSCTRL->PERICLKEN1, u32PeriphClk);
    }
    else
    {
        REG_SETBITS(SYSCTRL->PERICLKEN0, u32PeriphClk);
    }

}


/**
 ***********************************************************************************************
 ** \brief 系统外设时钟控制禁止
 ** \param [in]  u32PeriphClk 系统外设时钟 @ref Sysctrl_Periph_Clock

 ** \retval None
 ***********************************************************************************************/
void SYSCTRL_PeriphClkDisable(uint32_t u32PeriphClk)
{
    if(_PERICLK_REG1_MSK&u32PeriphClk)
    {
        u32PeriphClk = u32PeriphClk & (~_PERICLK_REG1_MSK);
        REG_CLEARBITS(SYSCTRL->PERICLKEN1, u32PeriphClk);
    }
    else
    {
        REG_CLEARBITS(SYSCTRL->PERICLKEN0, u32PeriphClk);
    }

}

/**
 ***********************************************************************************************
 ** \brief 系统外设复位
 ** \param [in]  u32PeriphReset 系统外设复位 @ref Sysctrl_Periph_Reset

 ** \retval None
 ***********************************************************************************************/
void SYSCTRL_PeriphReset(uint32_t u32PeriphReset)
{
    if(_PERICLK_REG1_MSK&u32PeriphReset)
    {
        u32PeriphReset = u32PeriphReset & (~_PERIRESET_REG1_MSK);
        REG_CLEARBITS(SYSCTRL->PERIRESET1, u32PeriphReset);
        REG_SETBITS(SYSCTRL->PERIRESET1, u32PeriphReset);
    }
    else
    {
        REG_CLEARBITS(SYSCTRL->PERIRESET0, u32PeriphReset);
        REG_SETBITS(SYSCTRL->PERIRESET0, u32PeriphReset);
    }

}


/**
 ***********************************************************************************************
 ** \brief 系统复位标志清除
 ** \param [in]  u32ResetFlag 系统复位标志 @ref Sysctrl_Reset_Flag

 ** \retval None
 ***********************************************************************************************/
void SYSCTRL_ResetFlagClear(uint32_t u32ResetFlag)
{
    REG_CLEARBITS(SYSCTRL->RESETFLAG, u32ResetFlag);
}


/**
 ***********************************************************************************************
 ** \brief 系统复位标志获取
 ** \param [in]  u32ResetFlag 系统复位标志 @ref Sysctrl_Reset_Flag

 ** \retval 复位标志
 ***********************************************************************************************/
uint32_t SYSCTRL_ResetFlagGet(uint32_t u32ResetFlag)
{
    return REG_READBITS(SYSCTRL->RESETFLAG, u32ResetFlag);
}

/**
 ***********************************************************************************************
 ** \brief 系统调试功能控制使能
 ** \param [in]  u32DebugModule 系统复位标志 @ref Sysctrl_Debug_Module

 ** \retval None
 ***********************************************************************************************/
void SYSCTRL_DebugEnable(uint32_t u32DebugModule)
{
    REG_SETBITS(SYSCTRL->DEBUGACTIVE, u32DebugModule);
}

/**
 ***********************************************************************************************
 ** \brief 系统调试功能控制禁止
 ** \param [in]  u32DebugModule 系统复位标志 @ref Sysctrl_Debug_Module

 ** \retval None
 ***********************************************************************************************/
void SYSCTRL_DebugDisable(uint32_t u32DebugModule)
{
    REG_CLEARBITS(SYSCTRL->DEBUGACTIVE, u32DebugModule);
}

/**
 ***********************************************************************************************
 ** \brief 获取芯片相关信息
 ** \param [in]  pstcChipInfo 芯片信息结构体指针 @ref stc_sysctrl_chip_info_t

 ** \retval None
 ***********************************************************************************************/
void SYSCTRL_GetChipInfo(stc_sysctrl_chip_info_t *pstcChipInfo)
{
    pstcChipInfo->pu8UID          = (uint8_t*)0x00101080;
    pstcChipInfo->pcProductNumber = (char_t*)0x00100D90;
    pstcChipInfo->u32FlashSize    = *((uint32_t*)0x00100DB0);
    pstcChipInfo->u32RamSize      = *((uint32_t*)0x00100DB4);
    pstcChipInfo->u16PinsCounter  = *((uint16_t*)0x00100DBA);        
}


//@} // SysctrlGroup

/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
