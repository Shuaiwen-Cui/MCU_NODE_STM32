################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/ControllerFunctions.c \
../EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_init_f32.c \
../EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_init_q15.c \
../EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_init_q31.c \
../EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_reset_f32.c \
../EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_reset_q15.c \
../EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_reset_q31.c \
../EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_sin_cos_f32.c \
../EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_sin_cos_q31.c 

OBJS += \
./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/ControllerFunctions.o \
./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_init_f32.o \
./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_init_q15.o \
./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_init_q31.o \
./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_reset_f32.o \
./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_reset_q15.o \
./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_reset_q31.o \
./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_sin_cos_f32.o \
./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_sin_cos_q31.o 

C_DEPS += \
./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/ControllerFunctions.d \
./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_init_f32.d \
./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_init_q15.d \
./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_init_q31.d \
./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_reset_f32.d \
./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_reset_q15.d \
./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_reset_q31.d \
./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_sin_cos_f32.d \
./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_sin_cos_q31.d 


# Each subdirectory must supply rules for building sources it contributes
EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/%.o EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/%.su EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/%.cyclo: ../EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/%.c EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../FATFS/Target -I../FATFS/App -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"E:/DEV/MCU_NODE_STM32/ONGOING/FRONTIER/BSP" -I"E:/DEV/MCU_NODE_STM32/ONGOING/FRONTIER/Setup" -I"E:/DEV/MCU_NODE_STM32/ONGOING/FRONTIER/EdgeIntelligence/CMSIS-DSP/Include" -I"E:/DEV/MCU_NODE_STM32/ONGOING/FRONTIER/EdgeIntelligence/CMSIS-NN/Include" -I"E:/DEV/MCU_NODE_STM32/ONGOING/FRONTIER/TinySHM" -I"E:/DEV/MCU_NODE_STM32/ONGOING/FRONTIER/App" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-EdgeIntelligence-2f-CMSIS-2d-DSP-2f-Source-2f-ControllerFunctions

clean-EdgeIntelligence-2f-CMSIS-2d-DSP-2f-Source-2f-ControllerFunctions:
	-$(RM) ./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/ControllerFunctions.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/ControllerFunctions.d ./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/ControllerFunctions.o ./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/ControllerFunctions.su ./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_init_f32.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_init_f32.d ./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_init_f32.o ./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_init_f32.su ./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_init_q15.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_init_q15.d ./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_init_q15.o ./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_init_q15.su ./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_init_q31.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_init_q31.d ./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_init_q31.o ./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_init_q31.su ./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_reset_f32.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_reset_f32.d ./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_reset_f32.o ./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_reset_f32.su ./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_reset_q15.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_reset_q15.d ./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_reset_q15.o ./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_reset_q15.su ./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_reset_q31.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_reset_q31.d ./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_reset_q31.o ./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_pid_reset_q31.su ./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_sin_cos_f32.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_sin_cos_f32.d ./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_sin_cos_f32.o ./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_sin_cos_f32.su ./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_sin_cos_q31.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_sin_cos_q31.d ./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_sin_cos_q31.o ./EdgeIntelligence/CMSIS-DSP/Source/ControllerFunctions/arm_sin_cos_q31.su

.PHONY: clean-EdgeIntelligence-2f-CMSIS-2d-DSP-2f-Source-2f-ControllerFunctions

