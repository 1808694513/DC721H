#ifndef __USER_LIGHT_H__
#define __USER_LIGHT_H__

#include "User_Include.h"

#define LIGHT_ON          GPIO_PD05_SET()
#define LIGHT_OFF         GPIO_PD05_RESET()

//状态值枚举 @ref Sta_Typedef
enum
{
    Light_Null_Sta = 0,   //空状态
    Light_ON_Sta,   //灯状态    打开
    Light_OFF_Sta,  //灯状态    关闭
};

typedef struct
{
    uint8_t     Next_Sta;   //空状态    @ref Sta_Typedef
    uint8_t     Now_Sta;    //当前状态  @ref Sta_Typedef
} Light_Status_Typedef;

//供外部使用
extern Light_Status_Typedef Light_Sta;


void User_Light_Init(void);
void Light_Run_Init(void);
void Light_Close_Handle(void);
void Light_Open_Handle(void);
void Light_Control_Handle(uint8_t Val);
void Light_Run_Sta_Handle(void);

#endif /* __USER_LIGHT_H__ */
