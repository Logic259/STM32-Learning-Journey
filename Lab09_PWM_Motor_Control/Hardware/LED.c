#include "stm32f10x.h"

// 初始化 LED(PA0-5) 和 蜂鸣器(PB9)
void LED_Buzzer_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);

    // 配置 LED PA0 - PA5 推挽输出
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    // 初始化熄灭所有LED (置高)
    GPIO_SetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5);

    // 配置 蜂鸣器 PB9 推挽输出
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    // 初始化关闭蜂鸣器 (假设低电平关)
    GPIO_ResetBits(GPIOB, GPIO_Pin_9);
}

// 控制函数：num为0-5代表第1到6个LED
void LED_ON(uint8_t num)
{
    // 使用位移操作，比如 num=0，则移位 0 位操作 Pin_0
    GPIO_ResetBits(GPIOA, (uint16_t)(0x0001 << num)); 
}

void LED_OFF(uint8_t num)
{
    GPIO_SetBits(GPIOA, (uint16_t)(0x0001 << num));
}

void LED_Toggle(uint8_t num)
{
    uint16_t pin = (uint16_t)(0x0001 << num);
    if (GPIO_ReadOutputDataBit(GPIOA, pin) == 0) // 如果当前是亮的
        GPIO_SetBits(GPIOA, pin); // 关
    else
        GPIO_ResetBits(GPIOA, pin); // 开
}

void Buzzer_ON(void)  { GPIO_SetBits(GPIOB, GPIO_Pin_9); }
void Buzzer_OFF(void) { GPIO_ResetBits(GPIOB, GPIO_Pin_9); }