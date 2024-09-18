################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../EdgeIntelligence/CMSIS-DSP/Source/CommonTables/CommonTables.c \
../EdgeIntelligence/CMSIS-DSP/Source/CommonTables/arm_common_tables.c \
../EdgeIntelligence/CMSIS-DSP/Source/CommonTables/arm_const_structs.c 

OBJS += \
./EdgeIntelligence/CMSIS-DSP/Source/CommonTables/CommonTables.o \
./EdgeIntelligence/CMSIS-DSP/Source/CommonTables/arm_common_tables.o \
./EdgeIntelligence/CMSIS-DSP/Source/CommonTables/arm_const_structs.o 

C_DEPS += \
./EdgeIntelligence/CMSIS-DSP/Source/CommonTables/CommonTables.d \
./EdgeIntelligence/CMSIS-DSP/Source/CommonTables/arm_common_tables.d \
./EdgeIntelligence/CMSIS-DSP/Source/CommonTables/arm_const_structs.d 


# Each subdirectory must supply rules for building sources it contributes
EdgeIntelligence/CMSIS-DSP/Source/CommonTables/%.o EdgeIntelligence/CMSIS-DSP/Source/CommonTables/%.su EdgeIntelligence/CMSIS-DSP/Source/CommonTables/%.cyclo: ../EdgeIntelligence/CMSIS-DSP/Source/CommonTables/%.c EdgeIntelligence/CMSIS-DSP/Source/CommonTables/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../FATFS/Target -I../FATFS/App -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"E:/DEV/MCU_NODE_STM32/ONGOING/FRONTIER/BSP" -I"E:/DEV/MCU_NODE_STM32/ONGOING/FRONTIER/Setup" -I"E:/DEV/MCU_NODE_STM32/ONGOING/FRONTIER/EdgeIntelligence/CMSIS-DSP/Include" -I"E:/DEV/MCU_NODE_STM32/ONGOING/FRONTIER/EdgeIntelligence/CMSIS-NN/Include" -I"E:/DEV/MCU_NODE_STM32/ONGOING/FRONTIER/TinySHM" -I"E:/DEV/MCU_NODE_STM32/ONGOING/FRONTIER/App" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-EdgeIntelligence-2f-CMSIS-2d-DSP-2f-Source-2f-CommonTables

clean-EdgeIntelligence-2f-CMSIS-2d-DSP-2f-Source-2f-CommonTables:
	-$(RM) ./EdgeIntelligence/CMSIS-DSP/Source/CommonTables/CommonTables.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/CommonTables/CommonTables.d ./EdgeIntelligence/CMSIS-DSP/Source/CommonTables/CommonTables.o ./EdgeIntelligence/CMSIS-DSP/Source/CommonTables/CommonTables.su ./EdgeIntelligence/CMSIS-DSP/Source/CommonTables/arm_common_tables.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/CommonTables/arm_common_tables.d ./EdgeIntelligence/CMSIS-DSP/Source/CommonTables/arm_common_tables.o ./EdgeIntelligence/CMSIS-DSP/Source/CommonTables/arm_common_tables.su ./EdgeIntelligence/CMSIS-DSP/Source/CommonTables/arm_const_structs.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/CommonTables/arm_const_structs.d ./EdgeIntelligence/CMSIS-DSP/Source/CommonTables/arm_const_structs.o ./EdgeIntelligence/CMSIS-DSP/Source/CommonTables/arm_const_structs.su

.PHONY: clean-EdgeIntelligence-2f-CMSIS-2d-DSP-2f-Source-2f-CommonTables

