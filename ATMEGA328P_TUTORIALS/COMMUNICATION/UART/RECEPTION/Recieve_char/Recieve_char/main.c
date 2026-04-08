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

#define F_CPU 8000000L

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


#define BAUD 9600
#define NORMAL_BAUD ((F_CPU/16/BAUD)-1) //corresponding value is 5

char c; // needed bcz without it only 1 commnd be executed,ie1st cmmnd is identified only 

void recieve_setup()
{
	UBRR0=NORMAL_BAUD;//SETTING BAUD RATE       
	UCSR0B=(1<<RXEN0)|(1<<TXEN0);//Enables reception and transmission to replay //corrspndg reg value :0x10
	UCSR0C=((1<<UCSZ00)|(1<<UCSZ01));// enables 8 bit transmission/reception   //corrspndg reg value :0x06
}
void blink_on_x()
{
	while (!(UCSR0A & 1<<RXC0));//WAIT FOR DATA TO BE RECIVED,ie while(!(1)); if data recived, 
		c=UDR0;
		if((c=='X')|(c=='x'))
		{
			PORTC=0x01;
			UDR0=c;
			while(!(UCSR0A&1<<TXC0)); //wait till the udr0 is empty, (!(1)), 1 if udr0 is empty. 
			//while(!(UCSR0A&1<<UDRE0));
		}
		else
		{
			PORTC=0x00;
			//UDR0=c;
		}
		//UDR0=c;
}
int main(void)
{
	DDRC=0x01;  // C PORT IS USED FOR OUTPUT BCZ THE PINS THAT THE CRYSTAL OSCILLTOR GETS CONNECED TO
				// SHOULDNT BE A AN OUTPUT, WE CAN STILL USE B PORT AS AN OUTPUT IF ONLY THE LED PORT IS SET AS INPUT :PORTB=1<<PORTB0
	PORTC=0x00;
	recieve_setup();
    while (1)
	{ 
		blink_on_x();			
	}
}


