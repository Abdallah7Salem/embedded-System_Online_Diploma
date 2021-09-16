/*
 * MainAlgorithm.c
 *
 *  Created on: Sep 16, 2021
 *      Author: Abdallah
 */

#include "MainAlgorithm.h"
#define THRESHOLD 20

// pressure_Val is declared in ..... file
extern int pressure_Val;

// declaration of pointer to function
void (*MA_ptr)();

// definition of set_Pressure_Val
void set_Pressure_Val()
{
	MA_ptr = high_Pressure_State ;
}

// definition of high_Pressure_State
void high_Pressure_State()
{
	if (pressure_Val <= THRESHOLD)
	{
		MA_ptr = high_Pressure_State ;
	}
	else
	{
		high_Pressure_Detect();
		MA_ptr = high_Pressure_State ;
	}
}

