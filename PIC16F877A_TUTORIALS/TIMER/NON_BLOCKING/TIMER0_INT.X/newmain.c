/*
 * File:   newmain.c
 * Author: [Developer]
 *
 * Created on 26 November, 2018, 10:28 AM
 */

// not working
#include <xc.h>
#define _XTAL_FREQ 16000000L
int c;
int VAL=0;
void interrupt timer_isr() // TIMER INTERRUPT FUNCTION 
{
  if(TMR0IF==1)      //CHECKING TIMER INTERRUPT FLAG IS SET OR NOT
  {                 //WHEN A INTERRUPT IS GENERATED, TMRIF BCMZ 1
      c++;         // A VARIABLE IS INITIALIZED TO COUNT EACH TIME TIMER FLAG SET
     TMR0IF=0;   //TIMR FLAG IS AGAIN RESET TO 0,TO START FROM BEGINING  
     //TMR0=241;
  }
  if(c==65)      //if(c=(1000/16))
  {             //WHEN THE VARIABLE REACH 65,ie, 65 TIMES INTERRUPT GENERATED,
  VAL=~VAL;     //THE VALUE OF THE 'VAL' CHANGES ,(0->1,1->0)
  c=0;         //THE VARIABLE IS THEN INITIALIZED AGAIN TO ZERO,           //TO STAR  FOR ANOTHER 10 INTERRUPTS
  
  }
}

void main(void) {
    TRISC5=0;
    OPTION_REG=0x07;
    GIE=1;
    PEIE=1;
    TMR0IE=1;
    //INTE=1;
    TMR0IF=0;
    RC5=0;
    while(1)
    {
        RC5=VAL;
    }
    
    return;
}

