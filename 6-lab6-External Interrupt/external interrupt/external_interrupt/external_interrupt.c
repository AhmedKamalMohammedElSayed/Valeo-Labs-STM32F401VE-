/*
 * external_interrupt_private.h
 *
 *  Created on: May 20, 2024
 *      Author: Ahmed Kamal & Abdulrahman Shawky
 * 		B.N.:         4              35
 */

#include "external_interrupt.h"
#include "Nvic.h"


NVIC_EXTI_Lines line[]={
		NVIC_EXTI_Line_0,
		NVIC_EXTI_Line_1,
		NVIC_EXTI_Line_2,
		NVIC_EXTI_Line_3,
		NVIC_EXTI_Line_4,
		NVIC_EXTI_Line_9_5,
		NVIC_EXTI_Line_9_5,
		NVIC_EXTI_Line_9_5,
		NVIC_EXTI_Line_9_5,
		NVIC_EXTI_Line_9_5,
		NVIC_EXTI_Line_15_10,
		NVIC_EXTI_Line_15_10,
		NVIC_EXTI_Line_15_10,
		NVIC_EXTI_Line_15_10,
		NVIC_EXTI_Line_15_10,
		NVIC_EXTI_Line_15_10,
		NVIC_EXTI_Line_16,
		NVIC_EXTI_Line_17,
		NVIC_EXTI_Line_18,
		0,
		0,
		NVIC_EXTI_Line_21,
		NVIC_EXTI_Line_22
};


void Exti_Init(EXTI_PORT portID,
		uint8 ExtiPin,EXTI_Edge edge
		){


	//	 EXTICR1 --> bits {0, 1, 2 ,3}
	//	 EXTICR2 --> bits {4, 5, 6 ,7}
	//	 EXTICR3 --> bits {8, 9, 10 ,11}
	//	 EXTICR4 --> bits {12, 13, 14 ,15}

	if (ExtiPin < 4) {
		SYSCFG->EXTICR1 &= ~(portID << (ExtiPin%4 * 4));
		SYSCFG->EXTICR1 |=  (portID << (ExtiPin%4 * 4));
	}
	else if (ExtiPin >= 4 && ExtiPin < 8){
		SYSCFG->EXTICR2 &= ~(portID << ( (ExtiPin%4) * 4));
		SYSCFG->EXTICR2 |=  (portID << ( (ExtiPin%4) * 4));
	}
	else if (ExtiPin >= 8 && ExtiPin < 12){
		SYSCFG->EXTICR3 &= ~(portID << ( (ExtiPin%4) * 4));
		SYSCFG->EXTICR3 |=  (portID << ( (ExtiPin%4) * 4));
	}
	else if (ExtiPin >= 12 && ExtiPin < 16){
		SYSCFG->EXTICR4 &= ~(portID << ( (ExtiPin%4) * 4));
		SYSCFG->EXTICR4 |=  (portID << ( (ExtiPin%4) * 4));
	}


	NVIC_EXTI_Lines NvicLine = line[ExtiPin];

	Nvic_EnableInterrupt(NvicLine);



	//	 Select the edge
	//	 case :: falling edge
	//	 case :: rising edge
	//	 case :: both edges

	switch (edge) {
	case EXTI_FALLING_EDGE:
		SET_BIT(EXTI->FTSR, ExtiPin);
		break;
	case EXTI_RISING_EDGE:
		SET_BIT(EXTI->RTSR, ExtiPin);
		break;
	case EXTI_FALLING_RISING_EDGES:
		SET_BIT(EXTI->FTSR, ExtiPin);
		SET_BIT(EXTI->RTSR, ExtiPin);
		break;
	}
}



void Exti_Enable(uint8 ExtiPin){
	SET_BIT(EXTI->IMR, ExtiPin);
}



void Exti_Disable(uint8 ExtiPin){
	CLEAR_BIT(EXTI->IMR, ExtiPin);
}


void Exti_HandlerPendingFlag(uint8 ExtiPin){
	SET_BIT(EXTI->PR, ExtiPin);
}
