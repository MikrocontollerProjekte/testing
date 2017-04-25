/**
*
*	Random Number Generation (RNG) for STM32F7xx
*	Code from GitHub Repo: https://github.com/MikrocontollerProjekte
*
**/


#include "stm32f7_random.h"


// init random number generator
void random_number_init(void)
{
	/* Enable RNG clock source */
	__HAL_RCC_RNG_CLK_ENABLE();

	/* Enable RNG Peripheral */
	RNG->CR |= RNG_CR_RNGEN;
}


// generates random number >= minValue and <= maxValue
uint32_t get_random_number(uint32_t minValue, uint32_t maxValue)
{
  uint32_t retval = 0;
  uint32_t mask = 0xFFFFFFFF;
  uint32_t randomValue = 0;

  if(minValue < maxValue)
  {
    if(maxValue <= 0x0FFFFFFF) mask = 0x0FFFFFFF;
    if(maxValue <= 0x00FFFFFF) mask = 0x00FFFFFF;
    if(maxValue <= 0x000FFFFF) mask = 0x000FFFFF;
    if(maxValue <= 0x0000FFFF) mask = 0x0000FFFF;
    if(maxValue <= 0x00000FFF) mask = 0x00000FFF;
    if(maxValue <= 0x000000FF) mask = 0x000000FF;
    if(maxValue <= 0x0000000F) mask = 0x0000000F;

    do{
    	while(!(RNG->SR & (RNG_SR_DRDY)));	// wait until one RNG number is generatet
      		randomValue = RNG->DR;

    	// use mask for better performance
    	randomValue = (randomValue & mask);
    }while(  (randomValue > maxValue) 
		   ||(randomValue < minValue)
	      );
    retval = randomValue;
  }
  else if(minValue == maxValue) {
    retval = minValue;
  }
  else {
	retval = minValue;
  }

  return(retval);
}




