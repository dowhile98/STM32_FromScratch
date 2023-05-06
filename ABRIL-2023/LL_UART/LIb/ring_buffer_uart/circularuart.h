/*
 * circularuart.h
 *
 *  Created on: May 5, 2023
 *      Author: jeffr
 */

#ifndef RING_BUFFER_UART_CIRCULARUART_H_
#define RING_BUFFER_UART_CIRCULARUART_H_

/*Includes ----------------------------------------------*/
#include <main.h>
#include <lwrb.h>
/*Typedef -----------------------------------------------*/
typedef enum{
	RBUART_OK,
	RBUART_ERROR,
	RBUART_TXCPLT,
	RBUART_RXCPLT
}RBUART_Result_t;

typedef struct{
	USART_TypeDef *USART;
	lwrb_t		buff;
	size_t		size;
	uint8_t 	rawByte;
	uint8_t 	txState;
}rbuart_t;
/*Defines -----------------------------------------------*/

/*Function prototype ------------------------------------*/
RBUART_Result_t rbuart_init(rbuart_t *RB, USART_TypeDef *USARTX, void *buffData, size_t _size);


/**
 * @brief funcion para enviar datos
 * @param rb: buffer utilizado para enviar datos
 * @param pData: puntero a los datos a enviar
 * @param size: tamaño de datos a enviar
 */
RBUART_Result_t rbuart_send(rbuart_t *rb, uint8_t *pData, size_t size);

/**
 * @brief funcion que inicia la recepcion de datos por interrupcion en el buffer circular
 * @param rb: puntero al buffer circular
 */
RBUART_Result_t rbuart_start_receive(rbuart_t *rb);

/**
 * @brief funcion para terminar de recbiir los datos
 */
RBUART_Result_t rbuart_stop_receive(rbuart_t *rb);
/**
 * @brief obtener los datos recibidos por IT
 * @param rb: puntero al buffer circular
 * @param rxData: puntero donde se almacena los datos recibidos
 * @param size: cantidad de datos leidos
 */
size_t rbuart_get_data(rbuart_t *rb, uint8_t *rxData, size_t size);

/**
 * @brief obtener la cantidad de datos almacenados en el buffer circular
 */
size_t rbuart_get_receiveSize(rbuart_t *rb);


/**
 * @brief callback para transmitir datos del del buffer circular
 * @param rb: puntero al buffer circular
 */
RBUART_Result_t rbuart_tx_callback(rbuart_t *rb);
/**
 * @brief callback para recibir datos a un buffer circular
 * @param rb: puntero al buffer circular
 * @param pData: Puntero de los datos recibidos
 * @param size: tamaño de datos recibidos
 */
RBUART_Result_t rbuart_rx_callback(rbuart_t *rb, uint8_t *pData, size_t size);

#endif /* RING_BUFFER_UART_CIRCULARUART_H_ */
