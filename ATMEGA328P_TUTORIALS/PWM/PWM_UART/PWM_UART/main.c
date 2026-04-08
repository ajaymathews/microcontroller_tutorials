/*
 * PWM_timer0.c
 *
 * Created: 02-06-2019 22:37:28
 * Author : [Developer]
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define F_CPU 8000000L
#define BAUD 9600
#define NORMAL_BAUD ((F_CPU/16/BAUD)-1) //corresponding value is 5
double DutyCycle;
double reg_value;


char c; // needed bcz without it only 1 commnd be executed,ie1st cmmnd is identified only
void recieve_setup()
{
	UBRR0=NORMAL_BAUD;//SETTING BAUD RATE
	UCSR0B=(1<<RXEN0);//Enables reception and transmission to replay //corrspndg reg value :0x10
	UCSR0C=((1<<UCSZ00)|(1<<UCSZ01));// enables 8 bit transmission/reception   //corrspndg reg value :0x06
}
void pwm_setup()
{	
	TCCR0A=((1 << COM0A1) | (1<<WGM01) | (1<<WGM00));// CLEAR OCROA ON COMPARE MATCH AND ENABLE FAST PWM
	TCCR0B=(1<<CS02)|(1<<CS00);//prescalar on /1024
}
void pwm_interrupt()
{
		TIMSK0=(1<<TOIE0);
		sei();
}
void get_from_uart()
{
	c=UDR0;
	DutyCycle=(double)c;
	reg_value=((DutyCycle/10)*255.0);
	return(reg_value);
}
int main(void)
{
	DDRB=0xFF;
	PORTB=0x00;
	
	DDRD=1<<PORTD6;
    recieve_setup();
	pwm_setup();
	//pwm_interrupt();
	OCR0A=get_from_uart();
    while (1) 
    {	
		get_from_uart();
		OCR0A=get_from_uart();
    }
}











ISR(TIMER0_OVF_vect)
{
		DutyCycle=10;
		OCR0A=((DutyCycle/100)*255);
		PORTB=~PORTB;
	
}


