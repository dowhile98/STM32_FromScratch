/*
 * stm32f4xx_it.c
 *
 *  Created on: 15 mar. 2023
 *      Author: jeffr
 */


#include "stm32f4xx.h"
#include "delay.h"

/**
 * @brief ISR -> SYSTICK
 */
void SysTick_Handler(void){
	TickInc_Callback();
}
