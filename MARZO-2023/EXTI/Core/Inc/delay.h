/*
 * delay.h
 *
 *  Created on: 30 ene. 2023
 *      Author: jeffr
 */

#ifndef INC_DELAY_H_
#define INC_DELAY_H_

#include "stm32f4xx.h"

/**
 * @brief configura la systick para generar interrupciones cada 1ms
 */
void SysTick_Init(void);
/**
 * @brief funcion para generar retardos en ms
 * @param[delay]: tiempo de retardo en ms deseado
 */
void delay_ms(uint32_t delay);

/**
 * @brief retorna el time stamp
 */
uint32_t GetTick(void);

#endif /* INC_DELAY_H_ */
