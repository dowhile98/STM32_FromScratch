################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/App/driver_mpu6050_basic.c \
../Core/App/driver_mpu6050_dmp.c \
../Core/App/driver_mpu6050_fifo.c 

OBJS += \
./Core/App/driver_mpu6050_basic.o \
./Core/App/driver_mpu6050_dmp.o \
./Core/App/driver_mpu6050_fifo.o 

C_DEPS += \
./Core/App/driver_mpu6050_basic.d \
./Core/App/driver_mpu6050_dmp.d \
./Core/App/driver_mpu6050_fifo.d 


# Each subdirectory must supply rules for building sources it contributes
Core/App/%.o Core/App/%.su Core/App/%.cyclo: ../Core/App/%.c Core/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/MPU650_LibDriver/Core/Inc" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/MPU650_LibDriver/Core/App" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/MPU650_LibDriver/Core/Components" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/MPU650_LibDriver/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/MPU650_LibDriver/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-App

clean-Core-2f-App:
	-$(RM) ./Core/App/driver_mpu6050_basic.cyclo ./Core/App/driver_mpu6050_basic.d ./Core/App/driver_mpu6050_basic.o ./Core/App/driver_mpu6050_basic.su ./Core/App/driver_mpu6050_dmp.cyclo ./Core/App/driver_mpu6050_dmp.d ./Core/App/driver_mpu6050_dmp.o ./Core/App/driver_mpu6050_dmp.su ./Core/App/driver_mpu6050_fifo.cyclo ./Core/App/driver_mpu6050_fifo.d ./Core/App/driver_mpu6050_fifo.o ./Core/App/driver_mpu6050_fifo.su

.PHONY: clean-Core-2f-App

