#include "stm32f10x.h"   
#include "Delay.h"
#include "LED.h"
#include "Key.h"
#include "OLED.h"
#include "CountSensor.h"

uint8_t KeyNum = 0;
uint8_t Mode = 0;
int main(void)
{	
  OLED_Power_Init();
  Delay_ms(20);
  OLED_Init();
  LED_Buzzer_Init();
  Key_Init();
	CountSensor_Init();	
	OLED_ShowString(1,2,"Mod");
	OLED_ShowNum(1,5,0,1);
	while(1)
	{

		OLED_ShowNum(1, 7, CountSensor_Get(), 5);
	}
} 
 