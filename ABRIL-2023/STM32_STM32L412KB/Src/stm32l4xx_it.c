/*
 * stm32l4xx_it.c
 *
 *  Created on: May 20, 2023
 *      Author: jeffr
 */
#include "SystemTime.h"
volatile uint32_t uwTicks = 0;
/*Systick ISR ----------------------------------------------*/
void SysTick_Handler(void){
	uwTicks += 1;
}


/*ADC ISR -------------------------------------------------*/
void ADC1_IRQHandler(void){
	//todo
}
