#include "H/Function_Init.H"

void PWM_Init(void);
/*****************************************************
*�������ƣ�void PWM_Test(void)
*�������ܣ�PWM��ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void PWM_Test(void)
{
	PWM_Init();
	while(1)
	{
	}
}
/*****************************************************
*�������ƣ�void PWM_Init(void)
*�������ܣ�PWM��ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void PWM_Init(void)
{
	PWMCON  = 0x3A;		//PWM�����IO��PWMʱ��ΪFsys/4
	PWMPRD  = 59;		//PWM����=(59+1)*(1/6us)=10us	;
	PWMCFG  = 0x07;		//PWM���������,�����P25/P26/P27
 	PWMDTY0 = 30;		//PWM0��Duty = 30/60 =1/2
	PWMDTY1 = 15;       //PWM0��Duty = 15/60 =1/4
	PWMDTY2 = 10;       //PWM0��Duty = 10/60 =1/6
	PWMDTYA = 0x00;
	PWMCON |= 0x80;     //����PWM
	IE1 |= 0x02;        //����PWM�ж�
	EA = 1;
}

/*****************************************************
*�������ƣ�void PWMInt(void) interrupt 8
*�������ܣ�PWM�жϺ���
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void PWMInt(void) interrupt 8
{	
	P20=~P20;	  
}