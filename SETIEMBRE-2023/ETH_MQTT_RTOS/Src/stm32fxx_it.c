/*
 * stm32fxx_it.c
 *
 *  Created on: Oct 25, 2023
 *      Author: jeffr
 */


/*Includes ----------------------------------*/
#include <stm32f4xx.h>
#include <MQTT/mqtt_interface.h>

extern volatile uint32_t uwTick;
/*ISR---------------------------------------*/

//void SysTick_Handler(void){
//	if(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk){
//		uwTick += 1;
//		//mqtt inteface tick counter
//		MilliTimer_Handler();
//	}
//	return;
//}
