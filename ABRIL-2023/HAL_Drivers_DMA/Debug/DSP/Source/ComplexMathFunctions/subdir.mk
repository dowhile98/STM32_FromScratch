################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DSP/Source/ComplexMathFunctions/arm_cmplx_conj_f32.c \
../DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q15.c \
../DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q31.c \
../DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_f32.c \
../DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q15.c \
../DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q31.c \
../DSP/Source/ComplexMathFunctions/arm_cmplx_mag_f32.c \
../DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q15.c \
../DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q31.c \
../DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_f32.c \
../DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q15.c \
../DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q31.c \
../DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.c \
../DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.c \
../DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.c \
../DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_f32.c \
../DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q15.c \
../DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q31.c 

OBJS += \
./DSP/Source/ComplexMathFunctions/arm_cmplx_conj_f32.o \
./DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q15.o \
./DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q31.o \
./DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_f32.o \
./DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q15.o \
./DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q31.o \
./DSP/Source/ComplexMathFunctions/arm_cmplx_mag_f32.o \
./DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q15.o \
./DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q31.o \
./DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_f32.o \
./DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q15.o \
./DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q31.o \
./DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.o \
./DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.o \
./DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.o \
./DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_f32.o \
./DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q15.o \
./DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q31.o 

C_DEPS += \
./DSP/Source/ComplexMathFunctions/arm_cmplx_conj_f32.d \
./DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q15.d \
./DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q31.d \
./DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_f32.d \
./DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q15.d \
./DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q31.d \
./DSP/Source/ComplexMathFunctions/arm_cmplx_mag_f32.d \
./DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q15.d \
./DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q31.d \
./DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_f32.d \
./DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q15.d \
./DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q31.d \
./DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.d \
./DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.d \
./DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.d \
./DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_f32.d \
./DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q15.d \
./DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q31.d 


# Each subdirectory must supply rules for building sources it contributes
DSP/Source/ComplexMathFunctions/%.o DSP/Source/ComplexMathFunctions/%.su DSP/Source/ComplexMathFunctions/%.cyclo: ../DSP/Source/ComplexMathFunctions/%.c DSP/Source/ComplexMathFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG '-D__FPU_PRESENT = 1' -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/HAL_Drivers_DMA/DSP/Include" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-DSP-2f-Source-2f-ComplexMathFunctions

clean-DSP-2f-Source-2f-ComplexMathFunctions:
	-$(RM) ./DSP/Source/ComplexMathFunctions/arm_cmplx_conj_f32.cyclo ./DSP/Source/ComplexMathFunctions/arm_cmplx_conj_f32.d ./DSP/Source/ComplexMathFunctions/arm_cmplx_conj_f32.o ./DSP/Source/ComplexMathFunctions/arm_cmplx_conj_f32.su ./DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q15.cyclo ./DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q15.d ./DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q15.o ./DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q15.su ./DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q31.cyclo ./DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q31.d ./DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q31.o ./DSP/Source/ComplexMathFunctions/arm_cmplx_conj_q31.su ./DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_f32.cyclo ./DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_f32.d ./DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_f32.o ./DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_f32.su ./DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q15.cyclo ./DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q15.d ./DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q15.o ./DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q15.su ./DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q31.cyclo ./DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q31.d ./DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q31.o ./DSP/Source/ComplexMathFunctions/arm_cmplx_dot_prod_q31.su ./DSP/Source/ComplexMathFunctions/arm_cmplx_mag_f32.cyclo ./DSP/Source/ComplexMathFunctions/arm_cmplx_mag_f32.d ./DSP/Source/ComplexMathFunctions/arm_cmplx_mag_f32.o ./DSP/Source/ComplexMathFunctions/arm_cmplx_mag_f32.su ./DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q15.cyclo ./DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q15.d ./DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q15.o ./DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q15.su ./DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q31.cyclo ./DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q31.d ./DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q31.o ./DSP/Source/ComplexMathFunctions/arm_cmplx_mag_q31.su ./DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_f32.cyclo ./DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_f32.d ./DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_f32.o ./DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_f32.su ./DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q15.cyclo ./DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q15.d ./DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q15.o ./DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q15.su ./DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q31.cyclo ./DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q31.d ./DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q31.o ./DSP/Source/ComplexMathFunctions/arm_cmplx_mag_squared_q31.su ./DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.cyclo ./DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.d ./DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.o ./DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.su ./DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.cyclo ./DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.d ./DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.o ./DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.su ./DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.cyclo ./DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.d ./DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.o ./DSP/Source/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.su ./DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_f32.cyclo ./DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_f32.d ./DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_f32.o ./DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_f32.su ./DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q15.cyclo ./DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q15.d ./DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q15.o ./DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q15.su ./DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q31.cyclo ./DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q31.d ./DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q31.o ./DSP/Source/ComplexMathFunctions/arm_cmplx_mult_real_q31.su

.PHONY: clean-DSP-2f-Source-2f-ComplexMathFunctions

