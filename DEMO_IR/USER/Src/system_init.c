#include "system_init.h"

void SystemInit(void)
{
	GPIO_Init();		 		//IO初始化
	TIMER0_Init();		 		//T0初始化，定时40us
	TM1638_Init();			    //TM1638初始化
	EXTI2_Init();		 		//外部中断口P22初始化

	TM1638_DisplayOnlyNumber(17, 17, 17, 17);	//数码管上电显示值
	EA = 1;						//开总中断
}