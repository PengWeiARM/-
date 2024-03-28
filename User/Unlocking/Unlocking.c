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


int count_value=0;  //错误次数计算

void Unlocking_Init(int ret)
{
	int aa=1;
	
	if(ret==0)
		
	{	
		
		LED_GREEN;
		ILI9341_Clear(0,0,240,320);
		LCD_SetColors(RED,WHITE);
		LCD_SetFont(&Font16x24);
		ILI9341_DispString_EN_CH(	90,98,"开锁成功");
		Delay(0xFFFFFF);
		LED2_OFF;
		count_value=0;
		while(aa)
		{
					TIM_SetCompare1(TIM4,5);//转到0°
					Delay(0xFFFFFF);//延时3s
					TIM_SetCompare1(TIM4,10);//转到45°
					Delay(0xFFFFFF);
					TIM_SetCompare1(TIM4,15);//转到90°
					Delay(0xFFFFFF);
//					TIM_SetCompare1(TIM4,20);//转到135°
//					Delay(0xFFFFFF);
//					TIM_SetCompare1(TIM4,25);//转到180°
//					Delay(0xFFFFFF);
//					TIM_SetCompare1(TIM4,20);//反转到135°
//					Delay(0xFFFFFF);
//					TIM_SetCompare1(TIM4,15);//反转到90°
//					Delay(0xFFFFFF);
					TIM_SetCompare1(TIM4,10);//反转到45°
					Delay(0xFFFFFF);
					TIM_SetCompare1(TIM4,5);//反转到0°
					Delay(0xFFFFFF);
			    aa=0;
		}
		
		Interface_Init(LCD_SCAN_MODE);  //返回初始界面
		
	}
	else
	{
		
		BEEP(TURN_ON);
		ILI9341_Clear(0,0,240,320);
		LCD_SetColors(RED,WHITE);
		LCD_SetFont(&Font16x24);
		ILI9341_DispString_EN_CH(	90,98,"开锁失败");
		Delay(0xFFFFFF);
		BEEP(CLOSE);
		
		if(count_value<2)  //错误次数小于3次
		{		
			
			
			Interface_Init(LCD_SCAN_MODE);  //返回初始界面
			count_value++;
		}
		else   //错误次数大于3次
		{
			LCD_SetBackColor(BLACK);   //设置背景为黑色
			ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);
			LED3_OFF;                 //关闭灯光
			Detection_Finger=ON;     //关闭指纹检测
			Detection_Screen=ON;     //停止屏幕检测
			Detection_ASR=ON;
		}	
			
	}
	

}
