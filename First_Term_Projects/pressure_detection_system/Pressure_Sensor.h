/*
 * Pressure_Sensor.h
 *
 *  Created on: Sep 16, 2021
 *      Author: Abdallah
 */

#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

// init pressure sensor
void PS_init();

// reading state of pressure sensor
void reading_State();

/* pointer to function
 * define in .c file */
extern void (*PS_ptr)();

#endif /* PRESSURE_SENSOR_H_ */
