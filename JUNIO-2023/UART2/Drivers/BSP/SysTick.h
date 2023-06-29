/*
 * SysTick.h
 *
 *  Created on: 16 jun. 2023
 *      Author: jeffr
 */

#ifndef BSP_SYSTICK_H_
#define BSP_SYSTICK_H_

/*Include -------------------------------------------------------*/
#include "stm32f4xx.h"

/*Fuction prototype --------------------------------------------*/
void SysTick_Init(uint32_t ticks);

void delay_ms(uint32_t delay);

uint32_t GetTicks(void);

void TicksInc(uint32_t inc);

#endif /* BSP_SYSTICK_H_ */
