/*
 * Recieve_char_interrupt.c
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
	//UCSR0B=(1<<RXEN0)|(1<<TXEN0);//Enables reception and transmission
	UCSR0B=(1<<RXEN0);//Enables reception
	UCSR0C=((1<<UCSZ00)|(1<<UCSZ01));// enables 8 bit transmission/reception
}
void enable_interrupt()
{
	UCSR0B|=(1<<RXCIE0);
	sei();
} 
void check_rcv()
{
	while ((UCSR0A & 1<<7))
	{
	c=UDR0;
	if(UDR0=='x')
	{
	PORTC=1<<PORTC1;		
	}
	}
	while (!(UCSR0A & 1<<7));
	_delay_ms(500);
	PORTC=0x00;	//code that executes, when no reception, or after reception
}
void blink()//to generate a continously running LED, to satisfy the interrupt is working, but to be noted that c port is used, thus pcint13 may get affected, in that case change it to bport
{
	DDRC=1<<PORTC0;
	PORTC=(1<<PORTC0);
	_delay_ms(500);
	PORTC^=(1<<PORTC0);
	_delay_ms(500);
}
int main(void)
{
	DDRB=0x01;
	recieve_setup();
	enable_interrupt();
    while (1)
	{ 
	blink();
	}
}
ISR(USART_RX_vect)  //calls interrput at the time of reception
{
	if(UDR0=='X')
	{
	PORTB^=1<<PORTB0;	//code to execute at interrupt, i
	}
	//while (!(UCSR0A & 1<<7));
	blink();
} 

