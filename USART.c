	#include "stm32f10x.h" // Clic droit sur stm32f10X.h et faire "open document"  pour ouvrir le fichier
	#include "clock.h"
	#include "gpio.h"

void USART_Init_Trans(USART_TypeDef * USART){
RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
Port_IO_Init_Output( GPIOA, 9);
USART->CR1 &= ~(0x1 <<12);
USART->CR1 |= (0x01<<3);	
USART->BRR |= (0x1D4<<4);
USART->BRR |= 0xC ;
USART-> CR2 &= ~(0x3<<12);
USART->CR1 |= (0x01<<13);
}

void USART_Init_Recep(USART_TypeDef *USART){
RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
USART->CR1 &= ~(0x1 <<12);
USART->CR1 |= (0x01<<2);	
USART->BRR |= (0x1D4<<4);
USART->BRR |= 0xC ;
USART-> CR2 &= ~(0x3<<12);
USART->CR1 |= (0x01<<13);

}


int USART_Send (USART_TypeDef * USART, u8 data){
if ((USART->DR )==0){ //tester avec TXE
	USART->DR = data;
	return 0;
}
else {return -1;}
}
