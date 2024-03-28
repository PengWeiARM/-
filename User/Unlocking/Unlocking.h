#ifndef _UNLOCKING_H
#define _UNLOCKING_H

#include "stm32f10x.h"



void Unlocking_Init(int ret);

extern int count_value;
extern char passWord[6];
extern char passWord_1[];

extern int Detection_Screen;
extern int Detection_Finger;
void Delay(uint32_t count);

#endif //_UNLOCKING_H
