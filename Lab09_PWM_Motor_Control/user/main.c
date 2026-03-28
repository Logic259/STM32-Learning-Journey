#include "stm32f10x.h"
#include "Delay.h"
#include "Motor.h"

int main(void)
{
    Motor_Init();
    
    while(1)
    {
        Motor_SetSpeed(30);  // 慢速正转
        Delay_ms(2000);
        Motor_SetSpeed(-60); // 快速反转
        Delay_ms(2000);
        Motor_SetSpeed(0);   // 停转
        Delay_ms(1000);
    }
}