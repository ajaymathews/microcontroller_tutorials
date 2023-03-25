//main can only acess and load only the functions that defined in this header

#ifndef KERNEL_H  //checking if oskernEl.h is defined or not
#define KERNEL_H  //if not then define oskernel.h
#include <stdint.h>

void kernellaunch(uint32_t quanta);//becuse we are going to use the round-robin sceduler
void kernelinit(void);
void threadyield(void);
//thread is a executuon of task
uint8_t kerneladdthreads(void(*task0)(void),   //to add threads to kernel andreturn a number if succcedded
												 void(*task1)(void),
											 	 void(*task2)(void)); 

												 
#endif

												 