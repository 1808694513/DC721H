#ifndef __USER_CRC_H__
#define __USER_CRC_H__

#include "User_Include.h"

#define TEA_LOOP_TIME (32)
extern const uint32_t TEA_Key[4];
extern const uint32_t TEA_ID;


unsigned int Get_CRC16(unsigned char *Buff_addr,unsigned char len);
unsigned int CRC16_MODBUS(unsigned char *puchMsg, unsigned int usDataLen);
uint8_t CRC8_Cal(uint8_t *ptr, uint8_t len);
void TEA_EnCode(unsigned char *Teabuf, unsigned char *buf);
void TEA_DeCode(uint8_t *buf, uint8_t *Teabuf);

#endif /* __USER_CRC_H__ */
