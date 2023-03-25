#define F_CPU 8000000


#include <avr/io.h>
#include <util/delay.h>
#include <string.h>


#define LCD_DATA_PORT PORTD


void master_init()
{
DDRB|=(1<<PORTB3)|(1<<PORTB5);//mosi,sck pin as output
SPCR=((1<<SPE)|(1<<MSTR)|(1<<SPR0)); //ENABLES SPI,MASTER ANDSET SCK FQ TO FOSC/16	
}

void master_char_send(char data_char)
{	
	SPDR=data_char;	
//	_delay_ms(10);		//placing data to the spdr reg, msb first
	while(!(SPSR&(1<<SPIF)));	//wait till transfer is complted
}

void master_string_send(char *string_ptr)
{
	while(*string_ptr!='\0')
	{
	master_char_send(*string_ptr);
	_delay_ms(100);
	string_ptr++;	
	}	
}
void slave_init()
{
	DDRB|=1<<PORTB4;//SET MISO AS OUTPUT, ALL ELSE AS INPUT
	SPCR=((1<<SPE)|(1<<SPR0)); //ENABLES SPI,SPRO
}
char slave_recieve_char()
{	
while(!(SPSR&(1<<SPIF)));//TILL RECEPTION IS COMPLETE	
return SPDR;
}

void cmd_8mode(int data)//this is for command such as clear screen,set cursor etc..
{
	PORTB&=~(1<<PORTB6);	//RS=0;		//command mode, if rs=1:data mode
	PORTB&=~(1<<PORTB7);	//EN=0;
	LCD_DATA_PORT=data;
	PORTB|=(1<<PORTB7);		//EN=1;		//enable needs to be 1 for the data to be tranferred to data_port
	_delay_ms(10);
	PORTB&=~(1<<PORTB7);	//EN=0;		//after setting the value 1, turns En again to zero to avoid false commnds
}
void cmd_4mode(int data)
{
	cmd_8mode(data);   //msb is send to the portb
	int shift_data=((data<<4)&(0xF0));
	cmd_8mode(shift_data);//lsb is send to the portb,only then the data is completely sent.
}
void lcd_4init()
{
	cmd_4mode(0x02);
	cmd_4mode(0x33);
	cmd_4mode(0x32);
	cmd_4mode(0x0C);
	cmd_4mode(0x06);
	cmd_4mode(0x01);
}
void lcd_clear()
{
	cmd_4mode(0x01);		/* Clear display */
	_delay_ms(2);
	cmd_4mode(0x80);		/* Cursor at home position */
}
void send_bit()
{
	PORTB|=(1<<PORTB7);	//E=1
	_delay_ms(10);
	PORTB&=~(1<<PORTB7);    //E=0
}
void print_string(char* data_pointer)
{
	PORTB|=(1<<PORTB6);//RS=1,DATA MODE
	PORTB&=~(1<<PORTB7);//EN=0
	
	while(*data_pointer!='\0')
	{
		LCD_DATA_PORT=*data_pointer;
		send_bit();
		LCD_DATA_PORT=((*data_pointer<<4)&(0xF0));
		send_bit();
		data_pointer++;
	}
	
}

void print_char(char char_data)
{
	PORTB|=(1<<PORTB6);//RS=1,DATA MODE
	PORTB&=~(1<<PORTB7);//EN=0

		LCD_DATA_PORT=char_data;
		send_bit();
		LCD_DATA_PORT=((char_data<<4)&(0xF0));
		send_bit();

	
}



int main(void)
{
	
	DDRC&=~(1<<PORTC0);
	
	if(PINC==0b1000001)
	{
		char data_buffer='k';
		char string_buffer[]="hello";
		master_init();
		/*
		//sending char by char
			for(int i=0;i<strlen(string_buffer);i++)
			{
				_delay_ms(10);
				master_char_send(string_buffer[i]);
			}
	*/
		master_string_send(string_buffer);
		//master_char_send(data_buffer);
	  
	}
	else
	{
		DDRD=0xFF;
		DDRB|=((1<<PORTB7)|(1<<PORTB6));//EN AND RS
		char recieve_string;
		char recieve_char;
		char string_data[20];
		slave_init();
		lcd_4init();
		while(1)
		{
		//recieve_char=slave_recieve_char();
		int i;
		for(i=0;recieve_char!='\0';i++)
		{
			recieve_char=slave_recieve_char();
			string_data[i]=recieve_char;
		}string_data[i]='\0';
		/*
		for(int i=0;i<string_data[i]!='\0';i++)
		{
		print_char(string_data[i]);
		}*/
		print_string(string_data);
		_delay_ms(100);
			}
/*
	//	while (1)
		{
			for(int i=0;recieve_string!='\0';i++)
			{
				recieve_string=slave_recieve_char();
				_delay_ms(10);
				print_char(recieve_string);
			}
			
		}
		*/
		
	}
	
}
