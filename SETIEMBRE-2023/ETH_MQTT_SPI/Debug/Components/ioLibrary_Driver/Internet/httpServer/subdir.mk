################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Components/ioLibrary_Driver/Internet/httpServer/httpParser.c \
../Components/ioLibrary_Driver/Internet/httpServer/httpServer.c \
../Components/ioLibrary_Driver/Internet/httpServer/httpUtil.c 

C_DEPS += \
./Components/ioLibrary_Driver/Internet/httpServer/httpParser.d \
./Components/ioLibrary_Driver/Internet/httpServer/httpServer.d \
./Components/ioLibrary_Driver/Internet/httpServer/httpUtil.d 

OBJS += \
./Components/ioLibrary_Driver/Internet/httpServer/httpParser.o \
./Components/ioLibrary_Driver/Internet/httpServer/httpServer.o \
./Components/ioLibrary_Driver/Internet/httpServer/httpUtil.o 


# Each subdirectory must supply rules for building sources it contributes
Components/ioLibrary_Driver/Internet/httpServer/%.o Components/ioLibrary_Driver/Internet/httpServer/%.su Components/ioLibrary_Driver/Internet/httpServer/%.cyclo: ../Components/ioLibrary_Driver/Internet/httpServer/%.c Components/ioLibrary_Driver/Internet/httpServer/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI/Components/ioLibrary_Driver/Ethernet" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI/Components/ioLibrary_Driver/Internet" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI/Components/ioLibrary_Driver/Internet/DHCP" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI/Components/ioLibrary_Driver/Internet/DNS" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI/Components/ioLibrary_Driver/Internet/FTPClient" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI/Components/ioLibrary_Driver/Internet/FTPServer" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI/Components/ioLibrary_Driver/Internet/httpServer" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI/Components/ioLibrary_Driver/Internet/MQTT" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI/Components/ioLibrary_Driver/Internet/SNMP" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI/Components/ioLibrary_Driver/Internet/SNTP" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI/Components/ioLibrary_Driver/Internet/TFTP" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_SPI/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Components-2f-ioLibrary_Driver-2f-Internet-2f-httpServer

clean-Components-2f-ioLibrary_Driver-2f-Internet-2f-httpServer:
	-$(RM) ./Components/ioLibrary_Driver/Internet/httpServer/httpParser.cyclo ./Components/ioLibrary_Driver/Internet/httpServer/httpParser.d ./Components/ioLibrary_Driver/Internet/httpServer/httpParser.o ./Components/ioLibrary_Driver/Internet/httpServer/httpParser.su ./Components/ioLibrary_Driver/Internet/httpServer/httpServer.cyclo ./Components/ioLibrary_Driver/Internet/httpServer/httpServer.d ./Components/ioLibrary_Driver/Internet/httpServer/httpServer.o ./Components/ioLibrary_Driver/Internet/httpServer/httpServer.su ./Components/ioLibrary_Driver/Internet/httpServer/httpUtil.cyclo ./Components/ioLibrary_Driver/Internet/httpServer/httpUtil.d ./Components/ioLibrary_Driver/Internet/httpServer/httpUtil.o ./Components/ioLibrary_Driver/Internet/httpServer/httpUtil.su

.PHONY: clean-Components-2f-ioLibrary_Driver-2f-Internet-2f-httpServer

