/*****************************************************************************
 * This file is part of avr-lib library.                                     *
 *                                                                           *
 * Avr-lib project is free software; you can redistribute it and/or          *
 * modify it under the terms of the GNU Lesser General Public                *
 * License as published by the Free Software Foundation; either              *
 * version 2.1 of the License, or (at your option) any later version.        *
 *                                                                           *
 * Avr-lib is distributed in the hope that it will be useful,                *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU         *
 * Lesser General Public License for more details.                           *
 *                                                                           *
 * You should have received a copy of the GNU Lesser General Public          *
 * License along with Avr-lib; if not, write to the Free Software            *
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,                        *
 * Boston, MA  02110-1301  USA                                               *
 *                                                                           *
 * Copyright (C) 2012 Cyril Hrubis <metan@ucw.cz>                            *
 *                                                                           *
 *****************************************************************************/

#include "crc.h"

uint8_t crc_8bit_8540(uint8_t crc, uint8_t next)
{
	uint8_t e = crc ^ next;
	
	e = e ^ (e << 3) ^ (e << 4) ^ (e << 6);
	e = e ^ (e >> 4) ^ (e >> 5);

	return e;
}
