/*
 * lcd.c
 *
 * Created: 11/5/2021 2:26:07 PM
 *  Author: Abdallah
 */ 

#include "lcd.h"

/* ========== Functions Defintions ========== */

// Function to clear screen
void LCD_clear_screen(void)
{
	LCD_write_command(LCD_CLEAR_SCREEN);  // LCD_CLEAR_SCREEN is a Macro
}

// Kick Start of LED
void LCD_kick(void)
{
	// Reset Enable bit
	LCD_CTRL_DATA_R |= (1<<ENABLE_SWITCH);
	
	// AC Characteristics : Enable cycle time (R & W ) = 500 ns
	_delay_ms(50);
	
	// Set Enable bit
	LCD_CTRL_DATA_R &= ~(1<<ENABLE_SWITCH);
}

void LCD_goTo_XY_Axis(unsigned char line, unsigned char position)
{
	if (line == 1)
	{
		if (position < 16 && position >= 0)
		{
			LCD_write_command(LCD_BEGIN_AT_FIRST_ROW + position);
		}
	}
	if (line == 2)
	{
		if (position < 32 && position >= 0)
		{
			LCD_write_command(LCD_BEGIN_AT_SECOND_ROW + position);
		}
		
	}
}

// Initialize LCD
void LCD_init(void)
{
	// Wait 15milliseconds for Vcc to rise to 4.5 V ,
	// Wait for more than 4.1milliseconds
	// Wait for more than 100microseconds
	// Total = 20ms
	_delay_ms(20);
		
	// Set CTRL Switches to Output
	LCD_CTRL_DDR_R |= (1<<ENABLE_SWITCH | 1<<RS_SWITCH | 1<<RW_SWITCH);
	
	// Turn OFF CTRL
	LCD_CTRL_DATA_R &= ~(1<<ENABLE_SWITCH | 1<<RW_SWITCH | 1<<RW_SWITCH);
	
	// Set LCD Port to Output
	LCD_PORT_DDR_R = 0xFF;
	
	_delay_ms(15);
	
	// Clear screen of the LCD
	LCD_clear_screen();
	
	/* ======= LCD is in 8 bit Mode ======= */
	#ifdef EIGHT_BIT_MODE
	LCD_write_command(LCD_FUNCTION_8BIT_2LINES);
	#endif
	
	/* ====== LCD is in 4 bit Mode ======= */
	#ifdef FOUR_BIT_MODE
	LCD_write_command(ENABLE_4BIT_MODE);
	LCD_write_command(LCD_FUNCTION_4BIT_2LINES);
	#endif
	
	LCD_write_command(LCD_ENTRY_MODE);
	LCD_write_command(LCD_BEGIN_AT_FIRST_ROW);
	LCD_write_command(LCD_DISP_ON_CURSOR_BLINK);
}


// Check if LCD is Busy
void LCD_is_busy(void)
{
	// 1) Set Port to Receive Data ( input )
	LCD_PORT_DDR_R &= ~(0xFF<<DATA_SHIFT);
	
	// 2) Put LCD on Read Mode ( RW ON )
	LCD_CTRL_DATA_R |= (1<<RW_SWITCH);
	
	// 3) Put LCD on Command Mode ( RS OFF )
	LCD_CTRL_DATA_R &= ~(1<<RS_SWITCH);
	
	LCD_kick();
	
	LCD_PORT_DDR_R |= (0xFF<<DATA_SHIFT);
	LCD_CTRL_DATA_R &= ~(1<<RW_SWITCH);	
}

// Function to write commands for LCD
void LCD_write_command(unsigned char command)
{	
	/* ====== LCD is in 8 bit Mode ====== */
	#ifdef EIGHT_BIT_MODE
		// check if LCD is busy
		LCD_is_busy();
	
		// Set LCD Port using command variable
		LCD_PORT_DATA_R = command;
	
		// Port Direction is set to Output in LCD_init()
	
		// Turn RW off so you can write
		// Turn RS off for command mode 
		LCD_CTRL_DATA_R &= ~((1<<RS_SWITCH) | (1<<RW_SWITCH));
	
		_delay_ms(1);
		LCD_kick();	
	#endif
	
	/* ===== LCD is in 4 bit Mode ===== */
	#ifdef FOUR_BIT_MODE
		// Check if LCD is busy
		LCD_is_busy();
		
	    /* ==== 1st 4 bit of command ==== */
		LCD_PORT_DATA_R = (LCD_PORT_DATA_R & 0x0F) | (command & 0xF0);
		
		// Turn RW off so you can write
		// Turn RS off for command mode
		LCD_CTRL_DATA_R &= ~((1<<RW_SWITCH) | (1<<RS_SWITCH));
		LCD_kick();
		
		/* ==== 2nd 4 bit of command ==== */
		LCD_PORT_DATA_R = (LCD_PORT_DATA_R & 0x0F) | (command << 4);
		
		// Turn RW off so you can write
		// Turn RS off for command mode
		LCD_CTRL_DATA_R &= ~((1<<RW_SWITCH) | (1 << RS_SWITCH));
		LCD_kick();
	#endif
}

void LCD_write_char(unsigned char character)
{
	/* ========== LCD is in 8 bit Mode ========== */
	#ifdef EIGHT_BIT_MODE
		//Check if LCD is busy
		LCD_is_busy();
	
		// Set LCD Port using data variable
		LCD_PORT_DATA_R = character;
	
		// Turn RW off so you can write
		LCD_CTRL_DATA_R &= ~(1<<RW_SWITCH);
		// Turn RS on for data mode
		LCD_CTRL_DATA_R |= (1<<RS_SWITCH);    
		_delay_ms(1);
		LCD_kick();
	#endif
	
	/* ======== LCD is in 4 bit mode ======= */
	#ifdef FOUR_BIT_MODE
		// Check if LCD is busy
		// LCD_is_busy();
		
		// 1st Four bits of data
		LCD_PORT_DATA_R = (LCD_PORT_DATA_R & 0x0F) | (character & 0xF0);

		// Turn RS on for data mode
		LCD_CTRL_DATA_R |= (1<<RS_SWITCH);
		
		// Turn RW off so you can write
		LCD_CTRL_DATA_R &= ~(1<<RW_SWITCH);
		
		LCD_kick();
		
		// 2nd Four bits of data
		LCD_PORT_DATA_R = (LCD_PORT_DATA_R & 0x0F) | (character << 4);
		
		// Turn RS on for data mode
		LCD_CTRL_DATA_R |= (1<<RS_SWITCH);
		// Turn RW off so you can write
		LCD_CTRL_DATA_R &= ~(1<<RW_SWITCH);
		
		LCD_kick();
	#endif
}

void LCD_write_string(char* string)
{
	// counter to avoid writing bigger word size than LCD screen
	int count = 0;
	while(*string > 0)
	{
		count++;
		LCD_write_char(*string++);
		if(count == 16)  // counter reached the end of the first row
		{
			LCD_goTo_XY_Axis(2, 0);  // line : row num 2 , starts from position 0 
		}
		else if (count == 32)
		{
			LCD_clear_screen();
			LCD_goTo_XY_Axis(1, 0);  // go to line 1 , position 0 
			count = 0;
		}
	}
}

/*
void LCD_custom_characters(void)
{
	LCD_write_command(64);
	LCD_write_char(0);
	LCD_write_char(14);
	LCD_write_char(17);
	LCD_write_char(2);
	LCD_write_char(4);
	LCD_write_char(4);
	LCD_write_char(0);
	LCD_write_char(4);
	LCD_write_command(LCD_BEGIN_AT_FIRST_ROW);
	LCD_write_char(0);
	_delay_ms(10);
}
*/