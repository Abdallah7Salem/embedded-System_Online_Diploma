/*
 * main.c
 *
 *  Created on: Sep 16, 2021
 *      Author: Abdallah
 */

#include "driver.h"
#include "Pressure_Sensor.h"
#include "MainAlgorithm.h"
#include "AlarmActuator.h"
#include "AlarmMonitor.h"

int pressure_Val;

int main (){
	// GPIO_INITIALIZATION();

	PS_ptr = PS_init ;
	MA_ptr = high_Pressure_State ;
	AM_ptr = alarm_Off_State ;

	while (1)
	{
		//Implement your Design
		(*PS_ptr)();  // pointer to pressure sensor module
		(*MA_ptr)();  // pointer to main algorithm module
		(*AM_ptr)();  // pointer to alarm monitor module
	}

}
