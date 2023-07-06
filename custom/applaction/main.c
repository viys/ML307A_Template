#include "app.h"

osThreadId_t ThreadIDT;	//线程ID标识
osThreadAttr_t THREAD_CFG;	//线程配置结构体


int cm_opencpu_entry(char * param)
{
	uart_open(CM_UART_DEV_0,CM_UART_BAUDRATE_115200,u0_callback);
	u0_printf("ML307A Start\r\n");

	/* 创建进程task1 */
	osThreadCreat("task1",task1,5,1024);
	osThreadCreat("task2",task2,5,1024);
	return 0;
}

