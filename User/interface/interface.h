#ifndef _INTERFACE_H
#define _INTERFACE_H

#include "./Key_Board/Key_Board.h"
#include "./Change_password/Change_password.h"
#include "./fingerprint/fingerprint.h"
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
  
} Touch_Button_Interface;



extern Touch_Button_Interface button_0[4];



void Touch_Button_Interface_Up(uint16_t x,uint16_t y);
void Interface_Init(uint8_t LCD_Mode);
void Touch_Button_Interface_Init(void);
void Draw_Interface_Button(void *btn);
void Touch_Button_Interface_Down(uint16_t x,uint16_t y);
void Command_Select_Interface(void *btn);




#endif //_INTERFACE_H
