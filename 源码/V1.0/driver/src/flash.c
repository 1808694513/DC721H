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
 ** @file flash.c
 **
 ** @brief Source file for FLASH functions
 **
 ** @author MADS Team
 **
 ******************************************************************************/

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "flash.h"
/**
 *******************************************************************************
 ** \addtogroup FlashGroup
 ******************************************************************************/
//@{

/*******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/
#define FLASH_END_ADDR              (0x00007FFFu)
#define FLASH_BYPASS()              FLASH->BYPASS = 0x5A5A;\
                                    FLASH->BYPASS = 0xA5A5;
#define FLASH_IE_TRUE               (0x03)
#define FLASH_IE_FALSE              (0x00)

#define FLASH_TIMEOUT_INIT          (0xFFFFFFu)
#define FLASH_TIMEOUT_PGM           (0xFFFFFFu)
#define FLASH_TIMEOUT_ERASE         (0xFFFFFFu)

#define FLASH_LOCK_ALL              (0x0u)
#define FLASH_UNLOCK_ALL            (0xFFFFFFFFu)
/*******************************************************************************
 * Global variable definitions (declared in header file with 'extern')
 ******************************************************************************/

/*******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/
/**
 ******************************************************************************
 ** \brief FLASH OP
 **
 ** Flash 操作控制数据类型重定义
 ******************************************************************************/
typedef enum en_flash_op
{
    Read        = 0u,           ///<读配置值
    Program     = 1u,           ///<编程配置值
    SectorErase = 2u,           ///<扇区擦除配置值
    ChipErase   = 3u,           ///<全片擦除配置值
} en_flash_op_t;

/*******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/

/*******************************************************************************
 * Local function prototypes ('static')
 ******************************************************************************/
#define FLASH_FlashLockAll()        FLASH_FlashLockSet(FLASH_LOCK_ALL);
#define FLASH_FlashUnlockAll()      FLASH_FlashLockSet(FLASH_UNLOCK_ALL);
/*******************************************************************************
 * Function implementation - global ('extern') and local ('static')
 ******************************************************************************/

/**
 *****************************************************************************
 ** \brief FLASH 编程保护加锁
 ** \param [in] u32LockSector 扇区锁
 **
 ** \note u32LockSector 第n个bit为'0'时的加锁Sector范围为[4*n, 4*n + 3]
 **
 ** \retval None
 *****************************************************************************/
void FLASH_FlashLockSet(uint32_t u32LockSector)
{
    FLASH_BYPASS();
    REG_WRITE(FLASH->SLOCK, u32LockSector);

}

// /**
 // *****************************************************************************
 // ** \brief FLASH 编程保护加锁
 // **
 // **
 // ** \retval Null
 // *****************************************************************************/
// void FLASH_FlashLockAll(void)
// {
    // FLASH_BYPASS();
    // REG_WRITE(FLASH->SLOCK, FLASH_LOCK_ALL);

// }

// /**
 // *****************************************************************************
 // ** \brief FLASH 编程保护解锁
 // **
 // **
 // ** \retval Null
 // *****************************************************************************/
// void FLASH_FlashUnlockAll(void)
// {
    // FLASH_BYPASS();
    // REG_WRITE(FLASH->SLOCK, FLASH_UNLOCK_ALL);

// }

/**
 *****************************************************************************
 ** \brief FLASH 读等待周期设置
 ** \param [in]  enWaitCycle  插入FLASH读等待周期数枚举类型 @ref en_flash_waitcycle_t
 **
 ** \note FlashWaitCycle0 = 0u,       ///< 读等待周期设置为0-即读周期为1（当HCLK小于等于24MHz时）
 ** \note FlashWaitCycle1 = 1u,       ///< 读等待周期设置为1-即读周期为2（当HCLK大于24MHz时必须至少为1）
 ** \note FlashWaitCycle2 = 2u,       ///< 读等待周期设置为2-即读周期为3（当HCK大于48MHz时必须至少为2）
 **
 ** \retval  None
 *****************************************************************************/
void FLASH_WaitCycle(en_flash_waitcycle_t enWaitCycle)
{
    FLASH_BYPASS();
    REG_WRITE(FLASH->WAIT, enWaitCycle);
}

/**
 *****************************************************************************
 ** \brief FLASH 中断标志获取
 **
 **
 ** \param [in]  u32IrqTypeFlag          @ref FLASH_IntTypeFlag
 **
 ** \retval 中断标志
 *****************************************************************************/
uint32_t Flash_GetIntFlag(uint32_t u32IrqTypeFlag)
{
    return REG_READBITS(FLASH->IFR, u32IrqTypeFlag);
}

/**
 *****************************************************************************
 ** \brief Flash中断标志清除
 **
 **
 ** \param [in]  u32IrqTypeFlag          @ref FLASH_IntTypeFlag
 **
 ** \retval None
 *****************************************************************************/
void Flash_ClearIntFlag(uint32_t u32IrqTypeFlag)
{
    REG_CLEARBITS(FLASH->ICLR, u32IrqTypeFlag);
}

/**
 *****************************************************************************
 ** \brief Flash中断使能
 **
 **
 ** \param [in]  u32IrqTypeEnable          @ref FLASH_IntType
 **
 ** \retval None
 *****************************************************************************/
void FLASH_EnableIrq(uint32_t u32IrqTypeEnable)
{
    FLASH_BYPASS();
    REG_SETBITS(FLASH->CR, u32IrqTypeEnable);
}

/**
 *****************************************************************************
 ** \brief Flash中断禁止
 **
 **
 ** \param [in]  u32IrqTypeEnable          @ref FLASH_IntType
 **
 ** \retval None
 *****************************************************************************/
void FLASH_DisableIrq(uint32_t u32IrqTypeEnable)
{
    FLASH_BYPASS();
    REG_CLEARBITS(FLASH->CR, u32IrqTypeEnable);
}

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
en_result_t FLASH_DataVerify(uint8_t *pu8SrcAddr, uint8_t *pu8DstAddr, uint32_t u32Size)
{
    while(u32Size--)
    {
        if(*pu8DstAddr++ != *pu8SrcAddr++)
        {
            return Error;
        }
    }

    return Ok;
}


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
en_result_t FLASH_WriteByte(uint32_t u32Addr, uint8_t *pu8Data, uint32_t u32Len)
{
    en_result_t             enResult = Ok;
    volatile uint32_t       u32TimeOut = FLASH_TIMEOUT_PGM;
    uint8_t *pu8DstAddr = (uint8_t *)u32Addr;

    if (FLASH_END_ADDR < (u32Addr + u32Len -1))
    {
        enResult = ErrorInvalidParameter;
        return (enResult);
    }

    //busy?
    u32TimeOut = FLASH_TIMEOUT_PGM;
    while (REG_READBITS(FLASH->CR, FLASH_CR_BUSY))
    {
        if(0 == u32TimeOut--)
        {
            return ErrorTimeout;
        }
    }

    //set OP
    u32TimeOut = FLASH_TIMEOUT_PGM;
    while(Program != REG_READBITS(FLASH->CR, FLASH_CR_OP))
    {
        if(u32TimeOut--)
        {
            FLASH_BYPASS();
            REG_MODIFY(FLASH->CR, FLASH_CR_OP, Program);
        }
        else
        {
            return ErrorTimeout;
        }
    }

    //Flash 解锁
    FLASH_FlashUnlockAll();

    while(u32Len)
    {
        //write data
        *(pu8DstAddr++) = *pu8Data++;
        u32Len--;

        //busy?
        u32TimeOut = FLASH_TIMEOUT_PGM;
        while (REG_READBITS(FLASH->CR, FLASH_CR_BUSY))
        {
            if(0 == u32TimeOut--)
            {
                return ErrorTimeout;
            }
        }
    }

    //Flash 加锁
    FLASH_FlashLockAll();

    return (enResult);
}

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
en_result_t FLASH_WriteHalfWord(uint32_t u32Addr, uint16_t *pu16Data, uint32_t u32Len)
{
    en_result_t             enResult = Ok;
    volatile uint32_t       u32TimeOut = FLASH_TIMEOUT_PGM;
    uint16_t *pu16DstAddr = (uint16_t *)u32Addr;

    if (FLASH_END_ADDR < (u32Addr + u32Len -1))
    {
        enResult = ErrorInvalidParameter;
        return (enResult);
    }

    //busy?
    u32TimeOut = FLASH_TIMEOUT_PGM;
    while (REG_READBITS(FLASH->CR, FLASH_CR_BUSY))
    {
        if(0 == u32TimeOut--)
        {
            return ErrorTimeout;
        }
    }

    //set OP
    u32TimeOut = FLASH_TIMEOUT_PGM;
    while(Program != REG_READBITS(FLASH->CR, FLASH_CR_OP))
    {
        if(u32TimeOut--)
        {
            FLASH_BYPASS();
            REG_MODIFY(FLASH->CR, FLASH_CR_OP, Program);
        }
        else
        {
            return ErrorTimeout;
        }
    }

    //Flash 解锁
    FLASH_FlashUnlockAll();

    while(u32Len)
    {
        //write data
        *(pu16DstAddr++) = *pu16Data++;
        u32Len--;

        //busy?
        u32TimeOut = FLASH_TIMEOUT_PGM;
        while (REG_READBITS(FLASH->CR, FLASH_CR_BUSY))
        {
            if(0 == u32TimeOut--)
            {
                return ErrorTimeout;
            }
        }
    }

    //Flash 加锁
    FLASH_FlashLockAll();

    return (enResult);
}

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
en_result_t FLASH_WriteWord(uint32_t u32Addr, uint32_t *pu32Data, uint32_t u32Len)
{
    en_result_t             enResult = Ok;
    volatile uint32_t       u32TimeOut = FLASH_TIMEOUT_PGM;
    uint32_t *pu32DstAddr = (uint32_t *)u32Addr;

    if (FLASH_END_ADDR < (u32Addr + u32Len -1))
    {
        enResult = ErrorInvalidParameter;
        return (enResult);
    }

    //busy?
    u32TimeOut = FLASH_TIMEOUT_PGM;
    while (REG_READBITS(FLASH->CR, FLASH_CR_BUSY))
    {
        if(0 == u32TimeOut--)
        {
            return ErrorTimeout;
        }
    }

    //set OP
    u32TimeOut = FLASH_TIMEOUT_PGM;
    while(Program != REG_READBITS(FLASH->CR, FLASH_CR_OP))
    {
        if(u32TimeOut--)
        {
            FLASH_BYPASS();
            REG_MODIFY(FLASH->CR, FLASH_CR_OP, Program);
        }
        else
        {
            return ErrorTimeout;
        }
    }

    //Flash 解锁
    FLASH_FlashUnlockAll();

    while(u32Len)
    {
        //write data
        *(pu32DstAddr++) = *pu32Data++;
        u32Len--;

        //busy?
        u32TimeOut = FLASH_TIMEOUT_PGM;
        while (REG_READBITS(FLASH->CR, FLASH_CR_BUSY))
        {
            if(0 == u32TimeOut--)
            {
                return ErrorTimeout;
            }
        }
    }

    //Flash 加锁
    FLASH_FlashLockAll();

    return (enResult);
}


/**
 *****************************************************************************
 ** \brief FLASH 扇区擦除
 **
 ** FLASH 扇区擦除.
 **
 ** \param [in]  u32SectorAddr    所擦除扇区内的地址
 **
 ** \retval Ok                    擦除成功.
 ** \retval ErrorInvalidParameter FLASH地址无效
 ** \retval ErrorTimeout          操作超时
 *****************************************************************************/
en_result_t FLASH_SectorErase(uint32_t u32SectorAddr)
{
    en_result_t             enResult = Ok;
    volatile uint32_t       u32TimeOut = FLASH_TIMEOUT_ERASE;

    if (FLASH_END_ADDR < u32SectorAddr)
    {
        enResult = ErrorInvalidParameter;
        return (enResult);
    }

    //busy?
    u32TimeOut = FLASH_TIMEOUT_ERASE;
    while (TRUE == FLASH->CR_f.BUSY)
    {
        if(0 == u32TimeOut--)
        {
            return ErrorTimeout;
        }
    }

    //Flash 解锁
    FLASH_FlashUnlockAll();

    //set OP
    u32TimeOut = FLASH_TIMEOUT_ERASE;
    while(SectorErase != REG_READBITS(FLASH->CR, FLASH_CR_OP))
    {
        if(u32TimeOut--)
        {
            FLASH_BYPASS();
            REG_MODIFY(FLASH->CR, FLASH_CR_OP, SectorErase);
        }
        else
        {
            return ErrorTimeout;
        }
    }

    //write data
    *((volatile uint8_t*)u32SectorAddr) = 0;

    //busy?
    u32TimeOut = FLASH_TIMEOUT_ERASE;
    while (REG_READBITS(FLASH->CR, FLASH_CR_BUSY))
    {
        if(0 == u32TimeOut--)
        {
            return ErrorTimeout;
        }
    }

    //Flash 加锁
    FLASH_FlashLockAll();

    return (enResult);
}



/**
 *****************************************************************************
 ** \brief FLASH 全片擦除(该函数仅限RAM中运行！！！)
 **
 ** FLASH 全片擦除.
 **
 **
 ** \retval Ok              擦除成功.
 ** \retval ErrorTimeout    操作超时
 **
 *****************************************************************************/
en_result_t Flash_ChipErase(void)
{
    en_result_t             enResult = Ok;
    volatile uint32_t       u32TimeOut = FLASH_TIMEOUT_ERASE;

    //busy?
    u32TimeOut = FLASH_TIMEOUT_ERASE;
    while (REG_READBITS(FLASH->CR, FLASH_CR_BUSY))
    {
        if(0 == u32TimeOut--)
        {
            return ErrorTimeout;
        }
    }

    //set OP
    u32TimeOut = FLASH_TIMEOUT_ERASE;
    while(ChipErase != FLASH->CR_f.OP)
    {
        if(u32TimeOut--)
        {
            FLASH_BYPASS();
            REG_MODIFY(FLASH->CR, FLASH_CR_OP, ChipErase);
        }
        else
        {
            return ErrorTimeout;
        }
    }

    //Flash 解锁
    FLASH_FlashUnlockAll();

    //write data
    *((volatile uint8_t*)0) = 0;

    //busy?
    u32TimeOut = FLASH_TIMEOUT_ERASE;
    while (REG_READBITS(FLASH->CR, FLASH_CR_BUSY))
    {
        if(0 == u32TimeOut--)
        {
            return ErrorTimeout;
        }
    }

    //Flash 加锁
    FLASH_FlashLockAll();

    return (enResult);
}


//@} // FlashGroup

/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
