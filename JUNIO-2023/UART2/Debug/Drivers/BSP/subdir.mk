################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/GPIO.c \
../Drivers/BSP/HD44780.c \
../Drivers/BSP/HD44780_Driver.c \
../Drivers/BSP/SysTick.c \
../Drivers/BSP/UART.c 

OBJS += \
./Drivers/BSP/GPIO.o \
./Drivers/BSP/HD44780.o \
./Drivers/BSP/HD44780_Driver.o \
./Drivers/BSP/SysTick.o \
./Drivers/BSP/UART.o 

C_DEPS += \
./Drivers/BSP/GPIO.d \
./Drivers/BSP/HD44780.d \
./Drivers/BSP/HD44780_Driver.d \
./Drivers/BSP/SysTick.d \
./Drivers/BSP/UART.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/%.o Drivers/BSP/%.su Drivers/BSP/%.cyclo: ../Drivers/BSP/%.c Drivers/BSP/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/JUNIO-2023/UART2/Core/Inc" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/JUNIO-2023/UART2/Lib/nanoModbus" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/JUNIO-2023/UART2/Lib/lwrb/src/include" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/JUNIO-2023/UART2/Lib/lwrb/src/include/lwrb" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/JUNIO-2023/UART2/Drivers/BSP" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/JUNIO-2023/UART2/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/JUNIO-2023/UART2/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP

clean-Drivers-2f-BSP:
	-$(RM) ./Drivers/BSP/GPIO.cyclo ./Drivers/BSP/GPIO.d ./Drivers/BSP/GPIO.o ./Drivers/BSP/GPIO.su ./Drivers/BSP/HD44780.cyclo ./Drivers/BSP/HD44780.d ./Drivers/BSP/HD44780.o ./Drivers/BSP/HD44780.su ./Drivers/BSP/HD44780_Driver.cyclo ./Drivers/BSP/HD44780_Driver.d ./Drivers/BSP/HD44780_Driver.o ./Drivers/BSP/HD44780_Driver.su ./Drivers/BSP/SysTick.cyclo ./Drivers/BSP/SysTick.d ./Drivers/BSP/SysTick.o ./Drivers/BSP/SysTick.su ./Drivers/BSP/UART.cyclo ./Drivers/BSP/UART.d ./Drivers/BSP/UART.o ./Drivers/BSP/UART.su

.PHONY: clean-Drivers-2f-BSP

