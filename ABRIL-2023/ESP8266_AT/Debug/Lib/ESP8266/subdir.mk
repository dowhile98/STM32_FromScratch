################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Lib/ESP8266/buffer.c \
../Lib/ESP8266/esp8266.c \
../Lib/ESP8266/esp8266_ll.c 

OBJS += \
./Lib/ESP8266/buffer.o \
./Lib/ESP8266/esp8266.o \
./Lib/ESP8266/esp8266_ll.o 

C_DEPS += \
./Lib/ESP8266/buffer.d \
./Lib/ESP8266/esp8266.d \
./Lib/ESP8266/esp8266_ll.d 


# Each subdirectory must supply rules for building sources it contributes
Lib/ESP8266/%.o Lib/ESP8266/%.su Lib/ESP8266/%.cyclo: ../Lib/ESP8266/%.c Lib/ESP8266/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/ESP8266_AT/Lib/ESP8266" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Lib-2f-ESP8266

clean-Lib-2f-ESP8266:
	-$(RM) ./Lib/ESP8266/buffer.cyclo ./Lib/ESP8266/buffer.d ./Lib/ESP8266/buffer.o ./Lib/ESP8266/buffer.su ./Lib/ESP8266/esp8266.cyclo ./Lib/ESP8266/esp8266.d ./Lib/ESP8266/esp8266.o ./Lib/ESP8266/esp8266.su ./Lib/ESP8266/esp8266_ll.cyclo ./Lib/ESP8266/esp8266_ll.d ./Lib/ESP8266/esp8266_ll.o ./Lib/ESP8266/esp8266_ll.su

.PHONY: clean-Lib-2f-ESP8266

