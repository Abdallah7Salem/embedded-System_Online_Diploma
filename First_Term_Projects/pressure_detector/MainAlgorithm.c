/*
 * MainAlgorithm.c
 *
 *  Created on: Sep 16, 2021
 *      Author: Abdallah
 */

#include "MainAlgorithm.h"
#define THRESHOLD 20

extern int pressure_Val;
void (*MA_ptr)();


void Set_Pressure_Val()
{
	MA_ptr = Normal_Pressure_State ;
}


void Normal_Pressure_State()
{
	if (pressure_Val <= THRESHOLD)
	{
		MA_ptr = Normal_Pressure_State ;
	}
	else
	{
		High_Pressure_Detected();
		MA_ptr = Normal_Pressure_State ;
	}
}

