#include "stm32f10x.h"
#include "Delay.h"

void Key_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    // PB10, PB12, PB13, PB14, PB15 
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
}

// 返回按键编号：0无, 1=PB12, 2=PB13, 3=PB14, 4=PB15, 5=PB10
uint8_t Key_GetNum(void)
{
    uint8_t KeyNum = 0;

    // 检测 PB12
    if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12) == 0) {
        Delay_ms(20); // 消抖
        while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12) == 0); // 等待松手
        Delay_ms(20);
        KeyNum = 1;
    }
    // 检测 PB13
    else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13) == 0) {
        Delay_ms(20);
        while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13) == 0);
        Delay_ms(20);
        KeyNum = 2;
    }
    // 检测 PB14
    else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14) == 0) {
        Delay_ms(20);
        while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14) == 0);
        Delay_ms(20);
        KeyNum = 3;
    }
    // 检测 PB15
    else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15) == 0) {
        Delay_ms(20);
        while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15) == 0);
        Delay_ms(20);
        KeyNum = 4;
    }
    // 检测 PB10
    else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10) == 0) {
        Delay_ms(20);
        while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10) == 0);
        Delay_ms(20);
        KeyNum = 5;
    }

    return KeyNum;
}