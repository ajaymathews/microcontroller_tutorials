/*
 * File:   newmain.c
 * Author: [Developer]
 *
 * Created on 15 December, 2018, 4:46 PM
 */


#include <xc.h>
#define _XTAL_FREQ 16000000L

int value = 0;
int Count = 0;
void main (void)
{
T1CON = 0b00110001;
TRISD1=0x00; 

while (1)
{
while (! TMR1IF);
TMR1IF = 0;
Count ++;
if (Count>7)
{
RD1 = ~ RD1;   
Count = 0;
}
}
} 
