################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSP/bsp_file.c \
../BSP/bsp_led.c \
../BSP/bsp_memory.c \
../BSP/bsp_sdcard.c \
../BSP/bsp_sdram.c \
../BSP/bsp_usart.c 

OBJS += \
./BSP/bsp_file.o \
./BSP/bsp_led.o \
./BSP/bsp_memory.o \
./BSP/bsp_sdcard.o \
./BSP/bsp_sdram.o \
./BSP/bsp_usart.o 

C_DEPS += \
./BSP/bsp_file.d \
./BSP/bsp_led.d \
./BSP/bsp_memory.d \
./BSP/bsp_sdcard.d \
./BSP/bsp_sdram.d \
./BSP/bsp_usart.d 


# Each subdirectory must supply rules for building sources it contributes
BSP/%.o BSP/%.su BSP/%.cyclo: ../BSP/%.c BSP/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../FATFS/Target -I../FATFS/App -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"E:/DEV/MCU_NODE_STM32/ONGOING/FRONTIER/BSP" -I"E:/DEV/MCU_NODE_STM32/ONGOING/FRONTIER/Setup" -I"E:/DEV/MCU_NODE_STM32/ONGOING/FRONTIER/EdgeIntelligence/CMSIS-DSP/Include" -I"E:/DEV/MCU_NODE_STM32/ONGOING/FRONTIER/EdgeIntelligence/CMSIS-NN/Include" -I"E:/DEV/MCU_NODE_STM32/ONGOING/FRONTIER/TinySHM" -I"E:/DEV/MCU_NODE_STM32/ONGOING/FRONTIER/App" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-BSP

clean-BSP:
	-$(RM) ./BSP/bsp_file.cyclo ./BSP/bsp_file.d ./BSP/bsp_file.o ./BSP/bsp_file.su ./BSP/bsp_led.cyclo ./BSP/bsp_led.d ./BSP/bsp_led.o ./BSP/bsp_led.su ./BSP/bsp_memory.cyclo ./BSP/bsp_memory.d ./BSP/bsp_memory.o ./BSP/bsp_memory.su ./BSP/bsp_sdcard.cyclo ./BSP/bsp_sdcard.d ./BSP/bsp_sdcard.o ./BSP/bsp_sdcard.su ./BSP/bsp_sdram.cyclo ./BSP/bsp_sdram.d ./BSP/bsp_sdram.o ./BSP/bsp_sdram.su ./BSP/bsp_usart.cyclo ./BSP/bsp_usart.d ./BSP/bsp_usart.o ./BSP/bsp_usart.su

.PHONY: clean-BSP

