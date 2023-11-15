/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    app_threadx.c
  * @author  MCD Application Team
  * @brief   ThreadX applicative file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 STMicroelectronics.
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
#include "app_threadx.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "main.h"
#include <stdio.h>
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
/* USER CODE BEGIN PV */
TX_THREAD mainTask;
TX_THREAD buttonTask;

static CHAR button_stack[1024];
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */


void main_thread_entry(ULONG param){
	printf("[MAIN] Main thread init ......");
	for(;;){
		printf("Main task running...");
		tx_thread_sleep(100);
	}
}

void button_thread_entry(ULONG param){


	printf("[BUTTON] button thread init ......");
	for(;;){
		printf("button task running...");
		tx_thread_sleep(150);
	}
}
/* USER CODE END PFP */

/**
  * @brief  Application ThreadX Initialization.
  * @param memory_ptr: memory pointer
  * @retval int
  */
UINT App_ThreadX_Init(VOID *memory_ptr)
{
  UINT ret = TX_SUCCESS;
  TX_BYTE_POOL *byte_pool = (TX_BYTE_POOL*)memory_ptr;

  /* USER CODE BEGIN App_ThreadX_Init */
  char * pointer;
  /* USER CODE END App_ThreadX_Init */
  //reserva memoria para el stack de la tarea main
  if(tx_byte_allocate(byte_pool, (VOID **)&pointer, 1024, TX_NO_WAIT) != TX_SUCCESS){

  }

  ret = tx_thread_create(&mainTask,
		  	  	  	  	  "Main Task",
						  main_thread_entry,
						  0,
						  pointer,
						  1024,
						  2,
						  2,
						  TX_NO_TIME_SLICE, TX_AUTO_START);
  if(ret != TX_SUCCESS){

  }

  ret = tx_thread_create(&buttonTask,
  		  	  	  	  	  "Button thread",
  						  button_thread_entry,
  						  0,
  						  button_stack,
  						  1024,
  						  4,
  						  4,
  						  TX_NO_TIME_SLICE, TX_AUTO_START);
  return ret;
}

/**
  * @brief  MX_ThreadX_Init
  * @param  None
  * @retval None
  */
void MX_ThreadX_Init(void)
{
  /* USER CODE BEGIN  Before_Kernel_Start */

  /* USER CODE END  Before_Kernel_Start */

  tx_kernel_enter();

  /* USER CODE BEGIN  Kernel_Start_Error */

  /* USER CODE END  Kernel_Start_Error */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
