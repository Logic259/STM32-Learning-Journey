#include "stm32f10x.h"   
#include "Delay.h"
int main(void)
{	
    
	while(1)
	{
		GPIO_ResetBits(GPIOB,GPIO_Pin_12);
		Delay_ms(100);
        GPIO_SetBits(GPIOB,GPIO_Pin_12);
		Delay_ms(100);
	}
} 
 