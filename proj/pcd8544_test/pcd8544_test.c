/*****************************************************************************
 * This file is part of Mikrocode library.                                   *
 *                                                                           *
 * Mikrocode project is free software; you can redistribute it and/or        *
 * modify it under the terms of the GNU Lesser General Public                *
 * License as published by the Free Software Foundation; either              *
 * version 2.1 of the License, or (at your option) any later version.        *
 *                                                                           *
 * Mikrocode is distributed in the hope that it will be useful,              *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU         *
 * Lesser General Public License for more details.                           *
 *                                                                           *
 * You should have received a copy of the GNU Lesser General Public          *
 * License along with Mikrocode; if not, write to the Free Software          *
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,                        *
 * Boston, MA  02110-1301  USA                                               *
 *                                                                           *
 * Copyright (C) 2009-2014 Cyril Hrubis <metan@ucw.cz>                       *
 *                                                                           *
 *****************************************************************************/

#include <avr/io.h>
#include <delay.h>
#include <utils.h>
#include <pcd8544.h>

int main(void)
{
	/* Set pin as output */
	SET_BIT(DDRB, PB0);
	SET_BIT(PORTB, PB0);

	/*
	 * Datasheet says to wait 30ms before display reset after power was
	 * turned on
	 */
	delay_ms(30);

	/* Initialize display */
	pcd8544_init();
	pcd8544_clear(0xaa);

	uint8_t pattern = 0xaa;

	/* Blink on PB0 */
	for(;;) {
		SET_BIT(PORTB, PB0);
		delay_ms(500);
		RESET_BIT(PORTB, PB0);
		delay_ms(500);
		pattern = ~pattern;
		pcd8544_write(pattern);
	}

	return 0;
}
