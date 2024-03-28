
#include "stm32f10x.h"
#include "./usart/bsp_usart.h"
#include "./usart/rx_data_queue.h"
#include "./led/bsp_led.h"  
#include "./as608/as608_test.h"
#include "./as608/bsp_as608.h"
#include "./lcd/bsp_ili9341_lcd.h"
#include "./lcd/bsp_xpt2046_lcd.h"
#include "./beep/bsp_beep.h"
#include "./Key_Board/Key_Board.h"
#include "./Unlocking/Unlocking.h"
#include "./fingerprint/fingerprint.h"
#include "./interface/interface.h" 
#include "./pwm/pwm_config.h"
#include "./Common/Common.h"
#include "./usart/bsp_usart1.h"
#include "./ESP8266/bsp_esp8266.h"
#include "./ESP8266/bsp_esp8266_test.h"
#include "./dwt_delay/core_delay.h"




int Detection_Screen=OFF;   //触摸检测开关变量off=1,led低电平点亮

char passWord_0[]="123456";
int interface=0;            //触摸界面检测函数

void Delay(uint32_t count)
{
	
	for(;count!=0;count--);
	
}


/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{		

	
		//初始化USART 配置模式为 9600 8-N-1，中断接收
		USART_Config();
		
	  //系统定时器初始化
		//SysTick_Init();
	
		USARTx_Config ();          //初始化串口1
    CPU_TS_TmrInit();         //内核向上计时器
	  ESP8266_Init (); 
		//LED初始化
		LED_GPIO_Config();	
		
		//蜂鸣器初始化
		BEEP_GPIO_Config();
		
		//LCD 初始化
		ILI9341_Init();  
	
		//触摸屏初始化
		XPT2046_Init();
		
		//从FLASH里获取校正参数，若FLASH无参数，则使用模式3进行校正
		Calibrate_or_Get_TouchParaWithFlash(6,0);
	   			
		//其中 6 模式为大部分液晶例程的默认显示方向  
		//ILI9341_GramScan ( 6 );	

		/*初始化环形缓冲区*/
		rx_queue_init();
   
		/*初始化指纹模块配置*/
		AS608_Config();
  
		/*测试STM32与指纹模块的通信*/
		Connect_Test();
		
		pwm_config();//配置输出pwm
		
		
                                                              //初始化WiFi模块使用的接口和外设

	 printf ( "\r\n野火 WF-ESP8266 WiFi模块测试例程\r\n" );                          //打印测试例程提示信息
	
  
		
		
		
		while(Detection_Screen)
		{
			
			   //触摸检测函数，本函数至少10ms调用一次
				XPT2046_TouchEvenHandler();
 
			 ESP8266_CheckRecv_SendDataTest(); // ESP8266 处理并发送数据
		}
  
			
	
	
  
	
	
}



/*********************************************END OF FILE**********************/
