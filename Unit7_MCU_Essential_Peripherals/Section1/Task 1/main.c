/*
 * unit7_section1_task1.c
 *
 * Created: 11/3/2021 12:34:56 PM
 * Author : Abdallah
 */ 

// Turn ON LEDs in forward manner 
// Then Turn OFF them in reverse manner

/* ========== Includes ========= */
#include "Memorymap.h"
#include "Utils.h"

/* ========= Definitions ======= */
#define F_CPU 8000000UL

/* ========= Functions Prototypes ========= */
void GPIO_PortA_Init(void);
void Delay_ms(volatile unsigned int delay);

/* ========== Main Program ======== */
int main(void)
{	
	GPIO_PortA_Init();
	
    while (1) 
    {
		int i;		
		// Turn LEDs ON in Forward Manner
		for (i = 0; i <= 7; i++)
		{
			SETBIT(PORTA, i);
			Delay_ms(150);
		}
		
		// Turn LEDs OFF in Backward Manner
		for (i = 7; i >= 0; i--)
		{
			RESETBIT(PORTA, i);
			Delay_ms(150);
		}
		
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

void Delay_ms(volatile unsigned int delay)
{
	unsigned int i, j;
	for (i = 0; i < delay; i++)
	{
		for (j = 0; j < 255; j++);
	}
	
}
