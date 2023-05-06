/*
 * rbuart.c
 *
 *  Created on: Apr 22, 2023
 *      Author: jeffr
 */

/*Includes ------------------------------------------------------------------------*/
#include "rbuart.h"
/*Private function ----------------------------------------------------------------*/

/*Function definition -------------------------------------------------------------*/
/**
 * @brief funcion para inicializar el buffer circular para funcionar con uart
 * @param UARTx: Puntero al uart utilizarse
 * @param bufferData: puntero para los datos del buffer circular
 * @param size: tamaño maximo del puntero de datos
 * @return RBUART_Result_t
 */
#if defined(USE_HAL_DRIVER)
RBUART_Result_t rbuart_init(rbuart_t *rb, UART_HandleTypeDef *UARTx, void* buffdata, size_t size){
#else
RBUART_Result_t rbuart_init(rbuart_t *rb, USART_TypeDef *UARTx, void* buffdata, size_t size){
#endif

	rb->rbuart = UARTx;
	rb->size = size;
	if(lwrb_init(&rb->buff, buffdata, size) == 1){
		return RBUART_OK;
	}
	return RBUART_ERROR;
}


/**
 * @brief callback para transmitir datos del del buffer circular
 * @param rb: puntero al buffer circular
 */
RBUART_Result_t rbuart_tx_callback(rbuart_t *rb){
	uint8_t data;
	size_t dataSize = lwrb_get_full(&rb->buff);
	if(dataSize == 0){

#if !defined(USE_HAL_DRIVER)
		rb->rbuart->CR1 &=~ (USART_CR1_TXEIE);
#endif
		rb->txState = 0;
		return RBUART_TXCPLT;
	}else{
#if defined(USE_HAL_DRIVER)
		lwrb_read(&rb->buff, &data, 1);
		rb->txState = 1;
		HAL_UART_Transmit_IT(rb->rbuart, &data, 1);

#else
		lwrb_read(rb, &data, 1);
		rb->rbuart->DR = data;
#endif
	}
	return RBUART_OK;
}
/**
 * @brief callback para recibir datos a un buffer circular
 * @param rb: puntero al buffer circular
 */
RBUART_Result_t rbuart_rx_callback(rbuart_t *rb, uint8_t *pData, size_t size){

	if(lwrb_get_free(&rb->buff) >= size){
		lwrb_write(&rb->buff, pData, size);
		HAL_UART_Receive_IT(rb->rbuart, &rb->rawByte, 1);
		return RBUART_RXCPLT;
	}
	return RBUART_ERROR;
}

/**
 * @brief funcion para enviar datos
 * @param rb: buffer utilizado para enviar datos
 * @param pData: puntero a los datos a enviar
 * @param size: tamaño de datos a enviar
 */
int32_t rbuart_send(rbuart_t *rb, uint8_t *pData, size_t size){
	uint8_t firstData;
	if(lwrb_get_free(&rb->buff) >= size){

		lwrb_write(&rb->buff, pData, size);
		if(rb->txState == 0){
			lwrb_read(&rb->buff, &firstData, 1);
			//se habilita la interrupcion para la transmisión
#if defined(USE_HAL_DRIVER)

			if(rb->rbuart->gState != HAL_UART_STATE_BUSY_TX || rb->rbuart->gState != HAL_UART_STATE_BUSY_TX_RX){
				HAL_UART_Transmit_IT(rb->rbuart, &firstData, 1);
			}
#else
			rb->rbuart->CR1 |= USART_CR1_TXEIE;
#endif
		}
		return size;
	}
	return 0;
}

/**
 * @brief funcion que inicia la recepcion de datos por interrupcion en el buffer circular
 * @param rb: puntero al buffer circular
 */
RBUART_Result_t rbuart_start_receive(rbuart_t *rb){
#if defined(USE_HAL_DRIVER)
	HAL_UART_Receive_IT(rb->rbuart, &rb->rawByte, 1);
#else
	rb->rbuart->CR1 |= USART_CR1_RXNEIE;
#endif
	return RBUART_OK;
}
/**
 * @brief funcion para terminar de recbiir los datos
 */
RBUART_Result_t rbuart_stop_receive(rbuart_t *rb){
#if defined(USE_HAL_DRIVER)
	rb->rbuart->Instance->CR1 &=~ USART_CR1_RXNEIE;
#else
	rb->rbuart->CR1 &=~ USART_CR1_RXNEIE;
#endif
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
