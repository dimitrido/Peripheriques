	#include "stm32f10x.h" // Clic droit sur stm32f10X.h et faire "open document"  pour ouvrir le fichier
	#include "clock.h"
	#include "gpio.h"





float Init_ADC_Single_Conv(ADC_TypeDef * ADC, int channel)
{

	if (ADC == ADC1)
	{
		RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	}
	else if (ADC == ADC2)
	{
		RCC->APB2ENR |= RCC_APB2ENR_ADC2EN;
	}
	
	ADC->CR2|= ADC_CR2_ADON;
	ADC->CR2 &= ~ADC_CR2_CONT; //single conversion
	ADC->SQR1 &= ~(0xF << 20); //longueur de conversion
	
	ADC-> SQR3 &= ~(0x1F);
	ADC-> SQR3 |= channel;		// on choisit la chaine a utilisé dans SQ1 car single mode		
	ADC-> CR2 |= ADC_CR2_CAL;
	while ((ADC->CR2 & ADC_CR2_CAL)==ADC_CR2_CAL){}
	return 1;
}



u16 getADC (ADC_TypeDef * ADC, int channel)
{
		
	u16 DR;
	ADC->SQR3 &= ~(0xF);
	ADC-> SQR3 |= channel;
	ADC->CR2 |= ADC_CR2_ADON;
		
	while ((ADC->SR & ADC_SR_EOC) == 0){	}
	DR = ADC->DR;
	return DR;
}

