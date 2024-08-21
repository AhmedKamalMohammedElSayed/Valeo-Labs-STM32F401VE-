/*
 * Keypad.c
 *
 *  Created on: ٢٧‏/٠٤‏/٢٠٢٤
 *      Author: Ahmed
 */
#include "Keypad.h"  // Include the header file that contains declarations and macros

uint32 key;  // Global variable to store the last pressed key


void Keypad_Init(void){  // Initialization function for the keypad
    // Configure GPIO pins for columns
    uint32 index = 0;
    for(index = COL_START_INDEX; index <= COL_END_INDEX; index++){
        Gpio_ConfigPin(COL_PORT, index, GPIO_INPUT, PULL_UP);  // Configure column pin as input with pull-up
    }

    // Configure GPIO pins for rows
    for(index = ROW_START_INDEX; index <= ROW_END_INDEX; index++){
        Gpio_ConfigPin(ROW_PORT, index, GPIO_OUTPUT, GPIO_PUSH_PULL);  // Configure row pin as output in push-pull mode
       Gpio_WritePin(ROW_PORT, index, KEYPAD_BTN_RELEASED);  // Set row pin to released state
	   //                             KEYPAD_BTN_RELEASED-> LOGIC_HIGH خطأ مطبعي
	   //       ROW & COLs -> LOGIC_HIGH THE BTNS ARE NOT WORKING IN THE BEGINNIG
    }
}

void Keypad_Manage(void){  // Function to scan the keypad for button presses
    uint32 rows;
    uint32 cols;

    for(rows = ROW_START_INDEX; rows <= ROW_END_INDEX; rows++){  // Iterate over rows
        Gpio_WritePin(ROW_PORT, rows, KEYPAD_BTN_PRESSED);  // Set current row to pressed state
        for(cols = COL_START_INDEX; cols <= COL_END_INDEX; cols++){  // Iterate over columns
            if(GPIO_ReadPin(COL_PORT, cols) == KEYPAD_BTN_PRESSED){  // Check if button in current row and column is released
                delay(50);  // Introduce delay for debouncing
                if(GPIO_ReadPin(COL_PORT, cols) == KEYPAD_BTN_PRESSED){  // Check again if button is still released after delay
                    key = ((rows - ROW_START_INDEX) * COL_NUM) + (cols - COL_START_INDEX);  // Calculate the pressed key
					// the above line convers 2-d arr into 1-d arr
                    KeypadCallout_keypressNotification();  // Call a callback function to notify about key press
                }
            }
        }

       Gpio_WritePin(ROW_PORT, rows, KEYPAD_BTN_RELEASED);  // Reset current row to released state
    }
}

uint32 Keypad_GetKey(void){  // Function to get the last pressed key
    return key;  // Return the last pressed key
}

void KeypadCallout_keypressNotification(void){

	uint32 num = Keypad_GetKey()+1;
		switch (num) {
	        case 0:
	        	Gpio_WritePin(GPIO_A, PIN_1, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_0, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_2, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_3, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_4, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_5, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_6, LOW);
	           break;
	        case 1:
	        	Gpio_WritePin(GPIO_A, PIN_0, LOW);
	        	Gpio_WritePin(GPIO_A, PIN_1, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_2, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_3, LOW);
	        	Gpio_WritePin(GPIO_A, PIN_4, LOW);
	        	Gpio_WritePin(GPIO_A, PIN_5, LOW);
	        	Gpio_WritePin(GPIO_A, PIN_6, LOW);
	            break;
	        case 2:
	        	Gpio_WritePin(GPIO_A, PIN_0, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_1, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_2, LOW);
	        	Gpio_WritePin(GPIO_A, PIN_3, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_4, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_5, LOW);
	        	Gpio_WritePin(GPIO_A, PIN_6, HIGH);
	            break;
	        case 3:
	        	Gpio_WritePin(GPIO_A, PIN_0, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_1, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_2, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_3, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_4, LOW);
	        	Gpio_WritePin(GPIO_A, PIN_5, LOW);
	        	Gpio_WritePin(GPIO_A, PIN_6, HIGH);
	            break;
	        case 4:
	        	Gpio_WritePin(GPIO_A, PIN_0, LOW);
	        	Gpio_WritePin(GPIO_A, PIN_1, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_2, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_3, LOW);
	        	Gpio_WritePin(GPIO_A, PIN_4, LOW);
	        	Gpio_WritePin(GPIO_A, PIN_5, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_6, HIGH);
	            break;
	        case 5:
	        	Gpio_WritePin(GPIO_A, PIN_0, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_1, LOW);
	        	Gpio_WritePin(GPIO_A, PIN_2, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_3, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_4, LOW);
	        	Gpio_WritePin(GPIO_A, PIN_5, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_6, HIGH);
	            break;
	        case 6:
	        	Gpio_WritePin(GPIO_A, PIN_0, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_1, LOW);
	        	Gpio_WritePin(GPIO_A, PIN_2, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_3, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_4, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_5, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_6, HIGH);
	            break;
	        case 7:
	        	Gpio_WritePin(GPIO_A, PIN_0, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_1, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_2, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_3, LOW);
	        	Gpio_WritePin(GPIO_A, PIN_4, LOW);
	        	Gpio_WritePin(GPIO_A, PIN_5, LOW);
	        	Gpio_WritePin(GPIO_A, PIN_6, LOW);
	            break;
	        case 8:
	        	Gpio_WritePin(GPIO_A, PIN_0, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_1, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_2, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_3, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_4, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_5, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_6, HIGH);
	            break;
	        case 9:
	        	Gpio_WritePin(GPIO_A, PIN_0, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_1, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_2, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_3, LOW);
	        	Gpio_WritePin(GPIO_A, PIN_4, LOW);
	        	Gpio_WritePin(GPIO_A, PIN_5, HIGH);
	        	Gpio_WritePin(GPIO_A, PIN_6, HIGH);
	            break;
	    }
}

void delay(uint32 count) {  // Function to introduce a delay
    for ( uint32 i = 0; i < count; i++);  // Loop for delay based on count
}
