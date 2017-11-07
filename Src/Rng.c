/*
 * Rng.c
 *
 *  Created on: Oct 31, 2017
 *      Author: user
 */

#include "Rng.h"
void generateRandomNumber(void){
	Rng->CR = RNG_RNGEN;
}

/**
 * Find out if RNG has produced a random number
 *  0 if not ready
 *  1 if random number is ready
 */

int isRandomNumberAvailable(){
	return Rng->SR & RNG_DRDY;
}

/**
 * Find out if RNG has encountered any error
 *  0 if no error
 *  Non-Zero if error
 */


int isAnyError(){
	return Rng->SR & (RNG_FAULTY_SEQUENCE | RNG_FAULTY_CLK);
}

/**
 * Find out if RNG has encountered any faulty random sequence
 *  0 if no error
 *  Non-Zero if error
 */


int isFaultyRandomSequence(void){
	return Rng->SR & RNG_FAULTY_SEQUENCE;
}

/**
 * Get a random number. This is blocking function
 */

int getRandomNumber(){
	do{
	generateRandomNumber();
	while(isRandomNumberAvailable());
	}while(isFaultyRandomSequence());
	return Rng->DR;
}

void getRandomNumberByInterrupt(void){
	Rng-> CR |= RNG_RNGEN;
	Rng-> CR |= RNG_IE;
}
