#include "User_MOT.h"

MOT_Sta_TypeDef MOT_Sta;

//****************************************************************
//功能描述：MOT 初始化
//输入参数：无
//返 回 值：无
//****************************************************************
void User_MOT_Init(void)
{
	stc_gpio_init_t stcGpioInit = {0};

    ///< 外设时钟使能
    SYSCTRL_PeriphClkEnable(SYSCTRL_PERICLK_PA);
    SYSCTRL_PeriphClkEnable(SYSCTRL_PERICLK_PB);
    //开始状态
    M_DN_OFF;
    M_UP_OFF;
	//IO初始化
    stcGpioInit.u32Mode = GPIO_MODE_OUTPUT_PP;
    stcGpioInit.u32Pin = GPIO_PIN_01 | GPIO_PIN_02;
    stcGpioInit.u32Pull = GPIO_PULL_NONE;
	GPIOA_Init(&stcGpioInit);
    stcGpioInit.u32Mode = GPIO_MODE_INPUT;
    stcGpioInit.u32Pin = GPIO_PIN_05;
    GPIOB_Init(&stcGpioInit);

    //参数初始化
    MOT_Sta.Now_Sta = MOT_Stop_Sta;
    MOT_Sta.Next_Sta = MOT_Null_Sta;
    MOT_Sta.Last_Sta = MOT_Null_Sta;
    MOT_Sta.Open_Limit = 0u;
    MOT_Sta.Close_Limit = 0u;   //电机打开关闭长按按住自锁
}

//****************************************************************
//功能描述：MOT 最大运行时间控制     (10ms运行一次)
//输入参数：无
//返 回 值：无
//****************************************************************
void MOT_MaxRunTime_Handle(void)
{
    if(MOT_Sta.Now_Sta != MOT_Stop_Sta)     //4分钟保护
    {
        if(MOT_Sta.MaxRunTime > 0)
        {
            if(--MOT_Sta.MaxRunTime == 0)
            {
                //关输出
                MOT_Sta.Next_Sta = MOT_Stop_Sta;
                if(MOT_Sta.Now_Sta == MOT_Close_Sta)
                {
                    MOT_Sta.Close_Finish_Sta = 1u;
                    MOT_Sta.Open_Finish_Sta = 0u;
                }
                else if(MOT_Sta.Now_Sta == MOT_Open_Sta)
                {
                    MOT_Sta.Open_Finish_Sta = 1u;
                    MOT_Sta.Close_Finish_Sta = 0u;
                }
            }
        }
    }
}

//****************************************************************
//功能描述：MOT 运行状态处理    (10ms运行一次)
//输入参数：无
//返 回 值：无
//****************************************************************
void MOT_Run_Sta_Handle(void)
{
    switch(MOT_Sta.Now_Sta)
    {
        case MOT_Open_Sta:
            if(MOT_Sta.Next_Sta == MOT_Close_Sta)
            {
                MOT_Stop;
                MOT_Sta.OpenCloseDelayTime = MOT_OpenCloseDelayTime_Val;
                MOT_Sta.Now_Sta = MOT_Close_Sta;
                MOT_Sta.Next_Sta = MOT_Null_Sta;
                MOT_Sta.MaxRunTime = MOT_MaxRunTime_Val;
            }
            else if(MOT_Sta.Next_Sta == MOT_Stop_Sta)
            {
                MOT_Sta.Now_Sta = MOT_Stop_Sta;
            }
            if(MOT_Sta.OpenCloseDelayTime == 0u)
            {
//                if(MOT_Sta.FX == 0u)
//                {
                    MOT_Open;

//                }
//                else
//                {
//                    MOT_Close;
//                }
            }
            else
            {
               if(--MOT_Sta.OpenCloseDelayTime == 0u)
               {
                //    ADC_I_Sta.MOT_DelayTime = ADC_MOT_DelayTime;//电流延时检测
               }
            }
            break;
        case MOT_Close_Sta:
            if(MOT_Sta.Next_Sta == MOT_Open_Sta)
            {
                MOT_Stop;
                MOT_Sta.OpenCloseDelayTime = MOT_OpenCloseDelayTime_Val;
                MOT_Sta.Now_Sta = MOT_Open_Sta;
                MOT_Sta.Next_Sta = MOT_Null_Sta;
                MOT_Sta.MaxRunTime = MOT_MaxRunTime_Val;
            }
            else if(MOT_Sta.Next_Sta == MOT_Stop_Sta)
            {
                MOT_Sta.Now_Sta = MOT_Stop_Sta;
            }
            if(MOT_Sta.OpenCloseDelayTime == 0u)
            {
//                if(MOT_Sta.FX == 0u)
//                {
                    MOT_Close;
//                }
//                else
//                {
//                    MOT_Open;
//                }
            }
            else
            {
               if(--MOT_Sta.OpenCloseDelayTime == 0u)
               {
                //    ADC_I_Sta.MOT_DelayTime = ADC_MOT_DelayTime;//电流延时检测
               }
            }
            break;
        case MOT_Stop_Sta:
            if(MOT_Sta.Next_Sta == MOT_Open_Sta)
            {
                MOT_Sta.Now_Sta = MOT_Open_Sta;
                MOT_Sta.Next_Sta = MOT_Null_Sta;
            }
            else if(MOT_Sta.Next_Sta == MOT_Close_Sta)
            {
                MOT_Sta.Now_Sta = MOT_Close_Sta;
                MOT_Sta.Next_Sta = MOT_Null_Sta;
            }

            MOT_Stop;
            MOT_Sta.OpenCloseDelayTime = 0u;
            MOT_Sta.MaxRunTime = 0u;

            MOT_Sta.MaxRunTime = MOT_MaxRunTime_Val;//输出延时保护

            break;
    }
}

//****************************************************************
//功能描述：MOT 换向处理    (按键控制)
//输入参数：无
//返 回 值：无
//****************************************************************
void MOT_FX_Handle(uint8_t Val)
{
    if(Val == 0u)
        MOT_Sta.FX = 0u;
    else if(Val == 1u)
        MOT_Sta.FX = 1u;
    else
        MOT_Sta.FX = MOT_Sta.FX != 1u ? 1u : 0u;
    
    MOT_Sta.Open_Finish_Sta = 0u;
    MOT_Sta.Close_Finish_Sta = 0u;
    
    FLASH_Save.Flash_Flag = 1u;
}

//****************************************************************
//功能描述：MOT 上行处理    (按键控制)
//输入参数：无
//返 回 值：无
//****************************************************************
void MOT_UP_Handle(void)
{
    if(MOT_Sta.Open_Finish_Sta == 0u)  //电机打开没有到位
    {
        if(MOT_Sta.FX == 0u){
            MOT_Sta.Next_Sta = MOT_Open_Sta;
        }else{
            MOT_Sta.Next_Sta = MOT_Close_Sta;
        }
        MOT_Sta.OpenCloseDelayTime = 0u;
//        ADC_I_Sta.MOT_DelayTime = ADC_MOT_DelayTime;//电流延时检测
    }
    MOT_Sta.Close_Finish_Sta = 0u;

}

//****************************************************************
//功能描述：MOT 下行处理    (按键控制)
//输入参数：无
//返 回 值：无
//****************************************************************
void MOT_DOWN_Handle(void)
{
    if(MOT_Sta.Close_Finish_Sta == 0u)  //电机关闭没有到位
    {
        if(MOT_Sta.FX == 0u){
            MOT_Sta.Next_Sta = MOT_Close_Sta;
        }else{
            MOT_Sta.Next_Sta = MOT_Open_Sta;
        }
        MOT_Sta.OpenCloseDelayTime = 0u;
//        ADC_I_Sta.MOT_DelayTime = ADC_MOT_DelayTime;//电流延时检测
    }
    MOT_Sta.Open_Finish_Sta = 0u;
}

//****************************************************************
//功能描述：MOT 停止处理    (按键控制)
//输入参数：无
//返 回 值：无
//****************************************************************
void MOT_STOP_Handle(void)
{
    MOT_Sta.Next_Sta = MOT_Stop_Sta;
}

//****************************************************************
//功能描述：接近开关位置检测
//输入参数：无
//返 回 值：无
//****************************************************************
void Read_ApproachSwitch_Handle(void)
{
    //接近开关是否使能
    if(MOT_Sta.ApproachSwitch_Flag == 0u)
    {
        MOT_Sta.ApproachSwitch_XD_Time = 0u;
        return;
    }

    if(APPROACH_SWITCH == 0u)
    {
        MOT_Sta.ApproachSwitch_XD_Time++;
    }
    else
    {
        MOT_Sta.ApproachSwitch_XD_Time = 0u;
    }
    if(MOT_Sta.ApproachSwitch_XD_Time > ApproachSwitch_XD_Time_Val)    //消抖完成
    {
        MOT_Sta.ApproachSwitch_XD_Time = 0u;
        //电机打开时有效
//        if(MOT_Sta.Now_Sta == MOT_Open_Sta)
//        {
//            MOT_Sta.Next_Sta = MOT_Stop_Sta;
//            if(MOT_Sta.FX == 0u)
//            {
//                MOT_Sta.Open_Finish_Sta = 1u;
//                MOT_Sta.Close_Finish_Sta = 0u;            
//            }
//            else
//            {
//                MOT_Sta.Open_Finish_Sta = 0u;
//                MOT_Sta.Close_Finish_Sta = 1u;    
//            }

//        }
//        else 
        if(MOT_Sta.Now_Sta == MOT_Close_Sta)//电机关闭时有效
        {
            MOT_Sta.Next_Sta = MOT_Stop_Sta;
            if(MOT_Sta.FX == 0u)
            {
                MOT_Sta.Open_Finish_Sta = 0u;
                MOT_Sta.Close_Finish_Sta = 1u;            
            }
            else
            {
                MOT_Sta.Open_Finish_Sta = 1u;
                MOT_Sta.Close_Finish_Sta = 0u;    
            }
        }
    }
}
