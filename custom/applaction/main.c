#include "app.h"

osThreadId_t ThreadI_DT;   // 线程ID标识
osThreadAttr_t THREAD_CFG; // 线程配置结构体

int cm_opencpu_entry(char *param)
{
	uart_open(CM_UART_DEV_0, CM_UART_BAUDRATE_115200, u0_callback);
	u0_printf("ML307A Start\r\n");

	/* 创建互斥锁 */
	TASK_MT = osMutexNew(NULL);
	/* 创建信号量 */
	TASK_ST = osSemaphoreNew(1, 0, NULL);
	/* 创建进程 */
	osThreadCreat("task1", task1, 6, 1024);
	osThreadCreat("task2", task2, 5, 1024);
	osThreadCreat("task3", task3, 7, 1024);

	/* 创建定时器 */
	osTimerCreat("timer1",time1_callback,osTimerPeriodic);

	return 0;
}
