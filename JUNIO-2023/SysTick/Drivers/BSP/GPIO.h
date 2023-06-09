/*
 * GPIO.h
 *
 *  Created on: 16 jun. 2023
 *      Author: jeffr
 */

#ifndef BSP_GPIO_H_
#define BSP_GPIO_H_

/*Includes ------------------------------------------*/
#include "stm32f4xx.h"
#include <stdbool.h>
/*Typedef -----------------------------------------------------*/
typedef enum{
	GPIO_PIN_0 = 1,			//0x1   //1
	GPIO_PIN_1 = 1<<1,		//0x2	//10
	GPIO_PIN_2 = 1<<2,		//0x4	//100
	GPIO_PIN_3 = 1<<3,		//0x8	//1000
	GPIO_PIN_4 = 1<<4,		//0x10  //10000
	GPIO_PIN_5 = 1<<5,
	GPIO_PIN_6 = 1<<6,
	GPIO_PIN_7 = 1<<7,
	GPIO_PIN_8 = 1<<8,
	GPIO_PIN_9 = 1<<9,
	GPIO_PIN_10 = 1<<10,
	GPIO_PIN_11 = 1<<11,
	GPIO_PIN_12 = 1<<12,
	GPIO_PIN_13 = 1<<13,
	GPIO_PIN_14 = 1<<14,
	GPIO_PIN_15 = 1<<15
}GPIO_Pin_t;

typedef enum{
	GPIO_PIN_RESET,
	GPIO_PIN_SET
}GPIO_PinState_t;

typedef enum{
	GPIO_MODE_INPUT = 0,
	GPIO_MODE_OUTPUT = 0x1,
	GPIO_MODE_AF	= 0x2,
	GPIO_MODE_ANALOG = 0x3
}GPIO_PinMode;

typedef enum{
	GPIO_OT_PP = 0x0,
	GPIO_OT_OP = 0x1
}GPIO_OType_t;


typedef enum{
	GPIO_SPEED_LOW = 0x0,
	GPIO_SPEED_MEDIUM = 0x1,
	GPIO_SPEED_HIGH	= 0x2,
	GPIO_SPEED_VHIGH = 0x3
}GPIO_Speed_t;

typedef enum{
	GPIO_PU_NONE = 0x0,
	GPIO_PU = 0x1,
	GPIO_PD = 0x2
}GPIO_PU_t;

typedef struct{
	GPIO_Pin_t pin;
	GPIO_PinMode mode;
	GPIO_OType_t outputType;
	GPIO_Speed_t speed;
	GPIO_PU_t pullup;
	uint8_t AF;
}GPIO_ConfigTypedef_t;
/*Defines -----------------------------------------------------*/
#define GPIO_MODE 	0x3U

bool BSP_PinRead(GPIO_TypeDef *P, GPIO_Pin_t pin);

void BSP_PinWrite(GPIO_TypeDef *P, GPIO_Pin_t pin, GPIO_PinState_t val);

void BSP_PinInit(GPIO_TypeDef *P,GPIO_ConfigTypedef_t *config);

#endif /* BSP_GPIO_H_ */
