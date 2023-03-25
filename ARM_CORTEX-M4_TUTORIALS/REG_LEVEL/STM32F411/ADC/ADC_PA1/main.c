/* 
ADC : ONLY ONE ADC1 OF 12 BIT WITH 19 CHANNELS

APB2 BUS PROVIDES CLOCK TO THE ADC1, 
INTERNAL TEMP SENSOR CONNECTED TO ADC CHANNEL 18

ADC->SR:
BIT 1:EOC , END OF CONVERSION, BCM 1 IF CONVERSION IS COMPLETED.


CR2:
BIT0:ADON , TURN ON ADC


SMPR1:
CHOOSE CYCLE CONTROLLER SPEND TO CONVERT SIGNAL

ADC CHANNEL1 IS CONNECTED TO THE PA1 IN CONTROLLER

*/

#include "stm32f4xx.h"                  // Device header

int ch1;




/***************************** ADC ************************/


void adc_init(void)
{
	RCC->APB2ENR |= 1<<8; //ENABLES CLOCK TO ADC
	
	ADC1->CR2 =0; //DISABLES ADC AT START, POWER OFF ADC
	
	ADC1->SQR3 |= 1; // (1<<0;)//ADC 1ST CONVERSION IN REGULAR SEQUENCE, CHANNEL 1

	ADC1->CR2 |= 1; //START ADC , NOT JUST POWER ON ADC

}
void adc_pin_init(void)
{
		
	RCC->AHB1ENR |= 1<<0; //PROVIDING THE CLOCK TO PORT A
	
	GPIOA->MODER |= 1<<3 | 1<<2; //SETTING THE PIN AS AN ANALOG PIN
	
}


void adc_start(void)
{
	ADC1->CR2 |= 1<<30;
	ADC1->CR2 |= 1;
}

void adc_stop(void)
{
//	ADC1->CR2 &= ~(1<<30);
	ADC1->CR2 =0;
}

int adc_read(void)
{
	while(!((ADC1->SR)&0x02)){}//wait for conversion to complete
	ch1=ADC1->DR;	
	return ch1;
}



/*************** ADC_MAIN***************/

int main(void)
{
  adc_pin_init();
	
	while(1)
	{
		adc_init();
		adc_start();
		ch1=adc_read();
		adc_stop();
	}
	
}
