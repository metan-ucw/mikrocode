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
  
   Software 1-wire implementation see one_wire_sw.c for details.

  */

#ifndef __ONE_WIRE_SW_H__
#define __ONE_WIRE_SW_H__

#include <stdint.h>

/*
 * Resets one wire bus.
 *
 * Returns:
 * 0 on success
 * 1 on no presence
 * 2 on bus always low
 */
uint8_t one_wire_sw_reset(void);

/*
 * Reads one bit. Returns 0 or 1.
 */
uint8_t one_wire_sw_read_bit(void);

/*
 * Reads byte.
 */
uint8_t one_wire_sw_read(void);

/*
 * Writes one bit.
 */
void one_wire_sw_write_bit(uint8_t byte);

/*
 * Writes byte.
 */
void one_wire_sw_write(uint8_t byte);

#endif /* __ONE_WIRE_SW_H__ */
