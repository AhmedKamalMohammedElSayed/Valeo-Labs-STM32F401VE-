#include "Nvic.h"
#include "Bit_Operations.h"

#define NVIC_ISER0 (*(uint32 *)(0xE000E100 + (0x04 * 0)))
#define NVIC_ISER1 (*(uint32 *)(0xE000E100 + (0x04 * 1)))
#define NVIC_ISER2 (*(uint32 *)(0xE000E100 + (0x04 * 2)))

#define NVIC_ICER0 (*(uint32 *)0xE000E180)
#define NVIC_ICER1 (*(uint32 *)0xE000E184)
#define NVIC_ICER2 (*(uint32 *)0xE000E188)

#define NVIC_IPR0 (*(uint32 *)(0xE000E100 + (0x400)))
#define NVIC_IPR1 (*(uint32 *)(0xE000E100 + (0x404)))
#define NVIC_IPR2 (*(uint32 *)(0xE000E100 + (0x408)))

void Nvic_EnableInterrupt(uint8 IRQn)
{
  static volatile uint32 *NVIC_ISER[] = {&NVIC_ISER0, &NVIC_ISER1, &NVIC_ISER2};
  if (IRQn < 96)
  {
    SET_BIT(*(NVIC_ISER[IRQn / 32]), (IRQn % 32));
  }
}

static void Nvic_DisableInterrupt(uint8 IRQn) __attribute__((unused));
static void Nvic_DisableInterrupt(uint8 IRQn)
{
  static volatile uint32 *NVIC_ICER[] = {&NVIC_ICER0, &NVIC_ICER1, &NVIC_ICER2};

  if (IRQn < 96)
  {
    SET_BIT(*(NVIC_ICER[IRQn / 32]), (IRQn % 32));
  }
}
void Nvic_SetPriority(uint8 IRQn, uint8 priority)
{
  static volatile uint32 *NVIC_IPR[] = {&NVIC_IPR0, &NVIC_IPR1, &NVIC_IPR2};

  // Ensure priority is within valid range (0-15)
  uint8 local_priority = priority;
  if (local_priority > 15)
  {

    local_priority = 15;
  }

  // Calculate the index and position of the priority field
  uint32 priority_group = IRQn / 4;        // Each IPR register contains 4 priorities
  uint32 priority_offset = (IRQn % 4) * 8; // Each priority is 8 bits apart

  // Write the priority value (using the top 4 bits)
  *NVIC_IPR[priority_group] &= ~(0xFF << priority_offset);                        // Clear the field
  *NVIC_IPR[priority_group] |= ((local_priority & 0xF) << (priority_offset + 4)); // Set new priority
}
