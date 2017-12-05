/*
 * Flash.h
 *
 *  Created on: Dec 5, 2017
 *      Author: user8
 */

#ifndef FLASH_H_
#define FLASH_H_

#include	"stdint.h"
#include	"Rcc.h"
#include	"string.h"

#define		FLASH_BASE_ADDR		0x40023C00
#define 	flash 			((FlashReg *)(FLASH_BASE_ADDR))

typedef struct FlashReg FlashReg;
struct FlashReg {
	volatile uint32_t ACR;			//0x00
	volatile uint32_t KEYR;			//0x04
	volatile uint32_t OPTKEYR;		//0x08
	volatile uint32_t SR;			//0x0c
	volatile uint32_t CR;			//0x10
	volatile uint32_t OPTCR;		//0x14
	volatile uint32_t OPTCR1;		//0x18
};

#define 	FLASH_BYTE_SIZE			0
#define		FLASH_HALFWORD_SIZE		1
#define		FLASH_WORD_SIZE			2
#define		FLASH_DOUBLEWORD_SIZE	3

#define		FLASH_ABC				((1<<24))
#define		FLASH_SECTOR_ERASE		((1<<1))
#define		FLASH_START				((1<<16))
#define		FLASH_PG				1

int	flashEraseSection(int sectionNum);
int	flashEnableProgramming(int programSize);
int	flashDisable(void);
int writeMessage(char *message,char *memoryIoWrite);


#endif /* FLASH_H_ */
