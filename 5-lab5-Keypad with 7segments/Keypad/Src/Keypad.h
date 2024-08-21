/*
 * Keypad.h
 *
 *  Created on: ٢٧‏/٠٤‏/٢٠٢٤
 *      Author: Ahmed
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "GPIO.h"

#define COL_PORT GPIO_B
#define COL_START_INDEX 0
#define COL_END_INDEX 2
#define COL_NUM 3

#define ROW_PORT GPIO_B
#define ROW_START_INDEX 5
#define ROW_END_INDEX 8

#define KEYPAD_BTN_PRESSED 0
#define	KEYPAD_BTN_RELEASED 1


void Keypad_Init(void);

void Keypad_Manage(void);

uint8 Keypad_Getkey(void);

void KeypadCallout_keypressNotification(void);

void delay(uint32 count);


#endif /* KEYPAD_H_ */
