/*
 * stm32f4xx_it.c
 *
 *  Created on: 15 mar. 2023
 *      Author: jeffr
 */


#include "stm32f4xx.h"
#include "delay.h"


extern void ADC1_CpltConvCallback(void);
/**
 * @brief ISR -> SYSTICK
 */
void SysTick_Handler(void){
	TickInc_Callback();
}

void DMA2_Stream4_IRQHandler (void){
	if(DMA2->HISR & DMA_HISR_TCIF4){
		DMA2->HIFCR |= DMA_HIFCR_CTCIF4;	//Clear
		ADC1_CpltConvCallback();
	}

}
