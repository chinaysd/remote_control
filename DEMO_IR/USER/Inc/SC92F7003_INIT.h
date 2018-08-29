//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	: SC92F7003_INIT.h
//	����		: 
//	ģ�鹦��	: SC92F7003_INIT�̼��⺯��ͷ�ļ�
//	�ֲ������б�:
//  ����������: 2018/3/18
// 	�汾		: V1.0 
//  ˵��        �������ļ���������SC92F8003  
//*************************************************************

#ifndef _SC92F7003_INIT_H_
#define _SC92F7003_INIT_H_

#include "SC92F7003_C.H"

#define     __I     volatile const   //ֻ���ڣ������
#define     __O     volatile         //ֻд�ڣ������
#define     __IO    volatile         //�ɶ���д�����������
#define enableInterrupts()    EA = 1 //ʹ�����ж�
#define disableInterrupts()   EA = 0 //�ر����ж�
#define   uchar           int8_t
#define   uint            int16_t
#define   ulong           int32_t

typedef   signed char     int8_t;
typedef   signed short    int16_t;
typedef   signed long     int32_t;

typedef unsigned char     uint8_t;
typedef unsigned short    uint16_t;
typedef unsigned long     uint32_t;

typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus, BitStatus, BitAction;
typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;
typedef enum {GPIO0 = 0,GPIO1,GPIO2}GPIO_TypeDef;


#endif

/******************* (C) COPYRIGHT 2018 SinOne Microelectronics *****END OF FILE****/
