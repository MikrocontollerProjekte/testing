#ifndef __STM32F7_RANDOM_H
#define __STM32F7_RANDOM_H


// includes
#include "stm32f7xx.h"
#include "stm32f7xx_hal_rcc.h"
#include "stm32f7xx_hal_rng.h"

// functions
void random_number_init(void);
uint32_t get_random_number(uint32_t minValue, uint32_t maxValue);

#endif 