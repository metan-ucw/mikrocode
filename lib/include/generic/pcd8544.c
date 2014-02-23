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

   The actual code is created by defining following macros and including this
   file.

   PCD8544_DATA       - sets LCD D/C pin to high
   PCD8544_CMD        - sets LCD D/C pin to low
   PCD8544_SCE_LOW    - sets LCD Chipselect pin to low
   PCD8544_SCE_HIGH   - sets LCD Chipselect pin to high
   PCD8544_RESET_LOW  - sets LCD Reset pin to low
   PCD8544_RESET_HIGH - sets LCD Reset pin to high
   PCD8544_SPI_WRITE  - writes a byte to LCD SPI bus

   void pcd8544_init_io(void) - initializes SPI bus and I/O pins

  */

#include "delay.h"
#include "pcd8544.h"

void pcd8544_reset(void)
{
	PCD8544_RESET_LOW;
	/*
	 * Datasheet says reset pulse should be at least 100ns long.
	 */
	delay_us(1);
	PCD8544_RESET_HIGH;
}

void pcd8544_cmd(uint8_t byte)
{
	PCD8544_CMD;
	PCD8544_SCE_LOW;
	PCD8544_SPI_WRITE(byte);
	PCD8544_SCE_HIGH;
}

void pcd8544_write(uint8_t byte)
{
	PCD8544_DATA;
	PCD8544_SCE_LOW;
	PCD8544_SPI_WRITE(byte);
	PCD8544_SCE_HIGH;
}

void pcd8544_clear(uint8_t byte)
{
	uint8_t x, y;

	pcd8544_cmd(PCD8544_CMD_SET_X(0));
	pcd8544_cmd(PCD8544_CMD_SET_Y(0));

	for (y = 0; y < 6; y++) {
		for (x = 0; x < 84; x++)
			pcd8544_write(byte);
	}
}

void pcd8544_init(void)
{
	pcd8544_init_io();
	pcd8544_reset();

	pcd8544_cmd(PCD8544_ADDRESS_EXT_CMD);
	pcd8544_cmd(PCD8544_CMD_VOP(48));
	pcd8544_cmd(PCD8544_CMD_TEPM_CTL(0));
	//TODO?
	pcd8544_cmd(PCD8544_CMD_BIAS(4));
	pcd8544_cmd(PCD8544_ADDRESS_BASIC_CMD);
	pcd8544_cmd(PCD8544_CMD_NORM_MODE);
}
