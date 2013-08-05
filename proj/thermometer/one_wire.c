/*****************************************************************************
 * This file is part of mclib library.                                       *
 *                                                                           *
 * Mclib project is free software; you can redistribute it and/or            *
 * modify it under the terms of the GNU Lesser General Public                *
 * License as published by the Free Software Foundation; either              *
 * version 2.1 of the License, or (at your option) any later version.        *
 *                                                                           *
 * Mclib is distributed in the hope that it will be useful,                  *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU         *
 * Lesser General Public License for more details.                           *
 *                                                                           *
 * You should have received a copy of the GNU Lesser General Public          *
 * License along with Mclib; if not, write to the Free Software              *
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,                        *
 * Boston, MA  02110-1301  USA                                               *
 *                                                                           *
 * Copyright (C) 2009-2013 Cyril Hrubis <metan@ucw.cz>                       *
 *                                                                           *
 *****************************************************************************/

#include <avr/interrupt.h>
#include <avr/io.h>
#include "utils.h"

/*
 * Needed only when running with interrupts enabled
 */
//#define ONE_WIRE_START cli()
//#define ONE_WIRE_STOP sei()

#define ONE_WIRE_START
#define ONE_WIRE_STOP

#define ONE_WIRE_SET_LOW do {  \
	SET_BIT(DDRC, PC5);    \
	RESET_BIT(PORTC, PC5); \
} while (0)

#define ONE_WIRE_SET_INPUT do { \
	RESET_BIT(DDRC, PC5);   \
} while (0)

#define ONE_WIRE_IS_LOW  PIN_OFF(PINC, PC5)

#define ONE_WIRE_IS_HIGH PIN_ON(PINC, PC5)

#include <one_wire_sw.c>
