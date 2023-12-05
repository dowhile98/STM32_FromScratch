/**
 * @file stm32_f4xx_it.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "stm32f4xx.h"
#include "delay.h"
#include <stdio.h>
#include "main.h"
#include <stdlib.h>
#include <string.h>
/**
 *
 */



void SysTick_Handler(void){
    if(SysTick->CTRL & 1<<16){
        //todo

    }
}
void TIM6_DAC_IRQHandler(void){
	if(TIM6->SR & TIM_SR_UIF){
		TIM6->SR &=~TIM_SR_UIF;
		//Todo
		tickInc(1);
	}
}

void TIM2_IRQHandler(void){
	static uint32_t ccr2;
	if(TIM2->SR & TIM_SR_CC2IF){
		TIM2->SR &=~ TIM_SR_CC2IF;
		//Todo
		ccr2 = TIM2->CCR2 + 16000;
		TIM2->CCR2 = ccr2;
	}
}
/**
 * 1mer
 * data.len += 1;
 * data.rx[count++] = byte1;
 *
 * 2do
 * data.len += 1;
 * data.rx[count++] = byte2;
 *
 * 3ro
 * data.len += 1;
 * data.rx[count] = byte3;
 *
 * count = 0;
 *
 * data.rx[0] ->primero
 * data.rx[2] ->ultimo
 */
void USART1_IRQHandler(void){
	static uint8_t state = 0;
	static uint8_t count = 0;
	if(USART1->SR & USART_SR_RXNE){
		uint8_t byte = USART1->DR;
//		<CL><CR>dato<CL><CR>
//		\r\n..dato..\r\n
//      start...dato1, dato2, dato3, dato5, daton..end
		//entero -> atoi
		//float -> atof
		//sscanf
		//strcmp
		switch(state){
		case 0:
			data.rx[count] = byte;
			count += 1;
			data.len = count;
			if(byte == '\r'){
				state = 1;
			}
			break;
		case 1:
			if((byte == '\n') && (data.rx[count - 1] == '\r')){
				data.rx[count] = byte;

				//memcpy
				count += 1;
				data.len = count;
				rxFlag = true;
			}else{
				memset(data.rx, 0, sizeof(RxData_t));
				data.len = 0;
			}
			count = 0;
			state = 0;
			break;
		}
	}
}
