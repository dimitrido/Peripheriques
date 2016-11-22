#include "stm32f10x.h"
#include "servomoteur.h"
#include "clock.h"
#include "gpio.h"	
#include "timer1234.h"
#include "girouette.h"
	
	
	
void init_servo(TIM_TypeDef*Timer, char Voie)
{
	PWM_init(Timer, Voie, 0.050);
	Set_duty_cycle(Timer, Voie , 10);
	
}
	
float servo(float duty,TIM_TypeDef*Timer, char Voie)
{
	//PWM_init(Timer, Voie, 0.050);
	Set_duty_cycle(Timer, Voie , duty);
	return 0;
}
