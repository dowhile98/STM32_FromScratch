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

void SysTick_Handler(void){
    if(SysTick->CTRL & 1<<16){
        //todo
        tickInc(1);
    }
}