/*
 * Platform_Types.h
 *
 * Created: 12/11/2021 1:55:04 AM
 *  Author: Abdallah
 */ 


#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

/* =============================== Symbols ====================== */
#define CPU_TYPE			CPU_TYPE_32
#define CPU_BIT_ORDER		LSB_FIRST
#define  CPU_BYTE_ORDER		LOW_BYTE_FIRST

/* ============================== Types ========================== */
typedef unsigned char boolean;

/* ========================
 *		  unsigned 
 * ========================
 */
typedef unsigned char uint8_t;
// typedef unsigned short uint16_t;
typedef unsigned long uint32_t;
typedef unsigned long long uint64_t;

/* =======================
 *		  signed 
 * =======================
 */
typedef signed char int8_t;
// typedef signed short int16_t;
typedef signed long int32_t;
typedef signed long long int64_t;

/* =======================
 *		  volatile 
 * =======================
 */

typedef volatile uint8_t		vuint8_t;
typedef volatile uint16_t		vuint16_t;
typedef volatile uint32_t		vuint32_t;
typedef volatile uint64_t		vuint64_t;

typedef volatile int8_t			vint8_t;
typedef volatile int16_t		vint16_t;
typedef volatile int32_t		vint32_t;
typedef volatile int64_t		vint64_t;	




#endif /* PLATFORM_TYPES_H_ */