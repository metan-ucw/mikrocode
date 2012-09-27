/*****************************************************************************
 * This file is part of mClib library.                                       *
 *                                                                           *
 * mClib project is free software; you can redistribute it and/or            *
 * modify it under the terms of the GNU Lesser General Public                *
 * License as published by the Free Software Foundation; either              *
 * version 2.1 of the License, or (at your option) any later version.        *
 *                                                                           *
 * mClib is distributed in the hope that it will be useful,                  *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU         *
 * Lesser General Public License for more details.                           *
 *                                                                           *
 * You should have received a copy of the GNU Lesser General Public          *
 * License along with mClib; if not, write to the Free Software              *
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,                        *
 * Boston, MA  02110-1301  USA                                               *
 *                                                                           *
 * Copyright (C) 2009-2012 Cyril Hrubis <metan@ucw.cz>                       *
 *                                                                           *
 *****************************************************************************/

#ifndef __M8_ADC_H__
#define __M8_ADC_H__

#include <stdint.h>
#include <avr/io.h>

/*** ADMUX register ***/

/** Reference selection **/

/*
 * Reference taken from AREF pin
 * internal reference off
 */
#define M8_ADC_REF_EXT 0x00
/*
 * Reference is taken from AVcc
 * with external capacitor on AREF
 */
#define M8_ADC_REF_AVCC 0x80
/*
 * Internal 2.56V reference with
 * external capacitor on AREF
 */
#define M8_ADC_REF_INT 0xc0

/** Adjust bit **/
/*
 * The result is 10 bit value stored
 * in 16 bit variable adjusted to the
 * right, use this to adjust it to the
 * left
 */
#define M8_ADC_ADJUST_LEFT 0x20

/** Input selection **/

/*
 * Adc IO ports
 */
#define M8_ADC0 0x00
#define M8_ADC1 0x01
#define M8_ADC2 0x02
#define M8_ADC3 0x03
#define M8_ADC5 0x05
#define M8_ADC6 0x06
#define M8_ADC7 0x07
/*
 * Connect ADCMUX to internal 1.30V reference
 */
#define M8_ADC_REF 0xfe
/*
 * Connect ADCMUX to GND
 */
#define M8_ADC_GND 0xff



/*** ADCSRA ***/

#define M8_ADC_EN (1<<ADEN)
/*
 * Start single conversion
 */
#define M8_ADC_SC  (1<<ADSC)
/*
 * Start free run mode
 */
#define M8_ADC_FR  (1<<ADFR)
/*
 * Start sending interupts after
 * conversion completititon
 */
#define M8_ADC_IE  (1<<ADIE)
/* 
 * Prescaler from 2 to 128
 */
#define M8_ADC_PRSC_2   0x01
#define M8_ADC_PRSC_4   0x02
#define M8_ADC_PRSC_8   0x03
#define M8_ADC_PRSC_16  0x04
#define M8_ADC_PRSC_32  0x05
#define M8_ADC_PRSC_64  0x06
#define M8_ADC_PRSC_128 0x07

/*
 * Initalize adc, for single conversion with prescaler set to 32
 * and internal reference call:
 *
 * m8_adc_set(M8_ADC_PRSC_32, M8_ADC_REF_INT);
 */
void m8_adc_set(uint8_t adcsra, uint8_t admux);
void m8_adc_start(uint8_t adcsra, uint8_t admux);

/*
 * Turn on/off adc by writing ADEN bit to ADCSRA register
 */
void m8_adc_on(void);
void m8_adc_off(void);

/*
 * Starts convertion by writing 1 to ADSC bit in ADMUX
 * reads result from ADCL and ADHL
 */
uint16_t m8_adc_read(uint8_t channel);


#endif /* __M8_ADC_H__ */
