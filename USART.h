
#include "stm32f10x.h"
#include "clock.h"
#include "gpio.h"


float Init_ADC_Single_Conv(ADC_TypeDef * ADC, u16 Duree_Acq_us);
u16 getADC (ADC_TypeDef * ADC, int channel);