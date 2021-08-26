#include "system.h"

#define START_TASK_PRIO	4
#define START_STK_SIZE 256
TaskHandle_t StartTask_Handler;
void start_task(void *pvParameters);
TimerHandle_t softwareTimer_Handler;

int main(void){
	
	systemInit();
	
	softwareTimer_Handler = xTimerCreate("led_task", pdMS_TO_TICKS(1000), pdTRUE, (void*)0, led_task);
	
	xTaskCreate(	(TaskFunction_t		) start_task,
								(const char*			) "start_task",
								(uint16_t					) START_STK_SIZE,
								(void*						) NULL,
								(UBaseType_t			) START_TASK_PRIO,
								(TaskHandle_t*		) &StartTask_Handler);
								
	vTaskStartScheduler();
}

void start_task(void *pvParameters){
	
	taskENTER_CRITICAL();
	
	//xTaskCreate (led_task, "led_task", LED_STK_SIZE, NULL, LED_TASK_PRIO, NULL);
	
	//xTaskCreate (buzzer_task, "buzzer_task", BUZZER_STK_SIZE, NULL, BUZZER_TASK_PRIO, NULL);
	
	//xTaskCreate (show_task, "show_task", SHOW_STK_SIZE, NULL, SHOW_TASK_PRIO, NULL);
	
	xTaskCreate (song_task, "song_task", BUZZER_STK_SIZE, NULL, 3, NULL);
	
	xTimerStart(softwareTimer_Handler, pdMS_TO_TICKS(0));
	
	xTaskCreate	(uart_sendData, "send data", UART_STK_SIZE, NULL, 5, NULL);
	
	vTaskDelete(StartTask_Handler);
	
	taskEXIT_CRITICAL();
}
