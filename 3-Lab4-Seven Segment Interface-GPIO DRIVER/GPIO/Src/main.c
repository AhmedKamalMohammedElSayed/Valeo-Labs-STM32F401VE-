// Names : Ahmed Kamal - Abd El-Rahman Shawky
//BN:		4				35
//team no : 39

#include "GPIO.h"
#include "Rcc.h"

void delay(uint32 count);
void Seven_Segment_Display(uint8 num);
void handleButtonPress(uint8 *ledColor, uint8 *prevButtonState);

int main(void)
{
    Rcc_Init();
    Rcc_Enable(RCC_GPIOA);
    Rcc_Enable(RCC_GPIOB);


    /* pin configuration for seven segment */
    Gpio_ConfigPin(GPIO_A, PIN_0, GPIO_OUTPUT, GPIO_PUSH_PULL);
    Gpio_ConfigPin(GPIO_A, PIN_1, GPIO_OUTPUT, GPIO_PUSH_PULL);
    Gpio_ConfigPin(GPIO_A, PIN_2, GPIO_OUTPUT, GPIO_PUSH_PULL);
    Gpio_ConfigPin(GPIO_A, PIN_3, GPIO_OUTPUT, GPIO_PUSH_PULL);
    Gpio_ConfigPin(GPIO_A, PIN_4, GPIO_OUTPUT, GPIO_PUSH_PULL);
    Gpio_ConfigPin(GPIO_A, PIN_5, GPIO_OUTPUT, GPIO_PUSH_PULL);
    Gpio_ConfigPin(GPIO_A, PIN_6, GPIO_OUTPUT, GPIO_PUSH_PULL);
    Gpio_ConfigPin(GPIO_A, PIN_7, GPIO_OUTPUT, GPIO_PUSH_PULL);


    /* pin configuration for button & RGB LED */
    Gpio_ConfigPin(GPIO_B, PIN_3, GPIO_INPUT, PULL_UP);
    CLEAR_BIT(GPIOB_OTYPER, 3, 1);

    Gpio_ConfigPin(GPIO_B, PIN_5, GPIO_OUTPUT, GPIO_PUSH_PULL);
    Gpio_ConfigPin(GPIO_B, PIN_6, GPIO_OUTPUT, GPIO_PUSH_PULL);
    Gpio_ConfigPin(GPIO_B, PIN_7, GPIO_OUTPUT, GPIO_PUSH_PULL);



    unsigned char ledColor = LED_OFF;
    unsigned char prevButtonState = BUTTON_RELEASED;

    while (1) {
    	handleButtonPress(&ledColor, &prevButtonState);

        // Display numbers from 0 to 7
//        for (uint8 i = 0; i <= 9; i++) {
//        	Seven_Segment_Display(i);
//            delay(1000000);
//        }
    }
}

void Seven_Segment_Display(uint8 num){
	Std_ReturnType ret;
	switch (num) {
        case 0:
        	ret=Gpio_WritePin(GPIO_A, PIN_0, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_1, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_2, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_3, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_4, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_5, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_6, LOW);
           break;
        case 1:
        	ret=Gpio_WritePin(GPIO_A, PIN_0, LOW);
        	ret=Gpio_WritePin(GPIO_A, PIN_1, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_2, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_3, LOW);
        	ret=Gpio_WritePin(GPIO_A, PIN_4, LOW);
        	ret=Gpio_WritePin(GPIO_A, PIN_5, LOW);
        	ret=Gpio_WritePin(GPIO_A, PIN_6, LOW);
            break;
        case 2:
        	ret=Gpio_WritePin(GPIO_A, PIN_0, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_1, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_2, LOW);
        	ret=Gpio_WritePin(GPIO_A, PIN_3, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_4, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_5, LOW);
        	ret=Gpio_WritePin(GPIO_A, PIN_6, HIGH);
            break;
        case 3:
        	ret=Gpio_WritePin(GPIO_A, PIN_0, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_1, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_2, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_3, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_4, LOW);
        	ret=Gpio_WritePin(GPIO_A, PIN_5, LOW);
        	ret=Gpio_WritePin(GPIO_A, PIN_6, HIGH);
            break;
        case 4:
        	ret=Gpio_WritePin(GPIO_A, PIN_0, LOW);
        	ret=Gpio_WritePin(GPIO_A, PIN_1, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_2, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_3, LOW);
        	ret=Gpio_WritePin(GPIO_A, PIN_4, LOW);
        	ret=Gpio_WritePin(GPIO_A, PIN_5, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_6, HIGH);
            break;
        case 5:
        	ret=Gpio_WritePin(GPIO_A, PIN_0, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_1, LOW);
        	ret=Gpio_WritePin(GPIO_A, PIN_2, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_3, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_4, LOW);
        	ret=Gpio_WritePin(GPIO_A, PIN_5, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_6, HIGH);
            break;
        case 6:
        	ret=Gpio_WritePin(GPIO_A, PIN_0, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_1, LOW);
        	ret=Gpio_WritePin(GPIO_A, PIN_2, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_3, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_4, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_5, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_6, HIGH);
            break;
        case 7:
        	ret=Gpio_WritePin(GPIO_A, PIN_0, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_1, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_2, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_3, LOW);
        	ret=Gpio_WritePin(GPIO_A, PIN_4, LOW);
        	ret=Gpio_WritePin(GPIO_A, PIN_5, LOW);
        	ret=Gpio_WritePin(GPIO_A, PIN_6, LOW);
            break;
        case 8:
        	ret=Gpio_WritePin(GPIO_A, PIN_0, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_1, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_2, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_3, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_4, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_5, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_6, HIGH);
            break;
        case 9:
        	ret=Gpio_WritePin(GPIO_A, PIN_0, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_1, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_2, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_3, LOW);
        	ret=Gpio_WritePin(GPIO_A, PIN_4, LOW);
        	ret=Gpio_WritePin(GPIO_A, PIN_5, HIGH);
        	ret=Gpio_WritePin(GPIO_A, PIN_6, HIGH);
            break;
    }
}

void delay(uint32 count) {
    for ( uint32 i = 0; i < count; i++);
}

void handleButtonPress(uint8 *ledColor, uint8 *prevButtonState) {

    uint32 buttonState = (GPIO_ReadPin(GPIO_B, PIN_3)) ? BUTTON_RELEASED : BUTTON_PRESSED;

    // Active low detection from high state to low state
    if (buttonState == BUTTON_PRESSED && *prevButtonState == BUTTON_RELEASED) {
        // Delay for debouncing
        delay(50);
        buttonState = (GPIO_ReadPin(GPIO_B, PIN_3)) ? BUTTON_RELEASED : BUTTON_PRESSED;
        if (buttonState == BUTTON_PRESSED) {
            switch (*ledColor) {
                case LED_OFF:
                    *ledColor = LED_RED;
                    break;
                case LED_RED:
                    *ledColor = LED_GREEN;
                    break;
                case LED_GREEN:
                    *ledColor = LED_BLUE;
                    break;
                case LED_BLUE:
                    *ledColor = LED_YELLOW;
                    break;
                case LED_YELLOW:
                    *ledColor = LED_CYAN;
                    break;
                case LED_CYAN:
                    *ledColor = LED_MAGENTA;
                    break;
                case LED_MAGENTA:
                    *ledColor = LED_WHITE;
                    break;
                case LED_WHITE:
                    *ledColor = LED_OFF;
                    break;
                default:
                    break;
            }

            // Update LED color
            GPIOB_ODR &= ~((1 << 5) | (1 << 6) | (1 << 7));  // Clear bits for pins 5, 6, and 7

            // Set LED color by OR-ing with the desired ledColor
            GPIOB_ODR |= *ledColor;
        }
    }
    *prevButtonState = buttonState;
}
