/*
 * MainAlgorithm.h
 *
 *  Created on: Sep 16, 2021
 *      Author: Abdallah
 */

#ifndef MAINALGORITHM_H_
#define MAINALGORITHM_H_

// prototype of functions 2
void high_Pressure_State();
void set_Pressure_Val();

/* see pointers of AM ( alarm monitor )
 * and MA ( main algorithm )
 */
extern void (*AM_ptr)(); // declared in AlarmMonitor.c
extern void (*MA_ptr)(); // declared in MainAlgorithm.c

/* see function high pressure detect
 * declared in AlarmMonitor.c
 */
extern void high_Pressure_Detect();

#endif /* MAINALGORITHM_H_ */
