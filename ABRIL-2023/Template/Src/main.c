/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/**
 * @brief
 */
#include <stdint.h>
#include <stm32f4xx.h>


void SysTick_Init(uint32_t ticks);

void delay_ms(uint32_t delay);
int main(void)
{
	uint32_t ticks;
	//PA15
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	GPIOD->MODER &=~ GPIO_MODER_MODE15;
	GPIOD->MODER |= GPIO_MODER_MODE15_0;
	/**
	 * ticks = systemcoreClock / freq;
	 */
	ticks = SystemCoreClock / 1000;
	SysTick_Init(ticks);
    /* Loop forever */
	for(;;){
		GPIOD->ODR ^= 1U<<15;
		delay_ms(100);
	}
}

void SysTick_Init(uint32_t ticks){
	/*1. Deshabilitar*/
	SysTick->CTRL = 0;
	/*Calular el  valor del registro reload*/
	/**
	 * updateEvent = SystickClk / freq - 1
	 * LOAD = udapteEvent
	 */
	SysTick->LOAD = ticks - 1;
	/*current val = 0*/
	SysTick->VAL = 0;
	/*configurar el registro de control*/
	//fuente de reloj
	SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;	//SYSCLK (AHB)
	//interrupcion

	//habilitacion del contador

	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;		//enable

	return;
}

void delay_ms(uint32_t delay){
	SysTick->VAL = 0;
	uint32_t i;
	for(i = 0; i< delay; i++){
		while(!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk)); //1ms
	}
	return;
}
