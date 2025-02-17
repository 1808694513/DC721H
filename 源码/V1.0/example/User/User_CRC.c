#include "User_CRC.h"

//****************************************************************
//功能描述：CRC16
//输入参数：无
//输出参数：无
//****************************************************************
unsigned int Get_CRC16(unsigned char *Buff_addr,unsigned char len)
{
    unsigned char i,flage;
    unsigned int Data_Crc = 0xFFFF;                 // CRC校验初值

    while (len--)
    {
        Data_Crc ^= *Buff_addr;
        for(i = 0u;i < 8u;i++)
        {
            flage = Data_Crc & 0x0001;
            Data_Crc >>= 1u;
            if(!flage)
            {
                continue;
            }
            else
            {
                Data_Crc ^= 0xA001;
        	}
        }
        Buff_addr++;
    }
    return Data_Crc;
}

//****************************************************************
//功能描述: WIFI_MODBUS校验
//输入参数：无
//输出参数：无
//****************************************************************
unsigned int CRC16_MODBUS(unsigned char *puchMsg, unsigned int usDataLen)
{
	uint16_t wCRCin = 0xFFFF;
	int16_t wCPoly = 0x8005;
	uint8_t wChar = 0;
	uint8_t i = 0;

	 while (usDataLen--)
	 {
		 wChar = *(puchMsg++);
		 wCRCin ^= (wChar << 8);

		 for(i = 0; i < 8; i++)
		 {
			 if(wCRCin & 0x8000)
			 {
				wCRCin = (wCRCin << 1) ^ wCPoly;
			 }
			 else
			 {
				wCRCin = wCRCin << 1;
			 }
		 }
	 }
	 return (wCRCin);
}


/*************************************************************************
** 函数名称：	               433CRC8校验
** 输入参数：
** 返回参数：
** 调用方式：
** 函数说明：ptr 数组指针   len 字符个数
**************************************************************************/
uint8_t CRC8_Cal(uint8_t *ptr, uint8_t len)
{
	uint8_t crc = 0;
	uint8_t i;
	while (len--)
	{
		crc ^= *ptr++;
		for (i = 0; i < 8; i++)
		{
			if (crc & 0x01)
			{
				crc = (crc >> 1) ^ 0x8C;
			}
			else
			{
				crc >>= 1;
			}
		}
	}
	return crc;
}

//const uint32_t TEA_Key[4] = {0xB7FAE432, 0x76B9DAF5, 0xAC540F39, 0x659D1F68};//测试用
const uint32_t TEA_Key[4] = {0x54A65D4C,0xE765FC35,0x968DE1E8,0xF875B98A}; //新杜亚
const uint32_t TEA_ID = 0x9E3779B9;

void TEA_EnCode(unsigned char *Teabuf, unsigned char *buf)
{
    uint32_t y = 0, z = 0, sum = 0;
    uint8_t i = 0;
    // y = (*(src  )<<24 | *(src+1) << 16 | *(src+2) << 8 | *(src+3));
    y = buf[0];
    y = (y << 8) + buf[1];
    y = (y << 8) + buf[2];
    y = (y << 8) + buf[3];

    // z = (*(src+4)<<24 | *(src+5) << 16 | *(src+6) << 8 | *(src+7));
    z = buf[4];
    z = (z << 8) + buf[5];
    z = (z << 8) + buf[6];
    z = (z << 8) + buf[7];
    sum = 0;

    for (i = 0; i < TEA_LOOP_TIME; i++)
    {
        sum += TEA_ID;
        y += ((z << 4) + TEA_Key[0]) ^ (z + sum) ^ ((z >> 5) + TEA_Key[1]);
        z += ((y << 4) + TEA_Key[2]) ^ (y + sum) ^ ((y >> 5) + TEA_Key[3]);
    }

    Teabuf[0] = (uint8_t)(y >> 24);
    Teabuf[1] = (uint8_t)(y >> 16);
    Teabuf[2] = (uint8_t)(y >> 8);
    Teabuf[3] = (uint8_t)(y);
    Teabuf[4] = (uint8_t)(z >> 24);
    Teabuf[5] = (uint8_t)(z >> 16);
    Teabuf[6] = (uint8_t)(z >> 8);
    Teabuf[7] = (uint8_t)(z);
}


/*************************************************************************
** 函数名称：	               解密算法
** 输入参数：
** 返回参数：
** 调用方式：
** 函数说明：Teabuf:密文储存区  buf:明文储存区
**************************************************************************/
void TEA_DeCode(uint8_t *buf, uint8_t *Teabuf)
{
	uint32_t y = 0, z = 0, sum = 0;
	uint8_t i = 0;
	y = Teabuf[0];
	y = (y << 8) + Teabuf[1];
	y = (y << 8) + Teabuf[2];
	y = (y << 8) + Teabuf[3];

	z = Teabuf[4];
	z = (z << 8) + Teabuf[5];
	z = (z << 8) + Teabuf[6];
	z = (z << 8) + Teabuf[7];

	sum = 0xC6EF3720;
	for (i = 0; i < TEA_LOOP_TIME; i++)
	{
		z -= ((y << 4) + TEA_Key[2]) ^ (y + sum) ^ ((y >> 5) + TEA_Key[3]);
		y -= ((z << 4) + TEA_Key[0]) ^ (z + sum) ^ ((z >> 5) + TEA_Key[1]);
		sum -= TEA_ID;
	}

	buf[0] = (uint8_t)(y >> 24);
	buf[1] = (uint8_t)(y >> 16);
	buf[2] = (uint8_t)(y >> 8);
	buf[3] = (uint8_t)(y);
	buf[4] = (uint8_t)(z >> 24);
	buf[5] = (uint8_t)(z >> 16);
	buf[6] = (uint8_t)(z >> 8);
	buf[7] = (uint8_t)(z);
}
