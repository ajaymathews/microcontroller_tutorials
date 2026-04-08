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
 
 
 IN proteus, set an internal crystal with 8 mhz(max), so fq is 8mhz.
 */


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define F_CPU 8000000L
#define BAUD  9600
#define NORMAL_BAUD  ((F_CPU/16/BAUD)-1) //for normal mode asynchronus operation

void transmit_set()
{
	UBRR0=NORMAL_BAUD; //SETTING THE BAUD RATE REGISTERS
	
	//UBRR0H=(NORMAL_BAUD >> 8); //MORE SAFER WAY IS TO ASSIGN THE BAUD DATA IN BOTH L AND H REGISTER SEPERATELY
	//UBRR0L=NORMAL_BAUD;
	//UBRR0L=51;
	UCSR0B=(1 << TXEN0);//enabling transmitter by overidinng normal port operation
	UCSR0C=((1 << UCSZ01)|(1 << UCSZ00));//8bit frame in reciver and transmitter use
}
void transmit_interrupt_enable()
{
	UCSR0B|=1<<TXCIE0;
}
int main(void)
{	
    transmit_set();
	sei();
	transmit_interrupt_enable();
    while(1) 
    {	
		_delay_ms(500);	//because when the udro gets a value, it immedetly calls the interrupt,
						// as long as the data is in UDR0, it passes that data multiple times,but interrupt is called instead
						// without a delay, it only transmit data one by one not multiple
		UDR0='p';
    }
}


ISR(USART_TX_vect)
{
	UDR0='A';        //UDR0 is assigned with a character it has the capability of calling interrupt itself,
    _delay_ms(500);	//but when it executes a delay it waits till, the data is transmitted and UDR0 becomes empty 
					//thus instead of calling itself it returns to while loop in main
	
	//UCSR0A|=1<<TXC0;	//IF IN CASE NEED TO CLEAR THE TRANSMIT FLAG
}




