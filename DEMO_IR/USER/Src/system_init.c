#include "system_init.h"

void SystemInit(void)
{
	GPIO_Init();		 		//IO��ʼ��
	TIMER0_Init();		 		//T0��ʼ������ʱ40us
	TM1638_Init();			    //TM1638��ʼ��
	EXTI2_Init();		 		//�ⲿ�жϿ�P22��ʼ��

	TM1638_DisplayOnlyNumber(17, 17, 17, 17);	//������ϵ���ʾֵ
	EA = 1;						//�����ж�
}