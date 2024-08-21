################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../external_interrupt/external_interrupt.c 

OBJS += \
./external_interrupt/external_interrupt.o 

C_DEPS += \
./external_interrupt/external_interrupt.d 


# Each subdirectory must supply rules for building sources it contributes
external_interrupt/external_interrupt.o: ../external_interrupt/external_interrupt.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DDEBUG -DSTM32F401VEHx -c -I../Inc -I"G:/C/external interrupt/external interrupt/external_interrupt" -I"G:/C/external interrupt/external interrupt/Gpio" -I"G:/C/external interrupt/external interrupt/Idscripts" -I"G:/C/external interrupt/external interrupt/Nvic" -I"G:/C/external interrupt/external interrupt/RCC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"external_interrupt/external_interrupt.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

