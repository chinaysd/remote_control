//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: SC92F7003_DEMO
//	����		: 
//	ģ�鹦��	: �����������ʾ
//  ����������: 2018/6/18
// 	�汾		: V1.0 
// 	��ע		: ��DEMO�����ο�֮��  
//*************************************************************

/************************����˵��*******************************************************
//����ң�ذ�������0~9���������ʾ��Ӧ��ֵ��������������ʾ----
//����ΪNEC�����ʽ���������TM1638����
//ռ����Դ���ⲿ�ж�2��Timer0��IO 
****************************************************************************************/

#include "system_init.h"

extern bit T0Flag1ms, T0Flag10ms, T0Flag100ms;	      //1���롢10���롢100�����־λ
uchar Event_10ms = 0, Event_100ms = 0, Event_500ms = 0;  //10���������¼���100��������ʱ�䣬500���������¼�

int main(void)
{
	SystemInit();		                        //ϵͳ��ʼ��

	while(1)
	{	
	   
		if(T0Flag1ms)
		{
			switch(Event_10ms)
			{
				case 1: 
                        //P2 = 0X30;
					break;

				case 2:	
                        //P2 = 0X30;
					break;

				case 3:
                       // P2 = 0X30;
					break;

				case 4:		
                          //P2 = 0X30;
					break;

				case 5:		
                         // P2 = 0X30;
					break;

				case 6:	
                          //P2 = 0X30;
					break;

				case 7:	
                          //P2 = 0X30;
					break;

			   	case 8:	
                          //P2 = 0X30;
					break;
				
				case 9:	
                          //P2 = 0X30;
					break;

				default:          
					Event_10ms = 0;
			}
			Event_10ms++;
			T0Flag1ms = 0;	
		}

		if(T0Flag10ms)
		{
			switch(Event_100ms)
			{
				case 1:				
					IR_Display();					  //��������������ʾ	
					   
					break;

				case 2:
                        // P2 = 0X30;
					break;

				case 3:		
                        // P2 = 0X30;
					break;

				case 4:		
                         //P2 = 0X30;
					break;

				case 5:		
                         //P2 = 0X30;
					break;

				case 6:		
                          //P2 = 0X30;
					break;

				case 7:		
                         /// P2 = 0X30;
					break;

			   	case 8:		
                        // P2 = 0X30;
					break;

				case 9:	
                        // P2 = 0X30;
					break;

				default:         		
					Event_100ms = 0;
			}
			Event_100ms++;
			T0Flag10ms = 0;	
		}

		if(T0Flag100ms)
		{										
			switch(Event_500ms)
			{
				case 1: 
                        //P2 = 0X30;
					break;

				case 2:
                        // P2 = 0X30;
				    break;

				case 3:	
                        // P2 = 0X30;
					break;

				case 4:	 
                         // P2 = 0X30;
					break;

				default:         		
					Event_500ms = 0;
			}
			Event_500ms++;
			T0Flag100ms = 0; 
		}		
	}
}


