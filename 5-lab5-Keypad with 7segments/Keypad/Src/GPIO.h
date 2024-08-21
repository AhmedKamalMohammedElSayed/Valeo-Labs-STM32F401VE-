// Names : Ahmed Kamal - Abd El-Rahman Shawky
//BN:		4				35
//team no : 39

#ifndef GPIO_H
#define GPIO_H

#include "Std_Types.h"
#include "GPIO_PRIVATE.h"

/*	PORT_NAME	*/
#define GPIO_A 'A'
#define	GPIO_B 'B'
#define GPIO_C 'C'
#define	GPIO_D 'D'

/*	PIN_NUMBER	*/
#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7

/*	PIN_MODES	*/
#define GPIO_INPUT 0x00
#define GPIO_OUTPUT 0x01
#define GPIO_ALTERNATE 0x02
#define GPIO_ANALOG 0x03

/*	DEFAULT_STATE	*/
#define GPIO_PUSH_PULL 0x00
#define	GPIO_OPEN_DRAIN 0x01

#define NO_PULL_UP_DOWN 0x00
#define PULL_UP 0x01
#define PULL_DOWN 0x10
#define RESERVED 0x11

/*	REG_OPERATIOS	*/
#define REG32(BASE_ADDR, OFFSET)  (*(uint32 *)((BASE_ADDR) + (OFFSET)))
#define SET_BIT(_REG_ADD, _BIT_POS, _BIT_MASK) (_REG_ADD |= (_BIT_MASK << _BIT_POS))
#define CLEAR_BIT(_REG_ADD, _BIT_POS, _BIT_MASK) (_REG_ADD&= ~(_BIT_MASK << _BIT_POS))
#define TOGGLE_BIT(_REG_ADD, _BIT_POS, _BIT_MASK) (_REG_ADD ^= (_BIT_MASK << _BIT_POS))
#define READ_BIT(_REG_ADD, _BIT_POS, _BIT_MASK) ((_REG_ADD >> _BIT_POS)&_BIT_MASK)

/* 		PIN_DATA		*/
#define LOW 0x0
#define HIGH 0x1

/* 	LED_COLOR	*/
#define LED_OFF     0x00
#define LED_RED     0x20  // PORTB Pin 5  		0010 0000
#define LED_GREEN   0x40  // PORTB Pin 6		0100 0000
#define LED_BLUE    0x80  // PORTB Pin 7		1000 0000
#define LED_YELLOW  (LED_RED | LED_GREEN)
#define LED_CYAN    (LED_GREEN | LED_BLUE)
#define LED_MAGENTA (LED_RED | LED_BLUE)
#define LED_WHITE   (LED_RED | LED_GREEN | LED_BLUE)

// Define button states
#define BUTTON_PRESSED 0
#define BUTTON_RELEASED 1


void Gpio_ConfigPin(uint32 PortName, uint32 PinNum, uint32 PinMode, uint32 DefaultState);
Std_ReturnType Gpio_WritePin(uint32 PortName, uint32 PinNum, uint32 Data);
uint32 GPIO_ReadPin(uint32 PortName, uint32 PinNum);



#endif //GPIO_H
