#include "config.h" /*Config ALL*/
int main(void)
{	
	SPI_config();
	GPIO_config()	;
	uint16_t data[3] = {'A','B','C'};
	while (1) {
		
		SPI_send_byte(SPI1,data,3);
		GPIO_SetBits(GPIOB, GPIO_Pin_2|GPIO_Pin_1);
		delaynop();
		GPIO_ResetBits(GPIOB, GPIO_Pin_2|GPIO_Pin_1);
		delaynop();
	}
}
