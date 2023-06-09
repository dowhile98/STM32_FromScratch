################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Lib/lwrb/src/lwrb/lwrb.c 

OBJS += \
./Lib/lwrb/src/lwrb/lwrb.o 

C_DEPS += \
./Lib/lwrb/src/lwrb/lwrb.d 


# Each subdirectory must supply rules for building sources it contributes
Lib/lwrb/src/lwrb/%.o Lib/lwrb/src/lwrb/%.su Lib/lwrb/src/lwrb/%.cyclo: ../Lib/lwrb/src/lwrb/%.c Lib/lwrb/src/lwrb/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/RTOS/Lib/rbuart" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/RTOS/Lib/lwrb/src" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/RTOS/Lib/lwrb/src/include" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/RTOS/Lib/lwrb/src/include/lwrb" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Lib-2f-lwrb-2f-src-2f-lwrb

clean-Lib-2f-lwrb-2f-src-2f-lwrb:
	-$(RM) ./Lib/lwrb/src/lwrb/lwrb.cyclo ./Lib/lwrb/src/lwrb/lwrb.d ./Lib/lwrb/src/lwrb/lwrb.o ./Lib/lwrb/src/lwrb/lwrb.su

.PHONY: clean-Lib-2f-lwrb-2f-src-2f-lwrb

