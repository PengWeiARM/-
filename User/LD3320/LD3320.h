#ifndef __LD3320_H
#define	__LD3320_H

#include "stm32f10x.h"
#include <stdio.h>
#include "./interface/interface.h"
#include "./lcd/bsp_ili9341_lcd.h"
#include "./lcd/bsp_xpt2046_lcd.h"
#include "./Key_Board/Key_Board.h"


typedef struct 
{
  uint16_t start_x;      //按键的x起始坐标  
  uint16_t start_y;      //按键的y起始坐标
  uint16_t end_x;        //按键的x结束坐标 
  uint16_t end_y; 
  char * para;   	     /* 按钮对应的字符 */
  uint8_t touch_flag;    //按键按下的标志
	
  void (*draw_btn)(void * btn);     //按键描绘函数
  void (*btn_command)(void * btn);  //按键功能执行函数
} Touch_Button_ASR;

extern Touch_Button_ASR button_2[2];

extern int Detection_ASR;

void Touch_Button_ASR_Up(uint16_t x,uint16_t y);
void Touch_Button_ASR_Down(uint16_t x,uint16_t y);
void ASR_Init(uint8_t LCD_Mode);
void Touch_Button_ASR_Init(void);
static void Command_Select_ASR(void *btn);
static void Draw_ASR_Button(void *btn);











#endif /*__LD3320_H */
