/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Abdallah Salem
 * @brief          : Main program body
 ******************************************************************************/

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif




/* ================================= Includes ======================================== */
#include "STM32F103X6.h"
#include "STM32_F103C6_GPIO_Driver.h"
#include "lcd.h"
#include "keypad.h"
#include "S7_segment.h"
#include "STM32_F103C6_EXTI_Driver.h"

/* ================================= Global Variables ================================= */
unsigned int IRQ_Flag = 0;			// Interrupt Flag

/* ================================== Prototypes ========================================= */
void clock_init();
extern void delay_ms(uint32_t delay);

/*
 * =====================================
 * 		CallBack Functions Prototypes
 * =====================================
 */
void EXTI9_CallBack(void);

/* ==================================== Main Program ======================================= */
int main(void)
{
	// Enable Clock
	RCC_GPIO_PORTA_CLK_EN();					// Enable Clock For Port A
	RCC_GPIO_PORTB_CLK_EN();					// Enable Clock For Port B
	RCC_AFIO_CLK_EN();							// Enable Clock For AFIO

	// Initialize LCD
	LCD_init();
	// Clear LCD Screen
	LCD_clear_screen();


	// Define An Object Of External Interrupt Pin Configuration
	EXTI_PinConfig_t	EXTI_Cfg;

	// User Make Configuration To The EXTI Using @ref
	// It uses @ref Instead of Defining Each Member Of The Structure
	// This Helps To Avoid MisMatch of Input lines with Ports Pins
	EXTI_Cfg.EXTI_Pin = EXTI9_PB9;

	// Trigger Case Of Interrupt ---> Set To Rising
	EXTI_Cfg.Trigger_Case = EXTI_Trigger_Rising;

	//CallBack Of Interrupt
	EXTI_Cfg.P_IRQ_CallBack = EXTI9_CallBack;

	// Enable External Interrupt Requests
	EXTI_Cfg.IRQ_Enable = EXTI_IRQ_Enable;

	MCAL_EXTI_GPIO_Init(&EXTI_Cfg);

	IRQ_Flag = 1;

	while(1)
	{
		if (IRQ_Flag)
		{
			LCD_clear_screen();
			IRQ_Flag = 0;
		}

		delay_ms(1000);

	}
}


/* ============= clock init definition ============== */
void clock_init()
{
	// Enable clock of Port A
	RCC_GPIO_PORTA_CLK_EN();

	// Enable clock of Port B
	RCC_GPIO_PORTB_CLK_EN();
}

/*
 * ======================================
 * 		CallBack Functions Definitions
 * 	=====================================
 */
void EXTI9_CallBack(void)
{
	IRQ_Flag = 1;
	LCD_write_string("IRQ EXTI9 has happened _|- ");
	delay_ms(1000);
}
