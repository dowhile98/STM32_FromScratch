/*
 * buttonV2.h
 *
 *  Created on: 24 mar. 2023
 *      Author: jeffr
 */

#ifndef COMPONENTS_BUTTONV2_H_
#define COMPONENTS_BUTTONV2_H_

/*Includes -------------------------------------------------- */
#include "stm32f4xx.h"
#include <stdbool.h>

/*Typedef ---------------------------------------------------*/
typedef struct{
	GPIO_TypeDef *GPIO;
	uint8_t pin;
	uint8_t state;
	uint32_t ticks;
	uint32_t tickstart;
	uint8_t pulseCount;
	void (*callback)(uint8_t pulse);
	bool isPulse;
}Button_Time_t;

typedef enum{
	BT_INIT_STATE,  //para definir el estado inicial
	BT_HIGH_STATE,	//cuando el pin este en alto para verificar si hay cambio de estado
	BT_LOW_STATE,	//cuando el pin este en bajo para verificar si cambio de estado
	BT_PULSE_COUNT,	//para incrimentar el conteo de pulsos si se presiona varias veces
	BT_TIME_VERIFY,	//tiempo maximo que se tiene para ingresar el siguiente pulso
	BT_DEBOUNCE_STATE
}Button_time_state_t;

/*Defines ---------------------------------------------------*/
#define MAX_TIME_WAIT_FOR_NEXT_PULSE	200

/*Function prototype ----------------------------------------*/
void Button_InitTime(Button_Time_t *BT, GPIO_TypeDef *GPIOx, uint8_t pin, void (*f)(uint8_t pulse));


void Button_Update(Button_Time_t *BT);


#endif /* COMPONENTS_BUTTONV2_H_ */
