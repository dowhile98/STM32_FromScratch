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
 * LED1 -> PD12
 * LED2 -> PD15
 *
 * SW -> PA0
 *
 * NUCLEO 64
 * LED  -> PA5
 * SW   -> PC13
 * COM -> USART2
 */

/*Includes --------------------------------------*/
#include <stdint.h>
#include "stm32f4xx.h"
#include <stdio.h>
#include "delay.h"
#include "lwbtn.h"

/*defines ---------------------------------------*/
/**
 * ##
 */
#define LED			D, 12
#define SW			A, 0
#define SW1			A, 1
#define SW2			A, 2


#define GPIOX_MODER_(a, b, c)	{GPIO ## a ->MODER &=~ (0x3<<(2 * b)) ; \
								GPIO ## a ->MODER |= c <<( 2 * b); }
#define GPIOX_MODER(a, b)		GPIOX_MODER_(a, b)

#define INPUT_READ_(a, b)		(GPIO ## a -> IDR & 1<<b) ? 1 : 0
#define INPUT_READ(a)			INPUT_READ_(a)

#define OUTPUT_SET_(a, b)		GPIO ## a -> ODR |= 1<<b
#define OUTPUT_SET(a)			OUTPUT_SET_(a)

#define OUTPUT_RESET_(a, b)		GPIO ## a -> ODR &=~( 1<<b)
#define OUTPUT_RESET(a)			OUTPUT_RESET_(a)

/*Global variables ------------------------------*/
uint8_t key[] = {0, 1, 2};
lwbtn_btn_t btns[] = {
		{.arg = (void *)&key[0]},
		{.arg = (void *)&key[1]},
		{.arg = (void *)&key[2]}
};
/*Function prototype ----------------------------*/
uint8_t
prv_btn_get_state(struct lwbtn* lw, struct lwbtn_btn* btn);
void
prv_btn_event(struct lwbtn* lw, struct lwbtn_btn* btn, lwbtn_evt_t evt);



/*Main ------------------------------------------*/
int main(void)
{
	uint32_t temp;
	/*habilitar el reloj*/
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;  //1<<3
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	/**
	 * PD12 -> salida
	 *
	 */
	GPIOD->MODER &=~(GPIO_MODER_MODE12); 	//Clear
	GPIOD->MODER |= GPIO_MODER_MODE12_0;	//Modo salida de proposito general
	GPIOD->OTYPER &=~ GPIO_OTYPER_OT12;		//PUSH PULL
	GPIOD->OSPEEDR &=~ GPIO_OSPEEDER_OSPEEDR12;
	/**
	 * PA0 -> entrada
	 */
	GPIOA->MODER &=~(GPIO_MODER_MODE0); //RESET STATE (INPUT FLOATING)
	GPIOA->PUPDR &=~ (GPIO_PUPDR_PUPD0); //no pull up /down

	/**
	 * @brief systick
	 * 
	 */
	temp = 16E+6 / 1E+3;
	SysTick_Config(temp);
	NVIC_SetPriority(SysTick_IRQn, 15);
	/**
	 * LWBTN
	 */
	lwbtn_init(btns, 3, prv_btn_get_state, prv_btn_event);
	/**
	 * EXTI
	 */
	RCC->AHB2ENR |= RCC_APB2ENR_SYSCFGEN;
	EXTI->IMR |= EXTI_IMR_IM0;
	//configurar el borde de disparo
	EXTI->RTSR |= EXTI_RTSR_TR0;					//rising edge
	//Seleecionar el pin
	SYSCFG->EXTICR[0] &=~(SYSCFG_EXTICR1_EXTI0);	//PA0
	EXTI->PR |= EXTI_PR_PR0;						//Clear
	//habilitar la interrupcion en la NVIC
	NVIC_EnableIRQ(EXTI0_IRQn);
	NVIC_SetPriority(EXTI0_IRQn, 3);


	for(;;){
		/*
		 * R0-R3 R4, LR, MSP Y pc ->push (se hace un backup)
		 * 						  ->pop
		 */

		//lwbtn_process(getTicks());
	}
}


/*Function definition -----------------------------------------*/
int __io_putchar(int ch){
	ITM_SendChar(ch);
	return ch;
}

uint8_t
prv_btn_get_state(struct lwbtn* lw, struct lwbtn_btn* btn){
	uint8_t sw = *((uint8_t*)btn->arg);
	uint8_t state = 0;
	switch(sw){
	case 0:
		state = INPUT_READ(SW);
		break;
	case 1:
		//state = (INPUT_READ(SW1)) ? 0 : 1;
		break;
	case 2:
		//state = INPUT_READ(SW2);
		break;
	}
	return state;
}

void
prv_btn_event(struct lwbtn* lw, struct lwbtn_btn* btn, lwbtn_evt_t evt){
	//uint8_t sw = *((uint8_t*)btn->arg);
	uint8_t event = evt;
	switch(event){
	case LWBTN_EVT_ONPRESS:
		printf("SW ON PRESS\r\n");
		break;
	case LWBTN_EVT_ONRELEASE:
		printf("SW ON RELEASE\r\n");
		break;
//	case LWBTN_EVT_KEEPALIVE:
//		printf("SW ON KEEPALIVE\r\n");
		break;
	case LWBTN_EVT_ONCLICK:
		printf("SW ON CLICK:%d\r\n", btn->click.cnt);
		break;
	}
}