
#include "main.h"
#include "stm32f4xx_it.h"

extern volatile int time;

void USART_TX (uint8_t* dt, uint16_t sz);
void DMA1_TransmitComplete(void);

void DMA1_Stream6_IRQHandler(void)
{
	  if(LL_DMA_IsActiveFlag_TC6(DMA1))
	  {
	    LL_DMA_ClearFlag_TC6(DMA1);
	    DMA1_TransmitComplete();
	  }
	  else if(LL_DMA_IsActiveFlag_TE6(DMA1))
	  {
	    LL_DMA_DisableStream(DMA1, LL_DMA_STREAM_6);
	  }
}


void TIM7_IRQHandler(void)
{
	if(LL_TIM_IsActiveFlag_UPDATE(TIM7))
	  {
	    LL_TIM_ClearFlag_UPDATE(TIM7);
	  }
	time++;

}

