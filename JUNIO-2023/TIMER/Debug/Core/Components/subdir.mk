################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Components/button.c \
../Core/Components/buttonV2.c 

OBJS += \
./Core/Components/button.o \
./Core/Components/buttonV2.o 

C_DEPS += \
./Core/Components/button.d \
./Core/Components/buttonV2.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Components/%.o Core/Components/%.su Core/Components/%.cyclo: ../Core/Components/%.c Core/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/TIMER/Core/Inc" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/TIMER/Core/Components" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/TIMER/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/TIMER/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Components

clean-Core-2f-Components:
	-$(RM) ./Core/Components/button.cyclo ./Core/Components/button.d ./Core/Components/button.o ./Core/Components/button.su ./Core/Components/buttonV2.cyclo ./Core/Components/buttonV2.d ./Core/Components/buttonV2.o ./Core/Components/buttonV2.su

.PHONY: clean-Core-2f-Components

