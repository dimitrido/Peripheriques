#include "stm32f10x.h"
#include "clock.h"
#include "gpio.h"


void IN_SURVEILLANCE_ALIM (void){// broche d'entrée PC2 (Schema voilier.PDF)
	
	Init_ADC_Single_Conv(ADC1, 12); // single mode
	Port_IO_Init_Input( GPIOC, 2, 1);
	
}

u16 LIR_SURVEILLANCE_ALIM (void){ // lecture d'entrée 
	
	static u16 DR;
	ADC1->CR2 |= ADC_CR2_ADON;
	while ((ADC1->SR & ADC_SR_EOC) == 0){	}
	DR = ADC1->DR;
	DR = (DR*100)/0xFFF;
	return DR;
}

unsigned int Low_batterie (float TENSION_REF, float TENSION_LIMITE ){ // Watchdog en PC2
	
	unsigned int WATCHDOG;
	WATCHDOG = (TENSION_LIMITE * (0xFFF))/ TENSION_REF; 
	ADC1-> LTR = WATCHDOG;
	ADC1-> HTR = 0xFFF; // limite supérieure toujours maximale
  (ADC1->CR1)|= ADC_CR1_AWDCH_3 | ADC_CR1_AWDCH_2 ;	//Watchdog en PC2
	//ADC1->CR1|=ADC_CR1_AWDIE; //permettre l'interruption watchdog 
	ADC1->CR1|=ADC_CR1_AWDEN; // watchdog ENABLE
return 0;

}
