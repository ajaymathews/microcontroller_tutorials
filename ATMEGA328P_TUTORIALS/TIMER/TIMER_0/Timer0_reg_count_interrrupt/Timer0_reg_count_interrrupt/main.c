/*
 * Interrupt_1.c
 *
 * Created: 31-05-2019 15:06:00
 * Author : [Developer]
 
note: do not write the ocr value and the starting value of tcnto be same or below.
      or do not write ocr value when tcnt0 is running that may result in the timer to skip the comparison
      
    :in normal timer mode tovo flag is set using an interrupt,and starts from zero
*/ 
#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 128000L // for the atmega to change the fq, if using proteus select the fq 128khz from int osclltr
int count=0;
int main(void)
{
TCCR0A=1<<WGM01; // setting CTC mode(WGM01 bit=1), which is that at CTC clears the timer on comparison with the OCROA,and resets to zero
TCCR0B=0X05;  //setting a prescalar value of clk/1024
OCR0A=100;  //(reg value 960 is 1 sec for max or the default fq ,    so u can use loop for max reg value 255 be in 960 range)
//OCR0A=7;           //(reg value 14 is 1 sec for fq 128khz,thereis a slight variation in 1*14 and 7*2)
TIMSK0=1<<OCIE0A;// setting when the timer 0 match occurs,an interrupt is enabled

sei(); // setting all the exernal interrupt,by including <avr/interrupt.h> header

DDRB=0xFF;
PORTB=0x00;
    while (1) 
    {	

	}
}

ISR(TIMER0_COMPA_vect)  //at each time tnt0  reaches ocroa, this interrupt is called. 
{                       //the reg comparison is done using a comparator ckt in atmega
	//PORTB=~PORTB;
	count++;
	if(count>=78)
	{
		count=0;
		PORTB=~PORTB;
	}
	
}


