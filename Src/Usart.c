/*
 * Usart.c
 *
 *  Created on: Dec 12, 2017
 *      Author: user8
 */

#include "Usart.h"



// Transmitter
//1. Enable the USART by writing the UE bit in USART_CR1 register to 1.
//2. Program the M bit in USART_CR1 to define the word length.
//3. Program the number of stop bits in USART_CR2.
//4. Select DMA enable (DMAT) in USART_CR3 if Multi buffer Communication is to take
//   place. Configure the DMA register as explained in multibuffer communication.
//5. Select the desired baud rate using the USART_BRR register.
//6. Set the TE bit in USART_CR1 to send an idle frame as first transmission.
//7. Write the data to send in the USART_DR register (this clears the TXE bit). Repeat this
//   for each data to be transmitted in case of single buffer.
//8. After writing the last data into the USART_DR register, wait until TC=1. This indicates
//   that the transmission of the last frame is complete. This is required for instance when
//   the USART is disabled or enters the Halt mode to avoid corrupting the last
//   transmission.

// Receiver
//1. Enable the USART by writing the UE bit in USART_CR1 register to 1.
//2. Program the M bit in USART_CR1 to define the word length.
//3. Program the number of stop bits in USART_CR2.
//4. Select DMA enable (DMAR) in USART_CR3 if multibuffer communication is to take
//   place. Configure the DMA register as explained in multibuffer communication. STEP 3
//5. Select the desired baud rate using the baud rate register USART_BRR
//6. Set the RE bit USART_CR1. This enables the receiver which begins searching for a
//   start bit.

void initUsartTransmitter(){
	usart1->CR1 |= TE_EN;
}

void initUsartReceiver(){
	usart1->CR1 |= RE_EN;
}

void writeData(uint32_t data){
	while(!(usart1->SR&(SR_TXE))){

	}
	usart1->DR = data;
}

void initUsart(){
		usart1->CR1 |= UE_ENABLE;
		usart1->CR1 |= (M9Data);			// 9-bit data
		usart1->CR2 &= ~(3<<12);			// clear the stop bit first
		usart1->CR2 |= (StopBit_2 <<12);	// set 2 stop bit
		usart1->CR1 &= ~(Oversampling_16);	// oversampling by 16
		usart1->CR1 |= PCE_ENABLE;			// enable Parity control
		usart1->CR1 |= OddParity;			// set the parity selection as odd parity
		usart1->BRR = 13;					// div_fraction as 8
		usart1->BRR |= (0x30<<4);			// div_mantissa as 48

}

void USARTSendCharDataOut(char* data){
	while(!(usart1->SR&(SR_TXE))){

	}
	usart1->DR=*data;

}