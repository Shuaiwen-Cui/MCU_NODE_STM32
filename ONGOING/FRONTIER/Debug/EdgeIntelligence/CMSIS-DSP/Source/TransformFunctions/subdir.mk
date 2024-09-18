################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/TransformFunctions.c \
../EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_bitreversal.c \
../EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_bitreversal2.c \
../EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_f32.c \
../EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_q15.c \
../EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_q31.c \
../EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_f32.c \
../EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_init_f32.c \
../EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_init_q15.c \
../EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_init_q31.c \
../EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_q15.c \
../EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_q31.c \
../EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_f32.c \
../EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_init_f32.c \
../EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_init_q15.c \
../EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_init_q31.c \
../EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_q15.c \
../EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_q31.c \
../EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix8_f32.c \
../EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_f32.c \
../EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_init_f32.c \
../EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_init_q15.c \
../EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_init_q31.c \
../EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_q15.c \
../EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_q31.c \
../EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_f32.c \
../EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_fast_f32.c \
../EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_fast_init_f32.c \
../EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_init_f32.c \
../EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_init_q15.c \
../EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_init_q31.c \
../EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_q15.c \
../EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_q31.c 

S_UPPER_SRCS += \
../EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_bitreversal2.S 

OBJS += \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/TransformFunctions.o \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_bitreversal.o \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_bitreversal2.o \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_f32.o \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_q15.o \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_q31.o \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_f32.o \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_init_f32.o \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_init_q15.o \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_init_q31.o \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_q15.o \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_q31.o \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_f32.o \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_init_f32.o \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_init_q15.o \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_init_q31.o \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_q15.o \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_q31.o \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix8_f32.o \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_f32.o \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_init_f32.o \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_init_q15.o \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_init_q31.o \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_q15.o \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_q31.o \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_f32.o \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_fast_f32.o \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_fast_init_f32.o \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_init_f32.o \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_init_q15.o \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_init_q31.o \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_q15.o \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_q31.o 

S_UPPER_DEPS += \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_bitreversal2.d 

C_DEPS += \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/TransformFunctions.d \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_bitreversal.d \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_bitreversal2.d \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_f32.d \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_q15.d \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_q31.d \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_f32.d \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_init_f32.d \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_init_q15.d \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_init_q31.d \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_q15.d \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_q31.d \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_f32.d \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_init_f32.d \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_init_q15.d \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_init_q31.d \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_q15.d \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_q31.d \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix8_f32.d \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_f32.d \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_init_f32.d \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_init_q15.d \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_init_q31.d \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_q15.d \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_q31.d \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_f32.d \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_fast_f32.d \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_fast_init_f32.d \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_init_f32.d \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_init_q15.d \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_init_q31.d \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_q15.d \
./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_q31.d 


# Each subdirectory must supply rules for building sources it contributes
EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/%.o EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/%.su EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/%.cyclo: ../EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/%.c EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../FATFS/Target -I../FATFS/App -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"E:/DEV/MCU_NODE_STM32/ONGOING/FRONTIER/BSP" -I"E:/DEV/MCU_NODE_STM32/ONGOING/FRONTIER/Setup" -I"E:/DEV/MCU_NODE_STM32/ONGOING/FRONTIER/EdgeIntelligence/CMSIS-DSP/Include" -I"E:/DEV/MCU_NODE_STM32/ONGOING/FRONTIER/EdgeIntelligence/CMSIS-NN/Include" -I"E:/DEV/MCU_NODE_STM32/ONGOING/FRONTIER/TinySHM" -I"E:/DEV/MCU_NODE_STM32/ONGOING/FRONTIER/App" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/%.o: ../EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/%.S EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-EdgeIntelligence-2f-CMSIS-2d-DSP-2f-Source-2f-TransformFunctions

clean-EdgeIntelligence-2f-CMSIS-2d-DSP-2f-Source-2f-TransformFunctions:
	-$(RM) ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/TransformFunctions.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/TransformFunctions.d ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/TransformFunctions.o ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/TransformFunctions.su ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_bitreversal.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_bitreversal.d ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_bitreversal.o ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_bitreversal.su ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_bitreversal2.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_bitreversal2.d ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_bitreversal2.o ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_bitreversal2.su ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_f32.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_f32.d ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_f32.o ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_f32.su ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_q15.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_q15.d ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_q15.o ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_q15.su ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_q31.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_q31.d ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_q31.o ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_q31.su ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_f32.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_f32.d ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_f32.o ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_f32.su ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_init_f32.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_init_f32.d ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_init_f32.o ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_init_f32.su ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_init_q15.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_init_q15.d ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_init_q15.o ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_init_q15.su ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_init_q31.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_init_q31.d ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_init_q31.o ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_init_q31.su ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_q15.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_q15.d ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_q15.o ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_q15.su ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_q31.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_q31.d ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_q31.o ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix2_q31.su ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_f32.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_f32.d ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_f32.o ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_f32.su ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_init_f32.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_init_f32.d ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_init_f32.o ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_init_f32.su ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_init_q15.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_init_q15.d ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_init_q15.o ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_init_q15.su ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_init_q31.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_init_q31.d ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_init_q31.o ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_init_q31.su ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_q15.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_q15.d ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_q15.o ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_q15.su ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_q31.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_q31.d ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_q31.o ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix4_q31.su ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix8_f32.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix8_f32.d ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix8_f32.o ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_cfft_radix8_f32.su
	-$(RM) ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_f32.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_f32.d ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_f32.o ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_f32.su ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_init_f32.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_init_f32.d ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_init_f32.o ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_init_f32.su ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_init_q15.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_init_q15.d ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_init_q15.o ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_init_q15.su ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_init_q31.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_init_q31.d ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_init_q31.o ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_init_q31.su ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_q15.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_q15.d ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_q15.o ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_q15.su ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_q31.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_q31.d ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_q31.o ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_dct4_q31.su ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_f32.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_f32.d ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_f32.o ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_f32.su ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_fast_f32.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_fast_f32.d ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_fast_f32.o ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_fast_f32.su ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_fast_init_f32.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_fast_init_f32.d ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_fast_init_f32.o ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_fast_init_f32.su ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_init_f32.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_init_f32.d ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_init_f32.o ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_init_f32.su ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_init_q15.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_init_q15.d ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_init_q15.o ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_init_q15.su ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_init_q31.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_init_q31.d ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_init_q31.o ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_init_q31.su ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_q15.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_q15.d ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_q15.o ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_q15.su ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_q31.cyclo ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_q31.d ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_q31.o ./EdgeIntelligence/CMSIS-DSP/Source/TransformFunctions/arm_rfft_q31.su

.PHONY: clean-EdgeIntelligence-2f-CMSIS-2d-DSP-2f-Source-2f-TransformFunctions

