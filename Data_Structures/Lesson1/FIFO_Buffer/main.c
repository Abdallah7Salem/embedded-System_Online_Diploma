/*
 * main.c
 *
 *  Created on: Sep 7, 2021
 *      Author: Abdallah
 */

#include "fifo.h"

int main (void)
{
	FIFO_struct FIFO_UART ;
	ELEMENT_TYPE i, temp = 0 ;
	if (FIFO_init( &FIFO_UART , uart_buffer, 5) == FIFO_no_error)
		printf("fifo init ------ Done \n");

	for (i = 0; i < 7; i++)
	{
		printf("FIFO enqueue (%x) \n", i);
		if (FIFO_enqueue(&FIFO_UART, i) == FIFO_no_error)
			printf("\t fifo enqueue ------ Done \n");
		else
			printf("\t fifo enqueue ------ failed \n");
	}

	FIFO_print (&FIFO_UART);

	if (FIFO_dequeue(&FIFO_UART, &temp) == FIFO_no_error)
		printf("fifo dequeue (%x) ------ Done \n", temp);
	if (FIFO_dequeue(&FIFO_UART, &temp) == FIFO_no_error)
		printf("fifo dequeue (%x) ------ Done \n", temp);

	FIFO_print (&FIFO_UART);



	return 0;
}
