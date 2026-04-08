/*

 * File:   newmain.c
 * Author: [Developer]
 *
 * Created on 30 October, 2019, 3:50 PM
 */


#include <xc.h>
#include <string.h>
#include<stdio.h>

#define _XTAL_FREQ 16000000

float adc_val;
char str[20];

void uart_init()
{
	TXSTA=0x24;//0b0010,0100
	RCSTA=0x90;
	SPBRG=103;
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


void adc_init()
{
// ADCON0:
    /*
          ADCS1=1;
          ADCS0=0;//PRESCALAR SELECTED 64 WITH ADCON1 AS 1
          CHS2:CHS0=000;//ADC0(ANO IS SELECTED)//ALREADY SELECTED IF NOT SET    
          GO_DONE=1;//WHEN ADON=1, STARTS CONVERSION AND S/W AUTTOMATALLY CLEARS THIS AFTER CONVERSION EACH TIME
                   //USED FOR STRTING CONVERSION AND CHECKING CONVERSION IS COMPLETED OR NOT
     */    
      //    ADCS1=1;
      //    ADCS0=0;
          ADON=1;//ADC MODULE IS POWERED(ON/OFF BIT)
    
//ADCON1:
    /*
          ADCS2=1;//PRESCALAR SELECTED   
          PCFG3:PCFG0=0000;//ALL ANALOG PINS ARE TAKEN AS ANALOG INPUTS
    */
    //ADCS2=1;
    ADFM=1;//RIGHT JUSTIFIED , MSB OF ADRESH BE LOW
}
void adc_start()
{
    GO_DONE=1;
}
float adc_read()
{
    while(GO_DONE);
    adc_val=ADRESL+(ADRESH<<8);
    adc_val=((adc_val)/1024)*5;
    return adc_val;
}
void main()
{
	TRISC6=0;
	TRISC7=1;
	uart_init();
    adc_init();
while(1)
{	
    adc_start();
    adc_val=adc_read();
    sprintf(str,": %f V \n\r",adc_val);
	str_transmit(str);
    __delay_ms(300);
}
}
