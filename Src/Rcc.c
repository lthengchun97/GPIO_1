/*
 * Rcc.c
 *
 *  Created on: Oct 27, 2017
 *      Author: Rex
 */
#include"Rcc.h"

uint32_t *rccAhb1Rst= (uint32_t *)(RCC_BASE_ADDR + RCC_AHB1RST_OFF);
uint32_t *rccAhb1En= (uint32_t *)(RCC_BASE_ADDR + RCC_AHB1EN_OFF);


void enableGpioA(void){
	//unreset GPIOG
	*rccAhb1Rst &= ~1;
	//Start clock of GPIOG
	*rccAhb1En |= 1;
}

void enableGpioB(void){
	//unreset GPIOG
	*rccAhb1Rst &= ~(1 << 1);
	//Start clock of GPIOG
	*rccAhb1En |= 1 << 1;
}

void enableGpioG(void){
	//unreset GPIOG
	*rccAhb1Rst &= ~(1 << 6);
	//Start clock of GPIOG
	*rccAhb1En |= 1 << 6;
}

void enableRng(void){
	Rcc->AHB2RSTR &= ~(1<<6);
	Rcc->AHB2ENR |= (1<<6);
}

void enableTimer8(void){

	Rcc->APB2RSTR &= ~(1<<1);
	Rcc->APB2ENR |= (1 <<1) ;
}
