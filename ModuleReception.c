#include "stm32f10x.h" // Clic droit sur stm32f10X.h et faire "open document"  pour ouvrir le fichier
	#include "clock.h"
	#include "gpio.h"
	#include "Timer1234.h"

void ModuleReception_Init(float freqTelecommande){ //dépend de la télécommande
	PWM_init(TIM4, '1', freqTelecommande);
}


float getDutyCycle(void){
	return (TIM4->CCR2);
}
