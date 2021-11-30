/*
 * STM32_F103C6_GPIO_Driver.h
 *
 *  Created on: Nov 27, 2021
 *      Author: Abdallah
 */

#ifndef INCLUDE_FOLDER_STM32_F103C6_EXTI_DRIVER_H_
#define INCLUDE_FOLDER_STM32_F103C6_EXTI_DRIVER_H_

/* ========================================== Includes ================================================= */
#include "STM32F103X6.h" 							// 1) Device Header
#include "STM32_F103C6_GPIO_Driver.h"  				// 2) GPIO Used In Mapping The Input Line With The Pins
									   	   	   	   	// To Help Making Constraints For User Not To Use It Wrong


/* ------------------------------------------------------------
 * Setting Constraints For Mapping The Input Lines With Ports Pins
 * This Structure Used To Take Input From The User
 * About : EXTI_InputLineNumber , GPIO_Port, GPIO_Pin
 * ----------------------------------------------------------- */

typedef struct
{
	// uint16 Due To EXTI Lines Are 0 ---> 15
	uint16_t		EXTI_InputLineNumber ;  		// Choose The Line Number To Use in EXTI

	GPIO_TypeDef *  GPIO_Port;						// GPIO Port Used For EXTI Driver

	uint16_t		GPIO_Pin;						// GPIO Pin Used For EXTI Driver

	uint8_t			IVT_IRQ_Number;					// Choose Interrupt Handler From Interrupt Vector Table
}EXTI_GPIO_Mapping_t;

/* -----------------------------------------------------------
 * Limiting Options/Selection For Customer/User Not To Choose
 * The EXTI_InputLineNumber, GPIO_Port, GPIO_Pin
 * Stop Them From Choosing These in Arbitrary Way
 */
typedef struct
{
	EXTI_GPIO_Mapping_t		EXTI_Pin;				// Specify the EXTI For GPIO Mapping
													//( Mapping EXTI Lines ---> GPIO Ports )
													// This Parameter Must Be Set Based On @ref EXTI_define
													// EXTI_define : We Set The Options For User Here ( CONSTRAINTS )

	uint8_t 				Trigger_Case;			// Specifies Rising Or Falling Edge Or Both Trigger .
													// This Parameter Must Be Set Based On @ref EXTI_Trigger_define

	uint8_t					IRQ_Enable;				// Enable or Disable the EXTI IRQ
													//(That Will Enable the IRQ Mask In EXTI And Also in the NVIC Interrupt Controller )
													// This Parameter Must be Set Based On @ref EXTI_IRQ_define

	void (* P_IRQ_CallBack)(void);					// Set the C Function() Which Will Be Called Once The IRQ Happen

}EXTI_PinConfig_t;

#define EXTI0			0
#define EXTI0_IRQ		6


/* ==================================== Reference Macros ================================================ */

// @ref EXTI_define

// EXTI0
// Ports A0, B0, C0, D0 : connected to EXTI0
#define EXTI0_PA0		(EXTI_GPIO_Mapping_t){EXTI0, GPIO_PORTA, GPIO_PIN_0, EXTI0_IRQ}
#define EXTI0_PB0		(EXTI_GPIO_Mapping_t){EXTI0, GPIO_PORTB, GPIO_PIN_0, EXTI0_IRQ}
#define EXTI0_PC0		(EXTI_GPIO_Mapping_t){EXTI0, GPIO_PORTC, GPIO_PIN_0, EXTI0_IRQ}
#define EXTI0_PD0		(EXTI_GPIO_Mapping_t){EXTI0, GPIO_PORTD, GPIO_PIN_0, EXTI0_IRQ}

// EXTI1
#define EXTI1_PA1		(EXTI_GPIO_Mapping_t){EXTI1, GPIO_PORTA, GPIO_PIN_1, EXTI1_IRQ}
#define EXTI1_PB1		(EXTI_GPIO_Mapping_t){EXTI1, GPIO_PORTB, GPIO_PIN_1, EXTI1_IRQ}
#define EXTI1_PC1		(EXTI_GPIO_Mapping_t){EXTI1, GPIO_PORTC, GPIO_PIN_1, EXTI1_IRQ}
#define EXTI1_PD1		(EXTI_GPIO_Mapping_t){EXTI1, GPIO_PORTD, GPIO_PIN_1, EXTI1_IRQ}

// EXTI2
#define EXTI2_PA2		(EXTI_GPIO_Mapping_t){EXTI2, GPIO_PORTA, GPIO_PIN_2, EXTI2_IRQ}
#define EXTI2_PB2		(EXTI_GPIO_Mapping_t){EXTI2, GPIO_PORTB, GPIO_PIN_2, EXTI2_IRQ}
#define EXTI2_PC2		(EXTI_GPIO_Mapping_t){EXTI2, GPIO_PORTC, GPIO_PIN_2, EXTI2_IRQ}
#define EXTI2_PD2		(EXTI_GPIO_Mapping_t){EXTI2, GPIO_PORTD, GPIO_PIN_2, EXTI2_IRQ}

// EXTI3
#define EXTI3_PA3		(EXTI_GPIO_Mapping_t){EXTI3, GPIO_PORTA, GPIO_PIN_3, EXTI3_IRQ}
#define EXTI3_PB3		(EXTI_GPIO_Mapping_t){EXTI3, GPIO_PORTB, GPIO_PIN_3, EXTI3_IRQ}
#define EXTI3_PC3		(EXTI_GPIO_Mapping_t){EXTI3, GPIO_PORTC, GPIO_PIN_3, EXTI3_IRQ}
#define EXTI3_PD3		(EXTI_GPIO_Mapping_t){EXTI3, GPIO_PORTD, GPIO_PIN_3, EXTI3_IRQ}

// EXTI4
#define EXTI4_PA4		(EXTI_GPIO_Mapping_t){EXTI4, GPIO_PORTA, GPIO_PIN_4, EXTI4_IRQ}
#define EXTI4_PB4		(EXTI_GPIO_Mapping_t){EXTI4, GPIO_PORTB, GPIO_PIN_4, EXTI4_IRQ}
#define EXTI4_PC4		(EXTI_GPIO_Mapping_t){EXTI4, GPIO_PORTC, GPIO_PIN_4, EXTI4_IRQ}
#define EXTI4_PD4		(EXTI_GPIO_Mapping_t){EXTI4, GPIO_PORTD, GPIO_PIN_4, EXTI4_IRQ}

// EXTI5
#define EXTI5_PA5		(EXTI_GPIO_Mapping_t){EXTI5, GPIO_PORTA, GPIO_PIN_5, EXTI5_IRQ}
#define EXTI5_PB5		(EXTI_GPIO_Mapping_t){EXTI5, GPIO_PORTB, GPIO_PIN_5, EXTI5_IRQ}
#define EXTI5_PC5		(EXTI_GPIO_Mapping_t){EXTI5, GPIO_PORTC, GPIO_PIN_5, EXTI5_IRQ}
#define EXTI5_PD5		(EXTI_GPIO_Mapping_t){EXTI5, GPIO_PORTD, GPIO_PIN_5, EXTI5_IRQ}

// EXTI6
#define EXTI6_PA6		(EXTI_GPIO_Mapping_t){EXTI6, GPIO_PORTA, GPIO_PIN_6, EXTI6_IRQ}
#define EXTI6_PB6		(EXTI_GPIO_Mapping_t){EXTI6, GPIO_PORTB, GPIO_PIN_6, EXTI6_IRQ}
#define EXTI6_PC6		(EXTI_GPIO_Mapping_t){EXTI6, GPIO_PORTC, GPIO_PIN_6, EXTI6_IRQ}
#define EXTI6_PD6		(EXTI_GPIO_Mapping_t){EXTI6, GPIO_PORTD, GPIO_PIN_6, EXTI6_IRQ}

// EXTI7
#define EXTI7_PA7		(EXTI_GPIO_Mapping_t){EXTI7, GPIO_PORTA, GPIO_PIN_7, EXTI7_IRQ}
#define EXTI7_PB7		(EXTI_GPIO_Mapping_t){EXTI7, GPIO_PORTB, GPIO_PIN_7, EXTI7_IRQ}
#define EXTI7_PC7		(EXTI_GPIO_Mapping_t){EXTI7, GPIO_PORTC, GPIO_PIN_7, EXTI7_IRQ}
#define EXTI7_PD7		(EXTI_GPIO_Mapping_t){EXTI7, GPIO_PORTD, GPIO_PIN_7, EXTI7_IRQ}

// EXTI8
#define EXTI8_PA8		(EXTI_GPIO_Mapping_t){EXTI8, GPIO_PORTA, GPIO_PIN_8, EXTI8_IRQ}
#define EXTI8_PB8		(EXTI_GPIO_Mapping_t){EXTI8, GPIO_PORTB, GPIO_PIN_8, EXTI8_IRQ}
#define EXTI8_PC8		(EXTI_GPIO_Mapping_t){EXTI8, GPIO_PORTC, GPIO_PIN_8, EXTI8_IRQ}
#define EXTI8_PD8		(EXTI_GPIO_Mapping_t){EXTI8, GPIO_PORTD, GPIO_PIN_8, EXTI8_IRQ}

// EXTI9
#define EXTI9_PA9		(EXTI_GPIO_Mapping_t){EXTI9, GPIO_PORTA, GPIO_PIN_9, EXTI9_IRQ}
#define EXTI9_PB9		(EXTI_GPIO_Mapping_t){EXTI9, GPIO_PORTB, GPIO_PIN_9, EXTI9_IRQ}
#define EXTI9_PC9		(EXTI_GPIO_Mapping_t){EXTI9, GPIO_PORTC, GPIO_PIN_9, EXTI9_IRQ}
#define EXTI9_PD9		(EXTI_GPIO_Mapping_t){EXTI9, GPIO_PORTD, GPIO_PIN_9, EXTI9_IRQ}

// EXTI10
#define EXTI10_PA10		(EXTI_GPIO_Mapping_t){EXTI10, GPIO_PORTA, GPIO_PIN_10, EXTI10_IRQ}
#define EXTI10_PB10		(EXTI_GPIO_Mapping_t){EXTI10, GPIO_PORTB, GPIO_PIN_10, EXTI10_IRQ}
#define EXTI10_PC10		(EXTI_GPIO_Mapping_t){EXTI10, GPIO_PORTC, GPIO_PIN_10, EXTI10_IRQ}
#define EXTI10_PD10		(EXTI_GPIO_Mapping_t){EXTI10, GPIO_PORTD, GPIO_PIN_10, EXTI10_IRQ}

// EXTI11
#define EXTI11_PA11		(EXTI_GPIO_Mapping_t){EXTI11, GPIO_PORTA, GPIO_PIN_11, EXTI11_IRQ}
#define EXTI11_PB11		(EXTI_GPIO_Mapping_t){EXTI11, GPIO_PORTB, GPIO_PIN_11, EXTI11_IRQ}
#define EXTI11_PC11		(EXTI_GPIO_Mapping_t){EXTI11, GPIO_PORTC, GPIO_PIN_11, EXTI11_IRQ}
#define EXTI11_PD11		(EXTI_GPIO_Mapping_t){EXTI11, GPIO_PORTD, GPIO_PIN_11, EXTI11_IRQ}

// EXTI 12
#define EXTI12_PA12		(EXTI_GPIO_Mapping_t){EXTI12, GPIO_PORTA, GPIO_PIN_12, EXTI12_IRQ}
#define EXTI12_PB12		(EXTI_GPIO_Mapping_t){EXTI12, GPIO_PORTB, GPIO_PIN_12, EXTI12_IRQ}
#define EXTI12_PC12		(EXTI_GPIO_Mapping_t){EXTI12, GPIO_PORTC, GPIO_PIN_12, EXTI12_IRQ}
#define EXTI12_PD12		(EXTI_GPIO_Mapping_t){EXTI12, GPIO_PORTD, GPIO_PIN_12, EXTI12_IRQ}

// EXTI 13
#define EXTI13_PA13		(EXTI_GPIO_Mapping_t){EXTI13, GPIO_PORTA, GPIO_PIN_13, EXTI13_IRQ}
#define EXTI13_PB13		(EXTI_GPIO_Mapping_t){EXTI13, GPIO_PORTB, GPIO_PIN_13, EXTI13_IRQ}
#define EXTI13_PC13		(EXTI_GPIO_Mapping_t){EXTI13, GPIO_PORTC, GPIO_PIN_13, EXTI13_IRQ}
#define EXTI13_PD13		(EXTI_GPIO_Mapping_t){EXTI13, GPIO_PORTD, GPIO_PIN_13, EXTI13_IRQ}

// EXTI 14
#define EXTI14_PA14		(EXTI_GPIO_Mapping_t){EXTI14, GPIO_PORTA, GPIO_PIN_14, EXTI14_IRQ}
#define EXTI14_PB14		(EXTI_GPIO_Mapping_t){EXTI14, GPIO_PORTB, GPIO_PIN_14, EXTI14_IRQ}
#define EXTI14_PC14		(EXTI_GPIO_Mapping_t){EXTI14, GPIO_PORTC, GPIO_PIN_14, EXTI14_IRQ}
#define EXTI14_PD14		(EXTI_GPIO_Mapping_t){EXTI14, GPIO_PORTD, GPIO_PIN_14, EXTI14_IRQ}

// EXTI 15
#define EXTI15_PA15		(EXTI_GPIO_Mapping_t){EXTI15, GPIO_PORTA, GPIO_PIN_15, EXTI15_IRQ}
#define EXTI15_PB15		(EXTI_GPIO_Mapping_t){EXTI15, GPIO_PORTB, GPIO_PIN_15, EXTI15_IRQ}
#define EXTI15_PC15		(EXTI_GPIO_Mapping_t){EXTI15, GPIO_PORTC, GPIO_PIN_15, EXTI15_IRQ}
#define EXTI15_PD15		(EXTI_GPIO_Mapping_t){EXTI15, GPIO_PORTD, GPIO_PIN_15, EXTI15_IRQ}





/* =============== Configuration Reference =============== */
#define EXTI0		0
#define EXTI1		1
#define EXTI2		2
#define EXTI3		3
#define EXTI4		4
#define EXTI5		5
#define EXTI6		6
#define EXTI7		7
#define EXTI8		8
#define EXTI9		9
#define EXTI10		10
#define EXTI11		11
#define EXTI12		12
#define EXTI13		13
#define EXTI14		14
#define EXTI15		15



// ===================================
// @ref EXTI_Trigger_define
// ===================================
#define EXTI_Trigger_Rising						0
#define EXTI_Trigger_Falling					1
#define EXTI_Trigger_Rising_And_Falling			2


// ==================================
// @ref EXTI_IRQ_define
// ==================================
#define EXTI_IRQ_Enable					1
#define EXTI_IRQ_Disable				0


/*
 * ==============================================================================================
 * 								APIs Supported By "MCAL EXTI DRIVER"
 * ==============================================================================================
 */

void MCAL_EXTI_GPIO_Init		(EXTI_PinConfig_t* EXTI_Config);
void MCAL_EXTI_GPIO_DeInit		(void);

void MCAL_EXTI_GPIO_Update		(EXTI_PinConfig_t* EXTI_Config);









#endif /* INCLUDE_FOLDER_STM32_F103C6_EXTI_DRIVER_H_ */
