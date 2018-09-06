
#include "ir1838.h"


extern uint IR_Count;				  //INT2ʱ�����ֵ�������ж�������������룩
uchar IR_KeyValue[4] = {0,0,0,0};	  //ϵͳ�롢�����롢�����뷴��������
uchar value ;						  //ң����������ֵ
uchar flag;
uchar LED_FLAG;
uchar n,ok_decode,aa;

//  ����ң�ذ�����Ӧ��ֵ  
//    1  2  3        -->	   45  46  47
//    4	 5	6		 -->	   44  40  43
//    7	 8	9		 -->	   07  15  09
//    *	 0	#		 -->	   16  19  0D
//	     up			 -->		   18
//   lf	 ok	  rg	 -->	   08  1C  5A
//	  	 dn			 -->		   52

/**************************************************
*�������ƣ�IR1838Processing
*��������: �������ݴ���
*��ڲ�������	        	
*���ڲ�������
*����˵����
**************************************************/
void IR1838Processing(void)
{
	static uchar  i = 0,j = 0;            
	static bit IR_Flag = 1;               //�Ƿ�ʼ�����־λ
	
	n++;
	
  if(n == 1)
	{
		IR_Count = 0;
	}
	if(n == 2)
	{
		if(IR_Count<=350 && IR_Count>=325)    //�����룬9ms+4.5ms=337.5������ǰ����0.5ms
		{
			i = 0;							  //�������½���
			IR_Flag = 0;              		  //���յ���ȷ��������,��ʼ��������
			IR_Count = 0;
			ok_decode=0;
			aa = 0;
		}
		if(IR_Count<=293 && IR_Count>=268)     //�����ж�
		{
		  aa++;
			if(aa > 9)
			{
				IR_KeyValue[2] = 0x17;
			}
			IR_Count = 0;
			n = 0;
			IR_Flag = 1;
		}
		
	}
	if(IR_Flag == 0)
	{            
		if(IR_Count<=31 && IR_Count>=25)	   //1.120ms,28
		{
			IR_KeyValue[i] >>= 1;
			IR_KeyValue[i] &= 0x7f;
			j++;
			
		}
		if(IR_Count<=59 && IR_Count>=53)	   //2.240ms,56
		{
			IR_KeyValue[i] >>= 1;
			IR_KeyValue[i] |= 0x80;
			j++;
			
		}
		IR_Count = 0;
		if(j == 8)
		{
			j = 0;
			i++;
			if(i > 3)						  //�������
			{
				i = 0;
				n = 0;
				IR_Flag = 1;
				IR_Count = 0;
			}
		}
		
	}
}

/**************************************************
*�������ƣ�IR_ReadKey
*��������: ������ң������ֵ
*��ڲ�������	        	
*���ڲ�������
*����˵��������0~9��Ч�����ఴ����ʾ----
**************************************************/
	#if 0
uchar IR_ReadKey(void)
{

	switch(IR_KeyValue[2])			//������
		{
			case 0x19:
				value = 0;
				break;
			case 0x45:
				value = 1;
				break;
			case 0x46:
				value = 2;
				break;
			case 0x47:
				if(!flag)
				{
					flag = 1;
					value = 3;
				}
				break;
			case 0x44:
				value = 4;
				break;
			case 0x40:
				value = 5;
				break;
			case 0x43:
				value = 6;
				break;
			case 0x07:
				value = 7;
				break;
			case 0x15:
				value = 8;
				break;
			case 0x09:
				value = 9;
				break;
			default:
				flag = 0;
				value = 17;	
		}
		return value;	
}
#endif
