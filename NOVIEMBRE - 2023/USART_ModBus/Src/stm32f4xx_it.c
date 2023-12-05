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
#include "main.h"
#include <stdlib.h>
#include <string.h>
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
 * 1mer
 * data.len += 1;
 * data.rx[count++] = byte1;
 *
 * 2do
 * data.len += 1;
 * data.rx[count++] = byte2;
 *
 * 3ro
 * data.len += 1;
 * data.rx[count] = byte3;
 *
 * count = 0;
 *
 * data.rx[0] ->primero
 * data.rx[2] ->ultimo
 */
