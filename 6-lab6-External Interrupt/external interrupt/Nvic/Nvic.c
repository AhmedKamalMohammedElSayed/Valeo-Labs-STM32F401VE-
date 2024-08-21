#include "Nvic.h"
#include "Bit_Operations.h"

#define NVIC_BASE (0xE000E100)

#define NVIC_ISER0 (*(uint32 *)(0xE000E100 + (0x04 * 0)))
#define NVIC_ISER1 (*(uint32 *)(0xE000E100 + (0x04 * 1)))
#define NVIC_ISER2 (*(uint32 *)(0xE000E100 + (0x04 * 2)))

#define NVIC_ICER0 (*(uint32 *)0xE000E180)
#define NVIC_ICER1 (*(uint32 *)0xE000E184)
#define NVIC_ICER2 (*(uint32 *)0xE000E188)

// Arrays to hold the addresses of ISER and ICER registers
static volatile uint32 *NVIC_ISER[] = {&NVIC_ISER0, &NVIC_ISER1, &NVIC_ISER2};
static volatile uint32 *NVIC_ICER[] = {&NVIC_ICER0, &NVIC_ICER1, &NVIC_ICER2};

void Nvic_EnableInterrupt(uint8 IRQn) {
  if (IRQn < 96) {
    SET_BIT(*NVIC_ISER[IRQn / 32], IRQn % 32);
  }
}

void Nvic_DisableInterrupt(uint8 IRQn) {
  if (IRQn < 96) {
    SET_BIT(*NVIC_ICER[IRQn / 32], IRQn % 32);
  }
}
