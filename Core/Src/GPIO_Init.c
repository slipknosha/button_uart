#include "init.h"

void GPIO_Init(void)
{
  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA); /* GPIOA Port Clock Enable */

  GPIO_InitStruct.Pin = LL_GPIO_PIN_0; //button
  GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT; //input mode
  GPIO_InitStruct.Pull = LL_GPIO_PULL_DOWN; //pull-down resistor
  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = LL_GPIO_PIN_2;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}
