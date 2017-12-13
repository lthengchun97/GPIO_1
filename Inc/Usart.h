/*
 * Usart.h
 *
 *  Created on: Dec 12, 2017
 *      Author: user8
 */

#ifndef USART_H_
#define USART_H_
#include <stdint.h>

#define		USART1_BASE_ADDR		0x40011000
#define		USART6_BASE_ADDR		0x40011400
#define 	usart1 			((UsartReg *)(USART1_BASE_ADDR))
#define 	usart6 			((UsartReg *)(USART6_BASE_ADDR))

typedef struct UsartReg UsartReg;
struct UsartReg {
	volatile uint32_t SR;			//0x00
	volatile uint32_t DR;			//0x04
	volatile uint32_t BRR;			//0x08
	volatile uint32_t CR1;			//0x0c
	volatile uint32_t CR2;			//0x10
	volatile uint32_t CR3;			//0x14
	volatile uint32_t GTPR;			//0x18
};


#define	UE_ENABLE			(1<<13)
#define	Oversampling_16		(1<<15)
#define	M8Data				(1<<12)
#define	M9Data				(1<<12)
#define	StopBit_1			0
#define	StopBit_0_5			1
#define	StopBit_2			2
#define	StopBit_1_5			3
#define PCE_ENABLE			(1<<10)
#define	OddParity			(1<<9)
#define	TE_EN				(1<<3)
#define	RE_EN				(1<<2)
#define	SR_TC				(1<<6)
#define	SR_TXE				(1<<7)

void initUsartTransmitter();
void initUsartReceiver();
void writeData(uint32_t data);
void initUsart();
void USARTSendCharDataOut(char* data);

#endif /* USART_H_ */
