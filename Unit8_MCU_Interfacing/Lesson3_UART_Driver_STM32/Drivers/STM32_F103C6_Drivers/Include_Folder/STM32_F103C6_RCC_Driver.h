/*
 * STM32_F103C6_GPIO_Driver.h
 *
 *  Created on: Nov 27, 2021
 *      Author: Abdallah
 */

#ifndef INCLUDE_FOLDER_STM32_F103C6_RCC_DRIVER_H_
#define INCLUDE_FOLDER_STM32_F103C6_RCC_DRIVER_H_

/* ========================================== Includes ================================================= */
#include "STM32F103X6.h" 							// 1) Device Header
#include "STM32_F103C6_GPIO_Driver.h"  				// 2) GPIO Used In Mapping The Input Line With The Pins
									   	   	   	   	// To Help Making Constraints For User Not To Use It Wrong

/* ========================================== Macros ================================================= */
#define HSE_Clock		(uint32_t)16000000
#define HSI_RC_Clk		(uint32_t)8000000


/* ========================================== APIs Prototype ================================================= */
uint32_t MCAL_RCC_GetSYS_CLKFreq(void);
uint32_t MCAL_RCC_GetHCLKFreq(void);
uint32_t MCAL_RCC_GetPCLK1Freq(void);
uint32_t MCAL_RCC_GetPCLK2Freq(void);



#endif /* INCLUDE_FOLDER_STM32_F103C6_RCC_DRIVER_H_ */
