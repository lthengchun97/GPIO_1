/*
 * Dma.c
 *
 *  Created on: Dec 19, 2017
 *      Author: user8
 */

#include "Dma.h"
#include "rcc.h"
#include "stdio.h"
#include "Usart.h"
#include "Timer.h"



/*
 * DMA2.stream7.channel4 = USART1.Tx
 * DMA2.stream2.channel4 = USART1.Rx
 *
 * PSIZE = 1 byte
 * MSIZE = 1 byte
 *
 * MBURST = In 8 bits increment
 * FIFO_BURST = 1/2 threshold
 *
 * PINC = no
 * MINC = yes
 *
 * Circular mode = no
 * Double buffer = no
 *
 * priority = high
 *
 * flow controller = DMA
 *
 * Transfer direction = memory to peripheral (Tx)
 * Transfer direction = peripheral to memory (Rx)
 *
 */

void initDmaForUsart1(char* data){
	dma2->S[7].CR &= ~(7<<25);
	dma2->S[7].CR &= ~(STREAM_EN);
	dma2->S[7].CR = PHE_1_BYTE | MEM_1_BYTE | INCR_8 | MINC_EN | H_Priority | DMA_FLOW |MEM_TO_PHE | CH4 /*|CIRC_EN*/;
	dma2->S[7].FCR |= FIFO_1_OF_2;
	dma2->S[7].M0AR = data;
	dma2->S[7].NDTR = 14;
	dma2->S[7].PAR =&(usart1->DR);
	dma2->S[7].CR |= (STREAM_EN);

}


void sendBitPattern(uint8_t data){
	timer8->PSC = 2;
	timer8->CCER = CC1_HIGH | CC1_OUTPUT_ENABLE;
	timer8->SMCR &= ~(7);
	timer8->CCMR1 |= TOGGLE_WAVE;
	timer8->ARR = 125;
	timer8->CCR1 = 125;
	timer8->CNT = 124;
	timer8->CR1 |= 0x01;			// start timer8
	timer8->DIER |= (1<<9);			// CC1DE DMA request enable

	//dma2->S[2].CR &= ~(7<<25);
	dma2->S[2].CR &= ~(STREAM_EN);
	dma2->S[2].CR = PHE_HALF_BYTE | MEM_HALF_BYTE | INCR_4 | MINC_EN | VH_Priority | DMA_FLOW |MEM_TO_PHE | CH7 | P_SINGLE_TRANSFER;
	dma2->S[2].M0AR = &data;
	dma2->S[2].NDTR = 20;
	dma2->S[2].PAR = &(timer8->CCR1);
	dma2->S[2].CR |= (STREAM_EN);
}

void dmaSetAddressAndSize(uint32_t memoryAddr, uint32_t peripheralAddr, uint32_t size){
//need to implement
}

int dmaStreamCheckFlag(DmaReg *dma,int streamNum,int flag){
	int isUpper16 = FALSE;
	volatile uint32_t *intrStatusReg = &dma->LISR;
	if(streamNum >= 4){
		intrStatusReg = &dma ->HISR;
		streamNum -= 4;
	}
	if(streamNum >= 2){
		streamNum -= 2;
		isUpper16 = TRUE;
	}

	return *intrStatusReg & (flag << (6 * streamNum + 16 * isUpper16));

}


