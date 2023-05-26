################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Lib/ioLibrary_Driver/Internet/httpServer/subdir.mk
-include Lib/ioLibrary_Driver/Internet/TFTP/subdir.mk
-include Lib/ioLibrary_Driver/Internet/SNTP/subdir.mk
-include Lib/ioLibrary_Driver/Internet/SNMP/subdir.mk
-include Lib/ioLibrary_Driver/Internet/MQTT/MQTTPacket/src/subdir.mk
-include Lib/ioLibrary_Driver/Internet/MQTT/subdir.mk
-include Lib/ioLibrary_Driver/Internet/FTPServer/subdir.mk
-include Lib/ioLibrary_Driver/Internet/FTPClient/subdir.mk
-include Lib/ioLibrary_Driver/Internet/DNS/subdir.mk
-include Lib/ioLibrary_Driver/Internet/DHCP/subdir.mk
-include Lib/ioLibrary_Driver/Ethernet/W5500/subdir.mk
-include Lib/ioLibrary_Driver/Ethernet/W5300/subdir.mk
-include Lib/ioLibrary_Driver/Ethernet/W5200/subdir.mk
-include Lib/ioLibrary_Driver/Ethernet/W5100S/subdir.mk
-include Lib/ioLibrary_Driver/Ethernet/W5100/subdir.mk
-include Lib/ioLibrary_Driver/Ethernet/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include Core/Components/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := W5100
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
W5100.elf \

MAP_FILES += \
W5100.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
W5100.list \


# All Target
all: main-build

# Main-build Target
main-build: W5100.elf secondary-outputs

# Tool invocations
W5100.elf W5100.map: $(OBJS) $(USER_OBJS) D:\TRABAJO\UMAKER\CURSOS\ARM\ -\ NUCLEO\STM32_FromScratch\ABRIL-2023\W5100\STM32F407VGTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "W5100.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"D:\TRABAJO\UMAKER\CURSOS\ARM - NUCLEO\STM32_FromScratch\ABRIL-2023\W5100\STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="W5100.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

W5100.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "W5100.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) W5100.elf W5100.list W5100.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
