################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Lib/lwprintf/src/system/lwprintf_sys_cmsis_os.c \
../Lib/lwprintf/src/system/lwprintf_sys_threadx.c \
../Lib/lwprintf/src/system/lwprintf_sys_win32.c 

OBJS += \
./Lib/lwprintf/src/system/lwprintf_sys_cmsis_os.o \
./Lib/lwprintf/src/system/lwprintf_sys_threadx.o \
./Lib/lwprintf/src/system/lwprintf_sys_win32.o 

C_DEPS += \
./Lib/lwprintf/src/system/lwprintf_sys_cmsis_os.d \
./Lib/lwprintf/src/system/lwprintf_sys_threadx.d \
./Lib/lwprintf/src/system/lwprintf_sys_win32.d 


# Each subdirectory must supply rules for building sources it contributes
Lib/lwprintf/src/system/%.o Lib/lwprintf/src/system/%.su Lib/lwprintf/src/system/%.cyclo: ../Lib/lwprintf/src/system/%.c Lib/lwprintf/src/system/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"D:/STM32Cube/Workspace/MPU6050/Core/App" -I"D:/STM32Cube/Workspace/MPU6050/Core/Component" -I"D:/STM32Cube/Workspace/MPU6050/Lib/mpu6050" -I"D:/STM32Cube/Workspace/MPU6050/Lib/lwprintf" -I"D:/STM32Cube/Workspace/MPU6050/Lib/lwprintf/src" -I"D:/STM32Cube/Workspace/MPU6050/Lib/lwprintf/src/include" -I"D:/STM32Cube/Workspace/MPU6050/Lib/lwprintf/src/include/lwprintf" -I"D:/STM32Cube/Workspace/MPU6050/Core/Component" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Lib-2f-lwprintf-2f-src-2f-system

clean-Lib-2f-lwprintf-2f-src-2f-system:
	-$(RM) ./Lib/lwprintf/src/system/lwprintf_sys_cmsis_os.cyclo ./Lib/lwprintf/src/system/lwprintf_sys_cmsis_os.d ./Lib/lwprintf/src/system/lwprintf_sys_cmsis_os.o ./Lib/lwprintf/src/system/lwprintf_sys_cmsis_os.su ./Lib/lwprintf/src/system/lwprintf_sys_threadx.cyclo ./Lib/lwprintf/src/system/lwprintf_sys_threadx.d ./Lib/lwprintf/src/system/lwprintf_sys_threadx.o ./Lib/lwprintf/src/system/lwprintf_sys_threadx.su ./Lib/lwprintf/src/system/lwprintf_sys_win32.cyclo ./Lib/lwprintf/src/system/lwprintf_sys_win32.d ./Lib/lwprintf/src/system/lwprintf_sys_win32.o ./Lib/lwprintf/src/system/lwprintf_sys_win32.su

.PHONY: clean-Lib-2f-lwprintf-2f-src-2f-system

