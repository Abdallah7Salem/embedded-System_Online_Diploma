/*
 * AlarmMonitor.h
 *
 *  Created on: Sep 16, 2021
 *      Author: Abdallah
 */

#ifndef ALARMMONITOR_H_
#define ALARMMONITOR_H_

#include "AlarmActuator.h"
#include "driver.h"

//Declaration of function of AM
void high_Pressure_Detect();
void alarm_Off_State();
void alarm_On_State();

//see alarm actuator functions
extern void start_Alarm();
extern void stop_Alarm();

/*pointer to function take
 * nothing return void .
 * pointer is defined in the .c file
 */
extern void (*AM_ptr)();

#endif /* ALARMMONITOR_H_ */
