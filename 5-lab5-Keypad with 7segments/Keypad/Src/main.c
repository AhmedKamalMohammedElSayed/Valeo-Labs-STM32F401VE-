// Names : Ahmed Kamal - Abd El-Rahman Shawky
//BN:		4				35
//team no : 39

#include "GPIO.h"
#include "Rcc.h"
#include "Keypad.h"


int main(void)
{
    Rcc_Init();
    Rcc_Enable(RCC_GPIOA);
    Rcc_Enable(RCC_GPIOB);


    /*     pin configuration for seven segment */

    Gpio_ConfigPin(GPIO_A, PIN_0, GPIO_OUTPUT, GPIO_PUSH_PULL);
    Gpio_ConfigPin(GPIO_A, PIN_1, GPIO_OUTPUT, GPIO_PUSH_PULL);
    Gpio_ConfigPin(GPIO_A, PIN_2, GPIO_OUTPUT, GPIO_PUSH_PULL);
    Gpio_ConfigPin(GPIO_A, PIN_3, GPIO_OUTPUT, GPIO_PUSH_PULL);
    Gpio_ConfigPin(GPIO_A, PIN_4, GPIO_OUTPUT, GPIO_PUSH_PULL);
    Gpio_ConfigPin(GPIO_A, PIN_5, GPIO_OUTPUT, GPIO_PUSH_PULL);
    Gpio_ConfigPin(GPIO_A, PIN_6, GPIO_OUTPUT, GPIO_PUSH_PULL);
    Gpio_ConfigPin(GPIO_A, PIN_7, GPIO_OUTPUT, GPIO_PUSH_PULL);

    Keypad_Init();  // Initialization function for the keypad



    while (1) {

        //Display numbers from 0 to 7
//        for (uint8 i = 0; i <= 9; i++) {
//        	Seven_Segment_Display(i);
//            delay(1000000);
//        }


    	Keypad_Manage();
    }
}



