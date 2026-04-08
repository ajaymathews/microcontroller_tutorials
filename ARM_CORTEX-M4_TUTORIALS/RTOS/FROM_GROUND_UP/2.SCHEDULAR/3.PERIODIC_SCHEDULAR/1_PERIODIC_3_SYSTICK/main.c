/*
	A PERIODIC INTERRUPT IS SCHEDULED FOR COUNTER4, IN WHICH TIMER 4 IS CONFIGURED TO PRODUCE A TIMMER INTERRUPT EVERY 1ms
	EACH COUNT1,2,3 IS INCREMENTED IN 1/1000ms, THUS WHEN TGE COUNT1 REACHES 1000 COUNT4(TIMER INTERRUPT COUNT) IS INCREMNTED

	*/

#include "kernel.h"
#define quanta 1     //DOESNT DEPENT ON QUANTA, ONLY DEPEND ON THE COUNT VALUE AND CLOCK
#include "stm32f4xx.h"  
#include "RTOS_BSP.h" //CODE FOR TIMER INITIALIZATION

uint32_t count0,count1,count2,count4;

#define dely 550000
#define RED (1<<14)               
#define RED_BIT (1<<28)          
#define GREEN (1<<12)
#define GREEN_BIT (1<<24)
#define BLUE (1<<15)
#define BLUE_BIT (1<<30)
#define GPIOD_CLOCK (1<<3)           

void GPIO_Init(){	
	RCC->AHB1ENR |= GPIOD_CLOCK;         
  GPIOD->MODER |= RED_BIT|GREEN_BIT|BLUE_BIT; 
} 
	                                 
void task0(void){		//THESE ARE THE TASKS, WHICH INCERMNTS THE COUNT0 VALUE
	while(1){					//AS TIME GOES ON, INSIDE A WHILE LOOP THUS KEE RUNNING
	count0++;
	threadyield();     //it will generate the systic interrupt, thus the task1 is executed when count0=1, 
/*									//the speed at which the counting takes plce depends upon the clock fq, which is 10mhz,
		if(count0>dely)
	{	count0=0;
		GPIOD->ODR ^= GREEN;}
*/	}
}

void task1(void){
while(1)
{	
	count1++;
	threadyield();
/*
	if(count1>dely)
	{	count1=0;
		GPIOD->ODR ^= BLUE;}
*/	}
}

void task2(void){    
while(1)
{	
	count2++;
	threadyield();
/*
	if(count2>dely)
	{ count2=0;
		GPIOD->ODR ^= RED;  }
*/  }
}

void TIM4_IRQHandler(void)  //TIMER INTERRUPT HANDLER IS CALLED EVERY 1MS
{
  count4++;                  //COUNT VALUE INCREMNTED UPON EVERY TIMER INTERRUPT
  HAL_TIM_IRQHandler(&htim4);
}

  int main(){
//	GPIO_Init();
	//TIM4_int_start();            //TIMER INIT AND TIMER INTERRUPT INIT IS CALLED
	kernelinit();
	kerneladdthreads(&task0,&task1,&task2);  //WHEN THE TASK IS RUNNING, EACH TASK IS RUN BY SCHEDULAR,WHICH CHNGES TASKS BY TIME
	kernellaunch(quanta);										 //AS THE TASK IS CHNGED BY SCHEDULR CUREENT STATUS OF SCHEDULR IS SAVED TO STACK AND THE RUN NEW TSK
}
