/*

	USING THIS ONLY ONE THREAD CAN COMMUNCT WITH TASK AT SAME TIME.BCZ IN CASE OF GLCD DIDPLY , EACHTASK RUNS THE GLCD AT SAME TIME ATIT TENDS TO 
	HANG, THS CAN BE AVOIDED BY USING SEMAPHORE METHOD(SPINLOCK).IN WHICH EACH TASK IS ASSIGNED A TOKEN VALUE.IF TASK ONE IS COMPLETE THEN ONLY THE TASK 2
	CAN RUN AND VICE VERSA.
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
{	signalwait(&semaphore2);//waits till the signal till semaphore2 bcmz greater than zero,THAT ISTASK COMPLETED ON NOT
	count1++;
	signalset(&semaphore1);
	}
}

void task2(void){    
while(1)
{	signalwait(&semaphore1);//WAIT TILL TASK1 IS COMPLETE
	count2++;
	signalset(&semaphore2);//incremnt semaphore 2 BY ONE, and only this can release the the task1 from SPINNING while LOOP
	                       //WE CAN INCLUDE AS MUCH OF TASK LINES INBETWEEN THIS, BCZ ONLY AFTER THAT TASK1 WILL EXECUTE
  }
}

int main(){
	semaphoreinit(&semaphore1,1);//INITIALIZE WITH TOKEN COUNT
	semaphoreinit(&semaphore2,0);
	kernelinit();
	kerneladdthreads(&task0,&task1,&task2);  //WHEN THE TASK IS RUNNING, EACH TASK IS RUN BY SCHEDULAR,WHICH CHNGES TASKS BY TIME
	kernellaunch(quanta);										 //AS THE TASK IS CHNGED BY SCHEDULR CUREENT STATUS OF SCHEDULR IS SAVED TO STACK AND THE RUN NEW TSK
}
