/**
 * @file delay.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "delay.h"

volatile uint32_t ticks = 0;

void tickInc(uint32_t i){
    ticks += i;
}
void delay_ms(uint32_t delay){
    uint32_t tickStart = getTicks();
    while ((getTicks() - tickStart) <= delay);
    
    return;
}

uint32_t getTicks(){
    return (uint32_t)ticks;
}       