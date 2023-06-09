################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Lib/rbuart/rbuart.c 

OBJS += \
./Lib/rbuart/rbuart.o 

C_DEPS += \
./Lib/rbuart/rbuart.d 


# Each subdirectory must supply rules for building sources it contributes
Lib/rbuart/%.o Lib/rbuart/%.su Lib/rbuart/%.cyclo: ../Lib/rbuart/%.c Lib/rbuart/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/RTOS/Lib/rbuart" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/RTOS/Lib/lwrb/src" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/RTOS/Lib/lwrb/src/include" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/RTOS/Lib/lwrb/src/include/lwrb" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Lib-2f-rbuart

clean-Lib-2f-rbuart:
	-$(RM) ./Lib/rbuart/rbuart.cyclo ./Lib/rbuart/rbuart.d ./Lib/rbuart/rbuart.o ./Lib/rbuart/rbuart.su

.PHONY: clean-Lib-2f-rbuart

