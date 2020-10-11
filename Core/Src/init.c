#include "init.h"

void init(void)
{
	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SYSCFG);
	LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);
	NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_0);
	SystemClock_Config();
	GPIO_Init();
	DMA_Init();
	USART2_UART_Init();
	TIM7_Init();
	LL_DMA_DisableStream(DMA1, LL_DMA_STREAM_6);
	LL_DMA_ClearFlag_TC6(DMA1);
	LL_DMA_ClearFlag_TE6(DMA1);
	LL_USART_EnableDMAReq_TX(USART2);
	LL_DMA_EnableIT_TC(DMA1, LL_DMA_STREAM_6);
	LL_DMA_EnableIT_TE(DMA1, LL_DMA_STREAM_6);
	LL_DMA_ClearFlag_TC6(DMA1);
	LL_DMA_ClearFlag_TE6(DMA1);
}
