/**
 * Rcc.c
 *
 *  Created on: April 19, 2024
 *      Author: Ahmed
 */

#include "Rcc.h"

#include "Rcc_Private.h"
#include "Std_Types.h"

#define SET_BIT(X, BIT)            (X |=  (1 << (BIT)))
#define CLEAR_BIT(X, BIT)          (X &= ~(1 << (BIT)))
#define READ_BIT(X, BIT)           (((X) >> (BIT)) & 1)
#define TOGGLE_BIT(X, BIT)         (X ^= (1 << (BIT)))


void Rcc_Init(void) { SET_BIT(RCC_CR, 0); }

void Rcc_Enable(Rcc_PeripheralIdType PeripheralId) {
  uint8 BusId = PeripheralId / 32;
  uint8 PeripheralBitPosition = PeripheralId % 32;
  switch (BusId) {
    case RCC_AHB1:
      SET_BIT(RCC_AHB1ENR, PeripheralBitPosition);
      break;
    case RCC_AHB2:
      SET_BIT(RCC_AHB2ENR, PeripheralBitPosition);
      break;
    case RCC_APB1:
      SET_BIT(RCC_APB1ENR, PeripheralBitPosition);
      break;
    case RCC_APB2:
      SET_BIT(RCC_APB2ENR, PeripheralBitPosition);
      break;
    default:
      break;
  }
}

void Rcc_Disable(Rcc_PeripheralIdType PeripheralId) {
     uint8 BusId = PeripheralId / 32;
  uint8 PeripheralBitPosition = PeripheralId % 32;
  switch (BusId) {
    case RCC_AHB1:
      SET_BIT(RCC_AHB1RSTR, PeripheralBitPosition);
      break;
    case RCC_AHB2:
      SET_BIT(RCC_AHB2RSTR, PeripheralBitPosition);
      break;
    case RCC_APB1:
      SET_BIT(RCC_APB1RSTR, PeripheralBitPosition);
      break;
    case RCC_APB2:
      SET_BIT(RCC_APB2RSTR, PeripheralBitPosition);
      break;
    default:
      break;
  }
}
