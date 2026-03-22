#include "stm32f10x.h"   
#include "Delay.h"
#include "LED.h"
#include "Key.h"
#include "OLED.h"

uint8_t KeyNum = 0;
uint8_t Mode = 0;
int main(void)
{	
  OLED_Power_Init();
  Delay_ms(20);
  OLED_Init();
  LED_Buzzer_Init();
  Key_Init();
	OLED_ShowString(1,2,"Mod");
	OLED_ShowNum(1,5,0,1);
	while(1)
	{
		KeyNum = Key_GetNum();
		if(KeyNum == 1)
        {
            if(Mode == 0)
            {
                Mode = 1; // 进入流水灯模式
				OLED_ShowString(1,2,"Mod");
	            OLED_ShowNum(1,5,1,1);
            }
            else
            {
                Mode = 0; // 关闭流水灯模式
				OLED_ShowString(1,2,"Mod");
	            OLED_ShowNum(1,5,0,1);
                LED_OFF(0); 
                LED_OFF(1);
            }
        }
		if(Mode == 1)
		{
			uint8_t i;
			for (i=0;i<2;i++)
			{
		LED_ON(i);
		Delay_ms(500);
		LED_OFF(i);
		Delay_ms(500);
			}
		}
	}
} 
 