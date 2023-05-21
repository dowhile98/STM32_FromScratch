################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DSP/Source/CommonTables/arm_common_tables.c \
../DSP/Source/CommonTables/arm_const_structs.c 

OBJS += \
./DSP/Source/CommonTables/arm_common_tables.o \
./DSP/Source/CommonTables/arm_const_structs.o 

C_DEPS += \
./DSP/Source/CommonTables/arm_common_tables.d \
./DSP/Source/CommonTables/arm_const_structs.d 


# Each subdirectory must supply rules for building sources it contributes
DSP/Source/CommonTables/%.o DSP/Source/CommonTables/%.su DSP/Source/CommonTables/%.cyclo: ../DSP/Source/CommonTables/%.c DSP/Source/CommonTables/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG '-D__FPU_PRESENT = 1' -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/HAL_Drivers_DMA/DSP/Include" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-DSP-2f-Source-2f-CommonTables

clean-DSP-2f-Source-2f-CommonTables:
	-$(RM) ./DSP/Source/CommonTables/arm_common_tables.cyclo ./DSP/Source/CommonTables/arm_common_tables.d ./DSP/Source/CommonTables/arm_common_tables.o ./DSP/Source/CommonTables/arm_common_tables.su ./DSP/Source/CommonTables/arm_const_structs.cyclo ./DSP/Source/CommonTables/arm_const_structs.d ./DSP/Source/CommonTables/arm_const_structs.o ./DSP/Source/CommonTables/arm_const_structs.su

.PHONY: clean-DSP-2f-Source-2f-CommonTables

