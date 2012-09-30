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

#include "avr_eeprom.h"

/*
 * Compatibility defines for older AVRs (such as atmega8)
 */
#ifndef EEPE
#define EEPE EEWE
#define EEMPE EEMWE
#endif

void avr_eeprom_write(uint16_t addr, uint8_t byte)
{
	/* Wait for write completion (if needed) */
	while (EECR & (1<<EEPE));

	/* Setup addres and data */
	EEAR = addr;
	EEDR = byte;

	/* Write byte */
	EECR |= (1<<EEMPE);
	EECR |= (1<<EEPE);
}

uint8_t avr_eeprom_read(uint16_t addr)
{
	/* Wait for write completion (if needed) */
	while (EECR & (1<<EEPE));

	/* Setup addres */
	EEAR = addr;

	/* Read byte */
	EECR |= (1<<EERE);

	return EEDR;
}

uint16_t avr_eeprom_read_uint16(uint16_t addr)
{
	return (avr_eeprom_read(addr) << 8) | avr_eeprom_read(addr + 1);
}

int16_t avr_eeprom_read_int16(uint16_t addr)
{
	return (int16_t)avr_eeprom_read_uint16(addr);
}

void avr_eeprom_write_uint16(uint16_t addr, uint16_t val)
{
	avr_eeprom_write(addr, (val >> 8));
	avr_eeprom_write(addr + 1, val & 0xff);
}

void avr_eeprom_write_int16(uint16_t addr, int16_t val)
{
	avr_eeprom_write_uint16(addr, (uint16_t)val);
}
