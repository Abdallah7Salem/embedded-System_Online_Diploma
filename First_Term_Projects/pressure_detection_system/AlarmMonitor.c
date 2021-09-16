/*
 * AlarmMonitor.c
 *
 *  Created on: Sep 16, 2021
 *      Author: Abdallah
 */

#include "AlarmMonitor.h"
int i; // interator for the loop
void (*AM_ptr)();

/* Definition Of Functions */

// high pressure detect
void high_Pressure_Detect()
{
	AM_ptr = alarm_On_State ;
}

// alarm on state
void alarm_On_State()
{
	for (i = 0; i < 500; i++) // duration of blinking in high pressure
	{
		start_Alarm();
		Delay(10000);
		stop_Alarm();
		Delay(10000);

	}
	AM_ptr = alarm_Off_State ;
}

// alarm off state
void alarm_Off_State()
{
	stop_Alarm();
	AM_ptr = alarm_Off_State ;
}
