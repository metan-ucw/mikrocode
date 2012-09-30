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

#include <avr/io.h>

#include "cpu_freq.h"

#include "delay.h"
#include "utils.h"

int main(void)
{
	/*
	 * Set CPU freq to 1Mhz, comment this out and uncomment CPU_FREQ in
	 * Makefile to define CPU frequency statically.
	 */
	set_cpu_freq(1000);

	/*
	 * Set pin as output.
	 */
	SET_BIT(DDRB, PB0);

	/* 
	 * Blink on PB0
	 */
	for(;;) {
		SET_BIT(PORTB, PB0);
		delay_us(100);
		RESET_BIT(PORTB, PB0);
		delay_us(100);
	}

	return 0;
}
