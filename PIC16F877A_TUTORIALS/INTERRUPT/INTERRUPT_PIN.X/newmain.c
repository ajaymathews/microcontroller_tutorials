/*
 * File:   newmain.c
 * Author: [Developer]
 *
 * Created on 28 October, 2019, 9:46 AM
 */


#include <xc.h>
#include <pic.h>
#define _XTAL_FREQ 16000000
int count=0;
int bin[0x00,0x01,0x02,0x04,0x08]
void main()
{	GIE=1;
	PEIE=1;
	INTE=1;
	TRISB0=1;
	TRISC=0x00;
	PORTC=0x00;
  while(1)
{  

	if(count<5)
	{
		PORTC=bin[count]
	}
	
	else
   {
		PORTC=0x00;
        count=0;
	}
}

}
void interrupt isr()
{
	if(INTF==1)
	{
	count++;
	}
	INTF=0;
    
}
