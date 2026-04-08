/*
 * Recieve.c
 *
 * Created: 15-06-2019 11:11:07
 * Author : [Developer]
 
 ucsr0a->RXC0 will be 1 at reception is complete
  ucsr0a->udre0 will be one if the buffer is ready to write new data.
 ucsr0b->rxcie will be 1,reception interrupt 
 ucsr0b->rxen ;1, enabls reception
ucsr0c-> ucsz01,ucsz00:1 ,for 8 bit transmission
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define F_CPU 8000000L
#define BAUD 9600
#define NORMAL_BAUD ((F_CPU/16/BAUD)-1)

char c;
void recieve_setup()
{
	 
	UBRR0=NORMAL_BAUD;//SETTING BAUD RATE       
	UCSR0B=(1<<RXEN0)|(1<<TXEN0);//Enables reception
	UCSR0C=((1<<UCSZ00)|(1<<UCSZ01));// enables 8 bit transmission/reception
}
void enable_interrupt()
{
	UCSR0B|=(1<<RXCIE0);
	sei();
}

 
void led_on_x()
{
	while ((UCSR0A & 1<<7) ){
	c=UDR0;
	if(c=='X'|c=='x')
	{
		PORTC=0x01;
		_delay_ms(500);
		UDR0='Z';
	}
	else
	{
	PORTC=0x00;
	//delay_ms(100);
	}
	}
}
int main(void)
{
	DDRC=0x01;
	PORTC=0x00;
	recieve_setup();
//	enable_interrupt();
    while (1)
	{ 
		led_on_x();			
	}
}

ISR(USART_RX_vect)
{
	PORTC=0xFF;
	_delay_ms(500);	
	PORTC=0x00;
} 

