/*
 * @file W5100_ll_driver.h
 *
 * @date Created on: May 24, 2023
 * @autor Quino B. Jeffry
 */

/**
 * @addtogroup W5100
 * @{
 */
/**
 * @defgroup W5100_LL_Driver W5100_LL
 * Funciones de bajo nivel W5100
 * @{
 */
#ifndef COMPONENTS_W5100_LL_DRIVER_H_
#define COMPONENTS_W5100_LL_DRIVER_H_



/*Include ----------------------------------------------------------*/

#include "main.h"
#include "spi.h"
#include "gpio.h"
#include "defines.h"
/**
 * @defgroup W5100_Defines Dependencias de HW
 * @brief 	en esta seccion se debe configurar la dependencias
 * 			de hardware necesarios para el funcionamiento del chip W5100.
 * @note - Depende del MCU Utilizado
 * @{
 */
/*Defines ----------------------------------------------------------*/
/**
 * @brief Selección del bus SPI
 */
#define ETH_SPI				SPI1  //!< SPIx a utilizarse para la comunicacion (SPI1, SPI2, SPI3..)

/**
 * @brief PIN CS del W5100
 */
#define W5100_CS			A, 4 //!< Define el puerto y el pin para ser usados por: GPIOX_ODR()

/**
 * @brief PIN RST del W5100
 */
#define W5100_RST			C, 4 //!< Define el puerto y el pin para ser usados por: GPIOX_ODR()

/**
 * @}
 */

/*Function prototype -----------------------------------------------*/

/**
 * @defgroup W5100_LL_ExportedFucntion Low Level Function
 * @brief Funciones que comunican al W5100 con el MCU
 * @note para este ejemplo se utiliza una interfaz SPI, por lo que se implementa
 * la funciones de bajo nivel para poder transmitir, leer, selección de chip,
 * reset y manejo de secciones criticas de codigo
 * @{
 */
uint8_t w5100_read_byte(void);
void w5100_write_byte(uint8_t byte);
void w5100_cs_enable(void);
void w5100_cs_disable(void);
void w5100_reset_assert(void);
void w5100_reset_deassert(void);
void w5100_reset(void);
void w5100_critical_enter(void);
void w5100_critical_exit(void);

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */
#endif /* COMPONENTS_W5100_LL_DRIVER_H_ */
