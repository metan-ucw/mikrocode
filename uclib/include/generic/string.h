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

#ifndef __STRING_H__
#define __STRING_H__

#include <stdint.h>

void str_write(void (*write)(char), char *str);

/*
 * Converts uint8_t into ASCII string. buf must be at least 4 chars wide.
 */
void str_uint8_t(char *buf, uint8_t val);

/*
 * Converts uint16_t into ASCII string, buf must be at least 6 chars wide.
 */
void str_uint16_t(char *buf, uint16_t val);

/*
 * Converts uint32_t into ASCII string, buf must be at least 11 chars wide.
 */
void str_uint32_t(char *buf, uint32_t val);

#endif /* __STRING_H__ */
