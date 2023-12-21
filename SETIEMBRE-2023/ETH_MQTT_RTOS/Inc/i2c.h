/*
 * i2c.h
 *
 *  Created on: Oct 31, 2023
 *      Author: jeffr
 */

#ifndef I2C_H_
#define I2C_H_
#ifdef __cplusplus
extern "C"{
#endif
/*Includes -----------------------------------------------------*/
#include "stm32f4xx.h"
#include "delay.h"
#include "Config.h"
#include <stdlib.h>

/*Defines ------------------------------------------------------*/
#define I2C1_SDA			B, 7
#define I2C1_SCL			B, 6
#define I2C1_INT			B, 4


/*Function prototype ------------------------------------------*/
void I2C1_Init(void);
uint8_t i2c_reg_write(I2C_TypeDef *I2C, uint8_t SlaveADDR, uint8_t regAddr, uint8_t *pData, uint16_t len, uint32_t timeout);
uint8_t i2c_reg_read(I2C_TypeDef *I2C, uint8_t SlaveADDR, uint8_t regAddr, uint8_t *pData, uint16_t len, uint32_t timeout);


#ifdef __cplusplus
}
#endif

#endif /* I2C_H_ */