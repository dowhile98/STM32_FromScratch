/*
 * stm32f4xx_it.c
 *
 *  Created on: 15 mar. 2023
 *      Author: jeffr
 */


#include "stm32f4xx.h"
#include "delay.h"
#include "AT_Command_Parse.h"

extern AT_CMD_Parse_t tinyfox;
/**
 * @brief ISR -> SYSTICK
 */
void SysTick_Handler(void){
	TickInc_Callback();
	AT_Device_TickInc(&tinyfox);
}

/**
 * @brief ISR -> USART1
 */
void USART1_IRQHandler (void){
	volatile uint8_t temp;
	//TX

	//RX
	if(USART1->SR & USART_SR_RXNE){		//interrupcion por RXNE
		temp = USART1->DR;
//		while(!(USART1->SR & USART_SR_TXE));
//		USART1->DR = temp;
		lwrb_write(&tinyfox.buff, &temp, 1);
	}
	//PE

	//OV
}
