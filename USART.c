	#include "stm32f10x.h" // Clic droit sur stm32f10X.h et faire "open document"  pour ouvrir le fichier
	#include "clock.h"
	#include "gpio.h"

void Init_Usart_Trans(USART_TypeDef * USART){
USART->CR1 &= ~(0x1 <<12);
USART->CR1 |= (0x01<<3);	
USART->BRR |= (0x1D4<<4);
USART->BRR |= 0xC ;
USART-> CR2 &= ~(0x3<<12);
USART->CR1 |= (0x01<<13);
}

void Init_Usart_Recep(USART_TypeDef *USART){
USART->CR1 &= ~(0x1 <<12);
USART->CR1 |= (0x01<<2);	
USART->BRR |= (0x1D4<<4);
USART->BRR |= 0xC ;
USART-> CR2 &= ~(0x3<<12);
USART->CR1 |= (0x01<<13);

}


int USART_Send (USART_TypeDef * USART, u8 data){
if ((USART->CR2 & (0x01<<7))==1){
	USART->DR = data;
	return 0;
}
else {return -1;}
}