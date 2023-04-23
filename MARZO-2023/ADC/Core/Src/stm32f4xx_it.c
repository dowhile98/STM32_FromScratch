/*
 * stm32f4xx_it.c
 *
 *  Created on: 15 mar. 2023
 *      Author: jeffr
 */


#include "stm32f4xx.h"
#include "delay.h"


extern void ADC1_CpltConvCallback(uint16_t data);
/**
 * @brief ISR -> SYSTICK
 */
void SysTick_Handler(void){
	TickInc_Callback();
}

void ADC_IRQHandler(void){
	if(ADC1->SR & ADC_SR_EOC){		//TERMINA LA CONVERSION
		ADC1_CpltConvCallback(ADC1->DR);
	}else if(ADC1->SR & ADC_SR_OVR){//SOBREESCRITURA DEL DATO CONVERTIDO
		ADC1->SR &=~ ADC_SR_OVR;
		//TODO

	}
}
