/*
 * PWM_jimshi_test.c
 *
 * Created: 03-06-2019 16:32:59
 * Author : [Developer]
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 128000L 


int main(void)
{
	DDRD=0xFF;
	TCCR0B=0xC3;
	TCCR0A=0x01;
	OCR0A=0x01;

    while (1) 
    {
		TCNT0=0xFF;
		while(!(TIFR0&(1<<1)));
		TIFR0=0x02;
		TCNT0=0xFF;
	}
}
		

