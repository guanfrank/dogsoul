################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/STM32F4-Discovery/stm32f4_discovery.c \
../Drivers/BSP/STM32F4-Discovery/stm32f4_discovery_audio.c 

OBJS += \
./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery.o \
./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery_audio.o 

C_DEPS += \
./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery.d \
./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery_audio.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM32F4-Discovery/%.o Drivers/BSP/STM32F4-Discovery/%.su Drivers/BSP/STM32F4-Discovery/%.cyclo: ../Drivers/BSP/STM32F4-Discovery/%.c Drivers/BSP/STM32F4-Discovery/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F469xx -c -I"C:/Users/fg/STM32CubeIDE/workspace_1.12.1/patu/sdk/mcu/include" -I../Core/Inc -I../FATFS/Target -I../FATFS/App -I../USB_HOST/App -I../USB_HOST/Target -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/fg/STM32CubeIDE/workspace_1.12.1/patu/Drivers/BSP/STM32F4-Discovery" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-STM32F4-2d-Discovery

clean-Drivers-2f-BSP-2f-STM32F4-2d-Discovery:
	-$(RM) ./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery.cyclo ./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery.d ./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery.o ./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery.su ./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery_audio.cyclo ./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery_audio.d ./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery_audio.o ./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery_audio.su

.PHONY: clean-Drivers-2f-BSP-2f-STM32F4-2d-Discovery

