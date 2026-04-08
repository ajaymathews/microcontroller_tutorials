/*
 * File:   newmain.c
 * Author: [Developer]
 *
 * Created on 11 November, 2019, 9:39 PM
 */
/*              I2C              */
/*
 MSSP module provides interrupts on start and stop bits
 also provides 10bit/7bit addressing 
 pins: SCL(RC3) & SDA(RC4) -
 REGISTERS: SSPCON,SSPCON2,SSPSTAT,SSPBUF,SSPSR,SSPADD 
 SSPADD:holds the slave address in slave mode, and when in master mode SSPADDR acts as baud rate generator
 SSPSR:shift register, shifts data in/out
 SSPBUF: holds the data both written/read
when SPSR recieves full byte,transfers to SSPBUFF and INTERRUPT is set.
 
 * SSPSTAT
 7-SMP=1:Slew Rate Control Disabled for 100khz and 1Mhz,
     =0:SRC enabled for 400khz(high speed mode)
 6-CKE=1/0:Enable/Disble SMBus inputs
 5-D/A(slave mode)=1:last byte recieved/transmited
                   0:last byte recieved/tansmitted is ADDRESS
 4-P:stop bit (indication) 1:detected
                           0:not detected
 3-S:start bit =1:detected
                0:not
 2-R/W:(slave mode) 1:read,0:write
        (master)1:transmits in progress,0:not
 1-UA=1:adrss need to update,0:adrss need not to update
 0:BF (TRANSMIT MODE)=1:SSPBUF full, 0:SSPBUFF empty
      (reception)= 1:data tranmsit in progrss, 0:transmit complete
 
  
 * SSPCON
 
 7-WCOL(collision detection)-tranmisson mode
   (Master):1,attempted a write to SSPBUFF,but condition for a transmission is not vald,
           :0,no collision
   (Slave):1,SSPBUFF is had be writen a new data,even previous data exists
 6-SSPOV:receive overflow bit,
    (Recieve):1,a byte is recived to SSPBUFF while holding previous data
              0,no overflow
 5-SSPEN:1: enables SDA,SC as serial pins
         0:diables
 4-CKP=1:relase clock
       0:Hold clock(clock stretch)
 3-0:SSPM3SSPM0=1000:I2C MASTER MODE FOS/(4*(SSPADD+1))  
 
 * SSPCON2
 7-GCEN(general call,(slve))1:if 0000h is recived to sspsr,intrpt is enbled
                                  0:dsbled
 6-ACKSTAT=1:ACK from slve recivd
           0:not recivd
 5-ACKDT:
 4-ACKEN:    
 3-RCEN(enble recptn(MSTER))
   =1:ENBLE
 2-PEN:stop bit
 1-RSEN:repeted stsrt condition enbled
 0-SEn:strt bit(master):strt scl,sda
 *    (slave):1=clock stretching enbled for slve trnsmit and rcptn 
              0:stretching on tranmit only
 * 
  
 In I2C communication (master mode), data is send by byte by byte
 * that is letter by lettr in case of character, for the mater sending the data
 * the communication is strts by sending start bit
 *and the sending the ADDRESSs of the the slave the ADDRESS is a 7 bit ADDRESS and 
 * since the data is 8 bit, the last bit is R(1)/W(0) thus the ADDRESS should be end with zero at last
 * for eg: 0x30, and,along with ADDRESS that we send thee data too,
 * and at the end of the data transfer which is a byte, the stop bit is seted.
 * 
 * (slave mode)
 * the data passed to the slave is read as ADDRESS, bcz it contains the ADDRESS as the
 * preterm of the data.thus using the checking the condition of D_nA(instead of DA in datasheet)
 * as zero, the sspbuf contains the address along with the data and we store this data in another variable
 * so that after that there comes the data.that data is recieved and transmitted to uart.
  

 */

#include <xc.h>
#define _XTAL_FREQ 16000000

char data_letter,addrs_letter;

void I2C_Master_Init(const unsigned long c)
{
//  SSPCON=0x28; 
    SSPEN=1;//Enables the pin as the serial communication pins
    SSPM3=1;
    SSPM2=0;
    SSPM1=0;
    SSPM0=0; //setting the clock as = FOSC /(4*(SSPADD+1))  

    
  // SSPCON2
    //No need to set.
    SSPCON2=0;
  // SSPSTAT = 0x80;
     SMP=1; //disables the slew rate for the clock frequency 100Khz and 1Mhz;
            // there for we set the clock frequency as 100Khz (100 * 1000)
     
     SSPADD = ((_XTAL_FREQ/4000)/c) - 1; //FOS/(4*(SSPADD+1)) from this find equaton for SSPADD
                                         //the 4000 is becuse the 4*1000(Khz)
                                         //setting the address on the master mode,actually
                                         //set the baud rate generator instead, thus the 
                                         //baud rate generator generates the clock frequency 
                                         //for the the given clock which is 100Khz
                                       
     TRISC3 = 1;//SDA&SCL pins set as input
     TRISC4 = 1;//the pins should be set as inputs, which is mentioned in the datasheet
                //on the page 86 left side 2 nd para.
}


void I2C_Master_Start()
{ 
    SEN = 1;//enables the start bit.
	while(!SSPIF);//upon recieving the the SEN/PEN/Data the sspif will be sets, till the data trnsfer is completed
    SSPIF=0;
}

void I2C_Master_Stop()
{
    PEN = 1;//enables the stop bits
	while(!SSPIF);// Wait for it to complete
    SSPIF=0;
}

void I2C_Master_Write(char letter_byte)//unsigned char Byte
{	
    SSPBUF = letter_byte;//it recieves
	while(!SSPIF);		// Wait for it to complete
	SSPIF = 0;			// Clear the flag bit	
}
void I2C_str(char *strings)
{
	while(*strings!='\0')//checks the recieved string letter by letter
{
	I2C_Master_Start();//strt bit is enables
 	I2C_Master_Write(0x30);
	I2C_Master_Write(*strings);
	I2C_Master_Stop();//strt bit is enables,
	strings++;  
	__delay_ms(100);
}
    /*DATA:[Developer]
 * : start_bit -> adrsss+R/W -> 'A' -> stop_bit 
     start_bit -> adrsss+R/W -> 'J' -> stop_bit 
     start_bit -> adrsss+R/W -> 'A' -> stop_bit 
     start_bit -> adrsss+R/W -> 'Y' -> stop_bit
 * */
 
}

void I2C_slave_init()
{
    
    //SSPSTAT = 0x80;
        SMP=1;//disables the slew rate for the clock frequency 100Khz and 1Mhz;
             //since master has the clock as 100,the slave also must be configured for 100khz clock
        
    //SSPCON  = 0x36;
        SSPEN=1;//Enables the pin as the serial communication pins
        SSPM3=0;
        SSPM2=1;
        SSPM1=1;
        SSPM0=0; //setting slave for 7 bit addressing 
            
   // SSPCON2 = 0x00;
        //not needed, since the value is 0;
               
    SSPADD  = 0x30;//the master will communicate to the address specified in the SSPADD 

    TRISC3  = 1 ;TRISC4  = 1 ;//SDA&SCL pins set as input
}
char I2C_slave_recieve()
{
    if(SSPIF==1)//when a data recieves to the i2c pins, the SSPIF flag is set,
    {          //and thusit can be used for checking
    
        CKP=0; //holds the clock low, for the data and ADDRESS to recieve
        if(!D_nA)
        {
            addrs_letter=SSPBUF;//stores the adrsss recieved to this variable
            while(!BF);        //wait for the reception of complete data, then only the data will arrive
            data_letter=SSPBUF;//stores the data in the data_variable,and trnsmits it.
            //TXREG=data_letter;     
            //while(!TRMT);         
            CKP=1;           //after the reception of data the clock is released to high, so that
                             //at the next data reception, the clock should be held low.
            SSPIF=0;
            return data_letter;
        }
       // SSPIF=0;
    }
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

void uart_str_receive()
{   int x;
	char c[50];
	for(int i=0;i<50;i++)
    {
	c[i]=uart_receive();
	if(c[i]==' ')
	{
		c[i+1]='\0';
		break;
    }
    }
I2C_str(c);
}
void uart_transmit(char buff)
{
    TXREG=buff;     
   while(!TRMT);
   return;
}

void main()
{
 TRISB0=1;
 uart_init();
 char buff;
 while(1)
 {
    if(RB0==1)
    {
      I2C_Master_Init(100);//SENDING THE CLOCK 100(100KHZ)  
      while(1)//setting the pic as the master when  RB0 is connected to Power  
      {
	   uart_str_receive();   
      }
    }
    else if(RB0==0)
    {
        I2C_slave_init();
        while(1)
        {     
            buff=I2C_slave_recieve();
            uart_transmit(buff);
        }    
    }
 }
}
