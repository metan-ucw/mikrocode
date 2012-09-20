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

#ifndef __CRC_H__
#define __CRC_H__

#include <stdint.h>

/*
 * 8-bit dalas CRC for polynomial x^8 + x^5 + x^4 + 1
 *
 * The usage is as follows:
 *
 * uint8_t crc = 0;
 *
 * for all bytes:
 * 	crc = crc_8bit_8540(crc, next byte);
 */
uint8_t crc_8bit_8540(uint8_t crc, uint8_t next);

#endif /* __CRC_H__ */
