#ifndef __DELAY_H__
#define __DELAY_H__
#include "stdint.h"
#include "stm32f10x_tim.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x.h"
void delay1ms(void);
void delay_ms(uint32_t u32ms);
void delay_us(uint16_t u16ms);
void delay_config(void);
#endif
