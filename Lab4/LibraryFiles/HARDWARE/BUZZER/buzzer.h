#ifndef __buzzer_H
#define __buzzer_H
#include "sys.h"
#include "system.h"

//Buzzer Port definition
#define BUZZER_TASK_PRIO		3     
#define BUZZER_STK_SIZE 		128   


#define BUZZER_PORT GPIOB
#define B_PIN GPIO_Pin_10
#define BUZZER PBout(10) 
/*----------------------------------*/

void BUZZER_Init(void);  
void buzzer_task(void *pvParameters);
#endif
