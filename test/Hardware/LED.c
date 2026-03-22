#include "stm32f10x.h"

// 硬件连接说明：
// LED: PA1, PA2, PA3, PA4, PA5, PA6 (共阳极，低电平点亮)
// 蜂鸣器: PB12 (低电平触发)

void LED_Buzzer_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);

    // 配置 LED 引脚 (PA1 - PA6)
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; // 推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    // 默认熄灭 (置高电平)
    GPIO_SetBits(GPIOA, GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6);

    // 配置 蜂鸣器 (PB12)
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_SetBits(GPIOB, GPIO_Pin_12); // 默认不叫 (高电平)
}

void LED_ON(uint16_t GPIO_Pin)
{
    // 低电平点亮
    GPIO_ResetBits(GPIOA, GPIO_Pin); 
}

void LED_OFF(uint16_t GPIO_Pin)
{
    // 高电平熄灭
    GPIO_SetBits(GPIOA, GPIO_Pin);
}

// 蜂鸣器控制 (低电平触发)
void Buzzer_ON(void)  { GPIO_ResetBits(GPIOB, GPIO_Pin_12); }
void Buzzer_OFF(void) { GPIO_SetBits(GPIOB, GPIO_Pin_12); }