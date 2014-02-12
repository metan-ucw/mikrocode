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

 /*

   Generic software one wire implementation.

   The actual code is created by defining following macros and including this
   file.

   ONE_WIRE_START - code called before one wire starts transmiting bit(s)
                    (if you are using interupts use disable them here)

   ONE_WIRE_STOP  - code called after one wire starts transmitting bit(s)
                    (if you are using interupts use enable them here)

   ONE_WIRE_SET_LOW    - sets pin low (ground)

   ONE_WIRE_SET_INPUT  - sets pin input/tristate

   ONE_WIRE_IS_LOW     - sample pin value

   ONE_WIRE_IS_HIGH    - sample pin value

  */

#include <stdint.h>

#include "delay.h"

#include "one_wire_sw.h"

uint8_t one_wire_sw_reset(void)
{
	ONE_WIRE_START;

	/* reset 1-wire bus */
	ONE_WIRE_SET_LOW;
	delay_us(480);

	/* wait for presence */
	ONE_WIRE_SET_INPUT;
	delay_us(66);

	/* no presence => error */
	if (ONE_WIRE_IS_HIGH)
		return 1;

	/* wait for end of the presence */
	delay_us(420);

	/* if still low => wrong wiring */
	if (ONE_WIRE_IS_LOW)
		return 2;

	ONE_WIRE_STOP;

	return 0;
}

uint8_t one_wire_sw_read_bit(void)
{
	uint8_t ret;

	ONE_WIRE_START;

	/* start reading frame */
	ONE_WIRE_SET_LOW;
	delay_us(2);
	ONE_WIRE_SET_INPUT;

	/* wait for signal */
	delay_us(10);

	ret = ONE_WIRE_IS_HIGH;

	/* wait for the end of the frame */
	delay_us(54);

	ONE_WIRE_STOP;

	return ret;
}

uint8_t one_wire_sw_read(void)
{
	uint8_t i, ret = 0, mask = 1;

	for (i = 0; i < 8; i++) {
		if (one_wire_sw_read_bit())
			ret |= mask;

		mask <<= 1;
	}

	return ret;
}

void one_wire_sw_write_bit(uint8_t bit)
{
	ONE_WIRE_START;

	if (bit) {
		/* start writing frame */
		ONE_WIRE_SET_LOW;
		delay_us(10);

		/* write one */
		ONE_WIRE_SET_INPUT;

		/* sleep for rest of the frame + recovery */
		delay_us(54);
	} else {
		/* start writing frame + write zero */
		ONE_WIRE_SET_LOW;
		delay_us(60);

		/* recovery */
		ONE_WIRE_SET_INPUT;
		delay_us(4);
	}

	ONE_WIRE_STOP;
}

void one_wire_sw_write(uint8_t byte)
{
	uint8_t i;

	for (i = 0; i < 8; i++) {
		one_wire_sw_write_bit(byte & 0x01);

		byte >>= 1;
	}
}
