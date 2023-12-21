/**
 *
 */

#ifndef __DELAY_H
#define __DELAY_H
#ifdef __cplusplus
extern "C" {
#endif

/*Includes -------------------------------------*/
#include <stm32f4xx.h>

extern volatile uint32_t uwTick;
/*Function prototype ---------------------------*/
void delay_init_it(void);

/**
 * @brief funcion encargada de generar retardos en ms
 * @param [delay]: tiempo de retado en ms deseado
 */
void delay_ms(uint32_t delay);

/**
 * @brief funcion similar a la funcion de arduino
 */
uint32_t millis(void);


#ifdef __cplusplus
 }
#endif
#endif /*__DELAY_H*/