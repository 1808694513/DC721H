#include "User_Include.h"

void Power_Init(void)
{
    __disable_irq();
    delay1ms(10u);
//    SYSCTRL_FuncEnable(SYSCTRL_FUNC_SWDIO);
    User_System_Init();
    User_BTim3_Init();
    User_WDT_Init();
//    User_ADC_Init();
    User_BeepLed_Init();
    User_Light_Init();
    User_MOT_Init();
    User_Button_Init();
    User_RF433_Init();
    delay1ms(10u);

    //波动开关初始化
    SystemTick_Time.updownToggleSwitch_Flag = 1u;
    Toggle_Switch_Handle();

    Flash_PowerON_Read_Handle();
    BeepLed_Set(5u,1u);

//    //433配对
//    BeepLed_Set(5u,1u);
//	RF_Sta.Set_DelayTime = RF_Set_DelayTime_Val;
//	RF_Sta.AddDel_DelayTime = 0u;
//	RF_Key.Set_Task = RF_Set_Step1;

    RF_Sta.RF_DataLen = 5u;RF_Sta.RF_Mode = RF_Old_Mode;//默认老协议
//    RF_Sta.RF_DataLen = 9u;RF_Sta.RF_Mode = RF_New_Mode;//默认新协议

//    MOT_Sta.ApproachSwitch_Flag = 1u;//接近开关使能

    __enable_irq();
}

/**
 ******************************************************************************
 ** \brief  Main function of project
 **
 ** \return uint32_t return value, if needed
 **
 ******************************************************************************/
int32_t main(void)
{
    Power_Init();
    while(1)
    {
        dog();
        Button_Shade_Handle();
        Button_Handle();
        Toggle_Switch_Handle();
        RF433_Data_Handle();
        Flash_Write_Handle();

        if(SystemTick_Time.Time_5ms_Flag == 1u)
        {
            SystemTick_Time.Time_5ms_Flag = 0u;
//            Read_ApproachSwitch_Handle();
//            ADC_Scan(0u);
//            ADC_DelayTime_Handle();
        }
        if(SystemTick_Time.Time_10ms_Flag == 1u)
        {
            SystemTick_Time.Time_10ms_Flag = 0u;
            Light_Run_Sta_Handle();
            MOT_Run_Sta_Handle();
            MOT_MaxRunTime_Handle();
            RF433_DelayTime_Handle();
        }
        if(SystemTick_Time.Time_100ms_Flag == 1u)
        {
            SystemTick_Time.Time_100ms_Flag = 0u;
            BeepLed_Handle();

        }
        if(SystemTick_Time.Time_1s_Flag == 1u)
        {
            SystemTick_Time.Time_1s_Flag = 0u;
        }
    }
}
