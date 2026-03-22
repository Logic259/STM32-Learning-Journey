#include "stm32f10x.h"   
#include "Delay.h"
int main(void)
{	
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef GPIO_Initstructure;
	GPIO_Initstructure.GPIO_Mode =GPIO_Mode_Out_PP;
    GPIO_Initstructure.GPIO_Pin =GPIO_Pin_All;
	GPIO_Initstructure.GPIO_Speed =GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_Initstructure);
	while(1)
	{
		GPIO_ResetBits(GPIOB,GPIO_Pin_12);
		Delay_ms(100);
        GPIO_SetBits(GPIOB,GPIO_Pin_12);
		Delay_ms(100);
	}
} 
 