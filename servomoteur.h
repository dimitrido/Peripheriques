
#include "stm32f10x.h"
#include "clock.h"
#include "gpio.h"


void init_servo(TIM_TypeDef*Timer, char Voie);
float servo(float duty,TIM_TypeDef*Timer, char Voie);
int vent (int angle);
