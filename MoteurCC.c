	#include "stm32f10x.h" // Clic droit sur stm32f10X.h et faire "open document"  pour ouvrir le fichier
	#include "clock.h"
	#include "gpio.h"
	#include "Timer1234.h"

void MoteurCC_Init(float freqTelecommande){ //dépend de la télécommande
	//Port_IO_Init_Output( GPIOA, 2, 0);
	PWM_init(TIM2, 3, freqTelecommande);
	Set_duty_cycle(TIM2, 3, 0);
}

void changeDirection(float dutyCycle){
	if (dutyCycle < 7.5){
	Port_IO_Set(GPIOA,2);
	Set_duty_cycle(TIM2,3,25);
	}
	else if (dutyCycle > 7.5) {
	Port_IO_Reset(GPIOA,2);
	Set_duty_cycle(TIM2,3,25);
	}
	else {Set_duty_cycle(TIM2,3,0);}
}
