#include "display.h"
#include "tm1638.h"
#include "ir1838.h"

/**************************************************
*�������ƣ�IR_Display	
*�������ܣ���������������ʾ
*��ڲ�������	        	
*���ڲ�������
*����˵����
**************************************************/
void IR_Display(void)
{
	uchar IR_Value; 
	IR_Value = IR_ReadKey();
    if(IR_Value == 3)
    {
       P27 = 1;
    }
    else if(IR_Value == 4)
    {
       P25 = 1;
    }
    else if()
    {
       P25 = 0;
       P27 = 0;
    }
	//TM1638_DisplayOnlyNumber(IR_Value, IR_Value, IR_Value, IR_Value);	
}