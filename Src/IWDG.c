/*
 * IWDG.c
 *
 *  Created on: Jan 9, 2018
 *      Author: user8
 */

#include "IWDG.h"
#include "rcc.h"

void initIWDG(){

	IWDG->KR = PR_RLR_EN;
	IWDG->PR = IWDG_PRESCALE_64;

	IWDG->RLR = 2000;
	IWDG->KR = START_WD;

}

void initWWDG(int val,int val1){
	WWDG->CFR &= WWDG_MASK;
	WWDG->CFR |= (val <<7);
	WWDG->CFR |= WDDG_T6 | val1;
}
