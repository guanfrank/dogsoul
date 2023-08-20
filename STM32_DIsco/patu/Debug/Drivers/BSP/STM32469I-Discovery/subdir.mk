################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/STM32469I-Discovery/stm32469i_discovery.c \
../Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_audio.c \
../Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_eeprom.c \
../Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_lcd.c \
../Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_qspi.c \
../Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_sd.c \
../Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_sdram.c \
../Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_ts.c 

OBJS += \
./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery.o \
./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_audio.o \
./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_eeprom.o \
./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_lcd.o \
./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_qspi.o \
./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_sd.o \
./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_sdram.o \
./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_ts.o 

C_DEPS += \
./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery.d \
./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_audio.d \
./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_eeprom.d \
./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_lcd.d \
./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_qspi.d \
./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_sd.d \
./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_sdram.d \
./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_ts.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM32469I-Discovery/%.o Drivers/BSP/STM32469I-Discovery/%.su Drivers/BSP/STM32469I-Discovery/%.cyclo: ../Drivers/BSP/STM32469I-Discovery/%.c Drivers/BSP/STM32469I-Discovery/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DUSE_HAL_DRIVER -DSTM32F469xx -c -I../Core/Inc -I../FATFS/Target -I../FATFS/App -I../USB_HOST/App -I../USB_HOST/Target -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/fg/STM32CubeIDE/workspace_1.12.1/patu/Drivers/BSP/STM32469I-Discovery" -I"C:/Users/fg/STM32CubeIDE/workspace_1.12.1/patu/Middlewares/ST/STM32_Audio/Addons/PDM/Inc" -I"C:/Users/fg/STM32CubeIDE/workspace_1.12.1/patu/PlatformPackage/RTE" -I"C:/Users/fg/STM32CubeIDE/workspace_1.12.1/patu/Application/Source" -I"C:/Users/fg/STM32CubeIDE/workspace_1.12.1/patu/sdk/mcu/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-STM32469I-2d-Discovery

clean-Drivers-2f-BSP-2f-STM32469I-2d-Discovery:
	-$(RM) ./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery.cyclo ./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery.d ./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery.o ./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery.su ./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_audio.cyclo ./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_audio.d ./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_audio.o ./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_audio.su ./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_eeprom.cyclo ./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_eeprom.d ./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_eeprom.o ./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_eeprom.su ./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_lcd.cyclo ./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_lcd.d ./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_lcd.o ./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_lcd.su ./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_qspi.cyclo ./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_qspi.d ./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_qspi.o ./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_qspi.su ./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_sd.cyclo ./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_sd.d ./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_sd.o ./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_sd.su ./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_sdram.cyclo ./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_sdram.d ./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_sdram.o ./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_sdram.su ./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_ts.cyclo ./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_ts.d ./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_ts.o ./Drivers/BSP/STM32469I-Discovery/stm32469i_discovery_ts.su

.PHONY: clean-Drivers-2f-BSP-2f-STM32469I-2d-Discovery

