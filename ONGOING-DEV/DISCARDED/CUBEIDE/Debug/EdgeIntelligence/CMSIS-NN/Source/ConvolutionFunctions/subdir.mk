################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_1x1_HWC_q7_fast_nonsquare.c \
../EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q15_basic.c \
../EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q15_fast.c \
../EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q15_fast_nonsquare.c \
../EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_RGB.c \
../EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_basic.c \
../EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_basic_nonsquare.c \
../EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_fast.c \
../EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_fast_nonsquare.c \
../EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_depthwise_conv_u8_basic_ver1.c \
../EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7.c \
../EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7_nonsquare.c \
../EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15.c \
../EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15_reordered.c 

OBJS += \
./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_1x1_HWC_q7_fast_nonsquare.o \
./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q15_basic.o \
./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q15_fast.o \
./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q15_fast_nonsquare.o \
./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_RGB.o \
./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_basic.o \
./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_basic_nonsquare.o \
./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_fast.o \
./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_fast_nonsquare.o \
./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_depthwise_conv_u8_basic_ver1.o \
./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7.o \
./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7_nonsquare.o \
./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15.o \
./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15_reordered.o 

C_DEPS += \
./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_1x1_HWC_q7_fast_nonsquare.d \
./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q15_basic.d \
./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q15_fast.d \
./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q15_fast_nonsquare.d \
./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_RGB.d \
./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_basic.d \
./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_basic_nonsquare.d \
./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_fast.d \
./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_fast_nonsquare.d \
./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_depthwise_conv_u8_basic_ver1.d \
./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7.d \
./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7_nonsquare.d \
./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15.d \
./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15_reordered.d 


# Each subdirectory must supply rules for building sources it contributes
EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/%.o EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/%.su EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/%.cyclo: ../EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/%.c EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../FATFS/Target -I../FATFS/App -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"E:/DEV/MCU_NODE_STM32/ONGOING/FRONTIER/BSP" -I"E:/DEV/MCU_NODE_STM32/ONGOING/FRONTIER/Setup" -I"E:/DEV/MCU_NODE_STM32/ONGOING/FRONTIER/EdgeIntelligence/CMSIS-DSP/Include" -I"E:/DEV/MCU_NODE_STM32/ONGOING/FRONTIER/EdgeIntelligence/CMSIS-NN/Include" -I"E:/DEV/MCU_NODE_STM32/ONGOING/FRONTIER/TinySHM" -I"E:/DEV/MCU_NODE_STM32/ONGOING/FRONTIER/App" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-EdgeIntelligence-2f-CMSIS-2d-NN-2f-Source-2f-ConvolutionFunctions

clean-EdgeIntelligence-2f-CMSIS-2d-NN-2f-Source-2f-ConvolutionFunctions:
	-$(RM) ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_1x1_HWC_q7_fast_nonsquare.cyclo ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_1x1_HWC_q7_fast_nonsquare.d ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_1x1_HWC_q7_fast_nonsquare.o ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_1x1_HWC_q7_fast_nonsquare.su ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q15_basic.cyclo ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q15_basic.d ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q15_basic.o ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q15_basic.su ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q15_fast.cyclo ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q15_fast.d ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q15_fast.o ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q15_fast.su ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q15_fast_nonsquare.cyclo ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q15_fast_nonsquare.d ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q15_fast_nonsquare.o ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q15_fast_nonsquare.su ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_RGB.cyclo ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_RGB.d ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_RGB.o ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_RGB.su ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_basic.cyclo ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_basic.d ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_basic.o ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_basic.su ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_basic_nonsquare.cyclo ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_basic_nonsquare.d ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_basic_nonsquare.o ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_basic_nonsquare.su ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_fast.cyclo ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_fast.d ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_fast.o ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_fast.su ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_fast_nonsquare.cyclo ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_fast_nonsquare.d ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_fast_nonsquare.o ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_convolve_HWC_q7_fast_nonsquare.su ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_depthwise_conv_u8_basic_ver1.cyclo ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_depthwise_conv_u8_basic_ver1.d ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_depthwise_conv_u8_basic_ver1.o ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_depthwise_conv_u8_basic_ver1.su ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7.cyclo ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7.d ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7.o ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7.su ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7_nonsquare.cyclo ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7_nonsquare.d ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7_nonsquare.o ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_depthwise_separable_conv_HWC_q7_nonsquare.su ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15.cyclo ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15.d ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15.o ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15.su ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15_reordered.cyclo ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15_reordered.d ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15_reordered.o ./EdgeIntelligence/CMSIS-NN/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_q7_q15_reordered.su

.PHONY: clean-EdgeIntelligence-2f-CMSIS-2d-NN-2f-Source-2f-ConvolutionFunctions

