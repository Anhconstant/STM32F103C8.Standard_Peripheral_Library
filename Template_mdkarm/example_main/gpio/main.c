#include "config.h" /*Config ALL*/
int main(void)
{	
	GPIO_config()	;
	while (1) {

		GPIO_SetBits(GPIOB, GPIO_Pin_2|GPIO_Pin_1);
		delaynop();
		GPIO_ResetBits(GPIOB, GPIO_Pin_2|GPIO_Pin_1);
		delaynop();
	}
}
