################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Lib/mpu6050/driver_mpu6050.c 

OBJS += \
./Lib/mpu6050/driver_mpu6050.o 

C_DEPS += \
./Lib/mpu6050/driver_mpu6050.d 


# Each subdirectory must supply rules for building sources it contributes
Lib/mpu6050/%.o Lib/mpu6050/%.su Lib/mpu6050/%.cyclo: ../Lib/mpu6050/%.c Lib/mpu6050/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"D:/STM32Cube/Workspace/MPU6050/Core/App" -I"D:/STM32Cube/Workspace/MPU6050/Core/Component" -I"D:/STM32Cube/Workspace/MPU6050/Lib/mpu6050" -I"D:/STM32Cube/Workspace/MPU6050/Lib/lwprintf" -I"D:/STM32Cube/Workspace/MPU6050/Lib/lwprintf/src" -I"D:/STM32Cube/Workspace/MPU6050/Lib/lwprintf/src/include" -I"D:/STM32Cube/Workspace/MPU6050/Lib/lwprintf/src/include/lwprintf" -I"D:/STM32Cube/Workspace/MPU6050/Core/Component" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Lib-2f-mpu6050

clean-Lib-2f-mpu6050:
	-$(RM) ./Lib/mpu6050/driver_mpu6050.cyclo ./Lib/mpu6050/driver_mpu6050.d ./Lib/mpu6050/driver_mpu6050.o ./Lib/mpu6050/driver_mpu6050.su

.PHONY: clean-Lib-2f-mpu6050

