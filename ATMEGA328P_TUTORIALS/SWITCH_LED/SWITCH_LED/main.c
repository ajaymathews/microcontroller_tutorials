/*
 * SWITCH_LED.c
 *
 * Created: 31-05-2019 11:03:33
 * Author : [Developer]
 */ 

//DEBOUNCE

#include <avr/io.h>
#define 16000000

int main(void)
{
	int C=0;
	DDRB=0x01;
	PORTB=0x02;  // THE REGISTER THAT STORES THIS PORT VALUES IS 'PINB', APPLING A 5V TO THE 2ND PIN OF B PORT 
	while(1)
	{
	if(!(PINB&0x02))
	{
		while (!(PINB&0x02)); //it has two value,either 1 or 0.
		C++;
		if(C==1)
		{
			PORTB|=0x01;	 //TURNIING LED ON
		}

		if(C==2)
		{
			PORTB&=0xfe; //turning off the last bit(output bit), the other input bits remain unchanged
			C=0;
		}
	}
	}

}

