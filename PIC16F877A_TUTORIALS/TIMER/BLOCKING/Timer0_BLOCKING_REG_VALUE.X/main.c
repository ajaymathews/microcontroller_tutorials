/*
 * File:   main.c
 * Author: [Developer]
 *
 * Created on 7 November, 2018, 3:58 PM
 */

// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
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
#define _XTAL_FREQ 16000000

void main(void) 
{   
    TRISB = 0x00;  // setting the b port as output
    PORTB = 0x00;  // setting the value of b port as 0
    //OPTION_REG = 0x87; // selecting the configuration for timer similar to 
                        //(not needed)nRBPU=1;(although it is not specified in data sheet,it is setted
                       //         and the n is used infront of rbpu is for negetation rbpu)
                      //PS2:PS0=111; setting the prescalar as 256
                     // nRBPU=1;
    T0CS=0;
    T0SE=0;
    PSA=0;
   // PS2:PS0=111;    // similar to
                       PS2=1;
                      PS1=1;
                     PS2=1;
    TMR0 = 241;(appx 1.2sec delay)  // setting the register value as 241 by the equation
    int x=TMR0;            //TMR0=256-((delay(1ms)*_XTAL_FREQ)/(prescalar*4))
                          //TMR0=(256-((1*10^-3)*(16*10^6))/(256*4))
    int c = 0;
    while(1)
    {
        if(TMR0IF == 1)
        {
            c++;
            TMR0IF = 0;
            TMR0 = x; 
        }
        
        if (c == 1000)
            
        {
            PORTB= 0xff;
           
        }
        
        if (c == 2000)
        {
            PORTB = 0x00;
            c= 0;
        }
             
    }
    
    }
    

