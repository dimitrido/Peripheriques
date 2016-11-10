#include "stm32f10x.h"
#include "servomoteur.h"
#include "clock.h"
#include "gpio.h"	
#include "timer1234.h"
	
	
 void init_girouette(TIM_TypeDef*Timer)
{
	
	Timer->ARR=1439;
	// configuration des deux pin T1 et T2
	
	Timer->CCMR1 &=~(0x303);
	Timer->CCMR1 |= (0x202);
	
	// configuration SMCR
	
	Timer->SMCR &=~(0x7);
	Timer->SMCR |=(0x3);
	
	// configuration CCER
	
	Timer->CCER &=~(0x22);
	Timer->CCER |=(0x22);
	
	//lancer comptage
	 Timer->CR1 |= TIM_CR1_CEN;
	
}
	
	
	
	
	
