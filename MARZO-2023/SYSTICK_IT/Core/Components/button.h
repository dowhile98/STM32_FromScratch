/*
 * button.h
 *
 *  Created on: 15 mar. 2023
 *      Author: jeffr
 */

#ifndef COMPONENTS_BUTTON_H_
#define COMPONENTS_BUTTON_H_

/*Includes -----------------------------------------*/
#include "stm32f4xx.h"
#include "delay.h"
#include <stdbool.h>
#include <stdlib.h>
/*Typedef -----------------------------------------*/
typedef struct{
	uint8_t state;
	GPIO_TypeDef *GPIO;
	uint8_t pin;
	void (*callback)(void);
	uint32_t tickstart;
}Button_t;

typedef enum{
	PIN_TO_HIGH,
	PIN_TO_LOW,
	PIN_RELEASED
}Button_state_t;
/**
 * @brief funcion que inicializa la instancia que represanta un pulsador fisico
 * @param [BT]: Puntero a una estructura que representa el pulsador
 * @param [GPIO]: Puerto donde esta conectado el pulsador
 * @param [pin]: numbero de pin donde esta conectado el pulsador
 * @param [callback]: puntero a la funcion callback
 */
void ButtonInit(Button_t *BT, GPIO_TypeDef *GPIO, uint32_t pin, void (*callback)(void));
/**
 * @brief funcion para verificar el estado del pulsador
 * @param [BT]: Puntero que representa el pulsador fisico
 * @param [level]: el estado logico a verificar
 */
bool ButtonRead(Button_t *BT, Button_state_t level);
#endif /* COMPONENTS_BUTTON_H_ */
