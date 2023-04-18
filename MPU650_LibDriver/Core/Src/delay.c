/*
 * delay.c
 *
 *  Created on: 15 mar. 2023
 *      Author: jeffr
 */


#include "delay.h"

/*Global variables -------------------------------------------------*/
volatile uint32_t uwTick = 0;


void SysTickInit(void){
	uint32_t temp;
	SystemCoreClockUpdate();
	//1. deshabilitar el conteo de la systick
	SysTick->CTRL &=~ SysTick_CTRL_ENABLE_Msk;
	//2. configurar el valor del registro reload
	SystemCoreClockUpdate();
	temp = SystemCoreClock / 1000 - 1;
	SysTick->LOAD = temp;
	//3. Configuras el registro de control y habilitas el conteo
	SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk; 			//system core clock

	//configurar la IT
	SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;				//habilita la IT
	NVIC_SetPriority(SysTick_IRQn, 15);

	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;				//habilita el conteo

	return;
}


/**
 * @brief funcion para generar retardos en ms
 */
void delay_ms(uint32_t delay){
	uint32_t tickstart = GetTicks();
	uint32_t wait = delay;
	//generacion del retardo
	while((GetTicks() - tickstart)<wait);
	return;
}
/**
 * @brief retorna el ticks generado por la SysTick
 * @return uint32_t
 */
uint32_t GetTicks(void){
	return (uint32_t)uwTick;
}


void TickInc_Callback(void){
	uwTick += 1;
	return;
}
