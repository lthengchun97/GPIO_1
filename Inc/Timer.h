/*
 * Timer.h
 *
 *  Created on: Nov 21, 2017
 *      Author: user8
 */

#ifndef TIMER_H_
#define TIMER_H_

#include	"stdint.h"

#define TIMER8_BASE_ADDR		0x40010400
#define timer8 			((TimerReg *)(TIMER8_BASE_ADDR))

#define TIM_SEL_OC		0

typedef struct TimerReg TimerReg;
struct TimerReg {
	volatile uint32_t CR1;			//0x00
	volatile uint32_t CR2;			//0x04
	volatile uint32_t SMCR;			//0x08
	volatile uint32_t DIER;			//0x0c
	volatile uint32_t SR;			//0x10
	volatile uint32_t EGR;			//0x14
	volatile uint32_t CCMR1;		//0x18
	volatile uint32_t CCMR2;		//0x1c
	volatile uint32_t CCER;			//0x20
	volatile uint32_t CNT;			//0x24
	volatile uint32_t PSC;			//0x28
	volatile uint32_t ARR;			//0x2C
	volatile uint32_t RCR;			//0x30
	volatile uint32_t CCR1;			//0x34
	volatile uint32_t CCR2;			//0x38
	volatile uint32_t CCR3;			//0x3C
	volatile uint32_t CCR4;			//0x40
	volatile uint32_t BDTR;			//0x44
	volatile uint32_t DCR;			//0x48
	volatile uint32_t DMAR;			//0x4C
};
/*
#define	timSelChn1AsOC(tim, mode)				\
		do{									\
		(tim)-> CCMR1 &=~ (3<< 0);		/*force CC1S[1:0]=0

}while(0)
*/
// Configure CCER
#define		CC1_HIGH			(0<<1)
#define		CC1_LOW				(1<<1)
#define		CC1_OUTPUT_ENABLE	(1)
#define		CC3_ENABLE			(1<<8)
#define		CC4_ENABLE			(1<<12)
#define		CC1_ENABLE			(1)


// Configure CR2
#define		NO_CC_PRELOAD_CONTROL	0

// Configure BDTR
#define		MOE_EN				(1<<15)

// Configure CCMR1
#define		CCMR1_CC_OUT		(0)
#define		ACTIVE_HIGH			(5<<4)
#define		ACTIVE_LOW			(4<<4)
#define		OCP1E_EN			(1<<3)

#define		TOGGLE_WAVE			(3<<4)

void Timer8Delay();
void initTimer8();
void forceOutCompareChannel1High();
void forceOutCompareChannel1Low();
void initOutputCompare();
void toggleOutCompareChannel1WithForce();
#endif /* TIMER_H_ */
