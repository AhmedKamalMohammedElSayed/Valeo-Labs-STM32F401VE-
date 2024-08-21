################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include external_interrupt/subdir.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include RCC/subdir.mk
-include Nvic/subdir.mk
-include Gpio/subdir.mk
-include subdir.mk
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

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
external\ interrupt.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
external\ interrupt.list \

OBJCOPY_HEX += \
external\ interrupt.hex \

OBJCOPY_BIN += \
external\ interrupt.bin \


# All Target
all: external\ interrupt.elf secondary-outputs

# Tool invocations
external\ interrupt.elf: $(OBJS) $(USER_OBJS) G:\C\external\ interrupt\external\ interrupt\STM32F401VEHX_FLASH.ld
	arm-none-eabi-gcc -o "external interrupt.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"G:\C\external interrupt\external interrupt\STM32F401VEHX_FLASH.ld" --specs=nosys.specs -Wl,-Map="external interrupt.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

external\ interrupt.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "external interrupt.list"
	@echo 'Finished building: $@'
	@echo ' '

external\ interrupt.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "external interrupt.hex"
	@echo 'Finished building: $@'
	@echo ' '

external\ interrupt.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "external interrupt.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
