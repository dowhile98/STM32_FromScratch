/*
 * delay.h
 *
 *  Created on: 15 mar. 2023
 *      Author: jeffr
 */

#ifndef INC_DELAY_H_
#define INC_DELAY_H_


/*Includes ----------------------------------------------------*/
#include "stm32f4xx.h"

/*Fucntion prototype -----------------------------------------*/
void SysTickInit(void);

/**
 * @brief funcion para generar retardos en ms
 */
void delay_ms(uint32_t delay);
/**
 * @brief retorna el ticks generado por la SysTick
 * @return uint32_t
 */
uint32_t GetTicks(void);

/**
 * @brief callback para incrementar el tick
 */
void TickInc_Callback(void);


#endif /* INC_DELAY_H_ */
