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

 /*
  
   The actual code is created by defining following macros and including this
   file.
  
   ONE_WIRE_READ  - returns byte read from one wire bus
   ONE_WIRE_WRITE - writes byte to one wire bus
   ONE_WIRE_RESET - resets the bus (returns 0 on success).

  */

#include "delay.h"
#include "one_wire.h"
#include "crc.h"
#include "ds18b20.h"

uint8_t ds18b20_conv_t(void)
{
	if (ONE_WIRE_RESET)
		return 1;

	/* request conversion */
	ONE_WIRE_WRITE(ONE_WIRE_SKIP_ROM);
	ONE_WIRE_WRITE(DS18B20_CONVERT_T);

	return 0;
}

uint8_t ds18b20_conv_wait(void)
{
	uint16_t ms = 0;

	/* Maximal conversion time is 750 ms (for 12 bit resolution) */
	while (ONE_WIRE_READ == 0x00 && ms++ <= 750)
		delay_us(1000);

	return ms > 750;
}

uint8_t ds18b20_conv_done(void)
{
	return ONE_WIRE_READ != 0x00;
}

static uint8_t read_scratchpad(uint8_t *buf)
{
	uint8_t i;

	if (ONE_WIRE_RESET)
		return 1;

	/* request scratchpad */
	ONE_WIRE_WRITE(ONE_WIRE_SKIP_ROM);
	ONE_WIRE_WRITE(DS18B20_READ_SCRATCHPAD);

	/* read scratchpad */	
	uint8_t crc = 0;
	
	for (i = 0; i < 9; i++) {
		buf[i] = ONE_WIRE_READ;
		crc = crc8_dallas(crc, buf[i]);
	}

	/* check scratchpad crc */
	if (crc != 0)
		return 2;

	return 0;
}

uint8_t ds18b20_read_t(int16_t *temp)
{
	uint8_t buf[9], ret;

	ret = read_scratchpad(buf);

	if (ret)
		return ret;

	*temp = (int16_t)buf[0] | (int16_t)buf[1] << 8;

	return 0;
}
