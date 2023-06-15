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
/*Includes ----------------------------------------------------*/
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "stm32f4xx.h"
#include "core_cm4.h"
/*Typedef -----------------------------------------------------*/

/*Defines -----------------------------------------------------*/

/*Global variables --------------------------------------------*/

/*Function prototype ------------------------------------------*/
int __io_putchar(int ch){
	//salida
	ITM_SendChar(ch);

	return ch;
}
/*main function -----------------------------------------------*/
int main(void)
{
	printf("HOLA MUNDO\r\n");

    /* Loop forever */
	for(;;);
}
/*Function definition -----------------------------------------*/


