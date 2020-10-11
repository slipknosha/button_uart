#ifndef __INIT_H
#define __INIT_H

#include "stm32f4xx_ll_dma.h"
#include "stm32f4xx_ll_rcc.h"
#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_system.h"
#include "stm32f4xx_ll_exti.h"
#include "stm32f4xx_ll_cortex.h"
#include "stm32f4xx_ll_utils.h"
#include "stm32f4xx_ll_pwr.h"
#include "stm32f4xx_ll_tim.h"
#include "stm32f4xx_ll_usart.h"
#include "stm32f4xx_ll_gpio.h"
#include "main.h"

extern char str[50];

void SystemClock_Config(void);
void GPIO_Init(void);
void DMA_Init(void);
void USART2_UART_Init(void);
void TIM7_Init(void);
void init(void);

#endif
