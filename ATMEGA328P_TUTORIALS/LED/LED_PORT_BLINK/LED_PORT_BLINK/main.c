/*
 * GccApplication3.c
 *
 * Created: 29-05-2019 11:06:37
 * Author : [Developer]
 */ 

#include <avr/io.h>
#include <avr/delay.h>

#define F_CPU 16000000L


int main(void)
{
	DDRB=0xFF; //used to set the direction of the register,ie o for input, and 1 for output
//DDRB=1<<PORTB3 // SETTING ONLY THE 3RD PIN IN PORT B
    PORTB=0x00; // TURN ON ATHE PINS IN THE PORT B TO LOW.
    while (1) 
    {
		//PORTB=0x01;// TURNING ONLY THE LAST PIN OF THE PORT B TO TOGGLE
//PORTB=1<<PORTB3 // TURN ON ONLY THE 3RD PIN IN PORT B
		//_delay_ms(1000);
		//PORTB=0x00;
		//_delay_ms(1000);
		
		PORTB=(1<<PORTB7)|(1<<PORTB5);// Turning ON the pin7 and pin 5 on B port as high, do not use '&' instead use '|'.
		_delay_ms(1000);
	   // PORTB=(0<<PORTB7)|(0<<PORTB5);// Turning OFF the pins 5 and 7 on the B port
	    PORTB=(1<<PORTB3); //But be careful that, when the,pin is assigned zero or one all other pins will be assigned zero.
		_delay_ms(1000);
		
    }
}

