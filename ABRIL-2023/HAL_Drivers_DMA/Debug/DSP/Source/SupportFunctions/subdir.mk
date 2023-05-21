################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DSP/Source/SupportFunctions/arm_copy_f32.c \
../DSP/Source/SupportFunctions/arm_copy_q15.c \
../DSP/Source/SupportFunctions/arm_copy_q31.c \
../DSP/Source/SupportFunctions/arm_copy_q7.c \
../DSP/Source/SupportFunctions/arm_fill_f32.c \
../DSP/Source/SupportFunctions/arm_fill_q15.c \
../DSP/Source/SupportFunctions/arm_fill_q31.c \
../DSP/Source/SupportFunctions/arm_fill_q7.c \
../DSP/Source/SupportFunctions/arm_float_to_q15.c \
../DSP/Source/SupportFunctions/arm_float_to_q31.c \
../DSP/Source/SupportFunctions/arm_float_to_q7.c \
../DSP/Source/SupportFunctions/arm_q15_to_float.c \
../DSP/Source/SupportFunctions/arm_q15_to_q31.c \
../DSP/Source/SupportFunctions/arm_q15_to_q7.c \
../DSP/Source/SupportFunctions/arm_q31_to_float.c \
../DSP/Source/SupportFunctions/arm_q31_to_q15.c \
../DSP/Source/SupportFunctions/arm_q31_to_q7.c \
../DSP/Source/SupportFunctions/arm_q7_to_float.c \
../DSP/Source/SupportFunctions/arm_q7_to_q15.c \
../DSP/Source/SupportFunctions/arm_q7_to_q31.c 

OBJS += \
./DSP/Source/SupportFunctions/arm_copy_f32.o \
./DSP/Source/SupportFunctions/arm_copy_q15.o \
./DSP/Source/SupportFunctions/arm_copy_q31.o \
./DSP/Source/SupportFunctions/arm_copy_q7.o \
./DSP/Source/SupportFunctions/arm_fill_f32.o \
./DSP/Source/SupportFunctions/arm_fill_q15.o \
./DSP/Source/SupportFunctions/arm_fill_q31.o \
./DSP/Source/SupportFunctions/arm_fill_q7.o \
./DSP/Source/SupportFunctions/arm_float_to_q15.o \
./DSP/Source/SupportFunctions/arm_float_to_q31.o \
./DSP/Source/SupportFunctions/arm_float_to_q7.o \
./DSP/Source/SupportFunctions/arm_q15_to_float.o \
./DSP/Source/SupportFunctions/arm_q15_to_q31.o \
./DSP/Source/SupportFunctions/arm_q15_to_q7.o \
./DSP/Source/SupportFunctions/arm_q31_to_float.o \
./DSP/Source/SupportFunctions/arm_q31_to_q15.o \
./DSP/Source/SupportFunctions/arm_q31_to_q7.o \
./DSP/Source/SupportFunctions/arm_q7_to_float.o \
./DSP/Source/SupportFunctions/arm_q7_to_q15.o \
./DSP/Source/SupportFunctions/arm_q7_to_q31.o 

C_DEPS += \
./DSP/Source/SupportFunctions/arm_copy_f32.d \
./DSP/Source/SupportFunctions/arm_copy_q15.d \
./DSP/Source/SupportFunctions/arm_copy_q31.d \
./DSP/Source/SupportFunctions/arm_copy_q7.d \
./DSP/Source/SupportFunctions/arm_fill_f32.d \
./DSP/Source/SupportFunctions/arm_fill_q15.d \
./DSP/Source/SupportFunctions/arm_fill_q31.d \
./DSP/Source/SupportFunctions/arm_fill_q7.d \
./DSP/Source/SupportFunctions/arm_float_to_q15.d \
./DSP/Source/SupportFunctions/arm_float_to_q31.d \
./DSP/Source/SupportFunctions/arm_float_to_q7.d \
./DSP/Source/SupportFunctions/arm_q15_to_float.d \
./DSP/Source/SupportFunctions/arm_q15_to_q31.d \
./DSP/Source/SupportFunctions/arm_q15_to_q7.d \
./DSP/Source/SupportFunctions/arm_q31_to_float.d \
./DSP/Source/SupportFunctions/arm_q31_to_q15.d \
./DSP/Source/SupportFunctions/arm_q31_to_q7.d \
./DSP/Source/SupportFunctions/arm_q7_to_float.d \
./DSP/Source/SupportFunctions/arm_q7_to_q15.d \
./DSP/Source/SupportFunctions/arm_q7_to_q31.d 


# Each subdirectory must supply rules for building sources it contributes
DSP/Source/SupportFunctions/%.o DSP/Source/SupportFunctions/%.su DSP/Source/SupportFunctions/%.cyclo: ../DSP/Source/SupportFunctions/%.c DSP/Source/SupportFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG '-D__FPU_PRESENT = 1' -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/HAL_Drivers_DMA/DSP/Include" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-DSP-2f-Source-2f-SupportFunctions

clean-DSP-2f-Source-2f-SupportFunctions:
	-$(RM) ./DSP/Source/SupportFunctions/arm_copy_f32.cyclo ./DSP/Source/SupportFunctions/arm_copy_f32.d ./DSP/Source/SupportFunctions/arm_copy_f32.o ./DSP/Source/SupportFunctions/arm_copy_f32.su ./DSP/Source/SupportFunctions/arm_copy_q15.cyclo ./DSP/Source/SupportFunctions/arm_copy_q15.d ./DSP/Source/SupportFunctions/arm_copy_q15.o ./DSP/Source/SupportFunctions/arm_copy_q15.su ./DSP/Source/SupportFunctions/arm_copy_q31.cyclo ./DSP/Source/SupportFunctions/arm_copy_q31.d ./DSP/Source/SupportFunctions/arm_copy_q31.o ./DSP/Source/SupportFunctions/arm_copy_q31.su ./DSP/Source/SupportFunctions/arm_copy_q7.cyclo ./DSP/Source/SupportFunctions/arm_copy_q7.d ./DSP/Source/SupportFunctions/arm_copy_q7.o ./DSP/Source/SupportFunctions/arm_copy_q7.su ./DSP/Source/SupportFunctions/arm_fill_f32.cyclo ./DSP/Source/SupportFunctions/arm_fill_f32.d ./DSP/Source/SupportFunctions/arm_fill_f32.o ./DSP/Source/SupportFunctions/arm_fill_f32.su ./DSP/Source/SupportFunctions/arm_fill_q15.cyclo ./DSP/Source/SupportFunctions/arm_fill_q15.d ./DSP/Source/SupportFunctions/arm_fill_q15.o ./DSP/Source/SupportFunctions/arm_fill_q15.su ./DSP/Source/SupportFunctions/arm_fill_q31.cyclo ./DSP/Source/SupportFunctions/arm_fill_q31.d ./DSP/Source/SupportFunctions/arm_fill_q31.o ./DSP/Source/SupportFunctions/arm_fill_q31.su ./DSP/Source/SupportFunctions/arm_fill_q7.cyclo ./DSP/Source/SupportFunctions/arm_fill_q7.d ./DSP/Source/SupportFunctions/arm_fill_q7.o ./DSP/Source/SupportFunctions/arm_fill_q7.su ./DSP/Source/SupportFunctions/arm_float_to_q15.cyclo ./DSP/Source/SupportFunctions/arm_float_to_q15.d ./DSP/Source/SupportFunctions/arm_float_to_q15.o ./DSP/Source/SupportFunctions/arm_float_to_q15.su ./DSP/Source/SupportFunctions/arm_float_to_q31.cyclo ./DSP/Source/SupportFunctions/arm_float_to_q31.d ./DSP/Source/SupportFunctions/arm_float_to_q31.o ./DSP/Source/SupportFunctions/arm_float_to_q31.su ./DSP/Source/SupportFunctions/arm_float_to_q7.cyclo ./DSP/Source/SupportFunctions/arm_float_to_q7.d ./DSP/Source/SupportFunctions/arm_float_to_q7.o ./DSP/Source/SupportFunctions/arm_float_to_q7.su ./DSP/Source/SupportFunctions/arm_q15_to_float.cyclo ./DSP/Source/SupportFunctions/arm_q15_to_float.d ./DSP/Source/SupportFunctions/arm_q15_to_float.o ./DSP/Source/SupportFunctions/arm_q15_to_float.su ./DSP/Source/SupportFunctions/arm_q15_to_q31.cyclo ./DSP/Source/SupportFunctions/arm_q15_to_q31.d ./DSP/Source/SupportFunctions/arm_q15_to_q31.o ./DSP/Source/SupportFunctions/arm_q15_to_q31.su ./DSP/Source/SupportFunctions/arm_q15_to_q7.cyclo ./DSP/Source/SupportFunctions/arm_q15_to_q7.d ./DSP/Source/SupportFunctions/arm_q15_to_q7.o ./DSP/Source/SupportFunctions/arm_q15_to_q7.su ./DSP/Source/SupportFunctions/arm_q31_to_float.cyclo ./DSP/Source/SupportFunctions/arm_q31_to_float.d ./DSP/Source/SupportFunctions/arm_q31_to_float.o ./DSP/Source/SupportFunctions/arm_q31_to_float.su ./DSP/Source/SupportFunctions/arm_q31_to_q15.cyclo ./DSP/Source/SupportFunctions/arm_q31_to_q15.d ./DSP/Source/SupportFunctions/arm_q31_to_q15.o ./DSP/Source/SupportFunctions/arm_q31_to_q15.su ./DSP/Source/SupportFunctions/arm_q31_to_q7.cyclo ./DSP/Source/SupportFunctions/arm_q31_to_q7.d ./DSP/Source/SupportFunctions/arm_q31_to_q7.o ./DSP/Source/SupportFunctions/arm_q31_to_q7.su ./DSP/Source/SupportFunctions/arm_q7_to_float.cyclo ./DSP/Source/SupportFunctions/arm_q7_to_float.d ./DSP/Source/SupportFunctions/arm_q7_to_float.o ./DSP/Source/SupportFunctions/arm_q7_to_float.su ./DSP/Source/SupportFunctions/arm_q7_to_q15.cyclo ./DSP/Source/SupportFunctions/arm_q7_to_q15.d ./DSP/Source/SupportFunctions/arm_q7_to_q15.o ./DSP/Source/SupportFunctions/arm_q7_to_q15.su ./DSP/Source/SupportFunctions/arm_q7_to_q31.cyclo ./DSP/Source/SupportFunctions/arm_q7_to_q31.d ./DSP/Source/SupportFunctions/arm_q7_to_q31.o ./DSP/Source/SupportFunctions/arm_q7_to_q31.su

.PHONY: clean-DSP-2f-Source-2f-SupportFunctions

