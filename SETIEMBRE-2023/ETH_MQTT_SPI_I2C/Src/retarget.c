/*
 * retarget.c
 *
 *  Created on: Oct 25, 2023
 *      Author: jeffr
 */

#include "stm32f4xx.h"
int __io_putchar(int ch){
	ITM_SendChar(ch);
	return ch;
}
