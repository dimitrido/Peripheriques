#include "stm32f10x.h"
#include "clock.h"
#include "gpio.h"

void init_girouette(TIM_TypeDef*Timer);
int angle_girouette(TIM_TypeDef*Timer);
