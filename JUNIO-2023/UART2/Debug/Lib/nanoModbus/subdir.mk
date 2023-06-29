################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Lib/nanoModbus/nanomodbus.c 

OBJS += \
./Lib/nanoModbus/nanomodbus.o 

C_DEPS += \
./Lib/nanoModbus/nanomodbus.d 


# Each subdirectory must supply rules for building sources it contributes
Lib/nanoModbus/%.o Lib/nanoModbus/%.su Lib/nanoModbus/%.cyclo: ../Lib/nanoModbus/%.c Lib/nanoModbus/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/JUNIO-2023/UART2/Core/Inc" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/JUNIO-2023/UART2/Lib/nanoModbus" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/JUNIO-2023/UART2/Lib/lwrb/src/include" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/JUNIO-2023/UART2/Lib/lwrb/src/include/lwrb" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/JUNIO-2023/UART2/Drivers/BSP" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/JUNIO-2023/UART2/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/JUNIO-2023/UART2/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Lib-2f-nanoModbus

clean-Lib-2f-nanoModbus:
	-$(RM) ./Lib/nanoModbus/nanomodbus.cyclo ./Lib/nanoModbus/nanomodbus.d ./Lib/nanoModbus/nanomodbus.o ./Lib/nanoModbus/nanomodbus.su

.PHONY: clean-Lib-2f-nanoModbus

