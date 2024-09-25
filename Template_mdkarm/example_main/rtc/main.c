#include "config.h" /*Config ALL*/
#include "stm32f10x_pwr.h"
#include "stm32f10x_rtc.h"
#include "stm32f10x_bkp.h"
void RTC_config(void){
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);
	PWR_BackupAccessCmd(ENABLE);
	BKP_DeInit();
	RCC_LSEConfig(RCC_LSE_ON);
	while (RCC_GetFlagStatus(RCC_FLAG_LSERDY) == RESET){}
	RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);
	RCC_RTCCLKCmd(ENABLE);
	RTC_WaitForSynchro();
	RTC_WaitForLastTask();
	RTC_ITConfig(RTC_IT_SEC, ENABLE);
	RTC_WaitForLastTask();
	//int a = 1;	// a= 1,2,4,8,.... =>  RTC cnt = 1s,0.5s,0.125s....
	RTC_SetPrescaler(31767 ); /* RTC period = RTCCLK/RTC_PR = (32.768 KHz)/(32767+1) */ // 
	RTC_WaitForLastTask();
}
int main(void)
{	
	GPIO_config()	;
	RTC_config()	;
	while (1) {
		if((RTC_GetCounter() % 2) == 0 ) GPIO_ResetBits(GPIOB, GPIO_Pin_1);	
		else GPIO_SetBits(GPIOB, GPIO_Pin_1);
	}
}

