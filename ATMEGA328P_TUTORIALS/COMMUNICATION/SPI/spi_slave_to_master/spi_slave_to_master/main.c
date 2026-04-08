/*
 * spi_slave_to_master.c
 *
 * Created: 04-09-2019 14:14:02
 * Author : [Developer]
 */ 

/*
 * SPI_TEST.c
 *
 * Created: 27-06-2019 12:48:43
 * Author : [Developer]
 
 
 master:
 ss line must be progmmed in s/w, must be held high for master transmission,if pulls to low it will be interpretted as a slave and mstr bit is set to zero from one.
 writing a byte to the SPI Data Register starts the SPI clock generator
 spdr is the data reg,
 
 
PINS:	 MOSI(SET AS O/P),SCK(SET AS O/P),SS:USER DEFINED
		 MISO:INPUT
BITS:	 SPCR:SPE,MSTR,SPR0->1   
		 SPDR=DATA;
		 WHIILE(!(SPSR&(1<<SPIF)));  :FROM EXAMPLE

 
 slave:
 data will not be shifted till untill ss pin is low(spi is active),whwn ss pin is high will not recieve data and spi logic is reset and clear all data in shift reg 
 dat trnsmitted by pulling low on ss pin on slave and trnsmission ended by pulling high on ss pin

PINS:	 MOSI,SCK,SS:INPUT
		 MISO(SET AS O/P):USER DEFINED

BITS:	 SPCR:SPE->1
		 WHILE(!(SPSR&(1<<SPIF)));  :TILL RECEPTION IS COMPLETE
		 return SPDR;

 
 
->The last incoming byte will be kept in the Buffer Register for later use
ateach shifting spif is set(in both slave and master)


spcr:spie->1:if spif is set interrpt is genrted
	:spe->1: spi enable
	:dord->1:lb trnsmitted first else msb first
	:mstr->1:master mode else slave
	:cpha,cpol determines leading edge and falling edge 
	:pi2x,spir1,spr0 set the sck fq
	page:177

spsr:spif:interrpt flg/set when trnsfer is complted or master ss pin is set to low
	:wcol:is set if data is written to spdr
	spi2x->1:spi trnsmissn speed is doubled in mastr mode

  
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000

void master_init()
{
DDRB|=(1<<PORTB3)|(1<<PORTB5);//mosi,sck pin as output
SPCR=((1<<SPE)|(1<<MSTR)|(1<<SPR0)); //ENABLES SPI,MASTER ANDSET SCK FQ TO FOSC/16	
}


#include <avr/io.h>


int main(void)
{
 
    while (1) 
    {
    }
}

