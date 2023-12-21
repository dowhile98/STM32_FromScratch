################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Components/mpu6050/driver_mpu6050.c \
../Components/mpu6050/driver_mpu6050_interface.c 

C_DEPS += \
./Components/mpu6050/driver_mpu6050.d \
./Components/mpu6050/driver_mpu6050_interface.d 

OBJS += \
./Components/mpu6050/driver_mpu6050.o \
./Components/mpu6050/driver_mpu6050_interface.o 


# Each subdirectory must supply rules for building sources it contributes
Components/mpu6050/%.o Components/mpu6050/%.su Components/mpu6050/%.cyclo: ../Components/mpu6050/%.c Components/mpu6050/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/NOVIEMBRE - 2023/ETH_MQTT_SPI_I2C/Components/mpu6050" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/NOVIEMBRE - 2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Ethernet" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/NOVIEMBRE - 2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/NOVIEMBRE - 2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet/DHCP" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/NOVIEMBRE - 2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet/DNS" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/NOVIEMBRE - 2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet/FTPClient" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/NOVIEMBRE - 2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet/FTPServer" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/NOVIEMBRE - 2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet/httpServer" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/NOVIEMBRE - 2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet/MQTT" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/NOVIEMBRE - 2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet/SNMP" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/NOVIEMBRE - 2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet/SNTP" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/NOVIEMBRE - 2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet/TFTP" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/NOVIEMBRE - 2023/ETH_MQTT_SPI_I2C/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/NOVIEMBRE - 2023/ETH_MQTT_SPI_I2C/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Components-2f-mpu6050

clean-Components-2f-mpu6050:
	-$(RM) ./Components/mpu6050/driver_mpu6050.cyclo ./Components/mpu6050/driver_mpu6050.d ./Components/mpu6050/driver_mpu6050.o ./Components/mpu6050/driver_mpu6050.su ./Components/mpu6050/driver_mpu6050_interface.cyclo ./Components/mpu6050/driver_mpu6050_interface.d ./Components/mpu6050/driver_mpu6050_interface.o ./Components/mpu6050/driver_mpu6050_interface.su

.PHONY: clean-Components-2f-mpu6050

