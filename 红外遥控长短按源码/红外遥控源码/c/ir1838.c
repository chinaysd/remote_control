
#include "ir1838.h"


extern uint IR_Count;				  //INT2时间计数值（用以判断引导码或数据码）
uchar IR_KeyValue[4] = {0,0,0,0};	  //系统码、数据码、数据码反码存放数组
uchar value ;						  //遥控器按键键值
uchar flag;
uchar LED_FLAG;
uchar n,ok_decode,aa;

//  红外遥控按键对应码值  
//    1  2  3        -->	   45  46  47
//    4	 5	6		 -->	   44  40  43
//    7	 8	9		 -->	   07  15  09
//    *	 0	#		 -->	   16  19  0D
//	     up			 -->		   18
//   lf	 ok	  rg	 -->	   08  1C  5A
//	  	 dn			 -->		   52

/**************************************************
*函数名称：IR1838Processing
*函数功能: 红外数据处理
*入口参数：无	        	
*出口参数：无
*功能说明：
**************************************************/
void IR1838Processing(void)
{
	static uchar  i = 0,j = 0;            
	static bit IR_Flag = 1;               //是否开始处理标志位
	
	n++;
	
  if(n == 1)
	{
		IR_Count = 0;
	}
	if(n == 2)
	{
		if(IR_Count<=350 && IR_Count>=325)    //引导码，9ms+4.5ms=337.5个，往前往后0.5ms
		{
			i = 0;							  //数组重新接收
			IR_Flag = 0;              		  //接收到正确的引导码,开始接收数据
			IR_Count = 0;
			ok_decode=0;
			aa = 0;
		}
		if(IR_Count<=293 && IR_Count>=268)     //重码判断
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
			if(i > 3)						  //接收完成
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
*函数名称：IR_ReadKey
*函数功能: 读红外遥控器键值
*入口参数：无	        	
*出口参数：无
*功能说明：按键0~9有效，其余按键显示----
**************************************************/
	#if 0
uchar IR_ReadKey(void)
{

	switch(IR_KeyValue[2])			//数据码
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
