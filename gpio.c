#include "stm32f10x.h" // Clic droit sur stm32f10X.h et faire "open document"  pour ouvrir le fichier





// fonction d'initialisation d'un broche en sortie
char Port_IO_Init_Output( GPIO_TypeDef * Port, u8 Broche, char alternate_mode){
	
if (Port==GPIOA)
	(RCC->APB2ENR) |=  RCC_APB2ENR_IOPAEN  ;
else if (Port==GPIOB)
	(RCC->APB2ENR) |=  RCC_APB2ENR_IOPBEN ;
else if (Port==GPIOC)
	(RCC->APB2ENR) |=  RCC_APB2ENR_IOPCEN ;
else if (Port==GPIOD)
	(RCC->APB2ENR) |=  RCC_APB2ENR_IOPDEN ;

if(alternate_mode==0)
{
	if (Broche < 8)
	{
		Port->CRL &= ~(0xF << Broche * 4);
		Port->CRL |= (0x01 << Broche * 4);
	}
	else 
	{
		Port->CRH &= ~(0xF << ((Broche - 8) * 4));
		Port->CRH |= (0x01 << ((Broche - 8) * 4));
		
	}
}

if(alternate_mode==1)
{
	if (Broche < 8)
	{
		Port->CRL &= ~(0xF << Broche * 4);
		Port->CRL |= (0x9 << Broche * 4);
	}
	else 
	{
		Port->CRH &= ~(0xF << ((Broche - 8) * 4));
		Port->CRH |= (0x9 << ((Broche - 8) * 4));
	}
}
return 0;
}



// fonction d'initialisation d'un broche en entrée
char Port_IO_Init_Input( GPIO_TypeDef * Port, u8 Broche, char analog)
{

if (Port==GPIOA)
	(RCC->APB2ENR) |=  RCC_APB2ENR_IOPAEN  ;
else if (Port==GPIOB)
	(RCC->APB2ENR) |=  RCC_APB2ENR_IOPBEN ;
else if (Port==GPIOC)
	(RCC->APB2ENR) |=  RCC_APB2ENR_IOPCEN ;
else if (Port==GPIOD)
	(RCC->APB2ENR) |=  RCC_APB2ENR_IOPDEN ;


if(analog==0)
{
	if (Broche < 8)
	{
		Port->CRL &= ~(0xF << Broche * 4);
		Port->CRL |= (0x04 << (Broche*4));;
	}
	else 
	{
		Port->CRH &= ~(0xF << ((Broche - 8) * 4));
		Port->CRH |=  (0x04 << ((Broche - 8) * 4));;
		
	}
}

if(analog==1)
{
	if (Broche < 8)
	{
		Port->CRL &= ~(0xF << Broche * 4);
		Port->CRL |= (0x0 << Broche * 4);
	}
	else 
	{
		Port->CRH &= ~(0xF << ((Broche - 8) * 4));
		Port->CRH |= (0x0 << ((Broche - 8) * 4));
	}
}

return 0;
}



// fonction de mise à un d'une broche
void Port_IO_Set(GPIO_TypeDef * Port, u8 Broche){
Port->BSRR = (0x01 << Broche);
}

// fonction de mise à zero d'une broche
void Port_IO_Reset(GPIO_TypeDef * Port, u8 Broche){
Port->BRR = (0x01 << Broche);
}

// fonction d'inversion de valeur d'une broche
void Port_IO_Blink(GPIO_TypeDef * Port, u8 Broche){
if (((Port->ODR) & (0x01 << Broche)) == (0x01 << Broche))
{	Port_IO_Reset(Port, Broche);}
else
{	Port_IO_Set(Port,Broche);}
}

// fonction de lecture d'une entrée
unsigned int Port_IO_Read(GPIO_TypeDef * Port, u8 Broche){
return (((Port->IDR) & (0x01 << Broche)) >> Broche);
}




