/*
 * Tx_Rx.c
 *
 * Created: 09-06-2019 16:21:48
 * Author : [Developer]
 


 
 from pdf:
 -----------
 
 TXCn flag indicates the completion of transmission
 UDREn indicates data register is empty

UDRn(:UDR0) is the register that stores the value,it has both the transmitted and recieved data,

UCSRnA contains certain flags for the operation.(no need until checking)
  such as UCSRnA->RxCn will be one when data is in receve buffer
	      UCSRnA->TxCn will be one if data in transmit buffer to be transmitted

 *UCSRnB->RXCIE->1:enables reception interrupt
 *UCSRnB->RXEN :1 //enabling reciever by overiding normal port operation
 *UCSRnB->UDRIEn:1//interrupt when data register empty
 UCSRnB->TXCIEn->1:enables transmision interrupt
 UCSRnB->TXENn :1 //enabling transmitter by overidinng normal port operation

 UCSRnC->7 and 8 bit default 0 ,thus already in asynchronus usart(no needto chnge)
 UCSZn2:1:0=0:1:1->8bit frame in reciver and transmitter use
 
 
 UBRRnL & UBRRnH :baud rate registers(these have 8 bit size)
 UBBRR[11:0] is the full register
 
 
 IN proteus, set the fq of the controller to 8mhz internal
 connect an external crystal with 8 mhz(max), so fq is 8mhz also add a capacitor np10u50v and change its value to 22pf.
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>

#define F_CPU 8000000L
#define BAUD  9600
#define NORMAL_BAUD  ((F_CPU/16/BAUD)-1) //for normal mode asynchronus operation
char buffer[]="button is pressed\n";
char *buffer_ptr=buffer;
int leng,i=0;

void transmit_set()
{
	UBRR0=NORMAL_BAUD; //SETTING THE BAUD RATE REGISTERS
	//UBRR0H=(NORMAL_BAUD >> 8); //MORE SAFER WAY IS TO ASSIGN THE BAUD DATA IN BOTH L AND H REGISTER SEPERATELY
	//UBRR0L=NORMAL_BAUD;

	UCSR0B=(1 << TXEN0);//enabling transmitter by overidinng normal port operation
	//UCSR0B=(1 << TXEN0)|(1<<RXCIE0);//if in case need to recieve data that is transferred
	UCSR0C=((1 << UCSZ01)|(1 << UCSZ00));//8bit frame in reciver and transmitter use
}

void send_char()
{	
		UDR0='X';	
}
void send_for_string()
{
	leng=strlen(buffer);
	for(i=0;i<=leng;i++)
	{
		UDR0=buffer[i];
		_delay_ms(100); //when using for loop, this delay is needed since data passed on so quickly,and in that time data can be printed bcs of this speed.
	}
}

void send_string()
{
	leng=strlen(buffer);
	while(i<=leng)
	{
	UDR0=*buffer_ptr;
	buffer_ptr++;
	i++;
	_delay_ms(100);		
	}
	if(i>leng)
	{
		i=0;
		buffer_ptr=buffer;
	}	
}
	
int main(void)
{	
	DDRB=0x00; //setting all as input, thus the crystal oscillator connected to that port doesnt get affected, but dont set that 2 pins as output
    transmit_set();
    while(1) 
    {		
		if(PINB==(0x01))  //check if the button is prssed
		{
			send_char(); 
			//send_string();
			//send_for_string();
			while(PINB==(0x01)); //will wait till the button is released, if we dont use this it will call the function multiple times
		}
    }
}



