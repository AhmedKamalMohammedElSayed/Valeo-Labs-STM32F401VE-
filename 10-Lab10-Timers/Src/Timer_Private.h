/*
 * Timer_Private.h
 *
 *  Created on: Oct 13, 2024
 *      Author: Ahmed Kamal
 */

#ifndef TIMER_PRIVATE
#define TIMER_PRIVATE

#include "Utils.h"

#define TIM2_BASE_ADDRESS 		0x40000000U		//Base address for Timer2

#define TIM2 ((volatile TIM2_REG *)(uint32*)TIM2_BASE_ADDRESS)


typedef struct {
	uint32 CR1;
	uint32 CR2;
	uint32 SMCR;
	uint32 DIER;
	uint32 SR;
	uint32 EGR;
	uint32 CCMR1;
	uint32 CCMR2;
	uint32 CCER;
	uint32 CNT;
	uint32 PSC;
	uint32 ARR;
	uint32 CCR1;
	uint32 CCR2;
	uint32 CCR3;
	uint32 CCR4;
	uint32 DCR;
	uint32 DMAR;
	uint32 OR;

}TIM2_REG;
#endif /*TIMER_PRIVATE*/
