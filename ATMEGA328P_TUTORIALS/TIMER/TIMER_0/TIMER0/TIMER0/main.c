
/*
 * timer0.c
 *
 * Created: 25-01-2019 10:19:54
 * Author : Student
*/
/*
#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000L
int cnt=0;
int j;
void timer0_init()
{
	
	TCCR0B= 0X05; //00000101 prescalar as /1024	
	
	TCNT0 = 0;   //timer value starts at zero
	
}

void delay()
{
	for(j=0;j<=31;j++);//for 1 sec dely on fq 8000000 in proteus
	{	
		while (!(TCNT0 ==255));
		TCNT0 =0;
	}
}

int main(void)
{
	
	//DDRC=0XFF;
	DDRD=0XFF;
	//sei();
	//timer0_init();
	TCCR0B= 0X05; //00000101 prescalar as /1024
	TCNT0 = 0;
    PORTD=0X00;
	while(1)
	{
		PORTD=0X00;
		delay();
		
			PORTD=0XFF;
			delay();
	}
}




 //interrupts when the TCNTO reaches a certain count
 
#include <avr/io.h>
#define F_CPU 128000L

int main(void)
{
	DDRB=0xFF;
	TCNT0=0;
	PORTB=0x00;
	TCCR0B=0x05;
	while(1)
	{
		if(TCNT0==13)
		{
			
			
			PORTB=~PORTB;
			TCNT0=0;
		}
		
	}
}

 interrupts when the t0v0 flag is set*/ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define F_CPU 8000000
int count=0;

int main(void)
{
	DDRB=0xFF;
	PORTB=0x00;
	TCCR0B=0x05;//1024
	TCNT0=0;
	//TIFR0=1<<TOV0;
	TIMSK0=1<<TOIE0;
	sei();
	
	while(1)
	{
	
	}
}
 
ISR(TIMER0_OVF_vect)
{
	if(count==31)
	{
	PORTB=~PORTB;
	count=0;
	}
	count++;
	//TCNT0=0;
	//cli();
}
