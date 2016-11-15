#include "stm32f10x.h"
#include "servomoteur.h"
#include "clock.h"
#include "gpio.h"	
#include "timer1234.h"
	
	
 void init_girouette(TIM_TypeDef*Timer)
{
	
	if (Timer==TIM1)
		
	(RCC->APB1ENR)|=  RCC_APB2ENR_TIM1EN;

	else if (Timer==TIM2)
	(RCC->APB1ENR)|=  RCC_APB1ENR_TIM2EN;

	else if (Timer==TIM3)
	(RCC->APB1ENR)|=  RCC_APB1ENR_TIM3EN;
		
	else if (Timer==TIM4)
	(RCC->APB1ENR)|=  RCC_APB1ENR_TIM4EN;
	
	
		
	// configuration SMCR
	
	Timer->SMCR &=~(TIM_CCMR1_CC1S);
	Timer->SMCR |=(TIM_CCMR1_CC1S_0);
	Timer->SMCR |=(TIM_CCMR1_CC1S_1);
	
	// configuration des deux pin T1 et T2
	
	Timer->CCMR1 &=~(TIM_CCMR1_CC1S);
	Timer->CCMR1 |= (TIM_CCMR1_CC1S_0);
	Timer->CCMR1 &=~(TIM_CCMR1_CC2S);
	Timer->CCMR1 |= (TIM_CCMR1_CC2S_0);
	
	// configuration CCER
	
	Timer->CCER &=~(TIM_CCER_CC1P);
	Timer->CCER &=~(TIM_CCER_CC2P);
	
	//gestion ARR
	
	Timer->ARR=1439;
	
	//lancer comptage
	 Timer->CR1 |=TIM_CR1_CEN;
	
}
	
int angle_girouette(TIM_TypeDef*Timer)
{
	return (Timer->CNT)/4;
}
	
	
	
	
	
	
