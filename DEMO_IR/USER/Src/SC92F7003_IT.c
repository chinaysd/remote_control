//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: SC92F7003_IT.C
//	作者		: 
//	模块功能	: SC92F7003_IT固件库函数C文件
//	局部函数列表:
//  最后更正日期: 2018/3/18
// 	版本		: V1.0   
//*************************************************************

#include "sc92f7003_it.h"
#include "ir1838.h"

volatile uint  T0Flag1msCount = 0, T0Flag10msCount = 0, T0Flag100msCount = 0, IR_Count = 0;	 // 1ms/10ms/100ms计数值，INT2时间计数值（用以判断引导码或数据码）
bit T0Flag1ms = 0,T0Flag10ms = 0, T0Flag100ms = 0;	//1毫秒、10毫秒、100毫秒标志位

void INT0Interrupt()		interrupt 0
{

}

void Timer0Interrupt()		interrupt 1
{
	TL0 = (65536 - 640)%256 + TL0 ;  	   	//此处修改初值使之更贴近40us
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