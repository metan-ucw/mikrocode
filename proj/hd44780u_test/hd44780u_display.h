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

/* display size and type */
#define HD44780U_COLUMNS 8
#define HD44780U_LINES   2

/* Clock pin */
#define HD44780U_BUS_E_ON   SET_BIT(PORTD, PD7)
#define HD44780U_BUS_E_OFF  RESET_BIT(PORTD, PD7)

/* Data/Command pin */
#define HD44780U_BUS_RS_ON  SET_BIT(PORTB, PB0)
#define HD44780U_BUS_RS_OFF RESET_BIT(PORTB, PB0)

/* Read/Write pin */
#define HD44780U_BUS_RW_ON  SET_BIT(PORTD, PD5)
#define HD44780U_BUS_RW_OFF RESET_BIT(PORTD, PD5)

/* Data bus write */
#define HD44780U_BUS_WRITE_4B display_write

/* Display io init */
#define HD44780U_IO_INIT display_io_init()

static void display_write(uint8_t data)
{
        if (data & 0x10)
                SET_BIT(PORTD, PD0);
        else
                RESET_BIT(PORTD, PD0);

        if (data & 0x20)
                SET_BIT(PORTD, PD1);
        else
                RESET_BIT(PORTD, PD1);

        if (data & 0x40)
                SET_BIT(PORTD, PD2);
        else
                RESET_BIT(PORTD, PD2);

        if (data & 0x80)
                SET_BIT(PORTD, PD3);
        else
                RESET_BIT(PORTD, PD3);

}

static void display_io_init(void)
{
	/* control */
	SET_BIT(DDRB, PB0);
	SET_BIT(DDRD, PD5);
	SET_BIT(DDRD, PD7);

	/* data */
	SET_BIT(DDRD, PD0);
	SET_BIT(DDRD, PD1);
	SET_BIT(DDRD, PD2);
	SET_BIT(DDRD, PD3);
}

/* including this driver is generated */
#include "hd44780u.c"
