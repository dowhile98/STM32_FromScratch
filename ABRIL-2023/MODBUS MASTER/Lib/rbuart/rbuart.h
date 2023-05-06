/*
 * rbuart.h
 *
 *  Created on: Apr 22, 2023
 *      Author: jeffr
 */

#ifndef RBUART_RBUART_H_
#define RBUART_RBUART_H_

/*Includes ----------------------------------------------------------*/
#include "lwrb.h"
#include <stdbool.h>
#include <stdint.h>
#include "main.h"

/*Typedef -----------------------------------------------------------*/
typedef enum{
	RBUART_OK = 0,
	RBUART_ERROR,
	RBUART_TXCPLT,
	RBUART_RXCPLT,
}RBUART_Result_t;
typedef struct{
#if defined(USE_HAL_DRIVER)
	UART_HandleTypeDef *rbuart;
#else
	USART_TypeDef *rbuart;
#endif
	lwrb_t buff;
	size_t size;
	uint8_t rawByte;
	uint8_t txState;

}rbuart_t;
/*Macro defines -----------------------------------------------------*/

/*Function prototype ------------------------------------------------*/
/**
 * @brief funcion para inicializar el buffer circular para funcionar con uart
 * @param UARTx: Puntero al uart utilizarse
 * @param bufferData: puntero para los datos del buffer circular
 * @param size: tamaño maximo del puntero de datos
 * @return RBUART_Result_t
 */
#if defined(USE_HAL_DRIVER)
RBUART_Result_t rbuart_init(rbuart_t *rb, UART_HandleTypeDef *UARTx, void* buffdata, size_t size);
#else
RBUART_Result_t rbuart_init(rbuart_t *rb, USART_TypeDef *UARTx, void* buffdata, size_t size);
#endif
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
/**
 * @brief funcion para enviar datos
 * @param rb: buffer utilizado para enviar datos
 * @param pData: puntero a los datos a enviar
 * @param size: tamaño de datos a enviar
 */
int32_t rbuart_send(rbuart_t *rb, uint8_t *pData, size_t size);
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


#endif /* RBUART_RBUART_H_ */
