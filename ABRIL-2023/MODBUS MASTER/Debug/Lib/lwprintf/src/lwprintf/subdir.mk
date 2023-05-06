################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Lib/lwprintf/src/lwprintf/lwprintf.c 

OBJS += \
./Lib/lwprintf/src/lwprintf/lwprintf.o 

C_DEPS += \
./Lib/lwprintf/src/lwprintf/lwprintf.d 


# Each subdirectory must supply rules for building sources it contributes
Lib/lwprintf/src/lwprintf/%.o Lib/lwprintf/src/lwprintf/%.su Lib/lwprintf/src/lwprintf/%.cyclo: ../Lib/lwprintf/src/lwprintf/%.c Lib/lwprintf/src/lwprintf/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"D:/STM32Cube/Workspace/MODBUS MASTER/Lib/nanoMODBUS" -I"D:/STM32Cube/Workspace/MODBUS MASTER/Core/App" -I"D:/STM32Cube/Workspace/MODBUS MASTER/Lib/rbuart" -I"D:/STM32Cube/Workspace/MODBUS MASTER/Lib/lwrb/src" -I"D:/STM32Cube/Workspace/MODBUS MASTER/Lib/lwrb/src/include" -I"D:/STM32Cube/Workspace/MODBUS MASTER/Lib/lwrb/src/include/lwrb" -I"D:/STM32Cube/Workspace/MODBUS MASTER/Lib/lwprintf" -I"D:/STM32Cube/Workspace/MODBUS MASTER/Lib/lwprintf/src" -I"D:/STM32Cube/Workspace/MODBUS MASTER/Lib/lwprintf/src/include" -I"D:/STM32Cube/Workspace/MODBUS MASTER/Lib/lwprintf/src/include/lwprintf" -I"D:/STM32Cube/Workspace/MODBUS MASTER/Lib/lwprintf/src/include/system" -I"D:/STM32Cube/Workspace/MODBUS MASTER/Lib/lwbtn" -I"D:/STM32Cube/Workspace/MODBUS MASTER/Lib/lwbtn/src" -I"D:/STM32Cube/Workspace/MODBUS MASTER/Lib/lwbtn/src/include" -I"D:/STM32Cube/Workspace/MODBUS MASTER/Lib/lwbtn/src/include/lwbtn" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Lib-2f-lwprintf-2f-src-2f-lwprintf

clean-Lib-2f-lwprintf-2f-src-2f-lwprintf:
	-$(RM) ./Lib/lwprintf/src/lwprintf/lwprintf.cyclo ./Lib/lwprintf/src/lwprintf/lwprintf.d ./Lib/lwprintf/src/lwprintf/lwprintf.o ./Lib/lwprintf/src/lwprintf/lwprintf.su

.PHONY: clean-Lib-2f-lwprintf-2f-src-2f-lwprintf

