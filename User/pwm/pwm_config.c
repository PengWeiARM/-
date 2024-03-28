/*--------------------------------------------------------------------
*配置通用定时器2、pwm输出端口通道
---------------------------------------------------------------------*/

#include "stm32f10x.h"
#include "./pwm/pwm_config.h"

/*-------------端口配置----------------*/
void gpio_config()
{
  GPIO_InitTypeDef GPIO_InitStructure;//定义结构体
	
  RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB,ENABLE);//开a组时钟
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_AFIO,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
  GPIO_Init(GPIOB,&GPIO_InitStructure);//初始化
}

/*-------------定时器3时基与通道配置----------------*/
void timebase_config()
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;//定义时基结构体
	TIM_OCInitTypeDef       TIM_OCInitStructure;//定义时基结构体
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);//开定时器3时钟
	
	TIM_TimeBaseInitStructure.TIM_Period=199;//20ms
	TIM_TimeBaseInitStructure.TIM_Prescaler=7199;
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseInitStructure);//初始化
	
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity= TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OC1Init(TIM4,&TIM_OCInitStructure);//初始化定时器2通道1
	
	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);//ccr预装使能
	TIM_ARRPreloadConfig(TIM4, ENABLE);//arr重载寄存器使能
	TIM_Cmd(TIM4,ENABLE);//使能定时器3
}

void pwm_config(void)
{
	gpio_config();
	timebase_config();
}
