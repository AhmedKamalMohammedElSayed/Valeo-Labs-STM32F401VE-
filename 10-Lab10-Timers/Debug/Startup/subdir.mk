################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Startup/startup_stm32f401vetx.s 

OBJS += \
./Startup/startup_stm32f401vetx.o 

S_DEPS += \
./Startup/startup_stm32f401vetx.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/startup_stm32f401vetx.o: ../Startup/startup_stm32f401vetx.s
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -c -I"D:/emb tasks/timer/timer/Gpio" -I"D:/emb tasks/timer/timer/Lib" -I"D:/emb tasks/timer/timer/RCC" -x assembler-with-cpp -MMD -MP -MF"Startup/startup_stm32f401vetx.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

