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


    /* 整屏清为白色 */
    LCD_SetBackColor(WHITE);
    ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);

    /* 初始化按钮 */
    Touch_Button_Finger_Init();

    /* 描绘按钮 */
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
    button_1[0].para = "添加指纹";
    button_1[0].touch_flag = 0;
    button_1[0].draw_btn = Draw_Finger_Button ;
    button_1[0].btn_command = Command_Select_Finger;

    button_1[1].start_x = 5;
    button_1[1].start_y = 80;
    button_1[1].end_x = 105;
    button_1[1].end_y = 150;
    button_1[1].para = "对比指纹";
    button_1[1].touch_flag = 0;
    button_1[1].draw_btn = Draw_Finger_Button ;
    button_1[1].btn_command = Command_Select_Finger;

    button_1[2].start_x =  5;
    button_1[2].start_y = 155;
    button_1[2].end_x = 105 ;
    button_1[2].end_y = 225;
    button_1[2].para = "删除指定指纹";
    button_1[2].touch_flag = 0;
    button_1[2].draw_btn = Draw_Finger_Button ;
    button_1[2].btn_command = Command_Select_Finger;

    button_1[3].start_x = 5;
    button_1[3].start_y = 230;
    button_1[3].end_x = 105 ;
    button_1[3].end_y = 300;
    button_1[3].para = "清空指纹库";
    button_1[3].touch_flag = 0;
    button_1[3].draw_btn = Draw_Finger_Button ;
    button_1[3].btn_command = Command_Select_Finger;

    button_1[4].start_x = 110;
    button_1[4].start_y = 5;
    button_1[4].end_x = 235 ;
    button_1[4].end_y = 300;
    button_1[4].para = "返回";
    button_1[4].touch_flag = 0;
    button_1[4].draw_btn = Draw_Finger_Button ;
    button_1[4].btn_command = Command_Select_Finger;

}




void Touch_Button_Finger_Down(uint16_t x,uint16_t y)
{
    uint8_t i;
    for(i=0; i<5; i++)
    {


        /* 触摸到了按钮 */
        if(x<=button_1[i].end_x && y<=button_1[i].end_y && y>=button_1[i].start_y && x>=button_1[i].start_x )
        {

            if(button_1[i].touch_flag == 0)     /*原本的状态为没有按下，则更新状态*/
            {
                button_1[i].touch_flag = 1;         /* 记录按下标志 */

                button_1[i].draw_btn(&button_1[i]);  /*重绘按钮*/


            }

        }
        else if(button_1[i].touch_flag == 1) /* 触摸移出了按键的范围且之前有按下按钮 */
        {
            button_1[i].touch_flag = 0;         /* 清除按下标志，判断为误操作*/

            button_1[i].draw_btn(&button_1[i]);   /*重绘按钮*/
        }

    }

}




/**
* @brief  Command_Select_Key 按键的功能执行函数
* @param  btn Touch_Button 类型的按键参数
* @retval 无
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
* @brief  Touch_Button_Up 按键被释放时调用的函数，由触摸屏调用
* @param  x 触摸最后释放时的x坐标
* @param  y 触摸最后释放时的y坐标
* @retval 无
*/
void Touch_Button_Finger_Up(uint16_t x,uint16_t y)
{

    uint8_t i;
    for(i=0; i<5; i++)
    {

        /* 触笔在按钮区域释放 */
        if((x<button_1[i].end_x && x>button_1[i].start_x && y<button_1[i].end_y && y>button_1[i].start_y))
        {
            button_1[i].touch_flag = 0;       /*释放触摸标志*/

            button_1[i].draw_btn(&button_1[i]); /*重绘按钮*/

            if(i!=4)
            {
                Finger_num=i+1;

                button_1[i].btn_command(&button_1[i]);  /*执行按键的功能命令*/

                break;
            }
            else
            {
                Interface_Init(LCD_SCAN_MODE);  //返回初始界面
                break;
            }


        }
    }
}





/**
* @brief  数字按钮的描绘函数
* @param  btn Touch_Button 类型的按键参数
* @retval 无
*/
static void Draw_Finger_Button(void *btn)
{
    Touch_Button_Finger *ptr = (Touch_Button_Finger *)btn ;

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





