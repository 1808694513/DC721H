#ifndef __USER_RF433_H__
#define __USER_RF433_H__

#include "User_Include.h"

#define Data_433            ((GPIO_PD04_READ() == GPIO_PIN_04) ? 1u : 0u)

#define Control_433_Time_Val    (60)
#define Start_Once_Val          (2400/Control_433_Time_Val)
#define Start_H_Count_MIN_Val   (4800/Control_433_Time_Val*7/10)
#define Start_H_Count_MAX_Val   (4800/Control_433_Time_Val*13/10)
#define Start_L_Count_MIN_Val   (1500/Control_433_Time_Val*7/10)
#define Start_L_Count_MAX_Val   (1500/Control_433_Time_Val*13/10)
#define Data0_L_Count_MIN_Val   (720/Control_433_Time_Val*7/10)
#define Data0_L_Count_MAX_Val   (720/Control_433_Time_Val*13/10)
#define Data0_H_Count_MIN_Val   (360/Control_433_Time_Val*7/10)
#define Data0_H_Count_MAX_Val   (360/Control_433_Time_Val*13/10)
#define Data1_L_Count_MIN_Val   (360/Control_433_Time_Val*7/10)
#define Data1_L_Count_MAX_Val   (360/Control_433_Time_Val*13/10)
#define Data1_H_Count_MIN_Val   (720/Control_433_Time_Val*7/10)
#define Data1_H_Count_MAX_Val   (720/Control_433_Time_Val*13/10)

#define RF_WEI_Count_Val        (8)
#define DAT_LEN                 (9)  //接收缓冲区数据长度
#define RF_MAX_Flash            (20) //最大保存的遥控器地址数量

#define RF_Addr_Len             (4)  //遥控器地址长度

#define RF_Set_DelayTime_Val        (10000/10) //设置时间 10s
#define RF_AddDel_DelayTime_Val     (10000/10) //添码删码时间 调电机正反转时间 10s
#define RF_Rece_DelayTime_Val       (250/10) //接收间隔时间 250ms


#define RF_LongDownTime_Val          (2000/10) //长按时间 2s
#define RF_LongDownTime_MAX_Val      (10000/10) //长按时间 10s
#define RF_LongERRTime_Val          (500/10) //长按抬起无效时间 500ms




//接收状态机  @ref RF_Task_Typedef
typedef enum
{
    RF_Wait = 0,        //等待接收
    RF_Once,            //开始接收判断
    RF_Start_H,         //接收起始信号高
    RF_Start_L,         //接收起始信号低
    RF_Data,            //接收数据
}RF_Task_Typedef;

//RF433设置状态机  @ref RF_Set_Task_Typedef
typedef enum
{
    RF_Set_Step1 = 0,
    RF_Set_Step2,
    RF_Set_Step3,
    RF_Set_Step4,
    RF_Set_Step5,
    RF_Set_Step6,
}RF_Set_Task_Typedef;

//无线模式  @ref RF_Mode_Typedef
enum
{
    RF_Old_Mode = 0,
    RF_New_Mode,
};

//接收到的命令  @ref RF_CMD_Typedef
enum
{
    RF_CMD_SET = 0xCC,          //设置
    RF_CMD_UP = 0x11,           //开
    RF_CMD_UP_TQ = 0x1E,        //开-抬起
    RF_CMD_DOWN = 0x33,         //关
    RF_CMD_DOWN_TQ = 0x3C,      //关-抬起
    RF_CMD_STOP = 0x55,         //停止
    RF_CMD_LIGHT = 0x0F,        //灯光
    RF_CMD_LIGHT_ON = 0x40,     //灯光开
    RF_CMD_LIGHT_OFF = 0x61,    //灯光关
};

//地址匹配标志  @ref RF_Addr_Match_Typedef
enum
{
    RF_Addr_Match_ERR = 0,
    RF_Addr_Match_OK,
};

//对码标志        @ref RF_Check_Typedef
enum
{
    RF_Check_ERR = 0,
    RF_Check_OK,
};

//接收数据保存  @ref RF_Flash_Typedef
typedef struct
{
    uint32_t Addr;                  //数据地址
    uint32_t Synchronization_Word;  //同步字
    uint8_t Channel;             //接收通道
} RF_Flash_Typedef;

//接收状态信息  @ref RF_State_Typedef
typedef struct
{
    RF_Task_Typedef RF_Task;       //接收状态机  @ref RF_Task_Typedef
    uint8_t RF_Finish;              //接收完成标志
    uint8_t RF_Buf[DAT_LEN];        //接收数据缓冲区
    uint8_t RF_BufBack[DAT_LEN];    //接收数据处理
    RF_Flash_Typedef RF_Flash[RF_MAX_Flash];      //遥控器地址保存  @ref RF_Flash_Typedef
    uint32_t Addr;                  //数据地址
    uint32_t Synchronization_Word;  //同步字    高24位
    uint8_t Channel;             //接收通道

    uint8_t RF_Mode;                //无线模式  @ref RF_Mode_Typedef
    uint8_t RF_DataLen;            //接收的数据长度
    uint8_t CMD;                //接收到的指令   @ref RF_CMD_Typedef
    uint8_t CRC8;                 //接收到的CRC8校验

    uint8_t Addr_Match;               //地址匹配标志    @ref RF_Addr_Match_Typedef
    uint8_t Check;                    //对码标志        @ref RF_Check_Typedef

    uint16_t Set_DelayTime;            //设置时间
    uint16_t AddDel_DelayTime;          //添码删码时间 调电机正反转时间
    uint16_t Rece_DelayTime;            //接收间隔时间

    uint16_t LongDownTime;              //长按时间
    uint16_t LongERRTime;               //长按抬起无效时间

    uint8_t CMD_Before;                 //上次接收到的指令   @ref RF_CMD_Typedef
    uint32_t Addr_Before;                //上次接收到的地址

} RF_State_Typedef;

//功能处理  @ref RF_Key_Typedef
typedef struct
{
    uint8_t Addr_Tab;                    //RF433保存的地址下标值
    RF_Set_Task_Typedef Set_Task;         //RF433设置状态机  @ref RF_Set_Task_Typedef
    uint32_t Check_Addr;                  //RF433对码的地址
    uint32_t Check_Channel;               //RF433对码的通道
    uint8_t Check_Tab;                    //RF433对码的下标值
} RF_Key_Typedef;

//供外部使用
extern RF_State_Typedef RF_Sta;//接收状态
extern RF_Key_Typedef RF_Key;//功能处理

void User_RF433_Init(void);
void RF433_Rece_Handle(uint8_t RFBit);
void RF433_Data_Handle(void);//433接收到数据处理
void RF433_Check_Handle(void);
void RF433_AddDel_Handle(void);
void RF433_Fun_Handle(void);
void RF433_LongFun_Handle(void);
void Flash_Write_Check_AddDel_Handle(uint8_t Val);
void RF433_DelayTime_Handle(void);

#endif /* __USER_RF433_H__ */
