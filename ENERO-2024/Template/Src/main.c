/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/*Includes ----------------------------------------------------------*/
#include <stdint.h>
#include "stm32f4xx.h"
#include <stdio.h>
/*Defines -----------------------------------------------------------*/
/**
 * valatile
 * extern
 * auto
 * static
 */
#define RCC_BASE_ADDR	0x40023800UL
//#define RCC_AHB1ENR_OFF	0x30
//
//#define AHB1ENR *(volatile uint32_t*)(RCC_BASE_ADDR + RCC_AHB1ENR_OFF)
//typedef struct{
//	uint8_t i;
//	uint8_t y;
//}prueba;

#define TEST_RCC   ((RCC_TypeDef *) RCC_BASE_ADDR)
/*Global variables --------------------------------------------------*/

/*Function prototype ------------------------------------------------*/
int main(void)
{
	/*Init ..........................................................*/
	printf("stm32 - cortex M4\r\n");
	printf("Quino B. Jeffry\r\n");
	printf("%s  %s\r\n", __TIME__, __DATE__);
	/*---------------------------------------------------------------*/
	//volatile uint32_t *AHB1ENR = (volatile uint32_t*)(RCC_BASE_ADDR + RCC_AHB1ENR_OFF);

	//*AHB1ENR |= 1<<3 | 1;

	//AHB1ENR |= 1<<3 | 1;
    /* Loop forever */
//	prueba t1;
//	prueba *t2 = &t1;

	/**
	 * * -> indireccion (acceder a la memoria o al contenido de la memoria apuntada)
	 * & -> direccion (obtener la direccion de memoria)
	 * ->   operador puntero
	 */
//	t2->i = 1;
//	t1.i = 2;

	TEST_RCC->AHB1ENR |= 1<<3 | 1;
	printf("0x%X\r\n", (unsigned int)RCC->AHB1ENR);

	for(;;){

	}
}

/*Function definition -----------------------------------------------*/
int __io_putchar(int ch){
	ITM_SendChar(ch);
	//uart
	return ch;
}