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

#include "delay.h"

#include "hd44780u.h"

void send_data(uint8_t data)
{
#ifdef HD44780U_BUS_WRITE_4B
	HD44780U_BUS_WRITE_4B(data);
	HD44780U_BUS_E_ON;
	delay_us(2000);
	HD44780U_BUS_E_OFF;

	HD44780U_BUS_WRITE_4B(data<<4);
	HD44780U_BUS_E_ON;
	delay_us(2000);
	HD44780U_BUS_E_OFF;
#else
#ifdef HD44780U_BUS_WRITE_8B
	HD44780U_BUS_WRITE_8B(data);
	HD44780U_BUS_E_ON;
	delay_us(2000);
	HD44780U_BUS_E_OFF;
#else
#error HD44780U_BUS_WRITE_4B or HD44780U_BUS_WRITE_8B must be defined
#endif
#endif
}

/* one common write for initialization */
#ifdef HD44780U_BUS_WRITE_4B
	#define HD44780U_BUS_WRITE HD44780U_BUS_WRITE_4B
#else
	#define HD44780U_BUS_WRITE HD44780U_BUS_WRITE_8B
#endif

void hd44780u_init(void)
{
	/* MCU initalizaton */
	HD44780U_IO_INIT;

	/* Set write & command mode */
	HD44780U_BUS_RW_OFF;
	HD44780U_BUS_RS_OFF;

	delay_ms(16);

	/* Init sequence */
	HD44780U_BUS_WRITE(0x30);
	HD44780U_BUS_E_ON;
	delay_ms(5);
	HD44780U_BUS_E_OFF;

	HD44780U_BUS_WRITE(0x30);
	HD44780U_BUS_E_ON;
	delay_us(100);
	HD44780U_BUS_E_OFF;

	HD44780U_BUS_WRITE(0x30);
	HD44780U_BUS_E_ON;
	delay_us(100);
	HD44780U_BUS_E_OFF;

	/* Initalize 4bit/8bit mode */
	#ifdef HD44780U_BUS_WRITE_4B
		HD44780U_BUS_WRITE(0x20);
		HD44780U_BUS_E_ON;
		delay_us(64);
		HD44780U_BUS_E_OFF;

		/*
		 * We are in 4 bit mode, let's
		 * set number of lines
		 */
		#if HD44780U_LINES == 1
			send_data(0x20);
		#elif HD44780U_LINES == 2
			send_data(0x28);
		#else
			#error HD44780U_LINES must be 1 or 2
		#endif
	#else
		//TODO:
		#error 8bit mode not coded
	#endif

	send_data(HD44780U_CNTL);
	send_data(HD44780U_CLEAR);
}

void hd44780u_cmd(uint8_t cmd)
{
	send_data(cmd);
}

void hd44780u_putc(char c)
{
	HD44780U_BUS_RS_ON;
	send_data(c);
	HD44780U_BUS_RS_OFF;
}

void hd44780u_puts(const char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
		hd44780u_putc(str[i]);
}

void hd44780u_load_userchar(uint8_t data[8], uint8_t pos)
{
	uint8_t i;

	for (i = 0; i < 8; i++) {
		send_data(HD44780U_SET_CGRAM_ADDR(i + (pos<<3)));
		HD44780U_BUS_RS_ON;
		send_data(data[i]);
		HD44780U_BUS_RS_OFF;
	}

	send_data(HD44780U_LINE1_START);
}
