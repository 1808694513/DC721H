#include "User_Iwdt.h"

//****************************************************************
//功能描述：WDT 初始化
//输入参数：无
//返 回 值：无
//****************************************************************
void User_WDT_Init(void)
{
    stc_iwdt_init_t stcIwdtInit = {0};
    ///< 开启WDT外设时钟
    SYSCTRL_PeriphClkEnable(SYSCTRL_PERICLK_IWDT);

    ///< IWDT 初始化
    ///< IWDT 溢出时间 = (计数值(u32ArrCounter)/32800) * 分频系数(u32Prescaler)
    ///< 本例为：(3280/32800)*32 = 3.2s
    stcIwdtInit.u32Action = IWDT_OVER_RESET__SLEEPMODE_STOP;
    stcIwdtInit.u32ArrCounter = 3280;
    stcIwdtInit.u32Window     = 0xFFF;
    stcIwdtInit.u32Prescaler  = IWDT_RC10K_DIV_32;
    IWDT_Init(&stcIwdtInit);

    ///< 启动 WDT
    IWDT_Start();
}
