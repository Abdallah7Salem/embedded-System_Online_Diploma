/*
 * keypad.c
 *
 *  Created on: Nov 15, 2021
 *      Author: Abdallah
 */


#include "keypad.h"

/* ============= Global Arrays to Store Rows and Columns of Keypad ============== */
int Keypad_Row[] = {R0, R1, R2, R3}; //rows of the keypad
int Keypad_Col[] = {C0, C1, C2, C3};//columns


void Keypad_init(){
	// ALL ROWS and COLUMNS are OUTPUT

	// Row 0
	PinCfg.GPIO_Pin_Number = R0;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	// Row 1
	PinCfg.GPIO_Pin_Number = R1;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	// Row 2
	PinCfg.GPIO_Pin_Number = R2;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	// Row 3
	PinCfg.GPIO_Pin_Number = R3;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	// Column 0
	PinCfg.GPIO_Pin_Number = C0;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	// Column 1
	PinCfg.GPIO_Pin_Number = C1;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	// Column 2
	PinCfg.GPIO_Pin_Number = C2;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	// Column 3
	PinCfg.GPIO_Pin_Number = C3;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	MCAL_GPIO_WritePort(KEYPAD_PORT, 0xFF);
}

// Function to get the key pressed on the Keypad
// And return it as char to send it to LCD
char Keypad_getkey(){

	int i,j;  // Two counters for Two loops

	// First loop : It determines the current column
	for (i = 0; i < 4; i++){

		/* --- All Column PINS are SET to 1, Once a PIN is pressed it will RESET --- */
		// Set Column 0
		MCAL_GPIO_WritePin(KEYPAD_PORT, Keypad_Col[0], GPIO_PIN_SET);
		// Set Column 1
		MCAL_GPIO_WritePin(KEYPAD_PORT, Keypad_Col[1], GPIO_PIN_SET);
		// Set Column 2
		MCAL_GPIO_WritePin(KEYPAD_PORT, Keypad_Col[2], GPIO_PIN_SET);
		// Set Column 3
		MCAL_GPIO_WritePin(KEYPAD_PORT, Keypad_Col[3], GPIO_PIN_SET);
		// Set Column i

		// This line of code CHECKS for the PIN pressed
		MCAL_GPIO_WritePin(KEYPAD_PORT, Keypad_Col[i], GPIO_PIN_RESET);

		// Second loop : It determines the current row
		// within the current column
		for(j = 0; j < 4; j++){
			// Read PIN Pressed
			if (MCAL_GPIO_ReadPin(KEYPAD_PORT, Keypad_Row[j]) == 0)
			{
				while(MCAL_GPIO_ReadPin(KEYPAD_PORT, Keypad_Row[j]) == 0);  // single pressing
				switch(i){
					case (0):
						if (j == 0) return '7';
						else if (j == 1) return '4';
						else if (j == 2) return '1';
						else if (j == 3) return '?';
						break;
					case (1):
						if (j == 0) return '8';
						else if (j == 1) return '5';
						else if (j == 2) return '2';
						else if (j == 3) return '0';
						break;
					case (2):
						if (j == 0) return '9';
						else if (j == 1) return '6';
						else if (j == 2) return '3';
						else if (j == 3) return '=';
						break;
					case (3):
						if (j == 0) return '/';
						else if (j == 1) return '*';
						else if (j == 2) return '-';
						else if (j == 3) return '+';
						break;
				}
			}
		}
	}
	return 'A';
}
