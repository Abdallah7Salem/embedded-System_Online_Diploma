/*
 * Pressure_Sensor.h
 *
 *  Created on: Sep 16, 2021
 *      Author: Abdallah
 */

#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

void PS_init();
void Reading_State();
extern void (*PS_ptr)();

#endif /* PRESSURE_SENSOR_H_ */
