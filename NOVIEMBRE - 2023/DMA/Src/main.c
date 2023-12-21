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

#include <stdint.h>
#include "stm32f4xx.h"
#include "delay.h"
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "arm_math.h"
#include "IIR_Filter.h"
/*Defines --------------------------------------------------------------------*/
#define DUTY(X)		X * 400/100
/*Typedefs -------------------------------------------------------------------*/

/*Global variables -----------------------------------------------------------*/
RxData_t data = {
		.len = 0
};
bool  rxFlag = false;

arm_biquad_casd_df1_inst_f32 IIR0;
float32_t iirState0[NUM_SECTIONS *4];
float32_t coeff[5*NUM_SECTIONS];
uint16_t adcData[3];
/*Function prototype ---------------------------------------------------------*/
void USART1_Config(void);
int __io_putchar(int ch){
	while(!(USART1->SR & USART_SR_TXE));
	//TDR
	//RDR
	USART1->DR = (uint8_t)(ch & 0xFF);
	return ch;
}

bool dataReady(void){
	bool flag = rxFlag;
	rxFlag = false;
	return flag;
}
uint8_t uart_send_data(USART_TypeDef *USART, uint8_t *pData, uint32_t len, uint32_t timeout);
/*Main function --------------------------------------------------------------*/
int main(void)
{
	USART1_Config();
	//habilitar la interrupcion para la recepcion
	USART1->CR1 |= USART_CR1_RXNEIE;
	NVIC_EnableIRQ(USART1_IRQn);
	NVIC_SetPriority(USART1_IRQn, 2);

	printf("USART1 Init OK!\r\n");
	/**
	 * PG12
	 */
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN;
	GPIOG->MODER &=~ GPIO_MODER_MODE12;
	GPIOG->MODER |= GPIO_MODER_MODE12_0;
	/**
	 * GENERACION DE BASE DE TIEMPO
	 */
	RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;
	TIM6->CR1 = 0;
	/*
	 * F = 16MHZ
	 * UPDATE  = 1KHZ
	 * PSC = 16 - 1
	 * ARR = F /(PSC + 1)(UPDATE) - 1
	 */
	TIM6->PSC = 16 - 1;
	TIM6->ARR = 1000 - 1;
	TIM6->DIER |= TIM_DIER_UIE;
	NVIC_EnableIRQ(TIM6_DAC_IRQn);
	NVIC_SetPriority(TIM6_DAC_IRQn, 0xF);

	TIM6->CR1 |= TIM_CR1_CEN;
	/**
	 * GENERACION DE SEÑAL
	 */
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	/**
	 * sg90
	 * 0 - > 544us
	 * 180 ->2.4mus
	 * f = 50hz
	 */
	/**
	 * Fpwm = Ftim/(ARR + 1)(PSC + 1)
	 * ARR = Ftim /(PSC +1)Fpwm - 1
	 * ARR = 16MHZ/(15 + 1)1000 - 1
	 * ARR = 1000 - 1
	 */
	TIM3->CR1 = 0;
	TIM3->PSC = 160 - 1;
	TIM3->ARR = 1000 - 1;

	TIM3->CR2 &=~ TIM_CR2_MMS;
	TIM3->CR2 |= TIM_CR2_MMS_1;
	/*HABILITAR EL CONTEO DEL TIMER*/
	TIM3->CR1 |= TIM_CR1_CEN;

	/**
	 * ADC
	 */
	RCC->APB2ENR |= RCC_APB2ENR_ADC2EN;
	ADC->CCR &=~ (ADC_CCR_ADCPRE);

	ADC2->CR1 = 0;
	ADC2->CR1 |= ADC_CR1_OVRIE;

	ADC2->CR2 |= ADC_CR2_EXTEN_0;
	ADC2->CR2 |= ADC_CR2_EXTSEL_3; //TIMER 3 TRGO

	NVIC_EnableIRQ(ADC_IRQn);

	/**
	 * CONFIGURACION DE LOS CANALES ADC Y CANTIDAD DE CONVERSIONES
	 */
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	GPIOC->MODER |= GPIO_MODER_MODE0;			//ANALOG
	GPIOC->PUPDR &=~ GPIO_PUPDR_PUPD0;			//no pull/down
	//secuencia de conversion
	ADC2->SQR3 &=~ ADC_SQR3_SQ1;
	ADC2->SQR3 |= 10 <<ADC_SQR3_SQ3_Pos  |10 <<ADC_SQR3_SQ2_Pos |10<<ADC_SQR3_SQ1_Pos;			//conversion del canal 10
	ADC2->SQR1 &=~ ADC_SQR1_L;
	ADC2->SQR1 |= (3 - 1)<<ADC_SQR1_L_Pos;		//3 Conversiones

	ADC2->SMPR1 |= ADC_SMPR1_SMP10_0; 			//010: 28 cycles


	/**
	 *
	 */
	iir_coeff_reorder(b,a,coeff,NUM_SECTIONS); //se reordena los coeficientes del filtro iir
	arm_biquad_cascade_df1_init_f32(&IIR0,NUM_SECTIONS,coeff,iirState0);
	/**
	 * DMA
	 */
	RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN;
	//CONFIGURAR PAR
	DMA2_Stream3->PAR = (uint32_t)&ADC2->DR;
	//CONFIGURAR EL MAR
	DMA2_Stream3->M0AR = (uint32_t)adcData;
	//configurar la longitud de datos
	DMA2_Stream3->NDTR = 3;
	//Configurar el registro de control
	DMA2_Stream3->CR = 0;

	DMA2_Stream3->CR |= DMA_SxCR_CIRC; //modo circular
	DMA2_Stream3->CR |= DMA_SxCR_PSIZE_0 | DMA_SxCR_MSIZE_0; //16BITS
	DMA2_Stream3->CR |= DMA_SxCR_MINC;		//memory address increment
	DMA2_Stream3->CR |= DMA_SxCR_CHSEL_0;	//adc2
	DMA2_Stream3->CR |= DMA_SxCR_TCIE | DMA_SxCR_TEIE;
	DMA2_Stream3->FCR = 0;
	DMA2_Stream3->CR |= DMA_SxCR_EN;
	NVIC_EnableIRQ(DMA2_Stream3_IRQn);
	//ADC
	ADC2->CR2 |= ADC_CR2_DMA | ADC_CR2_DDS;
	ADC2->CR2 |= ADC_CR2_ADON;

    /* Loop forever */
	for(;;){


	}
}
/*Function definition --------------------------------------------------------*/
void USART1_Config(void){
	//1. configurar los pines
	//PA9 y PA10
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER &=~ (GPIO_MODER_MODE9 | GPIO_MODER_MODE10);
	GPIOA->MODER |= GPIO_MODER_MODE9_1 | GPIO_MODER_MODE10_1; //FA

	GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEED9 | GPIO_OSPEEDR_OSPEED10;  //Very high speed
	//Asignacion de funcion alternativa
	GPIOA->AFR[1] &=~(GPIO_AFRH_AFSEL9 | GPIO_AFRH_AFSEL10);
	GPIOA->AFR[1] |= 0x7<<GPIO_AFRH_AFSEL9_Pos | 0x7<<GPIO_AFRH_AFSEL10_Pos;
	//2. habilitar el reloj
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
	//3. Deshabilitar
	USART1->CR1 = 0;
	// Configurar los baudios
	/**
	 * USARTDIV = 16E+6 / (16 * 115200)
	 * USARTDIV = 8.6805
	 * MANTISA = 0x8
	 * fraction = 0.6805 * 16 = 10.88 -> 11
	 * FRACTION = 0xB
	 * BRR = 0x8B;
	 */
	USART1->BRR = 0x8B;

	USART1->CR1 |= USART_CR1_TE | USART_CR1_RE;

	//habilitar
	USART1->CR1 |= USART_CR1_UE;
	return;
}

uint8_t uart_send_data(USART_TypeDef *USART, uint8_t *pData, uint32_t len, uint32_t timeout){
	uint32_t ticks = getTicks();
	while((getTicks() - ticks) < timeout){
		if(USART->SR & USART_SR_TXE){
			USART->DR = *pData;
			pData += 1;
			len -= 1;
			if(len == 0){
				return 0; 	//ok
			}
		}
	}
	return 1;  				//error
}