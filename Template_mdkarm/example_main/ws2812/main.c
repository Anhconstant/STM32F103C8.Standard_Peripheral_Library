#include "config.h" /*Config ALL*/
int main(void)
{	
	ws2812_data data;
	ws2812_InitStruct ws2812init	;
	ws2812init.TIM = TIM4;
	ws2812init.IO_PORT = GPIOA	;
	ws2812init.IO_PIN = 1<<2;
	ws2812_Init(&ws2812init);
	data.size	= 1	;
	data.data[1]	= 0xFFFFFF	;
	ws2812init.IO_PORT = GPIOA	;
	ws2812init.IO_PIN = 1<<2;
	GPIO_config()	;
	while (1) {
		ws2812_Write(&ws2812init,&data);
		delay_ms(1000);
		GPIO_SetBits(GPIOB,GPIO_Pin_2);
		//delaynop();
		delay_ms(1000);
		GPIO_ResetBits(GPIOB,GPIO_Pin_2);
		//delaynop();
		delay_ms(1000);
	}
}