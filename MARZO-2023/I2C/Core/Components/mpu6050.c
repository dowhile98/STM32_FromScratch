/*
 * mpu6050.c
 *
 *  Created on: 12 abr. 2023
 *      Author: jeffr
 */

#include "mpu6050.h"

/*Defines -----------------------------------------------------------*/
/* Default I2C address */
#define MPU6050_I2C_ADDR			0x68

/* Who I am register value */
#define MPU6050_I_AM				0x68

/* MPU6050 registers */
#define MPU6050_AUX_VDDIO			0x01
#define MPU6050_SMPLRT_DIV			0x19
#define MPU6050_CONFIG				0x1A
#define MPU6050_GYRO_CONFIG			0x1B
#define MPU6050_ACCEL_CONFIG		0x1C
#define MPU6050_MOTION_THRESH		0x1F
#define MPU6050_INT_PIN_CFG			0x37
#define MPU6050_INT_ENABLE			0x38
#define MPU6050_INT_STATUS			0x3A
#define MPU6050_ACCEL_XOUT_H		0x3B
#define MPU6050_ACCEL_XOUT_L		0x3C
#define MPU6050_ACCEL_YOUT_H		0x3D
#define MPU6050_ACCEL_YOUT_L		0x3E
#define MPU6050_ACCEL_ZOUT_H		0x3F
#define MPU6050_ACCEL_ZOUT_L		0x40
#define MPU6050_TEMP_OUT_H			0x41
#define MPU6050_TEMP_OUT_L			0x42
#define MPU6050_GYRO_XOUT_H			0x43
#define MPU6050_GYRO_XOUT_L			0x44
#define MPU6050_GYRO_YOUT_H			0x45
#define MPU6050_GYRO_YOUT_L			0x46
#define MPU6050_GYRO_ZOUT_H			0x47
#define MPU6050_GYRO_ZOUT_L			0x48
#define MPU6050_MOT_DETECT_STATUS	0x61
#define MPU6050_SIGNAL_PATH_RESET	0x68
#define MPU6050_MOT_DETECT_CTRL		0x69
#define MPU6050_USER_CTRL			0x6A
#define MPU6050_PWR_MGMT_1			0x6B
#define MPU6050_PWR_MGMT_2			0x6C
#define MPU6050_FIFO_COUNTH			0x72
#define MPU6050_FIFO_COUNTL			0x73
#define MPU6050_FIFO_R_W			0x74
#define MPU6050_WHO_AM_I			0x75

/* Gyro sensitivities in degrees/s */
#define MPU6050_GYRO_SENS_250		((float) 131)
#define MPU6050_GYRO_SENS_500		((float) 65.5)
#define MPU6050_GYRO_SENS_1000		((float) 32.8)
#define MPU6050_GYRO_SENS_2000		((float) 16.4)

/* Acce sensitivities in g/s */
#define MPU6050_ACCE_SENS_2			((float) 16384)
#define MPU6050_ACCE_SENS_4			((float) 8192)
#define MPU6050_ACCE_SENS_8			((float) 4096)
#define MPU6050_ACCE_SENS_16		((float) 2048)
/*Private function --------------------------------------------------*/
static MPU6050_Result_t mpu6050_set_standby_mode(MPU6050_t *dev, uint8_t sourse, uint8_t enable){
	uint8_t temp;
	if(dev->read(dev->mpuI2C, dev->dev_addr, MPU6050_PWR_MGMT_2, &temp, 1, 100) != true){
		return MPU6050_Result_Error;
	}
	temp &=~ (1<<sourse);
	temp |= enable << sourse;
	if(dev->write(dev->mpuI2C, dev->dev_addr, MPU6050_PWR_MGMT_2, &temp, 1, 100 ) != true){
		return MPU6050_Result_Error;
	}
	return MPU6050_Result_Ok;
}
/*Function definition -----------------------------------------------*/
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
MPU6050_Result_t MPU6050_Init(MPU6050_t* DataStruct, MPU6050_Device_t DeviceNumber){
	uint8_t temp;
	uint8_t timout = 100;
	DataStruct->dev_addr = DeviceNumber;
	if(DataStruct->isConnected(DataStruct->mpuI2C, DataStruct->dev_addr, 1000) != true){
		return MPU6050_Result_DeviceNotConnected;
	}
	/*Check who am i*/
	if(DataStruct->read(DataStruct->mpuI2C, DataStruct->dev_addr, MPU6050_WHO_AM_I, &temp, 1, 1000)){
		if(temp != MPU6050_I_AM){
			return MPU6050_Result_DeviceInvalid;
		}
	}
	temp = 1<<7;
	DataStruct->write(DataStruct->mpuI2C, DataStruct->dev_addr, MPU6050_PWR_MGMT_1,&temp, 1, 1000 );
	while(timout != 0 ){
		if(DataStruct->read(DataStruct->mpuI2C, DataStruct->dev_addr, MPU6050_PWR_MGMT_1, &temp, 1, 10) != true){
			return MPU6050_Result_Error;
		}
		if((temp &(1<<7)) == 0){
			break;
		}
		delay_ms(10);
		timout--;
	}
	/*delay 100ms*/
	delay_ms(100);
	/*Disable sleep*/
	if(DataStruct->read(DataStruct->mpuI2C, DataStruct->dev_addr, MPU6050_PWR_MGMT_1, &temp, 1, 100) != true){
		return MPU6050_Result_Error;
	}
	temp &= (1<<6);
	DataStruct->write(DataStruct->mpuI2C, DataStruct->dev_addr, MPU6050_PWR_MGMT_1, &temp, 1, 100);
	/*Set clock source*/
	if(DataStruct->read(DataStruct->mpuI2C, DataStruct->dev_addr, MPU6050_PWR_MGMT_1, &temp, 1,100) != true){
		return MPU6050_Result_Error;
	}
	temp &=~ (0x7<<0);
	temp |= DataStruct->confg.clk;
	if(DataStruct->write(DataStruct->mpuI2C, DataStruct->dev_addr, MPU6050_PWR_MGMT_1, &temp, 1, 100) != true){
		return MPU6050_Result_Error;
	}

	/*Sample read*/
	temp = DataStruct->confg.DataRate;
	MPU6050_SetDataRate(DataStruct, temp);
	/*Set low pass filter*/
	if(DataStruct->read(DataStruct->mpuI2C, DataStruct->dev_addr, MPU6050_CONFIG, &temp, 1, 100) != true){
		return MPU6050_Result_Error;
	}
	temp &=~ (0x7U);
	temp |= DataStruct->confg.filter;
	if(DataStruct->write(DataStruct->mpuI2C, DataStruct->dev_addr, MPU6050_CONFIG, &temp, 1, 100) != true){
		return MPU6050_Result_Error;
	}
	/*Enable temperatura sensor*/
	if(DataStruct->read(DataStruct->mpuI2C,DataStruct->dev_addr, MPU6050_PWR_MGMT_1, &temp, 1, 100 ) != true){
		return MPU6050_Result_Error;
	}
	temp &=~ (1<<3);
	if(DataStruct->write(DataStruct->mpuI2C, DataStruct->dev_addr, MPU6050_PWR_MGMT_1, &temp, 1, 100) != true ){
		return MPU6050_Result_Error;
	}
	/*enable accel	 */
	mpu6050_set_standby_mode(DataStruct, 5, 0);
	mpu6050_set_standby_mode(DataStruct, 4, 0);
	mpu6050_set_standby_mode(DataStruct, 3, 0);
	/*enable gyro*/
	mpu6050_set_standby_mode(DataStruct, 2, 0);
	mpu6050_set_standby_mode(DataStruct, 1, 0);
	mpu6050_set_standby_mode(DataStruct, 0, 0);
	/*Acelerometro*/
	temp = DataStruct->confg.AccelerometerSensitivity;
	MPU6050_SetAccelerometer(DataStruct, temp);
	/*Giroscopio*/
	temp = DataStruct->confg.GyroscopeSensitivity;
	MPU6050_SetGyroscope(DataStruct, temp);

	/*return ok*/
	return MPU6050_Result_Ok;
}

/**
 * @brief  Sets gyroscope sensitivity
 * @param  *DataStruct: Pointer to @ref TM_MPU6050_t structure indicating MPU6050 device
 * @param  GyroscopeSensitivity: Gyro sensitivity value. This parameter can be a value of @ref TM_MPU6050_Gyroscope_t enumeration
 * @retval Member of @ref TM_MPU6050_Result_t enumeration
 */
MPU6050_Result_t MPU6050_SetGyroscope(MPU6050_t* DataStruct, MPU6050_Gyroscope_t GyroscopeSensitivity){
	uint8_t temp;
	/*read*/
	DataStruct->read(DataStruct->mpuI2C, DataStruct->dev_addr, MPU6050_GYRO_CONFIG, &temp, 1, 1000);
	temp = (temp & 0xEF) | (uint8_t)GyroscopeSensitivity;
	if(DataStruct->write(DataStruct->mpuI2C, DataStruct->dev_addr, MPU6050_GYRO_CONFIG, &temp, 1, 1000) != true){
		return MPU6050_Result_Error;
	}
	temp = GyroscopeSensitivity;
	switch(temp){
	case MPU6050_Gyroscope_250s:
		DataStruct->g.sensitivy = 1.0 / MPU6050_GYRO_SENS_250;
		break;
	case MPU6050_Gyroscope_500s:
		DataStruct->g.sensitivy = 1.0 / MPU6050_GYRO_SENS_500;
		break;
	case MPU6050_Gyroscope_1000s:
		DataStruct->g.sensitivy = 1.0 / MPU6050_GYRO_SENS_1000;
		break;
	case MPU6050_Gyroscope_2000s:
		DataStruct->g.sensitivy = 1.0 / MPU6050_GYRO_SENS_2000;
		break;
	}
	return MPU6050_Result_Ok;
}

/**
 * @brief  Sets accelerometer sensitivity
 * @param  *DataStruct: Pointer to @ref TM_MPU6050_t structure indicating MPU6050 device
 * @param  AccelerometerSensitivity: Gyro sensitivity value. This parameter can be a value of @ref TM_MPU6050_Accelerometer_t enumeration
 * @retval Member of @ref TM_MPU6050_Result_t enumeration
 */
MPU6050_Result_t MPU6050_SetAccelerometer(MPU6050_t* DataStruct, MPU6050_Accelerometer_t AccelerometerSensitivity){
	uint8_t temp;
	/*leer*/
	DataStruct->read(DataStruct->mpuI2C, DataStruct->dev_addr, MPU6050_ACCEL_CONFIG, &temp, 1, 1000);
	temp = (temp & 0xEF) | (uint8_t)AccelerometerSensitivity;
	if(DataStruct->write(DataStruct->mpuI2C, DataStruct->dev_addr, MPU6050_ACCEL_CONFIG, &temp,1, 1000) != true){
		return MPU6050_Result_Error;
	}
	temp = AccelerometerSensitivity;
	switch(temp){
	case MPU6050_Accelerometer_2G:
		DataStruct->a.sensitivy = 1.0 / MPU6050_ACCE_SENS_2;
		break;
	case MPU6050_Accelerometer_4G:
		DataStruct->a.sensitivy = 1.0 / MPU6050_ACCE_SENS_4;
		break;
	case MPU6050_Accelerometer_8G:
		DataStruct->a.sensitivy = 1.0 / MPU6050_ACCE_SENS_8;
		break;
	case MPU6050_Accelerometer_16G:
		DataStruct->a.sensitivy = 1.0 / MPU6050_ACCE_SENS_16;
		break;
	}
	return MPU6050_Result_Ok;
}

/**
 * @brief  Sets output data rate
 * @param  *DataStruct: Pointer to @ref TM_MPU6050_t structure indicating MPU6050 device
 * @param  rate: Data rate value. An 8-bit value for prescaler value
 * @retval Member of @ref TM_MPU6050_Result_t enumeration
 */
MPU6050_Result_t MPU6050_SetDataRate(MPU6050_t* DataStruct, uint8_t rate){
	if(DataStruct->write(DataStruct->mpuI2C, DataStruct->dev_addr, MPU6050_SMPLRT_DIV, &rate, 1, 1000) == true){
		return MPU6050_Result_Ok;
	}
	return MPU6050_Result_Error;
}

/**
 * @brief  Enables interrupts
 * @param  *DataStruct: Pointer to @ref TM_MPU6050_t structure indicating MPU6050 device
 * @retval Member of @ref TM_MPU6050_Result_t enumeration
 */
MPU6050_Result_t MPU6050_EnableInterrupts(MPU6050_t* DataStruct){
	uint8_t temp;

	/*Level and pin type*/
	if(DataStruct->read(DataStruct->mpuI2C, DataStruct->dev_addr, MPU6050_INT_PIN_CFG, &temp, 1, 1000) != true){
		return MPU6050_Result_Error;
	}
	temp &=~ (1<<7 | 1<<6 | 1<<5);
	temp |= 0x10;
	temp |= DataStruct->ITconfg.level<<7 | DataStruct->ITconfg.pin_type<<6;
	DataStruct->write(DataStruct->mpuI2C, DataStruct->dev_addr, MPU6050_INT_PIN_CFG, &temp, 1, 1000);
	/*Enable interrupt*/
	if(DataStruct->read(DataStruct->mpuI2C, DataStruct->dev_addr, MPU6050_INT_ENABLE, &temp, 1, 1000) != true){
		return MPU6050_Result_Error;
	}
	temp |= DataStruct->ITconfg.it_type;

	DataStruct->write(DataStruct->mpuI2C, DataStruct->dev_addr, MPU6050_INT_ENABLE, &temp, 1, 1000);

	return MPU6050_Result_Error;
}

/**
 * @brief  Disables interrupts
 * @param  *DataStruct: Pointer to @ref TM_MPU6050_t structure indicating MPU6050 device
 * @retval Member of @ref TM_MPU6050_Result_t enumeration
 */
MPU6050_Result_t MPU6050_DisableInterrupts(MPU6050_t* DataStruct){
	uint8_t temp = 0x00;
	if(DataStruct->write(DataStruct->mpuI2C, DataStruct->dev_addr, MPU6050_INT_ENABLE, &temp, 1, 1000) == true){
		return MPU6050_Result_Ok;
	}
	return MPU6050_Result_Error;

}

/**
 * @brief  Reads and clears interrupts
 * @param  *DataStruct: Pointer to @ref TM_MPU6050_t structure indicating MPU6050 device
 * @param  *InterruptsStruct: Pointer to @ref TM_MPU6050_Interrupt_t structure to store status in
 * @retval Member of @ref TM_MPU6050_Result_t enumeration
 */
MPU6050_Result_t MPU6050_ReadInterrupts(MPU6050_t* DataStruct, MPU6050_Interrupt_t* InterruptsStruct){
	uint8_t read;
	InterruptsStruct->Status = 0;
	if(DataStruct->read(DataStruct->mpuI2C, DataStruct->dev_addr, MPU6050_INT_STATUS, &read, 1, 100) != true){
		return MPU6050_Result_Error;
	}
	InterruptsStruct->Status = read;

	return MPU6050_Result_Ok;
}

/**
 * @brief  Reads accelerometer data from sensor
 * @param  *DataStruct: Pointer to @ref TM_MPU6050_t structure to store data to
 * @retval Member of @ref TM_MPU6050_Result_t:
 *            - TM_MPU6050_Result_Ok: everything is OK
 *            - Other: in other cases
 */
MPU6050_Result_t MPU6050_ReadAccelerometer(MPU6050_t* DataStruct){
	uint8_t data[6];
	if (DataStruct->read(DataStruct->mpuI2C, DataStruct->dev_addr, MPU6050_ACCEL_XOUT_H, data, 6, 100) != true){
		return MPU6050_Result_Error;
	}

	/*formato*/
	DataStruct->a.x = (int16_t)(data[0] << 8 | data[1]);
	DataStruct->a.y = (int16_t)(data[2] << 8 | data[3]);
	DataStruct->a.z = (int16_t)(data[4] << 8 | data[5]);

	return MPU6050_Result_Ok;
}

/**
 * @brief  Reads gyroscope data from sensor
 * @param  *DataStruct: Pointer to @ref TM_MPU6050_t structure to store data to
 * @retval Member of @ref TM_MPU6050_Result_t:
 *            - TM_MPU6050_Result_Ok: everything is OK
 *            - Other: in other cases
 */
MPU6050_Result_t MPU6050_ReadGyroscope(MPU6050_t* DataStruct){
	uint8_t data[6];
	if (DataStruct->read(DataStruct->mpuI2C, DataStruct->dev_addr, MPU6050_GYRO_XOUT_H, data, 6, 100) != true){
		return MPU6050_Result_Error;
	}

	/*formato*/
	DataStruct->g.x = (int16_t)(data[0] << 8 | data[1]);
	DataStruct->g.y = (int16_t)(data[2] << 8 | data[3]);
	DataStruct->g.z = (int16_t)(data[4] << 8 | data[5]);

	return MPU6050_Result_Ok;
}

/**
 * @brief  Reads temperature data from sensor
 * @param  *DataStruct: Pointer to @ref TM_MPU6050_t structure to store data to
 * @retval Member of @ref TM_MPU6050_Result_t:
 *            - TM_MPU6050_Result_Ok: everything is OK
 *            - Other: in other cases
 */
MPU6050_Result_t MPU6050_ReadTemperature(MPU6050_t* DataStruct){
	uint8_t data[2];
	uint8_t temp;
	if(DataStruct->read(DataStruct->mpuI2C, DataStruct->dev_addr, MPU6050_TEMP_OUT_H, data, 2, 100) != true){
		return MPU6050_Result_Error;
	}
	temp = (data[0] << 8 | data[1]);
	DataStruct->temp = (float)((int16_t)temp / (float)340.0 + (float)36.53);
	return  MPU6050_Result_Ok;
}

/**
 * @brief  Reads accelerometer, gyroscope and temperature data from sensor
 * @param  *DataStruct: Pointer to @ref TM_MPU6050_t structure to store data to
 * @retval Member of @ref TM_MPU6050_Result_t:
 *            - TM_MPU6050_Result_Ok: everything is OK
 *            - Other: in other cases
 */
MPU6050_Result_t MPU6050_ReadAll(MPU6050_t* DataStruct){
	uint8_t data[14];
	int16_t temp;
	if(DataStruct->read(DataStruct->mpuI2C, DataStruct->dev_addr, MPU6050_ACCEL_XOUT_H, data, 14, 100) != true){
		return MPU6050_Result_Error;
	}
	DataStruct->a.x = (int16_t)(data[0] << 8 | data[1]);
	DataStruct->a.y = (int16_t)(data[2] << 8 | data[3]);
	DataStruct->a.z = (int16_t)(data[4] << 8 | data[5]);
	temp = (data[6] << 8 | data[7]);
	DataStruct->temp = (float)((float)((int16_t)temp) / (float)340.0 + (float)36.53);

	DataStruct->g.x = (int16_t)(data[8] << 8 | data[9]);
	DataStruct->g.y = (int16_t)(data[10] << 8 | data[11]);
	DataStruct->g.z = (int16_t)(data[12] << 8 | data[13]);

	return MPU6050_Result_Ok;
}
