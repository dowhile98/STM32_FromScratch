################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Lib/ioLibrary_Driver/Internet/TFTP/netutil.c \
../Lib/ioLibrary_Driver/Internet/TFTP/tftp.c 

OBJS += \
./Lib/ioLibrary_Driver/Internet/TFTP/netutil.o \
./Lib/ioLibrary_Driver/Internet/TFTP/tftp.o 

C_DEPS += \
./Lib/ioLibrary_Driver/Internet/TFTP/netutil.d \
./Lib/ioLibrary_Driver/Internet/TFTP/tftp.d 


# Each subdirectory must supply rules for building sources it contributes
Lib/ioLibrary_Driver/Internet/TFTP/%.o Lib/ioLibrary_Driver/Internet/TFTP/%.su Lib/ioLibrary_Driver/Internet/TFTP/%.cyclo: ../Lib/ioLibrary_Driver/Internet/TFTP/%.c Lib/ioLibrary_Driver/Internet/TFTP/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/W5100/Core/Components" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/W5100/Lib/ioLibrary_Driver" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/W5100/Lib/ioLibrary_Driver/Ethernet" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/W5100/Lib/ioLibrary_Driver/Ethernet/W5100" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/W5100/Lib/ioLibrary_Driver/Ethernet/W5100S" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/W5100/Lib/ioLibrary_Driver/Ethernet/W5200" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/W5100/Lib/ioLibrary_Driver/Ethernet/W5300" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/W5100/Lib/ioLibrary_Driver/Ethernet/W5500" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/W5100/Lib/ioLibrary_Driver/Internet" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/W5100/Lib/ioLibrary_Driver/Internet/DHCP" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/W5100/Lib/ioLibrary_Driver/Internet/DNS" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/W5100/Lib/ioLibrary_Driver/Internet/FTPClient" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/W5100/Lib/ioLibrary_Driver/Internet/FTPServer" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/W5100/Lib/ioLibrary_Driver/Internet/httpServer" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/W5100/Lib/ioLibrary_Driver/Internet/MQTT" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/W5100/Lib/ioLibrary_Driver/Internet/SNMP" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/W5100/Lib/ioLibrary_Driver/Internet/SNTP" -I"D:/TRABAJO/UMAKER/CURSOS/ARM - NUCLEO/STM32_FromScratch/ABRIL-2023/W5100/Lib/ioLibrary_Driver/Internet/TFTP" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Lib-2f-ioLibrary_Driver-2f-Internet-2f-TFTP

clean-Lib-2f-ioLibrary_Driver-2f-Internet-2f-TFTP:
	-$(RM) ./Lib/ioLibrary_Driver/Internet/TFTP/netutil.cyclo ./Lib/ioLibrary_Driver/Internet/TFTP/netutil.d ./Lib/ioLibrary_Driver/Internet/TFTP/netutil.o ./Lib/ioLibrary_Driver/Internet/TFTP/netutil.su ./Lib/ioLibrary_Driver/Internet/TFTP/tftp.cyclo ./Lib/ioLibrary_Driver/Internet/TFTP/tftp.d ./Lib/ioLibrary_Driver/Internet/TFTP/tftp.o ./Lib/ioLibrary_Driver/Internet/TFTP/tftp.su

.PHONY: clean-Lib-2f-ioLibrary_Driver-2f-Internet-2f-TFTP

