/*
 * delay.c
 *
 *  Created on: 30 ene. 2023
 *      Author: jeffr
 */


#include "delay.h"
/*Global variables -------------------------------------------*/

volatile uint32_t uwTick = 0;

/*Private function -------------------------------------------*/

/*Function definition ----------------------------------------*/
/**
 * @brief
 */
void SysTick_Init(void){
	uint32_t temp;
	//1. deshabilitar
	SysTick->CTRL = 0;
	//2. calcular el valor del registro LOAD
	temp = SystemCoreClock / 1000;
	SysTick->LOAD = temp - 1;
	SysTick->VAL = 0;
	//3. configurar el registro ctrl
	SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk; 	//clock sourse AHB
	SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;		//habilita la interrupcion de la systick
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;		//habilita el conteo
	return;
}


uint32_t GetTick(void){
	return (uint32_t)uwTick;
}

/**
 * @brief genera retardos
 *
 * @param delay : cantidad de retardo en ms deseado
 */
void delay_ms(uint32_t delay){
    uint32_t tickstart = GetTick();
	uint32_t wait = delay;
	//generacion del retardo
	while((GetTick() - tickstart)<wait);

	return;
}
