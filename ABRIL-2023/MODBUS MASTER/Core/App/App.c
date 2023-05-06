/*
 * App.c
 *
 *  Created on: Apr 22, 2023
 *      Author: jeffr
 */

/*includes ------------------------------------------------------*/
#include "main.h"
#include "rbuart.h"
#include "usart.h"
/*defines -------------------------------------------------------*/
#define MAX_RX_SIZE			100
#define MAX_TX_SIZE			100
/*Global variables ----------------------------------------------*/
rbuart_t rb_rx;
rbuart_t rb_tx;
uint8_t rx_data[MAX_RX_SIZE];
uint8_t tx_data[MAX_TX_SIZE];
/*Function definition -------------------------------------------*/
void app_init(void){
	/*Init*/
	rbuart_init(&rb_tx, &huart2, tx_data, MAX_TX_SIZE);
	rbuart_init(&rb_rx, &huart2, rx_data, MAX_RX_SIZE);
	rbuart_start_receive(&rb_rx);

	return;
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
	rbuart_tx_callback(&rb_tx);
	return;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){

	rbuart_rx_callback(&rb_rx, &rb_rx.rawByte, 1);
	return;
}
