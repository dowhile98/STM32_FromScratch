/*
 * circularuart.c
 *
 *  Created on: May 5, 2023
 *      Author: jeffr
 */

#include "circularuart.h"

RBUART_Result_t rbuart_init(rbuart_t *RB, USART_TypeDef *USARTX, void *buffData, size_t _size){
	RB->USART = USARTX;
	RB->size = _size;
	if(lwrb_init(&RB->buff, buffData, _size) == 1){
		return RBUART_OK;
	}
	return RBUART_ERROR;
}

RBUART_Result_t rbuart_send(rbuart_t *rb, uint8_t *pData, size_t size){

	if(lwrb_get_free(&rb->buff) >= size){
		lwrb_write(&rb->buff, pData, size);
		//enable interrupt
		rb->USART->CR1 |= USART_CR1_TXEIE;
		return RBUART_OK;
	}
	return RBUART_ERROR;
}


/**
 * @brief funcion que inicia la recepcion de datos por interrupcion en el buffer circular
 * @param rb: puntero al buffer circular
 */
RBUART_Result_t rbuart_start_receive(rbuart_t *rb){
	rb->USART->CR1 |= USART_CR1_RXNEIE;
	return RBUART_OK;
}

/**
 * @brief funcion para terminar de recbiir los datos
 */
RBUART_Result_t rbuart_stop_receive(rbuart_t *rb){
	rb->USART->CR1 &=~ USART_CR1_RXNEIE;
	return RBUART_OK;
}

/**
 * @brief obtener los datos recibidos por IT
 * @param rb: puntero al buffer circular
 * @param rxData: puntero donde se almacena los datos recibidos
 * @param size: cantidad de datos leidos
 */
size_t rbuart_get_data(rbuart_t *rb, uint8_t *rxData, size_t size){
	return lwrb_read(&rb->buff, rxData, size);
}

/**
 * @brief obtener la cantidad de datos almacenados en el buffer circular
 */
size_t rbuart_get_receiveSize(rbuart_t *rb){
	return lwrb_get_full(&rb->buff);
}

/**
 * @brief callback para transmitir datos del del buffer circular
 * @param rb: puntero al buffer circular
 */
RBUART_Result_t rbuart_tx_callback(rbuart_t *rb){
	uint8_t data;
	size_t dataSize = lwrb_get_full(&rb->buff);

	if(dataSize == 0){
		rb->USART->CR1 &=~ USART_CR1_TXEIE;
		rb->txState = RBUART_TXCPLT;
	}else{
		lwrb_read(&rb->buff, &data, 1);
		rb->USART->DR = data;
	}
	return RBUART_OK;
}

RBUART_Result_t rbuart_rx_callback(rbuart_t *rb, uint8_t *pData, size_t size){
	if(lwrb_get_free(&rb->buff)>0){
		lwrb_write(&rb->buff, pData, size);
		return RBUART_RXCPLT;
	}
	RBUART_ERROR;
}
