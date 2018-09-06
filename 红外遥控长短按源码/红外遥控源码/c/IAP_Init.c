#include "H/Function_Init.H"

//#define IapROM  0x00	  //0x00��ѡ��ROM������  0x02��ѡ��EEPROM������
//#define IapEPPROM  0x02	  //0x00��ѡ��ROM������  0x02��ѡ��EEPROM������
unsigned char code *IapAddr = 0x00;

void IAPWrite(uint Addr,uchar Value,uchar IAPArea);
uchar IAPRead(uint Addr,uchar IAPArea);
uchar IapReadData = 0x00;   //��Ŷ�ȡ��IAP����

/*****************************************************
*�������ƣ�void IAP_Test(uchar Address,uchar IAPArea)
*�������ܣ�IAP����
*��ڲ�����void
*���ڲ�����Address,IAPArea
*****************************************************/
void IAP_Test(uint Address,uchar IAPArea)
{
	IAPWrite(Address,0xff,IAPArea);
	IapReadData = IAPRead(Address,IAPArea);
	IAPADE = 0x00;       //IAPָ��ָ��ROM��
	while(1)
	{
		if(IapReadData == 0xff)
		{
			P20 = ~P20;
		}
		else
		{
			P21 = ~P21;
		}
	}
}

/*****************************************************
*�������ƣ�void IAPWrite(uchar Addr,uchar Value,uchar IAPArea)
*�������ܣ�IAP��ʼ��
*��ڲ�����void
*���ڲ�����Addr,Value,IAPArea
*****************************************************/
//IAPд����
void IAPWrite(uint Addr,uchar Value,uchar IAPArea)
{	
	EA = 0;
	IAPDAT = Value;      //д������Data
	IAPADH = ((Addr>>8)&0X7F);   //д���ַ�ĸ�5λ
	IAPADL = Addr;               //д���ַ�ĵ�8λ
	
	IAPADE = IAPArea;  //IAPArea=0x00��ѡ��ROM������  IAPArea=0x02��ѡ��EEPROM������
	IAPKEY = 240;		   //IAP������������ʱ��
	IAPCTL = 0x06;     //CPU hold timeΪ2ms��д���������
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	IAPADE = 0x00;      //MOVCָ��ROM
	EA = 1;
}
/*****************************************************
*�������ƣ�uchar IAPRead(uchar Addr,uchar IAPArea)
*�������ܣ�IAP��ʼ��
*��ڲ�����void
*���ڲ�����Addr,IAPArea
*****************************************************/
uchar IAPRead(uint Addr,uchar IAPArea)
{
	uchar ReadValue = 0x00;
	EA = 0;
	IAPADE = IAPArea;
	ReadValue = *(IapAddr+Addr); //��ȡ������
	IAPADE = 0x00;               //MOVCָ��ROM
	EA = 1;
	return ReadValue;
}
