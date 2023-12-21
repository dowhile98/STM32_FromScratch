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
 * LED1 -> PD12
 * LED2 -> PD15
 *
 * SW -> PA0
 *
 * NUCLEO 64
 * LED  -> PA5
 * SW   -> PC13
 * COM -> USART2
 */

/*Includes --------------------------------------*/
#include <stdint.h>
#include "stm32f4xx.h"
#include <stdio.h>



/*defines ---------------------------------------*/
/**
 * ##
 */
#define LED			D, 12
#define SW			A, 0

#define GPIOX_MODER_(a, b, c)	{GPIO ## a ->MODER &=~ (0x3<<(2 * b)) ; \
								GPIO ## a ->MODER |= c <<( 2 * b); }
#define GPIOX_MODER(a, b)		GPIOX_MODER_(a, b)

#define INPUT_READ_(a, b)		(GPIO ## a -> IDR & 1<<b) ? 1 : 0
#define INPUT_READ(a)			INPUT_READ_(a)

#define OUTPUT_SET_(a, b)		GPIO ## a -> ODR |= 1<<b
#define OUTPUT_SET(a)			OUTPUT_SET_(a)

#define OUTPUT_RESET_(a, b)		GPIO ## a -> ODR &=~( 1<<b)
#define OUTPUT_RESET(a)			OUTPUT_RESET_(a)

/*Function prototype ----------------------------*/
void delay_ms(uint32_t delay);

uint8_t flag = 0;
/*Main ------------------------------------------*/
int main(void)
{
	uint32_t temp;
	/*habilitar el reloj*/
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;  //1<<3
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	/**
	 * PD12 -> salida
	 *
	 */
	GPIOD->MODER &=~(GPIO_MODER_MODE12); 	//Clear
	GPIOD->MODER |= GPIO_MODER_MODE12_0;	//Modo salida de proposito general
	GPIOD->OTYPER &=~ GPIO_OTYPER_OT12;		//PUSH PULL
	GPIOD->OSPEEDR &=~ GPIO_OSPEEDER_OSPEEDR12;
	/**
	 * PA0 -> entrada
	 */
	GPIOA->MODER &=~(GPIO_MODER_MODE0); //RESET STATE (INPUT FLOATING)
	GPIOA->PUPDR &=~ (GPIO_PUPDR_PUPD0); //no pull up /down

	/**
	 * @brief systick
	 * 
	 */
	SysTick->CTRL = 0;
	SysTick->VAL = 0;
	temp = SystemCoreClock / 1E+3;
	SysTick->LOAD = temp - 1;
	SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;
	for(;;){
		GPIOD->ODR ^= GPIO_ODR_OD12;
		flag = (GPIOD->IDR)>>12 &  0x1;
		delay_ms(2000);
	}
}


/*Function definition -----------------------------------------*/
int __io_putchar(int ch){
	ITM_SendChar(ch);
	return ch;
}
void delay_ms(uint32_t delay){
	uint32_t i;
	SysTick->VAL = 0;
	for(i = 0; i<delay; i++){
		while(!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk)); //se bloque durante 1ms
	}
	return;
}