#include "Gpio.h"
#include "Rcc.h"
#include "Timer.h"

#define LED1_PIN 0
#define LED2_PIN 1
#define LED3_PIN 2

extern volatile uint32 ms_counter;

int main(void)
{


    Rcc_Init();
    Rcc_Enable(RCC_GPIOA);

    Gpio_ConfigPin(GPIO_A, LED1_PIN, GPIO_OUTPUT, GPIO_PUSH_PULL);
    Gpio_ConfigPin(GPIO_A, LED2_PIN, GPIO_OUTPUT, GPIO_PUSH_PULL);
    Gpio_ConfigPin(GPIO_A, LED3_PIN, GPIO_OUTPUT, GPIO_PUSH_PULL);

    TIM2_Init();

    uint32 led1_next_toggle_time = 50; // Next toggle time for LED1
    uint32 led2_next_toggle_time = 100; // Next toggle time for LED2
    uint32 led3_next_toggle_time = 200; // Next toggle time for LED3

    while (1) {
         //Check if ms_counter has reached or exceeded the next toggle time for LED1
        if (ms_counter >= led1_next_toggle_time) {
            Gpio_TogglePin(GPIO_A, LED1_PIN);
//        	Gpio_WritePin(GPIO_A, 0, HIGH);

            led1_next_toggle_time += 50; // Update next toggle time for LED1
        }

        // Check if ms_counter has reached or exceeded the next toggle time for LED2
        if (ms_counter >= led2_next_toggle_time) {
            Gpio_TogglePin(GPIO_A, LED2_PIN);
//        	Gpio_WritePin(GPIO_A, 1, HIGH);
            led2_next_toggle_time += 100; // Update next toggle time for LED2
        }

        // Check if ms_counter has reached or exceeded the next toggle time for LED3
        if (ms_counter >= led3_next_toggle_time) {
            Gpio_TogglePin(GPIO_A, LED3_PIN);
//        	Gpio_WritePin(GPIO_A, 2, HIGH);
            led3_next_toggle_time += 200; // Update next toggle time for LED3
        }


//
//    	Gpio_TogglePin(GPIO_A, LED3_PIN);
//    	for(int i=0 ; i<1000 ;i++);

    }
}
