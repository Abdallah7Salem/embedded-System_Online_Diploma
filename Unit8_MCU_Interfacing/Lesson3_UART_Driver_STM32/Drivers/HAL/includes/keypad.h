/*
 * keypad.h
 *
 *  Created on: Nov 15, 2021
 *      Author: Abdallah
 */

#ifndef KEYPAD_DRIVER_KEYPAD_H_
#define KEYPAD_DRIVER_KEYPAD_H_



/* ==================== Includes ======================== */
#include "STM32F103X6.h"
#include "STM32_F103C6_GPIO_Driver.h"

/* ==================== Macros Definitions ============== */

// We connected Keypad to PortB
#define KEYPAD_PORT		GPIO_PORTB  // Casted Address

// ==== ROWS OF KEYPAD ====
#define R0 				GPIO_PIN_0
#define R1 				GPIO_PIN_1
#define R2				GPIO_PIN_3
#define R3 				GPIO_PIN_4

// ==== COLUMNS OF KEYPAD ====
#define C0 				GPIO_PIN_5
#define C1 				GPIO_PIN_6
#define C2 				GPIO_PIN_7
#define C3 				GPIO_PIN_8


void Keypad_init(void);
char Keypad_getkey(void);

/* ============= Global Variable ================= */
GPIO_PinConfig_t PinCfg;


#endif /* KEYPAD_DRIVER_KEYPAD_H_ */
