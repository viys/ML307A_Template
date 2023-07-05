#include "uart.h"

/**
 * @brief 打开串口设备
 * 
 * @param dev 串口设备号 CM_UART_DEV_X
 * @param baudrate 波特率 CM_UART_BAUDRATE_X
 * @param event 回调函数
 */
void uart_open(cm_uart_dev_e dev,int baudrate,void* event)
{
    cm_uart_cfg_t uart_cfg;
    
    /* 串口设备注册 */
    cm_uart_register_event(dev,event);

    /* 串口设备配置 */
    uart_cfg.baudrate = baudrate;
    uart_cfg.byte_size = CM_UART_BYTE_SIZE_8;
    uart_cfg.stop_bit = CM_UART_STOP_BIT_ONE;
    uart_cfg.flow_ctrl = CM_UART_FLOW_CTRL_NONE;
    uart_cfg.parity = CM_UART_PARITY_NONE;
    cm_uart_open(dev,&uart_cfg);
}

