#include "RTOS_BSP.h"

int main()
{
	/*     TIMER2,3,4,5 AND ITS INTERRUPTS ARE INITIALIZED  */
	int32_t LED=0;
	TIM2_int_start();
	TIM3_int_start();
	TIM4_int_start();
	TIM5_int_start();
	while(1)
	{
		++LED;
		DelayMs(1000); //generating a delay using tim2 reg
	}
	
}
//if 1ms period is set then tim3,4,5_irqhandler is executed and 
//counter variable is incremented in 1 ms , can set any sec by setting period
	
