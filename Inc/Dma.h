/*
 * Dma.h
 *
 *  Created on: Dec 19, 2017
 *      Author: user8
 */

#include <stdint.h>
#include "Timer.h"
#ifndef DMA_H_
#define DMA_H_

#define		DMA1_BASE_ADDR		0x40026000
#define		DMA2_BASE_ADDR		0x40026400
#define 	dma1 			((DmaReg *)(DMA1_BASE_ADDR))
#define 	dma2 			((DmaReg *)(DMA2_BASE_ADDR))

// DMA Interrupt status register (xISR)
#define	DMA_FEIF		1
#define	DMA_DMEIF		(1<<2)
#define	DMA_TEIF		(1<<3)
#define	DMA_HTIF		(1<<4)
#define	DMA_TCIF		(1<<5)

#define	dmaStreamTCIF(d,s)		dmaStreamCheckFlag(d,s,DMA_TCIF)
#define	dmaStreamHTIF(d,s)		dmaStreamCheckFlag(d,s,DMA_HTIF)
#define	dmaStreamTEIF(d,s)		dmaStreamCheckFlag(d,s,DMA_TEIF)
#define	dmaStreamDMEIF(d,s)		dmaStreamCheckFlag(d,s,DMA_DMEIF)
#define	dmaStreamFEIF(d,s)		dmaStreamCheckFlag(d,s,DMA_FEIF)

typedef struct DmaStringReg DmaStringReg;
struct DmaStringReg{
	volatile uint32_t CR;
	volatile uint32_t NDTR;
	volatile uint32_t PAR;
	volatile uint32_t M0AR;
	volatile uint32_t M1AR;
	volatile uint32_t FCR;
};


typedef struct DmaReg DmaReg;
struct DmaReg {
	volatile uint32_t LISR;			//0x00
	volatile uint32_t HISR;			//0x04
	volatile uint32_t LIFCR;		//0x08
	volatile uint32_t HIFCR;		//0x0c
	DmaStringReg S[8];
};

// Channel Selection
#define	CH0		(0<<25)
#define	CH1		(1<<25)
#define	CH2		(2<<25)
#define	CH3		(3<<25)
#define	CH4		(4<<25)
#define	CH5		(5<<25)
#define	CH6		(6<<25)
#define	CH7		(7<<25)

// MBURST
#define	SINGLE_TRANSFER		(0<<23)
#define	INCR_4				(1<<23)
#define	INCR_8				(2<<23)
#define	INCR_16				(3<<23)

// PBURST
#define	P_SINGLE_TRANSFER		(0<<21)
#define	P_INCR_4				(1<<21)
#define	P_INCR_8				(2<<21)
#define	P_INCR_16				(3<<21)

// Buffer mode
#define	DOUBLE_BUFFER_MODE		(1<<18)

// Priority level
#define	L_Priority		(0<<16)
#define	M_Priority		(1<<16)
#define	H_Priority		(2<<16)
#define	VH_Priority		(3<<16)

// Peripheral increment offset size
#define	FIXED_TO_4		(1<<15)
#define	FIXED_TO_PSZIE	(0<<15)

// Memory data size
#define	MEM_1_BYTE		(0<<13)
#define	MEM_HALF_BYTE	(1<<13)
#define	MEM_ONE_WORD	(2<<13)

// Pheriperal data size
#define	PHE_1_BYTE		(0<<11)
#define	PHE_HALF_BYTE	(1<<11)
#define	PHE_ONE_WORD	(2<<11)

// Memory Increment mode
#define	MINC_EN			(1<<10)


// Circular mode
#define	CIRC_EN		(1<<8)

// Data Transfer Direction
#define	PHE_TO_MEM	(0<<6)
#define	MEM_TO_PHE	(1<<6)
#define	MEM_TO_MEM	(2<<6)

// Stream enable
#define	STREAM_EN	1

// FIFO threshold selection
#define	FIFO_1_OF_4		(0)
#define	FIFO_1_OF_2		(1)
#define	FIFO_3_OF_4		(2)
#define	FIFO_FULL		(3)

// Peripheral control flow
#define	DMA_FLOW		(0<<5)

// dma1->S[4].M0AR = 0;

void initDmaForUsart1(char* data);
int dmaStreamCheckFlag(DmaReg *dma,int streamNum,int flag);
void serialPrint(char *format,...);
void sendBitPattern(uint8_t data);
#endif /* DMA_H_ */
