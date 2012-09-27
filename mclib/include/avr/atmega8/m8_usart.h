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

#ifndef __M8_USART_H__
#define __M8_USART_H__

#include <avr/io.h>
#include <stdint.h>

#include "string.h"

/* 
 * Enables usart
 */
void m8_usart_init(uint16_t baud);

/* 
 * Bussy loop read
 */
char m8_usart_getc(void);

/* 
 * Bussy loop write
 */
void m8_usart_putc(char c);

/*
 * Bussy loop string write.
 */
void m8_usart_puts(const char *str);

#endif /* __M8_USART_H__ */
