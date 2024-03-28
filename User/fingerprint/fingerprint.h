#ifndef _fingerprint_H
#define _fingerprint_H

#include "stm32f10x.h"
#include "./lcd/bsp_ili9341_lcd.h"
#include "./lcd/bsp_xpt2046_lcd.h"
#include "./as608/as608_test.h"
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
  void (*btn_command)(void * btn);  //按键功能执行函数
} Touch_Button_Finger;



extern uint32_t Finger_num;
extern Touch_Button_Finger button_1[5];
extern int Detection_Finger;


void Draw_Finger_Button(void *btn);
void Touch_Button_Finger_Init(void);
void Finger_Init(uint8_t LCD_Mode);
void Touch_Button_Finger_Down(uint16_t x,uint16_t y);
void Command_Select_Finger(void *btn);
void Touch_Button_Finger_Up(uint16_t x,uint16_t y);



#endif //_fingerprint_H

