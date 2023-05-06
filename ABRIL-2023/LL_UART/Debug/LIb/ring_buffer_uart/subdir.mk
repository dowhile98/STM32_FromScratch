################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LIb/ring_buffer_uart/circularuart.c 

OBJS += \
./LIb/ring_buffer_uart/circularuart.o 

C_DEPS += \
./LIb/ring_buffer_uart/circularuart.d 


# Each subdirectory must supply rules for building sources it contributes
LIb/ring_buffer_uart/%.o LIb/ring_buffer_uart/%.su LIb/ring_buffer_uart/%.cyclo: ../LIb/ring_buffer_uart/%.c LIb/ring_buffer_uart/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/LL_UART/LIb/ring_buffer_uart" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/LL_UART/LIb/lwrb/src/include" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/LL_UART/LIb/lwrb/src/include/lwrb" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LIb-2f-ring_buffer_uart

clean-LIb-2f-ring_buffer_uart:
	-$(RM) ./LIb/ring_buffer_uart/circularuart.cyclo ./LIb/ring_buffer_uart/circularuart.d ./LIb/ring_buffer_uart/circularuart.o ./LIb/ring_buffer_uart/circularuart.su

.PHONY: clean-LIb-2f-ring_buffer_uart

