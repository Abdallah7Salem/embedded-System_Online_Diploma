/*
 * Task 2.c
 *
 * Created: 11/3/2021 2:10:02 PM
 * Author : Abdallah
 */ 

/* =========== Switch controlling LEDs Task ================ */

/* ========== Includes ========= */
#include "Memorymap.h"
#include "Utils.h"

/* ========= Definitions ======= */
#define F_CPU 8000000UL

/* ========= Functions Prototypes ========= */
void GPIO_PortA_Init(void);
void GPIO_PortC_Init(void);
void Delay_ms(volatile unsigned int delay);

/* ========== Main Program ======== */
int main(void)
{
	GPIO_PortA_Init();
	GPIO_PortC_Init();
	volatile int i;
	
	while (1)
	{
		for (i = 0; i <= 7; i++)
		{
		
				while (! READBIT(PINC, 0))
				{
					SETBIT(PORTA, i);
					while (! READBIT(PINC, 0));
				}
				
				Delay_ms(2000);
		}
		
		
		PORTA = 0x00;
		
	}
}

/* ============== Functions Definitions ============== */

void GPIO_PortA_Init(void)
{
	// RESET all bits of PortA ( Data register )
	PORTA = 0x00 ;
	
	// All port pins are output
	DDRA = 0xFF ; // 0b1111 1111
}

void GPIO_PortC_Init(void)
{
	// Making PortB bit 0 as input
	RESETBIT(DDRC, 0);
	
	SETBIT(PORTC, 0);
}

void Delay_ms(volatile unsigned int delay)
{
	unsigned int i, j;
	for (i = 0; i < delay; i++)
	{
		for (j = 0; j < 255; j++);
	}
	
}