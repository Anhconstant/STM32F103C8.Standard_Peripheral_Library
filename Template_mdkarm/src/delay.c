#ifndef __DELAY_C__
#define __DELAY_C__
#include "delay.h"


void delay_config(void){
	TIM_TimeBaseInitTypeDef tim;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
	tim.TIM_CounterMode = TIM_CounterMode_Up;
	tim.TIM_Period	= 0xffff;
	tim.TIM_Prescaler = 72-1 ;
	TIM_TimeBaseInit(TIM4,&tim);
	TIM_Cmd(TIM4,ENABLE);
}

void delay1ms(void){
	TIM_SetCounter(TIM4,0);
	while(TIM_GetCounter(TIM4)<1000);
}
void delay_ms(uint32_t u32ms){
	while(--u32ms){
		delay1ms();
	}
}
void delay_us(uint16_t u16ms){
	TIM_SetCounter(TIM4,0);
	while(TIM_GetCounter(TIM4)<u16ms);
}

#endif
