/*
 * lifo.c
 *
 *  Created on: Sep 3, 2021
 *      Author: Abdallah
 */
#include "lifo.h"
#include <stddef.h> // For NULL definition

// APIs
Stack_status Stack_init (Stack_struct* stack , uint32_t* buffer, unsigned int length)
{
	if (buffer == NULL)
		return Stack_Null ;

	stack -> base = buffer ;
	stack -> head = buffer ;
	stack -> length = length ;
	stack -> count = 0 ;

	return Stack_no_error ;
}

Stack_status Stack_Push_item (Stack_struct* stack , uint32_t item)
{
	// check stack is valid
	// if base, head or stack itself aren't found, it returns Stack_Null
	if (!stack -> base || !stack -> head || !stack)
		return Stack_Null ;

	// check stack is full ?
	// if (stack -> head >= (stack -> base + (stack -> length * 4)))
	if (stack -> count == stack -> length)
		return Stack_full ;

	// add value
	*(stack -> head) = item ;
	stack -> head++ ;
	stack -> count++ ;

	return Stack_no_error ;

}
Stack_status Stack_Pop_item (Stack_struct* stack , unsigned int* item)
{
	// check stack is valid
	if (!stack -> base || !stack -> head || !stack)
		return Stack_Null ;

	// check stack is empty ?
	if (stack -> count == 0)
		return Stack_empty ;

	stack -> head-- ;
	*item = *(stack -> head) ;
	stack -> count-- ;
	return Stack_no_error ;

}

