/**
 * @file delay.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef __DELAY_H
#define __DELAY_H

#include "stm32f4xx.h"
/**
 * @brief 
 * 
 * @param i 
 */
void tickInc(uint32_t i);
/**
 * @brief 
 * 
 * @param delay 
 */
void delay_ms(uint32_t delay);
/**
 * @brief Get the Ticks object
 * 
 * @return uint32_t 
 */
uint32_t getTicks();                //millis() -> arduino

#endif