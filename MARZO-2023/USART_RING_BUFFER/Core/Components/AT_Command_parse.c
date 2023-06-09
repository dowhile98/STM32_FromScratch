/*
 * AT_Command_parse.c
 *
 *  Created on: 22 mar. 2023
 *      Author: jeffr
 */
#include "AT_Command_Parse.h"
/*Define -------------------------------------------*/

/*Globla variables ----------------------------------*/

/**
 * @brief inicializar la instancia para el manejo del dispositivo por comandos AT
 */
void AT_Device_Init(AT_CMD_Parse_t *dev){
	//inicializar el buffer
	lwrb_init(&(dev->buff), dev->buff_data, 1024);
	//comando activo
	dev->ACTIV_CMD = CMD_NONE;
	return;
}


/**
 * @brief incrementar la base de tiempo
 */
void AT_Device_TickInc(AT_CMD_Parse_t *dev){
	dev->ticks += 1;
}

/**
 * @brief devuelve el valor de la base de tiempo
 */
uint32_t AT_Devic_Ticks(AT_CMD_Parse_t *dev){
	return dev->ticks;
}

/**
 * @brief envia commandos al dispositivo
 */
AT_DeviceState_t AT_Device_SendComand(AT_CMD_Parse_t *dev, CMD_List_t cmd){

	dev->ACTIV_CMD = cmd;
	lwrb_reset(&dev->buff);			//reinicia el buffer
	switch(cmd){
	case CMD_AT:
		//se envía el comando AT
		printf("%s", AT);				//OK\r\n
		break;
	case CMD_ID:
		printf("%s", ID);
		break;							//ABSCDDA123\r\n
	case CMD_PAC:
		printf("%s", PAC);				//010201233232\r\n
		break;
	case CMD_V:
		printf("%s", VOLT);				//2345\r\n0\r\n
		break;
	}
	return AT_DEVICE_OK ;
}


/**
 * @brief funcion para verificar la respuesta del dispositivo
 */
AT_DeviceResponse_t AT_DeviceUpdate(AT_CMD_Parse_t *dev){
	uint8_t ch;
	char data[30] = {0};
	if(lwrb_get_full(&dev->buff) > 0){
		lwrb_peek(&dev->buff, lwrb_get_full(&dev->buff) - 1 , &ch, 1);
		switch(dev->ACTIV_CMD){
		case CMD_AT:
			if(ch == '\n'){
				//repuesta
				lwrb_read(&dev->buff, data, lwrb_get_full(&dev->buff));
				if(strcmp(data, "OK\r\n") == 0){
					dev->ACTIV_CMD = CMD_NONE;
					return DEVICE_AT_OK;
				}else{
					return DEVICE_ERR;
				}
			}
			break;
		case CMD_ID:
			break;
		case CMD_PAC:
			break;
		case CMD_V:
			break;
		}
	}
	return DEVICE_WAIT;
}


