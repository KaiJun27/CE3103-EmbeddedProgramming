#ifndef __song_H
#define __song_H
#include "sys.h"
#include "system.h"
#include "buzzer.h"
#include "button.h"

/*
#define BUZZER_TASK_PRIO		3     
#define BUZZER_STK_SIZE 		128   


#define BUZZER_PORT GPIOB
#define B_PIN GPIO_Pin_10
#define BUZZER PBout(10) 
*/

static u32 notes[] = {
	 2272, // A - 440 Hz
	 2024, // B - 494 Hz
	 3816, // C - 262 Hz
	 3401, // D - 294 Hz
	 3030, // E - 330 Hz
	 2865, // F - 349 Hz
	 2551, // G - 392 Hz
	 1136, // a - 880 Hz
	 1012, // b - 988 Hz
	 1912, // c - 523 Hz
	 1703, // d - 587 Hz
	 1517, // e - 659 Hz
	 1432, // f - 698 Hz
	 1275 // g - 784 Hz
};

static u8* song =
(uint8_t*)"e2,d2,e2,d2,e2,B2,d2,c2,A2_C2,E2,A2,B2_E2,G2,B2,c4_E2,e2,d2,e2,d2,e2,B2,d2,c2,A2_C2,E2,A2,B2_E2,c2,B2,A4";

static uint32_t getNote(uint8_t ch);

static uint32_t getDuration(uint8_t ch);

static uint32_t getPause(uint8_t ch);

static void playNote(uint32_t note, uint32_t durationMs);

static void playSong(uint8_t *song);

void song_task(void *pvParameters);
#endif
