/*
 * external_interrupt_private.h
 *
 *  Created on: May 20, 2024
 *      Author: Ahmed Kamal & Abdulrahman Shawky
 * 		B.N.:         4              35
 */
#ifndef EXTERNAL_INTERRUPT_H_
#define EXTERNAL_INTERRUPT_H_


#include "external_interrupt_private.h"
#include "Bit_Operations.h"

typedef enum{
	EXTI_GPIOA, EXTI_GPIOB, EXTI_GPIOC,
	EXTI_GPIOD, EXTI_GPIOE, EXTI_GPIOH = 7
}EXTI_PORT;

typedef enum{
	EXTI_FALLING_EDGE, EXTI_RISING_EDGE,
	EXTI_FALLING_RISING_EDGES
}EXTI_Edge;



void Exti_Init(EXTI_PORT portID,
		uint8 ExtiPin,
		EXTI_Edge edge
		);


void Exti_Enable(uint8 ExtiPin);


void Exti_Disable(uint8 ExtiPin);


void Exti_HandlerPendingFlag(uint8 ExtiPin);


#endif /* EXTERNAL_INTERRUPT_H_ */
