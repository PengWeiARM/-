#ifndef _CHANGE_PASSWORD_H
#define _CHANGE_PASSWORD_H


#include "./Key_Board/Key_Board.h"



#define BUTTON_NUM_CHANGE 15




extern int interface;
extern Touch_Button button_change[15];


void Key_Board_Change_Init(uint8_t LCD_Mode);
void Touch_Button_Change_Init(void);
void Touch_Button_Change_Up(uint16_t x,uint16_t y);
void Command_Select_Key_Change(void *btn);
void Draw_Key_Change_Button(void *btn);
void Touch_Button_Change_Down(uint16_t x,uint16_t y);
void Draw_Key_Change_Button_1(void *btn);



#endif //_CHANGE_PASSWORD_H
