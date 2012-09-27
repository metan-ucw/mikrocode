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

#include <avr/io.h>
#include <avr/interrupt.h>
#include <utils.h>
#include <cpu_speed.h>
#include <sleep.h>
#include <m8_timer0.h>
#include <m8_usart.h>

#include "hd44780u_display.h"

static uint8_t      prescaler   = 0;

static uint8_t prescalers[] = {
	0x01, /* divide by 1    */
	0x02, /* divide by 8    */
	0x03, /* divide by 64   */
	0x04, /* divide by 256  */
	0x05, /* divide by 1024 */
};

static uint8_t prescalers_div[] = {
	0,
	3,
	6,
	8,
	10,
};

static void display_print(void)
{
	char buf[13], tmp;
	uint32_t div = OCR1A + 1;
	int i;

	/* compute frequency */
	uint32_t freq = (uint32_t) 100000 * CPU_SPEED;
	freq /= (uint32_t)(2<<(prescalers_div[prescaler])) * div;

	hd44780u_cmd(HD44780U_RETURN_HOME);
	str_uint32_t(buf, freq);
	
	for (i = 0; i < 10; i++)
		if (buf[i] == '0')
			buf[i] = ' ';
		else
			break;
	
	/* MHz range */
	if (freq >= 100000000) {
		tmp = buf[2];
		buf[2] = 0;
		hd44780u_puts(buf);
		hd44780u_putc('.');
		buf[2] = tmp;
		hd44780u_puts(buf+2);
		hd44780u_puts(" MHz");
	/* KHz range */
	} else if (freq >= 100000) {
		tmp = buf[5];
		buf[5] = 0;
		hd44780u_puts(buf);
		hd44780u_putc('.');
		buf[5] = tmp;
		hd44780u_puts(buf+5);
		hd44780u_puts(" KHz");
	/* Hz range */
	} else {
		buf[11] = 0;
		buf[10] = buf[9];
		buf[9] = buf[8];
		buf[8]  = '.';
		hd44780u_puts(buf);
		hd44780u_puts("  Hz");
	}

	/* Print MAX and prescaler */
	hd44780u_cmd(HD44780U_LINE2_START);
	hd44780u_puts("M ");
	str_uint16_t(buf, div);
	hd44780u_puts(buf);
	hd44780u_puts(" P ");
	str_uint16_t(buf, 1<<prescalers_div[prescaler]);	
	hd44780u_puts(buf);
}

int main(void)
{
	uint8_t speed = 0;
	uint8_t button = 0;
	uint8_t inc = 1;

	/* 16Mhz external xtall */
	set_cpu_speed(16000);

	/* turn PB1 to be output */
	SET_BIT(DDRB, PB0);
	/* turn on pull up */
	SET_BIT(PORTD, PD2);
	SET_BIT(PORTB, PB3);
	SET_BIT(PORTB, PB4);
	/* out to the BNC connector */
	SET_BIT(DDRB, PB1);
	/* backlight */
	SET_BIT(DDRC, PC5);
	RESET_BIT(PORTC, PC5);

	/* Initalize serial */
	m8_usart_init(9600);

	TCCR1A = (1<<COM1A0); /* Output compare toggles OC1A */
	TCCR1B = (1<<WGM12)|(1<<CS10);
	OCR1A  = 1;

	/*
	 * Initalize display, load user defined character.
	 */
	hd44780u_init();
	hd44780u_cmd(HD44780U_CNTL_DISPLAY_ON);
	
	display_print();

	/* 
	 * turn on PB0 sleep for 0.5 sec, turn off PB0, sleep
	 */
	for(;;) {
		if (PIN_OFF(PINB, PB4)) {
			OCR1A = OCR1A - inc;
			display_print();
			button = 1;
		}
		
		if (PIN_OFF(PINB, PB3)) {
			OCR1A = OCR1A + inc;
			display_print();
			button = 1;
		}
	
		if (PIN_OFF(PIND, PD2)) {
			prescaler = (prescaler + 1) % 5;
			TCCR1B = (1<<WGM12)|prescalers[prescaler];
			display_print();
			button = 1;
		}

		if (button == 1)
			speed++;
		else
			speed = 0;

		if (speed >= 20)
			inc = 100;
		else if (speed >= 10)
			inc = 10;
		else
			inc = 1;

		button = 0;
		
		SET_BIT(PORTB, PB0);
		sleep_ms(10);
		RESET_BIT(PORTB, PB0);
		sleep_ms(50);
	}

	return 0;
}
