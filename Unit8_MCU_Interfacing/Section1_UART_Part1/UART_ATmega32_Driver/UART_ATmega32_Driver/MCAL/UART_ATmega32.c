/*
 * UART_ATmega32.c
 *
 * Created: 2/23/2022 7:43:46 AM
 *  Author: Abdallah
 */ 

#include "UART_ATmega32.h"

void UART_Init(void)
{
	/* ################### BaudRate ################# */
	UBRRL = 51;												// BaudRate to make the UART work on a speed of 9600 
	CLEARBIT(UCSRA, U2X);									// To make the UART work on the normal speed mode 
	
	/* ################### Frame #################### */
	/* No parity Mode
	 * Data --> 8-bit ( Initial value by default )
	 */
	
	/* ################### Transmitter Enable ################ */
	SETBIT(UCSRB, TXEN);
	
	/* ################### Receiver Enable #################### */
	SETBIT(UCSRB, RXEN);
	
}

void UART_Send(uint8_t data)
{
	while(!READBIT(UCSRA, UDRE));								// Blocking till the UDRE register becomes empty
	UDR = data;
}

uint8_t UART_Receive(void)
{
	while(!READBIT(UCSRA, RXC));								// Blocking till the RXC ( Receive Completed ) flag is empty
	return UDR;
}

void UART_Send_Number(uint32_t Number)
{
	uint8_t *p = &Number;
	UART_Send(p[0]);
	UART_Send(p[1]);
	UART_Send(p[2]);
	UART_Send(p[3]);
}

uint32_t UART_Receive_Number(void)
{
	uint32_t Number;
	uint8_t *p = &Number;
	p[0] = UART_Receive();
	p[1] = UART_Receive();
	p[2] = UART_Receive();
	p[3] = UART_Receive();
	return Number;
}

void UART_Send_String(uint8_t *string_pointer)
{
	uint8_t loop_counter;
	for (loop_counter = 0; loop_counter <= string_pointer[loop_counter], loop_counter++)
	{
		UART_Send(string_pointer[loop_counter]);
	}
	UART_Send(DefaultStop);
}

void UART_Receive_String(uint8_t *Buffer)
{
	uint8_t i = 0;
	Buffer[i] = UART_Receive();
	while(Buffer[i] != DefaultStop)
	{
		i++;
		Buffer[i] = UART_Receive();
	}
	Buffer[i] = '\0';
}