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

#ifndef __M8_TIMER0_H__
#define __M8_TIMER0_H__

#include <avr/io.h>

/*
 * TCCR0 lower three bits, select timer source.
 */
#define M8_TMR0_CLK_STOP            0x00
#define M8_TMR0_CLK_DIV_1           0x01
#define M8_TMR0_CLK_DIV_8           0x02
#define M8_TMR0_CLK_DIV_64          0x03
#define M8_TMR0_CLK_DIV_256         0x04
#define M8_TMR0_CLK_DIV_1024        0x05
#define M8_TMR0_CLK_T0_FAILING_EDGE 0x06
#define M8_TMR0_CLK_T0_RISING_EDGE  0x07

/*
 * Select clock soddurce.
 */
void m8_timer0_source(uint8_t flag);

/*
 * Turn on overflow interrupt.
 */
void m8_timer0_int_on(void);

/*
 * Turn off overflow interrupt.
 */
void m8_timer0_int_off(void);

#endif /* __M8_TIMER_H__ */
