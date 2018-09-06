#include "H/Function_Init.H"

unsigned char a;
volatile uint IR_Count;
extern uchar IR_KeyValue[4];	  //ϵͳ�롢�����롢�����뷴��������
extern unsigned char LED_FLAG;
extern uchar ok_decode;
void main(void)
{
	IO_Init();
	Timer_Init();
  EX_Init();
	while(1)
	{
			if(0x47 == IR_KeyValue[2])
			{
					P27 = 1;			
			}
			else
			{
				P27 = 0;
			}
	}
}

/*****************************************************
*�������ƣ�void EX0/1/2() interrupt	0/2/10
*�������ܣ��ⲿ�жϳ�ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void EX0() interrupt	0
{
    
}

void EX1() interrupt	2
{
   
}

void EX2() interrupt	10
{
    //P27 = ~P27;
	  IR1838Processing();
	 
}

/**************************************************
*�������ƣ�void timer0/1/2() interrupt 1/3/5
*�������ܣ���ʱ���жϲ�������
*��ڲ�����void
*���ڲ�����void
**************************************************/
void timer0() interrupt 1
{
  TL0 = (65536 - 440)%256;
	TH0 = (65536 - 440)/256;
	//P27 = ~P27;
	IR_Count++;
}

void timer1() interrupt 3
{
	
}

void Timer2Int(void) interrupt 5
{		
	TF2 = 0;   //�������
    
}