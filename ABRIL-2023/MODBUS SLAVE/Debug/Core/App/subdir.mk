################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/App/App.c 

OBJS += \
./Core/App/App.o 

C_DEPS += \
./Core/App/App.d 


# Each subdirectory must supply rules for building sources it contributes
Core/App/%.o Core/App/%.su Core/App/%.cyclo: ../Core/App/%.c Core/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"D:/STM32Cube/Workspace/MODBUS/Lib/nanoMODBUS" -I"D:/STM32Cube/Workspace/MODBUS/Core/App" -I"D:/STM32Cube/Workspace/MODBUS/Lib/rbuart" -I"D:/STM32Cube/Workspace/MODBUS/Lib/lwrb/src" -I"D:/STM32Cube/Workspace/MODBUS/Lib/lwrb/src/include" -I"D:/STM32Cube/Workspace/MODBUS/Lib/lwrb/src/include/lwrb" -I"D:/STM32Cube/Workspace/MODBUS/Lib/lwprintf" -I"D:/STM32Cube/Workspace/MODBUS/Lib/lwprintf/src" -I"D:/STM32Cube/Workspace/MODBUS/Lib/lwprintf/src/include" -I"D:/STM32Cube/Workspace/MODBUS/Lib/lwprintf/src/include/lwprintf" -I"D:/STM32Cube/Workspace/MODBUS/Lib/lwprintf/src/include/system" -I"D:/STM32Cube/Workspace/MODBUS/Lib/lwbtn" -I"D:/STM32Cube/Workspace/MODBUS/Lib/lwbtn/src" -I"D:/STM32Cube/Workspace/MODBUS/Lib/lwbtn/src/include" -I"D:/STM32Cube/Workspace/MODBUS/Lib/lwbtn/src/include/lwbtn" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-App

clean-Core-2f-App:
	-$(RM) ./Core/App/App.cyclo ./Core/App/App.d ./Core/App/App.o ./Core/App/App.su

.PHONY: clean-Core-2f-App

