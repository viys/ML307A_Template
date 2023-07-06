#ifndef __APP_H
#define __APP_H

#include "includes.h"
#include "uart.h"

#define FlagSET(Flag,bit)	(Flag |= (bit))		//Flag置位
#define FlagCLR(Flag,bit)	(Flag &= ~(bit))	//Flag清位
#define FlagGET(Flag,bit)	(Flag & (bit))		//Flag获取

/**
 * @brief 进程创建函数
 * 
 * @param name 进程名
 * @param func 进程函数
 * @param priority 优先级
 * @param stacksize 栈空间
 * @return osThreadId_t 
 */
osThreadId_t osThreadCreat(const char * name,osThreadFunc_t func,osPriority_t priority,uint32_t stacksize);

/**
 * @brief 延迟函数
 * 
 * @param ms 要是5的整数倍,最小为5ms
 */
void osDelayMs(uint32_t ms);

/**
 * @brief 进程1
 * 
 * @param argument 
 */
void task1(void *argument);

/**
 * @brief 进程1
 * 
 * @param argument 
 */
void task2(void *argument);

#endif // !__APP_H