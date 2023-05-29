################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Inc/ds18b20.c \
../Core/Inc/onewire.c \
../Core/Inc/ssd1306.c \
../Core/Inc/ssd1306_font.c 

OBJS += \
./Core/Inc/ds18b20.o \
./Core/Inc/onewire.o \
./Core/Inc/ssd1306.o \
./Core/Inc/ssd1306_font.o 

C_DEPS += \
./Core/Inc/ds18b20.d \
./Core/Inc/onewire.d \
./Core/Inc/ssd1306.d \
./Core/Inc/ssd1306_font.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/%.o Core/Inc/%.su Core/Inc/%.cyclo: ../Core/Inc/%.c Core/Inc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc

clean-Core-2f-Inc:
	-$(RM) ./Core/Inc/ds18b20.cyclo ./Core/Inc/ds18b20.d ./Core/Inc/ds18b20.o ./Core/Inc/ds18b20.su ./Core/Inc/onewire.cyclo ./Core/Inc/onewire.d ./Core/Inc/onewire.o ./Core/Inc/onewire.su ./Core/Inc/ssd1306.cyclo ./Core/Inc/ssd1306.d ./Core/Inc/ssd1306.o ./Core/Inc/ssd1306.su ./Core/Inc/ssd1306_font.cyclo ./Core/Inc/ssd1306_font.d ./Core/Inc/ssd1306_font.o ./Core/Inc/ssd1306_font.su

.PHONY: clean-Core-2f-Inc

