#include "./LD3320/LD3320.h"
#include "./Unlocking/Unlocking.h"



Touch_Button_ASR button_2[2];
int Detection_ASR=OFF;



void ASR_Init(uint8_t LCD_Mode)
{
		
    uint8_t i;
    
    interface=5;

    ILI9341_GramScan ( LCD_Mode );


    /* ������Ϊ��ɫ */
    LCD_SetBackColor(WHITE);
    ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);

    /* ��ʼ����ť */
    Touch_Button_ASR_Init();

    /* ��水ť */
    for(i=0; i<2; i++)
    {
        button_2[i].draw_btn(&button_2[i]);

    }

	
	

    

}



void Touch_Button_ASR_Init(void)
{
    button_2[0].start_x = 5;
    button_2[0].start_y = 5;
    button_2[0].end_x = 235;
    button_2[0].end_y = 155;
    button_2[0].para = "��ʼ���";
    button_2[0].touch_flag = 0;
    button_2[0].draw_btn = Draw_ASR_Button ;
    button_2[0].btn_command = Command_Select_ASR;

    
    button_2[1].start_x = 5;
    button_2[1].start_y = 160;
    button_2[1].end_x = 235 ;
    button_2[1].end_y = 300;
    button_2[1].para = "����";
    button_2[1].touch_flag = 0;
    button_2[1].draw_btn = Draw_ASR_Button ;
    button_2[1].btn_command = Command_Select_ASR;

}



void Touch_Button_ASR_Down(uint16_t x,uint16_t y)
{
    uint8_t i;
    for(i=0; i<2; i++)
    {


        /* �������˰�ť */
        if(x<=button_2[i].end_x && y<=button_2[i].end_y && y>=button_2[i].start_y && x>=button_2[i].start_x )
        {

            if(button_2[i].touch_flag == 0)     /*ԭ����״̬Ϊû�а��£������״̬*/
            {
                button_2[i].touch_flag = 1;         /* ��¼���±�־ */

                button_2[i].draw_btn(&button_2[i]);  /*�ػ水ť*/


            }

        }
        else if(button_2[i].touch_flag == 1) /* �����Ƴ��˰����ķ�Χ��֮ǰ�а��°�ť */
        {
            button_2[i].touch_flag = 0;         /* ������±�־���ж�Ϊ�����*/

            button_2[i].draw_btn(&button_2[i]);   /*�ػ水ť*/
        }

    }

}



/**
* @brief  Command_Select_Key �����Ĺ���ִ�к���
* @param  btn Touch_Button ���͵İ�������
* @retval ��
*/
static void Command_Select_ASR(void *btn)
{

    char ch,aa;
		int ret;
		Detection_ASR=OFF;
		
	
    while(Detection_ASR)
    {
        /* ��ȡ�ַ�ָ�� */
        ch=getchar();
        if(ch=='0')
				{
					ILI9341_DispString_EN_CH(	90,158,"��˵����������");
					while(Detection_ASR)
					{
					aa=getchar();
					
					 switch(aa)
						{
				
							case '1':
								{ 
										ret=0;
										Unlocking_Init(ret);  //ִ�п���
									break;
								}
				
							case '2':
								{
										ret=1;
										Unlocking_Init(ret);  //����ʧ��
								}
        
					
						}
					
					
       
				  }  

            
      }
    }


}





/**
* @brief  Touch_Button_Up �������ͷ�ʱ���õĺ������ɴ���������
* @param  x ��������ͷ�ʱ��x����
* @param  y ��������ͷ�ʱ��y����
* @retval ��
*/
void Touch_Button_ASR_Up(uint16_t x,uint16_t y)
{

    uint8_t i;
    for(i=0; i<2; i++)
    {

        /* �����ڰ�ť�����ͷ� */
        if((x<button_2[i].end_x && x>button_2[i].start_x && y<button_2[i].end_y && y>button_2[i].start_y))
        {
            button_2[i].touch_flag = 0;       /*�ͷŴ�����־*/

            button_2[i].draw_btn(&button_2[i]); /*�ػ水ť*/

            if(i==0)
            {
                ILI9341_Clear(0,0,240,320);
								LCD_SetColors(RED,WHITE);
								LCD_SetFont(&Font16x24);
								ILI9341_DispString_EN_CH(	90,98,"��˵��һ������");
                button_2[i].btn_command(&button_2[i]);  /*ִ�а����Ĺ�������*/

                break;
            }
            else
            {
                Interface_Init(LCD_SCAN_MODE);  //���س�ʼ����
                break;
            }


        }
    }
}





/**
* @brief  ���ְ�ť����溯��
* @param  btn Touch_Button ���͵İ�������
* @retval ��
*/
static void Draw_ASR_Button(void *btn)
{
    Touch_Button_ASR *ptr = (Touch_Button_ASR *)btn ;

    /*�ͷŰ���*/
    if(ptr->touch_flag == 0)
    {
        /*����Ϊ���ܼ���Ӧ����ɫ*/
        LCD_SetColors(RED,WHITE);
        LCD_SetFont(&Font16x24);
        ILI9341_DispString_EN_CH(	ptr->start_x+5,ptr->start_y+50,ptr->para);
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







