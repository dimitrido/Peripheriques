//__________________________________________________________
// BINOME :
// ETAT : 
//__________________________________________________________

//____ registres de périphériques du stm_32
#include "stm32f10x.h"
#include "servomoteur.h"
#include "clock.h"
#include "gpio.h"	
#include "timer1234.h"


int main (void)
{
	static int PWM=3;

	PWM = pos_servomoteur(45, 180, 0,TIM2,2 );
	

	return 0;
}

