################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/delay.c \
../Src/driver_mpu6050_basic.c \
../Src/i2c.c \
../Src/retarget.c \
../Src/stm32fxx_it.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/system_stm32f4xx.c 

CPP_SRCS += \
../Src/main.cpp 

C_DEPS += \
./Src/delay.d \
./Src/driver_mpu6050_basic.d \
./Src/i2c.d \
./Src/retarget.d \
./Src/stm32fxx_it.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/system_stm32f4xx.d 

OBJS += \
./Src/delay.o \
./Src/driver_mpu6050_basic.o \
./Src/i2c.o \
./Src/main.o \
./Src/retarget.o \
./Src/stm32fxx_it.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/system_stm32f4xx.o 

CPP_DEPS += \
./Src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI_I2C/Components/mpu6050" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Ethernet" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet/DHCP" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet/DNS" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet/FTPClient" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet/FTPServer" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet/httpServer" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet/MQTT" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet/SNMP" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet/SNTP" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet/TFTP" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI_I2C/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI_I2C/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.cpp Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DSTM32F407xx -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI_I2C/Components/mpu6050" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI_I2C/Components/ArduinoJson/src" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Ethernet" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet/DHCP" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet/DNS" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet/FTPClient" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet/FTPServer" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet/httpServer" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet/MQTT" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet/SNMP" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet/SNTP" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI_I2C/Components/ioLibrary_Driver/Internet/TFTP" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI_I2C/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI_I2C/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/delay.cyclo ./Src/delay.d ./Src/delay.o ./Src/delay.su ./Src/driver_mpu6050_basic.cyclo ./Src/driver_mpu6050_basic.d ./Src/driver_mpu6050_basic.o ./Src/driver_mpu6050_basic.su ./Src/i2c.cyclo ./Src/i2c.d ./Src/i2c.o ./Src/i2c.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/retarget.cyclo ./Src/retarget.d ./Src/retarget.o ./Src/retarget.su ./Src/stm32fxx_it.cyclo ./Src/stm32fxx_it.d ./Src/stm32fxx_it.o ./Src/stm32fxx_it.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/system_stm32f4xx.cyclo ./Src/system_stm32f4xx.d ./Src/system_stm32f4xx.o ./Src/system_stm32f4xx.su

.PHONY: clean-Src

