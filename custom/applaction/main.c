#include "includes.h"
#include "app.h"

osThreadId_t DEMOT;	//线程ID标识
osThreadAttr_t THREAD_CFG;	//线程配置结构体

void demo(void *argument);

int cm_opencpu_entry(char * param)
{
	DEMOT = osThreadNew(demo,NULL,&THREAD_CFG);
	return 0;
}


void demo(void *argument)
{
	
}