################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LIb/lwrb/src/lwrb/lwrb.c 

OBJS += \
./LIb/lwrb/src/lwrb/lwrb.o 

C_DEPS += \
./LIb/lwrb/src/lwrb/lwrb.d 


# Each subdirectory must supply rules for building sources it contributes
LIb/lwrb/src/lwrb/%.o LIb/lwrb/src/lwrb/%.su LIb/lwrb/src/lwrb/%.cyclo: ../LIb/lwrb/src/lwrb/%.c LIb/lwrb/src/lwrb/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/LL_UART/LIb/ring_buffer_uart" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/LL_UART/LIb/lwrb/src/include" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/LL_UART/LIb/lwrb/src/include/lwrb" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LIb-2f-lwrb-2f-src-2f-lwrb

clean-LIb-2f-lwrb-2f-src-2f-lwrb:
	-$(RM) ./LIb/lwrb/src/lwrb/lwrb.cyclo ./LIb/lwrb/src/lwrb/lwrb.d ./LIb/lwrb/src/lwrb/lwrb.o ./LIb/lwrb/src/lwrb/lwrb.su

.PHONY: clean-LIb-2f-lwrb-2f-src-2f-lwrb

