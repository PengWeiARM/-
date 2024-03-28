/**
  ******************************************************************************
  * @file    bsp_as608.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   ָ��ʶ��ģ��ʵ��
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ��STM32 F103-�Ե� ������  
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 

#include "./as608/as608_test.h"
#include "./as608/bsp_as608.h"
#include "./lcd/bsp_ili9341_lcd.h"
#include "./lcd/bsp_xpt2046_lcd.h"
#include "./fingerprint/fingerprint.h"
#include "./Unlocking/Unlocking.h"
#include "./interface/interface.h" 
#include "./finger_ID/finger_ID.h"


extern uint8_t TouchOut_int_flag;
void Delay(uint32_t count);
int del=0;
int add=0;
int Detection_ADD=OFF;


/**
  * @brief  ָ��ģ�����
  * @param  ��
  * @retval ��
  */
void  FR_Task(void)
{	
  uint32_t   ch;
 
	ch=Finger_num;
	

	
  switch(ch)
  {
    case 1:
      Add_FR();                                    /*���ָ��*/
		 
    break;
			
	case 2:
      Compare_FR();                                /*�ȶ�ָ��*/
		  
    break;

    case 3:
      Del_FR();                                    /*ɾ��ָ���û�ָ��*/
		  
    break;
			
    case 4:
      Clean_FR();                                  /*���ָ�ƿ�*/
		 
    break;
   
  
  }
  return;		
}


/**
  * @brief  �����ָ��ģ���ͨ��
  * @param  ��
  * @retval ��
  */
void  Connect_Test(void)
{   
	ILI9341_Clear(0,0,240,320);
	LCD_SetColors(RED,WHITE);
	LCD_SetFont(&Font16x24);
	ILI9341_DispString_EN_CH(	0,80,"����һ��ָ��ģ��ʵ��");
	ILI9341_DispString_EN_CH(	0,110,"��ӭʹ��Ұ��STM32������");
	Delay(0xFFFFF);
	
  if(PS_Connect(&AS608_Addr))                      /*��AS608����ͨ��*/
  { 
	  ILI9341_DispString_EN_CH(	0,140,"δ��⵽ָ��ģ�飬�������ӣ�����");
  }
  else
  {
	  ILI9341_DispString_EN_CH(	0,170,"ͨѶ�ɹ�");
	  //���Ƴ�ʼѡ�����
		Interface_Init(LCD_SCAN_MODE);

  }
}


/**
  * @brief  ¼ָ��
  * @param  ��
  * @retval ��
  */
void  Add_FR(void)
{
  uint16_t  i,j,sure,ID=1;

  i=j=0;
	Detection_ADD=OFF;
  while(Detection_ADD)
  {
    switch (j)
    {
      case 0:                            /*ִ�е�1��*/
        
        i++;
      
        
	  
	  ILI9341_Clear(0,0,240,320);
	  LCD_SetColors(RED,WHITE);
	  LCD_SetFont(&Font16x24);
	  ILI9341_DispString_EN_CH(	0,10,"����밴��ָ");
        
        sure=PS_GetImage();              /*¼��ͼ��*/      
        if(sure == 0x00)
        {
          sure=PS_GenChar(CHAR_BUFFER1); /*��������1*/
          if(sure==0x00)
          { 
				   
			  
			  ILI9341_DispString_EN_CH(	0,40,"����ָ��1����������");
				
            sure=PS_HighSpeedSearch(CHAR_BUFFER1,0,PS_MAXNUM,&ID);
            if(sure==0x00)
            {
				
             
				
				ILI9341_DispString_EN_CH(	0,70,"ָ���Ѵ��ڣ�ָ��ID��%d������");
             
             return ;
            }              
            else 
            {
              i=0;
              j=1;                      /*��ת����2��*/
             }
           }
				 else
				 {
					 ShowErrMessage(sure);	       
				 }
        }
			  else 
			  {
				  ShowErrMessage(sure);	
			  }
      break;


      case 1:
        
        i++;
      
        
	  
	  ILI9341_DispString_EN_CH(	0,100,"������ٰ�һ����ָ");
      
        sure=PS_GetImage();
        if(sure==0x00)
        { 
          sure=PS_GenChar(CHAR_BUFFER2); /*��������2*/
          if(sure==0x00)
          { 
			  
				    
			  
			  ILI9341_DispString_EN_CH(	0,130,"����ָ��2����������");
            i=0;
            j=2;                         /*��ת����3��*/
          }
				  else 
				  {
					  ShowErrMessage(sure);
				  }

         }
			   else 
			   {
			   ShowErrMessage(sure);
         }				
       break;

			
       case 2:
         
         
	   
	   ILI9341_DispString_EN_CH(	0,160,"���ڶԱ����������ָ��");
       
         sure=PS_Match();                /*��ȷ�ȶ���öָ������*/
         if(sure==0x00) 
         {
				   
			 
			 ILI9341_DispString_EN_CH(	0,190,"����ָ�ƶԱȳɹ�������");
           
           j=3;                         /*��ת����4��*/
         }
         else
         {
           
			 
			 ILI9341_DispString_EN_CH(	0,210,"�Ա�ʧ�ܣ�������¼��ָ�ƣ�����");
					 
           ShowErrMessage(sure);
           i=0;
           j=0;
         }
        
       break;
         
         
       case 3:
         
         
	   ILI9341_DispString_EN_CH(	0,240,"��������ָ��ģ��");
       
         sure=PS_RegModel();            /*�ϲ�����������ģ�壩*/
         if(sure==0x00) 	
         {
          
			 ILI9341_DispString_EN_CH(	0,270,"����ָ��ģ��ɹ�������");
           j=4;                        /*��ת����5��*/
         } 
         else 
        {
         j =0;
         ShowErrMessage(sure);
        }
        
       break;
        

       case 4:
        
						/* ������Ϊ��ɫ */
						LCD_SetBackColor(WHITE);
						ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);	
						ILI9341_DispString_EN_CH(	0,30,"���������洢ID����ΧΪ0��239");
						Delay(0xFFFFFF);
						add=1;
						Detection_ADD=ON;
						Key_Board_ID_Init(LCD_SCAN_MODE);	

      }
    
      SysTick_Delay_Ms(1000);
      
      if(i==4)                       /*����4��û�а���ָ���˳�*/
      { 
        
		  ILI9341_DispString_EN_CH(	0,130,"¼ָ��ʧ�ܣ�");

        break;
      }
  }
}


/**
  * @brief  �ȶ�ָ�ƣ�ʶ��ָ�ƣ�
  * @param  ��
  * @retval ��
  */
void Compare_FR(void)  
{  
  uint16_t  ID=0;                    /*��ʼ��IDֵ*/  
  uint16_t  sure;
	int ret;
 
	  ILI9341_Clear(0,0,240,320);
	  LCD_SetColors(RED,WHITE);
	  LCD_SetFont(&Font16x24);
	  ILI9341_DispString_EN_CH(	0,10,"����Ա�ָ�ƣ��밴��ָ");
	

     sure=PS_GetImage();
  if(sure == 0x00)
  {
    sure=PS_GenChar(CHAR_BUFFER1);   /*��������1*/
    if(sure==0x00)
    {  
			/*��������ָ�ƿ�*/
      sure=PS_HighSpeedSearch(CHAR_BUFFER1,0,PS_MAXNUM,&ID);
      if(sure==0x00)
      {
		  
        
		  ILI9341_DispString_EN_CH(	0,40,"�Ա�ָ�Ƴɹ���ָ��ID��%d������");
		  Delay(0xFFFFFF);
		  ret=0;
		  Unlocking_Init(ret);
      }
      else 
      {
			ShowErrMessage(sure);
			}
    }
    else 
    {   
      ShowErrMessage(sure);	
    }
  }
	else  
	{
	  ShowErrMessage(sure);
	}
 
}



/**
  * @brief  ���ָ�ƿ�
  * @param  ��
  * @retval ��
  */
void Clean_FR(void) 
{
  uint16_t  sure;
  

  
	  ILI9341_Clear(0,0,240,320);
	  LCD_SetColors(RED,WHITE);
	  LCD_SetFont(&Font16x24);
	  ILI9341_DispString_EN_CH(	0,10,"���ָ�ƿ�");
	
	sure=PS_Empty();     
	if(sure == 0x00)
	{
		
		
		ILI9341_DispString_EN_CH(	0,40,"���ָ�ƿ�ɹ�������");
		
		Delay(0xFFFFFF);
		
		Interface_Init(LCD_SCAN_MODE);
	}
	else 
	{
		ShowErrMessage(sure);
	}

}


/**
  * @brief  ɾ��ָ���û�ָ��
  * @param  ��
  * @retval ��
  */
void Del_FR(void)
{ 

  	
		del=1;
	
	  ILI9341_Clear(0,0,240,320);
	  LCD_SetColors(RED,WHITE);
	  LCD_SetFont(&Font16x24);
	  ILI9341_DispString_EN_CH(	0,10,"ɾ��ָ���û�ID");
		ILI9341_DispString_EN_CH(	0,40,"���������洢ID����ΧΪ0��239");
		Delay(0xFFFFFF);
  
	  Key_Board_ID_Init(LCD_SCAN_MODE);	
	
	   
	   
	
}


/*********************************************END OF FILE**********************/
