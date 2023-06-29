/*
 * UART.c
 *
 *  Created on: 26 jun. 2023
 *      Author: jeffr
 */

#include "UART.h"

void UART_Init(USART_TypeDef *USART, UART_ConfigTypedef_t *config){


	//bits de parada
//	USART->CR2 &=~ USART_CR2_STOP;
//	USART->CR2 |= config->stopBit << USART_CR2_STOP_Pos;
	MODIFY_REG(USART->CR2, USART_CR2_STOP, config->stopBit);

	//M->
	USART->CR1 &=~ USART_CR1_M;
	USART->CR1 |= config->wordLength<<12;

	//paridad
	USART->CR1 &=~ (USART_CR1_PCE | USART_CR1_PS);
	USART->CR1 |= config->parity <<9;

	//modo
	USART->CR1 &=~ (USART_CR1_RE | USART_CR1_TE);
	USART->CR1 |= config->mode;

	//OVER
	USART->CR1 &=~ USART_CR1_OVER8;
	USART->CR1 |= config->over <<16;


	//BRR
	if(config->over == UART_OVER_8){
		USART->BRR = UART_BRR_SAMPLING8(config->pclk, config->baud);
	}else{
		USART->BRR = UART_BRR_SAMPLING16(config->pclk, config->baud);
	}

	//habilitar el UART
	USART->CR1 |= USART_CR1_UE;
	return;
}
/**
 * @brief
 * @param [USART]:
 * @param [pData]:
 * @param [len]:
 * @param [timeout]:
 */
uint8_t UART_SendData(USART_TypeDef *USART, uint8_t *pData, uint16_t len, uint32_t timeout){
	uint32_t tickStart = GetTicks();
	uint16_t *data;
	while((GetTicks() - tickStart)<= timeout){
		//envío de datos
		if(USART->SR & USART_SR_TXE){
			if(USART->CR1 & USART_CR1_M){	//9 bit de datos
				data = (uint16_t *) pData;
				USART->DR = *data & (0x1FF);
				//Verificar la paridad
				if(!(USART->CR1 & USART_CR1_PCE)){
					pData += 2;
					len -= 2;
				}else{
					pData += 1;
					len -= 1;
				}
			}else{							//8 bit de datos
				USART->DR = *pData & 0xFF;
				pData++;
				len -= 1;
			}
			//se verifica len
			if(len == 0){
				return 0;					//envio correcto
			}
		}
	}
	return 1;
}


uint8_t UART_ReceiveData(USART_TypeDef *USART, uint8_t *pData, uint16_t len, uint32_t timeout){
	uint32_t tickStart = GetTicks();
	while((GetTicks() - tickStart) <= timeout){
		if(USART->SR & USART_SR_RXNE){
			if(USART->CR1 & USART_CR1_M){
				if(!(USART->CR1 & USART_CR1_PCE)){
					*((uint16_t*)pData) = USART->DR & 0x1FF;
					pData += 2;
					len -= 2;
				}else{
					*pData = USART->DR & 0xFF;
					pData += 1;
					len -= 1;
				}
			}else{
				if(!(USART->CR1 & USART_CR1_PCE)){
					*pData = USART->DR & 0xFF;

				}else{
					*pData = USART->DR & 0x7F;
				}
				pData += 1;
				len -= 1;
			}
			if(len == 0){
				return 0;
			}
		}
	}
	return 1;
}










