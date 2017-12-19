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




/*
 * DMA2.stream2.channel4 = USART1.Tx
 * DMA2.stream7.channel4 = USART1.Rx
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

void initDmaForUsart1(void){
	char* data = "Hello";
	dma2->S[7].CR &= ~(7<<25);
	dma2->S[7].CR &= ~(STREAM_EN);
	dma2->S[7].CR = PHE_1_BYTE | MEM_1_BYTE | INCR_8 | MINC_EN | H_Priority | DMA_FLOW |MEM_TO_PHE | CH4;
	dma2->S[7].FCR |= FIFO_1_OF_2;
	dma2->S[7].M0AR = data;
	dma2->S[7].NDTR = 5;
	dma2->S[7].PAR =&(usart1->DR);

	dma2->S[7].CR |= (STREAM_EN);


}

void dmaSetAddressAndSize(uint32_t memoryAddr, uint32_t peripheralAddr, uint32_t size){


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

