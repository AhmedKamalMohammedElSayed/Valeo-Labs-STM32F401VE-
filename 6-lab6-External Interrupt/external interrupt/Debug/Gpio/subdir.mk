################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Gpio/Gpio.c 

OBJS += \
./Gpio/Gpio.o 

C_DEPS += \
./Gpio/Gpio.d 


# Each subdirectory must supply rules for building sources it contributes
Gpio/Gpio.o: ../Gpio/Gpio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DDEBUG -DSTM32F401VEHx -c -I../Inc -I"G:/C/external interrupt/external interrupt/external_interrupt" -I"G:/C/external interrupt/external interrupt/Gpio" -I"G:/C/external interrupt/external interrupt/Idscripts" -I"G:/C/external interrupt/external interrupt/Nvic" -I"G:/C/external interrupt/external interrupt/RCC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Gpio/Gpio.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

