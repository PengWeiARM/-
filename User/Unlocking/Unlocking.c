#include "./Unlocking/Unlocking.h"
#include <stdio.h>
#include <string.h>
#include "./Key_Board/Key_Board.h"
#include "./led/bsp_led.h" 
#include "./beep/bsp_beep.h"
#include "./Change_password/Change_password.h"
#include "./interface/interface.h"
#include "./LD3320/LD3320.h"
#include "./pwm/pwm_config.h"


int count_value=0;  //�����������

void Unlocking_Init(int ret)
{
	int aa=1;
	
	if(ret==0)
		
	{	
		
		LED_GREEN;
		ILI9341_Clear(0,0,240,320);
		LCD_SetColors(RED,WHITE);
		LCD_SetFont(&Font16x24);
		ILI9341_DispString_EN_CH(	90,98,"�����ɹ�");
		Delay(0xFFFFFF);
		LED2_OFF;
		count_value=0;
		while(aa)
		{
					TIM_SetCompare1(TIM4,5);//ת��0��
					Delay(0xFFFFFF);//��ʱ3s
					TIM_SetCompare1(TIM4,10);//ת��45��
					Delay(0xFFFFFF);
					TIM_SetCompare1(TIM4,15);//ת��90��
					Delay(0xFFFFFF);
//					TIM_SetCompare1(TIM4,20);//ת��135��
//					Delay(0xFFFFFF);
//					TIM_SetCompare1(TIM4,25);//ת��180��
//					Delay(0xFFFFFF);
//					TIM_SetCompare1(TIM4,20);//��ת��135��
//					Delay(0xFFFFFF);
//					TIM_SetCompare1(TIM4,15);//��ת��90��
//					Delay(0xFFFFFF);
					TIM_SetCompare1(TIM4,10);//��ת��45��
					Delay(0xFFFFFF);
					TIM_SetCompare1(TIM4,5);//��ת��0��
					Delay(0xFFFFFF);
			    aa=0;
		}
		
		Interface_Init(LCD_SCAN_MODE);  //���س�ʼ����
		
	}
	else
	{
		
		BEEP(TURN_ON);
		ILI9341_Clear(0,0,240,320);
		LCD_SetColors(RED,WHITE);
		LCD_SetFont(&Font16x24);
		ILI9341_DispString_EN_CH(	90,98,"����ʧ��");
		Delay(0xFFFFFF);
		BEEP(CLOSE);
		
		if(count_value<2)  //�������С��3��
		{		
			
			
			Interface_Init(LCD_SCAN_MODE);  //���س�ʼ����
			count_value++;
		}
		else   //�����������3��
		{
			LCD_SetBackColor(BLACK);   //���ñ���Ϊ��ɫ
			ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);
			LED3_OFF;                 //�رյƹ�
			Detection_Finger=ON;     //�ر�ָ�Ƽ��
			Detection_Screen=ON;     //ֹͣ��Ļ���
			Detection_ASR=ON;
		}	
			
	}
	

}
