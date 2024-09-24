#ifndef __CONFIG_C__
#define __CONFIG_C__
#include "config.h"
void delaynop(void){
	for(int i = 0 ; i < 0xfffff ;i++ ) __NOP() 	;
}
void GPIO_config(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE)	;	
	
	GPIO_InitTypeDef gpioInit;
	
	gpioInit.GPIO_Mode = GPIO_Mode_Out_PP	;
	gpioInit.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_1	;
	gpioInit.GPIO_Speed = GPIO_Speed_50MHz	;
	GPIO_Init(GPIOB, &gpioInit)	;
}
void USART_config(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE)	;
	
	GPIO_InitTypeDef gpioInit	;
	/*	A9	is UART1 TX	*/
	gpioInit.GPIO_Pin = GPIO_Pin_9 ;
	gpioInit.GPIO_Mode = GPIO_Mode_AF_PP;
	gpioInit.GPIO_Speed = GPIO_Speed_50MHz   ;
	GPIO_Init(GPIOA,&gpioInit);
	/*	A10	is UART1 RX	*/
	gpioInit.GPIO_Pin = GPIO_Pin_10 ;
	gpioInit.GPIO_Mode = GPIO_Mode_IPU;
	gpioInit.GPIO_Speed = GPIO_Speed_50MHz   ;
	GPIO_Init(GPIOA,&gpioInit);
	
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	USART_InitTypeDef uartInit	;
	
	uartInit.USART_BaudRate = 9600	;
	uartInit.USART_HardwareFlowControl = USART_HardwareFlowControl_None	;
	uartInit.USART_Mode = USART_Mode_Rx | USART_Mode_Tx ;
	uartInit.USART_Parity = USART_Parity_No;
	uartInit.USART_StopBits = USART_StopBits_1 ;
	uartInit.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART1,&uartInit);
	
	USART_Cmd(USART1,ENABLE);

}
void MCO_config(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE)	;
	GPIO_InitTypeDef gpioInit	;
	/*	A8	is	MCO	*/
	gpioInit.GPIO_Pin = GPIO_Pin_8 ;
	gpioInit.GPIO_Mode = GPIO_Mode_AF_PP;
	gpioInit.GPIO_Speed = GPIO_Speed_50MHz   ;
	GPIO_Init(GPIOA,&gpioInit);
	RCC_MCOConfig(RCC_MCO_PLLCLK_Div2);
}
void SPI_config(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE)	;
	GPIO_InitTypeDef gpioInit	;
	/*	A4	is	SPI	NSS		*/
	gpioInit.GPIO_Pin = GPIO_Pin_4	;
	gpioInit.GPIO_Mode = GPIO_Mode_AF_PP	;
	gpioInit.GPIO_Speed = GPIO_Speed_50MHz	;
	GPIO_Init(GPIOA,&gpioInit);
	/*	A5	is	SPI	SCK		*/
	gpioInit.GPIO_Pin = GPIO_Pin_5	;
	gpioInit.GPIO_Mode = GPIO_Mode_AF_PP	;
	gpioInit.GPIO_Speed = GPIO_Speed_50MHz	;
	GPIO_Init(GPIOA,&gpioInit);
	/*	A6	is	SPI	MISO	*/
	gpioInit.GPIO_Pin = GPIO_Pin_6	;
	gpioInit.GPIO_Mode = GPIO_Mode_IPU	;
	gpioInit.GPIO_Speed = GPIO_Speed_50MHz	;
	GPIO_Init(GPIOA,&gpioInit);
	/*	A7	is	SPI	MOSI	*/
	gpioInit.GPIO_Pin = GPIO_Pin_7	;
	gpioInit.GPIO_Mode = GPIO_Mode_AF_PP	;
	gpioInit.GPIO_Speed = GPIO_Speed_50MHz	;
	GPIO_Init(GPIOA,&gpioInit);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1,ENABLE);
	SPI_InitTypeDef spiInit;
	spiInit.SPI_BaudRatePrescaler	=	SPI_BaudRatePrescaler_128;
	spiInit.SPI_CPHA = SPI_CPHA_1Edge	;
	spiInit.SPI_CPOL = SPI_CPOL_High	;
	spiInit.SPI_DataSize = SPI_DataSize_8b	;
	spiInit.SPI_Direction = SPI_Direction_2Lines_FullDuplex	;
	spiInit.SPI_FirstBit = SPI_FirstBit_MSB	;
	spiInit.SPI_Mode = SPI_Mode_Master	;
	spiInit.SPI_NSS = SPI_NSS_Soft	;
	SPI_Init(SPI1,&spiInit);
	SPI_SSOutputCmd(SPI1,ENABLE);
	SPI_Cmd(SPI1,ENABLE);
	
	
}


#endif
