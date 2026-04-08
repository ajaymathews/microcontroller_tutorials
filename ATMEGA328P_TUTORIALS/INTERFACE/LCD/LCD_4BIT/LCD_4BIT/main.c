/*
 * LCD_4BIT.c
 *
 * Created: 02-08-2019 15:19:56
 * Author : [Developer]
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>

#define F_CPU 16000000
#define LCD_DATA_PORT PORTB

void cmd_8mode(int data)//this is for command such as clear screen,set cursor etc..
{
	PORTC&=~(1<<PORTC0);	//RS=0;		//command mode, if rs=1:data mode
	PORTC&=~(1<<PORTC1);	//EN=0;
	LCD_DATA_PORT=data;
	PORTC|=(1<<PORTC1);		//EN=1;		//enable needs to be 1 for the data to be tranferred to data_port
	_delay_ms(100);
	PORTC&=~(1<<PORTC1);	//EN=0;		//after setting the value 1, turns En again to zero to avoid false commnds
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
	PORTC|=(1<<PORTC1);	//E=1
	_delay_ms(10);
	PORTC&=~(1<<PORTC1);    //E=0
}
void print_string(char* data_pointer)
{
	PORTC|=(1<<PORTC0);//RS=1,DATA MODE
	PORTC&=~(1<<PORTC1);//EN=0
	
	while(*data_pointer!='\0')
	{
		LCD_DATA_PORT=*data_pointer;
		send_bit();
		LCD_DATA_PORT=((*data_pointer<<4)&(0xF0));
		send_bit();
		data_pointer++;
	}
	
}
int main(void)
{
	DDRC=0xFF;
	DDRB=0xFF;
	lcd_4init();
	char data[]="";
	while(1)
	{
		print_string("helloo people");
		while(1);
	}
}
