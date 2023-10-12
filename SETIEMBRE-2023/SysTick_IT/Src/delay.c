/*
 * delay.c
 *
 *  Created on: Oct 4, 2023
 *      Author: jeffr
 */


#include "delay.h"
/*Global variables ------------------------------------*/
volatile uint32_t uwTicks = 0;
/*Function definition ---------------------------------*/
void delay_init(uint32_t ticks){
	SysTick_Config(ticks);
	NVIC_SetPriority(SysTick_IRQn, 15);
	return;
}

void TicksInc(uint32_t i){
	uwTicks += i;
	return;
}

void delay_ms(uint32_t delay){
	uint32_t tickStart = GetTicks();
	while((GetTicks() - tickStart)<= delay);
	return;
}

uint32_t GetTicks(void){
	return uwTicks;
}