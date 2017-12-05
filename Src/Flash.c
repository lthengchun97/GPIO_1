/*
 * Flash.c
 *
 *  Created on: Dec 5, 2017
 *      Author: user8
 */

#include "Flash.h"
/**
 * Section erase the flash memory of STM32F729ZI6 MCU only
 * input  :
 * 	sectionNum is the section to erase
 * return :
 * 0	Fail to erase
 * 1	Successful
 */
int	flashEraseSection(int sectionNum){
	//Unlock through KEYR

	// 1 Set the sector number to erase
	// 2 Set the sector erase
	// 3 Start erase
	if(sectionNum > 11)
	{
		sectionNum = sectionNum +4;
	}
	flash->CR = ((sectionNum<<3)  |FLASH_SECTOR_ERASE |  FLASH_ABC | FLASH_START);
	// Check for failure or success
	return 1;			// successful to erase
	// Return status
}

/**
 * Enable flash programming with the stated program size
 * Input :
 * 	programSize is the size when writing into the flash:
 * 				FLASH_BYTE_SIZE
 * 				FLASH_HALFWORD_SIZE
 * 				FLASH_WORD_SIZE
 * 				FLASH_DOUBLEWORD_SIZE
 */

int	flashEnableProgramming(int programSize){
	flash->KEYR = 0x45670123;
	flash->KEYR = 0xCDEF89AB;
	flash->CR |= FLASH_PG;
	flash->CR |= (programSize << 8);
}

int	flashDisable(void){
	flash->CR &= ~(FLASH_PG);
}

int writeMessage(char *message,char *memoryIoWrite){
	//*memoryIoWrite = *message;
	strcpy(memoryIoWrite,message);
}
