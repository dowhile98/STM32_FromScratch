/*
 * SystemTime.h
 *
 *  Created on: May 20, 2023
 *      Author: jeffr
 */

#ifndef SYSTEMTIME_H_
#define SYSTEMTIME_H_


/*Includes -------------------------------------------------*/
#include "stm32l412xx.h"

/*Global variables -----------------------------------------*/
extern volatile uint32_t uwTicks;

/*Function -------------------------------------------------*/


__STATIC_INLINE void System_Tick_Init(uint32_t ticks){
	SysTick_Config(ticks);
	return;
}

__STATIC_INLINE uint32_t System_getTicks(void){
	return (uint32_t) uwTicks;
}

__STATIC_INLINE void System_IncTick(void){
	uwTicks += 1;
}

__STATIC_INLINE void delay_ms(uint32_t delay){
	uint32_t star = System_getTicks();
	uint32_t wait = delay;

	while((System_getTicks() - star)<= wait);

	return;
}
#endif /* SYSTEMTIME_H_ */
