#ifndef _fingerprint_H
#define _fingerprint_H

#include "stm32f10x.h"
#include "./lcd/bsp_ili9341_lcd.h"
#include "./lcd/bsp_xpt2046_lcd.h"
#include "./as608/as608_test.h"
#include "./led/bsp_led.h"


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

