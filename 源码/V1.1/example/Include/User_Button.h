#ifndef __USER_BUTTON_H__
#define __USER_BUTTON_H__

#include "User_Include.h"

#define K1              ((GPIO_PC04_READ() == GPIO_PIN_04) ? 1u : 0u)
#define K2              ((GPIO_PC03_READ() == GPIO_PIN_03) ? 1u : 0u)
#define K3              ((GPIO_PB04_READ() == GPIO_PIN_04) ? 1u : 0u)
#define K4              ((GPIO_PD02_READ() == GPIO_PIN_02) ? 1u : 0u)
#define S1              ((GPIO_PC05_READ() == GPIO_PIN_05) ? 1u : 0u)     //预留
#define S2              ((GPIO_PC06_READ() == GPIO_PIN_06) ? 1u : 0u)     //预留

#define KEY1       	0x01    //UP
#define KEY2		0x02    //STOP
#define KEY3	    0x04    //DOWN
#define KEY4	    0x08    //SET
#define KEY5        (KEY1 | KEY3)   //电机换向 UP+DOWN
#define KEY6        (KEY1 | KEY2)   //电机点动 UP+STOP


#define Button_XD_Time_Val              50   //消抖总时间   50ms
#define Button_Count_Val                Button_XD_Time_Val / 1     //消抖1ms进入一次
#define ButtonLongDownRepeat_Time_Val   (100 / Button_XD_Time_Val)
#define ButtonLongDown_Time_Val         (2000 / Button_XD_Time_Val)
#define ButtonLongDown_Time_MAX_Val     (15000 / Button_XD_Time_Val)
#define ButtonDouble_Time_Val           (100 / Button_Count_Val)
extern uint8_t updownButton_Flag;
extern uint8_t Button_Shade_Finish;
extern uint8_t ButtonDown1_Flag;
extern uint8_t ButtonDown2_Flag;
extern uint8_t ButtonDown3_Flag;
extern uint8_t ButtonDown4_Flag;
extern uint8_t ButtonDown5_Flag;
extern uint8_t ButtonDown6_Flag;
extern uint8_t ButtonDown7_Flag;
extern uint8_t KEY_Now; // 按键当前值
extern uint8_t KEY_Before; // 按键之前值
extern uint16_t Button_Count;
extern uint16_t ButtonLongDown1_Flag;
extern uint16_t ButtonLongDown2_Flag;
extern uint16_t ButtonLongDown3_Flag;
extern uint16_t ButtonLongDown4_Flag;
extern uint16_t ButtonLongDown5_Flag;
extern uint16_t ButtonLongDown6_Flag;
extern uint16_t ButtonLongDown7_Flag;
extern uint16_t ButtonDouble1_Time;
extern uint8_t ButtonDouble1_Flag;

extern uint8_t ButtonLongDown_Count;

//拨动开关
#define K_S1		0x10
#define K_S2		0x20


#define Toggle_Switch_XD_Time_Val       50   //消抖总时间   50ms
#define Toggle_Switch_Count_Val         Toggle_Switch_XD_Time_Val / 1     //消抖1ms进入一次
extern uint8_t updownToggleSwitch_Flag;
extern uint8_t ToggleSwitchDown1_Flag;
extern uint8_t ToggleSwitchDown2_Flag;
extern uint8_t Toggle_Switch_Now;
extern uint8_t Toggle_Switch_Before;
extern uint16_t Toggle_Switch_Count;

void User_Button_Init(void);
void Button_Shade_Handle(void);
void Button_Handle(void);
void Toggle_Switch_Handle(void);//拨动开关处理

//===================================KEY功能========================================
void KEY1_Handle(void);
void KEY2_Handle(void);
void KEY3_Handle(void);
void KEY4_Handle(void);
void KEY5_Handle(void);
void KEY6_Handle(void);
//void KEY2_Long_Handle(void);
void KEY1_TQ_Handle(void);
void KEY3_TQ_Handle(void);
void KEY4_Long_Handle(uint8_t mode);
void KEY4_TQ_Handle(uint8_t mode);
void KEY_MOT_Handle(void);
void KEY6_Long_Handle(void);

void Switch_S1_ON_Handle(void);
void Switch_S1_OFF_Handle(void);
void Switch_S2_ON_Handle(void);
void Switch_S2_OFF_Handle(void);

#endif /* __USER_BUTTON_H__ */
