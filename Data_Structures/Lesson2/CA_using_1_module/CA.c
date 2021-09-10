/*
 * CA.c
 *
 *  Created on: Sep 9, 2021
 *      Author: Abdallah
 */

#include "CA.h"

//variables
int CA_speed = 0 ;
int CA_distance = 0 ;
int CA_threshold = 50 ;

//STATE Pointer to function take nothing return void
void (*CA_state)();
int Ultrasonic_Get_Distance_Random (int l, int r, int count);


STATE_define (CA_waiting)
{
	//state_Name
	CA_state_id = CA_waiting ;

	//state_Action
	CA_speed = 0 ;

	//Event_Check
	//Ultrasonic_Get_Distance(CA_distance)
	CA_distance = Ultrasonic_Get_Distance_Random (45, 55, 1) ;
	(CA_distance <= CA_threshold)? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving)) ;
	printf("CA_waiting State: distance = %d  Speed = %d \n", CA_distance, CA_speed);

}

STATE_define (CA_driving)
{
	//state_Name
	CA_state_id = CA_driving ;

	//state_Action
	CA_speed = 30 ;

	//Event_Check
	//Ultrasonic_Get_Distance(CA_distance)
	CA_distance = Ultrasonic_Get_Distance_Random (45, 55, 1) ;
	(CA_distance <= CA_threshold)? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving)) ;
	printf("CA_driving State: distance = %d  Speed = %d \n", CA_distance, CA_speed);
}

int Ultrasonic_Get_Distance_Random (int l, int r, int count)
{
		// this will generate random number in range l and r
		int i, rand_num = 0;
		for (i = 0; i < count; i++)
		{
			rand_num = (rand() % (r - l + 1)) + l ;
		}

			return rand_num ;

}

