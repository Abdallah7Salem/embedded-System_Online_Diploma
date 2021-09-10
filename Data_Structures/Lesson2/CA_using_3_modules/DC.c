/*
 * DC.c
 *
 *  Created on: Sep 9, 2021
 *      Author: Abdallah
 */

#include "DC.h"

//variables
int DC_speed = 0 ;

//STATE Pointer to function take nothing return void
void (*DC_state)();

void DC_init ()
{
	//int PWM
	printf("DC_init \n");

}

void DC_motor (int s)
{
	DC_speed = s ;
	DC_state = STATE(DC_busy);
	printf("CA -------speed=%d---------> DC \n", DC_speed);


}

STATE_define (DC_idle)
{
	//state_Name
	DC_state_id = DC_idle ;

	//state_Action
	//call PWM to make speed = DC_speed

	printf("DC_idle State: distance = %d \n", DC_speed);

}

STATE_define (DC_busy)
{
	//state_Name
	DC_state_id = DC_busy ;

	//state_Action
	//call PWM to make speed = DC_speed

	DC_state = STATE(DC_idle);

	printf("DC_busy State: distance = %d \n", DC_speed);
}


