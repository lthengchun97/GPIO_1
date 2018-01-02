/*
 * ADC.c
 *
 *  Created on: Jan 2, 2018
 *      Author: user8
 */

#include "ADC.h"
#include "rcc.h"

void initADC(void){
	enableADC1();
	//adc1->CR1 |= ADC_CH5;
	adc1->CR2 = ADC_EN |CONT_EN;
	adc1->SQR1 = REG_CH_LENGTH_2;
	adc1->SQR3 = CONV_5 | CONV_13;
	adc1->SMPR2 = CYC_3;
	adc1->SMPR1 = CYC_480;
	adc1->CR2 |= START_REG_CONV;
}

void adcChannelSamplingTime(AdcReg *adc,int channel, int cycles){
	enableADC1();
	if (channel > 9){
		adc->SMPR1 = (cycles<<(channel-10)*3);
	}
	else if (channel < 9)
	{
		adc-> SMPR2 = (cycles << (channel*3));
	}
}

void adcSetChannelSamplingSequence(AdcReg *adc, int channels[], int numOfChan){
	enableADC1();
	adc->SQR1 |= (numOfChan<<POSITION_OF_LENGTH);
	for(int i=0;i<numOfChan;i++){
			if(i<6){
				adc->SQR3 |= (channels[i]<< (i*5));

			}
			else if(7<i<13){
				adc->SQR2 |= (channels[i]<< (i-7)*5);
			}
			else{
				adc->SQR1 |= (channels[i]<< (i-13)*5);
			}
		}
}

void configADC1(void){
	adc1->CR1 =ADC_10B_RESO |SCAN_EN;
	adc1->SQR1 = REG_CH_LENGTH_4;
	adc1->SQR3 = READ_CH1 | READ_CH6 | READ_CH10 | READ_CH14;
	adc1->CR2 = LEFT_ALIGN | START_REG_CONV ;
}
