/*
 * App.c
 *
 *  Created on: Jul 11, 2023
 *      Author: jeffr
 */
#include "gpio.h"
#include "main.h"
#include "cmsis_os.h"
#include "string.h"
#include <stdio.h>
/*Typedef ----------------------------------------------------------------*/
typedef enum{
	SYSTEM_SENSOR_FAIL = 1,
	SYSTEM_DATA_READY = 1<<1,
	SYSTEM_LCD_FAIL		= 1<<2
}SystemFlag_t;
/*Extern variables -------------------------------------------------------*/
extern osThreadId LCDHandle;
extern osThreadId SensorHandle;
extern osThreadId InputHandle;
extern osThreadId ControlHandle;
extern osMessageQId SensorQueueHandle;
extern osMessageQId LCDQueueHandle;
extern osSemaphoreId DataReadyHandle;
extern osSemaphoreId SensorDataReadyHandle;

osPoolDef(MemPool, 5, SensorData_t);
osPoolId MemPool;

extern EventGroupHandle_t systemFlag;
/**
* @brief Function implementing the Sensor thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Sensor_Task */
void Sensor_Task(void const * argument)
{
	float temp;
	float hum;
	SensorData_t *data;

	uint8_t count = 0;

	osDelay(100);
	xEventGroupSetBits(systemFlag, SYSTEM_DATA_READY);
  /* USER CODE BEGIN Sensor_Task */
  /* Infinite loop */
  for(;;)
  {
	  //lectura de sensores
	  count += 1;
	  temp = count - 3;
	  hum = count + 1;

	  xEventGroupSetBits(systemFlag, SYSTEM_SENSOR_FAIL);
	  //procesar

	  //envia
	  data = osPoolAlloc(MemPool);
	  //osMessagePut(SensorQueueHandle, info, millisec);
	  data->hum = hum;
	  data->temp = temp;
	  osMessagePut(SensorQueueHandle, (uint32_t)data, osWaitForever);

	  osDelay(100);
  }
  /* USER CODE END Sensor_Task */
}

/* USER CODE BEGIN Header_Input_Task */
/**
* @brief Function implementing the Input thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Input_Task */
void Input_Task(void const * argument)
{
	SensorData_t *data;
	SensorData_t rxData;
	osEvent evt;
  /* USER CODE BEGIN Input_Task */
	xEventGroupWaitBits(systemFlag, SYSTEM_DATA_READY, pdTRUE, pdTRUE, osWaitForever);
  /* Infinite loop */
  for(;;)
  {
    evt = osMessageGet(SensorQueueHandle, 100);
    if(evt.status == osEventMessage){
    	data = (SensorData_t *)evt.value.p;
    	memcpy(&rxData, data, sizeof(SensorData_t));
    	osPoolFree(MemPool, data);
    	//procesar este dato
    	printf("temp rx->%lu\r\n", (uint32_t)rxData.temp);
    	printf("hum rx->%lu\r\n", (uint32_t)rxData.hum);
    }
  }
  /* USER CODE END Input_Task */
}

/* USER CODE BEGIN Header_Control_Task */
/**
* @brief Function implementing the Control thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Control_Task */
void Control_Task(void const * argument)
{
	EventBits_t sys;
  /* USER CODE BEGIN Control_Task */
  /* Infinite loop */
  for(;;)
  {
	  sys = xEventGroupGetBits(systemFlag);
	  if(sys & SYSTEM_SENSOR_FAIL){
		  //todo

	  }

	  osDelay(100);
  }
  /* USER CODE END Control_Task */
}