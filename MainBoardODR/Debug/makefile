################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F3xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
MainBoardODR.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
MainBoardODR.list \

OBJCOPY_HEX += \
MainBoardODR.hex \


# All Target
all: MainBoardODR.elf secondary-outputs

# Tool invocations
MainBoardODR.elf: $(OBJS) $(USER_OBJS) C:\Users\Jonathan\Documents\GitHub\Terminator\MainBoardODR\STM32F334K8TX_FLASH.ld
	arm-none-eabi-gcc -o "MainBoardODR.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\Jonathan\Documents\GitHub\Terminator\MainBoardODR\STM32F334K8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="MainBoardODR.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

MainBoardODR.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "MainBoardODR.list"
	@echo 'Finished building: $@'
	@echo ' '

MainBoardODR.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "MainBoardODR.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
