#include "app.h"

osThreadId_t DEMOT;	//线程ID标识
osThreadAttr_t THREAD_CFG;	//线程配置结构体

void demo(void *argument);

int cm_opencpu_entry(char * param)
{
	uint8_t buff[10]={'1','2','3','4','5','6','7','8','9','c'};
	// DEMOT = osThreadNew(demo,NULL,&THREAD_CFG);
	uart_open(CM_UART_DEV_0,CM_UART_BAUDRATE_115200,demo);

	while (1)
	{
		osDelay(1000);
		cm_uart_write(CM_UART_DEV_0,buff,10,100);
	}
	
	return 0;
}


void demo(void *argument)
{
	
}