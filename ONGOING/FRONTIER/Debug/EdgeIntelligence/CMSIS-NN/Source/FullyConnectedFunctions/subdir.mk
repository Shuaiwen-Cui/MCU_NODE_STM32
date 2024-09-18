################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_mat_q7_vec_q15.c \
../EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_mat_q7_vec_q15_opt.c \
../EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_q15.c \
../EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_q15_opt.c \
../EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_q7.c \
../EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_q7_opt.c 

OBJS += \
./EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_mat_q7_vec_q15.o \
./EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_mat_q7_vec_q15_opt.o \
./EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_q15.o \
./EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_q15_opt.o \
./EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_q7.o \
./EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_q7_opt.o 

C_DEPS += \
./EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_mat_q7_vec_q15.d \
./EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_mat_q7_vec_q15_opt.d \
./EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_q15.d \
./EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_q15_opt.d \
./EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_q7.d \
./EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_q7_opt.d 


# Each subdirectory must supply rules for building sources it contributes
EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/%.o EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/%.su EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/%.cyclo: ../EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/%.c EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../FATFS/Target -I../FATFS/App -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"E:/DEV/MCU_NODE_STM32/ONGOING/FRONTIER/BSP" -I"E:/DEV/MCU_NODE_STM32/ONGOING/FRONTIER/Setup" -I"E:/DEV/MCU_NODE_STM32/ONGOING/FRONTIER/EdgeIntelligence/CMSIS-DSP/Include" -I"E:/DEV/MCU_NODE_STM32/ONGOING/FRONTIER/EdgeIntelligence/CMSIS-NN/Include" -I"E:/DEV/MCU_NODE_STM32/ONGOING/FRONTIER/TinySHM" -I"E:/DEV/MCU_NODE_STM32/ONGOING/FRONTIER/App" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-EdgeIntelligence-2f-CMSIS-2d-NN-2f-Source-2f-FullyConnectedFunctions

clean-EdgeIntelligence-2f-CMSIS-2d-NN-2f-Source-2f-FullyConnectedFunctions:
	-$(RM) ./EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_mat_q7_vec_q15.cyclo ./EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_mat_q7_vec_q15.d ./EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_mat_q7_vec_q15.o ./EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_mat_q7_vec_q15.su ./EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_mat_q7_vec_q15_opt.cyclo ./EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_mat_q7_vec_q15_opt.d ./EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_mat_q7_vec_q15_opt.o ./EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_mat_q7_vec_q15_opt.su ./EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_q15.cyclo ./EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_q15.d ./EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_q15.o ./EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_q15.su ./EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_q15_opt.cyclo ./EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_q15_opt.d ./EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_q15_opt.o ./EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_q15_opt.su ./EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_q7.cyclo ./EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_q7.d ./EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_q7.o ./EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_q7.su ./EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_q7_opt.cyclo ./EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_q7_opt.d ./EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_q7_opt.o ./EdgeIntelligence/CMSIS-NN/Source/FullyConnectedFunctions/arm_fully_connected_q7_opt.su

.PHONY: clean-EdgeIntelligence-2f-CMSIS-2d-NN-2f-Source-2f-FullyConnectedFunctions

