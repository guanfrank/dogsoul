################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32f469nihx.s 

<<<<<<<< HEAD:STM32_DIsco/patu/Debug/Core/Startup/subdir.mk
OBJS += \
./Core/Startup/startup_stm32f469nihx.o 

========
>>>>>>>> 4dfa1c8c6a4915b9bf21197640e1812902df8a12:STM32_DIsco/stm32f04Disc_Acc_EulerCalibrated/Debug/Core/Startup/subdir.mk
S_DEPS += \
./Core/Startup/startup_stm32f469nihx.d 

OBJS += \
./Core/Startup/startup_stm32f407vgtx.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/%.o: ../Core/Startup/%.s Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Core-2f-Startup

clean-Core-2f-Startup:
	-$(RM) ./Core/Startup/startup_stm32f469nihx.d ./Core/Startup/startup_stm32f469nihx.o

.PHONY: clean-Core-2f-Startup

