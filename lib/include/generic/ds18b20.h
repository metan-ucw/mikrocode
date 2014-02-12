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

 /*

   Dallas ds18b20 temperature sensor driver. See ds18b20.c for details.

  */

#ifndef __DS18B20_H__
#define __DS18B20_H__

#include <stdint.h>

/* Starts temperature conversion */
#define DS18B20_CONVERT_T 0x44
/* Requests scratchpad data (8 bytes + CRC) */
#define DS18B20_READ_SCRATCHPAD 0xbe

/*
 * Starts a single conversion.
 *
 * The device responds with zero bits until it's done.
 *
 * Maximal conversion times:
 *
 * resolution     time
 *    9 bit      93.75 ms
 *   10 bit      187.5 ms
 *   11 bit       375 ms
 *   12 bit       750 ms
 *
 *
 * Returns:
 * 0 on success
 * 1 when 1-wire bus reset failed
 */
uint8_t ds18b20_conv_t(void);

/*
 * Waits for conversion. The timeout is set to 750 ms.
 *
 * The 1-wire bus must not be reset betwen conversion and wait.
 *
 * Returns:
 * 0 on success
 * 1 on timeout
 */
uint8_t ds18b20_conv_wait(void);

/*
 * Checks if conversion is done.
 *
 * The 1-wire bus must not be reset betwen conversion and this.
 */
uint8_t ds18b20_conv_done(void);

/*
 * Reads temperature from scratchpad.
 *
 * Returns:
 * 0 on success
 * 1 when 1-wire bus reset failed
 * 2 when CRC was wrong
 */
uint8_t ds18b20_read_t(int16_t *temp);

#endif /* __DS18B20_H__ */
