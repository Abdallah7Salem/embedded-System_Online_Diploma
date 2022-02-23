/*
 * Utils.h
 *
 * Created: 11/2/2021 11:36:26 PM
 *  Author: Abdallah
 */ 


#ifndef UTILS_H_
#define UTILS_H_

// set bit to 1
#define SETBIT(reg, bit)         (reg |= (1<<bit))

// clear bit to 0 
#define CLEARBIT(reg, bit)       (reg &= ~(1<<bit))

// read bit digital value ( 1 or 0 )
#define READBIT(reg, bit)        ((reg>>bit) & 1)

#define TOGGLEBIT(reg, bit)      (reg ^= (1<<bit))



#endif /* UTILS_H_ */