#ifndef __USER_BEEPLED_H__
#define __USER_BEEPLED_H__

#include "User_Include.h"

#define BEEP_ON           GPIO_PD03_RESET()
#define BEEP_OFF          GPIO_PD03_SET()

#define BeepLedDealyTime_Val    (600/100) //常亮状态下闪烁延时时间   100ms进一次

//BeepLed执行结构体
typedef struct
{
    uint8_t Enable;  //使能
    uint8_t Speed;  //速度  周期时间=Speed*100ms * 2
    uint32_t Time;   //总时间,次数   100ms进一次
    uint8_t Sta;    //开关状态

    uint16_t DelayTime;  //常亮状态下延时时间  单位ms
} BeepLed_Work_TypeDef;

//供外部使用
extern BeepLed_Work_TypeDef BeepLed_Work;

void User_BeepLed_Init(void);
void BeepLed_Set(uint8_t speed, uint32_t time);
void BeepLed_OFF(void);
void BeepLed_Handle(void);

#endif /* __USER_BEEPLED_H__ */
