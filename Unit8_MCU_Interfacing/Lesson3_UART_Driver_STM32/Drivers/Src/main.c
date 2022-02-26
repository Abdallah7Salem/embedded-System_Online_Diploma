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
#include "STM32_F103C6_USART_Driver.h"

/* ================================= Global Variables ================================= */
unsigned char ch;

/* ================================== Prototypes ========================================= */
void clock_init();

/*
 * =====================================
 * 		CallBack Functions Prototypes
 * =====================================
 */
void Abdallah_UART_IRQ_Callback (void)
{
	MCAL_UART_ReceiveData(USART1, &ch, disable);
	MCAL_UART_SendData(USART1, &ch, enable);
}


/* ==================================== Main Program ======================================= */
int main(void)
{
	UART_Config UART_Configure;

	clock_init();

	UART_Configure.BaudRate = UART_BaudRate_115200;
	UART_Configure.HardwareFlowControl = UART_HardwareFlowControl_NONE;
	UART_Configure.IRQ_Enable = UART_IRQ_Enable_RXNEIE;
	UART_Configure.P_IRQ_CallBack = Abdallah_UART_IRQ_Callback;
	UART_Configure.Parity = UART_Parity_NONE;
	UART_Configure.Payload_Length = UART_Payload_Length_8B;
	UART_Configure.StopBits = UART_StopBits__1;
	UART_Configure.USART_Mode = UART_Mode_Tx_Rx;

	MCAL_UART_Init(USART1, &UART_Configure);
	MCAL_UART_GPIO_Set_Pins(USART1);

	while(1)
	{

	}
}


/* ============= clock init definition ============== */
void clock_init()
{
	// Enable clock of Port A
	RCC_GPIO_PORTA_CLK_EN();

	// Enable clock of Port B
	RCC_GPIO_PORTB_CLK_EN();

	// Enable clock for AFIO
	RCC_AFIO_CLK_EN();
}

/*
 * ======================================
 * 		CallBack Functions Definitions
 * 	=====================================
 */
