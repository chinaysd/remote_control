//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: SC92F7003_DEMO
//	作者		: 
//	模块功能	: 红外解码与显示
//  最后更正日期: 2018/6/18
// 	版本		: V1.0 
// 	备注		: 本DEMO仅做参考之用  
//*************************************************************

/************************功能说明*******************************************************
//红外遥控按下数字0~9，数码管显示对应数值。按下其他数显示----
//红外为NEC编码格式，数码管由TM1638驱动
//占用资源：外部中断2，Timer0，IO 
****************************************************************************************/

#include "system_init.h"

extern bit T0Flag1ms, T0Flag10ms, T0Flag100ms;	      //1毫秒、10毫秒、100毫秒标志位
uchar Event_10ms = 0, Event_100ms = 0, Event_500ms = 0;  //10毫秒周期事件，100毫秒周期时间，500毫秒周期事件

int main(void)
{
	SystemInit();		                        //系统初始化

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
					IR_Display();					  //红外控制数码管显示	
					   
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


