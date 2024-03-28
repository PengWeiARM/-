#ifndef _FINGER_ID_H
#define _FINGER_ID_H

#include "./Key_Board/Key_Board.h"




#define BUTTON_NUM_ID 15


extern int perform;
extern uint32_t key_num;
extern int interface;
extern Touch_Button button_ID[15];


void Key_Board_ID_Init(uint8_t LCD_Mode);
void Touch_Button_ID_Init(void);
void Touch_Button_ID_Up(uint16_t x,uint16_t y);
void Command_Select_Key_ID(void *btn);
void Draw_Key_ID_Button(void *btn);
void Touch_Button_ID_Down(uint16_t x,uint16_t y);


#endif //_FINGER_ID_HH

