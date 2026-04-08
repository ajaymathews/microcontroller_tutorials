//WE NEED SCHEDULER, THREAD CONTROL BLOCK(TCB),STACK TO STORE CONTXT OF THREAD.

#include "kernel.h"
#include "stm32f4xx.h"                  // Device header

#define syspri3 (*((volatile uint32_t *)0xE000ED20)) //ADDRESS OF PRIORITY REGITER(ON ALL CORTEX), TO SET PRIORITY OF SYSTICK
#define thread_nums 3                              //DEFINED 3 AS THEAD_NUMS
#define stack_size 100                             //CONTEXT SIZE
#define bus_clock 10000000                        //FQ OF THE CONTROLLER
#define plusone 1
uint32_t mills_prescalar;

void SchedulerLaunch(void);


struct tcb{                                        // CREATING STRUCTURE FOR TASK 
int32_t *stackptr;                                 // STACK POINTER TO POINT TO STACK WHEN EXECPTION OCCURS
	struct tcb *nextptr;                             // THEAD/TASK POINER TO POINT TO NEXT TASK AFTER COMPLETION OF CURRENT TASK
};

typedef struct tcb tcbtype;                        //CREATING A DATATYPE FOR THE STRUCTURE TCB, 
														                     	 //THUS USING TCBTYPE WE CAN CREATE ITS MEMBERS VARIABLES
tcbtype tcbs[thread_nums];                         //CREATING AN ARRAY OF THE STRUCTURE TCB TYPE
tcbtype *currentptr;                               //POINTER TO POINT TO CURRENT THREAD OF TYPE STRUCT TCB
int32_t tcb_stack[thread_nums][stack_size];        //CREATING 2D ARRAY[3][100] TO STORE
																					
//TO INITIALIZE THE STACK
void kernelstackinit(int i){                       //FN TO INITIALIZE STACK WITH i AS THE THREAD NUM 0, 1 AND 2	
	tcbs[i].stackptr = &tcb_stack[i][stack_size-16]; //STACKPOINTER POINTS TO TOP OF STACK OF SAME THREAD
	tcb_stack[i][stack_size-1]= 0x01000000;          //(1<<24 BIT OF XPSR[STATUS REG] SETS M-CORTEX IN THUMB MODE).
	//REG(R0,R1,R2,R3,R12,[R14]LR,[R15]PC,xPSR)[ORDER AS FROM LOW TO HIGH] , THUS STACK-1 SETS THE XPSR RG	
}

uint8_t kerneladdthreads(void(*task0)(void),void(*task1)(void),void(*task2)(void))
{
	//TO SETS THE TASK ARRANGEMNT FOR SCHEDULER
	__disable_irq();															   //DISABLES INTERRUPT WHILE EXECUTING THIS BLOCK
	tcbs[0].nextptr = &tcbs[1];                      //INITIALIZE FOT THE NEXT POINTER OF EACH THREAD TO POINT TO THE NEXT THREAD 
	tcbs[1].nextptr = &tcbs[2];											 //AND THUS LAST THREAD TO FIRST ONE
	tcbs[2].nextptr = &tcbs[0];
	
	kernelstackinit(0);                              //INITIALIZE STACK POINTR AND SET THUMB MODE FOR THREAD 0
	tcb_stack[0][stack_size-2] = (int32_t)(task0);    //PGM COUNTER TO TASK ZERO, SO THAT AT NEXT STEP IT STARTINS EXECUTING TASK 0,
//REG(R0,R1,R2,R3,R12,[R14]LR,[R15]PC,xPSR)[ORDER AS FROM LOW TO HIGH] , THUS STACK-2 SETS THE PC 	

//SIMILARLY SETS TASK 1 AND 2	
	kernelstackinit(1);
	tcb_stack[1][stack_size-2] = (int32_t)(task1);
	kernelstackinit(2);
	tcb_stack[2][stack_size-2] = (int32_t)(task2);
	
	currentptr = &tcbs[0];//begin with first thread 
	
	__enable_irq();
	return 1;
}

void kernelinit(void){
	__disable_irq();
	mills_prescalar = bus_clock/1000;          //MILLS_PRESCLR IS 10,000, THUS TO TOGGLE SYSTICK IN EACH MILLISECONDS (BCZ FQ IS 10,000,000 SIGNALS IN 1 SEC, 10,000 IN ONE MILLISECOND)
																							//count value is changed in these time
// mills_prescalar = bus_clock/1000;   // IF WANT TO DECREASE SYSTICK TIME FURTHER THAN 1MS, REDUCE THE PRESCALAR BY DIVIDING WITH HIGHER VALUE 
}

void kernellaunch(uint32_t quanta){
SysTick->CTRL =0;     //DISBLES THE SYSYTICK                              //systick reg can only be included if only, device header is added
SysTick->VAL=0;
SysTick->LOAD = (quanta*mills_prescalar)-1;      //QUANTA IN MILLISECONDS,
syspri3 =(syspri3 & 0x00FFFFFF)	| 0xE0000000;  //priority 7, which is the lowest

SysTick->CTRL = 0x00000007;
//SCHEDULAR LAUNCH TO LOAD NEW CONTEXT
	SchedulerLaunch();  

}
