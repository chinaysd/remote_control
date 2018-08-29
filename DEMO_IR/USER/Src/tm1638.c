#include "tm1638.h"
#include "intrins.h"

#define nop    _nop_();_nop_();_nop_();_nop_();_nop_();_nop_();

sbit DIO = P1^1;		   //数据输入输出脚
sbit CLK = P1^2;		   //时钟输入脚
sbit STB = P1^3;		   //片选脚

uchar code TableNumber[18]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,0x00,0X40}; //0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F,灭灯，-
uchar code TablePoint[18] ={0xbf,0x86,0xdb,0xcf,0xeb,0xed,0xfd,0x87,0xff,0xef,0xf7,0xfc,0x99,0xde,0xf9,0xf1,0x00,0X40};	//0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F（带小数点），灭灯，-

/**************************************************
*函数名称：SendData	
*函数功能：往TM1638写一个字节
*入口参数：dat       字节数据	        	
*出口参数：无
*功能说明：
**************************************************/
void SendData(uchar dat)	
{
	uchar i;
	for(i=0;i<8;i++)
	{	 
		CLK = 0;
		if(dat & 0x01) 
			DIO = 1;
		else 
			DIO = 0;
		_nop_();
		_nop_();
		_nop_();
		CLK = 1;
		dat >>= 1;
	}
	CLK=0;
	DIO=0;
}

/**************************************************
*函数名称：SendCommand	
*函数功能：往TM1638写命令
*入口参数：Command   命令值	        	
*出口参数：无
*功能说明：
**************************************************/
void SendCommand(uchar Command)
{
	STB=0;
	SendData(Command);
	STB=1;
}

/**************************************************
*函数名称：TM1638_Init	
*函数功能：TM1638初始化
*入口参数：无	        	
*出口参数：无
*功能说明：脉冲宽度为13/16
**************************************************/
void TM1638_Init(void)
{
	uchar i;
	SendCommand(0x8A);		//亮度调节
	SendCommand(0x40);      
	STB = 0;
	SendData(0xc0);	     	
	for(i=0;i<16;i++)	   //显示寄存器清0
	SendData(0x00);
	STB = 1;	
}

/**************************************************
*函数名称：TM1638_DisplayOnlyNumber	
*函数功能：TM1638显示（仅数字）
*入口参数：COM1~COM4   对应数码管编码表下标        	
*出口参数：无
*功能说明：
**************************************************/
void TM1638_DisplayOnlyNumber(uchar COM1,uchar COM2,uchar COM3,uchar COM4)
{
	SendCommand(0x40);
	STB = 0;
	SendData(0xc0 | 0x00);
	SendData(TableNumber[COM1]);	SendData(0x00);
	SendData(TableNumber[COM2]);	SendData(0x00);
	SendData(TableNumber[COM3]);	SendData(0x00);
	SendData(TableNumber[COM4]);	SendData(0x00);
	STB = 1;		
} 

