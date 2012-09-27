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
 * This provides simple bussy loop sleep functionality, these functions are not
 * 100% correct and can't be used incrementally for example for clock loop but
 * are precise enough to be used as wait loop for hardware initalization and
 * because of set_crystal_speed() are independent from crystal.
 *
 */

#ifndef __SLEEP_H__
#define __SLEEP_H__

#include <stdint.h>

/*
 * Sleep for time in seconds. Maximal time
 * is 256 seconds.
 */
void sleep_s(uint8_t time);

/*
 * Sleeps for time miliseconds. Maximal time is
 * about 2^16/10^3 = aprox. 65 seconds.
 */
void sleep_ms(uint16_t time);

/*
 * Sleeps for time in micro seconds.
 */
void sleep_us(uint16_t time);


#endif /* __SLEEP_H__ */
