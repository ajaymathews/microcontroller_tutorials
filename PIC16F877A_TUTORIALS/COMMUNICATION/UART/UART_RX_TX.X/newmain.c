/*
 * File:   newmain.c
 * Author: [Developer]
 *
 * Created on 23 October, 2019, 9:19 AM
 */


#include <xc.h>
#include <string.h>
#define _XTAL_FREQ 16000000
void uart_init()
{
	TXSTA=0x24;//0b0010,0100
	RCSTA=0x90;
	// Standard 9600 baud rate calculation for 16MHz
	SPBRG = ((_XTAL_FREQ / 64) / 9600) - 1; 
}
char receive()
{
	while(!RCIF);
	char b=RCREG;
	return b;
}

void transmit(char b)
{	
	TXREG=b;
	while(!TRMT);
}

void str_transmit(char *p)
{
	while(*p!='\0')
		{
			transmit(*p);
			p++;
	 	}    
}

void str_receive()
{
	char c[7];
	int i;
	for(i=0;i<7;i++)
	{
	c[i]=receive();
	if(c[i]==' ')
	{
		c[i]='\0';
		break;
    }
}
str_transmit(c);

}


void main()
{
	TRISC6=0;
	TRISC7=1;
	uart_init();
while(1)
{	
	str_receive();
	__delay_ms(100);
}
}
