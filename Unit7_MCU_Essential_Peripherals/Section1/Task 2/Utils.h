/*
 * Utils.h
 *
 * Created: 11/3/2021 12:43:40 PM
 *  Author: Abdallah
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define SETBIT(reg, bit)      (reg |= (1<<bit))

#define RESETBIT(reg, bit)    (reg &= ~(1<<bit))

#define READBIT(reg, bit)     ((reg>>bit) & 1)

#define TOGGLEBIT(reg, bit)   (reg ^= (1<<bit))



#endif /* UTILS_H_ */