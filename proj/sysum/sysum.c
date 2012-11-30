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

#include "delay.h"
#include "utils.h"

static uint8_t buffer[10][4] = {
	{1, 1, 1, 1},
	{0, 0, 0, 0},
	{1, 1, 1, 1},
	{0, 0, 0, 0},
	{1, 1, 1, 1},
	{0, 0, 0, 0},
	{1, 1, 1, 1},
	{0, 0, 0, 0},
	{1, 1, 1, 1},
	{0, 0, 0, 0},
};

static void set_buffer(uint8_t col)
{
	if (buffer[9][col])
		RESET_BIT(PORTB, PB2);
	else
		SET_BIT(PORTB, PB2);
	
	if (buffer[8][col])
		RESET_BIT(PORTB, PB0);
	else
		SET_BIT(PORTB, PB0);
	
	if (buffer[7][col])
		RESET_BIT(PORTD, PD7);
	else
		SET_BIT(PORTD, PD7);
	
	if (buffer[6][col])
		RESET_BIT(PORTD, PD6);
	else
		SET_BIT(PORTD, PD6);
	
	if (buffer[5][col])
		RESET_BIT(PORTD, PD5);
	else
		SET_BIT(PORTD, PD5);
	
	if (buffer[4][col])
		RESET_BIT(PORTD, PD4);
	else
		SET_BIT(PORTD, PD4);

	if (buffer[3][col])
		RESET_BIT(PORTD, PD3);
	else
		SET_BIT(PORTD, PD3);
	
	if (buffer[2][col])
		RESET_BIT(PORTD, PD2);
	else
		SET_BIT(PORTD, PD2);
	
	if (buffer[1][col])
		RESET_BIT(PORTC, PC5);
	else
		SET_BIT(PORTC, PC5);
	
	if (buffer[0][col])
		RESET_BIT(PORTC, PC4);
	else
		SET_BIT(PORTC, PC4);
}

static void neg_buffer(void)
{
	int i, j;

	for (i = 0; i < 4; i++)
		for (j = 0; j < 10; j++)
			buffer[j][i] = !buffer[j][i];
}

int main(void)
{
	/* turn led on */
	SET_BIT(DDRC, PC0);
	SET_BIT(PORTC, PC0);

	/* transistors */
	SET_BIT(DDRC, PC2);
	SET_BIT(DDRC, PC3);
	SET_BIT(DDRC, PC1);
	SET_BIT(DDRB, PB1);

	/* diodes */
	SET_BIT(DDRB, PB2);
	SET_BIT(DDRB, PB0);
	SET_BIT(DDRD, PD7);
	SET_BIT(DDRD, PD6);
	SET_BIT(DDRD, PD5);
	SET_BIT(DDRD, PD4);
	SET_BIT(DDRD, PD3);
	SET_BIT(DDRD, PD2);
	SET_BIT(DDRC, PC5);
	SET_BIT(DDRC, PC4);

	int cnt = 0;

	for(;;) {
		RESET_BIT(PORTB, PB1);
		set_buffer(0);
		SET_BIT(PORTC, PC2);
		delay_ms(5);
		
		RESET_BIT(PORTC, PC2);
		set_buffer(1);
		SET_BIT(PORTC, PC3);
		delay_ms(5);
	
		RESET_BIT(PORTC, PC3);
		set_buffer(2);
		SET_BIT(PORTC, PC1);
		delay_ms(5);

		RESET_BIT(PORTC, PC1);
		set_buffer(3);
		SET_BIT(PORTB, PB1);
		delay_ms(5);
	
		cnt++;

		if (cnt > 100) {
			cnt = 0;
			neg_buffer();
		}
	}

	return 0;
}
