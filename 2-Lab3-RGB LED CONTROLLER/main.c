
#define GPIOB_BASE_ADDR 0x40020400
#define GPIOB_MODER (*(unsigned long *)(GPIOB_BASE_ADDR+0x00))
#define GPIOB_OTYPER (*(unsigned long *)(GPIOB_BASE_ADDR+0x04))
#define GPIOB_ODR (*(unsigned long *)(GPIOB_BASE_ADDR+0x14))
#define GPIOB_PUPDR (*(unsigned long *)(GPIOB_BASE_ADDR+0x0C))
#define RCC_AHB1ENR (*(unsigned long *)(0x40023800 + 0x30))
#define RCC_CR (*(unsigned long *)(0x40023800 + 0x00))
#define GPIOB_IDR (*(unsigned long *)(GPIOB_BASE_ADDR + 0x10))



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



#define SET_BIT(_REG_ADDR, _BIT ,_BIT_POSN) (_REG_ADDR |=  (_BIT << _BIT_POSN))
#define CLEAR_BIT(_REG_ADDR, _BIT , _BIT_POSN) (_REG_ADDR &= ~(_BIT << _BIT_POSN))
#define TOGGLE_BIT(_REG_ADDR , _BIT ,_BIT_POSN) (_REG_ADDR ^=  (_BIT << _BIT_POSN))
#define READ_BIT(_REG_ADDR ,_BIT_POSN) ((_REG_ADDR >> _BIT_POSN) & 1)



void delay(unsigned long count);


int main(void)
{
	// enable the clock
    SET_BIT(RCC_CR, 1, 0);			// Enable HSE clock
    SET_BIT(RCC_AHB1ENR, 1, 1);		// Enable GPIOB clock


    // pin 3 port b configuration
    CLEAR_BIT(GPIOB_MODER, 0x03, 3*2);		//make it input_mode
    SET_BIT(GPIOB_PUPDR, 0x01, 3*2);		//pull up resistor
    CLEAR_BIT(GPIOB_OTYPER, 1, 3);			//push-pull configuration

    // pin 5 port b configuration
    CLEAR_BIT(GPIOB_MODER, 0x03, 5*2);		//clear bit
    SET_BIT(GPIOB_MODER, 1, 5*2);			//output mode
    CLEAR_BIT(GPIOB_OTYPER, 1, 5);			//push-pull configuration

    // pin 6 port b configuration
    CLEAR_BIT(GPIOB_MODER, 0x03, 6*2);		//clear bit
    SET_BIT(GPIOB_MODER, 1, 6*2);			//output mode
    CLEAR_BIT(GPIOB_OTYPER, 1, 6);			//push-pull configuration

    // pin 7 port b configuration
    CLEAR_BIT(GPIOB_MODER, 0x03, 7*2);		//clear bit
    SET_BIT(GPIOB_MODER, 1, 7*2);			//output mode
    CLEAR_BIT(GPIOB_OTYPER, 1, 7);			//push-pull configuration


    // pin 8 port b configuration -> testing
    CLEAR_BIT(GPIOB_MODER, 0x03, 8*2);		//clear bit
    SET_BIT(GPIOB_MODER, 1, 8*2);			//output mode
    CLEAR_BIT(GPIOB_OTYPER, 1, 8);			//push-pull configuration


    unsigned char buttonState = BUTTON_RELEASED;
    unsigned char prevButtonState = BUTTON_RELEASED;
    unsigned char ledColor = LED_OFF;



    while(1){
    	// button is low when pressing it otherwise the button is high
    	buttonState = (READ_BIT(GPIOB_IDR,3))?BUTTON_RELEASED :BUTTON_PRESSED;
    	// active low detection from high state to low state
        if (buttonState == BUTTON_PRESSED && prevButtonState == BUTTON_RELEASED) {
        	// delay for debouncing
        	delay(50);
        	buttonState = (READ_BIT(GPIOB_IDR,3))?BUTTON_RELEASED :BUTTON_PRESSED;
        	if(buttonState == BUTTON_PRESSED){
        		switch (ledColor) {
        		                    case LED_OFF:
        		                        ledColor = LED_RED;
        		                        break;
        		                    case LED_RED:
        		                        ledColor = LED_GREEN;
        		                        break;
        		                    case LED_GREEN:
        		                        ledColor = LED_BLUE;
        		                        break;
        		                    case LED_BLUE:
        		                        ledColor = LED_YELLOW;
        		                        break;
        		                    case LED_YELLOW:
        		                        ledColor = LED_CYAN;
        		                        break;
        		                    case LED_CYAN:
        		                        ledColor = LED_MAGENTA;
        		                        break;
        		                    case LED_MAGENTA:
        		                        ledColor = LED_WHITE;
        		                        break;
        		                    case LED_WHITE:
        		                        ledColor = LED_OFF;
        		                        break;
        		                    default:
        		                        break;
        		                }

        		                // Update LED color
								GPIOB_ODR &= ~((1<<5) | (1<<6) | (1<<7));  // Clear bits for pins 5, 6, and 7

								// Set LED color by OR-ing with the desired ledColor
								GPIOB_ODR |= ledColor;
        	}



        }
        prevButtonState = buttonState;

    }

    return 0;
}

void delay(unsigned long count) {
    for (unsigned long i = 0; i < count; i++);
}



