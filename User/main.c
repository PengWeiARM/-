
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




int Detection_Screen=OFF;   //������⿪�ر���off=1,led�͵�ƽ����

char passWord_0[]="123456";
int interface=0;            //���������⺯��

void Delay(uint32_t count)
{
	
	for(;count!=0;count--);
	
}


/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{		

	
		//��ʼ��USART ����ģʽΪ 9600 8-N-1���жϽ���
		USART_Config();
		
	  //ϵͳ��ʱ����ʼ��
		//SysTick_Init();
	
		USARTx_Config ();          //��ʼ������1
    CPU_TS_TmrInit();         //�ں����ϼ�ʱ��
	  ESP8266_Init (); 
		//LED��ʼ��
		LED_GPIO_Config();	
		
		//��������ʼ��
		BEEP_GPIO_Config();
		
		//LCD ��ʼ��
		ILI9341_Init();  
	
		//��������ʼ��
		XPT2046_Init();
		
		//��FLASH���ȡУ����������FLASH�޲�������ʹ��ģʽ3����У��
		Calibrate_or_Get_TouchParaWithFlash(6,0);
	   			
		//���� 6 ģʽΪ�󲿷�Һ�����̵�Ĭ����ʾ����  
		//ILI9341_GramScan ( 6 );	

		/*��ʼ�����λ�����*/
		rx_queue_init();
   
		/*��ʼ��ָ��ģ������*/
		AS608_Config();
  
		/*����STM32��ָ��ģ���ͨ��*/
		Connect_Test();
		
		pwm_config();//�������pwm
		
		
                                                              //��ʼ��WiFiģ��ʹ�õĽӿں�����

	 printf ( "\r\nҰ�� WF-ESP8266 WiFiģ���������\r\n" );                          //��ӡ����������ʾ��Ϣ
	
  
		
		
		
		while(Detection_Screen)
		{
			
			   //������⺯��������������10ms����һ��
				XPT2046_TouchEvenHandler();
 
			 ESP8266_CheckRecv_SendDataTest(); // ESP8266 ������������
		}
  
			
	
	
  
	
	
}



/*********************************************END OF FILE**********************/
