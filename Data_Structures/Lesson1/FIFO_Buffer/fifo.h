/*
 * fifo.h
 *
 *  Created on: Sep 7, 2021
 *      Author: Abdallah
 */

#ifndef FIFO_H_
#define FIFO_H_
#include <stdio.h>
#include <stdint.h>

//USER Configuration
//select the element type (uint8_t , uint26_t , uint32_t , ... )
#define ELEMENT_TYPE uint8_t

//create buffer 1
#define width1 5
ELEMENT_TYPE uart_buffer[width1] ;

/*
//create buffer 2
#define width2 7
ELEMENT_TYPE buffer2[width2] ;
*/

//FIFO data types

typedef struct
{
	unsigned int length ;
	unsigned int count ;
	ELEMENT_TYPE* base ;
	ELEMENT_TYPE* head ;
	ELEMENT_TYPE* tail;
}FIFO_struct;

typedef enum
{
	FIFO_no_error ,
	FIFO_full ,
	FIFO_empty ,
	FIFO_null
}FIFO_status;

// FIFO APIs
FIFO_status FIFO_init (FIFO_struct* fifo, ELEMENT_TYPE* uart_buffer, uint32_t length);
FIFO_status FIFO_enqueue (FIFO_struct* fifo, ELEMENT_TYPE item);
FIFO_status FIFO_dequeue (FIFO_struct* fifo, ELEMENT_TYPE* item);
FIFO_status FIFO_IS_FULL (FIFO_struct* fifo);
void FIFO_print (FIFO_struct* fifo);

#endif /* FIFO_H_ */
