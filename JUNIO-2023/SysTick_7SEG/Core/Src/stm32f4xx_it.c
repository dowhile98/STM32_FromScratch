/*
 * stm32f4xx_it.c
 *
 *  Created on: 16 jun. 2023
 *      Author: jeffr
 */
#include "stm32f4xx.h"
#include "SysTick.h"
#include "display.h"

extern Display_t disp;
void SysTick_Handler(void){
	TicksInc(1);
	//todo
	display_update(&disp);
}

