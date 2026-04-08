/*
 * LCD_TEST.c
 *
 * Created: 02-08-2019 10:59:08
 * Author : [Developer]
 PORTD &= ~(1 << n); // Pin n goes low
 PORTD |= (1 << n); // Pin n goes high
 
 
 RS connected to C0
 EN connected to C1
 
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>

#define F_CPU 16000000
#define LCD_DATA_PORT PORTB

char data_buffer[]="hiiiiii";
char *buffer_ptr=data_buffer;
int leng;


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

void lcd_8init()
{
	cmd_8mode(0x01); /* Clear display */
	cmd_8mode(0x38);//for 8 bit commnctn 
	cmd_8mode(0x0C);
}
void lcd_clear()
{
	cmd_8mode(0x01);		/* Clear display */
	_delay_ms(2);
	cmd_8mode(0x80);		/* Cursor at home position */
}
void lcd_send_enable()
{
	PORTC|=(1<<PORTC1);		//E=1
	_delay_ms(10);
	PORTC&=~(1<<PORTC1);    //E=0
}
void send_str_from_outside_main()
{
	PORTC|=(1<<PORTC0);//RS=1,DATA MODE
	for(int i=0;data_buffer[i]!='\0';i++)
	{
		LCD_DATA_PORT=data_buffer[i];
		lcd_send_enable();	
	}
}

void send_str_from_inside_main(char* main_pointer)
{
	PORTC|=(1<<PORTC0);//RS=1,DATA MODE
	while(*main_pointer)
	{
		LCD_DATA_PORT=*main_pointer;
		lcd_send_enable();
		main_pointer++;
	}
	
}
void send_4bit_str_from_inside_main(char* main_pointer)
{
	PORTC|=(1<<PORTC0);//RS=1,DATA MODE
	PORTC&=~(1<<PORTC1);//EN=0
	
	while(*main_pointer!='\0')
	{
		LCD_DATA_PORT=*main_pointer;
		lcd_send_enable();
		LCD_DATA_PORT=((*main_pointer<<4)&(0xF0));
		lcd_send_enable();
		main_pointer++;
	}
	
}

int main(void)
{
DDRC=0xFF;
DDRB=0xFF;
//lcd_8init();
lcd_4init();
char data[]="";
while(1)
{
//send_str_from_inside_main("how are you");
send_4bit_str_from_inside_main("helloo people");
while(1);
}
}
