/*
 * LCD_Keypad_Driver.c
 *
 * Created: 11/5/2021 2:23:54 PM
 * Author : Abdallah
 */ 

#include "LCD_driver/lcd.h"
#include "Keypad_driver/keypad.h"

int main(void)
{
    /* ===== Drivers Initialization ====== */
	LCD_init();
	keypad_init();
	_delay_ms(50);
	
	// variable to get keypad input char
	unsigned char pressed_key;
	
    while (1) 
    {
		pressed_key = keypad_getchar();
		
		switch (pressed_key)
		{
			case ('!'):
				LCD_clear_screen();
				break;
			case ('N'):
				break;
			default:
				LCD_write_char(pressed_key);
				break;
		}
    }
}

