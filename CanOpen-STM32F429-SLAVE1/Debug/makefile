################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include CANopenNode_STM32/subdir.mk
-include CANopenNode/storage/subdir.mk
-include CANopenNode/extra/subdir.mk
-include CANopenNode/309/subdir.mk
-include CANopenNode/305/subdir.mk
-include CANopenNode/304/subdir.mk
-include CANopenNode/303/subdir.mk
-include CANopenNode/301/subdir.mk
-include CANopenNode/subdir.mk
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


BUILD_ARTIFACT_NAME := CanOpen-STM32F429-SLAVE1
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
CanOpen-STM32F429-SLAVE1.elf \

MAP_FILES += \
CanOpen-STM32F429-SLAVE1.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
CanOpen-STM32F429-SLAVE1.list \


# All Target
all: main-build

# Main-build Target
main-build: CanOpen-STM32F429-SLAVE1.elf secondary-outputs

# Tool invocations
CanOpen-STM32F429-SLAVE1.elf CanOpen-STM32F429-SLAVE1.map: $(OBJS) $(USER_OBJS) /home/mihneadorcu/Desktop/Licenta/CanOpen-STM32F429-SLAVE1/STM32F407VGTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "CanOpen-STM32F429-SLAVE1.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"/home/mihneadorcu/Desktop/Licenta/CanOpen-STM32F429-SLAVE1/STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="CanOpen-STM32F429-SLAVE1.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

CanOpen-STM32F429-SLAVE1.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "CanOpen-STM32F429-SLAVE1.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) CanOpen-STM32F429-SLAVE1.elf CanOpen-STM32F429-SLAVE1.list CanOpen-STM32F429-SLAVE1.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
