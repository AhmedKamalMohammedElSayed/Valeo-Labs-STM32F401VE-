################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Usart/Usart.c 

C_DEPS += \
./Usart/Usart.d 

OBJS += \
./Usart/Usart.o 


# Each subdirectory must supply rules for building sources it contributes
Usart/%.o: ../Usart/%.c Usart/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -Wall -Wextra -g -DNDEBUG -DSTM32F401xE -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"D:\SD\Eclipse-Workspaces\eclipse-cpp\embedded23-ws\Lab9_SPI\Lib" -I"D:\SD\Eclipse-Workspaces\eclipse-cpp\embedded23-ws\Lab9_SPI\Nvic" -I"D:\SD\Eclipse-Workspaces\eclipse-cpp\embedded23-ws\Lab9_SPI\Rcc" -I"D:\SD\Eclipse-Workspaces\eclipse-cpp\embedded23-ws\Lab9_SPI\Gpio" -I"D:\SD\Eclipse-Workspaces\eclipse-cpp\embedded23-ws\Lab9_SPI\Usart" -I"D:\SD\Eclipse-Workspaces\eclipse-cpp\embedded23-ws\Lab9_SPI\Spi" -I"D:\SD\Eclipse-Workspaces\eclipse-cpp\embedded23-ws\Lab9_SPI\tc72" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


