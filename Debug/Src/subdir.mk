################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/ADC.c \
../Src/Dma.c \
../Src/Flash.c \
../Src/Gpio.c \
../Src/IWDG.c \
../Src/Rcc.c \
../Src/Rng.c \
../Src/Timer.c \
../Src/Usart.c \
../Src/i2c.c \
../Src/main.c \
../Src/stm32f4xx_hal_msp.c \
../Src/stm32f4xx_it.c \
../Src/system_stm32f4xx.c 

OBJS += \
./Src/ADC.o \
./Src/Dma.o \
./Src/Flash.o \
./Src/Gpio.o \
./Src/IWDG.o \
./Src/Rcc.o \
./Src/Rng.o \
./Src/Timer.o \
./Src/Usart.o \
./Src/i2c.o \
./Src/main.o \
./Src/stm32f4xx_hal_msp.o \
./Src/stm32f4xx_it.o \
./Src/system_stm32f4xx.o 

C_DEPS += \
./Src/ADC.d \
./Src/Dma.d \
./Src/Flash.d \
./Src/Gpio.d \
./Src/IWDG.d \
./Src/Rcc.d \
./Src/Rng.d \
./Src/Timer.d \
./Src/Usart.d \
./Src/i2c.d \
./Src/main.d \
./Src/stm32f4xx_hal_msp.d \
./Src/stm32f4xx_it.d \
./Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F429xx -I"C:/Student/ThengChun/STM32/RNG_2/Inc" -I"C:/Student/ThengChun/STM32/RNG_2/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Student/ThengChun/STM32/RNG_2/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Student/ThengChun/STM32/RNG_2/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Student/ThengChun/STM32/RNG_2/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


