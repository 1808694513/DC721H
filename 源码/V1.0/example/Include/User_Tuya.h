#ifndef __USER_TUYA_H__
#define __USER_TUYA_H__

#include "User_Include.h"

#define RX_Buf_Len_Max          20u      ///< 接受数据缓冲区最大长度
#define TX_Buf_Len_Max          20u     ///< 发送数据缓冲区最大长度

#define Tuya_Version_Num        0x00u   //Tuya版本号
#define MCU_Version_Num         0x03u   //MCU版本号

#define Wifi_Report_Time_Val    60u     //上报时间间隔(1m)


//================Wifi_Mode_to_MCU================
//接收WifiMode数据  CMD

#define T_XinTiao 					0x00    //心跳
#define T_Product_Information       0x01    //查询产品信息
#define T_Module_INQ 				0x02    //查询MCU设定模块工作模式
#define T_WIFI_WORK_STA 			0x03    //报告Wifi工作状态
#define T_Module_Updata 			0x0A    //模组通知MUC升级
#define T_Module_Updata_Next 		0x0B    //升级包传输
#define T_Check_Time 			    0x1C    //获取本地时间
#define T_WIFI_SSID 			    0x0E    //WIFI 产测
#define T_WIFI_Signal_Strength      0x24    //获取WIFI信号强度
#define T_Send_Func                 0x08    //上报功能数据
#define T_Get_Func 				    0x06    //功能数据下发处理

//WifiMode接收功能
#define	T_Control				    0x01	//电机控制
#define	T_Light					    0x65	//灯光

//WifiMode功能控制
#define	Wifi_Control_Open           0x00    //开
#define	Wifi_Control_Stop           0x01    //停止
#define	Wifi_Control_Close          0x02    //关
#define	Wifi_Control_Continue       0x03    //持续

#define Wifi_ERR_ERR                0x01    //错误
#define Wifi_ERR_OK                 0x00    //正常

#define Wifi_Light_OFF              0x00    //关灯
#define Wifi_Light_ON               0x01    //开灯


//=========================================Code_For_WifiMode============================================
extern  uint8_t	XinTiao_Sta[],          //心跳(反馈)
                WIFI_SC_Sta[],	        //配网请求(Smartconfig模式)
                WIFI_AP_Sta[],	        //配网请求(AP模式)
                Tuya_Mode_INQ[],	    //查询MCU设定模块工作模式(反馈)
                WIFI_INQ[],	            //报告Wifi工作状态(反馈)
 		        WIFI_Rest[],		    //重置wifi
                Func_Sta[],	            //应答模组控制命令
 			    WIFI_TEST[],		    //产测命令
                WIFI_Signal_Strength[], //获取WIFI信号强度
 			    Check_Time[],		    //获取本地时间
 			    UpData[],               //升级启动命令
                UpData_Transmit[];      //升级包传输命令(反馈)

extern uint8_t Product_Information[49];    //查询产品信息(反馈) {"p":"xawtwtiiacq6hegj","v":"1.0.0","m":0}
extern uint8_t Wifi_Information[58];       //指定Wifi信息(Smartconfig模式) {"ssid":"HUAWEI_B311_C255","password":"lym12345678"}
//#define INIT_DATA_MAX 13 //数据长度
//#define INIT_DATA_MIN 12 //数据长度

extern uint8_t WorkData_ALL[21];                            //MCU工作状态(反馈)


typedef struct
{
    union
    {
        uint8_t Byte;
        struct
        {
            uint8_t RX_Finish_Flag          :1;         //接收完成标志位
            uint8_t                         :7;         //预留位
        };
    };

    uint8_t RX_Buf_Len;                     //接受数据长度
    uint8_t RX_Buf_Pos;                     //接受数据指针
    uint8_t RX_Buf[RX_Buf_Len_Max];        //接受数据缓冲区

    uint8_t XD_Count;                       //接收消抖
    uint8_t RxNum;                       //接收到的数据位

}UART_Sta_TypeDef;

typedef struct
{
    union
    {
        uint8_t Byte;
        struct
        {
            uint8_t Check_Flag;                         //反馈查询标志位
            uint8_t Wifi_Connect_Flag;                  //设备联网中标志位
            uint8_t Wifi_Finish_Flag;                   //配网完成标志位
            uint8_t Wifi_XinTiao_Firsh_Flag;            //心跳首次标志位
            uint8_t                         :4;         //预留位
        };
    };

    uint8_t Year,Mouth,Week,Day,Hour,Minute,Second; //获取本地时间

    uint16_t Wifi_Report_Time;                    //上报时间间隔


}Tuya_Sta_TypeDef;

//供外部使用
extern UART_Sta_TypeDef UART_Sta;
extern Tuya_Sta_TypeDef Tuya_Sta;

void User_LPUART_Init(void);//LPUART 初始化
void LPUART_Send_SingleBuf(uint8_t pu8Buf);//LPUART 发送单字节数据
void Uart_Data_Pro(void);//串口消抖程序
void SendBuf_For_Tuya(uint8_t* pu8Buf);//发送数据给涂鸦模组
void RcecBuf_For_Tuya_Handle(void);//涂鸦数据接受处理
void Check_MCU_Pro(void);  //反馈查询程序
void WIFI_Report_Handle(void);//WIFI间隔上报

#endif /* __USER_TUYA_H__ */
