/*
 * File:   newmain.c
 * Author: [Developer]
 *
 * Created on 5 November, 2019, 12:28 AM
 *
 *  SPI has 4 pins SDO,SDI,SCK,SS(RA5)
 * SSPCON(control reg),SSPSTAT(ststus reg),SSPBUF(data reg),SSPSR(shift reg) controls SPI operation
 * sspsr recieves the data and thus by shifting move the data completely to sspbuf.
 * thus SSPIF is set
 * 
 *
 * MASTER:
 *
 *:SSPSTAT
 * SMP:0 //DATA SMPLED AT THE MIDDLE OF OUTPUT
 *       DONT KNOW IT'S SHOULD BE ZERO 1 MEANS SAMPLE DATA AT THE END OF OUTPUT
 * CKE:0(CLCK SELCT BIT)//0:TRANSMIT AT ACTIVE TO IDLE TRANSITION OF CLOCK
 *      :1 //:TRANSMIT AT IDLE TO ACTIVE TRANSITION OF CLOCK
 *       OTHER BITS IN SSPSTST ARE READ ONLY MOSTLY IN I2C 
 * BF 1:receptio complte SSPBUF is full
 *     0:reception not cmplte SSPBUF is empty
 *:SSPCON
 * WCOL :1//SSPBUF IS STILL TRANSMITTING , MUST CLR IN PGM
 *      :0//NO COLLLISION
 * SSPEN:1 ENABLE THE SPI BY SETTING THE CORESPONDING PINS
 *       (ALSO PINS PROPERTY ALSO NEED T BE CONFIGURED)
 * CKP:IDLE STATE FOR CLOCK
 *    1:HIGH 
 *    0:LOW
 * SSPM3:SSPM0:PRESCALAR
 * 
 * 
 * SLAVE
   SPI in slave mode ss pin control enabled in sspcon<3:0>
 *-   SMP must be zero in slave.
SPOV:Rcv over flow INDICATOR , OVERFLOW CAN ONLY OCCUR IN SLAVE
 *  1:OVERFLOW
 *  0:NO OVERFLOW
 * 
 SS pin must be grounded in order to workas a slave, if it is connected to vdd in slave mode, the pic will reset and
 SPEN  bit is cleared.
 
 
 */


#include <xc.h>
#define _XTAL_FREQ 16000000

int space_check=0;

void spi_master_init()
{
    SSPSTAT=0x00;//reffered above also same effect as not defined
    SSPCON=0x22;
    TRISC3=0;//CLOCK PIN AS OUTPUT
    TRISC5=0;//SERIAL DATA OUTPUT AS OUTPUT
    TRISC4=1;//SERIAL DATA INPUT AS INPUT
    TRISB1=0;
    TRISB2=0;
    TRISB3=0;
    
    RB1=1;RB2=1;RB3=1;
}
void uart_init()
{
	TXSTA=0x24;//0b0010,0100
	RCSTA=0x90;
	SPBRG=103;
    TRISC6=0;
    TRISC7=1;
    
}
char uart_receive()
{
	while(!RCIF);
	char b=RCREG;
	return b;
}
void uart_to_spi(char *str)
{
 while(*str!='\0')
  {
   SSPBUF=*str;
   while(!BF);
   __delay_ms(100); 
   str++;
   }
 
}

int slave_on(char x)
{
    if(x=='1')
    {
       RB1=0;
       RB2=1;
       RB3=1;
       return 1;
    }
    else if(x=='2') 
    {
       RB1=1;
       RB2=0;
       RB3=1;
       return 1;
    }
    else if(x=='3') 
    {
       RB1=1;
       RB2=1;
       RB3=0;
       return 1;
    }
}

void uart_str_receive()
{   int x;
	char c[50];
	for(int i=0;i<50;i++)
    {
	c[i]=uart_receive();
    x=slave_on(c[i]);
	if(c[i]==' ')
	{
		c[i+1]='\0';
		break;
    }
    if(x==1)
    {
        i--;
    }
    }
uart_to_spi(c);
}
void uart_transmit(char b)
{	
	TXREG=b;
	while(!TRMT);
}
void spi_slave_init()
{
   SSPSTAT=0x00;
   SSPCON=0x24;
    TRISC3=1; //CLOCK PIN AS OUTPUT
    TRISC5=0; //SERIAL DATA OUTPUT AS OUTPUT
    TRISC4=1; //SERIAL DATA INPUT AS INPUT
}

void spi_read_char()
{
  while(!SSPIF);
  uart_transmit(SSPBUF);
  while(BF);
  __delay_ms(100);
}
void main(void) 
{
   TRISB0=1;RB0=0;__delay_ms(10);
   int i=0,space_check=0;
   
   
           /*******  MASTER  *******/
    if(RB0==1)          //if RB0 is to vcc , master configuration in initialized      
    {                   //which means it is running in master mode
        uart_init();
         spi_master_init();
         __delay_ms(100);
         while(1)
         {
           uart_str_receive();  
          //__delay_ms(100);
         }
    }
   
    /*******  SLAVE  *******/
    if(RB0==0)
    {
     spi_slave_init();
      uart_init();
      __delay_ms(200);
      while(1)
      {
          while(SSPBUF!=' ')
          {
               spi_read_char();
          }
      }


    }
}
