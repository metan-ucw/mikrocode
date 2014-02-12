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

#include "string.h"

void str_write(void (*write)(char), char *str)
{
	while (*str != '\0')
		write(*(str++));
}

void str_uint8_t(char *buf, uint8_t val)
{
	buf[3] = '\0';
	buf[2] = val % 10 + '0';
	val /= 10;
	buf[1] = val % 10 + '0';
	val /= 10;
	buf[0] = val + '0';
}

void str_uint16_t(char *buf, uint16_t val)
{
	int i;

	buf[5] = '\0';

	for (i = 4; i > 0; i--) {
		buf[i] = val % 10 + '0';
		val /= 10;
	}

	buf[0] = val + '0';
}

void str_uint32_t(char *buf, uint32_t val)
{
	int i;

	buf[10] = '\0';

	for (i = 9; i > 0; i--) {
		buf[i] = val % 10 + '0';
		val /= 10;
	}

	buf[0] = val + '0';
}
