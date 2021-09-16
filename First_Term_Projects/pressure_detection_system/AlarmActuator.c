/*
 * AlarmActuator.c
 *
 *  Created on: Sep 16, 2021
 *      Author: Abdallah
 */

#include "AlarmActuator.h"
#include "driver.h"

// definition of start_Alarm function
void start_Alarm()
{
	set_Alarm_Actuator(1);
}

// definition of stop_Alarm function
void stop_Alarm()
{
	set_Alarm_Actuator(0);
}

