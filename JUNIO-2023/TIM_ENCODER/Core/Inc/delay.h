/*
 * delay.h
 *
 *  Created on: 10 oct. 2022
 *      Author: jeffr
 */

#ifndef INC_DELAY_H_
#define INC_DELAY_H_

/*Includes -----------------------------------------------*/

#include <stm32f4xx.h>
/*Function prototypes- -----------------------------------*/

void delay_init(void);

void delay_ms(uint32_t delay);

#endif /* INC_DELAY_H_ */
