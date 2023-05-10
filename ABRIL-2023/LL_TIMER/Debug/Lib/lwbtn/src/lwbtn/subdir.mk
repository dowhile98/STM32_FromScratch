################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Lib/lwbtn/src/lwbtn/lwbtn.c 

OBJS += \
./Lib/lwbtn/src/lwbtn/lwbtn.o 

C_DEPS += \
./Lib/lwbtn/src/lwbtn/lwbtn.d 


# Each subdirectory must supply rules for building sources it contributes
Lib/lwbtn/src/lwbtn/%.o Lib/lwbtn/src/lwbtn/%.su Lib/lwbtn/src/lwbtn/%.cyclo: ../Lib/lwbtn/src/lwbtn/%.c Lib/lwbtn/src/lwbtn/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/LL_TIMER/Lib/lwbtn/src/include" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/LL_TIMER/Lib/lwbtn/src/include/lwbtn" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Lib-2f-lwbtn-2f-src-2f-lwbtn

clean-Lib-2f-lwbtn-2f-src-2f-lwbtn:
	-$(RM) ./Lib/lwbtn/src/lwbtn/lwbtn.cyclo ./Lib/lwbtn/src/lwbtn/lwbtn.d ./Lib/lwbtn/src/lwbtn/lwbtn.o ./Lib/lwbtn/src/lwbtn/lwbtn.su

.PHONY: clean-Lib-2f-lwbtn-2f-src-2f-lwbtn

