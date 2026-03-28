#ifndef __LED_BUZZER_H
#define __LED_BUZZER_H
#include "stm32f10x.h"

void LED_Buzzer_Init(void);
void LED_ON(uint8_t num);
void LED_OFF(uint8_t num);
void LED_Toggle(uint8_t num);
void Buzzer_ON(void);
void Buzzer_OFF(void);

#endif
