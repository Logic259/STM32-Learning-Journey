#ifndef __LED_BUZZER_H
#define __LED_BUZZER_H
#include "stm32f10x.h"

// 初始化函数保持不变
void LED_Buzzer_Init(void);

void LED_ON(uint16_t GPIO_Pin);
void LED_OFF(uint16_t GPIO_Pin);

// 蜂鸣器控制保持不变
void Buzzer_ON(void);
void Buzzer_OFF(void);

#endif
