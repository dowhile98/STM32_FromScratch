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
typedef    void (*dma_rx_clear_tc_fn)(DMA_TypeDef *);
typedef    void (*dma_rx_clear_ht_fn)(DMA_TypeDef *);
typedef    uint32_t (*dma_rx_is_tc_fn)(DMA_TypeDef *);
typedef    uint32_t (*dma_rx_is_ht_fn)(DMA_TypeDef *);
/**
 *
 */
typedef enum{
	RBUART_OK = 0,
	RBUART_ERROR,
	RBUART_TXCPLT,
	RBUART_RXCPLT,
}RBUART_Result_t;

/**
 * @dma data
 */
typedef struct{
	uint8_t dma_buffer[128];
	uint16_t len;
	size_t old_pos;
	size_t pos;
}Data_t;
/**
 *
 */
typedef struct{
	/**
	 * pointer for hardware instance
	 */
	USART_TypeDef *rbuart;
	DMA_TypeDef *dma;
	uint32_t stream;
	uint32_t channel;
	dma_rx_clear_ht_fn clear_ht;
	dma_rx_clear_tc_fn clear_tc;
	dma_rx_is_ht_fn is_ht;
	dma_rx_is_tc_fn is_tc;
	/**
	 * dma data
	 */
	Data_t data;
	/**
	 * ring buffer
	 */
	lwrb_t buff;
	/**
	 * irqn
	 */
	IRQn_Type stream_irq;
	IRQn_Type usart_irq;
	uint8_t prio;
}rbuart_t;
/*Macro defines -----------------------------------------------------*/
/**
 * \brief           Calculate length of statically allocated array
 */
#define ARRAY_LEN(x)            (sizeof(x) / sizeof((x)[0]))
/*Function prototype ------------------------------------------------*/
/**
 * @brief funcion para inicializar el buffer circular para funcionar con uart
 * @param bufferData: puntero para los datos del buffer circular
 * @param size: tamaño maximo del puntero de datos
 * @return RBUART_Result_t
 */
RBUART_Result_t rbuart_tx_init(rbuart_t *rb, void* buffdata, size_t size);

RBUART_Result_t rbuart_rx_init(rbuart_t *rb, void* buffdata, size_t size);
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
RBUART_Result_t rbuart_rx_callback(rbuart_t *rb);
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

void rbuart_usart_IDLE_callback(rbuart_t *rb);


#endif /* RBUART_RBUART_H_ */
