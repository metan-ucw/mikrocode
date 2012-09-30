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

#include "m8_i2c.h"

void m8_i2c_init(void)
{
//	uint8_t speed = (((uint32_t)1000*CPU_SPEED) - 16) / 2;

//	if (CPU_SPEED < 36000)
//		speed = 10;

	TWBR = 1;
	TWSR |= ((1<<TWPS0)|(1<<TWPS1));
	TWCR |= (1<<TWEN);
}

void m8_i2c_start(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTA);

	while (!(TWCR & (1<<TWINT)));
}

void m8_i2c_stop(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	
	while (!(TWCR & (1<<TWSTO)));
}

bool m8_i2c_write(uint8_t byte)
{
	TWDR = byte;

	TWCR = (1<<TWINT)|(1<<TWEN);

	while (!(TWCR & (1<<TWINT)));
	
	if ((TWSR & 0xf8) == 0x40 || (TWSR & 0xf8) == 0x18 ||
	    (TWSR & 0xf8) == 0x28)
		return true;

	return false;
}

uint8_t m8_i2c_read(void)
{
	uint8_t byte = TWDR;

	TWCR |= (1<<TWEA);

	//TODO Check TWSR

	return byte;
}
