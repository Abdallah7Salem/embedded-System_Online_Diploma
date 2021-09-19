/*
 * AlarmMonitor.c
 *
 *  Created on: Sep 16, 2021
 *      Author: Abdallah
 */

#include "AlarmMonitor.h"
void (*AM_ptr)();

void High_Pressure_Detected()
{
	AM_ptr = Turn_On_Alarm ;
}

void Turn_On_Alarm()
{
	Start_Alarm();
	Delay(30000);
	Stop_Alarm();

	AM_ptr = Turn_Off_Alarm ;
}

void Turn_Off_Alarm()
{
	Stop_Alarm();
	AM_ptr = Turn_Off_Alarm ;
}
