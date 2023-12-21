################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Components/ioLibrary_Driver/Internet/DHCP/dhcp.c 

C_DEPS += \
./Components/ioLibrary_Driver/Internet/DHCP/dhcp.d 

OBJS += \
./Components/ioLibrary_Driver/Internet/DHCP/dhcp.o 


# Each subdirectory must supply rules for building sources it contributes
Components/ioLibrary_Driver/Internet/DHCP/%.o Components/ioLibrary_Driver/Internet/DHCP/%.su Components/ioLibrary_Driver/Internet/DHCP/%.cyclo: ../Components/ioLibrary_Driver/Internet/DHCP/%.c Components/ioLibrary_Driver/Internet/DHCP/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/NOVIEMBRE - 2023/ETH_MQTT_SPI_I2C/Components/mpu6050" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/NOVIEMBRE - 2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Ethernet" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/NOVIEMBRE - 2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/NOVIEMBRE - 2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet/DHCP" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/NOVIEMBRE - 2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet/DNS" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/NOVIEMBRE - 2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet/FTPClient" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/NOVIEMBRE - 2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet/FTPServer" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/NOVIEMBRE - 2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet/httpServer" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/NOVIEMBRE - 2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet/MQTT" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/NOVIEMBRE - 2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet/SNMP" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/NOVIEMBRE - 2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet/SNTP" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/NOVIEMBRE - 2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet/TFTP" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/NOVIEMBRE - 2023/ETH_MQTT_SPI_I2C/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/NOVIEMBRE - 2023/ETH_MQTT_SPI_I2C/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Components-2f-ioLibrary_Driver-2f-Internet-2f-DHCP

clean-Components-2f-ioLibrary_Driver-2f-Internet-2f-DHCP:
	-$(RM) ./Components/ioLibrary_Driver/Internet/DHCP/dhcp.cyclo ./Components/ioLibrary_Driver/Internet/DHCP/dhcp.d ./Components/ioLibrary_Driver/Internet/DHCP/dhcp.o ./Components/ioLibrary_Driver/Internet/DHCP/dhcp.su

.PHONY: clean-Components-2f-ioLibrary_Driver-2f-Internet-2f-DHCP
