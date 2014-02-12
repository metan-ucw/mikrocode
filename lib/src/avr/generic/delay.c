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

#include "cpu_freq.h"

#include "delay.h"

//TODO: sbiw is not on some ATtiny cpus
static void delay(uint16_t time)
{
	__asm__ volatile (
		"1: sbiw %0,1" "\n\t"
		"brne 1b"
		: "=w" (time)
		: "0" (time)
	);
}

void delay_ms(uint16_t time)
{
	uint16_t i;

	for (i = 0; i < CPU_FREQ_DIV_4; i++)
		delay(time - 2);
}

void delay_us(uint16_t time)
{
#ifdef CPU_FREQ_VAR
	#warning microsecond sleep does not yet work with variable CPU_FREQ
	delay(((CPU_FREQ/1000) * time) / 4);
#else
	delay(((CPU_FREQ/1000) * time) / 4);
#endif
}

void delay_s(uint8_t s)
{
	uint8_t i;

	for (i = 0; i < s; i++)
		delay_ms(1000);
}
