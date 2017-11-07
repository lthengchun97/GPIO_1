/*
 * extiReg.h
 *
 *  Created on: Nov 7, 2017
 *      Author: user8
 */

#ifndef EXTIREG_H_
#define EXTIREG_H_

#include <stdint.h>
#define 	EXTI_BASE_ADDR			0x40013C00
#define		EXTI					((ExTiReg *)(EXTI_BASE_ADDR))

typedef struct ExTiReg ExTiReg;
struct ExTiReg {
	volatile uint32_t IMR;				//Control and status register
	volatile uint32_t EMR;				//Reload value register
	volatile uint32_t RTSR;				//Current counter value register
	volatile uint32_t FTSR;				//Calibration value register
	volatile uint32_t SWIER;
	volatile uint32_t PR;
};

#define exTiIMREnable(bits)				(EXTI->IMR |= (1<<bits))
#define exTiIMRDisable(bits)			(EXTI->IMR &= ~(1<<bits))
#define exTiEMREnable(bits)				(EXTI->EMR |= (1<<bits))
#define exTiEMRDisable(bits)			(EXTI->EMR &= ~(1<<bits))
#define exTiRTSREnable(bits)			(EXTI->RTSR |= (1<<bits))
#define exTiRTSRDisable(bits)			(EXTI->RTSR &= ~(1<<bits))
#define exTiFTSREnable(bits)			(EXTI->FTSR |= (1<<bits))
#define exTiFTSRDisable(bits)			(EXTI->FTSR &= ~(1<<bits))
#define exTiSWIER(bits)					(EXTI->SWIER |= bits)
#define exTiPRClr(bits)					(EXTI->PR |= (1<<bits))
#define exTiPRRead						(EXTI->PR)

#endif /* EXTIREG_H_ */
