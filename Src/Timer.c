/*
 * Timer.c
 *
 *  Created on: Nov 21, 2017
 *      Author: user8
 */

#include "Timer.h"
#include "Rcc.h"
#include "Gpio.h"

void initTimer8(){
	// Enable timer 8 -- unreset, enable clk
	//...
	enableTimer8();
	// Configure the maximum counter value by setting ARR
	timer8->ARR = 5000;

	// Configure the prescalar by setting PSC
	timer8->PSC = 9000;

	// Select the clock source (internal clk)  -- Set SMCR:SMS[2:0] = 0
	timer8->SMCR &= 0xfff8;

	// Enable timer 0 CR1:CEN -> 1

	timer8->CR1 |= 0x01;
}

void Timer8Delay(){
	while(!(timer8->SR&0x01)){

	}
	timer8->SR &= ~(0x01);
}

void initTimer8Channel1(){
	// Enable timer 8 -- unreset, enable clk
		//...
		//enableTimer8();
		// Configure the maximum counter value by setting ARR
		timer8->ARR = 0xffff;

		// Configure the prescalar by setting PSC
		timer8->PSC = 4;

		// Select the clock source (internal clk)  -- Set SMCR:SMS[2:0] = 0
		timer8->SMCR &= 0xfff8;

		// Enable timer 0 CR1:CEN -> 1

		timer8->CR1 |= 0x01;
	//Configure Timer 8 channel 1 pin (PC6) -- Enable PORTC, set pin as AltFunc3 Out-PP
	//...
		gpioConfig(GpioC,AF3,GPIO_MODE_AF,GPIO_PUSH_PULL,GPIO_NO_PULL,GPIO_VHI_SPEED);
		gpioConfigAltFunction(GpioC,6,AF3);
	// Configure channel 1 as output compare --
}

void initTimer8Channel3(){
	//Configure Timer 8 channel 1 pin (PC8) -- Enable PORTC, set pin as AltFunc3 In
	//...

	// Configure channel 3 as input
}
