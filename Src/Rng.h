/*
 * Rng.h
 *
 *  Created on: Oct 31, 2017
 *      Author: user
 */

#ifndef RNG_H_
#define RNG_H_
#include <stdint.h>
#define RNG_BASE_ADDR	0x50060800
#define Rng 	((RngReg *)(RNG_BASE_ADDR))


typedef struct RngReg RngReg;
struct RngReg {
	volatile uint32_t CR;		//0h
	volatile uint32_t SR;		//4h
	volatile uint32_t DR;		//8h
};
//Status Register
#define RNG_FAULTY_SEQUENCE (1 << 2)
#define RNG_FAULTY_CLK		(1 << 1)
#define RNG_DRDY			1
//Control Register
#define RNG_RNGEN			(1 << 2)
#define RNG_IE				(1 << 3)

int getRandomNumber();
int isFaultyRandomSequence(void);
int isAnyError();
int isRandomNumberAvailable();
void generateRandomNumber(void);
void getRandomNumberByInterrupt(void);

#endif /* RNG_H_ */

