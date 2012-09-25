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

#include <avr/io.h>
#include <utils.h>
#include <cpu_speed.h>
#include <sleep.h>
#include "hd44780u_display.h"

/*
 * Compose user character.
 */
static uint8_t userchar[8] = {
HD44780U_USERCHAR_COMPOSE(0, 0, 0, 0, 0),
HD44780U_USERCHAR_COMPOSE(0, 0, 1, 0, 0),
HD44780U_USERCHAR_COMPOSE(0, 0, 1, 0, 0),
HD44780U_USERCHAR_COMPOSE(0, 1, 1, 1, 0),
HD44780U_USERCHAR_COMPOSE(0, 1, 1, 1, 0),
HD44780U_USERCHAR_COMPOSE(1, 1, 1, 1, 1),
HD44780U_USERCHAR_COMPOSE(1, 1, 1, 1, 1),
HD44780U_USERCHAR_COMPOSE(0, 0, 0, 0, 0),
};

int main(void)
{
	int i;

	/* 1Mhz */
	set_cpu_speed(1000);

	/* turn PB1 to be output */
	SET_BIT(DDRB, PB1);

	/*
	 * Initalize display, load user defined character.
	 */
	hd44780u_init();
	hd44780u_load_userchar(userchar, 0);
	hd44780u_cmd(HD44780U_CNTL_DISPLAY_ON);
	
	/*
	 * Print something.
	 */
	hd44780u_puts("Hello world! ****** Hello world! ******");
	hd44780u_cmd(HD44780U_LINE2_START);
	
	for (i = 0; i < 40; i++)
		hd44780u_putc(0);

	/* 
	 * turn on PB0 sleep for 0.5 sec, turn off PB0, sleep
	 */
	for(;;) {
		SET_BIT(PORTB, PB1);
		sleep_ms(100);
		RESET_BIT(PORTB, PB1);
		sleep_ms(500);
		hd44780u_cmd(HD44780U_DISPLAY_SHIFT_LEFT);
	}

	return 0;
}
