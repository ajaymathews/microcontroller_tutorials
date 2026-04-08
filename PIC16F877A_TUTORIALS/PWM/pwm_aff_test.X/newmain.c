/*
 * File:   newmain.c
 * Author: [Developer]
 *
 * Created on 12 November, 2018, 12:04 PM
 */
/*Actually the tmr2 timer started(we could initialize it to to zero if needed), then the timer will be incremented till it
 reaches the pr2 value and after that it again starts from zero, thus from zero to pr2 is the time period of the wave.with 100% dutycycle
 to generate a pwm from thus signal we write values to ccpr1l and ccp1con<4,5> bits , the lsb of the pwm 10 bit data is stored in 
 * the ccp1con<4,5> bits. thus the pwm is acheived. */


#include <xc.h>
#define _XTAL_FREQ 1000000
//REG=[ , , , , , , ,]     VAL=1011100110
//REG=VAL     -> 1,0 [1,1,1,0,0,1,1,0] 
//REG=VAL>>2  -> [1,0,1,1,1,0,0,1] 1,0


void dutycycle(unsigned int dc)
	{
		CCPR1L=(dc>>2);   /* the MSB is stored into the CCPR1L register by shifting the last last outside
                           since PWM REG has 10 bit and CCPRL REG stores only 8 bit, so LSB must be kicked out
                           this value doesnt go anywhere just not included in this register*/
        
        CCP1CON&=0xCF;    /*the CCP1CON<5,4>(5th and 4th bit) reg is the place where we store the MSB value 
                          that have been kicked out from the CCPR1L reg,for that we place zero in the 
                          5th and 4th position to recieve this value and other bits unchanged by AND ing with 1s
                          all the other bits than 4&5 */
        
		CCP1CON|=(0x30&(dc<<4));  /* to get the last LSB value, we shift the bits rightward by 4 bits, thus the bits
                                   already on outside(because cant store 10 bits in 8-bit register) of the register 
                                   will be moved to the front position 4 times and thus that 2 bits will reach the 5th and 4th position */  
	}

void main()
{
    int i;

	TRISC2=0;
    TRISB0=0;
	CCP1CON=0x0C;     // setting the values to reg, that is the 2nd and 3rd bit set as 1 to be in PWM mode  
	PR2=0xFF;         /* setting the pr2 asc high  value;
                        when tmr2 reaches and equals pr2, then tmr2 resets ,
                       dutycycle is latched from ccprl to ccprh(read only register)*/
	T2CON=0x04;      // setting the timer2  
	dutycycle(0);    //initializing dutycycle
	T2CON|=0x04;

        dutycycle(100);
        while(1);
}
