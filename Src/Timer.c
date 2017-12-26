/*
 * Timer.c
 *
 *  Created on: Nov 21, 2017
 *      Author: user8
 */

#include "Timer.h"
#include "Rcc.h"
#include "Gpio.h"
void initTimer8Channel1(){
	// Enable timer 8 -- unreset, enable clk
		//...
		//enableTimer8();

		// Configure the maximum counter value by setting ARR
		timer8->ARR = 126;

		// Configure the prescalar by setting PSC
		timer8->PSC = 2;

		// Select the clock source (internal clk)  -- Set SMCR:SMS[2:0] = 0
		timer8->SMCR &= 0xfff8;

		// Enable timer 0 CR1:CEN -> 1

		timer8->CR1 |= 0x01;
	//Configure Timer 8 channel 1 pin (PC6) -- Enable PORTC, set pin as AltFunc3 Out-PP
	//...
		//gpioConfig(GpioC,AF3,GPIO_MODE_AF,GPIO_PUSH_PULL,GPIO_NO_PULL,GPIO_VHI_SPEED);
		//gpioConfigAltFunction(GpioC,6,AF3);
	// Configure channel 1 as output compare --
}
void initTimer8(){
	// Enable timer 8 -- unreset, enable clk
	//...
	enableTimer8();
	//timer8->CCMR1 |= TOGGLE_WAVE;
	//timer8->CCR1 = 12;
	//timer8->CNT = 120;

	// Configure the maximum counter value by setting ARR
	//timer8->ARR = 126;

	// Configure the prescalar by setting PSC
	//timer8->PSC = 2;

	// Select the clock source (internal clk)  -- Set SMCR:SMS[2:0] = 0
	//timer8->SMCR &= 0xfff8;

	// Enable timer 0 CR1:CEN -> 1

	//timer8->CR1 |= 0x01;

	gpioConfig(GpioC,6,GPIO_MODE_AF,GPIO_PUSH_PULL,GPIO_PULL_UP,GPIO_VHI_SPEED);
	gpioConfigAltFunction(GpioC,6,AF3);
}

void Timer8Delay(){
	while(!(timer8->SR&0x01)){

	}
	timer8->SR &= ~(0x01);
}



void initTimer8Channel3(){
	//Configure Timer 8 channel 1 pin (PC8) -- Enable PORTC, set pin as AltFunc3 In
	//...
	gpioConfig(GpioC,AF3,GPIO_MODE_AF,GPIO_PUSH_PULL,GPIO_NO_PULL,GPIO_VHI_SPEED);
	gpioConfigAltFunction(GpioC,8,AF3);
	// Configure channel 3 as input
}

/*	Output Compare Configuration:
 * Procedure:
 *1. Select the counter clock (internal, external, prescaler).
 *2. Write the desired data in the TIMx_ARR and TIMx_CCRx registers.
 *3. Set the CCxIE bit if an interrupt request is to be generated.
 *4. Select the output mode. For example:
 *	– Write OCxM = 011 to toggle OCx output pin when CNT matches CCRx
 *	– Write OCxPE = 0 to disable preload register
 *	– Write CCxP = 0 to select active high polarity
 *	– Write CCxE = 1 to enable the output
 *5. Enable the counter by setting the CEN bit in the TIMx_CR1 register.
 */

/*
 * Configure the Timer8 input capture and output compare as follows:
	1.	Un-reset and clock Timer 8.
	2.	Timer8 Output Compare Channel 1 on PC6.
	3.	Set OC1 pin as active high polarity (in CCER register).
	4.	Enable OC1 pin to generate an output (CC1E in CCER register).
	5.	No auto-reload preload of the Output Compare Channel 1 (CCPC in CR2 register).
	6.	Timer8 Input Capture Channels 3 and 4.
	7.	Channel3 as input capture direct mode and channel 4 as indirect mode on PC8
		(Note: TI3 is mapped on PC8. So choose this mode when configuring IC3 and IC4 on CCMR2 register.)
	8.	Channel3 captures on rising edge and channel4 captures on falling edge.  (No filtering on the input signal.)
	9.	Configure APB2 to 90MHz (using CubeMX32)
	10.	Prescale the timer clock frequency by 2
	11.	Use up-counting mode
	12.	Enable MOE bit in BDTR register (otherwise the timer Capture/Compare will not work)

 */

void initOutputCompare(){
	timer8->CCER = CC1_HIGH | CC1_OUTPUT_ENABLE;		// Output compare 1 mode force active high polarity
	timer8->CR2 |= NO_CC_PRELOAD_CONTROL;				// No auto-reload preload
	timer8->BDTR = MOE_EN;								// Enable MOE bit
}

void forceOutCompareChannel1High(){
	timer8->CCMR1 &= ~(7 << 4);		// Reset it first
	timer8->CCMR1 |= ACTIVE_HIGH;
}

void forceOutCompareChannel1Low(){
	timer8->CCMR1 &= ~(7 << 4);		// Reset it first
	timer8->CCMR1 |= ACTIVE_LOW;
}

void toggleOutCompareChannel1WithForce(){
	forceOutCompareChannel1High();
	forceOutCompareChannel1Low();
}
