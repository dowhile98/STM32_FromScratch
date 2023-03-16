/*
 * button.c
 *
 *  Created on: 15 mar. 2023
 *      Author: jeffr
 */

#include "button.h"

/*Typedef ----------------------------------------------------------------*/
typedef enum{
	PIN_INIT,
	PIN_HIGH,
	PIN_LOW,
	PIN_DEBOUNCE
}Button_UML_t;
/**
 * @brief funcion que inicializa la instancia que represanta un pulsador fisico
 * @param [BT]: Puntero a una estructura que representa el pulsador
 * @param [GPIO]: Puerto donde esta conectado el pulsador
 * @param [pin]: numbero de pin donde esta conectado el pulsador
 * @param [callback]: puntero a la funcion callback
 */
void ButtonInit(Button_t *BT, GPIO_TypeDef *GPIO, uint32_t pin, void (*callback)(void)){
	BT->GPIO = GPIO;
	BT->pin = pin;
	BT->callback = callback;
	BT->state = PIN_INIT;
	return;
}
/**
 * @brief funcion para verificar el estado del pulsador
 * @param [BT]: Puntero que representa el pulsador fisico
 * @param [level]: el estado logico a verificar
 */
bool ButtonRead(Button_t *BT, Button_state_t level){
	switch(BT->state){
	case PIN_INIT:
		BT->GPIO->MODER &=~ (0x3U<< 2 *BT->pin);		//input floating
		if(BT->GPIO->IDR & 0x1<<BT->pin){			//pin en estado alto
			BT->state = PIN_HIGH;
		}else{
			BT->state = PIN_LOW;
		}
		break;
	case PIN_LOW:
		if(BT->GPIO->IDR & 0x1<<BT->pin){		//de bajo a alto
			BT->state = PIN_DEBOUNCE;
			BT->tickstart = GetTicks();
		}
		break;
	case PIN_HIGH:
		if(!(BT->GPIO->IDR & 0x1<<BT->pin)){	//alto a bajo
			BT->state = PIN_DEBOUNCE;
			BT->tickstart = GetTicks();
		}
		break;
	case PIN_DEBOUNCE:
		if((GetTicks() - BT->tickstart) >= 16){
			if(BT->GPIO->IDR & 0x1<<BT->pin){	//HIGH
				BT->state = PIN_HIGH;
				if(level == PIN_TO_HIGH){
					//ejecutar el callback
					if(BT->callback != NULL){
						BT->callback();
					}
					return true;
				}

			}else{								//LOW
				BT->state = PIN_LOW;
				if(level == PIN_TO_LOW){
					//ejecutar el callback
					if(BT->callback != NULL){
						BT->callback();
					}
					return true;
				}
			}
		}
		break;
	}
	return false;
}
