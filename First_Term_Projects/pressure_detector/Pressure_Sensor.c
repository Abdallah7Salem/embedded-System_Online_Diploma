/*
 * Pressure_Sensor.c
 *
 *  Created on: Sep 16, 2021
 *      Author: Abdallah
 */

#include "Pressure_Sensor.h"
#include "driver.h"

void (*PS_ptr)();
extern int pressure_Val;
extern void Set_Pressure_Val();

void PS_init()
{
	GPIO_INITIALIZATION();
	Reading_State();
}

// Here the sensor reads the values
void Reading_State()
{
	PS_ptr = Reading_State ;
	pressure_Val = Get_Pressure_Val() ;
	Set_Pressure_Val() ;
}
