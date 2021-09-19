/*
 * AlarmActuator.c
 *
 *  Created on: Sep 16, 2021
 *      Author: Abdallah
 */

#include "AlarmActuator.h"
#include "driver.h"

void Start_Alarm()
{
	Set_Alarm_Actuator(1);
}

void Stop_Alarm()
{
	Set_Alarm_Actuator(0);
}

