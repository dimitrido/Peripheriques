#include "stm32f10x.h" // Clic droit sur stm32f10X.h et faire "open document"  pour ouvrir le fichier
#include "clock.h"
#include "gpio.h"


void (*Ptr_Fct1)(void);
void (*Ptr_Fct2)(void);
void (*Ptr_Fct3)(void);
void (*Ptr_Fct4)(void);

//durée en microsecondes
float Timer_1234_Init (TIM_TypeDef *timer, float duree){
	
	static float tempo=0;
	static float inter=0;
	static int compteur=0;
	
	duree=duree/1000000.0;
	
	if (timer==TIM1)
		
	(RCC->APB1ENR)|=  RCC_APB2ENR_TIM1EN;

	else if (timer==TIM2)
	(RCC->APB1ENR)|=  RCC_APB1ENR_TIM2EN;

	else if (timer==TIM3)
	(RCC->APB1ENR)|=  RCC_APB1ENR_TIM3EN;
		
	else if (timer==TIM4)
	(RCC->APB1ENR)|=  RCC_APB1ENR_TIM4EN;
	

	
	if ((float)CLOCK_GetTIMCLK(timer)*duree <= 65535){
	timer->ARR = ((CLOCK_GetTIMCLK(timer)*duree));
	timer->CR1 |= TIM_CR1_CEN;
	timer->PSC = 0;
	}
	else {
	timer->ARR = 0xFFFF;
	
	timer->PSC = CLOCK_GetTIMCLK(timer)*duree /(0xFFFF)+1;
	}
	tempo=(float)(timer->PSC * timer->ARR)/CLOCK_GetTIMCLK(timer);
	
	
	while( (tempo != duree) && (compteur!=10) ) 
	{
		inter=(float)((float)(duree * CLOCK_GetTIMCLK(timer))/timer->PSC);
		timer->ARR =(int)inter;
		tempo=(float)(timer->PSC * timer->ARR)/CLOCK_GetTIMCLK(timer);
		compteur ++;
	}	
	timer->CR1 |= TIM_CR1_CEN;
	
return (tempo);

}


// fonction initialisation d'interruption


void Timer_Active_IT(TIM_TypeDef *timer, u8 priority, void(*IT_function)(void))
{
	u8 num_it=0;
		
	if (timer==TIM1)
	{
		num_it=27;
		Ptr_Fct1=IT_function;
	}
	else if (timer==TIM2)
	{
		num_it=28;	
		Ptr_Fct2=IT_function;
	}
	else if (timer==TIM3)
	{
		num_it=29;	
		Ptr_Fct3=IT_function;
	}
	else if (timer==TIM4)	
	{
		num_it=30;
		Ptr_Fct4=IT_function;
	}
	
	NVIC->ISER[0] |= (0x01 << num_it); //set interrupt TIMER
	NVIC->IP[num_it] = priority; //set priority
	timer->DIER = TIM_DIER_UIE;	//update interrupt enable
	
	
}	




//
//Handler des Timer 1 a 4
//

void TIM1_IRQHandler (void)
{
	Ptr_Fct1();
	TIM1->SR &= ~0x01;
}
void TIM2_IRQHandler (void)
{
	Ptr_Fct2();
	TIM2->SR &= ~0x01;
}
void TIM3_IRQHandler (void)
{
	Ptr_Fct3();
	TIM3->SR &= ~0x01;
}
void TIM4_IRQHandler (void)
{
	Ptr_Fct4();
	TIM4->SR &= ~0x01;
}


//initialisation de la PWM, NE PAS appeler Timer_Init avant
//Fréquence en kHz

void PWM_init(TIM_TypeDef*Timer, char Voie, float Freq)
{
	static float periode=0;
	periode=1/Freq;
	periode=periode*1000.0;
	// on initialise le timer en adéquation avec les parametres
	Timer_1234_Init (Timer, periode);
	
	// initialisation du port de sortie adéquat
		if (Timer==TIM1)
		{
			if (Voie == 1)
			{
				Timer->CCMR1 |= (0x6<<4);
				Timer->CCR1 |= Timer->ARR /2;
				Port_IO_Init_Output( GPIOA, 8, 1);
			}
			else if (Voie ==2)
			{
				Timer->CCMR1 |= (0x6<<12);
				Timer->CCR2 |= Timer->ARR /2;
				Port_IO_Init_Output( GPIOA, 9, 1);
			}
			else if (Voie ==3)
			{
				Timer->CCMR2 |= (0x6<<4);
				Timer->CCR3 |= Timer->ARR /2;
				Port_IO_Init_Output( GPIOA, 10, 1);
			}
			else if (Voie ==4)
			{
				Timer->CCMR2 |= (0x6<<12);
				Timer->CCR4 |= Timer->ARR /2;
				Port_IO_Init_Output( GPIOA, 11, 1);
			}			
		}
		else if (Timer==TIM2)
		{
			if (Voie == 1)
			{
				Timer->CCMR1 |= (0x6<<4);
				Timer->CCR1 |= Timer->ARR /2;
				Port_IO_Init_Output( GPIOA, 0, 1);
			}
			else if (Voie ==2)
			{
				Timer->CCMR1 |= (0x6<<12);
				Timer->CCR2 |= Timer->ARR /2;
				Port_IO_Init_Output( GPIOA, 1, 1);
			}
			else if (Voie ==3)
			{
				Timer->CCMR2 |= (0x6<<4);
				Timer->CCR3 |= Timer->ARR /2;
				Port_IO_Init_Output( GPIOA, 2, 1);
			}
			else if (Voie ==4)
			{
				Timer->CCMR2 |= (0x6<<12);
				Timer->CCR4 |= Timer->ARR /2;
				Port_IO_Init_Output( GPIOA, 3, 1);
			}		
		}
		
		
		else if (Timer==TIM3)
		{
			if (Voie == 1)
			{
				Timer->CCMR1 |= (0x6<<4);
				Timer->CCR1 |= Timer->ARR /2;
				Port_IO_Init_Output( GPIOA, 6, 1);
			}
			else if (Voie ==2)
			{
				Timer->CCMR1 |= (0x6<<12);
				Timer->CCR2 |= Timer->ARR /2;
				Port_IO_Init_Output( GPIOA, 7, 1);
			}
			else if (Voie ==3)
			{
				Timer->CCMR2 |= (0x6<<4);
				Timer->CCR3 |= Timer->ARR /2;
				Port_IO_Init_Output( GPIOB, 0, 1);
			}
			else if (Voie ==4)
			{
				Timer->CCMR2 |= (0x6<<12);
				Timer->CCR4 |= Timer->ARR /2;
				Port_IO_Init_Output( GPIOB, 1, 1);
			}		
		}
		
		
		else if (Timer==TIM4)	
		{
			if (Voie == 1)
			{
				Timer->CCMR1 |= (0x6<<4);
				Timer->CCR1 |= Timer->ARR /2;
				Port_IO_Init_Output( GPIOB, 6, 1);
			}
			else if (Voie ==2)
			{
				Timer->CCMR1 |= (0x6<<12);
				Timer->CCR2 |= Timer->ARR /2;
				Port_IO_Init_Output( GPIOB, 7, 1);
			}
			else if (Voie ==3)
			{
				Timer->CCMR2 |= (0x6<<4);
				Timer->CCR3 |= Timer->ARR /2;
				Port_IO_Init_Output( GPIOB, 8, 1);
			}
			else if (Voie ==4)
			{
				Timer->CCMR2 |= (0x6<<12);
				Timer->CCR4 |= Timer->ARR/2;
				Port_IO_Init_Output( GPIOB, 9, 1);
			}		
		}
	

}

// donner le rapport cyclique en %
void Set_duty_cycle( TIM_TypeDef*Timer, char Voie, float Duty_cycle)
{
			if (Timer==TIM1)
		{
		if (Voie == 1)
			{
					Timer->CCR1 = (int)(Timer->ARR *(Duty_cycle/100));
			}
			else if (Voie ==2)
			{
				
				Timer->CCR2 = (int)(Timer->ARR *(Duty_cycle/100));
				
			}
			else if (Voie ==3)
			{
			
				Timer->CCR3 = (int)(Timer->ARR *(Duty_cycle/100));
			
			}
			else if (Voie ==4)
			{
				
				Timer->CCR4 = (int)(Timer->ARR *(Duty_cycle/100));
				
			}			
		}
		else if (Timer==TIM2)
		{
		if (Voie == 1)
			{
					Timer->CCR1 = (int)(Timer->ARR *(Duty_cycle/100));
			}
			else if (Voie ==2)
			{
				
				Timer->CCR2 = (int)(Timer->ARR *(Duty_cycle/100));
				
			}
			else if (Voie ==3)
			{
			
				Timer->CCR3 = (int)(Timer->ARR *(Duty_cycle/100));
			
			}
			else if (Voie ==4)
			{
				
				Timer->CCR4 = (int)(Timer->ARR *(Duty_cycle/100));
				
			}		
		}
		
		
		else if (Timer==TIM3)
		{
		if (Voie == 1)
			{
					Timer->CCR1 = (int)(Timer->ARR *(Duty_cycle/100));
			}
			else if (Voie ==2)
			{
				
				Timer->CCR2 = (int)(Timer->ARR *(Duty_cycle/100));
				
			}
			else if (Voie ==3)
			{
			
				Timer->CCR3 = (int)(Timer->ARR *(Duty_cycle/100));
			
			}
			else if (Voie ==4)
			{
				
				Timer->CCR4 = (int)(Timer->ARR *(Duty_cycle/100));
				
			}			
		}
		
		
		else if (Timer==TIM4)	
		{
			if (Voie == 1)
			{
					Timer->CCR1 = (int)(Timer->ARR *(Duty_cycle/100));
			}
			else if (Voie ==2)
			{
				
				Timer->CCR2 = (int)(Timer->ARR *(Duty_cycle/100));
				
			}
			else if (Voie ==3)
			{
			
				Timer->CCER |=(0x1<<8);
				Timer->CCR3 = (int)((float)(Timer->ARR *(Duty_cycle/100)));
			
			}
			else if (Voie ==4)
			{
				
				Timer->CCR4 = (int)(Timer->ARR *(Duty_cycle/100));
				
			}		
		}
}
