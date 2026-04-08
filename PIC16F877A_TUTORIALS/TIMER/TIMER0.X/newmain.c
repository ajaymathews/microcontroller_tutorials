
// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define __XTAL_FREQ 16000000

//void delay(int time);

char value = 0;

void interrupt my_isr(void)
{  
    if(TMR0IF==1)
    {
        value=~value;   // complement the value for blinking the LEDs
        TMR0 =240;     /*Load the timer Value, (Note: Timervalue is 101 instaed of 100 as the
                         // TImer0 needs two instruction Cycles to start incrementing TMR0 */
        TMR0IF=0;       // Clear timer interrupt flag
    } 
}


void main()
{    
    TRISB=0x00;    //COnfigure PORTD as output to blink the LEDs

    PS2:PS0=000;
    PSA=0;
    T0CS=0;// Timer0 with external freq and 32 as prescalar
    TMR0=240;       // Load the time value for 1ms delay
    TMR0IE=1;       //Enable timer interrupt bit in PIE1 register
    GIE=1;          //Enable Global Interrupt
    PEIE=1;         //Enable the Peripheral Interrupt

    while(1)
    {
        PORTB = value;
    }
}


//void main(void) {
//    TRISB4=0;
//    RB4=0;
//   // OPTION_REG&=0b11000111;
//    //OPTION_REG|=0b00000111;
//    PS2:PS0=000;
//    int count=(256-((1*__XTAL_FREQ)/(2*4)));
//    
//    while(1)
//    {
//    while(TMR0IF==0);
//    RB4=~RB4;
//        TMR0=count;
//        TMR0IF=0;
////    while(1)
////    {
////        delay(.5);
////        RB4=1;
////        delay(.5);
////        RB4=0;
////    }
//    }return ;
//}

//void delay(int time)
//{
//    //int count=256-(time/2000000);
//  //  int count=(256-((1*__XTAL_FREQ)/(2*4)));
//   // int count=(__XTAL_FREQ/(4*2*(256)*(1/time)));
//  // int count=(4/_XTAL_FREQ)*2*(256);
//   // int count=(__XTAL_FREQ * time /(4*2));
//    
//}
