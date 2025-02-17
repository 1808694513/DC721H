#ifndef __USER_MOT_H__
#define __USER_MOT_H__

#include "User_Include.h"

#define M_DN_ON           GPIO_PA01_SET()
#define M_DN_OFF          GPIO_PA01_RESET()
#define M_UP_ON           GPIO_PA02_SET()
#define M_UP_OFF          GPIO_PA02_RESET()

#define MOT_Open          M_DN_OFF;M_UP_ON;
#define MOT_Close         M_DN_ON;M_UP_OFF;
#define MOT_Stop          M_DN_OFF;M_UP_OFF;

#define APPROACH_SWITCH   ((GPIO_PB05_READ() == GPIO_PIN_05) ? 1u : 0u)


#define MOT_OpenCloseDelayTime_Val      (500/10)                //电机打开关闭延时时间 500ms
#define MOT_MaxRunTime_Val              ((4*60000)/10)          //电机最大运行时间 4分钟

#define ApproachSwitch_XD_Time_Val      (50/5)                  //接近开关消抖时间 50ms

//状态值枚举 @ref Sta_Typedef
enum
{
    MOT_Null_Sta = 0u,          //空状态
    MOT_Open_Sta,               //MOT状态    打开
    MOT_Close_Sta,              //MOT状态    关闭
    DOT_MOT_Open_Sta,           //MOT状态    电动打开
    DOT_MOT_Close_Sta,          //MOT状态    电动关闭
    MOT_Stop_Sta,               //MOT停止
};

//电机状态结构体
typedef struct
{
    union
    {
        uint8_t Byte;
        struct
        {
            uint8_t ApproachSwitch_Flag     :1;         //接近开关使能位
            uint8_t FX                      :1;         //电机方向
            uint8_t Open_Limit              :1;         //电机打开限位(长按按住处理)
            uint8_t Close_Limit             :1;         //电机关闭限位(长按按住处理)
            uint8_t Close_Finish_Sta        :1;         //电机关闭完成状态(到位后自锁)
            uint8_t Open_Finish_Sta         :1;         //电机打开完成状态(到位后自锁)
            uint8_t Stop_Limit              :1;         //电机停止限位
            uint8_t Dot_Enable              :1;         //电动控制使能位
            //uint8_t                         :2;         //预留位
        };
    };

    uint8_t Now_Sta;        //当前状态  @ref Sta_Typedef
    uint8_t Next_Sta;       //下一状态  @ref Sta_Typedef
    uint8_t Last_Sta;       //上一状态  @ref Sta_Typedef

    uint16_t OpenCloseDelayTime;      //电机打开关闭延时时间
    uint16_t MaxRunTime;             //电机最大运行时间
    uint16_t ApproachSwitch_XD_Time;      //接近开关消抖时间

    uint16_t DOT_Flag;                //点动控制标志位
}MOT_Sta_TypeDef;

//供外部使用
extern MOT_Sta_TypeDef MOT_Sta;

void User_MOT_Init(void);
void MOT_MaxRunTime_Handle(void);
void MOT_Run_Sta_Handle(void);
void MOT_FX_Handle(uint8_t Val);
void MOT_UP_Handle(void);
void MOT_DOWN_Handle(void);
void MOT_STOP_Handle(void);
void Read_ApproachSwitch_Handle(void);

#endif /* __USER_MOT_H__ */
