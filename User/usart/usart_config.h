#ifndef __USART_CONFIG_H
#define	__USART_CONFIG_H

#define TEST_USART								USART1
#define TEST_USART_CLS						RCC_APB2Periph_USART1
#define TEST_USART_BAUD						115200

#define TEST_USART_TXD_PIN				GPIO_Pin_9
#define TEST_USART_TXD_GPIO_PORT	GPIOA
#define TEST_USART_TXD_CLK				RCC_APB2Periph_GPIOA

#define TEST_USART_RXD_PIN				GPIO_Pin_10
#define TEST_USART_RXD_GPIO_PORT  GPIOA
#define TEST_USART_RXD_CLK				RCC_APB2Periph_GPIOA

#define USART_IRQ									USART1_IRQn

#endif /* __USART_CONFIG_H */
