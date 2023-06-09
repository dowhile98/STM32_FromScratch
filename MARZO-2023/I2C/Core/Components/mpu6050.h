/*
 * mpu6050.h
 *
 *  Created on: 12 abr. 2023
 *      Author: jeffr
 */

#ifndef COMPONENTS_MPU6050_H_
#define COMPONENTS_MPU6050_H_

/*Include ------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
#include <stm32f4xx.h>
#include <delay.h>
/*Typedef ----------------------------------------------- */
/**
 * @brief  MPU6050 can have 2 different slave addresses, depends on it's input AD0 pin
 *         This feature allows you to use 2 different sensors with this library at the same time
 */
typedef enum  {
	MPU6050_Device_0 = 0x00, /*!< AD0 pin is set to low */
	MPU6050_Device_1 = 0x02  /*!< AD0 pin is set to high */
} MPU6050_Device_t;

/**
 * @brief  MPU6050 result enumeration
 */
typedef enum  {
	MPU6050_Result_Ok = 0x00,          /*!< Everything OK */
	MPU6050_Result_Error,              /*!< Unknown error */
	MPU6050_Result_DeviceNotConnected, /*!< There is no device with valid slave address */
	MPU6050_Result_DeviceInvalid       /*!< Connected device with address is not MPU6050 */
} MPU6050_Result_t;
typedef enum
{
	DLPF_260A_256G_Hz = 0x00,
	DLPF_184A_188G_Hz = 0x01,
	DLPF_94A_98G_Hz 	= 0x02,
	DLPF_44A_42G_Hz 	= 0x03,
	DLPF_21A_20G_Hz 	= 0x04,
	DLPF_10_Hz 				= 0x05,
	DLPF_5_Hz 				= 0x06
}MPU6050_DLPF_t;
typedef enum
{
	Internal_8MHz 	= 0x00,
	X_Axis_Ref		= 0x01,
	Y_Axis_Ref		= 0x02,
	Z_Axis_Ref		= 0x03,
	Ext_32_768KHz	= 0x04,
	Ext_19_2MHz		= 0x05,
	TIM_GENT_INREST	= 0x07
}MPU6050_CLKSEL_t;
/**
 * @brief  Parameters for accelerometer range
 */
typedef enum  {
	MPU6050_Accelerometer_2G = 0x00, /*!< Range is +- 2G */
	MPU6050_Accelerometer_4G = 0x01, /*!< Range is +- 4G */
	MPU6050_Accelerometer_8G = 0x02, /*!< Range is +- 8G */
	MPU6050_Accelerometer_16G = 0x03 /*!< Range is +- 16G */
} MPU6050_Accelerometer_t;

/**
 * @brief  Parameters for gyroscope range
 */
typedef enum  {
	MPU6050_Gyroscope_250s = 0x00,  /*!< Range is +- 250 degrees/s */
	MPU6050_Gyroscope_500s = 0x01,  /*!< Range is +- 500 degrees/s */
	MPU6050_Gyroscope_1000s = 0x02, /*!< Range is +- 1000 degrees/s */
	MPU6050_Gyroscope_2000s = 0x03  /*!< Range is +- 2000 degrees/s */
} MPU6050_Gyroscope_t;

/**
 * @brief mpu6050 pin level enumeration definition
 */
typedef enum
{
    MPU6050_PIN_LEVEL_HIGH = 0x00,        /**< active low */
    MPU6050_PIN_LEVEL_LOW  = 0x01,        /**< active high */
} mpu6050_pin_level_t;

/**
 * @brief mpu6050 pin type enumeration definition
 */
typedef enum
{
    MPU6050_PIN_TYPE_PUSH_PULL  = 0x00,        /**< push pull */
    MPU6050_PIN_TYPE_OPEN_DRAIN = 0x01,        /**< open drain */
} mpu6050_pin_type_t;

/**
 * @brief mpu6050 interrupt enumeration definition
 */
typedef enum
{
    MPU6050_INTERRUPT_MOTION        = 1<<6,        /**< motion */
    MPU6050_INTERRUPT_FIFO_OVERFLOW = 1<<4,        /**< fifo overflow */
    MPU6050_INTERRUPT_I2C_MAST      = 1<<3,        /**< i2c master */
    MPU6050_INTERRUPT_DMP           = 1<<1,        /**< dmp */
    MPU6050_INTERRUPT_DATA_READY    = 1,        /**< data ready */
} mpu6050_interrupt_type_t;
/**
 * @brief interrupt config struct
 */
typedef struct{
	mpu6050_pin_level_t level;
	mpu6050_pin_type_t pin_type;
	mpu6050_interrupt_type_t it_type;
}MPU6050_IT_Confg_t;
/**
 * @brief link function
 */
typedef bool (*mpu6050_write_fptr_t)(I2C_TypeDef *I2Cx, uint8_t slaveAddr,uint8_t reg_addr, uint8_t *pData, uint32_t Len, uint32_t timeout);
typedef bool (*mpu6050_read_fptr_t)(I2C_TypeDef *I2Cx, uint8_t slaveAddr,uint8_t reg_addr, uint8_t *pData, uint32_t Len, uint32_t timeout);
typedef bool (*mpu6050_deviceConnected)(I2C_TypeDef *I2Cx, uint8_t slaveAddr, uint32_t timeout);

/**
 * @brief data for accel and gyroscope
 */
typedef struct{
	int16_t x;
	int16_t y;
	int16_t z;
	float ax;
	float ay;
	float az;
	float sensitivy;
}Accel_t;

typedef struct{
	int16_t x;
	int16_t y;
	int16_t z;
	float gx;
	float gy;
	float gz;
	float sensitivy;
}Gyros_t;
/**
 * @brief data for manage MPU6050
 */
typedef struct{
	MPU6050_Accelerometer_t AccelerometerSensitivity;
	MPU6050_Gyroscope_t GyroscopeSensitivity;
	uint8_t DataRate;
	MPU6050_DLPF_t filter;
	MPU6050_CLKSEL_t clk;
}Config_t;
typedef struct{
	mpu6050_read_fptr_t read;
	mpu6050_write_fptr_t write;
	mpu6050_deviceConnected isConnected;
	I2C_TypeDef *mpuI2C;
	uint8_t dev_addr;
	Accel_t a;						//acelerometro
	Gyros_t g;						//giroscopio
	float temp;					//valor de temperatura
	Config_t confg;
	MPU6050_IT_Confg_t ITconfg;
}MPU6050_t;

/**
 * @brief  Interrupts union and structure
 */
typedef union {
	struct {
		uint8_t DataReady:1;       /*!< Data ready interrupt */
		uint8_t reserved2:2;       /*!< Reserved bits */
		uint8_t Master:1;          /*!< Master interrupt. Not enabled with library */
		uint8_t FifoOverflow:1;    /*!< FIFO overflow interrupt. Not enabled with library */
		uint8_t reserved1:1;       /*!< Reserved bit */
		uint8_t MotionDetection:1; /*!< Motion detected interrupt */
		uint8_t reserved0:1;       /*!< Reserved bit */
	} F;
	uint8_t Status;
} MPU6050_Interrupt_t;
/*Defines ------------------------------------------------*/
/**
 * @brief  Data rates predefined constants
 * @{
 */
#define MPU6050_DataRate_8KHz       0   /*!< Sample rate set to 8 kHz */
#define MPU6050_DataRate_4KHz       1   /*!< Sample rate set to 4 kHz */
#define MPU6050_DataRate_2KHz       3   /*!< Sample rate set to 2 kHz */
#define MPU6050_DataRate_1KHz       7   /*!< Sample rate set to 1 kHz */
#define MPU6050_DataRate_500Hz      15  /*!< Sample rate set to 500 Hz */
#define MPU6050_DataRate_250Hz      31  /*!< Sample rate set to 250 Hz */
#define MPU6050_DataRate_125Hz      63  /*!< Sample rate set to 125 Hz */
#define MPU6050_DataRate_100Hz      79  /*!< Sample rate set to 100 Hz */


#define MPU6050_LINK_READ_FUNC(HANDLE, FUNC)	(HANDLE)->read = FUNC

#define MPU6050_LINK_WRITE_FUNC(HANDLE, FUNC)	(HANDLE)->write = FUNC

#define MPU6050_LINK_ISCONECTED_FUNC(HANDLE, FUNC)	(HANDLE)->isConnected = FUNC
/*Function prototype -------------------------------------*/
/**
 * @brief  Initializes MPU6050 and I2C peripheral
 * @param  *DataStruct: Pointer to empty @ref TM_MPU6050_t structure
 * @param  DeviceNumber: MPU6050 has one pin, AD0 which can be used to set address of device.
 *          This feature allows you to use 2 different sensors on the same board with same library.
 *          If you set AD0 pin to low, then this parameter should be TM_MPU6050_Device_0,
 *          but if AD0 pin is high, then you should use TM_MPU6050_Device_1
 *
 *          Parameter can be a value of @ref TM_MPU6050_Device_t enumeration
 * @param  AccelerometerSensitivity: Set accelerometer sensitivity. This parameter can be a value of @ref TM_MPU6050_Accelerometer_t enumeration
 * @param  GyroscopeSensitivity: Set gyroscope sensitivity. This parameter can be a value of @ref TM_MPU6050_Gyroscope_t enumeration
 * @retval Initialization status:
 *            - TM_MPU6050_Result_t: Everything OK
 *            - Other member: in other cases
 */
MPU6050_Result_t MPU6050_Init(MPU6050_t* DataStruct, MPU6050_Device_t DeviceNumber);

/**
 * @brief  Sets gyroscope sensitivity
 * @param  *DataStruct: Pointer to @ref TM_MPU6050_t structure indicating MPU6050 device
 * @param  GyroscopeSensitivity: Gyro sensitivity value. This parameter can be a value of @ref TM_MPU6050_Gyroscope_t enumeration
 * @retval Member of @ref TM_MPU6050_Result_t enumeration
 */
MPU6050_Result_t MPU6050_SetGyroscope(MPU6050_t* DataStruct, MPU6050_Gyroscope_t GyroscopeSensitivity);

/**
 * @brief  Sets accelerometer sensitivity
 * @param  *DataStruct: Pointer to @ref TM_MPU6050_t structure indicating MPU6050 device
 * @param  AccelerometerSensitivity: Gyro sensitivity value. This parameter can be a value of @ref TM_MPU6050_Accelerometer_t enumeration
 * @retval Member of @ref TM_MPU6050_Result_t enumeration
 */
MPU6050_Result_t MPU6050_SetAccelerometer(MPU6050_t* DataStruct, MPU6050_Accelerometer_t AccelerometerSensitivity);

/**
 * @brief  Sets output data rate
 * @param  *DataStruct: Pointer to @ref TM_MPU6050_t structure indicating MPU6050 device
 * @param  rate: Data rate value. An 8-bit value for prescaler value
 * @retval Member of @ref TM_MPU6050_Result_t enumeration
 */
MPU6050_Result_t MPU6050_SetDataRate(MPU6050_t* DataStruct, uint8_t rate);

/**
 * @brief  Enables interrupts
 * @param  *DataStruct: Pointer to @ref TM_MPU6050_t structure indicating MPU6050 device
 * @retval Member of @ref TM_MPU6050_Result_t enumeration
 */
MPU6050_Result_t MPU6050_EnableInterrupts(MPU6050_t* DataStruct);

/**
 * @brief  Disables interrupts
 * @param  *DataStruct: Pointer to @ref TM_MPU6050_t structure indicating MPU6050 device
 * @retval Member of @ref TM_MPU6050_Result_t enumeration
 */
MPU6050_Result_t MPU6050_DisableInterrupts(MPU6050_t* DataStruct);

/**
 * @brief  Reads and clears interrupts
 * @param  *DataStruct: Pointer to @ref TM_MPU6050_t structure indicating MPU6050 device
 * @param  *InterruptsStruct: Pointer to @ref TM_MPU6050_Interrupt_t structure to store status in
 * @retval Member of @ref TM_MPU6050_Result_t enumeration
 */
MPU6050_Result_t MPU6050_ReadInterrupts(MPU6050_t* DataStruct, MPU6050_Interrupt_t* InterruptsStruct);

/**
 * @brief  Reads accelerometer data from sensor
 * @param  *DataStruct: Pointer to @ref TM_MPU6050_t structure to store data to
 * @retval Member of @ref TM_MPU6050_Result_t:
 *            - TM_MPU6050_Result_Ok: everything is OK
 *            - Other: in other cases
 */
MPU6050_Result_t MPU6050_ReadAccelerometer(MPU6050_t* DataStruct);

/**
 * @brief  Reads gyroscope data from sensor
 * @param  *DataStruct: Pointer to @ref TM_MPU6050_t structure to store data to
 * @retval Member of @ref TM_MPU6050_Result_t:
 *            - TM_MPU6050_Result_Ok: everything is OK
 *            - Other: in other cases
 */
MPU6050_Result_t MPU6050_ReadGyroscope(MPU6050_t* DataStruct);

/**
 * @brief  Reads temperature data from sensor
 * @param  *DataStruct: Pointer to @ref TM_MPU6050_t structure to store data to
 * @retval Member of @ref TM_MPU6050_Result_t:
 *            - TM_MPU6050_Result_Ok: everything is OK
 *            - Other: in other cases
 */
MPU6050_Result_t MPU6050_ReadTemperature(MPU6050_t* DataStruct);

/**
 * @brief  Reads accelerometer, gyroscope and temperature data from sensor
 * @param  *DataStruct: Pointer to @ref TM_MPU6050_t structure to store data to
 * @retval Member of @ref TM_MPU6050_Result_t:
 *            - TM_MPU6050_Result_Ok: everything is OK
 *            - Other: in other cases
 */
MPU6050_Result_t MPU6050_ReadAll(MPU6050_t* DataStruct);

#endif /* COMPONENTS_MPU6050_H_ */
