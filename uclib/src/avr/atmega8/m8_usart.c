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

#include "m8_usart.h"
#include "cpu_speed.h"

void m8_usart_init(uint16_t baud)
{
	uint16_t prescaler = ((uint32_t)1000*CPU_SPEED)/16/baud-1;

	/* set UBRR prescaler */
	UBRRH = (uint8_t) (prescaler>>8);
	UBRRL = (uint8_t) prescaler;

	/* enable TX a RX */
	UCSRB = (1<<RXEN) | (1<<TXEN);
	
	/* async, 8bit, no parity, 1 stop bit */
	UCSRC = (1<<URSEL)|(3<<UCSZ0);
}

void m8_usart_putc(char c)
{
	/* wait for empty buffer */
	while (!(UCSRA & (1<<UDRE)));

	UDR = c;
}

char m8_usart_getc(void)
{
	/* wait for data */
	while (!(UCSRA & (1<<RXC)));

	return UDR;
}

void m8_usart_puts(const char *str)
{
	while (*str != '\0')
		m8_usart_putc(*(str++));
}
