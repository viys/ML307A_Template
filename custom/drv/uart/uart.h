#ifndef __UART_H
#define __UART_H

#include "cm_uart.h"

/**
 * @brief 打开串口设备
 * 
 * @param dev 串口设备号
 * @param baudrate 波特率
 * @param event 回调函数
 */
void uart_open(cm_uart_dev_e dev,int baudrate,void* event);

#endif // !__UART_H