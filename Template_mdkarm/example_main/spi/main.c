#include "config.h" /*Config ALL*/
int main(void)
{	
	SPI_config();
	GPIO_config()	;
	while (1) {
		SPI_I2S_SendData(SPI1,'A');
		GPIO_SetBits(GPIOB, GPIO_Pin_2|GPIO_Pin_1);
		delaynop();
		GPIO_ResetBits(GPIOB, GPIO_Pin_2|GPIO_Pin_1);
		delaynop();
	}
}
