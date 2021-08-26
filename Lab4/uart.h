#ifndef __uart_H
#define __uart_H
#include "sys.h"
#include "system.h"

#define UART_TASK_PRIO 	5
#define UART_STK_SIZE 	128

void uart_init(u32 baudRate);
void uart_sendData(void);
void usart3_send(u8 data);
int USART3_IRQHandler(void);

#endif
