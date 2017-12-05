/*
` * i2c.c
 *
 *  Created on: Nov 28, 2017
 *      Author: user8
 */

#include "i2c.h"
#include "Gpio.h"
#include "Rcc.h"
#include "DbgMcu.h"

void initI2C(void){

	// I2C1 as Master
	gpioConfigAltFunction(GpioB,6,AF4);
	gpioConfig(GpioB,6, GPIO_MODE_AF , GPIO_OPEN_DRAIN , GPIO_PULL_UP , GPIO_HI_SPEED);
	gpioConfigAltFunction(GpioB,7,AF4);
	gpioConfig(GpioB,7, GPIO_MODE_AF , GPIO_OPEN_DRAIN , GPIO_PULL_UP , GPIO_HI_SPEED);
	enableI2C1();
	I2C1->CR1 |= 1;
	I2C1->CCR &= ~(1<<15);
	I2C1->CCR &= ~(1<<14);
	I2C1->CCR |= 80;
	I2C1->CR2 |= 8;
	I2C1->TRISE |= 9;
	I2C1->CR1 |=(1<<8);

	// I2C2 as Slave
	gpioConfigAltFunction(GpioF,0,AF4);
	gpioConfig(GpioF,0, GPIO_MODE_AF , GPIO_OPEN_DRAIN , GPIO_PULL_UP , GPIO_HI_SPEED);
	gpioConfigAltFunction(GpioF,1,AF4);
	gpioConfig(GpioF,1, GPIO_MODE_AF , GPIO_OPEN_DRAIN , GPIO_PULL_UP , GPIO_HI_SPEED);
	enableI2C2();

}

void TestI2C(void){
	initI2C();
	haltI2C1WhenDebugging();
	haltI2C2WhenDebugging();
}






