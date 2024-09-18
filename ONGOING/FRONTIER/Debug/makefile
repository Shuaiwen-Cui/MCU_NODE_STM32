################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Setup/subdir.mk
-include Middlewares/Third_Party/FatFs/src/option/subdir.mk
-include Middlewares/Third_Party/FatFs/src/subdir.mk
-include FATFS/Target/subdir.mk
-include FATFS/App/subdir.mk
-include EdgeIntelligence/CMSIS-NN/Source/SoftmaxFunctions/subdir.mk
-include EdgeIntelligence/CMSIS-NN/Source/PoolingFunctions/subdir.mk
-include EdgeIntelligence/CMSIS-NN/Source/NNSupportFunctions/subdir.mk
-include EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/subdir.mk
-include EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/subdir.mk
-include EdgeIntelligence/CMSIS-NN/Source/ActivationFunctions/subdir.mk
-include EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/subdir.mk
-include EdgeIntelligence/CMSIS-DSP/Source/SupportFunctions/subdir.mk
-include EdgeIntelligence/CMSIS-DSP/Source/StatisticsFunctions/subdir.mk
-include EdgeIntelligence/CMSIS-DSP/Source/MatrixFunctions/subdir.mk
-include EdgeIntelligence/CMSIS-DSP/Source/FilteringFunctions/subdir.mk
-include EdgeIntelligence/CMSIS-DSP/Source/FastMathFunctions/subdir.mk
-include EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/subdir.mk
-include EdgeIntelligence/CMSIS-DSP/Source/ComplexMathFunctions/subdir.mk
-include EdgeIntelligence/CMSIS-DSP/Source/CommonTables/subdir.mk
-include EdgeIntelligence/CMSIS-DSP/Source/BasicMathFunctions/subdir.mk
-include Drivers/STM32H7xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include BSP/subdir.mk
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


BUILD_ARTIFACT_NAME := PROJECT
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
PROJECT.elf \

MAP_FILES += \
PROJECT.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
PROJECT.list \


# All Target
all: main-build

# Main-build Target
main-build: PROJECT.elf secondary-outputs

# Tool invocations
PROJECT.elf PROJECT.map: $(OBJS) $(USER_OBJS) E:\DEV\MCU_NODE_STM32\ONGOING\FRONTIER\STM32H743IITX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "PROJECT.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"E:\DEV\MCU_NODE_STM32\ONGOING\FRONTIER\STM32H743IITX_FLASH.ld" --specs=nosys.specs -Wl,-Map="PROJECT.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

PROJECT.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "PROJECT.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) PROJECT.elf PROJECT.list PROJECT.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
