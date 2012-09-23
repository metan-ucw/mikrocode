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

/* display size and type */
#define HD44780U_COLUMNS 16
#define HD44780U_LINES   2

/* Clock pin */
#define HD44780U_BUS_E_ON   SET_BIT(PORTB, PB2)
#define HD44780U_BUS_E_OFF  RESET_BIT(PORTB, PB2)

/* Data/Command pin */
#define HD44780U_BUS_RS_ON  SET_BIT(PORTD, PD3)
#define HD44780U_BUS_RS_OFF RESET_BIT(PORTD, PD3)

/* Read/Write pin */
#define HD44780U_BUS_RW_ON
#define HD44780U_BUS_RW_OFF

/* Data bus write */
#define HD44780U_BUS_WRITE_4B display_write

/* Display io init */
#define HD44780U_IO_INIT display_io_init()

static void display_write(uint8_t data)
{
        if (data & 0x10)
                SET_BIT(PORTD, PD4);
        else
                RESET_BIT(PORTD, PD4);

        if (data & 0x20)
                SET_BIT(PORTD, PD5);
        else
                RESET_BIT(PORTD, PD5);

        if (data & 0x40)
                SET_BIT(PORTD, PD6);
        else
                RESET_BIT(PORTD, PD6);

        if (data & 0x80)
                SET_BIT(PORTD, PD7);
        else
                RESET_BIT(PORTD, PD7);
}

static void display_io_init(void)
{
	/* control */
	SET_BIT(DDRD, PD3);
	SET_BIT(DDRB, PB2);

	/* data */
	SET_BIT(DDRD, PD4);
	SET_BIT(DDRD, PD5);
	SET_BIT(DDRD, PD6);
	SET_BIT(DDRD, PD7);
}

/* including this driver is generated */
#include "hd44780u.c"
