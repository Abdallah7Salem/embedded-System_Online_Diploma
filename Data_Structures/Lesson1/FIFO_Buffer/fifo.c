/*
 * fifo.c
 *
 *  Created on: Sep 7, 2021
 *      Author: Abdallah
 */

#include "fifo.h"
#include <stddef.h>
FIFO_status FIFO_init (FIFO_struct* fifo, ELEMENT_TYPE* buffer, uint32_t length)
{
	if (buffer == NULL)
		return FIFO_null;

	fifo->base = buffer;
	fifo->head = buffer;
	fifo->tail = buffer;
	fifo->length = length;
	fifo->count = 0;

	return FIFO_no_error;
}

FIFO_status FIFO_enqueue (FIFO_struct* fifo, ELEMENT_TYPE item)
{
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;

	// FIFO is full ?
	 if (FIFO_IS_FULL (fifo) == FIFO_full )
		 return FIFO_full;

	 *(fifo->head) = item;
	 fifo->count++;

	 //Circular fifo
	 if (fifo->head == (fifo->base + (fifo->length * sizeof(ELEMENT_TYPE))))
		 fifo->head = fifo->base;
	 else
		 fifo->head++;

	 return FIFO_no_error;

}

FIFO_status FIFO_dequeue (FIFO_struct* fifo, ELEMENT_TYPE* item)
{
	if (!fifo->base || !fifo->head || !fifo-> tail)
		return FIFO_null;

	//check fifo is empty ?
	if (fifo->count == 0)
		return FIFO_empty;

	*item = *(fifo->tail) ;
	fifo->count--;

	//Circular fifo
	if (fifo->tail == (fifo->base + (fifo->length * sizeof(ELEMENT_TYPE))))
		fifo->tail = fifo->base ;
	else
		fifo->tail++ ;

	return FIFO_no_error ;
}

FIFO_status FIFO_IS_FULL (FIFO_struct* fifo)
{
	if (!fifo->head || !fifo->tail || !fifo->base)
		return FIFO_null;
	if (fifo->count == fifo->length)
		return FIFO_full;

	return FIFO_no_error;
}

void FIFO_print (FIFO_struct* fifo)
{
	ELEMENT_TYPE* temp ;
	int i ;
	if (fifo->count == 0)
	{
		printf("FIFO is empty \n");
	}
	else
	{
		temp = fifo->tail ;
		printf ("\n ===========fifo_print========\n");
		for (i = 0; i < fifo->count; i++)
		{
			printf("\t %X \n", *temp);
			temp++;
		}
		printf("============\n");
	}
}



