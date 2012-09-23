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

#include <avr/io.h>
#include "cpu_speed.h"
#include "utils.h"
#include "sleep.h"
#include "m8_i2c.h"

#define DS1307_ADDRESS 0xd0

static void do_blick(int n)
{
	int i;

	for (i = 0; i < n; i++) {
		SET_BIT(PORTB, PB1);
		sleep_ms(100);
		RESET_BIT(PORTB, PB1);
		sleep_ms(100);
	}
}


int main(void)
{
	/* 1Mhz */
	set_cpu_speed(1000);

	SET_BIT(DDRB, PB1);
	SET_BIT(PORTB, PB1);
	
	SET_BIT(DDRB, PB0);
	SET_BIT(PORTB, PB0);
	
	sleep_ms(500);

	m8_i2c_init();
	m8_i2c_start();
	if (!m8_i2c_write(DS1307_ADDRESS)) {
		RESET_BIT(PORTB, PB0);
		do_blick(1);
		sleep_ms(500);
	}

	if (!m8_i2c_write(0x00)) {
		RESET_BIT(PORTB, PB0);
		do_blick(2);
		sleep_ms(500);
	}

	if (!m8_i2c_write(0x00)) {
		RESET_BIT(PORTB, PB0);
		do_blick(3);
		sleep_ms(500);
	}

	m8_i2c_start();
	m8_i2c_write(DS1307_ADDRESS);
	m8_i2c_write(0x07); /* control register */
	m8_i2c_write(0x13);
	m8_i2c_stop();

	/* 
	 * turn on PB0 sleep for 1sec, turn off PB0, sleep
	 */
	int i = 0;
	for(;;) {
		SET_BIT(PORTB, PB1);
		sleep_ms(2000);
		RESET_BIT(PORTB, PB1);
		sleep_ms(2000);
		m8_i2c_start();
		if (!m8_i2c_write(DS1307_ADDRESS))
			RESET_BIT(PORTB, PB0);
		m8_i2c_write(0x07);
		m8_i2c_write(0x10 + i%4);
		m8_i2c_stop();
		i++;
	}

	return 0;
}
