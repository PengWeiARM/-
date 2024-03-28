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

    /* 整屏清为白色 */
    LCD_SetBackColor(WHITE);
    ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);


    /* 初始化按钮 */
    Touch_Button_Interface_Init();

    /* 描绘按钮 */
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
    button_0[0].para = "密码识别";
    button_0[0].touch_flag = 0;
    button_0[0].draw_btn = Draw_Interface_Button ;


    button_0[1].start_x =  5;
    button_0[1].start_y = 80;
    button_0[1].end_x = 105 ;
    button_0[1].end_y = 150;
    button_0[1].para = "指纹识别";
    button_0[1].touch_flag = 0;
    button_0[1].draw_btn = Draw_Interface_Button ;


    button_0[2].start_x = 5;
    button_0[2].start_y = 155;
    button_0[2].end_x = 105 ;
    button_0[2].end_y = 225;
    button_0[2].para = "语音识别";
    button_0[2].touch_flag = 0;
    button_0[2].draw_btn = Draw_Interface_Button ;


    button_0[3].start_x =  5;
    button_0[3].start_y = 230;
    button_0[3].end_x = 105 ;
    button_0[3].end_y = 300;
    button_0[3].para = "上位机控制";
    button_0[3].touch_flag = 0;
    button_0[3].draw_btn = Draw_Interface_Button ;


}





/**
* @brief  Touch_Button_Up 按键被释放时调用的函数，由触摸屏调用
* @param  x 触摸最后释放时的x坐标
* @param  y 触摸最后释放时的y坐标
* @retval 无
*/
void Touch_Button_Interface_Up(uint16_t x,uint16_t y)
{

    uint8_t i;
    
    for(i=0; i<4; i++)
    {

        /* 触笔在按钮区域释放 */
        if((x<button_0[i].end_x && x>button_0[i].start_x && y<button_0[i].end_y && y>button_0[i].start_y))
        {
            button_0[i].touch_flag = 0;       /*释放触摸标志*/

            button_0[i].draw_btn(&button_0[i]); /*重绘按钮*/

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
							ESP8266_StaTcpServer_ConfigTest();                                             //对ESP8266进行配置 STA模式
							#else
							ESP8266_ApTcpServer_ConfigTest();                                              //对ESP8266进行配置 AP模式
							#endif
						
            }


            break;


        }
    }
}


/**
* @brief  Touch_Button_Interface_Down 按键被按下时调用的函数，由触摸屏调用
* @param  x 触摸位置的x坐标
* @param  y 触摸位置的y坐标
* @retval 无
*/
void Touch_Button_Interface_Down(uint16_t x,uint16_t y)
{
    uint8_t i;
    for(i=0; i<4; i++)
    {


        /* 触摸到了按钮 */
        if(x<=button_0[i].end_x && y<=button_0[i].end_y && y>=button_0[i].start_y && x>=button_0[i].start_x )
        {

            if(button_0[i].touch_flag == 0)     /*原本的状态为没有按下，则更新状态*/
            {
                button_0[i].touch_flag = 1;         /* 记录按下标志 */

                button_0[i].draw_btn(&button_0[i]);  /*重绘按钮*/


            }

        }
        else if(button_0[i].touch_flag == 1) /* 触摸移出了按键的范围且之前有按下按钮 */
        {
            button_0[i].touch_flag = 0;         /* 清除按下标志，判断为误操作*/

            button_0[i].draw_btn(&button_0[i]);   /*重绘按钮*/
        }

    }

}





/**
* @brief  数字按钮的描绘函数
* @param  btn Touch_Button 类型的按键参数
* @retval 无
*/
static void Draw_Interface_Button(void *btn)
{
    Touch_Button_Interface *ptr = (Touch_Button_Interface *)btn ;

    /*释放按键*/
    if(ptr->touch_flag == 0)
    {
        /*背景为功能键相应的颜色*/
        LCD_SetColors(RED,WHITE);
        LCD_SetFont(&Font16x24);
        ILI9341_DispString_EN_CH(	ptr->start_x+5,ptr->start_y+20,ptr->para);
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



