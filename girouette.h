
#include "stm32f10x.h"
#include "clock.h"
#include "gpio.h"

float pos_servomoteur(int angle, int anglemax, int anglemin,TIM_TypeDef*Timer, char Voie);
