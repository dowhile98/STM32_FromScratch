/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
EventGroupHandle_t systemFlag;
/* USER CODE END Variables */
osThreadId LCDHandle;
osThreadId SensorHandle;
osThreadId InputHandle;
osThreadId ControlHandle;
osMessageQId SensorQueueHandle;
osMessageQId LCDQueueHandle;
osSemaphoreId DataReadyHandle;
osSemaphoreId SensorDataReadyHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void LCD_Task(void const * argument);
void Sensor_Task(void const * argument);
void Input_Task(void const * argument);
void Control_Task(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
	systemFlag = xEventGroupCreate();
  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* Create the semaphores(s) */
  /* definition and creation of DataReady */
  osSemaphoreDef(DataReady);
  DataReadyHandle = osSemaphoreCreate(osSemaphore(DataReady), 1);

  /* definition and creation of SensorDataReady */
  osSemaphoreDef(SensorDataReady);
  SensorDataReadyHandle = osSemaphoreCreate(osSemaphore(SensorDataReady), 1);

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* definition and creation of SensorQueue */
  osMessageQDef(SensorQueue, 5, SensorData_t);
  SensorQueueHandle = osMessageCreate(osMessageQ(SensorQueue), NULL);

  /* definition and creation of LCDQueue */
  osMessageQDef(LCDQueue, 2, LCDQueue_t);
  LCDQueueHandle = osMessageCreate(osMessageQ(LCDQueue), NULL);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of LCD */
  osThreadDef(LCD, LCD_Task, osPriorityNormal, 0, 128);
  LCDHandle = osThreadCreate(osThread(LCD), NULL);

  /* definition and creation of Sensor */
  osThreadDef(Sensor, Sensor_Task, osPriorityAboveNormal, 0, 128);
  SensorHandle = osThreadCreate(osThread(Sensor), NULL);

  /* definition and creation of Input */
  osThreadDef(Input, Input_Task, osPriorityNormal, 0, 128);
  InputHandle = osThreadCreate(osThread(Input), NULL);

  /* definition and creation of Control */
  osThreadDef(Control, Control_Task, osPriorityLow, 0, 128);
  ControlHandle = osThreadCreate(osThread(Control), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_LCD_Task */
/**
  * @brief  Function implementing the LCD thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_LCD_Task */
__weak void LCD_Task(void const * argument)
{
  /* USER CODE BEGIN LCD_Task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END LCD_Task */
}

/* USER CODE BEGIN Header_Sensor_Task */
/**
* @brief Function implementing the Sensor thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Sensor_Task */
__weak void Sensor_Task(void const * argument)
{
  /* USER CODE BEGIN Sensor_Task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
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
__weak void Input_Task(void const * argument)
{
  /* USER CODE BEGIN Input_Task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
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
__weak void Control_Task(void const * argument)
{
  /* USER CODE BEGIN Control_Task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Control_Task */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */
