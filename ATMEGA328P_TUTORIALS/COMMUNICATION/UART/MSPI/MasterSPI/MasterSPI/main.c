/*
 * SPI_TEST.c
 *
 * Created: 27-06-2019 12:48:43
 * Author : [Developer]
 
 
 
 for synchronus master mode
 UBBRN=(fosc/(2*baud))-1  //reg value
 for using uart in spi mode trnsmitter to be enabled.TXEN=1
 XCKn be clock
 trnsferred is initiated by udrn i/o location ..???
 ucsr0b:txen->1
 ucsr0b: udrie->1 :enablesinterrupt on data empty
 
 ucsrnc:umseln1:0 -> 11 :master spi
 ucsrnc:udordn->1:lsb transmitted first,0:msb first
 reffer page 206 and choose which spi mode is needed, and set below based on this
 ucsrnc:ucphan :leasing edge or tailing edge which data to be sampled
 ucsrnc:ucpoln:timig of data transfer
  
 */ 

#include <avr/io.h>

int main(void)
{
    while (1) 
    {
		
    }
}

