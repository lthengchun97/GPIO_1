/*
 * ADC.h
 *
 *  Created on: Jan 2, 2018
 *      Author: user8
 */

#ifndef ADC_H_
#define ADC_H_

#include "stdint.h"
#include "Common.h"
#include "Rcc.h"

#define ADC1_BASE_ADDR				0x40012000
#define	ADC2_BASE_ADDR				0x40012100
#define	ADC3_BASE_ADDR				0x40012200
#define	ADC_COMMON_BASE_ADDR		0x40012300

#define adc1 			((AdcReg *)(ADC1_BASE_ADDR))
#define adc2 			((AdcReg *)(ADC2_BASE_ADDR))
#define adc3 			((AdcReg *)(ADC3_BASE_ADDR))
#define adc_cm 			((AdcCommonReg *)(ADC_COMMON_BASE_ADDR))

typedef struct AdcReg AdcReg;
struct AdcReg {
	volatile uint32_t SR;		//0x00 Status
	volatile uint32_t CR1;		//0x04 Control
	volatile uint32_t CR2;		//0x08
	volatile uint32_t SMPR1;	//0x0c Sampling time Register
	volatile uint32_t SMPR2;	//0x10
	volatile uint32_t JOFR1;	//0x14 Injected Channel Data
	volatile uint32_t JOFR2;	//0x18
	volatile uint32_t JOFR3;	//0x1c
	volatile uint32_t JOFR4;	//0x20
	volatile uint32_t HTR;		//0x24 Watchdog higher threshold
	volatile uint32_t LTR;		//0x28 Watchdog lower threshold
	volatile uint32_t SQR1;		//0x2C Regular sequence register
	volatile uint32_t SQR2;		//0x30
	volatile uint32_t SQR3;		//0x34
	volatile uint32_t JSQR;		//0x38 Injected sequence register
	volatile uint32_t JDR1;		//0x3C Injected data register
	volatile uint32_t JDR2;		//0x40
	volatile uint32_t JDR3;		//0x44
	volatile uint32_t JDR4;		//0x48
	volatile uint32_t DR;		//0x4C Regular data register

};

typedef struct AdcCommonReg AdcCommonReg;
struct AdcCommonReg {
	volatile uint32_t CSR;		//0x00
	volatile uint32_t CCR;		//0x04
	volatile uint32_t CDR;		//0x08
};

void initADC(void);
void adcSetChannelSamplingSequence(AdcReg *adc, int channels[], int numOfChan);
void adcChannelSamplingTime(AdcReg *adc,int channel, int cycles);
//CR1
#define	ADC_CH5		(15)

//CR2
#define	ADC_EN		(1)
#define START_REG_CONV	(1<<30)
#define	CONT_EN		(1<<1)
#define	SING_EN		(0<<1)

// SMPR2
#define CYC_480		(7<<15)

// SMPR1
#define	CYC_3		(0<<9)

// CYCLES
#define ADC_3_CYCLES	0
#define ADC_15_CYCLES	1
#define ADC_28_CYCLES	2
#define ADC_56_CYCLES	3
#define ADC_84_CYCLES	4
#define ADC_112_CYCLES	5
#define ADC_144_CYCLES	6
#define ADC_480_CYCLES	7

// Configuration
#define	ADC_10B_RESO		(1<<24)
#define SCAN_EN				(1<<8)
#define REG_CH_LENGTH_4		(3<<20)
#define	READ_CH1			(1)
#define	READ_CH6			(6<<5)
#define	READ_CH10			(10<<10)
#define	READ_CH14			(14<<15)
#define	LEFT_ALIGN			(1<<11)
#define START_REG_CONV		(1<<30)

//SQR1
#define REG_CH_LENGTH_1		(0<<20)
#define REG_CH_LENGTH_2		(1<<20)
#define POSITION_OF_LENGTH   20
//SQR3
#define CONV_5		(5)
#define	CONV_13		(13<<5)
#endif /* ADC_H_ */
