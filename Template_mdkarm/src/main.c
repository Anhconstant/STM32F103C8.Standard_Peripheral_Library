#include "config.h" /*Config ALL*/
int main(void)
{	
	delay_config()	;
	GPIO_config()	;
	SPI_config()	;
	
	//delay_ms(100);
	while (1) {
		
		for(int i=0;i<10;i++){
			while(!(SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_TXE)));
			SPI_I2S_SendData(SPI1,'A'+i);
		}
		
		
		//delay_ms(100);
		GPIO_SetBits(GPIOB, GPIO_Pin_2|GPIO_Pin_1);
		delay_ms(100);
		GPIO_ResetBits(GPIOB, GPIO_Pin_2|GPIO_Pin_1);
		delay_ms(100);
	}
}
