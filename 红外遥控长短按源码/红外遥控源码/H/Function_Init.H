#ifndef _Function_Init_H_
#define _Function_Init_H_

#include "SC92F732x_C.H"
#include "intrins.H"
#define uchar unsigned char
#define uint unsigned int

#define IapROM  0x00	  //0x00：选择ROM区操作  0x02：选择EEPROM区操作
#define IapEPPROM  0x02	  //0x00：选择ROM区操作  0x02：选择EEPROM区操作

void IO_Init(void);
void Timer_Init(void);
void EX_Init(void);
void IR1838Processing(void);
uchar IR_ReadKey(void);
/*****************************************
说明：选择测试IC
*****************************************/
#define SC92F7323  0
#define SC92F7322  1
#define SC92F7321  2
#define SC92F7320  3

#define IC_MODEL  SC92F7320

#endif