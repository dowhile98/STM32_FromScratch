/*
 * AT_Command_Parse.h
 *
 *  Created on: 22 mar. 2023
 *      Author: jeffr
 */

#ifndef COMPONENTS_AT_COMMAND_PARSE_H_
#define COMPONENTS_AT_COMMAND_PARSE_H_

/*Includes --------------------------------------------*/
#include "delay.h"
#include "button.h"
#include "stm32f4xx.h"
#include <stdbool.h>
#include "lwrb/lwrb.h"
#include <string.h>
/*Typedef --------------------------------------------*/
typedef enum{
	CMD_NONE,
	CMD_AT,
	CMD_ID,
	CMD_PAC,
	CMD_V
}CMD_List_t;
typedef struct{
	lwrb_t buff;
	uint8_t buff_data[1024];
	CMD_List_t ACTIV_CMD;
	uint32_t ticks;
}AT_CMD_Parse_t;


typedef enum{
	AT_DEVICE_ERR,
	AT_DEVICE_OK,
	AT_DEVICE_BUSY
}AT_DeviceState_t;

typedef enum{
	DEVICE_ERR,
	DEVICE_AT_OK,
	DEVICE_ID_OK,
	DEVICE_PAC_OK,
	DEVICE_V_OK,
	DEVICE_WAIT
}AT_DeviceResponse_t;
/*Defines --------------------------------------------*/
#define AT		"AT\r\n"
#define VOLT	"AT$V\r\n"
#define ID		"AT$I=10\r\n"
#define PAC		"AT$I=11\r\n"
/*Extern definition ----------------------------------*/

/*Function prototype ---------------------------------*/
/**
 * @brief inicializar la instancia para el manejo del dispositivo por comandos AT
 */
void AT_Device_Init(AT_CMD_Parse_t *dev );
/**
 * @brief incrementar la base de tiempo
 */
void AT_Device_TickInc(AT_CMD_Parse_t *dev);

/**
 * @brief devuelve el valor de la base de tiempo
 */
uint32_t AT_Devic_Ticks(AT_CMD_Parse_t *dev);
/**
 * @brief envia commandos al dispositivo
 */
AT_DeviceState_t AT_Device_SendComand(AT_CMD_Parse_t *dev, CMD_List_t cmd);


/**
 * @brief funcion para verificar la respuesta del dispositivo
 */
AT_DeviceResponse_t AT_DeviceUpdate(AT_CMD_Parse_t *dev);

#endif /* COMPONENTS_AT_COMMAND_PARSE_H_ */
