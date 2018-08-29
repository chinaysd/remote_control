//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: SC92F7003_INIT.h
//	作者		: 
//	模块功能	: SC92F7003_INIT固件库函数头文件
//	局部函数列表:
//  最后更正日期: 2018/3/18
// 	版本		: V1.0 
//  说明        ：本库文件亦适用于SC92F8003  
//*************************************************************

#ifndef _SC92F7003_INIT_H_
#define _SC92F7003_INIT_H_

#include "SC92F7003_C.H"

#define     __I     volatile const   //只读口，输入口
#define     __O     volatile         //只写口，输出口
#define     __IO    volatile         //可读可写，输入输出口
#define enableInterrupts()    EA = 1 //使能总中断
#define disableInterrupts()   EA = 0 //关闭总中断
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
