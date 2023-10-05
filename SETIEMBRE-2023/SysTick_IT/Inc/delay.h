/*
 * delay.h
 *
 *  Created on: Oct 4, 2023
 *      Author: jeffr
 */

#ifndef DELAY_H_
#define DELAY_H_

/*Includes --------------------------------------------*/
#include <stm32c0xx.h>

/*Function prototype ----------------------------------*/
/**
 * @brief funcion de inicializacion de la base de tiempo
 * @params[ticks] : uint32_t ticks por segundo
 * @return : none
 * @note
 * ......
 */
void delay_init(uint32_t ticks);
/**
 *
 */
void delay_ms(uint32_t delay);
/**
 *
 */
uint32_t GetTicks(void);

void TicksInc(uint32_t i);

#endif /* DELAY_H_ */
