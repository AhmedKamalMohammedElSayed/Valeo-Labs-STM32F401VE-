################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Gpio.c \
../Src/Nvic.c \
../Src/Rcc.c \
../Src/Timer.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/Gpio.o \
./Src/Nvic.o \
./Src/Rcc.o \
./Src/Timer.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/Gpio.d \
./Src/Nvic.d \
./Src/Rcc.d \
./Src/Timer.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Gpio.o: ../Src/Gpio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F401VETx -DDEBUG -c -I../Inc -I"D:/emb tasks/timer/timer/Lib" -I"D:/emb tasks/timer/timer/Gpio" -I"D:/emb tasks/timer/timer/RCC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/Gpio.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/Nvic.o: ../Src/Nvic.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F401VETx -DDEBUG -c -I../Inc -I"D:/emb tasks/timer/timer/Lib" -I"D:/emb tasks/timer/timer/Gpio" -I"D:/emb tasks/timer/timer/RCC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/Nvic.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/Rcc.o: ../Src/Rcc.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F401VETx -DDEBUG -c -I../Inc -I"D:/emb tasks/timer/timer/Lib" -I"D:/emb tasks/timer/timer/Gpio" -I"D:/emb tasks/timer/timer/RCC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/Rcc.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/Timer.o: ../Src/Timer.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F401VETx -DDEBUG -c -I../Inc -I"D:/emb tasks/timer/timer/Lib" -I"D:/emb tasks/timer/timer/Gpio" -I"D:/emb tasks/timer/timer/RCC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/Timer.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/main.o: ../Src/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F401VETx -DDEBUG -c -I../Inc -I"D:/emb tasks/timer/timer/Lib" -I"D:/emb tasks/timer/timer/Gpio" -I"D:/emb tasks/timer/timer/RCC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/syscalls.o: ../Src/syscalls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F401VETx -DDEBUG -c -I../Inc -I"D:/emb tasks/timer/timer/Lib" -I"D:/emb tasks/timer/timer/Gpio" -I"D:/emb tasks/timer/timer/RCC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/syscalls.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/sysmem.o: ../Src/sysmem.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F401VETx -DDEBUG -c -I../Inc -I"D:/emb tasks/timer/timer/Lib" -I"D:/emb tasks/timer/timer/Gpio" -I"D:/emb tasks/timer/timer/RCC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/sysmem.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

