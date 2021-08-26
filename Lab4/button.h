#ifndef __button_H
#define __button_H

#include "system.h"
#include "sys.h"

//Button Port definition
#define BTN_TASK_PRIO		3     
#define BTN_STK_SIZE 		128   


#define BTN_PORT GPIOD
#define BTN_PIN GPIO_Pin_8
#define BTN PDin(8) 

void button_Init(void);


#endif