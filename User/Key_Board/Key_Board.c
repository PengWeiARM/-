#include "./Key_Board/Key_Board.h"
#include "./Unlocking/Unlocking.h"
#include "./interface/interface.h" 
#include "./as608/bsp_as608.h"



Touch_Button button[15];





char passWord[6];



uint32_t key_num=0;




void Key_Board_Init(uint8_t LCD_Mode)
{
	
	
  uint8_t i;
	interface=1;
	key_num=0;
	
	ILI9341_GramScan ( LCD_Mode );
	
	/* ������Ϊ��ɫ */
	LCD_SetBackColor(WHITE);
  ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);	

  
	/* ��ʼ����ť */
	Touch_Button_Init();
  
	/* ��水ť */
	for(i=0;i<BUTTON_NUM;i++)
	{
		button[i].draw_btn(&button[i]);
	  
	}
  
  
}



void Touch_Button_Init(void)
{
  
  button[0].start_x = BUTTON_STAY_X;                       //5
  button[0].start_y = BUTTON_STAY_Y;                      //90
  button[0].end_x = BUTTON_STAY_X+BUTTON_WHITH;           //5+70
  button[0].end_y = BUTTON_STAY_Y+BUTTON_HIGHT;            //90+40
  button[0].para = "����";
  button[0].touch_flag = 0;  
  button[0].draw_btn = Draw_Key_Button ;
  
  
  button[1].start_x =  BUTTON_STAY_X+BUTTON_SpaceX;                    //5
  button[1].start_y = BUTTON_STAY_Y;                      //90
  button[1].end_x = BUTTON_STAY_X+BUTTON_SpaceX*2+BUTTON_WHITH ; //5+75*2+70
  button[1].end_y = BUTTON_STAY_Y+BUTTON_HIGHT;              //90+40
  button[1].para = "";
  button[1].touch_flag = 0;  
  button[1].draw_btn = Draw_Key_Button ;
  
  
  button[2].start_x = BUTTON_STAY_X;
  button[2].start_y = BUTTON_STAY_Y+BUTTON_SpaceY;
  button[2].end_x = BUTTON_STAY_X+BUTTON_WHITH ;
  button[2].end_y = BUTTON_STAY_Y+BUTTON_SpaceY+BUTTON_HIGHT;
  button[2].para = "1";
  button[2].touch_flag = 0;  
  button[2].draw_btn = Draw_Key_Button ;
  button[2].btn_command = Command_Select_Key ;
  
  button[3].start_x =  BUTTON_STAY_X+BUTTON_SpaceX;
  button[3].start_y = BUTTON_STAY_Y+BUTTON_SpaceY;
  button[3].end_x = BUTTON_STAY_X+BUTTON_SpaceX+BUTTON_WHITH ;
  button[3].end_y = BUTTON_STAY_Y+BUTTON_SpaceY+BUTTON_HIGHT;
  button[3].para = "2";
  button[3].touch_flag = 0;  
  button[3].draw_btn = Draw_Key_Button ;
  button[3].btn_command = Command_Select_Key ;
  
  button[4].start_x = BUTTON_STAY_X+BUTTON_SpaceX*2;
  button[4].start_y = BUTTON_STAY_Y+BUTTON_SpaceY;
  button[4].end_x = BUTTON_STAY_X+BUTTON_SpaceX*2+BUTTON_WHITH ;
  button[4].end_y = BUTTON_STAY_Y+BUTTON_SpaceY+BUTTON_HIGHT;
  button[4].para = "3";
  button[4].touch_flag = 0;  
  button[4].draw_btn = Draw_Key_Button ;
  button[4].btn_command = Command_Select_Key ;
  
  button[5].start_x = BUTTON_STAY_X;
  button[5].start_y = BUTTON_STAY_Y+BUTTON_SpaceY*2;
  button[5].end_x = BUTTON_STAY_X+BUTTON_WHITH ;
  button[5].end_y = BUTTON_STAY_Y+BUTTON_SpaceY*2+BUTTON_HIGHT;
  button[5].para = "4";
  button[5].touch_flag = 0;  
  button[5].draw_btn = Draw_Key_Button ;
  button[5].btn_command = Command_Select_Key ;  
  
  button[6].start_x =  BUTTON_STAY_X+BUTTON_SpaceX;
  button[6].start_y = BUTTON_STAY_Y+BUTTON_SpaceY*2;
  button[6].end_x = BUTTON_STAY_X+BUTTON_SpaceX+BUTTON_WHITH ;
  button[6].end_y = BUTTON_STAY_Y+BUTTON_SpaceY*2+BUTTON_HIGHT;
  button[6].para = "5";
  button[6].touch_flag = 0;  
  button[6].draw_btn = Draw_Key_Button ;
  button[6].btn_command =  Command_Select_Key ;
  
  
 
  button[7].start_x = BUTTON_STAY_X+BUTTON_SpaceX*2;
  button[7].start_y = BUTTON_STAY_Y+BUTTON_SpaceY*2;
  button[7].end_x = BUTTON_STAY_X+BUTTON_SpaceX*2+BUTTON_WHITH ;
  button[7].end_y = BUTTON_STAY_Y+BUTTON_SpaceY*2+BUTTON_HIGHT;
  button[7].para = "6";
  button[7].touch_flag = 0;  
  button[7].draw_btn = Draw_Key_Button ;
  button[7].btn_command =  Command_Select_Key ;
  
  button[8].start_x = BUTTON_STAY_X;
  button[8].start_y = BUTTON_STAY_Y+BUTTON_SpaceY*3;
  button[8].end_x = BUTTON_STAY_X+BUTTON_WHITH ;
  button[8].end_y = BUTTON_STAY_Y+BUTTON_SpaceY*3+BUTTON_HIGHT;
  button[8].para = "7";
  button[8].touch_flag = 0;  
  button[8].draw_btn = Draw_Key_Button ;
  button[8].btn_command =  Command_Select_Key ;
  
  button[9].start_x = BUTTON_STAY_X+BUTTON_SpaceX;
  button[9].start_y = BUTTON_STAY_Y+BUTTON_SpaceY*3;
  button[9].end_x = BUTTON_STAY_X+BUTTON_SpaceX+BUTTON_WHITH ;
  button[9].end_y = BUTTON_STAY_Y+BUTTON_SpaceY*3+BUTTON_HIGHT;
  button[9].para = "8";
  button[9].touch_flag = 0;  
  button[9].draw_btn = Draw_Key_Button ;
  button[9].btn_command =  Command_Select_Key ;
  
  button[10].start_x = BUTTON_STAY_X+BUTTON_SpaceX*2;
  button[10].start_y = BUTTON_STAY_Y+BUTTON_SpaceY*3;
  button[10].end_x = BUTTON_STAY_X+BUTTON_SpaceX*2+BUTTON_WHITH ;
  button[10].end_y = BUTTON_STAY_Y+BUTTON_SpaceY*3+BUTTON_HIGHT;
  button[10].para = "9";
  button[10].touch_flag = 0;  
  button[10].draw_btn = Draw_Key_Button ;
  button[10].btn_command =  Command_Select_Key ;
  
  button[11].start_x = BUTTON_STAY_X;
  button[11].start_y = BUTTON_STAY_Y+BUTTON_SpaceY*4;
  button[11].end_x = BUTTON_STAY_X+BUTTON_WHITH ;
  button[11].end_y = BUTTON_STAY_Y+BUTTON_SpaceY*4+BUTTON_HIGHT;
  button[11].para = "ɾ��";
  button[11].touch_flag = 0;  
  button[11].draw_btn = Draw_Key_Button;
  button[11].btn_command =  Command_Select_Key ;
  
  button[12].start_x =  BUTTON_STAY_X+BUTTON_SpaceX;
  button[12].start_y = BUTTON_STAY_Y+BUTTON_SpaceY*4;
  button[12].end_x = BUTTON_STAY_X+BUTTON_SpaceX+BUTTON_WHITH ;
  button[12].end_y = BUTTON_STAY_Y+BUTTON_SpaceY*4+BUTTON_HIGHT;
  button[12].para = "0";
  button[12].touch_flag = 0;  
  button[12].draw_btn = Draw_Key_Button ;
  button[12].btn_command =  Command_Select_Key ;
  
  button[13].start_x = BUTTON_STAY_X+BUTTON_SpaceX*2;
  button[13].start_y = BUTTON_STAY_Y+BUTTON_SpaceY*4;
  button[13].end_x = BUTTON_STAY_X+BUTTON_SpaceX*2+BUTTON_WHITH ;
  button[13].end_y = BUTTON_STAY_Y+BUTTON_SpaceY*4+BUTTON_HIGHT;
  button[13].para = "ȷ��";
  button[13].touch_flag = 0;  
  button[13].draw_btn = Draw_Key_Button ;
  button[13].btn_command =  Command_Select_Key ;    
  
  button[14].start_x = 5;
  button[14].start_y = 5;
  button[14].end_x = 75 ;
  button[14].end_y = 45;
  button[14].para = "����";
  button[14].touch_flag = 0;  
  button[14].draw_btn = Draw_Key_Button ;
  button[14].btn_command =  Command_Select_Key ;    
  

  
 }


 /**
* @brief  Touch_Button_Down ����������ʱ���õĺ������ɴ���������
* @param  x ����λ�õ�x����
* @param  y ����λ�õ�y����
* @retval ��
*/
void Touch_Button_Down(uint16_t x,uint16_t y)
{
  uint8_t i;
  for(i=2;i<BUTTON_NUM;i++)
  {
	
			
		/* �������˰�ť */
		if(x<=button[i].end_x && y<=button[i].end_y && y>=button[i].start_y && x>=button[i].start_x )
		{
			
		  if(button[i].touch_flag == 0)     /*ԭ����״̬Ϊû�а��£������״̬*/
		  {
		   button[i].touch_flag = 1;         /* ��¼���±�־ */
		  
		   button[i].draw_btn(&button[i]);  /*�ػ水ť*/
			  
			  
		  }        
		  
		}
		else if(button[i].touch_flag == 1) /* �����Ƴ��˰����ķ�Χ��֮ǰ�а��°�ť */
		{
		  button[i].touch_flag = 0;         /* ������±�־���ж�Ϊ�����*/
		  
		  button[i].draw_btn(&button[i]);   /*�ػ水ť*/
		}
    
  }

}


/**
* @brief  Command_Select_Key �����Ĺ���ִ�к���
* @param  btn Touch_Button ���͵İ�������
* @retval ��
*/
static void Command_Select_Key(void *btn)
{
	
	char *p = passWord;
	
	sprintf(passWord,"%d",key_num);
    
    
	
	ILI9341_Clear(81,91,143,38);  //����ַ���ʾ����
    LCD_SetColors(RED,WHITE);
    LCD_SetFont(&Font16x24);
  
	ILI9341_DispString_EN_CH(	90,98,p);
	
	
	
}




/**
* @brief  Touch_Button_Up �������ͷ�ʱ���õĺ������ɴ���������
* @param  x ��������ͷ�ʱ��x����
* @param  y ��������ͷ�ʱ��y����
* @retval ��
*/
void Touch_Button_Up(uint16_t x,uint16_t y)
{
	
	int ret;
	uint8_t i; 
	
	
	for(i=2;i<BUTTON_NUM;i++)
     {
	 
		if(i!=13 && i!=14)
		{
		   /* �����ڰ�ť�����ͷ� */
			if((x<button[i].end_x && x>button[i].start_x && y<button[i].end_y && y>button[i].start_y))
			{        
				button[i].touch_flag = 0;       /*�ͷŴ�����־*/
			
				button[i].draw_btn(&button[i]); /*�ػ水ť*/        
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
			  
			
					button[i].btn_command(&button[i]);  /*ִ�а����Ĺ�������*/
			  
					break;
		    
			}
		}
		else 
	    {
				/* �����ڰ�ť�����ͷ� */
				if((x<button[i].end_x && x>button[i].start_x && y<button[i].end_y && y>button[i].start_y))
				{        
					button[i].touch_flag = 0;       /*�ͷŴ�����־*/
			
					button[i].draw_btn(&button[i]); /*�ػ水ť*/ 
            
			
					if(i==13)
					{
						ret=strcmp(passWord_0,passWord);  //������
			  
						if(ret==0)
						{
							
							Key_Board_Change_Init(LCD_SCAN_MODE);
						}
						else
						{
							Unlocking_Init(ret);
						}
			  
						break; 
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





/**
* @brief  ���ְ�ť����溯��
* @param  btn Touch_Button ���͵İ�������
* @retval ��
*/
static void Draw_Key_Button(void *btn)
{
  Touch_Button *ptr = (Touch_Button *)btn;
  
  /*�ͷŰ���*/
  if(ptr->touch_flag == 0)
  {
		/*����Ϊ���ܼ���Ӧ����ɫ*/
		LCD_SetColors(RED,WHITE);
	  LCD_SetFont(&Font16x24);
    ILI9341_DispString_EN_CH(	ptr->start_x+27,ptr->start_y+8,ptr->para);
  }
  else  /*��������*/
  {
    /*��ɫ����*/
		LCD_SetColors(WHITE,WHITE);
	  ILI9341_DrawRectangle(	ptr->start_x,
															ptr->start_y,
															ptr->end_x - ptr->start_x,
															ptr->end_y - ptr->start_y,1);
  } 
    /*��ť�߿�*/
		LCD_SetColors(BLUE,WHITE);
    ILI9341_DrawRectangle(	ptr->start_x,
															ptr->start_y,
															ptr->end_x - ptr->start_x,
															ptr->end_y - ptr->start_y,0);
  
}





