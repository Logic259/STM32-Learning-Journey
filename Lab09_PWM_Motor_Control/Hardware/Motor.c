#include "stm32f10x.h"
#include "Timer.h"

void Motor_Init(void)
{
    PWM_Init(); // 启动底层 PWM
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    
    // 配置 PA1, PA2 控制方向
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void Motor_SetSpeed(int8_t Speed)
{
    if (Speed >= 0) // 正转
    {
        GPIO_SetBits(GPIOA, GPIO_Pin_1);
        GPIO_ResetBits(GPIOA, GPIO_Pin_2);
        PWM_SetCompare1(Speed);
    }
    else // 反转
    {
        GPIO_ResetBits(GPIOA, GPIO_Pin_1);
        GPIO_SetBits(GPIOA, GPIO_Pin_2);
        PWM_SetCompare1(-Speed); // 占空比取正
    }
}