/*
 * S7_segment.c
 *
 *  Created on: Nov 16, 2021
 *      Author: Abdallah
 */

#include "S7_segment.h"

/* ============= Function Definition ============= */
void Init_7_segment (void)
{
	// We are connecting 7 segment to Port B from PB9 to PB15
	// We will Initialize the 7 PINS as Output

	//PB9 is Output push-pull : Speed 10 MHz
	PinCfg.GPIO_Pin_Number = GPIO_PIN_9;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIO_PORTB, &PinCfg);

	//PB10 is Output push-pull : Speed 10 MHz
	PinCfg.GPIO_Pin_Number = GPIO_PIN_10;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIO_PORTB, &PinCfg);

	//PB11 is Output push-pull : Speed 10 MHz
	PinCfg.GPIO_Pin_Number = GPIO_PIN_11;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIO_PORTB, &PinCfg);

	//PB12 is Output push-pull : Speed 10 MHz
	PinCfg.GPIO_Pin_Number = GPIO_PIN_12;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIO_PORTB, &PinCfg);

	//PB13 is Output push-pull : Speed 10 MHz
	PinCfg.GPIO_Pin_Number = GPIO_PIN_13;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIO_PORTB, &PinCfg);

	//PB14 is Output push-pull : Speed 10 MHz
	PinCfg.GPIO_Pin_Number = GPIO_PIN_14;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIO_PORTB, &PinCfg);

	//PB15 is Output push-pull : Speed 10 MHz
	PinCfg.GPIO_Pin_Number = GPIO_PIN_15;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIO_PORTB, &PinCfg);

}
