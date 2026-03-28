#include "stm32f10x.h"                  // Device header

void CountSensor_Init(void)
(
   RCC_APB2PeriphClockCmd(RCC_AHBPeriph_GPIOB,ENABLE);
   RCC_APB2PeriphClockCmd(RCC_AHBPeriph_AFIO,ENABLE);

)   
