################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Components/lwbtn/src/lwbtn/lwbtn.c 

OBJS += \
./Components/lwbtn/src/lwbtn/lwbtn.o 

C_DEPS += \
./Components/lwbtn/src/lwbtn/lwbtn.d 


# Each subdirectory must supply rules for building sources it contributes
Components/lwbtn/src/lwbtn/%.o Components/lwbtn/src/lwbtn/%.su Components/lwbtn/src/lwbtn/%.cyclo: ../Components/lwbtn/src/lwbtn/%.c Components/lwbtn/src/lwbtn/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/NOVIEMBRE - 2023/HAL_Driver/Components/lwbtn/src" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/NOVIEMBRE - 2023/HAL_Driver/Components/lwbtn/src/include" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/NOVIEMBRE - 2023/HAL_Driver/Components/lwbtn/src/include/lwbtn" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Components-2f-lwbtn-2f-src-2f-lwbtn

clean-Components-2f-lwbtn-2f-src-2f-lwbtn:
	-$(RM) ./Components/lwbtn/src/lwbtn/lwbtn.cyclo ./Components/lwbtn/src/lwbtn/lwbtn.d ./Components/lwbtn/src/lwbtn/lwbtn.o ./Components/lwbtn/src/lwbtn/lwbtn.su

.PHONY: clean-Components-2f-lwbtn-2f-src-2f-lwbtn

