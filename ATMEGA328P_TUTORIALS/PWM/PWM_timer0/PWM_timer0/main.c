/*
 * PWM_timer0.c
 *
 * Created: 02-06-2019 22:37:28
 * Author : [Developer]
 */ 
#define F_CPU  16000000L 
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
double DutyCycle;

int main(void)
{
	DDRB=0xFF;
	PORTB=0x00;
	DDRD=1<<PORTD6;
    TCCR0A=((1 << COM0A1) | (1<<WGM01) | (1<<WGM00));// CLEAR OCROA ON COMPARE MATCH AND ENABLE FAST PWM
	TCCR0B=(1<<CS02)|(1<<CS00);
//	TIMSK0=(1<<TOIE0);
	sei();
	DutyCycle=10;
	OCR0A=((DutyCycle/100)*255.0);
    while (1) 
    {	_delay_ms(100);
		//DutyCycle+=10;
		
		if(DutyCycle>100)
		{
			DutyCycle=0;
		}

    }
}
ISR(TIMER0_OVF_vect)
{
		DutyCycle=10;
		OCR0A=((DutyCycle/100)*255);
		PORTB=~PORTB;
	
}


