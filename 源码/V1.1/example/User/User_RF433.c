#include "User_RF433.h"

RF_State_Typedef RF_Sta;//接收状态
RF_Key_Typedef RF_Key;//功能处理

//****************************************************************
//功能描述：RF433 初始化
//输入参数：无
//返 回 值：无
//****************************************************************
void User_RF433_Init(void)
{
	stc_gpio_init_t stcGpioInit = {0};

    ///< 外设时钟使能
    SYSCTRL_PeriphClkEnable(SYSCTRL_PERICLK_PD);

	//IO初始化
    stcGpioInit.u32Mode = GPIO_MODE_INPUT;
    stcGpioInit.u32Pin = GPIO_PIN_04;
    stcGpioInit.u32Pull = GPIO_PULL_NONE;
	GPIOD_Init(&stcGpioInit);
}

//****************************************************************
//
//
//
//
//
//
//
//
//
//****************************************************************

//****************************************************************
//功能描述：RF433 接收处理
//输入参数：无
//返 回 值：无
//****************************************************************
void RF433_Rece_Handle(uint8_t RFBit)
{

    static uint8_t H_Cnt=0u,L_Cnt=0u;
    static uint8_t RF_Data_Cnt=0u,RF_WEI_Cnt=0u;
    static uint8_t Rece_Bit1_IF=0u;//接收高电平为1的标志
    static uint8_t Bit_Rece_IF=0u;//接收到第二个高电平标志

    if(RF_Sta.RF_Finish == 1u) return;

    switch (RF_Sta.RF_Task)
    {
        case RF_Wait://等待接收
            H_Cnt = 0u;L_Cnt = 0u;
            RF_Sta.RF_Task=RF_Once;
            break;
        case RF_Once://开始接收判断
            if(RFBit)
            {
                H_Cnt++;
                if(H_Cnt > Start_Once_Val)
                {
                    L_Cnt = 0u;
                    RF_Sta.RF_Task = RF_Start_H;//进入接收起始信号高
                }
            }
            else
            {
                L_Cnt++;H_Cnt = 0u;
            }
            break;
        case RF_Start_H://接收起始信号高
            if(RFBit)
            {
                H_Cnt++;L_Cnt = 0u;
                if(H_Cnt > Start_H_Count_MAX_Val)   //超过起始高最大值 回到初始状态
                {
                    RF_Sta.RF_Task = RF_Wait;
                }
            }
            else
            {
                L_Cnt++;
                if(H_Cnt >= Start_H_Count_MIN_Val && H_Cnt <= Start_H_Count_MAX_Val)
                {
                    RF_Sta.RF_Task = RF_Start_L;//进入接收起始信号低
                }
                else
                {
                    RF_Sta.RF_Task = RF_Wait;
                }
                H_Cnt = 0u;
            }
            break;
        case RF_Start_L://接收起始信号低
            if(!RFBit)
            {
                L_Cnt++;H_Cnt = 0u;
                if(L_Cnt > Start_L_Count_MAX_Val)   //超过起始高最大值 回到初始状态
                {
                    RF_Sta.RF_Task = RF_Wait;
                }
            }
            else
            {
                H_Cnt++;
                if(L_Cnt >= Start_L_Count_MIN_Val && L_Cnt <= Start_L_Count_MAX_Val)
                {
                    RF_Data_Cnt=0u,RF_WEI_Cnt=0u;
                    Rece_Bit1_IF = 0u;Bit_Rece_IF = 0u;
                    RF_Sta.RF_Task = RF_Data;//进入数据接收部分
                }
                else
                {
                    RF_Sta.RF_Task = RF_Wait;
                }
                L_Cnt = 0u;
            }
            break;
        case RF_Data://数据接收部分
            if(RFBit)
            {
                H_Cnt++;
                if(Bit_Rece_IF)//接收到第二个高电平标志
                {
                    Bit_Rece_IF = 0u;
                    if(L_Cnt >= Data0_L_Count_MIN_Val && L_Cnt <= Data0_L_Count_MAX_Val)
                    {
                        if(Rece_Bit1_IF)
                        {
                            RF_Sta.RF_Task = RF_Wait;
                        }
                        else
                        {
                            RF_Sta.RF_Buf[RF_Data_Cnt] <<= 1u;
                        }
                    }
                    else if(L_Cnt >= Data1_L_Count_MIN_Val && L_Cnt <= Data1_L_Count_MAX_Val)
                    {
                        if(!Rece_Bit1_IF)
                        {
                            RF_Sta.RF_Task = RF_Wait;
                        }
                        else
                        {
                            RF_Sta.RF_Buf[RF_Data_Cnt] <<= 1u;
                            RF_Sta.RF_Buf[RF_Data_Cnt] |= 0x01u;
                        }
                    }
                    if(++RF_WEI_Cnt >= RF_WEI_Count_Val)
                    {
                        RF_WEI_Cnt = 0u;
                        if(++RF_Data_Cnt >= RF_Sta.RF_DataLen)
                        {
                            RF_Data_Cnt = 0u;
                            RF_Sta.RF_Task = RF_Wait;
                            if(RF_Sta.RF_DataLen == 5u) //普通码
                                RF_Sta.RF_Finish = 1u;
                        }
                    }
                }
                if(H_Cnt >= Data0_L_Count_MAX_Val)//回初始状态
                {
                    RF_Sta.RF_Task = RF_Wait;
                }
                L_Cnt = 0u;
            }
            else
            {
                L_Cnt++;
                if(H_Cnt >= Data0_H_Count_MIN_Val && H_Cnt <= Data0_H_Count_MAX_Val)
                {
                    Rece_Bit1_IF = 0u;
                }
                else if(H_Cnt >= Data1_H_Count_MIN_Val && H_Cnt <= Data1_H_Count_MAX_Val)
                {
                    Rece_Bit1_IF = 1u;
                }
//                else
//                {
//                    RF_Sta.RF_Task = RF_Wait;
//                }
                Bit_Rece_IF = 1u;

                if(L_Cnt >= Data0_L_Count_MAX_Val)  //超时退出
                {
                    if((RF_Data_Cnt == RF_Sta.RF_DataLen-1u) && (RF_WEI_Cnt == RF_WEI_Count_Val-1u))//最后一位数据
                    {
                        RF_Sta.RF_Buf[RF_Data_Cnt] <<= 1u;
                        if(Rece_Bit1_IF)
                        {
                            RF_Sta.RF_Buf[RF_Data_Cnt] |= 0x01u;
                        }
                        RF_Sta.RF_Finish = 1u;
                    }
                    RF_Sta.RF_Task = RF_Wait;
                }
                H_Cnt = 0u;
            }
        default:
            break;
    }
}

//****************************************************************
//功能描述：RF433 接收到数据处理
//输入参数：无
//返 回 值：无
//****************************************************************
void RF433_Data_Handle(void)
{
    uint8_t i=0u;
    uint32_t temp_tab=0;//临时缓冲区下标
    if(RF_Sta.RF_Finish == 0u) return;

    for(i=0u; i<RF_Sta.RF_DataLen; i++)
    {
        RF_Sta.RF_BufBack[i] = RF_Sta.RF_Buf[i];
    }
    RF_Sta.RF_Finish = 0u;
    RF_Sta.Addr_Match = RF_Addr_Match_ERR;

    if(RF_Sta.RF_Mode == RF_New_Mode)       //新协议处理
    {
		//数据解密
		TEA_DeCode(RF_Sta.RF_BufBack, RF_Sta.RF_BufBack);
		//数据校验
		if (CRC8_Cal(RF_Sta.RF_BufBack,(RF_Sta.RF_DataLen - 1u)) != RF_Sta.RF_BufBack[RF_Sta.RF_DataLen - 1u]) return;

        RF_Sta.Addr = (uint32_t)(RF_Sta.RF_BufBack[4u]<<24u) | (uint32_t)(RF_Sta.RF_BufBack[5u]<<16u) |
                        (uint32_t)(RF_Sta.RF_BufBack[6u]<<8u) | (uint32_t)(RF_Sta.RF_BufBack[7]&0xF0u);
        RF_Sta.Channel = RF_Sta.RF_BufBack[7u]&0x0Fu;
        RF_Sta.Synchronization_Word = (uint32_t)(RF_Sta.RF_BufBack[1u]<<24u) |
                        (uint32_t)(RF_Sta.RF_BufBack[2u]<<16u) | (uint32_t)(RF_Sta.RF_BufBack[3u]<<8u);
        RF_Sta.CMD = RF_Sta.RF_BufBack[0u];
        RF_Sta.CRC8 = RF_Sta.RF_BufBack[8u];
    }
    else if(RF_Sta.RF_Mode == RF_Old_Mode)  //旧协议处理
    {
        RF_Sta.Addr = (RF_Sta.RF_BufBack[0u]<<24) | (RF_Sta.RF_BufBack[1u]<<16u) |
                        (RF_Sta.RF_BufBack[2u]<<8) | (RF_Sta.RF_BufBack[3u]&0xF0u);
        RF_Sta.Channel = RF_Sta.RF_BufBack[3u]&0x0Fu;
        RF_Sta.Synchronization_Word = 0xFFFFFFFFu;
        RF_Sta.CMD = RF_Sta.RF_BufBack[4u];
        RF_Sta.CRC8 = 0xFFu;
    }

    // if(RF_Sta.Check == RF_Check_ERR)
    // {
        RF_Sta.Addr_Match = RF_Addr_Match_ERR;
        //判断是否保存地址
        for(i=0u; i<RF_MAX_Flash; i++)
        {
            if(RF_Sta.Addr == RF_Sta.RF_Flash[i].Addr && (RF_Sta.Channel == RF_Sta.RF_Flash[i].Channel || RF_Sta.Channel == 0u))
            {
                RF_Sta.Addr_Match = RF_Addr_Match_OK;
                temp_tab = i;
                break;
            }
        }
    // }

    //判断同步码
    if(RF_Sta.RF_Mode == RF_New_Mode)
    {
        if(RF_Sta.Addr_Match == RF_Addr_Match_OK && RF_Sta.Channel != 0u)    //地址添加过判断同步码
        {
            if(RF_Sta.RF_Flash[temp_tab].Synchronization_Word != 0xFFFFFFFFu)   //初始状态 未配对 不判断同步码
            {
                if(RF_Sta.Synchronization_Word < RF_Sta.RF_Flash[temp_tab].Synchronization_Word) return;   //同步码错误
                else if(RF_Sta.Synchronization_Word >= RF_Sta.RF_Flash[temp_tab].Synchronization_Word)
                {
                    RF_Sta.RF_Flash[temp_tab].Synchronization_Word = RF_Sta.Synchronization_Word;
                    if(((RF_Sta.Synchronization_Word>>8) % 0x10) == 0u)  //按16次保存一次
                    {
                        FLASH_Save.Flash_Flag = 1u;
                    }
                }
            }
            else
            {
                RF_Sta.RF_Flash[temp_tab].Synchronization_Word = RF_Sta.Synchronization_Word;
                FLASH_Save.Flash_Flag = 1u;
            }
        }
    }

    if(RF_Sta.CMD == RF_Sta.CMD_Before && RF_Sta.Addr == RF_Sta.Addr_Before)//RF_Rece_DelayTime_Val ms内重复接收同一个命令退出
    {
        if(RF_Sta.Rece_DelayTime != 0u)
        {
            if(RF_Sta.LongDownTime < RF_LongDownTime_MAX_Val)
            {
                RF_Sta.LongDownTime+=(RF_Rece_DelayTime_Val-RF_Sta.Rece_DelayTime);
            }
            RF_Sta.LongERRTime = RF_LongERRTime_Val;

            RF_Sta.Rece_DelayTime = RF_Rece_DelayTime_Val;
            return;
        }
    }
    else
    {
        RF_Sta.CMD_Before = RF_Sta.CMD;
        RF_Sta.Addr_Before = RF_Sta.Addr;
        RF_Sta.LongDownTime++;
    }
    RF_Sta.Rece_DelayTime = RF_Rece_DelayTime_Val;

    if(RF_Sta.AddDel_DelayTime) //添码删码
    {
        if(RF_Sta.Channel != 0u)    //0通道无法设置
        {
            //添码删码处理
            RF433_AddDel_Handle();
            if(RF_Sta.AddDel_DelayTime == 0u)
                return;
        }
    }
    else if(RF_Sta.Set_DelayTime)   //对码
    {
        if(RF_Sta.Channel != 0u)    //0通道无法设置
        {
            if(RF_Sta.CMD == RF_CMD_SET && RF_Sta.Addr_Match == RF_Addr_Match_OK)   //如果有码并且是设置命令
            {
                RF_Sta.Set_DelayTime = 0u;
                BeepLed_Set(1u,5u);    //响5次
                return;
            }
            if((RF_Sta.CMD == RF_CMD_UP || RF_Sta.CMD == RF_CMD_DOWN || RF_Sta.CMD == RF_CMD_STOP || RF_Sta.CMD == RF_CMD_LIGHT || RF_Sta.CMD == RF_CMD_LIGHT_ON || RF_Sta.CMD == RF_CMD_LIGHT_OFF) && RF_Sta.Addr_Match == RF_Addr_Match_OK)
            {
                RF_Sta.Set_DelayTime = 0u;
                BeepLed_OFF();
            }
            //对码处理
            RF433_Check_Handle();
        }
    }

    if(!RF_Sta.AddDel_DelayTime && !RF_Sta.Set_DelayTime)
    {
        //用户处理代码
        if(RF_Sta.Addr_Match == RF_Addr_Match_OK)//判断是否对码 或未对码但有保存地址时 处理功能控制
        {
            RF433_Fun_Handle();
            if(RF_Sta.Channel != 0u)    //0通道无法设置
            {
                if(RF_Sta.CMD == RF_CMD_SET)
                {
                    RF_Sta.AddDel_DelayTime = RF_AddDel_DelayTime_Val;
                    //添码删码处理
                    RF433_AddDel_Handle();
                }
            }
        }
    }
}

//****************************************************************
//功能描述：RF433 对码处理
//输入参数：无
//返 回 值：无
//****************************************************************
void RF433_Check_Handle(void)
{
    static uint32_t Addr=0u;
    switch(RF_Key.Set_Task)
    {
        case RF_Set_Step1:
            if(RF_Sta.CMD == RF_CMD_SET)
            {
                RF_Sta.Set_DelayTime = RF_Set_DelayTime_Val;
                Addr = RF_Sta.Addr;
                BeepLed_Set(2u,50u);
                // BeepLed_Work.DelayTime = BeepLedDealyTime_Val;
                RF_Key.Set_Task = RF_Set_Step2;
            }
            break;
        case RF_Set_Step2:
            if(RF_Sta.CMD == RF_CMD_SET && Addr == RF_Sta.Addr)
            {
                RF_Sta.Set_DelayTime = RF_Set_DelayTime_Val;
                BeepLed_Set(1u,5u);
                // BeepLed_Work.DelayTime = BeepLedDealyTime_Val;
                RF_Sta.Set_DelayTime = 0u;
                RF_Sta.Check = RF_Check_OK;
                RF_Key.Set_Task = RF_Set_Step1;

                //保存
                Flash_Write_Check_AddDel_Handle(1u);
            }
            break;
        // case RF_Set_Step3:
        //     if((RF_Sta.CMD == RF_CMD_UP || RF_Sta.CMD == RF_CMD_DOWN) && Addr == RF_Sta.Addr)
        //     {
        //         BeepLed_Set(2u,4u);
        //         RF_Sta.Set_DelayTime = 0u;
        //         RF_Sta.Check = RF_Check_OK;
        //         RF_Key.Set_Task = RF_Set_Step1;

        //         //保存
        //         Flash_Write_Check_AddDel_Handle(1u);
        //     }
        //    break;
        default:
            break;
    }
}

//****************************************************************
//功能描述：RF433 添码删码处理  (电机换向)
//输入参数：无
//返 回 值：无
//****************************************************************
void RF433_AddDel_Handle(void)
{
    static uint32_t Addr=0u;
    static uint32_t Channel=0u;
    switch(RF_Key.Set_Task)
    {
        case RF_Set_Step1:
            if(RF_Sta.CMD == RF_CMD_SET)
            {
                Addr = RF_Sta.Addr;
                Channel = RF_Sta.Channel;
                RF_Sta.AddDel_DelayTime = RF_AddDel_DelayTime_Val;
                BeepLed_Set(2u,1u);    //闪一次
                RF_Key.Set_Task = RF_Set_Step2;
            }
            break;

        case RF_Set_Step2:
            if(Addr == RF_Sta.Addr && Channel == RF_Sta.Channel)
            {
                if(RF_Sta.CMD == RF_CMD_SET)
                {
                    RF_Sta.AddDel_DelayTime = RF_AddDel_DelayTime_Val;
                    BeepLed_Set(2u,1u);    //闪1次
                    RF_Key.Set_Task = RF_Set_Step3; //添码 //或配网
                }
                else if(RF_Sta.CMD == RF_CMD_STOP)
                {
                    RF_Sta.AddDel_DelayTime = RF_AddDel_DelayTime_Val;
                    BeepLed_Set(2u,1u);    //闪1次
                    RF_Key.Set_Task = RF_Set_Step4; //删码
                }
               else if(RF_Sta.CMD == RF_CMD_UP)
               {
                   RF_Sta.AddDel_DelayTime = RF_AddDel_DelayTime_Val;
                   BeepLed_Set(2u,1u);    //闪1次
                   RF_Key.Set_Task = RF_Set_Step5; //进入电机换向处理
               }
            }
            break;
        case RF_Set_Step3:
            if(RF_Sta.CMD == RF_CMD_SET && (Addr != RF_Sta.Addr || Channel != RF_Sta.Channel) && RF_Sta.Addr_Match != RF_Addr_Match_OK)
            {
                BeepLed_Set(2u,3u);    //闪3次
                RF_Sta.AddDel_DelayTime = 0u;
                RF_Key.Set_Task = RF_Set_Step1;
                //保存地址
                Flash_Write_Check_AddDel_Handle(2u);
            }
            // else if(RF_Sta.CMD == RF_CMD_SET && (Addr == RF_Sta.Addr && Channel == RF_Sta.Channel))  //配网
            // {
            //     BeepLed_Set(1u,5u);    //快闪5次
            //     RF_Sta.AddDel_DelayTime = 0u;
            //     RF_Key.Set_Task = RF_Set_Step1;
            //     //配网
            //     Tuya_Sta.Wifi_Finish_Flag = 0u;
            //     Tuya_Sta.Wifi_Connect_Flag = 0u;
            //     SendBuf_For_Tuya(WIFI_SC_Sta);
            //     // SendBuf_For_Tuya(WIFI_AP_Sta);
            // }
            break;
        case RF_Set_Step4:
            if(RF_Sta.CMD == RF_CMD_SET && (Addr == RF_Sta.Addr && Channel == RF_Sta.Channel))
            {
                BeepLed_Set(2u,3u);    //闪3次
                RF_Sta.AddDel_DelayTime = 0u;
                RF_Key.Set_Task = RF_Set_Step1;
                //保存地址
                Flash_Write_Check_AddDel_Handle(3u);
            }
            break;
       case RF_Set_Step5:
           if(RF_Sta.CMD == RF_CMD_DOWN && (Addr == RF_Sta.Addr && Channel == RF_Sta.Channel))
           {
               BeepLed_Set(2u,3u);    //闪3次
               RF_Sta.AddDel_DelayTime = 0u;
               RF_Key.Set_Task = RF_Set_Step1;
               MOT_FX_Handle(2u);    //电机换向    保存
           }
           break;
        default:
            break;
    }
}


//****************************************************************
//功能描述：RF433 功能处理
//输入参数：无
//返 回 值：无
//****************************************************************
void RF433_Fun_Handle(void)
{
    switch(RF_Sta.CMD)
    {
        case RF_CMD_UP:
            MOT_UP_Handle();
            break;
        case RF_CMD_DOWN:
            MOT_DOWN_Handle();
            break;
        case RF_CMD_STOP:
            MOT_STOP_Handle();
            break;
        case RF_CMD_LIGHT:
            Light_Control_Handle(2u);
            break;
        case RF_CMD_LIGHT_ON:
            Light_Control_Handle(1u);
            break;
        case RF_CMD_LIGHT_OFF:
            Light_Control_Handle(0u);
            break;
        default:
            break;
    }
}

//****************************************************************
//功能描述：RF433 对码 添码 删码 值处理
//输入参数：Val: 1对码 2添码 3删码
//返 回 值：无
//****************************************************************
void Flash_Write_Check_AddDel_Handle(uint8_t Val)
{
    uint8_t i=0u;
    if(Val == 1u || Val == 2u)//对码 添码
    {
        if(Val == 1u)//对码
        {
            if(RF_Sta.Addr != RF_Key.Check_Addr || RF_Sta.Channel != RF_Key.Check_Channel)//如果对码地址不匹配，重新赋值
            {
                RF_Key.Addr_Tab = 0u;
                RF_Key.Check_Tab = RF_Key.Addr_Tab;//对码的下标保存
                RF_Key.Check_Addr = RF_Sta.Addr;
                RF_Key.Check_Channel = RF_Sta.Channel;


                //全部清除
                for(i=0u; i<RF_MAX_Flash; i++)
                {

                    RF_Sta.RF_Flash[i].Addr = 0xFFFFFFFFu;
                    RF_Sta.RF_Flash[i].Channel = 0xFFu;
                    RF_Sta.RF_Flash[i].Synchronization_Word = 0xFFFFFFFFu;
                }
            }

        }

        RF_Sta.RF_Flash[RF_Key.Addr_Tab].Addr = RF_Sta.Addr;
        RF_Sta.RF_Flash[RF_Key.Addr_Tab].Channel = RF_Sta.Channel;
        RF_Sta.RF_Flash[RF_Key.Addr_Tab].Synchronization_Word = RF_Sta.Synchronization_Word;

        if(++RF_Key.Addr_Tab >= RF_MAX_Flash)   //如果超过最大地址表长度 覆盖最后一位
        {
            RF_Key.Addr_Tab = RF_MAX_Flash-1u;
        }
    }
    else if(Val == 3u)//删码    全部清除
    {
        for(i=0u; i<RF_MAX_Flash; i++)
        {

            RF_Sta.RF_Flash[i].Addr = 0xFFFFFFFFu;
            RF_Sta.RF_Flash[i].Channel = 0xFFu;
            RF_Sta.RF_Flash[i].Synchronization_Word = 0xFFFFFFFFu;
        }
        RF_Sta.Check = RF_Check_ERR;
        RF_Key.Check_Addr = 0xFFFFFFFFu;
        RF_Key.Check_Channel = 0xFFu;
        RF_Key.Check_Tab = 0xFFu;
        RF_Key.Addr_Tab = 0u;
    }

    FLASH_Save.Flash_Flag = 1u;
}

//****************************************************************
//功能描述：RF433 倒计时处理    (10ms进入一次)
//输入参数：无
//返 回 值：无
//****************************************************************
void RF433_DelayTime_Handle(void)
{
    if(RF_Sta.Set_DelayTime > 0u)
    {
        if(--RF_Sta.Set_DelayTime == 0u)
        {
//            BeepLed_OFF();
            RF_Key.Set_Task = RF_Set_Step1;
        }
    }
    if(RF_Sta.AddDel_DelayTime > 0u)
    {
        if(--RF_Sta.AddDel_DelayTime == 0u)
            RF_Key.Set_Task = RF_Set_Step1;
    }
    if(RF_Sta.Rece_DelayTime > 0u)
    {
        RF_Sta.Rece_DelayTime--;
    }

    if(RF_Sta.LongERRTime > 0u)
    {
        if(--RF_Sta.LongERRTime == 0u)
        {
            RF_Sta.LongDownTime = 0u;
        }
    }

    //长按时间判断
    if(RF_Sta.CMD == RF_CMD_UP_TQ || RF_Sta.CMD == RF_CMD_DOWN_TQ)
    {
        if(RF_Sta.LongDownTime > 0u)
        {
            if(RF_Sta.LongDownTime <= RF_LongDownTime_Val)
            {
                if(MOT_Sta.DOT_Flag == 1u)
                {
                    MOT_STOP_Handle();
                }
            }
//            RF_Sta.LongDownTime = 0u;
        }
    }

}
