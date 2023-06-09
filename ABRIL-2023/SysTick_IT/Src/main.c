/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/**
 * @brief
 */
#include <stdint.h>
#include <stm32f4xx.h>
#include <stdio.h>
#include <stdbool.h>
/*Typedef --------------------------------------------*/
typedef struct{
	GPIO_TypeDef *P;  //puerto
	uint32_t pin;		//pin
	uint8_t state;		//maquina de estados
	uint8_t debounce_ms;
	uint8_t tickStart;   //almacenar los ticks (tiempo)
}Button_t;
typedef enum{
	BUTTON_STATE_INIT,
	BUTTON_STATE_LOW,
	BUTTON_STATE_HIGH,
	BUTTON_STATE_DEBOUNCE
}Button_state_t;
/*Global variables -----------------------------------*/
Button_t sw = {
		.P = GPIOA,
		.pin = 0,
		.debounce_ms = 20,
		.state = BUTTON_STATE_INIT
};
volatile uint32_t uwTicks;
/*Function prototype ---------------------------------*/
void SysTick_Init(uint32_t ticks);

void delay_ms(uint32_t delay);

void SysTick_Handler(void){
	uwTicks += 1;
}
uint32_t GetTicks(void){
	return uwTicks;
}

bool pin_read(Button_t *btn);
/*****************************************************/
int main(void)
{
	uint32_t ticks;
	//PA15
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN | RCC_AHB1ENR_GPIOAEN;
	GPIOD->MODER &=~ GPIO_MODER_MODE15;
	GPIOD->MODER |= GPIO_MODER_MODE15_0;
	GPIOA->MODER &=~ GPIO_MODER_MODE0;
	/**
	 * ticks = systemcoreClock / freq;
	 */
	ticks = SystemCoreClock / 1000;
	SysTick_Init(ticks);



	ticks = GetTicks();
	int count = 0;
    /* Loop forever */
	for(;;){
//		if((GetTicks() - ticks)>= 100){ //(millis() - lastUpadte)>100
//			ticks = GetTicks();
//			GPIOD->ODR ^= 1U<<15;
//		}
//		/**
//		 * if(input){
//		 * delay(20);
//		 * while(bloqueo);
//		 *	validacion del estado
//		 * }
//		 */
		if(pin_read(&sw) == true){
			GPIOD->ODR ^= 1U<<15;
			printf("sw is press: %d\r\n", ++count);
		}
	}
}

void SysTick_Init(uint32_t ticks){
	/*1. Deshabilitar*/
	SysTick->CTRL = 0;
	/*Calular el  valor del registro reload*/
	/**
	 * updateEvent = SystickClk / freq - 1
	 * LOAD = udapteEvent
	 */
	SysTick->LOAD = ticks - 1;
	/*current val = 0*/
	SysTick->VAL = 0;
	/*configurar el registro de control*/
	//fuente de reloj
	SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;	//SYSCLK (AHB)
	//interrupcion
	SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;		//IT
	//habilitacion del contador

	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;		//enable

	return;
}

void delay_ms(uint32_t delay){
	uint32_t tickStart = GetTicks();
	while((GetTicks() - tickStart)<delay);
}


bool pin_read(Button_t *btn){
	switch(btn->state){
	case BUTTON_STATE_INIT:
		btn->tickStart = 0;
		btn->debounce_ms = (btn->debounce_ms == 0) ? 20 : btn->debounce_ms;
		//estado inicial del pin
		if(btn->P->IDR & 1u<<btn->pin){
			btn->state = BUTTON_STATE_HIGH;
		}else{
			btn->state = BUTTON_STATE_LOW;
		}
		break;
	case BUTTON_STATE_LOW:
		if(btn->P->IDR & 1u<<btn->pin){ //de bajo a alto
			btn->state = BUTTON_STATE_DEBOUNCE;
			btn->tickStart = GetTicks();
		}
		break;
	case BUTTON_STATE_HIGH:
		if(!(btn->P->IDR & 1u<<btn->pin)){ //de alto a bajo
			btn->state = BUTTON_STATE_DEBOUNCE;
			btn->tickStart = GetTicks();
		}
		break;
	case BUTTON_STATE_DEBOUNCE:
		if((GetTicks() - btn->tickStart)>= btn->debounce_ms){
			//verificar el estado
			if(btn->P->IDR & 1u<<btn->pin){ //press
				btn->state = BUTTON_STATE_HIGH;

			}else{
				btn->state = BUTTON_STATE_LOW;
				return true;
			}
		}
		break;
	}
	return false;
}

int __io_putchar(int ch){
	ITM_SendChar(ch);
	return ch;
}
