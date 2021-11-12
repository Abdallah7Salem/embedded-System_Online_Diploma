/*
 * STM32F103X6.h
 *
 *  Created on: Nov 11, 2021
 *      Author: Abdallah
 */

#ifndef INCLUDE_FOLDER_STM32F103X6_H_
#define INCLUDE_FOLDER_STM32F103X6_H_

/* =========================== Includes =========================== */

#include "stdlib.h"
#include "Platform_Types.h"

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


/* =================== Base Addresses for APB1 Peripherals ============= */
// Add whatever you want when you need it

/* ============================================================================================== */

/* ===================== Peripheral Registers GPIO ===================== */
typedef struct
{
	// 1st element takes 1st 4 bytes
	vuint32_t CRL;  		 // 0x00 -> 0x04
	vuint32_t CRH;  		 // 0x04 -> 0x08
	vuint32_t IDR;  		 // 0x08 -> 0x0C
	vuint32_t ODR;  		 // 0x0C -> 0x10
	vuint32_t BSRR;  		 // 0x10 -> 0x14
	vuint32_t BRR;  		 // 0x14 -> 0x18
	vuint32_t LCKR; 		 // 0x18

}GPIO_TypeDef;


/* ===================== Peripheral Registers RCC  ===================== */
typedef struct
{
	vuint32_t CR;			  // 0x00
	vuint32_t CFGR;			  // 0x04
	vuint32_t CIR;			  // 0x08
	vuint32_t APB2RSTR;		  // 0x0C
	vuint32_t APB1RSTR;		  // 0x10
	vuint32_t AHBENR;		  // 0x14
	vuint32_t APB2ENR;		  // 0x18
	vuint32_t APB1ENR;		  // 0x1C
	vuint32_t BDCR;			  // 0x20
	vuint32_t CSR;			  // 0x24
}RCC_TypeDef;


/* ===================== Peripheral Registers EXTI ===================== */
typedef struct
{
	vuint32_t IMR;			  // 0x00
	vuint32_t EMR;			  // 0x04
	vuint32_t RTSR;			  // 0x08
	vuint32_t FTSR;			  // 0x0C
	vuint32_t SWIER;		  // 0x10
	vuint32_t PR;			  // 0x14

}EXTI_Typedef;


/* ===================== Peripheral Registers AFIO ===================== */
typedef struct
{
	vuint32_t EVCR;			  // 0x00
	vuint32_t MAPR;			  // 0x04
	vuint32_t EXTICR1;		  // 0x08
	vuint32_t EXTICR2;		  // 0x0C
	vuint32_t EXTICR3;		  // 0x10
	vuint32_t EXTICR4;		  // 0x14
	uint32_t  Reserved_0;     // 0x18
	vuint32_t MAPR2;		  // 0x1C
}AFIO_TypeDef;


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
#define EXTI						((EXTI_TypeDef*)EXTI_BASE_ADDRESS)
// Casting AFIO
#define AFIO						((AFIO_TypeDef*)AFIO_BASE_ADDRESS)

/* ================================================================================================ */

/* ===================== Clock Enable Macros ========================== */

// Enable clock for Ports A, B, C, D, E
#define RCC_GPIO_PORTA_CLK_EN()		(RCC->APB2ENR |= 1 << 2)  //IOPA enable is in bit 2
#define RCC_GPIO_PORTB_CLK_EN()		(RCC->APB2ENR |= 1 << 3)  //IOPB enable is in bit 3
#define RCC_GPIO_PORTC_CLK_EN()		(RCC->APB2ENR |= 1 << 4)  //IOPC enable is in bit 4
#define RCC_GPIO_PORTD_CLK_EN()		(RCC->APB2ENR |= 1 << 5)  //IOPD enable is in bit 5
#define RCC_GPIO_PORTE_CLK_EN()		(RCC->APB2ENR |= 1 << 6)  //IOPE enable is in bit 6

// Enable clock for Alternative Function I/O
#define AFIO_CLK_EN()				(RCC->APB2ENR |= 1 << 0)  //AFIO enable is in bit 0


#endif /* INCLUDE_FOLDER_STM32F103X6_H_ */
