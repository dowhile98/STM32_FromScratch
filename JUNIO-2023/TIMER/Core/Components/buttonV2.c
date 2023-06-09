/*
 * buttonV2.c
 *
 *  Created on: 24 mar. 2023
 *      Author: jeffr
 */


#include "buttonV2.h"
#include "delay.h"

//static bool pinChangeVerify(Button_Time_t *BT){
//	//todo
//
//}
void Button_InitTime(Button_Time_t *BT, GPIO_TypeDef *GPIOx, uint8_t pin, void (*f)(uint8_t pulse)){
	BT->GPIO = GPIOx;
	BT->pin = pin;
	BT->callback = f;
	//estado inicial
	BT->pulseCount = 0;
	BT->state = BT_INIT_STATE;
	BT->isPulse = false;
	return;
}


void Button_Update(Button_Time_t *BT){
	BT->ticks += 5;							//se actualiza la base de tiempo
	switch(BT->state){
	case BT_INIT_STATE:
		if(BT->GPIO->IDR & (1<<BT->pin)){
			BT->state = BT_HIGH_STATE;
		}else{
			BT->state = BT_LOW_STATE;
		}
		break;
	case BT_HIGH_STATE:

		if(!(BT->GPIO->IDR & (1<<BT->pin))){ //cambio de estado a bajo
			BT->state = BT_DEBOUNCE_STATE;
			BT->tickstart= BT->ticks;
		}
		break;
	case BT_LOW_STATE:
		if(BT->GPIO->IDR & (1<<BT->pin)){ //cambio de estado a alto
			BT->state = BT_DEBOUNCE_STATE;
			BT->tickstart= BT->ticks;
		}
		break;
	case BT_DEBOUNCE_STATE:
		if((BT->ticks - BT->tickstart)>= 15){
			//SE VERIFICA EL ESTADO ACTUAL DEL PIN
			if(!(BT->GPIO->IDR & (1<<BT->pin))){ //si el pin regresa a bajo
				//PULSO VALIDO (verifica el estado anterior)
				if(BT->isPulse == false){
					BT->isPulse = true;
					BT->pulseCount = 0;
				}
				BT->tickstart = BT->ticks; //para iniciar el contador del timer
				BT->pulseCount += 1;
				BT->state = BT_TIME_VERIFY;
			}else{
				BT->state = BT_HIGH_STATE;
			}
		}
		break;
	case BT_TIME_VERIFY:
		if((BT->ticks - BT->tickstart) < MAX_TIME_WAIT_FOR_NEXT_PULSE){
			//se verifica el cambio de estado
			if(BT->GPIO->IDR & (1<<BT->pin)){
				BT->tickstart = BT->ticks;
				BT->state = BT_DEBOUNCE_STATE;
			}
		}else{
			//se ejecuta el callback
			BT->callback(BT->pulseCount);
			BT->state = BT_LOW_STATE;
			BT->isPulse = false;
		}
		break;
	case BT_PULSE_COUNT:


		break;
	}
}
