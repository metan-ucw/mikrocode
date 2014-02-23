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

#ifndef __M8_SPI_H__
#define __M8_SPI_H__

#include <stdint.h>
#include <avr/io.h>

#define M8_SPI_EN_INT (1<<SPIE)
#define M8_SPI_MASTER (1<<MSTR)
#define M8_SPI_SLAVE  (0)
#define M8_SPI_LSB    (1<<DORD)
#define M8_SPI_MSB    (0)

/*
 * Clock divider f_osc/4, f_osc/16, f_osc/64, f_osc/128
 */
#define M8_SPI_DIV(x) ((x)&0x03)

/*
 * Enables SPI, atmega is master
 */
void m8_spi_init(uint8_t cfg);

/*
 * Writes a byte to SPI
 */
void m8_spi_write(uint8_t byte);

#endif /* __M8_SPI_H__ */
