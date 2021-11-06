/*
 * keypad.h
 *
 * Created: 11/6/2021 12:28:21 PM
 *  Author: Abdallah
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

// CPU Frequency
#define F_CPU 1000000UL

/* ============ Includes ========= */
#include "MemoryMap.h"
#include <util/delay.h>

/* =========== Connections and Ports Definitions ========= */

// Defining four rows of the Keypad
#define R0  0
#define R1  1
#define R2  2
#define R3  3

// Defining four columns of the Keypad
#define C0  4
#define C1  5
#define C2  6
#define C3  7

// Connect Keypad Data to PortD
#define KEYPAD_PORT_DATA_R        PORTD

// Connect Keypad DDR to DDRD
#define KEYPAD_PORT_DDR_R          DDRD

// Connect Keypad PIN TO PIND 
#define KEYPAD_PORT_PIN_R          PIND


/* =============== Functionos Prototypes ============ */
void keypad_init(void);
char keypad_getchar(void);

#endif /* KEYPAD_H_ */