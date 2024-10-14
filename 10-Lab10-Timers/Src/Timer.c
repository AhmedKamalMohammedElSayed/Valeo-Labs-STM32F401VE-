#include"Timer_Private.h"
#include"Timer.h"
#include "Rcc.h"
#include "Nvic.h"

volatile  uint32 ms_counter = 0;  // Global counter variable

#define TIM_SR_UIF_Pos            (0U)
#define TIM_SR_UIF_Msk            (0x1UL << TIM_SR_UIF_Pos)                     /*!< 0x00000001 */
#define TIM_SR_UIF                TIM_SR_UIF_Msk

// Timer Initialization
void TIM2_Init(void) {


    Rcc_Enable(RCC_TIM2);

    // Set Prescaler to divide the clock
    // Assuming SystemCoreClock is 16 MHz, we want a 1ms tick
    TIM2->PSC = 0;  // Prescaler to divide clock by 16000 (16 MHz / 16000 = 1 kHz)

    // Set Auto-reload value for 1ms interrupt
    TIM2->ARR = (16000 - 1);      // Auto-reload value to count for 1 tick (1 ms at 1 kHz)

    // Enable Update Interrupt (UIE)
    TIM2->DIER |= (1<<0);

    // Enable the Timer
    TIM2->CR1 |= (1<<0);

    // Enable TIM2 interrupt in NVIC
    Nvic_SetPriority(28, 1);  // Set priority to 1

    Nvic_EnableInterrupt(28);

//    NVIC_EnableIRQ(TIM2_IRQn);
}

// Timer Interrupt Service Routine
void   TIM2_IRQHandler(void) {
    if ((TIM2->SR & TIM_SR_UIF)) { // Check if the update interrupt flag is set
        TIM2->SR &= ~TIM_SR_UIF; // Clear the interrupt flag
        ms_counter++; // Increment millisecond counter
    }
}


