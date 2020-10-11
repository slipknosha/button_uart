#include "init.h"

void SystemClock_Config(void)
{
  LL_FLASH_SetLatency(LL_FLASH_LATENCY_2);// In register FLASH_ACR set the 0x02 in group of bits named LATENCY that represent the ratio of the CPU clock period to the Flash memory access time. Setting 0x02 makes two wait states;
  while(LL_FLASH_GetLatency()!= LL_FLASH_LATENCY_2); //read while it will not reach 2

  LL_PWR_SetRegulVoltageScaling(LL_PWR_REGU_VOLTAGE_SCALE1); //set VOS bit in PWR_CR register
  LL_RCC_HSE_Enable(); //set HSEON bit in RCC_CR register


  while(LL_RCC_HSE_IsReady() != 1); /* Wait till HSE is ready */

  LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSE, LL_RCC_PLLM_DIV_4, 72, LL_RCC_PLLP_DIV_2);// set PPLM as 4, PPLP as 2, PPLN as 72 - configuring PLL
  LL_RCC_PLL_Enable();//set PLLON bit in RCC_CR register


  while(LL_RCC_PLL_IsReady() != 1);  /* Wait till PLL is ready */
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1); //set HPRE group of bits in CFGR register to 0xx - system clock not divided
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_2); //set group of bits PPRE1 in CFGR to 100 - AHB clock divided by 2
  LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);//set group of bits PPRE2 in CFGR to 0xx - AHB clock not divided
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);//set 10 in SW group of bits in CFGR - PLL selected as system clock


  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL); /* Wait till System clock is ready */
  LL_Init1msTick(72000000); //this function configures the Cortex-M SysTick source to have 1ms time base
  LL_SetSystemCoreClock(72000000); //this function sets directly SystemCoreClock CMSIS variable
}
