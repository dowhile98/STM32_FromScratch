/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "stm32f4xx.h"
/* Private includes ----------------------------------------------------------*/
#include "RCC.h"
#include "Config.h"
#include "USART.h"
#include "Delay.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Servo.h"

/* Private typedef -----------------------------------------------------------*/


/* Private define ------------------------------------------------------------*/


/* Private macro -------------------------------------------------------------*/
#define USE_SWV			0


#define DUTY(x)			(uint16_t)((((float)x/100)*(TIM2->ARR + 1)) - 1)
/* Private variables ---------------------------------------------------------*/

USART_Handle_t handle_usart2;

uint8_t rxBuffer[20];
uint8_t byte;
uint8_t i;

uint8_t duty;

Servo_Handle_t servo1;
Servo_Handle_t servo2;
/* Private function prototypes -----------------------------------------------*/


/* Private user code ---------------------------------------------------------*/


/* External variables --------------------------------------------------------*/


int main(void)
{
//	PLL_Config();
	/*delay init*/
#if USE_DELAY_US == 1
	delay_Init(SystemCoreClock/1000000);
#else
	delay_Init(SystemCoreClock/1000);
#endif
	/*UART INIT*/
	USART_Init(USART2, 115200);
	handle_usart2.pUSARTx = USART2;
	USART_IRQInterruptConfig(USART2_IRQn, ENABLE);
	USART_ReceiveDataIT(&handle_usart2, &byte, 1);
	/*CONFIGURAR EL SERVO*/
	servo1.pGPIO = GPIOA;
	servo1.Servo_Pin = 7;
	servo1.pTIM = TIM3;			//timer usado para manipular el servo
	servo1.TIM_CH = 2;				//canal usado
	servo1.TIM_PSC = 16000000;		//frecuencia de reloj del timer
	servo1.MinPulse = 0.6;			//0.6ms  pulso minimo
	servo1.MaxPulse = 2.3;			//2.3ms pulso maximo

	servo2.pGPIO = GPIOB;
	servo2.Servo_Pin = 0;
	servo2.pTIM = TIM3;			//timer usado para manipular el servo
	servo2.TIM_CH = 3;				//canal usado
	servo2.TIM_PSC = 16000000;		//frecuencia de reloj del timer
	servo2.MinPulse = 1;			//0.6ms  pulso minimo
	servo2.MaxPulse = 2;			//2.3ms pulso maximo
	SERVO_Init(&servo1);
	SERVO_Init(&servo2);
//	SERVO_Write(&servo1, 90);
//	delay_ms(500);
//	SERVO_WriteMicroSeconds(&servo1, 1800);
	/*LED INIT*/

    /* Loop forever */
	for(;;){
		SERVO_Write(&servo1, 0);
		SERVO_Write(&servo2, 180);
		delay_ms(2000);
		SERVO_Write(&servo2, 135);
		SERVO_Write(&servo1, 45);
		delay_ms(2000);
		SERVO_Write(&servo2, 90);
		SERVO_Write(&servo1, 90);
		delay_ms(2000);
		SERVO_Write(&servo2, 15);
		SERVO_Write(&servo1, 135);
		delay_ms(2000);
		SERVO_Write(&servo2, 0);
		SERVO_Write(&servo1, 180);
		delay_ms(2000);
	}
}


/*****************************************************************************/
void USART_ApplicationEventCallback(USART_Handle_t *pUSARTHandle,uint8_t event)
{
	if(event == USART_EVENT_RX_CMPLT){
		if(byte != 'X'){
				rxBuffer[i] = byte;
				i++;
		}else{
			rxBuffer[i] = '\n';
			duty = atoi((char*)rxBuffer);		//string -> integer
			memset(rxBuffer,0,i);				//limpia el buffer
			i = 0;
			TIM2->CCR3 = DUTY(duty);
		}

		USART_ReceiveDataIT(&handle_usart2, &byte, 1);
	}

}

/******************************************************************************/
int __io_putchar(int ch){
#if (USE_SWV== 1)
	ITM_SendChar((uint32_t)ch);
#else
	uint8_t c = ch & 0xFF;
	while(!(USART2->SR & USART_SR_TXE));  //espera hasta que usart este listo para transmitir otro byte
	USART2->DR = c;
#endif
	return ch;
}

