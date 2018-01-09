/*
 * IWDG.h
 *
 *  Created on: Jan 9, 2018
 *      Author: user8
 */

#ifndef IWDG_H_
#define IWDG_H_

#include <stdint.h>
#define IWDG_BASE_ADDR	0x40003000
#define WWDG_BASE_ADDR	0x40002C00
#define IWDG 	((IwdgReg *)(IWDG_BASE_ADDR))
#define WWDG 	((WwdgReg *)(WWDG_BASE_ADDR))

typedef struct IwdgReg IwdgReg;
struct IwdgReg {
	volatile uint32_t KR;		//0h
	volatile uint32_t PR;		//4h
	volatile uint32_t RLR;		//8h
	volatile uint32_t SR;		//0Ch
};

typedef struct WwdgReg WwdgReg;
struct WwdgReg {
	volatile uint32_t CR;		//0h
	volatile uint32_t CFR;		//4h
	volatile uint32_t SR;		//8h
};

//KR
#define	START_WD	(0xCCCC)
#define	PR_RLR_EN	(0x5555)
#define	RESET_WD	(0xAAAA)

//PR
#define	IWDG_PRESCALE_4			(0)
#define	IWDG_PRESCALE_8			(1)
#define	IWDG_PRESCALE_16		(2)
#define	IWDG_PRESCALE_32		(3)
#define	IWDG_PRESCALE_64		(4)
#define	IWDG_PRESCALE_128		(5)
#define	IWDG_PRESCALE_256		(6)

//SR
#define	IWDG_RVU				(1<<1)
#define	IWDG_PVU				1


//FOR WWDG

//CR
#define	WDG_EN		(1<<7)
#define	WDDG_T6		(1<<6)
//CFR
#define	COUNTER_1	(0)
#define	COUNTER_2	(1)
#define	COUNTER_4	(2)
#define	COUNTER_8	(3)
#define	WWDG_EWI	(1<<9)
#define	WWDG_MASK	(~0x7F)
#define	WWDG_EWI_FLAG (1)

#define	enableWindowWDG(to)			(WWDG->CR = WDG_EN | ((WDDG_T6 |to)& ~WWDG_MASK))
#define	resetWindowWDG(to)			(WWDG->CR = WDG_EN | ((WDDG_T6 | to)& ~WWDG_MASK))
#define	enableWakeUpInterrupt()		(WWDG->SR |= WWDG_EWI_FLAG)
#define	disableWakeUpInterrupt()	(WWDG->SR &= ~(WWDG_EWI_FLAG))


#define	wwdgSetUpPrescale(val)				\
	do{										\
		WWDG->CFR &= WWDG_MASK;				\
		WWDG->CFR |= (val <<7) & ~WWDG_MASK; \
	}while(0)

#define	wwdgSetUpWindowValue(val)			\
	do{										\
		WWDG->CFR &= WWDG_MASK;				\
		WWDG->CFR |= (WDDG_T6 | val) & ~WWDG_MASK;	    \
	}while(0)


#define	RVU_WHILE()			while(IWDG->SR & IWDG_RVU)
#define	PVU_WHILE()			while(IWDG->SR & IWDG_PVU)

void initIWDG();
void initWWDG(int val,int val1);

#endif /* IWDG_H_ */
