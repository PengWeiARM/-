/**
  ******************************************************************************
  * @file    bsp_as608.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   指纹识别模块实验
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火STM32 F103-霸道 开发板  
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
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
  * @brief  指纹模块操作
  * @param  无
  * @retval 无
  */
void  FR_Task(void)
{	
  uint32_t   ch;
 
	ch=Finger_num;
	

	
  switch(ch)
  {
    case 1:
      Add_FR();                                    /*添加指纹*/
		 
    break;
			
	case 2:
      Compare_FR();                                /*比对指纹*/
		  
    break;

    case 3:
      Del_FR();                                    /*删除指定用户指纹*/
		  
    break;
			
    case 4:
      Clean_FR();                                  /*清空指纹库*/
		 
    break;
   
  
  }
  return;		
}


/**
  * @brief  检测与指纹模块的通信
  * @param  无
  * @retval 无
  */
void  Connect_Test(void)
{   
	ILI9341_Clear(0,0,240,320);
	LCD_SetColors(RED,WHITE);
	LCD_SetFont(&Font16x24);
	ILI9341_DispString_EN_CH(	0,80,"这是一个指纹模块实验");
	ILI9341_DispString_EN_CH(	0,110,"欢迎使用野火STM32开发板");
	Delay(0xFFFFF);
	
  if(PS_Connect(&AS608_Addr))                      /*与AS608串口通信*/
  { 
	  ILI9341_DispString_EN_CH(	0,140,"未检测到指纹模块，请检查连接！！！");
  }
  else
  {
	  ILI9341_DispString_EN_CH(	0,170,"通讯成功");
	  //绘制初始选择界面
		Interface_Init(LCD_SCAN_MODE);

  }
}


/**
  * @brief  录指纹
  * @param  无
  * @retval 无
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
      case 0:                            /*执行第1步*/
        
        i++;
      
        
	  
	  ILI9341_Clear(0,0,240,320);
	  LCD_SetColors(RED,WHITE);
	  LCD_SetFont(&Font16x24);
	  ILI9341_DispString_EN_CH(	0,10,"命令：请按手指");
        
        sure=PS_GetImage();              /*录入图像*/      
        if(sure == 0x00)
        {
          sure=PS_GenChar(CHAR_BUFFER1); /*生成特征1*/
          if(sure==0x00)
          { 
				   
			  
			  ILI9341_DispString_EN_CH(	0,40,"输入指纹1正常！！！");
				
            sure=PS_HighSpeedSearch(CHAR_BUFFER1,0,PS_MAXNUM,&ID);
            if(sure==0x00)
            {
				
             
				
				ILI9341_DispString_EN_CH(	0,70,"指纹已存在，指纹ID：%d！！！");
             
             return ;
            }              
            else 
            {
              i=0;
              j=1;                      /*跳转到第2步*/
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
      
        
	  
	  ILI9341_DispString_EN_CH(	0,100,"命令：请再按一次手指");
      
        sure=PS_GetImage();
        if(sure==0x00)
        { 
          sure=PS_GenChar(CHAR_BUFFER2); /*生成特征2*/
          if(sure==0x00)
          { 
			  
				    
			  
			  ILI9341_DispString_EN_CH(	0,130,"输入指纹2正常！！！");
            i=0;
            j=2;                         /*跳转到第3步*/
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
         
         
	   
	   ILI9341_DispString_EN_CH(	0,160,"正在对比两次输入的指纹");
       
         sure=PS_Match();                /*精确比对两枚指纹特征*/
         if(sure==0x00) 
         {
				   
			 
			 ILI9341_DispString_EN_CH(	0,190,"输入指纹对比成功！！！");
           
           j=3;                         /*跳转到第4步*/
         }
         else
         {
           
			 
			 ILI9341_DispString_EN_CH(	0,210,"对比失败，请重新录入指纹！！！");
					 
           ShowErrMessage(sure);
           i=0;
           j=0;
         }
        
       break;
         
         
       case 3:
         
         
	   ILI9341_DispString_EN_CH(	0,240,"正在生成指纹模块");
       
         sure=PS_RegModel();            /*合并特征（生成模板）*/
         if(sure==0x00) 	
         {
          
			 ILI9341_DispString_EN_CH(	0,270,"生成指纹模块成功！！！");
           j=4;                        /*跳转到第5步*/
         } 
         else 
        {
         j =0;
         ShowErrMessage(sure);
        }
        
       break;
        

       case 4:
        
						/* 整屏清为白色 */
						LCD_SetBackColor(WHITE);
						ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);	
						ILI9341_DispString_EN_CH(	0,30,"命令：请输入存储ID，范围为0—239");
						Delay(0xFFFFFF);
						add=1;
						Detection_ADD=ON;
						Key_Board_ID_Init(LCD_SCAN_MODE);	

      }
    
      SysTick_Delay_Ms(1000);
      
      if(i==4)                       /*超过4次没有按手指则退出*/
      { 
        
		  ILI9341_DispString_EN_CH(	0,130,"录指纹失败！");

        break;
      }
  }
}


/**
  * @brief  比对指纹（识别指纹）
  * @param  无
  * @retval 无
  */
void Compare_FR(void)  
{  
  uint16_t  ID=0;                    /*初始化ID值*/  
  uint16_t  sure;
	int ret;
 
	  ILI9341_Clear(0,0,240,320);
	  LCD_SetColors(RED,WHITE);
	  LCD_SetFont(&Font16x24);
	  ILI9341_DispString_EN_CH(	0,10,"命令：对比指纹，请按手指");
	

     sure=PS_GetImage();
  if(sure == 0x00)
  {
    sure=PS_GenChar(CHAR_BUFFER1);   /*生成特征1*/
    if(sure==0x00)
    {  
			/*高速搜索指纹库*/
      sure=PS_HighSpeedSearch(CHAR_BUFFER1,0,PS_MAXNUM,&ID);
      if(sure==0x00)
      {
		  
        
		  ILI9341_DispString_EN_CH(	0,40,"对比指纹成功，指纹ID：%d！！！");
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
  * @brief  清空指纹库
  * @param  无
  * @retval 无
  */
void Clean_FR(void) 
{
  uint16_t  sure;
  

  
	  ILI9341_Clear(0,0,240,320);
	  LCD_SetColors(RED,WHITE);
	  LCD_SetFont(&Font16x24);
	  ILI9341_DispString_EN_CH(	0,10,"清空指纹库");
	
	sure=PS_Empty();     
	if(sure == 0x00)
	{
		
		
		ILI9341_DispString_EN_CH(	0,40,"清空指纹库成功！！！");
		
		Delay(0xFFFFFF);
		
		Interface_Init(LCD_SCAN_MODE);
	}
	else 
	{
		ShowErrMessage(sure);
	}

}


/**
  * @brief  删除指定用户指纹
  * @param  无
  * @retval 无
  */
void Del_FR(void)
{ 

  	
		del=1;
	
	  ILI9341_Clear(0,0,240,320);
	  LCD_SetColors(RED,WHITE);
	  LCD_SetFont(&Font16x24);
	  ILI9341_DispString_EN_CH(	0,10,"删除指定用户ID");
		ILI9341_DispString_EN_CH(	0,40,"命令：请输入存储ID，范围为0—239");
		Delay(0xFFFFFF);
  
	  Key_Board_ID_Init(LCD_SCAN_MODE);	
	
	   
	   
	
}


/*********************************************END OF FILE**********************/
