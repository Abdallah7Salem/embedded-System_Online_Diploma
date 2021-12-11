/*
 * AMIT_Kit_LCD.c
 *
 * Created: 12/11/2021 1:47:46 AM
 * Author : Abdallah
 */ 

#include "ATmega32_Drivers/Includes/ATmega32_Device_Header.h"
#include "ATmega32_Drivers/Includes/ATmega32_GPIO_Driver.h"
#include "HAL/LCD_driver/lcd.h"

#define F_CPU 8000000UL

GPIO_config * PinCfgA;
GPIO_config * PinCfgB;

int main(void)
{
    /* AMIT LCD Data Lines
	 * Configure the PORTA Pins (4..7) as Output
	 * LCD_D4 -> PORTA.4
	 * LCD_D5 -> PORTA.5
	 * LCD_D6 -> PORTA.6
	 * LCD_D7 -> PORTA.7
	 */
	
	// Configure PIN4 as Output(push-pull)
	PinCfgA->GPIO_PinNumber = GPIO_PIN4;
	PinCfgA->GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	
	// Configure PIN5 as Output(push-pull)
	PinCfgA->GPIO_PinNumber = GPIO_PIN5;
	PinCfgA->GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	
	// Configure PIN6 as Output(push-pull)
	PinCfgA->GPIO_PinNumber = GPIO_PIN6;
	PinCfgA->GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	
	// Configure PIN7 as Output(push-pull)
	PinCfgA->GPIO_PinNumber = GPIO_PIN7;
	PinCfgA->GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	
	MCAL_GPIO_Init(GPIOA, PinCfgA);
	
	/* AMIT LCD Control Lines
	 * Configure the PortB PINs as Output(push-pull)
	 * LCD_RS -> PORTB.1
	 * LCD_RW -> PORTB.2
	 * LCD_E  -> PORTB.3
	 */
	
	// Configure PIN1 as Output(push-pull)
	PinCfgB->GPIO_PinNumber = GPIO_PIN1;
	PinCfgB->GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	
	// Configure PIN2 as Output(push-pull)
	PinCfgB->GPIO_PinNumber = GPIO_PIN2;
	PinCfgB->GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	
	// Configure PIN3 as Output(push-pull)
	PinCfgB->GPIO_PinNumber = GPIO_PIN3;
	PinCfgB->GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	
	MCAL_GPIO_Init(GPIOB, PinCfgB);
	
	//#########################################
	
	// Initialize the LCD
	LCD_init();
	
	LCD_write_string("Learn in Depth");
	
	
	
    while (1) 
    {
    }
}
