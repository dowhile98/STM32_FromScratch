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

/**
 * @brief ISR -> USART1
 */
void USART1_IRQHandler (void){
//	volatile uint8_t temp;
	//TX

	//RX
	if(USART1->SR & USART_SR_RXNE){		//interrupcion por RXNE
//		temp = USART1->DR;
//		while(!(USART1->SR & USART_SR_TXE));
//		USART1->DR = temp;
	}
	//PE

	//OV
}
