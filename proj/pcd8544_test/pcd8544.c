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

#include <avr/io.h>
#include <utils.h>
#include <delay.h>
#include <m8_spi.h>

/*
 * Initializes I/O pins
 */
static inline void pcd8544_init_io(void)
{
	SET_BIT(DDRC, PC5);
	SET_BIT(DDRC, PC4);
	SET_BIT(DDRC, PC3);
	SET_BIT(DDRC, PC2);
	SET_BIT(DDRC, PC1);
}

/*
 * Changes between data/command
 */
#define PCD8544_DATA SET_BIT(PORTC, PC3)
#define PCD8544_CMD  RESET_BIT(PORTC, PC3)

/*
 * Chipselect, active low
 */
#define PCD8544_SCE_LOW  RESET_BIT(PORTC, PC5)
#define PCD8544_SCE_HIGH SET_BIT(PORTC, PC5)

/*
 * Reset, active low
 */
#define PCD8544_RESET_LOW RESET_BIT(PORTC, PC4)
#define PCD8544_RESET_HIGH SET_BIT(PORTC, PC4)

/*
 * SPI byte write
 */
#define PCD8544_SPI_WRITE(byte) spi_write(byte)

static inline void spi_write(uint8_t byte)
{
	uint8_t i;

	for (i = 0; i < 8; i++) {
		if (byte & 0x80)
			SET_BIT(PORTC, PC2);
		else
			RESET_BIT(PORTC, PC2);

		SET_BIT(PORTC, PC1);
//		delay_us(1);
		RESET_BIT(PORTC, PC1);
		byte<<=1;
	}
}

#include <pcd8544.c>
