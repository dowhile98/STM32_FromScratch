/*
 * rbuart.c
 *
 *  Created on: Apr 22, 2023
 *      Author: jeffr
 */

/*Includes ------------------------------------------------------------------------*/
#include "rbuart.h"
/*Private function ----------------------------------------------------------------*/
static void  usart_process_data(rbuart_t *rb, const void* data, size_t len){
	lwrb_write(&rb->buff, data, len);
}

static void usart_rx_check(rbuart_t *rb){
	 rb->data.pos = ARRAY_LEN(rb->data.dma_buffer) - LL_DMA_GetDataLength(rb->dma, rb->stream);
	 if(rb->data.pos != rb->data.old_pos){
		 if(rb->data.pos > rb->data.old_pos){
			 usart_process_data(rb,&rb->data.dma_buffer[rb->data.old_pos], rb->data.pos - rb->data.old_pos);
		 }else{
			 usart_process_data(rb,&rb->data.dma_buffer[rb->data.old_pos], ARRAY_LEN(rb->data.dma_buffer) - rb->data.old_pos);
			 if(rb->data.pos >0){
				 usart_process_data(rb,&rb->data.dma_buffer[0], rb->data.pos);
			 }
		 }
		 rb->data.old_pos = rb->data.pos;                          /* Save current position as old for next transfers */
	 }
	 return;
}
uint8_t
usart_start_tx_dma_transfer(rbuart_t *rb){
    uint32_t primask;
    uint8_t started = 0;
    primask = __get_PRIMASK();
    __disable_irq();
    if((rb->data.len == 0) && (rb->data.len = lwrb_get_linear_block_read_length(&rb->buff)) > 0){
    	 LL_DMA_DisableStream(rb->dma, rb->stream);
    	 /* Clear all flags */
    	 rb->clear_ht(rb->dma);
    	 rb->clear_tc(rb->dma);
    	 /* Prepare DMA data and length */
         LL_DMA_SetDataLength(rb->dma, rb->stream, rb->data.len);
         LL_DMA_SetMemoryAddress(rb->dma, rb->stream, (uint32_t)lwrb_get_linear_block_read_address(&rb->buff));

         /* Start transfer */

		LL_DMA_EnableStream(rb->dma, rb->stream);
		started = 1;
    }
    __set_PRIMASK(primask);
    return started;
}
/*Function definition -------------------------------------------------------------*/
/**
 * @brief funcion para inicializar el buffer circular para funcionar con uart
 * @param UARTx: Puntero al uart utilizarse
 * @param bufferData: puntero para los datos del buffer circular
 * @param size: tamaño maximo del puntero de datos
 * @return RBUART_Result_t
 */
RBUART_Result_t rbuart_tx_init(rbuart_t *rb, void* buffdata, size_t size){
	/**
	 * DMA
	 */
    LL_DMA_SetChannelSelection(rb->dma, rb->stream, rb->channel);
    LL_DMA_SetDataTransferDirection(rb->dma, rb->stream, LL_DMA_DIRECTION_MEMORY_TO_PERIPH);
    LL_DMA_SetStreamPriorityLevel(rb->dma, rb->stream, LL_DMA_PRIORITY_HIGH);
    LL_DMA_SetMode(rb->dma, rb->stream, LL_DMA_MODE_NORMAL);
    LL_DMA_SetPeriphIncMode(rb->dma, rb->stream, LL_DMA_PERIPH_NOINCREMENT);
    LL_DMA_SetMemoryIncMode(rb->dma, rb->stream, LL_DMA_MEMORY_INCREMENT);
    LL_DMA_SetPeriphSize(rb->dma, rb->stream, LL_DMA_PDATAALIGN_BYTE);
    LL_DMA_SetMemorySize(rb->dma, rb->stream, LL_DMA_MDATAALIGN_BYTE);
    LL_DMA_DisableFifoMode(rb->dma, rb->stream);
    LL_DMA_SetPeriphAddress(rb->dma, rb->stream, LL_USART_DMA_GetRegAddr(rb->rbuart));

    /* Enable HT & TC interrupts */
    LL_DMA_EnableIT_TC(rb->dma, rb->stream);

    NVIC_SetPriority(rb->stream_irq, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), rb->prio, 0));
    NVIC_EnableIRQ(rb->stream_irq);

    /**
     * USART
     */
    LL_USART_EnableDMAReq_TX(rb->rbuart);

    /* Enable USART and DMA */
    LL_USART_Enable(rb->rbuart);

    if(lwrb_init(&rb->buff, buffdata, size) == 1){
    	return RBUART_OK;
    }
	return RBUART_ERROR;
}

RBUART_Result_t rbuart_rx_init(rbuart_t *rb, void* buffdata, size_t size){
	/**
	 * DMA
	 */
    LL_DMA_SetChannelSelection(rb->dma, rb->stream, rb->channel);
    LL_DMA_SetDataTransferDirection(rb->dma, rb->stream, LL_DMA_DIRECTION_PERIPH_TO_MEMORY);
    LL_DMA_SetStreamPriorityLevel(rb->dma, rb->stream, LL_DMA_PRIORITY_HIGH);
    LL_DMA_SetMode(rb->dma, rb->stream, LL_DMA_MODE_CIRCULAR);
    LL_DMA_SetPeriphIncMode(rb->dma, rb->stream, LL_DMA_PERIPH_NOINCREMENT);
    LL_DMA_SetMemoryIncMode(rb->dma, rb->stream, LL_DMA_MEMORY_INCREMENT);
    LL_DMA_SetPeriphSize(rb->dma, rb->stream, LL_DMA_PDATAALIGN_BYTE);
    LL_DMA_SetMemorySize(rb->dma, rb->stream, LL_DMA_MDATAALIGN_BYTE);
    LL_DMA_DisableFifoMode(rb->dma, rb->stream);
    LL_DMA_SetPeriphAddress(rb->dma, rb->stream, LL_USART_DMA_GetRegAddr(rb->rbuart));
    LL_DMA_SetMemoryAddress(rb->dma, rb->stream, (uint32_t)rb->data.dma_buffer);
    LL_DMA_SetDataLength(rb->dma, rb->stream, ARRAY_LEN(rb->data.dma_buffer));

    /* Enable HT & TC interrupts */
    LL_DMA_EnableIT_HT(rb->dma, rb->stream);
    LL_DMA_EnableIT_TC(rb->dma, rb->stream);

    NVIC_SetPriority(rb->stream_irq, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 5, 0));
    NVIC_EnableIRQ(rb->stream_irq);

    /**
     * USART
     */
    LL_USART_ConfigAsyncMode(rb->rbuart);
    LL_USART_EnableDMAReq_RX(rb->rbuart);
    LL_USART_EnableIT_IDLE(rb->rbuart);

    /* USART interrupt */
    NVIC_SetPriority(rb->usart_irq, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 5, 1));
    NVIC_EnableIRQ(rb->usart_irq);

    /* Enable USART and DMA */
    LL_DMA_EnableStream(rb->dma, rb->stream);
    LL_USART_Enable(rb->rbuart);

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

	if (LL_DMA_IsEnabledIT_TC(rb->dma, rb->stream) && rb->is_tc(rb->dma)){
		rb->clear_tc(rb->dma);
		//todo
		lwrb_skip(&rb->buff, rb->data.len);
		rb->data.len = 0;
		usart_start_tx_dma_transfer(rb);
	}
	return RBUART_OK;
}
/**
 * @brief callback para recibir datos a un buffer circular
 * @param rb: puntero al buffer circular
 */
RBUART_Result_t rbuart_rx_callback(rbuart_t *rb){
	/**
	 * half transfer complet
	 */
	if(LL_DMA_IsEnabledIT_HT(rb->dma, rb->stream) && rb->is_ht(rb->dma)){
		  rb->clear_ht(rb->dma); /* Clear half-transfer complete flag */
		  //todo
		  usart_rx_check(rb);
	}
	/**
	 * transfer complet
	 */
	if(LL_DMA_IsEnabledIT_TC(rb->dma, rb->stream) && rb->is_tc(rb->dma)){
		rb->clear_tc(rb->dma);
		//todo
		usart_rx_check(rb);
	}
	return RBUART_ERROR;
}

void rbuart_usart_IDLE_callback(rbuart_t *rb){
	if(LL_USART_IsEnabledIT_IDLE(rb->rbuart) && LL_USART_IsActiveFlag_IDLE(rb->rbuart)){
		LL_USART_ClearFlag_IDLE(rb->rbuart);
		usart_rx_check(rb);
	}
}
/**
 * @brief funcion para enviar datos
 * @param rb: buffer utilizado para enviar datos
 * @param pData: puntero a los datos a enviar
 * @param size: tamaño de datos a enviar
 */
RBUART_Result_t rbuart_send(rbuart_t *rb, uint8_t *pData, size_t size){
	lwrb_write(&rb->buff, pData, size);   /* Write data to transmit buffer */
	usart_start_tx_dma_transfer(rb);
	return RBUART_OK;
}

/**
 * @brief funcion que inicia la recepcion de datos por interrupcion en el buffer circular
 * @param rb: puntero al buffer circular
 */
RBUART_Result_t rbuart_start_receive(rbuart_t *rb){
	LL_DMA_EnableStream(rb->dma, rb->stream);
	return RBUART_OK;
}
/**
 * @brief funcion para terminar de recbiir los datos
 */
RBUART_Result_t rbuart_stop_receive(rbuart_t *rb){
	LL_DMA_DisableStream(rb->dma, rb->stream);
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
