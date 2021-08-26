#include "show.h"

void show_task(void *pvParameters)
{
   u32 lastWakeTime = getSysTickCnt();
   while(1)
    {	

			vTaskDelayUntil(&lastWakeTime, F2T(RATE_50_HZ));

			oled_show();    
    }
}  

void oled_show(void)
{  
     //To DO
	 
	 
	 //call some function in oled to display something
	int count = 0;
	while(1){
		OLED_ShowString(0,0, "Kai Jun");
		OLED_ShowNumber(0,28, count, 5, 15);
		count++;
		delay_ms(1000);
		OLED_Refresh_Gram(); //refresh the OLED RAM
		if(count == 60) count = 0;
	}
	
   
	 //OLED_Refresh_Gram(); //refresh the OLED RAM

	  		
	}
