#include "Bit_Operations.h"
#include "Std_Types.h"
#include "Utils.h"
#include "Gpio.h"
#include "Rcc.h"
#include "Nvic.h"

typedef struct {
	uint32 IMR;
	uint32 EMR;
	uint32 RTSR;
	uint32 FTSR;
	uint32 SWIER;
	uint32 PR;
} ExtiType;

#define EXTI ((ExtiType *)0x40013C00)
#define SYSCFG_EXTICR1 (*(uint32*) (0x40013800 + 0x08))


int main() {
	Rcc_Init();
	Rcc_Enable(RCC_GPIOA);
	Rcc_Enable(RCC_GPIOB);
	Rcc_Enable(RCC_SYSCFG);

	uint8 selection = 1; // PB

	Gpio_ConfigPin(GPIO_A, 0, GPIO_OUTPUT, GPIO_PUSH_PULL);

	Gpio_ConfigPin(GPIO_B, 1, GPIO_INPUT, GPIO_PULL_UP);

	// enable falling edge on line 1
	EXTI->FTSR |= (1 << 1);

	// select PB1 to be connected on line 1
	SYSCFG_EXTICR1 &=~(0xf << (1 * 4));
	SYSCFG_EXTICR1 |= (selection << (1 * 4));



	// enalbe line 1
	EXTI->IMR |= (1 << 1);

	// enable line 1 on nvic
	Nvic_EnableInterrupt(7);




	while (1) {
	}

	return 0;
}



void MyExti1(void){
	Gpio_WritePin(GPIO_A, 0, HIGH);
	for (int i = 0; i < 1000000; i++) {
	}
	Gpio_WritePin(GPIO_A, 0, LOW);
	for (int i = 0; i < 1000000; i++) {
	}
	//clear pending flag
	SET_BIT(EXTI->PR, 1);
}


void EXTI1_IRQHandler(void) {
	Gpio_WritePin(GPIO_A, 0, LOW);
	for (int i = 0; i < 1000000; i++) {
	}
	Gpio_WritePin(GPIO_A, 0, HIGH);
	for (int i = 0; i < 1000000; i++) {
	}
	//clear pending flag
	SET_BIT(EXTI->PR, 1);
}

