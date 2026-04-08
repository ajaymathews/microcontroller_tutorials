/*
 * File:   newmain.c
 * Author: [Developer]
 *
 * Created on 15 December, 2018, 4:01 PM
 */


#include <xc.h>
char value = 0;
#define SBIT_PS1  5
#define SBIT_PS0  4

void interrupt timer_isr()
{  
    if(TMR1IF==1)
    {
        value=~value;   // complement the value for blinking the LEDs
        TMR1H=0x0B;     // Load the time value(0xBDC) for 100ms delay
        TMR1L=0xDC;
        TMR1IF=0;       // Clear timer interrupt flag
    } 
}


void main()
{    
    TRISD=0x00;    //COnfigure PORTD as output to blink the LEDs

   // T1CON = (1<<SBIT_PS1) | (1<<SBIT_PS0); // Timer0 with external freq and 8 as prescalar
    T1CON=0b00111101;
    TMR1H=0x0B;     // Load the time value(0xBDC) for 100ms delay
    TMR1L=0xDC;       
    
	TMR1IE=1;       //Enable timer interrupt bit in PIE1 register
    GIE=1;          //Enable Global Interrupt
    PEIE=1;         //Enable the Peripheral Interrupt
    TMR1ON = 1;     //Start Timer1    

    while(1)
    {
        PORTD = value;//
    }
}
