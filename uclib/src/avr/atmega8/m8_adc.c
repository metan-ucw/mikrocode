/*****************************************************************************
 * This file is part of uClib library.                                       *
 *                                                                           *
 * uClib project is free software; you can redistribute it and/or            *
 * modify it under the terms of the GNU Lesser General Public                *
 * License as published by the Free Software Foundation; either              *
 * version 2.1 of the License, or (at your option) any later version.        *
 *                                                                           *
 * uClib is distributed in the hope that it will be useful,                  *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU         *
 * Lesser General Public License for more details.                           *
 *                                                                           *
 * You should have received a copy of the GNU Lesser General Public          *
 * License along with uClib; if not, write to the Free Software              *
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,                        *
 * Boston, MA  02110-1301  USA                                               *
 *                                                                           *
 * Copyright (C) 2009-2012 Cyril Hrubis <metan@ucw.cz>                       *
 *                                                                           *
 *****************************************************************************/

#include <avr/io.h>
#include "m8_adc.h"

uint16_t m8_adc_read(uint8_t channel)
{
	uint8_t l, h;

	/*
	 * Select channel
	 */
	ADMUX  |= channel;
	
	/*
	 * Start single run conversion
	 */
	ADCSRA |= M8_ADC_SC;

	/*
	 * Wait for result
	 */
	while (ADCSRA & M8_ADC_SC);

	/*
	 * ADCL must be read first,
	 * because ADCH is blocked for
	 * writing bewten ADCL and ADCH
	 * read
	 */
	l = ADCL;
	h = ADCH;

	/* 
	 * Unselect channel
	 */
	ADMUX &= ~channel;

	return (uint16_t) l | (h<<8);
}

void m8_adc_set(uint8_t adcsra, uint8_t admux)
{ 
	ADCSRA=adcsra;
	ADMUX=admux;
}

void m8_adc_start(uint8_t adcsra, uint8_t admux)
{ 
	ADCSRA=adcsra|M8_ADC_EN;
	ADMUX=admux;
}

void m8_adc_on(void)
{
	ADCSRA |= M8_ADC_EN;
}

void m8_adc_off(void)
{
	ADCSRA &= ~M8_ADC_EN;
}
