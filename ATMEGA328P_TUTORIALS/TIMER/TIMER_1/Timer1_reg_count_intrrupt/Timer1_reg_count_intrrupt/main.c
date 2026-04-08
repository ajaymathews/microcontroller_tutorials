/*
 * Timer1_reg_count_intrrupt.c
 *
 * Created: 02-06-2019 16:46:17
 * Author : [Developer]
 */ 
//non blocking delay, as by the interrupt feature
#include <avr/io.h>
#include <avr/interrupt.h>
//#define F_CPU 16000000L
#define F_CPU 128000L
int main(void)
{
    // setting CTC mode(WGM12 bit=1), which is that at CTC clears the timer on comparison with the OCROA,and resets to zero
	TCCR1B=(1<<CS12)|(1<<CS10)|(1<<WGM12); //setting a prescalar value of clk/1024
	//OCR1A=960;//960 is the reg value for default fq
	OCR1A=15;//15 is the reg value for 128khz
	TIMSK1=1<<OCIE1A; //interrupt enable on output match On reg A
	DDRB=0xFF;
	PORTB=0x00;
	sei();
	while(1)
	{
		
		
	}
}
ISR(TIMER1_COMPA_vect)
{
	PORTB=~PORTB;	
}

