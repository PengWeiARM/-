#include "./finger_ID/finger_ID.h"
#include "./as608/as608_test.h"
#include "./interface/interface.h" 
#include "./as608/bsp_as608.h"


Touch_Button button_ID[15];
int perform=0;






void Key_Board_ID_Init(uint8_t LCD_Mode)
{
	
	
    uint8_t i;
	interface=4;
	key_num=0;
	Detection_Finger=ON;
	
	ILI9341_GramScan ( LCD_Mode );
	
		/* 整屏清为白色 */
		LCD_SetBackColor(WHITE);
    ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);	

  
	/* 初始化按钮 */
	Touch_Button_ID_Init();
  
	/* 描绘按钮 */
	for(i=0;i<BUTTON_NUM_ID;i++)
	{
		button_ID[i].draw_btn(&button_ID[i]);
	  
	}
  
  
}


void Touch_Button_ID_Init(void)
{
  
  button_ID[0].start_x = BUTTON_STAY_X;                       //5
  button_ID[0].start_y = BUTTON_STAY_Y;                      //90
  button_ID[0].end_x = BUTTON_STAY_X+BUTTON_WHITH;           //5+70
  button_ID[0].end_y = BUTTON_STAY_Y+BUTTON_HIGHT;            //90+40
  button_ID[0].para = "ID";
  button_ID[0].touch_flag = 0;  
  button_ID[0].draw_btn = Draw_Key_ID_Button ;
  
  
  button_ID[1].start_x =  BUTTON_STAY_X+BUTTON_SpaceX;                    //5
  button_ID[1].start_y = BUTTON_STAY_Y;                      //90
  button_ID[1].end_x = BUTTON_STAY_X+BUTTON_SpaceX*2+BUTTON_WHITH ; //5+75*2+70
  button_ID[1].end_y = BUTTON_STAY_Y+BUTTON_HIGHT;              //90+40
  button_ID[1].para = "";
  button_ID[1].touch_flag = 0;  
  button_ID[1].draw_btn = Draw_Key_ID_Button ;
  
  
  button_ID[2].start_x = BUTTON_STAY_X;
  button_ID[2].start_y = BUTTON_STAY_Y+BUTTON_SpaceY;
  button_ID[2].end_x = BUTTON_STAY_X+BUTTON_WHITH ;
  button_ID[2].end_y = BUTTON_STAY_Y+BUTTON_SpaceY+BUTTON_HIGHT;
  button_ID[2].para = "1";
  button_ID[2].touch_flag = 0;  
  button_ID[2].draw_btn = Draw_Key_ID_Button ;
  button_ID[2].btn_command = Command_Select_Key_ID ;
  
  button_ID[3].start_x =  BUTTON_STAY_X+BUTTON_SpaceX;
  button_ID[3].start_y = BUTTON_STAY_Y+BUTTON_SpaceY;
  button_ID[3].end_x = BUTTON_STAY_X+BUTTON_SpaceX+BUTTON_WHITH ;
  button_ID[3].end_y = BUTTON_STAY_Y+BUTTON_SpaceY+BUTTON_HIGHT;
  button_ID[3].para = "2";
  button_ID[3].touch_flag = 0;  
  button_ID[3].draw_btn = Draw_Key_ID_Button ;
  button_ID[3].btn_command = Command_Select_Key_ID ;
  
  button_ID[4].start_x = BUTTON_STAY_X+BUTTON_SpaceX*2;
  button_ID[4].start_y = BUTTON_STAY_Y+BUTTON_SpaceY;
  button_ID[4].end_x = BUTTON_STAY_X+BUTTON_SpaceX*2+BUTTON_WHITH ;
  button_ID[4].end_y = BUTTON_STAY_Y+BUTTON_SpaceY+BUTTON_HIGHT;
  button_ID[4].para = "3";
  button_ID[4].touch_flag = 0;  
  button_ID[4].draw_btn = Draw_Key_ID_Button ;
  button_ID[4].btn_command = Command_Select_Key_ID ;
  
  button_ID[5].start_x = BUTTON_STAY_X;
  button_ID[5].start_y = BUTTON_STAY_Y+BUTTON_SpaceY*2;
  button_ID[5].end_x = BUTTON_STAY_X+BUTTON_WHITH ;
  button_ID[5].end_y = BUTTON_STAY_Y+BUTTON_SpaceY*2+BUTTON_HIGHT;
  button_ID[5].para = "4";
  button_ID[5].touch_flag = 0;  
  button_ID[5].draw_btn = Draw_Key_ID_Button ;
  button_ID[5].btn_command = Command_Select_Key_ID ;  
  
  button_ID[6].start_x =  BUTTON_STAY_X+BUTTON_SpaceX;
  button_ID[6].start_y = BUTTON_STAY_Y+BUTTON_SpaceY*2;
  button_ID[6].end_x = BUTTON_STAY_X+BUTTON_SpaceX+BUTTON_WHITH ;
  button_ID[6].end_y = BUTTON_STAY_Y+BUTTON_SpaceY*2+BUTTON_HIGHT;
  button_ID[6].para = "5";
  button_ID[6].touch_flag = 0;  
  button_ID[6].draw_btn = Draw_Key_ID_Button ;
  button_ID[6].btn_command =  Command_Select_Key_ID;
  
  
 
  button_ID[7].start_x = BUTTON_STAY_X+BUTTON_SpaceX*2;
  button_ID[7].start_y = BUTTON_STAY_Y+BUTTON_SpaceY*2;
  button_ID[7].end_x = BUTTON_STAY_X+BUTTON_SpaceX*2+BUTTON_WHITH ;
  button_ID[7].end_y = BUTTON_STAY_Y+BUTTON_SpaceY*2+BUTTON_HIGHT;
  button_ID[7].para = "6";
  button_ID[7].touch_flag = 0;  
  button_ID[7].draw_btn = Draw_Key_ID_Button ;
  button_ID[7].btn_command =  Command_Select_Key_ID ;
  
  button_ID[8].start_x = BUTTON_STAY_X;
  button_ID[8].start_y = BUTTON_STAY_Y+BUTTON_SpaceY*3;
  button_ID[8].end_x = BUTTON_STAY_X+BUTTON_WHITH ;
  button_ID[8].end_y = BUTTON_STAY_Y+BUTTON_SpaceY*3+BUTTON_HIGHT;
  button_ID[8].para = "7";
  button_ID[8].touch_flag = 0;  
  button_ID[8].draw_btn = Draw_Key_ID_Button ;
  button_ID[8].btn_command =  Command_Select_Key_ID ;
  
  button_ID[9].start_x = BUTTON_STAY_X+BUTTON_SpaceX;
  button_ID[9].start_y = BUTTON_STAY_Y+BUTTON_SpaceY*3;
  button_ID[9].end_x = BUTTON_STAY_X+BUTTON_SpaceX+BUTTON_WHITH ;
  button_ID[9].end_y = BUTTON_STAY_Y+BUTTON_SpaceY*3+BUTTON_HIGHT;
  button_ID[9].para = "8";
  button_ID[9].touch_flag = 0;  
  button_ID[9].draw_btn = Draw_Key_ID_Button ;
  button_ID[9].btn_command =  Command_Select_Key_ID ;
  
  button_ID[10].start_x = BUTTON_STAY_X+BUTTON_SpaceX*2;
  button_ID[10].start_y = BUTTON_STAY_Y+BUTTON_SpaceY*3;
  button_ID[10].end_x = BUTTON_STAY_X+BUTTON_SpaceX*2+BUTTON_WHITH ;
  button_ID[10].end_y = BUTTON_STAY_Y+BUTTON_SpaceY*3+BUTTON_HIGHT;
  button_ID[10].para = "9";
  button_ID[10].touch_flag = 0;  
  button_ID[10].draw_btn = Draw_Key_ID_Button ;
  button_ID[10].btn_command =  Command_Select_Key_ID ;
  
  button_ID[11].start_x = BUTTON_STAY_X;
  button_ID[11].start_y = BUTTON_STAY_Y+BUTTON_SpaceY*4;
  button_ID[11].end_x = BUTTON_STAY_X+BUTTON_WHITH ;
  button_ID[11].end_y = BUTTON_STAY_Y+BUTTON_SpaceY*4+BUTTON_HIGHT;
  button_ID[11].para = "删除";
  button_ID[11].touch_flag = 0;  
  button_ID[11].draw_btn = Draw_Key_ID_Button;
  button_ID[11].btn_command =  Command_Select_Key_ID ;
  
  button_ID[12].start_x =  BUTTON_STAY_X+BUTTON_SpaceX;
  button_ID[12].start_y = BUTTON_STAY_Y+BUTTON_SpaceY*4;
  button_ID[12].end_x = BUTTON_STAY_X+BUTTON_SpaceX+BUTTON_WHITH ;
  button_ID[12].end_y = BUTTON_STAY_Y+BUTTON_SpaceY*4+BUTTON_HIGHT;
  button_ID[12].para = "0";
  button_ID[12].touch_flag = 0;  
  button_ID[12].draw_btn = Draw_Key_ID_Button ;
  button_ID[12].btn_command =  Command_Select_Key_ID ;
  
  button_ID[13].start_x = BUTTON_STAY_X+BUTTON_SpaceX*2;
  button_ID[13].start_y = BUTTON_STAY_Y+BUTTON_SpaceY*4;
  button_ID[13].end_x = BUTTON_STAY_X+BUTTON_SpaceX*2+BUTTON_WHITH ;
  button_ID[13].end_y = BUTTON_STAY_Y+BUTTON_SpaceY*4+BUTTON_HIGHT;
  button_ID[13].para = "确认";
  button_ID[13].touch_flag = 0;  
  button_ID[13].draw_btn = Draw_Key_ID_Button ;
  button_ID[13].btn_command =  Command_Select_Key_ID ;    
  
  button_ID[14].start_x = 5;
  button_ID[14].start_y = 5;
  button_ID[14].end_x = 75 ;
  button_ID[14].end_y = 45;
  button_ID[14].para = "返回";
  button_ID[14].touch_flag = 0;  
  button_ID[14].draw_btn = Draw_Key_ID_Button ;
  button_ID[14].btn_command =  Command_Select_Key_ID ;    
  

  
 }


  /**
* @brief  Touch_Button_Down 按键被按下时调用的函数，由触摸屏调用
* @param  x 触摸位置的x坐标
* @param  y 触摸位置的y坐标
* @retval 无
*/
void Touch_Button_ID_Down(uint16_t x,uint16_t y)
{
  uint8_t i;
  for(i=2;i<BUTTON_NUM_ID;i++)
  {
	
			
		/* 触摸到了按钮 */
		if(x<=button_ID[i].end_x && y<=button_ID[i].end_y && y>=button_ID[i].start_y && x>=button_ID[i].start_x )
		{
			
		  if(button_ID[i].touch_flag == 0)     /*原本的状态为没有按下，则更新状态*/
		  {
		   button_ID[i].touch_flag = 1;         /* 记录按下标志 */
		  
		   button_ID[i].draw_btn(&button_ID[i]);  /*重绘按钮*/
			  
			  
		  }        
		  
		}
		else if(button_ID[i].touch_flag == 1) /* 触摸移出了按键的范围且之前有按下按钮 */
		{
		  button_ID[i].touch_flag = 0;         /* 清除按下标志，判断为误操作*/
		  
		  button_ID[i].draw_btn(&button_ID[i]);   /*重绘按钮*/
		}
    
  }

}


/**
* @brief  Command_Select_Key 按键的功能执行函数
* @param  btn Touch_Button 类型的按键参数
* @retval 无
*/
static void Command_Select_Key_ID(void *btn)
{
	
	char *p = passWord;
	
	sprintf(passWord,"%d",key_num);
    
    
	
	ILI9341_Clear(81,91,143,38);
    LCD_SetColors(RED,WHITE);
    LCD_SetFont(&Font16x24);
  
	ILI9341_DispString_EN_CH(	90,98,p);
	
	
	
}


 /**
* @brief  Touch_Button_Up 按键被释放时调用的函数，由触摸屏调用
* @param  x 触摸最后释放时的x坐标
* @param  y 触摸最后释放时的y坐标
* @retval 无
*/
void Touch_Button_ID_Up(uint16_t x,uint16_t y)
{
	
	
	uint8_t i; 
	uint32_t  ID;
	 uint16_t  sure;
	
	
	for(i=2;i<BUTTON_NUM_ID;i++)
     {
	 
		if(i!=13 && i!=14)
		{
		   /* 触笔在按钮区域释放 */
			if((x<button_ID[i].end_x && x>button_ID[i].start_x && y<button_ID[i].end_y && y>button_ID[i].start_y))
			{        
				button_ID[i].touch_flag = 0;       /*释放触摸标志*/
			
				button_ID[i].draw_btn(&button_ID[i]); /*重绘按钮*/        
				if(key_num<=999999)
				{ 
								
				if(i==11)
					key_num=key_num/10;
				else if(i==12)
					key_num=key_num*10;
			 
				else
					key_num=key_num*10+(i-1);
			 
				}
				else
					key_num=0;
			  
			
					button_ID[i].btn_command(&button_ID[i]);  /*执行按键的功能命令*/
			  
					break;
		    
			}
		}
		else 
	    {
				/* 触笔在按钮区域释放 */
				if((x<button_ID[i].end_x && x>button_ID[i].start_x && y<button_ID[i].end_y && y>button_ID[i].start_y))
				{        
					button_ID[i].touch_flag = 0;       /*释放触摸标志*/
			
					button_ID[i].draw_btn(&button_ID[i]); /*重绘按钮*/ 
            
			
					if(i==13)
					{
						perform=1;
						GET_NUM();
						if(perform==del)
						{
							del=0;
							do
							{ 
		
								ID=GET_NUM();
		
							}while(!(ID<PS_MAXNUM));         /*输入ID不能超过指纹模块最大容量*/
		
							sure=PS_DeletChar(ID,1);         /*删除指定用户的指纹模板*/
	
							if(sure == 0x00)                
							{
	
								/* 整屏清为白色 */
								LCD_SetBackColor(WHITE);
								ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);	

								ILI9341_DispString_EN_CH(	0,70,"删除指定用户指纹成功！！！");
								Delay(0xFFFFFF);
		
								Interface_Init(LCD_SCAN_MODE);
							}
							else 
							{
								ShowErrMessage(sure);
							}
		
						}
						
						if(perform==add)
						{
							add=0;
							
							  do
								{ 
          
									ID=GET_NUM();

								}while(!(ID<PS_MAXNUM));
        
								sure=PS_StoreChar(CHAR_BUFFER2,ID);  /*储存模板*/
								if(sure==0x00) 	
								{
          
									/* 整屏清为白色 */
									LCD_SetBackColor(WHITE);
									ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);	
									ILI9341_DispString_EN_CH(	0,320,"录入指纹模块成功！！！");
									
									Delay(0xFFFFFF);
		
									Interface_Init(LCD_SCAN_MODE);
									
								} 
								else 
								{
									
								ShowErrMessage(sure);
								}
								break;
						}
    
							
      
						
					}
	

			  
					if(i==14)
					{
						
						Interface_Init(LCD_SCAN_MODE);
			  
						break; 
					}
					
		
				}
	  
	     }
		
     }
	 
   
}

static void Draw_Key_ID_Button(void *btn)
{
  Touch_Button *ptr = (Touch_Button *)btn;
  
  /*释放按键*/
  if(ptr->touch_flag == 0)
  {
		/*背景为功能键相应的颜色*/
		LCD_SetColors(RED,WHITE);
	  LCD_SetFont(&Font16x24);
    ILI9341_DispString_EN_CH(	ptr->start_x+27,ptr->start_y+8,ptr->para);
  }
  else  /*按键按下*/
  {
    /*白色背景*/
		LCD_SetColors(WHITE,WHITE);
	  ILI9341_DrawRectangle(	ptr->start_x,
															ptr->start_y,
															ptr->end_x - ptr->start_x,
															ptr->end_y - ptr->start_y,1);
  } 
    /*按钮边框*/
		LCD_SetColors(BLUE,WHITE);
    ILI9341_DrawRectangle(	ptr->start_x,
															ptr->start_y,
															ptr->end_x - ptr->start_x,
															ptr->end_y - ptr->start_y,0);
  
}

 
