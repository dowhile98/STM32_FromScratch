/*
 * stm32c0xx_it.c
 *
 *  Created on: Oct 4, 2023
 *      Author: jeffr
 */
#include "stm32c0xx.h"
#include "delay.h"

/*ISR Systick ------------------------------------*/
void SysTick_Handler(void){
	if(SysTick->CTRL & 1<<16){
		TicksInc(1);
	}
}
