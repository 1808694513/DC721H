#include "User_Timer.h"

//****************************************************************
//功能描述：BTim3 初始化
//输入参数：无
//返 回 值：无
//****************************************************************
void User_BTim3_Init()
{
    stc_btim_init_t BTim3InitCfg = {0};

    //配置GTIM无效，BTIM3/4/5有效
    SYSCTRL_FuncEnable(SYSCTRL_FUNC_GTIMCONFIG);

    ///< 使能BTIM3/4/5 外设时钟
    SYSCTRL_PeriphClkEnable(SYSCTRL_PERIRESET_GTIM);

    BTim3InitCfg.u32TaskMode = BTIM_TASK_MODE_CONTINUOUS_COUNTER;//连续计数模式
    BTim3InitCfg.u32WorkMode = BTIM_WORK_MODE_PCLK;//工作模式为定时器模式
    BTim3InitCfg.u32Prescaler = BTIM_COUNTER_CLK_DIV1;//输入信号分频系数为1
    BTim3InitCfg.u32ToggleEn = BTIM_TOGGLE_DISABLE;//Toggle_N和Toggle_P输出关闭
    // BTim3InitCfg.u32TriggerSource = BTIM_TRIGGER_SOURCE_ETR;//触发源选择外部管脚ETR
    // BTim3InitCfg.u32ExInputPolarity = BTIM_ETR_POLARITY_NORMAL;//外部输入极性选择 极性不翻转
    BTim3InitCfg.u32AutoReloadVal = 1440u - 1u;//配置重载寄存器的值为1440

    Btim_Init(BTIM3, &BTim3InitCfg);

    Btim_ClearFlag(BTIM3, BTIM_IT_CLR_UI); //清除溢出中断标志位
    Btim_EnableIT(BTIM3, BTIM_IT_UI);      //允许BTIM3溢出中断
    EnableNvic(BTIM3_4_5_IRQn, IrqLevel3, TRUE);
    Btim_Enable(BTIM3);//使能Timer3
}

//基本定时器3中断服务程序   60us
void BTim3_IRQHandler(void)
{
//    uint8_t i=0;
    if(TRUE == Btim_IsActiveFlag(BTIM3, BTIM_IT_FLAG_UI))
    {
        //测试定时时间
        // GPIO_Init_Handle(Data_433_PORT,Data_433_PIN,GPIO_MODE_OUTPUT_PP,GPIO_PULL_NONE);
        // if(i == 0){
        //     GPIO_PD04_RESET();
        //     i = 1;
        // }else{
        //     GPIO_PD04_SET();
        //     i = 0;
        // }

        RF433_Rece_Handle(Data_433);
        Btim_ClearFlag(BTIM3, BTIM_IT_CLR_UI); //清除溢出中断标志位
    }
}
