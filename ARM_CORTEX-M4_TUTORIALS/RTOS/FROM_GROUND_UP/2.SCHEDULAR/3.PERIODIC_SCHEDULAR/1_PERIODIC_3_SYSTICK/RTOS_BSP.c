#include "RTOS_BSP.h"

int counter2,counter3,counter4,counter5;


TIM_HandleTypeDef htim4; //ONLY TIMER 4 HANDLER TYPE IS DEFINED, IF MORE THAN 1 PERIODIC HANDLER
												// IS NEEDED, THEN MULTIPLE TIMER IS DEFINED


/* TIM4 init function */
void TIM4_init(void)
{
  TIM_ClockConfigTypeDef sClockSourceConfig;
  TIM_MasterConfigTypeDef sMasterConfig;

  htim4.Instance = TIM4;
  htim4.Init.Prescaler = 10000; //PRESCALER IS 1000 BCZ WE NEED 1MS FOR THE FQ 10MHZ, 
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = 1;   //in ms, thus timer interrupt is called every 1ms
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  HAL_TIM_Base_Init(&htim4);
 
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  HAL_TIM_ConfigClockSource(&htim4, &sClockSourceConfig);
 
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_UPDATE;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig);
 
}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef* tim_baseHandle)
{
 
  if(tim_baseHandle->Instance==TIM4)
  {

    /* Peripheral clock enable */
    __HAL_RCC_TIM4_CLK_ENABLE();

    /* Peripheral interrupt init */
    HAL_NVIC_SetPriority(TIM4_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(TIM4_IRQn);
 
  }
}

void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef* tim_baseHandle)
{

  if(tim_baseHandle->Instance==TIM4)
  {
 
    /* Peripheral clock disable */
    __HAL_RCC_TIM4_CLK_DISABLE();
    /* Peripheral interrupt Deinit*/
    HAL_NVIC_DisableIRQ(TIM4_IRQn);
  }
} 

void TIM4_int_start(void)
{
	 TIM4_init();
   HAL_TIM_Base_Start_IT(&htim4);
}

/*
void TIM4_IRQHandler(void)
{
  counter4++;
  HAL_TIM_IRQHandler(&htim4);
}
*/ //HIDED BECAUSE IT IS COPIED TO MAIN, AND ONLY 1 HANDLER SHOULD BE PRESENT
