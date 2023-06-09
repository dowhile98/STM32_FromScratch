/*
 * SysTick.c
 *
 *  Created on: 16 jun. 2023
 *      Author: jeffr
 */

/*Includes ------------------------------------------------------*/
#include "SysTick.h"

volatile uint32_t uwTicks = 0;


void SysTick_Init(uint32_t ticks){
	SysTick->CTRL = 0;

	SysTick->LOAD = ticks - 1;

	SysTick->VAL = 0;

	SysTick->CTRL = SysTick_CTRL_ENABLE_Msk | SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_CLKSOURCE_Msk;

	return;
}

void delay_ms(uint32_t delay){
//	SysTick->VAL = 0;
//
//	for(uint32_t i = 0; i <delay; i++){
//		while((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) == 0); //1ms
//	}
	uint32_t tickStart = GetTicks();
	uint32_t wait = delay;

	while((GetTicks() - tickStart) < wait);
	return;
}

uint32_t GetTicks(void){
	return (uint32_t)uwTicks;
}

void TicksInc(uint32_t inc){
	uwTicks += inc;
}
