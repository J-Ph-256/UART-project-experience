################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CMSIS/Core/Template/ARMv8-M/main_s.c \
../Drivers/CMSIS/Core/Template/ARMv8-M/tz_context.c 

OBJS += \
./Drivers/CMSIS/Core/Template/ARMv8-M/main_s.o \
./Drivers/CMSIS/Core/Template/ARMv8-M/tz_context.o 

C_DEPS += \
./Drivers/CMSIS/Core/Template/ARMv8-M/main_s.d \
./Drivers/CMSIS/Core/Template/ARMv8-M/tz_context.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/Core/Template/ARMv8-M/%.o Drivers/CMSIS/Core/Template/ARMv8-M/%.su Drivers/CMSIS/Core/Template/ARMv8-M/%.cyclo: ../Drivers/CMSIS/Core/Template/ARMv8-M/%.c Drivers/CMSIS/Core/Template/ARMv8-M/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F412Zx -c -I../Core/Inc -IC:/Users/james.phair/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/james.phair/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/james.phair/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/james.phair/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/CMSIS/Include -I"C:/Users/james.phair/STM32CubeIDE/workspace_1.18.2/NEWUARTPROJECT/Drivers" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-CMSIS-2f-Core-2f-Template-2f-ARMv8-2d-M

clean-Drivers-2f-CMSIS-2f-Core-2f-Template-2f-ARMv8-2d-M:
	-$(RM) ./Drivers/CMSIS/Core/Template/ARMv8-M/main_s.cyclo ./Drivers/CMSIS/Core/Template/ARMv8-M/main_s.d ./Drivers/CMSIS/Core/Template/ARMv8-M/main_s.o ./Drivers/CMSIS/Core/Template/ARMv8-M/main_s.su ./Drivers/CMSIS/Core/Template/ARMv8-M/tz_context.cyclo ./Drivers/CMSIS/Core/Template/ARMv8-M/tz_context.d ./Drivers/CMSIS/Core/Template/ARMv8-M/tz_context.o ./Drivers/CMSIS/Core/Template/ARMv8-M/tz_context.su

.PHONY: clean-Drivers-2f-CMSIS-2f-Core-2f-Template-2f-ARMv8-2d-M

