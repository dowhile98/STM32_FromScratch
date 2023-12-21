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
#include <stm32c0xx.h>
#include <stdbool.h>
#include <delay.h>
#include <lwbtn/lwbtn.h>
#include <stdio.h>

/*Macro defines ---------------------------------*/

#define MODE_INPUT				0x0
#define MODE_OUTPUT				0x1
#define MODE_AF					0x2
#define MODE_ANALOG				0x3


#define GPIO_MODER_(m, p, b) do{\
								GPIO ## p ->MODER &=~(0x3<<(2*b));\
								GPIO ## p ->MODER |= (m << (2*b));\
							 }while(0)

#define GPIO_MODER(a, b) GPIO_MODER_(a, b)
#define GPIO_CLOCK_ENABLE_(a, b)	RCC->IOPENR |= RCC_IOPENR_GPIO ## a ## EN
#define GPIO_CLOCK_ENABLE(a)  		GPIO_CLOCK_ENABLE_(a)

#define GPIO_PIN_SET_(a, b)		GPIO ## b -> BSRR |= (1<< b)
#define GPIO_PIN_SET(a)			GPIO_PIN_SET_(a)
#define GPIO_PIN_CLEAR_(a, b)		GPIO ## b -> BSRR |= (1<< (b + 16))
#define GPIO_PIN_CLEAR(a)			GPIO_PIN_CLEAR_(a)
/*Defines ---------------------------------------*/
#define USART2_TX				A, 2
#define USART2_RX				A, 3

/*Typedef ---------------------------------------*/
typedef uint8_t (*readFc)(void);
typedef enum{
	BUTTON1 = 0,
	BUTTON2,
	BUTTON3

}Btns_enum_t;

/*Funcion prototype ------------------------------*/
void
prv_btn_event(struct lwbtn* lw, struct lwbtn_btn* btn, lwbtn_evt_t evt);
uint8_t
prv_btn_get_state(struct lwbtn* lw, struct lwbtn_btn* btn);

void UART2_Init();
uint8_t getButton1(void);

void ADC1_Init(void);
/*Global variables ------------------------------*/
uint32_t ledTicks = 0;
uint32_t buttonTicks = 0;
uint8_t pins[] = {BUTTON1, BUTTON2, BUTTON3};

static lwbtn_btn_t btns[] = {
		{.arg = (void *)getButton1}
};

uint16_t adcVals[4];
/*Main function ----------------------------------*/
int main(void)
{
	RCC->IOPENR |= RCC_IOPENR_GPIOAEN | RCC_IOPENR_GPIOCEN;
	RCC->CR &=~ (RCC_CR_HSIDIV);
	SystemCoreClockUpdate();
	//LED - PA5
	//SWITCH -> PC13
	//MODER
	GPIOA->MODER &=~ (GPIO_MODER_MODE5); //reset (MODER5)
	GPIOA->MODER |= GPIO_MODER_MODE5_0; 	//Salida de proposito general ;

	GPIOC->MODER &=~ GPIO_MODER_MODE13;		//Reset (MODER13) Entrada
	//OTYPER
	GPIOA->OTYPER &=~ GPIO_OTYPER_OT5;
	//OSPEEDR
	GPIOA->OSPEEDR &=~ GPIO_OSPEEDR_OSPEED5;
	GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEED5_1;//High speed

	//PUPDR
	GPIOA->PUPDR &=~ GPIO_PUPDR_PUPD5;
	GPIOC->PUPDR &=~ GPIO_PUPDR_PUPD13;

	//poner en alto el pin
	GPIOA->ODR |= GPIO_ODR_OD5;
//	GPIOA->BSRR |= GPIO_BSRR_BS5; //1<<5
	//poner en bajo el pin
	GPIOA->ODR &=~ GPIO_ODR_OD5;
//	GPIOA->BSRR |= GPIO_BSRR_BR5; //1<<21
	SystemCoreClockUpdate();
	delay_init(SystemCoreClock / 1000);

	ledTicks = GetTicks();
	buttonTicks = GetTicks();
	//button init

	lwbtn_init(btns, 1,prv_btn_get_state, prv_btn_event);

	//usart
	UART2_Init();
	printf("HOLA MUNDO DESDE UART2\r\n");


	//ADC
	//PA0-PA1, PA4, PA5 analogicos
	GPIOA->MODER |= GPIO_MODER_MODE0 | GPIO_MODER_MODE1 | GPIO_MODER_MODE4 | GPIO_MODER_MODE5;
	GPIOA->PUPDR &=~(GPIO_MODER_MODE0 | GPIO_MODER_MODE1 | GPIO_MODER_MODE4 | GPIO_MODER_MODE5);
	ADC1_Init();
	//DMA
	RCC->AHBENR |= RCC_AHBENR_DMA1EN;

	//configuramos el canal del DMA
	DMA1_Channel1->CPAR = (uint32_t)&ADC1->DR;
	DMA1_Channel1->CMAR = (uint32_t)&adcVals[0];
	DMA1_Channel1->CNDTR = 4;
	DMA1_Channel1->CCR = 0;


	DMA1_Channel1->CCR |= DMA_CCR_PL;  //Very high
	DMA1_Channel1->CCR |= DMA_CCR_MSIZE_0 | DMA_CCR_PSIZE_0; //16bit
	DMA1_Channel1->CCR |= DMA_CCR_MINC; //Incrementa la memoria
	DMA1_Channel1->CCR |= DMA_CCR_CIRC;
	DMA1_Channel1->CCR |= DMA_CCR_TCIE;

	NVIC_EnableIRQ(DMA1_Channel1_IRQn);

	//mux

	//habilitamos el CHANNEL
	DMA1_Channel1->CCR |= DMA_CCR_EN;

	//configurar la habilitacion del dma en el adc
	ADC1->CR |= ADC_CFGR1_DMACFG | ADC_CFGR1_DMAEN;

	//Configurar el TIMER3 para generar el disparo
	RCC->APBENR1 |= RCC_APBENR1_TIM3EN;
	TIM3->CR1 = 0;
	TIM3->PSC = 48 - 1;
	TIM3->ARR = 10000 - 1;
	TIM3->CR2 &=~ TIM_CR2_MMS;
	TIM3->CR2 |= 2<<4;


	//habilitamos el adc
	ADC1->CR |= ADC_CR_ADEN;
	while(!(ADC1->ISR & ADC_ISR_ADRDY));
	ADC1->CR |= ADC_CR_ADSTART;

	TIM3->CR1 |= TIM_CR1_CEN;
	for(;;){
//		if((GetTicks() - ledTicks) >= 10){
//			ledTicks = GetTicks();
//			GPIOA->ODR ^= 1<<5;
//		}
		if((GetTicks() - buttonTicks)>= 5){
			//todo
			buttonTicks = GetTicks();
			lwbtn_process(GetTicks());
		}
	}
}

/*Funcion definition -----------------------------------------------*/
void UART2_Init(){
	//GPIO
	GPIO_CLOCK_ENABLE(USART2_TX);

	GPIO_MODER(MODE_AF, USART2_TX);
	GPIO_MODER(MODE_AF, USART2_RX);
	GPIOA->OTYPER &=~ (GPIO_OTYPER_OT2 | GPIO_OTYPER_OT3);
	GPIOA->PUPDR &=~ (GPIO_PUPDR_PUPD2 | GPIO_PUPDR_PUPD3);
	GPIOA->OSPEEDR |= GPIO_OSPEEDR_OSPEED2 | GPIO_OSPEEDR_OSPEED3;
	GPIOA->AFR[0] &=~ (GPIO_AFRL_AFSEL2 | GPIO_AFRL_AFSEL3);
	GPIOA->AFR[0] |= 0x1<<GPIO_AFRL_AFSEL2_Pos;
	GPIOA->AFR[0] |= 0x1<<GPIO_AFRL_AFSEL3_Pos;
	//UART
	RCC->APBENR1 |=  RCC_APBENR1_USART2EN;
	USART2->CR1 = 0;
	USART2->CR1 |= USART_CR1_TE;
	USART2->CR1 |= USART_CR1_RE;
	//USART2->CR1 |= USART_CR1_OVER8;
	//USART2->CR1 |= USART_CR1_RXNEIE_RXFNEIE;
	USART2->PRESC = 0x0;					//PCLK / 2 = 24MHZ
	/**
	 * BRR ->  2 * 24MHZ / 115200 =~ 417
	 * USARTDIV = 0x1A1
	 * 0x1 >> 1 = 0 -> 0001 >> 0000
	 * BRR = 0x1A0
	 */
	USART2->BRR = 0x1A1;

	USART2->CR1 |= USART_CR1_UE;
	return;
}

void ADC1_Init(void){
	//habilitar el reloj
	RCC->APBENR2 |= RCC_APBENR2_ADCEN;
	//configurar la fuente de reloj
	ADC->CCR &=~ADC_CCR_PRESC;			//no prescaler
	ADC1->CFGR2 |= ADC_CFGR2_CKMODE;   //MODO Sincrono
	//configurar el adc
	ADC1->CFGR1 = 0;
	ADC1->CFGR1 |= ADC_CFGR1_CHSELRMOD; //sequence up to 8 channels
	ADC1->CFGR1 |= ADC_CFGR1_WAIT;		//para asegurar la lectura de dato convertido
	ADC1->CFGR1 |= ADC_CFGR1_EXTEN_0; 	//disparo externo flanco asc..
	ADC1->CFGR1 |= 0x3<<ADC_CFGR1_EXTSEL_Pos; //Timer 3 TRGO Output
	//calibrar el adc
	ADC1->CR |= ADC_CR_ADVREGEN;
	delay_ms(10);
	ADC1->CR |= ADC_CR_ADCAL;
	while(!(ADC1->ISR & ADC_ISR_EOCAL));
	printf("ADC CAL. FACTOR: 0x%X\r\n", ADC1->DR);
	//configurar el tiempo de muestreo

	ADC1->SMPR |= ADC_SMPR_SMP2_1 | ADC_SMPR_SMP2_0; //SAMPLING 2 : 0x3 (12.5 Cycles)
	ADC1->SMPR |= ADC_SMPR_SMP1_0;	//SAMPLING 1: 0x1 (3.5 Cycles)

	ADC1->SMPR |= ADC_SMPR_SMPSEL0 | ADC_SMPR_SMPSEL3; //SAMPLING 2
	//configurar la secuencia de conversion
	ADC1->CHSELR = 0x0;
	ADC1->CHSELR |= 4;			//1st -> channel 4
	ADC1->CHSELR |= 1<<4; 		//2nd -> channel 1
	ADC1->CHSELR |= 5<<12;      //channel 5
	ADC1->CHSELR |= 0xFFFF<<16;

	return;
}

/**
 * \brief           Button event
 *
 * \param           lw: LwBTN instance
 * \param           btn: Button instance
 * \param           evt: Button event
 */
void
prv_btn_event(struct lwbtn* lw, struct lwbtn_btn* btn, lwbtn_evt_t evt){
	readFc button = (readFc)btn->arg;
	uint8_t event = evt;

	switch(event){
	case LWBTN_EVT_ONPRESS:
		if(button == getButton1){
			printf("BUTTON 1 ON PRESS\r\n");
		}
		break;
	case LWBTN_EVT_ONRELEASE:
		if(button == getButton1){
			printf("BUTTON 1 ON RELEASE\r\n");
		}
		break;
	case LWBTN_EVT_ONCLICK:
		if(button == getButton1){
			printf("BUTTON 1 ON CLICK:%d\r\n", btn->click.cnt);
		}
		break;
	case LWBTN_EVT_KEEPALIVE:
		if(button == getButton1){
			GPIOA->ODR ^= 1<<5;
		}
		break;
	}
}



uint8_t
prv_btn_get_state(struct lwbtn* lw, struct lwbtn_btn* btn){


	readFc fc = (readFc)btn->arg;
	return fc();
	return 0;
}

uint8_t getButton1(void){
	return (GPIOC->IDR) ? 0: 1;
}

int __io_putchar(int ch){
	uint8_t c = ch & 0xFF;

	while(!(USART2->ISR & USART_ISR_TXE_TXFNF));
	USART2->TDR = c;

	return ch;
}