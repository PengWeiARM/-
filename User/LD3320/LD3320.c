#include "./LD3320/LD3320.h"
#include "./Unlocking/Unlocking.h"



Touch_Button_ASR button_2[2];
int Detection_ASR=OFF;



void ASR_Init(uint8_t LCD_Mode)
{
		
    uint8_t i;
    
    interface=5;

    ILI9341_GramScan ( LCD_Mode );


    /* 整屏清为白色 */
    LCD_SetBackColor(WHITE);
    ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);

    /* 初始化按钮 */
    Touch_Button_ASR_Init();

    /* 描绘按钮 */
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
    button_2[0].para = "开始检测";
    button_2[0].touch_flag = 0;
    button_2[0].draw_btn = Draw_ASR_Button ;
    button_2[0].btn_command = Command_Select_ASR;

    
    button_2[1].start_x = 5;
    button_2[1].start_y = 160;
    button_2[1].end_x = 235 ;
    button_2[1].end_y = 300;
    button_2[1].para = "返回";
    button_2[1].touch_flag = 0;
    button_2[1].draw_btn = Draw_ASR_Button ;
    button_2[1].btn_command = Command_Select_ASR;

}



void Touch_Button_ASR_Down(uint16_t x,uint16_t y)
{
    uint8_t i;
    for(i=0; i<2; i++)
    {


        /* 触摸到了按钮 */
        if(x<=button_2[i].end_x && y<=button_2[i].end_y && y>=button_2[i].start_y && x>=button_2[i].start_x )
        {

            if(button_2[i].touch_flag == 0)     /*原本的状态为没有按下，则更新状态*/
            {
                button_2[i].touch_flag = 1;         /* 记录按下标志 */

                button_2[i].draw_btn(&button_2[i]);  /*重绘按钮*/


            }

        }
        else if(button_2[i].touch_flag == 1) /* 触摸移出了按键的范围且之前有按下按钮 */
        {
            button_2[i].touch_flag = 0;         /* 清除按下标志，判断为误操作*/

            button_2[i].draw_btn(&button_2[i]);   /*重绘按钮*/
        }

    }

}



/**
* @brief  Command_Select_Key 按键的功能执行函数
* @param  btn Touch_Button 类型的按键参数
* @retval 无
*/
static void Command_Select_ASR(void *btn)
{

    char ch,aa;
		int ret;
		Detection_ASR=OFF;
		
	
    while(Detection_ASR)
    {
        /* 获取字符指令 */
        ch=getchar();
        if(ch=='0')
				{
					ILI9341_DispString_EN_CH(	90,158,"请说出二级口令");
					while(Detection_ASR)
					{
					aa=getchar();
					
					 switch(aa)
						{
				
							case '1':
								{ 
										ret=0;
										Unlocking_Init(ret);  //执行开锁
									break;
								}
				
							case '2':
								{
										ret=1;
										Unlocking_Init(ret);  //开锁失败
								}
        
					
						}
					
					
       
				  }  

            
      }
    }


}





/**
* @brief  Touch_Button_Up 按键被释放时调用的函数，由触摸屏调用
* @param  x 触摸最后释放时的x坐标
* @param  y 触摸最后释放时的y坐标
* @retval 无
*/
void Touch_Button_ASR_Up(uint16_t x,uint16_t y)
{

    uint8_t i;
    for(i=0; i<2; i++)
    {

        /* 触笔在按钮区域释放 */
        if((x<button_2[i].end_x && x>button_2[i].start_x && y<button_2[i].end_y && y>button_2[i].start_y))
        {
            button_2[i].touch_flag = 0;       /*释放触摸标志*/

            button_2[i].draw_btn(&button_2[i]); /*重绘按钮*/

            if(i==0)
            {
                ILI9341_Clear(0,0,240,320);
								LCD_SetColors(RED,WHITE);
								LCD_SetFont(&Font16x24);
								ILI9341_DispString_EN_CH(	90,98,"请说出一级口令");
                button_2[i].btn_command(&button_2[i]);  /*执行按键的功能命令*/

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
static void Draw_ASR_Button(void *btn)
{
    Touch_Button_ASR *ptr = (Touch_Button_ASR *)btn ;

    /*释放按键*/
    if(ptr->touch_flag == 0)
    {
        /*背景为功能键相应的颜色*/
        LCD_SetColors(RED,WHITE);
        LCD_SetFont(&Font16x24);
        ILI9341_DispString_EN_CH(	ptr->start_x+5,ptr->start_y+50,ptr->para);
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







