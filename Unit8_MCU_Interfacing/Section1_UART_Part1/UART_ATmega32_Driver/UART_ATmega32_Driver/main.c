/*
 * UART_ATmega32_Driver.c
 *
 * Created: 2/23/2022 7:40:38 AM
 * Author : Abdallah
 */ 

#include "UART_ATmega32.h"
#include "lcd.h"

uint8_t data = 0;
int main(void)
{
	LCD_init();	
	UART_Init();
	
	UART_Send('M');
	UART_Send('y');
	UART_Send('M');
	
    /* Replace with your application code */
    while (1) 
    {
		LCD_goTo_XY_Axis(0, 0);
		data = UART_Receive();
		LCD_write_char(data);
		
    }
}

