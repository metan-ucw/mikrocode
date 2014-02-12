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

#ifndef __CPU_FREQ_H__
#define __CPU_FREQ_H__

#include <stdint.h>

#ifndef CPU_FREQ

# define CPU_FREQ _cpu_freq
# define CPU_FREQ_DIV_4 _cpu_freq_div_4

/* CPU freqency is variable */
# define CPU_FREQ_VAR

extern uint16_t _cpu_freq;

/* CPU freqency divided by 4 */
extern uint16_t _cpu_freq_div_4;

/*
 * Sets crystal speed in kHz
 */
void set_cpu_freq(uint16_t speed);

#else

# define CPU_FREQ_DIV_4 (CPU_FREQ/4)

#endif /* CPU_FREQ */

#endif /* __CPU_FREQ_H__ */
