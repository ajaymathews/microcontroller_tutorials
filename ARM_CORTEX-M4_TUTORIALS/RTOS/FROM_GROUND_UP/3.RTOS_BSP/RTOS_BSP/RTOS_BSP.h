/*the TIM_HandleType wont be recognized by the controller as a valid type , so we need to add hal header to the pgm for that,
, we click the mange run time environment button 2 left of pack installer , then from the device select stm32 cube hal and from that 
tick the TIM, after that click on the resolve on last of the dilog box.thus will show require framework msg, for that select the
stm32 cubee framework,and from that select the classic
now from include we can include "stm32f4xx_hal" then that type errror will be gone

*/

#ifndef  _RTOS_BSP_H
	#define  _RTOS_BSP_H
	
	#include "stm32f4xx_hal.h"              // Keil::Device:STM32Cube HAL:Common
	
//ADDING TIMEER MODULES:
	
	//CREATING HANDLE FOR TIMER MODULES 2,3,4,5
	extern TIM_HandleTypeDef htim2;	
	extern TIM_HandleTypeDef htim3;
	extern TIM_HandleTypeDef htim4;
	extern TIM_HandleTypeDef htim5;

	//API TO INITIALIZE TIMER 2,3,4,5
	void TIM2_init(void);
	void TIM3_init(void);
	void TIM4_init(void);
	void TIM5_init(void);

	//API TO START TIMER ALONG WITH INTERRUPT
	void TIM2_int_start(void); 
	void TIM3_int_start(void);
	void TIM4_int_start(void);
	void TIM5_int_start(void);
	
	 void DelayMs(__IO uint32_t Delay);

//API TO CALL ABOVE FUNCTION

	
void SystemClock_Config80Mhz(void);	
	
	
	
#endif