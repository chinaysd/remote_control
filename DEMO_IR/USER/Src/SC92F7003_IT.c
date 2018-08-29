//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: SC92F7003_IT.C
//	����		: 
//	ģ�鹦��	: SC92F7003_IT�̼��⺯��C�ļ�
//	�ֲ������б�:
//  ����������: 2018/3/18
// 	�汾		: V1.0   
//*************************************************************

#include "sc92f7003_it.h"
#include "ir1838.h"

volatile uint  T0Flag1msCount = 0, T0Flag10msCount = 0, T0Flag100msCount = 0, IR_Count = 0;	 // 1ms/10ms/100ms����ֵ��INT2ʱ�����ֵ�������ж�������������룩
bit T0Flag1ms = 0,T0Flag10ms = 0, T0Flag100ms = 0;	//1���롢10���롢100�����־λ

void INT0Interrupt()		interrupt 0
{

}

void Timer0Interrupt()		interrupt 1
{
	TL0 = (65536 - 640)%256 + TL0 ;  	   	//�˴��޸ĳ�ֵʹ֮������40us
	TH0 = (65536 - 640)/256;
	IR_Count++;

	if(++T0Flag1msCount > 24)
	{
		T0Flag1ms = 1;
		T0Flag1msCount = 0;
	}	
	if(++T0Flag10msCount > 249)
	{
		T0Flag10ms = 1;
		T0Flag10msCount = 0;
	}	
	if(++T0Flag100msCount > 2499)
	{
		T0Flag100ms = 1;
		T0Flag100msCount = 0;
	}		
}

void INT1Interrupt()		interrupt 2
{

}

void Timer1Interrupt()		interrupt 3
{
	
}

void UART0Interrupt()		interrupt 4
{
	
}

void Timer2Interrupt()		interrupt 5
{

}

void ADCInterrupt()			interrupt 6
{

}

void SSIInterrupt()			interrupt 7
{

}

void PWMInterrupt()			interrupt 8
{

}

void BTMInterrupt()			interrupt 9
{

}

void INT2Interrupt()		interrupt 10
{
	IR1838Processing();
		
}

/******************* (C) COPYRIGHT 2018 SinOne Microelectronics *****END OF FILE****/