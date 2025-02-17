#include "User_BeepLed.h"

BeepLed_Work_TypeDef BeepLed_Work;

//****************************************************************
//功能描述：LED、BEEP 初始化
//输入参数：无
//返 回 值：无
//****************************************************************
void User_BeepLed_Init(void)
{
	stc_gpio_init_t stcGpioInit = {0};

    ///< 外设时钟使能
    SYSCTRL_PeriphClkEnable(SYSCTRL_PERICLK_PD);

    //开始状态
    BEEP_OFF;

	//IO初始化
    stcGpioInit.u32Mode = GPIO_MODE_OUTPUT_PP;
    stcGpioInit.u32Pin = GPIO_PIN_03;
    stcGpioInit.u32Pull = GPIO_PULL_NONE;
	GPIOD_Init(&stcGpioInit);
    
    

    //参数初始化
    BeepLed_Work.Speed = 0u;
    BeepLed_Work.Time = 0u;
    BeepLed_Work.Enable = 0u;
}

//****************************************************************
//功能描述：LED、BEEP 设置
//输入参数：speed 响应速度; 为1则100ms亮100ms灭
//         time 总时间,次数 100ms进入一次;
//          若响应速度为 0 ，则为长亮或长响
//返 回 值：无
//****************************************************************
void BeepLed_Set(uint8_t speed, uint32_t time)
{
    BeepLed_Work.Speed = speed;
    BeepLed_Work.Time = time;
    BeepLed_Work.Enable = 1u;
}

//****************************************************************
//功能描述：LED、BEEP 关闭
//输入参数：无
//返 回 值：无
//****************************************************************
void BeepLed_OFF(void)
{
    BeepLed_Work.Enable = 0u;
    BEEP_OFF;
}

//****************************************************************
//功能描述：LED、BEEP 控制  100ms调用一次
//输入参数：无
//返 回 值：无
//****************************************************************
void BeepLed_Handle(void)
{
    static uint8_t speed=0u;
    // if(BeepLed_Work.DelayTime > 0u)
    // {
    //     if(--BeepLed_Work.DelayTime == 0u)
    //     {
    //         BeepLed_Set(0u,100u);
    //     }
    // }
    if(BeepLed_Work.Enable == 0u) return;

    if(BeepLed_Work.Speed == 0u)
    {
        BEEP_ON;
        if(--BeepLed_Work.Time == 0u)
        {
            BeepLed_Work.Enable = 0u;
            BEEP_OFF;
        }
    }
    else
    {
        if(speed >= BeepLed_Work.Speed)
        {
            speed = 0u;
            if(BeepLed_Work.Sta == 1u)
            {
                BEEP_OFF;
                BeepLed_Work.Sta = 0u;
                if(BeepLed_Work.Time == 0u)
                {
                    BeepLed_Work.Enable = 0u;
                }
            }
            else
            {
                BEEP_ON;
                BeepLed_Work.Sta = 1u;
                BeepLed_Work.Time--;
            }
        }
        speed++;
    }
}
