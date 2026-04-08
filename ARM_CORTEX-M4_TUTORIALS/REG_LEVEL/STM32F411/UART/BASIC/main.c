/*
     UART1 : APB2(BUS THAT UARTS IS CONNECTED)
     UART6->bit5 : APB2
     UART2 : APB1
		 TO CONFIGURE UART ,FOR CLOCK SIGNAL, ENABLE THESE BUS REGISTERS.
		 
		 AFTER THAT SEARCH FOR USART AND SELECT OPTIONS FROM THAT
		 FIND BAUDRATE REG,
		 USART->BRR:
		 USART->CR1: CNTROL REG IS TO ENABLE/DISABLE UART
		             TE(3RD BIT)TRANMISSN ENABLE, RE(2ND BIT)RECEPTN ENBLE , UE(13TH)UART ENBLE 
     
		 OVERSAMPLING:  IN OUR CASE NOT NEEDED
		 OVER8=1 //8 BIT -> FCLK/8
     OVER8=0 //16 BIT -> FCLK/16		
     
     FRAME ERROR: OCCURS WHEN STOP BIT IS NOT RECOGNISED		 
		 
		 SINCE USART PINS ARE GPIO PINS WITH ALTERNATE FUNCTION, SELECTED FOR ALTERNATE FUNCTION IN MODER REG
		 ALSO FROM PGE 149,AFRL HAS 8TH BIT USART6, THUS AP;LY A VALUE 8 TO REG,
		 ALSO THE UART PINS ARE RC6(TX),RC7(RX) THESE PINS MUST BE PROVIDED CLOCK
		 
		 
		 1 START BIT, DATA(8 OR 9 BIT), 1 OR MORE STOP BITS [CONFIGURABLE:1,1.5,2,2.5]
		 
		 WRITE TO THE USART->DR STORESS DATA IN TDR REG,COPIES TO SHIFT REG,AND TRANSMISSION TAKES PLACE, AFTER THAT
		 FROM DR, DATA PASSES TO TDR AND THEN ONLY TO SHIFT REG.
 		 
		 
		 
		 
		 IN RECEPTION DAT FROM THE  SHIFT REG PASSES TO RDR, WHEN RXNE FLAG IS CLEARED.
     -PGM M BIT IN CR1, FOR WORDLENGTH AND STOPBITS FROM  CR2

IN ASYNCHRONOUS MODE DATA IS CONFIGURED TO SEND WITH TX,
WHILE(!RXNE),   RXNE =1, DATA IS RECIEVED AND READY TO READ

*/

#include "stm32f4xx.h" // Device header
#define BAUD 0x0683

/* NOT USED
#define C_PORT 1<<2
#define AF_TX 1<<13
#define UART_EN 1<<5
#define USART_EN 1<<13
#define TX_EN 1<<3
*/

void delayMS(int delay)
{
	int i;
	for( ;delay>0;delay--)
	{
		for(i=0;i<3195;i++);
	}
}
/***************************** USART ************************/



void usart_init(void)
{ 
	RCC->AHB1ENR |= 1<<2;   //CONFIGURE C PORT FOR CLOCK SIGNAL
	
	RCC->APB2ENR |= 1<<5;   //SELECTING UART6 FROM APB2(PERIPHERAL CLOCK ENABLE REG) FOR CLOCK
	
	USART6->BRR = BAUD;       //9600 @16mhz ,  (fclk/8*(2-OVER8)*USART DIV)  //OVER8->OVERSAMPLING BY 8 BIT(can be 1(8bit) or 0(16bit)
	
	USART6->CR1 |= 1<<13;  //ENABLES THE UART COMMUNICATION
}





/********************* TRANSMISION***********************/
//PIN C6


void usart_tx_init(void)
{
	GPIOC->MODER |= 1<<13;  //SETTING THE PIN C6 TO ACT AS ALTERNATING FUNCTION, ie, UART mode
	
	GPIOC->AFR[0]=1<<27;   //ALTERNATE FUNCTION REGISTER,THE PIN CONFIGURATION FOR THE CORREPONDING PIN IS SET
										    //BASED ON THE PAGE:149	, SINCE AFR HAS BOTH L AND H REG, AFR[O] IS AFRL AND AFR[1] IS AFRH REG,
												//THUS AFTER IDENTIFYING PINS, WHETHER ON AFRH OR AFRL, AND THE NUMBER SUCH AS 'AF8' NEED TO SET THE BITS BASED ON AFRL
												//FROM PAGE 160 SET THE BITS,JUST BY THE NUMBER OF PINS IN BOARD AND ASSIGN BITS ACCORDING TO THE 
	                      //PIN SELECTED AS 'AF8' HAS CERTAIN BITS FORMAT , SET THAT FORMAT TO THE CORRESPONDING BIT POSITION

	USART6->CR1 |= 1<<3;    //ENABLING THE TRANSMISSION 
}



void usart_writechar(uint8_t ch)
{
	while(!(USART6->SR & 0x0080)){}//CHECKING THE TX BUFFER IS EMPTY FROM THE STATUS REGISTER,
  USART6->DR=ch;          //DATA IS PASSED TO THE UART DATA REGISTER
}

void usart_writestring(char *ptr)
{
	while(*ptr!='\0')
	{
		usart_writechar(*ptr);
		ptr++;
	}
}



/***************************RECEPTION*************************/
//PIN C7

void usart_rx_init(void)
{
	GPIOC->MODER |= 1<<15;//SETTING THE ALTERNATE FUNCTION FOR PIN 7
	
  GPIOC->AFR[0] |= 	1<<31; //SETTING THE ALTERNATING FUNCTION BY FINDING THE AF PINS FROM 149 AND 
	                         //APPLYING THE CORRESPONDING COMBINATION TO RC7(RX) PINS BITS POSITION IN 160
	
  USART6->CR1 |= 1<<2;//ENABLES THE RECEPTION
}


int readchar(void)
{
	while(!(USART6->SR & 0x0020)){}
	int letter = USART6->DR;
	return letter;	
}









/****************************** MAIN **********************************/


int main(void)
{
	 int letter;
	 usart_init();
	 usart_tx_init();
	
	
	
   usart_rx_init();
	
	
	
	while(1)
	{
		//usart_writechar('v');
		//usart_writestring("hello\r");
		
		letter=readchar();
		delayMS(1);
	  usart_writechar(letter);
	}
	
}
