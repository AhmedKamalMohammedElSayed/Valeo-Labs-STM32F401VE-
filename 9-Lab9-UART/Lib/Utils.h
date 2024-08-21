/**
 * Utils.h
 *
 *  Created on: Sun Mar 26 2023
 *  Author    : Ahmed Kamal
 */
#ifndef UTILS_H
#define UTILS_H

#include "Std_Types.h"
#define REG32(BASE_ADDR, OFFSET) (*(volatile uint32 *)((BASE_ADDR) + (OFFSET)))

#endif /* UTILS_H */
