/*
 * 7_segment.h
 *
 *  Created on: Nov 16, 2021
 *      Author: Abdallah
 */

#ifndef SEVEN_SEGMENT_DRIVER_7_SEGMENT_H_
#define SEVEN_SEGMENT_DRIVER_7_SEGMENT_H_

/* ====================== Includes ================== */
#include "STM32F103X6.h"
#include "STM32_F103C6_GPIO_Driver.h"

// ------------ Global Variable ------------
GPIO_PinConfig_t PinCfg;

/* ===== 7 Segments Macros Definitions ===== */

#define ZERO		0x01
#define ONE			0x79
#define TWO			0x24
#define THREE		0x30
#define FOUR		0X4C
#define FIVE 		0x12
#define SIX			0x02
#define SEVEN		0x19
#define EIGHT		0x00
#define NINE		0x10

/* ========== Functions Prototypes ========== */
void Init_7_segment (void);

#endif /* 7_SEGMENT_DRIVER_7_SEGMENT_H_ */
