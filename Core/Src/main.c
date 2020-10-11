#include "main.h"

volatile uint8_t fl_tx=0;
volatile int time=0;
char str[50];
char milliseconds[] = " milliseconds\n";

void USART_TX (uint8_t* dt, uint16_t sz);

int main(void)
{

  init();

  uint8_t reading = 0;
  uint8_t debounce_flag = 1;
  uint8_t uart_flag = 1;
  char warning[] = "Ukrainian Cossacks hold the button more than a second!\n";

  while (1)
  {
	  if ((reading =  (LL_GPIO_ReadInputPort(GPIOA)&GPIO_IDR_IDR_0))) { //reading current state of button
		  uart_flag=1;
		  if (debounce_flag) {
			  NVIC_EnableIRQ(TIM7_IRQn);//enable timer interrupt
			  LL_TIM_EnableIT_UPDATE(TIM7);//enable update of interrupt
			  LL_TIM_EnableCounter(TIM7);//enable counter of timer
			  while (time < 30); //debounce: waiting 30 ms
			  time = 0;
			  debounce_flag = 0;
		  }
	  } else {
		  if(uart_flag) {
			  NVIC_DisableIRQ(TIM7_IRQn);
			  LL_TIM_DisableIT_UPDATE(TIM7);
			  LL_TIM_DisableCounter(TIM7);
			  if(time < 1000) {
				  LL_DMA_ConfigAddresses(DMA1, LL_DMA_STREAM_6, (uint32_t)&warning, LL_USART_DMA_GetRegAddr(USART2), LL_DMA_GetDataTransferDirection(DMA1, LL_DMA_STREAM_6)); //string to transfer in UART is warning array
			  	  USART_TX((uint8_t*)warning, (uint8_t)sizeof(warning)); //func for transfer the data to PC from MCU
			  } else {
				  LL_DMA_ConfigAddresses(DMA1, LL_DMA_STREAM_6, (uint32_t)&str, LL_USART_DMA_GetRegAddr(USART2), LL_DMA_GetDataTransferDirection(DMA1, LL_DMA_STREAM_6));//select the str string
			  	  inttostr(time, str, 10);//converting int to str
			  	  concat(str, milliseconds);// concat the str and milliseconds array
			  	  USART_TX((uint8_t*)str, (uint8_t)sizeof(str));
			  }
			  	  time = 0;
			  	  reading = 0;
			  	  uart_flag = 0;
			  	  debounce_flag = 1;
			  }
		  }


	  }

  }

void DMA1_TransmitComplete(void)
{
  fl_tx = 1;
}

void USART_TX (uint8_t* dt, uint16_t sz)
{
  LL_DMA_DisableStream(DMA1, LL_DMA_STREAM_6);
  LL_DMA_SetDataLength(DMA1, LL_DMA_STREAM_6, sz);//set number of data to transfer
  LL_DMA_EnableStream(DMA1, LL_DMA_STREAM_6);
  while (!fl_tx); //waiting for transmit complete
  fl_tx=0;
}
