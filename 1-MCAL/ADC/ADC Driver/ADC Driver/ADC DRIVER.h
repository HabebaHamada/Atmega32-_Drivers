/*
 * ADC Driver.h
 *
 * Created: 3/20/2022 9:25:56 PM
 * Author : Habeba Hamada
 */ 


#ifndef ADC_H_Driver

#define F_CPU 8000000UL

#include "BIT Macros.h"
#include <avr/io.h>
#include <stdint.h>

//define Used Registers

#define  ADC_Direction               DDRA
#define  ADC_Port                    PORTA
#define  ADC_HighByte_DATA_REGISTER  ADCH
#define  ADC_LowByte_DATA_REGISTER   ADCL
#define  ADC_MUX_SELECTION_REGISTER  ADMUX
#define  ADC_CONTROL_STATUS_REGISTER ADCSRA

//Define ADMUX Register PINS
#define  REFS1    7
#define  REFS0    6
#define  ADLAR    5

//define reference selection bits
#define  AREF_pin    0
#define  AVCC_pin    1
#define  INTERNAL    3

#define  Left_Justified  1
#define  Right_Justified 0

//input channels
#define  ADC0  0
#define  ADC1  1
#define  ADC2  2
#define  ADC3  3
#define  ADC4  4
#define  ADC5  5
#define  ADC6  6
#define  ADC7  7

//Define ADCSRA Register PINS
#define  ADEN  7
#define  ADSC  6
#define  ADATE 5
#define  ADIF  4
#define  ADIE  3

void ADC_INIT(uint8_t V_reference,)
{
	
}