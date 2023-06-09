/*
 * display_ll_driver.c
 *
 *  Created on: 19 jun. 2023
 *      Author: jeffr
 */

#include "display.h"
#include "stm32f4xx.h"


void display_custom(Display_t *obj, uint8_t val){
	//todo

}

void display_write(uint8_t data, uint8_t digit, uint8_t dp){
	//todo
	//G-F-E-D-C-B-A ->data 0b0GFEDCBA ->0b0011000
	GPIOB->BSRR |= (data & 1) ? 1<<0 : 1<<(16 + 0);
	GPIOB->BSRR |= (data & 1<<1) ? 1<<1 : 1<<(16 + 1);
	GPIOB->BSRR |= (data & 1<<2) ? 1<<2 : 1<<(16 + 2);
	GPIOB->BSRR |= (data & 1<<3) ? 1<<3 : 1<<(16 + 3);
	GPIOB->BSRR |= (data & 1<<4) ? 1<<4 : 1<<(16 + 4);
	GPIOB->BSRR |= (data & 1<<5) ? 1<<5 : 1<<(16 + 5);
	GPIOB->BSRR |= (data & 1<<6) ? 1<<6 : 1<<(16 + 6);
	//Digito
	if(digit == DIGIT1){
		GPIOB->BSRR |= 1<<8;
		GPIOB->BSRR |= 1<<(16 + 9);
	}else if(digit == DIGIT2){
		GPIOB->BSRR |= 1<<9;
		GPIOB->BSRR |= 1<<(16 + 8);
	}
	//dp
	if(dp == DP_ON){
		GPIOB->BSRR |= 1<<7;
	}else{
		GPIOB->BSRR |= 1<<(16 + 7);
	}
}

