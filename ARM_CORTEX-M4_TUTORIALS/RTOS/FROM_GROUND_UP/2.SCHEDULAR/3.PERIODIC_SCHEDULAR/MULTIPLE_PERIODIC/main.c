/*
	A PERIODIC INTERRUPT IS SCHEDULED FOR COUNTER4, IN WHICH TIMER 4 IS CONFIGURED TO PRODUCE A TIMMER INTERRUPT EVERY 1ms
	EACH COUNT1,2,3 IS INCREMENTED IN 1/1000ms,
  every 1ms interrupt is occuring, and  periodic thread is to be executed from this interrupt instead of main thread
	*/

#include "kernel.h"
#define quanta 1     //every 1ms interrupt is occuring, and  periodic thread is to be executed from this interrupt instead of main thread
#include "stm32f4xx.h"  
#include "RTOS_BSP.h" //CODE FOR TIMER INITIALIZATION

uint32_t count0,count1,count2,count3,count4,count5;

	                                 
void task0(void){		//THESE ARE THE TASKS, WHICH INCERMNTS THE COUNT0 VALUE
	while(1){					//AS TIME GOES ON, INSIDE A WHILE LOOP THUS KEE RUNNING
	count0++;
	threadyield();     //it will generate the systic interrupt, thus the task1 is executed when count0=1, 
	}
}

void task1(void){
while(1)
{	
	count1++;
	threadyield();
	}
}

void task2(void){    
while(1)
{	
	count2++;
	threadyield();
}
}

void TIM4_IRQHandler(void)  //TIMER INTERRUPT HANDLER IS CALLED EVERY 1MS
{
  count4++;                  //COUNT VALUE INCREMNTED UPON EVERY TIMER INTERRUPT
  HAL_TIM_IRQHandler(&htim4);
}

void task3(void)  //NEW TASK, the periodic task
{         //PERIODIC THREAD HAS TO RUN AND EXIT/return[short task] , THUS DOESNT REQUIRE WHILE 1 LOOP
	       //BUT MAIN THREAD HAS WHILE
count3++;
}

void task5(void)  //NEW TASK, the periodic task
{         //PERIODIC THREAD HAS TO RUN AND EXIT/return[short task] , THUS DOESNT REQUIRE WHILE 1 LOOP
	       //BUT MAIN THREAD HAS WHILE
count5++;
}

int main(){
//	GPIO_Init();
  TIM4_int_start();//these are functns from previos pgm //TIMER INIT AND TIMER INTERRUPT INIT IS CALLED
	kernelinit();
	kerneladdthreads(&task0,&task1,&task2);  //WHEN THE TASK IS RUNNING, EACH TASK IS RUN BY SCHEDULAR,WHICH CHNGES TASKS BY TIME
	kernellaunch(quanta);										 //AS THE TASK IS CHNGED BY SCHEDULR CUREENT STATUS OF SCHEDULR IS SAVED TO STACK AND THE RUN NEW TSK
}
