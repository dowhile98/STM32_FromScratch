/*
 * stm32f4xx_it.c
 *
 *  Created on: 30 ene. 2023
 *      Author: jeffr
 */


#include "stm32f4xx.h"
#include "main.h"


extern void GPIO_IRQHandler(uint32_t pin);
extern volatile uint32_t uwTick;

__WEAK void GPIO_EXTI_Callback(uint32_t pin){

}

/**
 * @brief rutina de servicio de IT de la Systick
 */

void SysTick_Handler(void){

	if(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk){
		//todo
		uwTick++;
	}
}


void EXTI0_IRQHandler(void){

	GPIO_IRQHandler(0);

}
