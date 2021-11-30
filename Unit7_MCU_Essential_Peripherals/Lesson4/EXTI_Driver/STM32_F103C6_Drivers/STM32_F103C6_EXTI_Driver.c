/*
 * STM32_F103C6_GPIO_Driver.c
 *
 *  Created on: Nov 27, 2021
 *      Author: Abdallah
 */

/* ================================================== Includes =============================================================*/
#include "STM32_F103C6_EXTI_Driver.h"
#include "STM32_F103C6_GPIO_Driver.h"


/* ================================================= Generic Variables ==================================================== */
void (* GP_IRQ_CallBack[15])(void); 				 // Array Of 15 Pointer To Functions Take void And Return Nothing

/* =========================================== Generic Macros  ============================================================== */
#define AFIO_GPIO_EXTI_Mapping(x)	(	(x == GPIO_PORTA) ? 0 : \
										(x == GPIO_PORTB) ? 1 : \
										(x == GPIO_PORTC) ? 2 : \
										(x == GPIO_PORTD) ? 3 : 0	)


/* =========================================== Generic Functions ============================================================ */
void Enable_NVIC (uint16_t IRQ)
{
	switch (IRQ)
	{
	case 0:
		NVIC_IRQ6_EXTI0_Enable;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_Enable;
		break;
	case 2:
		NVIC_IRQ8_EXTI2_Enable;
		break;
	case 3:
		NVIC_IRQ9_EXTI3_Enable;
		break;
	case 4:
		NVIC_IRQ10_EXTI4_Enable;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_Enable;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_Enable;
		break;
	}
}

void Disable_NVIC (uint16_t IRQ)
{
	switch (IRQ)
		{
		case 0:
			NVIC_IRQ6_EXTI0_Disable;
			break;
		case 1:
			NVIC_IRQ7_EXTI1_Disable;
			break;
		case 2:
			NVIC_IRQ8_EXTI2_Disable;
			break;
		case 3:
			NVIC_IRQ9_EXTI3_Disable;
			break;
		case 4:
			NVIC_IRQ10_EXTI4_Disable;
			break;
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			NVIC_IRQ23_EXTI5_9_Disable;
			break;
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
			NVIC_IRQ40_EXTI10_15_Disable;
			break;
		}

}








void Update_EXTI	(EXTI_PinConfig_t* EXTI_Config)
{
	// 1) Configure GPIO To Be Alternative Function Input (Floating Input)

	GPIO_PinConfig_t PinCfg;
	// Update The GPIO Pin To Be Floating Input
	PinCfg.GPIO_Pin_Number = EXTI_Config->EXTI_Pin.GPIO_Pin;
	PinCfg.GPIO_MODE	  = GPIO_MODE_INPUT_FLOATING;
	MCAL_GPIO_Init(EXTI_Config->EXTI_Pin.GPIO_Port, &PinCfg);
	//=========================================================

	// 2) Update AFIO to Route between EXTI Line With Port A,B,C,D

	uint8_t AFIO_EXTICR_index = EXTI_Config->EXTI_Pin.EXTI_InputLineNumber / 4;

	uint8_t AFIO_EXTICR_Position = (EXTI_Config->EXTI_Pin.EXTI_InputLineNumber % 4) * 4;

	// Clear The Four Bits First
	AFIO->EXTICR[AFIO_EXTICR_index] &= ~(0xF << AFIO_EXTICR_Position);

	//
	AFIO->EXTICR[AFIO_EXTICR_index] |= ((AFIO_GPIO_EXTI_Mapping(EXTI_Config->EXTI_Pin.GPIO_Port) & 0xF) << AFIO_EXTICR_Position);

	//=========================================================

	// 3) Update Rising / Falling Edge Register

	// Reset Bits Of Rising
	EXTI->RTSR &= ~(1 << EXTI_Config->EXTI_Pin.EXTI_InputLineNumber);
	// Reset Bits Of Falling
	EXTI->FTSR &= ~(1 << EXTI_Config->EXTI_Pin.EXTI_InputLineNumber);

	// To Make An Update
	if (EXTI_Config->Trigger_Case == EXTI_Trigger_Rising)
	{
		// Set Bits Of Rising
		EXTI->RTSR |= (1 << EXTI_Config->EXTI_Pin.EXTI_InputLineNumber);
	}
	else if (EXTI_Config->Trigger_Case == EXTI_Trigger_Falling)
	{
		// Set Bits Of Falling
		EXTI->FTSR |= (1 << EXTI_Config->EXTI_Pin.EXTI_InputLineNumber);

	}
	else if (EXTI_Config->Trigger_Case == EXTI_Trigger_Rising_And_Falling)
	{
		// Set Both Bits Of Rising And Falling
		EXTI->RTSR |= (1 << EXTI_Config->EXTI_Pin.EXTI_InputLineNumber);
		EXTI->FTSR |= (1 << EXTI_Config->EXTI_Pin.EXTI_InputLineNumber);
	}
	//=========================================================
	// 4) Update Interrupt Handling CallBack

	GP_IRQ_CallBack[EXTI_Config->EXTI_Pin.EXTI_InputLineNumber] = EXTI_Config->P_IRQ_CallBack;

	//=========================================================
	// 5) Enable/Disable IRQ EXTI & NVIC

	if (EXTI_Config->IRQ_Enable	== EXTI_IRQ_Enable)
	{
		EXTI->IMR |= (1 << EXTI_Config->EXTI_Pin.EXTI_InputLineNumber);
		Enable_NVIC (EXTI_Config->EXTI_Pin.EXTI_InputLineNumber);
	}
	else if (EXTI_Config->IRQ_Enable == EXTI_IRQ_Disable)
	{
		EXTI->IMR &= ~(1 << EXTI_Config->EXTI_Pin.EXTI_InputLineNumber);
		Disable_NVIC (EXTI_Config->EXTI_Pin.EXTI_InputLineNumber);
	}

}



/* ========================================== APIs Functions Definitions ==================================================== */

/**======================================================================
 * @Fn					-MCAL_EXTI_GPIO_DeInit
 * @Brief				-Reset EXTI Registers and NVIC corresponding IRQ Mask
 * @return val			-None
 * @Note				-None
 */
void MCAL_EXTI_GPIO_DeInit	(void)
{
	EXTI->IMR 		= 0x00000000;				// Reset Value Is Got From The DataSheet
	EXTI->EMR 		= 0x00000000;
	EXTI->RTSR		= 0x00000000;
	EXTI->FTSR  	= 0x00000000;
	EXTI->SWIER 	= 0x00000000;
	EXTI->PR		= 0xFFFFFFFF;				// This Bit Is Cleared By Writing One To It

	// Disable All EXTI IRQ From NVIC (Non-Vectored Interrupt Controllers)
	NVIC_IRQ6_EXTI0_Disable;
	NVIC_IRQ7_EXTI1_Disable;
	NVIC_IRQ8_EXTI2_Disable;
	NVIC_IRQ9_EXTI3_Disable;
	NVIC_IRQ10_EXTI4_Disable;
	NVIC_IRQ23_EXTI5_9_Disable;
	NVIC_IRQ40_EXTI10_15_Disable;

}


/**==========================================================================
 * @Function Name				-MCAL_EXTI_GPIO_Init
 * @Brief						-This Is Used To Initialize EXTI From Specific GPIO PIN and Specify Mask/Trigger Condition
 * 								 and IRQ CallBack
 * @Param[in]					-EXTI_Config set by @ref EXTI_define, EXTI_Trigger_define and EXTI_IRQ_define
 * @return val					-None
 * @Note						-STM32F103C6 MCU has GPIO A,B,C,D,E Modules
 * 								But LQFP48 Package has only GPIO A,B , Parts of C, D exported as External Pins from
 * 								- Also Mandatory To Enable RCC Clock for AFIO And The Corresponding GPIO
 */
void MCAL_EXTI_GPIO_Init	(EXTI_PinConfig_t* EXTI_Config)
{
	Update_EXTI(EXTI_Config);
}


/**==========================================================================
 * @Function Name				-MCAL_EXTI_GPIO_Update
 * @Brief						-This Is Used To Initialize EXTI From Specific GPIO PIN and Specify Mask/Trigger Condition
 * 								 and IRQ CallBack
 * @Param[in]					-EXTI_Config set by @ref EXTI_define, EXTI_Trigger_define and EXTI_IRQ_define
 * @return val					-None
 * @Note						-STM32F103C6 MCU has GPIO A,B,C,D,E Modules
 * 								But LQFP48 Package has only GPIO A,B , Parts of C, D exported as External Pins from
 * 								- Also Mandatory To Enable RCC Clock for AFIO And The Corresponding GPIO
 */
void MCAL_EXTI_GPIO_Update	(EXTI_PinConfig_t* EXTI_Config)
{
	Update_EXTI(EXTI_Config);
}



/* ========================================================== ISR Functions ================================================ */
// EXTI0
void EXTI0_IRQHandler (void)
{
	// Clear By Writing "1" into the bit Pending Register (EXTI_PR)
	EXTI->PR |= 1 << 0;

	// Call IRQ_CallBack
	GP_IRQ_CallBack[0]();

}

// EXTI1
void EXTI1_IRQHandler (void)
{
	// Clear By Writing "1" into the bit Pending Register (EXTI_PR)
	EXTI->PR |= 1 << 1;

	// Call IRQ_CallBack
	GP_IRQ_CallBack[1]();

}

// EXTI2
void EXTI2_IRQHandler (void)
{
	// Clear By Writing "1" into the bit Pending Register (EXTI_PR)
	EXTI->PR |= 1 << 2;

	// Call IRQ_CallBack
	GP_IRQ_CallBack[2]();

}

// EXTI3
void EXTI3_IRQHandler (void)
{
	// Clear By Writing "1" into the bit Pending Register (EXTI_PR)
	EXTI->PR |= 1 << 3;

	// Call IRQ_CallBack
	GP_IRQ_CallBack[3]();

}

// EXTI4
void EXTI4_IRQHandler (void)
{
	// Clear By Writing "1" into the bit Pending Register (EXTI_PR)
	EXTI->PR |= 1 << 4;

	// Call IRQ_CallBack
	GP_IRQ_CallBack[4]();

}

// EXTI5 ---> EXTI9
void EXTI9_5_IRQHandler (void)
{
	if (EXTI->PR & 1<<5)	{	EXTI->PR |= (1<<5)	; GP_IRQ_CallBack[5]()	;	}
	if (EXTI->PR & 1<<6)	{	EXTI->PR |= (1<<6)	; GP_IRQ_CallBack[6]()	;	}
	if (EXTI->PR & 1<<7)	{	EXTI->PR |= (1<<7)	; GP_IRQ_CallBack[7]()	;	}
	if (EXTI->PR & 1<<8)	{	EXTI->PR |= (1<<8)	; GP_IRQ_CallBack[8]()	;	}
	if (EXTI->PR & 1<<9)	{	EXTI->PR |= (1<<9)	; GP_IRQ_CallBack[9]()	;	}
}

// EXTI10 ---> EXTI15
void EXTI15_10_IRQHandler (void)
{
	if (EXTI->PR & 1<<10)	{	EXTI->PR |= (1<<10)	; GP_IRQ_CallBack[10]()	;	}
	if (EXTI->PR & 1<<11)	{	EXTI->PR |= (1<<11)	; GP_IRQ_CallBack[11]()	;	}
	if (EXTI->PR & 1<<12)	{	EXTI->PR |= (1<<12)	; GP_IRQ_CallBack[12]()	;	}
	if (EXTI->PR & 1<<13)	{	EXTI->PR |= (1<<13)	; GP_IRQ_CallBack[13]()	;	}
	if (EXTI->PR & 1<<14)	{	EXTI->PR |= (1<<14)	; GP_IRQ_CallBack[14]()	;	}
	if (EXTI->PR & 1<<15)	{	EXTI->PR |= (1<<15)	; GP_IRQ_CallBack[15]()	;	}
}
