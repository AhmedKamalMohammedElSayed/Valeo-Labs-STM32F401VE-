################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../RCC/Rcc.c 

OBJS += \
./RCC/Rcc.o 

C_DEPS += \
./RCC/Rcc.d 


# Each subdirectory must supply rules for building sources it contributes
RCC/Rcc.o: ../RCC/Rcc.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DDEBUG -DSTM32F401VEHx -c -I../Inc -I"G:/C/external interrupt/external interrupt/external_interrupt" -I"G:/C/external interrupt/external interrupt/Gpio" -I"G:/C/external interrupt/external interrupt/Idscripts" -I"G:/C/external interrupt/external interrupt/Nvic" -I"G:/C/external interrupt/external interrupt/RCC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"RCC/Rcc.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

