################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include Components/ioLibrary_Driver/Internet/httpServer/subdir.mk
-include Components/ioLibrary_Driver/Internet/TFTP/subdir.mk
-include Components/ioLibrary_Driver/Internet/SNTP/subdir.mk
-include Components/ioLibrary_Driver/Internet/SNMP/subdir.mk
-include Components/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/subdir.mk
-include Components/ioLibrary_Driver/Internet/MQTT/subdir.mk
-include Components/ioLibrary_Driver/Internet/FTPServer/subdir.mk
-include Components/ioLibrary_Driver/Internet/FTPClient/subdir.mk
-include Components/ioLibrary_Driver/Internet/DNS/subdir.mk
-include Components/ioLibrary_Driver/Internet/DHCP/subdir.mk
-include Components/ioLibrary_Driver/Ethernet/W5500/subdir.mk
-include Components/ioLibrary_Driver/Ethernet/W5300/subdir.mk
-include Components/ioLibrary_Driver/Ethernet/W5200/subdir.mk
-include Components/ioLibrary_Driver/Ethernet/W5100S/subdir.mk
-include Components/ioLibrary_Driver/Ethernet/W5100/subdir.mk
-include Components/ioLibrary_Driver/Ethernet/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := ETH_MQTT_SPI
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
ETH_MQTT_SPI.elf \

MAP_FILES += \
ETH_MQTT_SPI.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
ETH_MQTT_SPI.list \

OBJCOPY_HEX += \
ETH_MQTT_SPI.hex \

OBJCOPY_BIN += \
ETH_MQTT_SPI.bin \


# All Target
all: main-build

# Main-build Target
main-build: ETH_MQTT_SPI.elf secondary-outputs

# Tool invocations
ETH_MQTT_SPI.elf ETH_MQTT_SPI.map: $(OBJS) $(USER_OBJS) D:\TRABAJO\UMAKER\CURSOS\ARM\ -\ NUCLEO\STM32_FromScratch\SETIEMBRE-2023\ETH_MQTT_SPI\STM32F407VGTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-g++ -o "ETH_MQTT_SPI.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"D:\TRABAJO\UMAKER\CURSOS\ARM - NUCLEO\STM32_FromScratch\SETIEMBRE-2023\ETH_MQTT_SPI\STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="ETH_MQTT_SPI.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -lstdc++ -lsupc++ -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

ETH_MQTT_SPI.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "ETH_MQTT_SPI.list"
	@echo 'Finished building: $@'
	@echo ' '

ETH_MQTT_SPI.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "ETH_MQTT_SPI.hex"
	@echo 'Finished building: $@'
	@echo ' '

ETH_MQTT_SPI.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "ETH_MQTT_SPI.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ETH_MQTT_SPI.bin ETH_MQTT_SPI.elf ETH_MQTT_SPI.hex ETH_MQTT_SPI.list ETH_MQTT_SPI.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
