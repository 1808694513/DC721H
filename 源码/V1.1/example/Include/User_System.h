#ifndef __USER_SYSTEM_H__
#define __USER_SYSTEM_H__

#include "User_Include.h"

typedef struct
{
    uint8_t Time_1ms_Flag;

    uint8_t Time_5ms;
    uint8_t Time_5ms_Flag;

    uint8_t Time_10ms;
    uint8_t Time_10ms_Flag;

    uint8_t Time_100ms;
    uint8_t Time_100ms_Flag;

    uint16_t Time_1s;
    uint8_t Time_1s_Flag;

    uint8_t updownButton_Flag;          //按键消抖
    uint8_t updownToggleSwitch_Flag;    //拨动开关消抖
} SystemTick_Time_Typedef;

//供外部使用
extern SystemTick_Time_Typedef SystemTick_Time;

void User_System_Init(void);

#endif /* __USER_SYSTEM_H__ */
