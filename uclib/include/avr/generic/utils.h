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

#ifndef __UTILS_H__
#define __UTILS_H__

#define SET_BIT(REG, BIT) _SFR_BYTE(REG) |= _BV(BIT) 
#define RESET_BIT(REG, BIT) _SFR_BYTE(REG) &= ~_BV(BIT)

#define PIN_ON(PORT, PIN) (_SFR_BYTE(PORT) & _BV(PIN))
#define PIN_OFF(PORT, PIN) (!(_SFR_BYTE(PORT) & _BV(PIN)))

#endif /* __UTILS_H__ */
