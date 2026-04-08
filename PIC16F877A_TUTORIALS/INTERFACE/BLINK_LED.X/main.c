/*
 * File:   newmain.c
 * Author: [Developer]
 *
 * Created on 9 October, 2018, 2:40 PM
 */

#include<pic.h>   // include pic headers
#include <xc.h>   // include xc8 complier header
#define _XTAL_FREQ 16000000 // to include the delay fuction
__CONFIG(0X3F7A);    //  Equalent to setting  CONFIGURATION bits

void main(void) 
{
    TRISB=0X00;   // SETTING THE B PORT AS OUTPUT
    TRISC4=0;  // SSETTING 4th PIN as the OUTPUT
    
//    //TURNING THE COMPLETE B PORT ON/OFF
//    while(1)
//    {
//    PORTB=0XFF;    // TURNING LIGHTS ON ALL PORTS
//    __delay_ms(100); // delay in microseconds
//    
//    // __delay_us(xxx);  // delay in nano seconds
//    
//    PORTB=0X00;   // TURNING LIGHTS OFF ALL PORTS
//   __delay_ms(100);
//    }
    
     //TURNING 4th PIN IN THE C PORT ON/OFF
//    while(1)
//    {
//        RC4=0;
//        __delay_ms(100);
//        RC4=1;
//        __delay_ms(100);   
//    }
    
    return;
}
