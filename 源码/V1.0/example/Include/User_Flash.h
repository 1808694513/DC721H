#ifndef __USER_FLASH_H__
#define __USER_FLASH_H__

#include "User_Include.h"

#define Flash_Addr_Base                 0x4200              //Flash保存基地址
#define EE_Save_Sys0_Addr               0x00                //参数0保存地址
#define EE_Save_Sys1_Addr               0x04                //参数1保存地址 电机换向
#define EE_Save_Sys2_Addr               0x08                //参数2保存地址 遥控器地址存储缓冲区下标
#define EE_Save_RF433_Check_Addr        0x0C                //RF433对码地址码
#define EE_Save_RF433_Check_FLAG        0x10                //RF433对码标志位
#define EE_Save_RF433_Addr              0x20                //RF433地址码保存地址 0x20-0xC0 保存20*2*4位地址

//首次上电保存值
#define ERR_Once_Temp_Val               0xAA

//Flash保存结构体
typedef struct
{
    uint32_t Flash_Data[128];                    //Flash保存数据
    uint8_t  Flash_Flag;                         //Flash保存标志位
} FLASH_Save_TypeDef;

//供外部使用
extern FLASH_Save_TypeDef FLASH_Save;


void Flash_Write_Word(uint32_t addr, uint32_t data);
uint32_t Flash_Read_Word(uint32_t addr);
void Flash_Read_RF433_Handle(void);
void Flash_Write_Handle(void);
void Flash_PowerON_Read_Handle(void);

#endif /* __USER_FLASH_H__ */
