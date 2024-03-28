#include "./interface/interface.h"
#include "./LD3320/LD3320.h"
#include "./Common/Common.h"
#include "./usart/bsp_usart1.h"
#include "./ESP8266/bsp_esp8266.h"
#include "./ESP8266/bsp_esp8266_test.h"
//#include "./dwt_delay/core_delay.h"



Touch_Button_Interface button_0[4];



void Interface_Init(uint8_t LCD_Mode)
{


    uint8_t i;
    key_num=0;
    interface=0;
    Detection_Finger=ON;
		Detection_ASR=ON;
	
    ILI9341_GramScan ( LCD_Mode );

    /* ������Ϊ��ɫ */
    LCD_SetBackColor(WHITE);
    ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);


    /* ��ʼ����ť */
    Touch_Button_Interface_Init();

    /* ��水ť */
    for(i=0; i<4; i++)
    {
        button_0[i].draw_btn(&button_0[i]);

    }

}



void Touch_Button_Interface_Init(void)
{


    button_0[0].start_x = 5;
    button_0[0].start_y = 5;
    button_0[0].end_x = 105;
    button_0[0].end_y = 75;
    button_0[0].para = "����ʶ��";
    button_0[0].touch_flag = 0;
    button_0[0].draw_btn = Draw_Interface_Button ;


    button_0[1].start_x =  5;
    button_0[1].start_y = 80;
    button_0[1].end_x = 105 ;
    button_0[1].end_y = 150;
    button_0[1].para = "ָ��ʶ��";
    button_0[1].touch_flag = 0;
    button_0[1].draw_btn = Draw_Interface_Button ;


    button_0[2].start_x = 5;
    button_0[2].start_y = 155;
    button_0[2].end_x = 105 ;
    button_0[2].end_y = 225;
    button_0[2].para = "����ʶ��";
    button_0[2].touch_flag = 0;
    button_0[2].draw_btn = Draw_Interface_Button ;


    button_0[3].start_x =  5;
    button_0[3].start_y = 230;
    button_0[3].end_x = 105 ;
    button_0[3].end_y = 300;
    button_0[3].para = "��λ������";
    button_0[3].touch_flag = 0;
    button_0[3].draw_btn = Draw_Interface_Button ;


}





/**
* @brief  Touch_Button_Up �������ͷ�ʱ���õĺ������ɴ���������
* @param  x ��������ͷ�ʱ��x����
* @param  y ��������ͷ�ʱ��y����
* @retval ��
*/
void Touch_Button_Interface_Up(uint16_t x,uint16_t y)
{

    uint8_t i;
    
    for(i=0; i<4; i++)
    {

        /* �����ڰ�ť�����ͷ� */
        if((x<button_0[i].end_x && x>button_0[i].start_x && y<button_0[i].end_y && y>button_0[i].start_y))
        {
            button_0[i].touch_flag = 0;       /*�ͷŴ�����־*/

            button_0[i].draw_btn(&button_0[i]); /*�ػ水ť*/

            if(i==0)
            {

                Key_Board_Init(LCD_SCAN_MODE);
            }
            if(i==1)
            {

                Finger_Init(LCD_SCAN_MODE);
            }
            if(i==2)
            {
                ASR_Init(LCD_SCAN_MODE);

            }
						if(i==3)
            {
               
							#ifndef BUILTAP_TEST
							ESP8266_StaTcpServer_ConfigTest();                                             //��ESP8266�������� STAģʽ
							#else
							ESP8266_ApTcpServer_ConfigTest();                                              //��ESP8266�������� APģʽ
							#endif
						
            }


            break;


        }
    }
}


/**
* @brief  Touch_Button_Interface_Down ����������ʱ���õĺ������ɴ���������
* @param  x ����λ�õ�x����
* @param  y ����λ�õ�y����
* @retval ��
*/
void Touch_Button_Interface_Down(uint16_t x,uint16_t y)
{
    uint8_t i;
    for(i=0; i<4; i++)
    {


        /* �������˰�ť */
        if(x<=button_0[i].end_x && y<=button_0[i].end_y && y>=button_0[i].start_y && x>=button_0[i].start_x )
        {

            if(button_0[i].touch_flag == 0)     /*ԭ����״̬Ϊû�а��£������״̬*/
            {
                button_0[i].touch_flag = 1;         /* ��¼���±�־ */

                button_0[i].draw_btn(&button_0[i]);  /*�ػ水ť*/


            }

        }
        else if(button_0[i].touch_flag == 1) /* �����Ƴ��˰����ķ�Χ��֮ǰ�а��°�ť */
        {
            button_0[i].touch_flag = 0;         /* ������±�־���ж�Ϊ�����*/

            button_0[i].draw_btn(&button_0[i]);   /*�ػ水ť*/
        }

    }

}





/**
* @brief  ���ְ�ť����溯��
* @param  btn Touch_Button ���͵İ�������
* @retval ��
*/
static void Draw_Interface_Button(void *btn)
{
    Touch_Button_Interface *ptr = (Touch_Button_Interface *)btn ;

    /*�ͷŰ���*/
    if(ptr->touch_flag == 0)
    {
        /*����Ϊ���ܼ���Ӧ����ɫ*/
        LCD_SetColors(RED,WHITE);
        LCD_SetFont(&Font16x24);
        ILI9341_DispString_EN_CH(	ptr->start_x+5,ptr->start_y+20,ptr->para);
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



