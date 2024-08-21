/*
 * external_interrupt_private.h
 *
 *  Created on: May 20, 2024
 *      Author: Ahmed Kamal & Abdulrahman Shawky
 * 		B.N.:         4              35
 */


#include "Bit_Operations.h"
#include "Std_Types.h"
#include "Utils.h"
#include "Gpio.h"
#include "Rcc.h"
#include "Nvic.h"
#include "external_interrupt.h"

typedef struct {
	uint32 IMR;
	uint32 EMR;
	uint32 RTSR;
	uint32 FTSR;
	uint32 SWIER;
	uint32 PR;
} ExtiType;


// Global counter variable
volatile uint8 counter = 0;


void delay(uint32 count);
void Seven_Segment_Display(uint8 num);

int main() {
    // Initialize the system clock, and  enable clock for GPIOA, GPIOB, and SYSCFG peripherals
	Rcc_Init();
	Rcc_Enable(RCC_GPIOA);
	Rcc_Enable(RCC_GPIOB);
	Rcc_Enable(RCC_SYSCFG);

    //Configure GPIOB pins 4, 9 as input with pull-up resistor
	Gpio_ConfigPin(GPIO_B, 4, GPIO_INPUT, GPIO_PULL_UP);
	Gpio_ConfigPin(GPIO_A, 9, GPIO_INPUT, GPIO_PULL_UP);


    // Configure GPIOA pins 0 to 7 as outputs with push-pull mode
    Gpio_ConfigPin(GPIO_A, 0, GPIO_OUTPUT, GPIO_PUSH_PULL);
    Gpio_ConfigPin(GPIO_A, 1, GPIO_OUTPUT, GPIO_PUSH_PULL);
    Gpio_ConfigPin(GPIO_A, 2, GPIO_OUTPUT, GPIO_PUSH_PULL);
    Gpio_ConfigPin(GPIO_A, 3, GPIO_OUTPUT, GPIO_PUSH_PULL);
    Gpio_ConfigPin(GPIO_A, 4, GPIO_OUTPUT, GPIO_PUSH_PULL);
    Gpio_ConfigPin(GPIO_A, 5, GPIO_OUTPUT, GPIO_PUSH_PULL);
    Gpio_ConfigPin(GPIO_A, 6, GPIO_OUTPUT, GPIO_PUSH_PULL);
    Gpio_ConfigPin(GPIO_A, 7, GPIO_OUTPUT, GPIO_PUSH_PULL);


    // Initialize and enable EXTI line for GPIOA pins 9, 4 with falling edge trigger
	Exti_Init(EXTI_GPIOA,9,EXTI_FALLING_EDGE);
	Exti_Enable(9);
	Exti_HandlerPendingFlag(9);

	Exti_Init(EXTI_GPIOB,4,EXTI_FALLING_EDGE);
	Exti_Enable(4);
	Exti_HandlerPendingFlag(4);


	while (1) {
		Seven_Segment_Display(counter);
		delay(50000);
	}

	return 0;
}

void delay(uint32 count) {
    for ( uint32 i = 0; i < count; i++);
}

// EXTI line 4 interrupt handler
void EXTI4_IRQHandler(void) {

    if (counter > 0) {
        counter--;
    }
    else{
        counter = 9;
    }
} 

// EXTI lines 5 to 9 interrupt handler
void EXTI9_5_IRQHandler(void){

    if (counter < 9) {
        counter++;
    }
    else
    {
        counter = 0;
    }

}

void Seven_Segment_Display(uint8 num) {
    switch (num) {
        case 0:
            Gpio_WritePin(GPIO_A, 0, HIGH);
            Gpio_WritePin(GPIO_A, 1, HIGH);
            Gpio_WritePin(GPIO_A, 2, HIGH);
            Gpio_WritePin(GPIO_A, 3, HIGH);
            Gpio_WritePin(GPIO_A, 4, HIGH);
            Gpio_WritePin(GPIO_A, 5, HIGH);
            Gpio_WritePin(GPIO_A, 6, LOW);
            break;
        case 1:
            Gpio_WritePin(GPIO_A, 0, LOW);
            Gpio_WritePin(GPIO_A, 1, HIGH);
            Gpio_WritePin(GPIO_A, 2, HIGH);
            Gpio_WritePin(GPIO_A, 3, LOW);
            Gpio_WritePin(GPIO_A, 4, LOW);
            Gpio_WritePin(GPIO_A, 5, LOW);
            Gpio_WritePin(GPIO_A, 6, LOW);
            break;
        case 2:
            Gpio_WritePin(GPIO_A, 0, HIGH);
            Gpio_WritePin(GPIO_A, 1, HIGH);
            Gpio_WritePin(GPIO_A, 2, LOW);
            Gpio_WritePin(GPIO_A, 3, HIGH);
            Gpio_WritePin(GPIO_A, 4, HIGH);
            Gpio_WritePin(GPIO_A, 5, LOW);
            Gpio_WritePin(GPIO_A, 6, HIGH);
            break;
        case 3:
            Gpio_WritePin(GPIO_A, 0, HIGH);
            Gpio_WritePin(GPIO_A, 1, HIGH);
            Gpio_WritePin(GPIO_A, 2, HIGH);
            Gpio_WritePin(GPIO_A, 3, HIGH);
            Gpio_WritePin(GPIO_A, 4, LOW);
            Gpio_WritePin(GPIO_A, 5, LOW);
            Gpio_WritePin(GPIO_A, 6, HIGH);
            break;
        case 4:
            Gpio_WritePin(GPIO_A, 0, LOW);
            Gpio_WritePin(GPIO_A, 1, HIGH);
            Gpio_WritePin(GPIO_A, 2, HIGH);
            Gpio_WritePin(GPIO_A, 3, LOW);
            Gpio_WritePin(GPIO_A, 4, LOW);
            Gpio_WritePin(GPIO_A, 5, HIGH);
            Gpio_WritePin(GPIO_A, 6, HIGH);
            break;
        case 5:
            Gpio_WritePin(GPIO_A, 0, HIGH);
            Gpio_WritePin(GPIO_A, 1, LOW);
            Gpio_WritePin(GPIO_A, 2, HIGH);
            Gpio_WritePin(GPIO_A, 3, HIGH);
            Gpio_WritePin(GPIO_A, 4, LOW);
            Gpio_WritePin(GPIO_A, 5, HIGH);
            Gpio_WritePin(GPIO_A, 6, HIGH);
            break;
        case 6:
            Gpio_WritePin(GPIO_A, 0, HIGH);
            Gpio_WritePin(GPIO_A, 1, LOW);
            Gpio_WritePin(GPIO_A, 2, HIGH);
            Gpio_WritePin(GPIO_A, 3, HIGH);
            Gpio_WritePin(GPIO_A, 4, HIGH);
            Gpio_WritePin(GPIO_A, 5, HIGH);
            Gpio_WritePin(GPIO_A, 6, HIGH);
            break;
        case 7:
            Gpio_WritePin(GPIO_A, 0, HIGH);
            Gpio_WritePin(GPIO_A, 1, HIGH);
            Gpio_WritePin(GPIO_A, 2, HIGH);
            Gpio_WritePin(GPIO_A, 3, LOW);
            Gpio_WritePin(GPIO_A, 4, LOW);
            Gpio_WritePin(GPIO_A, 5, LOW);
            Gpio_WritePin(GPIO_A, 6, LOW);
            break;
        case 8:
            Gpio_WritePin(GPIO_A, 0, HIGH);
            Gpio_WritePin(GPIO_A, 1, HIGH);
            Gpio_WritePin(GPIO_A, 2, HIGH);
            Gpio_WritePin(GPIO_A, 3, HIGH);
            Gpio_WritePin(GPIO_A, 4, HIGH);
            Gpio_WritePin(GPIO_A, 5, HIGH);
            Gpio_WritePin(GPIO_A, 6, HIGH);
            break;
        case 9:
            Gpio_WritePin(GPIO_A, 0, HIGH);
            Gpio_WritePin(GPIO_A, 1, HIGH);
            Gpio_WritePin(GPIO_A, 2, HIGH);
            Gpio_WritePin(GPIO_A, 3, LOW);
            Gpio_WritePin(GPIO_A, 4, LOW);
            Gpio_WritePin(GPIO_A, 5, HIGH);
            Gpio_WritePin(GPIO_A, 6, HIGH);
            break;
    }
}

