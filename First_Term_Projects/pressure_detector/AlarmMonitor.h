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
void High_Pressure_Detected();
void Turn_Off_Alarm();
void Turn_On_Alarm();

extern void Start_Alarm();
extern void Stop_Alarm();
extern void (*AM_ptr)();

#endif /* ALARMMONITOR_H_ */
