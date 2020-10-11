#include "init.h"

void TIM7_Init(void)
{

  /* USER CODE BEGIN TIM7_Init 0 */

  /* USER CODE END TIM7_Init 0 */

  LL_TIM_InitTypeDef TIM_InitStruct = {0}; //TIM Time Base configuration structure

  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM7);  /* Peripheral clock enable */

  NVIC_SetPriority(TIM7_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));

  /* USER CODE BEGIN TIM7_Init 1 */

  /* USER CODE END TIM7_Init 1 */
  TIM_InitStruct.Prescaler = 7199;                        // the timer will
  TIM_InitStruct.CounterMode = LL_TIM_COUNTERMODE_UP;	  // trigger interrupts
  TIM_InitStruct.Autoreload = 9;                          // every millisecond
  LL_TIM_Init(TIM7, &TIM_InitStruct);       //configure the TIMx time base unit
  LL_TIM_DisableARRPreload(TIM7); //clear ARPE bit in CR1 reg to disable auto-reload
  LL_TIM_SetTriggerOutput(TIM7, LL_TIM_TRGO_RESET); //set in reset mode group of bits MMS in CR2
  LL_TIM_DisableMasterSlaveMode(TIM7);
  /* USER CODE BEGIN TIM7_Init 2 */

  /* USER CODE END TIM7_Init 2 */

}
