#include "stm32f10x.h"
#include "servomoteur.h"
#include "clock.h"
#include "gpio.h"	
#include "timer1234.h"
	
	
	
	
	
float pos_servomoteur(int angle, int anglemax, int anglemin,TIM_TypeDef*Timer, char Voie )  // sortie sur GPIOA.1 pour TIM2_CH2
{	
	static float pwm ;
	static int delta_angle;
	
	delta_angle= anglemax-anglemin;
	PWM_init(Timer, Voie, 0.050);
	
	pwm= angle;
	pwm = ((pwm/delta_angle)+1);
	pwm = (pwm/(20))*Timer->ARR;
	
	if (Voie == 1)
	{Timer->CCR1 = (int)pwm;}
	if (Voie == 2)
	{Timer->CCR2 = (int)pwm;}
	if (Voie == 3)
	{Timer->CCR3 = (int)pwm;}
	if (Voie == 4)
	{Timer->CCR4 = (int)pwm;}	

	/*aux = (angle*1)/180;
	dutycycle = (1 + aux )/20;
	Timer->ARR *(Duty_cycle*/


	

	return (int)pwm;
}