#include "stm32f10x.h"
#include "Timer.h"

void Timer_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	TIM_Cmd(TIM2, ENABLE);
	
}