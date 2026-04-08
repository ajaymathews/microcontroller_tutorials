/*
 * Recieve.c
 *
 * Created: 15-06-2019 11:11:07
 * Author : [Developer]
 
 ucsr0a->RXC0 will be 1 at reception is complete
  ucsr0a->udre0 will be one if the buffer is ready to write new data.
 ucsr0b->rxcie will be 1,reception interrupt 
 ucsr0b->rxen ;1, enabls reception
ucsr0c-> ucsz01,ucsz00:1 ,for 8 bit transmission
 */ 

#define F_CPU 8000000L

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>


#define BAUD 9600
#define NORMAL_BAUD ((F_CPU/16/BAUD)-1) //corresponding value is 5

//char c; // needed bcz without it only 1 commnd be executed,ie1st cmmnd is identified only 

void recieve_setup()
{
	UBRR0=NORMAL_BAUD;//SETTING BAUD RATE       
	UCSR0B=(1<<RXEN0)|(1<<TXEN0);//Enables reception and transmission to replay //corrspndg reg value :0x10
	UCSR0C=((1<<UCSZ00)|(1<<UCSZ01));// enables 8 bit transmission/reception   //corrspndg reg value :0x06
}
char char_recieve()
{
	char c;
	while (!(UCSR0A & 1<<RXC0));//WAIT FOR DATA TO BE RECIVED,ie while(!(1)); if data recived, 
		c=UDR0;
		return c;
}
char *string_recieve(char string_data[]) //recievs the array from main as array
{
	//char string_data[100];
	int i=-1; //it is set to -1 , bcz initially i++ is executed for do while working.
	do
	{
		i++;
		string_data[i]=char_recieve(); //charctr is recivd to string_data each by each.
		if(string_data[i]=='\r')  //'\r is the checking condition for new line
		{
			string_data[i]='\0';   //assign last letter as \0 to exit reception
			//break;            //will work without this break because the while in do while exit whn '\0' comes 
		}
		
	}while(string_data[i]!='\0');  //is the checking condition for ending of a string

	return (string_data);
}
void send_char(char data_char)
{
	UDR0=data_char;
	//while(!(UCSR0A&1<<TXC0)); // ths doesnt seem to work as expected, only executes one iteration of loop correctly, thus reccmntd not use this
	while(!(UCSR0A&1<<UDRE0));	//wait for the data registr to empty.
	
}
int main(void)
{
	char string_data[100]; //the array that stores recieved data
							//must be declared in main, bcz reception function cant seem to retrn the pointer of this array when arry is not passed to rcv fnctn
	char *data_string;     //only needd in the cases that are cmmntd below
	char recv_msg[]="Received: "; //just a msg to repsnt data
	DDRC=0x01;  // C PORT IS USED FOR OUTPUT BCZ THE PINS THAT THE CRYSTAL OSCILLTOR GETS CONNECED TO
				// SHOULDNT BE A AN OUTPUT, WE CAN STILL USE B PORT AS AN OUTPUT IF ONLY THE LED PORT IS SET AS INPUT :PORTB=1<<PORTB0
	PORTC=0x00;
	recieve_setup();
    while (1)
	{ 
			
		string_recieve(string_data);
		for(int i=0;recv_msg[i]!='\0';i++)  //this method works bcz the data is stored in string data array that is passd to fn to recive data.
		{										//thus transmitting that array also prints the data
			send_char(recv_msg[i]);
		}
		for(int i=0;string_data[i]!='\0';i++)  //this method works bcz the data is stored in string data array that is passd to fn to recive data.
		{										//thus transmitting that array also prints the data
		send_char(string_data[i]);
		}
		
		
		/*
		data_string=string_recieve(string_data);   //this is actually a unncssry method, but it also works,which mens that the data is recivd to the data_string via pointer
		for(int i=0;*data_string!='\0';i++)			//but dont know why, only when the array is passd to function this method works otherwise, cant seem to obtain the addrss to data_string
		{
			send_char(*data_string);
			data_string++;
		}
		*/		
	}
}

