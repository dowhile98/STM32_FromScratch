/*
 * i2c.c
 *
 *  Created on: Oct 31, 2023
 *      Author: jeffr
 */
#include "i2c.h"

void I2C1_Init(void){
	uint32_t temp;
	RCC->AHB1ENR |= GPIOX_CLOCK(I2C1_SCL);
	GPIOX_MODER(MODE_ALTER, I2C1_SCL);
	GPIOX_MODER(MODE_ALTER, I2C1_SDA);
	GPIOB->OTYPER |= GPIO_OTYPER_OT7 | GPIO_OTYPER_OT6;
	GPIOX_OSPEEDR(MODE_SPD_VHIGH, I2C1_SCL);
	GPIOX_OSPEEDR(MODE_SPD_VHIGH, I2C1_SDA);//VERY HIGH SPEED
	GPIOX_PUPDR(MODE_PU_UP, I2C1_SCL);
	GPIOX_PUPDR(MODE_PU_UP, I2C1_SDA);		//Habilita las resitencias pull up internas
	GPIOX_AFR(4, I2C1_SCL);
	GPIOX_AFR(4, I2C1_SDA);
	//CONFIGURAR EL I2C1
	RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;
	//RESET
	I2C1->CR1 |= I2C_CR1_SWRST;
	I2C1->CR1 &=~ I2C_CR1_SWRST;
	/**
	 * PCLK1
	 */
	temp = SystemCoreClock / 1000000;
	I2C1->CR2 &=~ (I2C_CR2_FREQ);
	I2C1->CR2 |= (temp & 0x3F);
	/**
	 * TIMING (CCR)
	 * ->STANDART MODE = 100KHz
	 * CCR = PCLK1 / (2 * 100000)
	 * ->FAST MODE = 400KHz
	 * DUTY CYCLE (DUTY->CCR)
	 * DUTY == 0
	 * CCR = PCLK1 / (3 * 400000)
	 * DUTY == 1
	 * CCR = PCLK1 / (25 * 400000)
	 * ->FAST MODE PLUS
	 */
	temp = 16E+6 / (3 * 400E+3);
	I2C1->CCR = temp & 0xFFF;
	I2C1->CCR |= I2C_CCR_FS;
	/*Configurar el TRISE*/
	/**
	 * SM
	 * TRISE = PCLK1 / 1000000 + 1
	 * FS
	 * TRISE = (PCLK1 * 300) / (1000000000U) + 1
	 */
	temp = ((16E+6) * 300) / (1000000000U) + 1;
	I2C1->TRISE = temp;
	//DIRECCION ESCLAVA DE NUESTRO I2C1
	I2C1->OAR1 = 0x74;
	//habilitar el bus i2c
	I2C1->CR1 |= I2C_CR1_PE;
	return;
}

uint8_t i2c_reg_write(I2C_TypeDef *I2C, uint8_t SlaveADDR, uint8_t regAddr, uint8_t *pData, uint16_t len, uint32_t timeout){
	uint32_t temp= 0;
	uint32_t ticks = millis();
	if(len <= 0 || pData == NULL){
		return 1;
	}
	//esperar que el bus este desocupado
	do{
		if((millis() - ticks)> timeout){
			return 1;
		}
	}while(I2C->SR2 & I2C_SR2_BUSY);
	//generar la condicion de inicio (star)
	I2C->CR1 |= I2C_CR1_START;
	do{
		if((millis() - ticks)> timeout){
			I2C->CR1 |= I2C_CR1_STOP;
			return 1;
		}
	}while(!(I2C->SR1 & I2C_SR1_SB));

	//enviar la direccion del esclavo
	SlaveADDR = SlaveADDR <<1;					//[A6:A0] [R/W] (W = 0, R = 1)
	SlaveADDR &= ~1;
	I2C->DR = SlaveADDR;
	do{
		if((millis() - ticks)> timeout){
			I2C->CR1 |= I2C_CR1_STOP;
			return 1;
		}
	}while(!(I2C->SR1 & I2C_SR1_ADDR));
	//Limpiar los registros de estado
	temp = I2C->SR1;
	temp = I2C->SR2;
	(void)temp;

	//enviar la direccion de la region
	do{
		if((millis() - ticks)>timeout){
			I2C->CR1 |= I2C_CR1_STOP;
			return 1;
		}
	}while(!(I2C->SR1 & I2C_SR1_TXE));
	I2C->DR = regAddr;

	//enviar los n datos
	while(len>0){
		if(I2C->SR1 & I2C_SR1_TXE){
			I2C->DR = *pData;
			pData++;
			len--;
			if(len == 0){
				break;
			}
		}
		if((millis() - ticks)>timeout){
			I2C->CR1 |= I2C_CR1_STOP;
			return 1;
		}
	}
	//wait
	do{
		if((millis() - ticks)>timeout){
			I2C->CR1 |= I2C_CR1_STOP;
			return 1;
		}
	}while(((I2C->SR1 & I2C_SR1_TXE) == 0) &&((I2C->SR1 & I2C_SR1_BTF) == 0));

	//stop condition
	I2C->CR1 |= I2C_CR1_STOP;
	return 0;
}
uint8_t i2c_reg_read(I2C_TypeDef *I2C, uint8_t SlaveADDR, uint8_t regAddr, uint8_t *pData, uint16_t len, uint32_t timeout){
	uint32_t temp= 0;
	uint32_t ticks = millis();

	if(len <= 0 || pData == NULL){
		return 1;
	}
	//esperar que el bus este desocupado
	do{
		if((millis() - ticks)> timeout){
			return 1;
		}
	}while((I2C->SR2 & I2C_SR2_BUSY));

	//generar la condicion de inicio (star)
	I2C->CR1 |= I2C_CR1_START;
	do{
		if((millis() - ticks)> timeout){
			I2C->CR1 |= I2C_CR1_STOP;
			return 1;
		}
	}while((I2C->SR1 & I2C_SR1_SB)  == 0);

	//enviar la direccion del esclavo
	SlaveADDR = SlaveADDR <<1;					//[A6:A0] [R/W] (W = 0, R = 1)
	SlaveADDR &= ~1;
	I2C->DR = SlaveADDR;
	//I2C->DR = SlaveADDR;

	do{
		if((millis() - ticks)> timeout){
			I2C->CR1 |= I2C_CR1_STOP;
			return 1;
		}
	}while((I2C->SR1 & I2C_SR1_ADDR)  == 0);
	//while((I2C->SR1 & I2C_SR1_ADDR) == 0);

	//Limpiar los registros de estado
	temp = I2C->SR1;
	temp = I2C->SR2;
	(void)temp;

	//enviar la direccion base a leerse
	//enviar la direccion de la region
	do{
		if((millis() - ticks)>timeout){
			I2C->CR1 |= I2C_CR1_STOP;
			return 1;
		}
	}while(!(I2C->SR1 & I2C_SR1_TXE));
	I2C->DR = regAddr;

	//una nueva condicion de inicio
	//wait
	do{
		if((millis() - ticks)>timeout){
			I2C->CR1 |= I2C_CR1_STOP;
			return 1;
		}
	}while(((I2C->SR1 & I2C_SR1_TXE) == 0) && ((I2C->SR1 & I2C_SR1_BTF) == 0));

	//generar la condicion de inicio (star)
	I2C->CR1 |= I2C_CR1_START;
	do{
		if((millis() - ticks)> timeout){
			I2C->CR1 |= I2C_CR1_STOP;
			return 1;
		}
	}while((I2C->SR1 & I2C_SR1_SB)  == 0);
	//enviar la direccion del esclavo

	SlaveADDR |= 1;
	I2C->DR = SlaveADDR;
	do{
		if((millis() - ticks)> timeout){
			I2C->CR1 |= I2C_CR1_STOP;
			return 1;
		}
	}while((I2C->SR1 & I2C_SR1_ADDR)  == 0);

	//Limpiar los registros de estado
	temp = I2C->SR1;
	temp = I2C->SR2;
	(void)temp;

	//leer bytes
	I2C->CR1  |= I2C_CR1_ACK;

	while(len> 0){
		if(len == 1){
			I2C->CR1 &=~ I2C_CR1_ACK;

			do{
				if((millis() - ticks)>timeout){
					I2C1->CR1 |= I2C_CR1_STOP;
					return 1;
				}
			}while((I2C->SR1 & I2C_SR1_RXNE) == 0);

			I2C1->CR1 |= I2C_CR1_STOP;

			//LEER
			*pData = I2C->DR;
			len--;
			break;
		}else{
			//wait
			do{
				if((millis() - ticks)>timeout){
					I2C1->CR1 |= I2C_CR1_STOP;
					return 1;
				}
			}while((I2C->SR1 & I2C_SR1_RXNE) == 0);
			*pData = I2C->DR;
			pData++;
			len--;
		}
	}

	return 0;
}
