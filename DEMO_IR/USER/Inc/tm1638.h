#ifndef _TM1638_H_
#define _TM1638_H_
#include "SC92F7003_INIT.h"


void SendData(uchar dat);	
void SendCommand(uchar Command);
void TM1638_Init(void);
void TM1638_DisplayOnlyNumber(uchar COM1,uchar COM2,uchar COM3,uchar COM4);

#endif