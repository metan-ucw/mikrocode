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
 
   AVR internal EEPROM driver code.

   Values longer than one byte are read/written starting at selected address
   and it's your responsibility not to overlap them.

  */

#ifndef __EEPROM_H__
#define __EEPROM_H__

#include <stdint.h>

/*
 * General byte read.
 */
uint8_t avr_eeprom_read(uint16_t addr);

/*
 * General byte write.
 */
void avr_eeprom_write(uint16_t addr, uint8_t byte);

/*
 * More read functions
 */
static inline uint8_t avr_eeprom_read_uint8(uint16_t addr)
{
	return avr_eeprom_read(addr);
}

static inline int8_t avr_eeprom_read_int8(uint16_t addr)
{
	return (int8_t)avr_eeprom_read(addr);
}

uint16_t avr_eeprom_read_uint16(uint16_t addr);

int16_t avr_eeprom_read_int16(uint16_t addr);

/*
 * More write functions
 */
static inline void avr_eeprom_write_uint8(uint16_t addr, uint8_t val)
{
	avr_eeprom_write(addr, val);
}

static inline void avr_eeprom_write_int8(uint16_t addr, int8_t val)
{
	avr_eeprom_write(addr, (uint8_t)val);
}

void avr_eeprom_write_uint16(uint16_t addr, uint16_t val);

void avr_eeprom_write_int16(uint16_t addr, int16_t val);

#endif /* __EEPROM_H__ */
