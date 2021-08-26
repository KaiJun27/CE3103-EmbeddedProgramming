#include "button.h"

void button_Init(void){
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE); //Enable APB Clock
	
	GPIO_InitStructure.GPIO_Pin = BTN_PIN;				//LED Pin
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	//Push pull output
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//50M
	GPIO_Init(BTN_PORT, &GPIO_InitStructure);			//Initialize LED GPIO
	//GPIO_SetBits(BTN_PORT,BTN_PIN);
}

