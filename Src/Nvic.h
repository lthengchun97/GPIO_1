/*
 * Nvic.h
 *
 *  Created on: Oct 31, 2017
 *      Author: user8
 */

#ifndef NVIC_H_
#define NVIC_H_

#define NVIC_BASE_ADDR	0xE000E100
#define Nvic			((NvicReg *)(NVIC_BASE_ADDR))

typedef struct NvicReg NvicReg;
struct NvicReg {
	volatile uint32_t ISFR[3];					// Interrupt Set-Enable Register		(0h)
	volatile uint32_t reserved1[29];
	volatile uint32_t ICER[3];					// Interupt Clear-Enable Register		(80h)
	volatile uint32_t reserved2[29];
	volatile uint32_t ISPR[3];					// Interrupt Set-Pending Register		(100h)
	volatile uint32_t reserved3[29];
	volatile uint32_t ICPR[3];					// Interrupt Clear-Pending Register		(180h)
	volatile uint32_t reserved4[29];
	volatile uint32_t IABR[3];					//										(200h)
	volatile uint32_t reserved5[61];
	volatile uint32_t IPR[21];					//										(300h)
	volatile uint32_t reserved6[683];
	volatile uint32_t STIR;						//										(e00h)
};

#define nvicEnableIrq(irqNum)				(Nvic->ISFR[irqNum>>5] |= 1<< (irqNum & 0x1F))
#define nvicDisableIrq(irqNum)				(Nvic->ICER[irqNum>>5] |= 1<< (irqNum & 0x1F))
#define nvicSetPriority(irqNum,priority)	(Nvic->IPR[irqNum>>2] |= priority <<( (irqNum & 0x3)*8 + 4 ))

#endif /* NVIC_H_ */
