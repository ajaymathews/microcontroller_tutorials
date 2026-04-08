/*
 * Ext_interrupt.c
 *
 * Created: 06-06-2019 16:03:10
 * Author : [Developer]
 
 
 EICRA->ISC10:1, ANY LOGICAL  CHANGE IN INT1 PIN GENERTE INTERRUPT
 EIMSK->INT1:1 ,ENABLE INT1 INTERRUPT
 EIFR->INTF1:1 - IF THE INT1 TRIGGERS THE INTERRUPT, intf1 is set,CLEARED WHEN ISR IS EXECUTED
 
 PCICR->PCIE1:1, ENABLE PCINT INTERRUPT UPTO PCINT8-PCINT14,
 PCIFR->PCIF1:1 ,SETED IF PCINT8:14 TRIGGERS THE INTERRUPT,CLEARED WHEN ISR IS EXECUTED  
 PCMSK1->PCINT14-PCINT8:1, SETS THE PIN INDIVIDUALLY AS THE INTERRUPT PINS
 
 
 
 */ 
//IN THIS PROGRAM WE COULD CONNECT A SWITCH TO AN INTERRUPT PIN OR AUTOMATCALLY CHANGE PIN VIA CODE, IN ALL THIS METHODS AN INTERRPT IS GENERATED. 
//ALSO ANY PIN CAN BE SET BY AN INTERRPUT BY PCINT, AND 2 DEFINED INTERRPUTS ARE AT  INT1 AND INT0

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define F_CPU 16000000

int count=0;

void int1_init()
{
													//	EICRA=1<<ISC10; //NOT YET USED IN PGM
	EIMSK=1<<INT1;  //interrupt enable on int1 pin

													// to check//if(EIFR==(1<<INTF1))
}
void pcint8_14_init()
{
	PCICR=1<<PCIE1;//ENABLE PCINT INTERRUPT UPTO PCINT8-PCINT14,
														 // PCIFR=1<<PCIF1;//no need to set //IF PCINT8:14 TRIGGERS THE INTERRUPT,CLEARED BY CODE 'cli()' after WHEN ISR IS EXECUTED
	PCMSK1=(1<<PCINT13);//SETS THE PIN INDIVIDUALLY AS THE INTERRUPT PINS,IN THIS CASE PCINT13	
}

void change_output() //this function is to chnge output automatically and thus by generating an interrupt automticlly
{
	DDRC=1<<PORTC5;//IF PCINT13 IS SET AS AN OUTPUT
	//DDRD=(1<<PORTD3);//if INT1 IS set as output

//BUT THE CHANGE OUTPUT FUNCTON ON PCINT DOESNT INVOKE AN INTERRUPT, BUT SWITCH DOES. DONT KNOW WHY??

	//PORTD^=(1<<PORTD3);//TO CHECK INT1 INTERRUPT TRIGGERS, IF SET AS AN OUTPUT AND IT CHANGES 
	PORTC^=1<<PORTC5;//TO CHECK PCINT13 INTERRUPT TRIGGERS, IF SET AS AN OUTPUT AND IT CHANGES 
}

void enable_switch_on_int1() // enable this function to set the interrpt as input and connect a switch to each
{
	DDRD^=(0<<PORTD3); //THIS MAY WORK, TO SET D3 AS INPUT,NEED TO ASSIGN   0 TO D3 
	                   //DDRD=0x00;//THE ONLY SURE METHOD					   
}
void enable_switch_on_pcint13()
{
	DDRC^=(0<<PORTC5);	// TO SET PCINT13 AS SWITCH INPUT	
						//DDRC=0x00;
}
void led_run()//to generate a continously running LED, to satisfy the interrupt is working, but to be noted that c port is used, thus pcint13 may get affected, in that case change it to bport
{
	DDRC=1<<PORTC0;
	_delay_ms(500);
	PORTC=(1<<PORTC0);
	_delay_ms(500);	
	PORTC^=(1<<PORTC0);
	_delay_ms(500);
}

int main(void)
{
DDRB=1<<PORTB0;//PINB0 TO TOGGLE AS PER THE INTERRUPT
enable_switch_on_int1();
int1_init(); 

//enable_switch_on_pcint13();
//pcint8_14_init();
    while (1) 
    {	
		//change_output();
		led_run();
		//_delay_ms(3500);
		if(count==0)
		{	
			sei();//sets all the interrupt enable
		}
		else
		{
			cli();//clears the interrupt enable
			//_delay_ms(1000);
			count=0;
		}
		
    }
}
///*
ISR(INT1_vect)
{
	PORTB^=(1<<PORTB0);	
	count=1;
}
//*/

/*
ISR(PCINT1_vect)
{	
	PORTB=~PORTB;
	//PORTB^=(1<<PORTB0);
	count=1;
	PCIFR=1<<PCIF1;
}
*/
