################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/FreeRTOS/CMSIS_RTOS/cmsis_os.c 

C_DEPS += \
./Middlewares/Third_Party/FreeRTOS/CMSIS_RTOS/cmsis_os.d 

OBJS += \
./Middlewares/Third_Party/FreeRTOS/CMSIS_RTOS/cmsis_os.o 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/FreeRTOS/CMSIS_RTOS/%.o Middlewares/Third_Party/FreeRTOS/CMSIS_RTOS/%.su Middlewares/Third_Party/FreeRTOS/CMSIS_RTOS/%.cyclo: ../Middlewares/Third_Party/FreeRTOS/CMSIS_RTOS/%.c Middlewares/Third_Party/FreeRTOS/CMSIS_RTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_RTOS/Middlewares/Third_Party/FreeRTOS/CMSIS_RTOS" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_RTOS/Middlewares/Third_Party/FreeRTOS/include" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_RTOS/Middlewares/Third_Party/FreeRTOS/portable/GCC/ARM_CM4F" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_RTOS/Components/mpu6050" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_RTOS/Components/ioLibrary_Driver/Ethernet" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_RTOS/Components/ioLibrary_Driver/Internet" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_RTOS/Components/ioLibrary_Driver/Internet/DHCP" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_RTOS/Components/ioLibrary_Driver/Internet/DNS" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_RTOS/Components/ioLibrary_Driver/Internet/FTPClient" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_RTOS/Components/ioLibrary_Driver/Internet/FTPServer" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_RTOS/Components/ioLibrary_Driver/Internet/httpServer" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_RTOS/Components/ioLibrary_Driver/Internet/MQTT" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_RTOS/Components/ioLibrary_Driver/Internet/SNMP" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_RTOS/Components/ioLibrary_Driver/Internet/SNTP" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_RTOS/Components/ioLibrary_Driver/Internet/TFTP" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_RTOS/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/ETH_MQTT_RTOS/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-FreeRTOS-2f-CMSIS_RTOS

clean-Middlewares-2f-Third_Party-2f-FreeRTOS-2f-CMSIS_RTOS:
	-$(RM) ./Middlewares/Third_Party/FreeRTOS/CMSIS_RTOS/cmsis_os.cyclo ./Middlewares/Third_Party/FreeRTOS/CMSIS_RTOS/cmsis_os.d ./Middlewares/Third_Party/FreeRTOS/CMSIS_RTOS/cmsis_os.o ./Middlewares/Third_Party/FreeRTOS/CMSIS_RTOS/cmsis_os.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-FreeRTOS-2f-CMSIS_RTOS

