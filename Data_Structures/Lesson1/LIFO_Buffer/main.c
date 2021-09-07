/*
 * main.c
 *
 *  Created on: Sep 3, 2021
 *      Author: Abdallah
 */

#include <stdio.h>
#include "lifo.h"
#include <stdlib.h>

uint32_t buffer1 [5] ;
uint32_t buffer2 [5] ;


int main (void)
{
	Stack_struct uart_lifo , I2C_lifo ;
	// static allocation
	Stack_init(&uart_lifo, buffer1, 5) ;
	// dynamic allocation
	unsigned int* buffer2 = (unsigned int*) malloc (5 * sizeof(unsigned int));
	Stack_init(&I2C_lifo, buffer2, 5) ;

	unsigned int i ;

	for (i = 0; i < 7; i++)
	{
	  if(	Stack_Push_item(&uart_lifo, i) == Stack_no_error )
	  	  printf("UART_LIFO Push : %d \n", i);
	  else
		  printf("Couldn't push this item \n\n");
	}

	unsigned int temp ;
	for (i = 0; i < 7; i++)
	{
	  if(	Stack_Pop_item(&uart_lifo, &temp) == Stack_no_error)
		  printf("UART_LIFO Pop : %d \n", temp) ;
	  else
		  printf("Couldn't pop this item \n\n");
	}

	return 0;

}
