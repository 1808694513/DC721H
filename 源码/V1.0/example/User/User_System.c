#include "User_System.h"

SystemTick_Time_Typedef SystemTick_Time;

//****************************************************************
//功能描述：System 初始化
//输入参数：无
//返 回 值：无
//****************************************************************
void User_System_Init(void)
{
    stc_sysctrl_sysclk_source_init_t SysClkSrc = {0};
    stc_sysctrl_clk_init_t SysClk = {0};

    SysClkSrc.u32SysClkSourceType = SYSCTRL_SYSCLK_SOURCE_TYPE_RCH|\
                                    SYSCTRL_SYSCLK_SOURCE_TYPE_RCL;//系统时钟源 内部高速时钟   内部低速时钟
    SysClkSrc.u32RCHState = SYSCTRL_RCH_TRIM_48MHz |\
                            SYSCTRL_RCH_DIV2; //RCH配置 2分频   48MHZ
    SysClkSrc.u32RCLState = SYSCTRL_RCL_TRIM_32p8KHz |\
                                       SYSCTRL_RCL_WAITCYCLE256;     //RCL配置 32.8KHz  256个等待周期
    SYSCTRL_SysClkSrcInit(&SysClkSrc);


    SysClk.u32ClockType = SYSCTRL_CLOCKTYPE_SYSCLK |\
                          SYSCTRL_CLOCKTYPE_HCLK |\
                          SYSCTRL_CLOCKTYPE_PCLK;//初始化时钟类型SYSCLK,HCLK,PCLK
    SysClk.u32SysClkSource = SYSCTRL_SYSCLK_SOURCE_RCH;//系统时钟源 内部高速时钟
    SysClk.u32HClkDiv = SYSCTRL_SYSCLK_HCLK_PRS1;   //HCLK时钟分频 1分频
    SysClk.u32PClkDiv = SYSCTRL_SYSCLK_PCLK_PRS1;   //PCLK时钟分频 1分频
    SysClk.u32WaitCycle = SYSCTRL_FLASH_WAIT_CYCLE1;//FLASH读等待周期 1个周期
    SYSCTRL_SysClkInit(&SysClk);

    ///< 内核函数，SysTick配置，定时1ms
    SysTick_Config(24000);
    delay1ms(10u);
}

//systick中断服务程序   1ms
void SysTick_IRQHandler(void)
{
    SystemTick_Time.updownButton_Flag = 1u;
    SystemTick_Time.updownToggleSwitch_Flag = 1u;
    SystemTick_Time.Time_1ms_Flag = 1u;

//    Uart_Data_Pro();
    if(++SystemTick_Time.Time_5ms >= 5)     //5ms定时
    {
        SystemTick_Time.Time_5ms = 0;
        SystemTick_Time.Time_5ms_Flag = 1;
    }
    if(++SystemTick_Time.Time_10ms >= 10)   //10ms定时
    {
        SystemTick_Time.Time_10ms = 0;
        SystemTick_Time.Time_10ms_Flag = 1;
    }
    if(++SystemTick_Time.Time_100ms >= 100) //100ms定时
    {
        SystemTick_Time.Time_100ms = 0;
        SystemTick_Time.Time_100ms_Flag = 1;
    }
    if(++SystemTick_Time.Time_1s >= 1000)   //1s定时
    {
        SystemTick_Time.Time_1s = 0;
        SystemTick_Time.Time_1s_Flag = 1;
    }
}
