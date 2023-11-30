/**
 * @file stm32_f4xx_it.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "stm32f4xx.h"
#include "delay.h"
#include <stdio.h>

/**
 *
 */
void SysTick_Handler(void){
    if(SysTick->CTRL & 1<<16){
        //todo
        tickInc(1);
    }
}
/**
 *
 */
void EXTI0_IRQHandler(void){
	if(EXTI->PR & EXTI_PR_PR0){
		EXTI->PR |= EXTI_PR_PR0;
		//Todo añadir codigo que se ejecute cuando ocurre la interrupcion
		printf("rising edge detect\r\n");

	}
	return;
}
