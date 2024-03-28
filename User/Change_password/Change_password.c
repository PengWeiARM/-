#include "./Change_password/Change_password.h"
#include "./interface/interface.h" 
#include "./Unlocking/Unlocking.h"



char passWord_Now[];
Touch_Button button_change[15];






void Key_Board_Change_Init(uint8_t LCD_Mode)
{
	
	
    uint8_t i;
	key_num=0;
	interface=2;
	
	
	ILI9341_GramScan ( LCD_Mode );
	
  /* ������Ϊ��ɫ */
	LCD_SetBackColor(WHITE);
  ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);	

  
  /* ��ʼ����ť */
  Touch_Button_Change_Init();
  
  /* ��水ť */
  for(i=0;i<BUTTON_NUM_CHANGE;i++)
  {
    button_change[i].draw_btn(&button_change[i]);
	  
  }
  
  
}



void Touch_Button_Change_Init(void)
{
  
  button_change[0].start_x = BUTTON_STAY_X;                       //5
  button_change[0].start_y = BUTTON_STAY_Y;                      //90
  button_change[0].end_x = BUTTON_STAY_X+BUTTON_WHITH;           //5+70
  button_change[0].end_y = BUTTON_STAY_Y+BUTTON_HIGHT;            //90+40
  button_change[0].para = "������";
  button_change[0].touch_flag = 0;  
  button_change[0].draw_btn = Draw_Key_Change_Button_1 ;
  
  
  button_change[1].start_x =  BUTTON_STAY_X+BUTTON_SpaceX;                    //5
  button_change[1].start_y = BUTTON_STAY_Y;                      //90
  button_change[1].end_x = BUTTON_STAY_X+BUTTON_SpaceX*2+BUTTON_WHITH ; //5+75*2+70
  button_change[1].end_y = BUTTON_STAY_Y+BUTTON_HIGHT;              //90+40
  button_change[1].para = "";
  button_change[1].touch_flag = 0;  
  button_change[1].draw_btn = Draw_Key_Change_Button ;
  
  
  button_change[2].start_x = BUTTON_STAY_X;
  button_change[2].start_y = BUTTON_STAY_Y+BUTTON_SpaceY;
  button_change[2].end_x = BUTTON_STAY_X+BUTTON_WHITH ;
  button_change[2].end_y = BUTTON_STAY_Y+BUTTON_SpaceY+BUTTON_HIGHT;
  button_change[2].para = "1";
  button_change[2].touch_flag = 0;  
  button_change[2].draw_btn = Draw_Key_Change_Button ;
  button_change[2].btn_command = Command_Select_Key_Change ;
  
  button_change[3].start_x =  BUTTON_STAY_X+BUTTON_SpaceX;
  button_change[3].start_y = BUTTON_STAY_Y+BUTTON_SpaceY;
  button_change[3].end_x = BUTTON_STAY_X+BUTTON_SpaceX+BUTTON_WHITH ;
  button_change[3].end_y = BUTTON_STAY_Y+BUTTON_SpaceY+BUTTON_HIGHT;
  button_change[3].para = "2";
  button_change[3].touch_flag = 0;  
  button_change[3].draw_btn = Draw_Key_Change_Button ;
  button_change[3].btn_command = Command_Select_Key_Change ;
  
  button_change[4].start_x = BUTTON_STAY_X+BUTTON_SpaceX*2;
  button_change[4].start_y = BUTTON_STAY_Y+BUTTON_SpaceY;
  button_change[4].end_x = BUTTON_STAY_X+BUTTON_SpaceX*2+BUTTON_WHITH ;
  button_change[4].end_y = BUTTON_STAY_Y+BUTTON_SpaceY+BUTTON_HIGHT;
  button_change[4].para = "3";
  button_change[4].touch_flag = 0;  
  button_change[4].draw_btn = Draw_Key_Change_Button ;
  button_change[4].btn_command = Command_Select_Key_Change ;
  
  button_change[5].start_x = BUTTON_STAY_X;
  button_change[5].start_y = BUTTON_STAY_Y+BUTTON_SpaceY*2;
  button_change[5].end_x = BUTTON_STAY_X+BUTTON_WHITH ;
  button_change[5].end_y = BUTTON_STAY_Y+BUTTON_SpaceY*2+BUTTON_HIGHT;
  button_change[5].para = "4";
  button_change[5].touch_flag = 0;  
  button_change[5].draw_btn = Draw_Key_Change_Button ;
  button_change[5].btn_command = Command_Select_Key_Change ;  
  
  button_change[6].start_x =  BUTTON_STAY_X+BUTTON_SpaceX;
  button_change[6].start_y = BUTTON_STAY_Y+BUTTON_SpaceY*2;
  button_change[6].end_x = BUTTON_STAY_X+BUTTON_SpaceX+BUTTON_WHITH ;
  button_change[6].end_y = BUTTON_STAY_Y+BUTTON_SpaceY*2+BUTTON_HIGHT;
  button_change[6].para = "5";
  button_change[6].touch_flag = 0;  
  button_change[6].draw_btn = Draw_Key_Change_Button ;
  button_change[6].btn_command =  Command_Select_Key_Change ;
  
  
 
  button_change[7].start_x = BUTTON_STAY_X+BUTTON_SpaceX*2;
  button_change[7].start_y = BUTTON_STAY_Y+BUTTON_SpaceY*2;
  button_change[7].end_x = BUTTON_STAY_X+BUTTON_SpaceX*2+BUTTON_WHITH ;
  button_change[7].end_y = BUTTON_STAY_Y+BUTTON_SpaceY*2+BUTTON_HIGHT;
  button_change[7].para = "6";
  button_change[7].touch_flag = 0;  
  button_change[7].draw_btn = Draw_Key_Change_Button ;
  button_change[7].btn_command =  Command_Select_Key_Change ;
  
  button_change[8].start_x = BUTTON_STAY_X;
  button_change[8].start_y = BUTTON_STAY_Y+BUTTON_SpaceY*3;
  button_change[8].end_x = BUTTON_STAY_X+BUTTON_WHITH ;
  button_change[8].end_y = BUTTON_STAY_Y+BUTTON_SpaceY*3+BUTTON_HIGHT;
  button_change[8].para = "7";
  button_change[8].touch_flag = 0;  
  button_change[8].draw_btn = Draw_Key_Change_Button ;
  button_change[8].btn_command =  Command_Select_Key_Change ;
  
  button_change[9].start_x = BUTTON_STAY_X+BUTTON_SpaceX;
  button_change[9].start_y = BUTTON_STAY_Y+BUTTON_SpaceY*3;
  button_change[9].end_x = BUTTON_STAY_X+BUTTON_SpaceX+BUTTON_WHITH ;
  button_change[9].end_y = BUTTON_STAY_Y+BUTTON_SpaceY*3+BUTTON_HIGHT;
  button_change[9].para = "8";
  button_change[9].touch_flag = 0;  
  button_change[9].draw_btn = Draw_Key_Change_Button ;
  button_change[9].btn_command =  Command_Select_Key_Change ;
  
  button_change[10].start_x = BUTTON_STAY_X+BUTTON_SpaceX*2;
  button_change[10].start_y = BUTTON_STAY_Y+BUTTON_SpaceY*3;
  button_change[10].end_x = BUTTON_STAY_X+BUTTON_SpaceX*2+BUTTON_WHITH ;
  button_change[10].end_y = BUTTON_STAY_Y+BUTTON_SpaceY*3+BUTTON_HIGHT;
  button_change[10].para = "9";
  button_change[10].touch_flag = 0;  
  button_change[10].draw_btn = Draw_Key_Change_Button ;
  button_change[10].btn_command =  Command_Select_Key_Change ;
  
  button_change[11].start_x = BUTTON_STAY_X;
  button_change[11].start_y = BUTTON_STAY_Y+BUTTON_SpaceY*4;
  button_change[11].end_x = BUTTON_STAY_X+BUTTON_WHITH ;
  button_change[11].end_y = BUTTON_STAY_Y+BUTTON_SpaceY*4+BUTTON_HIGHT;
  button_change[11].para = "ɾ��";
  button_change[11].touch_flag = 0;  
  button_change[11].draw_btn = Draw_Key_Change_Button;
  button_change[11].btn_command =  Command_Select_Key_Change ;
  
  button_change[12].start_x =  BUTTON_STAY_X+BUTTON_SpaceX;
  button_change[12].start_y = BUTTON_STAY_Y+BUTTON_SpaceY*4;
  button_change[12].end_x = BUTTON_STAY_X+BUTTON_SpaceX+BUTTON_WHITH ;
  button_change[12].end_y = BUTTON_STAY_Y+BUTTON_SpaceY*4+BUTTON_HIGHT;
  button_change[12].para = "0";
  button_change[12].touch_flag = 0;  
  button_change[12].draw_btn = Draw_Key_Change_Button ;
  button_change[12].btn_command =  Command_Select_Key_Change ;
  
  button_change[13].start_x = BUTTON_STAY_X+BUTTON_SpaceX*2;
  button_change[13].start_y = BUTTON_STAY_Y+BUTTON_SpaceY*4;
  button_change[13].end_x = BUTTON_STAY_X+BUTTON_SpaceX*2+BUTTON_WHITH ;
  button_change[13].end_y = BUTTON_STAY_Y+BUTTON_SpaceY*4+BUTTON_HIGHT;
  button_change[13].para = "�޸�";
  button_change[13].touch_flag = 0;  
  button_change[13].draw_btn = Draw_Key_Change_Button ;
  button_change[13].btn_command =  Command_Select_Key_Change ;    
  
  button_change[14].start_x = 5;
  button_change[14].start_y = 5;
  button_change[14].end_x = 75 ;
  button_change[14].end_y = 45;
  button_change[14].para = "ȡ��";
  button_change[14].touch_flag = 0;  
  button_change[14].draw_btn = Draw_Key_Change_Button ;
  button_change[14].btn_command =  Command_Select_Key_Change ; 
  
 
  
 }

 
 /**
* @brief  Touch_Button_Up �������ͷ�ʱ���õĺ������ɴ���������
* @param  x ��������ͷ�ʱ��x����
* @param  y ��������ͷ�ʱ��y����
* @retval ��
*/
void Touch_Button_Change_Up(uint16_t x,uint16_t y)
{
	
	
	uint8_t i; 
	int ret;
	
	for(i=2;i<BUTTON_NUM_CHANGE;i++)
     {
	 
		if(i!=13 && i!=14 && i!=15) //���ְ���
		{
			/* �����ڰ�ť�����ͷ� */
			if((x<button_change[i].end_x && x>button_change[i].start_x && y<button_change[i].end_y && y>button_change[i].start_y))
			{        
				button_change[i].touch_flag = 0;       /*�ͷŴ�����־*/
			
				button_change[i].draw_btn(&button_change[i]); /*�ػ水ť*/        
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
			  
				button_change[i].btn_command(&button_change[i]);  /*ִ�а����Ĺ�������*/
			  
				break;
		    
			}
		}
		   else   //���ܰ���
	        {
				/* �����ڰ�ť�����ͷ� */
				if((x<button_change[i].end_x && x>button_change[i].start_x && y<button_change[i].end_y && y>button_change[i].start_y))
				{        
					button_change[i].touch_flag = 0;       /*�ͷŴ�����־*/
			
					button_change[i].draw_btn(&button_change[i]); /*�ػ水ť*/ 
            
			
					if(i==13)
					{
						strcpy(passWord_0,passWord_Now);  //�޸�����
			  
						Interface_Init(LCD_SCAN_MODE);  //���س�ʼ����
					
						break; 
					
					}
			  
					if(i==14)
					{
						ret=0;
					
						Unlocking_Init(ret);  //ִ�п���
			  
						break; 
					}	
					
				}
	  
	         }
			
      }
	 
}



void Touch_Button_Change_Down(uint16_t x,uint16_t y)
{
  uint8_t i;
  for(i=2;i<BUTTON_NUM_CHANGE;i++)
  {
	
			
		/* �������˰�ť */
		if(x<=button_change[i].end_x && y<=button_change[i].end_y && y>=button_change[i].start_y && x>=button_change[i].start_x )
		{
			
		  if(button_change[i].touch_flag == 0)     /*ԭ����״̬Ϊû�а��£������״̬*/
		  {
		   button_change[i].touch_flag = 1;         /* ��¼���±�־ */
		  
		   button_change[i].draw_btn(&button_change[i]);  /*�ػ水ť*/
			  
			  
		  }        
		  
		}
		else if(button_change[i].touch_flag == 1) /* �����Ƴ��˰����ķ�Χ��֮ǰ�а��°�ť */
		{
		  button_change[i].touch_flag = 0;         /* ������±�־���ж�Ϊ�����*/
		  
		  button_change[i].draw_btn(&button_change[i]);   /*�ػ水ť*/
		}
    
  }

}




/**
* @brief  Command_Select_Key_Change �����Ĺ���ִ�к���
* @param  btn Touch_Button ���͵İ�������
* @retval ��
*/
static void Command_Select_Key_Change(void *btn)
{
	
	char *p = passWord_Now;
	
	sprintf(passWord_Now,"%d",key_num);
    
    
	
	ILI9341_Clear(81,91,143,38);
    LCD_SetColors(RED,WHITE);
    LCD_SetFont(&Font16x24);
  
	ILI9341_DispString_EN_CH(	90,98,p);
	
	
	
}

/**
* @brief  ���ְ�ť����溯��
* @param  btn Touch_Button ���͵İ�������
* @retval ��
*/
static void Draw_Key_Change_Button(void *btn)
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



/**
* @brief  ��ť����溯��
* @param  btn Touch_Button_1 ���͵İ�������
* @retval ��
*/
static void Draw_Key_Change_Button_1(void *btn)
{
  Touch_Button *ptr = (Touch_Button *)btn;
  
  /*�ͷŰ���*/
  if(ptr->touch_flag == 0)
  {
		/*����Ϊ���ܼ���Ӧ����ɫ*/
		LCD_SetColors(RED,WHITE);
	  LCD_SetFont(&Font16x24);
    ILI9341_DispString_EN_CH(	ptr->start_x+5,ptr->start_y+10,ptr->para);
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



