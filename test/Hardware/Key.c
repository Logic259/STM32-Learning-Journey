#include "stm32f10x.h"
#include "Delay.h"

// 初始化按键引脚: PA8 - PA12
void Key_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    // 1. 开启 GPIOA 时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    // 2. 配置 PA8, PA9, PA10, PA11, PA12 为上拉输入 (IPU)
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

// 获取按键值函数
// 返回: 0=无按键, 1=PA8, 2=PA9, 3=PA10, 4=PA11, 5=PA12
uint8_t Key_GetNum(void)
{
    uint8_t KeyNum = 0;

    // 检测 Key 1 (PA8)1
    if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8) == 0)
    {
        Delay_ms(20); // 消抖
        while (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8) == 0); // 松手检测
        Delay_ms(20);
        KeyNum = 1;
    }
    // 检测 Key 2 (PA9)4
    else if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_9) == 0)
    {
        Delay_ms(20); while (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_9) == 0); Delay_ms(20);
        KeyNum = 4;
    }
    // 检测 Key 3 (PA10)5
    else if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_10) == 0)
    {
        Delay_ms(20); while (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_10) == 0); Delay_ms(20);
        KeyNum = 5;
    }
    // 检测 Key 4 (PA11)2
    else if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_11) == 0)
    {
        Delay_ms(20); while (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_11) == 0); Delay_ms(20);
        KeyNum = 2;
    }
    // 检测 Key 5 (PA12)3
    else if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_12) == 0)
    {
        Delay_ms(20); while (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_12) == 0); Delay_ms(20);
        KeyNum = 3;
    }

    return KeyNum;
}