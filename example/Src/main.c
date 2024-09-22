#include "stm32_main.h"
void delaynop(void);
void delaynop(void){
	for(int i = 0 ; i < 0xfffff ;i++ ) __NOP() 	;
}
int main(void)
{
	
	GPIO_InitTypeDef gpioInit;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	gpioInit.GPIO_Mode = GPIO_Mode_Out_PP	;
	gpioInit.GPIO_Pin = GPIO_Pin_2	;
	gpioInit.GPIO_Speed = GPIO_Speed_50MHz	;
	GPIO_Init(GPIOB, &gpioInit)	;

	while (1) {
		GPIO_SetBits(GPIOB, GPIO_Pin_2);
		delaynop();
		GPIO_ResetBits(GPIOB, GPIO_Pin_2);
		delaynop();
	}
	
}
