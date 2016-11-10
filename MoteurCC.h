#include "stm32f10x.h" // Clic droit sur stm32f10X.h et faire "open document"  pour ouvrir le fichier
#include "clock.h"
#include "gpio.h"
#include "Timer1234.h"


void MoteurCC_Init(float freqTelecommande);
float changeDirection(float dutyCycle);
