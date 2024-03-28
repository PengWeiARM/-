#ifndef _INTERFACE_H
#define _INTERFACE_H

#include "./Key_Board/Key_Board.h"
#include "./Change_password/Change_password.h"
#include "./fingerprint/fingerprint.h"
#include "./led/bsp_led.h" 




typedef struct 
{
  uint16_t start_x;      //按键的x起始坐标  
  uint16_t start_y;      //按键的y起始坐标
  uint16_t end_x;        //按键的x结束坐标 
  uint16_t end_y; 
  char * para;   	     /* 按钮对应的字符 */
  uint8_t touch_flag;    //按键按下的标志
	
  void (*draw_btn)(void * btn);     //按键描绘函数
  
} Touch_Button_Interface;



extern Touch_Button_Interface button_0[4];



void Touch_Button_Interface_Up(uint16_t x,uint16_t y);
void Interface_Init(uint8_t LCD_Mode);
void Touch_Button_Interface_Init(void);
void Draw_Interface_Button(void *btn);
void Touch_Button_Interface_Down(uint16_t x,uint16_t y);
void Command_Select_Interface(void *btn);




#endif //_INTERFACE_H
