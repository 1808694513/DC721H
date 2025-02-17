#ifndef __USER_IWDT_H__
#define __USER_IWDT_H__

#include "User_Include.h"

#define dog()       IWDT_Feed()

void User_WDT_Init(void);

#endif /* __USER_IWDT_H__ */
