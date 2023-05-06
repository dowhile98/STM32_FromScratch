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
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"D:/STM32Cube/Workspace/MODBUS/Lib/nanoMODBUS" -I"D:/STM32Cube/Workspace/MODBUS/Core/App" -I"D:/STM32Cube/Workspace/MODBUS/Lib/rbuart" -I"D:/STM32Cube/Workspace/MODBUS/Lib/lwrb/src" -I"D:/STM32Cube/Workspace/MODBUS/Lib/lwrb/src/include" -I"D:/STM32Cube/Workspace/MODBUS/Lib/lwrb/src/include/lwrb" -I"D:/STM32Cube/Workspace/MODBUS/Lib/lwprintf" -I"D:/STM32Cube/Workspace/MODBUS/Lib/lwprintf/src" -I"D:/STM32Cube/Workspace/MODBUS/Lib/lwprintf/src/include" -I"D:/STM32Cube/Workspace/MODBUS/Lib/lwprintf/src/include/lwprintf" -I"D:/STM32Cube/Workspace/MODBUS/Lib/lwprintf/src/include/system" -I"D:/STM32Cube/Workspace/MODBUS/Lib/lwbtn" -I"D:/STM32Cube/Workspace/MODBUS/Lib/lwbtn/src" -I"D:/STM32Cube/Workspace/MODBUS/Lib/lwbtn/src/include" -I"D:/STM32Cube/Workspace/MODBUS/Lib/lwbtn/src/include/lwbtn" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Lib-2f-lwrb-2f-src-2f-lwrb

clean-Lib-2f-lwrb-2f-src-2f-lwrb:
	-$(RM) ./Lib/lwrb/src/lwrb/lwrb.cyclo ./Lib/lwrb/src/lwrb/lwrb.d ./Lib/lwrb/src/lwrb/lwrb.o ./Lib/lwrb/src/lwrb/lwrb.su

.PHONY: clean-Lib-2f-lwrb-2f-src-2f-lwrb

