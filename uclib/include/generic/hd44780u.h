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
 * Copyright (C) 2009-2010 Cyril Hrubis <metan@ucw.cz>                       *
 *                                                                           *
 *****************************************************************************/

#ifndef __HD44780U_H__
#define __HD44780U_H__

#include <stdint.h>
#include "string.h"

/*
 * Use to turn on/off display, cursor and cursor
 * blinking 
 */
#define HD44780U_CNTL                 0x08
#define HD44780U_CNTL_DISPLAY_ON      0x0c
#define HD44780U_CNTL_CURSOR_ON       0x0a
#define HD44780U_CNTL_CURSOR_BLINK_ON 0x09

/*
 * Writes space code 20H into DDRAM. Sets DDRAM address
 * to 0 and clears shift (cursor gets to the left edge
 * and first line of the display). Also sets increment to 1.
 */
#define HD44780U_CLEAR                0x01

/*
 * Sets DDRAM address to 0 and clears shift (cursor
 * gets to the left edge and first line of the display)
 */
#define HD44780U_RETURN_HOME          0x02

/*
 *
 *
 */
#define HD44780U_ENTRY_MODE_INCREMENT 0x06
#define HD44780U_ENTRY_MODE_DECREMENT 0x04

/*
 * Display shift left and right cause move of begin
 * of the display again memory cursor follows display.
 *
 * Move cursor moves cursor only.
 */
#define HD44780U_DISPLAY_SHIFT_LEFT  0x18
#define HD44780U_DISPLAY_SHIFT_RIGHT 0x1c
#define HD44780U_CURSOR_SHIFT_LEFT   0x10
#define HD44780U_CURSOR_SHIFT_RIGHT  0x14

/*
 * Create command to set CGRAM address upper two
 * bits are ignored as CGRAM addresses are 6 bits long.
 */
#define HD44780U_SET_CGRAM_ADDR(x) (((x)&0x3f)|0x40)

/*
 * Creates command to set DDRAM address upper bit
 * is ignored as DDRAM addresses are 7 bits long.
 */
#define HD44780U_SET_DDRAM_ADDR(x) (((x)&0x7f)|0x80)


/*
 * Command for addresses in DDRAM
 */
#define HD44780U_LINE1_START         0x80
#if HD44780U_LINES == 1 
	#define HD44780U_LINE1_END   0xcF
#elif HD44780U_LINES == 2
	#define HD44780U_LINE1_END   0xa7
	#define HD44780U_LINE2_START 0xc0
	#define HD44780U_LINE2_END   0xe7
#else
	#error HD44780U_LINES must be one of 1 or 2
#endif

/*
 * Chars to be passed to putc to print user
 * defined characters.
 */
#define HD44780U_USERCHAR_1         0x00
#define HD44780U_USERCHAR_2         0x01
#define HD44780U_USERCHAR_3         0x02
#define HD44780U_USERCHAR_4         0x03
#define HD44780U_USERCHAR_5         0x04
#define HD44780U_USERCHAR_6         0x05
#define HD44780U_USERCHAR_7         0x06
#define HD44780U_USERCHAR_8         0x07

#define HD44780U_USERCHAR_COMPOSE(a, b, c, d, e) (a<<4)|(b<<3)|(c<<2)|(d<<1)|e

#endif  /* __HD44780U_H__ */
