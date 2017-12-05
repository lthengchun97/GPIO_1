/*
 * i2c.h
 *
 *  Created on: Nov 28, 2017
 *      Author: user8
 */

#ifndef I2C_H_
#define I2C_H_

#include <stdint.h>
#define I2C1_BASE_ADDR	0x40005400
#define I2C2_BASE_ADDR	0x40005800
#define I2C3_BASE_ADDR	0x40005C00
#define I2C1 	((I2cReg *)(I2C1_BASE_ADDR))
#define I2C2 	((I2cReg *)(I2C2_BASE_ADDR))
#define I2C3 	((I2cReg *)(I2C3_BASE_ADDR))


typedef struct I2cReg I2cReg;
struct I2cReg {
	volatile uint32_t CR1;		//0h
	volatile uint32_t CR2;		//4h
	volatile uint32_t OAR1;		//8h
	volatile uint32_t OAR2;		//0Ch
	volatile uint32_t DR;		//10h
	volatile uint32_t SR1;		//14h
	volatile uint32_t SR2;		//18h
	volatile uint32_t CCR;		//1Ch
	volatile uint32_t TRISE;	//20h
	volatile uint32_t FLTR;		//24h
};

void initI2C(void);
void TestI2C(void);

#endif /* I2C_H_ */
