/*
	RENDEVOUS INTER-TASK COMMUNICATION, IS THAT EACH TASK IN WHILE LOOP , IN ANY CASE ONE TASK ENTERS FIRST, IN RENDAVOUS ARRANGEMNT, 
	THE SEMAPHORE IS SET, OF THEIR TASK THUS SEMAPHORE TOKEN INCREMNTS, AND AFTER ITS PROCESS COMPLETION WAIT FOR TASK 2 TO COMPLETE.
	THUS WILL MAKE A DIFFERNCE OF 1 IN BETWEEN TASKS
	
	
	*/

#include "kernel.h"
#define quanta 1     //DOESNT DEPENT ON QUANTA, ONLY DEPEND ON THE COUNT VALUE AND CLOCK
#include "stm32f4xx.h"       

uint32_t count0,count1,count2,semaphore1,semaphore2;

	                                 
void task0(void){		//THESE ARE THE TASKS, WHICH INCERMNTS THE COUNT0 VALUE
	while(1){					//AS TIME GOES ON, INSIDE A WHILE LOOP THUS KEE RUNNING

		count0++;
	//threadyield();     //it will generate the systic interrupt, thus the task1 is executed when count0=1, 
	}
}

void task1(void){
while(1)
{	
	signalset(&semaphore1);
	signalwait(&semaphore2);//waits till the signal till semaphore2 bcmz greater than zero,THAT ISTASK COMPLETED ON NOT

	count1++;

	}
}

void task2(void){    
while(1)
{		
signalset(&semaphore2);//incremnt semaphore 2 BY ONE, and only this can release the the task1 from SPINNING while LOOP
	                       //WE CAN INCLUDE AS MUCH OF TASK LINES INBETWEEN THIS, BCZ ONLY AFTER THAT TASK1 WILL EXECUTE
signalwait(&semaphore1);//WAIT TILL TASK1 IS COMPLETE
  
	count2++;

}
}

int main(){
	semaphoreinit(&semaphore1,0);//INITIALIZE WITH TOKEN COUNT
	semaphoreinit(&semaphore2,0);
	kernelinit();
	kerneladdthreads(&task0,&task1,&task2);  //WHEN THE TASK IS RUNNING, EACH TASK IS RUN BY SCHEDULAR,WHICH CHNGES TASKS BY TIME
	kernellaunch(quanta);										 //AS THE TASK IS CHNGED BY SCHEDULR CUREENT STATUS OF SCHEDULR IS SAVED TO STACK AND THE RUN NEW TSK
}
