#include "User_Light.h"

Light_Status_Typedef Light_Sta;

//****************************************************************
//功能描述：Light 初始化
//输入参数：无
//返 回 值：无
//****************************************************************
void User_Light_Init(void)
{
	stc_gpio_init_t stcGpioInit = {0};

    ///< 外设时钟使能
    SYSCTRL_PeriphClkEnable(SYSCTRL_PERICLK_PD);

    //开始状态
    LIGHT_OFF;

	//IO初始化
    stcGpioInit.u32Mode = GPIO_MODE_OUTPUT_PP;
    stcGpioInit.u32Pin = GPIO_PIN_05;
    stcGpioInit.u32Pull = GPIO_PULL_NONE;
	GPIOD_Init(&stcGpioInit);

    //参数初始化
    Light_Sta.Now_Sta = Light_OFF_Sta;
    Light_Sta.Next_Sta = Light_Null_Sta;
}

//****************************************************************
//功能描述：Light 操作前数据初始化处理
//输入参数：无
//返 回 值：无
//****************************************************************
void Light_Run_Init(void)
{
    if(Light_Sta.Now_Sta == Light_ON_Sta)
    {
        LIGHT_ON;
    }
    else if(Light_Sta.Now_Sta == Light_OFF_Sta)
    {
        LIGHT_OFF;
    }
}


//****************************************************************
//功能描述：Light 关闭处理
//输入参数：无
//返 回 值：无
//****************************************************************
void Light_Close_Handle(void)
{
    Light_Sta.Now_Sta = Light_OFF_Sta;
    Light_Run_Init();

    //Wifi
//    if(Tuya_Sta.Wifi_Finish_Flag == 1u)//Wifi连接成功
//    {
//        Tuya_Sta.Check_Flag = 1u;
//        Tuya_Sta.Wifi_Report_Time = 0u;
//    }
}

//****************************************************************
//功能描述：Light 打开处理
//输入参数：无
//返 回 值：无
//****************************************************************
void Light_Open_Handle(void)
{
    Light_Sta.Now_Sta = Light_ON_Sta;
    Light_Run_Init();

    //Wifi
//    if(Tuya_Sta.Wifi_Finish_Flag == 1u)//Wifi连接成功
//    {
//        Tuya_Sta.Check_Flag = 1u;
//        Tuya_Sta.Wifi_Report_Time = 0u;
//    }
}

//****************************************************************
//功能描述：Light 控制处理
//输入参数：Val 0:关闭 1:打开 2:切换
//返 回 值：无
//****************************************************************
void Light_Control_Handle(uint8_t Val)
{

    if(Val == 0u)
    {
        Light_Sta.Next_Sta = Light_OFF_Sta;
    }
    else if(Val == 1u)
    {
        Light_Sta.Next_Sta = Light_ON_Sta;
    }
    else if(Val == 2u)
    {
        if(Light_Sta.Now_Sta == Light_ON_Sta)
        {
            Light_Sta.Next_Sta = Light_OFF_Sta;
        }
        else
        {
            Light_Sta.Next_Sta = Light_ON_Sta;
        }
    }

}

//****************************************************************
//功能描述：Light 运行状态处理    (10ms运行一次)
//输入参数：无
//返 回 值：无
//****************************************************************
void Light_Run_Sta_Handle(void)
{
    switch(Light_Sta.Now_Sta)
    {
        case Light_OFF_Sta:
            if(Light_Sta.Next_Sta == Light_ON_Sta)
            {
                Light_Open_Handle();
                Light_Sta.Next_Sta = Light_Null_Sta;
            }
            break;
        case Light_ON_Sta:
            if(Light_Sta.Next_Sta == Light_OFF_Sta)
            {
                Light_Close_Handle();
                Light_Sta.Next_Sta = Light_Null_Sta;
            }
            break;
        default:
            break;
    }
}
