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
  uint16_t start_x;      //������x��ʼ����  
  uint16_t start_y;      //������y��ʼ����
  uint16_t end_x;        //������x�������� 
  uint16_t end_y; 
  char * para;   	     /* ��ť��Ӧ���ַ� */
  uint8_t touch_flag;    //�������µı�־
	
  void (*draw_btn)(void * btn);     //������溯��
  void (*btn_command)(void * btn);  //��������ִ�к���
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
