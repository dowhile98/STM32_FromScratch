################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Component/driver_mpu6050_interface_stm32.c 

OBJS += \
./Core/Component/driver_mpu6050_interface_stm32.o 

C_DEPS += \
./Core/Component/driver_mpu6050_interface_stm32.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Component/%.o Core/Component/%.su Core/Component/%.cyclo: ../Core/Component/%.c Core/Component/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"D:/STM32Cube/Workspace/MPU6050/Core/App" -I"D:/STM32Cube/Workspace/MPU6050/Core/Component" -I"D:/STM32Cube/Workspace/MPU6050/Lib/mpu6050" -I"D:/STM32Cube/Workspace/MPU6050/Lib/lwprintf" -I"D:/STM32Cube/Workspace/MPU6050/Lib/lwprintf/src" -I"D:/STM32Cube/Workspace/MPU6050/Lib/lwprintf/src/include" -I"D:/STM32Cube/Workspace/MPU6050/Lib/lwprintf/src/include/lwprintf" -I"D:/STM32Cube/Workspace/MPU6050/Core/Component" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Component

clean-Core-2f-Component:
	-$(RM) ./Core/Component/driver_mpu6050_interface_stm32.cyclo ./Core/Component/driver_mpu6050_interface_stm32.d ./Core/Component/driver_mpu6050_interface_stm32.o ./Core/Component/driver_mpu6050_interface_stm32.su

.PHONY: clean-Core-2f-Component

