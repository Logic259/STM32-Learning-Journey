#include "stm32f10x.h"   

int main(void)
{	
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_Initstructure;
	GPIO_Initstructure.GPIO_Mode =GPIO_Mode_Out_PP;
    GPIO_Initstructure.GPIO_Pin =GPIO_Pin_1;
	GPIO_Initstructure.GPIO_Speed =GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_Initstructure);
	while(1)
	{
			 GPIO_WriteBit(GPIOA,GPIO_Pin_1,Bit_RESET);
	}
} 
