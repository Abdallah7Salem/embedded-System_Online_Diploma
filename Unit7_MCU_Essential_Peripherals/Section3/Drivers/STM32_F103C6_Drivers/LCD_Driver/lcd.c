/*
 * lcd.c
 *
 * Created: 11/5/2021 2:26:07 PM
 *  Author: Abdallah
 */

#include "lcd.h"

/* ========== Functions Defintions ========== */

// Function to make delay_ms 1ms
void delay_ms(uint32_t delay)
{
	uint32_t i, j;
	for (i = 0;i < delay; i++)
	{
		for (j = 0; j < 255; j++);
	}

}

// Initialize GPIO for LCD
void LCD_GPIO_init(void)
{
	// =================== Set CTRL Switches to Output ===========================================

	//RS_SWITCH is Output with Speed 10 MHz (push-pull) mode
	PinCfg.GPIO_Pin_Number = RS_SWITCH;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL_DATA_R, &PinCfg);

	//RW_SWITCH is Output with Speed 10 MHz (push-pull) mode
	PinCfg.GPIO_Pin_Number = RW_SWITCH;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL_DATA_R, &PinCfg);

	//Enable_SWITCH is Output with Speed 10 MHz (push-pull) mode
	PinCfg.GPIO_Pin_Number = ENABLE_SWITCH;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL_DATA_R, &PinCfg);

	// =================== Set LCD Port to Output with Speed 10 MHz (push-pull) mode ==============
	// PIN 0
	PinCfg.GPIO_Pin_Number = GPIO_PIN_0;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL_DATA_R, &PinCfg);

	// PIN 1
	PinCfg.GPIO_Pin_Number = GPIO_PIN_1;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL_DATA_R, &PinCfg);

	// PIN 2
	PinCfg.GPIO_Pin_Number = GPIO_PIN_2;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL_DATA_R, &PinCfg);

	// PIN 3
	PinCfg.GPIO_Pin_Number = GPIO_PIN_3;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL_DATA_R, &PinCfg);

	// PIN 4
	PinCfg.GPIO_Pin_Number = GPIO_PIN_4;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL_DATA_R, &PinCfg);

	// PIN 5
	PinCfg.GPIO_Pin_Number = GPIO_PIN_5;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL_DATA_R, &PinCfg);

	// PIN 6
	PinCfg.GPIO_Pin_Number = GPIO_PIN_6;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL_DATA_R, &PinCfg);

	// PIN 7
	PinCfg.GPIO_Pin_Number = GPIO_PIN_7;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL_DATA_R, &PinCfg);

	// RESET ENABLE_SWITCH PIN
	MCAL_GPIO_WritePin(LCD_CTRL_DATA_R, ENABLE_SWITCH, GPIO_PIN_RESET);
	// RESET RS_SWITCH PIN
	MCAL_GPIO_WritePin(LCD_CTRL_DATA_R, RS_SWITCH, GPIO_PIN_RESET);
	// RESET RW_SWITCH PIN
	MCAL_GPIO_WritePin(LCD_CTRL_DATA_R, RW_SWITCH, GPIO_PIN_RESET);

}

// Function to clear screen of LCD
void LCD_clear_screen(void)
{
	LCD_write_command(LCD_CLEAR_SCREEN);  // LCD_CLEAR_SCREEN is a Macro
}

// Kick Start of LED
void LCD_kick(void)
{
	// set Enable bit
	MCAL_GPIO_WritePin(LCD_CTRL_DATA_R, ENABLE_SWITCH, GPIO_PIN_SET);

	// AC Characteristics : Enable cycle time (R & W ) = 500 ns
	delay_ms(50);

	// Reset Enable bit
	MCAL_GPIO_WritePin(LCD_CTRL_DATA_R, ENABLE_SWITCH, GPIO_PIN_RESET);
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
		if (position < 16 && position >= 0)
		{
			LCD_write_command(LCD_BEGIN_AT_SECOND_ROW + position);
		}

	}
}

// Initialize LCD
void LCD_init(void)
{
	delay_ms(20);
	LCD_GPIO_init();
	delay_ms(15);

	LCD_clear_screen();

	LCD_write_command(LCD_FUNCTION_8BIT_2LINES);
	LCD_write_command(LCD_ENTRY_MODE);
	LCD_write_command(LCD_BEGIN_AT_FIRST_ROW);
	LCD_write_command(LCD_DISP_ON_CURSOR_BLINK);
}

// Check if LCD is Busy
void LCD_is_busy(void)
{
	// 1) Set Port to Receive Data ( input )
//	LCD_PORT_DDR_R &= ~(0xFF<<DATA_SHIFT);

	// PIN 0
	PinCfg.GPIO_Pin_Number = GPIO_PIN_0;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLOATING;
	MCAL_GPIO_Init(LCD_CTRL_DATA_R, &PinCfg);

	// PIN 1
	PinCfg.GPIO_Pin_Number = GPIO_PIN_1;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLOATING;
	MCAL_GPIO_Init(LCD_CTRL_DATA_R, &PinCfg);

	// PIN 2
	PinCfg.GPIO_Pin_Number = GPIO_PIN_2;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLOATING;
	MCAL_GPIO_Init(LCD_CTRL_DATA_R, &PinCfg);

	// PIN 3
	PinCfg.GPIO_Pin_Number = GPIO_PIN_3;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLOATING;
	MCAL_GPIO_Init(LCD_CTRL_DATA_R, &PinCfg);

	// PIN 4
	PinCfg.GPIO_Pin_Number = GPIO_PIN_4;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLOATING;
	MCAL_GPIO_Init(LCD_CTRL_DATA_R, &PinCfg);

	// PIN 5
	PinCfg.GPIO_Pin_Number = GPIO_PIN_5;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLOATING;
	MCAL_GPIO_Init(LCD_CTRL_DATA_R, &PinCfg);

	// PIN 6
	PinCfg.GPIO_Pin_Number = GPIO_PIN_6;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLOATING;
	MCAL_GPIO_Init(LCD_CTRL_DATA_R, &PinCfg);

	// PIN 7
	PinCfg.GPIO_Pin_Number = GPIO_PIN_7;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLOATING;
	MCAL_GPIO_Init(LCD_CTRL_DATA_R, &PinCfg);

	// 2) Put LCD on Read Mode ( RW ON )
	// LCD_CTRL_DATA_R |= (1<<RW_SWITCH);
	MCAL_GPIO_WritePin(LCD_CTRL_DATA_R, RW_SWITCH, GPIO_PIN_SET);

	// 3) Put LCD on Command Mode ( RS OFF )
	// LCD_CTRL_DATA_R &= ~(1<<RS_SWITCH);
	MCAL_GPIO_WritePin(LCD_CTRL_DATA_R, RS_SWITCH, GPIO_PIN_RESET);

	LCD_kick();

//	LCD_PORT_DDR_R |= (0xFF<<DATA_SHIFT);
//	LCD_CTRL_DATA_R &= ~(1<<RW_SWITCH);
	MCAL_GPIO_WritePin(LCD_CTRL_DATA_R, RW_SWITCH, GPIO_PIN_RESET);
}

// Function to write commands for LCD
void LCD_write_command(unsigned char command)
{
	/* ====== LCD is in 8 bit Mode ====== */

	// Set LCD Port using command variable
	MCAL_GPIO_WritePort(LCD_CTRL_DATA_R, command);

	// Port Direction is set to Output in LCD_init()

	// Turn RS off for command mode
	MCAL_GPIO_WritePin(LCD_CTRL_DATA_R, RS_SWITCH, GPIO_PIN_RESET);

	// Turn RW off so you can write
	MCAL_GPIO_WritePin(LCD_CTRL_DATA_R, RW_SWITCH, GPIO_PIN_RESET);

	delay_ms(1);
	LCD_kick();
}

void LCD_write_char(unsigned char character)
{
	/* ========== LCD is in 8 bit Mode ========== */

	// Set LCD Port using data variable
	MCAL_GPIO_WritePort(LCD_CTRL_DATA_R, character);

	// Turn RW off so you can write
	MCAL_GPIO_WritePin(LCD_CTRL_DATA_R, RW_SWITCH, GPIO_PIN_RESET);

	// Turn RS on for data mode
	MCAL_GPIO_WritePin(LCD_CTRL_DATA_R, RS_SWITCH, GPIO_PIN_SET);

	delay_ms(1);
	LCD_kick();
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
	delay_ms(10);
}
*/
