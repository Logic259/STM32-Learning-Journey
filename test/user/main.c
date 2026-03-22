#include "stm32f10x.h"   
#include "Delay.h"
#include "LED.h"
#include "Key.h"
#include "OLED.h"
#include "PWM.h"

void Full(void)
{
    uint8_t i;
    for(i = 0; i < 3; i++)
    {
        Buzzer_ON();   
        Delay_ms(100); 
        Buzzer_OFF();  
        Delay_ms(100); 
    }
}
void LED(int count)
{
    GPIO_SetBits(GPIOA, GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_6);

    if(count >= 1) GPIO_ResetBits(GPIOA, GPIO_Pin_1);
    if(count >= 2) GPIO_ResetBits(GPIOA, GPIO_Pin_6);
    if(count >= 3) GPIO_ResetBits(GPIOA, GPIO_Pin_4);
    if(count >= 4) GPIO_ResetBits(GPIOA, GPIO_Pin_3);
    if(count >= 5) GPIO_ResetBits(GPIOA, GPIO_Pin_2);
}

   int main(void)
{	
  PWM_Init();	
  OLED_Init();
  LED_Buzzer_Init();
  Key_Init();
uint8_t KeyNum = 0;
int16_t AC = 0 ;
int16_t BC = 0;
int16_t ALL = 5;
int16_t AF = 2;
int16_t BF = 3;
int16_t AFX = 5;
int16_t BFX = 0;
int model = 0;
int Timer = 0; 
int Step = 0;
	while(1)
	{
	if(model==0)
	{
	while(1)
	{
    OLED_ShowString(1,5,"Car Number");
	OLED_ShowString(2,2,"TypeA Car:");
	OLED_ShowString(3,2,"TypeB Car:");
	OLED_ShowString(4,2,"Free Seat:");
    OLED_ShowNum(2,12,AC,1);
	OLED_ShowNum(3,12,BC,1);
	OLED_ShowNum(4,12,ALL-AC-BC,1);
    KeyNum = Key_GetNum();
	Delay_ms(10);
	if(AC + BC < ALL)
    {
      LED(AC + BC);
      Timer = 0;
     }
     else
     {
       Timer++;
       if(Timer >= 50)
      {
       Timer = 0;
       Step++;
       if(Step > 4) Step = 0;
       GPIO_SetBits(GPIOA, GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_6);
       switch(Step){
       case 0: GPIO_ResetBits(GPIOA, GPIO_Pin_1); break;
       case 1: GPIO_ResetBits(GPIOA, GPIO_Pin_6); break;
       case 2: GPIO_ResetBits(GPIOA, GPIO_Pin_4); break;
       case 3: GPIO_ResetBits(GPIOA, GPIO_Pin_3); break;
       case 4: GPIO_ResetBits(GPIOA, GPIO_Pin_2); break;
                    }
                }
            }
		if(KeyNum == 1)
		{
			if(ALL-AC-BC>0){AC++;PWM_SetCompare1(100);GPIO_ResetBits(GPIOA, GPIO_Pin_5);}
		    else{Full();}
		}
		if(KeyNum == 2)
		{
			if(ALL-AC-BC > 0){
		    BC++;PWM_SetCompare1(50);GPIO_ResetBits(GPIOA, GPIO_Pin_5);}
			else{Full();}
		}
		if(KeyNum == 3&&AC>0)
		{
			AC--;
		}
		if(KeyNum == 4&&BC>0)
		{
			BC--;
		}
		else if(KeyNum == 5)
		{
			model=1;
			OLED_Clear();
			break;
		}
		if(AC+BC==1)
		{
		 GPIO_ResetBits(GPIOA, GPIO_Pin_1);
		}
				if(AC+BC==2)
		{
		 GPIO_ResetBits(GPIOA, GPIO_Pin_6);
		}
				if(AC+BC==3)
		{
		 GPIO_ResetBits(GPIOA, GPIO_Pin_4);
		}
				if(AC+BC==4)
		{
		 GPIO_ResetBits(GPIOA, GPIO_Pin_3);
		}
					if(AC+BC==5&&KeyNum != 5)
		{
		
		}
		if(ALL-(AC+BC) == 0&&(KeyNum == 1||KeyNum == 3))
		{
        Full();
		}
	}
}
	if(model==1)
	{
	while(1)
	    {
		KeyNum = Key_GetNum();
		OLED_ShowString(1,5,"Para");
		OLED_ShowString(2,2,"TypeA Car:");
	    OLED_ShowString(3,2,"TypeB Car:");
		OLED_ShowString(2,13,".");
		OLED_ShowNum(2,12,AF,1);
		OLED_ShowNum(2,14,AFX,1);	
		OLED_ShowString(3,13,".");
	    OLED_ShowNum(3,12,BF,1);
		OLED_ShowNum(3,14,BFX,1);
        if(KeyNum == 1)
		{
		 AFX+=5;
		 if(AFX%10==0)
		 {
		  AF++;
		  AFX =0; 
		 }			 
		}	
         if(KeyNum == 2)
		{ 
		 if(AF > 0 || AFX > 0) 
			{
			if(AFX == 5)
			{
			AFX = 0;
			}
			else
			{
			AFX = 5;
			AF--;
			}
			}		
		}
         if(KeyNum == 3)
		{
		 BFX+=5;
		 if(BFX%10==0)
		 {
		  BF++;
		  BFX=0;	 
		 }			 
		}	
        if(KeyNum == 4)
		 { 
		 if(BF > 0 || BFX > 0) 
			{
			if(BFX == 5)
			{
			BFX = 0;
			}
			else
			{
			BFX = 5;
			BF--;
			}
			}		
		}
          if(KeyNum == 5)
		{
			model=0;
			OLED_Clear();
			break;
		}		
		}
	}
	}
}
 