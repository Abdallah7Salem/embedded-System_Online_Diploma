/*
 * UART_ATmega32.h
 *
 * Created: 2/23/2022 7:44:01 AM
 *  Author: Abdallah
 */ 


#ifndef UART_ATMEGA32_H_
#define UART_ATMEGA32_H_

/* ========================== Includes ========================== */
#include <avr/io.h>
#include "Utils.h"
#include "Platform_Types.h"

/* ========================== Definitions ============================*/
#define DefaultStop		'\r'

/* ========================== Functions Prototypes ============================= */
void UART_Init(void);
void UART_Send(uint8_t data);
uint8_t UART_Receive(void);
void UART_Send_Number(uint32_t Number);
uint32_t UART_Receive_Number(void);
void UART_Send_String(uint8_t *string_pointer);
void UART_Receive_String(uint8_t *Buffer);



#endif /* UART_ATMEGA32_H_ */