
#include "stm32f10x.h"
#include "clock.h"
#include "gpio.h"


float Timer_1234_Init (TIM_TypeDef *timer, float duree); // duree en microseconde

void Timer_Active_IT(TIM_TypeDef *timer, char priority, void(*IT_function)(void)); // fonction d'initialisation  d'interruption

void PWM_init(TIM_TypeDef*Timer, char Voie, float Freq);	// fonction d'initialisation de la PWM

void Set_duty_cycle( float Duty_cycle);	//fonction d'application du rapport cyclique