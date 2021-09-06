/*
 * lifo.h
 *
 *  Created on: Sep 3, 2021
 *      Author: Abdallah
 */

#ifndef LIFO_H_
#define LIFO_H_


// type definitions

typedef unsigned int uint32_t;

typedef struct
{
	unsigned int length ;
	unsigned int count ;
	unsigned int* base ;
	unsigned int* head ;
}Stack_struct;


typedef enum
{
	Stack_no_error ,
	Stack_full ,
	Stack_empty ,
	Stack_Null ,
}Stack_status;

// APIs
Stack_status Stack_init (Stack_struct* stack , unsigned int* buf, unsigned int length);
Stack_status Stack_Push_item (Stack_struct* lBuf , unsigned int item);
Stack_status Stack_Pop_item (Stack_struct* lBuf , unsigned int* item);


#endif /* LIFO_H_ */
