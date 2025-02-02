/**
 * Gpio.c
 *
 *  Created on: Tue Apr 11 2023
 *  Author    : Abdullah Darwish
 */

#include "Gpio.h"
#include "Gpio_Private.h"
#include "Rcc.h"

uint32 GPIO_Addresses[2] = {0x40020000, 0x40020400};

void Gpio_ConfigPin(uint8 PortName, uint8 PinNum, uint8 PinMode,
                    uint8 DefaultState)
{
    uint8 PortId = PortName - GPIO_A;
    GpioType *gpioReg = (GpioType *)GPIO_Addresses[PortId]; // Cast to GpioType pointer

    uint8 OutputState = DefaultState & 0x1;
    uint8 InputState = DefaultState >> 1;

    gpioReg->GPIO_MODER &= ~(0x3 << (2 * PinNum));
    gpioReg->GPIO_MODER |= (PinMode << (2 * PinNum));

    gpioReg->GPIO_OTYPER &= ~(0x01 << PinNum);
    gpioReg->GPIO_OTYPER |= (OutputState << PinNum);

    gpioReg->GPIO_PUPDR &= ~(0x3 << (2 * PinNum));
    gpioReg->GPIO_PUPDR |= (InputState << (2 * PinNum));
}

static void Gpio_WritePin(uint8 PortName, uint8 PinNum, uint8 Data) __attribute__((unused));
static void Gpio_WritePin(uint8 PortName, uint8 PinNum, uint8 Data)
{
    uint8 PortId = PortName - GPIO_A;
    GpioType *gpioReg = (GpioType *)GPIO_Addresses[PortId]; // Cast to GpioType pointer
    gpioReg->GPIO_ODR &= ~(0x01 << PinNum);
    gpioReg->GPIO_ODR |= (Data << PinNum);
}

static uint8 Gpio_ReadPin(uint8 PortName, uint8 PinNum)__attribute__((unused));
static uint8 Gpio_ReadPin(uint8 PortName, uint8 PinNum)
{
    uint8 data = 0;
    uint8 PortId = PortName - GPIO_A;
    GpioType *gpioReg = (GpioType *)GPIO_Addresses[PortId]; // Cast to GpioType pointer
    data = (gpioReg->GPIO_IDR & (1 << PinNum)) >> PinNum;
    return data;
}

void Gpio_TogglePin(uint8 PortName, uint8 Pin)
{
    uint8 PortId = PortName - GPIO_A;
    GpioType *gpioReg = (GpioType *)GPIO_Addresses[PortId]; // Cast to GpioType pointer
    gpioReg->GPIO_ODR ^= (0x01 << Pin);
}
