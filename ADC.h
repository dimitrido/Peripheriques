
#include "stm32f10x.h"
#include "clock.h"
#include "gpio.h"


float Init_ADC_Single_Conv(ADC_TypeDef * ADC,int channel);
u16 getADC (ADC_TypeDef * ADC, int channel);