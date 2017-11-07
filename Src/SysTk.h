/*
 * SysTk.h
 *
 *  Created on: Nov 7, 2017
 *      Author: user8
 */

#ifndef SYSTK_H_
#define SYSTK_H_

#include <stdint.h>
#define 	SYSTICK_BASE_ADDR		0xE000E010
#define		SysTick					((SysTickReg *)(SYSTICK_BASE_ADDR))

#define		SYSTICK_EN				1
#define		SYSTICK_INTER_EN		(1 << 1)
#define		SYSTICK_PROC_CLK_SRC	(1 << 2)
#define		SYSTICK_CNTR_OVERFLOW	(1 << 16)


typedef struct SysTickReg SysTickReg;
struct SysTickReg {
	volatile uint32_t CTRL;				//Control and status register
	volatile uint32_t LOAD;				//Reload value register
	volatile uint32_t VAL;				//Current counter value register
	volatile uint32_t CALIB;			//Calibration value register
};

#define sysTickEnable()				(SysTick->CTRL |= SYSTICK_EN)
#define sysTickDisable()			(SysTick->CTRL &= ~SYSTICK_EN)
#define sysTickIntrEnable()			(SysTick->CTRL |= SYSTICK_INTER_EN)
#define sysTickIntrDisable()		(SysTick->CTRL &= ~SYSTICK_INTER_EN)
#define sysTickSetReload(x)			(SysTick->LOAD = (x))
#define sysTickReadCounter(x)		(SysTick->VAL)
#define sysTickClrCounter()			(SysTick->CTRL = 0xbadface)
//Set systick to run @ processor speed
#define sysTickFullSpped()			(SysTick->CTRL |= SYSTICK_PROC_CLK_SRC)
//Set systick to run @ 1/8 of AHB frequency
#define sysTickPrescaleSpeed()		(SysTick->CTRL &= ~SYSTICK_PROC_CLK_SRC)
//Determine if SysTick timer has expired. Return none zero if has expired
#define sysTickHasExpired()			(SysTick->CTRL & SYSTICK_CNTR_OVERFLOW)
#endif /* SYSTK_H_ */
