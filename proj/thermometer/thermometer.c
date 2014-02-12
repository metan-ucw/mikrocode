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

#include <avr/io.h>
#include <utils.h>
#include <delay.h>
#include <stdio.h>
#include "display.h"
#include "ds18b20.h"

static void error(const char *msg)
{
	hd44780u_cmd(HD44780U_LINE2_START);
	hd44780u_puts(msg);
}

int main(void)
{
	int16_t temp;
	char buf[16];

	/* turn PB1 to be output */
	SET_BIT(DDRB, PB1);

	/*
	 * Initalize display, load user defined character.
	 */
	hd44780u_init();
	hd44780u_cmd(HD44780U_CNTL_DISPLAY_ON);

	/*
	 * turn on PB0 sleep for 0.5 sec, turn off PB0, sleep
	 */
	for(;;) {

		SET_BIT(PORTB, PB1);

		if (ds18b20_conv_t()) {
			error("CONVFAIL");
			continue;
		}

		ds18b20_conv_wait();

		if (ds18b20_read_t(&temp)) {
			error("TEMPFAIL");
			continue;
		}

		delay_ms(100);

		temp = (5 * (temp + 4)) / 8;

		sprintf(buf, "%2i.%i C", temp/10, temp%10);
		hd44780u_cmd(HD44780U_LINE1_START);
		hd44780u_puts(buf);

		RESET_BIT(PORTB, PB1);
		delay_s(10);
	}

	return 0;
}
