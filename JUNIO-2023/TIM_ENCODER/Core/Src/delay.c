/*
 * delay.c
 *
 *  Created on: 10 oct. 2022
 *      Author: jeffr
 */

#include <delay.h>

void delay_init(void){
	uint32_t temp;
	//1. deshabilitar
	SysTick->CTRL &=~ (SysTick_CTRL_ENABLE_Msk);
	//2. calcular el valor de RELOAD
	SystemCoreClockUpdate();						//actualiza el valor de la variable systemcoreclock
	temp = SystemCoreClock / 1000;					//se desea generar un envento de actualizacion cada 1ms
	SysTick->LOAD = temp - 1;
	//3. activar el conteo
	SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;	//system core clock
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;		//se habilita el conteo

	return;
}

void delay_ms(uint32_t delay){
	uint32_t i;

	SysTick->VAL = 0;
	//se genera el retardo
	for(i = 0; i<delay; i++){
		while(!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk)); //Genera un retardo de 1ms
	}
	return;
}
