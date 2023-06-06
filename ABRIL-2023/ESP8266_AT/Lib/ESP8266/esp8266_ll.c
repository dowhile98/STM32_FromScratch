/**	
   ----------------------------------------------------------------------
    Copyright (c) 2016 Tilen Majerle

    Permission is hereby granted, free of charge, to any person
    obtaining a copy of this software and associated documentation
    files (the "Software"), to deal in the Software without restriction,
    including without limitation the rights to use, copy, modify, merge,
    publish, distribute, sublicense, and/or sell copies of the Software, 
    and to permit persons to whom the Software is furnished to do so, 
    subject to the following conditions:

    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
    AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
    HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
    OTHER DEALINGS IN THE SOFTWARE.
   ----------------------------------------------------------------------
 */
#include "esp8266_ll.h"
#include "main.h"
#include "usart.h"
#include "gpio.h"
#include "stm32f4xx_hal_uart.h"
/**************************************************************************/
/**************************************************************************/
uint8_t ch;
/**************************************************************************/
/*                                                                        */
/*    Edit file name to esp8266_ll.c and edit values for your platform    */
/*                                                                        */
/**************************************************************************/
void USART_RX_INTERRUPT_HANDLER_FUNCTION_NAME(UART_HandleTypeDef *huart);
/**************************************************************************/
/**************************************************************************/

uint8_t ESP8266_LL_USARTInit(uint32_t baudrate) {
	/* Init USART */
	huart1.Instance = USART1;
	huart1.Init.BaudRate = baudrate;
	huart1.Init.WordLength = UART_WORDLENGTH_8B;
	huart1.Init.StopBits = UART_STOPBITS_1;
	huart1.Init.Parity = UART_PARITY_NONE;
	huart1.Init.Mode = UART_MODE_TX_RX;
	huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart1.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&huart1) != HAL_OK)
	{
		Error_Handler();
	}
	HAL_UART_RegisterCallback(&huart1, HAL_UART_RX_COMPLETE_CB_ID, USART_RX_INTERRUPT_HANDLER_FUNCTION_NAME);
#if ESP8266_USE_CTS
    /* Enable RTS pin on MCU as output and set it low */
#endif
	HAL_UART_Receive_IT(&huart1, &ch, 1);
	/* Return 0 = Successful */
	return HAL_OK;
}

uint8_t ESP8266_LL_USARTSend(uint8_t* data, uint16_t count) {
	uint8_t status;
	/* Send data via USART */
	status = HAL_UART_Transmit(&huart1, data, count, 1000);
	/* Return 0 = Successful */
	return status;
}


void ESP8266_LL_SetRTS(uint8_t dir) {
    /* Set RTS direction we require */
    if (dir == ESP_RTS_HIGH) {
        //Set RTS pin high
    	HAL_GPIO_WritePin(ESP_RST_GPIO_Port, ESP_RST_Pin, GPIO_PIN_SET);
    } else {
        //Set RTS pin low
    	HAL_GPIO_WritePin(ESP_RST_GPIO_Port, ESP_RST_Pin, GPIO_PIN_RESET);
    }
}


/* USART receive interrupt handler */
void USART_RX_INTERRUPT_HANDLER_FUNCTION_NAME(UART_HandleTypeDef *huart) {

	/* Get character from USART */
	
	if(huart == &huart1){
		/* Send received character to ESP stack */
		ESP8266_DataReceived(&ch, 1);

		HAL_UART_Receive_IT(huart, &ch, 1);
	}
	
}
