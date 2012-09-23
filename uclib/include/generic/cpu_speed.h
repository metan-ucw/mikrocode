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

#ifndef __CPU_SPEED_H__
#define __CPU_SPEED_H__

#include <stdint.h>

#ifndef CPU_SPEED
#define CPU_SPEED _cpu_speed

extern uint16_t _cpu_speed;

/*
 * Sets crystal speed in kHz
 */
void set_cpu_speed(uint16_t speed);

#endif /* CPU_SPEED */

#endif /* __CPU_SPEED_H__ */
