#include "stm32f10x.h"   
#include "Delay.h"
int main(void)
{	
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_Initstructure;
	GPIO_Initstructure.GPIO_Mode =GPIO_Mode_Out_PP;
    GPIO_Initstructure.GPIO_Pin =GPIO_Pin_All;
	GPIO_Initstructure.GPIO_Speed =GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_Initstructure);
	while(1)
	{
			 GPIO_Write(GPIOA,~0x0001);
		     Delay_ms(100);
			  GPIO_Write(GPIOA,~0x0002);
		     Delay_ms(100);
		 GPIO_Write(GPIOA,~0x0004);
		     Delay_ms(100);
		 GPIO_Write(GPIOA,~0x0008);
		     Delay_ms(100);
		 GPIO_Write(GPIOA,~0x0010);
		     Delay_ms(100);
	}
} 
 