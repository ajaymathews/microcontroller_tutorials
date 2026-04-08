/*
 * File:   newmain.c
 * Author: [Developer]
 *
 * Created on 1 January, 2020, 10:07 AM
 */


#include <xc.h>

#define _XTAL_FREQ 16000000L
#define RS RB0
#define EN RB2
void send_str(char *p);


void cmd_4bit(int x)
{
    PORTB& = 0x0F;
    RS=0;
    EN=0;
    PORTB |= (x & 0xF0);
    EN=1;
    __delay_ms(10);
    EN=0;
    

    
    PORTB& = 0x0F;
    PORTB |= ((x<<4) & 0xF0);
    EN=1;
    __delay_ms(10);
    EN=0;
    
    
}
void lcd_init()
{
	//cmd_2bit(0x33);
	//cmd_2bit(0x32);
	cmd_4bit(0x02);
	cmd_4bit(0x01);
	//cmd_2bit(0x06);
	cmd_4bit(0x0c);
	cmd_4bit(0x80);
}


void data_4bit(char y)
{
    
	PORTB& = 0x0F;
    RS=1;
    EN=0;
    PORTB |= (y & 0xF0);
    EN=1;
    __delay_ms(10);
    EN=0;
    

    
    PORTB& = 0x0F;
    PORTB |= ((y<<4) & 0xF0);
    EN=1;
    __delay_ms(10);
    EN=0;
    
}
void send_str(char *p)
{
	while(*p!='\0')
	{
		data_4bit(*p);
		p++;
	}
}
void uart_init()
{
	TXSTA=0x24;//0b0010,0100
	RCSTA=0x90;
	SPBRG=103;
}

char receive()
{
	while(!RCIF);
	char b=RCREG;
	return b;
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

void str_receive()
{
	char c[15];
	int i;
	for(i=0;i<15;i++)
	{
	c[i]=receive();
	if(c[i]==' ')
	{
		c[i]='\0';
		break;
    }
}
//str_transmit(c);
    cmd_4bit(0x01);
send_str(c);
}

void main()
{
	TRISB=0x00;
    TRISC6=0;
	TRISC7=1;
	uart_init();
	lcd_init();
  /*  while(1)
    {
        str_receive();
        __delay_ms(100);
    }
*/	 data_4bit('h');
}
