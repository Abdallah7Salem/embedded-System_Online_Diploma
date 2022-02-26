/*
 * STM32F103X6.h
 *
 *  Created on: Nov 11, 2021
 *      Author: Abdallah
 */

#ifndef INCLUDE_FOLDER_STM32F103X6_H_
#define INCLUDE_FOLDER_STM32F103X6_H_

/* =========================== Includes =========================== */
#include "stdint.h"
#include "stdlib.h"


/* ==================== Base Addresses of Memory =================== */

#define FLASH_MEMORY_BASE_ADDRESS				0x08000000UL  // UL means it is constant
#define SYSTEM_MEMORY_BASE_ADDRESS				0x1FFFF000UL
#define SRAM_MEMORY_BASE_ADDRESS				0x20000000UL

// Base Address of Peripherals
#define PERIPHERALS_BASE_ADDRESS				0x40000000UL

// Base Address of Cortex-m3 internal peripherals
#define CORTEX_M3_INTERNAL_PERIPHERALS			0xE0000000UL

/* ================= Base Addresses for AHB Peripherals ============== */

// RCC
#define RCC_BASE_ADDRESS                        0x40021000UL

// ---------------------- GPIO -----------------------------
// A, B fully included in LQFP48 Package
#define GPIO_PORTA_BASE_ADDRESS					0x40010800UL
#define GPIO_PORTB_BASE_ADDRESS 				0x40010C00UL

// C, D Partial included in LQFP48 Package
#define GPIO_PORTC_BASE_ADDRESS					0x40011000UL
#define GPIO_PORTD_BASE_ADDRESS					0x40011400UL

//E not included in LQFP48 Package
#define GPIO_PORTE_BASE_ADDRESS					0x40011800UL


// EXTI ( External Interrupt )
#define EXTI_BASE_ADDRESS 						0x40010400UL

// AFIO ( Alternative Function Input/Output )
#define AFIO_BASE_ADDRESS 						0x40010000UL

// NVIC ( Non-Vectored Interrupt Controller )
#define NVIC_BASE_ADDRESS						0xE000E100UL
#define NVIC_ISER0								*(volatile uint32_t *)(NVIC_BASE_ADDRESS + 0x00)
#define NVIC_ISER1								*(volatile uint32_t *)(NVIC_BASE_ADDRESS + 0x04)
#define NVIC_ISER2								*(volatile uint32_t *)(NVIC_BASE_ADDRESS + 0x08)
#define NVIC_ICER0								*(volatile uint32_t *)(NVIC_BASE_ADDRESS + 0x80)
#define NVIC_ICER1								*(volatile uint32_t *)(NVIC_BASE_ADDRESS + 0x84)
#define NVIC_ICER2								*(volatile uint32_t *)(NVIC_BASE_ADDRESS + 0x88)

// ---------------------- UART -----------------------------
#define USART1_BASE_ADDRESS						0x40013800UL


/* =================== Base Addresses for APB1 Peripherals ============= */

// ---------------------- UART -----------------------------
#define USART2_BASE_ADDRESS						0x40004400UL
#define USART3_BASE_ADDRESS						0x40004800UL

/* ============================================================================================== */

/* ===================== Peripheral Registers GPIO ===================== */
typedef struct
{
	// 1st element takes 1st 4 bytes
	volatile uint32_t CRL;  		 // 0x00 -> 0x04
	volatile uint32_t CRH;  		 // 0x04 -> 0x08
	volatile uint32_t IDR;  		 // 0x08 -> 0x0C
	volatile uint32_t ODR;  		 // 0x0C -> 0x10
	volatile uint32_t BSRR;  		 // 0x10 -> 0x14
	volatile uint32_t BRR;  		 // 0x14 -> 0x18
	volatile uint32_t LCKR; 		 // 0x18

}GPIO_TypeDef;


/* ===================== Peripheral Registers RCC  ===================== */
typedef struct
{
	volatile uint32_t CR;			  // 0x00
	volatile uint32_t CFGR;			  // 0x04
	volatile uint32_t CIR;			  // 0x08
	volatile uint32_t APB2RSTR;		  // 0x0C
	volatile uint32_t APB1RSTR;		  // 0x10
	volatile uint32_t AHBENR;		  // 0x14
	volatile uint32_t APB2ENR;		  // 0x18
	volatile uint32_t APB1ENR;		  // 0x1C
	volatile uint32_t BDCR;			  // 0x20
	volatile uint32_t CSR;			  // 0x24
}RCC_TypeDef;


/* ===================== Peripheral Registers EXTI ===================== */
typedef struct
{
	volatile uint32_t IMR;			  // 0x00
	volatile uint32_t EMR;			  // 0x04
	volatile uint32_t RTSR;			  // 0x08
	volatile uint32_t FTSR;			  // 0x0C
	volatile uint32_t SWIER;		  // 0x10
	volatile uint32_t PR;			  // 0x14

}EXTI_Typedef;


/* ===================== Peripheral Registers AFIO ===================== */
typedef struct
{
	volatile uint32_t EVCR;			  // 0x00
	volatile uint32_t MAPR;			  // 0x04
	volatile uint32_t EXTICR[4];	  // 0x08, 0x0C, 0x10, 0x14
	uint32_t  Reserved_0;    		  // 0x18
	volatile uint32_t MAPR2;		  // 0x1C
}AFIO_TypeDef;

/* ===================== Peripheral Registers USART ===================== */
typedef struct
{
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t BRR;
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t CR3;
	volatile uint32_t GTPR;
}USART_TypeDef;

/* ================================================================================================ */

/* ===================== Peripheral Instants  ========================== */

// Casting Addresses
// Casting GPIO
#define GPIO_PORTA					((GPIO_TypeDef*)GPIO_PORTA_BASE_ADDRESS)
#define GPIO_PORTB					((GPIO_TypeDef*)GPIO_PORTB_BASE_ADDRESS)
#define GPIO_PORTC					((GPIO_TypeDef*)GPIO_PORTC_BASE_ADDRESS)
#define GPIO_PORTD					((GPIO_TypeDef*)GPIO_PORTD_BASE_ADDRESS)
#define GPIO_PORTE					((GPIO_TypeDef*)GPIO_PORTE_BASE_ADDRESS)

// Casting RCC
#define RCC							((RCC_TypeDef*)RCC_BASE_ADDRESS)
// Casting EXTI
#define EXTI						((EXTI_Typedef*)EXTI_BASE_ADDRESS)
// Casting AFIO
#define AFIO						((AFIO_TypeDef*)AFIO_BASE_ADDRESS)

// Casting USART
#define USART1						((USART_TypeDef*)USART1_BASE_ADDRESS)
#define USART2						((USART_TypeDef*)USART2_BASE_ADDRESS)
#define USART3						((USART_TypeDef*)USART3_BASE_ADDRESS)
/* ================================================================================================ */

/* ===================== Clock Enable Macros ========================== */

// Enable clock for Ports A, B, C, D, E
#define RCC_GPIO_PORTA_CLK_EN()		(RCC->APB2ENR |= 1 << 2)  //IOPA enable is in bit 2
#define RCC_GPIO_PORTB_CLK_EN()		(RCC->APB2ENR |= 1 << 3)  //IOPB enable is in bit 3
#define RCC_GPIO_PORTC_CLK_EN()		(RCC->APB2ENR |= 1 << 4)  //IOPC enable is in bit 4
#define RCC_GPIO_PORTD_CLK_EN()		(RCC->APB2ENR |= 1 << 5)  //IOPD enable is in bit 5
#define RCC_GPIO_PORTE_CLK_EN()		(RCC->APB2ENR |= 1 << 6)  //IOPE enable is in bit 6

// Enable clock for Alternative Function I/O
#define RCC_AFIO_CLK_EN()			(RCC->APB2ENR |= 1 << 0)  //AFIO enable is in bit 0

// Enable clock for USART
#define RCC_USART1_CLK_EN()			(RCC->APB2ENR |= 1 << 14)
#define RCC_USART2_CLK_EN()			(RCC->APB1ENR |= 1 << 17)
#define RCC_USART3_CLK_EN()			(RCC->APB1ENR |= 1 << 18)

// RCC Reset Mechanism
#define RCC_USART1_RESET()			(RCC->APB2RSTR |= 1 << 14)
#define RCC_USART2_RESET()			(RCC->APB1RSTR |= 1 << 17)
#define RCC_USART3_RESET()			(RCC->APB1RSTR |= 1 << 18)


/* ==================== Interrupt Vector Table ======================== */
// EXTI
#define EXTI0_IRQ		6
#define EXTI1_IRQ		7
#define EXTI2_IRQ		8
#define EXTI3_IRQ		9
#define EXTI4_IRQ		10
#define EXTI5_IRQ		23
#define EXTI6_IRQ		23
#define EXTI7_IRQ		23
#define EXTI8_IRQ		23
#define EXTI9_IRQ		23
#define EXTI10_IRQ		40
#define EXTI11_IRQ		40
#define EXTI12_IRQ		40
#define EXTI13_IRQ		40
#define EXTI14_IRQ		40
#define EXTI15_IRQ		40

#define USART1_IRQ		37
#define USART2_IRQ		38
#define USART3_IRQ		39

/* ================================================ NVIC IRQ Enable/Disable Macros =================================================== */

/* ========= Enable Interrupt Requests ====== */

// We Started From IRQ6 Due To DataSheet
// ISER : Interrupt Set Register

#define NVIC_IRQ6_EXTI0_Enable			(NVIC_ISER0 |= 1<<6)				// EXTI0 ---> PIN6 in NVIC
#define NVIC_IRQ7_EXTI1_Enable			(NVIC_ISER0 |= 1<<7)				// EXTI1 ---> PIN7 in NVIC
#define NVIC_IRQ8_EXTI2_Enable			(NVIC_ISER0 |= 1<<8)				// EXTI2 ---> PIN8 in NVIC
#define NVIC_IRQ9_EXTI3_Enable			(NVIC_ISER0 |= 1<<9)				// EXTI3 ---> PIN9 in NVIC
#define NVIC_IRQ10_EXTI4_Enable			(NVIC_ISER0 |= 1<<10)				// EXTI4 ---> PIN10 in NVIC
#define NVIC_IRQ23_EXTI5_9_Enable		(NVIC_ISER0 |= 1<<23)				// EXTI5, EXTI6, EXTI7, EXTI8, EXTI9 ---> PIN23 in NVIC

// 40 - 32 = 8
#define NVIC_IRQ40_EXTI10_15_Enable		(NVIC_ISER1 |= 1<<8)				// EXTI10, EXTI11, EXTI12, EXTI13, EXTI14, EXTI15
																			//  ---> PIN40 in NVIC

/* ======== Disable Interrupt Requests ====== */

// We Started From IRQ6 Due To DataSheet
// ICER : Interrupt Clear Register

#define NVIC_IRQ6_EXTI0_Disable			(NVIC_ICER0 |= 1<<6)				// EXTI0 ---> PIN6 in NVIC
#define NVIC_IRQ7_EXTI1_Disable			(NVIC_ICER0 |= 1<<7)				// EXTI1 ---> PIN7 in NVIC
#define NVIC_IRQ8_EXTI2_Disable			(NVIC_ICER0 |= 1<<8)				// EXTI2 ---> PIN8 in NVIC
#define NVIC_IRQ9_EXTI3_Disable			(NVIC_ICER0 |= 1<<9)				// EXTI3 ---> PIN9 in NVIC
#define NVIC_IRQ10_EXTI4_Disable		(NVIC_ICER0 |= 1<<10)				// EXTI4 ---> PIN10 in NVIC
#define NVIC_IRQ23_EXTI5_9_Disable		(NVIC_ICER0 |= 1<<23)				// EXTI5, EXTI6, EXTI7, EXTI8, EXTI9 ---> PIN23 in NVIC

// 40 - 32 = 8
#define NVIC_IRQ40_EXTI10_15_Disable	(NVIC_ICER1 |= 1<<8)				// EXTI10, EXTI11, EXTI12, EXTI13, EXTI14, EXTI15
																			//  ---> PIN40 in NVIC

// ----------------------------- USART ------------------------

// Enable
#define NVIC_IRQ37_USART1_Enable		(NVIC_ISER1 |= 1<<(USART1_IRQ - 32))	// IRQ - 32
#define NVIC_IRQ38_USART2_Enable		(NVIC_ISER1 |= 1<<(USART2_IRQ - 32))	// IRQ - 32
#define NVIC_IRQ39_USART3_Enable		(NVIC_ISER1 |= 1<<(USART3_IRQ - 32))	// IRQ - 32

// Disable
#define NVIC_IRQ37_USART1_Disable		(NVIC_ICER1 |= 1<<(USART1_IRQ - 32))	// IRQ - 32
#define NVIC_IRQ38_USART2_Disable		(NVIC_ICER1 |= 1<<(USART2_IRQ - 32))	// IRQ - 32
#define NVIC_IRQ39_USART3_Disable		(NVIC_ICER1 |= 1<<(USART3_IRQ - 32))	// IRQ - 32

















#endif /* INCLUDE_FOLDER_STM32F103X6_H_ */
