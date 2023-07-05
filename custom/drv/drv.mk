#uart
DRV_UART_DIR := custom/drv
OC_FILES +=  $(DRV_UART_DIR)/uart/uart.c
INC      += -I'$(DRV_UART_DIR)/uart'