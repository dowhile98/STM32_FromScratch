/*
 * stm32f4xx_it.c
 *
 *  Created on: 15 mar. 2023
 *      Author: jeffr
 */


#include "stm32f4xx.h"
#include "delay.h"
#include "buttonV2.h"
/**
 * @brief ISR -> SYSTICK
 */
void SysTick_Handler(void){
	TickInc_Callback();
}

extern Button_Time_t button;

void TIM6_DAC_IRQHandler(void){
	//SE GENERANDO
	TIM6->SR &=~ (TIM_SR_UIF);			//limpia la bandera
	//se ejecuta la fun
	//Button_Update(&BUTTON);
	Button_Update(&button);
}
