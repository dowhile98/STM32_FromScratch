################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/delay.c \
../Src/main.c \
../Src/stm32c0xx_it.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/system_stm32c0xx.c 

OBJS += \
./Src/delay.o \
./Src/main.o \
./Src/stm32c0xx_it.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/system_stm32c0xx.o 

C_DEPS += \
./Src/delay.d \
./Src/main.d \
./Src/stm32c0xx_it.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/system_stm32c0xx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DSTM32C031xx -DNUCLEO_C031C6 -DSTM32 -DSTM32C0 -DSTM32C031C6Tx -c -I../Inc -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/TIMER_BASE/Components/lwbtn/src/include" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/TIMER_BASE/Drivers/CMSIS/Include" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/SETIEMBRE-2023/TIMER_BASE/Drivers/CMSIS/Device/ST/STM32C0xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/delay.cyclo ./Src/delay.d ./Src/delay.o ./Src/delay.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/stm32c0xx_it.cyclo ./Src/stm32c0xx_it.d ./Src/stm32c0xx_it.o ./Src/stm32c0xx_it.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/system_stm32c0xx.cyclo ./Src/system_stm32c0xx.d ./Src/system_stm32c0xx.o ./Src/system_stm32c0xx.su

.PHONY: clean-Src

