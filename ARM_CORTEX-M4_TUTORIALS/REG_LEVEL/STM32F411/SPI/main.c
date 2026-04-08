/*
MOSI - PA7
MISO -
SCK - PA5
SS - PA4

RCC->AHB1ENR=1<<0 //A PORT
ENABLE SPI CLOCK , AF5 IS THE SPI PIN
WE ARE CHOOSING SPI1
MODER FOR 3 PINS AS ALTERNATING FUN
ALTERNATING FUN[L OR H] SET



*/
#include "stm32f4xx.h"                  // Device header

void spi_pin_init()
{
	RCC->AHB1ENR |=1;//(1<<0)
	
	GPIOA->MODER |= 1<<15 | 1<<11 | 1<<9 ; 
	
	
	
}
void spi_init()
{
	
}

int main()
{
	
}
