#include "./fingerprint/fingerprint.h"
#include "./interface/interface.h"


uint32_t Finger_num=0;
Touch_Button_Finger button_1[5];
int Detection_Finger=OFF;



void Finger_Init(uint8_t LCD_Mode)
{


    uint8_t i;
    key_num=0;
    Finger_num=0;
    interface=3;

    ILI9341_GramScan ( LCD_Mode );


    /* ������Ϊ��ɫ */
    LCD_SetBackColor(WHITE);
    ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);

    /* ��ʼ����ť */
    Touch_Button_Finger_Init();

    /* ��水ť */
    for(i=0; i<5; i++)
    {
        button_1[i].draw_btn(&button_1[i]);

    }

}

void Touch_Button_Finger_Init(void)
{
    button_1[0].start_x = 5;
    button_1[0].start_y = 5;
    button_1[0].end_x = 105;
    button_1[0].end_y = 75;
    button_1[0].para = "���ָ��";
    button_1[0].touch_flag = 0;
    button_1[0].draw_btn = Draw_Finger_Button ;
    button_1[0].btn_command = Command_Select_Finger;

    button_1[1].start_x = 5;
    button_1[1].start_y = 80;
    button_1[1].end_x = 105;
    button_1[1].end_y = 150;
    button_1[1].para = "�Ա�ָ��";
    button_1[1].touch_flag = 0;
    button_1[1].draw_btn = Draw_Finger_Button ;
    button_1[1].btn_command = Command_Select_Finger;

    button_1[2].start_x =  5;
    button_1[2].start_y = 155;
    button_1[2].end_x = 105 ;
    button_1[2].end_y = 225;
    button_1[2].para = "ɾ��ָ��ָ��";
    button_1[2].touch_flag = 0;
    button_1[2].draw_btn = Draw_Finger_Button ;
    button_1[2].btn_command = Command_Select_Finger;

    button_1[3].start_x = 5;
    button_1[3].start_y = 230;
    button_1[3].end_x = 105 ;
    button_1[3].end_y = 300;
    button_1[3].para = "���ָ�ƿ�";
    button_1[3].touch_flag = 0;
    button_1[3].draw_btn = Draw_Finger_Button ;
    button_1[3].btn_command = Command_Select_Finger;

    button_1[4].start_x = 110;
    button_1[4].start_y = 5;
    button_1[4].end_x = 235 ;
    button_1[4].end_y = 300;
    button_1[4].para = "����";
    button_1[4].touch_flag = 0;
    button_1[4].draw_btn = Draw_Finger_Button ;
    button_1[4].btn_command = Command_Select_Finger;

}




void Touch_Button_Finger_Down(uint16_t x,uint16_t y)
{
    uint8_t i;
    for(i=0; i<5; i++)
    {


        /* �������˰�ť */
        if(x<=button_1[i].end_x && y<=button_1[i].end_y && y>=button_1[i].start_y && x>=button_1[i].start_x )
        {

            if(button_1[i].touch_flag == 0)     /*ԭ����״̬Ϊû�а��£������״̬*/
            {
                button_1[i].touch_flag = 1;         /* ��¼���±�־ */

                button_1[i].draw_btn(&button_1[i]);  /*�ػ水ť*/


            }

        }
        else if(button_1[i].touch_flag == 1) /* �����Ƴ��˰����ķ�Χ��֮ǰ�а��°�ť */
        {
            button_1[i].touch_flag = 0;         /* ������±�־���ж�Ϊ�����*/

            button_1[i].draw_btn(&button_1[i]);   /*�ػ水ť*/
        }

    }

}




/**
* @brief  Command_Select_Key �����Ĺ���ִ�к���
* @param  btn Touch_Button ���͵İ�������
* @retval ��
*/
static void Command_Select_Finger(void *btn)
{

    Detection_Finger=OFF;

    while(Detection_Finger)
    {
        FR_Task();
    }


}




/**
* @brief  Touch_Button_Up �������ͷ�ʱ���õĺ������ɴ���������
* @param  x ��������ͷ�ʱ��x����
* @param  y ��������ͷ�ʱ��y����
* @retval ��
*/
void Touch_Button_Finger_Up(uint16_t x,uint16_t y)
{

    uint8_t i;
    for(i=0; i<5; i++)
    {

        /* �����ڰ�ť�����ͷ� */
        if((x<button_1[i].end_x && x>button_1[i].start_x && y<button_1[i].end_y && y>button_1[i].start_y))
        {
            button_1[i].touch_flag = 0;       /*�ͷŴ�����־*/

            button_1[i].draw_btn(&button_1[i]); /*�ػ水ť*/

            if(i!=4)
            {
                Finger_num=i+1;

                button_1[i].btn_command(&button_1[i]);  /*ִ�а����Ĺ�������*/

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
static void Draw_Finger_Button(void *btn)
{
    Touch_Button_Finger *ptr = (Touch_Button_Finger *)btn ;

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





