/*
 * state.h
 *
 *  Created on: Sep 9, 2021
 *      Author: Abdallah
 */

#ifndef STATE_H_
#define STATE_H_


//Automatic State Function Generated

#include "stdio.h"
#include "stdlib.h"

#define STATE_define(_statFUN_)     void ST_##_statFUN_()
#define STATE(_statFUN_)            ST_##_statFUN_

STATE_define(CA_waiting);

// States Connection
void US_Set_distance (int d);
void DC_motor (int s);

#endif /* STATE_H_ */
