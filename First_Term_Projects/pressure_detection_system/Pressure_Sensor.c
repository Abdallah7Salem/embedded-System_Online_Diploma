/*
 * Pressure_Sensor.c
 *
 *  Created on: Sep 16, 2021
 *      Author: Abdallah
 */

#include "Pressure_Sensor.h"
#include "driver.h"

// declare the pointer to function e.g. reading_State
void (*PS_ptr)();

// pressure_Val is defined in main.c file
extern int pressure_Val;

// set_Pressure_Val is defined in MainAlgorih.c file
extern void set_Pressure_Val();

void PS_init()
{
	GPIO_INITIALIZATION();
	reading_State();
}

// definition of reading_State function
void reading_State()
{
	PS_ptr = reading_State ;
	pressure_Val = get_Pressure_Val() ;
	set_Pressure_Val() ;
}
