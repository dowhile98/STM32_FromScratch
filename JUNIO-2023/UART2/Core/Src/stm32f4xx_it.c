/*
 * stm32f4xx_it.c
 *
 *  Created on: 16 jun. 2023
 *      Author: jeffr
 */
#include "stm32f4xx.h"
#include "SysTick.h"
#include "lwrb.h"

extern lwrb_t rxBuff;

void SysTick_Handler(void){
	TicksInc(1);
	//todo

}
void USART2_IRQHandler(void){
	uint8_t ch;
	if(USART2->SR & USART_SR_RXNE){
		//LEER EL DATO RECIBIDO
		ch = USART2->DR;
		lwrb_write(&rxBuff, &ch, 1);
	}
}
