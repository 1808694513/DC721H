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
 ** @file interrupts_hc32f002.c
 **
 ** @brief Source file for INTERRUPTS functions
 **
 ** @author MADS Team 
 **
 ******************************************************************************/
/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "ddl.h"
#include "interrupts_hc32f002.h"

/*******************************************************************************
 *                       IRQ WEAK DEFINE
 ******************************************************************************/
__WEAK void SysTick_IRQHandler(void);

__WEAK void PortA_IRQHandler(void);
__WEAK void PortB_IRQHandler(void);
__WEAK void PortC_IRQHandler(void);
__WEAK void PortD_IRQHandler(void);
__WEAK void ATim3_IRQHandler(void);
__WEAK void LpUart0_IRQHandler(void);
__WEAK void LpUart1_IRQHandler(void);
__WEAK void Spi_IRQHandler(void);
__WEAK void I2c_IRQHandler(void);
__WEAK void GTim_IRQHandler(void);
__WEAK void BTim3_IRQHandler(void);
__WEAK void BTim4_IRQHandler(void);
__WEAK void BTim5_IRQHandler(void);
__WEAK void Iwdt_IRQHandler(void);
__WEAK void Wwdt_IRQHandler(void);
__WEAK void Adc_IRQHandler(void);
__WEAK void Lvd_IRQHandler(void);
__WEAK void Flash_IRQHandler(void);
__WEAK void Ctrim_IRQHandler(void);

/**
 *******************************************************************************
 ** \brief NVIC 中断使能
 **
 ** \param [in]  enIrq          中断号枚举类型
 ** \param [in]  enLevel        中断优先级枚举类型
 ** \param [in]  bEn            中断开关
 ** \retval    Ok       设置成功
 **            其他值   设置失败
 ******************************************************************************/
void EnableNvic(IRQn_Type enIrq, en_irq_level_t enLevel, boolean_t bEn)
{
    NVIC_ClearPendingIRQ(enIrq);
    NVIC_SetPriority(enIrq, enLevel);
    if (TRUE == bEn)
    {
        NVIC_EnableIRQ(enIrq);
    }
    else
    {
        NVIC_DisableIRQ(enIrq);
    }
}

/**
 *******************************************************************************
 ** \brief NVIC hardware fault 中断实现
 **
 **
 ** \retval
 ******************************************************************************/
void HardFault_Handler(void)
{
    volatile int a = 0;

    while( 0 == a)
    {
        ;
    }

}


/**
 *******************************************************************************
 ** \brief NVIC SysTick 中断实现
 **
 ** \retval
 ******************************************************************************/
void SysTick_Handler(void)
{
   SysTick_IRQHandler();
}

/**
 *******************************************************************************
 ** \brief GPIO PortA 中断处理函数
 **
 ** \retval
 ******************************************************************************/
void PORTA_IRQHandler(void)
{
#if (INT_CALLBACK_ON == INT_CALLBACK_PORTA)
    PortA_IRQHandler();
#endif
}

/**
 *******************************************************************************
 ** \brief GPIO PortB 中断处理函数
 **
 ** \retval
 ******************************************************************************/
void PORTB_IRQHandler(void)
{
#if (INT_CALLBACK_ON == INT_CALLBACK_PORTB)
    PortB_IRQHandler();
#endif
}

/**
 *******************************************************************************
 ** \brief GPIO PortC 中断处理函数
 **
 ** \retval
 ******************************************************************************/
void PORTC_IRQHandler(void)
{
#if (INT_CALLBACK_ON == INT_CALLBACK_PORTC)
    PortC_IRQHandler();
#endif
}

/**
 *******************************************************************************
 ** \brief GPIO PortD 中断处理函数
 **
 ** \retval
 ******************************************************************************/
void PORTD_IRQHandler(void)
{
#if (INT_CALLBACK_ON == INT_CALLBACK_PORTD)
    PortD_IRQHandler();
#endif
}

/**
 *******************************************************************************
 ** \brief ATIM3 中断处理函数
 **
 ** \retval
 ******************************************************************************/
void ATIM3_IRQHandler(void)
{
#if (INT_CALLBACK_ON == INT_CALLBACK_ATIM3)
    ATim3_IRQHandler();
#endif
}

/**
 *******************************************************************************
 ** \brief LPUART0 低功耗串口0 中断处理函数
 **
 ** \retval
 ******************************************************************************/
void LPUART0_IRQHandler(void)
{
#if (INT_CALLBACK_ON == INT_CALLBACK_LPUART0)
    LpUart0_IRQHandler();
#endif
}

/**
 *******************************************************************************
 ** \brief LPUART1 低功耗串口1 中断处理函数
 **
 ** \retval
 ******************************************************************************/
void LPUART1_IRQHandler(void)
{
#if (INT_CALLBACK_ON == INT_CALLBACK_LPUART1)
    LpUart1_IRQHandler();
#endif
}

/**
 *******************************************************************************
 ** \brief SPI 中断处理函数
 **
 ** \retval
 ******************************************************************************/
void SPI_IRQHandler(void)
{
#if (INT_CALLBACK_ON == INT_CALLBACK_SPI)
    Spi_IRQHandler();
#endif
}

/**
 *******************************************************************************
 ** \brief I2C 中断处理函数
 **
 ** \retval
 ******************************************************************************/
void I2C_IRQHandler(void)
{
#if (INT_CALLBACK_ON == INT_CALLBACK_I2C)
    I2c_IRQHandler();
#endif
}

/**
 *******************************************************************************
 ** \brief GTIM BTIM3/4/5 中断处理函数
 **
 ** \retval
 ******************************************************************************/
void GTIM_BTIM3_4_5_IRQHandler(void)
{
#if (INT_CALLBACK_ON == INT_CALLBACK_GTIM)
    GTim_IRQHandler();
#endif

#if (INT_CALLBACK_ON == INT_CALLBACK_BTIM3)
    BTim3_IRQHandler();
#endif

#if (INT_CALLBACK_ON == INT_CALLBACK_BTIM4)
    BTim4_IRQHandler();
#endif

#if (INT_CALLBACK_ON == INT_CALLBACK_BTIM5)
    BTim5_IRQHandler();
#endif
}

/**
 *******************************************************************************
 ** \brief IWDT/WWDT 中断处理函数
 **
 ** \retval
 ******************************************************************************/
void IWDT_WWDT_IRQHandler(void)
{
#if (INT_CALLBACK_ON == INT_CALLBACK_IWDT)
    Iwdt_IRQHandler();
#endif

#if (INT_CALLBACK_ON == INT_CALLBACK_WWDT)
    Wwdt_IRQHandler();
#endif
}

/**
 *******************************************************************************
 ** \brief ADC 中断处理函数
 **
 ** \retval
 ******************************************************************************/
void ADC_IRQHandler(void)
{
#if (INT_CALLBACK_ON == INT_CALLBACK_ADC)
    Adc_IRQHandler();
#endif
}

/**
 *******************************************************************************
 ** \brief LVD 中断处理函数
 **
 ** \retval
 ******************************************************************************/
void LVD_IRQHandler(void)
{
#if (INT_CALLBACK_ON == INT_CALLBACK_LVD)
    Lvd_IRQHandler();
#endif
}

/**
 *******************************************************************************
 ** \brief FLASH 中断处理函数
 **
 ** \retval
 ******************************************************************************/
void FLASH_IRQHandler(void)
{
#if (INT_CALLBACK_ON == INT_CALLBACK_FLASH)
    Flash_IRQHandler();
#endif
}

/**
 *******************************************************************************
 ** \brief CTRIM 中断处理函数
 **
 ** \retval
 ******************************************************************************/
void CTRIM_IRQHandler(void)
{
#if (INT_CALLBACK_ON == INT_CALLBACK_CTRIM)
    Ctrim_IRQHandler();
#endif
}

/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
