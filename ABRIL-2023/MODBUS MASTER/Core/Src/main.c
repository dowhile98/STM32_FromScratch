/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
#include "main.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "lwbtn.h"
#include "lwbtn_opts.h"
#include "lwprintf.h"
#include "lwrb.h"
#include "App.h"
#include "nanomodbus.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef enum{
	BUTTON_1 = 0,
	BUTTON_2,
	BUTTON_3,
	BUTTON_4,
	BUTTON_5
}Button_Enum_t;


typedef struct{
	GPIO_TypeDef *BTGPIO;
	uint16_t BTPin;
	Button_Enum_t buttonNum;
}Button_Phy_t;

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
Button_Phy_t SW1 = {
		.BTGPIO = SW1_GPIO_Port,
		.BTPin = SW1_Pin,
		.buttonNum = BUTTON_1
};
Button_Phy_t SW2 = {
		.BTGPIO = SW2_GPIO_Port,
		.BTPin = SW2_Pin,
		.buttonNum = BUTTON_2
};
lwbtn_btn_t btns[2] = {
		{.arg = (void*) &SW1},
		{.arg = (void*) &SW2}
};

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
static uint8_t prv_btn_get_state(struct lwbtn* lw, struct lwbtn_btn* btn);

static void
prv_btn_event(struct lwbtn* lw, struct lwbtn_btn* btn, lwbtn_evt_t evt) ;
/**
 * \brief           Output function to handle all characters for print operation
 * \param[in]       ch: Character to output
 * \param[in]       p: \ref lwprintf_t handle
 * \return          ch on success, 0 on failure
 */
static int
lwprintf_my_out_func(int ch, lwprintf_t* p) {
    uint8_t c = (uint8_t)ch;

    /* Don't print zero */
    if (c == '\0') {
        return ch;
    }
    ITM_SendChar(ch);
    return ch;
}
void
my_buff_evt_fn(lwrb_t* buff, lwrb_evt_type_t type, size_t len){
    switch (type) {
        case LWRB_EVT_RESET:
            lwprintf_printf("[EVT] Buffer reset event!\r\n");
            break;
        case LWRB_EVT_READ:
            lwprintf_printf("[EVT] Buffer read event: %d byte(s)!\r\n", (int)len);
            break;
        case LWRB_EVT_WRITE:
            lwprintf_printf("[EVT] Buffer write event: %d byte(s)!\r\n", (int)len);
            break;
        default: break;
    }
}

int32_t read_serial(uint8_t* buf, uint16_t count, int32_t byte_timeout_ms, void* arg) {
	uint32_t tickStar = HAL_GetTick();
	do{
		if((HAL_GetTick() - tickStar)>= byte_timeout_ms){
			return 0;
		}
	}
	while(rbuart_get_receiveSize(&rb_rx) < count);
	return rbuart_get_data(&rb_rx, buf, count);
}


int32_t write_serial(const uint8_t* buf, uint16_t count, int32_t byte_timeout_ms, void* arg) {
	(void)byte_timeout_ms;
	return rbuart_send(&rb_tx, (uint8_t*)buf, count);
}
// The server address
#define RTU_SERVER_ADDRESS 1

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
  lwprintf_init(lwprintf_my_out_func);
  lwbtn_init_ex(NULL, btns, sizeof(btns) / sizeof(btns[0]), prv_btn_get_state, prv_btn_event);

  app_init();

  nmbs_platform_conf platform_conf;
  platform_conf.transport = NMBS_TRANSPORT_RTU;
  platform_conf.read = read_serial;
  platform_conf.write = write_serial;
  /* USER CODE END 2 */
  nmbs_t nmbs;
  nmbs_error err = nmbs_client_create(&nmbs, &platform_conf);
  if (err != NMBS_ERROR_NONE)
	  Error_Handler();
  nmbs_set_read_timeout(&nmbs, 1000);
  nmbs_set_byte_timeout(&nmbs, 100);

  nmbs_set_destination_rtu_address(&nmbs, RTU_SERVER_ADDRESS);
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  nmbs_bitfield coils = {0};
	  nmbs_bitfield_write(coils, 0, 1);
	  nmbs_bitfield_write(coils, 1, 1);
	  err = nmbs_write_multiple_coils(&nmbs, 64, 2, coils);
	  HAL_Delay(1000);
//	  if (err != NMBS_ERROR_NONE)
//		  Error_Handler();

	  // Read 3 coils from address 64
	  nmbs_bitfield_reset(coils);    // Reset whole bitfield to zero
	  err = nmbs_read_coils(&nmbs, 64, 3, coils);
	  HAL_Delay(1000);
//	  if (err != NMBS_ERROR_NONE)
//		  Error_Handler();

	  // Write 2 holding registers at address 26
	  uint16_t w_regs[2] = {123, 124};
	  err = nmbs_write_multiple_registers(&nmbs, 26, 2, w_regs);
	  HAL_Delay(1000);
//	  if (err != NMBS_ERROR_NONE)
//		  Error_Handler();

	  // Read 2 holding registers from address 26
	  uint16_t r_regs[2];
	  err = nmbs_read_holding_registers(&nmbs, 26, 2, r_regs);

//	  if (err != NMBS_ERROR_NONE)
//	      Error_Handler();
	  HAL_Delay(1000);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
static uint8_t prv_btn_get_state(struct lwbtn* lw, struct lwbtn_btn* btn){
	Button_Phy_t *BTN_PHY = (Button_Phy_t*)btn->arg;
	Button_Enum_t button = BTN_PHY->buttonNum;
	uint8_t state = 0;
	/*read button --------------------------------------------------------------------------*/
	if(button == BUTTON_1){
		state = (BTN_PHY->BTGPIO->IDR & BTN_PHY->BTPin) ? 1 : 0;
	}else if(button == BUTTON_2){
		state = (BTN_PHY->BTGPIO->IDR & BTN_PHY->BTPin) ?  0: 1;
	}
	return state;
}

static void prv_btn_event(struct lwbtn* lw, struct lwbtn_btn* btn, lwbtn_evt_t evt) {
	Button_Enum_t button = ((Button_Phy_t*)btn->arg)->buttonNum;
	(void)lw;
	uint8_t event = evt;
	if(button == BUTTON_1){
		switch(event){
		case LWBTN_EVT_ONPRESS:
			lwprintf_printf("button is onpressed\r\n");
			HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
			break;
		case LWBTN_EVT_ONRELEASE:
			lwprintf_printf("button is onrelease\r\n");
			HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
			break;
		case LWBTN_EVT_ONCLICK:
			lwprintf_printf("button clicked: %u\r\n", btn->click.cnt);
			break;
#if (LWBTN_CFG_USE_KEEPALIVE == 1)
		case LWBTN_EVT_KEEPALIVE:
			break;
#endif
		}
	}else if(BUTTON_2){
		//todo
	}
	return;
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
