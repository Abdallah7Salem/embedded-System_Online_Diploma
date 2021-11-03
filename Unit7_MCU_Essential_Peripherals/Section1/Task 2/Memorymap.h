/*
 * Memorymap.h
 *
 * Created: 11/3/2021 12:36:35 PM
 *  Author: Abdallah
 */ 


#ifndef MEMORYMAP_H_
#define MEMORYMAP_H_

#define PORTA *((volatile unsigned char *)0x3B)
#define DDRA  *((volatile unsigned char *)0x3A)
#define PINA  *((volatile unsigned char *)0x39)

#define PORTB *((volatile unsigned char *)0x38)
#define DDRB  *((volatile unsigned char *)0x37)
#define PINB  *((volatile unsigned char *)0x36)

#define PORTC *((volatile unsigned char *)0x35)
#define DDRC  *((volatile unsigned char *)0x34)
#define PINC  *((volatile unsigned char *)0x33)


#endif /* MEMORYMAP_H_ */