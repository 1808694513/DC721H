#include "User_Flash.h"

FLASH_Save_TypeDef FLASH_Save;

//****************************************************************
//功能描述：FLASH 单字写
//输入参数：addr:偏移地址   data:写入数据
//返 回 值：无
//****************************************************************
void Flash_Write_Word(uint32_t addr, uint32_t data)
{
	uint8_t i = 0;  
    en_result_t res = Error;
	__disable_irq();  
//	if (Flash_Read_Word(addr) != 0xFFFFFFFF) //若不为0xFF
//	{
		for (i = 0; i < 128u; i++) //临时保存
		{
           FLASH_Save.Flash_Data[i] = *(volatile uint32_t *)(Flash_Addr_Base + i * 4u);
		}
		FLASH_Save.Flash_Data[addr / 4u] = data; //把值保存进临时值
		while(res != Ok)
		{
            FLASH_SectorErase(Flash_Addr_Base);
            res = FLASH_WriteWord(Flash_Addr_Base, FLASH_Save.Flash_Data,128u);
		}

		//FLASH_WriteWord(Flash_Addr_Base, FLASH_Save.Flash_Data,128u) = Ok;
//	}
//	else
//	{
//    	res = FLASH_WriteWord(Flash_Addr_Base + addr, &data, 1u);
//	}
	__enable_irq();
}

//****************************************************************
//功能描述：FLASH 单字读
//输入参数：addr:偏移地址
//返 回 值：读取到的数据
//****************************************************************
uint32_t Flash_Read_Word(uint32_t addr)
{
	uint32_t Value;

	Value = *(volatile uint32_t *)(Flash_Addr_Base + addr);
	return Value;
}

//****************************************************************
//功能描述：RF433地址码读取地址处理
//输入参数：无
//返 回 值：无
//****************************************************************
void Flash_Read_RF433_Handle(void)
{
    uint8_t i=0u;
    RF_Key.Addr_Tab = (uint8_t)Flash_Read_Word(EE_Save_Sys2_Addr);
    if(RF_Key.Addr_Tab >= RF_MAX_Flash)
        RF_Key.Addr_Tab = 0u;
    for(i=0u;i<RF_MAX_Flash;i++)
    {
        RF_Sta.RF_Flash[i].Addr = Flash_Read_Word(EE_Save_RF433_Addr + i * 8u) & 0xFFFFFFF0u;
        RF_Sta.RF_Flash[i].Channel = Flash_Read_Word(EE_Save_RF433_Addr + i * 8u) & 0x0000000Fu;
        RF_Sta.RF_Flash[i].Synchronization_Word = Flash_Read_Word(EE_Save_RF433_Addr + i * 8u + 4u);
    }
    //读取对码标志
    // RF_Sta.Check = (uint8_t)Flash_Read_Word(EE_Save_RF433_Check_FLAG);
    // if(RF_Sta.Check == RF_Check_OK)
    // {
    //     //读取地址高28位,通道号低4位    (对码地址)
    //     RF_Key.Check_Addr = Flash_Read_Word(EE_Save_RF433_Check_Addr) & 0xFFFFFF00u;
    //     RF_Key.Check_Channel = Flash_Read_Word(EE_Save_RF433_Check_Addr) & 0x000000FFu;
    // }
}

//****************************************************************
//功能描述：FLASH 写入处理
//输入参数：无
//返 回 值：无
//****************************************************************
void Flash_Write_Handle(void)
{
    uint8_t i=0u;
	uint32_t temp=0;
	if(FLASH_Save.Flash_Flag == 0u)
		return;
	FLASH_Save.Flash_Flag = 0u;

    // FLASH_SectorErase(Flash_Addr_Base);
    // Flash_Write_Word(EE_Save_Sys0_Addr,0x55u);
	for(i=0u; i<RF_MAX_Flash; i++)
	{
        //保存地址高28位,通道号低4位
        Flash_Write_Word(EE_Save_RF433_Addr + i * 8u,(RF_Sta.RF_Flash[i].Addr | RF_Sta.RF_Flash[i].Channel));
        //保存同步字高24位
        Flash_Write_Word(EE_Save_RF433_Addr + i * 8u + 4u,RF_Sta.RF_Flash[i].Synchronization_Word);
	}
//	//保存地址高28位,通道号低4位    (对码地址)
//	Flash_Write_Word(EE_Save_RF433_Check_Addr,RF_Key.Check_Addr | RF_Key.Check_Channel);
//	//保存对码标志
//	Flash_Write_Word(EE_Save_RF433_Check_FLAG,RF_Sta.Check);
	//存储缓冲区下标低8位
	Flash_Write_Word(EE_Save_Sys2_Addr,(uint32_t)RF_Key.Addr_Tab);

	//存储电机数据
    temp = 0xFFFFFF00 | (uint32_t)(MOT_Sta.FX);
    Flash_Write_Word(EE_Save_Sys1_Addr, temp);

}

//****************************************************************
//功能描述：FLASH 上电读取处理   (上电读取一次)
//输入参数：无
//返 回 值：无
//****************************************************************
void Flash_PowerON_Read_Handle(void)
{
    uint8_t i=0u;
	uint32_t temp=0u;


    temp = Flash_Read_Word(EE_Save_Sys0_Addr);
    if((uint8_t)temp != ERR_Once_Temp_Val)
    {
        FLASH_SectorErase(Flash_Addr_Base);
        Flash_Write_Word(EE_Save_Sys0_Addr, ERR_Once_Temp_Val);
        //第一次上电所有保存值初始化为0xff
        for(i=0; i<RF_MAX_Flash; i++)
        {
            RF_Sta.RF_Flash[i].Addr = 0xFFFFFFFFu;
            RF_Sta.RF_Flash[i].Channel = 0xFFu;
            RF_Sta.RF_Flash[i].Synchronization_Word = 0xFFFFFFFFu;
        }
        RF_Sta.Check = RF_Check_ERR;
        RF_Key.Check_Addr = 0xFFFFFFFFu;
        RF_Key.Check_Channel = 0xFFu;
        RF_Key.Check_Tab = 0x00u;
        
        //首次上电写入默认地址
        Flash_Write_Word(EE_Save_RF433_Addr,0x20140C03);//地址码 出厂默认普通码
//        Flash_Write_Word(EE_Save_RF433_Addr,0x20200501);//地址码 出厂默认新滚码
        Flash_Write_Word(EE_Save_RF433_Addr+4u,0x00000000);//同步码
        
        RF_Sta.RF_Flash[0].Addr = 0x20140C00;
        RF_Sta.RF_Flash[0].Channel = 0x03u;
        RF_Sta.RF_Flash[0].Synchronization_Word = 0x00000000u;
        
        //调试时写入缓冲区下标为1 防止读取到0xff缓冲区溢出
        RF_Key.Addr_Tab = 0x01u;
        Flash_Write_Word(EE_Save_Sys2_Addr,(uint32_t)RF_Key.Addr_Tab);
        
        //调试时写入电机正反转为0 防止读取到0xff导致电机反转
        MOT_Sta.FX = 0x00u;
        Flash_Write_Word(EE_Save_Sys1_Addr,(uint32_t)MOT_Sta.FX);
    }
    else
    {
        //读RF433地址保存数据
        Flash_Read_RF433_Handle();
        //读MOT参数保存数据
        MOT_Sta.FX = (uint8_t)(Flash_Read_Word(EE_Save_Sys1_Addr));	//电机方向
    }

    //读完后立马保存一次
//    FLASH_Save.Flash_Flag = 1u;
}
