#ifndef _JIANPAN_H
#define _JIANPAN_H

#include "stm32f10x.h"
#include "./lcd/bsp_ili9341_lcd.h"
#include "./lcd/bsp_xpt2046_lcd.h"
#include <stdio.h>
#include <string.h>




#define BUTTON_NUM 15
#define BUTTON_STAY_X  5
#define BUTTON_STAY_Y  90
#define BUTTON_WHITH   70
#define BUTTON_HIGHT   40
#define BUTTON_SpaceX  (5+BUTTON_WHITH) //5+70
#define BUTTON_SpaceY  (5+BUTTON_HIGHT) //5+40








typedef struct 
{
  uint16_t start_x;   //������x��ʼ����  
  uint16_t start_y;   //������y��ʼ����
  uint16_t end_x;     //������x�������� 
  uint16_t end_y; 
  char * para;   	/* ��ť��Ӧ���ַ� */
  uint8_t touch_flag; //�������µı�־
	
  void (*draw_btn)(void * btn);     //������溯��
  void (*btn_command)(void * btn);  //��������ִ�к���
} Touch_Button;

extern char passWord[6];
extern char passWord_0[];
extern int interface;

extern uint32_t key_num;
extern Touch_Button button[15];

void Delay(uint32_t count);
void Key_Board_Init(uint8_t LCD_Mode);
void Touch_Button_Init(void);
void Touch_Button_Down(uint16_t x,uint16_t y);
void Touch_Button_Up(uint16_t x,uint16_t y);
void Draw_Key_Button(void *btn);
void Command_Select_Key(void *btn);




#endif //_JIANPAN_H
