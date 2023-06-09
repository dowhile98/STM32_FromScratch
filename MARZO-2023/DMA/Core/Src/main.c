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
/*Includes -------------------------------------------------------------------*/
#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include <stdbool.h>
#include "defines.h"
#include "delay.h"
#include "button.h"
#include "FIRCoeff.h"
#include "arm_math.h"
/*Typedef --------------------------------------------------------------------*/


/*Defines ------------------------------------------------------------------- */
#define LED		D , 12
#define SW		A , 0
#define IN1		A , 1
/*Global variables ---------------------------------------------------------- */
Button_t button1;
bool adcComplet = false;
float32_t in;
float32_t out;
#define BLOCKSIZE 		1
float32_t FirState[K + BLOCKSIZE - 1];
arm_fir_instance_f32 filtro;
uint16_t adcData[4];
/*function prototype ---------------------------------------------------------*/
void ADC1_Init(void);

void DMA2_Stream4_init(void);
/*main function --------------------------------------------------------------*/

int main(void)
{

	printf("EJEMPLO GPIO1\r\n");
	printf("%s, %s\r\n", __DATE__, __TIME__);


	//init filter
	arm_fir_init_f32(&filtro, K, h, FirState, BLOCKSIZE);
	//PD12 (LED1)
	RCC->AHB1ENR |= GPIOX_CLOCK(LED) | GPIOX_CLOCK(SW);
	GPIOX_MODER(MODE_OUT, LED);
	GPIOX_OTYPER(MODE_OT_PP, LED);
	GPIOX_OSPEEDR(MODE_SPD_VHIGH, LED);
	GPIOX_PUPDR(MODE_PU_NONE, LED);

	//PA0
	GPIOX_MODER(MODE_DIGITAL_INPUT, SW);
	GPIOX_PUPDR(MODE_PU_NONE, SW);
	//systick
	SysTickInit();

	//inicializar
	ButtonInit(&button1, GPIOA, 0, NULL);
	//adc init
	ADC1_Init();
	DMA2_Stream4_init();
	//configurar los canales
	RCC->AHB1ENR |= GPIOX_CLOCK(IN1);
	GPIOX_MODER(MODE_ANALOG_INPUT, IN1);
	GPIOX_PUPDR(MODE_PU_NONE, IN1);
	//Sequencer
	ADC1->SQR1 &=~ (ADC_SQR1_L);		//una sola conversion
	ADC1->SQR1 |= 3<<ADC_SQR1_L_Pos;
	ADC1->SQR3 = 1<<ADC_SQR3_SQ1_Pos | 1<<ADC_SQR3_SQ2_Pos | 1<<ADC_SQR3_SQ2_Pos | 1<<ADC_SQR3_SQ4_Pos;						//IN1
	//Habilita el ADC
	ADC1->CR2 |= ADC_CR2_ADON;
	/*timer 2 init -------------------------------------*/
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	/**
	 * Update envent  = Ftim / (PSC + 1) (ARR + 1)
	 * PSC = 15
	 * ARR = 16E+6 / (16 * 500) - 1
	 * ARR = 2000 - 1 = 1999
	 */
	TIM2->PSC = 15;
	TIM2->ARR = 1999;
	//Habilitar la salida TRGO
	TIM2->CR2 &=~ TIM_CR2_MMS;
	TIM2->CR2 |= TIM_CR2_MMS_1;		//habilita el TGRO para el disparo del adc
    //Habilitar el conteo
	TIM2->CR1 |= TIM_CR1_CEN;
	/* Loop forever */
	for(;;){
		if(ButtonRead(&button1, PIN_TO_LOW)){
			//todo
		}
		if(adcComplet == true){
			//procesado
			in = adcData[0];
			arm_fir_f32(&filtro, &in, &out, 1);
			printf("in: %.3f out: %.3f\r\n", in, out);
		}

	}
}

/*Function definition ---------------------------------------------------------*/

void ADC1_Init(void){
	//HABILITAR EL RELOJ
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	//Configurar los rigistros comunes entre ADC1, ADC2, ADC3
	ADC123_COMMON->CCR &=~ ADC_CCR_ADCPRE;				//PCLK2 / 2
	//Configurar los registros del ADC1
	ADC1->CR1 = 0;
	ADC1->CR1 |= ADC_CR1_OVRIE;				//Generar IT cuando se sobrescribe el dato convertido
	ADC1->CR1 |= ADC_CR1_EOCIE;				//generar IT cuando se termine de realizar la conversion

	ADC1->CR2 |= ADC_CR2_EXTEN_0;			//disparo con flanco acendente
	ADC1->CR2 |= ADC_CR2_EXTSEL_1 | ADC_CR2_EXTSEL_2; //disparo por timer2 out event

	//habilitar la peticiones de transferencia DMA
	ADC1->CR2 |= ADC_CR2_EOCS;
	ADC1->CR2 |= ADC_CR2_DDS;
	ADC1->CR2 |= ADC_CR2_DMA;
	//habilitar el modo scan
	ADC1->CR1 |= ADC_CR1_SCAN;
	return;
}
void DMA2_Stream4_init(void){

	/*Habilitar el reloj	 */
	RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN;
	/*Deshabilitar el stream*/
	DMA2_Stream4->CR &=~ DMA_SxCR_EN;
	while(DMA2_Stream4->CR & DMA_SxCR_EN);
	DMA2->HIFCR |= 0xF<<2 | 1U;
	/*Configurar el valor del registro PAR*/
	DMA2_Stream4->PAR = (uint32_t) &ADC1->DR;
	/*Configurar el valor del registro MAR*/
	DMA2_Stream4->M0AR = (uint32_t)adcData;
	/*Numero de datos a stransmitir*/
	DMA2_Stream4->NDTR = 4;
	/*Seleccionar el request*/
	DMA2_Stream4->CR &=~ DMA_SxCR_CHSEL;	//CHANNEL 0
	/*configurar la prioridad*/
	DMA2_Stream4->CR |= DMA_SxCR_PL;		//prioridad alta
	/*Configurar la FIFO*/
	DMA2_Stream4->FCR &=~ DMA_SxFCR_DMDIS;	//direct mode
	/*Direccion de transmicion, el tamaño de datos a transmitir y el incremento*/
	DMA2_Stream4->CR &=~ (DMA_SxCR_MSIZE | DMA_SxCR_PSIZE);
	DMA2_Stream4->CR |= DMA_SxCR_MSIZE_0 | DMA_SxCR_PSIZE_0;	//16bit
	DMA2_Stream4->CR |= DMA_SxCR_MINC;							//memory address increment
	DMA2_Stream4->CR |= DMA_SxCR_CIRC;		//modo circular
	/*Configurar las interrupciones */
	DMA2_Stream4->CR |= DMA_SxCR_TCIE;
	NVIC_EnableIRQ(DMA2_Stream4_IRQn);
	/*Habilitamos el dma*/
	DMA2_Stream4->CR |= DMA_SxCR_EN;
	return;
}
/**
 * @adc callback
 */
void ADC1_CpltConvCallback(void){
	//todo
	//printf("data->%u\r\n", data);
	adcComplet = true;

}
int __io_putchar(int ch){
	ITM_SendChar(ch);
	return ch;
}
