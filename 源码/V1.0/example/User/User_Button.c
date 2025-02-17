#include "User_Button.h"

uint8_t updownButton_Flag=0;
uint8_t Button_Shade_Finish=0;
uint8_t ButtonDown1_Flag=0;
uint8_t ButtonDown2_Flag=0;
uint8_t ButtonDown3_Flag=0;
uint8_t ButtonDown4_Flag=0;
uint8_t ButtonDown5_Flag=0;
uint8_t ButtonDown6_Flag=0;
uint8_t ButtonDown7_Flag=0;
uint8_t KEY_Now=0; // 按键当前值
uint8_t KEY_Before=0; // 按键之前值
uint16_t Button_Count=0;
uint16_t ButtonLongDown1_Flag=0;
uint16_t ButtonLongDown2_Flag=0;
uint16_t ButtonLongDown3_Flag=0;
uint16_t ButtonLongDown4_Flag=0;
uint16_t ButtonLongDown5_Flag=0;
uint16_t ButtonLongDown6_Flag=0;
uint16_t ButtonLongDown7_Flag=0;
uint16_t ButtonDouble1_Time=0;
uint8_t ButtonDouble1_Flag=0;

uint8_t ButtonLongDown_Count=0;

//拨动开关
uint8_t updownToggleSwitch_Flag=0;
uint8_t ToggleSwitchDown1_Flag=0;
uint8_t ToggleSwitchDown2_Flag=0;
uint8_t Toggle_Switch_Now=0;
uint8_t Toggle_Switch_Before=0;
uint16_t Toggle_Switch_Count=0;

//****************************************************************
//功能描述：Button 初始化
//输入参数：无
//返 回 值：无
//****************************************************************
void User_Button_Init(void)
{
	stc_gpio_init_t stcGpioInit = {0};

    ///< 外设时钟使能
    SYSCTRL_PeriphClkEnable(SYSCTRL_PERICLK_PB);
	SYSCTRL_PeriphClkEnable(SYSCTRL_PERICLK_PC);
	SYSCTRL_PeriphClkEnable(SYSCTRL_PERICLK_PD);

	//IO初始化
    stcGpioInit.u32Mode = GPIO_MODE_INPUT;
    stcGpioInit.u32Pin = GPIO_PIN_04;
    stcGpioInit.u32Pull = GPIO_PULL_NONE;
	GPIOB_Init(&stcGpioInit);//PB04
	stcGpioInit.u32Pin = GPIO_PIN_03 | GPIO_PIN_04 | GPIO_PIN_05 | GPIO_PIN_06;
	GPIOC_Init(&stcGpioInit);//PC03~PC06
	stcGpioInit.u32Pin = GPIO_PIN_02;
	GPIOD_Init(&stcGpioInit);//PD02
}

void Button_Shade_Handle()
{
	if(!K1){
		KEY_Now |= KEY1;
	}else{
		KEY_Now &= ~KEY1;
	}
	if(!K2){
		KEY_Now |= KEY2;
	}else{
		KEY_Now &= ~KEY2;
	}
	if(!K3){
		KEY_Now |= KEY3;
	}else{
		KEY_Now &= ~KEY3;
	}
	if(!K4){
		KEY_Now |= KEY4;
	}else{
		KEY_Now &= ~KEY4;
	}
	if (SystemTick_Time.updownButton_Flag == 0u)
	{
		return;
	}
	SystemTick_Time.updownButton_Flag = 0;
	if (KEY_Now == KEY_Before)
	{
		if (++Button_Count >= Button_Count_Val)
		{
			Button_Count = 0;
			Button_Shade_Finish = 1;
		}
	}
	else
	{
		KEY_Before = KEY_Now;
		Button_Count = 0;
	}
}
void Button_Handle()
{
	if (Button_Shade_Finish == 0u)
	{
		return;
	}
	Button_Shade_Finish = 0u;

	if (KEY_Before == KEY1)
	{
		if (!ButtonDown1_Flag)//单击
		{
			ButtonDown1_Flag = 1;
			ButtonLongDown1_Flag=1;

			if(++ButtonDouble1_Flag > 2){//双击计数
				ButtonDouble1_Flag = 0;
			}

			KEY1_Handle();
		}
		else
		{
			if (ButtonLongDown1_Flag == ButtonLongDown_Time_Val)//长按
			{

			}
			if (ButtonLongDown1_Flag < ButtonLongDown_Time_MAX_Val)
			{
				ButtonLongDown1_Flag++;
			}
		}
	}
	else
	{
		if (ButtonLongDown1_Flag < ButtonLongDown_Time_Val/* - ButtonLongDownRepeat_Time_Val */ && ButtonLongDown1_Flag)//抬起
		{
			if(ButtonDouble1_Flag >= 2){//双击
				ButtonDouble1_Flag = 0;
				ButtonDouble1_Time = 0;
				ButtonLongDown1_Flag = 0;

			}
			if(ButtonDouble1_Time >= ButtonDouble_Time_Val){//抬起
				ButtonDouble1_Time = 0;
				ButtonDouble1_Flag = 0;
				ButtonLongDown1_Flag = 0;
				KEY1_TQ_Handle();

			}else{
				ButtonDouble1_Time++;
			}
		}else{
			ButtonLongDown1_Flag = 0;
			ButtonDouble1_Flag = 0;
			ButtonDouble1_Time = 0;
		}
		ButtonDown1_Flag = 0;
	}
	if (KEY_Before == KEY2)
	{
		if (!ButtonDown2_Flag)
		{
			ButtonDown2_Flag = 1;
			KEY2_Handle();
		}
		else
		{
			if (ButtonLongDown2_Flag == ButtonLongDown_Time_Val + (3000u/Button_XD_Time_Val))//5s产测模式
			{
//				KEY2_Long_Handle();
			}
			if (ButtonLongDown2_Flag < ButtonLongDown_Time_MAX_Val)
			{
				ButtonLongDown2_Flag++;
			}
		}
	}
	else
	{
		if (ButtonLongDown2_Flag < ButtonLongDown_Time_Val - ButtonLongDownRepeat_Time_Val && ButtonLongDown2_Flag)
		{

		}
		ButtonDown2_Flag = 0;
		ButtonLongDown2_Flag = 0;
	}
	if (KEY_Before == KEY3)
	{
		if (!ButtonDown3_Flag)
		{
			ButtonDown3_Flag = 1;
			KEY3_Handle();
		}
		else
		{
			if (ButtonLongDown3_Flag == ButtonLongDown_Time_Val)
			{

			}
			if (ButtonLongDown3_Flag < ButtonLongDown_Time_MAX_Val)
			{
				ButtonLongDown3_Flag++;
			}
		}
	}
	else
	{
		if(ButtonLongDown3_Flag < ButtonLongDown_Time_Val/* - ButtonLongDownRepeat_Time_Val */ && ButtonLongDown3_Flag)
		{
			KEY3_TQ_Handle();
		}
		ButtonDown3_Flag = 0;
		ButtonLongDown3_Flag = 0;
	}
	if (KEY_Before == KEY4)
	{
		if (!ButtonDown4_Flag)
		{
			ButtonDown4_Flag = 1;
			KEY4_Handle();
		}
		else
		{
			if (ButtonLongDown4_Flag == ButtonLongDown_Time_Val)//2s对码模式
			{
				KEY4_Long_Handle(0u);
			}
			if(ButtonLongDown4_Flag == ButtonLongDown_Time_Val + (8000u/Button_XD_Time_Val))//10s恢复出厂
			{
				KEY4_Long_Handle(1u);
			}
//			if(ButtonLongDown4_Flag == ButtonLongDown_Time_Val + (3000u/Button_XD_Time_Val))//5s配网模式
//			{
//				KEY4_Long_Handle(2u);
//			}
			if (ButtonLongDown4_Flag < ButtonLongDown_Time_MAX_Val)
			{
				ButtonLongDown4_Flag++;
			}
		}
	}
	else
	{
		if(ButtonLongDown4_Flag >= ButtonLongDown_Time_Val + (8000u/Button_XD_Time_Val) && ButtonLongDown4_Flag)
		{
			//恢复出厂设置模式
			KEY4_TQ_Handle(1u);
		}
		else if(ButtonLongDown4_Flag >= ButtonLongDown_Time_Val + (3000u/Button_XD_Time_Val) && ButtonLongDown4_Flag)
		{
			//配网模式
			KEY4_TQ_Handle(2u);
		}
		else if(ButtonLongDown4_Flag >= ButtonLongDown_Time_Val && ButtonLongDown4_Flag)
		{
			//对码模式
			KEY4_TQ_Handle(0u);
		}
		ButtonDown4_Flag = 0;
		ButtonLongDown4_Flag = 0;
	}

	if (KEY_Before == KEY5)
	{
		if (!ButtonDown5_Flag)
		{
			ButtonDown5_Flag = 1;
			KEY5_Handle();
		}
		else
		{
			if (ButtonLongDown5_Flag == ButtonLongDown_Time_Val)
			{
				KEY_MOT_Handle();
			}
			if (ButtonLongDown5_Flag < ButtonLongDown_Time_MAX_Val)
			{
				ButtonLongDown5_Flag++;
			}
		}
	}
	else
	{
		if(ButtonLongDown5_Flag >= ButtonLongDown_Time_Val && ButtonLongDown5_Flag)
		{

		}
		ButtonDown5_Flag = 0;
		ButtonLongDown5_Flag = 0;
	}
	if (KEY_Before == KEY6)
	{
		if (!ButtonDown6_Flag)
		{
			ButtonDown6_Flag = 1;
			KEY6_Handle();
		}
		else
		{
			if (ButtonLongDown6_Flag == ButtonLongDown_Time_Val)
			{
				//KEY6_Long_Handle();
			}
			if (ButtonLongDown6_Flag < ButtonLongDown_Time_MAX_Val)
			{
				ButtonLongDown6_Flag++;
			}
		}
	}
	else
	{
		if(ButtonLongDown6_Flag >= ButtonLongDown_Time_Val && ButtonLongDown6_Flag)
		{

		}
		ButtonDown6_Flag = 0;
		ButtonLongDown6_Flag = 0;
	}
}

//拨动开关处理
void Toggle_Switch_Handle(void)
{
//	if(!S1){
//		Toggle_Switch_Now |= K_S1;
//	}else{
//		Toggle_Switch_Now &= ~K_S1;
//	}
	if(!S2){
		Toggle_Switch_Now |= K_S2;
	}else{
		Toggle_Switch_Now &= ~K_S2;
	}
	if(SystemTick_Time.updownToggleSwitch_Flag == 0u){
		return;
	}
	SystemTick_Time.updownToggleSwitch_Flag = 0u;
	if (Toggle_Switch_Now == Toggle_Switch_Before)
	{
		if (++Toggle_Switch_Count >= Toggle_Switch_Count_Val)
		{
			Toggle_Switch_Count = 0;
//			if (Toggle_Switch_Before&K_S1)
//			{
//				Switch_S1_ON_Handle();
//			}
//			else
//			{
//				Switch_S1_OFF_Handle();
//			}
			if (Toggle_Switch_Before&K_S2)
			{
				Switch_S2_ON_Handle();
			}
			else
			{
				Switch_S2_OFF_Handle();
			}
		}
	}
	else
	{
		Toggle_Switch_Before = Toggle_Switch_Now;
		Toggle_Switch_Count = 0;

		//不一样闪三次
		BeepLed_Set(2u,3u);
	}
}

//===================================KEY========================================

//UP
void KEY1_Handle(void)
{
	MOT_UP_Handle();
}

//STOP
void KEY2_Handle(void)
{
    MOT_STOP_Handle();
}

//DOWN
void KEY3_Handle(void)
{
    MOT_DOWN_Handle();
}

void KEY4_Handle(void)
{
//    SYSCTRL_FuncDisable(SYSCTRL_FUNC_SWDIO);
}

void KEY5_Handle(void)
{

}

void KEY6_Handle(void)
{

}

//产测
//void KEY2_Long_Handle(void)
//{
//	BeepLed_Set(2u,1u);
//	SendBuf_For_Tuya(WIFI_TEST);

//}


//mode 0:对码 1:恢复出厂设置 2：配网
void KEY4_Long_Handle(uint8_t mode)
{
	if(mode == 0u)
	{
		//进入对码模式
		BeepLed_Set(2u,1u);
	}
	else if(mode == 1u)
	{
		//进入恢复出厂设置模式
		BeepLed_Set(2u,3u);
	}
	else if(mode == 2u)
	{
		//进入配网模式
		BeepLed_Set(2u,2u);
	}

}

//UP抬起判断(点动模式需要停止)
void KEY1_TQ_Handle(void)
{
	if(MOT_Sta.DOT_Flag == 1u)
	{
		MOT_STOP_Handle();
	}
}

//DOWN抬起判断(点动模式需要停止)
void KEY3_TQ_Handle(void)
{
	if(MOT_Sta.DOT_Flag == 1u)
	{
		MOT_STOP_Handle();
	}
}

//mode 0:对码 1:恢复出厂设置 2:配网
void KEY4_TQ_Handle(uint8_t mode)
{
	if(mode == 0u)
	{
		//进入对码模式
		BeepLed_Set(0u,100u);
		RF_Sta.Set_DelayTime = RF_Set_DelayTime_Val;
		RF_Sta.AddDel_DelayTime = 0u;
		RF_Key.Set_Task = RF_Set_Step1;
	}
	else if(mode == 1u)
	{
		//进入恢复出厂设置模式
		BeepLed_Set(2u,5u);

		//删码
		Flash_Write_Check_AddDel_Handle(3u);

        //不换向
        MOT_FX_Handle(0u);

		//配网
//		Tuya_Sta.Wifi_Finish_Flag = 0u;
//		Tuya_Sta.Wifi_Connect_Flag = 1u;
//		SendBuf_For_Tuya(WIFI_SC_Sta);
	}
//	else if(mode == 2u)
//	{
//		//进入配网模式
//		BeepLed_Set(1u,5u);
//		//配网
//		Tuya_Sta.Wifi_Finish_Flag = 0u;
//		Tuya_Sta.Wifi_Connect_Flag = 0u;
//		SendBuf_For_Tuya(WIFI_SC_Sta);
//		// SendBuf_For_Tuya(WIFI_AP_Sta);
//	}
}

//电机换向
void KEY_MOT_Handle(void)
{
	BeepLed_Set(2u,3u);
	MOT_FX_Handle(2u);
}

//电机点动开关
void KEY6_Long_Handle(void)
{
	BeepLed_Set(1u,5u);
	if(MOT_Sta.DOT_Flag == 0u)
	{
		MOT_Sta.DOT_Flag = 1u;
	}
	else
	{
		MOT_Sta.DOT_Flag = 0u;
	}
}

//接近开关打开
void Switch_S1_ON_Handle(void)
{
    MOT_Sta.ApproachSwitch_Flag = 1u;
}

//接近开关关闭
void Switch_S1_OFF_Handle(void)
{
	MOT_Sta.ApproachSwitch_Flag = 0u;
}

void Switch_S2_ON_Handle(void)
{
	RF_Sta.RF_Mode = RF_New_Mode;
	RF_Sta.RF_DataLen = 9u;
}

void Switch_S2_OFF_Handle(void)
{
	RF_Sta.RF_Mode = RF_Old_Mode;
	RF_Sta.RF_DataLen = 5u;
}
