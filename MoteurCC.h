#include "stm32f10x.h"

void USART_Init_Trans(USART_TypeDef * USART);
void USART_Init_Recep(USART_TypeDef *USART);
int USART_Send (USART_TypeDef * USART, u8 data);
