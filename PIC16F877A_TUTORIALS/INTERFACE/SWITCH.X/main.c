/*
 * File:   main.c
 * Author: [Developer]
 *
 * Created on 20 October, 2018, 12:19 PM
 */

#include<pic.h>   // include pic headers
#include <xc.h>   // include xc8 complier header
#define _XTAL_FREQ 16000000 // to include the delay fuction
__CONFIG(0X3F7A);    //  Equalent to setting  CONFIGURATION bits

void main(void) {
    TRISB1=0;  // setting the b1 pin in the b port as output to connect led
    TRISB2=1;  // setting the b2 pin in the b port as input to read switch
    while(1)
    {
    if(RB2==0)  // checking the switch is on, by recieving 0. since the switch
                //is connected in active low
    {
        RB1=1;   // turning led ON
    }
    else
    {
        RB1=0;  // turning led OFF
    }
    
    }
    return;
}
