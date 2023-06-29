/*
 * UART.h
 *
 *  Created on: 26 jun. 2023
 *      Author: jeffr
 */

#ifndef BSP_UART_H_
#define BSP_UART_H_

/*Includes ---------------------------------------------------*/
#include "stm32f4xx.h"
#include "SysTick.h"
/*Defines ---------------------------------------------------*/

#define UART_DIV_SAMPLING16(_PCLK_, _BAUD_)            ((uint32_t)((((uint64_t)(_PCLK_))*25U)/(4U*((uint64_t)(_BAUD_)))))
#define UART_DIVMANT_SAMPLING16(_PCLK_, _BAUD_)        (UART_DIV_SAMPLING16((_PCLK_), (_BAUD_))/100U)
#define UART_DIVFRAQ_SAMPLING16(_PCLK_, _BAUD_)        ((((UART_DIV_SAMPLING16((_PCLK_), (_BAUD_)) - (UART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) * 100U)) * 16U)\
                                                         + 50U) / 100U)
/* UART BRR = mantissa + overflow + fraction
            = (UART DIVMANT << 4) + (UART DIVFRAQ & 0xF0) + (UART DIVFRAQ & 0x0FU) */
#define UART_BRR_SAMPLING16(_PCLK_, _BAUD_)            ((UART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) << 4U) + \
                                                        (UART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0xF0U) + \
                                                        (UART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0x0FU))

#define UART_DIV_SAMPLING8(_PCLK_, _BAUD_)             ((uint32_t)((((uint64_t)(_PCLK_))*25U)/(2U*((uint64_t)(_BAUD_)))))
#define UART_DIVMANT_SAMPLING8(_PCLK_, _BAUD_)         (UART_DIV_SAMPLING8((_PCLK_), (_BAUD_))/100U)
#define UART_DIVFRAQ_SAMPLING8(_PCLK_, _BAUD_)         ((((UART_DIV_SAMPLING8((_PCLK_), (_BAUD_)) - (UART_DIVMANT_SAMPLING8((_PCLK_), (_BAUD_)) * 100U)) * 8U)\
                                                         + 50U) / 100U)
/* UART BRR = mantissa + overflow + fraction
            = (UART DIVMANT << 4) + ((UART DIVFRAQ & 0xF8) << 1) + (UART DIVFRAQ & 0x07U) */
#define UART_BRR_SAMPLING8(_PCLK_, _BAUD_)             ((UART_DIVMANT_SAMPLING8((_PCLK_), (_BAUD_)) << 4U) + \
                                                        ((UART_DIVFRAQ_SAMPLING8((_PCLK_), (_BAUD_)) & 0xF8U) << 1U) + \
                                                        (UART_DIVFRAQ_SAMPLING8((_PCLK_), (_BAUD_)) & 0x07U))

#define UART_DATA_8B	0
#define UART_DATA_9B	1
#define UART_TE_EN		1<<3
#define UART_RE_EN		1<<2
#define UART_OVER_16	0
#define UART_OVER_8		1
/*Typedefs --------------------------------------------------*/
typedef enum{
    UART_STOP_1B 	= 0,
	UART_STOP_0_5B 	= 1<<12,
	UART_STOP_2BIT	= 2<<12,
	UART_STOP_1_5BIT= 3<<12

}UART_StopBit_t;
typedef enum{
	UART_PARITY_NONE = 0X0,
	UART_PARITY_EVEN = 0b10,
	UART_PARITY_ODD	 = 0b11
}UART_Parity_t;
typedef struct{
	UART_StopBit_t stopBit;
	UART_Parity_t parity;
	uint8_t over;
	uint32_t baud;
	uint32_t pclk;
	uint8_t wordLength;
	uint8_t mode;
}UART_ConfigTypedef_t;
/*Function prototype ----------------------------------------*/
/**
 *
 */
void UART_Init(USART_TypeDef *USART, UART_ConfigTypedef_t *config);
uint8_t UART_ReceiveData(USART_TypeDef *USART, uint8_t *pData, uint16_t len, uint32_t timeout);
uint8_t UART_SendData(USART_TypeDef *USART, uint8_t *pData, uint16_t len, uint32_t timeout);

#endif /* BSP_UART_H_ */
