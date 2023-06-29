/*
 * HD44780_Driver.c
 *
 *  Created on: 16 jun. 2023
 *      Author: jeffr
 */


/*Includes --------------------------------------------------*/
#include "SysTick.h"
#include "stm32f4xx.h"
#include "defines.h"
/*Macro defines --------------------------------------------*/
/* 4 bit mode */
/* Control pins, can be overwritten */
/* RS - Register select pin */
#define LCD_RS					A , 1
/* E - Enable pin */
#define LCD_E					A , 2
/* Data pins */
/* D4 - Data 4 pin */
#define LCD_D4					A , 3
/* D5 - Data 5 pin */
#define LCD_D5					A , 4
/* D6 - Data 6 pin */
#define LCD_D6					A , 5
/* D7 - Data 7 pin */
#define LCD_D7					A , 6


/*Defincion de funciones ------------------------------------*/

void LCD_Delay(uint32_t delayms){
	delay_ms(delayms);
	//HAL_Delay
	//__delay_ms
}

void LCD_nibble_write(uint8_t data, uint8_t control){
	uint32_t delay = 1;
	GPIOX_ODR(LCD_D7) = (data>>3) & 0x1;
	GPIOX_ODR(LCD_D6) = (data>>2) & 0x1;
	GPIOX_ODR(LCD_D5) = (data>>1) & 0x1;
	GPIOX_ODR(LCD_D4) = (data) & 0x1;
//	//PA1
//	GPIOA->BSRR |= ((data>>3) & 0x1) ? (1<<1) : (1<<(16 + 1));
//	//PA7
//	GPIOA->BSRR |= ((data>>2) & 0x1) ? (1<<7) : (1<<(16 + 7));

	GPIOX_ODR(LCD_E) = 0;

	if(control){
		GPIOX_ODR(LCD_RS) = 1;
	}else{
		GPIOX_ODR(LCD_RS) = 0;
	}

	GPIOX_ODR(LCD_E) = 1;
	while(delay-- >0);
	GPIOX_ODR(LCD_E) = 0;

	return;
}


