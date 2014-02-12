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

#ifndef __M8_I2C_H__
#define __M8_I2C_H__

#include <stdbool.h>
#include <stdint.h>

/*
 * Initalize i2c hardware.
 */
void m8_i2c_init(void);

/*
 * Start i2c transmission.
 */
void m8_i2c_start(void);

/*
 * Stop i2c transmission.
 */
void m8_i2c_stop(void);

/*
 * Write data to i2c.
 */
bool m8_i2c_write(uint8_t byte);

/*
 * Read data from i2c.
 */
uint8_t m8_i2c_read(void);

#endif /* __M8_I2C_H__ */
