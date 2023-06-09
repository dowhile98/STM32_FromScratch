/*
 * @file W5100_ll_driver.c
 *
 * @date Created on: May 24, 2023
 * @autor Quino B. Jeffry
 */

/**
 * @addtogroup W5100
 * @{
 */

#include "W5100_ll_driver.h"

/**
 * @addtogroup W5100_LL_Driver
 * @{
 */
/**
 * @addtogroup W5100_LL_ExportedFucntion
 * @{
 */

/**
 * @brief recibe un byte por el SPI
 * @note - Esta función envía un byte dummy y lee el byte recibido
 * @note - Esta función es una función de bloqueo por polling
 * @return uint8_t
 */
uint8_t w5100_read_byte(void){
	while(!(LL_SPI_IsActiveFlag_TXE(ETH_SPI)));
	LL_SPI_TransmitData8(ETH_SPI, 0xFF);
	while(!(LL_SPI_IsActiveFlag_RXNE(ETH_SPI)));
	return LL_SPI_ReceiveData8(ETH_SPI);
}

/**
 * @brief Esta función transmite un byte
 * @param byte[in] : byte a ser enviado
 * @note - Esta función tambien limpia la bandera RXNE una vez enviado el byte
 * @note - Esta función es de bloqueo por polling
 */
void w5100_write_byte(uint8_t byte){
	while(!(LL_SPI_IsActiveFlag_TXE(ETH_SPI)));
	LL_SPI_TransmitData8(ETH_SPI, byte);
	while(!(LL_SPI_IsActiveFlag_RXNE(ETH_SPI)));
	LL_SPI_ReceiveData8(ETH_SPI);
}

/**
 * @brief Selecciona el W5100 para la comunicación SPI
 * @note - CS : Nivel logico 0 (GND)
 */
void w5100_cs_enable(void){
	GPIOX_ODR(W5100_CS) = 0;
}

/**
 * @brief Deselecciona el W5100
 * @note - CS : Nivel lógico alto (VDD)
 */
void w5100_cs_disable(void){
	GPIOX_ODR(W5100_CS) = 1;
}

/**
 * @brief Pone a nivel bajo el pin RST del W5100
 */
void w5100_reset_assert(void){
	GPIOX_ODR(W5100_RST) = 0;
}

/**
 * @brief Pone a nivel alto del pin RST del 5100
 */
void w5100_reset_deassert(void){
	GPIOX_ODR(W5100_RST) = 1;
}

/**
 * @brief Genera un reset del chip W5100
 */
void w5100_reset(void){
	GPIOX_ODR(W5100_RST) = 0;
	HAL_Delay(100);
	GPIOX_ODR(W5100_RST) = 1;
	HAL_Delay(100);
}

/**
 * @brief deshabilita las interrupciones
 */
void w5100_critical_enter(void){
	__disable_irq();
}

/**
 * \brief habilita las interrupciones
 */
void w5100_critical_exit(void){
	__enable_irq();
}

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */
