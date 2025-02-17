#include "User_Tuya.h"


UART_Sta_TypeDef UART_Sta;
Tuya_Sta_TypeDef Tuya_Sta;

uint8_t	    XinTiao_Sta[]	        ={0x55,0xAA,MCU_Version_Num,0x00,0x00,0x01,0x00},   //心跳(反馈)
            WIFI_SC_Sta[]		    ={0x55,0xAA,MCU_Version_Num,0x05,0x00,0x01,0x00},	//配网请求(Smartconfig模式)
            WIFI_AP_Sta[]		    ={0x55,0xAA,MCU_Version_Num,0x05,0x00,0x01,0x01},	//配网请求(AP模式)
            Tuya_Mode_INQ[]         ={0x55,0xAA,MCU_Version_Num,0x02,0x00,0x00},		//查询MCU设定模块工作模式(反馈)
            WIFI_INQ[] 		        ={0x55,0xAA,MCU_Version_Num,0x03,0x00,0x00},	    //报告Wifi工作状态(反馈)
 		    WIFI_Rest[]			    ={0x55,0xAA,MCU_Version_Num,0x04,0x00,0x00},		//重置wifi
            Func_Sta[]			    ={0x55,0xAA,MCU_Version_Num,0x00,0xF0,0x00,0x00},	//应答模组控制命令
 			WIFI_TEST[]			    ={0x55,0xAA,MCU_Version_Num,0x0E,0x00,0x00},		//产测命令
            WIFI_Signal_Strength[]  ={0x55,0xAA,MCU_Version_Num,0x24,0x00,0x00},	//获取Wifi信号强度
 			Check_Time[]		    ={0x55,0xAA,MCU_Version_Num,0x1C,0x00,0x00},		//获取本地时间
 			UpData[]			    ={0x55,0xAA,MCU_Version_Num,0x0A,0x00,0x01,0x00},   //升级启动命令升级包分包传输大小： 0x00：默认 256byte（兼容旧 固件）0x01：512byte 0x02：1024byte
            UpData_Transmit[]       ={0x55,0xAA,MCU_Version_Num,0x0B,0x00,0x00};        //升级包传输命令(反馈)

//查询产品信息(反馈)                {"p":"xawtwtiiacq6hegj","v":"1.0.0","m":0}
uint8_t Product_Information[49]={
    0x55,0xAA,MCU_Version_Num,0x01,0x00,0x2A,
    0x7b,0x22,0x70,0x22,0x3a,0x22,0x78,0x61,0x77,0x74,0x77,0x74,0x69,0x69,0x61,0x63,0x71,0x36,0x68,0x65,0x67,0x6a,0x22,0x2c,
    0x22,0x76,0x22,0x3a,0x22,0x31,0x2e,0x30,0x2e,0x30,0x22,0x2c,0x22,0x6d,0x22,0x3a,0x30,0x7d
};


//指定Wifi信息(Smartconfig模式) {"ssid":"HUAWEI_B311_C255","password":"lym12345678"}
uint8_t Wifi_Information[58]={
    0x55,0xAA,MCU_Version_Num,0x2C,0x00,0x34,
    0x7b,0x22,0x73,0x73,0x69,0x64,0x22,0x3a,0x22,0x48,0x55,0x41,0x57,0x45,0x49,0x5f,0x42,0x33,0x31,0x31,0x5f,0x43,0x32,0x35,
    0x35,0x22,0x2c,0x22,0x70,0x61,0x73,0x73,0x77,0x6f,0x72,0x64,0x22,0x3a,0x22,0x6c,0x79,0x6d,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x22,0x7d
};

//MCU工作状态(反馈)
uint8_t WorkData_ALL[21] = {
	0x55,0xAA,MCU_Version_Num,0x07,0x00,0x0F,//65个数据
	0x01,0x04,0x00,0x01,0x01,//电机控制
	0x0C,0x05,0x00,0x01,0x00,//故障报警
	0x65,0x01,0x00,0x01,0x00,//灯光
};

//****************************************************************
//功能描述：LPUART 初始化
//输入参数：无
//返 回 值：无
//****************************************************************
void User_LPUART_Init(void)
{
    stc_gpio_init_t stcGpioInit = {0};
    stc_lpuart_init_t  stcInit = {0};
    //端口初始化
    ///< 外设时钟使能
    SYSCTRL_PeriphClkEnable(SYSCTRL_PERICLK_PA);

    GPIO_PA02_SET();
    stcGpioInit.u32Mode = GPIO_MODE_OUTPUT_PP;
//    stcGpioInit.u32Mode = GPIO_MODE_INPUT;
    stcGpioInit.u32Pin  = GPIO_PIN_02;
    stcGpioInit.u32Pull = GPIO_PULL_UP;
    GPIOA_Init(&stcGpioInit);

    stcGpioInit.u32Mode = GPIO_MODE_INPUT;
    stcGpioInit.u32Pin  = GPIO_PIN_01;
    GPIOA_Init(&stcGpioInit);

    GPIO_PA02_AF_LPUART0_TXD_SET();
    GPIO_PA01_AF_LPUART0_RXD_SET();

    //UART初始化
    ///<外设模块时钟使能
    SYSCTRL_PeriphClkEnable(SYSCTRL_PERICLK_LPUART0);

    ///<LPUART 初始化
    stcInit.u32StopBits    = LPUART_STOPBITS_1;            ///< 1停止位
    stcInit.u32Parity      = LPUART_PARITY_NONE;           ///< 无校验
    stcInit.u32FrameLength = LPUART_FRAME_LEN_8BITS;       ///< 帧长8位
    stcInit.u32TransMode   = LPUART_MODE_TX_RX;            ///< 发送模式
    stcInit.stcBaudRate.u32SclkSrc  = LPUART_CLKSRC_PCLK;  ///< 传输时钟源
    stcInit.stcBaudRate.u32Sclk     = SYSCTRL_GetPCLK();   ///< PCLK获取
    stcInit.stcBaudRate.u32BaudRate = 9600;                ///< 波特率

    LPUART_Init(LPUART0, &stcInit);

    LPUART_ClearIrq(LPUART0, LPUART_FLAG_ALL);
    LPUART_EnableIrq(LPUART0, LPUART_INT_RC);
    EnableNvic(LPUART0_IRQn, IrqLevel2, TRUE);
}

//****************************************************************
//功能描述：LPUART 发送单字节数据
//输入参数：*pu8Buf 待发送数据缓冲区
//返 回 值：无
//****************************************************************
void LPUART_Send_SingleBuf(uint8_t pu8Buf)
{
    LPUART_Transmit(LPUART0, &pu8Buf, 1, 0xFFFFFF);
}

void LpUart0_IRQHandler(void)
{
	static uint8_t Get_Uart_Count; //得到本次接收信号长度

    //接收
    if(LPUART_GetFlag(LPUART0, LPUART_FLAG_RC))
    {
        if(LPUART_GetFlag(LPUART0, LPUART_FLAG_PE|LPUART_FLAG_FE))
        {
            ///< 错误处理……
            LPUART_ClearIrq(LPUART0, LPUART_FLAG_PE|LPUART_FLAG_FE);
        }
        else
        {
            LPUART_ReceiveIT(LPUART0, &UART_Sta.RX_Buf[UART_Sta.RxNum]);
            LPUART_ClearIrq(LPUART0, LPUART_FLAG_RC);

            UART_Sta.XD_Count = 10u;	//消抖用10MS

            if(UART_Sta.RxNum == 0u) //帧头1号位数据
            {
                if(UART_Sta.RX_Buf[0u] == 0x55u) UART_Sta.RxNum = 1u; //8位数据正确
                else UART_Sta.RxNum = 0u; //错误等待下一次数据
            }
            else if(UART_Sta.RxNum == 1u) //帧头2号位数据
            {
                if(UART_Sta.RX_Buf[1u] == 0xAAu) UART_Sta.RxNum = 2u; //8位数据正确
                else UART_Sta.RxNum = 0u; //错误等待下一次数据
            }
            else if(UART_Sta.RxNum == 2u) //帧头3号位数据
            {
                if(UART_Sta.RX_Buf[2u] == Tuya_Version_Num) UART_Sta.RxNum = 3u; //8位数据正确
                else UART_Sta.RxNum = 0u; //错误等待下一次数据
            }
            else if(UART_Sta.RX_Buf[0u] == 0x55u && UART_Sta.RX_Buf[1u] == 0xAAu && UART_Sta.RX_Buf[2u] == Tuya_Version_Num) //帧头正确
            {
                if(UART_Sta.RxNum == 4u) //判断我需要接收的数据高位
                {
                    Get_Uart_Count = UART_Sta.RX_Buf[4u];Get_Uart_Count = Get_Uart_Count << 8u;
                }else
                if(UART_Sta.RxNum == 5u) //判断我需要接收的数据低位
                {
                    Get_Uart_Count |= UART_Sta.RX_Buf[5u];  //得到本次信号数据长度
                }else
                if(UART_Sta.RxNum != 4u && UART_Sta.RxNum != 5u)
                {
                    if(UART_Sta.RxNum == Get_Uart_Count + 6u)
                    {
                        UART_Sta.RxNum = 0u;
                        UART_Sta.RX_Finish_Flag = 1u;//全部数据读取完毕

                    }
                    // NOP1();
                }
                UART_Sta.RxNum++;
            }
            else
                UART_Sta.RxNum = 0u; //错误等待下一次数据
    //		UART_Sta.RX_Buf[UART_Sta.RxNum++]= SBUF;
    //		if(UART_Sta.RxNum >= RX_Buf_Len_Max)
    //		{
    //			UART_Sta.RxNum = 0u;
    //		}


//            UART_Sta.RX_Finish_Flag = 1u;
            // LPUART_EnableIrq(LPUART0, LPUART_INT_TXE);
            // LPUART_DisableIrq(LPUART0, LPUART_INT_RC);
        }
    }
}

//****************************************************************
//功能描述：串口消抖程序
//输入参数：无
//返 回 值：无
//****************************************************************
void Uart_Data_Pro(void)
{
	if(UART_Sta.XD_Count != 0u) //避免错位读值
	{
	    UART_Sta.XD_Count--;
		if(UART_Sta.XD_Count == 0u)
		{
		    UART_Sta.RX_Finish_Flag = 0u;UART_Sta.RxNum = 0u;
		}
	}
}

//****************************************************************
//功能描述：发送数据给涂鸦模组
//输入参数：pu8Buf 待发送数据缓冲区
//返 回 值：无
//****************************************************************
void SendBuf_For_Tuya(uint8_t* pu8Buf)
{

	uint16_t lrc=0u; //校验码 帧头版本校验和为0
	uint8_t Send_Time=0u; //发送次数
	uint8_t i=0u;

	LPUART_Send_SingleBuf(0X55u);
	LPUART_Send_SingleBuf(0XAAu);//发送帧头
	LPUART_Send_SingleBuf(MCU_Version_Num);//发送版本

	lrc = 0X55u + 0XAAu + MCU_Version_Num; //帧头版本校验和

	Send_Time = ((pu8Buf[4u] << 8u) | pu8Buf[5u]) + 6u; //需要发送的数据长度

	for(i=3u; i<Send_Time; i++) //发送数据位
	{
		LPUART_Send_SingleBuf(pu8Buf[i]);
		lrc = lrc + pu8Buf[i];
	}
	LPUART_Send_SingleBuf(lrc&0xffu);//发送校验和
}

//****************************************************************
//功能描述：涂鸦数据接受处理
//输入参数：pu8Buf 待发送数据缓冲区
//返 回 值：无
//****************************************************************
void RcecBuf_For_Tuya_Handle(void)
{
	uint8_t Rece_Time=0u; //接收次数
	uint8_t x=0u;
	uint16_t lrc=0u; //校验和

    if(UART_Sta.RX_Finish_Flag == 0u)
        return;
    UART_Sta.RX_Finish_Flag = 0u;

    Rece_Time = (uint16_t)(UART_Sta.RX_Buf[4u]<<8u | UART_Sta.RX_Buf[5u]) + 7u; //总数据长度
    for(x=0u; x<Rece_Time-1u; x++)  //得到校验和
    {
        lrc = lrc + UART_Sta.RX_Buf[x]; lrc = lrc & 0xff;
    }

    if(lrc!=UART_Sta.RX_Buf[Rece_Time-1u])	//最后校验没有对上 清掉所有数据
    {
        for(x=0u; x!=RX_Buf_Len_Max; x++)
        {
            UART_Sta.RX_Buf[x] = 0u;
        }
        return;
    }

    switch(UART_Sta.RX_Buf[3u]) //判断命令码
    {
        case T_XinTiao://模组发送心跳（需应答）
                if(Tuya_Sta.Wifi_XinTiao_Firsh_Flag == 0u)//第一次心跳包
                {
                    XinTiao_Sta[6u] = 0x00u;
                }
                else
                    XinTiao_Sta[6u] = 0x01u;
                SendBuf_For_Tuya(XinTiao_Sta);

//                if(Tuya_Sta.Wifi_XinTiao_Firsh_Flag == 0u)//第一次心跳包
//                    SendBuf_For_Tuya(Product_Information);

                Tuya_Sta.Wifi_XinTiao_Firsh_Flag = 1u;
                break;
        case T_Product_Information://查询产品信息
            SendBuf_For_Tuya(Product_Information);
            break;
        case T_WIFI_WORK_STA://报告Wifi工作状态
            switch(UART_Sta.RX_Buf[6u])
            {
                case 0x00u://Smartconfig模式
                    Tuya_Sta.Wifi_Finish_Flag = 0u;
                    Tuya_Sta.Wifi_Connect_Flag = 1u;
                    // BeepLed_Set(5u,300u);
                    break;
                case 0x01u://AP模式
                    // Tuya_Sta.Wifi_Finish_Flag = 0u;
                    // BeepLed_Set(5u,60u);
                    break;
                case 0x02u://连上Wifi但未连接路由
                    Tuya_Sta.Wifi_Connect_Flag = 0u;
                    // BeepLed_Set(2u,150u);
                    break;
                case 0x03u://WIFI已配置并且连上路由
                    // Tuya_Sta.Wifi_Connect_Flag = 1u;
                    // Tuya_Sta.Wifi_Finish_Flag = 0u;
                case 0x04u://连上路由并连接到平台
                    Tuya_Sta.Check_Flag = 1u;
                    Tuya_Sta.Wifi_Report_Time = 0u;
                    Tuya_Sta.Wifi_Finish_Flag = 1u;
                    Tuya_Sta.Wifi_Connect_Flag = 0u;
                    BeepLed_Set(1u,5u);
                    break;
            }
            SendBuf_For_Tuya(WIFI_INQ);
            break;
        case T_Module_INQ://查询MCU设定模块工作模式
            SendBuf_For_Tuya(Tuya_Mode_INQ);
            break;

		case T_WIFI_SSID://产测
        	if(UART_Sta.RX_Buf[6]==0x01u && UART_Sta.RX_Buf[7] >= 60u)//信号强度大于60%
            {
                BeepLed_Set(2u,5u); //成功进入产测
            }
            else
            {
                BeepLed_Set(1u,5u);//失败
            }
            break;
        // case T_WIFI_Signal_Strength://获取WIFI信号强度
        //     if(UART_Sta.RX_Buf[6u] <= 256u-10u && UART_Sta.RX_Buf[6u] != 0u) //信号强度-10db
        //     {
        //         BeepLed_Set(2u,5u); //成功进入产测
        //     }
        //     else
        //     {
        //         BeepLed_Set(1u,5u);//失败
        //     }
        //     break;
        case T_Check_Time://获取本地时间
        	if(UART_Sta.RX_Buf[6u] == 1u)
            {
                Tuya_Sta.Year=UART_Sta.RX_Buf[7u]; 		//年 成功取值 使用需要 + 2000
                Tuya_Sta.Mouth=UART_Sta.RX_Buf[8u]; 	//月
                Tuya_Sta.Day=UART_Sta.RX_Buf[9u]; 		//日
                Tuya_Sta.Hour=UART_Sta.RX_Buf[10u]; 	//时
                Tuya_Sta.Minute=UART_Sta.RX_Buf[11u];	//分
                Tuya_Sta.Second=UART_Sta.RX_Buf[12u];	//秒
                Tuya_Sta.Week=UART_Sta.RX_Buf[13u]; 	//周
                //Aim_Time=Hour*60+Minute; //目标时间
            }
            else
            {
                // _nop_(); //失败
            }
            SendBuf_For_Tuya(Check_Time);
            break;
        case T_Send_Func://功能上报
            Tuya_Sta.Check_Flag = 1u;
            Tuya_Sta.Wifi_Report_Time = 0u;
            break;
        case T_Get_Func://功能处理
            if(UART_Sta.RX_Buf[6u] == T_Control)//电机控制
            {
                if(UART_Sta.RX_Buf[10u] == Wifi_Control_Open)
                {
//                    if(MOT_Sta.FX == 0u)
                        MOT_UP_Handle();
//                    else if(MOT_Sta.FX == 1u)
//                        MOT_DOWN_Handle();
                }
                else if(UART_Sta.RX_Buf[10u] == Wifi_Control_Stop)
                {
                    MOT_STOP_Handle();
                }
                else if(UART_Sta.RX_Buf[10u] == Wifi_Control_Close)
                {
//                    if(MOT_Sta.FX == 0u)
                        MOT_DOWN_Handle();
//                    else if(MOT_Sta.FX == 1u)
//                        MOT_UP_Handle();
                }
            }
            else if(UART_Sta.RX_Buf[6u] == T_Light)//灯光
            {
                if(UART_Sta.RX_Buf[10u] == Wifi_Light_ON)
                    Light_Control_Handle(1u);
                else if(UART_Sta.RX_Buf[10u] == Wifi_Light_OFF)
                    Light_Control_Handle(0u);
            }
            // Tuya_Sta.Check_Flag = 1u;
            // Tuya_Sta.Wifi_Report_Time = 0u;
            break;
        case T_Module_Updata://升级启动命令
            // switch(UART_Sta.RX_Buf[8])
            // {
            // 	case 0x00://无需升级
            // 		UpData[8] = 0x01;
            // 		break;
            // 	case 0x10://有固件升级
            // 		UpData[8] = 0x11;
            // 		break;
            // 	case 0x20://进入YMODEN模式
            // 		UpData[8] = 0xccccc;
            // 		break;
            // 	case 0x30://升级固件校验结果正确
            // 		UpData[8] = 0x31;
            // 		break;
            // 	case 0x40://升级固件校验结果失败
            // 		UpData[8] = 0x41;
            // 		break;
            // }
            SendBuf_For_Tuya(UpData);
            break;
        case T_Module_Updata_Next://升级包传输命令
            SendBuf_For_Tuya(UpData_Transmit);
            break;
        default:break;
    }

}

//****************************************************************
//功能描述：反馈查询程序
//输入参数：无
//返 回 值：无
//****************************************************************
void Check_MCU_Pro(void)
{
	if(Tuya_Sta.Check_Flag)
	{
        //电机控制
        if(MOT_Sta.Now_Sta == MOT_Open_Sta)
        {
            if(MOT_Sta.FX == 0u)
                WorkData_ALL[10u] = Wifi_Control_Open;
            else if(MOT_Sta.FX == 1u)
                WorkData_ALL[10u] = Wifi_Control_Close;
        }
        else if(MOT_Sta.Now_Sta == MOT_Stop_Sta)
        {
            WorkData_ALL[10u] = Wifi_Control_Stop;
        }
        else if(MOT_Sta.Now_Sta == MOT_Close_Sta)
        {
            if(MOT_Sta.FX == 0u)
                WorkData_ALL[10u] = Wifi_Control_Close;
            else if(MOT_Sta.FX == 1u)
                WorkData_ALL[10u] = Wifi_Control_Open;
        }

        //报警处理
        WorkData_ALL[15u] = Wifi_ERR_OK;

        //灯光
        if(Light_Sta.Now_Sta == Light_ON_Sta)
            WorkData_ALL[20u] = Wifi_Light_ON;
        else if(Light_Sta.Now_Sta == Light_OFF_Sta)
            WorkData_ALL[20u] = Wifi_Light_OFF;

		SendBuf_For_Tuya(WorkData_ALL);
		Tuya_Sta.Check_Flag = 0u;
	}
}

//****************************************************************
//功能描述：WIFI间隔上报    (1s进入一次)
//输入参数：无
//返 回 值：无
//****************************************************************
void WIFI_Report_Handle(void)
{
    if(Tuya_Sta.Wifi_Finish_Flag == 1u)
    {
        if(++Tuya_Sta.Wifi_Report_Time >= Wifi_Report_Time_Val)
        {
            Tuya_Sta.Wifi_Report_Time = 0u;
            Tuya_Sta.Check_Flag = 1u;
        }
    }
}

