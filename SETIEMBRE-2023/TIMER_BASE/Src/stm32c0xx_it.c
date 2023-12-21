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

/*ISR Timer 14 ----------------------------------*/
void TIM14_IRQHandler(void){
	//verificar
	if(TIM14->SR & TIM_SR_UIF){
		TIM14->SR &=~ TIM_SR_UIF;   //clear
		//TODO
		GPIOA->ODR ^= 1<<5;

	}

	return;
}