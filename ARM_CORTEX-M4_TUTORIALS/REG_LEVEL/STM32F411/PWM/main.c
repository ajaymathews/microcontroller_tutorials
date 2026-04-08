/* 
SUPPOSE TIMER5 IS USED FOR THE PWM, THEN NEED TO FIND THE PIN ATTACHED TO THE CORRESPONDING TIMER,
IN OUR CASE TIMER5[CHANNEL-1] IS ATTACHED TO PA0, CHECK PGE:40 ON DATASHEET.


AND FROM THE ALTERNATE FUNC REG, TIMER5 IS ON THE AF2 IN AFRL REG.

FQ IS DETERMINED BY ARR REGISTER AND DUTY CYCLE IS BY TIMx_>CCRx REG

PWM MODE IS ENABED IN TIMx->CCMRx bit OC1M[6:4], 110 FOR PWM MODE

CC1E BIT IN TIMx->CCER REG SETS THE CHANNEL 1 AS PWM PIN. REFER 364, 

AT LAST ENABLE COUNTER BY TIM->CR1 BIT CEN=1

THE COUNTER STARTS FROM THE ZERO,AS THE OUTPUT PIN HIGH,
AS THE COUNTER REACHES,CCR1 VALUE(8889), ITS OUTPUT VALUE SHIFTS TO LOW
AND AS THE COUNTER REACES THE ARR(26667) VALUE, IT STARTS COUNTING AGAIN.


*/

#include "stm32f4xx.h"                  // Device header
//#define DUTY_CYCLE 30
int DUTY_CYCLE=0;
int val;

void timer_pin_init()
{
	//RCC->AHB1ENR=(1<<0);
	RCC->AHB1ENR |= 1;//ENABLING THE CLOCK TO THE A PORT
	
	GPIOA->MODER |= 1<<1;//SETTING ALTERNATE FUNCTION FOR THE PIN
	
	GPIOA->AFR[0] |= 1<<1; //SETTING THE CONFIGURATION OF AF2 INTO THE AFRL(AFR[0]) REGISTER.
}


	void timer5_init(void)
{
	
	RCC->APB1ENR |= 1<<3;// PROVIDES THE CLOCK TO TIMER5
	
	TIM5->PSC = 10-1;   // THUS 16000000/10 -> 1,600,000
	
	TIM5->ARR = 26667-1;//(26667-1) SINCE START IS FROM ZERO  
                      // THIS REG 'ARR' ALSO ACT AS SIMLAR FUNCTION TO PRESCALAR, REFFER DATASHEET
	                    // 1,600,000/26667 ->60 HZ ( 60 COUNT FOR 1 SEC)
	                    //IN THIS CASE 26667 IS CONSIDERED AS THE TIME PERIOD
											// THUS THE PWM SHOULD IN THE RATIO OF THIS NUMBER
	
	TIM5->CNT = 0;       //COUNT START ON ZERO
	
	TIM5->CR1=1;        //ENABLES THE COUNTER

}
void timer5_pwm_init(void)
{
		
	TIM5->CCMR1 |= 1<<6|1<<5;  //SET TO PWM MODE 1
	
	TIM5->CCER |= 1;         //(1<<0) //CC1E SETS THE CHANNEL 0 FOR PWM, BUT HAVE DOBT ON THE CHANNEL SELECTION
	 
	TIM5->CCR1 =(26667/(DUTY_CYCLE/10))-1; 
	
	//IN EXAMPLE 26667/8889 =3/1 =30%
}

void delayMs(int delay)
{
	int i;
	for( ;delay>0;delay--)//thedelay we entered is reduced upto zero
	{
		for(i=0;i<3200;i++);//execution runs for 1ms inside loop
	}
}

int main()
{
	timer_pin_init();
	timer5_init();
	timer5_pwm_init();
	
	while(1)
	{

		

		
	/*	for(DUTY_CYCLE=1;DUTY_CYCLE<=100;DUTY_CYCLE+=10)
		{
			//timer5_pwm_init();
			TIM5->CCR1 =(26667/(DUTY_CYCLE/10))-1; 
			delayMs(1000);
		}
	*/	
	for(val=4000;val>=700;val-=10)
		{
			//timer5_pwm_init();
			TIM5->CCR1 =val;
			delayMs(10);
		}
		for(val=700;val<=4000;val+=10)
		{
			//timer5_pwm_init();
			TIM5->CCR1 =val;
			delayMs(10);
		}
	}
	
	
	
	
}
