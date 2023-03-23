################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/lwrb/src/lwrb/lwrb.c 

OBJS += \
./Middlewares/Third_Party/lwrb/src/lwrb/lwrb.o 

C_DEPS += \
./Middlewares/Third_Party/lwrb/src/lwrb/lwrb.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/lwrb/src/lwrb/%.o Middlewares/Third_Party/lwrb/src/lwrb/%.su Middlewares/Third_Party/lwrb/src/lwrb/%.cyclo: ../Middlewares/Third_Party/lwrb/src/lwrb/%.c Middlewares/Third_Party/lwrb/src/lwrb/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/USART_RING_BUFFER/Core/Inc" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/USART_RING_BUFFER/Middlewares/Third_Party/lwrb" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/USART_RING_BUFFER/Middlewares/Third_Party/lwrb/src" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/USART_RING_BUFFER/Middlewares/Third_Party/lwrb/src/include" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/USART_RING_BUFFER/Core/Components" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/USART_RING_BUFFER/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/USART_RING_BUFFER/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-lwrb-2f-src-2f-lwrb

clean-Middlewares-2f-Third_Party-2f-lwrb-2f-src-2f-lwrb:
	-$(RM) ./Middlewares/Third_Party/lwrb/src/lwrb/lwrb.cyclo ./Middlewares/Third_Party/lwrb/src/lwrb/lwrb.d ./Middlewares/Third_Party/lwrb/src/lwrb/lwrb.o ./Middlewares/Third_Party/lwrb/src/lwrb/lwrb.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-lwrb-2f-src-2f-lwrb

